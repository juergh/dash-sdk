/*******************************************************************************
 * Copyright (C) 2004-2006 Intel Corp. All rights reserved.
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

#ifdef WIN32_PORT
#define STDERR_FILENO stderr
#include <windows.h>
#else
#include <sys/types.h>
#include <unistd.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include "eventlistener.h"
#include "eventsink.h"

static int port = EVENT_SINK_PORT;
static char *servicepath = EVENT_SINK_PATH;
static int is_debug = 1;
static int log_pid = 0;
static char *output_file = NULL;
struct mg_context	*ctx;

static void
debug_message_handler(const char *str,
		      debug_level_e level, void *user_data)
{
	if (log_pid == 0)
		log_pid = getpid();

        if ( is_debug > 0) {
		struct tm *tm;
		time_t now;
		char timestr[128];
		char *log_msg;
		//int p;

		time(&now);
		tm = localtime(&now);
                //strftime(timestr, 128, "%b %e %T", tm);

		log_msg = u_strdup_printf("%s [%d] %s\n",
					  timestr, log_pid, str);

                //if ((p =
                 //    write(STDERR_FILENO, log_msg, strlen(log_msg))) < 0)
                 //       fprintf(stderr, "Failed writing to log file\n");
                //fsync(STDERR_FILENO);


		u_free(log_msg);
	}
}


static void initialize_logging(void)
{
        debug_add_handler(debug_message_handler, -1, NULL);

}       

#ifdef BUILD_AS_LIB

#ifdef WIN32_PORT
DWORD WINAPI start_event_listener(LPVOID p_arg)
#else
void* start_event_listener (void* p_arg)
#endif
{
    eventlistener_start();
	return 0;
}

int
wsevent_start (int port, const char* service_path, fp_evt_callback fp_callback, void* data)
{

	/* initilize and register events */
	if(eventlistener_init(port, servicepath, 1, is_debug)) { return -1; }
	eventlistener_register_event_processor(fp_callback, data);

	/* start the event listener thread */
	#ifdef WIN32_PORT
		if (NULL == CreateThread(NULL, 0, start_event_listener, NULL, 0, NULL))
		{
			return -1;
		}
		else
		{
			return 0;
		}
	#else
		{
			pthread_t thr_id;
			pthread_create(&thr_id, NULL, start_event_listener, NULL);
		}
	#endif /* WIN32_PORT */

	//eventlistener_start();
	return 0;

}

int
wsevent_stop (void)
{

	eventlistener_stop ();

	return 0;
}

#else /* BUILD_AS_LIB */

static void usage(void)
{
	printf("\n\neventsink [-p port] [-r service_path] [-d] [-o output_file]\n\n");
}

static int print_events(WsXmlDocH indoc, void *data)
{
	FILE *f = stdout;
        const char *filename = output_file;
	struct tm *tm;
        time_t now;
        char timestr[128];
        char *log_msg;
        time(&now);
        tm = localtime(&now);
       // strftime(timestr, 128, "%b %e %T", tm);
	if (filename) {
		f = fopen(filename, "a+");
		if (f == NULL) {
			error("Could not open file for writing");
			return -1;
                }
        }

	if(f == stdout)
        	log_msg = u_strdup_printf("\t\t\033[22;32mAt %s received:\033[m \n\n",timestr);
	else
		log_msg = u_strdup_printf("At %s received:\n\n", timestr);
	        //fprintf(f, "%s", log_msg);

	       // ws_xml_dump_node_tree(f, ws_xml_get_doc_root(indoc));
			{
				WsXmlNodeH node;
				WsXmlNodeH class_node;
				char*	class_name;
				int		child_count;
				int		i;

				node		= ws_xml_get_soap_body (indoc);
				class_node	= ws_xml_get_child (node, 0, NULL, NULL);
				class_name  = ws_xml_get_node_local_name (class_node);

				printf ("\n%s\n", class_name);

				child_count	= ws_xml_get_child_count (class_node);
				for (i = 0; i < child_count; i++)
				{
					WsXmlNodeH	child_node;
					WsXmlAttrH	attr;
					char*		node_name;

					child_node	= ws_xml_get_child (class_node, i, NULL, NULL);
					attr		= ws_xml_get_node_attr (child_node, 0);
					node_name	= ws_xml_get_attr_value (attr);
					printf ("%-25s - %s\n", ws_xml_get_node_local_name (child_node), ws_xml_get_node_text (child_node));
				}
			}

	fflush(f);
	if (f != stdout) {
		fclose(f);
        }
        u_free(log_msg);
	return 0;
}


int main(int argc, char *argv[])
{
	int ch;
	if(argc > 1 && strcasecmp(argv[1], "help") == 0) {
		usage();
		exit(0);
	}
	while(argc > 1 && (ch = getopt(argc, argv, "p:r:o:d"))!= -1) {
		switch(ch) {
			case 'p':
				port = atoi(optarg);
				break;
			case 'r':
				servicepath = optarg;
				break;
			case 'd':
                is_debug = 1;
				break;
			case 'o':
				output_file = optarg;
				break;
			default:
				printf("Unrecognized option!\n");
				exit(0);
		}
	}
	initialize_logging();
    if(eventlistener_init(port, servicepath, 1, is_debug))
		exit(-1);
	eventlistener_register_event_processor(print_events, NULL);
	eventlistener_start();
	return 0;
}

#endif /* BUILD_AS_LIB */
