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
 * operatingsystem_c.h
 * A class representing a operating system.
 */
#ifndef __CDSDK_OPERATINGSYSTEM_H__
#define __CDSDK_OPERATINGSYSTEM_H__
#include <dsdk/dsdktypes.h>
#include <dsdkc/capi.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Operating system function table.
 */
struct _DSDKOperatingSystem;
typedef struct _DSDKOperatingSystem DSDKOperatingSystem;

/** 
 * @struct DSDKOperatingSystemFT
 * @brief Operating System function table 
 */
typedef struct _DSDKOperatingSystemFT
{

	/**
	 * Gets name of the CSCreationClassName
	 * @param nsme	The CSClassName
	 * @param max_len	maximum buffer length
	 **/
	void (*getCSCreationClassName) (DSDKOperatingSystem* os, char* name, int max_len);

	/**
	 * Gets name of the CSName
	 * @param nsme	The CSName
	 * @param max_len	maximum buffer length
	 **/
	void (*getCSName) (DSDKOperatingSystem* os, char* name, int max_len);

	/**
	 * Gets name of the CreationClassName
	 * @param nsme	The CreationClassName
	 * @param max_len	maximum buffer length
	 **/
	void (*getCreationClassName) (DSDKOperatingSystem* os, char* name, int max_len);

	/**
	 * Gets the Operating System Name.
	 * @param name	Operating system name
	 * @param max_len	maximum buffer length
	 **/ 	
 	void (*getName) (DSDKOperatingSystem* os, char* name, int max_len);


	/**
	 * Gets the operating system type
	 * @param type	operating system type
	 * @param max_len	maximum buffer length
	 */
	void (*getOStype) (DSDKOperatingSystem* os, char* type, int max_len);

	/**
	 * Gets the operating system type Description
	 * @param type	operating system type Description
	 * @param max_len	maximum buffer length
	 */
	void (*getOtherTypeDescription) (DSDKOperatingSystem* os, char* type, int max_len);

	/**
	 * Gets the EnabledState of the os
	 * @return The EnabledState
	 */
	uint16 (*getEnabledState) (DSDKOperatingSystem* os);

	/**
 	 * Gets the state of the os as string
 	 * @param state		The Enabled State is filled in
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getEnabledStateStr) (DSDKOperatingSystem* os, char* state, int max_len);

	/**
	 * Gets the last RequestedState of the os
	 * @return The RequestedState 
	 */
	uint16 (*getRequestedState) (DSDKOperatingSystem* os);

	/**
 	 * Gets the requested status of the os as string
 	 * @param state		The requested state is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getRequestedStateStr) (DSDKOperatingSystem* os, char* state, int max_len);

	/**
	 * Gets the available requested states of the operating system
	 * @param req_states	available requested states
	 * @param max_types	maximum types
	 */
	int (*getAvailableRequestedStates) (DSDKOperatingSystem* os, uint16* req_states, int max_types);

	/**
	 * Gets the available resquested state
	 * @param states		available requested states
	 * @param max_states	maximum states
	 */
	int (*getAvailableRequestedStatesStr) (DSDKOperatingSystem* os, char** states, int max_states, int max_strlen);

	/**
	 * Gets the transitioning state of operating system
	 * @return	The transitioning state of operating system
	 */
	uint16 (*getTransitioningToState) (DSDKOperatingSystem* os);

	/**
 	 * Gets Gets the transitioning state of operating system as string
 	 * @param state		The transitioning state
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getTransitioningToStateStr) (DSDKOperatingSystem* os, char* state, int max_len);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKOperatingSystem* os);

}DSDKOperatingSystemFT;

struct _DSDKOperatingSystem
{
	void*					hdl;
	DSDKOperatingSystemFT*	ft;
};


/**
 * Operating system iterator function table.
 */
struct _DSDKOperatingSystemIterator;
typedef struct _DSDKOperatingSystemIterator DSDKOperatingSystemIterator;

/**
 * @struct DSDKOperatingSystemIteratorFT
 * @brief Operating System iterator function table 
 */
typedef struct _DSDKOperatingSystemIteratorFT
{
	/**
	 * Returns the Operating System at this iterator location.
	 */
	DSDKOperatingSystem* (*getItem) (DSDKOperatingSystemIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKOperatingSystemIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKOperatingSystemIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKOperatingSystemIterator* di);

} DSDKOperatingSystemIteratorFT;

/**
 * @struct _DSDKOperatingSystemIterator 
 * @brief Iterator to iterate through the operating systems.
 */
struct _DSDKOperatingSystemIterator
{
	void*							hdl;
	DSDKOperatingSystemIteratorFT*	ft;
};

/**
 * Enumerate all the Operating System in a system.
 */
DSDKC_Export DSDKOperatingSystemIterator* enumOperatingSystem (
											DSDKClient* client, BOOL cached);

#ifdef SWIGIZE
//DSDKC_Export  void os_getVersion (DSDKOperatingSystem* os, char* version, int max_len);
//DSDKC_Export  void os_getStatus (DSDKOperatingSystem* os, char* status, int max_len);
DSDKC_Export void  os_getCSCreationClassName (DSDKOperatingSystem* os, char* name, int max_len);
DSDKC_Export void  os_getCSName (DSDKOperatingSystem* os, char* name, int max_len);
DSDKC_Export void  os_getCreationClassName (DSDKOperatingSystem* os, char* name, int max_len);
DSDKC_Export void  os_getName (DSDKOperatingSystem* os, char* name, int max_len);
DSDKC_Export void  os_getOSType (DSDKOperatingSystem* os, char* type, int max_len);
DSDKC_Export uint16  os_getEnabledState (DSDKOperatingSystem* os);
DSDKC_Export uint16  os_getRequestedState (DSDKOperatingSystem* os);
DSDKC_Export int  os_getAvailableRequestedStates (DSDKOperatingSystem* os, uint16* req_states, int max_types);
DSDKC_Export uint16  os_getTransitioningToState (DSDKOperatingSystem* os);
DSDKC_Export void  os_release (DSDKOperatingSystem* os);
DSDKC_Export DSDKOperatingSystem*  osi_getItem (DSDKOperatingSystemIterator* di);
DSDKC_Export void  osi_next (DSDKOperatingSystemIterator* di);
DSDKC_Export BOOL  osi_isEnd (DSDKOperatingSystemIterator* di);
DSDKC_Export void  osi_release (DSDKOperatingSystemIterator* di);
#endif //#ifdef SWIGIZE

#ifdef __cplusplus
}
#endif

#endif /* CDSDK_OPERATINGSYSTEM_H_*/



