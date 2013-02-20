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
 * operatingsystem_c.cpp
 * C wrapper for operating system.
 */
#include <vector>
#include <string>
#include <cstring>
#include <dsdk/oal/COALObject.h>
#include <dsdkc/operatingsystem_c.h>
#include <dsdk/operatingsystem.h>
#include <dsdkc/error_c.h>

using namespace dsdk;

/*
 * getCsCreationClassName
 */
extern "C" void 
os_getCSCreationClassName (DSDKOperatingSystem* os, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COperatingSystem* _os = (COperatingSystem*) (os->hdl);
		string str = _os->getCSCreationClassName ();
		::snprintf(name,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getCSName
 */
extern "C" void 
os_getCSName (DSDKOperatingSystem* os, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COperatingSystem* _os = (COperatingSystem*) (os->hdl);
		string str = _os->getCSName ();
		::snprintf(name,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getCreationClassName
 */
extern "C" void 
os_getCreationClassName (DSDKOperatingSystem* os, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COperatingSystem* _os = (COperatingSystem*) (os->hdl);
		string str = _os->getCreationClassName ();
		::snprintf(name,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}


/*
 * getName
 */
extern "C" void 
os_getName (DSDKOperatingSystem* os, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COperatingSystem* _os = (COperatingSystem*) (os->hdl);
		string str = _os->getName ();
		::snprintf(name,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getOSType
 */
extern "C" void 
os_getOSType (DSDKOperatingSystem* os, char* type, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COperatingSystem* _os = (COperatingSystem*) (os->hdl);
		string str = _os->getOSType ();
		::snprintf(type,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getOtherTypeDescription
 */
extern "C" void 
os_getOtherTypeDescription (DSDKOperatingSystem* os, char* type, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COperatingSystem* _os = (COperatingSystem*) (os->hdl);
		string str = _os->getOtherTypeDescription ();
		::snprintf(type,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getEnabledState
 */
extern "C" uint16
os_getEnabledState (DSDKOperatingSystem* os)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COperatingSystem* _os = (COperatingSystem*) (os->hdl);
		return _os->getEnabledState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEnabledStateStr
 */
extern "C" void 
os_getEnabledStateStr (DSDKOperatingSystem* os, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COperatingSystem* _os = (COperatingSystem*) (os->hdl);
		string str = _os->getEnabledStateStr ();
		::snprintf(state,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getRequestedState
 */
extern "C" uint16
os_getRequestedState (DSDKOperatingSystem* os)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COperatingSystem* _os = (COperatingSystem*) (os->hdl);
		return _os->getRequestedState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getRequestedStateStr
 */
extern "C" void 
os_getRequestedStateStr (DSDKOperatingSystem* os, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COperatingSystem* _os = (COperatingSystem*) (os->hdl);
		string str = _os->getRequestedStateStr ();
		::snprintf(state,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getAvailableRequestedStates
 */
extern "C" int 
os_getAvailableRequestedStates (DSDKOperatingSystem* os, uint16* req_states, int max_types)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COperatingSystem* _os = (COperatingSystem*) (os->hdl);
		vector<uint16>	_req_states = _os->getAvailableRequestedStates ();
		for (size_t i = 0; (i < _req_states.size () && (i < (size_t)max_types)); i++)
		{
			req_states [i]  = _req_states [i];
		}
		return (int)_req_states.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getAvailableRequestedStatesStr 
 */
extern "C" int 
os_getAvailableRequestedStatesStr (DSDKOperatingSystem* os, char** classfication, int max_info_value, 
														int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COperatingSystem* _os		= (COperatingSystem*) (os->hdl);
		vector <string> str	= _os->getAvailableRequestedStatesStr ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_info_value)); i++)
		{
			::snprintf(classfication [i],   max_strlen, "%s", str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}


/*
 * getTransitioningToState
 */

extern "C" uint16 
os_getTransitioningToState (DSDKOperatingSystem* os)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COperatingSystem* _os = (COperatingSystem*) (os->hdl);
		return _os->getTransitioningToState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getTransitioningToStateStr
 */
extern "C" void 
os_getTransitioningToStateStr (DSDKOperatingSystem* os, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COperatingSystem* _os = (COperatingSystem*) (os->hdl);
		string str = _os->getTransitioningToStateStr ();
		::snprintf(state,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * release
 */
extern "C" void 
os_release (DSDKOperatingSystem* os)
{
	dsdkc_setError (0, NULL);
	COperatingSystem* _os = (COperatingSystem*) (os->hdl);
	delete _os;
	delete os;
}

static DSDKOperatingSystemFT _osft = 
{
	os_getCSCreationClassName,
	os_getCSName,
	os_getCreationClassName,
	os_getName,
	os_getOSType,
	os_getOtherTypeDescription,
	os_getEnabledState,
	os_getEnabledStateStr,
	os_getRequestedState,
	os_getRequestedStateStr,
	os_getAvailableRequestedStates,
	os_getAvailableRequestedStatesStr,
	os_getTransitioningToState,
	os_getTransitioningToStateStr,
	os_release,
};

/*
 * Make a C based Operating System from the corresponding C++ object.
 */
static DSDKOperatingSystem* 
makeDSDKOperatingSystem (const COperatingSystem& os)
{
	DSDKOperatingSystem* dsdk_os = new DSDKOperatingSystem;
	if (NULL == dsdk_os) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_os->ft		= &_osft;
		dsdk_os->hdl	= new COperatingSystem (os);
		return dsdk_os;
	}
	CATCH_SET_ERROR ();

	delete dsdk_os;
	return NULL;

}


/*
 * getItem
 */
extern "C" DSDKOperatingSystem* 
osi_getItem (DSDKOperatingSystemIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		COperatingSystem::iterator* _iter = (COperatingSystem::iterator*) (di->hdl);
		if (*_iter == COperatingSystem::iterator::end ()) { return NULL; }
		return makeDSDKOperatingSystem (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}

/*
 * next
 */
extern "C" void 
osi_next (DSDKOperatingSystemIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		COperatingSystem::iterator* _iter = (COperatingSystem::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}

/*
 * isEnd
 */
extern "C" BOOL 
osi_isEnd (DSDKOperatingSystemIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		COperatingSystem::iterator* _iter = (COperatingSystem::iterator*) (di->hdl);
		return (*_iter == COperatingSystem::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}

/*
 * release
 */
extern "C" void 
osi_release (DSDKOperatingSystemIterator* di)
{
	dsdkc_setError (0, NULL);
	COperatingSystem::iterator* _iter = (COperatingSystem::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKOperatingSystemIteratorFT _osift = 
{
	osi_getItem,
	osi_next,
	osi_isEnd,
	osi_release
};

/*
 * Make a C based Operating System iterator from the corresponding C++ object.
 */
static DSDKOperatingSystemIterator* 
makeDSDKOperatingSystemIterator (const COperatingSystem::iterator& osi)
{

	DSDKOperatingSystemIterator* dsdk_osi = new DSDKOperatingSystemIterator;
	if (NULL == dsdk_osi) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_osi->ft  = &_osift;
		dsdk_osi->hdl = new COperatingSystem::iterator (osi);
		return dsdk_osi;
	}
	CATCH_SET_ERROR ();

	delete dsdk_osi;
	return NULL;
}


/*
 * enumOperatingSystem
 */
extern "C" DSDKOperatingSystemIterator*
enumOperatingSystem (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		COperatingSystem::iterator iter = COperatingSystem::enumOperatingSystems (
													(IClient*) client, 
													(cached ? true : false));

		return makeDSDKOperatingSystemIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;
}
