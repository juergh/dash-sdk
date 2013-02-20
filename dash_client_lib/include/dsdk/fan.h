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
 * fan.h
 * Classes to support fan.
 **/
#ifndef __DSDK_FAN_H__
#define __DSDK_FAN_H__
#include <dsdk/dsdkiterator.h>
#include <dsdk/dsdk_api.h>

namespace dsdk
{

class CIM_Fan;
class CFan;
typedef CAPIIterator<CFan, CIM_Fan> _CFanIterator;


/**
 * @class CFan
 * @brief A class representing a fan.
 */
class DSDK_Export CFan
{
public:
	DECLARE_API_ITERATOR (CFan);
	typedef CIM_Fan CIMType;

public:
	/**
	 * Enumerates all the fans present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the fan.
	 */
	static CFan::iterator enumFans (IClient* client, bool cached = true);

	/**
	 * Return the underlying CIM object
	 */
	CIM_Fan* getCIMObject (void) const { return _fan; }

public:
	/**
	 * Gets the System Creation class name of the fan
	 * @return The System Creation Class name
	 */
	string getSystemCreationClassName (void) const;
	
	/**
	 * Gets the System name of the fan
	 * @return The System name
	 */
	string getSystemName (void) const;

	/**
	 * Gets the Creation class Name of the fan
	 * @return The fan creation class name.
	 */
	string getCreationClassName (void) const;

	/**
	 *  Gets the device id of the fan
	 *  @return The fan device id.
	 */
	string getDeviceID (void) const;

	/**
	 * Gets the operational status of the fan
	 * @return The operational status
	 */
	vector<uint16> getOperationalStatus (void) const;

	/**
	 * Gets the operational status of the fan as string
	 * @return The operational status
	 */
	vector<string> getOperationalStatusStr (void) const;

	/**
	 * Gets the health state of the fan
	 * @return The health state
	 */
	uint16 getHealthState (void) const;

	/**
	 * Gets the health state of the fan as string
	 * @return The health state
	 */
	string getHealthStateStr (void) const;

	/**
	 * Returns true if the fan supports variable speed 
	 * @return	true if fan supports variable speed.
	 * 		false otherwise
	 */
	bool isVariableSpeed (void) const;

	/**
	 * Gets the fan's current speed(tach reading).It returns the Reading in RPM 
	 * if tach sensor is analog(numeric) sensor, else returns the status if its discrete sensor.
	 * @return	The speed of the fan.
	 */
	string getSpeed(void) const;

	/**
	 * Gets the desired speed of the fan 
	 * @return	The desired speed of the fan.
	 */
	uint64 getDesiredSpeed (void) const;
	
	/**
	 * Sets the desired speed of the fan 
	 * @param speed	The desired speed.
	 * @return 0		if success, error code if failure.
	 **/
	uint32 setDesiredSpeed (uint64 speed) const;
	
	/**
	 * Returns true if the fan supports variable speed 
	 * @return	true if fan supports variable speed.
	 * 		false otherwise
	 */
	bool isActiveCooling (void) const;

	/**
	 * Gets the state of the processor
	 * @return The enabled state
	 */
	uint16 getEnabledState (void) const;

	/**
	 * Gets the state of the processor as string
	 * @return The enabled state
	 */
	string getEnabledStateStr (void) const;

	/**
	 * Gets the last requested state of the processor
	 * @return The requested state
	 */
	uint16 getRequestedState (void) const;

	/**
	 * Gets the last requested state of the processor as string
	 * @return The requested state
	 */
	string getRequestedStateStr (void) const;

	/**
	 * Returns the name of the Element
	 * @return	The ElementName.
	 **/
 	string getElementName(void) const;

	/**
	 * getSetSpeedErrStr
	 * @param	err Error code returned from setDesiredSpeed
	 * @return		Error description.
	 */


	string getSetSpeedErrStr (uint32 err) const;

	/**
	* Verifies whether the Fan State Management is supported or not
	* @param
	* @return  true  - if Fan State Management is supported
	*          false - if Fan State Managemtn is not supported
	**/
	bool capableOfRequestStateChange() const;

	/**
	* Returns the CIM_EnabledLogicalElementCapabilities.RequestedStatesSupported property values
	* @param  TRS
	* @return  vector<uint16> array
	**/
	vector<uint16> getSupportedStates(void) const;

	/**
	* Returns the CIM_EnabledLogicalElementCapabilities.RequestedStatesSupported property string values
	* @param  TRS
	* @return  vector<string> array
	**/
	vector<string> getSupportedStatesStr(void) const;

	/**
	 * Verifies whether SetFanSpeed operation can be performed or not.
	 * @return	true - if supported
	 *			false - if not supported.
	 */
	bool capableOfSetFanSpeed() const;

public:
	/**
	 * Construct this object from the corresponding CIM_Fan object
	 */
	CFan (const CIM_Fan& fan);

	/**
	 * Copy constructor
	 */
	CFan (const CFan& cs);

	/**
	 * Destructor
	 */
	~CFan ();

	/**
	 * Assignment operator
	 */
	const CFan& operator = (const CFan& rhs);


	/**
	 * Returns the properties that are cached by this object
	 */
	 static vector<string> getCachedProps (void) ;

private:
	CIM_Fan*	_fan;
};


class CIM_RedundancySet;
class CFanRedundancySet;
typedef CAPIIterator<CFanRedundancySet, CIM_RedundancySet> _CFanRedundancySetIterator;


/**
  * @class CFanRedundancySet
  * @brief A class representing a Fan Redundancy set.
  **/
class DSDK_Export CFanRedundancySet
{
public:
	DECLARE_API_ITERATOR (CFanRedundancySet);
	typedef CIM_RedundancySet CIMType;

public:
	/**
	 * Enumerates all the fan redundancy sets present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the fan redundancy set.
	 */
	static CFanRedundancySet::iterator enumFanRedundancySets (IClient* client, 
														bool cached = true);

public:
	/**
	 * Redundancy status
	 */
	static const uint16 status_unknown;
	static const uint16 reserved;
	static const uint16 fully_redundant;
	static const uint16 degraded_redundancy;
	static const uint16 redundancy_lost;
	static const uint16 overall_failure;

	/**
	 * Type of the redundacy set 
	 */
	typedef enum
	{
		type_unknown,
		other,
		nplus1,
		load_balanced,
		sparing,
		limited_sparing,
		dmtf_reserved,
		vendor_reserved
		
	} Type_E;
	
public:
	/**
	 * Gets InstanceID
	 * @return The Instance ID
	 */
	string getInstanceID (void);

	/**
	 * Gets the current redundancy status 
	 * @return The current redundancy status.
	 */
	int getRedundancyStatus (void) const;
	
	/**
	 * Gets the type of the redundancy set 
	 * @return The type of the redundancy set.
	 */
	vector<Type_E> getType (void) const;
	
	/**
	 * Returns the minimum number needed 
	 * @return The minumum number 
	 */
	uint32 getMinimumNumberNeeded (void) const;

	/**
	 * Returns the name of the Element
	 * @return	The ElementName.
	 **/
 	string getElementName(void) const;

	/**
	 * Forces a failover from one fan to another fan.
	 * @return The status.
	 */
	uint32 failover (CFan& fan_from, CFan& fan_to);

public:
	/**
	 * Construct this object from the corresponding CIM_FanRedundancySet
	 * object
	 */
	CFanRedundancySet (const CIM_RedundancySet& rs);

	/**
	 * Copy constructor
	 */
	CFanRedundancySet (const CFanRedundancySet& cs);

	/**
	 * Destructor
	 */
	~CFanRedundancySet ();

	/**
	 * Assignment operator
	 */
	const CFanRedundancySet& operator = (const CFanRedundancySet& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	 static vector<string> getCachedProps (void) ;

private:
	CIM_RedundancySet*	_rs;
};

};	/* namespace dsdk */

#endif /* __DSDK_FAN_H__ */
