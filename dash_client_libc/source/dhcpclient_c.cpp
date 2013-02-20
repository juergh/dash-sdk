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
 * dhcpprotocolendpoint_c.cpp
 * C wrapper for DhcpProtocolEndPoint.
 */
#include <vector>
#include <string>
#include <cstring>
#include <dsdk/oal/COALObject.h>
#include <dsdkc/dhcpclient_c.h>
#include <dsdk/dhcpclient.h>
#include <dsdkc/error_c.h>


using namespace dsdk;

/*
 * getSystemCreationClassName
 */
extern "C" void 
dhcp_getSystemCreationClassName (DSDKDHCPClient* dhcp, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDHCPClient* _dhcp = (CDHCPClient*) (dhcp->hdl);
		string str = _dhcp->getSystemCreationClassName ();
		::snprintf(name,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getSystemName
 */
extern "C" void 
dhcp_getSystemName (DSDKDHCPClient* dhcp, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDHCPClient* _dhcp = (CDHCPClient*) (dhcp->hdl);
		string str = _dhcp->getSystemName ();
		::snprintf(name,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getCreationClassName
 */
extern "C" void 
dhcp_getCreationClassName (DSDKDHCPClient* dhcp, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDHCPClient* _dhcp = (CDHCPClient*) (dhcp->hdl);
		string str = _dhcp->getCreationClassName ();
		::snprintf(name,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getName
 */
extern "C" void 
dhcp_getName (DSDKDHCPClient* dhcp, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDHCPClient* _dhcp = (CDHCPClient*) (dhcp->hdl);
		string str = _dhcp->getName ();
		::snprintf(name,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}


/*
 * Gets Name Format
 */

extern "C" void 
dhcp_getNameFormat (DSDKDHCPClient* dhcp, char* name_farmat, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDHCPClient* _dhcp = (CDHCPClient*) (dhcp->hdl);
		string str = _dhcp->getNameFormat ();
		::snprintf(name_farmat,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getProtocolIFType
 */
extern "C" uint16 
dhcp_getProtocolIFType (DSDKDHCPClient* dhcp)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDHCPClient* _dhcp = (CDHCPClient*) (dhcp->hdl);
		return _dhcp->getProtocolIFType ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getProtocolIFTypeStr
 */
extern "C" void 
dhcp_getProtocolIFTypeStr (DSDKDHCPClient* dhcp, char* type, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDHCPClient* _dhcp = (CDHCPClient*) (dhcp->hdl);
		string str = _dhcp->getProtocolIFTypeStr ();
		::snprintf(type,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getOtherTypeDescription
 */
extern "C" void 
dhcp_getOtherTypeDescription (DSDKDHCPClient* dhcp, char* desc, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDHCPClient* _dhcp = (CDHCPClient*) (dhcp->hdl);
		string str = _dhcp->getOtherTypeDescription ();
		::snprintf(desc,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getEnabledState
 */
extern "C" uint16 
dhcp_getEnabledState (DSDKDHCPClient* dhcp)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDHCPClient* _dhcp = (CDHCPClient*) (dhcp->hdl);
		return _dhcp->getEnabledState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEnabledStateStr
 */
extern "C" void 
dhcp_getEnabledStateStr (DSDKDHCPClient* dhcp, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDHCPClient* _dhcp = (CDHCPClient*) (dhcp->hdl);
		string str = _dhcp->getEnabledStateStr ();
		::snprintf(state,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getRequestedState
 */
extern "C" uint16 
dhcp_getRequestedState (DSDKDHCPClient* dhcp)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDHCPClient* _dhcp = (CDHCPClient*) (dhcp->hdl);
		return _dhcp->getRequestedState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getRequestedStateStr
 */
extern "C" void 
dhcp_getRequestedStateStr (DSDKDHCPClient* dhcp, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDHCPClient* _dhcp = (CDHCPClient*) (dhcp->hdl);
		string str = _dhcp->getRequestedStateStr ();
		::snprintf(state,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getElementName
 */
extern "C" void 
dhcp_getElementName (DSDKDHCPClient* dhcp, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDHCPClient* _dhcp = (CDHCPClient*) (dhcp->hdl);
		string str = _dhcp->getElementName ();
		::snprintf(name,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getClientState
 */
extern "C" void 
dhcp_getClientState (DSDKDHCPClient* dhcp, char* client_state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CDHCPClient* _dhcp = (CDHCPClient*) (dhcp->hdl);
		string str = _dhcp->getClientState ();
		::snprintf(client_state, max_len, "%s", str.c_str());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * release
 */
extern "C" void 
dhcp_release (DSDKDHCPClient* dhcp)
{
	dsdkc_setError (0, NULL);
	CDHCPClient* _dhcp = (CDHCPClient*) (dhcp->hdl);
	delete _dhcp;
	delete dhcp;
}

static DSDKDHCPClientFT _dhcpft = 
{
	dhcp_getSystemCreationClassName,
	dhcp_getSystemName,
	dhcp_getCreationClassName,
	dhcp_getName,
	dhcp_getNameFormat,
	dhcp_getProtocolIFType,
	dhcp_getProtocolIFTypeStr,
	dhcp_getOtherTypeDescription,
	dhcp_getEnabledState,
	dhcp_getEnabledStateStr,
	dhcp_getRequestedState,
	dhcp_getRequestedStateStr,
	dhcp_getClientState,
	dhcp_getElementName,
	dhcp_release,
};


/*
 * Make a C based DHCPClient from the corresponding C++ object.
 */
static DSDKDHCPClient* 
makeDSDKDHCPClient (const CDHCPClient& dhcp)
{
	DSDKDHCPClient* dsdk_dhcp = new DSDKDHCPClient;
	if (NULL == dsdk_dhcp) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_dhcp->ft	= &_dhcpft;
		dsdk_dhcp->hdl	= new CDHCPClient (dhcp);
		return dsdk_dhcp;
	}
	CATCH_SET_ERROR ();

	delete dsdk_dhcp;
	return NULL;

}


/*
 * getItem
 */
extern "C" DSDKDHCPClient* 
dhcpi_getItem (DSDKDHCPClientIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CDHCPClient::iterator* _iter = (CDHCPClient::iterator*) (di->hdl);
		if (*_iter == CDHCPClient::iterator::end ()) { return NULL; }
		return makeDSDKDHCPClient (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
dhcpi_next (DSDKDHCPClientIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CDHCPClient::iterator* _iter = (CDHCPClient::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
dhcpi_isEnd (DSDKDHCPClientIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CDHCPClient::iterator* _iter = (CDHCPClient::iterator*) (di->hdl);
		return (*_iter == CDHCPClient::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
dhcpi_release (DSDKDHCPClientIterator* di)
{
	dsdkc_setError (0, NULL);
	CDHCPClient::iterator* _iter = (CDHCPClient::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKDHCPClientIteratorFT _dhcpift = 
{
	dhcpi_getItem,
	dhcpi_next,
	dhcpi_isEnd,
	dhcpi_release,
};


/*
 * Make a C based DHCPClient iterator from the corresponding C++ object.
 */
static DSDKDHCPClientIterator* 
makeDSDKDHCPClientIterator (const CDHCPClient::iterator& dhcpi)
{

	DSDKDHCPClientIterator* dsdk_dhcpi = new DSDKDHCPClientIterator;
	if (NULL == dsdk_dhcpi) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_dhcpi->ft  = &_dhcpift;
		dsdk_dhcpi->hdl = new CDHCPClient::iterator (dhcpi);
		return dsdk_dhcpi;
	}
	CATCH_SET_ERROR ();

	delete dsdk_dhcpi;
	return NULL;
}


/*
 * enumDHCPClient
 */
extern "C" DSDKDHCPClientIterator*
enumDHCPClients (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CDHCPClient::iterator iter = CDHCPClient::enumDHCPClients (
													(IClient*) client, 
													(cached ? true : false));

		return makeDSDKDHCPClientIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;
}






