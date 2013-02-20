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
 * physicalasset_c.cpp
 * C wrapper for physical asset.
 */
#include <vector>
#include <string>
#include <cstring>
#include <dsdk/oal/COALObject.h>
#include <dsdkc/physicalasset_c.h>
#include <dsdk/physicalasset.h>
#include <dsdkc/error_c.h>
#include <dsdk/dsdkexception.h>

using namespace dsdk;

/*
 * getTag
 */
extern "C" void 
pa_getTag (DSDKPhysicalAsset* pa, char* tag, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		string str = _pa->getTag ();
		::snprintf(tag,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getCreationClassName
 */
extern "C" void 
pa_getCreationClassName (DSDKPhysicalAsset* pa, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		string str = _pa->getCreationClassName ();
		::snprintf(name,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getManufacturer
 */
extern "C" void 
pa_getManufacturer (DSDKPhysicalAsset* pa, char* manufacturer, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		string str = _pa->getManufacturer ();
		::snprintf(manufacturer,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getModel
 */
extern "C" void 
pa_getModel (DSDKPhysicalAsset* pa, char* model, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		string str = _pa->getModel ();
		::snprintf(model,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getSerialNumber
 */
extern "C" void 
pa_getSerialNumber (DSDKPhysicalAsset* pa, char* serial_number, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		string str = _pa->getSerialNumber ();
		::snprintf(serial_number,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getPartNumber
 */
extern "C" void 
pa_getPartNumber (DSDKPhysicalAsset* pa, char* part_number, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		string str = _pa->getPartNumber ();
		::snprintf(part_number,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/* 
 * getSKU
 */
extern "C" void 
pa_getSKU (DSDKPhysicalAsset* pa, char* sku, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		string str = _pa->getSKU ();
		::snprintf(sku,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/* 
 * getElementName
 */
extern "C" void 
pa_getElementName (DSDKPhysicalAsset* pa, char* ele_name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		string str = _pa->getElementName ();
		::snprintf(ele_name,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * canBeFRUed
 */
extern "C" BOOL 
pa_canBeFRUed (DSDKPhysicalAsset* pa)
{
	dsdkc_setError (0, NULL);
	try
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		return _pa->canBeFRUed ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getPackageType
 */
extern "C" uint16 
pa_getPackageType (DSDKPhysicalAsset* pa)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		return _pa->getPackageType ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/* 
 * getPackageTypeStr
 */
extern "C" void 
pa_getPackageTypeStr (DSDKPhysicalAsset* pa, char* type, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		string str = _pa->getPackageTypeStr ();
		::snprintf(type,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getVendorCompatibilityStrings
 */
extern "C" int 
pa_getVendorCompatibilityStrings (DSDKPhysicalAsset* pa, char** vendor_comp, int max_value, 
														 int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		vector <string> str	= _pa->getVendorCompatibilityStrings ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_value)); i++)
		{
			::snprintf(vendor_comp [i],   max_strlen, "%s",str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/* 
 * getVersion
 */
extern "C" void 
pa_getVersion (DSDKPhysicalAsset* pa, char* version, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		string str = _pa->getVersion ();
		::snprintf(version,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getName
 */
extern "C" void 
pa_getName (DSDKPhysicalAsset* pa, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		string str = _pa->getName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * isHostingBoard
 */
extern "C" BOOL 
pa_isHostingBoard (DSDKPhysicalAsset* pa)
{
	dsdkc_setError (0, NULL);
	try
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		return _pa->isHostingBoard ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getTypeOfRack
 */
extern "C" uint16 
pa_getTypeOfRack (DSDKPhysicalAsset* pa)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		return _pa->getTypeOfRack ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/* 
 * getTypeOfRackStr
 */
extern "C" void 
pa_getTypeOfRackStr (DSDKPhysicalAsset* pa, char* type, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		string str = _pa->getTypeOfRackStr ();
		::snprintf(type,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getChassisPackageType
 */
extern "C" uint16 
pa_getChassisPackageType (DSDKPhysicalAsset* pa)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		return _pa->getChassisPackageType ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/* 
 * getChassisPackageTypeStr
 */
extern "C" void 
pa_getChassisPackageTypeStr (DSDKPhysicalAsset* pa, char* type, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		string str = _pa->getChassisPackageTypeStr ();
		::snprintf(type,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getConnectorLayout
 */
extern "C" uint16 
pa_getConnectorLayout (DSDKPhysicalAsset* pa)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		return _pa->getConnectorLayout ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/* 
 * getConnectorLayoutStr
 */
extern "C" void 
pa_getConnectorLayoutStr (DSDKPhysicalAsset* pa, char* layout, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		string str = _pa->getConnectorLayoutStr ();
		::snprintf(layout,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getSlotNumber
 */
extern "C" uint16 
pa_getSlotNumber (DSDKPhysicalAsset* pa)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		return _pa->getSlotNumber ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getFormFactor
 */
extern "C" uint16 
pa_getFormFactor (DSDKPhysicalAsset* pa)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		return _pa->getFormFactor ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getMemoryType
 */
extern "C" uint16 
pa_getMemoryType (DSDKPhysicalAsset* pa)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		return _pa->getMemoryType ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/* 
 * getMemoryTypeStr
 */
extern "C" void 
pa_getMemoryTypeStr (DSDKPhysicalAsset* pa, char* type, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		string str = _pa->getMemoryTypeStr ();
		::snprintf(type,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getMemorySpeed
 */
extern "C" uint32 
pa_getMemorySpeed (DSDKPhysicalAsset* pa)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		return _pa->getMemorySpeed ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getMemoryCapacity
 */
extern "C" uint64 
pa_getMemoryCapacity (DSDKPhysicalAsset* pa)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		return _pa->getMemoryCapacity ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getMemoryBankLabel
 */
extern "C" void 
pa_getMemoryBankLabel (DSDKPhysicalAsset* pa, char* bank_label, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
		string str = _pa->getMemoryBankLabel ();
		::snprintf(bank_label,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * release
 */
extern "C" void 
pa_release (DSDKPhysicalAsset* pa)
{
	dsdkc_setError (0, NULL);
	CPhysicalAsset* _pa = (CPhysicalAsset*) (pa->hdl);
	delete _pa;
	delete pa;
}


static DSDKPhysicalAssetFT _paft = 
{
	pa_getTag,
	pa_getCreationClassName,
	pa_getManufacturer,
	pa_getModel,
	pa_getSerialNumber,
	pa_getPartNumber,
	pa_getSKU,
	pa_getElementName,
	pa_canBeFRUed,
	pa_getPackageType,
	pa_getPackageTypeStr,
	pa_getVendorCompatibilityStrings,
	pa_getVersion,
	pa_getName,
	pa_isHostingBoard,
	pa_getTypeOfRack,
	pa_getTypeOfRackStr,
	pa_getChassisPackageType,
	pa_getChassisPackageTypeStr,
	pa_getConnectorLayout,
	pa_getConnectorLayoutStr,
	pa_getSlotNumber,
	pa_getFormFactor,
	pa_getMemoryType,
	pa_getMemoryTypeStr,
	pa_getMemorySpeed,
	pa_getMemoryCapacity,
	pa_getMemoryBankLabel,
	pa_release
};


/*
 * Make a C based physical asset from the corresponding C++ object.
 */
static DSDKPhysicalAsset* 
makeDSDKPhysicalAsset (const CPhysicalAsset& pa)
{
	DSDKPhysicalAsset* dsdk_pa = new DSDKPhysicalAsset;
	if (NULL == dsdk_pa) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_pa->ft  = &_paft;
		dsdk_pa->hdl = new CPhysicalAsset (pa);
		return dsdk_pa;
	}
	CATCH_SET_ERROR ();

	delete dsdk_pa;
	return NULL;
}


/*
 * getItem
 */
extern "C" DSDKPhysicalAsset* 
pai_getItem (DSDKPhysicalAssetIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CPhysicalAsset::iterator* _iter = (CPhysicalAsset::iterator*) (di->hdl);
		if (*_iter == CPhysicalAsset::iterator::end ()) { return NULL; }
		return makeDSDKPhysicalAsset (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
pai_next (DSDKPhysicalAssetIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CPhysicalAsset::iterator* _iter = (CPhysicalAsset::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
pai_isEnd (DSDKPhysicalAssetIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CPhysicalAsset::iterator* _iter = (CPhysicalAsset::iterator*) (di->hdl);
		return (*_iter == CPhysicalAsset::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
pai_release (DSDKPhysicalAssetIterator* di)
{
	dsdkc_setError (0, NULL);
	CPhysicalAsset::iterator* _iter = (CPhysicalAsset::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKPhysicalAssetIteratorFT _paift = 
{
	pai_getItem,
	pai_next,
	pai_isEnd,
	pai_release
};


/*
 * Make a C based physical asset iterator from the corresponding C++ object.
 */
static DSDKPhysicalAssetIterator* 
makeDSDKPhysicalAssetIterator (const CPhysicalAsset::iterator& pai)
{
	DSDKPhysicalAssetIterator* dsdk_pai = new DSDKPhysicalAssetIterator;
	if (NULL == dsdk_pai) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_pai->ft  = &_paift;
		dsdk_pai->hdl = new CPhysicalAsset::iterator (pai);
		return dsdk_pai;
	}
	CATCH_SET_ERROR ();

	delete dsdk_pai;
	return NULL;
}


/*
 * enumPhysicalAssets
 */
extern "C" DSDKPhysicalAssetIterator*
enumPhysicalAssets (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CPhysicalAsset::iterator iter = CPhysicalAsset::enumPhysicalAssets (
														(IClient*) client, 
														(cached ? true : false));
		return makeDSDKPhysicalAssetIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;

}


