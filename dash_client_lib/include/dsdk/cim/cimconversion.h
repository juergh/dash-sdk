/*
 * License Agreement 
 *
 * Copyright (c) 2007, 2008  Advanced Micro Devices.
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
 * cimconversion.h
 * CIM Conversion functions.
 */
#ifndef __DSDK_CIMCONVERSION_H__
#define __DSDK_CIMCONVERSION_H__
#include <cmci/cmci.h>
#include <cmci/native.h>
#include <dsdk/cim/cimtypes.h>
#include <dsdk/cim/cimerror.h>
#include <dsdk/cim/cimvalue.h>
#include <dsdk/cim/cimarray.h>
#include <dsdk/cim/cimstring.h>
#include <string>
#include <vector>
#include <string.h>
using std::string;
using std::vector;


namespace dsdk
{

#define DEFINE_TYPE_ADAPTER(TYPE, CMPI_TYPE, FIELD, MIN_VAL, MAX_VAL)		\
class DSDK_Export TYPE##DSDKAdapter                                         \
{                                                                           \
public:                                                                     \
	typedef TYPE AdapteeType;												\
    static const CMPIType cmpi_type = CMPI_TYPE;                            \
    static const int     min = 0;											\
    static const int     max = 0; /*FIXME: Store correct min max values! */	\
    static TYPE##DSDKAdapter create (string val_str)                        \
    {                                                                       \
        TYPE val;    /*FIXME: Use correct min max values for stringToVal */ \
		val = (TYPE) stringToVal (val_str, 0, 0);						    \
        return TYPE##DSDKAdapter (val);                                     \
    }                                                                       \
    static TYPE##DSDKAdapter create (CMPIValue* val, bool /*auto_release */)\
    {                                                                       \
        return TYPE (val->FIELD);                                           \
    }                                                                       \
	static CMPIValue toCMPIValue (TYPE val)									\
    {                                                                       \
        CMPIValue cv;                                                       \
        cv.FIELD = val;														\
		return cv;															\
    }                                                                       \
    operator TYPE () { return _val; }                                       \
                                                                            \
    TYPE##DSDKAdapter (TYPE val) : _val (val) { /* Empty */ }               \
private:																	\
    TYPE _val;                                                              \
};

#define DEFINE_SIMPLETYPE_ADAPTER(TYPE,CMPI_TYPE,FIELD,CONVFN)				\
class DSDK_Export TYPE##DSDKAdapter                                         \
{                                                                           \
public:                                                                     \
	typedef TYPE AdapteeType;												\
    static const CMPIType cmpi_type = CMPI_TYPE;                            \
	static const TYPE     min       = min_##TYPE;                           \
	static const TYPE     max       = max_##TYPE;                           \
    static TYPE##DSDKAdapter create (string val_str)                        \
    {                                                                       \
        TYPE val;                                                           \
		val = (TYPE) stringTo##CONVFN##Val (val_str, min, max);				\
        return TYPE##DSDKAdapter (val);                                     \
    }                                                                       \
    static TYPE##DSDKAdapter create (CMPIValue* val, bool /*auto_release */)\
    {                                                                       \
        return TYPE (val->FIELD);                                           \
    }                                                                       \
	static CMPIValue toCMPIValue (TYPE val)									\
    {                                                                       \
        CMPIValue cv;                                                       \
        cv.FIELD = val;														\
		return cv;															\
    }                                                                       \
    operator TYPE () { return _val; }                                       \
                                                                            \
    TYPE##DSDKAdapter (TYPE val) : _val (val) { /* Empty */ }               \
private:																	\
    TYPE _val;                                                              \
};

#define DEFINE_BOOLEAN_ADAPTER(TYPE, CMPI_TYPE, FIELD)						\
class DSDK_Export TYPE##DSDKAdapter                                         \
{                                                                           \
public:                                                                     \
	typedef TYPE AdapteeType;												\
    static const CMPIType cmpi_type = CMPI_TYPE;                            \
    static TYPE##DSDKAdapter create (string val_str)                        \
    {                                                                       \
        TYPE val;                                                           \
        val = (TYPE) stringToBool (val_str);								\
        return TYPE##DSDKAdapter (val);                                     \
    }                                                                       \
    static TYPE##DSDKAdapter create (CMPIValue* val, bool /*auto_release */)\
    {                                                                       \
        return TYPE (val->FIELD);                                           \
    }                                                                       \
	static CMPIValue toCMPIValue (TYPE val)									\
    {                                                                       \
        CMPIValue cv;                                                       \
        cv.FIELD = val;														\
		return cv;															\
    }                                                                       \
    operator TYPE () { return _val; }                                       \
                                                                            \
    TYPE##DSDKAdapter (TYPE val) : _val (val) { /* Empty */ }               \
private:																	\
    TYPE _val;                                                              \
};

inline uint64
stringToUVal (string val, uint64 min, uint64 max)
{
	uint64 ret;

	::sscanf (val.c_str (), "%llu", &ret);
	if (min != max && (ret < min || ret > max)) {
	    throw EInvalidValueObject (CMPI_string);
	}
	return ret;
}

/**
 * Convert a string to value 
 */
inline sint64
stringToVal (string val, sint64 min, sint64 max)
{
	sint64 ret;

	::sscanf (val.c_str (), "%lld", &ret);
	if (min != max && (ret < min || ret > max)) {
	    throw EInvalidValueObject (CMPI_string);
	}
	return ret;
}

#if defined(WIN32)
# define strcasecmp _stricmp
#endif

/**
 * Convert a string to boolean 
 */
inline bool
stringToBool (string val)
{
	if (!strcasecmp(val.c_str(), "true")) { 
		return true;
	}
	if (!strcasecmp(val.c_str(), "false")) { 
		return false;
	}
	throw EInvalidValueObject (CMPI_string);
}


/**
 * Convert a CIM value to a type. This template function will be used by the 
 * Object access layer to convert CCIMValue returned by client to the native
 * types.
 */
template <class TypeAdapter>
typename TypeAdapter::AdapteeType
to (CCIMValue& cv, bool auto_release = false)
{
	CMPIType   cmpi_type = cv.getLowLevelType ();
	CMPIValue* cmpi_val  = cv.getLowLevelValue ();

	if (cmpi_type != TypeAdapter::cmpi_type)
	{
		if (cmpi_type == CMPI_string) 
		{ 
			CMPIStatus status;			
			TypeAdapter rt = TypeAdapter::create (cmpi_val->string->ft->getCharPtr (cmpi_val->string, 
														   	    	&status)); 
			if (auto_release) { cmpi_val->string->ft->release (cmpi_val->string); }
			return rt;
		}
		else { throw (EInvalidValueObject (cmpi_type)); }
	}
	if (auto_release) { cv.invalidate (); }
	return TypeAdapter::create (cmpi_val, auto_release);
}

/**
 * Convert a CIM value to a type. This template function will be used by the 
 * Object access layer to convert CCIMValue returned by client to the native
 * vector types.
 */
template <class TypeAdapter>
vector <typename TypeAdapter::AdapteeType>
toArray (CCIMValue& cv, bool auto_release = false)
{
	CMPIType   cmpi_type = cv.getLowLevelType ();
	CMPIValue* cmpi_val  = cv.getLowLevelValue ();

	if (0 == (cmpi_type & CMPI_ARRAY)) 
	{ 
		vector<typename TypeAdapter::AdapteeType> ret;
		ret.push_back (to<TypeAdapter> (cv, auto_release));
		return ret;
	}

	CCIMArray ca = CCIMArray::toCCIMArray (cmpi_val->array, auto_release);
	if ((0 != (cmpi_type & TypeAdapter::cmpi_type)) ||
		(0 != (cmpi_type & CMPI_string)) || 
		(cmpi_type == CMPI_ARRAY))
	{
		unsigned int size = ca.getSize ();
		vector<typename TypeAdapter::AdapteeType> ret;
		for (unsigned int i = 0; i != size; i++)
		{
			CCIMValue cval = ca.getElementAt (i).getValue ();
			ret.push_back (to<TypeAdapter> (cval, false));			
		}

		if (auto_release) { cv.invalidate (); }
		return ret;
	}
	else { throw EInvalidValueObject (cmpi_type); }
}

/**
 * Convert from a type to CCIMValue 
 */
template <class TypeAdapter>
CCIMValue 
toCCIMValue (typename TypeAdapter::AdapteeType val)
{
	CMPIStatus rc;
	CMPIValue cv	= TypeAdapter::toCMPIValue (val);
	CMPIValue clone = native_clone_CMPIValue (TypeAdapter::cmpi_type, &cv, &rc);
	return CCIMValue::toCCIMValue (clone, TypeAdapter::cmpi_type, true);
}

/**
 * Convert from a vector to CCIMArray. @todo Check if array creates new 
 * memory for setElements or uses existing memory.
 */
template <class TypeAdapter>
CCIMArray
toCCIMArray (const vector<typename TypeAdapter::AdapteeType>& val)
{
	unsigned int num_elem = (unsigned int) val.size ();

	CCIMArray ca (TypeAdapter::cmpi_type, num_elem);
	for (unsigned int i = 0; i < num_elem; i++)
	{
		ca.setElementAt (i, 
						 toCCIMValue<TypeAdapter> (val [i]));
	}

	return ca;
}


/**
 * Convert from a vector to CCIMValue. 
 */
template <class TypeAdapter>
CCIMValue
toCCIMValueArray (const vector<typename TypeAdapter::AdapteeType>& val)
{
	CCIMArray ca = toCCIMArray<TypeAdapter> (val);
	return toCCIMValue <CCIMArray> (ca);
}
 
/* 
 * Adapters for Simple types
 */
DEFINE_SIMPLETYPE_ADAPTER (uint64,  CMPI_uint64, uint64,U)
DEFINE_SIMPLETYPE_ADAPTER (uint32,  CMPI_uint32, uint32,U)
DEFINE_SIMPLETYPE_ADAPTER (uint16,  CMPI_uint16, uint16,U)
DEFINE_SIMPLETYPE_ADAPTER (char16,  CMPI_char16, char16,U)
DEFINE_SIMPLETYPE_ADAPTER (uint8,   CMPI_uint8,  uint8,U)
DEFINE_SIMPLETYPE_ADAPTER (sint64,  CMPI_sint64, sint64,)
DEFINE_SIMPLETYPE_ADAPTER (sint32,  CMPI_sint32, sint32,)
DEFINE_SIMPLETYPE_ADAPTER (sint16,  CMPI_sint16, sint16,)
DEFINE_SIMPLETYPE_ADAPTER (sint8,   CMPI_sint8,  sint8,)
DEFINE_TYPE_ADAPTER       (real64,  CMPI_real64, real64, 0.0, 0.0)
DEFINE_TYPE_ADAPTER       (real32,  CMPI_real32, real32, 0.0, 0.0)
DEFINE_BOOLEAN_ADAPTER (boolean, CMPI_boolean, boolean)

/*
 * CIM Types are adapters for themselves. Just create an alias with
 * DSDKAdapter prefix to ease work of the MOF compiler code generator.
 */
#define CCIMConstClassDSDKAdapter	CCIMConstClass
#define CCIMInstanceDSDKAdapter		CCIMInstance
#define CCIMStringDSDKAdapter 		CCIMString
#define CCIMArrayDSDKAdapter 		CCIMArray
#define CCIMDateTimeDSDKAdapter		CCIMDateTime
#define datetimeDSDKAdapter			CCIMDateTimeDSDKAdapter
#define CCIMObjectPathDSDKAdapter	CCIMObjectPath

/**
 * @class stringDSDKAdapter
 * A Skeleton class providing just the adaptee type.
 */
class stringDSDKAdapter
{
public:
	typedef string AdapteeType;
};

/**
 * to template specialization for standard string type 
 */
template<>
inline string
to<stringDSDKAdapter> (CCIMValue& cv, bool auto_release)
{
	return (string) to<CCIMStringDSDKAdapter> (cv, auto_release);
}

/**
 * toCCIMValue specialization for standard string type
 */
template <>
inline CCIMValue 
toCCIMValue <stringDSDKAdapter> (string val)
{
	return toCCIMValue<CCIMString> (CCIMString (val));
}

/**
 * toArray template specialization for standard string type.
 */
template<>
inline vector<string>
toArray <stringDSDKAdapter> (CCIMValue& cv, bool auto_release)
{
	vector<CCIMString> vcs = toArray <CCIMStringDSDKAdapter> (cv, auto_release);

	vector<string> vs;
	for (unsigned int i = 0; i != vcs.size (); i++)
	{
		vs.push_back ((string) vcs [i]);
	}

	return vs;
}

/**
 * toCCIMArray template specialization.
 */
template <>
inline CCIMArray
toCCIMArray<stringDSDKAdapter> (const vector<string>& val)
{
	size_t num_elem = val.size ();

	vector<CCIMString>	vcs;	
	for (size_t i = 0; i < num_elem; i++)
	{
		vcs.push_back (CCIMString (val [i]));
	}

	return toCCIMArray <CCIMStringDSDKAdapter> (vcs);
}

/**************************************************************************************/
/* Added the below functions to support Opaquemanagementdata read and write operations 
 * as the exisiting architecture doesnt provide support for the uint8[] */
/**************************************************************************************/

/**
 * Convert from a uint8 vector to CCIMValue. 
 */
template <>
inline CCIMValue
toCCIMValueArray<uint8DSDKAdapter> (const vector<uint8>& val)
{
	if(val.size () > 1)
	{
		string str(val.begin(),val.end());
		return toCCIMValue<CCIMString> (CCIMString (str));
	}
	else
	{
		CCIMArray ca = toCCIMArray<uint8DSDKAdapter> (val);
		return toCCIMValue <CCIMArray> (ca);
	}
}

/**
 * toArray template specialization for standard uint8 type.
 */
template<>
inline vector<uint8>
toArray <uint8DSDKAdapter> (CCIMValue& cv, bool auto_release)
{
	CMPIValue* cmpi_val  = cv.getLowLevelValue ();
	CMPIStatus status;
	string val_str = cmpi_val->string->ft->getCharPtr (cmpi_val->string,&status); 
	vector<uint8> vs(val_str.begin(),val_str.end());
	return vs;
}

};

#endif  /* __DSDK_CIMCONVERSION_H__ */
