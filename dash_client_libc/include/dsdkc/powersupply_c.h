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
 * powersupply_c.h
 * A class representing a power supply installed.
 */
#ifndef __CDSDK_POWERSUPPLY_H__
#define __CDSDK_POWERSUPPLY_H__
#include <dsdk/dsdktypes.h>
#include <dsdkc/capi.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Power supply function table.
 */
struct _DSDKPowerSupply;
typedef struct _DSDKPowerSupply DSDKPowerSupply;

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
 * @struct DSDKPowerSupplyFT
 * @brief Power Supply function table 
 */
typedef struct _DSDKPowerSupplyFT
{
	/**
	 * Gets the powersupply System Creation class Name 
	 * @param name	Creation Class Name of the powersupply
	 * @param max_len	maximum buffer length
	 */
	void (*getSystemCreationClassName) (DSDKPowerSupply* ps, char* name, int max_len);

	/**
	 * Gets SystemName of the powersupply
	 * @param name	system Name of the powersupply
	 * @param max_len	maximum buffer length
	 **/
 	void (*getSystemName) (DSDKPowerSupply* ps, char* name, int max_len);

	/**
	 * Gets the powersupply Creation class Name 
	 * @param name	Creation Class Name of the powersupply
	 * @param max_len	maximum buffer length
	 */
	void (*getCreationClassName) (DSDKPowerSupply* ps, char* name, int max_len);

	/**
	 * Gets DeviceID of the powersupply
	 * @param devid	device ID of the powersupply
	 * @param max_len	maximum buffer length
	 **/
 	void (*getDeviceID) (DSDKPowerSupply* ps, char* devid, int max_len);

	/**
	 * Gets the total power value.
	 * @return The total power
	 **/ 	
 	uint32 (*getTotalPower) (DSDKPowerSupply* ps);

	/**
	 * Gets ElementName of the powersupply
	 * @param name	getElementName of the powersupply
	 * @param max_len	maximum buffer length
	 **/
 	void (*getElementName) (DSDKPowerSupply* ps, char* name, int max_len);

	/**
	 * Gets the OperationalStatus
	 * @param op_status	Operational Status
	 * @param max_types	maximum types
	 */
	int (*getOperationalStatus) (DSDKPowerSupply* ps, uint16* op_status, int max_types);

	/**
	 * Gets the list of operational status
	 * @param os			The operational status is filled in.
	 * @param max_os		maximum number of operational status
	 * @param max_strlen	maximum buffer size
	 */
	int (*getOperationalStatusStr) (DSDKPowerSupply* ps, char** os, int max_os, int max_strlen);

	/**
	 * Gets the health state of the powersupply
	 * @return The health state
	 */
	uint16 (*getHealthState) (DSDKPowerSupply* ps);

	/**
 	 * Gets the health state of the power supply as string
 	 * @param state		The health state is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getHealthStateStr) (DSDKPowerSupply* ps, char* state, int max_len);

	/**
	 * Gets the Enabled state of powersupply 
	 * @return The Enabled state
	 **/
	uint16 (*getEnabledState)  (DSDKPowerSupply* ps);

	/**
 	 * Gets the state of the power supply as string
 	 * @param state		The Enabled State is filled in
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getEnabledStateStr) (DSDKPowerSupply* ps, char* state, int max_len);

	/**
	 * Gets the Requested State state of powersupply 
	 * @return The Requested State
	 **/
	uint16 (*getRequestedState)  (DSDKPowerSupply* ps);

	/**
 	 * Gets the requested status of the power supply as string
 	 * @param state		The requested state is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getRequestedStateStr) (DSDKPowerSupply* ps, char* state, int max_len);

	/**
	 * Enables this power supply 
	 * @return  0 on success, throws execption on failure.
	 */
	uint32 (*enablePowerSupply) (DSDKPowerSupply* ps);

	/**
	 * Disables this processor 
	 * @return  0 on success, throws execption on failure.
	 */
	uint32 (*disablePowerSupply) (DSDKPowerSupply* ps);

	/**
	 * Resets this power supply 
	 * @return  0 on success, throws execption on failure.
	 */
	uint32 (*resetPowerSupply) (DSDKPowerSupply* ps);

	/**
	 * Makes this power supply offline. 
	 * @return  0 on success, throws execption on failure.
	 */
	uint32 (*offlinePowerSupply) (DSDKPowerSupply* ps);


	/**
	 * Releases this object
	 */
	void (*release) (DSDKPowerSupply* ps);

} DSDKPowerSupplyFT;

struct _DSDKPowerSupply
{
	void*			hdl;
	DSDKPowerSupplyFT*	ft;
};

/**
 * Power Supply iterator function table.
 */
struct _DSDKPowerSupplyIterator;
typedef struct _DSDKPowerSupplyIterator DSDKPowerSupplyIterator;

/**
 * @struct DSDKPowerSupplyIteratorFT
 * @brief Power Supply iterator function table 
 */
typedef struct _DSDKPowerSupplyIteratorFT
{
	/**
	 * Returns the power supply at this iterator location.
	 */
	DSDKPowerSupply* (*getItem) (DSDKPowerSupplyIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKPowerSupplyIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKPowerSupplyIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKPowerSupplyIterator* di);

} DSDKPowerSupplyIteratorFT;

/**
 * @struct _DSDKPowerSupplyIterator 
 * @brief Iterator to iterate through the power supply.
 */
struct _DSDKPowerSupplyIterator
{
	void*					hdl;
	DSDKPowerSupplyIteratorFT*	ft;
};

/**
 * Enumerate all the power supply in a system.
 */
DSDKC_Export DSDKPowerSupplyIterator* enumPowerSupplies(DSDKClient* client, BOOL cached);



/**
 * Power Supply Redundancy Set function table.
 */
struct _DSDKPowerSupplyRedundancySet;
typedef struct _DSDKPowerSupplyRedundancySet DSDKPowerSupplyRedundancySet;


/**
 * @struct DSDKPowerSupplyRedundancySetFT
 * @brief Power supply redundancy set function table 
 */
typedef struct _DSDKPowerSupplyRedundancySetFT
{

	/**
	 * Gets InstsnceID of the powersupply
	 * @param name	InstsnceID of the powersupply
	 * @param max_len	maximum buffer length
	 **/
 	void (*getInstsnceID) (DSDKPowerSupplyRedundancySet* rs, char* ins_id, int max_len);

	/**
	 * Gets the current redundancy status 
	 * @return The current redundancy status.
	 */
	uint16 (*getRedundancyStatus) (DSDKPowerSupplyRedundancySet* rs);
	
	/**
	 * Gets the type of the redundancy set 
	 * @return The type of the redundancy set.
	 */
	void (*getType) (DSDKPowerSupplyRedundancySet* rs, Type_E** type, int max_type);
	
	/**
	 * Returns the minimum number needed 
	 * @return The minumum number 
	 */
	uint32 (*getMinimumNumberNeeded) (DSDKPowerSupplyRedundancySet* rs);

	/**
	 * Gets ElementName of the redundancy set
	 * @param name	InstsnceID of the redundancy set
	 * @param max_len	maximum buffer length
	 **/
 	void (*getElementName) (DSDKPowerSupplyRedundancySet* rs, char* ele_name, int max_len);

	/**
	 * Forces a failover from one power supply to another power supply.
	 * @return The status.
	 */
	uint32 (*failover) (DSDKPowerSupplyRedundancySet* rs, DSDKPowerSupply* ps_from, DSDKPowerSupply* ps_to);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKPowerSupplyRedundancySet* cs);

} DSDKPowerSupplyRedundancySetFT;

struct _DSDKPowerSupplyRedundancySet
{
	void*			hdl;
	DSDKPowerSupplyRedundancySetFT*	ft;
};

/**
 * Power Supply Redundancy Set iterator function table.
 */
struct _DSDKPowerSupplyRedundancySetIterator;
typedef struct _DSDKPowerSupplyRedundancySetIterator DSDKPowerSupplyRedundancySetIterator;

/**
 * @struct DSDKPowerSupplyRedundancySetIteratorFT
 * @brief Power supply redundancy set iterator function table 
 */
typedef struct _DSDKPowerSupplyRedundancySetIteratorFT
{
	/**
	 * Returns the power supply redundancy set at this iterator location.
	 */
	DSDKPowerSupplyRedundancySet* (*getItem) (DSDKPowerSupplyRedundancySetIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKPowerSupplyRedundancySetIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKPowerSupplyRedundancySetIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKPowerSupplyRedundancySetIterator* di);

} DSDKPowerSupplyRedundancySetIteratorFT;

/**
 * @struct _DSDKPowerSupplyRedundancySetIterator 
 * @brief Iterator to iterate through the power supply redudndancy set.
 */
struct _DSDKPowerSupplyRedundancySetIterator
{
	void*					hdl;
	DSDKPowerSupplyRedundancySetIteratorFT*	ft;
};

/**
 * Enumerate all the power supply redudndancy set in a system.
 */
DSDKC_Export DSDKPowerSupplyRedundancySetIterator* 
				enumPowerSupplyRedundancySets (DSDKClient* client, BOOL cached);

#ifdef SWIGIZE
DSDKC_Export void  ps_getSystemCreationClassName (DSDKPowerSupply* ps, char* name, int max_len);
DSDKC_Export void  ps_getSystemName (DSDKPowerSupply* ps, char* name, int max_len);
DSDKC_Export void  ps_getCreationClassName (DSDKPowerSupply* ps, char* name, int max_len);
DSDKC_Export void  ps_getDeviceID (DSDKPowerSupply* ps, char* devid, int max_len);
DSDKC_Export uint32  ps_getTotalPower (DSDKPowerSupply* ps);
DSDKC_Export void  ps_getElementName (DSDKPowerSupply* ps, char* name, int max_len);
DSDKC_Export int  ps_getOperationalStatus (DSDKPowerSupply* ps, uint16* op_status, int max_types);
DSDKC_Export uint16  ps_getHealthState (DSDKPowerSupply* ps);
DSDKC_Export uint16  ps_getEnabledState (DSDKPowerSupply* ps);
DSDKC_Export uint16  ps_getRequestedState (DSDKPowerSupply* ps);
DSDKC_Export void  ps_release (DSDKPowerSupply* ps);
DSDKC_Export DSDKPowerSupply*  psi_getItem (DSDKPowerSupplyIterator* di);
DSDKC_Export void  psi_next (DSDKPowerSupplyIterator* di);
DSDKC_Export BOOL  psi_isEnd (DSDKPowerSupplyIterator* di);
DSDKC_Export void  psi_release (DSDKPowerSupplyIterator* di);
DSDKC_Export void  psrs_getInstsnceID (DSDKPowerSupplyRedundancySet* rs, char* ins_id, int max_len);
DSDKC_Export uint16  psrs_getRedundancyStatus (DSDKPowerSupplyRedundancySet* rs);
DSDKC_Export void  psrs_getType (DSDKPowerSupplyRedundancySet* rs, Type_E** type, int max_type);
DSDKC_Export uint32  psrs_getMinimumNumberNeeded (DSDKPowerSupplyRedundancySet* rs);
DSDKC_Export void  psrs_getElementName (DSDKPowerSupplyRedundancySet* rs, char* ele_name, int max_len);
DSDKC_Export uint32 psrs_failover (DSDKPowerSupplyRedundancySet* rs, DSDKPowerSupply *ps_from, DSDKPowerSupply *ps_to);
DSDKC_Export void  psrs_release (DSDKPowerSupplyRedundancySet* cs);
DSDKC_Export DSDKPowerSupplyRedundancySet*  psrsi_getItem (DSDKPowerSupplyRedundancySetIterator* di);
DSDKC_Export void  psrsi_next (DSDKPowerSupplyRedundancySetIterator* di);
DSDKC_Export BOOL  psrsi_isEnd (DSDKPowerSupplyRedundancySetIterator* di);
DSDKC_Export void  psrsi_release (DSDKPowerSupplyRedundancySetIterator* di);
#endif

#ifdef __cplusplus
}
#endif

#endif /* CDSDK_POWERSUPPLY_H_*/
