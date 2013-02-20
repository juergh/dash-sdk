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
 * opaquemanagementdata_c.cpp
 * C wrapper for opague management data.
 */
#include <vector>
#include <string>
#include <cstring>
#include <dsdk/oal/COALObject.h>
#include <dsdkc/opaquemanagementdata_c.h>
#include <dsdk/opaquemanagementdata.h>
#include <dsdkc/error_c.h>

using namespace dsdk;

/*
 * getTransformedDataSize
 */
extern "C" uint64 
omd_getTransformedDataSize (DSDKOpaqueManagementData* omd)
{
	/*COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
	return _omd->getTransformedDataSize ();*/
	return 0;
}


/*
 * getMaxSize
 */
extern "C" uint64 
omd_getMaxSize (DSDKOpaqueManagementData* omd)
{
	COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
	return _omd->getMaxSize ();
}


/*
 * getUntransformedDataFormat
 */
extern "C" void 
omd_getUntransformedDataFormat (DSDKOpaqueManagementData* omd, char* udf, int max_len)
{
	/*dsdkc_setError (0, NULL);
	try 
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		string str = _omd->getUntransformedDataFormat ();
		::snprintf(udf,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();*/

	return;
}

/*
 * getTransformations
 */
extern "C" int 
omd_getTransformations (DSDKOpaqueManagementData* omd, uint16* transformations, int max_transform)
{
	/*dsdkc_setError (0, NULL);
	try 
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		vector<uint16>	_transform_types = _omd->getTransformations ();
		for (size_t i = 0; (i < _transform_types.size () && (i < (size_t)max_transform)); i++)
		{
			transformations [i]  = _transform_types [i];
		}
		return (int)_transform_types.size ();
	}
	CATCH_SET_ERROR ();*/
	return 0;
}

/*
 * getTransformationKeyIDs 
 */
extern "C" int 
omd_getTransformationKeyIDs(DSDKOpaqueManagementData* omd,  char** transIDs, int max_ids, 
														int max_strlen)
{
	/*dsdkc_setError (0, NULL);
	try 
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		vector <string> str	= _omd->getTransformationKeyIDs ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_ids)); i++)
		{
			::snprintf(transIDs [i],   max_strlen, "%s",str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();*/
	return 0;
}

/*
 * getWriteLimited
 */
extern "C" uint16 
omd_getWriteLimited (DSDKOpaqueManagementData* omd)
{
	dsdkc_setError (0, NULL);
	try
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		return _omd->getWriteLimited ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 *getDataOrganization
 */
extern "C" uint16 
omd_getDataOrganization(DSDKOpaqueManagementData* omd)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		return _omd->getDataOrganization ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 *getAccess
 */
extern "C" uint16 
omd_getAccess(DSDKOpaqueManagementData* omd)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		return _omd->getAccess ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getNumberOfBlocks
 */
extern "C" uint64 
omd_getNumberOfBlocks (DSDKOpaqueManagementData* omd)
{
	COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
	return _omd->getNumberOfBlocks ();
}

/*
 * getBlockSize
 */
extern "C" uint64 
omd_getBlockSize(DSDKOpaqueManagementData* omd)
{
	COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
	return _omd->getBlockSize ();
}

/*
 * getConsumableBlocks
 */
extern "C" uint64 
omd_getConsumableBlocks(DSDKOpaqueManagementData* omd)
{
	COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
	return _omd->getConsumableBlocks ();
}

/*
 * getSystemCreationClassName
 */
extern "C" void 
omd_getSystemCreationClassName (DSDKOpaqueManagementData* omd, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		string str = _omd->getSystemCreationClassName ();
		::snprintf(name,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getSystemName
 */
extern "C" void 
omd_getSystemName (DSDKOpaqueManagementData* omd, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		string str = _omd->getSystemName ();
		::snprintf(name,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getCreationClassName
 */
extern "C" void 
omd_getCreationClassName (DSDKOpaqueManagementData* omd, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		string str = _omd->getCreationClassName ();
		
		::snprintf(name,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * getDeviceID
 */
extern "C" void 
omd_getDeviceID (DSDKOpaqueManagementData* omd, char* devid, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		string str = _omd->getDeviceID ();
		::snprintf(devid,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * Gets Element Name
 */
extern "C" void 
omd_getElementName (DSDKOpaqueManagementData* omd, char* elementname, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		string str = _omd->getElementName ();
		::snprintf(elementname,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * Gets getOwnerName
 */
extern "C" void 
omd_getOwnerName (DSDKOpaqueManagementData* omd, char* ownername, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		string str = _omd->getOwnerName ();
		::snprintf(ownername,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * createData
 */ 
extern "C" uint32 
omd_createData (const DSDKComputerSystem* cs,const char* device_id,uint64  size,const char* storagename)
{
	dsdkc_setError (0, NULL);
	uint32  status;

	try 
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);		
		status = COpaqueManagementData::createData(*_cs, string(device_id), size, string(storagename));
		return status;	
	}
	CATCH_SET_ERROR ();
	return 0;

}

/*
 * deleteData
 */
extern "C" void
omd_deleteData (DSDKOpaqueManagementData* omd)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		_omd->deleteData();
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * writeData
 */
extern "C" uint32 
omd_writeData (DSDKOpaqueManagementData* omd, uint64 offset, const char* data,uint8* lock)
{
	dsdkc_setError (0, NULL);
	try 
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		vector <uint8> locktoken;
		locktoken.push_back (*lock);
		/*vector <uint8> values;
		for (size_t i = 0; i < length; i++)
		{
			values.push_back (data [i]);
		}*/
       	return _omd->writeData (offset,string(data),&locktoken);
		
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
* importData
*/
extern "C" uint32 
omd_importData (DSDKOpaqueManagementData* omd, uint64 offset, uint64 length, const char* importURI)
{
	dsdkc_setError (0, NULL);
	uint32  status;

	try 
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		status = _omd->importData (offset, &length,string(importURI));
		return status;	
	}
	CATCH_SET_ERROR ();
	return 0;

}

/*
* readData
*/
extern "C" uint32 
omd_readData (DSDKOpaqueManagementData* omd, uint64 offset, uint64 length, const char* data,uint8* lock)
{
	dsdkc_setError (0, NULL);
	uint32  status;

	try 
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		//vector <uint8> values;
		vector <uint8> locktoken;
		//for (size_t i = 0; i < length; i++)
		//{
			locktoken.push_back (*lock);
		//}
		string values;
		status = _omd->readData (offset, &length, &values ,&locktoken);
		data = values.c_str();

		return status;	
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
* exportData
*/
extern "C" uint32 
omd_exportData (DSDKOpaqueManagementData* omd, uint64 offset, uint64 length, const char* ExportURI)
{
	dsdkc_setError (0, NULL);
	uint32  status;

	try 
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		status = _omd->exportData (offset, &length,string(ExportURI));
		return status;	
	}
	CATCH_SET_ERROR ();
	return 0;

}
/*
 * Lock
 */ 
extern "C" uint32 
omd_lockData (DSDKOpaqueManagementData* omd, BOOL bLock, uint8* token)
{
	dsdkc_setError (0, NULL);
	uint32  status;

	try 
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		vector <uint8> locktoken;
		locktoken.push_back(*token);

		status = _omd->lockData (bLock, &locktoken);
		return status;	
	}
	CATCH_SET_ERROR ();
	return 0;

}
/*
 * ReassignOwnership
 */ 
extern "C" uint32 
omd_changeOwner (DSDKOpaqueManagementData* omd, const char* newAccount)
{
	dsdkc_setError (0, NULL);
	uint32  status;

	try 
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		status = _omd->changeOwner (string(newAccount));
		return status;	
	}
	CATCH_SET_ERROR ();
	return 0;

}
/*
 * AssignAccess
 */ 
extern "C" uint32 
omd_assignAccess (DSDKOpaqueManagementData* omd, const char* account,uint16* activity ,uint64 act_len)
{
	dsdkc_setError (0, NULL);
	uint32  status;

	try 
	{
		COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
		vector<uint16> activities;		
		for (size_t i = 0; i < act_len; i++)
		{
			activities.push_back (*activity);
		}
		status = _omd->assignAccess(string(account),activities);
		return status;	
	}
	CATCH_SET_ERROR ();
	return 0;

}

/*
 * release
 */
extern "C" void 
omd_release (DSDKOpaqueManagementData* omd)
{
	dsdkc_setError (0, NULL);
	COpaqueManagementData* _omd = (COpaqueManagementData*) (omd->hdl);
	delete _omd;
	delete omd;
}

static DSDKOpaqueManagementDataFT _omdft = 
{
	omd_getTransformedDataSize,
	omd_getMaxSize,
	omd_getUntransformedDataFormat,
	omd_getTransformations,
	omd_getTransformationKeyIDs,
	omd_getWriteLimited,
	omd_getDataOrganization,
	omd_getAccess,
	omd_getNumberOfBlocks,
	omd_getBlockSize,
	omd_getConsumableBlocks,
	omd_getSystemCreationClassName,
	omd_getSystemName,
	omd_getCreationClassName,
	omd_getDeviceID,
	omd_getElementName,
	omd_getOwnerName,
	omd_readData,	
	omd_exportData,
	omd_writeData,
	omd_importData,
	omd_lockData,
	omd_changeOwner,
	omd_assignAccess,
	omd_release,
	omd_deleteData,
};

/*
 * Make a C based Opaque Management Data from the corresponding C++ object.
 */
static DSDKOpaqueManagementData* 
makeDSDKOpaqueManagementData (const COpaqueManagementData& omd)
{
	DSDKOpaqueManagementData* dsdk_omd = new DSDKOpaqueManagementData;
	if (NULL == dsdk_omd) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_omd->ft		= &_omdft;
		dsdk_omd->hdl		= new COpaqueManagementData (omd);
		return dsdk_omd;
	}
	CATCH_SET_ERROR ();

	delete dsdk_omd;
	return NULL;

}

/*
 * getItem
 */
extern "C" DSDKOpaqueManagementData* 
omdi_getItem (DSDKOpaqueManagementDataIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		COpaqueManagementData::iterator* _iter = (COpaqueManagementData::iterator*) (di->hdl);
		if (*_iter == COpaqueManagementData::iterator::end ()) { return NULL; }
		return makeDSDKOpaqueManagementData (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}

/*
 * next
 */
extern "C" void 
omdi_next (DSDKOpaqueManagementDataIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		COpaqueManagementData::iterator* _iter = (COpaqueManagementData::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}

/*
 * isEnd
 */
extern "C" BOOL 
omdi_isEnd (DSDKOpaqueManagementDataIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		COpaqueManagementData::iterator* _iter = (COpaqueManagementData::iterator*) (di->hdl);
		return (*_iter == COpaqueManagementData::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
omdi_release (DSDKOpaqueManagementDataIterator* di)
{
	dsdkc_setError (0, NULL);
	COpaqueManagementData::iterator* _iter = (COpaqueManagementData::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKOpaqueManagementDataIteratorFT _omdift = 
{
	omdi_getItem,
	omdi_next,
	omdi_isEnd,
	omdi_release
};


/*
 * Make a C based Opaque Management Data iterator from the corresponding C++ object.
 */
static DSDKOpaqueManagementDataIterator* 
makeDSDKOpaqueManagementDataIterator (const COpaqueManagementData::iterator& omdi)
{

	DSDKOpaqueManagementDataIterator* dsdk_omdi = new DSDKOpaqueManagementDataIterator;
	if (NULL == dsdk_omdi) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_omdi->ft  = &_omdift;
		dsdk_omdi->hdl = new COpaqueManagementData::iterator (omdi);
		return dsdk_omdi;
	}
	CATCH_SET_ERROR ();

	delete dsdk_omdi;
	return NULL;
}

/*
 * enumOpaqueManagementData
 */
extern "C" DSDKOpaqueManagementDataIterator*
enumOpaqueManagementData (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		COpaqueManagementData::iterator iter = COpaqueManagementData::enumOpaqueManagementData (
													(IClient*) client, 
													(cached ? true : false));

		return makeDSDKOpaqueManagementDataIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;
}
