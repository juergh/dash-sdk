
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
 * enumerator.c
 * Enumeration functions.
 */
#include <dsdk/oal/CIM_ComputerSystem.h>
#include <dsdk/oal/CIM_ProcessorCore.h>
#include <dsdk/oal/CIM_Processor.h>
#include <dsdk/oal/CIM_AssociatedPowerManagementService.h>
#include <dsdk/oal/CIM_PowerManagementService.h>
#include <dsdk/oal/CIM_ServiceAvailableToElement.h>
#include <dsdk/oal/CIM_SystemDevice.h>
#include <dsdk/oal/CIM_Realizes.h>
#include <dsdk/oal/CIM_OwningCollectionElement.h>
#include <dsdk/oal/CIM_AssociatedMemory.h>
#include <dsdk/oal/CIM_AssociatedSensor.h>
#include <dsdk/oal/CIM_AssociatedCooling.h>
#include <dsdk/oal/CIM_ConcreteComponent.h>
#include <dsdk/oal/CIM_RedundancySet.h>
#include <dsdk/oal/CIM_InstalledSoftwareIdentity.h>
#include <dsdk/oal/CIM_Memory.h>
#include <dsdk/oal/CIM_Account.h>
#include <dsdk/oal/CIM_Sensor.h>
#include <dsdk/oal/CIM_NumericSensor.h>
#include <dsdk/oal/CIM_Fan.h>
#include <dsdk/oal/CIM_PowerSupply.h>
#include <dsdk/oal/CIM_PhysicalMemory.h>
#include <dsdk/oal/CIM_PhysicalElement.h>
#include <dsdk/oal/CIM_SoftwareIdentity.h>
#include <dsdk/oal/CIM_ElementSettingData.h>
#include <dsdk/oal/CIM_AccountOnSystem.h>
#include <dsdk/oal/CIM_BootService.h>
#include <dsdk/oal/CIM_BootConfigSetting.h>
#include <dsdk/oal/CIM_OrderedComponent.h>
#include <dsdk/computersystem.h>
#include <dsdk/physicalasset.h>
#include <dsdk/memory.h>
#include <dsdk/processor.h>
#include <dsdk/powersupply.h>
#include <dsdk/fan.h>
#include <dsdk/sensor.h>
#include <dsdk/biosmanagement.h>
#include "enumeratortemplate.h"
#include <dsdk/enumerator.h>


namespace dsdk
{


/*
 * enumProcessors
 */
CProcessor::iterator  
enumProcessors (IClient* client, CComputerSystem cs)
{
	return enumSystemDevicePart<CComputerSystem, CProcessor> (client, cs);
}

/*
 * enumMemory
 */
CMemory::iterator  
enumMemory (IClient* client, CComputerSystem cs)
{
	return enumSystemDevicePart<CComputerSystem, CMemory> (client, cs);
}

/*
 * enumBootConfigs
 */
CBootConfig::iterator 
enumBootConfigs (IClient* client, CComputerSystem cs)
{
	return 	enumElementSettingDataSettingData <CComputerSystem, CBootConfig> (client, cs);
}

/*
 * enumUsers
 */
CUser::iterator
enumUsers (IClient* client, CComputerSystem cs)
{
	return enumAccountOnSystemPart <CComputerSystem, CUser> (client, cs);
}



/*
 * enumNumericSensors
 */
CNumericSensor::iterator 
enumNumericSensors	(IClient* client, CComputerSystem cs)
{
	return enumSystemDevicePart<CComputerSystem, CNumericSensor> (client, cs);
}

/*
 * enumSensors
 */
CSensor::iterator 
enumSensors	(IClient* client, CComputerSystem cs)
{
	return enumSystemDevicePart<CComputerSystem, CSensor> (client, cs);
}

/*
 * enumFans
 */
CFan::iterator
enumFans	(IClient* client, CComputerSystem cs)
{
	return enumSystemDevicePart<CComputerSystem, CFan> (client, cs);
}

/*
 * enumPowerSupplies
 */
CPowerSupply::iterator	  
enumPowerSupplies	 (IClient* client, CComputerSystem cs)
{
	return enumSystemDevicePart<CComputerSystem, CPowerSupply> (client, cs);
}

/*
 * enumCPhysicalAssets
 */
CPhysicalAsset::iterator  
enumPhysicalAssets (IClient* client, CComputerSystem cs)
{
	return enumSystemPackageAntecedent <CPhysicalAsset, CComputerSystem> (client, cs);
}

/*
 * enumSoftware
 */
CSoftware::iterator		  
enumSoftware (IClient* client, CComputerSystem cs)
{
	return enumSystemDevicePart<CComputerSystem, CSoftware> (client, cs);
}

/*
 * enumProcessorCores
 */
CProcessorCore::iterator  
enumProcessorCores  (IClient* client, CProcessor proc)
{
	return enumConcreteComponentPart <CProcessor,CProcessorCore> (client ,proc);
}

/*
 * enumMemory
 */
CMemory::iterator  
enumMemory (IClient* client, CProcessor proc)
{
	return enumAssociatedMemoryAntecedent <CProcessor, CMemory> (client, proc);
}

/*
 * enumCSensors
 */
CSensor::iterator  
enumSensors (IClient* client, CProcessor proc)
{
	return enumSystemDevicePart<CProcessor, CSensor> (client, proc);
}

/*
 * enumCNumericSensors
 */
CNumericSensor::iterator  
enumNumericSensors (IClient* client, CProcessor proc)
{
	return enumSystemDevicePart<CProcessor, CNumericSensor> (client, proc);
}

/*
 * enumFans
 */
CFan::iterator
enumFans (IClient* client, CProcessor proc)
{
	return enumAssociatedCoolingAntecedent <CProcessor, CFan> (client, proc);
}

/*
 * enumCPhysicalAssets
 */
CPhysicalAsset::iterator  
enumPhysicalAssets (IClient* client, CProcessor proc)
{
	return enumPhysicalAsset<CProcessor> (client, proc);
}

/*
 * enumCPhysicalAssets
 */
CPhysicalAsset::iterator  
enumPhysicalAssets (IClient* client, CMemory memory)
{
	return enumPhysicalAsset<CMemory> (client, memory);
}

/*
 * enumProcessors
 */
CProcessor::iterator		
enumProcessors (IClient* client, CFan fan)
{
	return enumAssociatedCoolingDependent<CProcessor, CFan> (client, fan);
}

/*
 * enumSensors
 */
CSensor::iterator			
enumSensors (IClient* client, CFan fan)
{
	return enumAssociatedSensorAntecedent<CFan, CSensor> (client, fan);
}

/*
 * enumNumericSensors
 */
CNumericSensor::iterator	
enumNumericSensors (IClient* client, CFan fan)
{
	return enumAssociatedSensorAntecedent<CFan, CNumericSensor> (client, fan);
}

/*
 * enumPhysicalAssets
 */
CPhysicalAsset::iterator  
enumPhysicalAssets	 (IClient* client, CFan fan)
{
	return enumPhysicalAsset<CFan> (client, fan);
}


/*
 * enumPhysicalAssets
 */
CPhysicalAsset::iterator  
enumPhysicalAssets	 (IClient* client, CPowerSupply ps)
{
	return enumPhysicalAsset<CPowerSupply> (client, ps);
}

/*
 * enumBiosAttributes
 */
CBIOSAttribute::iterator  
enumBIOSAttributes (IClient* client, CBIOSElement be)
{
	return enumConcreteComponentPart <CBIOSElement, CBIOSAttribute> (client ,be);
}

};
