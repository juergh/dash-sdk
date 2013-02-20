/*
 * License Agreement 
 *
 * Copyright (c) 2007, 2008, 2009 Advanced Micro Devices Inc.
 *
 * All rights reserved.
 *
 * Redistribution and use in any form of this material and any product thereof including
 * software in source or binary forms, along with any related documentation, with or 
 * without modification ("this material"), is permitted provided that the following 
 * conditions are met:
 *
 *    + Redistributions of source code of any software must retain the above copyright 
 *      notice and all terms of this license as part of the code.
 *
 *    + Redistributions in binary form of any software must reproduce the above copyright 
 *      notice and all terms of this license in any related documentation and/or other 
 *      materials.
 *
 *    + Neither the names nor trademarks of Advanced Micro Devices, Inc. or any copyright 
 *      holders or contributors may be used to endorse or promote products derived from 
 *      this material without specific prior written permission.
 *
 *    + Notice about U.S. Government restricted rights: This material is provided with ?
 *      RESTRICTED RIGHTS.? Use, duplication or disclosure by the U.S. Government is subject 
 *      to the full extent of restrictions set forth in FAR52.227 and DFARS252.227 et seq., 
 *      or any successor or applicable regulations. Use of this material by the U.S. 
 *      Government constitutes acknowledgment  of  the  proprietary rights of 
 *      Advanced Micro Devices, Inc. and any copyright holders and contributors. 
 *
 *    + In no event shall anyone redistributing or accessing or using this material 
 *      commence or participate in any arbitration or legal action relating to this 
 *      material against Advanced Micro Devices, Inc. or any copyright holders or contributors. 
 *      The foregoing shall survive any expiration or termination of this license or any 
 *      agreement or access or use related to this material.  
 *
 *    + ANY BREACH OF ANY TERM OF THIS LICENSE SHALL RESULT IN THE IMMEDIATE REVOCATION 
 *      OF ALL RIGHTS TO REDISTRIBUTE, ACCESS OR USE THIS MATERIAL. 
 *
 * THIS MATERIAL IS PROVIDED BY ADVANCED MICRO DEVICES, INC. AND ANY COPYRIGHT HOLDERS AND 
 * CONTRIBUTORS "AS IS" IN ITS CURRENT CONDITION AND WITHOUT ANY REPRESENTATIONS, GUARANTEE, 
 * OR WARRANTY OF ANY KIND OR IN ANY WAY RELATED TO SUPPORT, INDEMNITY, ERROR FREE OR 
 * UNINTERRUPTED OPERATION, OR THAT IT IS FREE FROM DEFECTS OR VIRUSES.  ALL OBLIGATIONS 
 * ARE HEREBY DISCLAIMED - WHETHER EXPRESS, IMPLIED, OR STATUTORY - INCLUDING, BUT NOT 
 * LIMITED TO, ANY IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY, FITNESS FOR A PARTICULAR 
 * PURPOSE, ACCURACY, COMPLETENESS, OPERABILITY, QUALITY OF SERVICE, OR NON-INFRINGEMENT. 
 * IN NO EVENT SHALL ADVANCED MICRO DEVICES, INC. OR ANY COPYRIGHT HOLDERS OR CONTRIBUTORS 
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, PUNITIVE, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, REVENUE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED 
 * OR BASED ON ANY THEORY OF LIABILITY ARISING IN ANY WAY RELATED TO THIS MATERIAL, EVEN IF 
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. THE ENTIRE AND AGGREGATE LIABILITY OF ADVANCED 
 * MICRO DEVICES, INC. AND ANY COPYRIGHT HOLDERS AND CONTRIBUTORS SHALL NOT EXCEED TEN DOLLARS 
 * (US $10.00). ANYONE REDISTRIBUTING OR ACCESSING OR USING THIS MATERIAL ACCEPTS THIS 
 * ALLOCATION OF RISK AND AGREES TO RELEASE ADVANCED MICRO DEVICES, INC. AND ANY COPYRIGHT 
 * HOLDERS AND CONTRIBUTORS FROM ANY AND ALL LIABILITIES, OBLIGATIONS, CLAIMS, OR DEMANDS IN 
 * EXCESS OF TEN DOLLARS (US $10.00). THE FOREGOING ARE ESSENTIAL TERMS OF THIS LICENSE AND, 
 * IF ANY OF THESE TERMS ARE CONSTRUED AS UNENFORCEABLE, FAIL IN ESSENTIAL PURPOSE, OR BECOME 
 * VOID OR DETRIMENTAL TO ADVANCED MICRO DEVICES, INC. OR ANY COPYRIGHT HOLDERS OR CONTRIBUTORS 
 * FOR ANY REASON, THEN ALL RIGHTS TO REDISTRIBUTE, ACCESS OR USE THIS MATERIAL SHALL TERMINATE 
 * IMMEDIATELY. MOREOVER, THE FOREGOING SHALL SURVIVE ANY EXPIRATION OR TERMINATION OF THIS 
 * LICENSE OR ANY AGREEMENT OR ACCESS OR USE RELATED TO THIS MATERIAL. 
 *
 * NOTICE IS HEREBY PROVIDED, AND BY REDISTRIBUTING OR ACCESSING OR USING THIS MATERIAL SUCH NOTICE 
 * IS ACKNOWLEDGED, THAT THIS MATERIAL MAY BE SUBJECT TO RESTRICTIONS UNDER THE LAWS AND REGULATIONS 
 * OF THE UNITED STATES OR OTHER COUNTRIES, WHICH INCLUDE BUT ARE NOT LIMITED TO, U.S. EXPORT 
 * CONTROL LAWS SUCH AS THE EXPORT ADMINISTRATION REGULATIONS AND NATIONAL SECURITY CONTROLS AS 
 * DEFINED THEREUNDER, AS WELL AS STATE DEPARTMENT CONTROLS UNDER THE U.S. MUNITIONS LIST. THIS 
 * MATERIAL MAY NOT BE USED, RELEASED, TRANSFERRED, IMPORTED, EXPORTED AND/OR RE-EXPORTED IN ANY 
 * MANNER PROHIBITED UNDER ANY APPLICABLE LAWS, INCLUDING U.S. EXPORT CONTROL LAWS REGARDING 
 * SPECIFICALLY DESIGNATED PERSONS, COUNTRIES AND NATIONALS OF COUNTRIES SUBJECT TO NATIONAL SECURITY 
 * CONTROLS. MOREOVER, THE FOREGOING SHALL SURVIVE ANY EXPIRATION OR TERMINATION OF ANY LICENSE 
 * OR AGREEMENT OR ACCESS OR USE RELATED TO THIS MATERIAL. 
 *
 * This license forms the entire agreement regarding the subject matter hereof and supersedes all 
 * proposals and prior discussions and writings between the parties with respect thereto. This 
 * license does not affect any ownership, rights, title, or interest in, or relating to, this 
 * material. No terms of this license can be modified or waived, and no breach of this license 
 * can be excused, unless done so in a writing signed by all affected parties. Each term of this 
 * license is separately enforceable. If any term of this license is determined to be or becomes 
 * unenforceable or illegal, such term shall be reformed to the minimum extent necessary in order 
 * for this license to remain in effect in accordance with its terms as modified by such reformation. 
 * This license shall be governed by and construed in accordance with the laws of the State of 
 * Texas without regard to rules on conflicts of law of any state or jurisdiction or the United 
 * Nations Convention on the International Sale of Goods. All disputes arising out of this license 
 * shall be subject to the jurisdiction of the federal and state courts in Austin, Texas, and all 
 * defenses are hereby waived concerning personal jurisdiction and venue of these courts.
 */

#include <stdio.h>
#include <assert.h>

#ifdef WIN32
#else
  #include <sys/socket.h>
  #include <netdb.h>
#endif

#include "log.h"

#include "sslclient.h"

SSL_CTX * SSLClient::g_ssl_ctx=NULL;

SSLClient::SSLClient(const char * _ip,int _port):Client(_ip,_port) {
};

bool SSLClient::init_ssl() {
  if (g_ssl_ctx) return true;
  char errmsg[0x100];
  SSL_library_init();
  SSL_load_error_strings();
#ifndef WIN32
  SSL_METHOD * meth = const_cast<SSL_METHOD*>(SSLv23_method());
#else
   SSL_METHOD * meth = SSLv23_method();
#endif
  g_ssl_ctx = SSL_CTX_new(meth);
  if (!g_ssl_ctx) {
    ERR_error_string_n(ERR_get_error(),errmsg,sizeof(errmsg));
    SSL_PRINT(ERR, "init_ssl(): Unable to create SSL context: %s",errmsg);
    return false;
  }

#ifdef VERIFY_SERVER
  if (!SSL_CTX_load_verify_locations(g_ssl_ctx, TELNET_SSL_SERVER_CA_CERT, NULL)) {
     ERR_error_string_n(ERR_get_error(),errmsg,sizeof(errmsg));
     SSL_PRINT(ERR, "%s: init_ssl(): SSL_CTX_load_verify_locations(): %s",m_id.c_str(),errmsg);
     return false;
  }
  SSL_CTX_set_verify(g_ssl_ctx,SSL_VERIFY_PEER,NULL);
  SSL_CTX_set_verify_depth(g_ssl_ctx,1);
#endif
  return true;
}

bool SSLClient::setup_encryption() {
  if (!init_ssl()) return false;
  char errmsg[0x100];
  m_ssl = SSL_new(g_ssl_ctx);
  if (!m_ssl) {
    SSL_PRINT(ERR, "%s: setup_encryption(): SSL_new() returns NULL pointer\n",m_id.c_str());
    return false;
  }

  //set 2000 ms timeout for SSL_accept()
  struct timeval timer;
  const int RCVTIMEOUT=2000;
  timer.tv_sec  =  RCVTIMEOUT / 1000;
  timer.tv_usec = (RCVTIMEOUT % 1000) * 1000;
  if (setsockopt(m_transport_socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timer, sizeof(timer)) < 0) {
    SSL_PRINT(ERR, "%s: setup_encryption(): setsockopt() SO_RCVTIMEO: %s\n",m_id.c_str(),STRWSAERR(WSAERRNO));
    return false;
  }

  const int SNDTIMEOUT=2000;
  timer.tv_sec  =  SNDTIMEOUT / 1000;
  timer.tv_usec = (SNDTIMEOUT % 1000) * 1000;
  if (setsockopt(m_transport_socket, SOL_SOCKET, SO_SNDTIMEO, (char *)&timer, sizeof(timer)) < 0) {
    SSL_PRINT(ERR, "%s: setup_encryption(): setsockopt() SO_SNDTIMEO: %s\n",m_id.c_str(),STRWSAERR(WSAERRNO));
    return false;
  }

  SSL_set_fd(m_ssl, m_transport_socket);
  int res=SSL_connect(m_ssl);
  if (res<=0) {
    ERR_error_string_n(ERR_get_error(),errmsg,sizeof(errmsg));
    SSL_PRINT(DEBUG, "%s: setup_encryption(): SSL_connect(): %s",m_id.c_str(),errmsg);
    return false;
  }
  SSL_PRINT(DEBUG, "%s: setup_encryption(): SSL connected: %s\n",m_id.c_str(),SSL_get_cipher(m_ssl));

 #ifdef xxxVERIFY_SERVER
  X509 *client_cert = SSL_get_peer_certificate(m_ssl);
  if (client_cert != NULL) {
    char * subject = X509_NAME_oneline(X509_get_subject_name(client_cert), 0, 0);
    if (!subject) {
      SSL_PRINT(ERR, "%s: setup_encryption(): X509_NAME_oneline(X509_get_subject_name()) returns NULL\n",m_id.c_str());
      return false;
    }
    chart * issuer = X509_NAME_oneline(X509_get_issuer_name(client_cert), 0, 0);
    if (!issuer) {
      SSL_PRINT(ERR, "%s: setup_encryption(): X509_NAME_oneline(X509_get_issuer_name()) returns NULL\n",m_id.c_str());
      return false;
    }
    SSL_PRINT(INFO, "Client certificate: subject: %s  issuer: %s\n",m_id.c_str(), subject,issuer);
    free(subject);
    free(issuer);
    X509_free(client_cert);
  } else {
    SSL_PRINT(INFO, "%s: setup_encryption(): The SSL Server does not have a certificate!\n",m_id.c_str());
  }
 #endif
  return true;
}

void SSLClient::closeconn() {
  if (isConnected()) {
    SSL_PRINT(DEBUG, "%s: closeconn(): SSL shutdown\n",m_id.c_str());
    char errmsg[0x100];
    if (SSL_shutdown(m_ssl)<0) {
      ERR_error_string_n(ERR_get_error(),errmsg,sizeof(errmsg));
      SSL_PRINT(ERR, "%s: closeconn(): SSL_shutdown() failed: %s",m_id.c_str(),errmsg);
    }
  }
  Client::closeconn();
}
