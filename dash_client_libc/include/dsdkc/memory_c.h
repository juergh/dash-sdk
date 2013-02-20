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
 * memory_c.h
 * A class representing a  memory.
 */
#ifndef __CDSDK_MEMORY_H__
#define __CDSDK_MEMORY_H__
#include <dsdk/dsdktypes.h>
#include <dsdkc/capi.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 *  Memory function table.
 */
struct _DSDKMemory;
typedef struct _DSDKMemory DSDKMemory;


/**
 * @struct DSDKMemoryFT
 * @brief  Memory function table 
 */
typedef struct _DSDKMemoryFT
{
	/**
	 * Gets the memory System Creation class Name 
	 * @param name	Creation Class Name of the memory
	 * @param max_len	maximum buffer length
	 */
	void (*getSystemCreationClassName) (DSDKMemory* pm, char* name, int max_len);

	/**
	 * Gets SystemName of the memory
	 * @param name	system Name of the memory
	 * @param max_len	maximum buffer length
	 **/
 	void (*getSystemName) (DSDKMemory* pm, char* name, int max_len);

	/**
	 * Gets the memory Creation class Name 
	 * @param name	Creation Class Name of the memory
	 * @param max_len	maximum buffer length
	 */
	void (*getCreationClassName) (DSDKMemory* pm, char* name, int max_len);

	/**
	 * Gets the memory Device ID 
	 * @param name	CDevice ID of the memory
	 * @param max_len	maximum buffer length
	 */
	void (*getDeviceID) (DSDKMemory* pm, char* dev_id, int max_len);

	/**
	 * Returns true if the memory is volatile 
	 * @return	true if the memory is volatile
	 * 		false otherwise
	 */
	BOOL (*isVolatile) (DSDKMemory* pm);

	/**
	 * Gets the memory access type Ex (Read/Write etc).
	 * @return The memory access.
	 */
	uint16 (*getAccess) (DSDKMemory* pm);

	/**
	 * Gets the memory access type as string.
	 * @param access	Access type
	 * @param max_len	maximum buffer length
	 */
	void (*getAccessStr) (DSDKMemory* pm, char* access, int max_len);

	/**
	 * Gets the BlockSize of memory
	 * @return The memory BlockSize.
	 */
	uint64 (*getBlockSize) (DSDKMemory* pm);

	/**
	 * Gets the NumberOfBlocks of memory
	 * @return The memory NumberOfBlocks.
	 */
	uint64 (*getNumberOfBlocks) (DSDKMemory* pm);

	/**
	 * Gets the ConsumableBlocks of memory
	 * @return The memory ConsumableBlocks
	 */
	uint64 (*getConsumableBlocks) (DSDKMemory* pm);

	/**
	 * Gets the EnabledState of the memory
	 * @return The EnabledState
	 */
	uint16 (*getEnabledState) (DSDKMemory* pm);

	/**
 	 * Gets the state of the memory as string
 	 * @param state		The Enabled State is filled in
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getEnabledStateStr) (DSDKMemory* pm, char* state, int max_len);

	/**
	 * Gets the last RequestedState of the memory
	 * @return The RequestedState 
	 */
	uint16 (*getRequestedState) (DSDKMemory* pm);

	/**
 	 * Gets the requested status of the memory as string
 	 * @param state		The requested state is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getRequestedStateStr) (DSDKMemory* pm, char* state, int max_len);

	/**
	 * Gets the OperationalStatus
	 * @param op_status	Operational Status
	 * @param max_types	maximum types
	 */
	int (*getOperationalStatus) (DSDKMemory* pm, uint16* op_status, int max_types);

	/**
	 * Gets the list of operational status
	 * @param os			The operational status is filled in.
	 * @param max_os		maximum number of operational status
	 * @param max_strlen	maximum buffer size
	 */
	int (*getOperationalStatusStr) (DSDKMemory* pm, char** os, int max_os, int max_strlen);

	/**
	 * Gets the HealthState of the memory
	 * @return The HealthState 
	 */
	uint16 (*getHealthState) (DSDKMemory* pm);

	/**
 	 * Gets the health state of the memory as string
 	 * @param state		The health state is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getHealthStateStr) (DSDKMemory* pm, char* state, int max_len);

	/**
	 * Gets Element Name of the memory
	 * @param ele_name	ElementName of the memory
	 * @param max_len	maximum buffer length
	 **/
 	void (*getElementName) (DSDKMemory* pm, char* ele_name, int max_len);


	/**
	 * Releases this object
	 */
	void (*release) (DSDKMemory* cs);

} DSDKMemoryFT;

struct _DSDKMemory
{
	void*					hdl;
	DSDKMemoryFT*	ft;
};

/**
 *  memory iterator function table.
 */
struct _DSDKMemoryIterator;
typedef struct _DSDKMemoryIterator DSDKMemoryIterator;

/**
 * @struct DSDKMemoryIteratorFT
 * @brief  Memory iterator function table 
 */
typedef struct _DSDKMemoryIteratorFT
{
	/**
	 * Returns the  memory at this iterator location.
	 */
	DSDKMemory* (*getItem) (DSDKMemoryIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKMemoryIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKMemoryIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKMemoryIterator* di);

} DSDKMemoryIteratorFT;

/**
 * @struct _DSDKMemoryIterator 
 * @brief Iterator to iterate through the  memorys.
 */
struct _DSDKMemoryIterator
{
	void*							hdl;
	DSDKMemoryIteratorFT*	ft;
};

/**
 * Enumerate all the  memory in a system.
 */
DSDKC_Export DSDKMemoryIterator* enumMemory (
											DSDKClient* client, BOOL cached);

#ifdef SWIGIZE
DSDKC_Export void  pm_getSystemCreationClassName (DSDKMemory* pm, char* name, int max_len);
DSDKC_Export void  pm_getSystemName (DSDKMemory* pm, char* name, int max_len);
DSDKC_Export void  pm_getCreationClassName (DSDKMemory* pm, char* name, int max_len);
DSDKC_Export void  pm_getDeviceID (DSDKMemory* pm, char* dev_id, int max_len);
DSDKC_Export BOOL  pm_isVolatile (DSDKMemory* pm);
DSDKC_Export uint16  pm_getAccess (DSDKMemory* pm);
DSDKC_Export uint64  pm_getBlockSize (DSDKMemory* pm);
DSDKC_Export uint64  pm_getNumberOfBlocks (DSDKMemory* pm);
DSDKC_Export uint64  pm_getConsumableBlocks (DSDKMemory* pm);
DSDKC_Export uint16 pm_getEnabledState (DSDKMemory* pm);
DSDKC_Export uint16 pm_getRequestedState (DSDKMemory* pm);
DSDKC_Export int  pm_getOperationalStatus (DSDKMemory* pm, uint16* op_status, int max_types);
DSDKC_Export uint16  pm_getHealthState (DSDKMemory* pm);
DSDKC_Export void  pm_getElementName (DSDKMemory* pm, char* ele_name, int max_len);
DSDKC_Export void  pm_release (DSDKMemory* pm);
DSDKC_Export DSDKMemory*  pmi_getItem (DSDKMemoryIterator* di);
DSDKC_Export void  pmi_next (DSDKMemoryIterator* di);
DSDKC_Export BOOL  pmi_isEnd (DSDKMemoryIterator* di);
DSDKC_Export void  pmi_release (DSDKMemoryIterator* di);
#endif

#ifdef __cplusplus
}
#endif

#endif /* __CDSDK_SOFTWARE_H__*/
