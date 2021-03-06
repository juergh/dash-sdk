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
 * dnsclient_c.cpp
 * C wrapper for dnsclient.
 */
#include <vector>
#include <string>
#include <cstring>
#include <dsdk/oal/COALObject.h>
#include <dsdkc/dnsclient_c.h>
#include <dsdk/dnsclient.h>
#include <dsdkc/error_c.h>


using namespace dsdk;

/*
 * getSystemCreationClassName
 */
extern "C" void 
dns_getSystemCreationClassName (DSDKDNSClient* dns, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDNSClient* _dns = (CDNSClient*) (dns->hdl);
		string str = _dns->getSystemCreationClassName ();
		::snprintf(name,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getSystemName
 */
extern "C" void 
dns_getSystemName (DSDKDNSClient* dns, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDNSClient* _dns = (CDNSClient*) (dns->hdl);
		string str = _dns->getSystemName ();
		::snprintf(name,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getCreationClassName
 */
extern "C" void 
dns_getCreationClassName (DSDKDNSClient* dns, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDNSClient* _dns = (CDNSClient*) (dns->hdl);
		string str = _dns->getCreationClassName ();
		::snprintf(name,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getName
 */
extern "C" void 
dns_getName (DSDKDNSClient* dns, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDNSClient* _dns = (CDNSClient*) (dns->hdl);
		string str = _dns->getName ();
		::snprintf(name,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getNameFormat
 */
extern "C" void 
dns_getNameFormat (DSDKDNSClient* dns, char* name_format, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDNSClient* _dns = (CDNSClient*) (dns->hdl);
		string str = _dns->getNameFormat ();
		::snprintf(name_format,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getHostName
 */
extern "C" void 
dns_getHostname (DSDKDNSClient* dns, char* hostname, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDNSClient* _dns = (CDNSClient*) (dns->hdl);
		string str = _dns->getHostname ();
		::snprintf(hostname,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getProtocolIFType
 */
extern "C" uint16 
dns_getProtocolIFType (DSDKDNSClient* dns)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDNSClient* _dns = (CDNSClient*) (dns->hdl);
		return _dns->getProtocolIFType ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getProtocolIFTypeStr
 */
extern "C" void 
dns_getProtocolIFTypeStr (DSDKDNSClient* dns, char* type, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDNSClient* _dns = (CDNSClient*) (dns->hdl);
		string str = _dns->getProtocolIFTypeStr ();
		::snprintf(type,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getEnabledState
 */
extern "C" uint16 
dns_getEnabledState (DSDKDNSClient* dns)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDNSClient* _dns = (CDNSClient*) (dns->hdl);
		return _dns->getEnabledState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEnabledStateStr
 */
extern "C" void 
dns_getEnabledStateStr (DSDKDNSClient* dns, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDNSClient* _dns = (CDNSClient*) (dns->hdl);
		string str = _dns->getEnabledStateStr ();
		::snprintf(state,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getRequestedState
 */
extern "C" uint16 
dns_getRequestedState (DSDKDNSClient* dns)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDNSClient* _dns = (CDNSClient*) (dns->hdl);
		return _dns->getRequestedState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getRequestedStateStr
 */
extern "C" void 
dns_getRequestedStateStr (DSDKDNSClient* dns, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDNSClient* _dns = (CDNSClient*) (dns->hdl);
		string str = _dns->getRequestedStateStr ();
		::snprintf(state,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getElementname
 */
extern "C" void 
dns_getElementName (DSDKDNSClient* dns, char* ele_name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDNSClient* _dns = (CDNSClient*) (dns->hdl);
		string str = _dns->getElementName ();
		::strncpy (ele_name, str.c_str (), max_len);
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getAppendPrimarySuffixes
 */
extern "C" BOOL 
dns_appendPrimarySuffixes (DSDKDNSClient* dns)
{
	dsdkc_setError (0, NULL);
	try
	{
		CDNSClient*_dns = (CDNSClient*) (dns->hdl);
		return _dns->appendPrimarySuffixes ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getAppendParentSuffixes
 */
extern "C" BOOL 
dns_appendParentSuffixes (DSDKDNSClient* dns)
{
	dsdkc_setError (0, NULL);
	try
	{
		CDNSClient*_dns = (CDNSClient*) (dns->hdl);
		return _dns->appendParentSuffixes ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getDNSSuffixesToAppend
 */
extern "C" int 
dns_getDNSSuffixesToAppend (DSDKDNSClient* dns, char** append_values, int max_value, 
														 int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDNSClient*_dns = (CDNSClient*) (dns->hdl);
		vector <string> str	= _dns->getDNSSuffixesToAppend ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_value)); i++)
		{
			::snprintf(append_values [i],   max_strlen, "%s", str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getDomainName
 */
extern "C" void 
dns_getDomainName (DSDKDNSClient* dns, char* domainname, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDNSClient* _dns = (CDNSClient*) (dns->hdl);
		string str = _dns->getDomainName ();
		::snprintf(domainname,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getUseSuffixWhenRegistering
 */
extern "C" BOOL 
dns_useSuffixWhenRegistering (DSDKDNSClient* dns)
{
	dsdkc_setError (0, NULL);
	try
	{
		CDNSClient*_dns = (CDNSClient*) (dns->hdl);
		return _dns->useSuffixWhenRegistering ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getRegisterThisConnectionsAddress
 */
extern "C" BOOL 
dns_registerThisConnectionsAddress (DSDKDNSClient* dns)
{
	dsdkc_setError (0, NULL);
	try
	{
		CDNSClient*_dns = (CDNSClient*) (dns->hdl);
		return _dns->registerThisConnectionsAddress ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getDHCPOptionsToUse
 */
extern "C" int 
dns_getDHCPOptionsToUse (DSDKDNSClient* dns, uint16* options, int max_types)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDNSClient*_dns = (CDNSClient*) (dns->hdl);
		vector<uint16>	_options = _dns->getDHCPOptionsToUse ();
		for (size_t i = 0; (i < _options.size () && (i < (size_t)max_types)); i++)
		{
			options [i]  = _options [i];
		}
		return (int)_options.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * release
 */
extern "C" void 
dns_release (DSDKDNSClient* dns)
{
	dsdkc_setError (0, NULL);
	CDNSClient* _dns = (CDNSClient*) (dns->hdl);
	delete _dns;
	delete dns;
}

static DSDKDNSClientFT _dnsft = 
{
	dns_getSystemCreationClassName,
	dns_getSystemName,
	dns_getCreationClassName,
	dns_getName,
	dns_getNameFormat,
	dns_getHostname,
	dns_getProtocolIFType,
	dns_getProtocolIFTypeStr,
	dns_getEnabledState,
	dns_getEnabledStateStr,
	dns_getRequestedState,
	dns_getRequestedStateStr,
	dns_getElementName,
	dns_appendPrimarySuffixes,
	dns_appendParentSuffixes,
	dns_getDNSSuffixesToAppend,
	dns_getDomainName,
	dns_useSuffixWhenRegistering,
	dns_registerThisConnectionsAddress,
	dns_getDHCPOptionsToUse,
	dns_release
};


/*
 * Make a C based DNSClient from the corresponding C++ object.
 */
static DSDKDNSClient* 
makeDSDKDNSClient (const CDNSClient& dns)
{
	DSDKDNSClient* dsdk_dns = new DSDKDNSClient;
	if (NULL == dsdk_dns) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_dns->ft	= &_dnsft;
		dsdk_dns->hdl	= new CDNSClient (dns);
		return dsdk_dns;
	}
	CATCH_SET_ERROR ();

	delete dsdk_dns;
	return NULL;

}


/*
 * getItem
 */
extern "C" DSDKDNSClient* 
dnsi_getItem (DSDKDNSClientIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CDNSClient::iterator* _iter = (CDNSClient::iterator*) (di->hdl);
		if (*_iter == CDNSClient::iterator::end ()) { return NULL; }
		return makeDSDKDNSClient (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
dnsi_next (DSDKDNSClientIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CDNSClient::iterator* _iter = (CDNSClient::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
dnsi_isEnd (DSDKDNSClientIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CDNSClient::iterator* _iter = (CDNSClient::iterator*) (di->hdl);
		return (*_iter == CDNSClient::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
dnsi_release (DSDKDNSClientIterator* di)
{
	dsdkc_setError (0, NULL);
	CDNSClient::iterator* _iter = (CDNSClient::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKDNSClientIteratorFT _dnsift = 
{
	dnsi_getItem,
	dnsi_next,
	dnsi_isEnd,
	dnsi_release,
};


/*
 * Make a C based DNSClient iterator from the corresponding C++ object.
 */
static DSDKDNSClientIterator* 
makeDSDKDNSClientIterator (const CDNSClient::iterator& dnsi)
{

	DSDKDNSClientIterator* dsdk_dnsi = new DSDKDNSClientIterator;
	if (NULL == dsdk_dnsi) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_dnsi->ft  = &_dnsift;
		dsdk_dnsi->hdl = new CDNSClient::iterator (dnsi);
		return dsdk_dnsi;
	}
	CATCH_SET_ERROR ();

	delete dsdk_dnsi;
	return NULL;
}


/*
 * enumDNSClient
 */
extern "C" DSDKDNSClientIterator*
enumDNSClients (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CDNSClient::iterator iter = CDNSClient::enumDNSClients (
													(IClient*) client, 
													(cached ? true : false));

		return makeDSDKDNSClientIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;
}
