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
 * memory_c.cpp
 * C wrapper for memory.
 */
#include <vector>
#include <string>
#include <cstring>
#include "COALObject.h"
#include <dsdkc/memory_c.h>
#include <dsdk/memory.h>
#include <dsdkc/error_c.h>
#include <dsdk/dsdkexception.h>

using namespace dsdk;

/*
 * getSystemCreationClassName
 */
extern "C" void 
pm_getSystemCreationClassName (DSDKMemory* pm, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CMemory* _pm = (CMemory*) (pm->hdl);
		string str = _pm->getSystemCreationClassName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getSystemName
 */
extern "C" void 
pm_getSystemName (DSDKMemory* pm, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CMemory* _pm = (CMemory*) (pm->hdl);
		string str = _pm->getSystemName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getCreationClassName
 */
extern "C" void 
pm_getCreationClassName (DSDKMemory* pm, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CMemory* _pm = (CMemory*) (pm->hdl);
		string str = _pm->getCreationClassName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getDeviceID
 */
extern "C" void 
pm_getDeviceID (DSDKMemory* pm, char* dev_id, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CMemory* _pm = (CMemory*) (pm->hdl);
		string str = _pm->getDeviceID ();
		::snprintf(dev_id,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * isVolatile
 */
extern "C" BOOL 
pm_isVolatile (DSDKMemory* pm)
{
	dsdkc_setError (0, NULL);
	try
	{
		CMemory* _pm = (CMemory*) (pm->hdl);
		return _pm->isVolatile ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getAccess
 */
extern "C" uint16 
pm_getAccess (DSDKMemory* pm)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CMemory* _pm = (CMemory*) (pm->hdl);
		return _pm->getAccess ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getAccessStr
 */
extern "C" void 
pm_getAccessStr (DSDKMemory* pm, char* access, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CMemory* _pm = (CMemory*) (pm->hdl);
		string str = _pm->getAccessStr ();
		::snprintf(access,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getTotalWidth
 */
extern "C" uint64 
pm_getBlockSize (DSDKMemory* pm)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CMemory* _pm = (CMemory*) (pm->hdl);
		return _pm->getBlockSize ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getDataWidth
 */
extern "C" uint64 
pm_getNumberOfBlocks (DSDKMemory* pm)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CMemory* _pm = (CMemory*) (pm->hdl);
		return _pm->getNumberOfBlocks ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getConsumableBlocks
 */
extern "C" uint64 
pm_getConsumableBlocks (DSDKMemory* pm)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CMemory* _pm = (CMemory*) (pm->hdl);
		return _pm->getConsumableBlocks ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEnabledState
 */
extern "C" uint16
pm_getEnabledState (DSDKMemory* pm)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CMemory* _pm = (CMemory*) (pm->hdl);
		return _pm->getEnabledState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEnabledStateStr
 */
extern "C" void 
pm_getEnabledStateStr (DSDKMemory* pm, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CMemory* _pm = (CMemory*) (pm->hdl);
		string str = _pm->getEnabledStateStr ();
		::snprintf(state,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getRequestedState
 */
extern "C" uint16
pm_getRequestedState (DSDKMemory* pm)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CMemory* _pm = (CMemory*) (pm->hdl);
		return _pm->getRequestedState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getRequestedStateStr
 */
extern "C" void 
pm_getRequestedStateStr (DSDKMemory* pm, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CMemory* _pm = (CMemory*) (pm->hdl);
		string str = _pm->getRequestedStateStr ();
		::snprintf(state,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getOperationalStatus
 */
extern "C" int 
pm_getOperationalStatus (DSDKMemory* pm, uint16* op_status, int max_types)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CMemory* _pm = (CMemory*) (pm->hdl);
		vector<uint16>	_op_status = _pm->getOperationalStatus ();
		for (size_t i = 0; (i < _op_status.size () && (i < (size_t)max_types)); i++)
		{
			op_status [i]  = _op_status [i];
		}
		return (int)_op_status.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getOperationalStatusStr
 */
extern "C" int 
pm_getOperationalStatusStr (DSDKMemory* pm, char** os, int max_os, 
														int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CMemory* _pm		= (CMemory*) (pm->hdl);
		vector <string> str	= _pm->getOperationalStatusStr ();
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
 * getHealthState
 */
extern "C" uint16 
pm_getHealthState (DSDKMemory* pm)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CMemory* _pm = (CMemory*) (pm->hdl);
		return _pm->getHealthState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getHealtStateStr
 */
extern "C" void 
pm_getHealthStateStr (DSDKMemory* pm, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CMemory* _pm = (CMemory*) (pm->hdl);
		string str = _pm->getHealthStateStr ();
		::snprintf(state,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getElementName
 */
extern "C" void 
pm_getElementName (DSDKMemory* pm, char* ele_name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CMemory* _pm = (CMemory*) (pm->hdl);
		string str = _pm->getElementName ();
		::snprintf(ele_name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * release
 */
extern "C" void 
pm_release (DSDKMemory* pm)
{
	dsdkc_setError (0, NULL);
	CMemory* _pm = (CMemory*) (pm->hdl);
	delete _pm;
	delete pm;
}


static DSDKMemoryFT _pmft = 
{
	pm_getSystemCreationClassName,
	pm_getSystemName,
	pm_getCreationClassName,
	pm_getDeviceID,
	pm_isVolatile,
	pm_getAccess,
	pm_getAccessStr,
	pm_getBlockSize,
	pm_getNumberOfBlocks,
	pm_getConsumableBlocks,
	pm_getEnabledState,
	pm_getEnabledStateStr,
	pm_getRequestedState,
	pm_getRequestedStateStr,
	pm_getOperationalStatus,
	pm_getOperationalStatusStr,
	pm_getHealthState,
	pm_getHealthStateStr,
	pm_getElementName,
	pm_release
};


/*
 * Make a C based  memory from the corresponding C++ object.
 */
static DSDKMemory* 
makeDSDKMemory (const CMemory& pm)
{
	DSDKMemory* dsdk_pm = new DSDKMemory;
	if (NULL == dsdk_pm) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_pm->ft  = &_pmft;
		dsdk_pm->hdl = new CMemory (pm);
		return dsdk_pm;
	}
	CATCH_SET_ERROR ();

	delete dsdk_pm;
	return NULL;

}


/*
 * getItem
 */
extern "C" DSDKMemory* 
pmi_getItem (DSDKMemoryIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CMemory::iterator* _iter = (CMemory::iterator*) (di->hdl);
		if (*_iter == CMemory::iterator::end ()) { return NULL; }
		return makeDSDKMemory (*(*_iter));
	}
	CATCH_SET_ERROR ();

	return NULL;
}


/*
 * next
 */
extern "C" void 
pmi_next (DSDKMemoryIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CMemory::iterator* _iter = (CMemory::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
pmi_isEnd (DSDKMemoryIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CMemory::iterator* _iter = (CMemory::iterator*) (di->hdl);
		return (*_iter == CMemory::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
pmi_release (DSDKMemoryIterator* di)
{
	dsdkc_setError (0, NULL);
	CMemory::iterator* _iter = (CMemory::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKMemoryIteratorFT _pmift = 
{
	pmi_getItem,
	pmi_next,
	pmi_isEnd,
	pmi_release
};


/*
 * Make a C based  memory iterator from the corresponding C++ object.
 */
static DSDKMemoryIterator* 
makeDSDKMemoryIterator (const CMemory::iterator& pmi)
{
	DSDKMemoryIterator* dsdk_pmi = new DSDKMemoryIterator;
	if (NULL == dsdk_pmi) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_pmi->ft  = &_pmift;
		dsdk_pmi->hdl = new CMemory::iterator (pmi);
		return dsdk_pmi;
	}
	CATCH_SET_ERROR ();

	delete dsdk_pmi;
	return NULL;
}


/*
 * enumMemory
 */
extern "C" DSDKMemoryIterator*
enumMemory (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CMemory::iterator iter = CMemory::enumMemory (
														(IClient*) client, 
														(cached ? true : false));
		return makeDSDKMemoryIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;

}


