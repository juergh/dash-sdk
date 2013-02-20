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
 * software_c.cpp
 * C wrapper for software.
 */
#include <vector>
#include <string>
#include <cstring>
#include <dsdk/oal/COALObject.h>
#include <dsdkc/software_c.h>
#include <dsdk/software.h>
#include <dsdkc/error_c.h>
#include <dsdk/dsdkexception.h>

using namespace dsdk;

/*
 * getManufacturer
 */
extern "C" void 
sw_getInstanceID (DSDKSoftware* sw, char* instanceid, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CSoftware* _sw	= (CSoftware*) (sw->hdl);
		string str		= _sw->getInstanceID ();
		::snprintf(instanceid,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getIsEntity
 */
extern "C" BOOL 
sw_getIsEntity(DSDKSoftware* sw)
{
	dsdkc_setError (0, NULL);
	try
	{
		CSoftware* _sw	= (CSoftware*) (sw->hdl);
		return _sw->getIsEntity ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getVersionString
 */
extern "C" void 
sw_getVersionString (DSDKSoftware* sw, char* version, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CSoftware* _sw	= (CSoftware*) (sw->hdl);
		string str		= _sw->getVersionString ();
		::snprintf(version,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getMajorVersion
 */
extern "C" uint16 
sw_getMajorVersion (DSDKSoftware* sw)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CSoftware* _sw = (CSoftware*) (sw->hdl);
		return _sw->getMajorVersion ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getMinorVersion
 */
extern "C" uint16 
sw_getMinorVersion (DSDKSoftware* sw)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CSoftware* _sw = (CSoftware*) (sw->hdl);
		return _sw->getMinorVersion ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getRevisionNumber
 */
extern "C" uint16 
sw_getRevisionNumber (DSDKSoftware* sw)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CSoftware* _sw = (CSoftware*) (sw->hdl);
		return _sw->getRevisionNumber ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 *getBuildNumber
 */
extern "C" uint16 
sw_getBuildNumber (DSDKSoftware* sw)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CSoftware* _sw = (CSoftware*) (sw->hdl);
		return _sw->getBuildNumber ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getTargetOSTypes
 */
extern "C" int 
sw_getTargetOSTypes (DSDKSoftware* sw, uint16* ostypes, int max_types)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CSoftware* _sw		= (CSoftware*) (sw->hdl);
		vector<uint16>	_os_types = _sw->getTargetOSTypes ();
		for (size_t i = 0; (i < _os_types.size () && (i < (size_t)max_types)); i++)
		{
			ostypes [i]  = _os_types [i];
		}
		return (int)_os_types.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getTargetOperatingSystems 
 */
extern "C" int 
sw_getTargetOperatingSystems (DSDKSoftware* sw, char** os, int max_os, 
														int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CSoftware* _sw		= (CSoftware*) (sw->hdl);
		vector <string> str	= _sw->getTargetOperatingSystems ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_os)); i++)
		{
			::snprintf(os [i],   max_strlen, "%s",str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}


/*
 * getIdentityInfoType 
 */
extern "C" int 
sw_getIdentityInfoType (DSDKSoftware* sw, char** identityinfotype, int max_info_type, 
														int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CSoftware* _sw		= (CSoftware*) (sw->hdl);
		vector <string> str	= _sw->getIdentityInfoType ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_info_type)); i++)
		{
			::snprintf(identityinfotype [i],   max_strlen, "%s",str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getIdentityInfoValue 
 */
extern "C" int 
sw_getIdentityInfoValue (DSDKSoftware* sw, char** identityInfoValue, int max_info_value, 
														int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CSoftware* _sw		= (CSoftware*) (sw->hdl);
		vector <string> str	= _sw->getIdentityInfoValue ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_info_value)); i++)
		{
			::snprintf(identityInfoValue [i],   max_strlen, "%s",str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getClassifications 
 */
extern "C" int 
sw_getClassifications (DSDKSoftware* sw, uint16* classification, 
										 int max_classification)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CSoftware* _sw = (CSoftware*) (sw->hdl);
		vector <uint16> classifications	= _sw->getClassifications  ();
		for (int i = 0; ((i < (int)classifications.size ()) && 
											(i < max_classification)); i++)
		{
			classification [i] = classifications [i];
		}
		return (int) classifications.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getClassificationsStr 
 */
extern "C" int 
sw_getClassificationsStr (DSDKSoftware* sw, char** classfication, int max_info_value, 
														int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CSoftware* _sw		= (CSoftware*) (sw->hdl);
		vector <string> str	= _sw->getClassificationsStr ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_info_value)); i++)
		{
			::snprintf(classfication [i],   max_strlen, "%s",str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * release
 */
extern "C" void 
sw_release (DSDKSoftware* sw)
{
	dsdkc_setError (0, NULL);
	CSoftware* _sw = (CSoftware*) (sw->hdl);
	delete _sw;
	delete sw;
}


static DSDKSoftwareFT _swft = 
{
	sw_getInstanceID,
	sw_getIsEntity,
	sw_getVersionString, 
	sw_getMajorVersion,
	sw_getMinorVersion,
	sw_getRevisionNumber, 
	sw_getBuildNumber,
	sw_getTargetOSTypes,
	sw_getTargetOperatingSystems,
	sw_getIdentityInfoType,
	sw_getIdentityInfoValue,
	sw_getClassifications,
	sw_getClassificationsStr,
	sw_release
};


/*
 * Make a C based software from the corresponding C++ object.
 */
static DSDKSoftware* 
makeDSDKSoftware (const CSoftware& sw)
{
	DSDKSoftware* dsdk_sw = new DSDKSoftware;
	if (NULL == dsdk_sw) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_sw->ft  = &_swft;
		dsdk_sw->hdl = new CSoftware (sw);
		return dsdk_sw;
	}
	CATCH_SET_ERROR ();

	delete dsdk_sw;
	return NULL;

}


/*
 * getItem
 */
extern "C" DSDKSoftware* 
swi_getItem (DSDKSoftwareIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CSoftware::iterator* _iter = (CSoftware::iterator*) (di->hdl);
		if (*_iter == CSoftware::iterator::end ()) { return NULL; }
		return makeDSDKSoftware (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
swi_next (DSDKSoftwareIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CSoftware::iterator* _iter = (CSoftware::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
swi_isEnd (DSDKSoftwareIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CSoftware::iterator* _iter = (CSoftware::iterator*) (di->hdl);
		return (*_iter == CSoftware::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
swi_release (DSDKSoftwareIterator* di)
{
	dsdkc_setError (0, NULL);
	CSoftware::iterator* _iter = (CSoftware::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKSoftwareIteratorFT _swift = 
{
	swi_getItem,
	swi_next,
	swi_isEnd,
	swi_release
};


/*
 * Make a C based software iterator from the corresponding C++ object.
 */
static DSDKSoftwareIterator* 
makeDSDKSoftwareIterator (const CSoftware::iterator& swi)
{
	DSDKSoftwareIterator* dsdk_swi = new DSDKSoftwareIterator;
	if (NULL == dsdk_swi) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_swi->ft  = &_swift;
		dsdk_swi->hdl = new CSoftware::iterator (swi);
		return dsdk_swi;
	}
	CATCH_SET_ERROR ();

	delete dsdk_swi;
	return NULL;
}


/*
 * enumSoftware
 */
extern "C" DSDKSoftwareIterator*
enumSoftware (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CSoftware::iterator iter = CSoftware::enumSoftware (
														(IClient*) client, 
														(cached ? true : false));
		return makeDSDKSoftwareIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;

}


