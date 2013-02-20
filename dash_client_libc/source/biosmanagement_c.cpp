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
 * biosmanagement_c.cpp
 * C wrapper for biosmanagement.
 */
#include <vector>
#include <string>
#include <cstring>
#include <dsdk/oal/COALObject.h>
#include <dsdkc/biosmanagement_c.h>
#include <dsdk/biosmanagement.h>
#include <dsdkc/error_c.h>

using namespace dsdk;

/*
 * getInstanceID
 */
extern "C" void 
ba_getInstanceID (DSDKBIOSAttribute* ba, char* instanceid, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		string str = _ba->getInstanceID ();
		::snprintf( instanceid, max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getAttributeName
 */
extern "C" void 
ba_getAttributeName (DSDKBIOSAttribute* ba, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		string str = _ba->getAttributeName ();
		::snprintf( name, max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getCurrentValue
 */
extern "C" int 
ba_getCurrentValue (DSDKBIOSAttribute* ba, char** current_values, int max_value, 
														 int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		vector <string> str	= _ba->getCurrentValue ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_value)); i++)
		{
			::snprintf( current_values [i], max_strlen, "%s",  str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}


/*
 * getDefaultValue
 */
extern "C" int 
ba_getDefaultValue (DSDKBIOSAttribute* ba, char** default_values, int max_value, 
														 int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		vector <string> str	= _ba->getDefaultValue ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_value)); i++)
		{
			::snprintf( default_values [i], max_strlen, "%s",  str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getPendingValue
 */
extern "C" int 
ba_getPendingValue (DSDKBIOSAttribute* ba, char** pending_values, int max_value, 
														 int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		vector <string> str	= _ba->getPendingValue ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_value)); i++)
		{
			::snprintf(pending_values [i],   max_strlen, "%s",  str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * isReadOnly
 */
extern "C" BOOL 
ba_isReadOnly (DSDKBIOSAttribute* ba)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		return _ba->isReadOnly ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * isOrderedList
 */
extern "C" BOOL 
ba_isOrderedList (DSDKBIOSAttribute* ba)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		return _ba->isOrderedList ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getPossibleValues
 */
extern "C" int 
ba_getPossibleValues (DSDKBIOSAttribute* ba, char** values, int max_value, 
														 int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		vector <string> str	= _ba->getPossibleValues ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_value)); i++)
		{
			::snprintf( values [i],  max_strlen, "%s", str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getPossibleValuesDescription
 */
extern "C" int 
ba_getPossibleValuesDescription (DSDKBIOSAttribute* ba, char** values, int max_value, 
														 int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		vector <string> str	= _ba->getPossibleValuesDescription ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_value)); i++)
		{
			::snprintf( values [i],  max_strlen, "%s", str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getLowerBound
 */
extern "C" uint64 
ba_getLowerBound (DSDKBIOSAttribute* ba)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		return _ba->getLowerBound ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getUpperBound
 */
extern "C" uint64 
ba_getUpperBound (DSDKBIOSAttribute* ba)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		return _ba->getUpperBound ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getProgrammaticUnit
 */
extern "C" void 
ba_getProgrammaticUnit (DSDKBIOSAttribute* ba, char* program_unit, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		string str = _ba->getProgrammaticUnit ();
		::snprintf(program_unit,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getScalarIncrement
 */
extern "C" uint32 
ba_getScalarIncrement (DSDKBIOSAttribute* ba)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		return _ba->getScalarIncrement ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getMaxLength
 */
extern "C" uint64 
ba_getMaxLength (DSDKBIOSAttribute* ba)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		return _ba->getMaxLength ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getMinLength
 */
extern "C" uint64 
ba_getMinLength (DSDKBIOSAttribute* ba)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		return _ba->getMinLength ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getStringType
 */
extern "C" uint32 
ba_getStringType (DSDKBIOSAttribute* ba)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		return _ba->getStringType ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getStringTypeStr
 */
extern "C" void 
ba_getStringTypeStr (DSDKBIOSAttribute* ba, char* type, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		string str = _ba->getStringTypeStr ();
		::snprintf(type,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}


/*
 * getValueExpression
 */
extern "C" void 
ba_getValueExpression (DSDKBIOSAttribute* ba, char* value_exp, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		string str = _ba->getValueExpression ();
		::snprintf(value_exp,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * isPasswordSet
 */
extern "C" BOOL 
ba_isPasswordSet (DSDKBIOSAttribute* ba)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		return _ba->isPasswordSet ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getPasswordEncoding
 */
extern "C" uint32 
ba_getPasswordEncoding (DSDKBIOSAttribute* ba)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		return _ba->getPasswordEncoding ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getPasswordEncodingStr
 */
extern "C" void
ba_getPasswordEncodingStr (DSDKBIOSAttribute* ba, char* pass_enc, int max_len) 
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		string str = _ba->getPasswordEncodingStr ();
		::snprintf(pass_enc,  max_len, "%s",  str.c_str ());
		
	}
	CATCH_SET_ERROR ();
	return;
}


/*
 * setAttribute
 */
extern "C" uint32 
ba_setAttribute (DSDKBIOSAttribute* ba, char** values, int num_values)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
		vector <string> _values;
		for (int i = 0; i < num_values; i++)
		{
			_values.push_back (values [i]);
		}
		return _ba->setAttribute (_values);
	}
	CATCH_SET_ERROR ();
	return (uint32)-1;
}


/*
 * release
 */
extern "C" void 
ba_release (DSDKBIOSAttribute* ba)
{
	dsdkc_setError (0, NULL);
	CBIOSAttribute* _ba = (CBIOSAttribute*) (ba->hdl);
	delete _ba;
	delete ba;
}

static DSDKBIOSAttributeFT _baft = 
{
	
	ba_getInstanceID,
	ba_getAttributeName,
	ba_getCurrentValue,
	ba_getDefaultValue,
	ba_getPendingValue,
	ba_isReadOnly,
	ba_isOrderedList,
	ba_getPossibleValues,
	ba_getPossibleValuesDescription,
	ba_getLowerBound,
	ba_getUpperBound,
	ba_getProgrammaticUnit,
	ba_getScalarIncrement,
	ba_getMaxLength,
	ba_getMinLength,
	ba_getStringType,
	ba_getStringTypeStr,
	ba_getValueExpression,
	ba_isPasswordSet,
	ba_getPasswordEncoding,
	ba_getPasswordEncodingStr,
	ba_setAttribute,
	ba_release
};


/*
 * Make a C based BIOSAttribute from the corresponding C++ object.
 */
static DSDKBIOSAttribute* 
makeDSDKBIOSAttribute (const CBIOSAttribute& ba)
{
	DSDKBIOSAttribute* dsdk_ba = new DSDKBIOSAttribute;
	if (NULL == dsdk_ba) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_ba->ft		= &_baft;
		dsdk_ba->hdl	= new CBIOSAttribute (ba);
		return dsdk_ba;
	}
	CATCH_SET_ERROR ();

	delete dsdk_ba;
	return NULL;

}


/*
 * getItem
 */
extern "C" DSDKBIOSAttribute* 
bai_getItem (DSDKBIOSAttributeIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBIOSAttribute::iterator* _iter = (CBIOSAttribute::iterator*) (di->hdl);
		if (*_iter == CBIOSAttribute::iterator::end ()) { return NULL; }
		return makeDSDKBIOSAttribute (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
bai_next (DSDKBIOSAttributeIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBIOSAttribute::iterator* _iter = (CBIOSAttribute::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
bai_isEnd (DSDKBIOSAttributeIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBIOSAttribute::iterator* _iter = (CBIOSAttribute::iterator*) (di->hdl);
		return (*_iter == CBIOSAttribute::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
bai_release (DSDKBIOSAttributeIterator* di)
{
	dsdkc_setError (0, NULL);
	CBIOSAttribute::iterator* _iter = (CBIOSAttribute::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKBIOSAttributeIteratorFT _baift = 
{
	bai_getItem,
	bai_next,
	bai_isEnd,
	bai_release
};

/*
 * Make a C based BIOS Attribute iterator from the corresponding C++ object.
 */
static DSDKBIOSAttributeIterator* 
makeDSDKBIOSAttributeIterator (const CBIOSAttribute::iterator& bai)
{

	DSDKBIOSAttributeIterator* dsdk_bai = new DSDKBIOSAttributeIterator;
	if (NULL == dsdk_bai) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_bai->ft  = &_baift;
		dsdk_bai->hdl = new CBIOSAttribute::iterator (bai);
		return dsdk_bai;
	}
	CATCH_SET_ERROR ();

	delete dsdk_bai;
	return NULL;
}

/*
 * enumBIOSAttribute
 */
extern "C" DSDKBIOSAttributeIterator*
enumBIOSAttributes (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBIOSAttribute::iterator iter = CBIOSAttribute::enumBIOSAttributes (
													(IClient*) client, 
													(cached ? true : false));

		return makeDSDKBIOSAttributeIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;
}

/*
 * getManufacturer
 */
extern "C" void 
be_getManufacturer(DSDKBIOSElement* be, char* manufacturer, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSElement* _be = (CBIOSElement*) (be->hdl);
		string str = _be->getManufacturer ();
		::snprintf(manufacturer,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getPrimaryBIOS
 */
extern "C" BOOL 
be_getPrimaryBIOS (DSDKBIOSElement* be)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBIOSElement* _be = (CBIOSElement*) (be->hdl);
		return _be->getPrimaryBIOS ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getVersion
 */
extern "C" void 
be_getVersion (DSDKBIOSElement* be, char* version, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSElement* _be = (CBIOSElement*) (be->hdl);
		string str = _be->getVersion ();
		::snprintf(version,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getName
 */
extern "C" void 
be_getName (DSDKBIOSElement* be, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSElement* _be = (CBIOSElement*) (be->hdl);
		string str = _be->getName ();
		::snprintf(name,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getSoftwareElementState
 */
extern "C" uint16 
be_getSoftwareElementState (DSDKBIOSElement* be)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSElement* _be = (CBIOSElement*) (be->hdl);
		return _be->getSoftwareElementState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getSoftwareElementStateStr
 */
extern "C" void 
be_getSoftwareElementStateStr (DSDKBIOSElement* be, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSElement* _be = (CBIOSElement*) (be->hdl);
		string str = _be->getSoftwareElementStateStr ();
		::snprintf(state,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getSoftwareElementID
 */
extern "C" void 
be_getSoftwareElementID (DSDKBIOSElement* be, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSElement* _be = (CBIOSElement*) (be->hdl);
		string str = _be->getSoftwareElementID ();
		::snprintf(name,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getTargetOperatingSystem
 */
extern "C" uint16 
be_getTargetOperatingSystem (DSDKBIOSElement* be)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSElement* _be = (CBIOSElement*) (be->hdl);
		return _be->getTargetOperatingSystem ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getTargetOperatingSystemStr
 */
extern "C" void 
be_getTargetOperatingSystemStr (DSDKBIOSElement* be, char* os, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSElement* _be = (CBIOSElement*) (be->hdl);
		string str = _be->getTargetOperatingSystemStr ();
		::snprintf(os,  max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getRegistryURIs
 */
extern "C" int 
be_getRegistryURIs (DSDKBIOSAttribute* be, char** registryuri, int max_value, 
														 int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSElement* _be = (CBIOSElement*) (be->hdl);
		vector <string> str	= _be->getRegistryURIs ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_value)); i++)
		{
			::snprintf(registryuri [i],  max_strlen, "%s", str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getAttributes
 */
extern "C" int 
be_getAttributes (DSDKBIOSElement* be, DSDKBIOSAttribute** attributes, int max_attributes)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CBIOSElement* _be = (CBIOSElement*) (be->hdl);
		vector <CBIOSAttribute> _attributes	= _be->getAttributes ();
		for (int i = 0; ((i < (int)_attributes.size ()) && 
											(i < max_attributes)); i++)
		{
			attributes [i] = makeDSDKBIOSAttribute (_attributes [i]);
		}
		return (int) _attributes.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * restoreDefaults
 */
extern "C" uint32 
be_restoreDefaults (DSDKBIOSElement* be)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBIOSElement* _be = (CBIOSElement*) (be->hdl);
		return _be->restoreDefaults ();
	}
	CATCH_SET_ERROR ();
	return (uint32)-1;
}


/*
 * release
 */
extern "C" void 
be_release (DSDKBIOSElement* be)
{
	dsdkc_setError (0, NULL);
	CBIOSElement* _be = (CBIOSElement*) (be->hdl);
	delete _be;
	delete be;
}


static DSDKBIOSElementFT _beft = 
{
	be_getManufacturer,
	be_getPrimaryBIOS,
	be_getVersion,
	be_getName,
	be_getSoftwareElementState,
	be_getSoftwareElementStateStr,
	be_getSoftwareElementID,
	be_getTargetOperatingSystem,
	be_getTargetOperatingSystemStr,
	be_getRegistryURIs,
	be_getAttributes,
	be_restoreDefaults,
	be_release,
};


/*
 * Make a C based BIOSElement from the corresponding C++ object.
 */
static DSDKBIOSElement* 
makeDSDKBIOSElement (const CBIOSElement& be)
{
	DSDKBIOSElement* dsdk_be = new DSDKBIOSElement;
	if (NULL == dsdk_be) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_be->ft		= &_beft;
		dsdk_be->hdl	= new CBIOSElement (be);
		return dsdk_be;
	}
	CATCH_SET_ERROR ();

	delete dsdk_be;
	return NULL;

}


/*
 * getItem
 */
extern "C" DSDKBIOSElement* 
bei_getItem (DSDKBIOSElementIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBIOSElement::iterator* _iter = (CBIOSElement::iterator*) (di->hdl);
		if (*_iter == CBIOSElement::iterator::end ()) { return NULL; }
		return makeDSDKBIOSElement (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
bei_next (DSDKBIOSElementIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBIOSElement::iterator* _iter = (CBIOSElement::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
bei_isEnd (DSDKBIOSElementIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBIOSElement::iterator* _iter = (CBIOSElement::iterator*) (di->hdl);
		return (*_iter == CBIOSElement::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
bei_release (DSDKBIOSElementIterator* di)
{
	dsdkc_setError (0, NULL);
	CBIOSElement::iterator* _iter = (CBIOSElement::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKBIOSElementIteratorFT _beift = 
{
	bei_getItem,
	bei_next,
	bei_isEnd,
	bei_release
};

/*
 * Make a C based Computer system iterator from the corresponding C++ object.
 */
static DSDKBIOSElementIterator* 
makeDSDKBIOSElementIterator (const CBIOSElement::iterator& bei)
{

	DSDKBIOSElementIterator* dsdk_bei = new DSDKBIOSElementIterator;
	if (NULL == dsdk_bei) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_bei->ft  = &_beift;
		dsdk_bei->hdl = new CBIOSElement::iterator (bei);
		return dsdk_bei;
	}
	CATCH_SET_ERROR ();

	delete dsdk_bei;
	return NULL;
}


/*
 * enumBIOSElement
 */
extern "C" DSDKBIOSElementIterator*
enumBIOSElements (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CBIOSElement::iterator iter = CBIOSElement::enumBIOSElements (
													(IClient*) client, 
													(cached ? true : false));

		return makeDSDKBIOSElementIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;
}


