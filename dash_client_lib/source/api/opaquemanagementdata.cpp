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
 * opaguemanagement.cpp
 * A class representing a opaque management data.
 */
#include <dsdk/oal/CIM_Account.h>
#include <dsdk/oal/CIM_AssignedIdentity.h>
#include <dsdk/oal/CIM_OpaqueManagementData.h>
#include <dsdk/oal/CIM_OpaqueManagementDataService.h>
#include <dsdk/oal/CIM_ServiceAffectsElement.h>
#include <dsdk/oal/CIM_ServiceAffectsElementWithQuota.h>
#include <dsdk/oal/CIM_HostedService.h>
#include <dsdk/oal/CIM_OpaqueManagementDataOwner.h>
#include <dsdk/opaquemanagementdata.h>
#include <dsdk/dsdkexception.h>
#include "apiimp.h"


using namespace dsdk;

static const string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

/*
 * Constructor
 */
COpaqueManagementData::COpaqueManagementData (const CIM_OpaqueManagementData& omd)
{ 
	_omd = new CIM_OpaqueManagementData (omd); 
}

/*
 * Constructor
 */
COpaqueManagementData::COpaqueManagementData (const COpaqueManagementData& omd)
{
	this->_omd = new CIM_OpaqueManagementData (*(omd._omd));
}

/*
 * Destruction 
 */
COpaqueManagementData::~COpaqueManagementData ()
{
	if (this->_omd) { delete this->_omd; }
}

/*
 * Assignment operator
 */
const COpaqueManagementData& 
COpaqueManagementData::operator = (const COpaqueManagementData& rhs)
{
	if (this->_omd) { delete this->_omd; }
	this->_omd  = new CIM_OpaqueManagementData (*rhs._omd);
	return *this;
}

/*
 * enumOpagueManagementData
 */
COpaqueManagementData::iterator 
COpaqueManagementData::enumOpaqueManagementData (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_OpaqueManagementData::iterator iter = 
		CIM_OpaqueManagementData::enumInstances (client, 0, props);

	if (cached) { return createIterator (iter, props); }
	else 		{ return createIterator (iter); }
}

//Not supported in schema v2.22
/*
 * Gets TransformedDataSize
 */
//uint64 
//COpaqueManagementData::getTransformedDataSize (void)  const
//{
//	return _omd->getTransformedDataSize ();
//}

/*
 * Gets MaxSize
 */
uint64 
COpaqueManagementData::getMaxSize (void) const
{
	return _omd->getMaxSize ();
}

//Not supported in schema v2.22
/*
 * Gets UntransformedDataFormat
 */
//string 
//COpaqueManagementData::getUntransformedDataFormat (void) const
//{
//	return _omd->getUntransformedDataFormat ();
//}

/*
 * Gets Transformations
 */
//vector<uint16> 
//COpaqueManagementData::getTransformations (void)  const
//{
//	return _omd->getTransformations ();
//}

/*
 * Gets TransformationKeyIDs
 */
//vector<string> 
//COpaqueManagementData::getTransformationKeyIDs (void) const
//{
//	return _omd->getTransformationKeyIDs ();
//}

/*
 * Gets LastAccessed
 */
datetime 
COpaqueManagementData::getLastAccessed (void) const
{
	return _omd->getLastAccessed ();
}

/*
 * getWriteLimited
 */
uint16 
COpaqueManagementData::getWriteLimited (void) const
{
	return _omd->getWriteLimited();
}

/*
 * Gets DataOrganization
 */
uint16 
COpaqueManagementData::getDataOrganization (void) const
{
	return _omd->getDataOrganization();
}

/*
 * Gets Access
 */
uint16 
COpaqueManagementData::getAccess (void) const
{
	return _omd->getAccess();
}

/*
 * Gets NumberOfBlocks
 */
uint64 
COpaqueManagementData::getNumberOfBlocks (void) const
{
	return _omd->getNumberOfBlocks();
}

/*
 * Gets BlockSize
 */
uint64 
COpaqueManagementData::getBlockSize (void) const
{
	return _omd->getBlockSize();
}

/*
 * Gets ConsumableBlocks
 */
uint64 
COpaqueManagementData::getConsumableBlocks (void)  const
{
	return _omd->getConsumableBlocks();
}

/*
 * Gets SystemCreationClassName
 */
string 
COpaqueManagementData::getSystemCreationClassName (void)  const
{
	return _omd->getSystemCreationClassName();
}

/*
 * Gets SystemName
 */
string 
COpaqueManagementData::getSystemName (void) const
{
	return _omd->getSystemName();
}

/*
 * Gets CreationClassName
 */
string 
COpaqueManagementData::getCreationClassName (void) const
{
	return _omd->getCreationClassName();
}

/*
 * Gets DeviceID
 */
string 
COpaqueManagementData::getDeviceID (void) const
{
	return _omd->getDeviceID();
}

/*
 * Gets Element Name
 */
string 
COpaqueManagementData::getElementName (void) const
{
	return _omd->getElementName();
}

/*
 * Gets getOwnerName
 */
string 
COpaqueManagementData::getOwnerName (void) const
{
	vector<string>	empty_props,props;
	props.push_back("UserID");
	/* enumerate the opaque management data service associated with this data */
	CIM_Identity::iterator iter = 
						CIM_OpaqueManagementDataOwner <CIM_Identity,
						CIM_OpaqueManagementData>::enumerateSubject(_omd->getClient(),*_omd,empty_props);

	if (iter == CIM_Identity::iterator::end ())
	{
		throw EFunctionNotSupported ("Invalid Instance");		
	}	
	
	CIM_Account::iterator acciter = 
						CIM_AssignedIdentity <CIM_Identity,
						CIM_Account>::enumerateManagedElement(_omd->getClient(),*iter,props);

	if (acciter == CIM_Account::iterator::end ())
	{
		throw EFunctionNotSupported ("Invalid Instance");		
	}	
	CIM_Account user = *acciter;
	return user.getUserID();	
}

/*
 * createData
 */ 
uint32
COpaqueManagementData::createData (const CComputerSystem& cs, 
								   const string& name,
									uint64  size,
								   const string& storagename,
								   const string& dataformat)
{
	vector<string>	empty_props;
	vector<string> ignore;	

	IClient* client = cs.getCIMObject ()->getClient ();
	string current_user = client->getUser();

	/* Create the data  */
	CIM_OpaqueManagementData	data (CCIMInstance::nullInstance ());
	CIM_StorageExtent			storage (CCIMInstance::nullInstance ());
	CIM_Account					user (CCIMInstance::nullInstance ());
	CIM_ConcreteJob				job (CCIMInstance::nullInstance ());

	/* enumerate the opaque management data service associated with this CS */
	CIM_OpaqueManagementDataService::iterator iter =
		CIM_HostedService <CIM_ComputerSystem, 
		CIM_OpaqueManagementDataService>::enumerateDependent (client,
															   *(cs.getCIMObject ()),
															   empty_props);
	
	if (iter == CIM_OpaqueManagementDataService::iterator::end ())
	{
		throw EFunctionNotSupported ("Create");
	}

	CIM_OpaqueManagementDataService omdservice = *iter;

	/* find the identity for this user */
	CIM_Account::iterator acciter = CIM_Account::enumInstances(client,0,empty_props);
	for (;acciter != CIM_Account::iterator::end (); ++acciter)
	{
		if (current_user == (*acciter).getUserID ())
		{
			user = *acciter;
			break;
		}
	}
	if (acciter == CIM_Account::iterator::end ())
	{
		throw EFunctionNotSupported ("Create");
	}

	CIM_Identity::iterator idi = 
		CIM_AssignedIdentity <CIM_Identity, CIM_Account>::enumerateIdentityInfo (client, user, empty_props);
	if (idi == CIM_Identity::iterator::end ())
	{
		throw EFunctionNotSupported ("Create");
	}
	CIM_Identity identities = *idi;

	if (!storagename.empty())
	{
		/* if storage name is specified, find and use the storage */
		CIM_StorageExtent::iterator sei = 
			CIM_StorageExtent::enumInstances (client, 0, empty_props);
		for (; sei != CIM_StorageExtent::iterator::end (); ++sei)
		{
			CIM_StorageExtent se = *sei;
			if (se.getName () == storagename)
			{
				storage = *sei;
			}
		}
		if (sei == CIM_StorageExtent::iterator::end ())
		{
			ignore.push_back ("BasedOnExtent"); /* if could not find the storage ignore it */
		}
	}
	else
		ignore.push_back ("BasedOnExtent");
	if(dataformat.empty())
	{
		ignore.push_back ("DataFormat");
	}
	/* create the OMD */
	uint32 status = omdservice.Create(size,dataformat,name,identities ,storage,&data,&job,ignore);
	/* if set attribute is success return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else
	{
		string retcodestr = omdservice.getValueStr_Create_ReturnCode(status);
		throw EFunctionReturnedWithFailure ("CIM_OpaqueManagementData::Create",
											retcodestr, status);
	}
}

/*
 * deleteData
 */
void
COpaqueManagementData::deleteData (void)
{
	_omd->getClient ()->deleteInstance (_omd->getObjectPath ());

}

/*
 * is_base64
 */
static inline bool is_base64(unsigned char c) {
  return (isalnum(c) || (c == '+') || (c == '/'));
}

/*
 * base64_encode
 */
string base64_encode(const unsigned char *toEncode, unsigned int length) {
  string ret;
  int i = 0;
  int j = 0;
  unsigned char char_array_3[3];
  unsigned char char_array_4[4];

  while (length--) {
    char_array_3[i++] = *(toEncode++);
    if (i == 3) {
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;

      for(i = 0; (i <4) ; i++)
        ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }

  if (i)
  {
    for(j = i; j < 3; j++)
      char_array_3[j] = '\0';

    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] = char_array_3[2] & 0x3f;

    for (j = 0; (j < i + 1); j++)
      ret += base64_chars[char_array_4[j]];

    while((i++ < 3))
      ret += '=';

  }

  return ret;

}

/*
 * base64_decode
 */
string base64_decode(std::string const& encoded_string) {
  int in_len = encoded_string.size();
  int i = 0;
  int j = 0;
  int in_ = 0;
  unsigned char char_array_4[4], char_array_3[3];
  string ret;

  while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
    char_array_4[i++] = encoded_string[in_]; in_++;
    if (i ==4) {
      for (i = 0; i <4; i++)
        char_array_4[i] = (unsigned char)base64_chars.find(char_array_4[i]);

      char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

      for (i = 0; (i < 3); i++)
        ret += char_array_3[i];
      i = 0;
    }
  }

  if (i) {
    for (j = i; j <4; j++)
      char_array_4[j] = 0;

    for (j = 0; j <4; j++)
      char_array_4[j] = (unsigned char)base64_chars.find(char_array_4[j]);

    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

    for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
  }

  return ret;
}

/* 
 * readData
 */ 
uint32
COpaqueManagementData::readData (uint64 offset, uint64* length, string *readData ,vector<uint8>* lock) const
{
	vector <string> empty_props;	
	vector<uint8> data;

	/* enumerate the opaque management data service associated with this data */
	CIM_OpaqueManagementDataService::iterator iter = 
						CIM_ServiceAffectsElement <CIM_OpaqueManagementData,
						CIM_OpaqueManagementDataService>::enumerateAffectingElement (_omd->getClient(),
																				*(this->getCIMObject ()),
																				empty_props);
	if (iter == CIM_OpaqueManagementDataService::iterator::end ())
	{
		throw EFunctionNotSupported ("ReadOpaqueManagementData");
	}

	/* there should be only one service assocated with the data so use the first instance */
	CIM_OpaqueManagementDataService omdatasrvice = *iter;

	/* read the data */	
	uint32 status = omdatasrvice.Read(*(this->getCIMObject()), offset, length, &data, *lock);
	string strdata(data.begin(),data.end());
	*readData = base64_decode(strdata);	
	
	/* if set attribute is success return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else
	{
		string retcodestr = omdatasrvice.getValueStr_Read_ReturnCode(status);
		throw EFunctionReturnedWithFailure ("CIM_OpaqueManagementData::readData",
											retcodestr, status);
	}	
}

/*
 * ExportToURI
 */ 
uint32
COpaqueManagementData::exportData (uint64 offset, uint64* length, const string ExportURI)
{
	vector <string> empty_props;
	vector <uint8> lock;

	/* enumerate the opaque management data service associated with this data */
	CIM_OpaqueManagementDataService::iterator Iter =
						CIM_ServiceAffectsElement <CIM_OpaqueManagementData,
						CIM_OpaqueManagementDataService>::enumerateAffectingElement (_omd->getClient(),
																				*(this->getCIMObject ()),
																				 empty_props);
	if (Iter == CIM_OpaqueManagementDataService::iterator::end ())
	{
		throw EFunctionNotSupported ("ExportToURI");
	}

	/* there should be only one service assocated with the data so use the first instance */
	CIM_OpaqueManagementDataService omdatasrvice= *Iter;

	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

	/* write the data  */
	uint32 status = omdatasrvice.ExportToURI (*(this->getCIMObject()), offset, length, ExportURI, lock, &job);
	
	/* if set attribute is success return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else
	{
		string retcodestr = omdatasrvice.getValueStr_ExportToURI_ReturnCode(status);
		throw EFunctionReturnedWithFailure ("CIM_OpaqueManagementData::ExportToURI", 
											retcodestr, status);
	}
	
}

/*
 * writeOpaqueManagementData
 */ 
uint32 COpaqueManagementData::writeData (uint64 offset, const string data ,vector<uint8>* lock)
{
	vector <string> empty_props;	
	uint64 length;

	/* enumerate the opaque management data service associated with this data */
	CIM_OpaqueManagementDataService::iterator Iter =
						CIM_ServiceAffectsElement <CIM_OpaqueManagementData,
						CIM_OpaqueManagementDataService>::enumerateAffectingElement (_omd->getClient(),
																				*(this->getCIMObject ()),
																				 empty_props);
	if (Iter == CIM_OpaqueManagementDataService::iterator::end ())
	{
		throw EFunctionNotSupported ("Write");
	}

	/* there should be only one service assocated with the data so use the first instance */
	CIM_OpaqueManagementDataService omdatasrvice= *Iter;

	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());
	length = data.length();

	string data1 = base64_encode(reinterpret_cast<const unsigned char*>(data.c_str()),data.length());
		
	char *dataconvert = new char[data1.length()+1];
	dataconvert[data1.length()]=0;
	memcpy(dataconvert,data1.c_str(),data1.length());
	const vector<uint8> encodedata(dataconvert, dataconvert + data1.length());

	/* write the data  */
	uint32 status = omdatasrvice.Write (*(this->getCIMObject()), offset, &length, true, encodedata, *lock, &job);
	
	/* if set attribute is success return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else
	{
		string retcodestr = omdatasrvice.getValueStr_Write_ReturnCode(status);
		throw EFunctionReturnedWithFailure ("CIM_OpaqueManagementData::writeData", 
											retcodestr, status);
	}	
}

/*
 * ImportFromURI
 */ 
uint32
COpaqueManagementData::importData (uint64 offset, uint64* length, const string ImportURI)
{
	vector <string> empty_props;
	vector <uint8> lock;

	/* enumerate the opaque management data service associated with this data */
	CIM_OpaqueManagementDataService::iterator Iter =
						CIM_ServiceAffectsElement <CIM_OpaqueManagementData,
						CIM_OpaqueManagementDataService>::enumerateAffectingElement (_omd->getClient(),
																				*(this->getCIMObject ()),
																				 empty_props);
	if (Iter == CIM_OpaqueManagementDataService::iterator::end ())
	{
		throw EFunctionNotSupported ("ImportFromURI");
	}

	/* there should be only one service assocated with the data so use the first instance */
	CIM_OpaqueManagementDataService omdatasrvice= *Iter;

	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

	/* write the data  */
	uint32 status = omdatasrvice.ImportFromURI (*(this->getCIMObject()), offset, length,true, ImportURI, lock, &job);
	
	/* if set attribute is success return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else
	{
		string retcodestr = omdatasrvice.getValueStr_ImportFromURI_ReturnCode(status);
		throw EFunctionReturnedWithFailure ("CIM_OpaqueManagementData::ImportFromURI", 
											retcodestr, status);
	}	
}

/*
 * Lock
 */ 
uint32
COpaqueManagementData::lockData (boolean bLock, vector<uint8>* lockTocken )
{
	vector <string> empty_props;	

	/* enumerate the opaque management data service associated with this data */
	CIM_OpaqueManagementDataService::iterator Iter =
						CIM_ServiceAffectsElement <CIM_OpaqueManagementData,
						CIM_OpaqueManagementDataService>::enumerateAffectingElement (_omd->getClient(),
																				*(this->getCIMObject ()),
																				 empty_props);
	if (Iter == CIM_OpaqueManagementDataService::iterator::end ())
	{
		throw EFunctionNotSupported ("Lock");
	}

	/* there should be only one service assocated with the data so use the first instance */
	CIM_OpaqueManagementDataService omdatasrvice= *Iter;

	/* lock the data  */
	uint32 status = omdatasrvice.Lock (*(this->getCIMObject()), bLock, lockTocken);
	
	/* if set attribute is success return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else
	{
		string retcodestr = omdatasrvice.getValueStr_Lock_ReturnCode(status);
		throw EFunctionReturnedWithFailure ("CIM_OpaqueManagementData::Lock", 
											retcodestr, status);
	}	
}

/*
 * ReassignOwnership
 */ 
uint32
COpaqueManagementData::changeOwner (const string newAccount)
{
	vector <string> empty_props;
	CIM_Account	 user (CCIMInstance::nullInstance ());

	/* enumerate the opaque management data service associated with this data */
	CIM_OpaqueManagementDataService::iterator Iter =
						CIM_ServiceAffectsElement <CIM_OpaqueManagementData,
						CIM_OpaqueManagementDataService>::enumerateAffectingElement (_omd->getClient(),
																				*(this->getCIMObject ()),
																				 empty_props);
	if (Iter == CIM_OpaqueManagementDataService::iterator::end ())
	{
		throw EFunctionNotSupported ("ReassignOwnership");
	}

	/* there should be only one service assocated with the data so use the first instance */
	CIM_OpaqueManagementDataService omdatasrvice= *Iter;	

	/* find the identity for this user */
	CIM_Account::iterator iter = CIM_Account::enumInstances(_omd->getClient(),0,empty_props);
	for (;iter != CIM_Account::iterator::end (); ++iter)
	{
		if (newAccount == (*iter).getUserID ())
		{
			user = *iter;
			break;
		}
	}
	if (iter == CIM_Account::iterator::end ())
	{
		throw EFunctionNotSupported ("Invalid User");
	}

	CIM_Identity::iterator idi = 
		CIM_AssignedIdentity <CIM_Identity, CIM_Account>::enumerateIdentityInfo (_omd->getClient(), user, empty_props);
	if (idi == CIM_Identity::iterator::end ())
	{
		throw EFunctionNotSupported ("Invalid User");
	}	
	
	CIM_Identity identities = *idi;

	/* change the user  */
	uint32 status = omdatasrvice.ReassignOwnership (identities ,*(this->getCIMObject()));
	
	/* if set attribute is success return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else
	{
		string retcodestr = omdatasrvice.getValueStr_ReassignOwnership_ReturnCode(status);
		throw EFunctionReturnedWithFailure ("CIM_OpaqueManagementData::ReassignOwnership", 
											retcodestr, status);
	}
}

/*
 * AssignAccess
 */ 
uint32
COpaqueManagementData::assignAccess (const string account,const vector<uint16> activities)
{
	vector <string> empty_props;
	CIM_Account	 user (CCIMInstance::nullInstance ());

	/* enumerate the opaque management data service associated with this data */
	CIM_OpaqueManagementDataService::iterator Iter =
						CIM_ServiceAffectsElement <CIM_OpaqueManagementData,
						CIM_OpaqueManagementDataService>::enumerateAffectingElement (_omd->getClient(),
																				*(this->getCIMObject ()),
																				 empty_props);
	if (Iter == CIM_OpaqueManagementDataService::iterator::end ())
	{
		throw EFunctionNotSupported ("AssignAccess");
	}

	/* there should be only one service assocated with the data so use the first instance */
	CIM_OpaqueManagementDataService omdatasrvice= *Iter;

	/* find the identity for this user */
	CIM_Account::iterator iter = CIM_Account::enumInstances(_omd->getClient(),0,empty_props);
	for (;iter != CIM_Account::iterator::end (); ++iter)
	{
		if (account == (*iter).getUserID ())
		{
			user = *iter;
			break;
		}
	}
	if (iter == CIM_Account::iterator::end ())
	{
		throw EFunctionNotSupported ("Invalid User");
	}

	CIM_Identity::iterator idi = 
		CIM_AssignedIdentity <CIM_Identity, CIM_Account>::enumerateIdentityInfo (_omd->getClient(), user, empty_props);
	if (idi == CIM_Identity::iterator::end ())
	{
		throw EFunctionNotSupported ("Invalid User");
	}	
	
	CIM_Identity identities = *idi;

	/* change the user  */
	uint32 status = omdatasrvice.AssignAccess (identities ,*(this->getCIMObject()),activities);
	
	/* if set attribute is success return 0, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return status;
	}
	else
	{
		string retcodestr = omdatasrvice.getValueStr_AssignAccess_ReturnCode(status);
		throw EFunctionReturnedWithFailure ("CIM_OpaqueManagementData::AssignAccess", 
											retcodestr, status);
	}

}

/*
* getCachedProps
*/
vector<string>
COpaqueManagementData::getCachedProps (void)
{
	vector<string> props;

	props.push_back ("TransformedDataSize");
	props.push_back ("MaxSize");
	props.push_back ("UntransformedDataFormat");
	props.push_back ("Transformations");
	props.push_back ("TransformationKeyIDs");
	props.push_back ("LastAccessed");
	props.push_back ("WriteLimited");
	props.push_back ("DataOrganization");
	props.push_back ("Access");
	props.push_back ("NumberOfBlocks");
	props.push_back ("BlockSize");
	props.push_back ("ConsumableBlocks");
	props.push_back ("SystemCreationClassName");
	props.push_back ("SystemName");
	props.push_back ("CreationClassName");
	props.push_back ("DeviceID");
	props.push_back("ElementName");
	return props;
}

/*
 * OpagueManagementData::Iterator
 */
DEFINE_API_ITERATOR (COpaqueManagementData);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (COpaqueManagementData, CIM_OpaqueManagementData);

