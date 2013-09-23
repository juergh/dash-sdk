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
#include <signal.h>
#include <unistd.h>

#ifdef WIN32
  #include <io.h>
  #include <process.h>
  #define getpid _getpid
  #define spawnvp _spawnvp
#else
  #include <sys/wait.h>
  #include <sys/time.h>
  #include <sys/resource.h>
#endif

#include "sslclient.h"
#include "server.h"
#include "log.h"


bool check=false;
int child_pid=0;
bool child_terminated=false;

void sigterm_handler(int) {
  SSL_PRINT(INFO, "sigterm_handler(): terminate (pid=%d)\n",getpid());
  Transport::stop();
}

#ifndef WIN32
void sigchild_handler(int) {
  int status;
  int pid;
  while (0<(pid=waitpid(-1, &status, WNOHANG))) {
    SSL_PRINT(DEBUG, "sigchild_handler(): Child terminated: PID %d (return code %d)\n",pid,status);
    child_terminated=true;
    Transport::stop();
  }
}
#endif

int main (int argc, char *argv[]) {
 #ifdef WIN32
  #ifdef DEBUGFILE
  if (!_access(DEBUGFILE,0)) {
    if (remove(DEBUGFILE)) {
      SSL_PRINT(DEBUG, "cannot remove '%s' : %s\n",DEBUGFILE,strerror(errno));
    }
  }
  #endif  
  WORD wVersionRequested;
  WSADATA wsaData;
  wVersionRequested = MAKEWORD( 2, 0 );
  if(WSAStartup( wVersionRequested, &wsaData )!=0) {
    SSL_PRINT(ERR, "WSAStartup: %s",STRWSAERR(WSAERRNO));
    return false;
  }
 #endif

  signal(SIGTERM, &sigterm_handler);
 #ifndef WIN32
  signal(SIGCHLD, &sigchild_handler);
 #endif

  if (argc<4) {
    SSL_PRINT(ERR, "Syntax: ssl_client <IP> <port> <telnet_client> {<telnet_client_arg>}\n");
    exit(1);
  }

  int port=atoi(argv[2]);
  if (port<1 || port>0xFFFF) {
    SSL_PRINT(ERR, "Invalid port number %s\n",argv[2]);
    exit(1);
  }

  class Server * server=new Server();
  class Client * client=NULL;

  do {
    if (!server->go()) break;

    if (server->isConnected()) {
      if (!client) client=new SSLClient(argv[1],port);
      client->set_transport_target(server);
      server->set_transport_target(client);
    } else if (server->isListening()) {
      if (!child_pid) {
        int listen_port=server->get_port();
        SSL_PRINT(DEBUG, "ssl_client is listening on port %d\n",listen_port);
        char str_port[0x10];
        _snprintf(str_port,sizeof(str_port),"%d",listen_port);
        char ** child_argv = new char*[argc-3+1];
        int i;
        std::string cmdline;
        for (i=0;i<argc-3;i++) {
          if (i>0 && !strcmp(argv[i+3],"%p")) child_argv[i]=str_port;
          else if (i>0 && !strcmp(argv[i+3],"%h")) child_argv[i]=const_cast<char*>("localhost");
         #ifdef WIN32
          else if (strchr(argv[i+3],' ')) {
            child_argv[i]=new char[strlen(argv[i+3])+2+1];
            strcpy(child_argv[i],"\"");
            strcat(child_argv[i],argv[i+3]);
            strcat(child_argv[i],"\"");
          }
         #endif
          else child_argv[i]=argv[i+3];
          if (i>0) cmdline+=' ';
          cmdline+=child_argv[i];
        }
        const char * child_prog=argv[3];

        SSL_PRINT(DEBUG, "start child '%s' : '%s'\n",child_prog,cmdline.c_str());

        child_argv[i]=NULL;
       #ifdef WIN32
        child_pid=spawnvp(_P_NOWAIT,child_prog, const_cast<char* const*>(child_argv));
        if (child_pid<0) {
          SSL_PRINT(ERR, "spawnvp('%s') failed: %s\n",child_prog,strerror(errno));
          break;
        }
       #else
        child_pid=fork();
        if (child_pid<0) {
          SSL_PRINT(ERR, "FATAL: fork failed: %s\n",strerror(errno));
          break;
        } else if (!child_pid) { /* child */
          SSL_PRINT(TRACE, "child\n" );
	  // close all sockets except STDIN, STDOUT, STDERR
	  struct rlimit rlim;
	  int fd, maxFd;
	  maxFd = getrlimit(RLIMIT_NOFILE, &rlim) == 0 ? rlim.rlim_max : 256;
	  for (fd = 3; fd < maxFd; ++fd) close(fd);
	  // exec child process
          execvp(child_prog, const_cast<char* const*>(child_argv));
          SSL_PRINT(ERR, "execcvp('%s') failed: %s\n",child_prog,strerror(errno));
	  exit(1); // exit on error
        } else {
          SSL_PRINT(DEBUG, "child started: PID %d\n",child_pid);
        }
       #endif
      }
    }
    if (client) if (!client->go()) break;
  } while (Transport::wait_for_event());

  if (!child_terminated && child_pid>0) {
    if (server->isConnected()) {
      SSL_PRINT(DEBUG, "child is still connected to server class!\n");
      server->closeconn();
    }
   #ifndef WIN32
    int i;
    for (i=40;i>0;i--) { //wait for 4 seconds
      if (child_terminated) break;
      if (i==20) kill(child_pid,SIGTERM);
      if (i==10) kill(child_pid,SIGKILL);
      Sleep(100);
    }
    if (i) {
	SSL_PRINT(DEBUG, "Child terminated\n");
    } else {
	SSL_PRINT(WARN, "Could not terminate client!\n");
    }
   #endif
  }
  if (client) delete client;
  if (server) delete server;
  SSL_PRINT(DEBUG, "main(): close\n");
 #ifdef WIN32
  WSACleanup();
 #endif
  return 0;
};
