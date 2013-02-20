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
 * sensor.h
 * A Sensor class.
 **/
#ifndef __DSDK_SENSOR_H__
#define __DSDK_SENSOR_H__
#include <dsdk/dsdkiterator.h>
#include <dsdk/dsdk_api.h>



namespace dsdk
{

class CIM_Sensor;
class CSensor;
typedef CAPIIterator<CSensor, CIM_Sensor> _CSensorIterator;

/**
  * @class CSensor
  * @brief A class representing a Sensor.
  */
class DSDK_Export CSensor
{
public:
	DECLARE_API_ITERATOR (CSensor);
	typedef CIM_Sensor	CIMType;
	
	/**
	 * Enumerates all the sensors present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the sensor.
	 */
	static CSensor::iterator enumSensors (IClient* client, 
										  bool 	   cached = true);

	/**
	 * Return the underlying CIM object
	 */
	CIM_Sensor* getCIMObject (void) const { return _sensor; }

public:

	static const uint16 	unknown; 
	static const uint16 	other; 
	static const uint16 	temperature; 
	static const uint16 	voltage; 
	static const uint16 	current; 
	static const uint16 	tachometer; 
	static const uint16 	counter; 
	static const uint16 	Switch; 
	static const uint16 	lock; 
	static const uint16 	humidity; 
	static const uint16 	smoke_detection; 
	static const uint16 	presence; 
	static const uint16 	air_flow; 
	static const uint16 	power_consumption;
	static const uint16 	power_production;
	static const uint16 	dmtf_reserved;
	static const uint16 	vendor_reserved;


public:
	/**
	 * Gets the System Creation class of the sensor
	 * @return The System Creation Class name
	 */
	string getSystemCreationClassName (void) const;
	
	/**
	 * Gets the System name of the sensor
	 * @return The System name
	 */
	string getSystemName (void) const;

	/**
	 * Gets the Creation class Name of the sensor
	 * @return The processor creation class name.
	 */
	string getCreationClassName (void) const;

	/**
	 *  Gets the device id of the sensor
	 *  @return The sensor device id.
	 */
	string getDeviceID (void) const;

	/**
	 * Gets the type of the sensor 
	 * @return The sensor type.
	 */
	uint16 getSensorType (void) const;

	/**
	 * Gets the type of the sensor as string
	 * @return The sensor Type
	 */
	string getSensorTypeStr (void) const;

	/**
	 * Gets the possible states of this sensor.
	 * @return The possible states of this sensor.
	 */
	vector<string> getPossibleStates (void) const;

	/**
	 * Gets the current state of this sensor.
	 * @return The current state of this sensor.
	 */
	string getCurrentState (void) const;

	/**
	 * Gets the element name of the sensor
	 * @return The element name
	 */
	string getElementName (void) const;

	/**
	 * Gets the sensor type description if the sensor type is "other".
	 * @return The sensor type description 
	 */
	string getOtherSensorTypeDescription (void) const;

	/**
	 * Gets the state of the sensor
	 * @return The enabled state
	 */
	uint16 getEnabledState (void) const;

	/**
	 * Gets the state of the sensor as string
	 * @return The enabled state
	 */
	string getEnabledStateStr (void) const;

	/**
	 * Gets the last requested state of the sensor
	 * @return The requested state
	 */
	uint16 getRequestedState (void) const;

	/**
	 * Gets the last requested state of the sensor as string
	 * @return The requested state
	 */
	string getRequestedStateStr (void) const;

	/**
	 * Gets the operational status of the sensor
	 * @return The operational status
	 */
	vector<uint16> getOperationalStatus (void) const;

	/**
	 * Gets the operational status of the sensor as string
	 * @return The operational status
	 */
	vector<string> getOperationalStatusStr (void) const;

	/**
	 * Gets the health state of the sensor
	 * @return The health state
	 */
	uint16 getHealthState (void) const;

	/**
	 * Gets the health state of the sensor as string
	 * @return The health state
	 */
	string getHealthStateStr (void) const;

public:
	/**
	 * Construct this object from the corresponding CIM_Sensor
	 * object
	 */
	CSensor (const CIM_Sensor& sensor);
	
	/**
	 * Copy constructor
	 */
	CSensor (const CSensor& cs);

	/**
	 * Destructor
	 */
	~CSensor ();

	/**
	 * Assignment operator
	 */
	const CSensor& operator = (const CSensor& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void);

private:
	CIM_Sensor* _sensor;
};

class CIM_NumericSensor;
class CNumericSensor;
typedef CAPIIterator<CNumericSensor, CIM_NumericSensor> _CNumericSensorIterator;

/**
  * @class CNumericSensor
  * @brief A class representing a Numeric Sensor.
  */
class DSDK_Export CNumericSensor : public CSensor
{
public:
	DECLARE_API_ITERATOR (CNumericSensor);
	typedef CIM_NumericSensor	CIMType;
	
	/**
	 * Enumerates all the numeric sensors present under a MAP.
	 * @param client Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the numeric sensor.
	 */
	static CNumericSensor::iterator enumNumericSensors (IClient* client, 
										  				bool cached = true);

	/**
	 * Return the underlying CIM object
	 */
	CIM_NumericSensor* getCIMObject (void) const { return _ns; }


public:
	/**
	 * Unit types
	 */
	static const uint16 unknown	; 
	static const uint16 other	; 
	static const uint16 degrees_c;
	static const uint16 degrees_f;
	static const uint16 degrees_k;
	static const uint16 volts; 
	static const uint16 amps; 
	static const uint16 watts; 
	static const uint16 joules; 
	static const uint16 coulombs; 
	static const uint16 va; 
	static const uint16 nits; 
	static const uint16 lumens; 
	static const uint16 lux; 
	static const uint16 candelas; 
	static const uint16 kpa; 
	static const uint16 psi; 
	static const uint16 newtons	; 
	static const uint16 cfm; 
	static const uint16 rpm; 
	static const uint16 hertz	; 
	static const uint16 seconds	; 
	static const uint16 minutes	; 
	static const uint16 hours; 
	static const uint16 days; 
	static const uint16 weeks; 
	static const uint16 mils; 
	static const uint16 inches; 
	static const uint16 feet; 
	static const uint16 cubic_inches;
	static const uint16 cubic_feet	;
	static const uint16 meters;
	static const uint16 cubic_centimeters;
	static const uint16 cubic_meters;
	static const uint16 liters;
	static const uint16 fluid_ounces;
	static const uint16 radians;
	static const uint16 steradians	;
	static const uint16 revolutions	;
	static const uint16 cycles;
	static const uint16 gravities	;
	static const uint16 ounces;
	static const uint16 pounds;
	static const uint16 foot_pounds	;
	static const uint16 ounce_inches;
	static const uint16 gauss;
	static const uint16 gilberts;
	static const uint16 henries;
	static const uint16 farads;
	static const uint16 ohms;
	static const uint16 siemens;
	static const uint16 moles;
	static const uint16 becquerels;
	static const uint16 ppm;
	static const uint16 decibels;
	static const uint16 dba;
	static const uint16 dbc;
	static const uint16 grays;
	static const uint16 sieverts	;
	static const uint16 color_temperature_degrees_k	;
	static const uint16 bits;
	static const uint16 bytes;
	static const uint16 words;
	static const uint16 doublewords	;
	static const uint16 quadwords;
	static const uint16 percentage	;
	static const uint16 pascals;

	/**
	 * Rate Units
	 */
	static const uint16 none;
	static const uint16 per_usec;
	static const uint16 per_msec;
	static const uint16 per_sec;
	static const uint16 per_minute;
	static const uint16 per_hour;
	static const uint16 per_day;
	static const uint16 per_week;
	static const uint16 per_month;
	static const uint16 per_year;

	/** Supported Thresholds */
	static const uint16 lower_threshold_non_critical_supported; 
	static const uint16 upper_threshold_non_critical_supported; 
	static const uint16 lower_threshold_critical_supported; 	
	static const uint16 upper_threshold_critical_supported;		
	static const uint16 lower_threshold_non_fatal_supported;	
	static const uint16 upper_threshold_non_fatal_supported; 	


public:
	/**
	 * Gets the System Creation class name of the sensor
	 * @return The System Creation Class name
	 */
	string getSystemCreationClassName (void) const;
	
	/**
	 * Gets the System name of the sensor
	 * @return The System name
	 */
	string getSystemName (void) const;

	/**
	 * Gets the Creation class Name of the sensor
	 * @return The processor creation class name.
	 */
	string getCreationClassName (void) const;

	/**
	 *  Gets the device id of the sensor
	 *  @return The sensor device id.
	 */
	string getDeviceID (void) const;

	/**
	 * Gets the base unit 
	 * @return The base unit type
	 */
	uint16 getBaseUnit (void) const;

	/**
	 * Gets the base unit as string 
	 * @return The base unit type
	 */
	string getBaseUnitStr (void) const;

	/**
	 * Gets the unit modifier 
	 * @return The Unit Modifier.
	 */
	sint32 getUnitModifier (void) const;

	/**
	 * Gets the rate unit 
	 * @return The rate unit
	 */
	uint16 getRateUnit (void) const;

	/**
	 * Gets the rate unit 
	 * @return The rate unit
	 */
	string getRateUnitStr (void) const;

	/**
	 * Gets the current reading 
	 * @return The current reading
	 */
	sint32 getCurrentReading (void) const;

	/**
	 * Gets the lower threshold non critical 
	 * @return The lower threshold non-critical value
	 */
	int getLowerThresholdNonCritical (void) const;

	/**
	 * Sets the lower threshold non critical 
	 * @param val The lower threshold non-critical value. 
	 */
	void setLowerThresholdNonCritical (int val) const;

	/**
	 * Gets the upper threshold non critical 
	 * @return The upper threshold non-critical value
	 */
	int getUpperThresholdNonCritical (void) const;

	/**
	 * Sets the upper threshold non critical 
	 * @param val The upper threshold non-critical value. 
	 */
	void setUpperThresholdNonCritical (int val) const;

	/**
	 * Gets the lower threshold critical 
	 * @return The lower threshold critical value
	 */
	int getLowerThresholdCritical (void) const;

	/**
	 * Sets the lower threshold critical 
	 * @param val The lower threshold critical value. 
	 */
	void setLowerThresholdCritical (int val) const;

	/**
	 * Gets the upper threshold critical 
	 * @return The upper threshold critical value
	 */
	int getUpperThresholdCritical (void) const;

	/**
	 * Sets the upper threshold critical 
	 * @param val The upper threshold critical value. 
	 */
	void setUpperThresholdCritical (int val) const;

	/**
	 * Gets the lower threshold fatal
	 * @return The lower threshold fatal value
	 */
	int getLowerThresholdFatal (void) const;

	/**
	 * Sets the lower threshold fatal
	 * @param val The lower threshold fatal value. 
	 */
	void setLowerThresholdFatal (int val) const;

	/**
	 * Gets the upper threshold fatal
	 * @return The upper threshold fatal value
	 */
	int getUpperThresholdFatal (void) const;

	/**
	 * Sets the upper threshold fatal
	 * @param val The upper threshold fatal value. 
	 */
	void setUpperThresholdFatal (int val) const;

	/**
	 * Gets the set of supported thresholds 
	 * @return The bitmask
	 */
	vector<uint16> getSupportedThresholds (void) const;

	/**
	 * Gets the set of settable thresholds 
	 * @return The bitmask
	 */
	vector<uint16> getSettableThresholds (void) const;

	/**
	 * Gets the type of the sensor 
	 * @return The sensor type.
	 */
	uint16 getSensorType (void) const;

	/**
	 * Gets the type of the sensor as string
	 * @return The sensor Type
	 */
	string getSensorTypeStr (void) const;

	/**
	 * Gets the possible states of this sensor.
	 * @return The possible states of this sensor.
	 */
	vector<string> getPossibleStates (void) const;

	/**
	 * Gets the current state of this sensor.
	 * @return The current state of this sensor.
	 */
	string getCurrentState (void) const;

	/**
	 * Gets the element name of the sensor
	 * @return The element name
	 */
	string getElementName (void) const;

	/**
	 * Gets the sensor type description if the sensor type is "other".
	 * @return The sensor type description 
	 */
	string getOtherSensorTypeDescription (void) const;

	/**
	 * Gets the state of the sensor
	 * @return The enabled state
	 */
	uint16 getEnabledState (void) const;

	/**
	 * Gets the state of the sensor as string
	 * @return The enabled state
	 */
	string getEnabledStateStr (void) const;

	/**
	 * Gets the last requested state of the sensor
	 * @return The requested state
	 */
	uint16 getRequestedState (void) const;

	/**
	 * Gets the last requested state of the sensor as string
	 * @return The requested state
	 */
	string getRequestedStateStr (void) const;

	/**
	 * Gets the operational status of the sensor
	 * @return The operational status
	 */
	vector<uint16> getOperationalStatus (void) const;

	/**
	 * Gets the operational status of the sensor as string
	 * @return The operational status
	 */
	vector<string> getOperationalStatusStr (void) const;

	/**
	 * Gets the health state of the sensor
	 * @return The health state
	 */
	uint16 getHealthState (void) const;

	/**
	 * Gets the health state of the sensor as string
	 * @return The health state
	 */
	string getHealthStateStr (void) const;

	/**
	 * Restore to the default threshold values 
	 */
	bool restoreDefaultThresholds (void) const;

	/**
	 * Converts a CSensor to CNumericSensor
	 * @param sensor Sensor to be converted to Numeric Sensor.
	 */
	static CNumericSensor toNumericSensor (CSensor& senosr);

public:
	/**
	 * Construct this object from the corresponding CIM_NumericSensor
	 * object
	 */
	CNumericSensor (const CIM_NumericSensor& ns);
	
	/**
	 * Copy constructor
	 */
	CNumericSensor (const CNumericSensor& cs);

	/**
	 * Destructor
	 */
	~CNumericSensor ();

	/**
	 * Assignment operator
	 */
	const CNumericSensor& operator = (const CNumericSensor& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void);

private:
	CIM_NumericSensor* _ns;
};

}; 	/* namespace dsdk */

#endif /*SENSOR_H_*/
