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
 * ipinterface_c.h
 * A class representing a IP Interface.
 */
#ifndef __CDSDK_IPINTERFACE_H__
#define __CDSDK_IPINTERFACE_H__
#include <dsdk/dsdktypes.h>
#include <dsdkc/capi.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * IPInterface table.
 */
struct _DSDKIPInterface;
typedef struct _DSDKIPInterface DSDKIPInterface;

/** 
 * @struct DSDKIPInterfaceFT
 * @brief ip Interface function table 
 */
typedef struct _DSDKIPInterfaceFT
{

	/**
	 * Gets the IPInterface System Creation class Name 
	 * @param name	Creation Class Name of the IPInterface
	 * @param max_len	maximum buffer length
	 */
	void (*getSystemCreationClassName) (DSDKIPInterface* ip, char* name, int max_len);

	/**
	 * Gets SystemName of the IPInterface
	 * @param name	system Name of the IPInterface
	 * @param max_len	maximum buffer length
	 **/
 	void (*getSystemName) (DSDKIPInterface* ip, char* name, int max_len);

	/**
	 * Gets the IPInterface Creation class Name 
	 * @param name	Creation Class Name of the IPInterface
	 * @param max_len	maximum buffer length
	 */
	void (*getCreationClassName) (DSDKIPInterface* ip, char* name, int max_len);

	/**
	 * Gets Name
	 * @param name The name
	 * @param max_len maximum buffer length
	 */
	void (*getName) (DSDKIPInterface* ip, char* name, int max_len);

	/**
	 * Gets Name format
	 * @param name The name format
	 * @param max_len maximum buffer length
	 */
	void (*getNameFormat) (DSDKIPInterface* ip, char* name_format, int max_len);

	/**
	 * Gets the ProtocolIF type of the IPInterface
	 * @return The ProtocolIF type
	 */
	uint16 (*getProtocolIFType) (DSDKIPInterface* ip);

	/**
 	 * Gets the interface type of the ip interface as string
 	 * @param type		The interface type is filled in
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getProtocolIFTypeStr) (DSDKIPInterface* ip, char* type, int max_len);

	/**
	 * Gets the state of the ip interface
	 * @return The enabled state
	 */
	uint16 (*getEnabledState) (DSDKIPInterface* ip);

	/**
 	 * Gets the state of the ip interface as string
 	 * @param state		The Enabled State is filled in
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getEnabledStateStr) (DSDKIPInterface* ip, char* state, int max_len);

	/**
	 * Gets the requested state of the ip interface
	 * @return The enabled state
	 */
	uint16 (*getRequestedState) (DSDKIPInterface* ip);

	/**
 	 * Gets the requested status of the ip interface as string
 	 * @param state		The requested state is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getRequestedStateStr) (DSDKIPInterface* ip, char* state, int max_len);


	/**
	 * Gets ElementName
	 * @param domaimname	The ElementName
	 * @param max_len	maximum	buffer length
	 */
	void (*getElementName) (DSDKIPInterface* ip, char* ele_name, int max_len);

	/**
	 * Gets IPv4Address
	 * @param addr	The IPv4Address
	 * @param max_len	maximum	buffer length
	 */
	void (*getIPv4Address) (DSDKIPInterface* ip, char* addr, int max_len);

	/**
	 * Gets SubnetMask
	 * @param sub_mask	The SubnetMask
	 * @param max_len	maximum	buffer length
	 */
	void (*getSubnetMask) (DSDKIPInterface* ip, char* sub_mask, int max_len);
	
	/**
	 * Gets AddressOrigin
	 * @return address origin
	 */
	uint16 (*getAddressOrigin) (DSDKIPInterface* ip);

	/**
 	 * Gets the address orgin of the ip interface as string
 	 * @param orgin		The address orgin is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getAddressOriginStr) (DSDKIPInterface* ip, char* orgin, int max_len);

	/**
	 * Gets IPv6Address
	 * @param addr	The IPv6Address
	 * @param max_len	maximum	buffer length
	 */
	void (*getIPv6Address) (DSDKIPInterface* ip, char* addr, int max_len);

	/**
	 * Gets IPv6AddressType
	 * @return IPv6AddressType
	 */
	uint16 (*getIPv6AddressType) (DSDKIPInterface* ip);

	/**
 	 * Gets the IPV6 address type of the ip interface as string
 	 * @param type		The IPV6 address is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getIPv6AddressTypeStr) (DSDKIPInterface* ip, char* type, int max_len);

	/**
	 * Gets IPv6SubnetPrefixLength
	 * @return IPv6SubnetPrefixLength
	 */
	uint16 (*getIPv6SubnetPrefixLength) (DSDKIPInterface* ip);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKIPInterface* ip);

} DSDKIPInterfaceFT;

struct _DSDKIPInterface
{
	void*						hdl;
	DSDKIPInterfaceFT*	ft;
};

/**
 * IPInterface iterator function table.
 */
struct _DSDKIPInterfaceIterator;
typedef struct _DSDKIPInterfaceIterator DSDKIPInterfaceIterator;

/**
 * @struct DSDKIPInterfaceIteratorFT
 * @brief IPInterface iterator function table 
 */
typedef struct _DSDKIPInterfaceIteratorFT
{
	/**
	 * Returns the IPInterface at this iterator location.
	 */
	DSDKIPInterface* (*getItem) (DSDKIPInterfaceIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKIPInterfaceIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKIPInterfaceIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKIPInterfaceIterator* di);

	
} DSDKIPInterfaceIteratorFT;

/**
 * @struct _DSDKIPInterfaceIterator 
 * @brief Iterator to iterate through the IPInterface.
 */
struct _DSDKIPInterfaceIterator
{
	void*						hdl;
	DSDKIPInterfaceIteratorFT*	ft;
};

/**
 * Enumerate all the IPInterface in a system.
 */
DSDKC_Export DSDKIPInterfaceIterator* enumIPInterfaces (
											DSDKClient* client, BOOL cached);

#ifdef SWIGIZE
DSDKC_Export void  ip_getSystemCreationClassName (DSDKIPInterface* ip, char* name, int max_len);
DSDKC_Export void  ip_getSystemName (DSDKIPInterface* ip, char* name, int max_len);
DSDKC_Export void  ip_getCreationClassName (DSDKIPInterface* ip, char* name, int max_len);
DSDKC_Export void  ip_getName (DSDKIPInterface* ip, char* name, int max_len);
DSDKC_Export void  ip_getNameFormat (DSDKIPInterface* ip, char* name_format, int max_len);
DSDKC_Export uint16  ip_getProtocolIFType (DSDKIPInterface* ip);
DSDKC_Export uint16  ip_getRequestedState (DSDKIPInterface* ip);
DSDKC_Export uint16  ip_getEnabledState (DSDKIPInterface* ip);
DSDKC_Export void  ip_getElementName (DSDKIPInterface* ip, char* ele_name, int max_len);
DSDKC_Export void  ip_getIPv4Address (DSDKIPInterface* ip, char* addr, int max_len);
DSDKC_Export void  ip_getSubnetMask (DSDKIPInterface* ip, char* sub_mask, int max_len);
DSDKC_Export uint16  ip_getAddressOrigin (DSDKIPInterface* ip);
DSDKC_Export void  ip_getIPv6Address (DSDKIPInterface* ip, char* addr, int max_len);
DSDKC_Export uint16  ip_getIPv6AddressType (DSDKIPInterface* ip);
DSDKC_Export void ip_getIPv6AddressTypeStr (DSDKIPInterface* ip, char* type, int max_len);
DSDKC_Export uint16  ip_getIPv6SubnetPrefixLength (DSDKIPInterface* ip);
DSDKC_Export void  ip_release (DSDKIPInterface* ip);
DSDKC_Export DSDKIPInterface*  ipi_getItem (DSDKIPInterfaceIterator* di);
DSDKC_Export void  ipi_next (DSDKIPInterfaceIterator* di);
DSDKC_Export BOOL  ipi_isEnd (DSDKIPInterfaceIterator* di);
DSDKC_Export void  ipi_release (DSDKIPInterfaceIterator* di);
#endif

#ifdef __cplusplus
}
#endif

#endif /* CDSDK_IPINTERFACE_H_*/







