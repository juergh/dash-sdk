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
 * physicalasset.h
 * A class representing a physical asset
 **/
#ifndef __DSDK_PHYSICALASSET_H__
#define __DSDK_PHYSICALASSET_H__
#include <dsdk/dsdkiterator.h>
#include <dsdk/dsdk_api.h>

namespace dsdk 
{

class CIM_PhysicalElement;
class CPhysicalAsset;
typedef CAPIIterator<CPhysicalAsset, CIM_PhysicalElement> _CPhysicalAssetIterator;

/**
 * @class CPhysicalAsset
 * @brief A Physical Asset.
 **/
class DSDK_Export CPhysicalAsset
{
 public:
	DECLARE_API_ITERATOR (CPhysicalAsset);
	typedef CIM_PhysicalElement CIMType;
	
	/**
	 * Enumerates all the physical assets present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the physical assets.
	 */
	static CPhysicalAsset::iterator enumPhysicalAssets (IClient* client,
										 	    	    bool cached = true);
	/**
	 * Return the underlying CIM object
	 */
	CIM_PhysicalElement* getCIMObject (void) const { return _pe; }

public:
	/**
	 * Gets the physical asset Tag
	 * @return The physical asset Tag
	 */
	string getTag (void) const;

	/**
	 * Gets the physical asset CreationClassName 
	 * @return The physical asset CreationClassName
	 */
	string getCreationClassName (void) const;

	/**
	 * Get the manufacturer of the physical asset.
	 * @return		The manufacturer string. 
	 */
	string getManufacturer (void) const;

	/**
 	 * Gets the model of the physical asset. 
 	 * @return 	The model string.
 	 */
 	string getModel (void) const;
 	
 	/**
 	 * Gets the serial number of the physical asset.
 	 * @return		The serial number string.
 	 */
 	string getSerialNumber (void) const;
 	
 	/**
 	 * Gets the part number of the physical asset.
 	 * @return		The part number string.
 	 */
 	string getPartNumber (void) const;

	/** 
 	 * Gets the SKU info of the physical asset.
 	 * @return		The SKU String.
 	 */
 	string getSKU (void) const;
 	
 	/**
 	 * Gets the ElementName.
 	 * @return The ElementName.
 	 */
 	string getElementName (void) const;

 	/** 
 	 * Check if physical asset can be FRUed.
 	 * @return If physical asset can be FRUed
 	 */
 	boolean canBeFRUed (void) const;

 	/**
 	 * Gets the package type
 	 * @return The package type.
 	 */
 	uint16 getPackageType (void) const;

 	/**
 	 * Gets the package type as string
 	 * @return The package type.
 	 */
 	string getPackageTypeStr (void) const;

 	/**
 	 * Gets the VendorCompatibilityStrings
 	 * @return The VendorCompatibilityStrings
 	 */
 	vector<string> getVendorCompatibilityStrings (void) const;

 	/**
 	 * Gets the version of physical package
 	 * @return The version
 	 */
 	string getVersion (void) const;

 	/**
 	 * Gets the name of physical package
 	 * @return The name
 	 */
 	string getName (void) const;

 	/**
 	 * Gets the card's HostingBoard
 	 * @return The HostingBoard
 	 */
 	boolean isHostingBoard (void) const;

 	/**
 	 * Gets the Rack type of the Rack
 	 * @return The TypeOfRack
 	 */
 	uint16 getTypeOfRack (void) const;

 	/**
 	 * Gets the Rack type of the Rack as string
 	 * @return The TypeOfRack
 	 */
 	string getTypeOfRackStr (void) const;

	/**
 	 * Gets the chassis  type
 	 * @return The ChassisType
 	 */
	vector<uint16> getChassisTypes  (void) const;
	
	/**
 	 * Gets the chassis  type as string
 	 * @return The ChassisTypeStr
 	 */
	vector<string> getChassisTypesStr (void) const;

	/**
 	 * Gets the chassis package type as string
 	 * @return The ChassisPackageType
 	 */
 	uint16 getChassisPackageType (void) const;

	/**
 	 * Gets the chassis package type as string
 	 * @return The ChassisPackageType
 	 */
 	string getChassisPackageTypeStr (void) const;

 	/**
 	 * Gets the physical connector layout
 	 * @return The ConnectorLayout
 	 */
 	uint16 getConnectorLayout (void) const;

 	/**
 	 * Gets the physical connector layout as string
 	 * @return The ConnectorLayout
 	 */
 	string getConnectorLayoutStr (void) const;

	/**
 	 * Gets the slot number
 	 * @return The slot number
 	 */
 	uint16 getSlotNumber (void) const;

 	/**
 	 * Gets the memory form factor
 	 * @return The FormFactor
 	 */
 	uint16 getFormFactor (void) const;

 	/**
 	 * Gets the memory form factor as string
 	 * @return The FormFactor
 	 */
 	string getFormFactorStr (void) const;

	/**
 	 * Gets the memory type
 	 * @return The MemoryType
 	 */
 	uint16 getMemoryType (void) const;

 	/**
 	 * Gets the memory type as string
 	 * @return The MemoryType
 	 */
 	string getMemoryTypeStr (void) const;

	/**
 	 * Gets the memory speed
 	 * @return The memory speed
 	 */
 	uint32 getMemorySpeed (void) const;

 	/**
 	 * Gets the memory capacity
 	 * @return The memory capacity
 	 */
 	uint64 getMemoryCapacity (void) const;

 	/**
 	 * Gets the memory Bank Label
 	 * @return The memory BankLabel
 	 */
 	string getMemoryBankLabel (void) const;


public:
	/**
	 * Construct this object from the corresponding CIM_PhysicalElement
	 * object
	 */
	CPhysicalAsset (const CIM_PhysicalElement& pe);

	/**
	 * Copy constructor
	 */
	CPhysicalAsset (const CPhysicalAsset& pa);

	/**
	 * Destructor
	 */
	~CPhysicalAsset ();

	/**
	 * Assignment operator
	 */
	const CPhysicalAsset& operator = (const CPhysicalAsset& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void);

private:
	CIM_PhysicalElement* _pe;
}; 


class CIM_PhysicalMemory;
class CPhysicalMemory;
typedef CAPIIterator<CPhysicalMemory, CIM_PhysicalMemory> _CPhysicalMemoryIterator;

/**
 * @class CPhysicalMemory
 * @brief A Physical Memory.
 **/
class DSDK_Export CPhysicalMemory : public CPhysicalAsset
{
 public:
	DECLARE_API_ITERATOR (CPhysicalMemory);
	typedef CIM_PhysicalMemory CIMType;
	
	/**
	 * Enumerates all the physical memory present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the physical memory.
	 */
	static CPhysicalMemory::iterator enumPhysicalMemory (IClient* client,
								 	    				bool cached = true);
	/**
	 * Return the underlying CIM object
	 */
	CIM_PhysicalMemory* getCIMObject (void) const { return _pm; }

public:
	/**
	 * Gets the memory form factor
	 * @return The FormFactor
	 */
	uint16 getFormFactor (void) const;

 	/**
 	 * Gets the memory form factor as string
 	 * @return The FormFactor
 	 */
 	string getFormFactorStr (void) const;

	/**
	 * Gets the memory type
	 * @return The MemoryType
	 */
	uint16 getMemoryType (void) const;

	/**
	 * Gets the memory type as string
	 * @return The MemoryType
	 */
	string getMemoryTypeStr (void) const;

	/**
	 * Gets the memory speed
	 * @return The memory speed
	 */
	uint32 getMemorySpeed (void) const;

	/**
	 * Gets the memory capacity
	 * @return The memory capacity
	 */
	uint64 getMemoryCapacity (void) const;

	/**
	 * Gets the memory Bank Label
	 * @return The memory BankLabel
	 */
	string getMemoryBankLabel (void) const;


public:
	/**
	 * Construct this object from the corresponding CIM_PhysicalMemory
	 * object
	 */
	CPhysicalMemory (const CIM_PhysicalMemory& pm);

	/**
	 * Copy constructor
	 */
	CPhysicalMemory (const CPhysicalMemory& pa);

	/**
	 * Destructor
	 */
	~CPhysicalMemory ();

	/**
	 * Assignment operator
	 */
	const CPhysicalMemory& operator = (const CPhysicalMemory& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void);

private:
	CIM_PhysicalMemory* _pm;
}; 


class CIM_Card;
class CCard;
typedef CAPIIterator<CCard, CIM_Card> _CCardIterator;

/**
 * @class CCard
 * @brief A Physical Asset.
 **/
class DSDK_Export CCard : public CPhysicalAsset
{
 public:
	DECLARE_API_ITERATOR (CCard);
	typedef CIM_Card CIMType;
	
	/**
	 * Enumerates all the physical assets present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the physical assets.
	 */
	static CCard::iterator enumCards (IClient* client,
										 	    	    bool cached = true);
	/**
	 * Return the underlying CIM object
	 */
	CIM_Card* getCIMObject (void) const { return _card; }

public:
 	/** 
 	 * Check if physical asset can be FRUed.
 	 * @return If physical asset can be FRUed
 	 */
 	boolean canBeFRUed (void) const;

 	/**
 	 * Gets the package type
 	 * @return The package type.
 	 */
 	uint16 getPackageType (void) const;

 	/**
 	 * Gets the package type as string
 	 * @return The package type.
 	 */
 	string getPackageTypeStr (void) const;

 	/**
 	 * Gets the VendorCompatibilityStrings
 	 * @return The VendorCompatibilityStrings
 	 */
 	vector<string> getVendorCompatibilityStrings (void) const;

 	/**
 	 * Gets the version of physical package
 	 * @return The version
 	 */
 	string getVersion (void) const;

 	/**
 	 * Gets the name of physical package
 	 * @return The name
 	 */
 	string getName (void) const;

 	/**
 	 * Gets the card's HostingBoard
 	 * @return The HostingBoard
 	 */
 	boolean isHostingBoard (void) const;


public:
	/**
	 * Construct this object from the corresponding CIM_Card
	 * object
	 */
	CCard (const CIM_Card& card);

	/**
	 * Copy constructor
	 */
	CCard (const CCard& pa);

	/**
	 * Destructor
	 */
	~CCard ();

	/**
	 * Assignment operator
	 */
	const CCard& operator = (const CCard& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void);

private:
	CIM_Card* _card;
}; 


class CIM_PhysicalFrame;
class CPhysicalFrame;
typedef CAPIIterator<CPhysicalFrame, CIM_PhysicalFrame> _CPhysicalFrameIterator;

/**
 * @class CPhysicalFrame
 * @brief A Physical Memory.
 **/
class DSDK_Export CPhysicalFrame : public CPhysicalAsset
{
 public:
	DECLARE_API_ITERATOR (CPhysicalFrame);
	typedef CIM_PhysicalFrame CIMType;
	
	/**
	 * Enumerates all the physical frame present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the physical frame.
	 */
	static CPhysicalFrame::iterator enumPhysicalFrames (IClient* client,
								 	    				bool cached = true);
	/**
	 * Return the underlying CIM object
	 */
	CIM_PhysicalFrame* getCIMObject (void) const { return _pf; }

public:
 	/** 
 	 * Check if physical asset can be FRUed.
 	 * @return If physical asset can be FRUed
 	 */
 	boolean canBeFRUed (void) const;

 	/**
 	 * Gets the frame type
 	 * @return The frame type.
 	 */
 	uint16 getPackageType (void) const;

 	/**
 	 * Gets the frame type as string
 	 * @return The frame type.
 	 */
 	string getPackageTypeStr (void) const;

 	/**
 	 * Gets the VendorCompatibilityStrings
 	 * @return The VendorCompatibilityStrings
 	 */
 	vector<string> getVendorCompatibilityStrings (void) const;

 	/**
 	 * Gets the version of frame
 	 * @return The version
 	 */
 	string getVersion (void) const;

 	/**
 	 * Gets the name of frame
 	 * @return The name
 	 */
 	string getName (void) const;


public:
	/**
	 * Construct this object from the corresponding CIM_PhysicalFrame
	 * object
	 */
	CPhysicalFrame (const CIM_PhysicalFrame& pf);

	/**
	 * Copy constructor
	 */
	CPhysicalFrame (const CPhysicalFrame& pa);

	/**
	 * Destructor
	 */
	~CPhysicalFrame ();

	/**
	 * Assignment operator
	 */
	const CPhysicalFrame& operator = (const CPhysicalFrame& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void);

private:
	CIM_PhysicalFrame* _pf;
}; 


class CIM_Chassis;
class CChassis;
typedef CAPIIterator<CChassis, CIM_Chassis> _CChassisIterator;

/**
 * @class CChassis
 * @brief A Chassis.
 **/
class DSDK_Export CChassis : public CPhysicalFrame
{
 public:
	DECLARE_API_ITERATOR (CChassis);
	typedef CIM_Chassis CIMType;
	
	/**
	 * Enumerates all the chassis present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the chassis.
	 */
	static CChassis::iterator enumChassis (IClient* client,
								 	    				bool cached = true);
	/**
	 * Return the underlying CIM object
	 */
	CIM_Chassis* getCIMObject (void) const { return _chassis; }

public:
	/**
 	 * Gets the chassis package type
 	 * @return The ChassisPackageType
 	 */
 	uint16 getChassisPackageType (void) const;

	/**
 	 * Gets the chassis package type as string
 	 * @return The ChassisPackageType
 	 */
 	string getChassisPackageTypeStr (void) const;

public:
	/**
	 * Construct this object from the corresponding CIM_Chassis
	 * object
	 */
	CChassis (const CIM_Chassis& chassis);

	/**
	 * Copy constructor
	 */
	CChassis (const CChassis& pa);

	/**
	 * Destructor
	 */
	~CChassis ();

	/**
	 * Assignment operator
	 */
	const CChassis& operator = (const CChassis& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void);

private:
	CIM_Chassis* _chassis;
}; 

class CIM_Rack;
class CRack;
typedef CAPIIterator<CRack, CIM_Rack> _CRackIterator;

/**
 * @class CRack
 * @brief A Chassis.
 **/
class DSDK_Export CRack : public CPhysicalFrame
{
 public:
	DECLARE_API_ITERATOR (CRack);
	typedef CIM_Rack CIMType;
	
	/**
	 * Enumerates all the rack present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the rack.
	 */
	static CRack::iterator enumRacks (IClient* client,
								 	    				bool cached = true);
	/**
	 * Return the underlying CIM object
	 */
	CIM_Rack* getCIMObject (void) const { return _rack; }

public:
	/**
	 * Gets the Rack type of the Rack
	 * @return The TypeOfRack
	 */
	uint16 getTypeOfRack (void) const;

	/**
	 * Gets the Rack type of the Rack as string
	 * @return The TypeOfRack
	 */
	string getTypeOfRackStr (void) const;

public:
	/**
	 * Construct this object from the corresponding CIM_Rack
	 * object
	 */
	CRack (const CIM_Rack& rack);

	/**
	 * Copy constructor
	 */
	CRack (const CRack& pa);

	/**
	 * Destructor
	 */
	~CRack ();

	/**
	 * Assignment operator
	 */
	const CRack& operator = (const CRack& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void);

private:
	CIM_Rack* _rack;
}; 

class CIM_Slot;
class CSlot;
typedef CAPIIterator<CSlot, CIM_Slot> _CSlotIterator;

/**
 * @class CSlot
 * @brief A Slot.
 **/
class DSDK_Export CSlot : public CPhysicalAsset
{
 public:
	DECLARE_API_ITERATOR (CSlot);
	typedef CIM_Slot CIMType;
	
	/**
	 * Enumerates all the slot present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the slots.
	 */
	static CSlot::iterator enumSlot (IClient* client,
										 	    	    bool cached = true);
	/**
	 * Return the underlying CIM object
	 */
	CIM_Slot* getCIMObject (void) const { return _slot; }

public:
 	/**
 	 * Gets the VendorCompatibilityStrings
 	 * @return The VendorCompatibilityStrings
 	 */
 	vector<string> getVendorCompatibilityStrings (void) const;

 	/**
 	 * Gets the physical connector layout
 	 * @return The ConnectorLayout
 	 */
 	uint16 getConnectorLayout (void) const;

 	/**
 	 * Gets the physical connector layout as string
 	 * @return The ConnectorLayout
 	 */
 	string getConnectorLayoutStr (void) const;

	/**
 	 * Gets the slot number
 	 * @return The slot number
 	 */
 	uint16 getSlotNumber (void) const;

public:
	/**
	 * Construct this object from the corresponding CIM_Slot
	 * object
	 */
	CSlot (const CIM_Slot& slot);

	/**
	 * Copy constructor
	 */
	CSlot (const CSlot& pa);

	/**
	 * Destructor
	 */
	~CSlot ();

	/**
	 * Assignment operator
	 */
	const CSlot& operator = (const CSlot& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void);

private:
	CIM_Slot* _slot;
}; 



};	/* namespace dsdk */

#endif /* __DSDK_PHYSICALASSET_H__ */

