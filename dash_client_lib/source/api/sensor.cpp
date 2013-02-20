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
 * sensor.cpp
 * A class representing a sensor
 */
#include <dsdk/oal/CIM_Sensor.h>
#include <dsdk/oal/CIM_NumericSensor.h>
#include <dsdk/sensor.h>
#include <math.h>
#include <dsdk/dsdkexception.h>
#include "apiimp.h"

using namespace dsdk;

/*
 * Constructor
 */
CSensor::CSensor (const CIM_Sensor& sensor)
{ 
	_sensor = new CIM_Sensor (sensor); 
}

/*
 * Constructor
 */
CSensor::CSensor (const CSensor& sensor)
{
	this->_sensor = new CIM_Sensor (*(sensor._sensor));
}

/*
 * Destruction 
 */
CSensor::~CSensor ()
{
	if (this->_sensor) { delete this->_sensor; }
}

/*
 * Assignment operator
 */
const CSensor& 
CSensor::operator = (const CSensor& rhs)
{
	if (this->_sensor) { delete this->_sensor; }
	this->_sensor  = new CIM_Sensor (*rhs._sensor);
	return *this;
}

/*
 * enumSensors
 */
CSensor::iterator 
CSensor::enumSensors (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_Sensor::iterator iter = 
		CIM_Sensor::enumInstances (client, 0, props);

	if (cached) { return createIterator (iter, props); }
	else 		{ return createIterator (iter); 		  }
}

/*
 * getSystemCreationClassName 
 */
string 
CSensor::getSystemCreationClassName (void) const
{
	return _sensor->getSystemCreationClassName ();
}

/*
 * getSystemName 
 */
string 
CSensor::getSystemName (void) const
{
	return _sensor->getSystemName ();
}

/*
 * getCreationClassName 
 */
string 
CSensor::getCreationClassName (void) const 
{ 
	return this->_sensor->getCreationClassName ();
} 	

/*
 * getDeviceID
 */
string 
CSensor::getDeviceID (void) const
{
	return ((CSensor*) this)->_sensor->getDeviceID ();
}

/*
 * getSensorType
 */
uint16 
CSensor::getSensorType (void) const
{
	uint16 type = ((CSensor*) this)->_sensor->getSensorType ();
	if ((type > CIM_Sensor::SensorType_DMTF_Reserved_low) && 
		(type < CIM_Sensor::SensorType_DMTF_Reserved_high))
	{
		return dmtf_reserved;
	}
	else if ((type > CIM_Sensor::SensorType_Vendor_Reserved_low) && 
			 (type < CIM_Sensor::SensorType_Vendor_Reserved_high))
	{
		return vendor_reserved;
	}
	else
	{
		return type;
	}
}

/*
 * getSensorTypeStr
 */
string
CSensor::getSensorTypeStr (void) const
{
	return CIM_Sensor::getValueStr_SensorType (_sensor->getSensorType ());
}

/*
 * getPossibleStates
 */
vector<string> 
CSensor::getPossibleStates (void) const
{
	return ((CSensor*) this)->_sensor->getPossibleStates ();
}

/*
 * getCurrentState
 */
string 
CSensor::getCurrentState (void) const
{
	return ((CSensor*) this)->_sensor->getCurrentState ();
}

/*
 * getElementName
 */
string
CSensor::getElementName (void) const
{ 
	return ((CSensor*) this)->_sensor->getElementName (); 
} 	

/*
 * getOtherFamilyDescription
 */
string 
CSensor::getOtherSensorTypeDescription (void) const
{ 
	return ((CSensor*) this)->_sensor->getOtherSensorTypeDescription (); 
} 	

/*
 * getEnabledState
 */
uint16 
CSensor::getEnabledState (void) const
{ 
	return ((CSensor*) this)->_sensor->getEnabledState (); 
} 	

/*
 * getEnabledStateStr
 */
string
CSensor::getEnabledStateStr (void) const
{ 
	return CIM_Processor::getValueStr_EnabledState (
				((CSensor*) this)->_sensor->getEnabledState ()); 
} 

/*
 * getRequestedState
 */
uint16
CSensor::getRequestedState (void) const
{ 
	return ((CSensor*) this)->_sensor->getRequestedState (); 
} 	

/*
 * getRequestedStateStr
 */
string
CSensor::getRequestedStateStr (void) const
{ 
	return CIM_Processor::getValueStr_RequestedState (
			((CSensor*) this)->_sensor->getRequestedState ()); 
} 	

/*
 * getOperationalStatus
 */
vector<uint16>
CSensor::getOperationalStatus (void) const
{ 
	return ((CSensor*) this)->_sensor->getOperationalStatus (); 
} 	

/*
 * getOperationalStatusStr
 */
vector<string>
CSensor::getOperationalStatusStr (void) const 
{
	vector<uint16> status = ((CSensor*) this)->_sensor->getOperationalStatus ();
	vector <string> status_str;
	for(size_t value = 0; value < status.size(); value++ )
	{
		status_str.push_back(((CSensor*) this)->_sensor->getValueStr_OperationalStatus (status [value]));
	}

	return status_str;
}

/*
 * getHealthState
 */
uint16
CSensor::getHealthState (void) const
{ 
	return ((CSensor*) this)->_sensor->getHealthState (); 
} 	

/*
 * getHealthStateStr
 */
string
CSensor::getHealthStateStr (void) const
{ 
	return CIM_Processor::getValueStr_HealthState (
			((CSensor*) this)->_sensor->getHealthState ()); 
} 	

/*
 * Sensor type
 */
const uint16 	CSensor::unknown		= CIM_Sensor::SensorType_Unknown;
const uint16 	CSensor::other			= CIM_Sensor::SensorType_Other;
const uint16 	CSensor::temperature	= CIM_Sensor::SensorType_Temperature;
const uint16 	CSensor::voltage		= CIM_Sensor::SensorType_Voltage;
const uint16 	CSensor::current		= CIM_Sensor::SensorType_Current;
const uint16 	CSensor::tachometer		= CIM_Sensor::SensorType_Tachometer;
const uint16 	CSensor::counter		= CIM_Sensor::SensorType_Counter;
const uint16 	CSensor::Switch			= CIM_Sensor::SensorType_Switch;
const uint16 	CSensor::lock			= CIM_Sensor::SensorType_Lock;
const uint16 	CSensor::humidity		= CIM_Sensor::SensorType_Humidity;
const uint16 	CSensor::smoke_detection= CIM_Sensor::SensorType_Smoke_Detection;
const uint16 	CSensor::presence		= CIM_Sensor::SensorType_Presence;
const uint16 	CSensor::air_flow		= CIM_Sensor::SensorType_Air_Flow;
const uint16 	CSensor::power_consumption = CIM_Sensor::SensorType_Power_Consumption;
const uint16 	CSensor::power_production  = CIM_Sensor::SensorType_Power_Production;
const uint16 	CSensor::dmtf_reserved	   = CIM_Sensor::SensorType_DMTF_Reserved_low;
const uint16 	CSensor::vendor_reserved   = CIM_Sensor::SensorType_Vendor_Reserved_low;

/*
 * getCachedProps
 */
vector<string> 
CSensor::getCachedProps (void)
{
	vector<string> props;
	props.push_back ("SystemCreationClassName");
	props.push_back ("SystemName");
	props.push_back ("CreationClassName");
	props.push_back ("DeviceID");
	props.push_back ("SensorType");
	props.push_back ("PossibleStates");
	props.push_back ("CurrentState");
	props.push_back ("ElementName");
	props.push_back ("OtherSensorTypeDescription");
	props.push_back ("EnabledState");
	props.push_back ("RequestedState");
	props.push_back ("OperationalStatus");
	props.push_back ("HealthState");

	return props;
}

/*
 * CSensor::Iterator
 */
DEFINE_API_ITERATOR (CSensor);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CSensor, CIM_Sensor);


/*
 * Constructor
 */
CNumericSensor::CNumericSensor (const CIM_NumericSensor& ns) : CSensor (ns)
{ 
	_ns = new CIM_NumericSensor (ns); 
}

/*
 * Constructor
 */
CNumericSensor::CNumericSensor (const CNumericSensor& ns) : CSensor (ns)
{
	this->_ns = new CIM_NumericSensor (*(ns._ns));
}

/*
 * Destruction 
 */
CNumericSensor::~CNumericSensor ()
{
	if (this->_ns) { delete this->_ns; }
}

/*
 * Assignment operator
 */
const CNumericSensor& 
CNumericSensor::operator = (const CNumericSensor& rhs)
{
	if (this->_ns) { delete this->_ns; }
	this->_ns  = new CIM_NumericSensor (*rhs._ns);
	return *this;
}

/*
 * toNumericSensor
 */
CNumericSensor
CNumericSensor::toNumericSensor (CSensor& sensor)
{
	/* construct a CIM_NumericSensor from CIM_Sensor */
	CCIMInstance		inst (sensor.getCIMObject ()->getObjectPath ());
	CIM_NumericSensor	ns   (inst);              

	ns.initialize (sensor.getCIMObject ()->getClient());
	return ns;
}

/*
 * enumNumericSensors
 */
CNumericSensor::iterator 
CNumericSensor::enumNumericSensors (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_NumericSensor::iterator iter = 
					CIM_NumericSensor::enumInstances (client, 0, props);

	if (cached) { return createIterator (iter, props); }
	else 		{ return createIterator (iter); 		 }
}

/*
 * getSystemCreationClassName 
 */
string 
CNumericSensor::getSystemCreationClassName (void) const
{
	return _ns->getSystemCreationClassName ();
}

/*
 * getSystemName 
 */
string 
CNumericSensor::getSystemName (void) const
{
	return _ns->getSystemName ();
}

/*
 * getCreationClassName 
 */
string 
CNumericSensor::getCreationClassName (void) const 
{ 
	return this->_ns->getCreationClassName ();
} 	

/*
 * getDeviceID
 */
string 
CNumericSensor::getDeviceID (void) const
{
	return ((CNumericSensor*) this)->_ns->getDeviceID ();
}

/*
 * getBaseUnit
 */
uint16
CNumericSensor::getBaseUnit (void) const
{
	return ((CNumericSensor*) this)->_ns->getBaseUnits ();
}

/*
 * getBaseUnitStr
 */
string
CNumericSensor::getBaseUnitStr (void) const
{
	return CIM_NumericSensor::getValueStr_BaseUnits (
		((CNumericSensor*) this)->_ns->getBaseUnits ());
}

/*
 * getUnitModifier
 */
sint32
CNumericSensor::getUnitModifier (void) const
{
	return ((CNumericSensor*) this)->_ns->getUnitModifier ();
}

/*
 * getRateUnit
 */
uint16
CNumericSensor::getRateUnit (void) const
{
	return ((CNumericSensor*) this)->_ns->getRateUnits ();
}

/*
 * getRateUnitStr
 */
string
CNumericSensor::getRateUnitStr (void) const
{
	return CIM_NumericSensor::getValueStr_RateUnits (
		((CNumericSensor*) this)->_ns->getRateUnits ());
}

/*
 * getCurrentReading
 */
sint32 
CNumericSensor::getCurrentReading (void) const
{
//	return ((CNumericSensor*) this)->_ns->getCurrentReading ();

	//Note: At this point we are not sure, whether the following calculations should be done at the API leyer or
	// Apps layer. As per the specs, it should be at the Apps layer.

	double val = ((CNumericSensor*) this)->_ns->getCurrentReading () * 
		pow((double)10, (double)((CNumericSensor*) this)->_ns->getUnitModifier() );

	return (sint32)val;

}

/*
 * getLowerThresholdNonCritical
 */
int 
CNumericSensor::getLowerThresholdNonCritical (void) const
{
	return ((CNumericSensor*) this)->_ns->getLowerThresholdNonCritical ();
}


/*
 * setLowerThresholdNonCritical
 */
void 
CNumericSensor::setLowerThresholdNonCritical (int val) const
{
	((CNumericSensor*) this)->_ns->setLowerThresholdNonCritical (val);
}

/*
 * getUpperThresholdNonCritical
 */
int 
CNumericSensor::getUpperThresholdNonCritical (void) const
{
	return ((CNumericSensor*) this)->_ns->getUpperThresholdNonCritical ();
}


/*
 * setUpperThresholdNonCritical
 */
void 
CNumericSensor::setUpperThresholdNonCritical (int val) const
{
	((CNumericSensor*) this)->_ns->setUpperThresholdNonCritical (val);
}

/*
 * getLowerThresholdCritical
 */
int 
CNumericSensor::getLowerThresholdCritical (void) const
{
	return ((CNumericSensor*) this)->_ns->getLowerThresholdCritical ();
}

/*
 * setLowerThresholdCritical
 */
void 
CNumericSensor::setLowerThresholdCritical (int val) const
{
	((CNumericSensor*) this)->_ns->setLowerThresholdCritical (val);
}

/*
 * getUpperThresholdCritical
 */
int 
CNumericSensor::getUpperThresholdCritical (void) const
{
	return ((CNumericSensor*) this)->_ns->getUpperThresholdCritical ();
}

/*
 * setUpperThresholdCritical
 */
void 
CNumericSensor::setUpperThresholdCritical (int val) const
{
	((CNumericSensor*) this)->_ns->setUpperThresholdCritical (val);
}


/*
 * getLowerThresholdFatal
 */
int 
CNumericSensor::getLowerThresholdFatal (void) const
{
	return ((CNumericSensor*) this)->_ns->getLowerThresholdFatal ();
}

/*
 * setLowerThresholdFatal
 */
void 
CNumericSensor::setLowerThresholdFatal (int val) const
{
	((CNumericSensor*) this)->_ns->setLowerThresholdFatal (val);
}

/*
 * getUpperThresholdFatal
 */
int 
CNumericSensor::getUpperThresholdFatal (void) const
{
	return ((CNumericSensor*) this)->_ns->getUpperThresholdFatal ();
}

/*
 * setUpperThresholdFatal
 */
void 
CNumericSensor::setUpperThresholdFatal (int val) const
{
	((CNumericSensor*) this)->_ns->setUpperThresholdFatal (val);
}

/*
 * getSupportedThresholds
 */
vector<uint16> 
CNumericSensor::getSupportedThresholds (void) const
{
	return ((CNumericSensor*) this)->_ns->getSupportedThresholds ();
}

/*
 * getSettableThresholds
 */
vector<uint16> 
CNumericSensor::getSettableThresholds (void) const
{
	return ((CNumericSensor*) this)->_ns->getSettableThresholds ();
}

/*
 * getSensorType
 */
uint16 
CNumericSensor::getSensorType (void) const
{
	uint16 type = ((CNumericSensor*) this)->_ns->getSensorType ();
	if ((type > CIM_Sensor::SensorType_DMTF_Reserved_low) && 
		(type < CIM_Sensor::SensorType_DMTF_Reserved_high))
	{
		return dmtf_reserved;
	}
	else if ((type > CIM_Sensor::SensorType_Vendor_Reserved_low) && 
			 (type < CIM_Sensor::SensorType_Vendor_Reserved_high))
	{
		return vendor_reserved;
	}
	else
	{
		return type;
	}
}

/*
 * getSensorTypeStr
 */
string
CNumericSensor::getSensorTypeStr (void) const
{
	return CIM_Sensor::getValueStr_SensorType (_ns->getSensorType ());
}

/*
 * getPossibleStates
 */
vector<string> 
CNumericSensor::getPossibleStates (void) const
{
	return ((CNumericSensor*) this)->_ns->getPossibleStates ();
}

/*
 * getCurrentState
 */
string 
CNumericSensor::getCurrentState (void) const
{
	return ((CNumericSensor*) this)->_ns->getCurrentState ();
}

/*
 * getElementName
 */
string
CNumericSensor::getElementName (void) const
{ 
	return ((CNumericSensor*) this)->_ns->getElementName (); 
} 	

/*
 * getOtherFamilyDescription
 */
string 
CNumericSensor::getOtherSensorTypeDescription (void) const
{ 
	return ((CNumericSensor*) this)->_ns->getOtherSensorTypeDescription (); 
} 	

/*
 * getEnabledState
 */
uint16 
CNumericSensor::getEnabledState (void) const
{ 
	return ((CNumericSensor*) this)->_ns->getEnabledState (); 
} 	

/*
 * getEnabledStateStr
 */
string
CNumericSensor::getEnabledStateStr (void) const
{ 
	return CIM_Processor::getValueStr_EnabledState (
				((CNumericSensor*) this)->_ns->getEnabledState ()); 
} 

/*
 * getRequestedState
 */
uint16
CNumericSensor::getRequestedState (void) const
{ 
	return ((CNumericSensor*) this)->_ns->getRequestedState (); 
} 	

/*
 * getRequestedStateStr
 */
string
CNumericSensor::getRequestedStateStr (void) const
{ 
	return CIM_Processor::getValueStr_RequestedState (
			((CNumericSensor*) this)->_ns->getRequestedState ()); 
} 	

/*
 * getOperationalStatus
 */
vector<uint16>
CNumericSensor::getOperationalStatus (void) const
{ 
	return ((CNumericSensor*) this)->_ns->getOperationalStatus (); 
} 	

/*
 * getOperationalStatusStr
 */
vector<string>
CNumericSensor::getOperationalStatusStr (void) const 
{
	vector<uint16> status = ((CNumericSensor*) this)->_ns->getOperationalStatus ();
	vector <string> status_str;
	for(size_t value = 0; value < status.size(); value++ )
	{
		status_str.push_back(((CNumericSensor*) this)->_ns->getValueStr_OperationalStatus (status [value]));
	}

	return status_str;
}

/*
 * getHealthState
 */
uint16
CNumericSensor::getHealthState (void) const
{ 
	return ((CNumericSensor*) this)->_ns->getHealthState (); 
} 	

/*
 * getHealthStateStr
 */
string
CNumericSensor::getHealthStateStr (void) const
{ 
	return CIM_Processor::getValueStr_HealthState (
			((CNumericSensor*) this)->_ns->getHealthState ()); 
} 	

/*
 * restoreDefaultThresholds
 */
bool 
CNumericSensor::restoreDefaultThresholds (void) const
{
	return (0 == ((CNumericSensor*) this)->_ns->RestoreDefaultThresholds ());
}

	/*
	 * Unit types
	 */
	const uint16 CNumericSensor::unknown					 	= CIM_NumericSensor::BaseUnits_Unknown;
	const uint16 CNumericSensor::other						= CIM_NumericSensor::BaseUnits_Other;
	const uint16 CNumericSensor::degrees_c					= CIM_NumericSensor::BaseUnits_Degrees_C;
	const uint16 CNumericSensor::degrees_f					= CIM_NumericSensor::BaseUnits_Degrees_F;
	const uint16 CNumericSensor::degrees_k					= CIM_NumericSensor::BaseUnits_Degrees_K;
	const uint16 CNumericSensor::volts						= CIM_NumericSensor::BaseUnits_Volts;
	const uint16 CNumericSensor::amps						= CIM_NumericSensor::BaseUnits_Amps;
	const uint16 CNumericSensor::watts						= CIM_NumericSensor::BaseUnits_Watts;
	const uint16 CNumericSensor::joules						= CIM_NumericSensor::BaseUnits_Joules;
	const uint16 CNumericSensor::coulombs					= CIM_NumericSensor::BaseUnits_Coulombs;
	const uint16 CNumericSensor::va							= CIM_NumericSensor::BaseUnits_VA;
	const uint16 CNumericSensor::nits						= CIM_NumericSensor::BaseUnits_Nits;
	const uint16 CNumericSensor::lumens						= CIM_NumericSensor::BaseUnits_Lumens;
	const uint16 CNumericSensor::lux							= CIM_NumericSensor::BaseUnits_Lux;
	const uint16 CNumericSensor::candelas					= CIM_NumericSensor::BaseUnits_Candelas;
	const uint16 CNumericSensor::kpa							= CIM_NumericSensor::BaseUnits_kPa;
	const uint16 CNumericSensor::psi							= CIM_NumericSensor::BaseUnits_PSI;
	const uint16 CNumericSensor::newtons						= CIM_NumericSensor::BaseUnits_Newtons;
	const uint16 CNumericSensor::cfm							= CIM_NumericSensor::BaseUnits_CFM;
	const uint16 CNumericSensor::rpm							= CIM_NumericSensor::BaseUnits_RPM;
	const uint16 CNumericSensor::hertz						= CIM_NumericSensor::BaseUnits_Hertz;
	const uint16 CNumericSensor::seconds						= CIM_NumericSensor::BaseUnits_Seconds;
	const uint16 CNumericSensor::minutes						= CIM_NumericSensor::BaseUnits_Minutes;
	const uint16 CNumericSensor::hours						= CIM_NumericSensor::BaseUnits_Hours;
	const uint16 CNumericSensor::days						= CIM_NumericSensor::BaseUnits_Days;
	const uint16 CNumericSensor::weeks						= CIM_NumericSensor::BaseUnits_Weeks;
	const uint16 CNumericSensor::mils						= CIM_NumericSensor::BaseUnits_Mils;
	const uint16 CNumericSensor::inches						= CIM_NumericSensor::BaseUnits_Inches;
	const uint16 CNumericSensor::feet						= CIM_NumericSensor::BaseUnits_Feet;
	const uint16 CNumericSensor::cubic_inches				= CIM_NumericSensor::BaseUnits_Cubic_Inches;
	const uint16 CNumericSensor::cubic_feet					= CIM_NumericSensor::BaseUnits_Cubic_Feet;
	const uint16 CNumericSensor::meters						= CIM_NumericSensor::BaseUnits_Meters;
	const uint16 CNumericSensor::cubic_centimeters			= CIM_NumericSensor::BaseUnits_Cubic_Centimeters;
	const uint16 CNumericSensor::cubic_meters				= CIM_NumericSensor::BaseUnits_Cubic_Meters;
	const uint16 CNumericSensor::liters						= CIM_NumericSensor::BaseUnits_Liters;
	const uint16 CNumericSensor::fluid_ounces				= CIM_NumericSensor::BaseUnits_Fluid_Ounces;
	const uint16 CNumericSensor::radians						= CIM_NumericSensor::BaseUnits_Radians;
	const uint16 CNumericSensor::steradians					= CIM_NumericSensor::BaseUnits_Steradians;
	const uint16 CNumericSensor::revolutions					= CIM_NumericSensor::BaseUnits_Revolutions;
	const uint16 CNumericSensor::cycles						= CIM_NumericSensor::BaseUnits_Cycles;
	const uint16 CNumericSensor::gravities					= CIM_NumericSensor::BaseUnits_Gravities;
	const uint16 CNumericSensor::ounces						= CIM_NumericSensor::BaseUnits_Ounces;
	const uint16 CNumericSensor::pounds						= CIM_NumericSensor::BaseUnits_Pounds;
	const uint16 CNumericSensor::foot_pounds					= CIM_NumericSensor::BaseUnits_Foot_Pounds;
	const uint16 CNumericSensor::ounce_inches				= CIM_NumericSensor::BaseUnits_Ounce_Inches;
	const uint16 CNumericSensor::gauss						= CIM_NumericSensor::BaseUnits_Gauss;
	const uint16 CNumericSensor::gilberts					= CIM_NumericSensor::BaseUnits_Gilberts;
	const uint16 CNumericSensor::henries						= CIM_NumericSensor::BaseUnits_Henries;
	const uint16 CNumericSensor::farads						= CIM_NumericSensor::BaseUnits_Farads;
	const uint16 CNumericSensor::ohms						= CIM_NumericSensor::BaseUnits_Ohms;
	const uint16 CNumericSensor::siemens						= CIM_NumericSensor::BaseUnits_Siemens;
	const uint16 CNumericSensor::moles						= CIM_NumericSensor::BaseUnits_Moles;
	const uint16 CNumericSensor::becquerels					= CIM_NumericSensor::BaseUnits_Becquerels;
	const uint16 CNumericSensor::ppm							= CIM_NumericSensor::BaseUnits_PPM__parts_million_;
	const uint16 CNumericSensor::decibels					= CIM_NumericSensor::BaseUnits_Decibels;
	const uint16 CNumericSensor::dba							= CIM_NumericSensor::BaseUnits_DbA;
	const uint16 CNumericSensor::dbc							= CIM_NumericSensor::BaseUnits_DbC;
	const uint16 CNumericSensor::grays						= CIM_NumericSensor::BaseUnits_Grays;
	const uint16 CNumericSensor::sieverts					= CIM_NumericSensor::BaseUnits_Sieverts;
	const uint16 CNumericSensor::color_temperature_degrees_k	= CIM_NumericSensor::BaseUnits_Color_Temperature_Degrees_K;
	const uint16 CNumericSensor::bits						= CIM_NumericSensor::BaseUnits_Bits;
	const uint16 CNumericSensor::bytes						= CIM_NumericSensor::BaseUnits_Bytes;
	const uint16 CNumericSensor::words						= CIM_NumericSensor::BaseUnits_Words__data_;
	const uint16 CNumericSensor::doublewords					= CIM_NumericSensor::BaseUnits_DoubleWords;
	const uint16 CNumericSensor::quadwords					= CIM_NumericSensor::BaseUnits_QuadWords;
	const uint16 CNumericSensor::percentage					= CIM_NumericSensor::BaseUnits_Percentage;
	const uint16 CNumericSensor::pascals						= CIM_NumericSensor::BaseUnits_Pascals;


/*
 * Rate Units
 */
const uint16 CNumericSensor::none				= CIM_NumericSensor::RateUnits_None;
const uint16 CNumericSensor::per_usec			= CIM_NumericSensor::RateUnits_Per_MicroSecond;
const uint16 CNumericSensor::per_msec			= CIM_NumericSensor::RateUnits_Per_MilliSecond;
const uint16 CNumericSensor::per_sec			= CIM_NumericSensor::RateUnits_Per_Second;
const uint16 CNumericSensor::per_minute			= CIM_NumericSensor::RateUnits_Per_Minute;
const uint16 CNumericSensor::per_hour			= CIM_NumericSensor::RateUnits_Per_Hour;
const uint16 CNumericSensor::per_day			= CIM_NumericSensor::RateUnits_Per_Day;
const uint16 CNumericSensor::per_week			= CIM_NumericSensor::RateUnits_Per_Week;
const uint16 CNumericSensor::per_month			= CIM_NumericSensor::RateUnits_Per_Month;
const uint16 CNumericSensor::per_year			= CIM_NumericSensor::RateUnits_Per_Year; 

/* 
 * Supported Thresholds 
 */
const uint16 CNumericSensor::lower_threshold_non_critical_supported	= CIM_NumericSensor::SupportedThresholds_LowerThresholdNonCritical;
const uint16 CNumericSensor::upper_threshold_non_critical_supported	= CIM_NumericSensor::SupportedThresholds_UpperThresholdNonCritical;
const uint16 CNumericSensor::lower_threshold_critical_supported 	= CIM_NumericSensor::SupportedThresholds_LowerThresholdCritical;
const uint16 CNumericSensor::upper_threshold_critical_supported		= CIM_NumericSensor::SupportedThresholds_UpperThresholdCritical;
const uint16 CNumericSensor::lower_threshold_non_fatal_supported	= CIM_NumericSensor::SupportedThresholds_LowerThresholdFatal;
const uint16 CNumericSensor::upper_threshold_non_fatal_supported 	= CIM_NumericSensor::SupportedThresholds_UpperThresholdFatal;

/*
 * getCachedProps
 */
vector<string> 
CNumericSensor::getCachedProps (void)
{
	vector<string> props = CSensor::getCachedProps ();
	props.push_back ("BaseUnits");
	props.push_back ("UnitModifier");
	props.push_back ("RateUnits");
	props.push_back ("CurrentReading");
	props.push_back ("LowerThresholdNonCritical");
	props.push_back ("UpperThresholdNonCritical");
	props.push_back ("LowerThresholdCritical");
	props.push_back ("UpperThresholdCritical");
	props.push_back ("LowerThresholdFatal");
	props.push_back ("UpperThresholdFatal");
	props.push_back ("SupportedThresholds");
	props.push_back ("SettableThresholds");

	return props;
}

/*
 * CNumericSensor::Iterator
 */
DEFINE_API_ITERATOR (CNumericSensor);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CNumericSensor, CIM_NumericSensor);
