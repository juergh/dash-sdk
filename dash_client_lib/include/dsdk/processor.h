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
 * processor.h
 * Class representing a processor.
 **/
#ifndef __DSDK_PROCESSOR_H__
#define __DSDK_PROCESSOR_H__
#include <dsdk/dsdkiterator.h>
#include <dsdk/dsdk_api.h>
#include <dsdk/dsdktypes.h>
#include <dsdk/cimmap.h>


namespace dsdk
{

class CIM_ProcessorCore;
class CProcessorCore;
typedef CAPIIterator<CProcessorCore, CIM_ProcessorCore> _CProcessorCoreIterator;

/**
 * @class CProcessorCore
 * @brief A Processor Core
 **/
 class DSDK_Export CProcessorCore 
 {
 public:
	DECLARE_API_ITERATOR (CProcessorCore);
	typedef CIM_ProcessorCore CIMType;
	
	/**
	 * Enumerates all the processor cores present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the processor cores.
	 */
	static CProcessorCore::iterator enumProcessorCores (IClient* client,
										 	    	    bool cached = true);
	/**
	 * Return the underlying CIM object
	 */
	CIM_ProcessorCore* getCIMObject (void) const { return _pc; }

 public:
 	/**
 	 * Processor core status
 	 **/
	static const uint16 unknown;
	static const uint16 reserved;
	static const uint16 enabled;
	static const uint16 disabled;
	static const uint16 disabled_by_user;
	static const uint16 disabled_by_POST_error;

	/** Processor characteristics @{ **/
 	static const uint16 characteristics_unknown;
 	static const uint16 characteristics_reserved;
 	static const uint16 characteristics_64_bit;	
 	static const uint16 characteristics_32_bit;
 	/** } **/
 	
 public:
	/**
	 * Gets the instance ID of the processor Core 
	 * @return The Instance ID
	 **/
	string getInstanceID (void) const;

	/**
	 * Gets the Core Enabled state of  processor Core 
	 * @return The Core Enabled state
	 **/
	uint16 getCoreEnabledState (void) const;

	/**
	 * Gets the Core Enabled state of processor Core as string
	 * @return The Core Enabled state 
	 **/
	string getCoreEnabledStateStr (void) const;

	/**
	 * Gets the load percentage of this processor core 
	 * @return The load percentage of this processor core.
	 **/
	uint16 getLoadPercentage (void) const;

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
	 * Gets the operational status of the processor
	 * @return The operational status
	 */
	vector<uint16> getOperationalStatus (void) const;

	/**
	 * Gets the operational status of the processor as string
	 * @return The operational status
	 */
	vector<string> getOperationalStatusStr (void) const;

	/**
	 * Gets the health state of the processor
	 * @return The health state
	 */
	uint16 getHealthState (void) const;

	/**
	 * Gets the health state of the processor as string
	 * @return The health state
	 */
	string getHealthStateStr (void) const;

	/**
	 * Gets the element name of the processor
	 * @return The element name
	 */
	string getElementName (void) const;

public:
	/**
	 * Construct this object from the corresponding CIM_ProcessorCore
	 * object
	 */
	CProcessorCore (const CIM_ProcessorCore& pc);
	
	/**
	 * Copy constructor
	 */
	CProcessorCore (const CProcessorCore& cs);

	/**
	 * Destructor
	 */
	~CProcessorCore ();

	/**
	 * Assignment operator
	 */
	const CProcessorCore& operator = (const CProcessorCore& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void);

private:
	CIM_ProcessorCore*	_pc;
};

class CIM_Processor;
class CProcessor;
typedef CAPIIterator<CProcessor, CIM_Processor> _CProcessorIterator;

/**
  * @class CProcessor
  * @brief A class representing a Processor.
  **/
class DSDK_Export CProcessor 
{
public:
	DECLARE_API_ITERATOR (CProcessor);
	typedef CIM_Processor CIMType;

public:
	/**
	 * Enumerates all the processors present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the processors.
	 */
	static CProcessor::iterator enumProcessors (IClient* client,
										 	    bool cached = true);

	/**
	 * Return the underlying CIM object
	 */
	CIM_Processor* getCIMObject (void) const { return _proc; }

public:
	/**
	 * The status of the processor
	 **/
	static const uint16 unknown;
	static const uint16 enabled;
	static const uint16 disabled_by_user;
	static const uint16 disabled_by_BIOS;
	static const uint16 idle;			
	static const uint16 other;
 	

	/** Processor characteristics @{ */
 	static const uint32 characteristics_unknown		= 0x01;
 	static const uint32 characteristics_reserved	= 0x02;
 	static const uint32 characteristics_64_bit		= 0x04;
 	static const uint32 characteristics_32_bit		= 0x08;
	/** } */

public:
	/**
	 * Gets the processor SystemCreationClassName 
	 * @return The processor SystemCreationClassName 
	 */
	string getSystemCreationClassName (void) const;

	/**
	 * Gets the processor SystemName
	 * @return The processor SystemName.
	 */
	string getSystemName (void) const;

	/**
	 * Gets the processor CreationClassName 
	 * @return The processor CreationClassName
	 */
	string getCreationClassName (void) const;

	/**
	 * Gets the processor DeviceID
	 * @return The processor DeviceID.
	 */
	string getDeviceID (void) const;

	/**
	 * Gets the processor family 
	 * @return The processor family.
	 */
	string getFamily (void) const;

	/**
	 * Gets the current clock speed 
	 * @return The current clock speed in Mhz
	 */
	uint32 getCurrentClockSpeed (void) const;

	/**
	 * Gets the maximum clock speed 
	 * @return The maximum clock speed in Mhz.
	 */
	uint32 getMaxClockSpeed (void) const;

	/**
	 * Gets the external clock speed 
	 * @return The external clock speed in Mhz
	 */
	uint32 getExternalBusClockSpeed (void) const;

	/**
	 * Gets the current status of the processor 
	 * @return The current status
	 */
	uint16 getCPUStatus (void) const;

	/**
	 * Gets the current status of the processor as string
	 * @return The current status 
	 */
	string getCPUStatusStr (void) const;

	/**
	 * Gets load of this processor in the last minute 
	 * @return The load percentage 
	 */
	uint32 getLoadPercentage (void) const;

	/**
	 * Gets the EnabledState of the processor
	 * @return The EnabledState
	 */
	uint16 getEnabledState (void) const;

	/**
	 * Gets the EnabledState of the processor as string
	 * @return The EnabledState
	 */
	string getEnabledStateStr (void) const;

	/**
	 * Gets the last RequestedState of the processor
	 * @return The RequestedState 
	 */
	uint16 getRequestedState (void) const;

	/**
	 * Gets the last RequestedState  of the processor as string
	 * @return The RequestedState 
	 */
	string getRequestedStateStr (void) const;

	/**
	 * Gets the OperationalStatus of the processor
	 * @return The OperationalStatus 
	 */
	vector<uint16> getOperationalStatus (void) const;

	/**
	 * Gets the OperationalStatus  of the processor as string
	 * @return The OperationalStatus 
	 */
	vector<string> getOperationalStatusStr (void) const;

	/**
	 * Gets the HealthState of the processor
	 * @return The HealthState 
	 */
	uint16 getHealthState (void) const;

	/**
	 * Gets the HealthState of the processor as string
	 * @return The HealthState
	 */
	string getHealthStateStr (void) const;

	/**
	 * Gets the ElementName of the processor
	 * @return The ElementName
	 */
	string getElementName (void) const;

	/**
	 * Gets the family description if the family type is "other".
	 * @return The family description 
	 */
	string getOtherFamilyDescription (void) const;

public:
	/**
	 * Enables this processor 
	 * @return  0 on success, throws execption on failure.
	 */
	uint32 enableProcessor (void);

	/**
	 * Disables this processor 
	 * @return  0 on success, throws execption on failure.
	 */
	uint32 disableProcessor (void);

	/**
	 * Resets this processor 
	 * @return  0 on success, throws execption on failure.
	 */
	uint32 resetProcessor (void);

public:
	/**
	 * Construct this object from the corresponding CIM_Processor
	 * object
	 */
	CProcessor (const CIM_Processor& proc);
	
	/**
	 * Copy constructor
	 */
	CProcessor (const CProcessor& cs);

	/**
	 * Destructor
	 */
	~CProcessor ();

	/**
	 * Assignment operator
	 */
	const CProcessor& operator = (const CProcessor& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void);

private:
	CIM_Processor*		_proc;
};

};	/* namespace dsdk */

#endif /*PROCESSOR_H_*/
