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
 * objectpath.h
 * A class representing the CIM Object Path as defined by DMTF CIM 
 * infrastructure specification. (DSP004)
 */
#ifndef __DSDK_OBJECTPATH_H__
#define __DSDK_OBJECTPATH_H__
#include <cmci/cmci.h>
#include <string>
#include <map>
#include <vector>
#include <dsdk/cim/cimerror.h>
#include <dsdk/cim/cimvalue.h>
#include <dsdk/cim/cimdata.h>
#include <dsdk/cim/cimenumeration.h>
#include <dsdk/cim/cimutils.h>

using std::vector;
using std::string;
using std::map;

namespace dsdk
{

/**
 * @class CCIMObjectPath
 * @brief A Class representing a CIM Object path. This class provides a 
 * C++ wrapper and mostly delegates the functions to the low level C 
 * API.
 */
class DSDK_Export CCIMObjectPath
{
public:
	/**
	 * Constructs a CIM Object Path refrencing a CIM element in the specified
	 * namespace.
	 * @param	ns			The namespace relative to the current namespace.
	 * @param	object_name	The name of the CIM element.
	 * @throws	ECIMError
	 */
	CCIMObjectPath (const string& ns, const string& object_name) throw (ECIMError);

	/**
	 * Constructs a CIM Object path referencing an instance of the specified
	 * CIM element as defined in the specified namespace and identified 
	 * by the given key properties and their corresponding values.
	 * @param	ns			The namespace in which the CIM element is defined.
	 * @param	object_name	The name of the CIM Element referenced.
	 * @param	keys		The keys and their corresponding values that 
	 *					    identify an instance of the CIM element.
	 * @throws	ECIMError
	 */
	CCIMObjectPath (const string& ns, const string& object_name, 
						const map<string, CCIMValue>& keys) throw (ECIMError);


	/**
	 * Constructs a CIM Object path referencing an instance of the specified
	 * CIM element as defined in the specified namespace on the specified 
	 * host and identified by the given key properties and their corresponding
	 * values.
	 * @param	ns			The namespace in which the CIM element is defined.
	 * @param	hostname	The host name or IP Address.
	 * @param	objectname	The name of the CIM Element referenced.
	 * @param	keys		The keys and their corresponding values that 
	 *					    identify an instance of the CIM element.
	 * @throws	ECIMError
	 */
	CCIMObjectPath (const string& hostname, 
					const string& ns, 
					const string& objectname,
					const map<string, CCIMValue>& keys) throw (ECIMError);


	/**
	 * Convert the low level object path to CCIMObjectPath. The low level 
	 * object path should not be released or assigned to another object after
	 * this call. We could have cloned this low level object path 
	 * but this would incur an unnecessary memory allocation since most 
	 * of the use cases will be just a straight conversion from low level 
	 * object path.
	 */
	static CCIMObjectPath toCCIMObjectPath (CMPIObjectPath* path, 
											bool _auto_release = true);

	/**
	 * Returns a null instance. This instance cannot be used for any 
	 * operations, but to act as a place holder for the creation of 
	 * upper layer objects.
	 */
	static CCIMObjectPath nullInstance (void) { return CCIMObjectPath (); }


	/**
	 * Clone this object path 
	 */
	CCIMObjectPath* clone (void) const;

public:
	/** Copy constructor */
	CCIMObjectPath (const CCIMObjectPath& op) throw (ECIMError);

	/** Assignment operator */
	const CCIMObjectPath& operator = (const CCIMObjectPath& rhs) 
														throw (ECIMError);

public:
	/** Destructor */
	~CCIMObjectPath ();

public:
	/** 
	 * Set/replace the nameSpace component.
	 * @param ns	The nameSpace string
	 * @return 		None.
	 * @throws		ECIMError
     */
	void setNameSpace (const string& ns) throw (ECIMError);

	/** 
	 * Get the nameSpace component.
	 * @return The namespace component.
	 * @throws ECIMError
     */
	string getNameSpace (void) const throw (ECIMError);

	/** 
	 * Set/replace the host name component.
	 * @param hn	The host name string
	 * @return 		None.
	 * @throws		ECIMError
     */
	void setHostName (const string& hn) throw (ECIMError);

	/** 
	 * Get the host name component.
	 * @return The host name component.
	 * @throws ECIMError
     */
	string getHostName (void) const throw (ECIMError);
	
	/** 
	 * Set/replace the class name component.
	 * @param cn	The class name string
	 * @return 		None.
	 * @throws		ECIMError.
     */
	void setClassName (const string& cn) throw (ECIMError);

	/** 
	 * Get the class name component.
	 * @return The class name component.
	 * @throws ECIMError.
     */
	string getClassName (void) const throw (ECIMError);

	/**
	 * Adds/replaces a named key property.
     * @param name	Key property name.
     * @param value Address of value structure.
	 * @throws		ECIMError.
     */
	void addKey (const string& name, const CCIMValue& value) throw (ECIMError);
	
	/**
	 * Gets a named key property value.
	 * @param name	Key property name.
	 * @return 		Entry value.
	 * @throws		ECIMError.
     */
	CCIMData getKey (const string& name) const throw (ECIMError);


	/**
	 * Gets the number of key properties contained in this object path.
	 * @return	The number of properties.
	 * @throws	ECIMError.
	 */
	unsigned int getKeyCount (void) const throw (ECIMError);

	/**
	 * Gets a key property value defined by its index.
	 * @param index	Position in the internal Data array.
	 * @param name 	Output: Returned property name (suppressed when NULL).
	 * @return 		Data value.
	 * @throws		ECIMError.
     */
	CCIMData getKeyAt (unsigned int index, string* name) 
												const throw (ECIMError);

	/**
	 * Set/replace nameSpace and classname components from @p src
	 * @param src	Source input.
	 * @throw 		ECIMError.
     */
	void setNameSpaceFromObjectPath (const CCIMObjectPath& src) 
													throw (ECIMError);

	/**
	 * Set/replace hostname, nameSpace and classname components from 
	 * @p src.
	 * @param src	Source input.
	 * @return 		None.
	 * @throws		ECIMError.
     */
	void setHostAndNameSpaceFromObjectPath (const CCIMObjectPath& src)
														throw (ECIMError);

	/**
	 * Get class qualifier value.
	 * @param qual_name	Qualifier name.
	 * @return	Qualifier value.
	 * @throws	ECIMError.
     */
	CCIMData getClassQualifier (const string& qual_name) const throw (ECIMError);

	/**
	 * Get property qualifier value.
	 * @param prop_name Property name.
	 * @param qual_name	Qualifier name.
	 * @return	Qualifier value.
	 * @throws	ECIMError.
     */
	CCIMData getPropertyQualifier (const string& prop_name,
								   const string& qual_name) const throw (ECIMError);

	/**
	 * Get method qualifier value.
	 * @param method_name	Method name.
	 * @param qual_name 	Qualifier name.
	 * @return	Qualifier value.
	 * @throws	ECIMError.
     */
	CCIMData getMethodQualifier (const string& method_name, 
								 const string& qual_name) const throw (ECIMError);

	/** 
	 * Get method parameter quailifier value.
	 * @param method_name	Method name.
	 * @param param_name 	Parameter name.
	 * @param qual_name		Qualifier name.
	 * @return Qualifier value.
	 * @throws ECIMError.
     */
	CCIMData getParameterQualifier (const string& method_name,
									const string& param_name,
									const string& qual_name) const throw (ECIMError);

	/**
	 * Generates a well formed string representation of this ObjectPath.
	 * @return	String representation.
	 */
	string toString (void) const throw (ECIMError);

	/**
	 * isNullInstance
	 */
	bool isNullInstance (void) { return _null_inst; }


public:
	/**
	 * Returns the low level object path.
	 */
	CMPIObjectPath* getLowLevelObject (void) const { return _path; }

public:
	typedef CIterator<CKeyClass<CCIMObjectPath> > iterator;

public:
	/*--------- CCIMValue Conversion adapter required functions ----------*/
	typedef CCIMObjectPath 	AdapteeType;
    static const CMPIType 	cmpi_type = CMPI_ref;

	/**
	 * Creates this object from a string. This is not supported.
	 */
    static CCIMObjectPath create (string /* val_str */) 
    { 
    	throw (EInvalidValueObject (CMPI_string));
    }

	/**
	 * Creates this object from a low level CMPIValue.
	 */
    static CCIMObjectPath create (CMPIValue* val, bool auto_release)         
    {                                                                       
        return toCCIMObjectPath (val->ref, auto_release);
    }

	/**
	 * Converts @p val to a low level CMPIValue object.
	 */
	static CMPIValue toCMPIValue (CCIMObjectPath val)									
    {                                                                       
        CMPIValue cv;                                                       
        cv.ref = val.getLowLevelObject ();                                                   
		return cv;															
    }          
	/*------------ End of CCIMConversion adapter functions ---------------*/

public:
	/* A static function to convert a low level instance to an object path */
	static CCIMObjectPath instanceToObjectPath (CMPIInstance* inst, bool auto_release = false);

private:
	/**
	 * Private default constructor
	 */
	CCIMObjectPath () : _auto_release (true), _null_inst (true) { /* Empty */ }

	/**
	 * Construct the object from the low level object.
	 */
	CCIMObjectPath (CMPIObjectPath* path) : _path (path) { /* Empty */ }

private:
	int*			_ref_count;
	CMPIObjectPath*	_path;	/**< The underlying low level object path */
	bool			_auto_release;
	bool			_null_inst;
};


/**
 * Convert a CIM value to a CCIMObjectPath. 
 * @bug This template specialization function is 
 * added to support Intel AMT DASH implementations that do 
 * not support enumerating Instance Names. Based on the CIMValue type 
 * passed to us we either create an object path from the lower level object
 * path or create it from the instance itself (we will assume all the 
 * properties in the instance are key properties).
 */
template <>
inline CCIMObjectPath
to<CCIMObjectPath> (CCIMValue& cv, bool auto_release)
{
	CMPIType   cmpi_type = cv.getLowLevelType ();
	CMPIValue* cmpi_val  = cv.getLowLevelValue ();

	if (cmpi_type == CMPI_ref)
	{
		if (auto_release) { cv.invalidate (); }
		return CCIMObjectPath::create (cmpi_val, auto_release);
	}
	else if (cmpi_type == CMPI_instance)
	{
		return CCIMObjectPath::instanceToObjectPath (cmpi_val->inst, auto_release);	
	}
	else { throw (EInvalidValueObject (cmpi_type)); }
}


};	/* namespace dsdk */

#endif	/* __DSDK_OBJECTPATH_H__ */

