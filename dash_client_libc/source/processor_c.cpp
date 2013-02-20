
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
 * processor_c.cpp
 * C wrapper for software.
 */
#include <vector>
#include <string>
#include <cstring>
#include <dsdk/oal/COALObject.h>
#include <dsdkc/processor_c.h>
#include <dsdk/processor.h>
#include <dsdk/enumerator.h>
#include <dsdkc/error_c.h>
#include <dsdk/dsdkexception.h>

using namespace dsdk;

/*
 * getInstanceID
 */
extern "C" void 
pc_getInstanceID (DSDKProcessorCore* pc, char* instid, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessorCore* _pc = (CProcessorCore*) (pc->hdl);
		string str			= _pc->getInstanceID ();
		::snprintf(instid,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getCoreEnabledState
 */
extern "C" uint16 
pc_getCoreEnabledState (DSDKProcessorCore* pc)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessorCore* _pc = (CProcessorCore*) (pc->hdl);
		return _pc->getCoreEnabledState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEnabledState
 */
extern "C" uint16 
pc_getEnabledState (DSDKProcessorCore* pc)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessorCore* _pc = (CProcessorCore*) (pc->hdl);
		return _pc->getEnabledState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getLoadPercentage
 */
extern "C" uint16 
pc_getLoadPercentage (DSDKProcessorCore* pc)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessorCore* _pc = (CProcessorCore*) (pc->hdl);
		return _pc->getLoadPercentage ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getRequestedState
 */
extern "C" uint16 
pc_getRequestedState (DSDKProcessorCore* pc)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessorCore* _pc = (CProcessorCore*) (pc->hdl);
		return _pc->getRequestedState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getOperationalStatus
 */
extern "C" int 
pc_getOperationalStatus (DSDKProcessorCore* pc, uint16* op_status, int max_types)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessorCore* _pc = (CProcessorCore*) (pc->hdl);
		vector<uint16>	_op_status = _pc->getOperationalStatus ();
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
 * getHealthState
 */
extern "C" uint16 
pc_getHealthState (DSDKProcessorCore* pc)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessorCore* _pc = (CProcessorCore*) (pc->hdl);
		return _pc->getHealthState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getElementName
 */
extern "C" void 
pc_getElementName (DSDKProcessorCore* pc, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessorCore* _pc = (CProcessorCore*) (pc->hdl);
		string str			= _pc->getElementName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * release
 */
extern "C" void 
pc_release (DSDKProcessorCore* pc)
{
	dsdkc_setError (0, NULL);
	CProcessorCore* _pc = (CProcessorCore*) (pc->hdl);
	delete _pc;
	delete pc;
}


static DSDKProcessorCoreFT _pcft = 
{
	pc_getInstanceID,
	pc_getCoreEnabledState,
	pc_getEnabledState,
	pc_getLoadPercentage,
	pc_getRequestedState,
	pc_getOperationalStatus,
	pc_getHealthState,
	pc_getElementName,
	pc_release
};


/*
 * Make a C based processor from the corresponding C++ object.
 */
static DSDKProcessorCore* 
makeDSDKProcessorCore (const CProcessorCore& pc)
{
	DSDKProcessorCore* dsdk_pc = new DSDKProcessorCore;
	if (NULL == dsdk_pc) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_pc->ft  = &_pcft;
		dsdk_pc->hdl = new CProcessorCore (pc);
		return dsdk_pc;
	}
	CATCH_SET_ERROR ();

	delete dsdk_pc;
	return NULL;

}


/*
 * getItem
 */
extern "C" DSDKProcessorCore* 
pci_getItem (DSDKProcessorCoreIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CProcessorCore::iterator* _iter = (CProcessorCore::iterator*) (di->hdl);
		if (*_iter == CProcessorCore::iterator::end ()) { return NULL; }
		return makeDSDKProcessorCore (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
pci_next (DSDKProcessorCoreIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CProcessorCore::iterator* _iter = (CProcessorCore::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
pci_isEnd (DSDKProcessorCoreIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CProcessorCore::iterator* _iter = (CProcessorCore::iterator*) (di->hdl);
		return (*_iter == CProcessorCore::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
pci_release (DSDKProcessorCoreIterator* di)
{
	dsdkc_setError (0, NULL);
	CProcessorCore::iterator* _iter = (CProcessorCore::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKProcessorCoreIteratorFT _pcift = 
{
	pci_getItem,
	pci_next,
	pci_isEnd,
	pci_release
};


/*
 * Make a C based processor iterator from the corresponding C++ object.
 */
static DSDKProcessorCoreIterator* 
makeDSDKProcessorCoreIterator (const CProcessorCore::iterator& pci)
{
	DSDKProcessorCoreIterator* dsdk_pci = new DSDKProcessorCoreIterator;
	if (NULL == dsdk_pci) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_pci->ft  = &_pcift;
		dsdk_pci->hdl = new CProcessorCore::iterator (pci);
		return dsdk_pci;
	}
	CATCH_SET_ERROR ();

	delete dsdk_pci;
	return NULL;
}


/*
 * enumProcessorCores
 */
extern "C" DSDKProcessorCoreIterator*
enumProcessorCores (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CProcessorCore::iterator iter = CProcessorCore::enumProcessorCores (
														(IClient*) client, 
														(cached ? true : false));
		return makeDSDKProcessorCoreIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;

}

/*
 * getSystemCreationClassName
 */
extern "C" void 
proc_getSystemCreationClassName (DSDKProcessor* proc, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		string str = _proc->getSystemCreationClassName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getSystemName
 */
extern "C" void 
proc_getSystemName (DSDKProcessor* proc, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		string str = _proc->getSystemName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getCreationClassName
 */
extern "C" void 
proc_getCreationClassName (DSDKProcessor* proc, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		string str = _proc->getCreationClassName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getDeviceID
 */
extern "C" void 
proc_getDeviceID (DSDKProcessor* proc, char* dev_id, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		string str = _proc->getDeviceID ();
		::snprintf(dev_id,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getFamily
 */
extern "C" void 
proc_getFamily (DSDKProcessor* proc, char* fmaily, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		string str = _proc->getFamily ();
		::snprintf(fmaily,   max_len,str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getCurrentClockSpeed
 */
extern "C" uint32 
proc_getCurrentClockSpeed (DSDKProcessor* proc)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		return _proc->getCurrentClockSpeed ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getMaxClockSpeed
 */
extern "C" uint32 
proc_getMaxClockSpeed (DSDKProcessor* proc)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		return _proc->getMaxClockSpeed ();
	}
	CATCH_SET_ERROR ();
	return 0;
}
 	
/*
 * getExternalBusClockSpeed
 */
extern "C" uint32 
proc_getExternalBusClockSpeed (DSDKProcessor* proc)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		return _proc->getExternalBusClockSpeed ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getCPUStatus
 */
extern "C" uint16 
proc_getCPUStatus (DSDKProcessor* proc)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		return _proc->getCPUStatus ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getCPUStatusStr
 */
extern "C" void 
proc_getCPUStatusStr (DSDKProcessor* proc, char* status, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		string str = _proc->getCPUStatusStr ();
		::snprintf(status,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getLoadPercentage
 */
extern "C" uint32 
proc_getLoadPercentage (DSDKProcessor* proc)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		return _proc->getLoadPercentage ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEnabledState
 */
extern "C" uint16 
proc_getEnabledState (DSDKProcessor* proc)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		return _proc->getEnabledState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEnabledStateStr
 */
extern "C" void 
proc_getEnabledStateStr (DSDKProcessor* proc, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		string str = _proc->getEnabledStateStr ();
		::snprintf(state,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getRequestedState
 */
extern "C" uint16 
proc_getRequestedState (DSDKProcessor* proc)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		return _proc->getRequestedState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getRequestedStateStr
 */
extern "C" void 
proc_getRequestedStateStr (DSDKProcessor* proc, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		string str = _proc->getRequestedStateStr ();
		::snprintf(state,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getOperationalStatus
 */
extern "C" int 
proc_getOperationalStatus (DSDKProcessor* proc, uint16* op_status, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		vector<uint16>	_op_status = _proc->getOperationalStatus ();
		for (size_t i = 0; (i < _op_status.size () && (i < (size_t)max_len)); i++)
		{
			op_status [i]  = _op_status [i];
		}
		return (int)_op_status.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getOperationalStatuss 
 */
extern "C" int 
proc_getOperationalStatusStr (DSDKProcessor* proc, char** os, int max_os, 
														int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc		= (CProcessor*) (proc->hdl);
		vector <string> str	= _proc->getOperationalStatusStr ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_os)); i++)
		{
			::snprintf(os [i],   max_strlen, "%s", str [i].c_str ());
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
proc_getHealthState (DSDKProcessor* proc)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		return _proc->getHealthState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getHealtStateStr
 */
extern "C" void 
proc_getHealthStateStr (DSDKProcessor* proc, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		string str = _proc->getHealthStateStr ();
		::snprintf(state,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getElementName
 */
extern "C" void 
proc_getElementName (DSDKProcessor* proc, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		string str = _proc->getElementName ();
		::snprintf(name,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getOtherFamilyDescription
 */
extern "C" void 
proc_getOtherFamilyDescription (DSDKProcessor* proc, char* desc, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CProcessor* _proc = (CProcessor*) (proc->hdl);
		string str = _proc->getOtherFamilyDescription ();
		::snprintf(desc,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * release
 */
extern "C" void 
proc_release (DSDKProcessor* proc)
{
	dsdkc_setError (0, NULL);
	CProcessor* _proc = (CProcessor*) (proc->hdl);
	delete _proc;
	delete proc;
}


static DSDKProcessorFT _csft = 
{
	proc_getSystemCreationClassName,
	proc_getSystemName,
	proc_getCreationClassName,
	proc_getDeviceID,
	proc_getFamily,
	proc_getCurrentClockSpeed,
	proc_getMaxClockSpeed,	
	proc_getExternalBusClockSpeed,
	proc_getCPUStatus,
	proc_getCPUStatusStr,
	proc_getLoadPercentage,
	proc_getEnabledState,
	proc_getEnabledStateStr,
	proc_getRequestedState,
	proc_getRequestedStateStr,
	proc_getOperationalStatus,
	proc_getOperationalStatusStr,
	proc_getHealthState,
	proc_getHealthStateStr,
	proc_getElementName,
	proc_getOtherFamilyDescription,
	proc_release,
};


/*
 * Make a C based Processor from the corresponding C++ object.
 */
static DSDKProcessor* 
makeDSDKProcessor (const CProcessor& proc)
{
	DSDKProcessor* dsdk_proc = new DSDKProcessor;
	if (NULL == dsdk_proc) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_proc->ft  = &_csft;
		dsdk_proc->hdl = new CProcessor (proc);
		return dsdk_proc;
	}
	CATCH_SET_ERROR ();

	delete dsdk_proc;
	return NULL;

}


/*
 * getItem
 */
extern "C" DSDKProcessor* 
proci_getItem (DSDKProcessorIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CProcessor::iterator* _iter = (CProcessor::iterator*) (di->hdl);
		if (*_iter == CProcessor::iterator::end ()) { return NULL; }
		return makeDSDKProcessor (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
proci_next (DSDKProcessorIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CProcessor::iterator* _iter = (CProcessor::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
proci_isEnd (DSDKProcessorIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CProcessor::iterator* _iter = (CProcessor::iterator*) (di->hdl);
		return (*_iter == CProcessor::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
proci_release (DSDKProcessorIterator* di)
{
	dsdkc_setError (0, NULL);
	CProcessor::iterator* _iter = (CProcessor::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKProcessorIteratorFT _procift = 
{
	proci_getItem,
	proci_next,
	proci_isEnd,
	proci_release
};


/*
 * Make a C based Processor iterator from the corresponding C++ object.
 */
static DSDKProcessorIterator* 
makeDSDKProcessorIterator (const CProcessor::iterator& proci)
{
	DSDKProcessorIterator* dsdk_proci = new DSDKProcessorIterator;
	if (NULL == dsdk_proci) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_proci->ft  = &_procift;
		dsdk_proci->hdl = new CProcessor::iterator (proci);
		return dsdk_proci;
	}
	CATCH_SET_ERROR ();

	delete dsdk_proci;
	return NULL;
}


/*
 * enumProcessors
 */
extern "C" DSDKProcessorIterator*
enumProcessors (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CProcessor::iterator iter = CProcessor::enumProcessors (
														(IClient*) client, 
														(cached ? true : false));
		return makeDSDKProcessorIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;

}

/**
 * Enumerate all the processors in a given ComputerSystem.
 */
DSDKC_Export DSDKProcessorIterator*
enumComputerSystemProcessors (DSDKClient* client, DSDKComputerSystem* cs)
{
	dsdkc_setError (0, NULL);
	try
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		CProcessor::iterator iter = enumProcessors ((IClient*) client, *_cs);
		return makeDSDKProcessorIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;
}
