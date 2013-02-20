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
 * apiimp.h
 * Iterator Creation functions.
 */
#ifndef __DSDK_APIIMP_H__
#define __DSDK_APIIMP_H__
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
#include <dsdk/oal/CIM_PhysicalPackage.h>
#include <dsdk/oal/CIM_Card.h>
#include <dsdk/oal/CIM_Rack.h>
#include <dsdk/oal/CIM_Chassis.h>
#include <dsdk/oal/CIM_PhysicalConnector.h>
#include <dsdk/oal/CIM_Slot.h>
#include <dsdk/oal/CIM_SoftwareIdentity.h>
#include <dsdk/oal/CIM_ElementSettingData.h>
#include <dsdk/oal/CIM_AccountOnSystem.h>
#include <dsdk/oal/CIM_Role.h>
#include <dsdk/oal/CIM_Privilege.h>
#include <dsdk/oal/CIM_BootService.h>
#include <dsdk/oal/CIM_BootConfigSetting.h>
#include <dsdk/oal/CIM_OrderedComponent.h>
#include <dsdk/oal/CIM_BIOSAttribute.h>
#include <dsdk/oal/CIM_BIOSElement.h>
#include <dsdk/oal/CIM_OperatingSystem.h>
#include <dsdk/oal/CIM_NetworkPort.h>
#include <dsdk/oal/CIM_USBRedirectionService.h>
#include <dsdk/oal/CIM_USBRedirectionSAP.h>
#include <dsdk/oal/CIM_TextRedirectionService.h>
#include <dsdk/oal/CIM_TextRedirectionSAP.h>
#include <dsdk/oal/CIM_OpaqueManagementData.h>
#include <dsdk/oal/CIM_Battery.h>
#include <dsdk/oal/CIM_DHCPProtocolEndpoint.h>
#include <dsdk/oal/CIM_IPProtocolEndpoint.h>
#include <dsdk/oal/CIM_DNSProtocolEndpoint.h>
#include <dsdk/oal/CIM_RegisteredProfile.h>
#include <dsdk/oal/CIM_EthernetPort.h>
#include <dsdk/oal/CIM_IndicationFilter.h>
#include <dsdk/oal/CIM_FilterCollection.h>
#include <dsdk/oal/CIM_IndicationService.h>
#include <dsdk/oal/CIM_IndicationSubscription.h>
#include <dsdk/oal/CIM_AbstractIndicationSubscription.h>
#include <dsdk/oal/CIM_FilterCollectionSubscription.h>
#include <dsdk/oal/CIM_ListenerDestination.h>
#include <dsdk/oal/CIM_ManagedElement.h>
#include <dsdk/computersystem.h>
#include <dsdk/physicalasset.h>
#include <dsdk/memory.h>
#include <dsdk/processor.h>
#include <dsdk/powersupply.h>
#include <dsdk/fan.h>
#include <dsdk/sensor.h>
#include <dsdk/bootconfig.h>
#include <dsdk/software.h>
#include <dsdk/user.h>
#include <dsdk/privilege.h>
#include <dsdk/biosmanagement.h>
#include <dsdk/operatingsystem.h>
#include <dsdk/networkport.h>
#include <dsdk/textredirection.h>
#include <dsdk/usbredirection.h>
#include <dsdk/opaquemanagementdata.h>
#include <dsdk/battery.h>
#include <dsdk/dhcpclient.h>
#include <dsdk/ipinterface.h>
#include <dsdk/dnsclient.h>
#include <dsdk/registeredprofile.h>
#include <dsdk/ethernetport.h>
#include <dsdk/indications.h>


using namespace dsdk;

/**
 * Create's CComputerSystem Iterator from CIM_ComputerSystem iterator
 */
CComputerSystem::iterator createIterator (CIM_ComputerSystem::iterator iter, vector<string> cached_props = vector <string>()); 

/**
 * Create's CBootDevice Iterator from CIM_BootSourceSetting iterator
 */
CBootDevice::iterator createIterator (CIM_BootSourceSetting::iterator iter, vector<string> cached_props = vector <string>()); 

/**
 * Create's CBootConfig Iterator from CIM_BootConfigSetting iterator
 */
CBootConfig::iterator createIterator (CIM_BootConfigSetting::iterator iter, vector<string> cached_props = vector <string>());

/**
 * Create's CFan Iterator from CIM_Fan iterator
 */
CFan::iterator createIterator (CIM_Fan::iterator iter, vector<string> cached_props = vector <string>()); 

/**
 * Create's CMemory Iterator from CIM_Memory iterator
 */
CMemory::iterator createIterator (CIM_Memory::iterator iter, vector<string> cached_props = vector <string>()); 

/**
 * Create's CPhysicalAsset Iterator from CIM_PhysicalElement iterator
 */
CPhysicalAsset::iterator createIterator (CIM_PhysicalElement::iterator iter, vector<string> cached_props = vector <string>()); 

/**
 * Create's CPhysicalMemory Iterator from CIM_PhysicalMemory iterator
 */
CPhysicalMemory::iterator createIterator (CIM_PhysicalMemory::iterator iter, vector<string> cached_props = vector <string>()); 

/**
 * Create's CCard Iterator from CIM_Card iterator
 */
CCard::iterator createIterator (CIM_Card::iterator iter, vector<string> cached_props = vector <string>()); 

/**
 * Create's CPhysicalFrame Iterator from CIM_PhysicalFrame iterator
 */
CPhysicalFrame::iterator createIterator (CIM_PhysicalFrame::iterator iter, vector<string> cached_props = vector <string>()); 

/**
 * Create's CChassis Iterator from CIM_Chassis iterator
 */
CChassis::iterator createIterator (CIM_Chassis::iterator iter, vector<string> cached_props = vector <string>()); 

/**
 * Create's CRack Iterator from CIM_Rack iterator
 */
CRack::iterator createIterator (CIM_Rack::iterator iter, vector<string> cached_props = vector <string>()); 

/**
 * Create's CSlot Iterator from CIM_Slot iterator
 */
CSlot::iterator createIterator (CIM_Slot::iterator iter, vector<string> cached_props = vector <string>()); 

/**
 * Create's CPowerSupply Iterator from CIM_PowerSupply iterator
 */
CPowerSupply::iterator createIterator (CIM_PowerSupply::iterator iter, vector<string> cached_props = vector <string>()); 

/**
 * Create's CProcessor Iterator from CIM_Processor iterator
 */
CProcessor::iterator createIterator (CIM_Processor::iterator iter, vector<string> cached_props = vector <string>());

/**
 * Create's CProcessorCore Iterator from CIM_ProcessorCore iterator
 */
CProcessorCore::iterator createIterator (CIM_ProcessorCore::iterator iter, vector<string> cached_props = vector <string>());

/**
 * Create's CSensor Iterator from CIM_Sensor iterator
 */
CSensor::iterator createIterator (CIM_Sensor::iterator iter, vector<string> cached_props = vector <string>());

/**
 * Create's CNumericSensor Iterator from CIM_NumericSensor iterator
 */
CNumericSensor::iterator createIterator (CIM_NumericSensor::iterator iter, vector<string> cached_props = vector <string>());

/**
 * Create's CSoftware Iterator from CIM_SoftwareIdentity iterator
 */
CSoftware::iterator createIterator (CIM_SoftwareIdentity::iterator iter, vector<string> cached_props = vector <string>());

/**
 * Create's CUser Iterator from CIM_Account iterator
 */
CUser::iterator createIterator (CIM_Account::iterator iter, vector<string> cached_props = vector <string>());

/**
 * Create's CRole Iterator from CIM_Role iterator
 */
CRole::iterator createIterator (CIM_Role::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's CRole Iterator from CIM_Role iterator
 */
CPrivilege::iterator createIterator (CIM_Privilege::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's CBIOSElement Iterator from CIM_BIOSElement iterator
 */
CBIOSElement::iterator createIterator (CIM_BIOSElement::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's CBIOSAttribute Iterator from CIM_BIOSAttribute iterator
 */
CBIOSAttribute::iterator createIterator (CIM_BIOSAttribute::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's COperaingSystem Iterator from CIM_OperatingSystem iterator
 */
COperatingSystem::iterator createIterator (CIM_OperatingSystem::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's CNetworkPort Iterator from CIM_NetworkPort iterator
 */
CNetworkPort::iterator createIterator (CIM_NetworkPort::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's CTextRedirection Iterator from CIM_TextRedirectionSAP iterator
 */
CTextRedirection::iterator createIterator (CIM_TextRedirectionSAP::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's CUSBRedirection Iterator from CIM_USBRedirectionSAP iterator
 */
CUSBRedirection::iterator createIterator (CIM_USBRedirectionSAP::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's COpaqueManagementData Iterator from CIM_OpaqueManagementData iterator
 */
COpaqueManagementData::iterator createIterator (CIM_OpaqueManagementData::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's CBattery Iterator from CIM_Battery iterator
 */
CBattery::iterator createIterator (CIM_Battery::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's CDhcpProtocolEndPoint Iterator from CIM_DHCPProtocolEndpoint iterator
 */
CDHCPClient::iterator createIterator (CIM_DHCPProtocolEndpoint::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's IPProtocolEndPoint Iterator from CIM_IPProtocolEndpoint iterator
 */
CIPInterface::iterator createIterator (CIM_IPProtocolEndpoint::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's DNSProtocolEndPoint Iterator from CIM_DNSProtocolEndpoint iterator
 */
CDNSClient::iterator createIterator (CIM_DNSProtocolEndpoint::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's RegisteredProfile Iterator from CIM_RegisteredProfile iterator
 */
CRegisteredProfile::iterator createIterator (CIM_RegisteredProfile::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's EthernetPort Iterator from CIM_EthernetPort iterator
 */
CEthernetPort::iterator createIterator (CIM_EthernetPort::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's CIndicationFilter Iterator from CIM_IndicationFilter iterator
 */
CIndicationFilter::iterator createIterator (CIM_IndicationFilter::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's CFilterCollection Iterator from CIM_FilterCollection iterator
 */
CFilterCollection::iterator createIterator (CIM_FilterCollection::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's CAlertDestination Iterator from CIM_ListenerDestination iterator
 */
CAlertDestination::iterator createIterator (CIM_ListenerDestination::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's CIndicationSubscription Iterator from CIM_CIndicationSubscription iterator
 */
CAbstractIndicationSubscription::iterator createIterator (CIM_AbstractIndicationSubscription<CIM_ManagedElement, CIM_ListenerDestination>::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's CIndicationSubscription Iterator from CIM_CIndicationSubscription iterator
 */
CIndicationSubscription::iterator createIterator (CIM_IndicationSubscription<CIM_IndicationFilter, CIM_ListenerDestination>::iterator iter, vector<string> cached_props = vector <string>()) ;

/**
 * Create's CFilterCollectionSubscription Iterator from CIM_FilterCollectionSubscriptioniterator
 */
CFilterCollectionSubscription::iterator createIterator (CIM_FilterCollectionSubscription<CIM_FilterCollection, CIM_ListenerDestination>::iterator iter, vector<string> cached_props = vector <string>()) ;

#endif /* __DSDK_APIIMP_H__ */



