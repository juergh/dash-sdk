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
 * fan_c.h
 * A class representing a fan.
 */
#ifndef __CDSDK_FAN_H__
#define __CDSDK_FAN_H__
#include <dsdk/dsdktypes.h>
#include <dsdkc/capi.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Fan function table.
 */
struct _DSDKFan;
typedef struct _DSDKFan DSDKFan;

#ifndef __Type_E_defined__
#define __Type_E_defined__
typedef enum
{
	type_unknown,
	other,
	nplus1,
	load_balanced,
	sparing,
	limited_sparing,
	dmtf_reserved,
	vendor_reserved
	
} Type_E;
#endif

/**
 * @struct DSDKFanFT
 * @brief Fan function table 
 */
typedef struct _DSDKFanFT
{
	/**
	 * Gets name of the SystemCreationClassName
	 * @param nsme	The SystemCreationClassName
	 * @param max_len	maximum buffer length
	 **/
	void (*getSystemCreationClassName) (DSDKFan* fan, char* name, int max_len);

	/**
	 * Gets name of the SystemName
	 * @param nsme	The SystemName
	 * @param max_len	maximum buffer length
	 **/
	void (*getSystemName) (DSDKFan* fan, char* name, int max_len);

	/**
	 * Gets name of the CreationClassName
	 * @param nsme	The CreationClassName
	 * @param max_len	maximum buffer length
	 **/
	void (*getCreationClassName) (DSDKFan* fan, char* name, int max_len);


	/**
	 * Gets name of the Device ID
	 * @param devid	The device ID
	 * @param max_len	maximum buffer length
	 **/
	void (*getDeviceID) (DSDKFan* fan, char* devid, int max_len);

	/**
	 * Gets the OperationalStatus
	 * @param op_status	Operational Status
	 * @param max_types	maximum types
	 */
	int (*getOperationalStatus) (DSDKFan* fan, uint16* op_status, int max_types);

	/**
	 * Gets the list of operational status
	 * @param os			The operational status is filled in.
	 * @param max_os		maximum number of operational status
	 * @param max_strlen	maximum buffer size
	 */
	int (*getOperationalStatusStr) (DSDKFan* fan, char** os, int max_os, int max_strlen);

	/**
	 * Gets the health state of the fan
	 * @return The health state
	 */
	uint16 (*getHealthState) (DSDKFan* fan);

	/**
 	 * Gets the health state of the fan as string
 	 * @param state		The health state is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getHealthStateStr) (DSDKFan* fan, char* state, int max_len);

	/**
	 * Returns true if the fan supports variable speed 
	 * @return	true if fan supports variable speed.
	 * 		false otherwise
	 */
	BOOL (*isVariableSpeed) (DSDKFan* fan);
	
	/**
	 * Gets the fan's current speed(tach reading).
	 * @param speed	The speed of the fan.
	 * @param max_len	maximum buffer length
	 */
	void (*getSpeed) (DSDKFan* fan, char* speed, int max_len);
	
	/**
	 * Gets the desired speed of the fan 
	 * @return	The desired speed of the fan.
	 */
	uint64 (*getDesiredSpeed) (DSDKFan* fan);

	/**
	 * Sets the desired speed of the fan 
	 * @param speed	The desired speed.
	 * @return  0 if success, else error code.
	 **/
	uint32 (*setDesiredSpeed) (DSDKFan* fan, uint64 speed);

	/**
	 * Returns true if the fan supports variable speed 
	 * @return	true if fan supports variable speed.
	 * 		false otherwise
	 */
	BOOL (*isActiveCooling) (DSDKFan* fan);

	/**
	 * Gets the enabled state of the fan 
	 * @return	The enabled state of the fan.
	 */
	uint16 (*getEnabledState) (DSDKFan* fan);

	/**
 	 * Gets the state of the fan as string
 	 * @param state		The Enabled State is filled in
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getEnabledStateStr) (DSDKFan* fan, char* state, int max_len);

	/**
	 * Gets the requested state of the fan 
	 * @return	The requested state of the fan.
	 */
	uint16 (*getRequestedState) (DSDKFan* fan);

	/**
 	 * Gets the requested status of the fan as string
 	 * @param state		The requested state is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getRequestedStateStr) (DSDKFan* fan, char* state, int max_len);

	/**
	 * Gets the name of the Element
	 * @param ele_name	The element name
	 * @param max_len	maximum buffer length
	 **/
	void (*getElementName) (DSDKFan* fan, char* ele_name, int max_len);

	/**
	 * getSetSpeedErrStr
	 * @param	err Error code returned from setDesiredSpeed
	 * @return		Error description.
	 */
	void (*getSetSpeedErrStr) (DSDKFan* fan, uint32 err, char* ret_error, int max_len);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKFan* fan);

} DSDKFanFT;

struct _DSDKFan
{
	void*		hdl;
	DSDKFanFT*	ft;
};

/**
 * Fan iterator function table.
 */
struct _DSDKFanIterator;
typedef struct _DSDKFanIterator DSDKFanIterator;

/**
 * @struct DSDKFanIteratorFT
 * @brief Fan iterator function table 
 */
typedef struct _DSDKFanIteratorFT
{
	/**
	 * Returns the Fan at this iterator location.
	 */
	DSDKFan* (*getItem) (DSDKFanIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKFanIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKFanIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKFanIterator* di);

} DSDKFanIteratorFT;

/**
 * @struct _DSDKFanIterator 
 * @brief Iterator to iterate through the fans.
 */
struct _DSDKFanIterator
{
	void*					hdl;
	DSDKFanIteratorFT*	ft;
};

/**
 * Enumerate all the fans in a system.
 */
DSDKC_Export DSDKFanIterator* enumFans (DSDKClient* client, BOOL cached);



/**
 * fan redundancy set function table.
 */
struct _DSDKFanRedundancySet;
typedef struct _DSDKFanRedundancySet DSDKFanRedundancySet;

/**
 * @struct DSDKFanRedundancySetFT
 * @brief Fan function table 
 */
typedef struct _DSDKFanRedundancySetFT
{
	/**
	 * Gets the current redundancy status 
	 * @return The current redundancy status.
	 */
	int (*getRedundancyStatus) (DSDKFanRedundancySet* rs);
	
	/**
	 * Gets the type of the redundancy set 
	 * @return The type of the redundancy set.
	 */
	void (*getType) (DSDKFanRedundancySet* rs, Type_E** type, int max_type);
	
	/**
	 * Returns the minimum number needed 
	 * @return The minumum number 
	 */
	uint32 (*getMinimumNumberNeeded) (DSDKFanRedundancySet* rs);

	/**
	 * Forces a failover from one fan to another fan.
	 * @return The status.
	 */
	uint32 (*failover) (DSDKFanRedundancySet* rs, DSDKFan* fan_from, DSDKFan* fan_to);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKFanRedundancySet* cs);

} DSDKFanRedundancySetFT;

struct _DSDKFanRedundancySet
{
	void*					hdl;
	DSDKFanRedundancySetFT*	ft;
};

/**
 * fan redundancy set  iterator function table.
 */
struct _DSDKFanRedundancySetIterator;
typedef struct _DSDKFanRedundancySetIterator DSDKFanRedundancySetIterator;

/**
 * @struct DSDKFanRedundancySetIteratorFT
 * @brief Fan redundancy set iterator function table 
 */
typedef struct _DSDKFanRedundancySetIteratorFT
{
	/**
	 * Returns the fan redundancy set at this iterator location.
	 */
	DSDKFanRedundancySet* (*getItem) (DSDKFanRedundancySetIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKFanRedundancySetIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKFanRedundancySetIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKFanRedundancySetIterator* di);

} DSDKFanRedundancySetIteratorFT;

/**
 * @struct _DSDKFanRedundancySetIterator 
 * @brief Iterator to iterate through the fan redundancy sets
 */
struct _DSDKFanRedundancySetIterator
{
	void*							hdl;
	DSDKFanRedundancySetIteratorFT*	ft;
};

/**
 * Enumerate all the fan redundancy sets in a system.
 */
DSDKC_Export DSDKFanRedundancySetIterator* enumFanRedundancySets (
											DSDKClient* client, BOOL cached);

#ifdef SWIGIZE
DSDKC_Export void  fan_getSystemCreationClassName (DSDKFan* fan, char* name, int max_len);
DSDKC_Export void  fan_getSystemName (DSDKFan* fan, char* name, int max_len);
DSDKC_Export void  fan_getCreationClassName (DSDKFan* fan, char* name, int max_len);
DSDKC_Export void  fan_getDeviceID (DSDKFan* fan, char* devid, int max_len);
DSDKC_Export int  fan_getOperationalStatus (DSDKFan* fan, uint16* op_status, int max_types);
DSDKC_Export uint16  fan_getHealthState (DSDKFan* fan);
DSDKC_Export BOOL  fan_isVariableSpeed (DSDKFan* fan);
DSDKC_Export void  fan_getSpeed (DSDKFan* fan, char* speed, int max_len);
DSDKC_Export uint64  fan_getDesiredSpeed (DSDKFan* fan);
DSDKC_Export uint32  fan_setDesiredSpeed (DSDKFan* fan, uint64 speed);
DSDKC_Export BOOL  fan_isActiveCooling (DSDKFan* fan);
DSDKC_Export uint16  fan_getEnabledState (DSDKFan* fan);
DSDKC_Export uint16  fan_getRequestedState (DSDKFan* fan);
DSDKC_Export void  fan_getElementName (DSDKFan* fan, char* ele_name, int max_len);
DSDKC_Export void fan_getSetSpeedErrStr (DSDKFan* fan, uint32 err, char* ret_error, int max_len);
DSDKC_Export void  fan_release (DSDKFan* fan);
DSDKC_Export DSDKFan*  fani_getItem (DSDKFanIterator* di);
DSDKC_Export void  fani_next (DSDKFanIterator* di);
DSDKC_Export BOOL  fani_isEnd (DSDKFanIterator* di);
DSDKC_Export void  fani_release (DSDKFanIterator* di);
DSDKC_Export int  fanrs_getRedundancyStatus (DSDKFanRedundancySet* rs);
DSDKC_Export void  fanrs_getType (DSDKFanRedundancySet* rs, Type_E** type, int max_type);
DSDKC_Export uint32  fanrs_getMinimumNumberNeeded (DSDKFanRedundancySet* rs);
DSDKC_Export uint32 fanrs_failover (DSDKFanRedundancySet* rs, DSDKFan *fan_from, DSDKFan *fan_to);
DSDKC_Export void  fanrs_release (DSDKFanRedundancySet* cs);
DSDKC_Export DSDKFanRedundancySet*  rsi_getItem (DSDKFanRedundancySetIterator* di);
DSDKC_Export void  rsi_next (DSDKFanRedundancySetIterator* di);
DSDKC_Export BOOL  rsi_isEnd (DSDKFanRedundancySetIterator* di);
DSDKC_Export void  rsi_release (DSDKFanRedundancySetIterator* di);
#endif

#ifdef __cplusplus
}
#endif

#endif /* CDSDK_FAN_H_*/
