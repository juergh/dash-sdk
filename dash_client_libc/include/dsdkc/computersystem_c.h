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
 * computersystem_c.h
 * A class representing a computer system.
 */
#ifndef __CDSDK_COMPUTERSYSTEM_H__
#define __CDSDK_COMPUTERSYSTEM_H__
#include <dsdk/dsdktypes.h>
#include <dsdkc/capi.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Computer system function table.
 */
struct _DSDKComputerSystem;
typedef struct _DSDKComputerSystem DSDKComputerSystem;


/** 
 * @struct DSDKComputerSystemFT
 * @brief Computer System function table 
 */
typedef struct _DSDKComputerSystemFT
{

	/**
	 * Gets the name of the computer system
	 **/
 	void (*getName) (DSDKComputerSystem* cs, char* name, int max_len);
 	
	/**
	 * Gets the name of the computer system
	 **/
 	void (*getElementName) (DSDKComputerSystem* cs, char* name, int max_len);

 	/**
 	 * Gets the primary owner of the computer system
 	 **/
 	void (*getPrimaryOwner) (DSDKComputerSystem* cs,
 								 char* owner, int max_len);
 	
 	/**
 	 * Returns the primary owner contact of the computer system
 	 **/
 	void (*getPrimaryOwnerContact) (DSDKComputerSystem* cs, 
 								 			char* contact, int max_len);

	/**
 	 * Gets the EnabledState of the computer system
 	 * @return	The EnabledState
 	 **/
 	uint16 (*getEnabledState) (DSDKComputerSystem* cs);

	/**
	 * Gets the enabled state of the computer system as string
	 */
	void (*getEnabledStateStr) (DSDKComputerSystem* cs, char* str, int max_len);

	/**
 	 * Gets the last RequestedState of the computer system
 	 * @return	The RequestedState
 	 **/
 	uint16 (*getRequestedState) (DSDKComputerSystem* cs);

	/**
	 * Gets the last Requested state of the computer system as string
	 */
	void (*getRequestedStateStr) (DSDKComputerSystem* cs, char* str, int max_len);

	/**
	 * Gets the purpose(s) of this computer is dedicated to.
	 * @param dedicated				The dedicated purpose(s) is filled in here.
	 * @param max_dedicated			Maximum dedicated purpose to be filled in dedicated.
	 */
	int (*getDedicated) (DSDKComputerSystem* cs, uint16* dedicated, int max_dedicated);

	/**
	 * Gets the purpose(s) of this computer is dedicated to as string
	 * @param dedicated				The dedicated purpose(s) is filled in here.
	 * @param max_dedicated			Maximum dedicated purpose to be filled in dedicated.
	 * @param max_strlen			Maximum buffer size for dedicated.
	 */
	int (*getDedicatedStr) (DSDKComputerSystem* cs, char** dedicated, int max_dedicated, int max_strlen);

	/**
	 * Gets the current power state of this computer system.
	 **/ 	
 	uint16 (*getPowerState) (DSDKComputerSystem* cs);

	/**
	 * Gets the power state as a string.
	 */
	void (*getPowerStateStr) (DSDKComputerSystem* cs, char* str, int max_len);

	/**
	 * Gets the Requested Power State of this computer system.
	 **/ 	
 	uint16 (*getRequestedPowerState) (DSDKComputerSystem* cs);

	/**
	 * Gets the Requested power state of this computer system as a string.
	 */
	void (*getRequestedPowerStateStr) (DSDKComputerSystem* cs, char* str, int max_len);

	/**
	 * Gets the power change capabilities of this computer system.
	 * @param power_change	The power change capabilities
	 * @param max_types	maximum types
	 */
	int (*getPowerChangeCapabilities) (DSDKComputerSystem* cs, uint16* power_change, int max_types);

	/**
	 * Gets the power change capabilities of this computer system as string
	 * @param capabilities			The power capabilities(s) is filled in here.
	 * @param max_capabilities		Maximum capabilities purpose to be filled in capabilities.
	 * @param max_strlen			Maximum buffer size for capabilities.
	 */
	int (*getPowerChangeCapabilitiesStr) (DSDKComputerSystem* cs, char** capabilities, 
										  int max_capabilities, int max_strlen);

	/**
	 * Gets the power states supported for this computer system.
	 * @param power_states	The power states supported
	 * @param max_types	maximum types
	 */
	int (*getPowerStatesSupported) (DSDKComputerSystem* cs, uint16* power_states, int max_types);

	/**
	 * Gets the power states supported for this computer system.
	 * @param power_states	The power states(s) is filled in here.
	 * @param max_states	Maximum power state to be filled in power_states.
	 * @param max_strlen	Maximum buffer size for power_states.
	 */
	int (*getPowerStatesSupportedStr) (DSDKComputerSystem* cs, char** power_states, int max_states, int max_strlen);

	/**
	 * Power On the computer system
	 **/ 
 	uint32 (*powerOn) (DSDKComputerSystem* cs);
 	
 	/**
 	 * Power off the computer system.
 	 **/
 	uint32 (*powerOff) (DSDKComputerSystem* cs);
 	
 	/**
 	 * PowerCycle the computer system
 	 **/
 	uint32 (*powerCycle) (DSDKComputerSystem* cs);

 	/**
 	 * Power Reset the computer system
 	 **/
	uint32 (*powerReset) (DSDKComputerSystem* cs);

	/**
 	 * Graceful Power reset  the computer system
 	 **/
 	uint32 (*powerResetGraceful) (DSDKComputerSystem* cs);

	/**
	 * Gets the error discription for error returned by power commands
	 **/
	void (*getReqPwrStateChangeErrStr) (DSDKComputerSystem* cs, uint32 err, char* err_str, int max_len);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKComputerSystem* cs);

} DSDKComputerSystemFT;

struct _DSDKComputerSystem
{
	void*					hdl;
	DSDKComputerSystemFT*	ft;
};

/**
 * Computer system iterator function table.
 */
struct _DSDKComputerSystemIterator;
typedef struct _DSDKComputerSystemIterator DSDKComputerSystemIterator;

/**
 * @struct DSDKComputerSystemIteratorFT
 * @brief Computer system iterator function table 
 */
typedef struct _DSDKComputerSystemIteratorFT
{
	/**
	 * Returns the computer system at this iterator location.
	 */
	DSDKComputerSystem* (*getItem) (DSDKComputerSystemIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKComputerSystemIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKComputerSystemIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKComputerSystemIterator* di);

	
	/**
	 * getTestName
	 */
	void (*getTestName) (DSDKComputerSystemIterator* cs, char* name, int max_len);
	

} DSDKComputerSystemIteratorFT;

/**
 * @struct _DSDKComputerSystemIterator 
 * @brief Iterator to iterate through the computer systems.
 */
struct _DSDKComputerSystemIterator
{
	void*							hdl;
	DSDKComputerSystemIteratorFT*	ft;
};

/**
 * Enumerate all the computer systems in a system.
 */
DSDKC_Export DSDKComputerSystemIterator* enumComputerSystems (
											DSDKClient* client, BOOL cached);

#ifdef SWIGIZE
DSDKC_Export uint16  cs_getPowerState (DSDKComputerSystem* cs);
DSDKC_Export void  cs_getPowerStateStr (DSDKComputerSystem* cs, char* ps, int max_len);
DSDKC_Export void  csi_getTestName (DSDKComputerSystemIterator* cs, char* name, int max_len);
DSDKC_Export void  cs_getName (DSDKComputerSystem* cs, char* name, int max_len);
DSDKC_Export void  cs_getPrimaryOwner (DSDKComputerSystem* cs, char* owner, int max_len);
DSDKC_Export void  cs_getPrimaryOwnerContact (DSDKComputerSystem* cs, char* contact, int max_len);
DSDKC_Export uint32  cs_powerOn (DSDKComputerSystem* cs);
DSDKC_Export uint32  cs_powerOff (DSDKComputerSystem* cs);
DSDKC_Export uint32  cs_powerCycle (DSDKComputerSystem* cs);
DSDKC_Export uint32  cs_powerReset (DSDKComputerSystem* cs);
DSDKC_Export uint32 cs_powerResetGraceful (DSDKComputerSystem* cs);
DSDKC_Export void  cs_getReqPwrStateChangeErrStr (DSDKComputerSystem* cs, uint32 err, char* err_str, int max_len);
DSDKC_Export void  cs_release (DSDKComputerSystem* cs);
DSDKC_Export DSDKComputerSystem*  csi_getItem (DSDKComputerSystemIterator* di);
DSDKC_Export void  csi_next (DSDKComputerSystemIterator* di);
DSDKC_Export BOOL  csi_isEnd (DSDKComputerSystemIterator* di);
DSDKC_Export void  csi_release (DSDKComputerSystemIterator* di);
#endif //#ifdef SWIGIZE

#ifdef __cplusplus
}
#endif

#endif /* CDSDK_COMPUTERSYSTEM_H_*/
