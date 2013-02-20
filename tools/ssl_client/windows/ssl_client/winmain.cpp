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

#include <winsock2.h>
#include "../../src/log.h"

extern int main(int argc, char *argv[]);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

  main(__argc,__argv);
	return 0;
}

extern void winprint(const char * msg, ...) {
 #ifdef DEBUGFILE
  va_list argptr;
  va_start(argptr,msg);
  if (msg && *msg) {
    FILE * f=fopen(DEBUGFILE,"a");
    if (f) {
      vfprintf(f,msg,argptr);
      fclose(f);
    }
  }
  va_end(argptr);
 #endif
}

extern void winprint_m(const char * msg, ...) {
  if (msg && *msg) {
    va_list argptr;
    va_start(argptr,msg);
    char buffer[0x100];
    buffer[0]=0;
    _vsnprintf(buffer,sizeof(buffer),msg,argptr);
    buffer[sizeof(buffer)-1]=0;
    winprint(buffer);    
    MessageBox(NULL,buffer,"SSL Client",MB_OK);
    va_end(argptr);
  }
}

extern const char * WSAGetLastErrorString(int error) {
	switch(error)
	{
		case 0                    : break;		
		case WSAEACCES            : return "Access denied";		
		case WSAEADDRINUSE        : return "Address already in use";		
		case WSAEADDRNOTAVAIL     : return "Cannot assign requested address";
		case WSAEAFNOSUPPORT      : return "Address family not supported by protocol family";
		case WSAEALREADY          : return "Operation already in progress";		
		case WSAECONNABORTED      : return "Software caused connection abort";		
		case WSAECONNREFUSED      : return "Connection refused";		
		case WSAECONNRESET        : return "Connection reset by peer";		
		case WSAEDESTADDRREQ      : return "Destination address required. ";		
		case WSAEFAULT            : return "Bad address";		
		case WSAEHOSTDOWN         : return "Host is down";		
		case WSAEHOSTUNREACH      : return "No route to host";		
		case WSAEINPROGRESS       : return "Operation now in progress";		
		case WSAEINTR             : return "Interrupted function call";		
		case WSAEINVAL            : return "Invalid argument";		
		case WSAEISCONN           : return "Socket is already connected";		
		case WSAEMFILE            : return "Too many open files";		
		case WSAEMSGSIZE          : return "Message too long";		
		case WSAENETDOWN          : return "Network is down";		
		case WSAENETRESET         : return "Network dropped connection on reset";		
		case WSAENETUNREACH       : return "Network is unreachable";		
		case WSAENOBUFS           : return "No buffer space available";		
		case WSAENOPROTOOPT       : return "Bad protocol option";		
		case WSAENOTCONN          : return "Socket is not connected";		
		case WSAENOTSOCK          : return "Socket operation on non-socket";		
		case WSAEOPNOTSUPP        : return "Operation not supported";		
		case WSAEPFNOSUPPORT      : return "Protocol family not supported";		
		case WSAEPROCLIM          : return "Too many processes";		
		case WSAEPROTONOSUPPORT   : return "Protocol not supported";		
		case WSAEPROTOTYPE        : return "Protocol wrong type for socket";		
		case WSAESHUTDOWN         : return "Cannot send after socket shutdown";		
		case WSAESOCKTNOSUPPORT   : return "Socket type not supported";		
		case WSAETIMEDOUT         : return "Connection timed out";		
		case WSAEWOULDBLOCK       : return "Resource temporarily unavailable";		
		case WSAHOST_NOT_FOUND    : return "Host not found";		
		case WSA_INVALID_HANDLE   : return "Specified event object handle is invalid";		
		case WSA_INVALID_PARAMETER: return "One or more parameters are invalid";		
	  //case WSAINVALIDPROCTABLE  : return "Invalid procedure table from service provider";		
      //case WSAINVALIDPROVIDER   : return "Invalid service provider version number";		
		case WSA_IO_PENDING       : return "Overlapped operations will complete later";		
		case WSA_IO_INCOMPLETE    : return "Overlapped I/O event object not in signaled state";		
		case WSA_NOT_ENOUGH_MEMORY: return "Insufficient memory available";		
		case WSANOTINITIALISED    : return "Successful WSAStartup not yet performed";		
		case WSANO_DATA           : return "Valid name, no data record of requested type";		
		case WSANO_RECOVERY       : return "This is a non-recoverable error";		
	  //case WSAPROVIDERFAILEDINIT: return "Unable to initialize a service provider";		
		case WSASYSCALLFAILURE    : return "System call failure";		
		case WSASYSNOTREADY       : return "Network subsystem is unavailable";		
		case WSATRY_AGAIN         : return "Non-authoritative host not found";		
		case WSAVERNOTSUPPORTED   : return "WINSOCK.DLL version out of range";		
		case WSAEDISCON           : return "Graceful shutdown in progress";		
		case WSA_OPERATION_ABORTED: return "Overlapped operation aborted";		
	}
  return "Unknown Winsock error";
}

