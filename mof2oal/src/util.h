/*
 * <AMD 3BSD notice header>
 *
 * Copyright (c) 2006, 2007, 2008 Advanced Micro Devices, Inc.
 *
 * All rights reserved.
 *
 * This file is subject to the license found in the LICENSE.AMD file which
 * states the following in part:
 *
 * Redistribution and use in any form of this material and any product
 * thereof including software in source or binary forms, along with any
 * related documentation, with or without modification ("this material"),
 * is permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code of any software must retain the above
 *     copyright notice and all terms of this license as part of the code.
 *
 *   * Redistributions in binary form of any software must reproduce the
 *     above copyright notice and all terms of this license in any related
 *     documentation and/or other materials. 
 *
 *   * Neither the names nor trademarks of Advanced Micro Devices, Inc.
 *     or any copyright holders or contributors may be used to endorse or
 *     promote products derived from this material without specific prior
 *     written permission.
 */

#ifndef __MOF2CPP_UTIL_H__
#define __MOF2CPP_UTIL_H__
#include "skeleton.h"
#include <string>

using std::string;

extern string g_skeldir;
extern string g_wrapper_dll_name;
extern bool g_oalcs;
extern bool g_oaldll;

inline string 
replaceStr (string str, string var, string val)
{
	string::size_type pos = 0;
	while (true)
	{
		pos = str.find (var, pos);
		if (pos >=  str.size ()) { break; }

		str = str.replace (pos, var.size (), val);
		pos += val.size ();
	}

	return str;
}

inline string
toCVariable (string str)
{
	for (string::size_type i = 0; i < str.size (); i++)
	{
		if (('A' <= str [i] && str [i] <= 'Z') ||
			('a' <= str [i] && str [i] <= 'z') ||
			('0' <= str [i] && str [i] <= '9') || 
			('_' == str [i]))
		{
			continue;
		}
		else { str = str.replace (i, 1, "_"); }
	}

	return str;
}

inline string 
fixCRLF (string str)
{
	string new_str   = "";
	int	   new_ix    = 0;
	for (string::size_type i = 0; i < str.size (); i++)
	{
		switch (str [i])
		{
		case '\n' : 
			new_str += "\r\n";
			break;

		case '\r' : 
			new_str += "\r\n";
			if ((i != str.size ()) && (str [i + 1] == '\n')) { i++; }
			break;

		default:
			new_str += str [i];
		}
	}

	return new_str;
}

inline bool
isRangeValue (string val)
{
	return (val.find ("..") != string::npos);
}

inline string
rangeLow (string val)
{
	string::size_type pos = val.find ("..");
	if (pos == 0) { return ""; }
	else 		  { return val.substr (0, pos); }
}

inline string
rangeHigh (string val)
{
	string::size_type pos = val.find ("..");
	if (pos + 2 != val.size ()) { return val.substr (pos + 2); }
	else { return ""; }
}

/**
 * Loads all the skeleton files
 */
inline void 
loadSkeletonFiles (void)
{
	CSkeleton::instance ()->load ("FILE", 			g_skeldir + "file.skel");
	CSkeleton::instance ()->load ("ENUMERATOR", 	g_skeldir + "enumerator.skel");
	CSkeleton::instance ()->load ("ASSOCIATION", 	g_skeldir + "association.skel");
	CSkeleton::instance ()->load ("CLASS", 			g_skeldir + "class.skel");
	CSkeleton::instance ()->load ("METHOD", 		g_skeldir + "method.skel");
	CSkeleton::instance ()->load ("REFERENCE", 		g_skeldir + "reference.skel");
	CSkeleton::instance ()->load ("PROPERTY", 		g_skeldir + "property.skel");
	CSkeleton::instance ()->load ("PROPERTY_ARRAY", g_skeldir + "property_array.skel");
	CSkeleton::instance ()->load ("GET_PROPERTY", 	g_skeldir + "get_property.skel");
	CSkeleton::instance ()->load ("SET_PROPERTY", 	g_skeldir + "set_property.skel");
	CSkeleton::instance ()->load ("GET_PROPERTY_ARRAY", g_skeldir + "get_property_array.skel");
	CSkeleton::instance ()->load ("SET_PROPERTY_ARRAY", g_skeldir + "set_property_array.skel");
}

/* Type Conversion Stuff */

/*
 * convert c/c++ data type to data types used at the dll interface
 */
inline string 
getCtoDLLDataTypeConversion(string cdt, string varname) {
	string ret;

	if (cdt == "string") {
		ret =  "mystrdup(" + varname + ".c_str())";
	} else if (cdt == "datetime") {
		ret =  "mystrdup(" + varname + ".getStringFormat().c_str())";
	} else {
		ret = varname;
	}
	return ret;
}
inline string 
getCtoDLLDataTypeConversion(string cdt) {
	return getCtoDLLDataTypeConversion(cdt, "n");
}

/*
 * convert data types used at the dll interface to c/c++ data type
 */
inline string 
getDLLtoCDataTypeConversion(string cdt, string varname) {
	string ret;
	
	if (cdt == "char*") {
		ret = "mystrdup(" +varname + ".c_str())";
	} else if (cdt == "datetime") {
            ret =  "datetime(std::string(" + varname + "));";
	} else {
		ret = varname;
	}
	return ret;
}
inline string 
getDLLtoCDataTypeConversion(string cdt) {
	return getDLLtoCDataTypeConversion(cdt, "n");
}

inline string 
getDLLDataType(string cdt) {
	string ret;

	if (cdt == "string" || cdt == "datetime") {
		ret =  "char*";
	} else {
		ret = cdt;
	}
	return ret;
}

inline string 
getDataTypeFromArray (string cdt) 
{
    string ret = cdt;
    if (cdt.find("vector") != string::npos) {
	ret.replace(0,7,"");
	ret.replace(ret.length()-1,1,"");
    }
    return ret;
}

/*
 * convert c/c++ data type to C# data type
 */
inline string 
ConvertToCSDataType (string cdt)
{
	string ret = "";

	if (cdt == "uint8") {
			ret =  "Byte";
	} else if (cdt == "sint8") {
			ret =  "SByte";
	} else if (cdt == "uint16") {
			ret =  "UInt16";
	} else if (cdt == "uint32") {
			ret =  "UInt32";
	} else if (cdt == "uint64") {
			ret =  "UInt64";
	} else if (cdt == "sint16") {
			ret =  "Int16";
	} else if (cdt == "sint32") {
			ret =  "Int32";
	} else if (cdt == "sint64") {
			ret =  "Int64";
	} else if ((cdt == "string") ||
			   (cdt == "datetime")) {
			ret =  "String";
	} else if (cdt == "boolean") {
			ret =  "Boolean";
	} else if (cdt == "real32") {
			ret =  "Float";
	} else if (cdt == "real64") {
			ret =  "Double";
	} else if (cdt == "object") {
			ret =  "Object";
	} else if (cdt.find("vector") != string::npos) {
			ret = getDataTypeFromArray(cdt);
			string c = ConvertToCSDataType(ret);
			ret = (c.find("#error") == string::npos ? c : ret) + "[]";
	} else {
		ret =  "#error type " + cdt + "is not handled by mof2oal!";
	}
	return ret;
}

inline string 
ConvertToCSDataEnumType (string cdt)
{
	string ret = "";

	if (cdt == "uint8") {
			ret =  "byte";
	} else if (cdt == "sint8") {
			ret =  "sbyte";
	} else if (cdt == "uint16") {
			ret =  "ushort";
	} else if (cdt == "uint32") {
			ret =  "uint";
	} else if (cdt == "uint64") {
			ret =  "ulong";
	} else if (cdt == "sint16") {
			ret =  "short";
	} else if (cdt == "sint32") {
			ret =  "int";
	} else if (cdt == "sint64") {
			ret =  "long";
	} else {
		ret =  "#error type " + cdt + "is not handled by mof2oal!";
	}
	return ret;
}

inline bool
isCimOrDriClass(string _type) {
    bool ret = false;
    string arrtype = ConvertToCSDataType(_type);
    if (arrtype.find("[]") != string::npos) {
        /* handle CIM and DRI class arguments in a special way... */
	/* try to convert this data type to a C# data type */
	string tmp = ConvertToCSDataType(getDataTypeFromArray(_type));
	/* check whether this is a unknown data type (e.g. a CIM or a DRI class) */
	if (tmp.find("#error") != string::npos) {
	    ret = true;
	}
    } else {
	string tmp = ConvertToCSDataType(_type);
	/* check whether this is a unknown data type (e.g. a CIM or a DRI class) */
	if (tmp.find("#error") != string::npos) {
	    ret = true;
	}
    }
    return ret;
}
#endif /* __UTIL_H__ */

