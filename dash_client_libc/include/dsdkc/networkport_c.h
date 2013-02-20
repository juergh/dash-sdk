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
 * networkport_c.h
 * A class representing a network port.
 */
#ifndef __CDSDK_NETWORKPORT_H__
#define __CDSDK_NETWORKPORT_H__
#include <dsdk/dsdktypes.h>
#include <dsdkc/capi.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Network Port function table.
 */
struct _DSDKNetworkPort;
typedef struct _DSDKNetworkPort DSDKNetworkPort;

/** 
 * @struct DSDKNetworkPortFT
 * @brief Network Port function table 
 */
typedef struct _DSDKNetworkPortFT
{

	/**
	 * Gets the networkport System Creation class Name 
	 * @param name	Creation Class Name of the networkport
	 * @param max_len	maximum buffer length
	 */
	void (*getSystemCreationClassName) (DSDKNetworkPort* np, char* name, int max_len);

	/**
	 * Gets SystemName of the networkport
	 * @param name	system Name of the networkport
	 * @param max_len	maximum buffer length
	 **/
 	void (*getSystemName) (DSDKNetworkPort* np, char* name, int max_len);

	/**
	 * Gets the networkport Creation class Name 
	 * @param name	Creation Class Name of the networkport
	 * @param max_len	maximum buffer length
	 */
	void (*getCreationClassName) (DSDKNetworkPort* np, char* name, int max_len);

	/**
	 * Gets Name of the networkport
	 * @param name Name of the networkport
	 * @param max_len	maximum buffer length
	 **/
 	void (*getName) (DSDKNetworkPort* np, char* name, int max_len);

	/**
	 * Gets Speed
	 * @return speed
	 */
	uint64 (*getSpeed) (DSDKNetworkPort* np);

	/**
	 * Gets LinkTechnology
	 * @return LinkTechnology
	 */
	uint16 (*getLinkTechnology) (DSDKNetworkPort* np);

	/**
 	 * Gets the LinkTechnology as string
 	 * @param lt		The link technology is filled in
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getLinkTechnologyStr) (DSDKNetworkPort* np, char* lt, int max_len);

	/**
	 * Gets getPermanentAddress of the networkport
	 * @param perm_addr getPermanentAddress of the networkport
	 * @param max_len	maximum buffer length
	 **/
 	void (*getPermanentAddress) (DSDKNetworkPort* np, char* perm_addr, int max_len);

	/**
	 * Gets maxSpeed
	 * @return maxspeed
	 */
	uint64 (*getMaxSpeed) (DSDKNetworkPort* np);

	/**
	 * Gets RequestedSpeed
	 * @return RequestedSpeed
	 */
	uint64 (*getRequestedSpeed) (DSDKNetworkPort* np);


	/**
	 * Gets DeviceID
	 * @param devid	NetworkPort Device ID
	 * @param max_len	maximum buffer length
	 */
	void (*getDeviceID) (DSDKNetworkPort* np, char* devid, int max_len);

	/**
	 * Gets the state of the network port
	 * @return The enabled state
	 */
	uint16 (*getEnabledState) (DSDKNetworkPort* np);

	/**
 	 * Gets the state of the network port as string
 	 * @param state		The Enabled State is filled in
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getEnabledStateStr) (DSDKNetworkPort* np, char* state, int max_len);

	/**
	 * Gets the requested state of the network port
	 * @return The enabled state
	 */
	uint16 (*getRequestedState) (DSDKNetworkPort* np);

	/**
 	 * Gets the requested status of the network port as string
 	 * @param state		The requested state is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getRequestedStateStr) (DSDKNetworkPort* np, char* state, int max_len);

	/**
	 * Gets ElementName
	 * @param ele_name	The ElementName
	 * @param max_len	maximum buffer length
	 */
	void (*getElementName) (DSDKNetworkPort* np, char* ele_name, int max_len);

	
	/**
	 * Releases this object
	 */
	void (*release) (DSDKNetworkPort* np);

} DSDKNetworkPortFT;


struct _DSDKNetworkPort
{
	void*				hdl;
	DSDKNetworkPortFT*	ft;
};

/**
 * Network Port iterator function table.
 */
struct _DSDKNetworkPortIterator;
typedef struct _DSDKNetworkPortIterator DSDKNetworkPortIterator;

/**
 * @struct DSDKNetworkPortIteratorFT
 * @brief Network Port iterator function table 
 */
typedef struct _DSDKNetworkPortIteratorFT
{
	/**
	 * Returns the Network Port at this iterator location.
	 */
	DSDKNetworkPort* (*getItem) (DSDKNetworkPortIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKNetworkPortIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKNetworkPortIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKNetworkPortIterator* di);

	
} DSDKNetworkPortIteratorFT;

/**
 * @struct _DSDKNetworkPortIterator 
 * @brief Iterator to iterate through the Network Port.
 */
struct _DSDKNetworkPortIterator
{
	void*						hdl;
	DSDKNetworkPortIteratorFT*	ft;
};

/**
 * Enumerate all the Network Port in a system.
 */
DSDKC_Export DSDKNetworkPortIterator* enumNetworkPorts (
											DSDKClient* client, BOOL cached);


#ifdef SWIGIZE
DSDKC_Export void  np_getSystemCreationClassName (DSDKNetworkPort* np, char* name, int max_len);
DSDKC_Export void  np_getSystemName (DSDKNetworkPort* np, char* name, int max_len);
DSDKC_Export void  np_getCreationClassName (DSDKNetworkPort* np, char* name, int max_len);
DSDKC_Export void  np_getName (DSDKNetworkPort* np, char* name, int max_len);
DSDKC_Export uint64  np_getSpeed (DSDKNetworkPort* np);
DSDKC_Export uint16  np_getLinkTechnology (DSDKNetworkPort* np);
DSDKC_Export void  np_getPermanentAddress (DSDKNetworkPort* np, char* perm_addr, int max_len);
DSDKC_Export uint64  np_getMaxSpeed (DSDKNetworkPort* np);
DSDKC_Export uint64  np_getRequestedSpeed (DSDKNetworkPort* np);
DSDKC_Export void  np_getDeviceID (DSDKNetworkPort* np, char* devid, int max_len);
DSDKC_Export uint16  np_getRequestedState (DSDKNetworkPort* np);
DSDKC_Export uint16  np_getEnabledState (DSDKNetworkPort* np);
DSDKC_Export void  np_getElementName (DSDKNetworkPort* np, char* ele_name, int max_len);
DSDKC_Export void  np_release (DSDKNetworkPort* np);
DSDKC_Export DSDKNetworkPort*  npi_getItem (DSDKNetworkPortIterator* di);
DSDKC_Export void  npi_next (DSDKNetworkPortIterator* di);
DSDKC_Export BOOL  npi_isEnd (DSDKNetworkPortIterator* di);
DSDKC_Export void  npi_release (DSDKNetworkPortIterator* di);
#endif

#ifdef __cplusplus
}
#endif

#endif /* CDSDK_NETWORKPORT_H_*/





