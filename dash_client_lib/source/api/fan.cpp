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
 * fan.cpp
 * Classes to support fan.
 **/
#include <dsdk/oal/CIM_Fan.h>
#include <dsdk/oal/CIM_RedundancySet.h>
#include <dsdk/fan.h>
#include "apiimp.h"
#include <sstream>
#include <dsdk/cimcapabilities.h>


using namespace dsdk;
 
/*
 * Constructor
 */
CFan::CFan (const CIM_Fan& fan)
{ 
	_fan = new CIM_Fan (fan); 
}

/*
 * Constructor
 */
CFan::CFan (const CFan& fan)
{
	this->_fan = new CIM_Fan (*(fan._fan));
}

/*
 * Destruction 
 */
CFan::~CFan ()
{
	if (this->_fan) { delete this->_fan; }
}

/*
 * Assignment operator
 */
const CFan& 
CFan::operator = (const CFan& rhs)
{
	if (this->_fan) { delete this->_fan; }
	this->_fan  = new CIM_Fan (*rhs._fan);
	return *this;
}


/*
 * enumerateFans
 */
CFan::iterator 
CFan::enumFans (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_Fan::iterator iter = CIM_Fan::enumInstances (client, 0, props);

	if (cached) { return createIterator (iter, props);  }
	else 		{ return createIterator (iter); 		}
}

/*
 * getSystemCreationClassName 
 */
string 
CFan::getSystemCreationClassName (void) const
{
	return _fan->getSystemCreationClassName ();
}

/*
 * getSystemName 
 */
string 
CFan::getSystemName (void) const
{
	return _fan->getSystemName ();
}

/*
 * getCreationClassName 
 */
string 
CFan::getCreationClassName (void) const 
{ 
	return this->_fan->getCreationClassName ();
} 	

/*
 * getDeviceID 
 */
string 
CFan::getDeviceID (void) const
{
	return ((CFan*) this)->_fan->getDeviceID (); 
}

/*
 * getOperationalStatus
 */
vector<uint16>
CFan::getOperationalStatus (void) const
{ 
	return ((CFan*) this)->_fan->getOperationalStatus (); 
} 	

/*
 * getOperationalStatusStr
 */
vector<string>
CFan::getOperationalStatusStr (void) const 
{
	vector<uint16> status = ((CFan*) this)->_fan->getOperationalStatus ();
	vector <string> status_str;
	for(size_t value = 0; value < status.size(); value++ )
	{
		status_str.push_back(((CFan*) this)->_fan->getValueStr_OperationalStatus (status [value]));
	}

	return status_str;
}

/*
 * getHealthState
 */
uint16
CFan::getHealthState (void) const
{ 
	return ((CFan*) this)->_fan->getHealthState (); 
} 	

/*
 * getHealthStateStr
 */
string
CFan::getHealthStateStr (void) const
{ 
	return CIM_Processor::getValueStr_HealthState (
			((CFan*) this)->_fan->getHealthState ()); 
} 	

/*
 * isVariableSpeed
 */
bool 
CFan::isVariableSpeed (void) const
{
	return (((CFan*) this)->_fan->getVariableSpeed () != 0);
}

/*
 * getSpeed
 */
string
CFan::getSpeed(void) const
{
	vector<string> empty_props;
	/* enumerate the sensor associated with this fan */
	CIM_Sensor::iterator iter = CIM_AssociatedSensor <CIM_Sensor,
									CIM_Fan>::enumerateAntecedent (_fan->getClient(),
																*(this->getCIMObject ()),
																 empty_props);
	if (iter == CIM_Sensor::iterator::end ())
	{
		throw EFunctionNotSupported ("getFanSpeed");
	}

	/* Check the sensor type  */
	for (; iter != CIM_Sensor::iterator::end (); ++iter)
	{
		CSensor    sensor =  *iter;

		if (CIM_Sensor::SensorType_Tachometer == sensor.getSensorType())
		{
			CNumericSensor ns = CNumericSensor::toNumericSensor (sensor);

			/* assume the sensor as numeric sensor and try to get the reading if not it will 
			  throw execption, then its a discrete sensor get its current state. */
			try
			{
				 std::stringstream sstr;
				 sstr << ns.getCurrentReading ();
				 return sstr.str();
			}
			catch (...)
			{
				return ns.getCurrentState ();
			}
		}
	}

	return "N/A";
}

/*
 * getDesiredSpeed
 */
uint64 
CFan::getDesiredSpeed (void) const
{
	return ((CFan*) this)->_fan->getDesiredSpeed ();
}

/*
 * setDesiredSpeed
 */
uint32 
CFan::setDesiredSpeed (uint64 speed) const
{
		/* uint32 enabled_state =this->getEnabledState();
		signed int status_setspeed = -1; 
		if (2 == enabled_state || 1 == variable_speed)
		{ */
			
		// Verify whether the Fan Speed is settable or ont
		if(capableOfSetFanSpeed() == false) {
			throw EFunctionNotSupported ("SetSpeed");
		}
			uint32 status = ((CFan*) this)->_fan->SetSpeed (speed);
			/* if set attribute is success return 0, else throw EFunctionReturnedWithFailure execption */
			if (0 == status)
			{
				return status;
			}
			else 
			{
				string retcodestr = _fan->getValueStr_SetSpeed_ReturnCode(status);
				throw EFunctionReturnedWithFailure ("CIM_Fan::SetSpeed", retcodestr, status);
			}
			
	/*	}
		else
		{
			fprintf (stderr, "Error: set Speed Method is not Supported\n");
			return status_setspeed;
		} */
}

/*
 * isActiveCooling
 */
bool 
CFan::isActiveCooling (void) const
{
	return (((CFan*) this)->_fan->getActiveCooling () != 0);
}

/*
 * getEnabledState
 */
uint16 
CFan::getEnabledState (void) const
{ 
	return ((CFan*) this)->_fan->getEnabledState (); 
} 	

/*
 * getEnabledStateStr
 */
string
CFan::getEnabledStateStr (void) const
{ 
	return CIM_Processor::getValueStr_EnabledState (
				((CFan*) this)->_fan->getEnabledState ()); 
} 

/*
 * getRequestedState
 */
uint16
CFan::getRequestedState (void) const
{ 
	return ((CFan*) this)->_fan->getRequestedState (); 
} 	

/*
 * getRequestedStateStr
 */
string
CFan::getRequestedStateStr (void) const
{ 
	return CIM_Processor::getValueStr_RequestedState (
			((CFan*) this)->_fan->getRequestedState ()); 
} 	

/*
 * getElementName 
 */
string 
CFan::getElementName (void) const
{
	return ((CFan*) this)->_fan->getElementName (); 
}

/*
 * getSetSpeedErrStr
 */
string 
CFan::getSetSpeedErrStr (uint32 err) const
{
	return CIM_Fan::getValueStr_SetSpeed_ReturnCode (err);
}

bool
CFan::capableOfRequestStateChange() const
{
	vector<uint16> states = CCIMCapabilities::getSupportedStates(this->_fan->getClient(), *(_fan));
	// Verifies whether the RequestedStatesSupported array contains at least one value
	if (states.size() == 0 )
		return false;

	return true;
}
vector<uint16>
CFan::getSupportedStates(void) const
{
	/* Used Generic API */
	return 	CCIMCapabilities::getSupportedStates(this->_fan->getClient(), *(_fan));
}

vector<string>
CFan::getSupportedStatesStr(void) const
{	
	/* Used Generic API */
	return CCIMCapabilities::getSupportedStatesStr(this->_fan->getClient(), *(_fan));
}


/*
 * capableOfSetFanSpeed: This capability API verifies whether SetSpeed() extrinsic method is implemented at the target.
   Returns True or False.
 */
bool
CFan::capableOfSetFanSpeed() const
{
	if (CIM_EnabledLogicalElementCapabilities::RequestedStatesSupported_Disabled == this->getEnabledState() || 
		this->isVariableSpeed() == false)
	{ 
		return false;
	}
	return true;
}

/*
 * getCachedProps
 */
vector<string> 
CFan::getCachedProps (void) 
{
	vector<string> props;
	props.push_back ("SystemCreationClassName");
	props.push_back ("SystemName");
	props.push_back ("CreationClassName");
	props.push_back ("DeviceID");
	props.push_back ("HealthState");
	props.push_back ("OperationalStatus");
	props.push_back ("VariableSpeed");
	props.push_back ("DesiredSpeed");
	props.push_back ("ActiveCooling");
	props.push_back ("ElementName");
	props.push_back ("EnabledState");
	props.push_back ("RequestedState");
	return props;
}

/*
 * Fan::Iterator
 */
DEFINE_API_ITERATOR (CFan);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CFan, CIM_Fan);


/*
 * Create API Redundancy Set Iterator Definetion 
 */
static CFanRedundancySet::iterator 
createFanRedundancySetIterator (CIM_RedundancySet::iterator iter)
{
	_CFanRedundancySetIterator* rsi = new _CFanRedundancySetIterator (iter);
	return CFanRedundancySet::iterator (rsi);
}

static CFanRedundancySet::iterator 
createFanRedundancySetIterator (CIM_RedundancySet::iterator iter, vector<string> cached_props)
{
	_CFanRedundancySetIterator* rsi = new _CFanRedundancySetIterator (iter, cached_props);
	return CFanRedundancySet::iterator (rsi);
}


/*
 * Constructor
 */
CFanRedundancySet::CFanRedundancySet (const CIM_RedundancySet& rs)
{ 
	_rs = new CIM_RedundancySet (rs); 
}

/*
 * Constructor
 */
CFanRedundancySet::CFanRedundancySet (const CFanRedundancySet& rs)
{
	this->_rs = new CIM_RedundancySet (*(rs._rs));
}

/*
 * Destruction 
 */
CFanRedundancySet::~CFanRedundancySet ()
{
	if (this->_rs) { delete this->_rs; }
}

/*
 * Assignment operator
 */
const CFanRedundancySet& 
CFanRedundancySet::operator = (const CFanRedundancySet& rhs)
{
	if (this->_rs) { delete this->_rs; }
	this->_rs  = new CIM_RedundancySet (*rhs._rs);
	return *this;
}


/*
 * enumerateFanRedundancySets
 */
CFanRedundancySet::iterator 
CFanRedundancySet::enumFanRedundancySets (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_RedundancySet::iterator iter = 
		CIM_RedundancySet::enumInstances (client, 0, props);

	if (cached) { return createFanRedundancySetIterator (iter, props);  }
	else 		{ return createFanRedundancySetIterator (iter); 		 }
}

/*
 * getInstanceID
 */
string 
CFanRedundancySet::getInstanceID (void)
{
	return _rs->getInstanceID ();
}

/*
 * getRedundancyStatus
 */
int
CFanRedundancySet::getRedundancyStatus (void) const
{
	return ((CFanRedundancySet*) this)->_rs->getRedundancyStatus ();
}

/*
 * getType
 */
vector<CFanRedundancySet::Type_E> 
CFanRedundancySet::getType (void) const
{
	vector<uint16> rs_type = 
			((CFanRedundancySet*) this)->_rs->getTypeOfSet ();

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
CFanRedundancySet::getMinimumNumberNeeded (void) const
{
	return ((CFanRedundancySet*) this)->_rs->getMinNumberNeeded ();
}

/*
 * getElementName 
 */
string 
CFanRedundancySet::getElementName (void) const
{
	return ((CFanRedundancySet*) this)->_rs->getElementName (); 
}

/*
 * failover
 */
uint32 
CFanRedundancySet::failover (CFan& fan_from, CFan& fan_to)
{ 
	uint32 status = ((CFanRedundancySet*) this)->_rs->Failover (*(fan_from.getCIMObject ()), 
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
const uint16 CFanRedundancySet::status_unknown			= CIM_RedundancySet::RedundancyStatus_Unknown;
const uint16 CFanRedundancySet::reserved				= CIM_RedundancySet::RedundancyStatus_DMTF_Reserved;
const uint16 CFanRedundancySet::fully_redundant		= CIM_RedundancySet::RedundancyStatus_Fully_Redundant;
const uint16 CFanRedundancySet::degraded_redundancy	= CIM_RedundancySet::RedundancyStatus_Degraded_Redundancy;
const uint16 CFanRedundancySet::redundancy_lost		= CIM_RedundancySet::RedundancyStatus_Redundancy_Lost;
const uint16 CFanRedundancySet::overall_failure		= CIM_RedundancySet::RedundancyStatus_Overall_Failure;


/*
 * getCachedProps
 */
vector<string> 
CFanRedundancySet::getCachedProps (void) 
{
	vector<string> props;
	props.push_back ("RedundancyStatus");
	props.push_back ("TypeOfSet");
	props.push_back ("MinNumberNeeded");
	props.push_back ("ElementName");
	return props;
}


/*
 * Fan::Iterator
 */
DEFINE_API_ITERATOR (CFanRedundancySet);
 
