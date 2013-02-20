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

#ifdef WIN32
  #include <io.h>
  #define EINTR WSAEINTR
#else
  #include <sys/ioctl.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
#endif

#include "log.h"

#include "transport.h"

bool Transport::m_stop=false;
//---------------Transport-----------------------------------------------------

fd_set * Transport::g_fdset[2]={NULL,NULL};
fd_set * Transport::g_event[2]={NULL,NULL};
int Transport::g_maxfd=0;
int Transport::g_refcount=0;

Transport::Transport(std::string _id):m_id(_id) {
  if (!g_refcount) {
    for (int s=0;s<2;s++) {
      assert(!g_fdset[s]);
      g_fdset[s]=new fd_set;FD_ZERO(g_fdset[s]);
      assert(!g_event[s]);
      g_event[s]=new fd_set;FD_ZERO(g_event[s]);
    }
  }
  m_buffer=new char[BUFSIZE];
  m_buffer_used_bytes=0;
  m_buffer_pos=0;
  m_transport_socket=-1;
  m_conn_type=ConnTypeUnknown;
  m_transport_to=0;
  g_refcount++;
}

Transport::~Transport() {
  g_refcount--;
  assert(g_fdset[0] && g_fdset[1]);
  assert(g_event[0] && g_event[1]);
  if (!g_refcount) {
    for (int s=0;s<2;s++) {
      delete g_fdset[s];g_fdset[s]=0;
      delete g_event[s];g_event[s]=NULL;
    }
  }
  delete m_buffer;
  SSL_PRINT(TRACE, "%s: ~Transport(): Transport deleted\n",m_id.c_str());
}

ssize_t Transport::read(char *buf, size_t count) {
 #ifdef _WIN32
  if (m_conn_type==ConnTypeSocket) return ::recv(m_transport_socket,buf,count,0);
  else
 #endif
  return ::read(m_transport_socket,buf,count);
}

ssize_t Transport::write(const char *buf, size_t count) {
 #ifdef _WIN32
  if (m_conn_type==ConnTypeSocket) return ::send(m_transport_socket,buf,count,0);
  else
 #endif
  return ::write(m_transport_socket,buf,count);
}

void Transport::clr_fd(int i, bool wr) {
 #ifndef WIN32
  assert(i>=0 && i<FD_SETSIZE);
  if (i>=0 && i<FD_SETSIZE) 
 #endif
  {
    FD_CLR(i,g_fdset[wr]);
    FD_CLR(i,g_event[wr]);
  }
}

void Transport::set_fd(int i,bool wr) {
 #ifndef WIN32
  assert(i>=0 && i<FD_SETSIZE);
  if (i>=0 && i<FD_SETSIZE) 
 #endif
  {
    if (i>=g_maxfd) g_maxfd=i+1;
    FD_SET(i,g_fdset[wr]);
  }
}

bool Transport::get_event(int i,bool wr) {
 #ifndef WIN32
  assert(i>=0 && i<FD_SETSIZE);
  if (i>=0 && i<FD_SETSIZE)
 #endif
  {
    if (FD_ISSET(i,g_event[wr])) {
      FD_CLR(i,g_event[wr]);
      return true;
    }
  }
  return false;
}

bool Transport::wait_for_event(void) {
  //SSL_PRINT(TRACE, "wait_for_g_event()\n");
  static fd_set fdtemp[2];
  FD_ZERO(fdtemp+0);
  FD_ZERO(fdtemp+1);
  struct timeval tv;
  tv.tv_usec = 500*1000;
  tv.tv_sec = 0;
  for (int s=0;s<2;s++) for (int i=0;i<g_maxfd;i++) if (FD_ISSET(i,g_fdset[s])) FD_SET(i,fdtemp+s);
  int res=select(g_maxfd, fdtemp+0, fdtemp+1, NULL, &tv);
  if (res<0) {
      if (WSAERRNO!=EINTR) {
          SSL_PRINT(ERR, "wait_for_event() select(): %s",STRWSAERR(WSAERRNO));
      }  else  {
          SSL_PRINT(TRACE, "wait_for_event() select(): %s",STRWSAERR(WSAERRNO));
          res=0;
      }
  } else if (res>0) {
      for (int s=0;s<2;s++) for (int i=0;i<g_maxfd;i++) if (FD_ISSET(i,fdtemp+s)) FD_SET(i,g_event[s]);
  }
  //SSL_PRINT(TRACE, "wait_for_event() end (%d,%d)\n",m_stop,res);
  return !m_stop && res>=0;
}

bool Transport::connect(int _transport_socket) {
  m_transport_socket=_transport_socket;
  set_fd(m_transport_socket);
  if (!setup_encryption()) {
    SSL_PRINT(DEBUG, "%s: connect(): setup_encryption() failed\n",m_id.c_str());
    if (m_transport_to && m_transport_to->isConnected()) {
        char msg[0x100];
        _snprintf(msg,sizeof(msg),"* Setup for encryption failed\n");
        m_transport_to->write(msg,strlen(msg));
    }
    closeconn();
    return false; 
  }
  if (m_conn_type==ConnTypeUnknown) {
      SSL_PRINT(WARN, "%s: connect(): unknown connection type (m_conn_type==ConnTypeUnknown)\n",m_id.c_str());
  }
  if (m_conn_type==ConnTypeSocket) {
    int bufsize = BUFSIZE;
    if (setsockopt(m_transport_socket, SOL_SOCKET, SO_SNDBUF, (char *)&bufsize, sizeof(bufsize))<0) {
      SSL_PRINT(ERR, "%s: connect(): setsockopt(): %s\n",m_id.c_str(),STRWSAERR(WSAERRNO));
      closeconn();
      return false;
    }
  
    struct timeval timer;
    const int RCVTIMEOUT=100;
    timer.tv_sec  =  RCVTIMEOUT / 1000;
    timer.tv_usec = (RCVTIMEOUT % 1000) * 1000;
    if (setsockopt(m_transport_socket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timer, sizeof(timer)) < 0) {
      SSL_PRINT(ERR, "%s connect(): setsockopt() SO_RCVTIMEO: %s\n",m_id.c_str(),STRWSAERR(WSAERRNO));
      closeconn();
      return false;
    }
  
    const int SNDTIMEOUT=100;
    timer.tv_sec  =  SNDTIMEOUT / 1000;
    timer.tv_usec = (SNDTIMEOUT % 1000) * 1000;
    if (setsockopt(m_transport_socket, SOL_SOCKET, SO_SNDTIMEO, (char *)&timer, sizeof(timer)) < 0) {
      SSL_PRINT(ERR, "%s connect(): setsockopt() SO_SNDTIMEO: %s\n",m_id.c_str(),STRWSAERR(WSAERRNO));
      closeconn();
      return false;
    }
  }
  m_buffer_used_bytes=m_buffer_pos=0;
  return true;
}

bool Transport::send(const char * ptr, int * start, int * size) {
  assert(*size>0 && *size<=BUFSIZE);
  assert(*start>=0 && *start<BUFSIZE);
  assert(*start<*size);
  int res=write(ptr+*start,*size-*start);
  if (res<0) {
   #ifdef WIN32
    if (WSAERRNO==WSAEWOULDBLOCK || WSAERRNO==WSAEINTR) {
   #else
    if (errno==EAGAIN || errno==EWOULDBLOCK || errno==EINTR) {
   #endif
      SSL_PRINT(TRACE, "%s: send(): nothing sent, %s\n",m_id.c_str(),STRWSAERR(WSAERRNO));
      return true;
    } else {
      SSL_PRINT(DEBUG, "%s: send(): nothing sent, %s\n",m_id.c_str(),STRWSAERR(WSAERRNO));
      closeconn();
      return false;
    }
  } else if (res==0) {
    SSL_PRINT(DEBUG, "%s: send(): 0/%d bytes sent -> DISCONNECT\n",m_id.c_str(),*size-*start);
    closeconn();
    return true;
  } else {
    SSL_PRINT(TRACE, "%s: send() %d/%d bytes sent\n",m_id.c_str(),res,*size-*start);
    if (*start+res==*size) {
       if (*start>0) clr_fd(m_transport_socket,true);
       *start=*size=0;
    } else {
       *start+=res;
       assert(*start<*size);
       set_fd(m_transport_socket,true);
    }
    return true;
  }
}

bool Transport::transport() {
  while (isConnected()) {
    //send queued bytes from m_buffer
    if (m_buffer_used_bytes) {
      assert(m_buffer);
      if (m_transport_to && m_transport_to->isConnected()) {
        SSL_PRINT(TRACE, "%s: transport(): try to send %d bytes data to %s\n",m_id.c_str(),m_buffer_used_bytes-m_buffer_pos,m_transport_to->m_id.c_str());
        if (!m_transport_to->send(m_buffer,&m_buffer_pos,&m_buffer_used_bytes)) {
            return false;
        }
      }
    }

    //check for receive g_event
    if (m_buffer_used_bytes<BUFSIZE && get_event(m_transport_socket)) {
      SSL_PRINT(TRACE, "%s: transport(): receive g_event\n",m_id.c_str());
      assert(m_buffer);
      int res=read(m_buffer+m_buffer_used_bytes,BUFSIZE-m_buffer_used_bytes);
      if (res==0) {
        SSL_PRINT(DEBUG, "%s: transport(): read(): normal DISCONNECT\n",m_id.c_str());
        closeconn();
      }
      if (res<0) {
       #ifdef WIN32
        if (WSAERRNO==WSAEWOULDBLOCK || WSAERRNO==WSAEINTR) {
       #else
        if (errno==EAGAIN || errno==EWOULDBLOCK || errno==EINTR) {
       #endif
          SSL_PRINT(TRACE, "%s: transport(): read(): %s\n",m_id.c_str(),STRWSAERR(WSAERRNO));
        } else {
          SSL_PRINT(DEBUG, "%s: transport(): read(): %s -> DISCONNECT\n",m_id.c_str(),STRWSAERR(WSAERRNO));
          closeconn();
          return false;
        }
      } else {
        m_buffer_used_bytes+=res;
      }
    } else break;
  }
  return true;
}

void Transport::set_transport_target(class Transport * _transport_to) {
  m_transport_to=_transport_to;
}

void Transport::closeconn() {
  if (m_transport_socket<0) return;
  SSL_PRINT(DEBUG, "%s: closeconn(): close connection\n",m_id.c_str());
  clr_fd(m_transport_socket);
  clr_fd(m_transport_socket,true);
  ::closesocket(m_transport_socket);
  m_transport_socket=-1;
  if (m_transport_to && m_transport_to->isConnected()) m_transport_to->closeconn();
 }
