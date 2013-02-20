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
 * computersystem.h
 * A class representing a computer system.
 */
#ifndef __DSDK_COMPUTERSYSTEM_H__
#define __DSDK_COMPUTERSYSTEM_H__
#include <dsdk/dsdk_api.h>
#include <dsdk/dsdktypes.h>
#include <dsdk/cimmap.h>
#include <dsdk/cim/cimdatetime.h>
#include <dsdk/oal/CIM_ComputerSystem.h>
#include <dsdk/oal/CIM_AssociatedPowerManagementService.h>
#include <dsdk/oal/CIM_PowerManagementService.h>
#include <dsdk/oal/CIM_ServiceAvailableToElement.h>
#include <dsdk/oal/CIM_PowerManagementCapabilities.h>
#include <dsdk/oal/CIM_ElementCapabilities.h>
namespace dsdk
{

class CIM_ComputerSystem;
class CComputerSystem;
typedef CAPIIterator<CComputerSystem, CIM_ComputerSystem> _CComputerSystemIterator;

/**
  * @class CComputerSystem
  * @brief A class representing a computer system
  **/
class DSDK_Export CComputerSystem
{
public:
	DECLARE_API_ITERATOR (CComputerSystem);
	typedef CIM_ComputerSystem CIMType;

public:
	/**
	 * Enumerates all the computer systems present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the computer systems.
	 */
	static CComputerSystem::iterator enumComputerSystems (IClient* client,
										 				  bool cached = true);

public:
	/**
	 * Return the underlying CIM object
	 */
	CIM_ComputerSystem* getCIMObject (void) const { return _cs; }

public:
	/**
	 * Returns the name of the computer system
	 * @return	The name.
	 **/
 	string getName (void) const;
	
	/**
	 * Returns the name of the computer system
	 * @return	The name.
	 **/
 	string getElementName (void) const;
 	
 	/**
 	 * Returns the primary owner of the computer system
 	 * @return	The primary owner.
 	 **/
 	string getPrimaryOwner (void) const;
 	
 	/**
 	 * Returns the primary owner contact of the computer system
 	 * @return	The primary owner contact.
 	 **/
 	string getPrimaryOwnerContact (void) const;

 	/**
 	 * Gets the EnabledState of the computer system
 	 * @return	The EnabledState
 	 **/
 	uint16 getEnabledState (void) const;

	/**
	 * Gets the EnabledState of the computer system as string
	 * @return The EnabledState
	 */
	string getEnabledStateStr (void) const;

	/**
 	 * Gets the last RequestedState of the computer system
 	 * @return	The RequestedState
 	 **/
 	uint16 getRequestedState (void) const;

	/**
	 * Gets the last RequestedState of the computer system as string
	 * @return The RequestedState 
	 */
	string getRequestedStateStr (void) const;

	/** 
 	 * Gets the purpose(s) of this computer is dedicated to.
 	 * @return	The dedicated purpose(s)
 	 **/
 	vector<uint16> getDedicated (void) const;

	/** 
 	 * Gets the purpose(s) of this computer is dedicated to as string.
 	 * @return	The dedicated purpose(s)
 	 **/
 	vector<string> getDedicatedStr (void) const;

	/**
	 * Gets the current power state of this computer system.
	 * @return The current power state.
	 **/ 	
 	uint16 getPowerState (void) const;

	/**
	 * Gets the power state of this computer system as a string.
	 * @return The power state as string
	 */
	string getPowerStateStr (void) const;

	/**
	 * Gets the last requested power state of this computer system.
	 * @return The last requested power state.
	 **/ 	
 	uint16 getRequestedPowerState (void) const;

	/**
	 * Gets the power state as a string.
	 * @return The power state as string
	 */
	string getRequestedPowerStateStr (void) const;

	/**
	 * Gets the time when this computer system will be powered on again.
	 * @return The next power on time.
	 **/ 	
 	datetime getPowerOnTime (void) const;

	/**
	 * Gets the power change capabilities of this computer system.
	 * @return The power change capabilities
	 **/ 	
 	vector<uint16> getPowerChangeCapabilities (void) const;

	/**
	 * Gets the power change capabilities of this computer system as string
	 * @return The power change capabilities
	 **/ 	
 	vector<string> getPowerChangeCapabilitiesStr (void) const;

	/**
	 * Gets the power states supported for this computer system.
	 * @return The power state supported
	 **/ 	
 	vector<uint16> getPowerStatesSupported (void) const;

	/**
	 * Gets the power states supported for this computer system as string.
	 * @return The power state supported
	 **/ 	
 	vector<string> getPowerStatesSupportedStr (void) const;

	/**
	 * getReqPwrStateChangeErrStr
	 * @param err	error
	 * @return The power state change error as string
	 */
	string getReqPwrStateChangeErrStr (uint32 err) const;

	/*
	* Verifies that the RequestStateChange() method is supported or not.
	* If the PowerChangeCapabilities property array contains on of the value = 3, the method is supported.
	* @return  true  - if supported
	*		   false  -if not supported
	*/
	bool capableOfRequestPowerStateChange (void) const;

	/**
	 * Verifies whether the computersystem can actually manage power management states.
	 * @param pmc	If the system supports, then this parameter contains the reference of
	 *				the corresponding capabilities using which power states can be managed.
	 * @return	true - if supported
	 *			false - if not supported.
	 */
	bool capableOfPowerStatesManagement(CIM_PowerManagementService &pms, CIM_PowerManagementCapabilities &pmc) const;

	/**
	 * Verifies whether the computersystem can actually manage power management states.
	 * @return	true - if supported
	 *			false - if not supported.
	 */
	bool capableOfPowerStatesManagement() const;

	/**
	* Verifies whether the perticulare power operation(On, Off, Reset, PowerCycle,...) is supported
	* on the Computersystem or not.
	* @param	integer value for the perticular power operation.
	* 
	* @return  true  - if supported
	*          false - if not supported.
	*/
	bool isSupportedValue(uint16 checkVal) const;

public:
	/**
	 * Power On the computer system
	 **/ 
 	uint32 powerOn (void) const;
 	
 	/**
 	 * Power off the computer system.
 	 **/
 	uint32 powerOff (void) const;
 	
 	/**
 	 * PowerCycle the computer system
 	 **/
 	uint32 powerCycle (void) const;

 	/**
 	 * PowerReset the computer system
 	 **/
 	uint32 powerReset (void) const;

	/**
 	 * Graceful Power reset  the computer system
 	 **/
 	uint32 powerResetGraceful (void) const;

	/**
 	 * Power Off Graceful the computer system
 	 **/
 	uint32 powerOffGraceful (void) const;

	/**
	 * Power States
	 **/
	static const uint16 other;
	static const uint16 on ;
	static const uint16 sleep_light;
	static const uint16 sleep_deep;
	static const uint16 power_cycle_soft_off;
	static const uint16 hard_off;
	static const uint16 hibernate_soft_off;
	static const uint16 soft_off;
	static const uint16 power_cycle_hard_off;
	static const uint16 master_bus_reset;
	static const uint16 diag_uint16errupt;
	static const uint16 master_bus_reset_graceful;

public:
	/**
	 * Construct this object from the corresponding CIM_ComputerSystem 
	 * object
	 */
	CComputerSystem (const CIM_ComputerSystem& cs); 

	/**
	 * Copy constructor
	 */
	CComputerSystem (const CComputerSystem& cs);

	/**
	 * Destructor
	 */
	~CComputerSystem ();

	/**
	 * Assignment operator
	 */
	const CComputerSystem& operator = (const CComputerSystem& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void) ;

private:
	CIM_ComputerSystem*	_cs;
};

};	/* namespace dsdk */

#endif /*COMPUTERSYSTEM_H_*/
