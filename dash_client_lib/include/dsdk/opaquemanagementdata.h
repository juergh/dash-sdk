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
 * opaquemanagement.h
 * A class representing a opaque management data.
 */
#ifndef __DSDK_OPAQUEMANAGEMENT_H__
#define __DSDK_OPAQUEMANAGEMENT_H__
#include <dsdk/dsdk_api.h>
#include <dsdk/dsdktypes.h>
#include <dsdk/cimmap.h>
#include <dsdk/cim/cimdatetime.h>
#include <dsdk/computersystem.h>

namespace dsdk
{

class CIM_OpaqueManagementData;
class COpaqueManagementData;
typedef CAPIIterator<COpaqueManagementData, CIM_OpaqueManagementData> _COpaqueManagementDataIterator;

/**
 * @class COpaqueManagementData
 * @brief A class representing opaquemanagementdata
 **/

class DSDK_Export COpaqueManagementData
{
public:
	DECLARE_API_ITERATOR (COpaqueManagementData);
	typedef CIM_OpaqueManagementData CIMType;

public:
	/**
	 * Enumerates all the OMD present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the  opaque management data.
	 */
	static COpaqueManagementData::iterator enumOpaqueManagementData (IClient* client,
										 				  bool cached = true);

public:
	/**
	 * Return the underlying CIM object
	 */
	CIM_OpaqueManagementData* getCIMObject (void) const { return _omd; }


	/**
	 * Gets TransformedDataSize
	 * @return	The transformed data size
	 */
	//uint64 getTransformedDataSize (void) const;

	/**
	 * Gets MaxSize
	 * @return The max size
	 */
	uint64 getMaxSize (void) const;

	/**
	 * Gets UntransformedDataFormat
	 * @return The untransformed data format
	 */
	//string getUntransformedDataFormat (void) const;

	/**
	 * Gets an array of Transformations
	 * @ return the Transformations
	 */
	//vector<uint16> getTransformations (void)  const;

	/**
	 * Gets an array of TransformationKeyIDs
	 *@ return the array of TransformationKeyIDs
	 */
	//vector<string> getTransformationKeyIDs (void) const;

	/**
	 * Gets LastAccessed
	 * @ return LastAccessed data
	 */
	datetime getLastAccessed (void) const;

	/**
	 * Gets WriteLimited
	 * @return	true if writelimited success
	 *			false otherwise
	 */
	uint16 getWriteLimited (void) const;

	/**
	 * Gets DataOrganization
	 * @ return the dataorganization
	 */
	uint16 getDataOrganization (void) const;

	
	/**
	 * Gets Access
	 *@ return the data access
	 */
	uint16 getAccess (void) const;

	/**
	 * Gets NumberOfBlocks
	 * @return The number of blocks
	 */
	uint64 getNumberOfBlocks (void) const;

	/**
	 * Gets BlockSize
	 * @return the blocksize in bytes
	 */
	uint64 getBlockSize (void) const;

	/**
	 * Gets ConsumableBlocks
	 * @ return the cosumbaleblocks
	 */
	uint64 getConsumableBlocks (void)  const;

	
	/**
	 * Gets SystemCreationClassName
	 * @return SystemCreationClassName
	 */
	string getSystemCreationClassName (void)  const;

	/**
	 * Gets SystemName
	 * @ return the systemname
	 */
	string getSystemName (void) const;

	/**
	 * Gets CreationClassName
	 * @ return the creationclassname
	 */
	string getCreationClassName (void) const;

	/**
	 * Gets DeviceID
	 * @return The device ID
	 */
	string getDeviceID (void) const;

	/**
	 * Gets ElementName
	 * @return The ElementName
	 */
	string getElementName (void) const;

	string getOwnerName (void) const;

	/**
	 * createData
	 * @param cs		  Computer system where the opaquemanagementdata will be added.
	 * @param name		  name of the opaquemanagementdata
	 * @param size        Size of the opaquemanagementdata
	 * @param storagename storage location 
	 */

	//static uint32 createData (const CComputerSystem& cs,const string& name, uint64 size, const string& storagename = "") ;
	static uint32 createData (const CComputerSystem& cs,const string& name,uint64  size,const string& storagename = "",const string& dataformat = "");
	
	/**
	 * readData
	 * @param offset	offset to read data
	 * @param length	pointer to the length of data to read
	 * @param data		pointer to the data to read
	 */
	//uint32 readData (uint64 offset, uint64* length, vector<uint8>* data) const;
	uint32 readData (uint64 offset, uint64* length, string* readData, vector<uint8>* lock) const;

	/**
	 * exportData
	 * @param offset	offset to read data
	 * @param length	pointer to the length of data to read
	 * @param data		pointer to the data to read
	 */
	uint32 exportData (uint64 offset, uint64* length, const string ExportURI);

	/**
	 * writeData
	 * @param offset	offset to write data
	 * @param length	pointer to the length of data to write
	 * @param data		data to write
	 */
	//uint32 writeData (uint64 offset, uint64* length, const vector<uint8> data);
	uint32 writeData (uint64 offset, string data, vector<uint8>* lock);

	
	/**
	 * importData
	 * @param offset	    offset to write data
	 * @param length	    pointer to the length of data to write
	 * @param ImportURI		data to write
	 */
	uint32 importData (uint64 offset, uint64* length, const string ImportURI);

	/**
	 * lockData
	 * @param bLock	      lock the data
	 * @param lockTocken  pointer to the token
	 */
	uint32 lockData (boolean bLock, vector<uint8>* lockTocken );

	/**
	 * changeOwner
	 * @param newUser		Reassiagning new user
	 */
	uint32 changeOwner (const string newUser);

	/**
	 * assignAccess
	 * @param newUser		access premissions to user
	 * @param activities	activities to assaign
	 */
	uint32 assignAccess (const string User,const vector<uint16> activities);

	/**
	 * Delets this opaquemanagementdata
	 */
	void deleteData (void);

public:
	/**
	 * Construct this object from the corresponding CIM_OpaqueManagementData 
	 * object
	 */
	COpaqueManagementData (const CIM_OpaqueManagementData& omd); 

	/**
	 * Copy constructor
	 */
	COpaqueManagementData (const COpaqueManagementData& ba);

	/**
	 * Destructor
	 */
	~COpaqueManagementData ();

	/**
	 * Assignment operator
	 */
	const COpaqueManagementData& operator = (const COpaqueManagementData& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void);

private:
	CIM_OpaqueManagementData*	_omd;
};

};	/* namespace dsdk */

#endif /*__DSDK_OPAGUEMANAGEMENT_H__*/
