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
#include <dsdk/oal/CIM_ComputerSystem.h>
#include <dsdk/oal/CIM_ManagedElement.h>
#include <dsdk/oal/CIM_AssociatedPowerManagementService.h>
#include <dsdk/oal/CIM_PowerManagementService.h>
#include <dsdk/oal/CIM_ServiceAvailableToElement.h>
#include <dsdk/oal/CIM_PowerManagementCapabilities.h>
#include <dsdk/oal/CIM_ElementCapabilities.h>
#include <dsdk/computersystem.h>
#include <dsdk/dsdkexception.h>
#include <dsdk/cimcapabilities.h>
#include "apiimp.h"


using namespace dsdk;

/*
 * Constructor
 */
CComputerSystem::CComputerSystem (const CIM_ComputerSystem& cs)
{ 
	_cs = new CIM_ComputerSystem (cs); 
}

/*
 * Constructor
 */
CComputerSystem::CComputerSystem (const CComputerSystem& cs)
{
	this->_cs = new CIM_ComputerSystem (*(cs._cs));
}

/*
 * Destruction 
 */
CComputerSystem::~CComputerSystem ()
{
	if (this->_cs) { delete this->_cs; }
}

/*
 * Assignment operator
 */
const CComputerSystem& 
CComputerSystem::operator = (const CComputerSystem& rhs)
{
	if (this->_cs) { delete this->_cs; }
	this->_cs  = new CIM_ComputerSystem (*rhs._cs);
	return *this;
}

/*
 * enumerateComputerSystems
 */
CComputerSystem::iterator 
CComputerSystem::enumComputerSystems (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_ComputerSystem::iterator iter = 
		CIM_ComputerSystem::enumInstances (client, 0, props);

	if (cached) { return createIterator (iter, props);  	  }
	else 		{ return createIterator (iter); }
}

/*
 * getName 
 */
string 
CComputerSystem::getName (void) const
{
	return ((CComputerSystem*) this)->_cs->getName (); 
}
/*
 * getElementName 
 */
string 
CComputerSystem::getElementName (void) const
{
	return ((CComputerSystem*) this)->_cs->getElementName (); 
}


/*
 * getPrimaryOwner
 */
string 
CComputerSystem::getPrimaryOwner (void) const
{ 
	return ((CComputerSystem*) this)->_cs->getPrimaryOwnerName (); 
}
 	
/*
 * getPrimaryOwnerContact
 */
string 
CComputerSystem::getPrimaryOwnerContact (void) const
{ 
	return ((CComputerSystem*) this)->_cs->getPrimaryOwnerContact (); 
}

/*
 * getEnabledState
 */
uint16 
CComputerSystem::getEnabledState (void) const
{ 
	return ((CComputerSystem*) this)->_cs->getEnabledState (); 
}

/*
 * getEnabledStateStr
 */
string
CComputerSystem::getEnabledStateStr (void) const
{ 
	return CIM_ComputerSystem::getValueStr_EnabledState (
				((CComputerSystem*) this)->_cs->getEnabledState ()); 
} 

/*
 * getRequestedState
 */
uint16 
CComputerSystem::getRequestedState (void) const
{ 
	return ((CComputerSystem*) this)->_cs->getRequestedState (); 
}

/*
 * getRequestedStateStr
 */
string
CComputerSystem::getRequestedStateStr (void) const
{ 
	return CIM_ComputerSystem::getValueStr_RequestedState (
			((CComputerSystem*) this)->_cs->getRequestedState ()); 
} 	

/*
 * getDedicated
 */
vector<uint16> 
CComputerSystem::getDedicated (void) const
{
	return ((CComputerSystem*) this)->_cs->getDedicated ();
}

/*
 * getDedicatedStr
 */
vector<string> 
CComputerSystem::getDedicatedStr (void) const
{
	vector<uint16> dedicated = ((CComputerSystem*) this)->_cs->getDedicated ();
	vector <string> dedicated_str;
	for(size_t i = 0; i < dedicated.size(); i++ )
	{
		dedicated_str.push_back(this->_cs->getValueStr_Dedicated (dedicated [i]));
	}

	return dedicated_str;
}

/*
 * getPowerState
 */
uint16
CComputerSystem::getPowerState (void) const
{
	vector<string>	props;
	props.push_back ("PowerState");

	vector<CIM_AssociatedPowerManagementService<CIM_PowerManagementService, CIM_ComputerSystem> > apms = 
		CIM_AssociatedPowerManagementService <CIM_PowerManagementService, 
											  CIM_ComputerSystem>::getInstances (_cs->getClient (),0, props);

	if (0 == apms.size ())
	{
		throw EFunctionNotSupported ("PowerState");
	}

/*	
	vector<CIM_AssociatedPowerManagementService<CIM_PowerManagementService, CIM_ComputerSystem> > apms;
	if(capableOfPowerStateProperty("PowerState", apms) == false)
	{
		throw EFunctionNotSupported ("PowerState");
	}
*/	

	/* Return the power state, only one power management service will be 
	   supported, so use the first one*/
	return apms [0].getPowerState ();
}

/*
 * getPowerStateStr
 */
string 
CComputerSystem::getPowerStateStr (void) const
{ 
	return CIM_AssociatedPowerManagementService 
			<CIM_PowerManagementService, CIM_ComputerSystem>::getValueStr_PowerState (
															(uint16) getPowerState ());
}

/*
 * getRequestedPowerState
 */
uint16
CComputerSystem::getRequestedPowerState (void) const
{
	vector<string>	props;
	props.push_back ("RequestedPowerState");

	vector<CIM_AssociatedPowerManagementService<CIM_PowerManagementService, CIM_ComputerSystem> > apms = 
		CIM_AssociatedPowerManagementService <CIM_PowerManagementService, 
											  CIM_ComputerSystem>::getInstances (_cs->getClient (),0, props);

	if (0 == apms.size ())
	{
		throw EFunctionNotSupported ("RequestedPowerState");
	}
/*
	vector<CIM_AssociatedPowerManagementService<CIM_PowerManagementService, CIM_ComputerSystem> > apms;
	if(capableOfPowerStateProperty("RequestedPowerState", apms) == false)
	{
		throw EFunctionNotSupported ("RequestedPowerState");
	}
*/
	/* Return the last requested power state, only one power management service will be 
	   supported, so use the first one*/
	return apms [0].getRequestedPowerState ();
}

/*
 * getRequestedPowerStateStr
 */
string 
CComputerSystem::getRequestedPowerStateStr (void) const
{ 
		return CIM_AssociatedPowerManagementService 
			<CIM_PowerManagementService, CIM_ComputerSystem>::getValueStr_RequestedPowerState (
															(uint16) getRequestedPowerState ());
}

/*
 * getPowerOnTime
 */
datetime
CComputerSystem::getPowerOnTime (void) const
{
	vector<string>	props;
	props.push_back ("PowerOnTime");

	vector<CIM_AssociatedPowerManagementService<CIM_PowerManagementService, CIM_ComputerSystem> > apms = 
		CIM_AssociatedPowerManagementService <CIM_PowerManagementService, 
											  CIM_ComputerSystem>::getInstances (_cs->getClient (),0, props);

	if (0 == apms.size ())
	{
		throw EFunctionNotSupported ("PowerOnTime");
	}

/*
	vector<CIM_AssociatedPowerManagementService<CIM_PowerManagementService, CIM_ComputerSystem> > apms;
	if(capableOfPowerStateProperty("PowerOnTime", apms) == false)
	{
		throw EFunctionNotSupported ("PowerOnTime");
	}
*/
	/* Return the next power on time, only one power management service will be 
	   supported, so use the first one*/
	return apms [0].getPowerOnTime ();
}

/*
 * getPowerChangeCapabilities
 */
vector<uint16>
CComputerSystem::getPowerChangeCapabilities (void) const
{
	CIM_PowerManagementCapabilities pmc (CCIMInstance::nullInstance());
	CIM_PowerManagementService pms(CCIMInstance::nullInstance());

	// Verify whether the Power Management Service is available or not
	if(capableOfPowerStatesManagement(pms, pmc) == false) 
		throw EFunctionNotSupported ("PowerChangeCapabilities");

	/* Return the last requested power state, only one power management service will be 
	   supported, so use the first one*/

	return pmc.getPowerChangeCapabilities ();
}

/*
 * getPowerChangeCapabilitiesStr
 */
vector<string >
CComputerSystem::getPowerChangeCapabilitiesStr (void) const
{ 
	vector<uint16> capabilities = getPowerChangeCapabilities ();
	vector <string> capabilities_str;
	for(size_t i = 0; i < capabilities.size(); i++ )
	{
		capabilities_str.push_back(CIM_PowerManagementCapabilities::getValueStr_PowerChangeCapabilities (
																					capabilities [i]));
	}

	return capabilities_str;
}

/*
 * getPowerStatesSupported
 */
vector<uint16>
CComputerSystem::getPowerStatesSupported (void) const
{
	CIM_PowerManagementCapabilities pmc(CCIMInstance::nullInstance ());
	CIM_PowerManagementService pms(CCIMInstance::nullInstance());

	// Verify whether the Power Management Service is available or not
	if(capableOfPowerStatesManagement(pms, pmc) == false) 
		throw EFunctionNotSupported ("PowerStatesSupported");

	return pmc.getPowerStatesSupported ();
}

/*
 * getPowerStatesSupportedStr
 */
vector<string >
CComputerSystem::getPowerStatesSupportedStr (void) const
{ 
	vector <uint16> states = getPowerStatesSupported ();
	vector <string> states_str;
	for(size_t i = 0; i < states.size(); i++ )
	{
		states_str.push_back(CIM_PowerManagementCapabilities::getValueStr_PowerStatesSupported (
																					states [i]));
	}
	return states_str;
}

/*
 * getReqPwrStateChangeErrStr
 */
string 
CComputerSystem::getReqPwrStateChangeErrStr (uint32 err) const
{
	return CIM_PowerManagementService::getValueStr_RequestStateChange_ReturnCode (err);
}


/*
 * powerOn
 */
uint32 
CComputerSystem::powerOn (void) const
{
	uint32 status = 0;
	CIM_PowerManagementService pms(CCIMInstance::nullInstance());
	CIM_PowerManagementCapabilities pmc (CCIMInstance::nullInstance());

	// Verify whether the Power Management Service is available or not
	if(capableOfPowerStatesManagement(pms, pmc) == false) 
		throw EFunctionNotSupported ("powerOn");

	// Verify whether RequestPowerStateChange() method is supported or not
	if(capableOfRequestPowerStateChange() == false) 
		throw EFunctionNotSupported ("powerOn");

	// Verify whether Power On operation is supported or not
	if ( isSupportedValue(CIM_PowerManagementCapabilities::PowerStatesSupported_On) )
	{
		datetime 		now = CCIMDateTime::getCurrentDateTime ();
		datetime 		immediate = CCIMDateTime (0, true);
		CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

		vector<string> ignore;
		ignore.push_back ("TimeoutPeriod");
		ignore.push_back ("Time");
			
		status = pms.RequestPowerStateChange (
				CIM_PowerManagementService::RequestPowerStateChange_PowerState_Power_On,
				*_cs, 
				now, 
				&job, 
				immediate,
				ignore);
			
		/* if RequestPowerStateChange is success(0) return 0, else throw EFunctionReturnedWithFailure execption */
		if (status == 4096)
		{
			int currJobState = job.getJobState();
			if (currJobState != 7){
				string retcodestr = pms.getValueStr_RequestStateChange_ReturnCode(status);
				throw EFunctionReturnedWithFailure ("CIM_PowerManagementService::RequestPowerStateChange", retcodestr, status);
			}
		}
		else if (status != 0)
		{
			string retcodestr = pms.getValueStr_RequestPowerStateChange_ReturnCode(status);
			throw EFunctionReturnedWithFailure ("CIM_PowerManagementService::RequestPowerStateChange", 
											retcodestr, status);
		}
	}
	return status;
}

/*
 * powerOff
 */
uint32 
CComputerSystem::powerOff (void) const
{
	uint32 status = 0;
	CIM_PowerManagementService pms(CCIMInstance::nullInstance());
	CIM_PowerManagementCapabilities pmc (CCIMInstance::nullInstance());

	// Verify whether the Power Management Service is available or not
	if(capableOfPowerStatesManagement(pms, pmc) == false) 
			throw EFunctionNotSupported ("powerOff");

	// Verify whether RequestPowerStateChange() method is supported or not
	if(capableOfRequestPowerStateChange() == false) 
		throw EFunctionNotSupported ("powerOff");

	// Verify whether Power Off operation is supported or not
	if ( isSupportedValue(CIM_PowerManagementCapabilities::PowerStatesSupported_Off___Soft) )
	{
		datetime 		now = CCIMDateTime::getCurrentDateTime ();
		datetime 		immediate = CCIMDateTime (0, true);
		CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

		/* try soft power off, if not supported try hadr power off . */
		vector<string> ignore;
		ignore.push_back ("TimeoutPeriod");
		ignore.push_back ("Time");
		vector<uint16> states =this->getPowerChangeCapabilities();

		status = pms.RequestPowerStateChange (
				CIM_PowerManagementService::RequestPowerStateChange_PowerState_Power_Off___Soft,
				*_cs, 
				now, 
				&job, 
				immediate,
				ignore);
		
		if (status == pms.RequestPowerStateChange_ReturnCode_Not_Supported)
		{
			/* if soft power off not supported try hard power off */
			status = pms.RequestPowerStateChange (
						CIM_PowerManagementService::RequestPowerStateChange_PowerState_Power_Off___Hard,
						*_cs, 
						now, 
						&job, 
						immediate,
						ignore);
		}

		/* if RequestPowerStateChange is success(0) return 0, else throw EFunctionReturnedWithFailure execption */
		if (status == 4096)
		{
			int currJobState = job.getJobState();
			if (currJobState != 7){
				string retcodestr = pms.getValueStr_RequestStateChange_ReturnCode(status);
				throw EFunctionReturnedWithFailure ("CIM_PowerManagementService::RequestPowerStateChange", retcodestr, status);
			}
		}
		else if (status != 0)
		{
			string retcodestr = pms.getValueStr_RequestPowerStateChange_ReturnCode(status);
			throw EFunctionReturnedWithFailure ("CIM_PowerManagementService::RequestPowerStateChange", 
												retcodestr, status);
		}
	}
	return status;
}

/*
 * powerCycle
 */
uint32 
CComputerSystem::powerCycle (void) const
{
	uint32 status = 0;
	CIM_PowerManagementService pms(CCIMInstance::nullInstance());
	CIM_PowerManagementCapabilities pmc (CCIMInstance::nullInstance());

	// Verify whether the Power Management Service is available or not
	if(capableOfPowerStatesManagement(pms, pmc) == false) 
		throw EFunctionNotSupported ("powerCycle");

	// Verify whether RequestPowerStateChange() method is supported or not
	if(capableOfRequestPowerStateChange() == false) 
		throw EFunctionNotSupported ("powerCycle");

	// Verify whether Power Cycle operation is supported or not
	if ( isSupportedValue(CIM_PowerManagementCapabilities::PowerStatesSupported_Power_Cycle__Off___Soft_) )
	{
		datetime 		now = CCIMDateTime::getCurrentDateTime ();
		datetime 		immediate = CCIMDateTime (0, true);
		CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

		vector<string> ignore;
		ignore.push_back ("TimeoutPeriod");
		ignore.push_back ("Time");

		/* do a soft power cycle first and if not supported do a hard power cycle */
		status = pms.RequestPowerStateChange (
				CIM_PowerManagementService::RequestPowerStateChange_PowerState_Power_Cycle__Off_Soft_,
				*_cs, 
				now, 
				&job, 
				immediate,
				ignore);
		if (status == pms.RequestPowerStateChange_ReturnCode_Not_Supported)
		{
			/* if soft power cycle not supported do a hard power cycle */
			status = pms.RequestPowerStateChange (
				CIM_PowerManagementService::RequestPowerStateChange_PowerState_Power_Cycle__Off_Hard_,
				*_cs, 
				now, 
				&job, 
				immediate,
				ignore);
		}

		/* if RequestPowerStateChange is success(0) return 0, else throw EFunctionReturnedWithFailure execption */
		if (status == 4096)
		{
			int currJobState = job.getJobState();
			if (currJobState != 7){
			string retcodestr = pms.getValueStr_RequestStateChange_ReturnCode(status);
			throw EFunctionReturnedWithFailure ("CIM_PowerManagementService::RequestPowerStateChange", retcodestr, status);
			}
		}
		else if (status != 0)
		{
			string retcodestr = pms.getValueStr_RequestPowerStateChange_ReturnCode(status);
			throw EFunctionReturnedWithFailure ("CIM_PowerManagementService::RequestPowerStateChange", 
												retcodestr, status);
		}
	}
	return status;
}


/*
 * powerReset
 */
uint32 
CComputerSystem::powerReset (void) const
{
	uint32 status = 0;
	CIM_PowerManagementService pms(CCIMInstance::nullInstance());
	CIM_PowerManagementCapabilities pmc (CCIMInstance::nullInstance());

	// Verify whether the Power Management Service is available or not
	if(capableOfPowerStatesManagement(pms, pmc) == false) 
		throw EFunctionNotSupported ("powerReset");

	// Check whether RequestPowerStateChange() method is supported or not
	if(capableOfRequestPowerStateChange() == false) 
		throw EFunctionNotSupported ("powerReset");

	// Verify whether PowerReset operation is supported or not
	if ( isSupportedValue(CIM_PowerManagementCapabilities::PowerStatesSupported_Master_Bus_Reset) )
	{
		datetime 		now = CCIMDateTime::getCurrentDateTime ();
		datetime 		immediate = CCIMDateTime (0, true);
		CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

		vector<string> ignore;
		ignore.push_back ("TimeoutPeriod");
		ignore.push_back ("Time");

		status = pms.RequestPowerStateChange (
						CIM_PowerManagementService::RequestPowerStateChange_PowerState_Master_Bus_Reset,
						*_cs, 
						now, 
						&job, 
						immediate,
						ignore);
		/* if RequestPowerStateChange is success(0) return 0, else throw EFunctionReturnedWithFailure execption */
		if (status == 4096)
		{
			int currJobState = job.getJobState();
			if (currJobState != 7){
			string retcodestr = pms.getValueStr_RequestStateChange_ReturnCode(status);
			throw EFunctionReturnedWithFailure ("CIM_PowerManagementService::RequestPowerStateChange", retcodestr, status);
			}
		}
		else if (status != 0)
		{
			string retcodestr = pms.getValueStr_RequestPowerStateChange_ReturnCode(status);
			throw EFunctionReturnedWithFailure ("CIM_PowerManagementService::RequestPowerStateChange", 
												retcodestr, status);
		}
	}
	return status;
}


/*
 * Power Reset Graceful 
 */
uint32 
CComputerSystem::powerResetGraceful (void) const
{
	uint32 status = 0;
	CIM_PowerManagementService pms(CCIMInstance::nullInstance());
	CIM_PowerManagementCapabilities pmc (CCIMInstance::nullInstance());

	// Verify whether the Power Management Service is available or not
	if(capableOfPowerStatesManagement(pms, pmc) == false) 
		throw EFunctionNotSupported ("powerResetGraceful");

	// Check whether RequestPowerStateChange() method is supported or not
	if(capableOfRequestPowerStateChange() == false) 
		throw EFunctionNotSupported ("powerResetGraceful");

	// Verify whether PowerResetGraceful operation is supported or not
	if ( isSupportedValue(CIM_PowerManagementCapabilities::PowerStatesSupported_Master_Bus_Reset_Graceful) )
	{
		datetime 		now = CCIMDateTime::getCurrentDateTime ();
		datetime 		immediate = CCIMDateTime (0, true);
		CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

		vector<string> ignore;
		ignore.push_back ("TimeoutPeriod");
		ignore.push_back ("Time");

		status = pms.RequestPowerStateChange (
						CIM_PowerManagementService::RequestPowerStateChange_PowerState_Master_Bus_Reset_Graceful,
						*_cs, 
						now, 
						&job, 
						immediate,
						ignore);
		/* if RequestPowerStateChange is success(0) return 0, else throw EFunctionReturnedWithFailure execption */
		if (status == 4096)
		{
			int currJobState = job.getJobState();
			if (currJobState != 7){
			string retcodestr = pms.getValueStr_RequestStateChange_ReturnCode(status);
			throw EFunctionReturnedWithFailure ("CIM_PowerManagementService::RequestPowerStateChange", retcodestr, status);
			}
		}
		else if (status != 0)
		{
			string retcodestr = pms.getValueStr_RequestPowerStateChange_ReturnCode(status);
			throw EFunctionReturnedWithFailure ("CIM_PowerManagementService::RequestPowerStateChange", 
												retcodestr, status);
		}
	}
	return status;
}
/*
 * Power Off-Graceful 
 */
uint32 
CComputerSystem::powerOffGraceful (void) const
{
	uint32 status = 0;;
	CIM_PowerManagementService pms(CCIMInstance::nullInstance());
	CIM_PowerManagementCapabilities pmc (CCIMInstance::nullInstance());

	// Verify whether the Power Management Service is available or not
	if(capableOfPowerStatesManagement(pms, pmc) == false) 
		throw EFunctionNotSupported ("powerOffGraceful");

	if(capableOfRequestPowerStateChange() == false) 
		throw EFunctionNotSupported ("powerOffGraceful");

	// Verify whether PowerResetGraceful operation is supported or not
	if ( isSupportedValue(CIM_PowerManagementCapabilities::PowerStatesSupported_Off___Soft_Graceful) )
	{
		datetime 		now = CCIMDateTime::getCurrentDateTime ();
		datetime 		immediate = CCIMDateTime (0, true);
		CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

		vector<string> ignore;
		ignore.push_back ("TimeoutPeriod");
		ignore.push_back ("Time");

		status = pms.RequestPowerStateChange (
						CIM_PowerManagementService::RequestPowerStateChange_PowerState_Power_Off___Soft_Graceful,
						*_cs, 
						now, 
						&job, 
						immediate,
						ignore);
		/* if RequestPowerStateChange is success(0) return 0, else throw EFunctionReturnedWithFailure execption */
		if (status == 4096)
		{
			int currJobState = job.getJobState();
			if (currJobState != 7){
			string retcodestr = pms.getValueStr_RequestStateChange_ReturnCode(status);
			throw EFunctionReturnedWithFailure ("CIM_PowerManagementService::RequestPowerStateChange", retcodestr, status);
			}
		}
		else if (status != 0)
		{
			string retcodestr = pms.getValueStr_RequestPowerStateChange_ReturnCode(status);
			throw EFunctionReturnedWithFailure ("CIM_PowerManagementService::RequestPowerStateChange", 
												retcodestr, status);
		}
	}
	return status;
}



bool
CComputerSystem::capableOfRequestPowerStateChange(void) const
{
	CIM_PowerManagementCapabilities pmc(CCIMInstance::nullInstance ());
	CIM_PowerManagementService pms(CCIMInstance::nullInstance());

	// Verify whether PMS and PMC instances exists or not.
	if ( ! capableOfPowerStatesManagement(pms, pmc)) 
		return false;

		vector<uint16> pcstates = pmc.getPowerChangeCapabilities();
	if ( pcstates.size() == 0 ) return false;
	for (size_t i=0; i < pcstates.size(); i++)
	{
		if ( pcstates[i] == CIM_PowerManagementCapabilities::PowerCapabilities_Power_State_Settable )
			return true;
	}

	return false;

}


bool 
CComputerSystem::capableOfPowerStatesManagement(CIM_PowerManagementService &pms, 
												CIM_PowerManagementCapabilities &pmc) const
{
	vector<string>	props;
	props.push_back("PowerChangeCapabilities");
	props.push_back("PowerStatesSupported");

	CIM_PowerManagementService::iterator pmsiter = CIM_AssociatedPowerManagementService <
					CIM_PowerManagementService, CIM_ComputerSystem>::enumerateServiceProvided (
								((CComputerSystem*) this)->_cs->getClient (), *_cs, props);
	if (pmsiter == CIM_PowerManagementService::iterator::end ())
	{
		//throw EFunctionNotSupported ("PowerChangeCapabilities");
		return false;
	}

	/* Only one power management service will be supported so use the first power management service	*/
	pms = *pmsiter;

	CIM_PowerManagementCapabilities::iterator pmciter = CIM_ElementCapabilities <
					CIM_PowerManagementService, CIM_PowerManagementCapabilities>::enumerateCapabilities (
								this->_cs->getClient (), pms, props);

	if (pmciter == CIM_PowerManagementCapabilities::iterator::end ())
	{
		//throw EFunctionNotSupported ("PowerChangeCapabilities");
		return false;
	}

	/* 
	  Only one power management capabilities will be supported so 
	  use the first power management capabilities
	 */
	pmc = *pmciter;
	return true;
}

bool
CComputerSystem::capableOfPowerStatesManagement() const
{
	CIM_PowerManagementCapabilities pmc(CCIMInstance::nullInstance ());
	CIM_PowerManagementService pms(CCIMInstance::nullInstance());

	return capableOfPowerStatesManagement(pms, pmc);
}

bool
CComputerSystem::isSupportedValue(uint16 checkVal) const
{
	vector<uint16> pstates = this->getPowerStatesSupported(); 
	for (size_t i=0; i < pstates.size(); i++)
	{
		if (pstates[i] == checkVal)
			return true;
	}

	return false;
}


/*
 * Power State 
 */
const uint16 CComputerSystem::other					= CIM_AssociatedPowerManagementService<CIM_PowerManagementService, CIM_ComputerSystem>::PowerState_Other;
const uint16 CComputerSystem::on 	  		  		= CIM_AssociatedPowerManagementService<CIM_PowerManagementService, CIM_ComputerSystem>::PowerState_On;
const uint16 CComputerSystem::sleep_light   		= CIM_AssociatedPowerManagementService<CIM_PowerManagementService, CIM_ComputerSystem>::PowerState_Sleep___Light;
const uint16 CComputerSystem::sleep_deep	  		= CIM_AssociatedPowerManagementService<CIM_PowerManagementService, CIM_ComputerSystem>::PowerState_Sleep__Deep;
const uint16 CComputerSystem::power_cycle_soft_off	= CIM_AssociatedPowerManagementService<CIM_PowerManagementService, CIM_ComputerSystem>::PowerState_Power_Cycle__Off___Soft_;
const uint16 CComputerSystem::hard_off				= CIM_AssociatedPowerManagementService<CIM_PowerManagementService, CIM_ComputerSystem>::PowerState_Off___Hard;
const uint16 CComputerSystem::hibernate_soft_off 	= CIM_AssociatedPowerManagementService<CIM_PowerManagementService, CIM_ComputerSystem>::PowerState_Hibernate__Off___Soft_;
const uint16 CComputerSystem::soft_off				= CIM_AssociatedPowerManagementService<CIM_PowerManagementService, CIM_ComputerSystem>::PowerState_Off___Soft;
const uint16 CComputerSystem::power_cycle_hard_off	= CIM_AssociatedPowerManagementService<CIM_PowerManagementService, CIM_ComputerSystem>::PowerState_Power_Cycle__Off_Hard_;
const uint16 CComputerSystem::master_bus_reset		= CIM_AssociatedPowerManagementService<CIM_PowerManagementService, CIM_ComputerSystem>::PowerState_Master_Bus_Reset;
const uint16 CComputerSystem::diag_uint16errupt		= CIM_AssociatedPowerManagementService<CIM_PowerManagementService, CIM_ComputerSystem>::PowerState_Diagnostic_Interrupt__NMI_;
const uint16 CComputerSystem::master_bus_reset_graceful = CIM_AssociatedPowerManagementService<CIM_PowerManagementService, CIM_ComputerSystem>::PowerState_Master_Bus_Reset_Graceful;

/*
 * getCachedProps
 */
vector<string> 
CComputerSystem::getCachedProps (void) 
{
	vector<string> props;

	props.push_back ("Name");
	props.push_back ("PrimaryOwnerName");
	props.push_back ("PrimaryOwnerContact");
	props.push_back ("EnabledState");
	props.push_back ("RequestedState");
	props.push_back ("Dedicated");
	props.push_back("ElementName");
	props.push_back("SystemCreationClassName");
	props.push_back("CreationClassName");
	return props;
}

/*
 * ComputerSystem::Iterator
 */
DEFINE_API_ITERATOR (CComputerSystem);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CComputerSystem, CIM_ComputerSystem);
