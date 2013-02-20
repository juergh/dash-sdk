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
 * textredirection_c.h
 * A class representing a text redirection.
 */
#ifndef __CDSDK_TEXTREDIRECTION_H__
#define __CDSDK_TEXTREDIRECTION_H__
#include <dsdk/dsdktypes.h>
#include <dsdkc/capi.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Text redirection function table.
 */
struct _DSDKTextRedirection;
typedef struct _DSDKTextRedirection DSDKTextRedirection;


/** 
 * @struct DSDKTextRedirectionFT
 * @brief Text Redirection function table 
 */
typedef struct _DSDKTextRedirectionFT
{

	/**
	 * Gets SystemCreationClassName
	 * @return the systemcreationclassname
	 */
	void (*getSystemCreationClassName) (DSDKTextRedirection* tr, char* str, int max_len);

	/**
	 * Gets SystemName
	 * @return the systemname
	 */
	void (*getSystemName) (DSDKTextRedirection* tr, char* str, int max_len);

	/**
	 * Gets the Text redirection name
	 * @param str	The name string
	 * @param max_len	maximum buffer size
	 */
	void (*getName) (DSDKTextRedirection* tr, char* str, int max_len);

	/**
	 * Gets CreationClassName
	 * @ return the creationclassname
	 */
	void (*getCreationClassName) (DSDKTextRedirection* tr, char* str, int max_len);

	/**
	 * Gets ElementName
	 */
	void (*getElementName) (DSDKTextRedirection* tr, char* str, int max_len);

	/**
	 * Gets the state of the text redirection
	 * @return The enabled state
	 */
	uint16 (*getEnabledState) (DSDKTextRedirection* tr);

	/**
 	 * Gets the state of the text redirection as string
 	 * @param state		The Enabled State is filled in
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getEnabledStateStr) (DSDKTextRedirection* tr, char* state, int max_len);

	/**
	 * Gets the requested state of the text redirection
	 * @return The enabled state
	 */
	uint16 (*getRequestedState) (DSDKTextRedirection* tr);

	/**
 	 * Gets the requested status of the text redirection as string
 	 * @param state		The requested state is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getRequestedStateStr) (DSDKTextRedirection* tr, char* state, int max_len);

	/**
	 * Gets the session terminate sequence
	 * @param str The termination sequence string
	 * @param max_len	maximum buffer size
	 */
	void (*getTerminationSequence) (DSDKTextRedirection* tr, char* str, int max_len);
	
	/**
	 * Gets the text flow type
	 * @param str	Teh textflowtype string
	 * @param max_len	maximum buffer size
	 */
	void (*getTextFlowType) (DSDKTextRedirection* tr, char* str, int max_len);
		
	/**
	 * Gets the port number
	 */
	uint32 (*getPortNumber) (DSDKTextRedirection* tr);
	

	/**
	 * Gets protocol interface type
	 * @param str	The protocol interface type
	 * @param max_len	maximim buffer length
	 */
	void (*getProtocolIFType) (DSDKTextRedirection* tr, char* str, int max_len);

	/**
	 * Gets MaxCurrentEnabledSAPs
	 * return the MaxCurrentEnabledSAPs
	 */
	uint16 (*getMaxCurrentEnabledSAPs) (DSDKTextRedirection* tr);
	
	/**
	 * Enable/Activate this redirection session
	 */
	void (*activate) (DSDKTextRedirection* tr);

	/**
	 * Enable this redirection session.
	 */
	void (*enable) (DSDKTextRedirection* tr);

	/** 
	 * Disable this redirection session
	 */
	void (*disable) (DSDKTextRedirection* tr);

	/**
	 * Starts the text redirection
	 */
	void (*startRedirection) (DSDKTextRedirection* tr);
	/**
	 * Releases this object
	 */
	void (*release) (DSDKTextRedirection* tr);

} DSDKTextRedirectionFT;

struct _DSDKTextRedirection
{
	void*					hdl;
	DSDKTextRedirectionFT*	ft;
};

/**
 * Text Redirection iterator function table.
 */
struct _DSDKTextRedirectionIterator;
typedef struct _DSDKTextRedirectionIterator DSDKTextRedirectionIterator;

/**
 * @struct DSDKTextRedirectionIteratorFT
 * @brief Text Redirection iterator function table 
 */
typedef struct _DSDKTextRedirectionIteratorFT
{
	/**
	 * Returns the Text Redirection at this iterator location.
	 */
	DSDKTextRedirection* (*getItem) (DSDKTextRedirectionIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKTextRedirectionIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKTextRedirectionIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKTextRedirectionIterator* di);

} DSDKTextRedirectionIteratorFT;

/**
 * @struct _DSDKTextRedirectionIterator 
 * @brief Iterator to iterate through the TextRedirection.
 */
struct _DSDKTextRedirectionIterator
{
	void*							hdl;
	DSDKTextRedirectionIteratorFT*	ft;
};

/**
 * Enumerate all the Text Redirection in a system.
 */
DSDKC_Export DSDKTextRedirectionIterator* enumTextRedirection (
											DSDKClient* client, BOOL cached);

#ifdef SWIGIZE
//DSDKC_Export  void tr_getStatus (DSDKTextRedirection* tr, char* status, int max_len);
DSDKC_Export void tr_getSystemCreationClassName (DSDKTextRedirection* tr, char* name, int max_len);
DSDKC_Export void tr_getSystemName (DSDKTextRedirection* tr, char* name, int max_len);
DSDKC_Export void tr_getName (DSDKTextRedirection* tr, char* name, int max_len);
DSDKC_Export void tr_getCreationClassName(DSDKTextRedirection* tr, char* name, int max_len);
DSDKC_Export void tr_getElementName (DSDKTextRedirection* tr, char* name, int max_len);
DSDKC_Export uint16 tr_getEnabledState(DSDKTextRedirection* tr);
DSDKC_Export uint16 tr_getRequestedState(DSDKTextRedirection* tr);
DSDKC_Export void tr_getTerminationSequence (DSDKTextRedirection* tr, char* name, int max_len);
DSDKC_Export void tr_getTextFlowType (DSDKTextRedirection* tr, char* name, int max_len);
DSDKC_Export uint32 tr_getPortNumber (DSDKTextRedirection* tr);
DSDKC_Export void tr_getProtocolIFType (DSDKTextRedirection* tr, char* ptype, int max_len);
DSDKC_Export uint16 tr_getMaxCurrentEnabledSAPs (DSDKTextRedirection* tr);
DSDKC_Export void tr_activate (DSDKTextRedirection* tr);
DSDKC_Export void tr_enable (DSDKTextRedirection* tr);
DSDKC_Export void tr_disable (DSDKTextRedirection* tr);
DSDKC_Export void tr_startRedirection (DSDKTextRedirection* tr);
DSDKC_Export void tr_release (DSDKTextRedirection* tr);
DSDKC_Export DSDKTextRedirection* tri_getItem (DSDKTextRedirectionIterator* di);
DSDKC_Export void tri_next (DSDKTextRedirectionIterator* di);
DSDKC_Export BOOL tri_isEnd (DSDKTextRedirectionIterator* di);
DSDKC_Export void tri_release (DSDKTextRedirectionIterator* di);
#endif //#ifdef SWIGIZE

#ifdef __cplusplus
}
#endif

#endif /* CDSDK_TEXTREDIRECTION_H_*/




	
