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
 * networkport_c.cpp
 * C wrapper for network port.
 */
#include <vector>
#include <string>
#include <cstring>
#include <dsdk/oal/COALObject.h>
#include <dsdkc/networkport_c.h>
#include <dsdk/networkport.h>
#include <dsdkc/error_c.h>

using namespace dsdk;

/*
 * getSystemCreationClassName
 */
extern "C" void 
np_getSystemCreationClassName (DSDKNetworkPort* np, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CNetworkPort* _np = (CNetworkPort*) (np->hdl);
		string str = _np->getSystemCreationClassName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getSystemName
 */
extern "C" void 
np_getSystemName (DSDKNetworkPort* np, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CNetworkPort* _np = (CNetworkPort*) (np->hdl);
		string str = _np->getSystemName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getCreationClassName
 */
extern "C" void 
np_getCreationClassName (DSDKNetworkPort* np, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CNetworkPort* _np = (CNetworkPort*) (np->hdl);
		string str = _np->getCreationClassName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * Gets Name
 */
extern "C" void 
np_getName (DSDKNetworkPort* np, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CNetworkPort* _np = (CNetworkPort*) (np->hdl);
		string str = _np->getName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * Gets Speed
 */
extern "C" uint64 
np_getSpeed (DSDKNetworkPort* np)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CNetworkPort* _np = (CNetworkPort*) (np->hdl);
		return _np->getSpeed ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * Gets Link Technology
 */
extern "C" uint16 
np_getLinkTechnology (DSDKNetworkPort* np)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CNetworkPort* _np = (CNetworkPort*) (np->hdl);
		return _np->getLinkTechnology ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getLinkTechnologyStr
 */
extern "C" void 
np_getLinkTechnologyStr (DSDKNetworkPort* np, char* lt, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CNetworkPort* _np = (CNetworkPort*) (np->hdl);
		string str = _np->getLinkTechnologyStr ();
		::snprintf(lt,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getPermanantAddress
 */
extern "C" void 
np_getPermanentAddress (DSDKNetworkPort* np, char* perm_addr, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CNetworkPort* _np = (CNetworkPort*) (np->hdl);
		string str = _np->getPermanentAddress ();
		::snprintf(perm_addr,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * Gets Max Speed
 */
extern "C" uint64 
np_getMaxSpeed (DSDKNetworkPort* np)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CNetworkPort* _np = (CNetworkPort*) (np->hdl);
		return _np->getMaxSpeed ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * Gets Requested Speed
 */
extern "C" uint64 
np_getRequestedSpeed (DSDKNetworkPort* np)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CNetworkPort* _np = (CNetworkPort*) (np->hdl);
		return _np->getRequestedSpeed ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getDeviceID
 */
extern "C" void 
np_getDeviceID (DSDKNetworkPort* np, char* devid, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CNetworkPort* _np = (CNetworkPort*) (np->hdl);
		string str = _np->getDeviceID ();
		::snprintf(devid,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getEnabledState
 */
extern "C" uint16 
np_getEnabledState (DSDKNetworkPort* np)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CNetworkPort* _np = (CNetworkPort*) (np->hdl);
		return _np->getEnabledState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEnabledStateStr
 */
extern "C" void 
np_getEnabledStateStr (DSDKNetworkPort* np, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CNetworkPort* _np = (CNetworkPort*) (np->hdl);
		string str = _np->getEnabledStateStr ();
		::snprintf(state, max_len, "%s", str.c_str());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getRequestedState
 */
extern "C" uint16 
np_getRequestedState (DSDKNetworkPort* np)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CNetworkPort* _np = (CNetworkPort*) (np->hdl);
		return _np->getRequestedState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getRequestedStateStr
 */
extern "C" void 
np_getRequestedStateStr (DSDKNetworkPort* np, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CNetworkPort* _np = (CNetworkPort*) (np->hdl);
		string str = _np->getRequestedStateStr ();
		::snprintf(state,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getElementName
 */
extern "C" void 
np_getElementName (DSDKNetworkPort* np, char* ele_name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CNetworkPort* _np = (CNetworkPort*) (np->hdl);
		string str = _np->getElementName ();
		::snprintf(ele_name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * release
 */
extern "C" void 
np_release (DSDKNetworkPort* np)
{
	dsdkc_setError (0, NULL);
	CNetworkPort* _np = (CNetworkPort*) (np->hdl);
	delete _np;
	delete np;
}

static DSDKNetworkPortFT _npft = 
{
	np_getSystemCreationClassName,
	np_getSystemName,
	np_getCreationClassName,
	np_getName,
	np_getSpeed,
	np_getLinkTechnology,
	np_getLinkTechnologyStr,
	np_getPermanentAddress,
	np_getMaxSpeed,
	np_getRequestedSpeed,
	np_getDeviceID,
	np_getEnabledState,
	np_getEnabledStateStr,
	np_getRequestedState,
	np_getRequestedStateStr,
	np_getElementName,
	np_release
};

/*
 * Make a C based Network Port from the corresponding C++ object.
 */
static DSDKNetworkPort* 
makeDSDKNetworkPort (const CNetworkPort& np)
{
	DSDKNetworkPort* dsdk_np = new DSDKNetworkPort;
	if (NULL == dsdk_np) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_np->ft		= &_npft;
		dsdk_np->hdl	= new CNetworkPort (np);
		return dsdk_np;
	}
	CATCH_SET_ERROR ();

	delete dsdk_np;
	return NULL;

}


/*
 * getItem
 */
extern "C" DSDKNetworkPort* 
npi_getItem (DSDKNetworkPortIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CNetworkPort::iterator* _iter = (CNetworkPort::iterator*) (di->hdl);
		if (*_iter == CNetworkPort::iterator::end ()) { return NULL; }
		return makeDSDKNetworkPort (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
npi_next (DSDKNetworkPortIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CNetworkPort::iterator* _iter = (CNetworkPort::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
npi_isEnd (DSDKNetworkPortIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CNetworkPort::iterator* _iter = (CNetworkPort::iterator*) (di->hdl);
		return (*_iter == CNetworkPort::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
npi_release (DSDKNetworkPortIterator* di)
{
	dsdkc_setError (0, NULL);
	CNetworkPort::iterator* _iter = (CNetworkPort::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKNetworkPortIteratorFT _npift = 
{
	npi_getItem,
	npi_next,
	npi_isEnd,
	npi_release,
};


/*
 * Make a C based Network Port iterator from the corresponding C++ object.
 */
static DSDKNetworkPortIterator* 
makeDSDKNetworkPortIterator (const CNetworkPort::iterator& npi)
{

	DSDKNetworkPortIterator* dsdk_npi = new DSDKNetworkPortIterator;
	if (NULL == dsdk_npi) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_npi->ft  = &_npift;
		dsdk_npi->hdl = new CNetworkPort::iterator (npi);
		return dsdk_npi;
	}
	CATCH_SET_ERROR ();

	delete dsdk_npi;
	return NULL;
}


/*
 * enumNetworkPorts
 */
extern "C" DSDKNetworkPortIterator*
enumNetworkPorts (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CNetworkPort::iterator iter = CNetworkPort::enumNetworkPorts (
													(IClient*) client, 
													(cached ? true : false));

		return makeDSDKNetworkPortIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;
}




