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
 * powersupply_c.cpp
 * C wrapper for power supply.
 */
#include <vector>
#include <string>
#include <cstring>
#include <dsdk/oal/COALObject.h>
#include <dsdkc/powersupply_c.h>
#include <dsdk/powersupply.h>
#include <dsdkc/error_c.h>
#include <dsdk/dsdkexception.h>

using namespace dsdk;

/*
 * getSystemCreationClassName
 */
extern "C" void 
ps_getSystemCreationClassName (DSDKPowerSupply* ps, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupply* _ps = (CPowerSupply*) (ps->hdl);
		string str = _ps->getSystemCreationClassName ();
		::strncpy (name, str.c_str (), max_len);
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getSystemName
 */
extern "C" void 
ps_getSystemName (DSDKPowerSupply* ps, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupply* _ps = (CPowerSupply*) (ps->hdl);
		string str = _ps->getSystemName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getCreationClassName
 */
extern "C" void 
ps_getCreationClassName (DSDKPowerSupply* ps, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupply* _ps = (CPowerSupply*) (ps->hdl);
		string str = _ps->getCreationClassName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getDeviceID
 */
extern "C" void 
ps_getDeviceID (DSDKPowerSupply* ps, char* devid, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupply* _ps = (CPowerSupply*) (ps->hdl);
		string str = _ps->getDeviceID ();
		::snprintf(devid,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getTotalPower
 */
extern "C" uint32 
ps_getTotalPower (DSDKPowerSupply* ps)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupply* _ps = (CPowerSupply*) (ps->hdl);
		return _ps->getTotalPower ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getElementName
 */
extern "C" void 
ps_getElementName (DSDKPowerSupply* ps, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupply* _ps = (CPowerSupply*) (ps->hdl);
		string str = _ps->getElementName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getOperationalStatus
 */
extern "C" int 
ps_getOperationalStatus (DSDKPowerSupply* ps, uint16* op_status, int max_types)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupply* _ps = (CPowerSupply*) (ps->hdl);
		vector<uint16>	_op_status = _ps->getOperationalStatus ();
		for (size_t i = 0; (i < _op_status.size () && (i < (size_t)max_types)); i++)
		{
			op_status [i]  = _op_status [i];
		}
		return (int)_op_status.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getOperationalStatusStr
 */
extern "C" int 
ps_getOperationalStatusStr (DSDKPowerSupply* pm, char** os, int max_os, 
														int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupply* _ps		= (CPowerSupply*) (pm->hdl);
		vector <string> str	= _ps->getOperationalStatusStr ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_os)); i++)
		{
			::snprintf(os [i],   max_strlen, "%s",str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getHealthState
 */

extern "C" uint16 
ps_getHealthState (DSDKPowerSupply* ps)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupply* _ps = (CPowerSupply*) (ps->hdl);
		return _ps->getHealthState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getHealtStateStr
 */
extern "C" void 
ps_getHealthStateStr (DSDKPowerSupply* pm, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupply* _ps = (CPowerSupply*) (pm->hdl);
		string str = _ps->getHealthStateStr ();
		::snprintf(state,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getEnabledState
 */

extern "C" uint16 
ps_getEnabledState (DSDKPowerSupply* ps)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupply* _ps = (CPowerSupply*) (ps->hdl);
		return _ps->getEnabledState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEnabledStateStr
 */
extern "C" void 
ps_getEnabledStateStr (DSDKPowerSupply* pm, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupply* _ps = (CPowerSupply*) (pm->hdl);
		string str = _ps->getEnabledStateStr ();
		::snprintf(state,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getRequestedState
 */

extern "C" uint16 
ps_getRequestedState (DSDKPowerSupply* ps)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupply* _ps = (CPowerSupply*) (ps->hdl);
		return _ps->getRequestedState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getRequestedStateStr
 */
extern "C" void 
ps_getRequestedStateStr (DSDKPowerSupply* pm, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupply* _ps = (CPowerSupply*) (pm->hdl);
		string str = _ps->getRequestedStateStr ();
		::snprintf(state,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * enablePowerSupply
 */

extern "C" uint32 
ps_enablePowerSupply (DSDKPowerSupply* ps)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupply* _ps = (CPowerSupply*) (ps->hdl);
		return _ps->enablePowerSupply ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * disablePowerSupply
 */

extern "C" uint32
ps_disablePowerSupply (DSDKPowerSupply* ps)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupply* _ps = (CPowerSupply*) (ps->hdl);
		return _ps->disablePowerSupply ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * resetPowerSupply
 */

extern "C" uint32 
ps_resetPowerSupply (DSDKPowerSupply* ps)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupply* _ps = (CPowerSupply*) (ps->hdl);
		return _ps->resetPowerSupply ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * offlinePowerSupply
 */

extern "C" uint32 
ps_offlinePowerSupply (DSDKPowerSupply* ps)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupply* _ps = (CPowerSupply*) (ps->hdl);
		return _ps->offlinePowerSupply ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * release
 */
extern "C" void 
ps_release (DSDKPowerSupply* ps)
{
	dsdkc_setError (0, NULL);
	CPowerSupply* _ps = (CPowerSupply*) (ps->hdl);
	delete _ps;
	delete ps;
}


static DSDKPowerSupplyFT _psft = 
{
	ps_getSystemCreationClassName,
	ps_getSystemName,
	ps_getCreationClassName,
	ps_getDeviceID,
	ps_getTotalPower,
	ps_getElementName,
	ps_getOperationalStatus,
	ps_getOperationalStatusStr,
	ps_getHealthState,
	ps_getHealthStateStr,
	ps_getEnabledState,
	ps_getEnabledStateStr,
	ps_getRequestedState,
	ps_getRequestedStateStr,
	ps_enablePowerSupply,
	ps_disablePowerSupply,
	ps_resetPowerSupply,
	ps_offlinePowerSupply,
	ps_release
};


/*
 * Make a C based software from the corresponding C++ object.
 */
static DSDKPowerSupply* 
makeDSDKPowerSupply (const CPowerSupply& ps)
{
	DSDKPowerSupply* dsdk_ps = new DSDKPowerSupply;
	if (NULL == dsdk_ps) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_ps->ft  = &_psft;
		dsdk_ps->hdl = new CPowerSupply (ps);
		return dsdk_ps;
	}
	CATCH_SET_ERROR ();

	delete dsdk_ps;
	return NULL;

}


/*
 * getItem
 */
extern "C" DSDKPowerSupply* 
psi_getItem (DSDKPowerSupplyIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CPowerSupply::iterator* _iter = (CPowerSupply::iterator*) (di->hdl);
		if (*_iter == CPowerSupply::iterator::end ()) { return NULL; }
		return makeDSDKPowerSupply (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
psi_next (DSDKPowerSupplyIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CPowerSupply::iterator* _iter = (CPowerSupply::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
psi_isEnd (DSDKPowerSupplyIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CPowerSupply::iterator* _iter = (CPowerSupply::iterator*) (di->hdl);
		return (*_iter == CPowerSupply::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
psi_release (DSDKPowerSupplyIterator* di)
{
	dsdkc_setError (0, NULL);
	CPowerSupply::iterator* _iter = (CPowerSupply::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKPowerSupplyIteratorFT _psift = 
{
	psi_getItem,
	psi_next,
	psi_isEnd,
	psi_release
};


/*
 * Make a C based software iterator from the corresponding C++ object.
 */
static DSDKPowerSupplyIterator* 
makeDSDKPowerSupplyIterator (const CPowerSupply::iterator& psi)
{
	DSDKPowerSupplyIterator* dsdk_psi = new DSDKPowerSupplyIterator;
	if (NULL == dsdk_psi) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_psi->ft  = &_psift;
		dsdk_psi->hdl = new CPowerSupply::iterator (psi);
		return dsdk_psi;
	}
	CATCH_SET_ERROR ();

	delete dsdk_psi;
	return NULL;
}


/*
 * enumPowerSupplys
 */
extern "C" DSDKPowerSupplyIterator*
enumPowerSupplies (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CPowerSupply::iterator iter = CPowerSupply::enumPowerSupplies (
														(IClient*) client, 
														(cached ? true : false));
		return makeDSDKPowerSupplyIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;

}

/*
 * getInstsnceID
 */
extern "C" void 
psrs_getInstsnceID (DSDKPowerSupplyRedundancySet* rs, char* ins_id, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupplyRedundancySet* _rs = (CPowerSupplyRedundancySet*) (rs->hdl);
		string str = _rs->getInstanceID ();
		::snprintf(ins_id,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getRedundancyStatus
 */
extern "C" uint16 
psrs_getRedundancyStatus (DSDKPowerSupplyRedundancySet* rs)
{
	dsdkc_setError (0, NULL);
	try
	{
		CPowerSupplyRedundancySet* _rs = (CPowerSupplyRedundancySet*) (rs->hdl);
		return _rs->getRedundancyStatus ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getType
 */
extern "C" void 
psrs_getType (DSDKPowerSupplyRedundancySet* rs, Type_E** type, int max_type)
{
	dsdkc_setError (0, NULL);
	try
	{
		CPowerSupplyRedundancySet* _rs = (CPowerSupplyRedundancySet*) (rs->hdl);
		vector<CPowerSupplyRedundancySet::Type_E> _type = _rs->getType ();

		for (size_t i = 0; i < _type.size (); i++)
		{
			*type [i] = (Type_E)_type [i];
		}
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getMinimumNumberNeeded
 */
extern "C" uint32 
psrs_getMinimumNumberNeeded (DSDKPowerSupplyRedundancySet* rs)
{
	dsdkc_setError (0, NULL);
	try
	{
		CPowerSupplyRedundancySet* _rs = (CPowerSupplyRedundancySet*) (rs->hdl);
		return _rs->getMinimumNumberNeeded ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getElementName
 */
extern "C" void 
psrs_getElementName (DSDKPowerSupplyRedundancySet* rs, char* ele_name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPowerSupplyRedundancySet* _rs = (CPowerSupplyRedundancySet*) (rs->hdl);
		string str = _rs->getElementName ();
		::snprintf(ele_name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}
/*
 * failover
 */
extern "C" uint32
psrs_failover (DSDKPowerSupplyRedundancySet* rs, DSDKPowerSupply *ps_from, DSDKPowerSupply *ps_to)
{
	dsdkc_setError (0, NULL);
	try
	{
		CPowerSupplyRedundancySet* _rs = (CPowerSupplyRedundancySet*) (rs->hdl);
		CPowerSupply* _ps_from = (CPowerSupply*)  (ps_from->hdl);
		CPowerSupply* _ps_to = (CPowerSupply*) (ps_to->hdl);

		return _rs->failover (*_ps_from, *_ps_to);
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * release
 */
extern "C" void 
psrs_release (DSDKPowerSupplyRedundancySet* cs)
{
	dsdkc_setError (0, NULL);
	CPowerSupplyRedundancySet* _ps = (CPowerSupplyRedundancySet*) (cs->hdl);
	delete _ps;
	delete cs;
}


static DSDKPowerSupplyRedundancySetFT _csft = 
{
	psrs_getInstsnceID,
	psrs_getRedundancyStatus,
	psrs_getType,
	psrs_getMinimumNumberNeeded,
	psrs_getElementName,
	psrs_failover,
	psrs_release
};


/*
 * Make a C based power supply redundancy set from the corresponding C++ object.
 */
static DSDKPowerSupplyRedundancySet* 
makeDSDKPowerSupplyRedundancySet (const CPowerSupplyRedundancySet& cs)
{
	DSDKPowerSupplyRedundancySet* dsdk_cs = new DSDKPowerSupplyRedundancySet;
	if (NULL == dsdk_cs) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_cs->ft  = &_csft;
		dsdk_cs->hdl = new CPowerSupplyRedundancySet (cs);
		return dsdk_cs;
	}
	CATCH_SET_ERROR ();

	delete dsdk_cs;
	return NULL;
}


/*
 * getItem
 */
extern "C" DSDKPowerSupplyRedundancySet* 
psrsi_getItem (DSDKPowerSupplyRedundancySetIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CPowerSupplyRedundancySet::iterator* _iter = (CPowerSupplyRedundancySet::iterator*) (di->hdl);
		if (*_iter == CPowerSupplyRedundancySet::iterator::end ()) { return NULL; }
		return makeDSDKPowerSupplyRedundancySet (*(*_iter));
	}
	CATCH_SET_ERROR ();

	return NULL;
}


/*
 * next
 */
extern "C" void 
psrsi_next (DSDKPowerSupplyRedundancySetIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CPowerSupplyRedundancySet::iterator* _iter = (CPowerSupplyRedundancySet::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
psrsi_isEnd (DSDKPowerSupplyRedundancySetIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CPowerSupplyRedundancySet::iterator* _iter = (CPowerSupplyRedundancySet::iterator*) (di->hdl);
		return (*_iter == CPowerSupplyRedundancySet::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
psrsi_release (DSDKPowerSupplyRedundancySetIterator* di)
{
	dsdkc_setError (0, NULL);
	CPowerSupplyRedundancySet::iterator* _iter = (CPowerSupplyRedundancySet::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKPowerSupplyRedundancySetIteratorFT _psrsift = 
{
	psrsi_getItem,
	psrsi_next,
	psrsi_isEnd,
	psrsi_release
};


/*
 * Make a C based power supply redundancy set iterator from the corresponding C++ object.
 */
static DSDKPowerSupplyRedundancySetIterator* 
makeDSDKPowerSupplyRedundancySetIterator (const CPowerSupplyRedundancySet::iterator& psrsi)
{
	DSDKPowerSupplyRedundancySetIterator* dsdk_psrsi = new DSDKPowerSupplyRedundancySetIterator;
	if (NULL == dsdk_psrsi) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_psrsi->ft  = &_psrsift;
		dsdk_psrsi->hdl = new CPowerSupplyRedundancySet::iterator (psrsi);
		return dsdk_psrsi;
	}
	CATCH_SET_ERROR ();

	delete dsdk_psrsi;
	return NULL;
}


/*
 * enumPowerSupplyRedundancySets
 */
extern "C" DSDKPowerSupplyRedundancySetIterator*
enumPowerSupplyRedundancySets (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CPowerSupplyRedundancySet::iterator iter = 
			CPowerSupplyRedundancySet::enumPowerSupplyRedundancySets (
													(IClient*) client, 
													(cached ? true : false));
		return makeDSDKPowerSupplyRedundancySetIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;
}


