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
 * biosmanagement_c.h
 * A class representing a bios management.
 */
#ifndef __CDSDK_BIOSMANAGEMENT_H__
#define __CDSDK_BIOSMANAGEMENT_H__
#include <dsdk/dsdktypes.h>
#include <dsdkc/capi.h>

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * BIOSAttribute function table.
 */
struct _DSDKBIOSAttribute;
typedef struct _DSDKBIOSAttribute DSDKBIOSAttribute;

/**
 * BIOSElement function table.
 */
struct _DSDKBIOSElement;
typedef struct _DSDKBIOSElement DSDKBIOSElement;



/** 
 * @struct DSDKBIOSAttributeFT
 * @brief BIOS Attribute function table 
 */
typedef struct _DSDKBIOSAttributeFT
{
	/**
	 * Gets the Instance ID
	 * @param instanceid	instanceid 
	 * @param max_len		maximum buffer length
	 */
	void (*getInstanceID) (DSDKBIOSAttribute* ba, char* instanceid, int max_len);
	/**
	 * Gets AttributeName
	 * return the attribute name
	 */
	void (*getAttributeName) (DSDKBIOSAttribute* ba, char* name, int max_len);

	/**
	 * Gets the value of the Attribute
	 * @param current_value	Current attribute value
	 * @param max_value		maximum number of values
	 * @max_strlen			maximum buffer length
	 */
	int (*getCurrentValue) (DSDKBIOSAttribute* ba, char** current_value, 
							   int max_value, int max_strlen);

	/**
	 * Gets the Default value of the Attribute
	 * @param default_values	Default attribute value
	 * @param max_value			maximum number of values
	 * @max_strlen				maximum buffer length
	 */
	int (*getDefaultValue) (DSDKBIOSAttribute* ba, char** default_values, 
							   int max_value, int max_strlen);
	
	/**
	 * Gets the Pending value of the Attribute
	 * @param pending_values	Pending attribute value
	 * @param max_value			maximum number of values
	 * @max_strlen				maximum buffer length
	 */
	int (*getPendingValue) (DSDKBIOSAttribute* ba, char** pending_values, 
							   int max_value, int max_strlen);

	/**
	 * Gets IsReadyonly flag of the Attribte
	 * @return	true if success
				false otherwise
	 */
	BOOL (*isReadOnly) (DSDKBIOSAttribute* ba);

	/**
	 * Gets IsOrderedList
	 * @ return True or False
	 */
	BOOL (*isOrderedList) (DSDKBIOSAttribute* ba);

	/**
	 * Gets the possible values for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSEnumeration.
	 * @param values 		The PossibleValues
	 * @param max_value		maximum number values
	 * @max_strlen			maximum buffer length
	 */
	int (*getPossibleValues) (DSDKBIOSAttribute* ba, char** values, 
							   int max_value, int max_strlen);

	/**
	 * Gets the possible description values for this attribute. This function is 
	 *			applicable only if attribute type is CIM_BIOSEnumeration.
	 * @param values 		The Possible Values Description
	 * @param max_value		maximum number of values
	 * @max_strlen			maximum buffer length
	 */
	int (*getPossibleValuesDescription) (DSDKBIOSAttribute* ba, char** values, 
							   int max_value, int max_strlen);

	/**
	 * Gets the lower bound values for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSInteger.
	 * return The lower bound values
	 */
	uint64 (*getLowerBound) (DSDKBIOSAttribute* ba);

	/**
	 * Gets the upper bound values for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSInteger.
	 * return The upper bound values
	 */
	uint64 (*getUpperBound) (DSDKBIOSAttribute* ba);

	/**
	 * Gets the programmatic unit for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSInteger.
	 * @param	program_unit	The programmatic unit for this attribute.
	 * @param	max_len			maximum buffer length
	 */
	void (*getProgrammaticUnit) (DSDKBIOSAttribute* ba, char* program_unit, int max_len);

	/**
	 * Gets the scalar increment for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSInteger.
	 * return The scalar increment 
	 */
	uint32 (*getScalarIncrement) (DSDKBIOSAttribute* ba);

	/**
	 * Gets the maximum length of string for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSString or CIM_BIOSPassword.
	 * return The maximum length
	 */
	uint64 (*getMaxLength) (DSDKBIOSAttribute* ba);

	/**
	 * Gets the minimum length of string for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSString or CIM_BIOSPassword
	 * return The minimumlength
	 */
	uint64 (*getMinLength) (DSDKBIOSAttribute* ba);

	/**
	 * Gets the string type of string for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSString.
	 * return The minimumlength
	 */
	uint32 (*getStringType) (DSDKBIOSAttribute* ba);

	/**
	 * Gets the string type of string for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSString.
	 * @param	type		The stirng type
	 * @param	max_len		maximum buffer length
	 */
	void (*getStringTypeStr) (DSDKBIOSAttribute* ba, char* type, int max_len);

	/**
	 * Gets the ValueExpression of string for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSString.
	 * @param	value_exp	The ValueExpression
	 * @param	max_len		maximum buffer length
	 */
	void (*getValueExpression) (DSDKBIOSAttribute* ba, char* value_exp, int max_len);

	/**
	 * Checks if password is set for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSPassword.
	 * return The tru or false
	 */
	BOOL (*isPasswordSet) (DSDKBIOSAttribute* ba);

	/**
	 * Gets the PasswordEncoding type for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSPassword.
	 * return PasswordEncoding
	 */
	uint32 (*getPasswordEncoding) (DSDKBIOSAttribute* ba);

	/**
	 * Gets the PasswordEncoding for this attribute as string. This function is applicable only 
	 *			if attribute type is CIM_BIOSPassword.
	 * @param The PasswordEncoding
	 */
	void (*getPasswordEncodingStr) (DSDKBIOSAttribute* ba, char* pass_enc, int max_len);

	/**
	 * Sets the attribute value
	 * @param values	Set attribute values
	 * @param num_values	maximum number of values
	 */
	uint32 (*setAttribute) (DSDKBIOSAttribute* ba, char** values, int num_values);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKBIOSAttribute* ba);

} DSDKBIOSAttributeFT;

struct _DSDKBIOSAttribute
{
	void*					hdl;
	DSDKBIOSAttributeFT*	ft;
};

/**
 * BIOSElement iterator function table.
 */
struct _DSDKBIOSAttributeIterator;
typedef struct _DSDKBIOSAttributeIterator DSDKBIOSAttributeIterator;

/**
 * @struct DSDKBIOSAttributeIteratorFT
 * @brief BIOSAttribute iterator function table 
 */
typedef struct _DSDKBIOSAttributeIteratorFT
{
	/**
	 * Returns the BIOSAttribute at this iterator location.
	 */
	DSDKBIOSAttribute* (*getItem) (DSDKBIOSAttributeIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKBIOSAttributeIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKBIOSAttributeIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKBIOSAttributeIterator* di);

} DSDKBIOSAttributeIteratorFT;

/**
 * @struct _DSDKBIOSAttributeIterator 
 * @brief Iterator to iterate through the BIOSAttribute.
 */
struct _DSDKBIOSAttributeIterator
{
	void*							hdl;
	DSDKBIOSAttributeIteratorFT*	ft;
};

/**
 * Enumerate all the BIOSAttribute in a system.
 */
DSDKC_Export DSDKBIOSAttributeIterator* enumBIOSAttributes (
											DSDKClient* client, BOOL cached);




/** 
 * @struct DSDKBIOSElementFT
 * @brief BIOS Element function table 
 */
typedef struct _DSDKBIOSElementFT
{
	/**
	 * Gets the manufacturer of this BIOS
	 * @param manufacturer	Manufacturer of this BIOS
	 * @param max_len	maximum buffer length
	 */

	void (*getManufacturer) (DSDKBIOSElement* be, char* manufacturer, int max_len);
	
	/**
	 * Gets PrimaryBIOS
	 * return True False
	 */
	BOOL (*getPrimaryBIOS) (DSDKBIOSElement* be);
	
	/**
	 * Gets the verson of the BIOS
	 * @return The version of this bis
	 */
	void (*getVersion) (DSDKBIOSElement* be, char* version, int max_len);

	/**
	 * Gets the name of the Attribute
	 * @param name	attribute name
	 * @param max_len	maximum buffer length
	 */
	void (*getName) (DSDKBIOSElement* be, char* name, int max_len);

	/**
	 * Gets SoftwareElementState
	 * @return the softwarelement state
	 */
	uint16 (*getSoftwareElementState) (DSDKBIOSElement* be);

	/**
	 * Gets DoftwareElementState as string
	 * @param state		software element state
	 * @param max_len	maximum buffer length
	 */
	void (*getSoftwareElementStateStr) (DSDKBIOSElement* be, char* state, int max_len);

	/**
	 * Gets SoftwareElementID
	 * @param name	 name
	 * @param max_len	maximum buffer length
	 */
	void (*getSoftwareElementID) (DSDKBIOSElement* be, char* name, int max_len);

	/**
	 * Gets TargetOperatingSystem
	 * @return the TargetOperatingSystem
	 */
	uint16 (*getTargetOperatingSystem) (DSDKBIOSElement* be);

	/**
	 * Gets TargetOperatingSystem as string
	 * @param os		Target os
	 * @param max_len	maximum buffer length
	 */
	void (*getTargetOperatingSystemStr) (DSDKBIOSElement* be, char* os, int max_len);

	/**
	 * Gets Registry URI's
	 * @param registryuri 	The RegistryURIs
	 * @param max_value	maximum maximum number values
	 * @max_strlen	maximum buffer length
	 */
	int (*getRegistryURIs) (DSDKBIOSAttribute* ba, char** registryuri, 
							   int max_value, int max_strlen);
	
	/**
	 * Gets the BIOS attributes
	 * @param attributes	BIOS attributes
	 * @param max_attributes	Maximum BIOS Attrubutes
	 */
	int (*getAttributes) (DSDKBIOSElement* be, DSDKBIOSAttribute** attributes, int max_attributes);

	/**
	 * Restore the BIOSDefaults values
	 */
	uint32 (*restoreDefaults) (DSDKBIOSElement* be);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKBIOSElement* be);

} DSDKBIOSElementFT;

struct _DSDKBIOSElement
{
	void*				hdl;
	DSDKBIOSElementFT*	ft;
};

/**
 * BIOSElement iterator function table.
 */
struct _DSDKBIOSElementIterator;
typedef struct _DSDKBIOSElementIterator DSDKBIOSElementIterator;

/**
 * @struct DSDKBIOSElementIteratorFT
 * @brief BIOSElement iterator function table 
 */
typedef struct _DSDKBIOSElementIteratorFT
{
	/**
	 * Returns the BIOSElement at this iterator location.
	 */
	DSDKBIOSElement* (*getItem) (DSDKBIOSElementIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKBIOSElementIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKBIOSElementIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKBIOSElementIterator* di);

} DSDKBIOSElementIteratorFT;

/**
 * @struct _DSDKBIOSElementIterator 
 * @brief Iterator to iterate through the BIOSElement.
 */
struct _DSDKBIOSElementIterator
{
	void*						hdl;
	DSDKBIOSElementIteratorFT*	ft;
};

/**
 * Enumerate all the BIOSElement in a system.
 */
DSDKC_Export DSDKBIOSElementIterator* enumBIOSElements (
											DSDKClient* client, BOOL cached);

#ifdef SWIGIZE
DSDKC_Export void  ba_getInstanceID (DSDKBIOSAttribute* ba, char* instanceid, int max_len);
DSDKC_Export void  ba_getAttributeName (DSDKBIOSAttribute* ba, char* name, int max_len);
DSDKC_Export int  ba_getCurrentValue (DSDKBIOSAttribute* ba, char** current_values, int max_value, int max_strlen);
DSDKC_Export int  ba_getDefaultValue (DSDKBIOSAttribute* ba, char** default_values, int max_value, int max_strlen);
DSDKC_Export int  ba_getPendingValue (DSDKBIOSAttribute* ba, char** pending_values, int max_value, int max_strlen);
DSDKC_Export uint32  ba_setAttribute (DSDKBIOSAttribute* ba, char** values, int num_values);
DSDKC_Export void ba_getPasswordEncodingStr (DSDKBIOSAttribute* ba, char* pass_enc, int max_len);
DSDKC_Export void  ba_release (DSDKBIOSAttribute* ba);
DSDKC_Export DSDKBIOSAttribute*  bai_getItem (DSDKBIOSAttributeIterator* di);
DSDKC_Export void  bai_next (DSDKBIOSAttributeIterator* di);
DSDKC_Export BOOL  bai_isEnd (DSDKBIOSAttributeIterator* di);
DSDKC_Export void  bai_release (DSDKBIOSAttributeIterator* di);
DSDKC_Export void  be_getManufacturer(DSDKBIOSElement* be, char* manufacturer, int max_len);
DSDKC_Export BOOL  be_getPrimaryBIOS (DSDKBIOSElement* be);
DSDKC_Export void  be_getVersion (DSDKBIOSElement* be, char* version, int max_len);
DSDKC_Export void  be_getName (DSDKBIOSElement* be, char* name, int max_len);
DSDKC_Export uint16  be_getSoftwareElementState (DSDKBIOSElement* be);
DSDKC_Export void  be_getSoftwareElementID (DSDKBIOSElement* be, char* name, int max_len);
DSDKC_Export int  be_getAttributes (DSDKBIOSElement* be, DSDKBIOSAttribute** attributes, int max_attributes);
DSDKC_Export uint32  be_restoreDefaults (DSDKBIOSElement* be);
DSDKC_Export void  be_release (DSDKBIOSElement* be);
DSDKC_Export void  bei_next (DSDKBIOSElementIterator* di);
DSDKC_Export BOOL  bei_isEnd (DSDKBIOSElementIterator* di);
DSDKC_Export void  bei_release (DSDKBIOSElementIterator* di);
#endif

#ifdef __cplusplus
}
#endif

#endif /* CDSDK_BIOSMANAGEMENT_H_*/


