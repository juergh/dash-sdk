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
 * processot_c.h
 * A class representing a processor installed.
 */
#ifndef __CDSDK_PROCESSOR_H__
#define __CDSDK_PROCESSOR_H__
#include <dsdk/dsdktypes.h>
#include <dsdkc/capi.h>
#include <dsdkc/computersystem_c.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Processor Core function table.
 */
struct _DSDKProcessorCore;
typedef struct _DSDKProcessorCore DSDKProcessorCore;


/**
 * @struct DSDKProcessorCoreFT
 * @brief Processor Core function table 
 */
typedef struct _DSDKProcessorCoreFT
{
	/**
 	 * Gets the instance ID of the processor Core 
 	 * @param instid	The Instance ID
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getInstanceID) (DSDKProcessorCore* pc, char* instid, int max_len);

	/**
	 * Gets the Core Enabled state of  processor Core 
	 * @return The Core Enabled state
	 **/
	uint16 (*getCoreEnabledState)  (DSDKProcessorCore* pc);

	/**
	 * Gets the Enabled state of  processor Core 
	 * @return The Enabled state
	 **/
	uint16 (*getEnabledState)  (DSDKProcessorCore* pc);

	/**
 	 * Gets the load percentage of this processor core 
 	 * @return The load percentage of this processor core.
 	 **/
 	uint16 (*getLoadPercentage) (DSDKProcessorCore* pc);

	/**
	 * Gets the Requested State state of  processor Core 
	 * @return The Requested State
	 **/
	uint16 (*getRequestedState)  (DSDKProcessorCore* pc);

	/**
	 * Gets the OperationalStatus
	 * @param op_status	Operational Status
	 * @param max_types	maximum types
	 */
	int (*getOperationalStatus) (DSDKProcessorCore* pc, uint16* op_status, int max_types);

	/**
	 * Gets the health state of the processor
	 * @return The health state
	 */
	uint16 (*getHealthState) (DSDKProcessorCore* pc);

	/**
 	 * Gets the Element Name of the processor Core 
 	 * @param name	The Element Name
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getElementName) (DSDKProcessorCore* pc, char* name, int max_len);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKProcessorCore* cs);

} DSDKProcessorCoreFT;

struct _DSDKProcessorCore
{
	void*					hdl;
	DSDKProcessorCoreFT*	ft;
};

/**
 * Processor Core iterator function table.
 */
struct _DSDKProcessorCoreIterator;
typedef struct _DSDKProcessorCoreIterator DSDKProcessorCoreIterator;

/**
 * @struct DSDKProcessorCoreIteratorFT
 * @brief Processor Core iterator function table 
 */
typedef struct _DSDKProcessorCoreIteratorFT
{
	/**
	 * Returns the Processor Core at this iterator location.
	 */
	DSDKProcessorCore* (*getItem) (DSDKProcessorCoreIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKProcessorCoreIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKProcessorCoreIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKProcessorCoreIterator* di);

} DSDKProcessorCoreIteratorFT;

/**
 * @struct _DSDKProcessorCoreIterator 
 * @brief Iterator to iterate through the Processor Cores.
 */
struct _DSDKProcessorCoreIterator
{
	void*							hdl;
	DSDKProcessorCoreIteratorFT*	ft;
};

/**
 * Enumerate all the Processor cores in a system.
 */
DSDKC_Export DSDKProcessorCoreIterator* enumProcessorCores (
											DSDKClient* client, BOOL cached);

/**
 * Processor function table.
 */
struct _DSDKProcessor;
typedef struct _DSDKProcessor DSDKProcessor;


/**
 * @struct DSDKProcessorFT
 * @brief Processor function table 
 */
typedef struct _DSDKProcessorFT
{
	/**
	 * Gets the processor System Creation class Name 
	 * @param name	Creation Class Name of the processor
	 * @param max_len	maximum buffer length
	 */
	void (*getSystemCreationClassName) (DSDKProcessor* proc, char* name, int max_len);

	/**
	 * Gets SystemName of the processor
	 * @param name	system Name of the processor
	 * @param max_len	maximum buffer length
	 **/
 	void (*getSystemName) (DSDKProcessor* proc, char* name, int max_len);

	/**
	 * Gets the processor Creation class Name 
	 * @param name	Creation Class Name of the processor
	 * @param max_len	maximum buffer length
	 */
	void (*getCreationClassName) (DSDKProcessor* proc, char* name, int max_len);

	/**
	 * Gets the processor device id. 
	 * @return The processor device id.
	 */
	void (*getDeviceID) (DSDKProcessor* proc, char* dev_id, int max_len);

	/**
	 * Gets the processor family 
	 * @return The processor family.
	 */
	void (*getFamily) (DSDKProcessor* proc, char* method, int max_len);

	/**
 	 * Gets the current clock speed 
 	 * @return The current clock speed in Mhz
 	 */
 	uint32 (*getCurrentClockSpeed) (DSDKProcessor* proc);

	/**
 	 * Gets the maximum clock speed 
 	 * @return The maximum clock speed in Mhz.
 	 */
 	uint32 (*getMaxClockSpeed) (DSDKProcessor* proc);

	/**
 	 * Gets the external bus clock speed 
 	 * @return The external bus clock speed.
 	 */
 	uint32 (*getExternalBusClockSpeed) (DSDKProcessor* proc);

	/**
 	 * Gets the CPU Status 
 	 * @return The CPU Status .
 	 */
 	uint16 (*getCPUStatus) (DSDKProcessor* proc);

	/**
 	 * Gets the CPU status of the processor as string
 	 * @param status	The Status of cpu is filled in
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getCPUStatusStr) (DSDKProcessor* proc, char* status, int max_len);

	/**
 	 * Gets load of this processor in the last minute 
 	 * @return The load percentage 
 	 */
 	uint32 (*getLoadPercentage) (DSDKProcessor* proc);

	/**
	 * Gets the state of the processor
	 * @return The enabled state
	 */
	uint16 (*getEnabledState) (DSDKProcessor* proc);

	/**
 	 * Gets the state of the processor as string
 	 * @param state		The Enabled State is filled in
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getEnabledStateStr) (DSDKProcessor* proc, char* state, int max_len);

	/**
	 * Gets the requested state of the processor
	 * @return The enabled state
	 */
	uint16 (*getRequestedState) (DSDKProcessor* proc);

	/**
 	 * Gets the requested status of the processor as string
 	 * @param state		The requested state is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getRequestedStateStr) (DSDKProcessor* proc, char* state, int max_len);

	/**
	 * Gets the list of OperationalStatus
	 * @param op_status	Operational Status
	 * @param max_types	maximum types
	 */
	int (*getOperationalStatus) (DSDKProcessor* proc, uint16* op_status, int max_types);

	/**
	 * Gets the list of operational status
	 * @param os			The operational status is filled in.
	 * @param max_os		maximum number of operational status
	 * @param max_strlen	maximum buffer size
	 */
	int (*getOperationalStatusStr) (DSDKProcessor* proc, char** os, int max_os, int max_strlen);

	/**
	 * Gets the health state of the processor
	 * @return The health state
	 */
	uint16 (*getHealthState) (DSDKProcessor* proc);

	/**
 	 * Gets the health state of the processor as string
 	 * @param state		The health state is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getHealthStateStr) (DSDKProcessor* proc, char* state, int max_len);

	/**
 	 * Gets the Element Name of the processor 
 	 * @param name	The Element Name
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getElementName) (DSDKProcessor* proc, char* name, int max_len);

	/**
 	 * Gets the Other FamilyD escription of the processor 
 	 * @param name	The OtherFamilyDescription
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getOtherFamilyDescription) (DSDKProcessor* proc, char* desc, int max_len);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKProcessor* proc);

} DSDKProcessorFT;

struct _DSDKProcessor
{
	void*				hdl;
	DSDKProcessorFT*	ft;
};

/**
 * Processor iterator function table.
 */
struct _DSDKProcessorIterator;
typedef struct _DSDKProcessorIterator DSDKProcessorIterator;

/**
 * @struct DSDKProcessorIteratorFT
 * @brief Processor iterator function table 
 */
typedef struct _DSDKProcessorIteratorFT
{
	/**
	 * Returns the processor at this iterator location.
	 */
	DSDKProcessor* (*getItem) (DSDKProcessorIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKProcessorIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKProcessorIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKProcessorIterator* di);

} DSDKProcessorIteratorFT;

/**
 * @struct _DSDKProcessorIterator 
 * @brief Iterator to iterate through the processors.
 */
struct _DSDKProcessorIterator
{
	void*						hdl;
	DSDKProcessorIteratorFT*	ft;
};

/**
 * Enumerate all the processors in a system.
 */
DSDKC_Export DSDKProcessorIterator* enumProcessors (
											DSDKClient* client, BOOL cached);

/**
 * Enumerate all the processors in a given ComputerSystem.
 */
DSDKC_Export DSDKProcessorIterator* enumComputerSystemProcessors (DSDKClient* client, DSDKComputerSystem* cs);

#ifdef SWIGIZE
DSDKC_Export void  pc_getInstanceID (DSDKProcessorCore* pc, char* instid, int max_len);
DSDKC_Export uint16  pc_getCoreEnabledState (DSDKProcessorCore* pc);
DSDKC_Export uint16  pc_getEnabledState (DSDKProcessorCore* pc);
DSDKC_Export uint16  pc_getLoadPercentage (DSDKProcessorCore* pc);
DSDKC_Export uint16  pc_getRequestedState (DSDKProcessorCore* pc);
DSDKC_Export int  pc_getOperationalStatus (DSDKProcessorCore* pc, uint16* op_status, int max_types);
DSDKC_Export uint16  pc_getHealthState (DSDKProcessorCore* pc);
DSDKC_Export void  pc_getElementName (DSDKProcessorCore* pc, char* name, int max_len);
DSDKC_Export void  pc_release (DSDKProcessorCore* pc);
DSDKC_Export DSDKProcessorCore*  pci_getItem (DSDKProcessorCoreIterator* di);
DSDKC_Export void  pci_next (DSDKProcessorCoreIterator* di);
DSDKC_Export BOOL  pci_isEnd (DSDKProcessorCoreIterator* di);
DSDKC_Export void  pci_release (DSDKProcessorCoreIterator* di);
DSDKC_Export void  proc_getDeviceID (DSDKProcessor* proc, char* dev_id, int max_len);
DSDKC_Export void  proc_getFamily (DSDKProcessor* proc, char* fmaily, int max_len);
DSDKC_Export uint32  proc_getCurrentClockSpeed (DSDKProcessor* proc);
DSDKC_Export uint32  proc_getMaxClockSpeed (DSDKProcessor* proc);
DSDKC_Export uint32  proc_getExternalBusClockSpeed (DSDKProcessor* proc);
DSDKC_Export uint16  proc_getCPUStatus (DSDKProcessor* proc);
DSDKC_Export uint32  proc_getLoadPercentage (DSDKProcessor* proc);
DSDKC_Export uint16  proc_getEnabledState (DSDKProcessor* proc);
DSDKC_Export uint16  proc_getRequestedState (DSDKProcessor* proc);
DSDKC_Export int  proc_getOperationalStatus (DSDKProcessor* proc, uint16* op_status, int max_len);
DSDKC_Export uint16  proc_getHealthState (DSDKProcessor* proc);
DSDKC_Export void  proc_getElementName (DSDKProcessor* proc, char* name, int max_len);
DSDKC_Export void  proc_getOtherFamilyDescription (DSDKProcessor* proc, char* desc, int max_len);
DSDKC_Export void  proc_release (DSDKProcessor* proc);
DSDKC_Export DSDKProcessor*  proci_getItem (DSDKProcessorIterator* di);
DSDKC_Export void  proci_next (DSDKProcessorIterator* di);
DSDKC_Export BOOL  proci_isEnd (DSDKProcessorIterator* di);
DSDKC_Export void  proci_release (DSDKProcessorIterator* di);
#endif // #ifdef SWIGIZE

#ifdef __cplusplus
}
#endif

#endif /* __CDSDK_PROCESSOR_H__*/
