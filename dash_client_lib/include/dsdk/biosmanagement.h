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
 * biosmanagement.h
 * A class representing a BIOS management.
 */
#ifndef __DSDK_BIOSMANAGEMENT_H__
#define __DSDK_BIOSMANAGEMENT_H__
#include <dsdk/dsdk_api.h>
#include <dsdk/dsdktypes.h>
#include <dsdk/cimmap.h>
#include <dsdk/oal/CIM_BIOSService.h>
#include <dsdk/oal/CIM_ComputerSystem.h>
#include <dsdk/oal/CIM_BIOSServiceCapabilities.h>

namespace dsdk
{

class CIM_BIOSAttribute;
class CBIOSAttribute;
typedef CAPIIterator<CBIOSAttribute, CIM_BIOSAttribute> _CBIOSAttributeIterator;

class CIM_BIOSElement;
class CBIOSElement;
typedef CAPIIterator<CBIOSElement, CIM_BIOSElement> _CBIOSElementIterator;

/**
 * @class CBIOSAttribute
 * @brief A class representing bios attribute 
 **/

class DSDK_Export CBIOSAttribute
{
public:
	DECLARE_API_ITERATOR (CBIOSAttribute);
	typedef CIM_BIOSAttribute CIMType;

public:
	/**
	 * Enumerates all the bios attributes present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the bios attributes.
	 */
	static CBIOSAttribute::iterator enumBIOSAttributes (IClient* client,
										 				  bool cached = true);

public:
	/**
	 * Return the underlying CIM object
	 */
	CIM_BIOSAttribute* getCIMObject (void) const { return _ba; }


	/**
	 * Gets the instance id of the bios attribute 
	 * @return The instance id
	 */
	string getInstanceID (void) const;

	/**
	 * Gets AttributeName
	 * return the attribute name
	 */
	string getAttributeName (void) const;
	
	/**
	 * Gets the value of the Attribute
	 * @return The current value of Attribute
	 */
	vector<string> getCurrentValue (void) const;

	/**
	 * Gets the default value of the Attribute
	 * @return The default value of the Attribute
	 */
	vector<string> getDefaultValue (void)const;

	/**
	 * Gets an array of PendingValue
	 *  @return The Pending value of the Attribute
	 */
	vector<string> getPendingValue (void) const; 

	/**
	 * Gets IsReadyonly flag of the Attribte
	 * @return	true if success
	 *			false if failure
	 */

	boolean	isReadOnly (void) const;

	/**
	 * Gets IsOrderedList
	 * return True or False
	 */
	boolean isOrderedList (void) const;

	/**
	 * Gets the possible values for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSEnumeration.
	 * return The possible values
	 */
	vector<string> getPossibleValues (void) const;

	/**
	 * Gets the possible description values for this attribute. This function is 
	 *			applicable only if attribute type is CIM_BIOSEnumeration.
	 * return The possible values
	 */
	vector<string> getPossibleValuesDescription (void) const;

	/**
	 * Gets the lower bound values for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSInteger.
	 * return The lower bound values
	 */
	uint64 getLowerBound (void) const;

	/**
	 * Gets the upper bound values for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSInteger.
	 * return The upper bound values
	 */
	uint64 getUpperBound (void) const;

	/**
	 * Gets the programmatic unit for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSInteger.
	 * return The programmatic unit
	 */
	string getProgrammaticUnit (void) const;

	/**
	 * Gets the scalar increment for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSInteger.
	 * return The scalar increment 
	 */
	uint32 getScalarIncrement (void) const;

	/**
	 * Gets the maximum length of string for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSString or CIM_BIOSPassword.
	 * return The maximum length
	 */
	uint64 getMaxLength (void) const;

	/**
	 * Gets the minimum length of string for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSString or CIM_BIOSPassword
	 * return The minimumlength
	 */
	uint64 getMinLength (void) const;

	/**
	 * Gets the string type of string for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSString.
	 * return The minimumlength
	 */
	uint32 getStringType (void) const;

	/**
	 * Gets the string type of string for this attribute as string. This function is applicable only 
	 *			if attribute type is CIM_BIOSString.
	 * return The minimumlength
	 */
	string getStringTypeStr (void) const;

	/**
	 * Gets the ValueExpression of string for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSString.
	 * return The ValueExpression
	 */
	string getValueExpression (void) const;

	/**
	 * Checks if password is set for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSPassword.
	 * return The tru or false
	 */
	boolean isPasswordSet (void) const;

	/**
	 * Gets the PasswordEncoding type for this attribute. This function is applicable only 
	 *			if attribute type is CIM_BIOSPassword.
	 * return PasswordEncoding
	 */
	uint32 getPasswordEncoding (void) const;

	/**
	 * Gets the PasswordEncoding for this attribute as string. This function is applicable only 
	 *			if attribute type is CIM_BIOSPassword.
	 * return The PasswordEncoding
	 */
	string getPasswordEncodingStr (void) const;

public:
	/**
	 * Sets the Bios Attribute
	 * @param value	Set attribute values
	 */
	uint32 setAttribute (const vector <string>& value);

	/**
	 * Verifies whether BIOS Management Services instances exists or not.
	 * @param bs		if the operation is supported, bs contains the corresponding
	 *					instance using which this operation can be perfroemd.
	 * @param be		If the operation is supported, bs contains the
	 *					corresponding instace using which the operation can be performed.
	 * @param bsc	    if the operation is supported, bsc contains the corresponding
	 *					instance using which this operation can be perfroemd. 
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfBIOSManagementService(CIM_BIOSService &bs, CIM_BIOSElement &be, CIM_BIOSServiceCapabilities &bsc) const;

	/**
	 * Verifies whether BIOS Management Services instances exists or not.
	 * @return true  - if Exists
	 *		   false - if not Exists.
	 */
	bool capableOfBIOSManagementService() const;

	/**
	 * Verifies whether SetBIOSAttributeEmbeddedInstanc operation can be performed or not.
	 * @param bs		if the operation is supported, bs contains the corresponding
	 *					instance using which this operation can be perfroemd.
	 * @param be		If the operation is supported, bs contains the
	 *					corresponding instace using which the operation can be performed.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfSetBIOSAttributeEmbeddedInstance(CIM_BIOSService &bs, CIM_BIOSElement &be ) const;

	/**
	 * Verifies whether SetBIOSAttributeEmbeddedInstance operation can be performed or not.
	 * @return true  - if supported
	 *		   false - if not supported.
	 */
	bool capableOfSetBIOSAttributeEmbeddedInstance() const;

	/**
	 * Verifies whether SetBIOSAttributes operation can be performed or not.
	 * @param bs		if the operation is supported, bs contains the corresponding
	 *					instance using which this operation can be perfroemd.
	 * @param be		If the operation is supported, bs contains the
	 *					corresponding instace using which the operation can be performed.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfSetBIOSAttributes(CIM_BIOSService &bs, CIM_BIOSElement &be ) const;

	/**
	 * Verifies whether SetBIOSAttributes operation can be performed or not.
	 * @return true  - if supported
	 *		   false - if not supported.
	 */
	bool capableOfSetBIOSAttributes() const;

	/**
	 * Verifies whether SetBIOSAttribute operation can be performed or not.
	 * @param bs		if the operation is supported, bs contains the corresponding
	 *					instance using which this operation can be perfroemd.
	 * @param be		If the operation is supported, bs contains the
	 *					corresponding instace using which the operation can be performed.
	 * @return true  - if supported
	 *		   false - if not supported.
	 */
	bool capableOfSetBIOSAttribute(CIM_BIOSService &bs,  CIM_BIOSElement &be) const;

	/**
	 * Verifies whether SetBIOSAttribute operation can be performed or not.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfSetBIOSAttribute() const;

	/**
	* This method return the SupportedPasswordEncodings property values and their string values.
	* @param  encod_val		If operation is sucessfull, method returns integer vector.
	*         encod_val		If operation is sucessfull, method returns string vector
	*
	* @ return   true  - if propery exists and contains at least one value.
	*            false - if propery does not exists.
	*/
	bool getSupportedEncodingsStr(vector<string> &encod_str) const;

	/**
	* This method return the SupportedPasswordAlgorithms property string values.
	* @param  algo_str		If operation is sucessfull, method returns string vector.
	*
	* @ return   true  - if propery exists and contains at least one value.
	*            false - if propery does not exists.
	*/
	bool getSupportedPasswordAlgorithms(vector<string> &algo_str) const;


public:
	/**
	 * Construct this object from the corresponding CIM_BIOSAttribute 
	 * object
	 */
	CBIOSAttribute (const CIM_BIOSAttribute& ba); 

	/**
	 * Copy constructor
	 */
	CBIOSAttribute (const CBIOSAttribute& ba);

	/**
	 * Destructor
	 */
	~CBIOSAttribute ();

	/**
	 * Assignment operator
	 */
	const CBIOSAttribute& operator = (const CBIOSAttribute& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void) ;

private:
	CIM_BIOSAttribute*	_ba;
};

/**
  * @class CBIOSElement
  * @brief A class representing a bios element
  **/
class DSDK_Export CBIOSElement
{
public:
	DECLARE_API_ITERATOR (CBIOSElement);
	typedef CIM_BIOSElement CIMType;

public:
	/**
	 * Enumerates all the bios elements present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the bios element.
	 */
	static CBIOSElement::iterator enumBIOSElements (IClient* client,
										 				  bool cached = true);

public:
	/**
	 * Return the underlying CIM object
	 */
	CIM_BIOSElement* getCIMObject (void) const { return _be; }

	/**
	 * Gets the manufacturer of this BIOS
	 * @return The manufacturer of this bios
	 */
	string getManufacturer (void) const;

	/**
	 * Gets PrimaryBIOS
	 * return True False
	 */
	boolean getPrimaryBIOS (void) const;

	/**
	 * Gets the verson of the BIOS
	 * @return The version of this bis
	 */
	string getVersion (void) const;

	 /**
	  * Gets the name of the Attribute
	  * @erturn The name of the bios attribute
	  */
	string getName (void) const;

	/**
	 * Gets SoftwareElementState
	 * @return the softwarelement state
	 */
	uint16 getSoftwareElementState (void) const;

	/**
	 * Gets SoftwareElementState as string
	 * @return the softwarelement state
	 */
	string getSoftwareElementStateStr (void) const;
	
	/**
	 * Gets SoftwareElementID
	 * @return the softwarelement ID
	 */
	string getSoftwareElementID (void) const;

	/**
	 * Gets TargetOperatingSystem
	 * @return the TargetOperatingSystem
	 */
	uint16 getTargetOperatingSystem (void) const;

	/**
	 * Gets TargetOperatingSystem as string
	 * @return The TargetOperatingSystem
	 */
	string getTargetOperatingSystemStr (void) const;

	/**
	 * Gets Registry URI's
	 * @return The RegistryURIs
	 */
	vector<string> getRegistryURIs (void) const;

public:
	/**
	 * Gets the BIOS attributes
	 * @return Bios attributes
	 */
	vector<CBIOSAttribute> getAttributes (void) const;

	/**
	 * Restore the BIOSDefaults values
	 */
	uint32 restoreDefaults (void) ;

	bool capableOfBIOSManagementService(CIM_BIOSService &bs, CIM_BIOSServiceCapabilities &bsc) const;
	bool capableOfBIOSManagementService() const;
	bool isSupportedMethod(CIM_BIOSService &bs, uint32 method ) const;
	bool capableOfReadRawBIOSData(CIM_BIOSService &bs ) const;
	bool capableOfReadRawBIOSData() const;
	bool capableOfWriteRawBIOSData(CIM_BIOSService &bs ) const;
	bool capableOfWriteRawBIOSData() const;
	vector<uint32> getSupportedMethods();
	/**
	 * Verifies whether RestoreDefaults can be performed or not on 
	 * the specified ComputerSystem instance.
	 * @param cs		Computersystem instance of which the default 
	 *					values can be restored.
	 * @param bs		If the operation is supported, bs contains the
	 *					associated instace on which the operation can be performed.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfRestoreDefaults(CIM_BIOSService &bs ) const;

	/**
	 * Verifies whether RestoreDefaults can be performed or not that corresponds to
	 *	default computersystem instance.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfRestoreDefaults() const;
	
public:
	/**
	 * Construct this object from the corresponding CIM_BIOSElement 
	 * object
	 */
	CBIOSElement (const CIM_BIOSElement& be); 

	/**
	 * Copy constructor
	 */
	CBIOSElement (const CBIOSElement& be);

	/**
	 * Destructor
	 */
	~CBIOSElement ();

	/**
	 * Assignment operator
	 */
	const CBIOSElement& operator = (const CBIOSElement& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void) ;

private:
	CIM_BIOSElement*	_be;
};

};	/* namespace dsdk */

#endif /*__DSDK_BIOSMANAGEMENT_H__*/
