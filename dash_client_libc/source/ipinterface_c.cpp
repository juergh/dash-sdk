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
 * ipinterface_c.cpp
 * C wrapper for ipinterface.
 */
#include <vector>
#include <string>
#include <cstring>
#include <dsdk/oal/COALObject.h>
#include <dsdkc/ipinterface_c.h>
#include <dsdk/ipinterface.h>
#include <dsdkc/error_c.h>


using namespace dsdk;

/*
 * getSystemCreationClassName
 */
extern "C" void 
ip_getSystemCreationClassName (DSDKIPInterface* ip, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _IP = (CIPInterface*) (ip->hdl);
		string str = _IP->getSystemCreationClassName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getSystemName
 */
extern "C" void 
ip_getSystemName (DSDKIPInterface* ip, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _IP = (CIPInterface*) (ip->hdl);
		string str = _IP->getSystemName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getCreationClassName
 */
extern "C" void 
ip_getCreationClassName (DSDKIPInterface* ip, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _IP = (CIPInterface*) (ip->hdl);
		string str = _IP->getCreationClassName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getName
 */
extern "C" void 
ip_getName (DSDKIPInterface* ip, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _IP = (CIPInterface*) (ip->hdl);
		string str = _IP->getName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getNameFormat
 */
extern "C" void 
ip_getNameFormat (DSDKIPInterface* ip, char* name_format, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _IP = (CIPInterface*) (ip->hdl);
		string str = _IP->getNameFormat ();
		::snprintf(name_format,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getProtocolIFType
 */
extern "C" uint16 
ip_getProtocolIFType (DSDKIPInterface* ip)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _IP = (CIPInterface*) (ip->hdl);
		return _IP->getProtocolIFType ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getProtocolIFTypeStr
 */
extern "C" void 
ip_getProtocolIFTypeStr (DSDKIPInterface* ip, char* type, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _ip = (CIPInterface*) (ip->hdl);
		string str = _ip->getProtocolIFTypeStr ();
		::snprintf(type,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getEnabledState
 */
extern "C" uint16 
ip_getEnabledState (DSDKIPInterface* ip)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _ip = (CIPInterface*) (ip->hdl);
		return _ip->getEnabledState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEnabledStateStr
 */
extern "C" void 
ip_getEnabledStateStr (DSDKIPInterface* ip, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _ip = (CIPInterface*) (ip->hdl);
		string str = _ip->getEnabledStateStr ();
		::snprintf(state, max_len, "%s", str.c_str());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getRequestedState
 */
extern "C" uint16 
ip_getRequestedState (DSDKIPInterface* ip)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _ip = (CIPInterface*) (ip->hdl);
		return _ip->getRequestedState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getRequestedStateStr
 */
extern "C" void 
ip_getRequestedStateStr (DSDKIPInterface* ip, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _ip = (CIPInterface*) (ip->hdl);
		string str = _ip->getRequestedStateStr ();
		::snprintf(state,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getElementname
 */
extern "C" void 
ip_getElementName (DSDKIPInterface* ip, char* ele_name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _IP = (CIPInterface*) (ip->hdl);
		string str = _IP->getElementName ();
		::snprintf(ele_name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getIPv4Address
 */
extern "C" void 
ip_getIPv4Address (DSDKIPInterface* ip, char* addr, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _IP = (CIPInterface*) (ip->hdl);
		string str = _IP->getIPv4Address ();
		::snprintf(addr,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getSubnetMask
 */
extern "C" void 
ip_getSubnetMask (DSDKIPInterface* ip, char* sub_mask, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _IP = (CIPInterface*) (ip->hdl);
		string str = _IP->getSubnetMask ();
		::snprintf(sub_mask,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getAddressOrigin
 */
extern "C" uint16 
ip_getAddressOrigin (DSDKIPInterface* ip)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _IP = (CIPInterface*) (ip->hdl);
		return _IP->getAddressOrigin ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getAddressOriginStr
 */
extern "C" void 
ip_getAddressOriginStr (DSDKIPInterface* ip, char* orgin, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _ip = (CIPInterface*) (ip->hdl);
		string str = _ip->getAddressOriginStr ();
		::snprintf(orgin,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getIPv6Address
 */
extern "C" void 
ip_getIPv6Address (DSDKIPInterface* ip, char* addr, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _IP = (CIPInterface*) (ip->hdl);
		string str = _IP->getIPv6Address ();
		::snprintf(addr,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getIPv6AddressType
 */
extern "C" uint16 
ip_getIPv6AddressType (DSDKIPInterface* ip)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _IP = (CIPInterface*) (ip->hdl);
		return _IP->getIPv6AddressType ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getIPV6AddressTypeStr
 */
extern "C" void 
ip_getIPv6AddressTypeStr (DSDKIPInterface* ip, char* type, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _ip = (CIPInterface*) (ip->hdl);
		string str = _ip->getIPv6AddressTypeStr ();
		::snprintf(type,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getIPv6SubnetPrefixLength
 */
extern "C" uint16 
ip_getIPv6SubnetPrefixLength (DSDKIPInterface* ip)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CIPInterface* _IP = (CIPInterface*) (ip->hdl);
		return _IP->getIPv6SubnetPrefixLength ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * release
 */
extern "C" void 
ip_release (DSDKIPInterface* ip)
{
	dsdkc_setError (0, NULL);
	CIPInterface* _IP = (CIPInterface*) (ip->hdl);
	delete _IP;
	delete ip;
}

static DSDKIPInterfaceFT _IPft = 
{
	ip_getSystemCreationClassName,
	ip_getSystemName,
	ip_getCreationClassName,
	ip_getName,
	ip_getNameFormat,
	ip_getProtocolIFType,
	ip_getProtocolIFTypeStr,
	ip_getEnabledState,
	ip_getEnabledStateStr,
	ip_getRequestedState,
	ip_getRequestedStateStr,
	ip_getElementName,
	ip_getIPv4Address,
	ip_getSubnetMask,
	ip_getAddressOrigin,
	ip_getAddressOriginStr,
	ip_getIPv6Address,
	ip_getIPv6AddressType,
	ip_getIPv6AddressTypeStr,
	ip_getIPv6SubnetPrefixLength,
	ip_release,
};


/*
 * Make a C based IPInterface from the corresponding C++ object.
 */
static DSDKIPInterface* 
makeDSDKIPInterface (const CIPInterface& ip)
{
	DSDKIPInterface* dsdk_IP = new DSDKIPInterface;
	if (NULL == dsdk_IP) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_IP->ft	= &_IPft;
		dsdk_IP->hdl	= new CIPInterface (ip);
		return dsdk_IP;
	}
	CATCH_SET_ERROR ();

	delete dsdk_IP;
	return NULL;

}


/*
 * getItem
 */
extern "C" DSDKIPInterface* 
ipi_getItem (DSDKIPInterfaceIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CIPInterface::iterator* _iter = (CIPInterface::iterator*) (di->hdl);
		if (*_iter == CIPInterface::iterator::end ()) { return NULL; }
		return makeDSDKIPInterface (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
ipi_next (DSDKIPInterfaceIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CIPInterface::iterator* _iter = (CIPInterface::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
ipi_isEnd (DSDKIPInterfaceIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CIPInterface::iterator* _iter = (CIPInterface::iterator*) (di->hdl);
		return (*_iter == CIPInterface::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
ipi_release (DSDKIPInterfaceIterator* di)
{
	dsdkc_setError (0, NULL);
	CIPInterface::iterator* _iter = (CIPInterface::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKIPInterfaceIteratorFT _IPift = 
{
	ipi_getItem,
	ipi_next,
	ipi_isEnd,
	ipi_release,
};


/*
 * Make a C based IPInterface iterator from the corresponding C++ object.
 */
static DSDKIPInterfaceIterator* 
makeDSDKIPInterfaceIterator (const CIPInterface::iterator& IPi)
{

	DSDKIPInterfaceIterator* dsdk_IPi = new DSDKIPInterfaceIterator;
	if (NULL == dsdk_IPi) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_IPi->ft  = &_IPift;
		dsdk_IPi->hdl = new CIPInterface::iterator (IPi);
		return dsdk_IPi;
	}
	CATCH_SET_ERROR ();

	delete dsdk_IPi;
	return NULL;
}


/*
 * enumIPInterface
 */
extern "C" DSDKIPInterfaceIterator*
enumIPInterfaces (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CIPInterface::iterator iter = CIPInterface::enumIPInterfaces (
													(IClient*) client, 
													(cached ? true : false));

		return makeDSDKIPInterfaceIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;
}
