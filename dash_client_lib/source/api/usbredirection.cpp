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
/**
 * usbredirection.h
 * A class representing a usb redirection.
 */
#include <dsdk/oal/CIM_USBRedirectionSAP.h>
#include <dsdk/oal/CIM_RemoteServiceAccessPoint.h>
#include <dsdk/oal/CIM_RemoteAccessAvailableToElement.h>
// #include <dsdk/oal/CIM_EnabledLogicalElementCapabilities.h>
// #include <dsdk/oal/CIM_ElementCapabilities.h>
#include <dsdk/oal/CIM_ServiceAccessBySAP.h>
#include <dsdk/usbredirection.h>
#include <dsdk/dsdkexception.h>
#include <dsdk/cimcapabilities.h>
#include "apiimp.h"
//#include <dos.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <net/if.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#endif 

#define DASHWEBSERVER TEXT("DashWebServer")

using namespace dsdk;

/*
 * Constructor
 */
CUSBRedirection::CUSBRedirection (const CIM_USBRedirectionSAP& usbr)
{ 
	_usbr = new CIM_USBRedirectionSAP (usbr); 
}

/*
 * Constructor
 */
CUSBRedirection::CUSBRedirection (const CUSBRedirection& usbr)
{
	this->_usbr = new CIM_USBRedirectionSAP (*(usbr._usbr));
}

/*
 * Destruction 
 */
CUSBRedirection::~CUSBRedirection ()
{
	if (this->_usbr) { delete this->_usbr; }
}

/*
 * Assignment operator
 */
const CUSBRedirection& 
CUSBRedirection::operator = (const CUSBRedirection& rhs)
{
	if (this->_usbr) { delete this->_usbr; }
	this->_usbr  = new CIM_USBRedirectionSAP (*rhs._usbr);
	return *this;
}

/*
 * enumerateOperatingSystems
 */
CUSBRedirection::iterator 
CUSBRedirection::enumUSBRedirections (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_USBRedirectionSAP::iterator iter = 
		CIM_USBRedirectionSAP::enumInstances (client, 0, props);

	if (cached) { return createIterator (iter, props);  	  }
	else 		{ return createIterator (iter); }
}

/*
 * getSystemCreationClassName
 */
string 
CUSBRedirection::getSystemCreationClassName (void) const
{
	return _usbr->getSystemCreationClassName ();
}

/*
 * getSystemName
 */
string 
CUSBRedirection::getSystemName (void) const
{
	return _usbr->getSystemName ();
}
/*
 * getName
 */
string
CUSBRedirection::getName (void) const
{
	return _usbr->getName ();
}

/*
 * getCreationClassName
 */
string 
CUSBRedirection::getCreationClassName (void) const
{
	return _usbr->getCreationClassName ();
}

/*
 * getElementName
 */
string 
CUSBRedirection::getElementName (void) const
{
	return _usbr->getElementName ();
}

/*
 * getEnabledState
 */
uint16 
CUSBRedirection::getEnabledState (void) const
{
	return _usbr->getEnabledState ();
}

/*
 * getEnabledState
 */
string
CUSBRedirection::getEnabledStateStr (void) const
{
	return CIM_USBRedirectionSAP::getValueStr_EnabledState (_usbr->getEnabledState ());
}

/*
 * getRequestedState
 */
uint16
CUSBRedirection::getRequestedState (void) const
{
	return _usbr->getRequestedState ();
}

/*
 * getRequestedStateStr
 */
string
CUSBRedirection::getRequestedStateStr (void) const
{
	return CIM_USBRedirectionSAP::getValueStr_RequestedState (_usbr->getRequestedState ());
}

/*
 * getConnectionMode
 */
string
CUSBRedirection::getConnectionMode (void) const
{
	return _usbr->getValueStr_ConnectionMode (_usbr->getConnectionMode ());
}

/*
 * getResetTimeout
 */
datetime
CUSBRedirection::getResetTimeout (void) const
{
	return _usbr->getResetTimeout ();
}

/*
 * getSessionTimeout
 */
datetime
CUSBRedirection::getSessionTimeout (void) const
{
	return _usbr->getSessionTimeout ();
}

/*
 * activate
 */
int
CUSBRedirection::activate (void) const
{
	uint32				ret;
	uint32				ret1;
	datetime 			immediate = CCIMDateTime (0, true);
	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

	vector<string> ignore;
	vector<string>	empty_props;
	ignore.push_back ("TimeoutPeriod");
//	int  retsupport;
	//CIM_USBRedirectionService::iterator iter = CIM_ServiceAccessBySAP <CIM_USBRedirectionService, CIM_USBRedirectionSAP>::
	//enumerateAntecedent (_usbr->getClient (), *(this->getCIMObject ()), empty_props);
	//if (iter == CIM_USBRedirectionService::iterator::end ())
	//{
	//	throw EFunctionNotSupported ("getProtocolIFType");
	//}
	//CIM_USBRedirectionService usb = *iter;

	// This func call verifies whether the USBRS instance exiest and returns USBRS instance. 
	CIM_USBRedirectionService usb(CCIMInstance::nullInstance());
	if(capableOfUSBRServiceRequestStatesChange(usb) == false)
	{
		throw EFunctionNotSupported ("activate");
	}
	// Verifies whether activate operation is supported or not.
	if (isSupportedRequestStates (usb,CIM_EnabledLogicalElementCapabilities::RequestedStatesSupported_Enabled) == false)
	{
		throw EFunctionNotSupported ("activate");
	}

	/*if (0 != (ret1 = this->usbenablesupport().size()))
	 { */
		ret1 = usb.RequestStateChange (CIM_USBRedirectionService::RequestStateChange_RequestedState_Enabled,
									  &job,
									  immediate,
									  ignore);
		if (ret1 == 4096)
		{
			int currJobState = job.getJobState();
			if (currJobState != 7){
			string retcodestr1 = usb.getValueStr_RequestStateChange_ReturnCode(ret1);
			throw EFunctionReturnedWithFailure ("CIM_USBRedirectionService::RequestStateChange", retcodestr1, ret1);
			}
		}else if (ret1 != 0) {
			string retcodestr1 = usb.getValueStr_RequestStateChange_ReturnCode(ret1);
			throw EFunctionReturnedWithFailure ("CIM_USBRedirectionService::RequestStateChange", retcodestr1, ret1);
		}
		
	/* }
	else
	{ fprintf (stderr, "Requested State Change Not Supported.");
	return 1;} */

	/* if (0 != (retsupport = this->enablesupport().size()))
	{ */
		ret = _usbr->RequestStateChange (CIM_USBRedirectionSAP::RequestStateChange_RequestedState_Enabled,
									  &job,
									  immediate, 
								  ignore);
		if (ret == 4096) {
			int currJobState = job.getJobState();
			if (currJobState != 7){
			string retcodestr = _usbr->getValueStr_RequestStateChange_ReturnCode(ret);
			throw EFunctionReturnedWithFailure ("CIM_USBRedirectionSAP::RequestStateChange", retcodestr, ret);
			}
			
		}else if (ret != 0) {
			string retcodestr = _usbr->getValueStr_RequestStateChange_ReturnCode(ret);
			throw EFunctionReturnedWithFailure ("CIM_USBRedirectionSAP::RequestStateChange", retcodestr, ret);

		}
		return 0;
	/*}
	else
	{ fprintf (stderr, "Requested State Change Not Supported."); 
		return 1;} */
}

/*
 * disabled
 */
void
CUSBRedirection::disable (void) const
{

	uint32				ret;
	uint32				ret1;
	datetime 			immediate = CCIMDateTime (0, true);
	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

	vector<string> ignore;
	vector<string>	empty_props;
	ignore.push_back ("TimeoutPeriod");

	// This func call verifies whether the USBRS instance exiest and returns USBRS instance. 
	CIM_USBRedirectionService usb(CCIMInstance::nullInstance());
	if(capableOfUSBRServiceRequestStatesChange(usb) == false)
	{
		throw EFunctionNotSupported ("disable");
	}
	// Verifies whether activate operation is supported or not.
	if (isSupportedRequestStates (usb,CIM_EnabledLogicalElementCapabilities::RequestedStatesSupported_Disabled) == false)
	{
		throw EFunctionNotSupported ("disable");
	}

/*	if (0 != (retsupport = this->enablesupport().size()))
	{ */
		ret = _usbr->RequestStateChange (CIM_USBRedirectionSAP::RequestStateChange_RequestedState_Disabled,
									  &job,
									  immediate,
									  ignore);
		if (ret == 4096)
		{
			int currJobState = job.getJobState();
			if (currJobState != 7){
			string retcodestr = _usbr->getValueStr_RequestStateChange_ReturnCode(ret);
			throw EFunctionReturnedWithFailure ("CIM_USBRedirectionSAP::RequestStateChange", retcodestr, ret);
			}
		}else if (ret != 0) {
			string retcodestr = _usbr->getValueStr_RequestStateChange_ReturnCode(ret);
			throw EFunctionReturnedWithFailure ("CIM_USBRedirectionSAP::RequestStateChange", retcodestr, ret);

		}	
	
/*	}	else
	{ fprintf (stderr, "Requested State Change Not Supported."); } */	

/*	if (0 != (retsupport = this->usbenablesupport().size()))
	{ */
		ret1 = usb.RequestStateChange(CIM_USBRedirectionService::RequestStateChange_RequestedState_Disabled,
								  &job,
								  immediate);
	
		/* if set attribute is success return 0, else throw EFunctionReturnedWithFailure execption */
		if (ret1 == 4096)
		{
			int currJobState = job.getJobState();
			if (currJobState != 7){
			string retcodestr = _usbr->getValueStr_RequestStateChange_ReturnCode(ret);
			throw EFunctionReturnedWithFailure ("CIM_USBRedirectionService::RequestStateChange", retcodestr, ret);
			}
		}else if (ret1 != 0) {
			string retcodestr = _usbr->getValueStr_RequestStateChange_ReturnCode(ret);
			throw EFunctionReturnedWithFailure ("CIM_USBRedirectionService::RequestStateChange", retcodestr, ret);

		}
		return;
	/* }
	else
	{ fprintf (stderr, "Requested State Change Not Supported."); } */

}
void GetPort(char *val)
{
	char * config_file;
	FILE		*fp;
	char		line[512],opt[512];
	size_t		line_no = 0;
	config_file = getenv ("MONGOOSE_CONF");
	if (config_file==NULL)
	{
		sscanf("8080","%s",val);
		return;
	}
		
	fp = fopen(config_file, "r");
	if (fp == NULL) {
		//fprintf(stderr, "cannot open config file %s: %s\n",config_file, strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	/* Loop over the lines in config file */
	while (fgets(line, sizeof(line), fp) != NULL) {

		line_no++;

		/* Ignore empty lines and comments */
		if (line[0] == '#' || line[0] == '\n')
			continue;

		if (sscanf(line, "%s %[^\r\n#]", opt, val) != 2) {
			fprintf(stderr, "%s: line %d is invalid\n",
			    config_file, (int) line_no);
			exit(EXIT_FAILURE);
		}
		if (strcmp(opt, "ports") == 0 )
		{
			break;
		}
	}

	(void) fclose(fp);
}

bool isServiceExisits()
{

#ifdef _WIN32
	SC_HANDLE schSCManager = OpenSCManager( NULL, NULL, SC_MANAGER_ALL_ACCESS); 
	if (schSCManager==0) 
		return false;
	SC_HANDLE schService = OpenService( schSCManager, DASHWEBSERVER, SERVICE_ALL_ACCESS);
	if (schService==0) 
		return false;	

	CloseServiceHandle(schService); 
	CloseServiceHandle(schSCManager); 
#endif

	return true;
}
/*
 * startFolderRedirection
 */
int 
CUSBRedirection::startFolderRedirection (string path, string defaultServer) const
{
	vector<string> empty_props;
	string ip = "";			 
    char hostName[255],port[512];

	CIM_RemoteServiceAccessPoint rmsrv(CCIMInstance::nullInstance());
	// This func call verifies whether the USBRS instance exiest and returns USBRS instance. 
	if(capableOfFolderRedirection(rmsrv) == false)
	{
		throw EFunctionNotSupported ("FolderRedirection");
	}

	if(strcasecmp(defaultServer.c_str(), "true") == 0)
	{
		GetPort(port);
		while(path.find(" ") != string::npos)
		{
			path.replace(path.find(" "), 1, "%20");
		}
#ifdef _WIN32
		if(!isServiceExisits())
		{
			//ShellExecute(NULL,NULL,L"webserver.exe",L"-i",NULL,SW_HIDE);
			string command = "webserver.exe -i";
			if (-1 == system (command.c_str ()))
			{
				fprintf(stdout,"\n system (%s)\n",command.c_str ());
				return -1;
			}
		}
		else
		{
			///ShellExecute(NULL,NULL,L"webserver.exe",L"-r",NULL,SW_HIDE);
			string command = "webserver -s";
			if (-1 == system (command.c_str ()))
			{
				fprintf(stdout,"\n system (%s)\n",command.c_str ());
				return -1;
			}
			command = "webserver -r";
			if (-1 == system (command.c_str ()))
			{
				fprintf(stdout,"\n system (%s)\n",command.c_str ());
				return -1;
			}

		}
		PHOSTENT hostinfo;
		WSAData wsaData;
		
		if ( WSAStartup( MAKEWORD(2, 2), &wsaData ) == 0 )
		{
			if( gethostname ( hostName, sizeof(hostName)) == 0)
			{
				if((hostinfo = gethostbyname(hostName)) != NULL)
				{
					ip = inet_ntoa (*(struct in_addr *)*hostinfo->h_addr_list);
				}
			}
		}				
		WSACleanup();
		string webaddr = "http://" + ip + ":" + port + "/" + path;
		path.clear();
		path.append(webaddr);
#else
		string command = "LD_LIBRARY_PATH=../lib ./webserver";
		if (-1 == system (command.c_str ()))
		{
			fprintf(stdout,"\n system (%s)\n",command.c_str ());
			return -1;
		}
		int fd;
		struct ifreq req;

		if((fd = socket(PF_INET, SOCK_DGRAM, 0)) != -1)
		{
			strncpy(req.ifr_name, "eth0", IFNAMSIZ);
			if (ioctl(fd, SIOCGIFADDR, &req) < 0)
				perror("ioctl");
			else		
				ip = inet_ntoa(((struct sockaddr_in*) &req.ifr_addr)->sin_addr);					
			if(close(fd)!=0)
				perror("close");		
		}
		string address = "http://" + ip + ":" + port + "/" + path;
		std::string webaddr = "";

		int i = 0;
		while(address.find("//") != string::npos)
		{
			i++;
			if(i > 1)
				address.replace(address.find("//"), 2, "/");
			webaddr.append(address.substr(0,address.find("//")+1));
			address = address.substr(address.find("//")+1,address.size());
		}
		webaddr.append(address);
		path.clear();
		path.append(webaddr);
#endif	
				
	}
	/* set the samba/nfs path */
	rmsrv.setAccessInfo (path);
	return this->activate ();	
}

/*
 * EnabledSupport for CIM_USBRedirectionSAP
 */
/* vector<uint16>
CUSBRedirection::enablesupport (void) const
{ 
vector<string>	empty_props;
CIM_EnabledLogicalElementCapabilities::iterator eleciter = CIM_ElementCapabilities <CIM_USBRedirectionSAP, CIM_EnabledLogicalElementCapabilities>::
enumerateCapabilities (_usbr->getClient (), *(this->getCIMObject ()), empty_props);

if (eleciter == CIM_EnabledLogicalElementCapabilities::iterator::end ())
{
	fprintf (stdout, "ELEC  Instance is not Found:");
} 
CIM_EnabledLogicalElementCapabilities ems = *eleciter;
return ems.getRequestedStatesSupported();
	
} */

/*
 * EnabledSupport for CIM_USBRedirectionService
 */
/* vector<uint16>
CUSBRedirection::usbenablesupport (void) const
{ 
vector<string>	empty_props;
CIM_USBRedirectionService::iterator iter = CIM_ServiceAccessBySAP <CIM_USBRedirectionService, CIM_USBRedirectionSAP>::
	enumerateAntecedent (_usbr->getClient (), *(this->getCIMObject ()), empty_props);

if (iter == CIM_USBRedirectionService::iterator::end ())
{
	throw EFunctionNotSupported ("getProtocolIFType");
}

CIM_USBRedirectionService usb = *iter;
CIM_USBRedirectionCapabilities::iterator eleciter = CIM_ElementCapabilities <CIM_USBRedirectionService, CIM_USBRedirectionCapabilities>::
enumerateCapabilities (_usbr->getClient (), usb, empty_props);

if (eleciter == CIM_USBRedirectionServiceCapabilities::iterator::end ())
{
	fprintf (stdout, "USBRedirectionServiceCapabilities  Instance is not Found:");

} 

CIM_USBRedirectionServiceCapabilities ems = *eleciter;
	
return ems.getRequestedStatesSupported();
	
} */
/*
 * getCachedProps
 */


bool CUSBRedirection::capableOfFolderRedirection(CIM_RemoteServiceAccessPoint &rmsrv) const
{
	vector<string> empty_props;

	/* NFS/Samba folder redirection are only supported if the USB redirection connection more is 'Connect' 
	  so check for connecton mode */
	if (_usbr->getConnectionMode () != 3)
	{
		return false;
	}

	/* enumerate the CIM_RemoteServiceAccessPoint associated with this usbredirection instance */
	CIM_RemoteServiceAccessPoint::iterator iter = CIM_RemoteAccessAvailableToElement <CIM_RemoteServiceAccessPoint,
								CIM_USBRedirectionSAP>::enumerateAntecedent (_usbr->getClient(),
																		    *(this->getCIMObject ()),
																			empty_props);
	if (iter == CIM_RemoteServiceAccessPoint::iterator::end ())
	{
		return false;
	}

	/* only one instance of RemoteService Access Point will be associated with USBRedirectionSAP use first instance */
	rmsrv = *iter;
	return true;
}

bool CUSBRedirection::capableOfFolderRedirection() const
{
	CIM_RemoteServiceAccessPoint rmsrv(CCIMInstance::nullInstance());
	return capableOfFolderRedirection(rmsrv);
}


bool CUSBRedirection::capableOfUSBRSAPRequestStatesChange(CIM_USBRedirectionService &usb) const
{
	vector<string>	empty_props;

	// Verifies whether the USBRedirectionServic instance exists or not.
	CIM_USBRedirectionService::iterator iter = CIM_USBRedirectionService::
				enumInstances(_usbr->getClient(),0, empty_props);
	if (iter == CIM_USBRedirectionService::iterator::end ())
	{
		return false;
	}
	usb = (CIM_USBRedirectionService)*iter;

	// Verify whether atleast one SAP instance associated with USBRS exists or not.
	CIM_USBRedirectionSAP::iterator sapiter = CIM_ServiceAccessBySAP<CIM_USBRedirectionService, CIM_USBRedirectionSAP>::
		enumerateDependent(this->_usbr->getClient(), usb, empty_props);

	if ( sapiter == CIM_USBRedirectionSAP::iterator::end () )
		return false;

	CIM_USBRedirectionSAP usbrsap = * sapiter;

	vector<uint16> states = CCIMCapabilities::getSupportedStates(_usbr->getClient(), usbrsap);
	// Verifies whether the RequestedStatesSupported array contains at least one value
	if (states.size() == 0 )
		return false;

	return true;
}

bool CUSBRedirection::capableOfUSBRSAPRequestStatesChange(void) const
{
	CIM_USBRedirectionService usbr (CCIMInstance::nullInstance());
	return capableOfUSBRSAPRequestStatesChange(usbr);
}



bool CUSBRedirection::capableOfUSBRServiceRequestStatesChange(CIM_USBRedirectionService &usb) const
{
	vector<string>	empty_props;

	// Verifies whether the USBRedirectionServic instance exists or not.
	CIM_USBRedirectionService::iterator iter = CIM_USBRedirectionService::
				enumInstances(_usbr->getClient(),0, empty_props);

	if (iter == CIM_USBRedirectionService::iterator::end ())
	{
		return false;
	}
	usb = *iter;

	vector<uint16> states = CCIMCapabilities::getSupportedStates(_usbr->getClient(), usb);
	// Verifies whether the RequestedStatesSupported array contains at least one value
	if (states.size() == 0 )
		return false;

	return true;
}

bool CUSBRedirection::capableOfUSBRServiceRequestStatesChange(void) const
{
	CIM_USBRedirectionService usb(CCIMInstance::nullInstance());
	return capableOfUSBRServiceRequestStatesChange(usb);
}

bool CUSBRedirection::isSupportedRequestStates (CIM_USBRedirectionService &usb, uint16 checkVal) const
{
	if ( capableOfUSBRServiceRequestStatesChange(usb) == false )
		return false ;

	return CCIMCapabilities::isSupportedValue(_usbr->getClient(), usb, checkVal); 
}	

bool
CUSBRedirection::getSupportedStates(vector<uint16> &states_val) const
{	
	CIM_USBRedirectionService usb(CCIMInstance::nullInstance());
	if ( capableOfUSBRServiceRequestStatesChange(usb) )
		states_val = CCIMCapabilities::getSupportedStates(_usbr->getClient(), usb);

	if (states_val.size() == 0 )
		return false;

	return true;
}

bool
CUSBRedirection::getSupportedStatesStr(vector<string> &states_str) const
{	
	CIM_USBRedirectionService usb(CCIMInstance::nullInstance());
	if ( capableOfUSBRServiceRequestStatesChange(usb) )
		states_str = CCIMCapabilities::getSupportedStatesStr(_usbr->getClient(), usb);

	if (states_str.size() == 0 )
		return false;

	return true;
}


vector<string> 
CUSBRedirection::getCachedProps (void)
{
	vector<string> props;

	props.push_back ("SystemCreationClassName");
	props.push_back ("SystemName");
	props.push_back ("Name");
	props.push_back ("CreationClassName");
	props.push_back ("ElementName");
	props.push_back ("EnabledState");
	props.push_back ("RequestedState");
	props.push_back ("ConnectionMode");
	props.push_back ("ResetTimeout");
	props.push_back ("SessionTimeout");
	return props;
}

/*
 * USBRedirection::Iterator
 */
DEFINE_API_ITERATOR (CUSBRedirection);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CUSBRedirection, CIM_USBRedirectionSAP);
