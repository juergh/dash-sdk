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
 * battery_c.h
 * A class representing a battery.
 */
#ifndef __CDSDK_BATTERY_H__
#define __CDSDK_BATTERY_H__
#include <dsdk/dsdktypes.h>
#include <dsdkc/capi.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Battery function table.
 */
struct _DSDKBattery;
typedef struct _DSDKBattery DSDKBattery;


/** 
 * @struct DSDKBatteryFT
 * @brief Battery function table 
 */
typedef struct _DSDKBatteryFT
{
	/**
	 * Gets the battery System Creation class Name 
	 * @param name	Creation Class Name of the battery
	 * @param max_len	maximum buffer length
	 */
	void (*getSystemCreationClassName) (DSDKBattery* bat, char* name, int max_len);

	/**
	 * Gets SystemName of the battery
	 * @param name	system Name of the battery
	 * @param max_len	maximum buffer length
	 **/
 	void (*getSystemName) (DSDKBattery* bat, char* name, int max_len);

	/**
	 * Gets the battery Creation class Name 
	 * @param name	Creation Class Name of the battery
	 * @param max_len	maximum buffer length
	 */
	void (*getCreationClassName) (DSDKBattery* bat, char* name, int max_len);

	/**
	 * Gets DeviceID of the battery
	 * @param devid	device ID of the battery
	 * @param max_len	maximum buffer length
	 **/
 	void (*getDeviceID) (DSDKBattery* bat, char* devid, int max_len);
	
	/**
	 * Gets the Status of this battery.
	 * @return The battery status
	 **/ 	
 	uint16 (*getBatteryStatus) (DSDKBattery* bat);

	/**
 	 * Gets the status of this battery as string
 	 * @param state		The status
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getBatterStatusStr) (DSDKBattery* bat, char* status, int max_len);

	/**
	 * Gets the OperationalStatus
	 * @param op_status	Operational Status
	 * @param max_types	maximum types
	 */
	int (*getOperationalStatus) (DSDKBattery* bat, uint16* op_status, int max_types);

	/**
	 * Gets the list of operational status
	 * @param os			The operational status is filled in.
	 * @param max_os		maximum number of operational status
	 * @param max_strlen	maximum buffer size
	 */
	int (*getOperationalStatusStr) (DSDKBattery* bat, char** os, int max_os, int max_strlen);

	/**
	 * Gets the health state of the batteery
	 * @return The health state
	 */
	uint16 (*getHealthState) (DSDKBattery* bat);

	/**
 	 * Gets the health state of the batessor as string
 	 * @param state		The health state is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getHealthStateStr) (DSDKBattery* bat, char* state, int max_len);

	/**
	 * Gets the state of the batessor
	 * @return The enabled state
	 */
	uint16 (*getEnabledState) (DSDKBattery* bat);

	/**
 	 * Gets the state of the batessor as string
 	 * @param state		The Enabled State is filled in
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getEnabledStateStr) (DSDKBattery* bat, char* state, int max_len);

	/**
	 * Gets the requested state of the batessor
	 * @return The enabled state
	 */
	uint16 (*getRequestedState) (DSDKBattery* bat);

	/**
 	 * Gets the requested status of the batessor as string
 	 * @param state		The requested state is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getRequestedStateStr) (DSDKBattery* bat, char* state, int max_len);

	/**
	 * Gets ElemantName of the battery
	 * @param name	ElementName of the battery
	 * @param max_len	maximum buffer length
	 **/
 	void (*getElementName) (DSDKBattery* bat, char* name, int max_len);

	/**
	 * Gets the getChemistry of this battery.
	 * @return The battery Chemistry
	 **/ 	
 	uint16 (*getChemistry) (DSDKBattery* bat);

	/**
	 * Gets the getMaxRechargeCount of this battery.
	 * @return The battery MaxRechargeCount
	 **/ 	
 	uint32 (*getMaxRechargeCount) (DSDKBattery* bat);

	/**
	 * Gets the getRechargeCount of this battery.
	 * @return The battery RechargeCount
	 **/ 	
 	uint32 (*getRechargeCount) (DSDKBattery* bat);

	/**
	 * Gets the getExpectedLife of this battery.
	 * @return The battery ExpectedLife
	 **/ 	
 	uint32 (*getExpectedLife) (DSDKBattery* bat);

	/**
 	 * Gets EstimatedRunTime of the battery.
	 * @return Estimated run time
 	 **/
 	uint32 (*getEstimatedRunTime) (DSDKBattery* bat);

	/**
 	 * Gets TimeToFullCharge of the battery.
	 * @return TimeToFullCharge
 	 **/
 	uint32 (*getTimeToFullCharge) (DSDKBattery* bat);

	/**
 	 * Gets MaxRechargeTime of the battery.
	 * @return MaxRechargeTime
 	 **/
 	uint32 (*getMaxRechargeTime) (DSDKBattery* bat);

	/**
	 * Enable/turn on Battery
	 */
	void (*enable) (DSDKBattery* bat);

	/**
	 * Disable/turn off Battery
	 */
	void (*disable) (DSDKBattery* bat);

	/**
	 * Test/perform recalculation of charge thresholds.
	 */
	void (*test) (DSDKBattery* bat);

	/**
	 * Reset/recharge of battery.
	 */
	void (*reset) (DSDKBattery* bat);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKBattery* bat);

} DSDKBatteryFT;


struct _DSDKBattery
{
	void*			hdl;
	DSDKBatteryFT*	ft;
};


/**
 * Battery iterator function table.
 */
struct _DSDKBatteryIterator;
typedef struct _DSDKBatteryIterator DSDKBatteryIterator;

/**
 * @struct DSDKBatteryIteratorFT
 * @brief Battery iterator function table 
 */
typedef struct _DSDKBatteryIteratorFT
{
	/**
	 * Returns the software at this iterator location.
	 */
	DSDKBattery* (*getItem) (DSDKBatteryIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKBatteryIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKBatteryIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKBatteryIterator* di);

} DSDKBatteryIteratorFT;

/**
 * @struct _DSDKBatteryIterator 
 * @brief Iterator to iterate through the Battery.
 */
struct _DSDKBatteryIterator
{
	void*					hdl;
	DSDKBatteryIteratorFT*	ft;
};


/**
 * Enumerate all the battery in a system.
 */
DSDKC_Export DSDKBatteryIterator* enumBattery (
											DSDKClient* client, BOOL cached);

#ifdef SWIGIZE
DSDKC_Export void  bat_getSystemCreationClassName (DSDKBattery* bat, char* name, int max_len);
DSDKC_Export void  bat_getSystemName (DSDKBattery* bat, char* name, int max_len);
DSDKC_Export void  bat_getCreationClassName (DSDKBattery* bat, char* name, int max_len);
DSDKC_Export void  bat_getDeviceID (DSDKBattery* bat, char* devid, int max_len);
DSDKC_Export uint16  bat_getBatteryStatus (DSDKBattery* bat);
DSDKC_Export int  bat_getOperationalStatus (DSDKBattery* bat, uint16* op_status, int max_types);
DSDKC_Export uint16  bat_getHealthState (DSDKBattery* bat);
DSDKC_Export uint16  bat_getEnabledState (DSDKBattery* bat);
DSDKC_Export uint16  bat_getRequestedState (DSDKBattery* bat);
DSDKC_Export void  bat_getElementName (DSDKBattery* bat, char* name, int max_len);
DSDKC_Export uint16  bat_getChemistry (DSDKBattery* bat);
DSDKC_Export uint32  bat_getMaxRechargeCount (DSDKBattery* bat);
DSDKC_Export uint32  bat_getRechargeCount (DSDKBattery* bat);
DSDKC_Export uint32  bat_getExpectedLife (DSDKBattery* bat);
DSDKC_Export uint32  bat_getEstimatedRunTime (DSDKBattery* bat);
DSDKC_Export uint32  bat_getTimeToFullCharge (DSDKBattery* bat);
DSDKC_Export uint32  bat_getMaxRechargeTime (DSDKBattery* bat);
DSDKC_Export void  bat_enable (DSDKBattery* bat);
DSDKC_Export void  bat_disable (DSDKBattery* bat);
DSDKC_Export void  bat_test (DSDKBattery* bat);
DSDKC_Export void  bat_reset (DSDKBattery* bat);
DSDKC_Export void  bat_release (DSDKBattery* bat);
DSDKC_Export DSDKBattery*  bati_getItem (DSDKBatteryIterator* di);
DSDKC_Export void  bati_next (DSDKBatteryIterator* di);
DSDKC_Export BOOL  bati_isEnd (DSDKBatteryIterator* di);
DSDKC_Export void  bati_release (DSDKBatteryIterator* di);
#endif

#ifdef __cplusplus
}
#endif
#endif /* CDSDK_BATTERY_H_*/












