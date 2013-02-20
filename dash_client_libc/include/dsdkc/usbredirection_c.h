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
 * usbredirection_c.h
 * A class representing a usb redirection.
 */
#ifndef __CDSDK_USBREDIRECTION_H__
#define __CDSDK_USBREDIRECTION_H__
#include <dsdk/dsdktypes.h>
#include <dsdkc/capi.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * USBRedirection function table.
 */
struct _DSDKUSBRedirection;
typedef struct _DSDKUSBRedirection DSDKUSBRedirection;


/** 
 * @struct DSDKUSBRedirectionFT
 * @brief USB Redirection function table 
 */
typedef struct _DSDKUSBRedirectionFT
{
	
	/**
	 * Gets SystemCreationClassName
	 * @return the systemcreationclassname
	 */
	void (*getSystemCreationClassName) (DSDKUSBRedirection* usbr, char* str, int max_len);

	/**
	 * Gets SystemName
	 * @return the systemname
	 */
	void (*getSystemName) (DSDKUSBRedirection* usbr, char* str, int max_len);

	/**
	 * Gets the Text redirection name
	 * @param str	The name string
	 * @param max_len	maximum buffer size
	 */
	void (*getName) (DSDKUSBRedirection* usbr, char* str, int max_len);

	/**
	 * Gets CreationClassName
	 * @ return the creationclassname
	 */
	void (*getCreationClassName) (DSDKUSBRedirection* usbr, char* str, int max_len);

	/**
	 * Gets ElementName
	 */
	void (*getElementName) (DSDKUSBRedirection* usbr, char* str, int max_len);

	/**
	 * Gets the state of the usb redirection
	 * @return The enabled state
	 */
	uint16 (*getEnabledState) (DSDKUSBRedirection* usbr);

	/**
 	 * Gets the state of the usb redirection as string
 	 * @param state		The Enabled State is filled in
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getEnabledStateStr) (DSDKUSBRedirection* usbr, char* state, int max_len);

	/**
	 * Gets the requested state of the usb redirection
	 * @return The enabled state
	 */
	uint16 (*getRequestedState) (DSDKUSBRedirection* usbr);

	/**
 	 * Gets the requested status of the usb redirection as string
 	 * @param state		The requested state is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getRequestedStateStr) (DSDKUSBRedirection* usbr, char* state, int max_len);

	/**
	 * Gets the connection mode
	 * @param cmode The connection mode
	 * @param max_len	maximum buffer length
	 */
	void (*getConnectionMode) (DSDKUSBRedirection* usbr, char* cmode, int max_len);

	/**
	 * Enable/Activate this redirection session
	 */
	void (*activate) (DSDKUSBRedirection* usbr);

	/**
	 * Enable this redirection session.
	 */
	void (*enable) (DSDKUSBRedirection* usbr);

	/** 
	 * Disable this redirection session
	 */
	void (*disable) (DSDKUSBRedirection* usbr);

	/** 
	 * Starts the NFS/Samba share redirection. 
	 */
	int (*startFolderRedirection) (DSDKUSBRedirection* usbr, char* path);
	
	/**
	 * Releases this object
	 */
	void (*release) (DSDKUSBRedirection* usbr);

} DSDKUSBRedirectionFT;

struct _DSDKUSBRedirection
{
	void*					hdl;
	DSDKUSBRedirectionFT*	ft;
};

/**
 * USBRedirection iterator function table.
 */
struct _DSDKUSBRedirectionIterator;
typedef struct _DSDKUSBRedirectionIterator DSDKUSBRedirectionIterator;

/**
 * @struct DSDKUSBRedirectionIteratorFT
 * @brief USBRedirection iterator function table 
 */
typedef struct _DSDKUSBRedirectionIteratorFT
{
	/**
	 * Returns the USBRedirection at this iterator location.
	 */
	DSDKUSBRedirection* (*getItem) (DSDKUSBRedirectionIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKUSBRedirectionIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKUSBRedirectionIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKUSBRedirectionIterator* di);

} DSDKUSBRedirectionIteratorFT;

/**
 * @struct _DSDKUSBRedirectionIterator 
 * @brief Iterator to iterate through the USBRedirection.
 */
struct _DSDKUSBRedirectionIterator
{
	void*							hdl;
	DSDKUSBRedirectionIteratorFT*	ft;
};

/**
 * Enumerate all the USBRedirection .
 */
DSDKC_Export DSDKUSBRedirectionIterator* enumUSBRedirection (DSDKClient* client, BOOL cached);

#ifdef SWIGIZE
DSDKC_Export void usbr_getSystemCreationClassName (DSDKUSBRedirection* usbr, char* name, int max_len);
DSDKC_Export void usbr_getSystemName (DSDKUSBRedirection* usbr, char* name, int max_len);
DSDKC_Export void usbr_getName (DSDKUSBRedirection* usbr, char* name, int max_len);
DSDKC_Export void usbr_getCreationClassName(DSDKUSBRedirection* usbr, char* name, int max_len);
DSDKC_Export void usbr_getElementName (DSDKUSBRedirection* usbr, char* name, int max_len);
DSDKC_Export uint16 usbr_getEnabledState(DSDKUSBRedirection* usbr);
DSDKC_Export void usbr_getEnabledStateStr (DSDKUSBRedirection* tr, char* state, int max_len);
DSDKC_Export uint16 usbr_getRequestedState(DSDKUSBRedirection* usbr);
DSDKC_Export void usbr_getRequestedStateStr (DSDKUSBRedirection* tr, char* state, int max_len);
DSDKC_Export void usbr_getConnectionMode (DSDKUSBRedirection* usbr, char* cmode, int max_len);
DSDKC_Export void usbr_activate (DSDKUSBRedirection* usbr);
DSDKC_Export void usbr_disable (DSDKUSBRedirection* usbr);
DSDKC_Export void usbr_release (DSDKUSBRedirection* usbr);
DSDKC_Export int usbr_startFolderRedirection (DSDKUSBRedirection* usbr, char* path);
DSDKC_Export DSDKUSBRedirection* usbri_getItem (DSDKUSBRedirectionIterator* di);
DSDKC_Export void usbri_next (DSDKUSBRedirectionIterator* di);
DSDKC_Export BOOL usbri_isEnd (DSDKUSBRedirectionIterator* di);
DSDKC_Export void usbri_release (DSDKUSBRedirectionIterator* di);
#endif //#ifdef SWIGIZE




#ifdef __cplusplus
}
#endif

#endif /* CDSDK_USBREDIRECTION_H_*/

