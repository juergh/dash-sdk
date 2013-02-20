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
 * sensor_c.h
 * A class representing a sensor installed.
 */
#ifndef __CDSDK_SENSOR_H__
#define __CDSDK_SENSOR_H__
#include <dsdk/dsdktypes.h>
#include <dsdkc/capi.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Sensor function table.
 */
struct _DSDKSensor;
typedef struct _DSDKSensor DSDKSensor;


/**
 * @struct DSDKSensorFT
 * @brief Sensor function table 
 */
typedef struct _DSDKSensorFT
{

 	/**
	 * Gets name of the SystemCreationClassName
	 * @param nsme	The SystemCreationClassName
	 * @param max_len	maximum buffer length
	 **/
	void (*getSystemCreationClassName) (DSDKSensor* sensor, char* name, int max_len);

	/**
	 * Gets name of the SystemName
	 * @param nsme	The SystemName
	 * @param max_len	maximum buffer length
	 **/
	void (*getSystemName) (DSDKSensor* sensor, char* name, int max_len);

	/**
	 * Gets name of the CreationClassName
	 * @param nsme	The CreationClassName
	 * @param max_len	maximum buffer length
	 **/
	void (*getCreationClassName) (DSDKSensor* sensor, char* name, int max_len);


	/**
	 * Gets name of the Device ID
	 * @param devid	The device ID
	 * @param max_len	maximum buffer length
	 **/
	void (*getDeviceID) (DSDKSensor* sensor, char* devid, int max_len);
	
	/**
 	 * Gets the type of the sensor 
 	 * @return The sensor type.
 	 */
 	uint16 (*getSensorType) (DSDKSensor* sensor);

	/**
	 * Gets the type of the sensor as string
	 * @param sensor_type	The sensor Type string
	 * @param max_len	maximum buffer length
	 */
	void (*getSensorTypeStr) (DSDKSensor* sensor, char* sensor_type, int max_len);
 	
 	/**
 	 * Gets the possible states of this sensor.
 	 * @param possible_state	The number of possible states of this sensor.
	 * @param max_state	maximum number of states
	 * @param max_strlen	maximum buffer size
 	 */
 	int (*getPossibleStates) (DSDKSensor* sensor, char** possible_state, 
							   int max_state, int max_strlen);
 	
 	/**
 	 * Gets the current state of this sensor.
 	 * @param state	The current state of this sensor.
	 * @param max_len	maximum buffer length
 	 */
 	void (*getCurrentState) (DSDKSensor* sensor, char* state, int max_len);

	/**
	 * Gets the name of the Element
	 * @param ele_name	The element name
	 * @param max_len	maximum buffer length
	 **/
	void (*getElementName) (DSDKSensor* sensor, char* ele_name, int max_len);

	/**
	 * Gets the sensor type description if the sensor type is "other".
	 * @param type_desc	The sensor type description
	 * @param max_len	maximum buffer length
	 */
	void (*getOtherSensorTypeDescription) (DSDKSensor* sensor, char* type_desc, int max_len);

	/**
	 * Gets the enabled state of the sensor 
	 * @return	The enabled state of the sensor.
	 */
	uint16 (*getEnabledState) (DSDKSensor* sensor);

	/**
 	 * Gets the state of the sensor as string
 	 * @param state		The Enabled State is filled in
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getEnabledStateStr) (DSDKSensor* sensor, char* state, int max_len);

	/**
	 * Gets the requested state of the sensor 
	 * @return	The requested state of the sensor.
	 */
	uint16 (*getRequestedState) (DSDKSensor* sensor);

	/**
 	 * Gets the requested status of the sensor as string
 	 * @param state		The requested state is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getRequestedStateStr) (DSDKSensor* sensor, char* state, int max_len);

	/**
	 * Gets the OperationalStatus
	 * @param op_status	Operational Status
	 * @param max_types	maximum types
	 */
	int (*getOperationalStatus) (DSDKSensor* sensor, uint16* op_status, int max_types);

	/**
	 * Gets the list of operational status
	 * @param os			The operational status is filled in.
	 * @param max_os		maximum number of operational status
	 * @param max_strlen	maximum buffer size
	 */
	int (*getOperationalStatusStr) (DSDKSensor* sensor, char** os, int max_os, int max_strlen);

	/**
	 * Gets the health state of the sensor
	 * @return The health state
	 */
	uint16 (*getHealthState) (DSDKSensor* sensor);

	/**
 	 * Gets the health state of the sensor as string
 	 * @param state		The health state is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getHealthStateStr) (DSDKSensor* sensor, char* state, int max_len);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKSensor* cs);

} DSDKSensorFT;

struct _DSDKSensor
{
	void*			hdl;
	DSDKSensorFT*	ft;
};

/**
 * Sensor iterator function table.
 */
struct _DSDKSensorIterator;
typedef struct _DSDKSensorIterator DSDKSensorIterator;

/**
 * @struct DSDKSensorIteratorFT
 * @brief Sensor iterator function table 
 */
typedef struct _DSDKSensorIteratorFT
{
	/**
	 * Returns the sensor at this iterator location.
	 */
	DSDKSensor* (*getItem) (DSDKSensorIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKSensorIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKSensorIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKSensorIterator* di);

} DSDKSensorIteratorFT;

/**
 * @struct _DSDKSensorIterator 
 * @brief Iterator to iterate through the sensor.
 */
struct _DSDKSensorIterator
{
	void*					hdl;
	DSDKSensorIteratorFT*	ft;
};

/**
 * Enumerate all the sensor in a system.
 */
DSDKC_Export DSDKSensorIterator* enumSensors (DSDKClient* client, BOOL cached);



/**
 * Numeric Sensor function table.
 */
struct _DSDKNumericSensor;
typedef struct _DSDKNumericSensor DSDKNumericSensor;


/**
 * @struct DSDKNumericSensorFT
 * @brief Numeric Sensor function table 
 */
typedef struct _DSDKNumericSensorFT
{

 	/**
 	 * Gets the base unit 
 	 * @return The base unit type
 	 */
 	uint16 (*getBaseUnit) (DSDKNumericSensor* ns);
 	
 	/**
 	 * Gets the unit modifier 
 	 * @return The Unit Modifier.
 	 */
 	int (*getUnitModifier) (DSDKNumericSensor* ns);

 	/**
 	 * Gets the rate unit 
 	 * @return The rate unit
 	 */
 	uint16 (*getRateUnit) (DSDKNumericSensor* ns);
 	
 	/**
 	 * Gets the current reading 
 	 * @return The current reading
 	 */
 	int (*getCurrentReading) (DSDKNumericSensor* ns);

	/**
 	 * Gets the lower threshold non critical 
 	 * @return The lower threshold non-critical value
 	 */
 	int (*getLowerThresholdNonCritical) (DSDKNumericSensor* ns);

	/**
 	 * Sets the lower threshold non critical 
 	 * @param val The lower threshold non-critical value. 
 	 */
 	void (*setLowerThresholdNonCritical) (DSDKNumericSensor* ns, int val);

	/**
 	 * Gets the upper threshold non critical 
 	 * @return The upper threshold non-critical value
 	 */
 	int (*getUpperThresholdNonCritical) (DSDKNumericSensor* ns);

	/**
 	 * Sets the upper threshold non critical 
 	 * @param val The upper threshold non-critical value. 
 	 */
 	void (*setUpperThresholdNonCritical) (DSDKNumericSensor* ns, int val);

	/**
 	 * Gets the lower threshold critical 
 	 * @return The lower threshold critical value
 	 */
 	int (*getLowerThresholdCritical) (DSDKNumericSensor* ns);

	/**
 	 * Sets the lower threshold critical 
 	 * @param val The lower threshold critical value. 
 	 */
 	void (*setLowerThresholdCritical) (DSDKNumericSensor* ns, int val);

	/**
 	 * Gets the upper threshold critical 
 	 * @return The upper threshold critical value
 	 */
 	int (*getUpperThresholdCritical) (DSDKNumericSensor* ns);

	/**
 	 * Sets the upper threshold critical 
 	 * @param val The upper threshold critical value. 
 	 */
 	void (*setUpperThresholdCritical) (DSDKNumericSensor* ns, int val);
 	
	/**
 	 * Gets the lower threshold fatal 
 	 * @return The lower threshold fatal value
 	 */
 	int (*getLowerThresholdFatal) (DSDKNumericSensor* ns);

	/**
 	 * Sets the lower threshold fatal 
 	 * @param val The lower threshold fatal value. 
 	 */
 	void (*setLowerThresholdFatal) (DSDKNumericSensor* ns, int val);

	/**
 	 * Gets the upper threshold fatal 
 	 * @return The upper threshold fatal value
 	 */
 	int (*getUpperThresholdFatal) (DSDKNumericSensor* ns);

	/**
 	 * Sets the upper threshold fatal 
 	 * @param val The upper threshold fatal value. 
 	 */
 	void (*setUpperThresholdFatal) (DSDKNumericSensor* ns, int val);

	/**
	 * Gets the set of supported thresholds 
	 * @return The number of supported thresholds
	 */
	int (*getSupportedThresholds) (DSDKNumericSensor* ns, uint16* supported_thresholds, int max_thresholds);
	
	/**
	 * Gets the set of settable thresholds 
	 * @return The number of settable thresholds
	 */
	int (*getSettableThresholds) (DSDKNumericSensor* ns, uint16* settable_thresholds, int max_thresholds);
	
	/**
	 * Restore to the default threshold values 
	 */
	BOOL (*restoreDefaultThresholds) (DSDKNumericSensor* ns);


	/**
	 * Releases this object
	 */
	void (*release) (DSDKNumericSensor* cs);

} DSDKNumericSensorFT;

struct _DSDKNumericSensor
{
	void*			hdl;
	DSDKNumericSensorFT*	ft;
};

/**
 * Numeric Sensor iterator function table.
 */
struct _DSDKNumericSensorIterator;
typedef struct _DSDKNumericSensorIterator DSDKNumericSensorIterator;

/**
 * @struct DSDKNumericSensorIteratorFT
 * @brief Numeric Sensor iterator function table 
 */
typedef struct _DSDKNumericSensorIteratorFT
{
	/**
	 * Returns the numeric sensor at this iterator location.
	 */
	DSDKNumericSensor* (*getItem) (DSDKNumericSensorIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKNumericSensorIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKNumericSensorIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKNumericSensorIterator* di);

} DSDKNumericSensorIteratorFT;

/**
 * @struct _DSDKNumericSensorIterator 
 * @brief Iterator to iterate through the numeric senosr.
 */
struct _DSDKNumericSensorIterator
{
	void*					hdl;
	DSDKNumericSensorIteratorFT*	ft;
};

/**
 * Enumerate all the numeric sensor in a system.
 */
DSDKC_Export DSDKNumericSensorIterator* 
				enumNumericSensors (DSDKClient* client, BOOL cached);

#ifdef SWIGIZE
DSDKC_Export void sensor_getSystemCreationClassName (DSDKSensor* sensor, char* name, int max_len);
DSDKC_Export void sensor_getSystemName (DSDKSensor* sensor, char* name, int max_len);
DSDKC_Export void sensor_getCreationClassName (DSDKSensor* sensor, char* name, int max_len);
DSDKC_Export void sensor_getDeviceID (DSDKSensor* sensor, char* devid, int max_len);
DSDKC_Export uint16 sensor_getSensorType (DSDKSensor* sensor);
DSDKC_Export void sensor_getSensorTypeStr (DSDKSensor* sensor, char* sensor_type, int max_len);
DSDKC_Export int sensor_getPossibleStates (DSDKSensor* sensor, char** possible_state, int max_state, int max_strlen);
DSDKC_Export void sensor_getCurrentState (DSDKSensor* sensor, char* state, int max_len);
DSDKC_Export void sensor_getElementName (DSDKSensor* sensor, char* ele_name, int max_len);
DSDKC_Export void sensor_getOtherSensorTypeDescription (DSDKSensor* sensor, char* type_desc, int max_len);
DSDKC_Export uint16 sensor_getEnabledState (DSDKSensor* sensor);
DSDKC_Export uint16 sensor_getRequestedState (DSDKSensor* sensor);
DSDKC_Export int sensor_getOperationalStatus (DSDKSensor* sensor, uint16* op_status, int max_types);
DSDKC_Export uint16 sensor_getHealthState (DSDKSensor* sensor);
DSDKC_Export void sensor_release (DSDKSensor* sensor);
DSDKC_Export DSDKSensor* sensori_getItem (DSDKSensorIterator* di);
DSDKC_Export void sensori_next (DSDKSensorIterator* di);
DSDKC_Export BOOL sensori_isEnd (DSDKSensorIterator* di);
DSDKC_Export void sensori_release (DSDKSensorIterator* di);
DSDKC_Export uint16 ns_getBaseUnit (DSDKNumericSensor* ns);
DSDKC_Export int ns_getUnitModifier (DSDKNumericSensor* ns);
DSDKC_Export uint16 ns_getRateUnit (DSDKNumericSensor* ns);
DSDKC_Export int ns_getCurrentReading (DSDKNumericSensor* ns);
DSDKC_Export int ns_getLowerThresholdNonCritical (DSDKNumericSensor* ns);
DSDKC_Export void ns_setLowerThresholdNonCritical (DSDKNumericSensor* ns, int val);
DSDKC_Export int ns_getUpperThresholdNonCritical (DSDKNumericSensor* ns);
DSDKC_Export void ns_setUpperThresholdNonCritical (DSDKNumericSensor* ns, int val);
DSDKC_Export int ns_getLowerThresholdCritical (DSDKNumericSensor* ns);
DSDKC_Export void ns_setLowerThresholdCritical (DSDKNumericSensor* ns, int val);
DSDKC_Export int ns_getUpperThresholdCritical (DSDKNumericSensor* ns);
DSDKC_Export void ns_setUpperThresholdCritical (DSDKNumericSensor* ns, int val);
DSDKC_Export int ns_getLowerThresholdFatal (DSDKNumericSensor* ns);
DSDKC_Export void ns_setLowerThresholdFatal (DSDKNumericSensor* ns, int val);
DSDKC_Export int ns_getUpperThresholdFatal (DSDKNumericSensor* ns);
DSDKC_Export void ns_setUpperThresholdFatal (DSDKNumericSensor* ns, int val);
DSDKC_Export int ns_getSupportedThresholds (DSDKNumericSensor* ns, uint16* supported_thresholds, int max_thresholds);
DSDKC_Export int ns_getSettableThresholds (DSDKNumericSensor* ns, uint16* settable_thresholds, int max_thresholds);
DSDKC_Export BOOL ns_restoreDefaultThresholds (DSDKNumericSensor* ns);
DSDKC_Export void ns_release (DSDKNumericSensor* ns);
DSDKC_Export DSDKNumericSensor* nsi_getItem (DSDKNumericSensorIterator* di);
DSDKC_Export void nsi_next (DSDKNumericSensorIterator* di);
DSDKC_Export BOOL nsi_isEnd (DSDKNumericSensorIterator* di);
DSDKC_Export void nsi_release (DSDKNumericSensorIterator* di);
#endif

#ifdef __cplusplus
}
#endif

#endif /* CDSDK_SENSOR_H_*/
