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
 * cimenumeration.h
 * A class representing CIM enumeration.
 */
#ifndef __DSDK_CIMENUMERATION_H__
#define __DSDK_CIMENUMERATION_H__
#include <cmci/cmci.h>
#include <dsdk/cim/cimerror.h>
#include <dsdk/cim/cimdata.h>
#include <dsdk/cim/cimconversion.h>
#include <dsdk/dsdkiterator.h>
#ifdef _WIN32
#pragma warning (push)
#pragma warning (disable:4127)
#endif

namespace dsdk 
{

class CCIMInstance;
extern void DSDK_Export makeInstanceObjectPath (CCIMInstance* inst, const string& classname);

/**
 * @class CCIMEnumeration
 * @brief A class representing CIM Enumeration.
 */
class DSDK_Export CCIMEnumeration 
{
public:
	/**
	 * Convert the low level Enumeration to CCIMEnumeration. The low level 
	 * enumeration should not be released or assigned to another object 
	 * after this call. We could have cloned this low level argument
	 * but this would incur an unneccessary memory allocation since 
	 * most of the use cases will be just a straight conversion from 
	 * low level argument.
	 */
	static CCIMEnumeration toCCIMEnumeration (CMPIEnumeration* en,
											  bool auto_release = true);

public:
	/**
	 * Copy constructor.
	 */
	CCIMEnumeration (const CCIMEnumeration& en);

	/**
	 * Assignment operator
	 */
	const CCIMEnumeration& operator = (const CCIMEnumeration& rhs);

public:
	/*
	 * The object path of the low level function does not contain the 
	 * namespace component, due to some bug in sfcc. The following functions
	 * allow us to store namespace seperately. 
	 */

	/**
	 * Sets the name space corresponding to this instance.
	 */
	void setNameSpace (const string& ns);

	/**
	 * Gets the class name corresponding to this instance.
	 */
	string getClassName (void) const;

	/**
	 * Sets the class name corresponding to this instance.
	 */
	void setClassName (const string& classname);

public:
	/**
	 * Destructor
	 */
	~CCIMEnumeration ();

public:
	/**
	 * Clone this object
	 */
	CCIMEnumeration* clone (void) const;

public:
	/**
	 * Returns the low level instance.
	 */
	CMPIEnumeration* getLowLevelObject (void) const { return _en; }


	/**
	 * Get the next element of this enumeration.
	 */
	CCIMData getNext (void) const throw (ECIMError);

	/**
	 * Test for any elements left in this enumeration.
	 */
	bool hasNext (void) const throw (ECIMError);

public:
	/*--------- CCIMValue Conversion adapter required functions ----------*/
	typedef CCIMEnumeration AdapteeType;
    static const CMPIType 	cmpi_type = CMPI_enumeration;

	/**
	 * Creates this object from a string. This is not supported.
	 */
    static CCIMEnumeration create (string /* val_str */) 
    { 
    	throw (EInvalidValueObject (CMPI_string));
    }

	/**
	 * Creates this object from a low level CMPIValue.
	 */
    static CCIMEnumeration create (CMPIValue* val, bool auto_release)         
    {                                                                       
        return toCCIMEnumeration (val->Enum, auto_release);
    }

	/**
	 * Converts @p val to a low level CMPIValue object.
	 */
	static CMPIValue toCMPIValue (CCIMEnumeration val)									
    {                                                                       
        CMPIValue cv;                                                       
        cv.Enum = val.getLowLevelObject ();                                                   
		return cv;															
    }          
	/*------------ End of CCIMValue Conversion adapter functions -----------*/
                                                                            

private:
	/**
	 * Private constructor taking CMPIEnumeration as argument.
	 */
	CCIMEnumeration (CMPIEnumeration* en) : _en (en), 
											_ns_set (false),
											_ns (""),
											_classname_set (false),
											_classname ("") { /* Empty */ }

private:
	CMPIEnumeration*	_en;
	bool				_ns_set;
	string				_ns;
	bool				_classname_set;
	string				_classname;
	int*				_ref_count;
	bool				_auto_release;
};

/**
 * @class CKeyClass
 * @brief A template class providing the key class for CIM class iterators.
 */
template <class ItemClass>
class DSDK_Export CKeyClass : public IGenericKey <ItemClass>
{
public:
    /**
     * Create this key from a CCIMEnumeration.
     */
    static CKeyClass* create (const CCIMEnumeration& en)
	{
		return new CKeyClass (en);
	}

public:
    /**
     * Returns the current Item this key is pointing to
     */
    const ItemClass& getItem (void) { return *_item; }

    /**
     * Moves the Key to the next item.
     */
    void next (void)
	{
		CCIMValue cv = _en.getNext ().getValue ().clone ();
		if (0 == _item)															
		{
			_item = new ItemClass (to <ItemClass> (cv, true));

			if (_item->cmpi_type == CMPI_instance)
			{
				makeInstanceObjectPath ((CCIMInstance*)_item, _en.getClassName ());
			}
		}																		
		else																	
		{																		
			*_item = to <ItemClass> (cv, true);  

			if (_item->cmpi_type == CMPI_instance)
			{
				makeInstanceObjectPath ((CCIMInstance*)_item, _en.getClassName ());
			}
		}
	}

    /**
     * Checks if there is next item.
     * @return true if there is a next item.
     *         false otherwise.
     */
    bool hasNext (void) { return _en.hasNext (); }

    /**
     * Checks if two keys are equal.
     * @return true if equal.
     *         false otherwise.
     */
    bool isEqual (const IGenericKey<ItemClass>*) { return false; }

public:
	virtual ~CKeyClass ()
	{
		if (0 != _item) { delete _item; }
	}

protected:
    CKeyClass (const CCIMEnumeration& en) : _en (en), _item (0) { /* Empty */ }

private:
    CCIMEnumeration     _en;
    ItemClass*			_item;
};

};	/* namespace dsdk */

#ifdef _WIN32
#pragma warning (pop)
#endif

#endif /* __DSDK_CIMENUMERATION_H__ */

