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
 * powersupply.cpp
 * Class representing power supply.
 */
#include <dsdk/oal/CIM_PowerSupply.h>
#include <dsdk/oal/CIM_RedundancySet.h>
#include <dsdk/powersupply.h>
#include "apiimp.h"

using namespace dsdk;
 
/*
 * Constructor
 */
CPowerSupply::CPowerSupply (const CIM_PowerSupply& ps)
{ 
	_ps = new CIM_PowerSupply (ps); 
}

/*
 * Constructor
 */
CPowerSupply::CPowerSupply (const CPowerSupply& ps)
{
	this->_ps = new CIM_PowerSupply (*(ps._ps));
}

/*
 * Destruction 
 */
CPowerSupply::~CPowerSupply ()
{
	if (this->_ps) { delete this->_ps; }
}

/*
 * Assignment operator
 */
const CPowerSupply& 
CPowerSupply::operator = (const CPowerSupply& rhs)
{
	if (this->_ps) { delete this->_ps; }
	this->_ps  = new CIM_PowerSupply (*rhs._ps);
	return *this;
}


/*
 * enumeratePowerSupplies
 */
CPowerSupply::iterator 
CPowerSupply::enumPowerSupplies (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_PowerSupply::iterator iter = CIM_PowerSupply::enumInstances (client, 
																	 0, 
																	 props);
	if (cached) { return createIterator (iter, props);  }
	else 		{ return createIterator (iter); 		}
}

/*
* getSystemCreationClassName
*/
string
CPowerSupply::getSystemCreationClassName (void) const
{
return _ps->getSystemCreationClassName ();
}

/*
* getSystemName
*/
string
CPowerSupply::getSystemName (void) const
{
return _ps->getSystemName ();
}

/*
* getCreationClassName
*/
string
CPowerSupply::getCreationClassName (void) const
{
return this->_ps->getCreationClassName ();
}


/*
 * getDeviceID 
 */
string 
CPowerSupply::getDeviceID (void) const
{
	return ((CPowerSupply*) this)->_ps->getDeviceID (); 
}

/*
 * getTotalPower
 */
uint32 
CPowerSupply::getTotalPower (void) const
{
	return ((CPowerSupply*) this)->_ps->getTotalOutputPower ();
}

/*
 * getElementName 
 */
string 
CPowerSupply::getElementName (void) const
{
	return ((CPowerSupply*) this)->_ps->getElementName (); 
}

/*
 * getOperationalStatus
 */
vector<uint16>
CPowerSupply::getOperationalStatus (void) const
{ 
	return ((CPowerSupply*) this)->_ps->getOperationalStatus (); 
} 	

/*
 * getOperationalStatusStr
 */
vector<string>
CPowerSupply::getOperationalStatusStr (void) const 
{
	vector<uint16> status = ((CPowerSupply*) this)->_ps->getOperationalStatus ();
	vector <string> status_str;
	for(size_t value = 0; value < status.size(); value++ )
	{
		status_str.push_back(((CPowerSupply*) this)->_ps->getValueStr_OperationalStatus (status [value]));
	}

	return status_str;
}

/*
 * getHealthState
 */
uint16
CPowerSupply::getHealthState (void) const
{ 
	return ((CPowerSupply*) this)->_ps->getHealthState (); 
} 	

/*
 * getHealthStateStr
 */
string
CPowerSupply::getHealthStateStr (void) const
{ 
	return CIM_Processor::getValueStr_HealthState (
			((CPowerSupply*) this)->_ps->getHealthState ()); 
} 	

/*
 * getEnabledState
 */
uint16 
CPowerSupply::getEnabledState (void) const
{ 
	return ((CPowerSupply*) this)->_ps->getEnabledState (); 
} 	

/*
 * getEnabledStateStr
 */
string
CPowerSupply::getEnabledStateStr (void) const
{ 
	return CIM_Processor::getValueStr_EnabledState (
				((CPowerSupply*) this)->_ps->getEnabledState ()); 
} 

/*
 * getRequestedState
 */
uint16
CPowerSupply::getRequestedState (void) const
{ 
	return ((CPowerSupply*) this)->_ps->getRequestedState (); 
} 	

/*
 * getRequestedStateStr
 */
string
CPowerSupply::getRequestedStateStr (void) const
{ 
	return CIM_Processor::getValueStr_RequestedState (
			((CPowerSupply*) this)->_ps->getRequestedState ()); 
} 	

/*
 * enablePowerSupply
 */
uint32
CPowerSupply::enablePowerSupply (void)
{
	datetime 		immediate = CCIMDateTime (0, true);
	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

	uint32 status = this->_ps->RequestStateChange (
		CIM_PowerSupply::RequestStateChange_RequestedState_Enabled, &job, immediate);

	/* if RequestStateChange is success(0) return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else 
	{
		string retcodestr = CIM_PowerSupply::getValueStr_RequestStateChange_ReturnCode (status);
			throw EFunctionReturnedWithFailure ("CIM_PowerSupply::RequestStateChange", 
													retcodestr, status);
	}
}

/*
 * disablePowerSupply
 */
uint32
CPowerSupply::disablePowerSupply (void)
{
	datetime 		immediate = CCIMDateTime (0, true);
	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

	uint32 status = this->_ps->RequestStateChange (
		CIM_PowerSupply::RequestStateChange_RequestedState_Disabled, &job, immediate);

	/* if RequestStateChange is success(0) return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else 
	{
		string retcodestr = CIM_PowerSupply::getValueStr_RequestStateChange_ReturnCode (status);
			throw EFunctionReturnedWithFailure ("CIM_PowerSupply::RequestStateChange", 
													retcodestr, status);
	}
}

/*
 * resetPowerSupply
 */
uint32
CPowerSupply::resetPowerSupply (void)
{
	datetime 		immediate = CCIMDateTime (0, true);
	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

	uint32 status = this->_ps->RequestStateChange (
			CIM_PowerSupply::RequestStateChange_RequestedState_Reset, &job, immediate);

	/* if RequestStateChange is success(0) return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else 
	{
		string retcodestr = CIM_PowerSupply::getValueStr_RequestStateChange_ReturnCode (status);
			throw EFunctionReturnedWithFailure ("CIM_PowerSupply::RequestStateChange", 
													retcodestr, status);
	}
}

/*
 * offlinePowerSupply
 */
uint32
CPowerSupply::offlinePowerSupply (void)
{
	datetime 		immediate = CCIMDateTime (0, true);
	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

	uint32 status = this->_ps->RequestStateChange (
			CIM_PowerSupply::RequestStateChange_RequestedState_Offline, &job, immediate);

	/* if RequestStateChange is success(0) return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else 
	{
		string retcodestr = CIM_PowerSupply::getValueStr_RequestStateChange_ReturnCode (status);
			throw EFunctionReturnedWithFailure ("CIM_PowerSupply::RequestStateChange", 
													retcodestr, status);
	}
}

/*
 * Active Input Voltage
 */
const uint16 CPowerSupply::other		  = CIM_PowerSupply::ActiveInputVoltage_Other;
const uint16 CPowerSupply::unknown     = CIM_PowerSupply::ActiveInputVoltage_Unknown;
const uint16 CPowerSupply::range1      = CIM_PowerSupply::ActiveInputVoltage_Range_1;
const uint16 CPowerSupply::range2      = CIM_PowerSupply::ActiveInputVoltage_Range_2;
const uint16 CPowerSupply::both        = CIM_PowerSupply::ActiveInputVoltage_Both;
const uint16 CPowerSupply::neither     = CIM_PowerSupply::ActiveInputVoltage_Neither;

/*
 * Types of switching
 */	
const uint16 CPowerSupply::type_other		= CIM_PowerSupply::TypeOfRangeSwitching_Other;
const uint16 CPowerSupply::type_unknown		= CIM_PowerSupply::TypeOfRangeSwitching_Unknown;
const uint16 CPowerSupply::manual			= CIM_PowerSupply::TypeOfRangeSwitching_Manual;
const uint16 CPowerSupply::auto_switch		= CIM_PowerSupply::TypeOfRangeSwitching_Autoswitch;
const uint16 CPowerSupply::wide_range		= CIM_PowerSupply::TypeOfRangeSwitching_Wide_Range;
const uint16 CPowerSupply::na				= CIM_PowerSupply::TypeOfRangeSwitching_Not_Applicable;

/*
 * getCachedProps
 */
vector<string> 
CPowerSupply::getCachedProps (void)
{
	vector<string> props;

	props.push_back ("SystemCreationClassName");
	props.push_back ("SystemName");
	props.push_back ("CreationClassName");
	props.push_back ("DeviceID");
	props.push_back ("ElementName");
	props.push_back ("EnabledState");
	props.push_back ("RequestedState");
	props.push_back ("OperationalStatus");
	props.push_back ("HealthState");
	props.push_back ("TotalOutputPower");
	return props;
}

/*
 * CPowerSupply::Iterator
 */
DEFINE_API_ITERATOR (CPowerSupply);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CPowerSupply, CIM_PowerSupply);


/*
 * Create API Redundancy Set Iterator Definetion 
 */
static CPowerSupplyRedundancySet::iterator 
createPowerSupplyRedundancySetIterator (CIM_RedundancySet::iterator iter)
{
	_CPowerSupplyRedundancySetIterator* rsi = new _CPowerSupplyRedundancySetIterator (iter);
	return CPowerSupplyRedundancySet::iterator (rsi);
}

static CPowerSupplyRedundancySet::iterator 
createPowerSupplyRedundancySetIterator (CIM_RedundancySet::iterator iter, vector<string> cached_props)
{
	_CPowerSupplyRedundancySetIterator* rsi = new _CPowerSupplyRedundancySetIterator (iter, cached_props);
	return CPowerSupplyRedundancySet::iterator (rsi);
}


/*
 * Constructor
 */
CPowerSupplyRedundancySet::CPowerSupplyRedundancySet (const CIM_RedundancySet& rs)
{ 
	_rs = new CIM_RedundancySet (rs); 
}

/*
 * Constructor
 */
CPowerSupplyRedundancySet::CPowerSupplyRedundancySet (const CPowerSupplyRedundancySet& rs)
{
	this->_rs = new CIM_RedundancySet (*(rs._rs));
}

/*
 * Destruction 
 */
CPowerSupplyRedundancySet::~CPowerSupplyRedundancySet ()
{
	if (this->_rs) { delete this->_rs; }
}

/*
 * Assignment operator
 */
const CPowerSupplyRedundancySet& 
CPowerSupplyRedundancySet::operator = (const CPowerSupplyRedundancySet& rhs)
{
	if (this->_rs) { delete this->_rs; }
	this->_rs  = new CIM_RedundancySet (*rhs._rs);
	return *this;
}

/*
 * enumeratePowerSupplyRedundancySets
 */
CPowerSupplyRedundancySet::iterator 
CPowerSupplyRedundancySet::enumPowerSupplyRedundancySets (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_RedundancySet::iterator iter = 
		CIM_RedundancySet::enumInstances (client, 0, props);

	if (cached) { return createPowerSupplyRedundancySetIterator (iter, props);  }
	else 		{ return createPowerSupplyRedundancySetIterator (iter); 		 }
}

/*
 * getInstanceID
 */
string 
CPowerSupplyRedundancySet::getInstanceID (void)
{
	return _rs->getInstanceID ();
}

/*
 * getRedundancyStatus
 */
uint16
CPowerSupplyRedundancySet::getRedundancyStatus (void) const
{
	return ((CPowerSupplyRedundancySet*) this)->_rs->getRedundancyStatus ();
}

/*
 * getType
 */
vector<CPowerSupplyRedundancySet::Type_E> 
CPowerSupplyRedundancySet::getType (void) const
{
	vector<uint16> rs_type = 
			((CPowerSupplyRedundancySet*) this)->_rs->getTypeOfSet ();

	vector<Type_E> ret;
	for (size_t i = 0; i < rs_type.size (); i++)
	{
		if (rs_type [i] == CIM_RedundancySet::TypeOfSet_Unknown)
		{
			ret.push_back (type_unknown);
		}
		else if (rs_type [i] == CIM_RedundancySet::TypeOfSet_Other)
		{
			ret.push_back (other);
		}
		else if (rs_type [i] == CIM_RedundancySet::TypeOfSet_N_1)
		{
			ret.push_back (nplus1);
		}
		else if (rs_type [i] == CIM_RedundancySet::TypeOfSet_Load_Balanced)
		{
			ret.push_back (load_balanced);
		}
		else if (rs_type [i] == CIM_RedundancySet::TypeOfSet_Sparing)
		{
			ret.push_back (sparing);
		}
		else if (rs_type [i] == CIM_RedundancySet::TypeOfSet_Limited_Sparing)
		{
			ret.push_back (limited_sparing);
		}
		else if ((rs_type [i] > CIM_RedundancySet::TypeOfSet_DMTF_Reserved_low) && 
				 (rs_type [i] < CIM_RedundancySet::TypeOfSet_DMTF_Reserved_high))
		{
			ret.push_back (dmtf_reserved);
		}
		else if ((rs_type [i] > CIM_RedundancySet::TypeOfSet_Vendor_Reserved_low) && 
				 (rs_type [i] < CIM_RedundancySet::TypeOfSet_Vendor_Reserved_high))
		{
			ret.push_back (vendor_reserved);
		}
	}

	return ret;
}

/*
 * getMinimumNumberNeeded
 */
uint32 
CPowerSupplyRedundancySet::getMinimumNumberNeeded (void) const
{
	return ((CPowerSupplyRedundancySet*) this)->_rs->getMinNumberNeeded ();
}

/*
 * getElementName 
 */
string 
CPowerSupplyRedundancySet::getElementName (void) const
{
	return ((CPowerSupplyRedundancySet*) this)->_rs->getElementName (); 
}

/*
 * failover
 */
uint32 
CPowerSupplyRedundancySet::failover (CPowerSupply& fan_from, CPowerSupply& fan_to)
{ 
	uint32 status = ((CPowerSupplyRedundancySet*) this)->_rs->Failover (*(fan_from.getCIMObject ()), 
																*(fan_to.getCIMObject ())); 

	/* if failover is changed successfully, return success.
		else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else 
	{
		string  retcodestr = _rs->getValueStr_Failover_ReturnCode (status);
		throw EFunctionReturnedWithFailure ("CIM_Redundancy::failover", 
											retcodestr, status);
	}

} 	


/*
 * Redundancy status
 */
const uint16 CPowerSupplyRedundancySet::status_unknown		= CIM_RedundancySet::RedundancyStatus_Unknown;
const uint16 CPowerSupplyRedundancySet::reserved			= CIM_RedundancySet::RedundancyStatus_DMTF_Reserved;
const uint16 CPowerSupplyRedundancySet::fully_redundant		= CIM_RedundancySet::RedundancyStatus_Fully_Redundant;
const uint16 CPowerSupplyRedundancySet::degraded_redundancy	= CIM_RedundancySet::RedundancyStatus_Degraded_Redundancy;
const uint16 CPowerSupplyRedundancySet::redundancy_lost		= CIM_RedundancySet::RedundancyStatus_Redundancy_Lost;
const uint16 CPowerSupplyRedundancySet::overall_failure		= CIM_RedundancySet::RedundancyStatus_Overall_Failure;


/*
 * getCachedProps
 */
vector<string> 
CPowerSupplyRedundancySet::getCachedProps (void)
{
	vector<string> props;
	props.push_back ("RedundancyStatus");
	props.push_back ("TypeOfSet");
	props.push_back ("MinNumberNeeded");
	props.push_back ("ElementName");
	return props;
}


/*
 * CPowerSupplyRedundancySet::Iterator
 */
DEFINE_API_ITERATOR (CPowerSupplyRedundancySet);
 
