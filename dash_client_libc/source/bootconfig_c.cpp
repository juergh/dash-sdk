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
 * bootconfig_c.cpp
 * C wrapper for software.
 */
#include <vector>
#include <string>
#include <cstring>
#include <dsdkc/capi.h>
#include <dsdk/oal/COALObject.h>
#include <dsdkc/bootconfig_c.h>
#include <dsdk/bootconfig.h>
#include <dsdkc/error_c.h>

using namespace dsdk;
extern DSDKBootConfigFT _bcft;

/*
 * Gets the InstanceID 
 */
extern "C" void 
bd_getInstanceID (DSDKBootDevice* bd, char* ins_id, int max_len)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBootDevice* _bd = (CBootDevice*) (bd->hdl);
		string str		 = _bd->getElementName ();
		::snprintf(ins_id,  max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * Gets the element name 
 */
extern "C" void 
bd_getElementName (DSDKBootDevice* bd, char* element_name, int max_len)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBootDevice* _bd = (CBootDevice*) (bd->hdl);
		string str		 = _bd->getElementName ();
		::snprintf(element_name,  max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * Gets the BootString
 */
extern "C" void 
bd_getBootString (DSDKBootDevice* bd, char* bootstring, int max_len)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBootDevice* _bd = (CBootDevice*) (bd->hdl);
		string str		 = _bd->getBootString ();
		::snprintf(bootstring,  max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * Gets the BIOSBootString
 */
extern "C" void 
bd_getBIOSBootString (DSDKBootDevice* bd, char* biosbootstring, int max_len)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBootDevice* _bd = (CBootDevice*) (bd->hdl);
		string str		 = _bd->getBIOSBootString ();
		::snprintf(biosbootstring,  max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * Gets the structuredBootString
 */
extern "C" void 
bd_getStructuredBootString (DSDKBootDevice* bd, char* str_bootstring, int max_len)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBootDevice* _bd = (CBootDevice*) (bd->hdl);
		string str		 = _bd->getStructuredBootString ();
		::snprintf(str_bootstring,  max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getFailThroughSupported
 */
extern "C" uint16 
bd_getFailThroughSupported (DSDKBootDevice* bd)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBootDevice* _bd = (CBootDevice*) (bd->hdl);
		return _bd->getFailThroughSupported ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * release
 */
extern "C" void 
bd_release (DSDKBootDevice* bd)
{
	dsdkc_setError (0, NULL);
	CBootDevice* _bd = (CBootDevice*) (bd->hdl);
	delete _bd;
	delete bd;
}

static DSDKBootDeviceFT _bdft = 
{
	bd_getInstanceID,
	bd_getElementName,
	bd_getBootString,
	bd_getBIOSBootString,
	bd_getStructuredBootString,
	bd_getFailThroughSupported,
	bd_release
};

/*
 * Make a C based BootDevice from the corresponding C++ object.
 */
static DSDKBootDevice* 
makeDSDKBootDevice (const CBootDevice& bd)
{
	DSDKBootDevice* dsdk_bd = new DSDKBootDevice;
	if (NULL == dsdk_bd) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_bd->ft	= &_bdft;
		dsdk_bd->hdl	= new CBootDevice (bd);
		return dsdk_bd;
	}
	CATCH_SET_ERROR ();

	delete dsdk_bd;
	return NULL;

}


/*
 * getItem
 */
extern "C" DSDKBootDevice* 
bdi_getItem (DSDKBootDeviceIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBootDevice::iterator* _iter = (CBootDevice::iterator*) (di->hdl);
		if (*_iter == CBootDevice::iterator::end ()) { return NULL; }
		return makeDSDKBootDevice (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
bdi_next (DSDKBootDeviceIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBootDevice::iterator* _iter = (CBootDevice::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
bdi_isEnd (DSDKBootDeviceIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBootDevice::iterator* _iter = (CBootDevice::iterator*) (di->hdl);
		return (*_iter == CBootDevice::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
bdi_release (DSDKBootDeviceIterator* di)
{
	dsdkc_setError (0, NULL);
	CBootDevice::iterator* _iter = (CBootDevice::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKBootDeviceIteratorFT _bdift = 
{
	bdi_getItem,
	bdi_next,
	bdi_isEnd,
	bdi_release,
};


/*
 * Make a C based BootDevice iterator from the corresponding C++ object.
 */
static DSDKBootDeviceIterator* 
makeDSDKBootDeviceIterator (const CBootDevice::iterator& bdi)
{

	DSDKBootDeviceIterator* dsdk_bdi = new DSDKBootDeviceIterator;
	if (NULL == dsdk_bdi) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_bdi->ft  = &_bdift;
		dsdk_bdi->hdl = new CBootDevice::iterator (bdi);
		return dsdk_bdi;
	}
	CATCH_SET_ERROR ();

	delete dsdk_bdi;
	return NULL;
}


/*
 * enumBootDevices
 */
extern "C" DSDKBootDeviceIterator*
enumBootDevices (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBootDevice::iterator iter = CBootDevice::enumBootDevices (
													(IClient*) client, 
													(cached ? true : false));

		return makeDSDKBootDeviceIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;
}

/*
 * Gets the instance id
 */
extern "C" void 
bc_getInstanceID (DSDKBootConfig* bc, char* inst_id, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBootConfig* _bc = (CBootConfig*) (bc->hdl);
		string str		 = _bc->getInstanceID ();
		::snprintf(inst_id,  max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * Gets the element name 
 */
extern "C" void 
bc_getElementName (DSDKBootConfig* bc, char* element_name, int max_len)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBootConfig* _bc = (CBootConfig*) (bc->hdl);
		string str		 = _bc->getElementName ();
		::snprintf(element_name,  max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * Is this default boot configuration 
 */
extern "C" BOOL 
bc_isDefaultBoot (DSDKBootConfig* bc)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBootConfig* _bc = (CBootConfig*) (bc->hdl);
		return (BOOL)_bc->isDefaultBoot ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * Is this current boot configuration 
 */
extern "C" BOOL 
bc_isCurrentBoot (DSDKBootConfig* bc)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBootConfig* _bc = (CBootConfig*) (bc->hdl);
		return (BOOL)_bc->isCurrentBoot ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * Is this next boot configuration 
 */
extern "C" BOOL 
bc_isNextBoot (DSDKBootConfig* bc)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBootConfig* _bc = (CBootConfig*) (bc->hdl);
		return (BOOL)_bc->isNextBoot ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * Set this configuration as default configuration
 */
extern "C" void 
bc_setDefaultBoot (DSDKBootConfig* bc)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBootConfig* _bc = (CBootConfig*) (bc->hdl);
		_bc->setDefaultBoot ();
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * Set this configuration next boot.
 */
extern "C" void 
bc_setNextBoot (DSDKBootConfig* bc)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBootConfig* _bc = (CBootConfig*) (bc->hdl);
		_bc->setNextBoot ();
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * Gets the boot order
 */
extern "C" int
bc_getBootOrder (DSDKBootConfig* bc, DSDKBootDevice** boot_order, 
									 int max_device)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBootConfig* _bc = (CBootConfig*) (bc->hdl);
		vector <CBootDevice>	_boot_order	 = _bc->getBootOrder ();

		for (int i = 0; (i < (int)_boot_order.size () && (i < max_device)); i++)
		{
			boot_order[i] = makeDSDKBootDevice (_boot_order [i]);
		}
		return (int)_boot_order.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * Change boot order
 */
extern "C" void 
bc_changeBootOrder (DSDKBootConfig* bc, DSDKBootDevice* boot_order[], int num_device)
{
	dsdkc_setError (0, NULL);
	try
	{
		vector <CBootDevice> _boot_order;		

		for (int i = 0; i < num_device; i++)
		{
			CBootDevice* _bd = (CBootDevice*) (boot_order [i]->hdl);
			_boot_order.push_back (*_bd);
		}

		CBootConfig* _bc = (CBootConfig*) (bc->hdl);
		_bc->changeBootOrder (_boot_order);
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * add boot config
 */
extern "C" DSDKBootConfig*
bc_addBootConfig (DSDKComputerSystem* cs)
{
	dsdkc_setError (0, NULL);
	try
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		DSDKBootConfig*  _bc = new DSDKBootConfig;

		_bc->ft			= &_bcft;
		_bc->hdl		= new CBootConfig (CBootConfig::addBootConfig (*_cs));
		return _bc;
	}
	CATCH_SET_ERROR ();

	return NULL;
}

/*
 * delete this boot config
 */
extern "C" void 
bc_deleteBootConfig (DSDKBootConfig* bc)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBootConfig* _bc = (CBootConfig*) (bc->hdl);
		_bc->deleteBootConfig ();
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * release
 */
extern "C" void 
bc_release (DSDKBootConfig* bc)
{
	dsdkc_setError (0, NULL);
	CBootConfig* _bc = (CBootConfig*) (bc->hdl);
	delete _bc;
	delete bc;
}

DSDKBootConfigFT _bcft = 
{
	bc_getInstanceID,
	bc_getElementName,
	bc_isDefaultBoot,
	bc_isCurrentBoot,
	bc_isNextBoot,
	bc_setDefaultBoot,
	bc_setNextBoot,
	bc_getBootOrder,
	bc_changeBootOrder,
	bc_addBootConfig,
	bc_deleteBootConfig,
	bc_release
};

/*
 * Make a C based software from the corresponding C++ object.
 */
static DSDKBootConfig* 
makeDSDKBootConfig (const CBootConfig& bc)
{
	DSDKBootConfig* dsdk_bc = new DSDKBootConfig;
	if (NULL == dsdk_bc) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_bc->ft  = &_bcft;
		dsdk_bc->hdl = new CBootConfig (bc);
		return dsdk_bc;
	}
	CATCH_SET_ERROR ();

	delete dsdk_bc;
	return NULL;
}


/*
 * getItem
 */
extern "C" DSDKBootConfig* 
bci_getItem (DSDKBootConfigIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBootConfig::iterator* _iter = (CBootConfig::iterator*) (di->hdl);
		if (*_iter == CBootConfig::iterator::end ()) { return NULL; }
		return makeDSDKBootConfig (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
bci_next (DSDKBootConfigIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBootConfig::iterator* _iter = (CBootConfig::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
bci_isEnd (DSDKBootConfigIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBootConfig::iterator* _iter = (CBootConfig::iterator*) (di->hdl);
		return (*_iter == CBootConfig::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
bci_release (DSDKBootConfigIterator* di)
{
	dsdkc_setError (0, NULL);
	CBootConfig::iterator* _iter = (CBootConfig::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKBootConfigIteratorFT _bcift = 
{
	bci_getItem,
	bci_next,
	bci_isEnd,
	bci_release
};


/*
 * Make a C based software iterator from the corresponding C++ object.
 */
static DSDKBootConfigIterator* 
makeDSDKBootConfigIterator (const CBootConfig::iterator& bci)
{
	DSDKBootConfigIterator* dsdk_bci = new DSDKBootConfigIterator;
	if (NULL == dsdk_bci) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_bci->ft  = &_bcift;
		dsdk_bci->hdl = new CBootConfig::iterator (bci);
		return dsdk_bci;
	}
	CATCH_SET_ERROR ();

	delete dsdk_bci;
	return NULL;
}


/*
 * enumBootConfigs
 */
extern "C" DSDKBootConfigIterator*
enumBootConfigs (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBootConfig::iterator iter = CBootConfig::enumBootConfigs (
													(IClient*) client, 
													(cached ? true : false));
		return makeDSDKBootConfigIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;
}



