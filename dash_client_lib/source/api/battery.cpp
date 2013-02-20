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
 * battery.cpp
 * A class representing a battery.
 */
#include <dsdk/oal/CIM_Battery.h>
#include <dsdk/battery.h>
#include <dsdk/cimcapabilities.h>
//#include <dsdk/oal/CIM_EnabledLogicalElementCapabilities.h>
//#include <dsdk/oal/CIM_ElementCapabilities.h>
#include "apiimp.h"

using namespace dsdk;

/*
 * Constructor
 */
CBattery::CBattery (const CIM_Battery& bat)
{ 
	_bat = new CIM_Battery (bat); 
}

/**
 * Constructor
 */
CBattery::CBattery (const CBattery& bat)
{
	this->_bat = new CIM_Battery (*(bat._bat));
}

/**
 * Destruction 
 */
CBattery::~CBattery ()
{
	if (this->_bat) { delete this->_bat; }
}

/**
 * Assignment operator
 */
const CBattery& 
CBattery::operator = (const CBattery& rhs)
{
	if (this->_bat) { delete this->_bat; }
	this->_bat  = new CIM_Battery (*rhs._bat);
	return *this;
}


/*
 * enumBattery
 */
CBattery::iterator 
CBattery::enumBattery (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_Battery::iterator iter = 
				CIM_Battery::enumInstances (client, 0, props);

	if (cached) { return createIterator (iter, props);  	  }
	else 		{ return createIterator (iter); }
}

/*
 * getSystemCreationClassName 
 */
string 
CBattery::getSystemCreationClassName (void) const 
{ 
	return this->_bat->getSystemCreationClassName ();
} 	

/*
 * getSystemName 
 */
string 
CBattery::getSystemName (void) const 
{ 
	return this->_bat->getSystemName ();
} 	

/*
 * getCreationClassName 
 */
string 
CBattery::getCreationClassName (void) const 
{ 
	return this->_bat->getCreationClassName ();
} 	

/*
 * getDeviceID
 */
string 
CBattery::getDeviceID (void) const 
{ 
	return this->_bat->getDeviceID ();
} 	


/**
 * getBatteryStatus
 */
uint16
CBattery::getBatteryStatus (void) const
{
	return ((CBattery*) this)->_bat->getBatteryStatus ();
}

/*
 * getBatteryStatusStr
 */
string 
CBattery::getBatteryStatusStr (void) const
{
	return _bat->getValueStr_BatteryStatus (((CBattery*) this)->_bat->getBatteryStatus ());
}

/*
 * getOperationalStatus
 */
vector<uint16>
CBattery::getOperationalStatus (void) const
{ 
	return ((CBattery*) this)->_bat->getOperationalStatus (); 
} 	

/*
 * getOperationalStatusStr
 */
vector<string>
CBattery::getOperationalStatusStr (void) const 
{
	vector<uint16> status = ((CBattery*) this)->_bat->getOperationalStatus ();
	vector <string> status_str;
	for(size_t value = 0; value < status.size(); value++ )
	{
		status_str.push_back(((CBattery*) this)->_bat->getValueStr_OperationalStatus (status [value]));
	}

	return status_str;
}

/*
 * getHealthState
 */
uint16 
CBattery::getHealthState (void) const
{ 
	return ((CBattery*) this)->_bat->getHealthState (); 
} 	

/*
 * getHealthStateStr
 */
string
CBattery::getHealthStateStr (void) const
{ 
	return CIM_Processor::getValueStr_HealthState (
			((CBattery*) this)->_bat->getHealthState ()); 
} 	

/*
 * getEnabledState
 */
uint16
CBattery::getEnabledState (void) const
{ 
	return ((CBattery*) this)->_bat->getEnabledState (); 
} 	

/*
 * getEnabledStateStr
 */
string
CBattery::getEnabledStateStr (void) const
{ 
	string str = CIM_Processor::getValueStr_EnabledState (
				((CBattery*) this)->_bat->getEnabledState ()); 
	return str;
} 

/*
 * getRequestedState
 */
uint16 
CBattery::getRequestedState (void) const
{ 
	return ((CBattery*) this)->_bat->getRequestedState (); 
} 	

/*
 * getRequestedStateStr
 */
string
CBattery::getRequestedStateStr (void) const
{ 
	return CIM_Processor::getValueStr_RequestedState (
			((CBattery*) this)->_bat->getRequestedState ()); 
} 	

/*
 * getElementName
 */
string
CBattery::getElementName (void) const
{ 
	return ((CBattery*) this)->_bat->getElementName (); 
} 	

/*
 * getChemistry
 */
uint16 
CBattery::getChemistry (void) const
{
	return ((CBattery*) this)->_bat->getChemistry ();
}

/*
 * getChemistryStr
 */
string 
CBattery::getChemistryStr (void) const
{
	return _bat->getValueStr_Chemistry (getChemistry ());
}

/*
 * getMaxRechargeCount
 */
uint32
CBattery::getMaxRechargeCount (void) const
{
	return ((CBattery*) this)->_bat->getMaxRechargeCount ();
}

/*
 * getRechargeCount
 */
uint32
CBattery::getRechargeCount (void) const
{
	return ((CBattery*) this)->_bat->getRechargeCount ();
}

/*
 * getExpectedLife
 */
uint32
CBattery::getExpectedLife (void) const
{
	return ((CBattery*) this)->_bat->getExpectedLife ();
}

/*
 * getEstimatedRunTime
 */
uint32
CBattery::getEstimatedRunTime (void) const
{
	return ((CBattery*) this)->_bat->getEstimatedRunTime ();
}

/*
 * getTimeToFullCharge
 */
uint32
CBattery::getTimeToFullCharge (void) const
{
	return ((CBattery*) this)->_bat->getTimeToFullCharge ();
}

/*
 * getMaxRechargeTime
 */
uint32
CBattery::getMaxRechargeTime (void) const
{
	return ((CBattery*) this)->_bat->getMaxRechargeTime ();
}

/*
* Enable/turn on Battery
*/
uint32
CBattery::enable (void) const
{
	uint32				ret;
	datetime 			immediate = CCIMDateTime (0, true);
	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

	vector<string> ignore;
	ignore.push_back ("TimeoutPeriod");
	// vector<uint16> states;
	
	ret = _bat->RequestStateChange(CIM_Battery::RequestStateChange_RequestedState_Enabled,
								  &job,
								  immediate);
	/* if enable is success return 0, else throw EFunctionReturnedWithFailure execption */
	if (ret == 4096)
	{
		int currJobState = job.getJobState();
		if (currJobState != 7){
		string retcodestr = _bat->getValueStr_RequestStateChange_ReturnCode(ret);
		throw EFunctionReturnedWithFailure ("CIM_Battery::Enable", retcodestr, ret);
		}
	}
	else if (ret != 0)
	{
		fprintf (stdout, "RequestPowerStateChange is supported.\n");
		string retcodestr = _bat->getValueStr_RequestStateChange_ReturnCode(ret);
		throw EFunctionReturnedWithFailure ("CIM_Battery::Enable", 
											retcodestr, ret);
	}
	return ret;
}
	


/*
* Disable/turn off Battery
*/
uint32
CBattery::disable (void) const
{
	uint32				ret;
	datetime 			immediate = CCIMDateTime (0, true);
	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

	vector<string> ignore;
	ignore.push_back ("TimeoutPeriod");

	ret = _bat->RequestStateChange(CIM_Battery::RequestStateChange_RequestedState_Disabled,
								  &job,
								  immediate);
	/* if disable is success return 0, else throw EFunctionReturnedWithFailure execption */
	if (ret == 4096)
	{
		int currJobState = job.getJobState();
		if (currJobState != 7){
		string retcodestr = _bat->getValueStr_RequestStateChange_ReturnCode(ret);
		throw EFunctionReturnedWithFailure ("CIM_Battery::Disable", retcodestr, ret);
		}
	}
	else if (ret != 0)
	{
		string retcodestr = _bat->getValueStr_RequestStateChange_ReturnCode(ret);
		throw EFunctionReturnedWithFailure ("CIM_Battery::Disable", 
											retcodestr, ret);
	}
	return ret;

}


/*
* Test/perform recalculation of charge thresholds.
*/
uint32
CBattery::test (void) const
{
	uint32				ret;
	datetime 			immediate = CCIMDateTime (0, true);
	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

	vector<string> ignore;
	ignore.push_back ("TimeoutPeriod");

	ret = _bat->RequestStateChange(CIM_Battery::RequestStateChange_RequestedState_Test,
								  &job,
								  immediate);
	/* if test is success return 0, else throw EFunctionReturnedWithFailure execption */
	if (ret == 4096)
	{
		int currJobState = job.getJobState();
		if (currJobState != 7){
		string retcodestr = _bat->getValueStr_RequestStateChange_ReturnCode(ret);
		throw EFunctionReturnedWithFailure ("CIM_Battery::test", retcodestr, ret);
		}
	}
	else if (ret != 0)
	{
		string retcodestr = _bat->getValueStr_RequestStateChange_ReturnCode(ret);
		throw EFunctionReturnedWithFailure ("CIM_Battery::test", 
											retcodestr, ret);
	}
	return ret;
	

}

/*
* Reset/recharge of battery.
*/
uint32
CBattery::reset (void) const
{
	uint32				ret;
	datetime 			immediate = CCIMDateTime (0, true);
	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

	vector<string> ignore;
	ignore.push_back ("TimeoutPeriod");

	ret = _bat->RequestStateChange(CIM_Battery::RequestStateChange_RequestedState_Reset,
								  &job,
								  immediate);
	/* if reset is success return 0, else throw EFunctionReturnedWithFailure execption */
	if (ret == 4096)
	{
		int currJobState = job.getJobState();
		if (currJobState != 7){
		string retcodestr = _bat->getValueStr_RequestStateChange_ReturnCode(ret);
		throw EFunctionReturnedWithFailure ("CIM_Battery::reset", retcodestr, ret);
		}
	}
	else if (ret != 0)
	{
		string retcodestr = _bat->getValueStr_RequestStateChange_ReturnCode(ret);
		throw EFunctionReturnedWithFailure ("CIM_Battery::reset", 
											retcodestr, ret);
	}
	return ret;
}

bool
CBattery::capableOfRequestStateChange(void) const
{
	/* Used Generic API */
	vector<uint16> states = CCIMCapabilities::getSupportedStates(this->_bat->getClient(), *(_bat));
	// Verifies whether the RequestedStatesSupported array contains at least one value
	if (states.size() == 0 )
		return false;

	return true;
}

vector<uint16>
CBattery::getSupportedStates(void) const
{
	/* Used Generic API */
	return 	CCIMCapabilities::getSupportedStates(this->_bat->getClient(), *(_bat));
}

vector<string>
CBattery::getSupportedStatesStr(void) const
{	
	/* Used Generic API */
	return CCIMCapabilities::getSupportedStatesStr(this->_bat->getClient(), *(_bat));
}



/* vector<uint16> 
CBattery::requestedStateSupport (void) const
{
	
vector<string>	empty_props;
	CIM_EnabledLogicalElementCapabilities::iterator eleciter =
			CIM_ElementCapabilities <CIM_Battery, CIM_EnabledLogicalElementCapabilities>::
			enumerateCapabilities (_bat->getClient (), *(this->getCIMObject ()), empty_props);

	if (eleciter == CIM_EnabledLogicalElementCapabilities::iterator::end ())
	{
		// error no association instance found
		throw EFunctionNotSupported ("User:RequestedState supported not available");
		//return -1;
	} 

	CIM_EnabledLogicalElementCapabilities bat_ems = *eleciter;
	return bat_ems.getRequestedStatesSupported();
}*/

/*
 * Battery status
 */
const uint16 CBattery::Other						= CIM_Battery::BatteryStatus_Other;
const uint16 CBattery::Unknown						= CIM_Battery::BatteryStatus_Unknown;
const uint16 CBattery::Fully_Charged				= CIM_Battery::BatteryStatus_Fully_Charged;
const uint16 CBattery::Low							= CIM_Battery::BatteryStatus_Low;
const uint16 CBattery::Critical						= CIM_Battery::BatteryStatus_Critical;
const uint16 CBattery::Charging						= CIM_Battery::BatteryStatus_Charging;
const uint16 CBattery::Charging_and_High			= CIM_Battery::BatteryStatus_Charging_and_High;
const uint16 CBattery::Charging_and_Low				= CIM_Battery::BatteryStatus_Charging_and_Low;
const uint16 CBattery::Charging_and_Critical		= CIM_Battery::BatteryStatus_Charging_and_Critical;
const uint16 CBattery::Undefined					= CIM_Battery::BatteryStatus_Undefined;
const uint16 CBattery::Partially_Charged			= CIM_Battery::BatteryStatus_Partially_Charged;
const uint16 CBattery::Learning						= CIM_Battery::BatteryStatus_Learning;
const uint16 CBattery::Overcharged					= CIM_Battery::BatteryStatus_Overcharged;

/* 
 *Battery chemistry
 */
const uint16 Other					= CIM_Battery::Chemistry_Other;
const uint16 Unknown				= CIM_Battery::Chemistry_Unknown;
const uint16 Lead_Acid				= CIM_Battery::Chemistry_Lead_Acid;
const uint16 Nickel_Cadmium			= CIM_Battery::Chemistry_Nickel_Cadmium;
const uint16 Nickel_Metal_Hydride	= CIM_Battery::Chemistry_Nickel_Metal_Hydride;
const uint16 Lithium_ion			= CIM_Battery::Chemistry_Lithium_ion;
const uint16 Zinc_air				= CIM_Battery::Chemistry_Zinc_air;
const uint16 Lithium_Polymer		= CIM_Battery::Chemistry_Lithium_Polymer;


/*
 * getCachedProps
 */
vector<string> 
CBattery::getCachedProps (void)
{
	vector<string> props;
	props.push_back ("SystemCreationClassName");
	props.push_back ("SystemName");
	props.push_back ("CreationClassName");
	props.push_back ("DeviceID");
	props.push_back ("BatteryStatus");
	props.push_back ("ElementName");
	props.push_back ("EnabledState");
	props.push_back ("RequestedState");
	props.push_back ("OperationalStatus");
	props.push_back ("HealthState");
	props.push_back ("Chemistry");
	props.push_back ("MaxRechargeCount");
	props.push_back ("RechargeCount");
	props.push_back ("ExpectedLife");
	props.push_back ("TimeToFullCharge");
	props.push_back ("MaxRechargeTime");
	props.push_back ("EstimatedRunTime");
	return props;
}


/**
 * CBattery::Iterator
 */
DEFINE_API_ITERATOR (CBattery);
 
/**
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CBattery, CIM_Battery);
