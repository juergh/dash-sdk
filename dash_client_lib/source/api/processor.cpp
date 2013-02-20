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
 * A class representing a processor.
 */
#include <dsdk/oal/CIM_ProcessorCore.h>
#include <dsdk/oal/CIM_Processor.h>
#include <dsdk/processor.h>
#include "apiimp.h"

using namespace dsdk;

/*
 * Constructor
 */
CProcessorCore::CProcessorCore (const CIM_ProcessorCore& pc)
{ 
	_pc = new CIM_ProcessorCore (pc); 
}

/*
 * Constructor
 */
CProcessorCore::CProcessorCore (const CProcessorCore& pc)
{
	this->_pc = new CIM_ProcessorCore (*(pc._pc));
}

/*
 * Destruction 
 */
CProcessorCore::~CProcessorCore ()
{
	if (this->_pc) { delete this->_pc; }
}

/*
 * Assignment operator
 */
const CProcessorCore& 
CProcessorCore::operator = (const CProcessorCore& rhs)
{
	if (this->_pc) { delete this->_pc; }
	this->_pc  = new CIM_ProcessorCore (*rhs._pc);
	return *this;
}


/*
 * enumProcessorCore
 */
CProcessorCore::iterator 
CProcessorCore::enumProcessorCores (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_ProcessorCore::iterator iter = 
				CIM_ProcessorCore::enumInstances (client, 0, props);

	if (cached) { return createIterator (iter, props);  	  }
	else 		{ return createIterator (iter); }
}

/*
 * getInstanceID 
 */
string 
CProcessorCore::getInstanceID (void) const
{
	return ((CProcessorCore*) this)->_pc->getInstanceID ();
}

/*
 * getCoreEnabledState
 */
uint16
CProcessorCore::getCoreEnabledState (void) const
{
	return ((CProcessorCore*) this)->_pc->getCoreEnabledState ();
}

/*
 * getCoreEnabledState
 */
string
CProcessorCore::getCoreEnabledStateStr (void) const
{
	return CIM_ProcessorCore::getValueStr_CoreEnabledState ( 
				((CProcessorCore*) this)->_pc->getCoreEnabledState ());
}

/*
 * getLoadPercentage
 */
uint16 
CProcessorCore::getLoadPercentage (void) const
{
	return ((CProcessorCore*) this)->_pc->getLoadPercentage ();
}

/*
 * getEnabledState
 */
uint16 
CProcessorCore::getEnabledState (void) const
{ 
	return ((CProcessorCore*) this)->_pc->getEnabledState (); 
} 	

/*
 * getEnabledStateStr
 */
string
CProcessorCore::getEnabledStateStr (void) const
{ 
	string str = CIM_ProcessorCore::getValueStr_EnabledState (
				((CProcessorCore*) this)->_pc->getEnabledState ()); 
	return str;
} 

/*
 * getRequestedState
 */
uint16 
CProcessorCore::getRequestedState (void) const
{ 
	return ((CProcessorCore*) this)->_pc->getRequestedState (); 
} 	

/*
 * getRequestedStateStr
 */
string
CProcessorCore::getRequestedStateStr (void) const
{ 
	return CIM_ProcessorCore::getValueStr_RequestedState (
			((CProcessorCore*) this)->_pc->getRequestedState ()); 
} 	

/*
 * getOperationalStatus
 */
vector<uint16>
CProcessorCore::getOperationalStatus (void) const
{ 
	return ((CProcessorCore*) this)->_pc->getOperationalStatus (); 
}

/*
 * getOperationalStatusStr
 */
vector<string>
CProcessorCore::getOperationalStatusStr (void) const 
{
	vector<uint16> status = ((CProcessorCore*) this)->_pc->getOperationalStatus ();
	vector <string> status_str;
	for(size_t value = 0; value < status.size(); value++ )
	{
		status_str.push_back(((CProcessorCore*) this)->_pc->getValueStr_OperationalStatus (status [value]));
	}

	return status_str;
}

/*
 * getHealthState
 */
uint16 
CProcessorCore::getHealthState (void) const
{ 
	return ((CProcessorCore*) this)->_pc->getHealthState (); 
}

/*
 * getHealthStateStr
 */
string
CProcessorCore::getHealthStateStr (void) const
{ 
	return CIM_ProcessorCore::getValueStr_HealthState (
			((CProcessorCore*) this)->_pc->getHealthState ()); 
}

/*
 * getElementName
 */
string
CProcessorCore::getElementName (void) const
{ 
	return ((CProcessorCore*) this)->_pc->getElementName (); 
}

/*
 * Processor core status
 */
const uint16 CProcessorCore::unknown				= CIM_ProcessorCore::CoreEnabledState_Unknown;
const uint16 CProcessorCore::reserved				= CIM_ProcessorCore::CoreEnabledState_DMTF_Reserved;
const uint16 CProcessorCore::enabled				= CIM_ProcessorCore::CoreEnabledState_Core_Enabled;
const uint16 CProcessorCore::disabled				= CIM_ProcessorCore::CoreEnabledState_Core_Disabled;
const uint16 CProcessorCore::disabled_by_user		= CIM_ProcessorCore::CoreEnabledState_Core_Disabled_by_User;
const uint16 CProcessorCore::disabled_by_POST_error	= CIM_ProcessorCore::CoreEnabledState_Core_Disabled_By_POST_Error_;

/* 
 *Processor characteristics
 */
const uint16 characteristics_unknown	= CIM_ProcessorCore::Characteristics_Unknown;
const uint16 characteristics_reserved	= CIM_ProcessorCore::Characteristics_DMTF_Reserved;
const uint16 characteristics_64_bit		= CIM_ProcessorCore::Characteristics_64_bit_Capable;
const uint16 characteristics_32_bit		= CIM_ProcessorCore::Characteristics_32_bit_Capable;


/*
 * getCachedProps
 */
vector<string> 
CProcessorCore::getCachedProps (void)
{
	vector<string> props;
	props.push_back ("InstanceID");
	props.push_back ("CoreEnableState");
	props.push_back ("LoadPercentage");
	props.push_back ("ElementName");
	props.push_back ("EnabledState");
	props.push_back ("RequestedState");
	props.push_back ("OperationalStatus");
	props.push_back ("HealthState");
	return props;
}

/*
 * CProcessorCore::Iterator
 */
DEFINE_API_ITERATOR (CProcessorCore);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CProcessorCore, CIM_ProcessorCore);


/*
 * Constructor
 */
CProcessor::CProcessor (const CIM_Processor& proc)
{ 
	_proc = new CIM_Processor (proc); 
}

/*
 * Constructor
 */
CProcessor::CProcessor (const CProcessor& proc)
{
	this->_proc = new CIM_Processor (*(proc._proc));
}

/*
 * Destruction 
 */
CProcessor::~CProcessor ()
{
	if (this->_proc) { delete this->_proc; }
}

/*
 * Assignment operator
 */
const CProcessor& 
CProcessor::operator = (const CProcessor& rhs)
{
	if (this->_proc) { delete this->_proc; }
	this->_proc  = new CIM_Processor (*rhs._proc);
	return *this;
}

/*
 * enumProcessors
 */
CProcessor::iterator 
CProcessor::enumProcessors (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_Processor::iterator iter = 
				CIM_Processor::enumInstances (client, 0, props);

	if (cached) { return createIterator (iter, props);}
	else 		{ return createIterator (iter); 		}
}

/*
 * getSystemCreationClassName 
 */
string 
CProcessor::getSystemCreationClassName (void) const 
{ 
	return this->_proc->getSystemCreationClassName ();
} 	

/*
 * getSystemName 
 */
string 
CProcessor::getSystemName (void) const 
{ 
	return this->_proc->getSystemName ();
} 	

/*
 * getCreationClassName 
 */
string 
CProcessor::getCreationClassName (void) const 
{ 
	return this->_proc->getCreationClassName ();
} 	

/*
 * getDeviceID
 */
string 
CProcessor::getDeviceID (void) const 
{ 
	return this->_proc->getDeviceID ();
} 	

/*
 * getFamily 
 */
string 
CProcessor::getFamily (void) const 
{ 
	return CIM_Processor::getValueStr_Family (
					((CProcessor*) this)->_proc->getFamily ()); 
} 	

/*
 * getCurrentClockSpeed
 */
uint32 
CProcessor::getCurrentClockSpeed (void) const
{ 
	return ((CProcessor*) this)->_proc->getCurrentClockSpeed (); 
} 	

/*
 * getMaxClockSpeed 
 */
uint32 
CProcessor::getMaxClockSpeed (void) const
{
	return ((CProcessor*) this)->_proc->getMaxClockSpeed (); 
}

/*
 * getExternalBusClockSpeed 
 */
uint32 
CProcessor::getExternalBusClockSpeed (void) const
{
	return ((CProcessor*) this)->_proc->getExternalBusClockSpeed (); 
}

/*
 * getCPUStatus
 */
uint16
CProcessor::getCPUStatus (void) const
{ 
	return ((CProcessor*) this)->_proc->getCPUStatus (); 
} 	
 	

/*
 * getCPUStatusStr
 */
string 
CProcessor::getCPUStatusStr (void) const
{
	return CIM_Processor::getValueStr_CPUStatus (_proc->getCPUStatus ());
}

/*
 * getLoadPercentage
 */
uint32 
CProcessor::getLoadPercentage (void) const
{ 
	return ((CProcessor*) this)->_proc->getLoadPercentage (); 
} 	

/*
 * getEnabledState
 */
uint16 
CProcessor::getEnabledState (void) const
{ 
	return ((CProcessor*) this)->_proc->getEnabledState (); 
} 	

/*
 * getEnabledStateStr
 */
string
CProcessor::getEnabledStateStr (void) const
{ 
	return CIM_Processor::getValueStr_EnabledState (
				((CProcessor*) this)->_proc->getEnabledState ()); 
} 

/*
 * getRequestedState
 */
uint16
CProcessor::getRequestedState (void) const
{ 
	return ((CProcessor*) this)->_proc->getRequestedState (); 
} 	

/*
 * getRequestedStateStr
 */
string
CProcessor::getRequestedStateStr (void) const
{ 
	return CIM_Processor::getValueStr_RequestedState (
			((CProcessor*) this)->_proc->getRequestedState ()); 
} 	

/*
 * getOperationalStatus
 */
vector<uint16>
CProcessor::getOperationalStatus (void) const
{ 
	return ((CProcessor*) this)->_proc->getOperationalStatus (); 
} 	

/*
 * getOperationalStatusStr
 */
vector<string>
CProcessor::getOperationalStatusStr (void) const 
{
	vector<uint16> status = ((CProcessor*) this)->_proc->getOperationalStatus ();
	vector <string> status_str;
	for(size_t value = 0; value < status.size(); value++ )
	{
		status_str.push_back(((CProcessor*) this)->_proc->getValueStr_OperationalStatus (status [value]));
	}

	return status_str;
}

/*
 * getHealthState
 */
uint16
CProcessor::getHealthState (void) const
{ 
	return ((CProcessor*) this)->_proc->getHealthState (); 
} 	

/*
 * getHealthStateStr
 */
string
CProcessor::getHealthStateStr (void) const
{ 
	return CIM_Processor::getValueStr_HealthState (
			((CProcessor*) this)->_proc->getHealthState ()); 
} 	

/*
 * getElementName
 */
string
CProcessor::getElementName (void) const
{ 
	return ((CProcessor*) this)->_proc->getElementName (); 
} 	

/*
 * getOtherFamilyDescription
 */
string 
CProcessor::getOtherFamilyDescription (void) const
{ 
	return ((CProcessor*) this)->_proc->getOtherFamilyDescription (); 
} 	

/*
 * enableProcessor
 */
uint32
CProcessor::enableProcessor (void)
{
	datetime 		immediate = CCIMDateTime (0, true);
	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

	uint32 status = this->_proc->RequestStateChange (
		CIM_Processor::RequestStateChange_RequestedState_Enabled, &job, immediate);

	/* if RequestStateChange is success(0) return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else 
	{
		string retcodestr = CIM_Processor::getValueStr_RequestStateChange_ReturnCode (status);
			throw EFunctionReturnedWithFailure ("CIM_Processor::RequestStateChange", 
													retcodestr, status);
	}
}

/*
 * disableProcessor
 */
uint32
CProcessor::disableProcessor (void)
{
	datetime 		immediate = CCIMDateTime (0, true);
	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

	uint32 status = this->_proc->RequestStateChange (
		CIM_Processor::RequestStateChange_RequestedState_Disabled, &job, immediate);

	/* if RequestStateChange is success(0) return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else 
	{
		string retcodestr = CIM_Processor::getValueStr_RequestStateChange_ReturnCode (status);
			throw EFunctionReturnedWithFailure ("CIM_Processor::RequestStateChange", 
													retcodestr, status);
	}
}

/*
 * resetProcessor
 */
uint32
CProcessor::resetProcessor (void)
{
	datetime 		immediate = CCIMDateTime (0, true);
	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

	uint32 status = this->_proc->RequestStateChange (
			CIM_Processor::RequestStateChange_RequestedState_Reset, &job, immediate);

	/* if RequestStateChange is success(0) return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else 
	{
		string retcodestr = CIM_Processor::getValueStr_RequestStateChange_ReturnCode (status);
			throw EFunctionReturnedWithFailure ("CIM_Processor::RequestStateChange", 
													retcodestr, status);
	}
}

/*
 * The status of the processor
 */
const uint16 CProcessor::unknown 			= CIM_Processor::CPUStatus_Unknown;
const uint16 CProcessor::enabled			= CIM_Processor::CPUStatus_CPU_Enabled;
const uint16 CProcessor::disabled_by_user	= CIM_Processor::CPUStatus_CPU_Disabled_by_User;
const uint16 CProcessor::disabled_by_BIOS	= CIM_Processor::CPUStatus_CPU_Disabled_By_BIOS__POST_Error_;
const uint16 CProcessor::idle				= CIM_Processor::CPUStatus_CPU_Is_Idle;
const uint16 CProcessor::other				= CIM_Processor::CPUStatus_Other;

/*
 * getCachedProps
 */
vector<string> 
CProcessor::getCachedProps (void)
{
	vector<string> props;
	props.push_back ("SystemCreationClassName");
	props.push_back ("SystemName");
	props.push_back ("CreationClassName");
	props.push_back ("DeviceID");
	props.push_back ("ElementName");
	props.push_back ("EnabledState");
	props.push_back ("RequestedState");
	props.push_back ("OperationalStatus");
	props.push_back ("HealthState");
	props.push_back ("Family");
	props.push_back ("MaxClockSpeed");
	props.push_back ("CurrentClockSpeed");
	props.push_back ("ExternalBusClockSpeed");
	props.push_back ("LoadPercentage");
	props.push_back ("CPUStatus");
	props.push_back ("OtherFamilyDescription");
	return props;
}


/*
 * CProcessor::Iterator
 */
DEFINE_API_ITERATOR (CProcessor);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CProcessor, CIM_Processor);
