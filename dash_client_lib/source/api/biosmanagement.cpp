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
 * A class representing a bios management.
 */
#include <dsdk/oal/CIM_BIOSElement.h>
#include <dsdk/oal/CIM_BIOSAttribute.h>
#include <dsdk/oal/CIM_BIOSService.h>
#include <dsdk/oal/CIM_BIOSEnumeration.h>
#include <dsdk/oal/CIM_BIOSInteger.h>
#include <dsdk/oal/CIM_BIOSString.h>
#include <dsdk/oal/CIM_BIOSPassword.h>
#include <dsdk/oal/CIM_SystemBIOS.h>
#include <dsdk/oal/CIM_ServiceAffectsElement.h>
#include <dsdk/oal/CIM_ConcreteComponent.h>
#include <dsdk/oal/CIM_BIOSServiceCapabilities.h>
#include <dsdk/biosmanagement.h>
#include <dsdk/dsdkexception.h>
#include "apiimp.h"
#include <dsdk/enumerator.h>


using namespace dsdk;

/*
 * Constructor
 */
CBIOSAttribute::CBIOSAttribute (const CIM_BIOSAttribute& ba)
{ 
	_ba = new CIM_BIOSAttribute (ba); 
}

/*
 * Constructor
 */
CBIOSAttribute::CBIOSAttribute (const CBIOSAttribute& ba)
{
	this->_ba = new CIM_BIOSAttribute (*(ba._ba));
}

/*
 * Destruction 
 */
CBIOSAttribute::~CBIOSAttribute ()
{
	if (this->_ba) { delete this->_ba; }
}

/*
 * Assignment operator
 */
const CBIOSAttribute& 
CBIOSAttribute::operator = (const CBIOSAttribute& rhs)
{
	if (this->_ba) { delete this->_ba; }
	this->_ba  = new CIM_BIOSAttribute (*rhs._ba);
	return *this;
}

/*
 * enumerateBIOSElement
 */
CBIOSAttribute::iterator 
CBIOSAttribute::enumBIOSAttributes (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_BIOSAttribute::iterator iter = 
		CIM_BIOSAttribute::enumInstances (client, 0, props);

	if (cached) { return createIterator (iter, props); }
	else 		{ return createIterator (iter); }
}

/*
 * getInstanceID 
 */
string 
CBIOSAttribute::getInstanceID(void) const
{
	return _ba->getInstanceID ();
}
/*
 * getAttributeName 
 */
string 
CBIOSAttribute::getAttributeName (void) const
{
	return _ba->getAttributeName ();
}

/*
 * getCurrentValue 
 */
vector<string> 
CBIOSAttribute::getCurrentValue (void) const
{
	vector<string> values;
	values = _ba->getCurrentValue ();
	return values;
}

/*
 * getDefaultValue 
 */
vector<string> 
CBIOSAttribute::getDefaultValue (void) const
{
	vector<string> values;
	values = _ba->getDefaultValue ();
	return values;
}

/*
 * getPendingValue 
 */
vector<string> 
CBIOSAttribute::getPendingValue (void) const
{
	vector<string> values;
	values = _ba->getPendingValue ();
	return values;
}
/*
 * isReadOnly 
 */
boolean 
CBIOSAttribute::isReadOnly (void) const
{
	return _ba->getIsReadOnly ();
}

/*
 * isOrderedList 
 */
boolean 
CBIOSAttribute::isOrderedList (void) const
{
	return _ba->getIsOrderedList ();
}

/*
 * getPossibleValues
 */
vector<string> 
CBIOSAttribute::getPossibleValues (void) const
{
	return ((CIM_BIOSEnumeration*)_ba)->getPossibleValues ();
}

/*
 * getPossibleValuesDescription 
 */
vector<string>
CBIOSAttribute::getPossibleValuesDescription  (void) const
{
	return ((CIM_BIOSEnumeration*)_ba)->getPossibleValuesDescription ();
}

/*
 * getLowerBound
 */
uint64
CBIOSAttribute::getLowerBound (void) const
{
	return ((CIM_BIOSInteger*)_ba)->getLowerBound ();
}

/*
 * getUpperBound
 */
uint64
CBIOSAttribute::getUpperBound (void) const
{
	return ((CIM_BIOSInteger*)_ba)->getUpperBound ();
}

/*
 * getProgrammaticUnit
 */
string
CBIOSAttribute::getProgrammaticUnit (void) const
{
	return ((CIM_BIOSInteger*)_ba)->getProgrammaticUnit ();
}

/*
 * getScalarIncrement
 */
uint32
CBIOSAttribute::getScalarIncrement (void) const
{
	return ((CIM_BIOSInteger*)_ba)->getScalarIncrement ();
}

/*
 * getMaxLength
 */
uint64
CBIOSAttribute::getMaxLength (void) const
{
	return ((CIM_BIOSString*)_ba)->getMaxLength ();
}

/*
 * getMinLength
 */
uint64
CBIOSAttribute::getMinLength (void) const
{
	return ((CIM_BIOSString*)_ba)->getMinLength ();
}

/*
 * getStringType 
 */
uint32
CBIOSAttribute::getStringType (void) const
{
	return ((CIM_BIOSString*)_ba)->getStringType ();
}

/*
 * getStringTypeStr
 */
string
CBIOSAttribute::getStringTypeStr (void) const
{
	return CIM_BIOSString::getValueStr_StringType (((CIM_BIOSString*)_ba)->getStringType ());
}

/*
 * getValueExpression
 */
string
CBIOSAttribute::getValueExpression (void) const
{
	return ((CIM_BIOSString*)_ba)->getValueExpression ();
}


/*
 * isPasswordSet
 */
boolean 
CBIOSAttribute::isPasswordSet (void) const
{
	return ((CIM_BIOSPassword*)_ba)->getIsSet ();
}

/*
 * getPasswordEncoding
 */
uint32
CBIOSAttribute::getPasswordEncoding (void) const
{
	return ((CIM_BIOSPassword*)_ba)->getPasswordEncoding ();
}

/*
 * getPasswordEncodingStr
 */
string
CBIOSAttribute::getPasswordEncodingStr (void) const
{
	return CIM_BIOSPassword::getValueStr_PasswordEncoding (((CIM_BIOSPassword*)_ba)->getPasswordEncoding ());
}


/*
 * setAttribute
 */
uint32 
CBIOSAttribute::setAttribute (const vector<string>& values) 
{
	uint32 result;
	CIM_BIOSService bs(CCIMInstance::nullInstance ());
	CIM_BIOSElement be(CCIMInstance::nullInstance ());
	
	if(capableOfSetBIOSAttribute(bs,be) == false)	{
		throw EFunctionNotSupported ("setBIOSAttribute");
	}

	uint32 status = bs.SetBIOSAttribute (be, this->getAttributeName(), values, "", 2, &result);

	
	/* if set attribute is success return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else 
	{
		string  retcodestr = bs.getValueStr_SetBIOSAttributeEmbeddedInstance_ReturnCode(status);
		throw EFunctionReturnedWithFailure ("CIM_BIOSService::SetBIOSAttribute", 
											retcodestr, status);
	}
}

bool 
CBIOSAttribute::capableOfBIOSManagementService(CIM_BIOSService &bs, CIM_BIOSElement &be, CIM_BIOSServiceCapabilities &bsc) const
{	
	vector<string> empty_props;

	CIM_BIOSService::iterator Iterbs = CIM_ServiceAffectsElement <CIM_BIOSAttribute,
									 CIM_BIOSService>::enumerateAffectingElement (this->_ba->getClient(),
									 *(_ba), empty_props);

	if (Iterbs == CIM_BIOSService::iterator::end ())
		return false;

	/* only one BIOS Service  will be associated with a BIOSAttribute through Service AffectsElement
	*/
	bs = *Iterbs;

	/* Enumerate the Find the BIOSElement instance associated with BIOSAttribute 
	*/
	CCIMObjectPath op = CCIMObjectPath::nullInstance ();
	CIM_BIOSElement::iterator Iterbe = CIM_ConcreteComponent <CIM_BIOSElement,
		CIM_BIOSAttribute>::enumerateGroupComponent(this->_ba->getClient(),
		*(_ba), empty_props);

	if (Iterbe == CIM_BIOSElement::iterator::end ())
		return false;

	/* only one BIOS Element  will be associated with a BIOSAttribute through ConcreteComponent class  */
	be = *Iterbe;


	// Enumerate CIM_BIOSServiceCapabilities instance associated with BIOSService through ElementCapabilities instance.	
	CIM_BIOSServiceCapabilities::iterator Iterbsc = CIM_ElementCapabilities< CIM_BIOSService, 
		CIM_BIOSServiceCapabilities>::enumerateCapabilities(this->_ba->getClient(), bs, empty_props);
	
	if (Iterbsc == CIM_BIOSServiceCapabilities::iterator::end ())
		return false;

	bsc = *Iterbsc;

	return true;
}

bool 
CBIOSAttribute::capableOfBIOSManagementService() const
{
	CIM_BIOSService bs(CCIMInstance::nullInstance ());
	CIM_BIOSElement be(CCIMInstance::nullInstance ());
	CIM_BIOSServiceCapabilities bsc (CCIMInstance::nullInstance ());
	return capableOfBIOSManagementService(bs, be, bsc);
}

bool 
CBIOSAttribute::capableOfSetBIOSAttributes(CIM_BIOSService &bs, CIM_BIOSElement &be) const
{
	CIM_BIOSServiceCapabilities bsc (CCIMInstance::nullInstance ());

	if ( false == capableOfBIOSManagementService(bs, be, bsc) )
		return false;

	vector<uint32> vmethods = bsc.getMethodsSupported();
	for ( size_t i=0; i < vmethods.size(); i++)
	{
		if (vmethods[i] == CIM_BIOSServiceCapabilities::MethodsSupported_SetBIOSAttributes)
			return true;
	}
	return false;
}
/**
 */
bool 
CBIOSAttribute::capableOfSetBIOSAttributes() const
{
	CIM_BIOSService bs(CCIMInstance::nullInstance ());
	CIM_BIOSElement be(CCIMInstance::nullInstance ());
	return capableOfSetBIOSAttribute(bs, be);
}
bool
CBIOSAttribute::capableOfSetBIOSAttributeEmbeddedInstance(CIM_BIOSService &bs, CIM_BIOSElement &be ) const
{
	CIM_BIOSServiceCapabilities bsc (CCIMInstance::nullInstance ());

	if ( false == capableOfBIOSManagementService(bs, be, bsc) )
		return false;

	vector<uint32> vmethods = bsc.getMethodsSupported();
	for ( size_t i=0; i < vmethods.size(); i++)
	{
		if (vmethods[i] == CIM_BIOSServiceCapabilities::MethodsSupported_SetBIOSAttributeEmbeddedInstance)
			return true;
	}
	return false;
}

bool 
CBIOSAttribute::capableOfSetBIOSAttributeEmbeddedInstance() const
{
	CIM_BIOSService bs(CCIMInstance::nullInstance ());
	CIM_BIOSElement be(CCIMInstance::nullInstance ());

	return capableOfSetBIOSAttributeEmbeddedInstance(bs, be);
}
bool 
CBIOSAttribute::capableOfSetBIOSAttribute(CIM_BIOSService &bs, CIM_BIOSElement &be) const
{
	CIM_BIOSServiceCapabilities bsc (CCIMInstance::nullInstance ());

	if ( false == capableOfBIOSManagementService(bs, be, bsc) )
		return false;

	vector<uint32> vmethods = bsc.getMethodsSupported();
	for ( size_t i=0; i < vmethods.size(); i++)
	{
		if (vmethods[i] == CIM_BIOSServiceCapabilities::MethodsSupported_SetBIOSAttribute)
			return true;
	}
	return false;
}
/**
 */
bool 
CBIOSAttribute::capableOfSetBIOSAttribute() const
{
	CIM_BIOSService bs(CCIMInstance::nullInstance ());
	CIM_BIOSElement be(CCIMInstance::nullInstance ());
	return capableOfSetBIOSAttribute(bs, be);
}

bool 
CBIOSAttribute::getSupportedEncodingsStr(vector<string> &encod_str) const
{
	CIM_BIOSService bs(CCIMInstance::nullInstance ());
	CIM_BIOSElement be(CCIMInstance::nullInstance ());
	CIM_BIOSServiceCapabilities bsc (CCIMInstance::nullInstance ());
	if ( false == capableOfBIOSManagementService(bs, be, bsc) )
		return false;
	
	vector<uint32> encod_val = bsc.getSupportedPasswordEncodings();
	if ( encod_val.size() == 0 ) return false;
	
	for ( size_t i=0; i < encod_val.size(); i++)
	{
		encod_str.push_back(bsc.getValueStr_SupportedPasswordEncodings(encod_val[i]));
	}
	return true;
}

bool 
CBIOSAttribute::getSupportedPasswordAlgorithms(vector<string> &algo_str) const
{
	CIM_BIOSService bs(CCIMInstance::nullInstance ());
	CIM_BIOSElement be(CCIMInstance::nullInstance ());
	CIM_BIOSServiceCapabilities bsc (CCIMInstance::nullInstance ());
	if ( false == capableOfBIOSManagementService(bs, be, bsc) )
		return false;
	
	algo_str = bsc.getSupportedPasswordAlgorithms();
	if ( algo_str.size() == 0 ) return false;
	
	return true;
}


/*
 * getCachedProps
 */
vector<string>
CBIOSAttribute::getCachedProps (void) 
{
	vector<string> props;
	props.push_back ("InstanceID");
	props.push_back ("AttributeName");
	props.push_back ("CurrentValue");
	props.push_back ("DefaultValue");
	props.push_back ("PendingValue");
	props.push_back ("IsReadOnly");
	props.push_back ("IsOrderedList");
	props.push_back ("PossibleValues");
	props.push_back ("AttributeName");
	props.push_back ("PossibleValuesDescription");
	props.push_back ("LowerBound");
	props.push_back ("UpperBound");
	props.push_back ("ProgrammaticUnit");
	props.push_back ("ScalarIncrement");
	props.push_back ("MaxLength");
	props.push_back ("MinLength");
	props.push_back ("StringType");
	props.push_back ("ValueExpression");
	props.push_back ("IsSet");
	props.push_back ("PasswordEncoding");
	return props;
}

/*
 * BIOSAttribute::Iterator
 */
DEFINE_API_ITERATOR (CBIOSAttribute);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CBIOSAttribute, CIM_BIOSAttribute);


/*
 * Constructor
 */
CBIOSElement::CBIOSElement (const CIM_BIOSElement& be)
{ 
	_be = new CIM_BIOSElement (be); 
}

/*
 * Constructor
 */
CBIOSElement::CBIOSElement (const CBIOSElement& be)
{
	this->_be = new CIM_BIOSElement (*(be._be));
}

/*
 * Destruction 
 */
CBIOSElement::~CBIOSElement ()
{
	if (this->_be) { delete this->_be; }
}

/*
 * Assignment operator
 */
const CBIOSElement& 
CBIOSElement::operator = (const CBIOSElement& rhs)
{
	if (this->_be) { delete this->_be; }
	this->_be  = new CIM_BIOSElement (*rhs._be);
	return *this;
}

/*
 * enumerateBIOSElement
 */
CBIOSElement::iterator 
CBIOSElement::enumBIOSElements (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_BIOSElement::iterator iter = 
		CIM_BIOSElement::enumInstances (client, 0, props);

	if (cached) { return createIterator (iter, props); }
	else 		{ return createIterator (iter); }
}

/*
 * getName 
 */
string 
CBIOSElement::getName (void) const
{
	return _be->getName ();
}

/*
 * getManufacture 
 */
string 
CBIOSElement::getManufacturer (void) const
{
	return _be->getManufacturer();
}

/*
 * getPrimaryBIOS
 */
boolean 
CBIOSElement::getPrimaryBIOS (void) const
{
	return _be->getPrimaryBIOS ();
}

/*
 * getVersion
 */
string 
CBIOSElement::getVersion (void) const
{
	return _be->getVersion ();
}

/*
 * getSoftwareElementState
 */
uint16 
CBIOSElement::getSoftwareElementState (void) const
{
	return _be->getSoftwareElementState ();
}

/*
 * getSoftwareElementStateStr
 */
string
CBIOSElement::getSoftwareElementStateStr (void) const
{
	return CIM_BIOSElement::getValueStr_SoftwareElementState (_be->getSoftwareElementState ());
}

/*
 * getSoftwareElementID
 */
string 
CBIOSElement::getSoftwareElementID (void) const
{
	return _be->getSoftwareElementID ();
}

/*
 * getTargetOperatingSystem
 */
uint16 
CBIOSElement::getTargetOperatingSystem (void) const
{
	return _be->getTargetOperatingSystem ();
}

/*
 * getTargetOperatingSystemStr
 */
string
CBIOSElement::getTargetOperatingSystemStr (void) const
{
	return CIM_BIOSElement::getValueStr_TargetOperatingSystem (_be->getTargetOperatingSystem ());
}

/*
 * getRegistryURIs
 */
vector<string>
CBIOSElement::getRegistryURIs (void) const
{
	return _be->getRegistryURIs ();
}

/*
 * getAttributes
 */
vector<CBIOSAttribute> 
CBIOSElement::getAttributes (void) const
{
	vector <CBIOSAttribute> attributes;
	
	/* enumerate the attribute associated with this BIOS element */
	/* @todo  */
	//CBIOSAttribute::iterator iter = enumBIOSAttributes (_be->getClient(), *(_be));
	CBIOSAttribute::iterator iter = CBIOSAttribute::enumBIOSAttributes (_be->getClient());
	for (; iter != CBIOSAttribute::iterator::end (); ++iter) 
	{
		CBIOSAttribute attribute = *iter;
		attributes.push_back (attribute);
	}
	
	return attributes;
}

/*
 * restoreDefaults
 */
uint32
CBIOSElement::restoreDefaults (void) 
{
	CIM_BIOSService bs(CCIMInstance::nullInstance ());
	CIM_BIOSElement be(CCIMInstance::nullInstance ());

	if(capableOfRestoreDefaults(bs) == false)	{
		throw EFunctionNotSupported ("restoreBIOSDefaults");
	}
	uint32 status = bs.RestoreBIOSDefaults (*(this->getCIMObject()), "", 0);
	/* if BIOS restored successfully return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else 
	{
		string  retcodestr = bs.getValueStr_RestoreBIOSDefaults_ReturnCode(status);
		throw EFunctionReturnedWithFailure ("CIM_BIOSService::RestoreBIOSDefaults", 
											retcodestr, status);
	}
}
// ============================ Below =====================
bool 
CBIOSElement::capableOfBIOSManagementService(CIM_BIOSService &bs, CIM_BIOSServiceCapabilities &bsc) const
{
	vector<string> empty_props;
	/* enumerate the Computer System associated with this BIOS Element */
	CIM_ComputerSystem::iterator iter = CIM_SystemBIOS <CIM_ComputerSystem,
									CIM_BIOSElement>::enumerateGroupComponent (_be->getClient(),
																*(this->getCIMObject ()),
																 empty_props);
	if (iter == CIM_ComputerSystem::iterator::end ())
		return false;

	/* only one computer system will be associated with a BIOS Element so use the first instance */
	CIM_ComputerSystem cs = *iter;

	/* enumerate the BIOS Service associated with the computer system */
	CIM_BIOSService::iterator Iter = CIM_ServiceAffectsElement <CIM_ComputerSystem,
									 CIM_BIOSService>::enumerateAffectingElement (this->_be->getClient(),
									 cs, empty_props);
	if (Iter == CIM_BIOSService::iterator::end ())
		return false;

	/* only one BIOS Service  will be associated with a computer system through Service AffectsElement  */
	bs = *Iter;

	/* enumerate the BIOSSErviceCapabilities instance associate with BIOSService through ElementCapbilities */
	CIM_BIOSServiceCapabilities::iterator bsciter = CIM_ElementCapabilities <
						CIM_BIOSService,CIM_BIOSServiceCapabilities>::enumerateCapabilities (
						bs.getClient (), bs,empty_props);
	if (bsciter == CIM_BIOSServiceCapabilities::iterator::end())
	{
		//throw EFunctionNotSupported ("BIOSServiceCapabilities");
		return false;
	}
	/* 
	  Only one BIOS Service capabilities will be supported, so use the first BIOS Service capabilities
	 */
	bsc = *bsciter;
	return true;
}


bool 
CBIOSElement::capableOfBIOSManagementService() const
{
	CIM_BIOSService bs(CCIMInstance::nullInstance ());
	CIM_BIOSServiceCapabilities bsc (CCIMInstance::nullInstance ());
	return capableOfBIOSManagementService(bs, bsc);
}

bool 
CBIOSElement::isSupportedMethod(CIM_BIOSService &bs, uint32 method ) const
{
	CIM_BIOSServiceCapabilities bsc (CCIMInstance::nullInstance ());
	if ( capableOfBIOSManagementService(bs, bsc) == false)
		return false;

	vector<uint32> vmethods = bsc.getMethodsSupported();
	for ( size_t i=0; i < vmethods.size(); i++)
	{
		if (vmethods[i] == method)
			return true;
	}
	return false;
}

/*
*/
bool 
CBIOSElement::capableOfReadRawBIOSData(CIM_BIOSService &bs) const
{
	return isSupportedMethod(bs, CIM_BIOSServiceCapabilities::MethodsSupported_ReadRawBIOSData);
}
bool
CBIOSElement::capableOfReadRawBIOSData() const
{
	CIM_BIOSService bs(CCIMInstance::nullInstance ());
	return capableOfReadRawBIOSData(bs);
}
/*
*/
bool 
CBIOSElement::capableOfWriteRawBIOSData(CIM_BIOSService &bs) const
{
	return isSupportedMethod(bs, CIM_BIOSServiceCapabilities::MethodsSupported_WriteRawBIOSData);
}

bool
CBIOSElement::capableOfWriteRawBIOSData() const
{
	CIM_BIOSService bs(CCIMInstance::nullInstance ());
	return capableOfWriteRawBIOSData(bs);
}

/*
*/
bool 
CBIOSElement::capableOfRestoreDefaults(CIM_BIOSService &bs ) const
{
	return isSupportedMethod(bs, CIM_BIOSServiceCapabilities::MethodsSupported_RestoreBIOSDefaults);
}

bool 
CBIOSElement::capableOfRestoreDefaults() const
{
	CIM_BIOSService bs(CCIMInstance::nullInstance ());
	return capableOfRestoreDefaults(bs);
}
vector<uint32>
CBIOSElement::getSupportedMethods()
{
	CIM_BIOSServiceCapabilities bsc (CCIMInstance::nullInstance ());
	CIM_BIOSService bs (CCIMInstance::nullInstance ());
	return bsc.getMethodsSupported();
}

//================================== Above =============================================
/*
 * getCachedProps
 */
vector<string> 
CBIOSElement::getCachedProps (void) 
{
	vector<string> props;

	props.push_back ("Manufacturer");
	props.push_back ("PrimaryBIOS");
	props.push_back ("Name");
	props.push_back ("Version");
	props.push_back ("SoftwareElementState");
	props.push_back ("SoftwareElementID");
	props.push_back ("TargetOperatingSystem");
	props.push_back ("RegistryURIs");
	return props;
}

/*
 * BIOSElement::Iterator
 */
DEFINE_API_ITERATOR (CBIOSElement);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CBIOSElement, CIM_BIOSElement);
