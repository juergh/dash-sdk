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
 * fan_c.cpp
 * C wrapper for fan.
 */
#include <vector>
#include <string>
#include <cstring>
#include <dsdk/oal/COALObject.h>
#include <dsdkc/fan_c.h>
#include <dsdk/fan.h>
#include <dsdkc/error_c.h>
#include <dsdk/dsdkexception.h>

using namespace dsdk;

/*
 * getSystemCreationClassName
 */
extern "C" void 
fan_getSystemCreationClassName (DSDKFan* fan, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CFan*_fan = (CFan*) (fan->hdl);
		string str = _fan->getSystemCreationClassName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getSystemName
 */
extern "C" void 
fan_getSystemName (DSDKFan* fan, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CFan*_fan = (CFan*) (fan->hdl);
		string str = _fan->getSystemName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getCreationClassName
 */
extern "C" void 
fan_getCreationClassName (DSDKFan* fan, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CFan*_fan = (CFan*) (fan->hdl);
		string str = _fan->getCreationClassName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getDeviceID
 */
extern "C" void 
fan_getDeviceID (DSDKFan* fan, char* devid, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CFan*_fan = (CFan*) (fan->hdl);
		string str = _fan->getDeviceID ();
		::snprintf(devid,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getOperationalStatus
 */
extern "C" int 
fan_getOperationalStatus (DSDKFan* fan, uint16* op_status, int max_types)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CFan*_fan = (CFan*) (fan->hdl);
		vector<uint16>	_op_status = _fan->getOperationalStatus ();
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
 * getOperationalStatus
 */
extern "C" int 
fan_getOperationalStatusStr (DSDKFan* fan, char** os, int max_os, 
														int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CFan* _proc		= (CFan*) (fan->hdl);
		vector <string> str	= _proc->getOperationalStatusStr ();
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
fan_getHealthState (DSDKFan* fan)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CFan*_fan = (CFan*) (fan->hdl);
		return _fan->getHealthState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getHealtStateStr
 */
extern "C" void 
fan_getHealthStateStr (DSDKFan* fan, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CFan* _fan = (CFan*) (fan->hdl);
		string str = _fan->getHealthStateStr ();
		::snprintf(state,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * isVariablespeed
 */
extern "C" BOOL 
fan_isVariableSpeed (DSDKFan* fan)
{
	dsdkc_setError (0, NULL);
	try
	{
		CFan*_fan = (CFan*) (fan->hdl);
		return _fan->isVariableSpeed ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getSpeed
 */
extern "C" void 
fan_getSpeed (DSDKFan* fan, char* speed, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CFan* _fan = (CFan*) (fan->hdl);
		string str = _fan->getSpeed ();
		::snprintf(speed,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getDesiredSpeed
 */
extern "C" uint64 
fan_getDesiredSpeed (DSDKFan* fan)
{
	dsdkc_setError (0, NULL);
	try
	{
		CFan* _fan = (CFan*) (fan->hdl);
		return _fan->getDesiredSpeed ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * set Desired Speed 
 */
extern "C" uint32 
fan_setDesiredSpeed (DSDKFan* fan, uint64 speed)
{
	dsdkc_setError (0, NULL);
	try
	{
		CFan* _fan = (CFan*) (fan->hdl);
		return _fan->setDesiredSpeed (speed);
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * isActiveCooling
 */
extern "C" BOOL 
fan_isActiveCooling (DSDKFan* fan)
{
	dsdkc_setError (0, NULL);
	try
	{
		CFan*_fan = (CFan*) (fan->hdl);
		return _fan->isActiveCooling ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEnabledState
 */

extern "C" uint16 
fan_getEnabledState (DSDKFan* fan)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CFan*_fan = (CFan*) (fan->hdl);
		return _fan->getEnabledState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEnabledStateStr
 */
extern "C" void 
fan_getEnabledStateStr (DSDKFan* fan, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CFan* _fan = (CFan*) (fan->hdl);
		string str = _fan->getEnabledStateStr ();
		::snprintf(state,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getRequestedState
 */
extern "C" uint16 
fan_getRequestedState (DSDKFan* fan)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CFan*_fan = (CFan*) (fan->hdl);
		return _fan->getRequestedState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getRequestedStateStr
 */
extern "C" void 
fan_getRequestedStateStr (DSDKFan* fan, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CFan* _fan = (CFan*) (fan->hdl);
		string str = _fan->getRequestedStateStr ();
		::snprintf(state,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * get Elemenet Name
 */
extern "C" void 
fan_getElementName (DSDKFan* fan, char* ele_name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CFan* _fan = (CFan*) (fan->hdl);
		string str = _fan->getElementName ();
		::snprintf(ele_name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getSetSpeedErrStr
 */
extern "C" void 
fan_getSetSpeedErrStr (DSDKFan* fan, uint32 err, char* ret_error, int max_len) 
{
	dsdkc_setError (0, NULL);
	try 
	{
		CFan* _fan = (CFan*) (fan->hdl);
		string str = _fan->getSetSpeedErrStr (err);
		::snprintf(ret_error,   max_len, "%s",str.c_str ());		
	}
	CATCH_SET_ERROR ();
	return;
}


/*
 * release
 */
extern "C" void 
fan_release (DSDKFan* fan)
{
	dsdkc_setError (0, NULL);
	CFan* _fan = (CFan*) (fan->hdl);
	delete _fan;
	delete fan;
}

static DSDKFanFT _fanft = 
{
	fan_getSystemCreationClassName,
	fan_getSystemName,
	fan_getCreationClassName,
	fan_getDeviceID,
	fan_getOperationalStatus,
	fan_getOperationalStatusStr,
	fan_getHealthState,
	fan_getHealthStateStr,
	fan_isVariableSpeed,
	fan_getSpeed,
	fan_getDesiredSpeed,
	fan_setDesiredSpeed,
	fan_isActiveCooling,
	fan_getEnabledState,
	fan_getEnabledStateStr,
	fan_getRequestedState,
	fan_getRequestedStateStr,
	fan_getElementName,
	fan_getSetSpeedErrStr,
	fan_release,
};


/*
 * Make a C based fan from the corresponding C++ object.
 */
static DSDKFan* 
makeDSDKFan (const CFan& fan)
{
	DSDKFan* dsdk_fan = new DSDKFan;
	if (NULL == dsdk_fan) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_fan->ft  = &_fanft;
		dsdk_fan->hdl = new CFan (fan);
		return dsdk_fan;
	}
	CATCH_SET_ERROR ();

	delete dsdk_fan;
	return NULL;

}


/*
 * getItem
 */
extern "C" DSDKFan* 
fani_getItem (DSDKFanIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CFan::iterator* _iter = (CFan::iterator*) (di->hdl);
		if (*_iter == CFan::iterator::end ()) { return NULL; }
		return makeDSDKFan (*(*_iter));
	}
	CATCH_SET_ERROR ();

	return NULL;
}


/*
 * next
 */
extern "C" void 
fani_next (DSDKFanIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CFan::iterator* _iter = (CFan::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
fani_isEnd (DSDKFanIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CFan::iterator* _iter = (CFan::iterator*) (di->hdl);
		return (*_iter == CFan::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
fani_release (DSDKFanIterator* di)
{
	dsdkc_setError (0, NULL);
	CFan::iterator* _iter = (CFan::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKFanIteratorFT _fanift = 
{
	fani_getItem,
	fani_next,
	fani_isEnd,
	fani_release
};


/*
 * Make a C based fan iterator from the corresponding C++ object.
 */
static DSDKFanIterator* 
makeDSDKFanIterator (const CFan::iterator& fani)
{
	DSDKFanIterator* dsdk_fani = new DSDKFanIterator;
	if (NULL == dsdk_fani) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_fani->ft  = &_fanift;
		dsdk_fani->hdl = new CFan::iterator (fani);
		return dsdk_fani;
	}
	CATCH_SET_ERROR ();

	delete dsdk_fani;
	return NULL;
}


/*
 * enumFans
 */
extern "C" DSDKFanIterator*
enumFans (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CFan::iterator iter = CFan::enumFans ((IClient*) client, (cached ? true : false));
		return makeDSDKFanIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;

}


/*
 * getRedundancyStatus
 */
extern "C" int 
fanrs_getRedundancyStatus (DSDKFanRedundancySet* rs)
{
	dsdkc_setError (0, NULL);
	try
	{
		CFanRedundancySet* _rs = (CFanRedundancySet*) (rs->hdl);
		return _rs->getRedundancyStatus ();
	}
	CATCH_SET_ERROR ();
	return -1;
}

/*
 * getType
 */
extern "C" void 
fanrs_getType (DSDKFanRedundancySet* rs, Type_E** type, int max_type)
{
	dsdkc_setError (0, NULL);
	try
	{
		CFanRedundancySet* _rs = (CFanRedundancySet*) (rs->hdl);
		vector<CFanRedundancySet::Type_E> _type = _rs->getType ();

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
fanrs_getMinimumNumberNeeded (DSDKFanRedundancySet* rs)
{
	dsdkc_setError (0, NULL);
	try
	{
		CFanRedundancySet* _rs = (CFanRedundancySet*) (rs->hdl);
		return _rs->getMinimumNumberNeeded ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * failover
 */
extern "C" uint32
fanrs_failover (DSDKFanRedundancySet* rs, DSDKFan *fan_from, DSDKFan *fan_to)
{
	dsdkc_setError (0, NULL);
	try
	{
		CFanRedundancySet* _rs = (CFanRedundancySet*) (rs->hdl);
		CFan* _fan_from = (CFan*)  (fan_from->hdl);
		CFan* _fan_to = (CFan*) (fan_to->hdl);

		return _rs->failover (*_fan_from, *_fan_to);
	}
	CATCH_SET_ERROR ();
	return 0;
}


/*
 * release
 */
extern "C" void 
fanrs_release (DSDKFanRedundancySet* cs)
{
	dsdkc_setError (0, NULL);
	CFanRedundancySet* _cs = (CFanRedundancySet*) (cs->hdl);
	delete _cs;
	delete cs;
}


static DSDKFanRedundancySetFT _csft = 
{
	fanrs_getRedundancyStatus,
	fanrs_getType,
	fanrs_getMinimumNumberNeeded,
	fanrs_failover,
	fanrs_release
};


/*
 * Make a C based fan redundancy set from the corresponding C++ object.
 */
static DSDKFanRedundancySet* 
makeDSDKFanRedundancySet (const CFanRedundancySet& cs)
{
	DSDKFanRedundancySet* dsdk_cs = new DSDKFanRedundancySet;
	if (NULL == dsdk_cs) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_cs->ft  = &_csft;
		dsdk_cs->hdl = new CFanRedundancySet (cs);
		return dsdk_cs;
	}
	CATCH_SET_ERROR ();

	delete dsdk_cs;
	return NULL;
}


/*
 * getItem
 */
extern "C" DSDKFanRedundancySet* 
rsi_getItem (DSDKFanRedundancySetIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CFanRedundancySet::iterator* _iter = (CFanRedundancySet::iterator*) (di->hdl);
		if (*_iter == CFanRedundancySet::iterator::end ()) { return NULL; }
		return makeDSDKFanRedundancySet (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
rsi_next (DSDKFanRedundancySetIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CFanRedundancySet::iterator* _iter = (CFanRedundancySet::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
rsi_isEnd (DSDKFanRedundancySetIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CFanRedundancySet::iterator* _iter = (CFanRedundancySet::iterator*) (di->hdl);
		return (*_iter == CFanRedundancySet::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
rsi_release (DSDKFanRedundancySetIterator* di)
{
	dsdkc_setError (0, NULL);
	CFanRedundancySet::iterator* _iter = (CFanRedundancySet::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKFanRedundancySetIteratorFT _rsift = 
{
	rsi_getItem,
	rsi_next,
	rsi_isEnd,
	rsi_release
};


/*
 * Make a C based fan redundancy set iterator from the corresponding C++ object.
 */
static DSDKFanRedundancySetIterator* 
makeDSDKFanRedundancySetIterator (const CFanRedundancySet::iterator& rsi)
{
	DSDKFanRedundancySetIterator* dsdk_rsi = new DSDKFanRedundancySetIterator;
	if (NULL == dsdk_rsi) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_rsi->ft  = &_rsift;
		dsdk_rsi->hdl = new CFanRedundancySet::iterator (rsi);
		return dsdk_rsi;
	}
	CATCH_SET_ERROR ();

	delete dsdk_rsi;
	return NULL;

}


/*
 * enumCFanRedundancySets
 */
extern "C" DSDKFanRedundancySetIterator*
enumFanRedundancySets (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CFanRedundancySet::iterator iter = CFanRedundancySet::enumFanRedundancySets (
													(IClient*) client, 
													(cached ? true : false));
		return makeDSDKFanRedundancySetIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;
}


