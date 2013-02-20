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
 * battery_c.cpp
 * C wrapper for battery.
 */
#include <vector>
#include <string>
#include <cstring>
#include <dsdk/oal/COALObject.h>
#include <dsdkc/battery_c.h>
#include <dsdk/battery.h>
#include <dsdkc/error_c.h>


using namespace dsdk;

/*
 * getSystemCreationClassName
 */
extern "C" void 
bat_getSystemCreationClassName (DSDKBattery* bat, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBattery*_bat = (CBattery*) (bat->hdl);
		string str = _bat->getSystemCreationClassName ();
		::snprintf( name, max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getSystemName
 */
extern "C" void 
bat_getSystemName (DSDKBattery* bat, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBattery*_bat = (CBattery*) (bat->hdl);
		string str = _bat->getSystemName ();
		::snprintf( name, max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getCreationClassName
 */
extern "C" void 
bat_getCreationClassName (DSDKBattery* bat, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBattery*_bat = (CBattery*) (bat->hdl);
		string str = _bat->getCreationClassName ();
		::snprintf( name, max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getDeviceID
 */
extern "C" void 
bat_getDeviceID (DSDKBattery* bat, char* devid, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBattery*_bat = (CBattery*) (bat->hdl);
		string str = _bat->getDeviceID ();
		::snprintf( devid, max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getBatteryStatus
 */
extern "C" uint16 
bat_getBatteryStatus (DSDKBattery* bat)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		return _bat->getBatteryStatus ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getBatteryStatusStr
 */
extern "C" void 
bat_getBatteryStatusStr (DSDKBattery* bat, char* status, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		string str = _bat->getBatteryStatusStr ();
		::snprintf( status, max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getOperationalStatus
 */
extern "C" int 
bat_getOperationalStatus (DSDKBattery* bat, uint16* op_status, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		vector<uint16>	_op_status = _bat->getOperationalStatus ();
		for (size_t i = 0; (i < _op_status.size () && (i < (size_t)max_len)); i++)
		{
			op_status [i]  = _op_status [i];
		}
		return (int)_op_status.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getOperationalStatuss 
 */
extern "C" int 
bat_getOperationalStatusStr (DSDKBattery* bat, char** os, int max_os, 
														int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBattery* _bat		= (CBattery*) (bat->hdl);
		vector <string> str	= _bat->getOperationalStatusStr ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_os)); i++)
		{
			::snprintf( os [i], max_strlen, "%s", str [i].c_str ());
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
bat_getHealthState (DSDKBattery* bat)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		return _bat->getHealthState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getHealtStateStr
 */
extern "C" void 
bat_getHealthStateStr (DSDKBattery* bat, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		string str = _bat->getHealthStateStr ();
		::snprintf( state, max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getEnabledState
 */
extern "C" uint16 
bat_getEnabledState (DSDKBattery* bat)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		return _bat->getEnabledState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEnabledStateStr
 */
extern "C" void 
bat_getEnabledStateStr (DSDKBattery* bat, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		string str = _bat->getEnabledStateStr ();
		::snprintf( state, max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getRequestedState
 */
extern "C" uint16 
bat_getRequestedState (DSDKBattery* bat)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		return _bat->getRequestedState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getRequestedStateStr
 */
extern "C" void 
bat_getRequestedStateStr (DSDKBattery* bat, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		string str = _bat->getRequestedStateStr ();
		::snprintf( state, max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getElementName
 */
extern "C" void 
bat_getElementName (DSDKBattery* bat, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBattery*_bat = (CBattery*) (bat->hdl);
		string str = _bat->getElementName ();
		::snprintf( name, max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getChemistry
 */

extern "C" uint16 
bat_getChemistry (DSDKBattery* bat)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		return _bat->getChemistry ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getMaxRechargeCount
 */

extern "C" uint32 
bat_getMaxRechargeCount (DSDKBattery* bat)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		return _bat->getMaxRechargeCount ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getRechargeCount
 */

extern "C" uint32 
bat_getRechargeCount (DSDKBattery* bat)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		return _bat->getRechargeCount ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getExpectedLife
 */

extern "C" uint32 
bat_getExpectedLife (DSDKBattery* bat)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		return _bat->getExpectedLife ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEstimatedRunTime
 */
extern "C" uint32 
bat_getEstimatedRunTime (DSDKBattery* bat)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		return _bat->getEstimatedRunTime ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getTimeToFullCharge
 */
extern "C" uint32 
bat_getTimeToFullCharge (DSDKBattery* bat)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		return _bat->getTimeToFullCharge ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getMaxRechargeTime
 */
extern "C" uint32 
bat_getMaxRechargeTime (DSDKBattery* bat)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		return _bat->getMaxRechargeTime ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * Enable/Turn On Battery
 */
extern "C" void 
bat_enable (DSDKBattery* bat)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		_bat->enable ();
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * Disable/Turn off Battery
 */
extern "C" void 
bat_disable (DSDKBattery* bat)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		_bat->disable ();
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * Test/perform recalculation of charge thresholds.
 */
extern "C" void 
bat_test (DSDKBattery* bat)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		_bat->test ();
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * Reset/recharge of battery.
 */
extern "C" void 
bat_reset (DSDKBattery* bat)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBattery* _bat = (CBattery*) (bat->hdl);
		_bat->reset ();
	}
	CATCH_SET_ERROR ();
	return;
}


/*
 * release
 */
extern "C" void 
bat_release (DSDKBattery* bat)
{
	dsdkc_setError (0, NULL);
	CBattery* _bat = (CBattery*) (bat->hdl);
	delete _bat;
	delete bat;
}

static DSDKBatteryFT _batft = 
{
	bat_getSystemCreationClassName,
	bat_getSystemName,
	bat_getCreationClassName,
	bat_getDeviceID,
	bat_getBatteryStatus,
	bat_getBatteryStatusStr,
	bat_getOperationalStatus,
	bat_getOperationalStatusStr,
	bat_getHealthState,
	bat_getHealthStateStr,
	bat_getEnabledState,
	bat_getEnabledStateStr,
	bat_getRequestedState,
	bat_getRequestedStateStr,
	bat_getElementName,
	bat_getChemistry,
	bat_getMaxRechargeCount,
	bat_getRechargeCount,
	bat_getExpectedLife,
	bat_getEstimatedRunTime,
	bat_getTimeToFullCharge,
	bat_getMaxRechargeTime,
	bat_enable,
	bat_disable,
	bat_test,
	bat_reset,
	bat_release,
};


/*
 * Make a C based Battery from the corresponding C++ object.
 */
static DSDKBattery* 
makeDSDKBattery (const CBattery& bat)
{
	DSDKBattery* dsdk_bat = new DSDKBattery;
	if (NULL == dsdk_bat) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_bat->ft	= &_batft;
		dsdk_bat->hdl	= new CBattery (bat);
		return dsdk_bat;
	}
	CATCH_SET_ERROR ();

	delete dsdk_bat;
	return NULL;

}


/*
 * getItem
 */
extern "C" DSDKBattery* 
bati_getItem (DSDKBatteryIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBattery::iterator* _iter = (CBattery::iterator*) (di->hdl);
		if (*_iter == CBattery::iterator::end ()) { return NULL; }
		return makeDSDKBattery (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
bati_next (DSDKBatteryIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBattery::iterator* _iter = (CBattery::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
bati_isEnd (DSDKBatteryIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBattery::iterator* _iter = (CBattery::iterator*) (di->hdl);
		return (*_iter == CBattery::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
bati_release (DSDKBatteryIterator* di)
{
	dsdkc_setError (0, NULL);
	CBattery::iterator* _iter = (CBattery::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKBatteryIteratorFT _batift = 
{
	bati_getItem,
	bati_next,
	bati_isEnd,
	bati_release,
};


/*
 * Make a C based Battery iterator from the corresponding C++ object.
 */
static DSDKBatteryIterator* 
makeDSDKBatteryIterator (const CBattery::iterator& bati)
{

	DSDKBatteryIterator* dsdk_bati = new DSDKBatteryIterator;
	if (NULL == dsdk_bati) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_bati->ft  = &_batift;
		dsdk_bati->hdl = new CBattery::iterator (bati);
		return dsdk_bati;
	}
	CATCH_SET_ERROR ();

	delete dsdk_bati;
	return NULL;
}


/*
 * enumBattery
 */
extern "C" DSDKBatteryIterator*
enumBattery (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBattery::iterator iter = CBattery::enumBattery (
													(IClient*) client, 
													(cached ? true : false));

		return makeDSDKBatteryIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;
}


