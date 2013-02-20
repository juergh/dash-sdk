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
 * textredirection.h
 * A class representing a text redirection.
 */
#include <dsdk/oal/CIM_TextRedirectionSAP.h>
#include <dsdk/oal/CIM_RedirectionService.h>
#include <dsdk/oal/CIM_ProtocolEndpoint.h>
#include <dsdk/oal/CIM_TCPProtocolEndpoint.h>
#include <dsdk/oal/CIM_EnabledLogicalElementCapabilities.h>
#include <dsdk/oal/CIM_ElementCapabilities.h>
#include <dsdk/oal/CIM_BindsTo.h>
#include <dsdk/oal/CIM_ServiceAccessBySAP.h>
#include <dsdk/textredirection.h>
#include <dsdk/dsdkexception.h>
#include <dsdk/cimcapabilities.h>
#include "apiimp.h"


using namespace dsdk;

/*
 * Constructor
 */
CTextRedirection::CTextRedirection (const CIM_TextRedirectionSAP& tr)
{ 
	_tr = new CIM_TextRedirectionSAP (tr); 
	_tcp = NULL;
	_pe  = NULL;
}

/*
 * Constructor
 */
CTextRedirection::CTextRedirection (const CTextRedirection& tr)
{
	this->_tr = new CIM_TextRedirectionSAP (*(tr._tr));
	if (tr._tcp != NULL)
	{
		this->_tcp = new CIM_TCPProtocolEndpoint (*(tr._tcp));
	}
	else
	{
		this->_tcp = NULL;
	}

	if (tr._pe != NULL)
	{
		this->_pe = new CIM_ProtocolEndpoint (*(tr._pe));
	}
	else
	{
		this->_pe = NULL;
	}
}

/*
 * Destruction 
 */
CTextRedirection::~CTextRedirection ()
{
	if (this->_tr) { delete this->_tr; }
	if (this->_tcp) { delete this->_tcp; }
	if (this->_pe) { delete this->_pe; }
}

/*
 * Assignment operator
 */
const CTextRedirection& 
CTextRedirection::operator = (const CTextRedirection& rhs)
{
	if (this->_tr) { delete this->_tr; }
	this->_tr  = new CIM_TextRedirectionSAP (*rhs._tr);
	
	if (rhs._tcp!= NULL) { this->_tcp = new CIM_TCPProtocolEndpoint (*rhs._tcp);}
	else (this->_tcp = NULL);

	if (rhs._pe!= NULL) { this->_pe = new CIM_ProtocolEndpoint (*rhs._pe);}
	else (this->_pe = NULL);

	return *this;
}

/*
 * enumerateOperatingSystems
 */
CTextRedirection::iterator 
CTextRedirection::enumTextRedirections (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_TextRedirectionSAP::iterator iter = 
		CIM_TextRedirectionSAP::enumInstances (client, 0, props);

	if (cached) { return createIterator (iter, props);  	  }
	else 		{ return createIterator (iter); }
}

/*
 * getSystemCreationClassName
 */
string 
CTextRedirection::getSystemCreationClassName (void) const
{
	return _tr->getSystemCreationClassName ();
}

/*
 * getSystemName
 */
string 
CTextRedirection::getSystemName (void) const
{
	return _tr->getSystemName ();
}
/*
 * getName
 */
string
CTextRedirection::getName (void) const
{
	return _tr->getName ();
}

/*
 * getCreationClassName
 */
string 
CTextRedirection::getCreationClassName (void) const
{
	return _tr->getCreationClassName ();
}

/*
 * getElementName
 */
string 
CTextRedirection::getElementName (void) const
{
	return _tr->getElementName ();
}

/*
 * getEnabledState
 */
uint16 
CTextRedirection::getEnabledState (void) const
{
	return _tr->getEnabledState ();
}

/*
 * getEnabledState
 */
string
CTextRedirection::getEnabledStateStr (void) const
{
	return CIM_TextRedirectionSAP::getValueStr_EnabledState (_tr->getEnabledState ());
}

/*
 * getRequestedState
 */
uint16
CTextRedirection::getRequestedState (void) const
{
	return _tr->getRequestedState ();
}

/*
 * getRequestedStateStr
 */
string
CTextRedirection::getRequestedStateStr (void) const
{
	return CIM_TextRedirectionSAP::getValueStr_RequestedState (_tr->getRequestedState ());
}

/*
 * getTerminationSequence
 */
string
CTextRedirection::getTerminationSequence (void) const
{
	return _tr->getSessionTerminateSequence ();
}

/*
 * getTextFlowType
 */
string
CTextRedirection::getTextFlowType (void) const
{
	return _tr->getValueStr_TextFlowType (_tr->getTextFlowType ());
}

/*
 * getPortNumber
 */
uint32
CTextRedirection::getPortNumber (void)
{
	if (_tcp == NULL)
	{
		vector<string> empty_props;

		///* enumerate the Endpoint protocolassociated with this redirection session */
		//CIM_ProtocolEndpoint::iterator iter = CIM_BindsTo <CIM_ProtocolEndpoint,
		//						CIM_TextRedirectionSAP>::enumerateAntecedent (_tr->getClient(),
		//																    *(this->getCIMObject ()),
		//																	empty_props);
		//if (iter == CIM_ProtocolEndpoint::iterator::end ())
		//{
		//	throw EFunctionNotSupported ("getPortNumber");
		//}

		//CIM_ProtocolEndpoint pe = *iter;

		CIM_ProtocolEndpoint pe(CCIMInstance::nullInstance());
		if(capableOfPEPortNumber(pe) == false) {
			throw EFunctionNotSupported ("getPortNumber");	
		}

		/* 
		   some implementation have TCPProtocolEndpoint directly associated with TextRedirectionSAP, some implemenation
		   have TCPProtocolEndpoint associated wiht ProtocolEndpoint, that is associated with TextRedirectionSAP 
		   so try getting the port number and see if associated instance is TCPProtocolEndpoint, else find the TCPProtocolEndpoint 
		   that is associated with ProtocolEndpoint 
		 */

		try {

			CIM_TCPProtocolEndpoint* tcppe = (CIM_TCPProtocolEndpoint*)&pe;
			tcppe->getPortNumber ();
			_tcp  = new CIM_TCPProtocolEndpoint (*tcppe);
		}
		catch (...)
		{

			/* enumerate the Endpoint protocolassociated with this redirection session */
			/*CIM_TCPProtocolEndpoint::iterator iter2 = CIM_BindsTo <CIM_TCPProtocolEndpoint,
									CIM_TCPProtocolEndpoint>::enumerateAntecedent (_tr->getClient(),
																				pe,
																				empty_props);
			if (iter2 == CIM_TCPProtocolEndpoint::iterator::end ())
			{
				throw EFunctionNotSupported ("getPortNumber");
			}

			CIM_TCPProtocolEndpoint tcppe = *iter2;*/

			CIM_TCPProtocolEndpoint tcpe(CCIMInstance::nullInstance());
			if(capableOfTCPEPortNumber(pe, tcpe) == false) {
				throw EFunctionNotSupported ("getPortNumber");	
			}

			_tcp  = new CIM_TCPProtocolEndpoint (tcpe);
		}
	}
	return _tcp->getPortNumber();
}

/*
 * getProtocolIFType
 */
string
CTextRedirection::getProtocolIFType (void) 
{
	if (_pe == NULL)
	{
		vector<string> props;
		props.push_back("ProtocolIFType");
		props.push_back("PortNumber");


		/* enumerate the Endpoint protocolassociated with this redirection session */
		CIM_ProtocolEndpoint::iterator iter = CIM_BindsTo <CIM_ProtocolEndpoint,
								CIM_TextRedirectionSAP>::enumerateAntecedent (_tr->getClient(),
																		    *(this->getCIMObject ()),
																			props);
		if (iter == CIM_ProtocolEndpoint::iterator::end ())
		{
			throw EFunctionNotSupported ("getProtocolIFType");
		}

		CIM_ProtocolEndpoint pe = *iter;
		_pe  = new CIM_ProtocolEndpoint (pe);
	}

	return _pe->getValueStr_ProtocolIFType (_pe->getProtocolIFType ());
}

/*
 * activate
 */
void
CTextRedirection::activate (void) const
{
	uint32				ret;
	uint32				ret1;
	datetime 			immediate = CCIMDateTime (0, true);
	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

	vector<string> ignore;
	ignore.push_back ("TimeoutPeriod");
	
	// This func call verifies whether the TRS instance exiest and returns TRS instance. 
	CIM_TextRedirectionService te(CCIMInstance::nullInstance());
	if(capableOfTRServiceRequestStatesChange(te) == false) {
		throw EFunctionNotSupported ("activate");
	}
	// Verifies whether activate operation is supported or not.
	if (isSupportedRequestStates (te,CIM_EnabledLogicalElementCapabilities::RequestedStatesSupported_Enabled) == false)
	{
		throw EFunctionNotSupported ("activate");
	}
/*	if (0 != (ret1 = this->textenablesupport().size()))
	{ 
				fprintf (stdout, "Requested State Change is Supported."); */
		ret1 = te.RequestStateChange(CIM_TextRedirectionService::RequestStateChange_RequestedState_Enabled,
								  &job,
								  immediate);
	
	/* if set attribute is success return 0, else throw EFunctionReturnedWithFailure execption */
	/* if (0 != ret1)
	{
		fprintf (stderr, "Requested State Change Supported.");
		string retcodestr1 = te.getValueStr_RequestStateChange_ReturnCode(ret1);
		throw EFunctionReturnedWithFailure ("CIM_TextRedirectionService::activate", retcodestr1, ret1);
	}
	}
	else
	{
		fprintf (stderr, "Requested State Change Not Supported.ret1"); 
		//return retsupport;
	} */
	
	if (0 != ret1)
	{
		string retcodestr1 = _tr->getValueStr_RequestStateChange_ReturnCode(ret1);
		throw EFunctionReturnedWithFailure ("CIM_TextRedirectionService::activate", retcodestr1, ret1);
	
	}
/*	if (0 != (retsupport = this->trenablesupport().size()))
	{ 
		fprintf (stdout, "Requested State Change is Supported."); */
	ret = _tr->RequestStateChange (CIM_TextRedirectionSAP::RequestStateChange_RequestedState_Enabled,
								  &job,
								  immediate);
	/* if set attribute is success return 0, else throw EFunctionReturnedWithFailure execption */
/*	if (0 != ret)
	{
		fprintf (stderr, "Requested State Change Supported.");
		string retcodestr = _tr->getValueStr_RequestStateChange_ReturnCode(ret);
		throw EFunctionReturnedWithFailure ("CIM_TextRedirection::activate", retcodestr, ret);
	}
	}
	else
	{
		fprintf (stderr, "Requested State Change Not Supported.ret"); 
		//return retsupport;
	} */
	if (0 != ret)
	{
		string retcodestr = _tr->getValueStr_RequestStateChange_ReturnCode(ret);
		throw EFunctionReturnedWithFailure ("CIM_TextRedirectionSAP::activate", retcodestr, ret);
	
	}
	return;

}

/*
 * disabled
 */
void
CTextRedirection::disable (void) const
{

	uint32				ret;
	uint32				ret1;
	datetime 			immediate = CCIMDateTime (0, true);
	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());
	vector<string> ignore;
	vector<string>	empty_props;
	ignore.push_back ("TimeoutPeriod");
	
	// This func call verifies whether the TRS instance exiest and returns TRS instance. 
	CIM_TextRedirectionService te(CCIMInstance::nullInstance());
	if(capableOfTRServiceRequestStatesChange(te) == false) {
		throw EFunctionNotSupported ("activate");
	}

	// Verifies whether TimeoutPeriod operation is supported or not.
	if (isSupportedRequestStates (te, CIM_EnabledLogicalElementCapabilities::RequestedStatesSupported_Disabled) == false)
		throw EFunctionNotSupported ("TimeoutPeriod");

/*	if (0 != (retsupport = this->trenablesupport().size()))
	{ */
		ret = _tr->RequestStateChange (CIM_TextRedirectionSAP::RequestStateChange_RequestedState_Disabled,
							  &job,
								  immediate);
	
		/* if set attribute is success return 0, else throw EFunctionReturnedWithFailure execption */
		if (ret == 4096)
		{
			int currJobState = job.getJobState();
			if (currJobState != 7){
			string retcodestr = _tr->getValueStr_RequestStateChange_ReturnCode(ret);
			throw EFunctionReturnedWithFailure ("CIM_TextRedirectionSAP::RequestStateChange", retcodestr, ret);
			}
		}else if (0 != ret)
		{
			string retcodestr = _tr->getValueStr_RequestStateChange_ReturnCode(ret);
			throw EFunctionReturnedWithFailure ("CIM_TextRedirectionSAP::disable", retcodestr, ret);
		}
		
/*	}
	else
	{
		fprintf (stderr, "Requested State Change Not Supported."); 
		//return retsupport;
	} */
/*	if (0 != (ret1 = this->textenablesupport().size()))
	{ */
		ret1 = te.RequestStateChange(CIM_TextRedirectionService::RequestStateChange_RequestedState_Disabled,
								  &job,
								  immediate);
	
	/* if set attribute is success return 0, else throw EFunctionReturnedWithFailure execption */
	if (ret1 == 4096)
	{
		int currJobState = job.getJobState();
		if (currJobState != 7){
		string retcodestr = te.getValueStr_RequestStateChange_ReturnCode(ret);
		throw EFunctionReturnedWithFailure ("CIM_TextRedirectionService::RequestStateChange", retcodestr, ret);
		}
	}else if (0 != ret1)
	{
		// fprintf (stderr, "Requested State Change Supported.");
		string retcodestr1 = te.getValueStr_RequestStateChange_ReturnCode(ret1);
		throw EFunctionReturnedWithFailure ("CIM_TextRedirectionService::disable", retcodestr1, ret1);
	}
	
	/* }
	else
	{
		fprintf (stderr, "Requested State Change Not Supported."); 
		//return retsupport;
	} */
	return;
}


bool CTextRedirection::capableOfTRSAPRequestStatesChange(CIM_TextRedirectionService &te) const
{
	vector<string>	empty_props;
	// Verifies whether the TextRedirectionService instance exists or not.
		CIM_TextRedirectionService::iterator iter = CIM_TextRedirectionService::enumInstances(_tr->getClient(),0, empty_props);

	if (iter == CIM_TextRedirectionService::iterator::end ())
			return false;

	te = *iter;

	// Verify whether and SAP instance associated with TRS exists or not.
	CIM_TextRedirectionSAP::iterator sapiter = CIM_ServiceAccessBySAP<CIM_TextRedirectionService, CIM_TextRedirectionSAP>::
		enumerateDependent(this->_tr->getClient(), te, empty_props);

	if ( sapiter == CIM_TextRedirectionSAP::iterator::end () )
		return false;

	CIM_TextRedirectionSAP trsap = * sapiter;

	vector<uint16> states = CCIMCapabilities::getSupportedStates(_tr->getClient(),trsap);
	// Verifies whether the RequestedStatesSupported array contains at least one value
	if (states.size() == 0 )
		return false;

	return true;
}

bool CTextRedirection::capableOfTRSAPRequestStatesChange(void) const
{
	CIM_TextRedirectionService te(CCIMInstance::nullInstance());
	return capableOfTRSAPRequestStatesChange(te);
}


bool CTextRedirection::capableOfTRServiceRequestStatesChange(CIM_TextRedirectionService &te) const
{
	vector<string>	empty_props;

	// Verifies whether the TextRedirectionService instance exists or not.
		CIM_TextRedirectionService::iterator iter = CIM_TextRedirectionService::
				enumInstances(_tr->getClient(),0, empty_props);

	if (iter == CIM_TextRedirectionService::iterator::end ())
			return false;

	te = *iter;

	vector<uint16> states = CCIMCapabilities::getSupportedStates(_tr->getClient(),te);
	// Verifies whether the RequestedStatesSupported array contains at least one value
	if (states.size() == 0 )
		return false;

	return true;
}

bool CTextRedirection::capableOfTRServiceRequestStatesChange(void) const
{
	CIM_TextRedirectionService te(CCIMInstance::nullInstance());
	return capableOfTRServiceRequestStatesChange(te);
}



bool CTextRedirection::isSupportedRequestStates (CIM_TextRedirectionService & te, uint16 checkVal) const
{
	return CCIMCapabilities::isSupportedValue(_tr->getClient(), te, checkVal); 
}	

bool
CTextRedirection::getSupportedStates(vector<uint16> &states_val) const
{
	CIM_TextRedirectionService te(CCIMInstance::nullInstance());
	if ( capableOfTRServiceRequestStatesChange(te) )
		states_val = CCIMCapabilities::getSupportedStates(_tr->getClient(), te);
	if ( states_val.size() == 0 )
		return false;

	return true;
}

bool
CTextRedirection::getSupportedStatesStr(vector<string> &states_str) const
{	
	CIM_TextRedirectionService te(CCIMInstance::nullInstance());
	if ( capableOfTRServiceRequestStatesChange(te) )
		states_str = CCIMCapabilities::getSupportedStatesStr(_tr->getClient(), te);

	if ( states_str.size() == 0 )
		return false;

	return true;
}


/*
 * startRedirection
 */
int
CTextRedirection::startRedirection (void)
{
	IClient* client = _tr->getClient ();

	string host	= client->getHostName ();
	string userName = client->getUser();
	string passwd = client->getPassword();

	string protocol	= getProtocolIFType ();
	char   port [10];

#ifdef WIN32
	if (protocol == "SSH")
	{
		sprintf (port, "%d", getPortNumber());
		string portstr = port;
		string command = "putty -ssh -P " + portstr + " " + 
			"-l " + userName + " -pw " + passwd + " " + host;
		if (-1 == system (command.c_str ()))
		{
			return -1;
		}
		try {
			disable();
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Failed to Disconnect %s",e.what ());
			return -1;
		}
	}
	else if (protocol == "Telnet")
	{
		sprintf (port, "%d", getPortNumber());
		string portstr = port;
		string command = "putty -telnet -P " + portstr + " " + host;
		if (-1 == system (command.c_str ()))
		{
			fprintf(stdout,"\n system (command.c_str ())\n");
			return -1;
		}
		try {
			disable();
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Failed to Disconnect  %s",e.what ());
			return -1;
		}
	}
	else if (protocol == "Other")//TelnetS
	{
		sprintf (port, "%d", getPortNumber());
		string portstr = port;
		fprintf(stdout,"Other aCalling");
		string command = "ssl_client " + host + " " + portstr + " putty -telnet %h %p";
		if (-1 == system (command.c_str ()))
		{
			return -1;
		}
		try {
			disable();
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error:Failed to Disconnect  %s",e.what ());
			return -1;
		}
	}
	else
	{
		return -1;
	}
#else

	if (protocol == "SSH")
	{
                char user [100];
                fprintf (stdout, "Login : ");
                scanf ("%s", user);

		sprintf (port, "%d", getPortNumber());
		string portstr = port;

		string command = "ssh -p " + portstr + " " + user + "@" + host;
		if (-1 == system (command.c_str ()))
		{
			return -1;
		}
		disable();
	}
	else if (protocol == "Telnet")
	{
		sprintf (port, "%d", getPortNumber());
		string portstr = port;

		string command = "telnet " +  host + " " + port;
		printf ("%s\n", command.c_str ());
		if (-1 == system (command.c_str ()))
		{
			return -1;
		}
		disable();
	}
	else if (protocol == "Other")//TelnetS
	{
		sprintf (port, "%d", getPortNumber());
		string portstr = port;

		string command = "ssl_client " + host + " " + portstr + " telnet %h %p";
		if (-1 == system (command.c_str ()))
		{
			return -1;
		}
		disable();
	}
	else
	{
		return -1;
	}

#endif

	return 0;
}



#if 0
/*
 * startRedirection
 */
int
CTextRedirection::startRedirection (void)
{
	IClient* client = _tr->getClient ();

	string host	= client->getHostName ();
	string protocol	= getProtocolIFType ();
	char port [10];

	sprintf (port, "%d", getPortNumber ());
	string portstr = port;

#ifdef WIN32
	if (protocol == "SSH")
	{
		//string command = "putty -ssh -l " + user + " -pw " + password + " -P " + port + " " + host;
		string command = "putty -ssh -P " + portstr + " " + host;
		if (-1 == system (command.c_str ()))
		{
			return -1;
		}
	}
	else if (protocol == "Telnet")
	{
		//string command = "putty -telnet -l " + user + " -P " + port + " " + host;
		string command = "putty -telnet -P " + portstr + " " + host;
		if (-1 == system (command.c_str ()))
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}
#else

	if (protocol == "SSH")
	{
		char user [100]; 
		fprintf (stdout, "Login : ");
		scanf ("%s", user);

		string command = "ssh -p " + portstr + " " + user + "@" + host;
		if (-1 == system (command.c_str ()))
		{
			return -1;
		}
	}
	else if (protocol == "Telnet")
	{
		string command = "telnet " +  host + " " + port;
		if (-1 == system (command.c_str ()))
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}

#endif

	return 0;
}
#endif

bool
CTextRedirection::capableOfPEPortNumber(CIM_ProtocolEndpoint &pe) const
{
	vector<string> props;
	props.push_back("PortNumber");

	/* enumerate the Endpoint protocolassociated with this redirection session */
	CIM_ProtocolEndpoint::iterator iter = CIM_BindsTo <CIM_ProtocolEndpoint,
							CIM_TextRedirectionSAP>::enumerateAntecedent (_tr->getClient(),
																	    *(this->getCIMObject ()),
																		props);
	if (iter == CIM_ProtocolEndpoint::iterator::end ())
	{
		return false;
	}

	pe = *iter;
	return true;
}

bool
CTextRedirection::capableOfPEPortNumber() const
{
	CIM_ProtocolEndpoint pe(CCIMInstance::nullInstance());
	return capableOfPEPortNumber(pe);
}

bool
CTextRedirection::capableOfTCPEPortNumber(CIM_ProtocolEndpoint pe,
										CIM_TCPProtocolEndpoint &tcpe) const
{

	vector<string> empty_props;
	/* enumerate the Endpoint protocolassociated with this redirection session */
	CIM_TCPProtocolEndpoint::iterator iter = CIM_BindsTo <CIM_TCPProtocolEndpoint,
							CIM_ProtocolEndpoint>::enumerateAntecedent (_tr->getClient(),
																		pe,
																		empty_props);
	if (iter == CIM_TCPProtocolEndpoint::iterator::end ())
	{
		return false;
	}

	tcpe = *iter;
	return true;
}

bool
CTextRedirection::capableOfTCPEPortNumber(CIM_ProtocolEndpoint pe) const
{
	CIM_TCPProtocolEndpoint tcpe(CCIMInstance::nullInstance());
	return capableOfPEPortNumber(tcpe);
}

/*
bool
CTextRedirection::capableOfTxtRedirectService(CIM_TextRedirectionService &te) const
{

	vector<string>	empty_props;
	
	CIM_TextRedirectionService::iterator iter = CIM_ServiceAccessBySAP <CIM_TextRedirectionService, CIM_TextRedirectionSAP>::
	enumerateAntecedent (_tr->getClient (), *(this->getCIMObject ()), empty_props);
	if (iter == CIM_TextRedirectionService::iterator::end ())
	{
			return false;
	}

	te = *iter;
	return true;
}

bool
CTextRedirection::capableOfTxtRedirectService() const
{
	CIM_TextRedirectionService te(CCIMInstance::nullInstance());
	return capableOfTxtRedirectService(te);
}



/*
 * getCachedProps
 */
vector<string> 
CTextRedirection::getCachedProps (void)
{
	vector<string> props;

	props.push_back ("SystemCreationClassName");
	props.push_back ("SystemName");
	props.push_back ("Name");
	props.push_back ("CreationClassName");
	props.push_back ("ElementName");
	props.push_back ("EnabledState");
	props.push_back ("RequestedState");
	props.push_back ("SessionTerminateSequence");
	props.push_back ("TextFlowType");
	props.push_back ("PortNumber");
	props.push_back ("ProtocolIFType");
	return props;
}

/*
 * getMaxCurrentEnabledSAPs
 */
uint16
CTextRedirection::getMaxCurrentEnabledSAPs (void) const
{

	//vector<string>	empty_props;
	//CIM_TextRedirectionService::iterator iter = CIM_ServiceAccessBySAP <CIM_TextRedirectionService, CIM_TextRedirectionSAP>::
	//enumerateAntecedent (_tr->getClient (), *(this->getCIMObject ()), empty_props);
	//if (iter == CIM_TextRedirectionService::iterator::end ())
	//	{
	//		throw EFunctionNotSupported ("getMaxCurrentEnabledSAPs");
	//	}

	//	CIM_TextRedirectionService te = *iter;
	CIM_TextRedirectionService te(CCIMInstance::nullInstance());
	if(capableOfTRServiceRequestStatesChange(te) == false) {
		throw EFunctionNotSupported ("getMaxCurrentEnabledSAPs");
	}
	return te.getMaxCurrentEnabledSAPs();

}
/*
 * OperatingSystem::Iterator
 */
DEFINE_API_ITERATOR (CTextRedirection);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CTextRedirection, CIM_TextRedirectionSAP);
