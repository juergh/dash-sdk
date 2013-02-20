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
 * @bootconfig_c.h
 * @brief A class representing a boot configuration.
 */
#ifndef __CDSDK_BOOTCONFIG_H__
#define __CDSDK_BOOTCONFIG_H__
#include <dsdk/dsdktypes.h>
#include <dsdkc/capi.h>
#include <dsdkc/computersystem_c.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Boot Device function table.
 */
struct _DSDKBootDevice;
typedef struct _DSDKBootDevice DSDKBootDevice;

/**
 * @struct DSDKBootDeviceFT
 * @brief Boot Device function table 
 */
typedef struct _DSDKBootDeviceFT
{
	/**
	 * Gets theInstanceID
	 * @param ins_id	InstanceID
	 * @param max_len	maximum buffer length
	 */
	 void (*getInstanceID) (DSDKBootDevice* bd, char* ins_id, int max_len);

	/**
	 * Gets the element name 
	 * @param element_name	Bootconfig element name
	 * @param max_len	maximum buffer length
	 */
	void (*getElementName) (DSDKBootDevice* bd, char* element_name, int max_len);

	/**
	 * Gets the BootString
	 * @param inst_id	BootString
	 * @param max_len	maximum buffer length
	 */
	void (*getBootString) (DSDKBootDevice* bd, char* bootstring, int max_len);

	/**
	 * Gets the BIOSBootString
	 * @param caption	BIOSBootString
	 * @param max_len	maximum buffer length
	 */
	void (*getBIOSBootString) (DSDKBootDevice* bd, char* biosbootstring, int max_len);

	/**
	 * Gets the StructuredBootString
	 * @param caption	StructuredBootString
	 * @param max_len	maximum buffer length
	 */
	void (*getStructuredBootString) (DSDKBootDevice* bd, char* str_bootstring, int max_len);

	/**
	 * Gets fail through supported
	 * @return	The fail through suooprted
	 */
	uint16 (*getFailThroughSupported) (DSDKBootDevice* bd);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKBootDevice* bd);

}DSDKBootDeviceFT;

struct _DSDKBootDevice
{
	void*				hdl;
	DSDKBootDeviceFT*	ft;
};

/**
 * Boot Config iterator function table.
 */
struct _DSDKBootDeviceIterator;
typedef struct _DSDKBootDeviceIterator DSDKBootDeviceIterator;

/**
 * @struct DSDKBootConfigIteratorFT
 * @brief Boot Config iterator function table 
 */
typedef struct _DSDKBootDeviceIteratorFT
{
	/**
	 * Returns the software at this iterator location.
	 */
	DSDKBootDevice* (*getItem) (DSDKBootDeviceIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKBootDeviceIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKBootDeviceIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKBootDeviceIterator* di);

} DSDKBootDeviceIteratorFT;

/**
 * @struct _DSDKBootConfigIterator 
 * @brief Iterator to iterate through the boot configurations.
 */
struct _DSDKBootDeviceIterator
{
	void*						hdl;
	DSDKBootDeviceIteratorFT*	ft;
};

/**
 * Enumerate all the boot configurations in a system.
 */
DSDKC_Export DSDKBootDeviceIterator* enumBootDevices (DSDKClient* client, BOOL cached);


/**
 * Boot Config function table.
 */
struct _DSDKBootConfig;
typedef struct _DSDKBootConfig DSDKBootConfig;

/**
 * @struct DSDKBootConfigFT
 * @brief Boot Config function table 
 */
typedef struct _DSDKBootConfigFT
{
	/**
	 * Gets theInstanceID
	 * @param ins_id	InstanceID
	 * @param max_len	maximum buffer length
	 */
	 void (*getInstanceID) (DSDKBootConfig* bc, char* ins_id, int max_len);

	/**
	 * Gets the element name 
	 * @param element_name	Bootconfig element name
	 * @param max_len	maximum buffer length
	 */
	void (*getElementName) (DSDKBootConfig* bc, char* element_name, int max_len);

	/**
	 * Is this default boot configuration 
	 * @return	true if success
	 *			false otherwise
	 */
	BOOL (*isDefaultBoot) (DSDKBootConfig* bc);

	/**
	 * Is this current boot configuration 
	 * @return	true if success
	 *			false otherwise
	 */
	BOOL (*isCurrentBoot) (DSDKBootConfig* bc);

	/**
	 * Is this next boot configuration 
	 * @return	true if success
	 *			false otherwise
	 */
	BOOL (*isNextBoot) (DSDKBootConfig* bc);

	/**
	 * Set this configuration as default configuration
	 */
	void (*setDefaultBoot) (DSDKBootConfig* bc);

	/**
	 * Set this configuration next boot.
	 */
	void (*setNextBoot) (DSDKBootConfig* bc);

	/**
	 * Gets the boot order
	 * @param boot_order	Boot order list
	 * @param max_device	maximum devices
	 */
	int (*getBootOrder) (DSDKBootConfig* bc, DSDKBootDevice** boot_order, 
											  int max_device);

	/**
	 * Change boot order
	 * @param boot_order	changed boot order
	 * @param num_device	maximum buffer length
	 */
	void (*changeBootOrder) (DSDKBootConfig* bc, DSDKBootDevice* boot_order[], int num_device);

	/**
	 * add boot config
	 */
	DSDKBootConfig* (*addBootConfig) (DSDKComputerSystem* cs);

	/**
	 * delete this boot config
	 */
	void (*deleteBootConfig) (DSDKBootConfig* bc);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKBootConfig* cs);

} DSDKBootConfigFT;

struct _DSDKBootConfig
{
	void*				hdl;
	DSDKBootConfigFT*	ft;
};

/**
 * Boot Config iterator function table.
 */
struct _DSDKBootConfigIterator;
typedef struct _DSDKBootConfigIterator DSDKBootConfigIterator;

/**
 * @struct DSDKBootConfigIteratorFT
 * @brief Boot Config iterator function table 
 */
typedef struct _DSDKBootConfigIteratorFT
{
	/**
	 * Returns the software at this iterator location.
	 */
	DSDKBootConfig* (*getItem) (DSDKBootConfigIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKBootConfigIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKBootConfigIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKBootConfigIterator* di);

} DSDKBootConfigIteratorFT;

/**
 * @struct _DSDKBootConfigIterator 
 * @brief Iterator to iterate through the boot configurations.
 */
struct _DSDKBootConfigIterator
{
	void*						hdl;
	DSDKBootConfigIteratorFT*	ft;
};

/**
 * Enumerate all the boot configurations in a system.
 */
DSDKC_Export DSDKBootConfigIterator* enumBootConfigs (DSDKClient* client, BOOL cached);

#ifdef SWIGIZE
DSDKC_Export void  bd_getInstanceID (DSDKBootDevice* bd, char* ins_id, int max_len);
DSDKC_Export void  bd_getElementName (DSDKBootDevice* bd, char* element_name, int max_len);
DSDKC_Export void  bd_getBootString (DSDKBootDevice* bd, char* bootstring, int max_len);
DSDKC_Export void  bd_getBIOSBootString (DSDKBootDevice* bd, char* biosbootstring, int max_len);
DSDKC_Export void  bd_getStructuredBootString (DSDKBootDevice* bd, char* str_bootstring, int max_len);
DSDKC_Export uint16  bd_getFailThroughSupported (DSDKBootDevice* bd);
DSDKC_Export void  bd_release (DSDKBootDevice* bd);
DSDKC_Export DSDKBootDevice*  bdi_getItem (DSDKBootDeviceIterator* di);
DSDKC_Export void  bdi_next (DSDKBootDeviceIterator* di);
DSDKC_Export BOOL  bdi_isEnd (DSDKBootDeviceIterator* di);
DSDKC_Export void  bdi_release (DSDKBootDeviceIterator* di);
DSDKC_Export void  bc_getInstanceID (DSDKBootConfig* bc, char* inst_id, int max_len);
DSDKC_Export void  bc_getElementName (DSDKBootConfig* bc, char* element_name, int max_len);
DSDKC_Export BOOL  bc_isDefaultBoot (DSDKBootConfig* bc);
DSDKC_Export BOOL  bc_isCurrentBoot (DSDKBootConfig* bc);
DSDKC_Export BOOL  bc_isNextBoot (DSDKBootConfig* bc);
DSDKC_Export void  bc_setDefaultBoot (DSDKBootConfig* bc);
DSDKC_Export void  bc_setNextBoot (DSDKBootConfig* bc);
DSDKC_Export int bc_getBootOrder (DSDKBootConfig* bc, DSDKBootDevice** boot_order, int max_device);
DSDKC_Export DSDKBootConfig* bc_addBootConfig (DSDKComputerSystem* cs);
DSDKC_Export void  bc_deleteBootConfig (DSDKBootConfig* bc);
DSDKC_Export void  bc_release (DSDKBootConfig* bc);
DSDKC_Export DSDKBootConfig*  bci_getItem (DSDKBootConfigIterator* di);
DSDKC_Export void  bci_next (DSDKBootConfigIterator* di);
DSDKC_Export BOOL  bci_isEnd (DSDKBootConfigIterator* di);
DSDKC_Export void  bci_release (DSDKBootConfigIterator* di);
#endif

#ifdef __cplusplus
}
#endif

#endif /* CDSDK_BOOTCONFIG_H_*/


