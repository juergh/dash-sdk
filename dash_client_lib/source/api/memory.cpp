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
 * memory.cpp
 * Classes representing a memory.
 **/
#include <dsdk/oal/CIM_Memory.h>
#include <dsdk/memory.h>
#include "apiimp.h"

using namespace dsdk;

/*
 * Constructor
 */
CMemory::CMemory (const CIM_Memory& memory)
{ 
	_memory = new CIM_Memory (memory); 
}

/*
 * Constructor
 */
CMemory::CMemory (const CMemory& memory)
{
	this->_memory = new CIM_Memory (*(memory._memory));
}

/*
 * Destruction 
 */
CMemory::~CMemory ()
{
	if (this->_memory) { delete this->_memory; }
}

/*
 * Assignment operator
 */
const CMemory& 
CMemory::operator = (const CMemory& rhs)
{
	if (this->_memory) { delete this->_memory; }
	this->_memory  = new CIM_Memory (*rhs._memory);
	return *this;
}

/*
 * enumerateMemory
 */
CMemory::iterator 
CMemory::enumMemory (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_Memory::iterator iter = 
				CIM_Memory::enumInstances (client, 0, props);

	if (cached) { return createIterator (iter, props);  }
	else 		{ return createIterator (iter); 		}
}

/*
 * getSystemCreationClassName 
 */
string 
CMemory::getSystemCreationClassName (void) const 
{ 
	return this->_memory->getSystemCreationClassName ();
} 	

/*
 * getSystemName 
 */
string 
CMemory::getSystemName (void) const 
{ 
	return this->_memory->getSystemName ();
} 	

/*
 * getCreationClassName 
 */
string 
CMemory::getCreationClassName (void) const 
{ 
	return this->_memory->getCreationClassName ();
} 	

/*
 * getDeviceID
 */
string 
CMemory::getDeviceID (void) const 
{ 
	return this->_memory->getDeviceID ();
} 	

/*
 * isVolatile 
 */
boolean
CMemory::isVolatile (void) const 
{ 
	return ((CMemory*) this)->_memory->getVolatile (); 
} 	

/*
 * getAccess
 */
uint16 
CMemory::getAccess (void) const
{ 
	return ((CMemory*) this)->_memory->getAccess (); 
} 	

/*
 * getAccessStr
 */
string 
CMemory::getAccessStr (void) const
{
	return CIM_Memory::getValueStr_Access (_memory->getAccess ());
}

/*
 * getBlockSize 
 */
uint64
CMemory::getBlockSize (void) const
{
	return ((CMemory*) this)->_memory->getBlockSize (); 
}

/*
 * getNumberOfBlocks 
 */
uint64 
CMemory::getNumberOfBlocks (void) const
{
	return ((CMemory*) this)->_memory->getNumberOfBlocks (); 
}

/*
 * getConsumableBlocks
 */
uint64
CMemory::getConsumableBlocks (void) const
{ 
	return ((CMemory*) this)->_memory->getConsumableBlocks (); 
} 	
 	

/*
 * getEnabledState
 */
uint16 
CMemory::getEnabledState (void) const
{ 
	return ((CMemory*) this)->_memory->getEnabledState (); 
} 	

/*
 * getEnabledStateStr
 */
string
CMemory::getEnabledStateStr (void) const
{ 
	return CIM_Memory::getValueStr_EnabledState (
				((CMemory*) this)->_memory->getEnabledState ()); 
} 

/*
 * getRequestedState
 */
uint16
CMemory::getRequestedState (void) const
{ 
	return ((CMemory*) this)->_memory->getRequestedState (); 
} 	

/*
 * getRequestedStateStr
 */
string
CMemory::getRequestedStateStr (void) const
{ 
	return CIM_Memory::getValueStr_RequestedState (
			((CMemory*) this)->_memory->getRequestedState ()); 
} 	

/*
 * getOperationalStatus
 */
vector<uint16>
CMemory::getOperationalStatus (void) const
{ 
	return ((CMemory*) this)->_memory->getOperationalStatus (); 
} 	

/*
 * getOperationalStatusStr
 */
vector<string>
CMemory::getOperationalStatusStr (void) const 
{
	vector<uint16> status = ((CMemory*) this)->_memory->getOperationalStatus ();
	vector <string> status_str;
	for(size_t value = 0; value < status.size(); value++ )
	{
		status_str.push_back(((CMemory*) this)->_memory->getValueStr_OperationalStatus (status [value]));
	}

	return status_str;
}

/*
 * getHealthState
 */
uint16
CMemory::getHealthState (void) const
{ 
	return ((CMemory*) this)->_memory->getHealthState (); 
} 	

/*
 * getHealthStateStr
 */
string
CMemory::getHealthStateStr (void) const
{ 
	return CIM_Memory::getValueStr_HealthState (
			((CMemory*) this)->_memory->getHealthState ()); 
} 	

/*
 * getElementName
 */
string
CMemory::getElementName (void) const
{ 
	return ((CMemory*) this)->_memory->getElementName (); 
} 	

/*
 * getCachedProps
 */
vector<string> 
CMemory::getCachedProps (void)
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
	props.push_back ("Volatile");
	props.push_back ("Access");
	props.push_back ("BlockSize");
	props.push_back ("NumberOfBlocks");
	props.push_back("ConsumableBlocks");
	return props;
}


/*
 * CMemory::Iterator
 */
DEFINE_API_ITERATOR (CMemory);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CMemory, CIM_Memory);
