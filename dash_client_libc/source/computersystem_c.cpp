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
 * computersystem_c.cpp
 * C wrapper for computer system.
 */
#include <vector>
#include <string>
#include <cstring>
#include <dsdk/oal/COALObject.h>
#include <dsdkc/computersystem_c.h>
#include <dsdk/computersystem.h>
#include <dsdkc/error_c.h>


using namespace dsdk;

/*
 * getName
 */
extern "C" void 
cs_getName (DSDKComputerSystem* cs, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		string str = _cs->getName ();
		::snprintf(name,  max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getElementName
 */
extern "C" void 
cs_getElementName (DSDKComputerSystem* cs, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		string str = _cs->getElementName ();
		::snprintf(name,  max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getPrimaryOwner
 */
extern "C" void 
cs_getPrimaryOwner (DSDKComputerSystem* cs, char* owner, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		string str = _cs->getPrimaryOwner ();
		::snprintf(owner,  max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}


/*
 * getPrimaryOwnerContact
 */
extern "C" void 
cs_getPrimaryOwnerContact (DSDKComputerSystem* cs, char* contact, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		string str = _cs->getPrimaryOwnerContact ();
		::snprintf(contact,  max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getEnabledState
 */
extern "C" uint16 
cs_getEnabledState (DSDKComputerSystem* cs)
{
	dsdkc_setError (0, NULL);
	try
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		return _cs->getEnabledState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEnabledStateStr
 */
extern "C" void 
cs_getEnabledStateStr (DSDKComputerSystem* cs, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		string str = _cs->getEnabledStateStr ();
		::snprintf(state,  max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getRequestedState
 */
extern "C" uint16 
cs_getRequestedState (DSDKComputerSystem* cs)
{
	dsdkc_setError (0, NULL);
	try
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		return _cs->getRequestedState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getRequestedStateStr
 */
extern "C" void 
cs_getRequestedStateStr (DSDKComputerSystem* cs, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		string str = _cs->getRequestedStateStr ();
		::snprintf(state,  max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getDedicated
 */
extern "C" int 
cs_getDedicated (DSDKComputerSystem* cs, uint16* dedicated, int max_types)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		vector<uint16>	_dedicated = _cs->getDedicated ();
		for (size_t i = 0; (i < _dedicated.size () && (i < (size_t)max_types)); i++)
		{
			dedicated [i]  = _dedicated [i];
		}
		return (int)_dedicated.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getDedicatedStr
 */
extern "C" int 
cs_getDedicatedStr (DSDKComputerSystem* cs, char** dedicated, int max_dedicated, 
														int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CComputerSystem* _cs	= (CComputerSystem*) (cs->hdl);
		vector <string> str		= _cs->getDedicatedStr ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_dedicated)); i++)
		{
			::snprintf(dedicated [i],  max_strlen, "%s", str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getPowerState
 */
extern "C" uint16 
cs_getPowerState (DSDKComputerSystem* cs)
{
	dsdkc_setError (0, NULL);
	try
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		return _cs->getPowerState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getPowerStateStr
 */
extern "C" void 
cs_getPowerStateStr (DSDKComputerSystem* cs, char* ps, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		string str = _cs->getPowerStateStr ();
		::snprintf(ps,  max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getRequestedPowerState
 */
extern "C" uint16 
cs_getRequestedPowerState (DSDKComputerSystem* cs)
{
	dsdkc_setError (0, NULL);
	try
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		return _cs->getRequestedPowerState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getRequestedPowerStateStr
 */
extern "C" void 
cs_getRequestedPowerStateStr (DSDKComputerSystem* cs, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		string str = _cs->getRequestedPowerStateStr ();
		::snprintf(state,  max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getPowerChangeCapabilities
 */
extern "C" int 
cs_getPowerChangeCapabilities (DSDKComputerSystem* cs, uint16* power_change, int max_types)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		vector<uint16>	_power_change = _cs->getPowerChangeCapabilities ();
		for (size_t i = 0; (i < _power_change.size () && (i < (size_t)max_types)); i++)
		{
			power_change [i]  = _power_change [i];
		}
		return (int)_power_change.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getPowerChangeCapabilitiesStr
 */
extern "C" int 
cs_getPowerChangeCapabilitiesStr (DSDKComputerSystem* cs, char** capabilities, int max_capabilities, 
														int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CComputerSystem* _cs	= (CComputerSystem*) (cs->hdl);
		vector <string> str		= _cs->getPowerChangeCapabilitiesStr ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_capabilities)); i++)
		{
			::snprintf(capabilities [i],  max_strlen, "%s", str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getPowerStatesSupported
 */
extern "C" int 
cs_getPowerStatesSupported (DSDKComputerSystem* cs, uint16* power_states, int max_types)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		vector<uint16>	_power_states = _cs->getPowerStatesSupported ();
		for (size_t i = 0; (i < _power_states.size () && (i < (size_t)max_types)); i++)
		{
			power_states [i]  = _power_states [i];
		}
		return (int)_power_states.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}
/*
 * getPowerStatesSupportedStr
 */
extern "C" int 
cs_getPowerStatesSupportedStr (DSDKComputerSystem* cs, char** power_states, int max_states, 
														int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CComputerSystem* _cs	= (CComputerSystem*) (cs->hdl);
		vector <string> str		= _cs->getPowerStatesSupportedStr ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_states)); i++)
		{
			::snprintf(power_states [i],  max_strlen, "%s", str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}


/*
 * getTestName
 */

extern "C" void 
csi_getTestName (DSDKComputerSystemIterator* cs, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		string str = _cs->getName ();
		::snprintf(name,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}
 
/*
 * powerOn
 */
extern "C" uint32 
cs_powerOn (DSDKComputerSystem* cs)
{
	dsdkc_setError (0, NULL);
	try
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		return _cs->powerOn ();
	}
	CATCH_SET_ERROR ();
	return 0;
}


/*
 * powerOff
 */
extern "C" uint32 
cs_powerOff (DSDKComputerSystem* cs)
{
	dsdkc_setError (0, NULL);
	try
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		return _cs->powerOff ();
	}
	CATCH_SET_ERROR ();
	return 0;
}


/*
 * powerCycle
 */
extern "C" uint32 
cs_powerCycle (DSDKComputerSystem* cs)
{
	dsdkc_setError (0, NULL);
	try
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		return _cs->powerCycle ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * powerCycle
 */
extern "C" uint32 
cs_powerReset (DSDKComputerSystem* cs)
{
	dsdkc_setError (0, NULL);
	try
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		return _cs->powerReset ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * Power Reset Graceful 
 */
extern "C" uint32 
cs_powerResetGraceful (DSDKComputerSystem* cs)
{
	dsdkc_setError (0, NULL);
	try
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		return _cs->powerResetGraceful ();
	}
	CATCH_SET_ERROR ();
	return 0;
}


/*
 * getReqPwrStateChangeErrStr
 */
extern "C" void 
cs_getReqPwrStateChangeErrStr (DSDKComputerSystem* cs, uint32 err, char* err_str, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		string str = _cs->getReqPwrStateChangeErrStr (err);
		::snprintf(err_str,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}


/*
 * release
 */
extern "C" void 
cs_release (DSDKComputerSystem* cs)
{
	dsdkc_setError (0, NULL);
	CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
	delete _cs;
	delete cs;
}

static DSDKComputerSystemFT _csft = 
{
	cs_getName,
	cs_getElementName,
	cs_getPrimaryOwner,
	cs_getPrimaryOwnerContact,
	cs_getEnabledState,
	cs_getEnabledStateStr,
	cs_getRequestedState,
	cs_getRequestedStateStr,
	cs_getDedicated,
	cs_getDedicatedStr,
	cs_getPowerState,
	cs_getPowerStateStr,
	cs_getRequestedPowerState,
	cs_getRequestedPowerStateStr,
	cs_getPowerChangeCapabilities,
	cs_getPowerChangeCapabilitiesStr,
	cs_getPowerStatesSupported,
	cs_getPowerStatesSupportedStr,
	cs_powerOn,
	cs_powerOff,
	cs_powerCycle,
	cs_powerReset,
	cs_powerResetGraceful,
	cs_getReqPwrStateChangeErrStr,
	cs_release,
};


/**
 * Make a C based Computer system from the corresponding C++ object.
 */
static DSDKComputerSystem* 
makeDSDKComputerSystem (const CComputerSystem& cs)
{
	DSDKComputerSystem* dsdk_cs = new DSDKComputerSystem;
	if (NULL == dsdk_cs) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_cs->ft		= &_csft;
		dsdk_cs->hdl	= new CComputerSystem (cs);
		return dsdk_cs;
	}
	CATCH_SET_ERROR ();

	delete dsdk_cs;
	return NULL;

}


/*
 * getItem
 */
extern "C" DSDKComputerSystem* 
csi_getItem (DSDKComputerSystemIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CComputerSystem::iterator* _iter = (CComputerSystem::iterator*) (di->hdl);
		if (*_iter == CComputerSystem::iterator::end ()) { return NULL; }
		return makeDSDKComputerSystem (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
csi_next (DSDKComputerSystemIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CComputerSystem::iterator* _iter = (CComputerSystem::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
csi_isEnd (DSDKComputerSystemIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CComputerSystem::iterator* _iter = (CComputerSystem::iterator*) (di->hdl);
		return (*_iter == CComputerSystem::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 0;
}


/*
 * release
 */
extern "C" void 
csi_release (DSDKComputerSystemIterator* di)
{
	dsdkc_setError (0, NULL);
	CComputerSystem::iterator* _iter = (CComputerSystem::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKComputerSystemIteratorFT _csift = 
{
	csi_getItem,
	csi_next,
	csi_isEnd,
	csi_release,
	csi_getTestName 
};


/**
 * Make a C based Computer system iterator from the corresponding C++ object.
 */
static DSDKComputerSystemIterator* 
makeDSDKComputerSystemIterator (const CComputerSystem::iterator& csi)
{

	DSDKComputerSystemIterator* dsdk_csi = new DSDKComputerSystemIterator;
	if (NULL == dsdk_csi) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_csi->ft  = &_csift;
		dsdk_csi->hdl = new CComputerSystem::iterator (csi);
		return dsdk_csi;
	}
	CATCH_SET_ERROR ();

	delete dsdk_csi;
	return NULL;
}


/*
 * enumComputerSystems
 */
extern "C" DSDKComputerSystemIterator*
enumComputerSystems (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CComputerSystem::iterator iter = CComputerSystem::enumComputerSystems (
													(IClient*) client, 
													(cached ? true : false));

		return makeDSDKComputerSystemIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;
}


