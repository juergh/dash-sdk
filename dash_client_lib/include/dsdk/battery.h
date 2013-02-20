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
 * battery.h
 * Class representing a battery.
 **/
#ifndef __DSDK_BATTERY_H__
#define __DSDK_BATTERY_H__
#include <dsdk/dsdkiterator.h>
#include <dsdk/dsdk_api.h>
#include <dsdk/dsdktypes.h>
#include <dsdk/cimmap.h>


namespace dsdk
{

class CIM_Battery;
class CBattery;
typedef CAPIIterator<CBattery, CIM_Battery> _CBatteryIterator;

/**
 * @class CBattery
 * @brief A Battery 
 **/
 class DSDK_Export CBattery 
 {
 public:
	DECLARE_API_ITERATOR (CBattery);
	typedef CIM_Battery CIMType;
	
	/**
	 * Enumerates all the battery present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the battery.
	 */
	static CBattery::iterator enumBattery (IClient* client,
										 	    	    bool cached = true);
	/**
	 * Return the underlying CIM object
	 */
	CIM_Battery* getCIMObject (void) const { return _bat; }

 public:

	/**
	 * Description of the charge status of the Battery.
	 */ 

	static const uint16 batteryOther;
	static const uint16 batteryUnknown;
	static const uint16 Fully_Charged;
	static const uint16 Low;
	static const uint16 Critical;
	static const uint16 Charging;
	static const uint16 Charging_and_High;
	static const uint16 Charging_and_Low;
	static const uint16 Charging_and_Critical;
	static const uint16 Undefined;
	static const uint16 Partially_Charged;
	static const uint16 Learning;
	static const uint16 Overcharged;

	/* 
	 * An enumeration that describes the chemistry of the Battery.
	 */

	static const uint16 Other;
	static const uint16 Unknown;
	static const uint16 Lead_Acid;
	static const uint16 Nickel_Cadmium;
	static const uint16 Nickel_Metal_Hydride;
	static const uint16 Lithium_ion;
	static const uint16 Zinc_air;
	static const uint16 Lithium_Polymer;

 public:
	/**
	 * Gets the battery System Creation class Name 
	 * @return The battery system creation class name
	 */
	string getSystemCreationClassName (void) const;

	/**
	 * Gets the battery System Name
	 * @return The battery system name.
	 */
	string getSystemName (void) const;

	/**
	 * Gets the battery Creation class Name 
	 * @return The battery creation class name.
	 */
	string getCreationClassName (void) const;

	/**
	 * Gets the battery device id
	 * @return The battery device id.
	 */
	string getDeviceID (void) const;

	/**
	 * Gets the current status of the battery 
	 * @return The current status
	 */
	uint16 getBatteryStatus (void) const;

	/**
	 * Gets the current status of the battery as string
	 * @return The current status 
	 */
	string getBatteryStatusStr (void) const;

	/**
	 * Gets the operational status of the battery
	 * @return The operational status
	 */
	vector<uint16> getOperationalStatus (void) const;

	/**
	 * Gets the operational status of the battery as string
	 * @return The operational status
	 */
	vector<string> getOperationalStatusStr (void) const;

	/**
	 * Gets the health state of the battery
	 * @return The health state
	 */
	uint16 getHealthState (void) const;

	/**
	 * Gets the health state of the battery as string
	 * @return The health state
	 */
	string getHealthStateStr (void) const;

	/**
	 * Gets the state of the battery
	 * @return The enabled state
	 */
	uint16 getEnabledState (void) const;

	/**
	 * Gets the state of the battery as string
	 * @return The enabled state
	 */
	string getEnabledStateStr (void) const;

	/**
	 * Gets the last requested state of the battery
	 * @return The requested state
	 */
	uint16 getRequestedState (void) const;

	/**
	 * Gets the last requested state of the battery as string
	 * @return The requested state
	 */
	string getRequestedStateStr (void) const;

	/**
	 * Gets the element name of the battery
	 * @return The element name
	 */
	string getElementName (void) const;

	/**
	 * Gets the battery chemistry
	 * @return battery  chemistry
	 **/
	uint16 getChemistry (void) const;

	/**
	 * Gets the battery Chemistry 
	 * @return battery  Chemistry as string
	 **/	
	string getChemistryStr (void) const;

	/**
	 * Gets the MaxRechargeCount of the battery
	 * @return MaxRechargeCount of the battery
	 **/
	uint32 getMaxRechargeCount (void) const;

	/**
	 * Gets the RechargeCount of the battery
	 * @return RechargeCount of the battery
	 **/
	uint32 getRechargeCount (void) const;

	/**
	 * Gets the ExpectedLife of the battery
	 * @return ExpectedLife of the battery
	 **/
	uint32 getExpectedLife (void) const;

	/**
	 * Gets the EstimatedRunTime of the battery
	 * @return EstimatedRunTime of the battery
	 **/
	uint32 getEstimatedRunTime (void) const;

	/**
	 * Gets the TimeToFullCharge of the battery
	 * @return TimeToFullCharge of the battery
	 **/
	uint32 getTimeToFullCharge (void) const;

	/**
	 * Gets the MaxRechargeTime of the battery
	 * @return MaxRechargeTime of the battery
	 **/
	uint32 getMaxRechargeTime (void) const;

	/**
	 * Enable/turn on Battery
	 */
	uint32 enable (void) const;

	/**
	 * Disable/turn off Battery
	 */
	uint32 disable (void) const;

	/**
	 * Test/perform recalculation of charge thresholds.
	 */
	uint32 test (void) const;

	/**
	 * Reset/recharge of battery.
	 */
	uint32 reset (void) const;

	/*
	* Verifies that the RequestStateChange() method is supported or not.
	* If the PowerChangeCapabilities property array contains on of the value = 3, the method is supported.
	* @return  true  - if supported
	*		   false - if not supported
	*/
	bool capableOfRequestStateChange (void) const;

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
 	
public:
	/**
	 * Construct this object from the corresponding CIM_Battery
	 * object
	 */
	CBattery (const CIM_Battery& bat);
	
	/**
	 * Copy constructor
	 */
	CBattery (const CBattery& cs);

	/**
	 * Destructor
	 */
	~CBattery ();

	/**
	 * Assignment operator
	 */
	const CBattery& operator = (const CBattery& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	
	static vector<string> getCachedProps (void) ;

	

private:
	CIM_Battery*	_bat;
};

};	/* namespace dsdk */

#endif /*battery_H_*/
