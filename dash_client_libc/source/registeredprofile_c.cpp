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
 * registeredprofile_c.cpp
 * C wrapper for registeredprofile.
 */
#include <vector>
#include <string>
#include <cstring>
#include <dsdk/oal/COALObject.h>
#include <dsdkc/registeredprofile_c.h>
#include <dsdk/registeredprofile.h>
#include <dsdkc/error_c.h>

using namespace dsdk;

/*
 * getCharacteristics
 */
extern "C" int 
rp_getAdvertiseTypes (DSDKRegisteredProfile* rp, uint16* adv_types, int max_types)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CRegisteredProfile* _rp				  = (CRegisteredProfile*) (rp->hdl);
		vector<uint16>	_adv_types = _rp->getAdvertiseTypes ();
		for (size_t i = 0; (i < _adv_types.size () && (i < (size_t)max_types)); i++)
		{
			adv_types [i]  = _adv_types [i];
		}
		return (int)_adv_types.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

extern "C" int 
rp_getValueAdvertiseTypesStr (DSDKRegisteredProfile* rp, char** type_adv, int max_types, int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CRegisteredProfile* _rp = (CRegisteredProfile*) (rp->hdl);
		vector <string> str	= _rp->getAdvertiseTypeDescriptions ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_types)); i++)
		{
			::snprintf(type_adv [i],   max_strlen, "%s",  str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;

}

/*
 * get InstanceID
 */
extern "C" void 
rp_getInstanceID (DSDKRegisteredProfile* rp, char* insid, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CRegisteredProfile* _rp = (CRegisteredProfile*) (rp->hdl);
		string str = _rp->getInstanceID ();
		::snprintf(insid,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * get RegisteredName
 */
extern "C" void 
rp_getRegisteredName (DSDKRegisteredProfile* rp, char* reg_name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CRegisteredProfile* _rp = (CRegisteredProfile*) (rp->hdl);
		string str = _rp->getRegisteredName ();
		::snprintf(reg_name,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getRegisteredOrganization
 */
extern "C" uint64 
rp_getRegisteredOrganization (DSDKRegisteredProfile* rp)
{
	dsdkc_setError (0, NULL);
	try
	{
		CRegisteredProfile* _rp = (CRegisteredProfile*) (rp->hdl);
		return _rp->getRegisteredOrganization ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getValueRegisteredOrganizationStr
 */
extern "C" void 
rp_getValueRegisteredOrganizationStr (DSDKRegisteredProfile* rp, char* regorgstr, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CRegisteredProfile* _rp = (CRegisteredProfile*) (rp->hdl);
		string str = _rp->getValueRegisteredOrganizationStr ();
		::snprintf(regorgstr,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * gets RegisteredVersion
 */
extern "C" void 
rp_getRegisteredVersion (DSDKRegisteredProfile* rp, char* reg_version, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CRegisteredProfile* _rp = (CRegisteredProfile*) (rp->hdl);
		string str = _rp->getRegisteredVersion ();
		::snprintf(reg_version,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getOtherRegisteredOrganization
 */
extern "C" void 
rp_getOtherRegisteredOrganization (DSDKRegisteredProfile* rp, char* reg_org, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CRegisteredProfile* _rp = (CRegisteredProfile*) (rp->hdl);
		string str = _rp->getOtherRegisteredOrganization ();
		::snprintf(reg_org,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getAdvertiseTypeDescriptions
 */
extern "C" int 
rp_getAdvertiseTypeDescriptions (DSDKRegisteredProfile* rp, char** type_desc, int max_value, 
														 int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CRegisteredProfile* _rp = (CRegisteredProfile*) (rp->hdl);
		vector <string> str	= _rp->getAdvertiseTypeDescriptions ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_value)); i++)
		{
			::snprintf(type_desc [i],   max_strlen, "%s",  str [i].c_str ());
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
rp_release (DSDKRegisteredProfile* rp)
{
	dsdkc_setError (0, NULL);
	CRegisteredProfile* _rp = (CRegisteredProfile*) (rp->hdl);
	delete _rp;
	delete rp;
}

static DSDKRegisteredProfileFT _rpft = 
{
	rp_getAdvertiseTypes,
	rp_getValueAdvertiseTypesStr,
	rp_getInstanceID,
	rp_getRegisteredName,
	rp_getRegisteredOrganization,
	rp_getValueRegisteredOrganizationStr,
	rp_getOtherRegisteredOrganization,
	rp_getRegisteredVersion,
	rp_getAdvertiseTypeDescriptions,
	rp_release,
};

/*
 * Make a C based RegisteredProfile from the corresponding C++ object.
 */
static DSDKRegisteredProfile* 
makeDSDKRegisteredProfile (const CRegisteredProfile& rp)
{
	DSDKRegisteredProfile* dsdk_rp = new DSDKRegisteredProfile;
	if (NULL == dsdk_rp) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_rp->ft	= &_rpft;
		dsdk_rp->hdl	= new CRegisteredProfile (rp);
		return dsdk_rp;
	}
	CATCH_SET_ERROR ();

	delete dsdk_rp;
	return NULL;

}


/*
 * getItem
 */
extern "C" DSDKRegisteredProfile* 
rpi_getItem (DSDKRegisteredProfileIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CRegisteredProfile::iterator* _iter = (CRegisteredProfile::iterator*) (di->hdl);
		if (*_iter == CRegisteredProfile::iterator::end ()) { return NULL; }
		return makeDSDKRegisteredProfile (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
rpi_next (DSDKRegisteredProfileIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CRegisteredProfile::iterator* _iter = (CRegisteredProfile::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
rpi_isEnd (DSDKRegisteredProfileIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CRegisteredProfile::iterator* _iter = (CRegisteredProfile::iterator*) (di->hdl);
		return (*_iter == CRegisteredProfile::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
rpi_release (DSDKRegisteredProfileIterator* di)
{
	dsdkc_setError (0, NULL);
	CRegisteredProfile::iterator* _iter = (CRegisteredProfile::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKRegisteredProfileIteratorFT _rpift = 
{
	rpi_getItem,
	rpi_next,
	rpi_isEnd,
	rpi_release,
};


/*
 * Make a C based RegisteredProfile iterator from the corresponding C++ object.
 */
static DSDKRegisteredProfileIterator* 
makeDSDKRegisteredProfileIterator (const CRegisteredProfile::iterator& rpi)
{

	DSDKRegisteredProfileIterator* dsdk_rpi = new DSDKRegisteredProfileIterator;
	if (NULL == dsdk_rpi) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_rpi->ft  = &_rpift;
		dsdk_rpi->hdl = new CRegisteredProfile::iterator (rpi);
		return dsdk_rpi;
	}
	CATCH_SET_ERROR ();

	delete dsdk_rpi;
	return NULL;
}


/*
 * enumRegisteredProfile
 */
extern "C" DSDKRegisteredProfileIterator*
enumRegisteredProfile (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CRegisteredProfile::iterator iter = CRegisteredProfile::enumRegisteredProfile (
													(IClient*) client, 
													(cached ? true : false));

		return makeDSDKRegisteredProfileIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;
}

/*
 * isAdvertised
 */
extern "C" BOOL
isAdvertised (DSDKClient* client, char* profilename, char* versionno)
{
	dsdkc_setError (0, NULL);
	try
	{
		return CRegisteredProfile::isAdvertised((IClient*) client, string(profilename), string(versionno));
	}
	CATCH_SET_ERROR ();
	return false;
}

