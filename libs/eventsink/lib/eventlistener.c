/*******************************************************************************
* Copyright (C) 2004-2007 Intel Corp. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
*  - Neither the name of Intel Corp. nor the names of its
*    contributors may be used to endorse or promote products derived from this
*    software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL Intel Corp. OR THE CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

/**
 * @author Anas Nashif
 * @author Liang Hou
 */
#include <stdlib.h>
#include <stdio.h>
#include "mongoose.h"
#ifdef WIN32_PORT
#include "u/pthreadx.h"
#define PACKAGE		"eventsink"
#define VERSION		"1.0"
#else
#include <pthread.h>
#include <sys/socket.h>
#endif
#include "u/libu.h"

#include "wsman-soap.h"
#include "wsman-soap-envelope.h"
#include "wsman-names.h"
#include "wsman-soap-message.h"
#include "wsman-xml.h"
#include "wsman-xml-api.h"
#include "eventlistener.h"

#ifdef WIN32_PORT
enum {
  PTHREAD_CREATE_JOINABLE       = 0,  /* Default */
  PTHREAD_CREATE_DETACHED       = 1,
};

//extern int pthread_attr_setdetachstate (pthread_attr_t * attr, int detachstate);
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#define AUTHENTICATION_REALM "EVENTLISTENER"

#define WSMAN_STATUS_OK 20
#define WSMAN_STATUS_METHOD_NOT_ALLOWED 405
#define WSMAN_STATUS_UNSUPPORTED_MEDIA_TYPE 415
#define WSMAN_STATUS_BAD_REQUEST 400
#define WSMAN_STATUS_INTERNAL_SERVER_ERROR 500

#define SOAP_CONTENT_TYPE "application/soap+xml"

//list_t *request_list = NULL;
int    stop_event_listener   = 0;

#ifndef WIN32_PORT
pthread_mutex_t shttpd_mutex;
#else
HANDLE	shttpd_mutex;
#endif

struct mg_context	*ctx = NULL;

struct eventlistener_ctx{
	int port;
	char *servicepath;
	int authnotneeded;
	int debug;
	eventlistener_bauth_callback_t         bauthf; /* basic authorization callback */
	eventlistener_dauth_callback_t         dauthf; /* digest authorization callback */
	eventlistener_event_processor_t	eventf; /* Event procesion callback */
	void *data;
};

static struct eventlistener_ctx *listener = NULL;

typedef struct {
	char *response;
	int length;
	int ind;
} ShttpMessage;

int eventlistener_init(int port, char *servicepath, int authnotneeded, int is_debug)
{
	if(listener) return 0;
	listener = u_zalloc(sizeof(struct eventlistener_ctx));
	if(listener == NULL) {
		debug("Insufficient memory!");
		return -1;
	}
	listener->port = port;
	listener->servicepath = u_strdup(servicepath);
	listener->authnotneeded = authnotneeded;
    listener->debug = is_debug;
	return 0;
}

void eventlistener_register_bauth_callback(eventlistener_bauth_callback_t bauthf)
{
	listener->bauthf = bauthf;
}

void eventlistener_register_dauth_callback(eventlistener_dauth_callback_t dauthf)
{
	listener->dauthf = dauthf;
}

void eventlistener_register_event_processor(eventlistener_event_processor_t eventf, void *data)
{
	listener->eventf = eventf;
	listener->data = data;
}


static void accept_events_call(WsmanMessage *wsman_msg,char* ip_addr)
{
	char *buf = NULL;
	char *messageid;
	int len;
	WsXmlDocH ackdoc = NULL;
	WsXmlDocH in_doc = wsman_build_inbound_envelope(wsman_msg);
	WsXmlNodeH header = ws_xml_get_soap_header(in_doc);
	WsXmlNodeH acknode = ws_xml_get_child(header, 0, XML_NS_WS_MAN, WSM_ACKREQUESTED);
	if(acknode) {
		ackdoc = ws_xml_create_envelope();
		messageid = ws_xml_get_node_text(ws_xml_get_child(header, 0, XML_NS_ADDRESSING, WSA_MESSAGE_ID));
		header = ws_xml_get_soap_header(ackdoc);
		ws_xml_add_child(header, XML_NS_ADDRESSING, WSA_TO, WSA_TO_ANONYMOUS);
		ws_xml_add_child(header, XML_NS_ADDRESSING, WSA_RELATES_TO, messageid);
		ws_xml_add_child(header, XML_NS_ADDRESSING, WSA_ACTION, WSMAN_ACTION_ACK);
		ws_xml_dump_memory_enc(ackdoc, &buf, &len, wsman_msg->charset);
		u_buf_set(wsman_msg->response, buf, len);
		ws_xml_destroy_doc(ackdoc);
		u_free(buf);
	}
	if(listener->eventf)
		listener->eventf(in_doc, listener->data,ip_addr);
	ws_xml_destroy_doc(in_doc);
}

char*
ipToStr (unsigned long ip,char*str)
{
	sprintf (str, "%ld.%ld.%ld.%ld", (ip >> 0) & 0xff,
	(ip >> 8) & 0xff,
	(ip >> 16) & 0xff,
	(ip >> 24) & 0xff);
	return str;
}



static int server_callback(struct mg_request_info *arg)
{
	const char *method;
	const char *content_type = '\0';
	char *encoding = NULL;
	int status = WSMAN_STATUS_OK;
	char *fault_reason = NULL;
	WsmanMessage *wsman_msg;
	size_t length;
	char *body;
	unsigned long int IP;
	char *ip_addr;

	ShttpMessage *shttp_msg = (ShttpMessage *) arg->status_code;
	int n = 0;
	int k;
	int i;
	hash_t *hash = hash_create(HASHCOUNT_T_MAX, 0, 0);
	hash_set_allocator(hash, NULL, NULL, NULL);

	debug("Server callback started %s. len = %d, sent = %d",
	      (shttp_msg == NULL) ? "initialy" : "continue",
	      arg->post_data_len, (shttp_msg == NULL) ? 0 : shttp_msg->ind);
	if (shttp_msg != NULL) {
		// We already have the response, but server
		// output buffer is smaller then it.
		// Some part of resopnse have already sent.
		// Just continue to send it to server
		goto CONTINUE;
	}
	// Here we must handle the initial request
    wsman_msg = wsman_soap_message_new();

	// Check HTTP headers

	/*method = shttpd_get_env(arg, "REQUEST_METHOD");
	if (strncmp(method, "POST", 4)) {*/
	if (strncmp(arg->request_method, "POST",4)) {
		//debug("Unsupported method %s", method);
		debug("Unsupported method %s", arg->request_method);
		status = WSMAN_STATUS_METHOD_NOT_ALLOWED;
		fault_reason = "POST method supported only";
	}

	//content_type = shttpd_get_header(arg, "Content-Type");
	for (i = 0; i < arg->num_headers; i++) {
		if (!strcasecmp("Content-Type", arg->http_headers[i].name))
			content_type = arg->http_headers[i].value;		
		hash_alloc_insert(hash, arg->http_headers[i].name, arg->http_headers[i].value);
	}
	if (content_type && strncmp(content_type,
				    SOAP_CONTENT_TYPE,
				    strlen(SOAP_CONTENT_TYPE)) != 0) {
		status = WSMAN_STATUS_UNSUPPORTED_MEDIA_TYPE;
		fault_reason = "Unsupported content type";
		goto DONE;
	}
	if(content_type) {
		char *p = strstr(content_type, "charset");
		if(p) {
			p += strlen("charset");
			p++;
			wsman_msg->charset = u_strdup(p);
			encoding = u_strdup(p);
		}
	}
	wsman_msg->status.fault_code = WSMAN_RC_OK;
	wsman_msg->http_headers = hash;

	// Get request from http server
    /*length = shttpd_get_post_query_len(arg);
    body = shttpd_get_post_query(arg);*/
	length = arg->post_data_len;
    body = arg->post_data;
	if (body == NULL) {
		status = WSMAN_STATUS_BAD_REQUEST;
		fault_reason = "No request body";
		error("NULL request body. len = %d", length);
	}
	u_buf_construct(wsman_msg->request, body, length, length);
	debug("Posted request: %s, wsman_msg len = %d", u_buf_ptr(wsman_msg->request),
			u_buf_len(wsman_msg->request));

	// some plugins can use credentials for its
	// own authentication
	/*shttpd_get_credentials(arg, &wsman_msg->auth_data.username,
			       &wsman_msg->auth_data.password);*/


	// Call dispatcher. Real request handling
	if (status == WSMAN_STATUS_OK) {
		// dispatch if we didn't find out the error
		ip_addr = (char*)malloc(16);
		//#ifdef WIN32
		//IP = arg->sa.u.sin.sin_addr.S_un.S_addr;
		IP = htonl (arg->remote_ip);
		ipToStr(IP,ip_addr);

		//#else
		//ip_addr = inet_ntoa (arg->sa.u.sin.sin_addr);
		//ip_addr = inet_ntoa (arg->remote_ip);
                //IP = htonl (arg->remote_ip);
                //ipToStr(IP,ip_addr);

		//#endif

		accept_events_call(wsman_msg,ip_addr);
		#ifdef WIN32
		free(ip_addr);
		#endif
		status = wsman_msg->http_code;
	}


	if (wsman_msg->request) {
		// we don't need request any more
//		if(strcmp(wsman_msg->charset, "UTF-8") == 0)
			(void) u_buf_steal(wsman_msg->request);
		u_buf_free(wsman_msg->request);
		wsman_msg->request = NULL;
	}
	// here we start to handle the response

	shttp_msg = (ShttpMessage *) malloc(sizeof(ShttpMessage));
	if (shttp_msg == NULL) {
		status = WSMAN_STATUS_INTERNAL_SERVER_ERROR;
		fault_reason = "No memory";
		goto DONE;
	}


	shttp_msg->length = u_buf_len(wsman_msg->response);
	debug("message len = %d", shttp_msg->length);
	shttp_msg->response = u_buf_steal(wsman_msg->response);
	shttp_msg->ind = 0;
      DONE:
	 wsman_soap_message_destroy(wsman_msg);
	debug("Response (status) %d (%s)", status, fault_reason);

	// Here we begin to create the http response.
	// Create the headers at first.
	// We consider output buffer of server is large enough to hold all headers.

	n += snprintf(arg->post_data + n, arg->post_data_len - n, "HTTP/1.1 %d %s\r\n",
		      status, fault_reason);
	n += snprintf(arg->post_data + n, arg->post_data_len - n, "Server: %s/%s\r\n",
		      PACKAGE, VERSION);
	if (!shttp_msg || shttp_msg->length == 0) {
		// can't send the body of response or nothing to send
		n += snprintf(arg->post_data + n, arg->post_data_len - n, "\r\n");
		//arg->last = 1;
		u_free(shttp_msg);
		return n;
	}

	n += snprintf(arg->post_data + n, arg->post_data_len - n,
		      "Content-Type: application/soap+xml;charset=%s\r\n", encoding);
	n += snprintf(arg->post_data + n, arg->post_data_len - n,
		      "Content-Length: %d\r\n", shttp_msg->length);
	n += snprintf(arg->post_data + n, arg->post_data_len - n, "\r\n");
	u_free(encoding);
	// add response body to output buffer
      CONTINUE:
	k = arg->post_data_len - n;
	if (k <= shttp_msg->length - shttp_msg->ind) {
		// not enogh room for all message. transfer only part
		memcpy(arg->post_data_len + n, shttp_msg->response + shttp_msg->ind,
		       k);
		shttp_msg->ind += k;
		arg->status_code = shttp_msg;
		return n + k;
	}
	// Enough room for all response body
	memcpy(arg->post_data + n, shttp_msg->response + shttp_msg->ind,
	       shttp_msg->length - shttp_msg->ind);
	n += shttp_msg->length - shttp_msg->ind;
	if (n + 4 > arg->post_data_len) {
		// not enough room for empty lines at the end of the message
		arg->status_code = shttp_msg;
		shttp_msg->ind = shttp_msg->length;
		return n;
	}
	// here we can complete
	n += snprintf(arg->post_data + n, arg->post_data_len - n, "\r\n\r\n");
	debug("%s", arg->post_data);
	u_free(shttp_msg->response);
	u_free(shttp_msg);
	#ifndef WIN32
	u_free(ip_addr);
	#endif

	//arg->last = 1;
	arg->status_code = NULL;
	return n;
}


/*static void *service_connection(void *arg)
{
	int sock;
	lnode_t *node;
	struct shttpd_ctx *httpctx;

//        pthread_mutex_lock(&shttpd_mutex);
	if(list_isempty(request_list)) {
//                pthread_mutex_unlock(&shttpd_mutex);
		return NULL;
	}
	node = list_del_first(request_list);
	sock = (int) ((char *) lnode_get(node) - (char *) NULL);
//        pthread_mutex_unlock(&shttpd_mutex);
	lnode_destroy(node);
        //debug("Thread %d handles sock %d", pthread_self(), sock);

    httpctx;
        httpctx = shttpd_init(NULL,"auth_realm", AUTHENTICATION_REALM,
                        "debug", listener->debug? "1" : "0", NULL);
	if (httpctx == NULL) {
		(void) shutdown(sock, 2);
		close(sock);
		return NULL;
	}
        shttpd_register_url(httpctx, listener->servicepath, NULL,
                            server_callback, listener->authnotneeded, NULL);
	if(listener->bauthf)
		shttpd_register_bauth_callback(httpctx, listener->bauthf);
	if(listener->dauthf)
		shttpd_register_dauth_callback(httpctx, listener->dauthf);
	shttpd_add(httpctx, sock);
	while (shttpd_active(httpctx)) {
		shttpd_poll(httpctx, 100);
	}
	shttpd_fini(httpctx);
//        debug("Thread %d processed sock %d", pthread_self(), sock);
	return NULL;
}*/

void eventlistener_start()
{
	char port[255];
	/*int lsn;
	int sock;
	int r;
	lnode_t *node;
	pthread_t thr_id;
	pthread_attr_t pattrs;
#ifdef WIN32_PORT
		DWORD dwThreadId;

		shttpd_mutex = CreateMutex(NULL, FALSE, NULL);

#endif*/


	if(listener == NULL) {
		debug("Event Sink uninitialized!");
		return;
	}
//	request_list = list_create(LISTCOUNT_T_MAX);
//	lsn = shttpd_open_port(listener->port);
//  //      if ((r = pthread_mutexattr_init(&pattrs)) != 0) {
//  //              debug("pthread_attr_init failed = %d", r);
//  //              return;
//  //      }
//
//  //      if ((r = pthread_mutexattr_settype(&pattrs,PTHREAD_CREATE_DETACHED)) != 0) {
//  //              debug("pthread_attr_setdetachstate = %d", r);
//  //              return;
//  //      }
//		//else
//		//{
//		//	if (pthread_mutex_init(&shttpd_mutex, &pattrs) != 0) return;
//		//}
//	while(1) {
//		if ((sock = shttpd_accept(lsn, 1000)) == -1) {
//
//			if (stop_event_listener == 1) { return; }
//			continue;
//		}
//		debug("Sock %d accepted", sock);
//		node = lnode_create((void *) ((char *) NULL + sock));
//		if (node == NULL) {
//			debug("lnode_create == NULL");
//			(void) shutdown(sock, 2);
//			close(sock);
//			continue;
//		}
//        //pthread_mutex_lock(&shttpd_mutex);
//		list_append(request_list, node);
//        //pthread_mutex_unlock(&shttpd_mutex);
//
//#ifndef WIN32_PORT
//                r = pthread_create(&thr_id, &pattrs, service_connection,NULL);
//#else
//			CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)service_connection, NULL, 0, &dwThreadId);
//#endif
//
//        }
	if ((ctx = mg_start()) == NULL) {		
		return NULL;
	}
	sprintf(port, "%d", listener->port );
	mg_set_option(ctx, "ports",port);
	mg_set_uri_callback(ctx,  listener->servicepath,server_callback, NULL);

	if(listener->bauthf)		
		mg_set_auth_callback(ctx, "/*", listener->bauthf, NULL);		
        return;
}

void
eventlistener_stop (void)
{
	mg_stop(ctx);

	/*if (request_list)
	{
		list_destroy (request_list);
		request_list = NULL;
	}*/

	if(listener)
	{
		if (listener->servicepath) { u_free (listener->servicepath); }
		u_free (listener);
		listener = NULL;
	}

	stop_event_listener = 1;

}
