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
 * enumeratortemplate.h
 * Enumeration template functions.
 */
#ifndef __DSDK_ENUMERATOR_TEMPLATE_H__
#define __DSDK_ENUMERATOR_TEMPLATE_H__
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
#include <dsdk/oal/CIM_ElementSettingData.h>
#include <dsdk/oal/CIM_AccountOnSystem.h>
#include <dsdk/oal/CIM_ComputerSystemPackage.h>
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
#include "apiimp.h"

namespace dsdk
{

/**
 * Enumerate the physical assets.
 * Applies to CFan, CProcessor, CPowerSupply
 */
template <class T_Dependent>
inline CPhysicalAsset::iterator
enumPhysicalAsset (IClient* 	  client, 
				   T_Dependent	  dep, 
				   vector<string> props = CPhysicalAsset::getCachedProps ())
{
	CIM_PhysicalElement::iterator iter = 
		CIM_Realizes<CIM_PhysicalElement, 
				 	 typename T_Dependent::CIMType>::enumerateAntecedent (client, 
														*(dep.getCIMObject ()),
														props);
	return createIterator (iter);
}

template <class T_Antecedent, class T_Dependent>
inline typename T_Antecedent::iterator
enumSystemPackageAntecedent (IClient* 	  client, 
							 T_Dependent	  dep, 
							 vector<string> props = CPhysicalAsset::getCachedProps ())
{
	CIM_PhysicalElement::iterator iter = 
		CIM_ComputerSystemPackage <CIM_PhysicalElement, 
				 	 typename T_Dependent::CIMType>::enumerateAntecedent (client, 
														*(dep.getCIMObject ()),
														props);
	return createIterator (iter);
}

template <class T_Antecedent, class T_Dependent>
inline typename T_Dependent::iterator
enumSystemPackageDependent (IClient* 		client, 
							T_Antecedent	antecedent, 
							vector<string> props = T_Dependent::getCachedProps ())
{
	CIM_PhysicalElement::iterator iter = 
		CIM_ComputerSystemPackage <CIM_PhysicalElement, 
				 	 typename T_Antecedent::CIMType>::enumerateDependent (client, 
														*(antecedent.getCIMObject ()),
														props);
	return createIterator (iter);
}

/**
 * Enumerate the redundancy sets
 * This applies CFanRedundancySet, CPowerSupplyRedundancySet
 */
template <class T_RedundancySet, class T_Element>
inline typename T_RedundancySet::iterator
enumRedundancySet (IClient*			client,
			       T_Element		elem,
				   vector<string>	props = T_RedundancySet::getCachedProps ())
{
	typename T_RedundancySet::iterator iter = 
		CIM_OwningCollectionElement <
							CIM_RedundancySet, 
							typename T_Element::CIMType>::enumerateOwningElement (
														client, 
														elem.getCIMObject (),
														props);
	return iter;
}

/**
 * Enumerate the part component in the container that matches the result
 * class.
 * The following are currently supported
 * 	CProcessor
 *	CMemory
 *	CFan
 *	CSensor
 *	CPowerSupply
 */
template <class TGroup, class TPart>
inline typename TPart::iterator
enumSystemDevicePart (IClient*	client, 
					  TGroup	group)
{
	typename TPart::CIMType::iterator iter = 
		CIM_SystemDevice <typename TGroup::CIMType, 
						  typename TPart::CIMType>::enumeratePartComponent ( 
													client,
													*(group.getCIMObject ()),
													TPart::getCachedProps ());

	return createIterator (iter, TPart::getCachedProps ());
}


/**
 * Enumerate the group devices in the system device that matches the result
 * class.
 */
template <class TGroup, class TPart>
inline typename TGroup::iterator
enumSystemDeviceGroup (IClient*	client, 
			   		   TPart		part)
{
	typename TGroup::CIMType::iterator iter = 
		CIM_SystemDevice <typename TGroup::CIMType,
						  typename TPart::CIMType>::enumerateGroupComponent ( 
					  								client,
													*(part.getCIMObject ()),
													TGroup::getCachedProps ());
	return createIterator (iter, TGroup::getCachedProps ());
}


/**
 * Enumerate the part component in the concrete container that matches the result
 * class.
 */
template <class TGroup, class TPart>
inline typename TPart::iterator
enumConcreteComponentPart (IClient*	client, 
			   		  TGroup	group)
{
	typename TPart::CIMType::iterator iter = 
		CIM_ConcreteComponent <typename TGroup::CIMType, 
						  typename TPart::CIMType>::enumeratePartComponent ( 
													client,
													(*group.getCIMObject ()),
													TPart::getCachedProps ());
	return createIterator (iter, TPart::getCachedProps ());
}

/**
 * Enumerate the group component from the concrete component that matches the result
 * class.
 */
template <class TGroup, class TPart>
inline typename TGroup::iterator
enumConcreteComponentGroup (IClient*	client, 
			   		   TPart		part)
{
	typename TGroup::CIMType::iterator iter = 
		CIM_SystemDevice <typename TGroup::CIMType,
						  typename TPart::CIMType>::enumerateGroupComponent ( 
					  								client,
													(*part.getCIMObject ()),
													TGroup::getCachedProps ());
	return createIterator (iter, TGroup::getCachedProps ());
}


/**
 * Enumerate the antecedent in the associated memory that matches the result
 * class.
 */
template <class TDependent, class TAntecedent>
inline typename TAntecedent::iterator
enumAssociatedMemoryAntecedent (IClient*		client, 
								TDependent		dependent)
{
	typename TAntecedent::CIMType::iterator iter = 
		CIM_AssociatedMemory <typename TAntecedent::CIMType,
						  typename TDependent::CIMType>::enumerateAntecedent ( 
					  								client,
													(*dependent.getCIMObject ()),
													TAntecedent::getCachedProps ());
	return createIterator (iter, TAntecedent::getCachedProps ());
}


/**
 * Enumerate the dependent in the associated memory that matches the result
 * class.
 */
template <class TDependent, class TAntecedent>
inline typename TDependent::iterator
enumAssociatedMemoryDependent (IClient*			client, 
							   TAntecedent		antecedent)
{
	typename TDependent::CIMType::iterator iter = 
		CIM_AssociatedMemory <typename TDependent::CIMType,
						  typename TAntecedent::CIMType>::enumerateAntecedent ( 
					  								client,
													(*antecedent.getCIMObject ()),
													TDependent::getCachedProps ());
	return createIterator (iter, TDependent::getCachedProps ());
}

/**
 * Enumerate the physical memory
 * Applies to CMemory
 */
template <class T_Dependent>
inline CPhysicalMemory::iterator
enumPhysicalMemory (IClient* 	  client, 
				   T_Dependent	  dep, 
				   vector<string> props = CPhysicalMemory::getCachedProps ())
{
	CIM_PhysicalMemory::iterator iter = 
		CIM_Realizes<CIM_PhysicalMemory, 
				 	 typename T_Dependent::CIMType>::enumerateAntecedent (client, 
														*(dep.getCIMObject ()),
														props);
	return createIterator (iter);
}

/**
 * Enumerate the antecedent in the associated sensor that matches the result
 * class.
 */
template <class TDependent, class TAntecedent>
inline typename TAntecedent::iterator
enumAssociatedSensorAntecedent (IClient*		client, 
								TDependent		dependent)
{
	typename TAntecedent::CIMType::iterator iter = 
		CIM_AssociatedSensor <typename TAntecedent::CIMType,
						  typename TDependent::CIMType>::enumerateAntecedent ( 
					  								client,
													(*dependent.getCIMObject ()),
													TAntecedent::getCachedProps ());
	return createIterator (iter, TAntecedent::getCachedProps ());
}


/**
 * Enumerate the dependent in the associated sensor that matches the result
 * class.
 */
template <class TDependent, class TAntecedent>
inline typename TDependent::iterator
enumAssociatedSensorDependent (IClient*			client, 
							   TAntecedent		antecedent)
{
	typename TDependent::CIMType::iterator iter = 
		CIM_AssociatedSensor <typename TDependent::CIMType,
						  typename TAntecedent::CIMType>::enumerateAntecedent ( 
					  								client,
													(*antecedent.getCIMObject ()),
													TDependent::getCachedProps ());
	return createIterator (iter, TDependent::getCachedProps ());
}


/**
 * Enumerate the antecedent in the associated cooling that matches the result
 * class.
 */
template <class TDependent, class TAntecedent>
inline typename TAntecedent::iterator
enumAssociatedCoolingAntecedent (IClient*		client, 
								TDependent		dependent)
{
	typename TAntecedent::CIMType::iterator iter = 
		CIM_AssociatedCooling <typename TAntecedent::CIMType,
						  typename TDependent::CIMType>::enumerateAntecedent ( 
					  								client,
													(*dependent.getCIMObject ()),
													TAntecedent::getCachedProps ());
	return createIterator (iter, TAntecedent::getCachedProps ());
}


/**
 * Enumerate the dependent in the associated cooling that matches the result
 * class.
 */
template <class TDependent, class TAntecedent>
inline typename TDependent::iterator
enumAssociatedCoolingDependent (IClient*		client, 
								TAntecedent		antecedent)
{
	typename TDependent::CIMType::iterator iter = 
		CIM_AssociatedCooling <typename TDependent::CIMType,
						  typename TAntecedent::CIMType>::enumerateAntecedent ( 
					  								client,
													(*antecedent.getCIMObject ()),
													TDependent::getCachedProps ());
	return createIterator (iter, TDependent::getCachedProps ());
}

/**
 * Enumerate the owning collection element in the container that matches 
 * the result class.
 * This applies to the following pairs
 *	CComputerSystem	CFanRedundancySet
 *	CComputerSystem	CPowerSupplyRedundancySet
 */
template <class TContainer, class TResult>
inline typename TResult::iterator
enumOwningCollectionElement (IClient* 	   	  client, 
			   		   		 TContainer 	  container, 
			   		   		 vector<string>&  props)
{
	typename TResult::iterator iter = 
		CIM_OwningCollectionElement <
						typename TResult::CIMType,
						typename TContainer::CIMType
									>::enumerateOwningElement ( 
					  								client,
													(*container.getCIMObject ()),
													props);
	return iter;
}


/**
 * Enumerate the installed software in the system that matches the result
 * class.
 * The following are currently supported
 * InstalledSoftware
 */
template <class TSystem, class TInstalledSoftware>
inline typename TInstalledSoftware::iterator
enumInstalledSoftwareIdentityInstalledSoftware (IClient*	client, 
											   TSystem	system)
{
	typename TInstalledSoftware::CIMType::iterator iter = 
		CIM_InstalledSoftwareIdentity <typename TSystem::CIMType, 
						  typename TInstalledSoftware::CIMType>::enumerateInstalledSoftware ( 
													client,
													(*system.getCIMObject ()),
													TInstalledSoftware::getCachedProps ());
	return createIterator (iter, TInstalledSoftware::getCachedProps ());
}

/**
 * Enumerate the Accounts on the system
 * class.
 *	CCUser
 */
template <class TGroup, class TPart>
inline typename TPart::iterator
enumAccountOnSystemPart (IClient*	client, 
						 TGroup	group)
{
	typename TPart::CIMType::iterator iter = 
		CIM_AccountOnSystem <typename TGroup::CIMType, 
							 typename TPart::CIMType>::enumeratePartComponent ( 
													client,
													*(group.getCIMObject ()),
													TPart::getCachedProps ());
	return createIterator (iter, TPart::getCachedProps ());
}


/**
 * Enumerate the group devices in the system device that matches the result
 * class.
 */
template <class TGroup, class TPart>
inline typename TGroup::iterator
enumAccountOnSystemGroup (IClient*	client, 
						  TPart		part)
{
	typename TGroup::CIMType::iterator iter = 
		CIM_AccountOnSystem <typename TGroup::CIMType,
							 typename TPart::CIMType>::enumerateGroupComponent ( 
					  								client,
													(*part.getCIMObject ()),
													TGroup::getCachedProps ());
	return createIterator (iter, TGroup::getCachedProps ());
}

/**
 * Enumerate the setting data in the system that matches the result
 * class.
 * The following are currently supported
 * BootConfigSetting
 */
template <class TManagedElement, class TSettingData>
inline typename TSettingData::iterator
enumElementSettingDataSettingData (IClient*	        client, 
								   TManagedElement  me)
{
	typename TSettingData::CIMType::iterator iter = 
		CIM_ElementSettingData <typename TManagedElement::CIMType, 
						    typename  TSettingData::CIMType>::enumerateSettingData ( 
													client,
													*(me.getCIMObject ()),
													TSettingData::getCachedProps ());
	return createIterator (iter, TSettingData::getCachedProps ());
}






};

#endif /* __DSDK_ENUMERATOR_TEMPLATE_H__ */

