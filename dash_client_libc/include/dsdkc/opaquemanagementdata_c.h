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
 * opaquemanagement_c.h
 * A class representing a Opaque Management Data
 */
#ifndef __CDSDK_OPAQUEMANAGEMENT_H__
#define __CDSDK_OPAQUEMANAGEMENT_H__
#include <dsdk/dsdktypes.h>
#include <dsdkc/capi.h>
#include <dsdkc/computersystem_c.h>

#ifdef __cplusplus
extern "C"
{
#endif



/**
 * OpaqueManagementData function table.
 */

struct _DSDKOpaqueManagementData;
typedef struct _DSDKOpaqueManagementData DSDKOpaqueManagementData;

/** 
 * @struct DSDKOpaqueManagementDataFT
 * @brief OpaqueManagementData function table 
 */

typedef struct _DSDKOpaqueManagementDataFT
{

	/**
	 * Gets TransformedDataSize
	 */
	uint64 (*getTransformedDataSize) (DSDKOpaqueManagementData* omd);

	/**
	 * Gets MaxSize
	 */
	uint64 (*getMaxSize) (DSDKOpaqueManagementData* omd);

	/**
	 * Gets UntransformedDataFormat
	 * @param str	Untransformed data format
	 * @param max_len	maximum buffer length
	 */
	void (*getUntransformedDataFormat) (DSDKOpaqueManagementData* omd, char* str, int max_len);

	/**
	 * Gets an array of Transformations
	 * @ return the Transformations
	 */
	int (*getTransformations) (DSDKOpaqueManagementData* omd, uint16* transformations, int max_transform);

	
	/**
	 * Gets an array of TransformationKeyIDs
	 *@ return the array of TransformationKeyIDs
	 */
	int (*getTransformationKeyIDs) (DSDKOpaqueManagementData* omd, char** transIDs, int max_ids, int max_strlen);

	/**
	 * Gets WriteLimited
	 */
	uint16 (*getWriteLimited) (DSDKOpaqueManagementData* omd);

	/**
	 * Gets DataOrganization
	 * @ return the dataorganization
	 */
	uint16 (*getDataOrganization) (DSDKOpaqueManagementData* omd);

		
	/**
	 * Gets Access
	 *@ return the data access
	 */
	uint16 (*getAccess) (DSDKOpaqueManagementData* omd);

	/**
	 * Gets NumberOfBlocks
	 */
	uint64 (*getNumberOfBlocks) (DSDKOpaqueManagementData* omd);

	
	/**
	 * Gets BlockSize
	 * @return the blocksize in bytes
	 */
	uint64 (*getBlockSize) (DSDKOpaqueManagementData* omd);

	/**
	 * Gets ConsumableBlocks
	 * @ return the cosumbaleblocks
	 */
	uint64 (*getConsumableBlocks) (DSDKOpaqueManagementData* omd);

	/**
	 * Gets SystemCreationClassName
	 * @return SystemCreationClassName
	 */
	void (*getSystemCreationClassName) (DSDKOpaqueManagementData* omd, char* str, int max_len);

	/**
	 * Gets SystemName
	 * @ return the systemname
	 */
	void (*getSystemName) (DSDKOpaqueManagementData* omd, char* str, int max_len);

	/**
	 * Gets CreationClassName
	 * @ return the creationclassname
	 */
	void (*getCreationClassName) (DSDKOpaqueManagementData* omd, char* str, int max_len);

	/**
	 * Gets DeviceID
	 * @param str	Device ID
	 * @param max_len	maximum buffer length
	 */
	void (*getDeviceID) (DSDKOpaqueManagementData* omd, char* str, int max_len);

	/**
	 * Gets ElementName
	 * @param str	Device ID
	 * @param max_len	maximum buffer length
	 */
	void (*getElementName) (DSDKOpaqueManagementData* omd, char* str, int max_len);

	/**
	 * Gets OwnerName
	 * @param str	Device ID
	 * @param max_len	maximum buffer length
	 */
	void (*getOwnerName) (DSDKOpaqueManagementData* omd, char* str, int max_len);

	/**
	 * readData
	 * @param offset	offset to readd
	 * @param length	length of the data to read
	 */
	uint32 (*readData) (DSDKOpaqueManagementData* omd, uint64 offset, uint64 length,const char* data,uint8* lock);
	
	/**
	 * exportData
	 * @param offset	offset to readd
	 * @param length	length of the data to read
	 */
	uint32 (*exportData) (DSDKOpaqueManagementData* omd, uint64 offset, uint64 length,const char* ExportURI);
	
	/**
	 * writeData
	 * @param offset	offset to write
	 * @param length	length of data to write
	 * @param data		data to write
	 */
	uint32 (*writeData) (DSDKOpaqueManagementData* omd, uint64 offset, const char* data,uint8* lock);

	/**
	 * importData
	 * @param offset	offset to readd
	 * @param length	length of the data to read
	 */
	uint32 (*importData) (DSDKOpaqueManagementData* omd, uint64 offset, uint64 length,const char* ImportURI);

	/**
	 * lockData
	 * @param bLock 	set the lock
	 * @param tocken	lock tocken
	 */
	uint32 (*lockData) (DSDKOpaqueManagementData* omd, BOOL bLock, uint8* tocken);
	
	/**
	 * changeOwner
	 * @param newAccount 	set the newAccount 
	 */
	uint32 (*changeOwner) (DSDKOpaqueManagementData* omd, const char* newAccount);

	/**
	 * assignAccess
	 * @param account 	set the activities to Account 
	 * @param activity  set read/write activities
	 * @param act_len	no of activities
	 */
	uint32 (*assignAccess) (DSDKOpaqueManagementData* omd, const char* account,uint16* activity ,uint64 act_len);
	
	/**
	 * Delets this opaquemanagementdata
	 */
	void (*deleteData) (DSDKOpaqueManagementData* omd);
	
	/**
	 * Releases this object
	 */
	void (*release) (DSDKOpaqueManagementData* omd);

} DSDKOpaqueManagementDataFT;

struct _DSDKOpaqueManagementData
{
	void*						hdl;
	DSDKOpaqueManagementDataFT*	ft;
};

/**
 * OpaqueManagementData iterator function table.
 */
struct _DSDKOpaqueManagementDataIterator;
typedef struct _DSDKOpaqueManagementDataIterator DSDKOpaqueManagementDataIterator;

typedef struct _DSDKOpaqueManagementDataIteratorFT
{
	/**
	 * Returns the OpaqueManagementData at this iterator location.
	 */
	DSDKOpaqueManagementData* (*getItem) (DSDKOpaqueManagementDataIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKOpaqueManagementDataIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKOpaqueManagementDataIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKOpaqueManagementDataIterator* di);

} DSDKOpaqueManagementDataIteratorFT;

/**
 * @struct _DSDKOpaqueManagementDataIterator 
 * @brief Iterator to iterate through the OpaqueManagementData.
 */
struct _DSDKOpaqueManagementDataIterator
{
	void*									hdl;
	DSDKOpaqueManagementDataIteratorFT*	ft;
};

/**
 * Enumerate all the OpaqueManagementData in a system.
 */
DSDKC_Export DSDKOpaqueManagementDataIterator* enumOpaqueManagementData (
											DSDKClient* client, BOOL cached);

/**
 * createData
 * @param cs		  Computer system where the opaquemanagementdata will be added.
 * @param name		  name of the opaquemanagementdata
 * @param size        Size of the opaquemanagementdata
 * @param storagename storage location 
 */

DSDKC_Export uint32 (*createData) (const DSDKComputerSystem* cs,const char * device_id, uint64 size, const char* storagename) ;




#ifdef SWIGIZE
DSDKC_Export uint64  omd_getTransformedDataSize (DSDKOpaqueManagementData* omd);
DSDKC_Export uint64  omd_getMaxSize (DSDKOpaqueManagementData* omd);
DSDKC_Export void  omd_getUntransformedDataFormat (DSDKOpaqueManagementData* omd, char* udf, int max_len);
DSDKC_Export int  omd_getTransformations (DSDKOpaqueManagementData* omd, uint16* transformations, int max_transform);
DSDKC_Export int  omd_getTransformationKeyIDs(DSDKOpaqueManagementData* omd,  char** transIDs, int max_ids, int max_strlen);
DSDKC_Export uint16 omd_getWriteLimited (DSDKOpaqueManagementData* omd);
DSDKC_Export uint16  omd_getDataOrganization(DSDKOpaqueManagementData* omd);
DSDKC_Export uint16  omd_getAccess(DSDKOpaqueManagementData* omd);
DSDKC_Export uint64  omd_getNumberOfBlocks (DSDKOpaqueManagementData* omd);
DSDKC_Export uint64  omd_getBlockSize(DSDKOpaqueManagementData* omd);
DSDKC_Export uint64  omd_getConsumableBlocks(DSDKOpaqueManagementData* omd);
DSDKC_Export void  omd_getSystemCreationClassName (DSDKOpaqueManagementData* omd, char* name, int max_len);
DSDKC_Export void  omd_getSystemName (DSDKOpaqueManagementData* omd, char* name, int max_len);
DSDKC_Export void  omd_getCreationClassName (DSDKOpaqueManagementData* omd, char* name, int max_len);
DSDKC_Export void  omd_getDeviceID (DSDKOpaqueManagementData* omd, char* devid, int max_len);
DSDKC_Export void omd_getElementName (DSDKOpaqueManagementData* omd, char* str, int max_len);
DSDKC_Export void omd_getOwnerName (DSDKOpaqueManagementData* omd, char* str, int max_len);
DSDKC_Export uint32  omd_writeData (DSDKOpaqueManagementData* omd, uint64 offset, const char* data,uint8* lock);
DSDKC_Export uint32  omd_importData (DSDKOpaqueManagementData* omd, uint64 offset, uint64 length,const char* ImportURI);
DSDKC_Export uint32  omd_readData (DSDKOpaqueManagementData* omd, uint64 offset, uint64 length,const char* data,uint8* lock);
DSDKC_Export uint32 omd_exportData (DSDKOpaqueManagementData* omd, uint64 offset, uint64 length,const char* ExportURI);
DSDKC_Export uint32 omd_lockData (DSDKOpaqueManagementData* omd, BOOL bLock, uint8* tocken);
DSDKC_Export uint32 omd_changeOwner (DSDKOpaqueManagementData* omd, const char* newAccount);
DSDKC_Export uint32 omd_assignAccess (DSDKOpaqueManagementData* omd, const char* account,uint16* activity ,uint64 act_len);
DSDKC_Export void  omd_release (DSDKOpaqueManagementData* omd);
DSDKC_Export void omd_deleteData (DSDKOpaqueManagementData* omd);
DSDKC_Export DSDKOpaqueManagementData*  omdi_getItem (DSDKOpaqueManagementDataIterator* di);
DSDKC_Export void  omdi_next (DSDKOpaqueManagementDataIterator* di);
DSDKC_Export BOOL  omdi_isEnd (DSDKOpaqueManagementDataIterator* di);
DSDKC_Export void  omdi_release (DSDKOpaqueManagementDataIterator* di);
#endif //#ifdef SWIGIZE

#ifdef __cplusplus
}
#endif

#endif /* CDSDK_OPAQUEMANAGEMENT_H_*/







	


