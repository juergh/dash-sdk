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
 * bootconfig.cpp
 * Class representing Boot Control.
 */
#include <dsdk/oal/CIM_ComputerSystem.h>
#include <dsdk/oal/CIM_HostedService.h>
#include <dsdk/oal/CIM_BootService.h>
#include <dsdk/oal/CIM_BootServiceCapabilities.h>
#include <dsdk/oal/CIM_BootConfigSetting.h>
#include <dsdk/oal/CIM_ElementSettingData.h>
#include <dsdk/oal/CIM_OrderedComponent.h>
#include <dsdk/oal/CIM_EnabledLogicalElementCapabilities.h>
#include <dsdk/oal/CIM_ElementCapabilities.h>
#include <dsdk/bootconfig.h>
#include <dsdk/dsdkexception.h>
#include "apiimp.h"
#include <dsdk/oal/CIM_ElementCapabilities.h>
#include <dsdk/oal/CIM_ServiceAffectsElement.h>


using namespace dsdk;

/*
 * Constructor
 */
CBootDevice::CBootDevice (const CIM_BootSourceSetting& bss, uint64 sequence)
{ 
	_bss			   = new CIM_BootSourceSetting (bss); 
	_assigned_sequence = sequence;
}

/*
 * Constructor
 */
CBootDevice::CBootDevice (const CBootDevice& bd)
{
	this->_bss				 = new CIM_BootSourceSetting (*(bd._bss));
	this->_assigned_sequence = bd._assigned_sequence;
}

/*
 * Destruction 
 */
CBootDevice::~CBootDevice ()
{
	if (this->_bss) { delete this->_bss; }
}

/*
 * Assignment operator
 */
const CBootDevice& 
CBootDevice::operator = (const CBootDevice& rhs)
{
	if (this->_bss) { delete this->_bss; }
	this->_bss				 = new CIM_BootSourceSetting (*rhs._bss);
	this->_assigned_sequence = rhs._assigned_sequence;
	return *this;
}

/*
 * enumBootDevices
 */
CBootDevice::iterator 
CBootDevice::enumBootDevices (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_BootSourceSetting::iterator iter = 
			CIM_BootSourceSetting::enumInstances (client, 
												 0, 
												 props);
	if (cached) { return createIterator (iter, props);  }
	else 		{ return createIterator (iter); 		}
}

/*
 * getInstanceID
 */
string 
CBootDevice::getInstanceID (void) const
{
	return ((CBootDevice*) this)->_bss->getInstanceID ();
}

/*
 * getElementName
 */
string 
CBootDevice::getElementName (void) const
{
	return ((CBootDevice*) this)->_bss->getElementName ();
}

/*
 * getBootString
 */
string 
CBootDevice::getBootString (void) const
{
	return ((CBootDevice*) this)->_bss->getBootString ();
}

/*
 * getBIOSBootString
 */
string 
CBootDevice::getBIOSBootString (void) const
{
	return ((CBootDevice*) this)->_bss->getBIOSBootString ();
}

/*
 * getStructuredBootString
 */
string 
CBootDevice::getStructuredBootString (void) const
{
	return ((CBootDevice*) this)->_bss->getStructuredBootString ();
}

/*
 * getFailThroughSupported
 */
uint16
CBootDevice::getFailThroughSupported (void) const
{
	return ((CBootDevice*) this)->_bss->getFailThroughSupported ();
}

/*
 * getFailThroughSupportedStr
 */
string
CBootDevice::getFailThroughSupportedStr (void) const
{
	return CIM_BootSourceSetting::getValueStr_FailThroughSupported (
		((CBootDevice*) this)->_bss->getFailThroughSupported ());
}

/*
 * compareBootOrder
 */
bool
CBootDevice::compareBootOrder (const CBootDevice& first, 
							   const CBootDevice& second)
{
	if (first._assigned_sequence < second._assigned_sequence){ return true; }
	else													 { return false;}
}

/*
 * getCachedProps
 */
vector<string> 
CBootDevice::getCachedProps (void) 
{
	vector<string> props;
	props.push_back ("InstanceID");
	props.push_back ("ElementName");
	props.push_back ("BootString");
	props.push_back ("BIOSBootString");
	props.push_back ("StructuredBootString");
	props.push_back ("FailThroughSupported");
	return props;
}

/*
 * CBootDevice::Iterator
 */
DEFINE_API_ITERATOR (CBootDevice);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CBootDevice, CIM_BootSourceSetting);


/*
 * Constructor
 */
CBootConfig::CBootConfig (const CIM_BootConfigSetting& bcs)
{ 
	_bcs = new CIM_BootConfigSetting (bcs); 
}

/*
 * Constructor
 */
CBootConfig::CBootConfig (const CBootConfig& bc)
{
	this->_bcs = new CIM_BootConfigSetting (*(bc._bcs));
}

/*
 * Destruction 
 */
CBootConfig::~CBootConfig ()
{
	if (this->_bcs) { delete this->_bcs; }
}

/*
 * Assignment operator
 */
const CBootConfig& 
CBootConfig::operator = (const CBootConfig& rhs)
{
	if (this->_bcs) { delete this->_bcs; }
	this->_bcs  = new CIM_BootConfigSetting (*rhs._bcs);
	return *this;
}

/*
 * enumBootConfig
 */
CBootConfig::iterator 
CBootConfig::enumBootConfigs (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_BootConfigSetting::iterator iter = 
			CIM_BootConfigSetting::enumInstances (client, 
												 0, 
												 props);
	if (cached) { return createIterator (iter, props);  }
	else 		{ return createIterator (iter); 		}
}

/*
 * getInstanceID
 */
string 
CBootConfig::getInstanceID (void) const
{
	return ((CBootConfig*) this)->_bcs->getInstanceID ();
}

/*
 * getElementName
 */
string 
CBootConfig::getElementName (void) const
{
	return ((CBootConfig*) this)->_bcs->getElementName ();
}

/*
 * isDefaultBoot
 */
bool
CBootConfig::isDefaultBoot (void) const
{
	vector <string> props;
	props.push_back ("IsDefault");

	/* enumerate the boot ordered component for the boot config */
	vector <CIM_ElementSettingData<CIM_ComputerSystem, CIM_BootConfigSetting> > esd =
		CIM_ElementSettingData <CIM_ComputerSystem, CIM_BootConfigSetting>
									::getInstancesBySettingData (this->_bcs->getClient (),
														  *(this->_bcs),
														  props);

	if (0 == esd.size ()) { throw EDSDKError (DSDK_INSTANCE_NOT_FOUND); }

	/* only one instance of element setting data from this boot config 
	will be associated to computer system  so use the first instance */
	return (1 == esd [0].getIsDefault ());
}

/*
 * isCurrentBoot
 */
bool
CBootConfig::isCurrentBoot (void) const
{
	vector <string> props;
	props.push_back ("IsCurrent");

	/* enumerate the boot ordered component for the boot config */
	vector <CIM_ElementSettingData<CIM_ComputerSystem, CIM_BootConfigSetting> > esd =
		CIM_ElementSettingData <CIM_ComputerSystem, CIM_BootConfigSetting>
									::getInstancesBySettingData (this->_bcs->getClient (),
														  *(this->_bcs),
														  props);

	if (0 == esd.size ()) { throw EDSDKError (DSDK_INSTANCE_NOT_FOUND); }

	/* only one instance of element setting data from this boot config 
	will be associated to computer system  so use the first instance */
	return (1 == esd [0].getIsCurrent ());
}

/*
 * isNextBoot
 */
bool
CBootConfig::isNextBoot (void) const
{
	vector <string> props;
	props.push_back ("IsNext");

	/* enumerate the boot ordered component for the boot config */
	vector <CIM_ElementSettingData<CIM_ComputerSystem, CIM_BootConfigSetting> > esd =
		CIM_ElementSettingData <CIM_ComputerSystem, CIM_BootConfigSetting>
									::getInstancesBySettingData (this->_bcs->getClient (),
														  *(this->_bcs),
														  props);

	if (0 == esd.size ()) { throw EDSDKError (DSDK_INSTANCE_NOT_FOUND); }

	/* only one instance of element setting data from this boot config 
	will be associated to computer system  so use the first instance */
	return (1 == esd [0].getIsNext ());
}


/*
 * setDefaultBoot
 */
uint32
CBootConfig::setDefaultBoot (void)
{
	CIM_BootService bs(CCIMInstance::nullInstance ());

	if(capableOfSetDefaultBoot(bs) == false) {
		throw EFunctionNotSupported ("SetDefaultBoot");
	}


	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());
	uint32 status = bs.SetBootConfigRole (*(this->_bcs), 
				   CIM_BootService::SetBootConfigRole_Role_IsDefault, &job);
	
	/* if set attribute is success return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else 
	{
		string retcodestr = bs.getValueStr_SetBootConfigRole_ReturnCode(status);
		throw EFunctionReturnedWithFailure ("CIM_BootConfigSetting::setDefaultBoot", 
											retcodestr, status);
	}
}

bool
CBootConfig::capableOfSetDefaultBoot(CIM_BootService &bs)	{
	vector <string> empty_props;

	CIM_BootService::iterator iter = 
		CIM_BootService::enumInstances (this->_bcs->getClient (), 
										0, 
										empty_props);
	if (iter == CIM_BootService::iterator::end ())
	{
		return false;
	}
	bs = *iter;
	return true;
}

bool
CBootConfig::capableOfSetDefaultBoot()	{
	CIM_BootService bs(CCIMInstance::nullInstance ());
	return capableOfSetDefaultBoot(bs);
}

/*
 * setNextBoot
 */
uint32
CBootConfig::setNextBoot (void)
{
	CIM_BootService bs(CCIMInstance::nullInstance ());
	if(capableOfSetNextBoot(bs) == false) 
	{
		throw EFunctionNotSupported ("SetNextBoot");
	}

	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

	uint32 status = bs.SetBootConfigRole (*(this->_bcs), 
									CIM_BootService::SetBootConfigRole_Role_IsNext,
									&job);
	
	/* if set attribute is success return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else 
	{
		string retcodestr = bs.getValueStr_SetBootConfigRole_Role((uint16)status);
		throw EFunctionReturnedWithFailure ("CIM_BootConfigSetting::setNextBoot",
											retcodestr, status);
	}
}

bool
CBootConfig::capableOfSetNextBoot(CIM_BootService &bs)
{
	vector <string> empty_props;

	CIM_BootService::iterator iter 
		= CIM_BootService::enumInstances (this->_bcs->getClient (), 
										  0, empty_props);
	
	if (iter == CIM_BootService::iterator::end ())
	{
		return false;
	}

	bs = *iter;
	return true;
}

bool CBootConfig::capableOfSetNextBoot()
{
	CIM_BootService bs(CCIMInstance::nullInstance ());
	return capableOfSetNextBoot(bs);
}

/*
 * getBootOrder
 */
vector<CBootDevice>
CBootConfig::getBootOrder (void) const
{
	list <CBootDevice>	boot_order_list;
	vector<CBootDevice>	boot_order;
	vector <string>		props;

	props.push_back ("AssignedSequence");
	props.push_back ("PartComponent");
	props.push_back ("GroupComponent");

	/* enumerate the boot ordered component for the boot config */
	vector <CIM_OrderedComponent<CIM_BootConfigSetting, CIM_BootSourceSetting> > oc =
		CIM_OrderedComponent <CIM_BootConfigSetting, CIM_BootSourceSetting>
									::getInstancesByGroupComponent (this->_bcs->getClient (),
														  *(this->_bcs),
														  props);

	for (size_t i = 0; i < oc.size (); i++)
	{
		uint64 sequence;

		CIM_BootSourceSetting bss  = CCIMInstance (oc [i].getPartComponent ());
		bss.initialize (this->_bcs->getClient());
		bss.enableCache (CBootDevice::getCachedProps ());
		
		try {
			sequence = oc [i].getAssignedSequence ();
		}
		catch (...)
		{
			sequence = 0;
		}

		CBootDevice boot = CBootDevice (bss, sequence);

		boot_order_list.push_back (boot);
	}

	/* sort the boot order using sequence number */
	boot_order_list.sort (CBootDevice::compareBootOrder);

	/* copy to a vector */
	list<CBootDevice>::iterator iter1 = boot_order_list.begin();
	for (; iter1 != boot_order_list.end (); iter1++)
	{
		CBootDevice bdi = *iter1;
		boot_order.push_back (bdi);
	}

	return boot_order;
}

/*
 * getBootOrder
 */
uint32
CBootConfig::changeBootOrder (const vector<CBootDevice>& boot_order)
{
	vector<CIM_BootSourceSetting>			old_bss;
	vector<CIM_BootSourceSetting>			new_bss;
	size_t									i, j;
	vector <string>							props;
/*
	if (capableOfChangeBootOrder() == false )
	{
		throw EFunctionNotSupported ("Change Boot Order not supported");
	}
*/
	props.push_back ("AssignedSequence");
	props.push_back ("PartComponent");
	props.push_back ("GroupComponent");

	/* enumerate the boot ordered component for the boot config */
	vector <CIM_OrderedComponent<CIM_BootConfigSetting, CIM_BootSourceSetting> > oc =
		CIM_OrderedComponent <CIM_BootConfigSetting, CIM_BootSourceSetting>
									::getInstancesByGroupComponent (this->_bcs->getClient (),
														  *(this->_bcs),
														  props);

	for (size_t i = 0; i < oc.size (); i++)
	{
		CIM_BootSourceSetting bss  = CCIMInstance (oc [i].getPartComponent ());
		bss.initialize (this->_bcs->getClient());
		bss.enableCache (CBootDevice::getCachedProps ());
		old_bss.push_back (bss);
	}

	/* copy the boot order as given from input to new boot source setting (new_bss)*/
	for (i = 0; i < boot_order.size (); i++)
	{
		for (j = 0; j < old_bss.size (); j++)
		{
			/* the boot device match add it the new list */
			if (old_bss [j].getInstanceID () == boot_order [i].getInstanceID ())
			{
				new_bss.push_back (old_bss [j]);
			}
		}
	}

	/* copy the remaining boot devices that are not given from the input */
	for (i = 0; i < old_bss.size (); i++)
	{
		for (j = 0; j < new_bss.size (); j++)
		{
			/* check if we already copied this boot device */
			if (new_bss [j].getInstanceID () == old_bss [i].getInstanceID ())
			{
				break;
			}
		}

		/* if we havent copied the device then copy it */
		if (j == new_bss.size ())
		{
			new_bss.push_back (old_bss [i]);
		}
	}

	uint32 status = this->_bcs->ChangeBootOrder (new_bss, NULL);
	
	/* if set attribute is success return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else 
	{
		string retcodestr = _bcs->getValueStr_ChangeBootOrder_ReturnCode(status);
		throw EFunctionReturnedWithFailure ("CIM_BootConfigSetting::ChangeBootOrder",
											retcodestr, status);
	}
}

/*
 * changeBootOrderSupport
 */
bool
CBootConfig::capableOfchangeBootOrder () 
{
	vector <string> empty_props;
	CIM_BootService::iterator iter 
		= CIM_BootService::enumInstances (this->_bcs->getClient (), 
										  0, 
										  empty_props);
	if (iter == CIM_BootService::iterator::end ())
	{
		return false;
	}

	CIM_BootService bs = *iter;
	return true;

	// As of 2/3/10, there is no support availabel for CIM_BootServiceCapabilities on any target,
	// so, following  code is bypassed and present spec doesn't mention for this verification.
/*
	CIM_BootServiceCapabilities::iterator eleciter =
			CIM_ElementCapabilities <CIM_BootService, CIM_BootServiceCapabilities>::
			enumerateCapabilities (this->_bcs->getClient (), bs ,empty_props);

	if (eleciter == CIM_BootServiceCapabilities::iterator::end ())
	{
		throw EFunctionNotSupported ("Change Boot Order.");
	} 

	CIM_BootServiceCapabilities bs_ems = *eleciter;
	return bs_ems.getBootConfigCapabilities();
*/

} 



/*
 * changeBootOrderSupport
 */
/* vector<uint16>
CBootConfig::changeBootOrderSupport (void) const
{
	vector <string> empty_props;
	CIM_BootService::iterator iter 
		= CIM_BootService::enumInstances (this->_bcs->getClient (), 
										  0, 
										  empty_props);
	if (iter == CIM_BootService::iterator::end ())
	{
		throw EFunctionNotSupported ("Change Boot Order");
	}

	CIM_BootService bs = *iter;


	CIM_BootServiceCapabilities::iterator eleciter =
			CIM_ElementCapabilities <CIM_BootService, CIM_BootServiceCapabilities>::
			enumerateCapabilities (this->_bcs->getClient (), bs ,empty_props);

	if (eleciter == CIM_BootServiceCapabilities::iterator::end ())
	{
		throw EFunctionNotSupported ("Change Boot Order.");
	} 

	CIM_BootServiceCapabilities bs_ems = *eleciter;
	return bs_ems.getBootConfigCapabilities();
} */


/*
 * addBootConfig
 */

CBootConfig
CBootConfig::addBootConfig (const CComputerSystem& cs, const CBootConfig& bc)
{

	/* Enumerate the Boot Service with this CS */
	CIM_BootService bs(CCIMInstance::nullInstance ());
	CBootConfig CBC (CCIMInstance::nullInstance ());  // Without this, non static fun call can't be done
	if(CBC.capableOfAddBootConfig(cs,bs) == false) {
		throw EFunctionNotSupported ("addBootConfig");
	}

	/* Create the boot config using boot service */
	CIM_BootConfigSetting	boot_config (CCIMInstance::nullInstance ());

	if (0 != bs.CreateBootConfigSetting (*(bc._bcs), *(cs.getCIMObject ()), &boot_config, NULL))
	{
		throw EDSDKError (DSDK_CREATE_BOOT_CONFIG_FAILED); 
	}

	return boot_config;
}

/*
 * addBootConfig
 */
CBootConfig
CBootConfig::addBootConfig (const CComputerSystem& cs)
{
	/* create a null instance template to create the boot config with default value */
	CBootConfig bc (CCIMInstance::nullInstance ());
	return addBootConfig (cs, bc);
}


/*
 * deleteBootConfig
 **/
void
CBootConfig::deleteBootConfig (void)
{
	_bcs->getClient ()->deleteInstance (_bcs->getObjectPath ());
}



bool 
CBootConfig::capableOfBootConfigManagement(const CComputerSystem &cs, CIM_BootService &bs, CIM_BootServiceCapabilities &bsc)
{
	vector<string>	empty_props;
	CIM_BootService::iterator iter = CIM_BootService::enumInstances (cs.getCIMObject ()->getClient (), 
																	 0, empty_props);
	// Veriry whether BootService instance Exists or not.
	if (iter == CIM_BootService::iterator::end ())
		return false;

	bs = *iter;
			
	// Verify whether at least a BootServiceCapabilities instance exists.
	CIM_BootServiceCapabilities::iterator eleciter =
			CIM_ElementCapabilities <CIM_BootService, CIM_BootServiceCapabilities>::
			enumerateCapabilities (bs.getClient(), bs ,empty_props);

	if (eleciter == CIM_BootServiceCapabilities::iterator::end ())
		return false;

	bsc = *eleciter;

	return false;
}

bool 
CBootConfig::capableOfBootConfigManagement(const CComputerSystem &cs)
{
	CIM_BootService bs (CCIMInstance::nullInstance ());
	CIM_BootServiceCapabilities bsc (CCIMInstance::nullInstance ());
	if ( capableOfBootConfigManagement(cs, bs, bsc)== true )
		return true;

	return false;
}



bool
CBootConfig::capableOfAddBootConfig(const CComputerSystem &cs, CIM_BootService &bs )
{
	CIM_BootServiceCapabilities bsc (CCIMInstance::nullInstance ());
	// Verify whether the BootService and BootServiceCapabilities instance exists or not.
	if ( capableOfBootConfigManagement(cs, bs, bsc)== false )
		return false;

	vector <uint16> states = bsc.getBootConfigCapabilities();

	// Verify whether at least a BootServiceCapabilities  property exists or not
	if (states.size() == 0 )
		return false;
	// Verify whether the BootConfigCapabilities property contains the Value 2
	for (size_t i=0; i < states.size(); i++)
	{
		if (states[i] == CIM_BootServiceCapabilities::BootConfigCapabilities_Applies_Boot_Configuration )
			return true;
	}
	return true;
}

bool
CBootConfig::capableOfAddBootConfig(const CComputerSystem &cs)
{
	/* create a null instance template to create the boot config with default value */
	CIM_BootService bs (CCIMInstance::nullInstance ());
	return capableOfAddBootConfig(cs, bs);
}
bool
CBootConfig::capableOfDeleteBootConfig(const CComputerSystem &cs)
{
	/* create a null instance template to create the boot config with default value */
	CIM_BootService bs (CCIMInstance::nullInstance ());
	// If the BooService is able to do addBootConfig then it able to deleteBootConfig
	return capableOfAddBootConfig(cs, bs);
}

bool 
CBootConfig::getBootCapabilitiesSupported(const CComputerSystem &cs, vector<uint16> &states_val)
{
	CIM_BootServiceCapabilities bsc (CCIMInstance::nullInstance ());
	CIM_BootService bs (CCIMInstance::nullInstance ());
	// Verify whether the BootService and BootServiceCapabilities instance exists or not.
	if ( capableOfBootConfigManagement(cs, bs, bsc)== false )
		return false;

	states_val = bsc.getBootCapabilitiesSupported();
	if ( states_val.size() == 0)
		return false;

	return true;
}

bool
CBootConfig::getBootCapabilitiesSupportedStr(const CComputerSystem &cs, vector<string> &states_str)
{
	vector<uint16> states_val;

	CIM_BootServiceCapabilities bsc (CCIMInstance::nullInstance ());
	CIM_BootService bs (CCIMInstance::nullInstance ());
	// Verify whether the BootService and BootServiceCapabilities instance exists or not.
	if ( capableOfBootConfigManagement(cs, bs, bsc)== false )
		return false;

	states_val = bsc.getBootCapabilitiesSupported();
	if ( states_val.size() == 0)
		return false;
	for ( size_t i=0; i < states_val.size(); i++)
	{	
		states_str.push_back(bsc.getValueStr_BootCapabilitiesSupported(states_val[i]));
	}

	return true;	
}


bool 
CBootConfig::getBootStringsSupported(const CComputerSystem &cs, vector<uint16> &states_val)
{
	CIM_BootServiceCapabilities bsc (CCIMInstance::nullInstance ());
	CIM_BootService bs (CCIMInstance::nullInstance ());
	// Verify whether the BootService and BootServiceCapabilities instance exists or not.
	if ( capableOfBootConfigManagement(cs, bs, bsc)== false )
		return false;

	states_val = bsc.getBootStringsSupported();
	if ( states_val.size() == 0)
		return false;

	return true;
}

bool
CBootConfig::getBootStringsSupportedStr(const CComputerSystem &cs, vector<string> &states_str)
{
	vector<uint16> states_val;

	CIM_BootServiceCapabilities bsc (CCIMInstance::nullInstance ());
	CIM_BootService bs (CCIMInstance::nullInstance ());
	// Verify whether the BootService and BootServiceCapabilities instance exists or not.
	if ( capableOfBootConfigManagement(cs, bs, bsc)== false )
		return false;

	states_val = bsc.getBootStringsSupported();
	if ( states_val.size() == 0)
		return false;
	for ( size_t i=0; i < states_val.size(); i++)
	{	
		states_str.push_back(bsc.getValueStr_BootStringsSupported(states_val[i]));
	}

	return true;	
}



/*
 * getCachedProps
 */
vector<string> 
CBootConfig::getCachedProps (void) 
{
	vector<string> props;
	props.push_back ("InstanceID");
	props.push_back ("ElementName");
	return props;
}


/*
 * CBootConfig::Iterator
 */
DEFINE_API_ITERATOR (CBootConfig);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CBootConfig, CIM_BootConfigSetting);
