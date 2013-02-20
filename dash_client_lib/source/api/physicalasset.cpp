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
 * physicalasset.cpp
 * Class representing a physical asset.
 */
#include <dsdk/oal/CIM_PhysicalElement.h>
#include <dsdk/oal/CIM_PhysicalPackage.h>
#include <dsdk/oal/CIM_Card.h>
#include <dsdk/oal/CIM_Rack.h>
#include <dsdk/oal/CIM_Chassis.h>
#include <dsdk/oal/CIM_PhysicalConnector.h>
#include <dsdk/oal/CIM_Slot.h>
#include <dsdk/physicalasset.h>
#include "apiimp.h"

using namespace dsdk;

/*
 * Constructor
 */
CPhysicalAsset::CPhysicalAsset (const CIM_PhysicalElement& pe)
{ 
	_pe = new CIM_PhysicalElement (pe); 
}

/*
 * Constructor
 */
CPhysicalAsset::CPhysicalAsset (const CPhysicalAsset& pa)
{
	this->_pe = new CIM_PhysicalElement (*(pa._pe));
}

/*
 * Destruction 
 */
CPhysicalAsset::~CPhysicalAsset ()
{
	if (this->_pe) { delete this->_pe; }
}

/*
 * Assignment operator
 */
const CPhysicalAsset& 
CPhysicalAsset::operator = (const CPhysicalAsset& rhs)
{
	if (this->_pe) { delete this->_pe; }
	this->_pe  = new CIM_PhysicalElement (*rhs._pe);
	return *this;
}

/*
 * enumPhysicalAsset
 */
CPhysicalAsset::iterator 
CPhysicalAsset::enumPhysicalAssets (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_PhysicalElement::iterator iter = 
			CIM_PhysicalElement::enumInstances (client, 
											    0, 
											    props);
	if (cached) { return createIterator (iter, props); }
	else 		{ return createIterator (iter); 		 }
}

/*
 * getTag
 */
string 
CPhysicalAsset::getTag (void) const 
{ 
	return  ((CPhysicalAsset*) this)->_pe->getTag ();
} 	

/*
 * getCreationClassName 
 */
string 
CPhysicalAsset::getCreationClassName (void) const 
{ 
	return  ((CPhysicalAsset*) this)->_pe->getCreationClassName ();
} 	

/*
 * getManufacturer 
 */
string 
CPhysicalAsset::getManufacturer (void) const
{
	return ((CPhysicalAsset*) this)->_pe->getManufacturer ();
}

/*
 * getModel
 */
string 
CPhysicalAsset::getModel (void) const
{
	return ((CPhysicalAsset*) this)->_pe->getModel ();
}

/*
 * getSerialNumber
 */
string 
CPhysicalAsset::getSerialNumber (void) const
{
	return ((CPhysicalAsset*) this)->_pe->getSerialNumber ();
}

/*
 * getPartNumber
 */
string 
CPhysicalAsset::getPartNumber (void) const
{
	return ((CPhysicalAsset*) this)->_pe->getPartNumber ();
}

/*
 * getSKU
 */
string 
CPhysicalAsset::getSKU (void) const
{
	return ((CPhysicalAsset*) this)->_pe->getSKU ();
}

/*
 * getElementName
 */
string 
CPhysicalAsset::getElementName (void) const
{
	return ((CPhysicalAsset*) this)->_pe->getElementName ();
}

/*
 * canBeFRUed
 */
boolean 
CPhysicalAsset::canBeFRUed (void) const
{
	return ((CIM_PhysicalPackage*)this->_pe)->getCanBeFRUed ();
}

/*
 * getPackageType
 */
uint16
CPhysicalAsset::getPackageType (void) const
{
	return ((CIM_PhysicalPackage*)this->_pe)->getPackageType ();
}

/*
 * getPackageTypeStr
 */
string
CPhysicalAsset::getPackageTypeStr (void) const
{
	return CIM_PhysicalPackage::getValueStr_PackageType (
				((CIM_PhysicalPackage*)this->_pe)->getPackageType ());
}

/*
 * getVendorCompatibilityStrings
 */
vector<string>
CPhysicalAsset::getVendorCompatibilityStrings (void) const
{
	return ((CIM_PhysicalPackage*)this->_pe)->getVendorCompatibilityStrings ();
}

/*
 * getVersion
 */
string
CPhysicalAsset::getVersion (void) const
{
	return ((CIM_PhysicalPackage*)this->_pe)->getVersion ();
}

/*
 * getName
 */
string
CPhysicalAsset::getName (void) const
{
	return ((CIM_PhysicalPackage*)this->_pe)->getName ();
}

/*
 * isHostingBoard
 */
boolean
CPhysicalAsset::isHostingBoard (void) const
{
	return ((CIM_Card*)this->_pe)->getHostingBoard ();
}

/*
 * getTypeOfRack
 */
uint16
CPhysicalAsset::getTypeOfRack (void) const
{
	return ((CIM_Rack*)this->_pe)->getTypeOfRack ();
}

/*
 * getTypeOfRackStr
 */
string
CPhysicalAsset::getTypeOfRackStr (void) const
{
	return CIM_Rack::getValueStr_TypeOfRack (
				((CIM_Rack*)this->_pe)->getTypeOfRack ());
}

/*
 * getChassisTypes
 */
vector<uint16>
CPhysicalAsset::getChassisTypes   (void) const
{
	return ((CIM_Chassis*)this->_pe)->getChassisTypes  ();
}

/*
 * getChassisTypesStr 
 */
vector<string>
CPhysicalAsset::getChassisTypesStr  (void) const
{
	vector <string> chassistype_str;
	
	vector<uint16> chassistype = ((CIM_Chassis*)this->_pe)->getChassisTypes  ();
	for(size_t i = 0; i < chassistype.size(); i++ )
	{
		chassistype_str.push_back(((CIM_Chassis*)this->_pe)->getValueStr_ChassisTypes (chassistype [i]));
	}

	return chassistype_str;
}


/*
 * getChassisPackageType
 */
uint16
CPhysicalAsset::getChassisPackageType (void) const
{
	return ((CIM_Chassis*)this->_pe)->getChassisPackageType ();
}

/*
 * getChassisPackageTypeStr
 */
string
CPhysicalAsset::getChassisPackageTypeStr (void) const
{
	return CIM_Chassis::getValueStr_ChassisPackageType (
				((CIM_Chassis*)this->_pe)->getChassisPackageType ());
}

/*
 * getConnectorLayout
 */
uint16
CPhysicalAsset::getConnectorLayout (void) const
{
	return ((CIM_PhysicalConnector*)this->_pe)->getConnectorLayout ();
}

/*
 * getConnectorLayoutStr
 */
string
CPhysicalAsset::getConnectorLayoutStr (void) const
{
	return CIM_PhysicalConnector::getValueStr_ConnectorLayout (
				((CIM_PhysicalConnector*)this->_pe)->getConnectorLayout ());
}

/*
 * getSlotNumber
 */
uint16
CPhysicalAsset::getSlotNumber (void) const
{
	return ((CIM_Slot*)this->_pe)->getNumber ();
}

/*
 * getFormFactor
 */
uint16
CPhysicalAsset::getFormFactor (void) const
{
	return ((CIM_PhysicalMemory*)this->_pe)->getFormFactor ();
}

/*
 * getFormFactorStr
 */
string
CPhysicalAsset::getFormFactorStr (void) const
{
	return CIM_PhysicalMemory::getValueStr_FormFactor (
					((CIM_PhysicalMemory*)this->_pe)->getFormFactor ());
}

/*
 * getMemoryType
 */
uint16
CPhysicalAsset::getMemoryType (void) const
{
	return ((CIM_PhysicalMemory*)this->_pe)->getMemoryType ();
}

/*
 * getMemoryTypeStr
 */
string
CPhysicalAsset::getMemoryTypeStr (void) const
{
	return CIM_PhysicalMemory::getValueStr_MemoryType (
					((CIM_PhysicalMemory*)this->_pe)->getMemoryType ());
}

/*
 * getMemorySpeed
 */
uint32
CPhysicalAsset::getMemorySpeed (void) const
{
	return ((CIM_PhysicalMemory*)this->_pe)->getSpeed ();
}

/*
 * getMemoryCapacity
 */
uint64
CPhysicalAsset::getMemoryCapacity (void) const
{
	return ((CIM_PhysicalMemory*)this->_pe)->getCapacity ();
}
/*
 * getMemoryBankLabel
 */
string
CPhysicalAsset::getMemoryBankLabel (void) const
{
	return ((CIM_PhysicalMemory*)this->_pe)->getBankLabel ();
}

/*
 * getCachedProps
 */
vector<string> 
CPhysicalAsset::getCachedProps (void)
{
	vector<string> props;
	props.push_back ("Tag");
	props.push_back ("CreationClassName");
	props.push_back ("Manufacturer");
	props.push_back ("Model");
	props.push_back ("SerialNumber");
	props.push_back ("PartNumber");
	props.push_back ("SKU");
	props.push_back ("ElementName");

	//CIM_PhysicalPackage, CIM_Physical_Component
	props.push_back ("CanBeFRUed");

	//physical package, CIM_Card, CIM_PhysicalFrame, CIM_Rack, CIM_Chassis
	props.push_back ("PackageType");
	props.push_back ("VendorCompatibilityStrings"); //CIM_Slot
	props.push_back ("Version");
	props.push_back ("Name");

	//CIM_Card
	props.push_back ("HostingBoard");

	//CIM_Rack
	props.push_back ("TypeOfRack");

	//CIM_Chassis
	props.push_back ("ChassisPackageType");

	//CIM_PhysicalComponent, CIM_Slot
	props.push_back ("ConnectorLayout");

	//CIM_PhysicalComponent, CIM_Slot
	props.push_back ("Number");

	//CIM_PhysicalMemory
	props.push_back ("FormFactor");
	props.push_back ("MemoryType");
	props.push_back ("Speed");
	props.push_back ("Capacity");
	props.push_back ("BankLabel");
	return props;
}

/*
 * CPhysicalAsset::Iterator
 */
DEFINE_API_ITERATOR (CPhysicalAsset);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CPhysicalAsset, CIM_PhysicalElement);


/*------ physical memory ----------*/
/*
 * Constructor
 */
CPhysicalMemory::CPhysicalMemory (const CIM_PhysicalMemory& pm) : CPhysicalAsset (pm)
{ 
	_pm = new CIM_PhysicalMemory (pm); 
}

/*
 * Constructor
 */
CPhysicalMemory::CPhysicalMemory (const CPhysicalMemory& pm) : CPhysicalAsset (pm)
{
	this->_pm = new CIM_PhysicalMemory (*(pm._pm));
}

/*
 * Destruction 
 */
CPhysicalMemory::~CPhysicalMemory ()
{
	if (this->_pm) { delete this->_pm; }
}

/*
 * Assignment operator
 */
const CPhysicalMemory& 
CPhysicalMemory::operator = (const CPhysicalMemory& rhs)
{
	if (this->_pm) { delete this->_pm; }
	this->_pm  = new CIM_PhysicalMemory (*rhs._pm);
	return *this;
}

/*
 * enumPhysicalAsset
 */
CPhysicalMemory::iterator 
CPhysicalMemory::enumPhysicalMemory (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_PhysicalMemory::iterator iter = 
			CIM_PhysicalMemory::enumInstances (client, 
											    0, 
											    props);
	if (cached) { return createIterator (iter, props); }
	else 		{ return createIterator (iter); 		 }
}

/*
 * getFormFactor
 */
uint16
CPhysicalMemory::getFormFactor (void) const
{
	return ((CIM_PhysicalMemory*)this->_pm)->getFormFactor ();
}

/*
 * getFormFactorStr
 */
string
CPhysicalMemory::getFormFactorStr (void) const
{
	return CIM_PhysicalMemory::getValueStr_FormFactor (
					((CIM_PhysicalMemory*)this->_pm)->getFormFactor ());
}

/*
 * getMemoryType
 */
uint16
CPhysicalMemory::getMemoryType (void) const
{
	return ((CIM_PhysicalMemory*)this->_pm)->getMemoryType ();
}

/*
 * getMemoryTypeStr
 */
string
CPhysicalMemory::getMemoryTypeStr (void) const
{
	return CIM_PhysicalMemory::getValueStr_MemoryType (
					((CIM_PhysicalMemory*)this->_pm)->getMemoryType ());
}

/*
 * getMemorySpeed
 */
uint32
CPhysicalMemory::getMemorySpeed (void) const
{
	return ((CIM_PhysicalMemory*)this->_pm)->getSpeed ();
}

/*
 * getMemoryCapacity
 */
uint64
CPhysicalMemory::getMemoryCapacity (void) const
{
	return ((CIM_PhysicalMemory*)this->_pm)->getCapacity ();
}
/*
 * getMemoryBankLabel
 */
string
CPhysicalMemory::getMemoryBankLabel (void) const
{
	return ((CIM_PhysicalMemory*)this->_pm)->getBankLabel ();
}

/*
 * getCachedProps
 */
vector<string> 
CPhysicalMemory::getCachedProps (void)
{
	vector<string> props = CPhysicalAsset::getCachedProps ();
	props.push_back ("FormFactor");
	props.push_back ("MemoryType");
	props.push_back ("Speed");
	props.push_back ("Capacity");
	props.push_back ("BankLabel");
	return props;
}

/*
 * CPhysicalMemory::Iterator
 */
DEFINE_API_ITERATOR (CPhysicalMemory);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CPhysicalMemory, CIM_PhysicalMemory);


/* ---------- Card -----------*/
/*
 * Constructor
 */
CCard::CCard (const CIM_Card& card) : CPhysicalAsset (card)
{ 
	_card = new CIM_Card (card); 
}

/*
 * Constructor
 */
CCard::CCard (const CCard& card) : CPhysicalAsset (card)
{
	this->_card = new CIM_Card (*(card._card));
}

/*
 * Destruction 
 */
CCard::~CCard ()
{
	if (this->_card) { delete this->_card; }
}

/*
 * Assignment operator
 */
const CCard& 
CCard::operator = (const CCard& rhs)
{
	if (this->_card) { delete this->_card; }
	this->_card  = new CIM_Card (*rhs._card);
	return *this;
}

/*
 * enumPhysicalAsset
 */
CCard::iterator 
CCard::enumCards (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_Card::iterator iter = 
			CIM_Card::enumInstances (client, 
											    0, 
											    props);
	if (cached) { return createIterator (iter, props); }
	else 		{ return createIterator (iter); 		 }
}

/*
 * canBeFRUed
 */
boolean 
CCard::canBeFRUed (void) const
{
	return ((CIM_PhysicalPackage*)this->_card)->getCanBeFRUed ();
}

/*
 * getPackageType
 */
uint16
CCard::getPackageType (void) const
{
	return ((CIM_PhysicalPackage*)this->_card)->getPackageType ();
}

/*
 * getPackageTypeStr
 */
string
CCard::getPackageTypeStr (void) const
{
	return CIM_PhysicalPackage::getValueStr_PackageType (
				((CIM_PhysicalPackage*)this->_card)->getPackageType ());
}

/*
 * getVendorCompatibilityStrings
 */
vector<string>
CCard::getVendorCompatibilityStrings (void) const
{
	return ((CIM_PhysicalPackage*)this->_card)->getVendorCompatibilityStrings ();
}

/*
 * getVersion
 */
string
CCard::getVersion (void) const
{
	return ((CIM_PhysicalPackage*)this->_card)->getVersion ();
}

/*
 * getName
 */
string
CCard::getName (void) const
{
	return ((CIM_PhysicalPackage*)this->_card)->getName ();
}

/*
 * isHostingBoard
 */
boolean
CCard::isHostingBoard (void) const
{
	return ((CIM_Card*)this->_card)->getHostingBoard ();
}


/*
 * getCachedProps
 */
vector<string> 
CCard::getCachedProps (void)
{
	vector<string> props = CPhysicalAsset::getCachedProps ();
	props.push_back ("CanBeFRUed");
	props.push_back ("PackageType");
	props.push_back ("VendorCompatibilityStrings");
	props.push_back ("Version");
	props.push_back ("Name");
	props.push_back ("HostingBoard");
	return props;
}

/*
 * CCard::Iterator
 */
DEFINE_API_ITERATOR (CCard);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CCard, CIM_Card);


/* --------- Physical Frame --------- */
/*
 * Constructor
 */
CPhysicalFrame::CPhysicalFrame (const CIM_PhysicalFrame& pf) : CPhysicalAsset (pf)
{ 
	_pf = new CIM_PhysicalFrame (pf); 
}

/*
 * Constructor
 */
CPhysicalFrame::CPhysicalFrame (const CPhysicalFrame& pf) : CPhysicalAsset (pf)
{
	this->_pf = new CIM_PhysicalFrame (*(pf._pf));
}

/*
 * Destruction 
 */
CPhysicalFrame::~CPhysicalFrame ()
{
	if (this->_pf) { delete this->_pf; }
}

/*
 * Assignment operator
 */
const CPhysicalFrame& 
CPhysicalFrame::operator = (const CPhysicalFrame& rhs)
{
	if (this->_pf) { delete this->_pf; }
	this->_pf  = new CIM_PhysicalFrame (*rhs._pf);
	return *this;
}

/*
 * enumPhysicalAsset
 */
CPhysicalFrame::iterator 
CPhysicalFrame::enumPhysicalFrames (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_PhysicalFrame::iterator iter = 
			CIM_PhysicalFrame::enumInstances (client, 
											    0, 
											    props);
	if (cached) { return createIterator (iter, props); }
	else 		{ return createIterator (iter); 		 }
}

/*
 * canBeFRUed
 */
boolean 
CPhysicalFrame::canBeFRUed (void) const
{
	return ((CIM_PhysicalPackage*)this->_pf)->getCanBeFRUed ();
}

/*
 * getPackageType
 */
uint16
CPhysicalFrame::getPackageType (void) const
{
	return ((CIM_PhysicalPackage*)this->_pf)->getPackageType ();
}

/*
 * getPackageTypeStr
 */
string
CPhysicalFrame::getPackageTypeStr (void) const
{
	return CIM_PhysicalPackage::getValueStr_PackageType (
				((CIM_PhysicalPackage*)this->_pf)->getPackageType ());
}

/*
 * getVendorCompatibilityStrings
 */
vector<string>
CPhysicalFrame::getVendorCompatibilityStrings (void) const
{
	return ((CIM_PhysicalPackage*)this->_pf)->getVendorCompatibilityStrings ();
}

/*
 * getVersion
 */
string
CPhysicalFrame::getVersion (void) const
{
	return ((CIM_PhysicalPackage*)this->_pf)->getVersion ();
}

/*
 * getName
 */
string
CPhysicalFrame::getName (void) const
{
	return ((CIM_PhysicalPackage*)this->_pf)->getName ();
}


/*
 * getCachedProps
 */
vector<string> 
CPhysicalFrame::getCachedProps (void)
{
	vector<string> props = CPhysicalAsset::getCachedProps ();

	props.push_back ("CanBeFRUed");
	props.push_back ("PackageType");
	props.push_back ("VendorCompatibilityStrings");
	props.push_back ("Version");
	props.push_back ("Name");

	return props;
}

/*
 * CPhysicalFrame::Iterator
 */
DEFINE_API_ITERATOR (CPhysicalFrame);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CPhysicalFrame, CIM_PhysicalFrame);



/* --------- Chassis --------- */
/*
 * Constructor
 */
CChassis::CChassis (const CIM_Chassis& chassis) : CPhysicalFrame (chassis) 
{ 
	_chassis = new CIM_Chassis (chassis); 
}

/*
 * Constructor
 */
CChassis::CChassis (const CChassis& chassis) : CPhysicalFrame (chassis)
{
	this->_chassis = new CIM_Chassis (*(chassis._chassis));
}

/*
 * Destruction 
 */
CChassis::~CChassis ()
{
	if (this->_chassis) { delete this->_chassis; }
}

/*
 * Assignment operator
 */
const CChassis& 
CChassis::operator = (const CChassis& rhs)
{
	if (this->_chassis) { delete this->_chassis; }
	this->_chassis  = new CIM_Chassis (*rhs._chassis);
	return *this;
}

/*
 * enumChassis
 */
CChassis::iterator 
CChassis::enumChassis (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_Chassis::iterator iter = 
			CIM_Chassis::enumInstances (client, 
											    0, 
											    props);
	if (cached) { return createIterator (iter, props); }
	else 		{ return createIterator (iter); 		 }
}

/*
 * getChassisPackageType
 */
uint16
CChassis::getChassisPackageType (void) const
{
	return ((CIM_Chassis*)this->_chassis)->getChassisPackageType ();
}

/*
 * getChassisPackageTypeStr
 */
string
CChassis::getChassisPackageTypeStr (void) const
{
	return CIM_Chassis::getValueStr_ChassisPackageType (
				((CIM_Chassis*)this->_chassis)->getChassisPackageType ());
}

/*
 * getCachedProps
 */
vector<string> 
CChassis::getCachedProps (void)
{
	vector<string> props = CPhysicalFrame::getCachedProps ();

	props.push_back ("ChassisPackageType");

	return props;
}

/*
 * CChassis::Iterator
 */
DEFINE_API_ITERATOR (CChassis);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CChassis, CIM_Chassis);



/* --------- Chassis --------- */
/*
 * Constructor
 */
CRack::CRack (const CIM_Rack& rack) : CPhysicalFrame (rack) 
{ 
	_rack = new CIM_Rack (rack); 
}

/*
 * Constructor
 */
CRack::CRack (const CRack& rack) : CPhysicalFrame (rack)
{
	this->_rack = new CIM_Rack (*(rack._rack));
}

/*
 * Destruction 
 */
CRack::~CRack ()
{
	if (this->_rack) { delete this->_rack; }
}

/*
 * Assignment operator
 */
const CRack& 
CRack::operator = (const CRack& rhs)
{
	if (this->_rack) { delete this->_rack; }
	this->_rack  = new CIM_Rack (*rhs._rack);
	return *this;
}

/*
 * enumChassis
 */
CRack::iterator 
CRack::enumRacks (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_Rack::iterator iter = 
			CIM_Rack::enumInstances (client, 
											    0, 
											    props);
	if (cached) { return createIterator (iter, props); }
	else 		{ return createIterator (iter); 		 }
}

/*
 * getTypeOfRack
 */
uint16
CRack::getTypeOfRack (void) const
{
	return ((CIM_Rack*)this->_rack)->getTypeOfRack ();
}

/*
 * getTypeOfRackStr
 */
string
CRack::getTypeOfRackStr (void) const
{
	return CIM_Rack::getValueStr_TypeOfRack (
				((CIM_Rack*)this->_rack)->getTypeOfRack ());
}

/*
 * getCachedProps
 */
vector<string> 
CRack::getCachedProps (void)
{
	vector<string> props = CPhysicalFrame::getCachedProps ();

	props.push_back ("ChassisPackageType");

	return props;
}

/*
 * CRack::Iterator
 */
DEFINE_API_ITERATOR (CRack);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CRack, CIM_Rack);


/*
 * Constructor
 */
CSlot::CSlot (const CIM_Slot& slot) : CPhysicalAsset (slot)
{ 
	_slot = new CIM_Slot (slot); 
}

/*
 * Constructor
 */
CSlot::CSlot (const CSlot& slot) : CPhysicalAsset (slot)
{
	this->_slot = new CIM_Slot (*(slot._slot));
}

/*
 * Destruction 
 */
CSlot::~CSlot ()
{
	if (this->_slot) { delete this->_slot; }
}

/*
 * Assignment operator
 */
const CSlot& 
CSlot::operator = (const CSlot& rhs)
{
	if (this->_slot) { delete this->_slot; }
	this->_slot  = new CIM_Slot (*rhs._slot);
	return *this;
}

/*
 * enumSlot
 */
CSlot::iterator 
CSlot::enumSlot (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_Slot::iterator iter = 
			CIM_Slot::enumInstances (client, 0, 
											props);
	if (cached) { return createIterator (iter, props); }
	else 		{ return createIterator (iter); 		 }
}

/*
 * getVendorCompatibilityStrings
 */
vector<string>
CSlot::getVendorCompatibilityStrings (void) const
{
	return ((CIM_PhysicalPackage*)this->_slot)->getVendorCompatibilityStrings ();
}

/*
 * getConnectorLayout
 */
uint16
CSlot::getConnectorLayout (void) const
{
	return ((CIM_PhysicalConnector*)this->_slot)->getConnectorLayout ();
}

/*
 * getConnectorLayoutStr
 */
string
CSlot::getConnectorLayoutStr (void) const
{
	return CIM_PhysicalConnector::getValueStr_ConnectorLayout (
				((CIM_PhysicalConnector*)this->_slot)->getConnectorLayout ());
}

/*
 * getSlotNumber
 */
uint16
CSlot::getSlotNumber (void) const
{
	return ((CIM_Slot*)this->_slot)->getNumber ();
}


/*
 * getCachedProps
 */
vector<string> 
CSlot::getCachedProps (void)
{
	vector<string> props = CPhysicalAsset::getCachedProps ();
	props.push_back ("VendorCompatibilityStrings");
	props.push_back ("ConnectorLayout");
	props.push_back ("Number");
	return props;
}

/*
 * CSlot::Iterator
 */
DEFINE_API_ITERATOR (CSlot);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CSlot, CIM_Slot);
