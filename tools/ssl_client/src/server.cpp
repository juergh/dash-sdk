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
#include <string.h>
#include <unistd.h>

#ifdef WIN32
  #include <time.h>
#else
  #include <fcntl.h>
  #include <arpa/inet.h>
#endif

#include "log.h"
#include "server.h"

Server::Server():Transport("server") {
  m_listen_socket=-1;
  m_listen_port=0;
  m_conn_type=ConnTypeSocket;
}

Server::~Server() {
  if (isConnected()) closeconn();
};

int Server::listen() {
  sockaddr_in sockaddr_listen;
  memset((char *) &sockaddr_listen, 0, sizeof sockaddr_listen);

  m_listen_socket=::socket(AF_INET, SOCK_STREAM, 0);

  int opt = 1;
  if(setsockopt(m_listen_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) == -1) {
    SSL_PRINT(ERR, "%s: listen(): setsockopt(SO_REUSEADDR): %s\n",m_id.c_str(),STRWSAERR(WSAERRNO));
    return 0;
  }

  sockaddr_listen.sin_family = AF_INET;
  sockaddr_listen.sin_addr.s_addr =  htonl(INADDR_ANY);
  sockaddr_listen.sin_port = htons(m_listen_port);

  if (bind(m_listen_socket, (struct sockaddr *)&sockaddr_listen, sizeof sockaddr_listen) < 0) {
   #ifdef WIN32
    if (WSAERRNO==WSAEADDRINUSE) {
   #else
    if (errno==EADDRINUSE) {
   #endif
        SSL_PRINT(INFO, "%s: listen(): bind(port#%d): %s --> RETRY\n",m_id.c_str(),m_listen_port,STRWSAERR(WSAERRNO));
        return -1;
    } else {
        SSL_PRINT(ERR, "%s: listen(): bind(port#%d): %s\n",m_id.c_str(),m_listen_port,STRWSAERR(WSAERRNO));
        return 0;
    }
  } else {
    struct sockaddr_in mysockname;
    socklen_t mysocknamelen=sizeof(mysockname);

    int res=::getsockname(m_listen_socket, (sockaddr*) &mysockname, &mysocknamelen);
    if (res<0) {
        SSL_PRINT(ERR, "%s: listen(): getsockname() listen: %s\n",m_id.c_str(),STRWSAERR(WSAERRNO));
        return 0;
    }

    m_listen_port=ntohs(mysockname.sin_port);

   #ifdef WIN32
    DWORD ul=1;
    if (SOCKET_ERROR==ioctlsocket(m_listen_socket,FIONBIO,&ul)) {
      SSL_PRINT(ERR, "%s: listen(): ioctlsocket(,FIONBIO) listen: %s\n",m_id.c_str(),STRWSAERR(WSAERRNO));
      return 0;
    }
   #else
    fcntl(m_listen_socket,F_GETFL);
    if (res>=0) {
      if (fcntl(m_listen_socket,F_SETFL,res|O_NONBLOCK)<0) {
        SSL_PRINT(ERR, "%s: listen(): fnctl(,F_SETFL) listen: %s\n",m_id.c_str(),STRWSAERR(WSAERRNO));
        return 0;
      }
    } else {
      SSL_PRINT(ERR, "%s: fnctl(,F_GETFL) listen: %s\n",m_id.c_str(),STRWSAERR(WSAERRNO));
      return 0;
    }
   #endif
    if (::listen(m_listen_socket, 1)<0) {
      SSL_PRINT(ERR, "%s: listen(): %s\n",m_id.c_str(),strerror(errno));
      return 0;
    }
    set_fd(m_listen_socket);
    SSL_PRINT(DEBUG, "%s: listen(): listening on port %d\n",m_id.c_str(),m_listen_port);
  }
  m_accept_timeout=time(NULL);
  return m_listen_port;
}

bool Server::accept() {
  if (get_event(m_listen_socket)) {
    struct sockaddr_in sockaddr_client;
    socklen_t sockaddrlen=sizeof(sockaddr_client);
    int new_transport_socket = ::accept(m_listen_socket, (struct sockaddr *)&sockaddr_client, &sockaddrlen);
    if (new_transport_socket<0) {
     #ifdef WIN32
      if (WSAERRNO==WSAEWOULDBLOCK || WSAERRNO==WSAEINTR) {
     #else
      if (errno==EAGAIN || errno==EWOULDBLOCK || errno==EINTR) {
     #endif
        SSL_PRINT(DEBUG, "%s: accept(): %s\n",m_id.c_str(),STRWSAERR(WSAERRNO));
      } else {
        SSL_PRINT(ERR, "%s: accept(): %s\n",m_id.c_str(),STRWSAERR(WSAERRNO));
        if (!isConnected()) return false;
      }
    } else {
      SSL_PRINT(DEBUG, "%s: accept(): connection request from %s\n",m_id.c_str(),inet_ntoa(sockaddr_client.sin_addr));
      if (isConnected()) {
        SSL_PRINT(WARN, "%s: accept(): already connected - refuse new connection\n",m_id.c_str());
        closesocket(new_transport_socket);
      } else {
        if (!Transport::connect(new_transport_socket)) return false;
        SSL_PRINT(DEBUG, "%s: accept(): connected\n",m_id.c_str());
        return true;
      } 
    }
  }
  return true;
}

bool Server::go() {
  if (isConnected()) {
    if (!Transport::transport()) return false;
  }

  if (!isListening()) {
    if (!listen()) return false;
  } else {
    if (!accept()) return false;
  }

  if (isListening() && !isConnected()) {
    if (time(NULL)>m_accept_timeout+12) {
      closeconn();
      SSL_PRINT(DEBUG, "%s: go(): accept timeout\n",m_id.c_str());
      return false;
    }
  }

  if (m_stop) {
    closeconn();
    return false;
  }

  return true;
}

void Server::closeconn() {
  Transport::closeconn();
  if (m_listen_socket>=0) ::closesocket(m_listen_socket);
  m_listen_socket=-1;
  m_stop=true;
}
