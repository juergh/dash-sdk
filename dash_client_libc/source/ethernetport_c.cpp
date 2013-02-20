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
 * ethernetport_c.cpp
 * C wrapper for ethernetport.
 */
#include <vector>
#include <string>
#include <cstring>
#include <dsdk/oal/COALObject.h>
#include <dsdkc/ethernetport_c.h>
#include <dsdk/ethernetport.h>
#include <dsdkc/error_c.h>
#include <dsdk/dsdkexception.h>

using namespace dsdk;


/*
 * getPortType
 */
extern "C" uint16 
eth_getPortType (DSDKEthernetPort* eth)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CEthernetPort* _eth		= (CEthernetPort*) (eth->hdl);
		return _eth->getPortType ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * Gets PortTypeStr
 */
extern "C" void 
eth_getPortTypeStr (DSDKEthernetPort* eth, char* type, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CEthernetPort* _eth	= (CEthernetPort*) (eth->hdl);
		string str			= _eth->getPortTypeStr ();
		::snprintf(type,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * gets network addresses
 */

extern "C" int 
eth_getNetworkAddresses (DSDKEthernetPort* eth, char** na, int max_na, 
														int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CEthernetPort* _eth		= (CEthernetPort*) (eth->hdl);
		vector <string> str	= _eth->getNetworkAddresses ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_na)); i++)
		{
			::snprintf(na [i],   max_len, "%s", str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getCapabilities
 */
extern "C" int 
eth_getCapabilities (DSDKEthernetPort* eth, uint16* capabilities, int max_types)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CEthernetPort* _eth		= (CEthernetPort*) (eth->hdl);
		vector<uint16>	_capabilities = _eth->getCapabilities ();
		for (size_t i = 0; (i < _capabilities.size () && (i < (size_t)max_types)); i++)
		{
			capabilities [i]  = _capabilities [i];
		}
		return (int)_capabilities.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getCapabilitiesStr 
 */
extern "C" int 
eth_getCapabilitiesStr (DSDKEthernetPort* eth, char** capabilities, int max_capabilities, 
														int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CEthernetPort* _eth		= (CEthernetPort*) (eth->hdl);
		vector <string> str	= _eth->getCapabilitiesStr ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_capabilities)); i++)
		{
			::snprintf(capabilities [i],   max_strlen, "%s", str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEnabledCapabilities
 */
extern "C" int 
eth_getEnabledCapabilities (DSDKEthernetPort* eth, uint16* enab_capabilities, int max_types)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CEthernetPort* _eth		= (CEthernetPort*) (eth->hdl);
		vector<uint16>	_enab_capabilities = _eth->getEnabledCapabilities ();
		for (size_t i = 0; (i < _enab_capabilities.size () && (i < (size_t)max_types)); i++)
		{
			enab_capabilities [i]  = _enab_capabilities [i];
		}
		return (int)_enab_capabilities.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEnabledCapabilitiesStr 
 */
extern "C" int 
eth_getEnabledCapabilitiesStr (DSDKEthernetPort* eth, char** capabilities, int max_capabilities, 
														int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CEthernetPort* _eth		= (CEthernetPort*) (eth->hdl);
		vector <string> str	= _eth->getEnabledCapabilitiesStr ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_capabilities)); i++)
		{
			::snprintf(capabilities [i],   max_strlen, "%s", str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}


/*
 * getLinkTechnology
 */
extern "C" uint16 
eth_getLinkTechnology (DSDKEthernetPort* eth)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CEthernetPort* _eth		= (CEthernetPort*) (eth->hdl);
		return _eth->getLinkTechnology ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * Gets PermanantAddress
 */
extern "C" void 
eth_getPermanantAddress (DSDKEthernetPort* eth, char* perm_addr, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CEthernetPort* _eth	= (CEthernetPort*) (eth->hdl);
		string str			= _eth->getPermanentAddress ();
		::snprintf(perm_addr,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * Gets DeviceID
 */
extern "C" void 
eth_getDeviceID (DSDKEthernetPort* eth, char* dev_id, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CEthernetPort* _eth	= (CEthernetPort*) (eth->hdl);
		string str			= _eth->getDeviceID ();
		::snprintf(dev_id,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * release
 */
extern "C" void 
eth_release (DSDKEthernetPort* eth)
{
	dsdkc_setError (0, NULL);
	CEthernetPort* _eth = (CEthernetPort*) (eth->hdl);
	delete _eth;
	delete eth;
}

static DSDKEthernetPortFT _ethft = 
{
	eth_getPortType,
	eth_getPortTypeStr,
	eth_getNetworkAddresses,
	eth_getCapabilities,
	eth_getCapabilitiesStr,
	eth_getEnabledCapabilities,
	eth_getEnabledCapabilitiesStr,
	eth_getLinkTechnology,
	eth_getPermanantAddress,
	eth_getDeviceID,
	eth_release
};


/*
 * Make a C based EthernetPort from the corresponding C++ object.
 */
static DSDKEthernetPort* 
makeDSDKEthernetPort (const CEthernetPort& eth)
{
	DSDKEthernetPort* dsdk_eth = new DSDKEthernetPort;
	if (NULL == dsdk_eth) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_eth->ft  = &_ethft;
		dsdk_eth->hdl = new CEthernetPort (eth);
		return dsdk_eth;
	}
	CATCH_SET_ERROR ();

	delete dsdk_eth;
	return NULL;

}


/*
 * getItem
 */
extern "C" DSDKEthernetPort* 
ethi_getItem (DSDKEthernetPortIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CEthernetPort::iterator* _iter = (CEthernetPort::iterator*) (di->hdl);
		if (*_iter == CEthernetPort::iterator::end ()) { return NULL; }
		return makeDSDKEthernetPort (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
ethi_next (DSDKEthernetPortIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CEthernetPort::iterator* _iter = (CEthernetPort::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
ethi_isEnd (DSDKEthernetPortIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CEthernetPort::iterator* _iter = (CEthernetPort::iterator*) (di->hdl);
		return (*_iter == CEthernetPort::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
ethi_release (DSDKEthernetPortIterator* di)
{
	dsdkc_setError (0, NULL);
	CEthernetPort::iterator* _iter = (CEthernetPort::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKEthernetPortIteratorFT _ethift = 
{
	ethi_getItem,
	ethi_next,
	ethi_isEnd,
	ethi_release
};


/*
 * Make a C based EthernetPort iterator from the corresponding C++ object.
 */
static DSDKEthernetPortIterator* 
makeDSDKEthernetPortIterator (const CEthernetPort::iterator& ethi)
{
	DSDKEthernetPortIterator* dsdk_ethi = new DSDKEthernetPortIterator;
	if (NULL == dsdk_ethi) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_ethi->ft  = &_ethift;
		dsdk_ethi->hdl = new CEthernetPort::iterator (ethi);
		return dsdk_ethi;
	}
	CATCH_SET_ERROR ();

	delete dsdk_ethi;
	return NULL;
}


/*
 * enumEthernetPort
 */
extern "C" DSDKEthernetPortIterator*
enumEthernetPorts (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CEthernetPort::iterator iter = CEthernetPort::enumEthernetPorts (
														(IClient*) client, 
														(cached ? true : false));
		return makeDSDKEthernetPortIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;

}


