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
 * bootconfig.h
 * Class representing a Boot Control.
 */
#ifndef __DSDK_BOOTCONFIG_H__
#define __DSDK_BOOTCONFIG_H__
#include <dsdk/dsdkiterator.h>
#include <dsdk/dsdk_api.h>
#include <dsdk/dsdktypes.h>
#include <dsdk/computersystem.h>
#include <dsdk/oal/CIM_BootService.h>
#include <list>
#include <dsdk/oal/CIM_BootServiceCapabilities.h>

using std::list;

namespace dsdk 
{

class CIM_BootConfigSetting;
class CIM_BootSourceSetting;
class CBootConfig;
class CBootDevice;
typedef CAPIIterator<CBootConfig, CIM_BootConfigSetting> _CBootConfigIterator;
typedef CAPIIterator<CBootDevice, CIM_BootSourceSetting> _CBootDeviceIterator;

/**
  * @class CBootDevice
  * @brief A class representing a boot device (CIM_BootDourceSetting)
  */
class DSDK_Export CBootDevice 
{
public:
	DECLARE_API_ITERATOR (CBootDevice);
	typedef CIM_BootSourceSetting CIMType;

public:
	/**
	 * Enumerates all the boot device present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the boot device.
	 */
	static CBootDevice::iterator enumBootDevices (IClient* client, bool cached = true);

public:
	/**
	 * Gets the instance id
	 * @return The instance id
	 */
	string getInstanceID (void) const;

	/**
	 * Gets the element name 
	 * @return The element name
	 */
	string getElementName (void) const;

	/**
	 * Gets the Boot String 
	 * @return The boot string
	 */
	string getBootString (void) const;

	/**
	 * Gets the BIOS Boot String 
	 * @return The BIOS boot string
	 */
	string getBIOSBootString (void) const;

	/**
	 * Gets the Structured Boot String 
	 * @return The structured boot string
	 */
	string getStructuredBootString (void) const;

	/**
	 * Gets the Fail through supported
	 * @return The fail through supported
	 */
	uint16 getFailThroughSupported (void) const;

	/**
	 * Gets the Fail through supported as string
	 * @return The fail through supported
	 */
	string getFailThroughSupportedStr (void) const;

public:
	/**
	 * Construct this object from the corresponding CIM_BootConfigSetting object
	 */
	CBootDevice (const CIM_BootSourceSetting& bss, uint64 sequence = 0);

	/**
	 * Copy constructor
	 */
	CBootDevice (const CBootDevice& bd);

	/**
	 * Destructor
	 */
	~CBootDevice ();

	/**
	 * Assignment operator
	 */
	const CBootDevice& operator = (const CBootDevice& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void) ;

	/**
	 * Compate the boot order of the  Boot Devices
	 */
	static bool compareBootOrder (const CBootDevice& first, 
											   const CBootDevice& second);


private:
	uint64					_assigned_sequence;
	CIM_BootSourceSetting*	_bss;
};


/**
  * @class CBootConfig
  * @brief A class representing a boot configuration (CIM_BootConfigSetting)
  */
class DSDK_Export CBootConfig 
{
public:
	DECLARE_API_ITERATOR (CBootConfig);
	typedef CIM_BootConfigSetting CIMType;

public:
	/**
	 * Enumerates all the boot configuration present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the boot config.
	 */
	static CBootConfig::iterator enumBootConfigs (IClient* client, bool cached = true);

public:
	/**
	 * Gets the instance id
	 * @return The instance id
	 */
	string getInstanceID (void) const;

	/**
	 * Gets the element name 
	 * @return The element name
	 */
	string getElementName (void) const;

	/**
	 * Is this default boot configuration 
	 * @return is default boot
	 */
	bool isDefaultBoot (void) const;

	/**
	 * Is this current boot configuration 
	 * @return is current boot
	 */
	bool isCurrentBoot (void) const;

	/**
	 * Is this next boot configuration 
	 * @return is next boot
	 */
	bool isNextBoot (void) const;

	/**
	 * Set this configuration as default configuration
	 */
	uint32 setDefaultBoot (void);

	/**
	 * Set this configuration next boot.
	 */
	uint32 setNextBoot (void);

	/**
	 * get boot order
	 * @return boot order list
	 */
	vector<CBootDevice> getBootOrder (void) const;

	/**
	 * change boot order
	 * @param boot_order new boot order list
	 */
	uint32 changeBootOrder (const vector<CBootDevice>& boot_order);

		/**
	 * change boot order
	 * @param boot_order new boot order list
	 */
//	vector<uint16> changeBootOrderSupport (void) const;
	bool capableOfchangeBootOrder () ;

	/**
	 * add boot config
	 * @param cs compuer system where the new config to be added
	 */
	static CBootConfig addBootConfig (const CComputerSystem& cs);

	/**
	 * add boot config
	 * @param cs Compuer system where the new config to be added
     * @param bc Existing boot configuration used as template
	 */
	static CBootConfig addBootConfig (const CComputerSystem& cs, const CBootConfig& bc);

	/**
	 * delete this boot config
	 */
	void deleteBootConfig (void);


	/**
	 * Verifies whether SetDefaultBoot operation can be performed or not.
	 * @param bs		if the operation is supported, bs contains the corresponding
	 *					instance using which this operation can be perfroemd.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfSetDefaultBoot(CIM_BootService &bs);

	/**
	 * Verifies whether SetDefaultBoot operation can be performed or not.
	 * @return	true - if supported
	 *			false - if not supported.
	 */
	bool capableOfSetDefaultBoot();

	/**
	 * Verifies whether SetNextBoot operation can be performed or not.
	 * @param bs		if the operation is supported, bs contains the corresponding
	 *					instance using which this operation can be perfroemd.
	 * @return	true - if supported
	 *			false - if not supported.
	 */
	bool capableOfSetNextBoot(CIM_BootService &bs);

	/**
	 * Verifies whether SetNextBoot operation can be performed or not.
	 * @return	true - if supported
	 *			false - if not supported.
	 */
	bool capableOfSetNextBoot();

	/**
	 * Verifies whether AddBootConfig operation can be performed or not.
	 * @param cs		This method uses client parameter of the cs instance. Hence
	 *					this value should be populated before passing as parameter 
	 *					to this method.
	 * @param bs		if the operation is supported, bs contains the corresponding
	 *					instance using which this operation can be perfroemd.
	 * @return	true - if supported
	 *			false - if not supported.
	 */
	bool capableOfAddBootConfig(const CComputerSystem &cs, CIM_BootService  &bs);
	
	/**
	 * Verifies whether AddBootConfig operation can be performed or not.
	 * @param cs		This method uses client parameter of the cs instance. Hence
	 *					this value should be populated before passing as parameter 
	 *					to this method.
	 * @return	true - if supported
	 *			false - if not supported.
	 */
	bool capableOfAddBootConfig(const CComputerSystem &cs);

	/**
	* verifies whether the BootService and BootServiceCapabilities instances are exists or not.
	* @param cs		This method uses client parameter of the cs instance. Hence
	*					this value should be populated before passing as parameter 
	*					to this method.
	*		 bs		CIM_BootService output parameter passed as reference, if service exists, it returns instance.
	*		 bsc	CIM_BootServiceCapabilities output parameter passed as reference, if service exists, it returns instance.
	* @return true  - if the both the BS and BSC instances are exists.
	*		 false - if either one instance does not exists.
	**/
	bool capableOfBootConfigManagement(const CComputerSystem &cs, CIM_BootService &bs, CIM_BootServiceCapabilities &bsc);

	/**
	* verifies whether the BootService and BootServiceCapabilities instances are exists or not.
	* @param cs		This method uses client parameter of the cs instance. Hence
	*					this value should be populated before passing as parameter 
	*					to this method.
	* @return true  - if the both the BS and BSC instances are exists.
	*		 false - if either one instance does not exists.
	**/
	bool capableOfBootConfigManagement(const CComputerSystem &cs);
	
	/**
	* verifies whether the deleteBootConfig() method is supported or not by BootService .
	* @param cs		This method uses client parameter of the cs instance. Hence
	*					this value should be populated before passing as parameter 
	*					to this method.
	* @return true  - if deleteBootConfig() method is supported. 
	*		 false - if deleteBootConfig() method is not supported 
	**/
	bool capableOfDeleteBootConfig(const CComputerSystem &cs);

	/**
	* This method returns the integer values of the BootCapabilitiesSupported properties.
	* @param cs		This method uses client parameter of the cs instance. Hence
	*					this value should be populated before passing as parameter 
	*					to this method.
	*		 states_val	if the BootCapabilitiesSupported properties exists, the values are returnd as insteger vector.
	* @return	true  - if the BootCapabilitiesSupported properties exists and have at least one value.
	*			false - it the BootCapabilitiesSupported properties does not exists.
	**/
	bool getBootCapabilitiesSupported(const CComputerSystem &cs, vector<uint16> &states_val);
	
	/**
	* This method returns the string values of the BootCapabilitiesSupported properties.
	* @param cs		This method uses client parameter of the cs instance. Hence
	*					this value should be populated before passing as parameter 
	*					to this method.
	*		 states_str	if the BootCapabilitiesSupported properties exists, the values are returnd as string vector.
	* @return	true  - if the BootCapabilitiesSupported properties exists and have at least one value.
	*			false - it the BootCapabilitiesSupported properties does not exists.
	**/
	bool getBootCapabilitiesSupportedStr(const CComputerSystem &cs, vector<string> &states_str);

	/**
	* This method returns the integer values of the BootStringsSupportedd properties.
	* @param cs		This method uses client parameter of the cs instance. Hence
	*					this value should be populated before passing as parameter 
	*					to this method.
	*		 states_val	if the BootStringsSupported properties exists, the values are returnd as insteger vector.
	* @return	true  - if the BootStringsSupported properties exists and have at least one value.
	*			false - it the BootStringsSupportedd properties does not exists.
	**/
	bool getBootStringsSupported(const CComputerSystem &cs, vector<uint16> &states_val);
	
	/**
	* This method returns the string values of the BootStringsSupportedd properties.
	* @param cs		This method uses client parameter of the cs instance. Hence
	*					this value should be populated before passing as parameter 
	*					to this method.
	*		 states_str	if the BootStringsSupported properties exists, the values are returnd as string vector.
	* @return	true  - if the BootStringsSupported properties exists and have at least one value.
	*			false - it the BootStringsSupportedd properties does not exists.
	**/
	bool getBootStringsSupportedStr(const CComputerSystem &cs, vector<string> &states_str);

	
public:
	/**
	 * Construct this object from the corresponding CIM_BootConfigSetting object
	 */
	CBootConfig (const CIM_BootConfigSetting& bcs);

	/**
	 * Copy constructor
	 */
	CBootConfig (const CBootConfig& bc);

	/**
	 * Destructor
	 */
	~CBootConfig ();

	/**
	 * Assignment operator
	 */
	const CBootConfig& operator = (const CBootConfig& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void) ;

private:
	CIM_BootConfigSetting*	_bcs;
};

};	/* namespace dsdk */

#endif /*BOOTCONFIG_H_*/
