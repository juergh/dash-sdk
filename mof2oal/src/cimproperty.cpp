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

#include "cimproperty.h"
#include "skeleton.h"
#include "util.h"

/*
 * Constructor.
 */
CCIMProperty::CCIMProperty (string data_type, string name, bool is_array) : 
					_data_type (data_type), _name (name), _is_array (is_array),
					_key (false)
{
	if (g_allproperty_writeable)
	{
		_read_only = false;
	}
	else 
	{
		_read_only = true;
	}

}

/*
 * generateCode
 */
string
CCIMProperty::generateCode (void)
{
	string code;
	if (_is_array) 
	{ 
		code = CSkeleton::instance ()->getContent ("PROPERTY_ARRAY");  
		code = ::replaceStr (code, "%GET_PROPERTY_ARRAY%", 
	   						 CSkeleton::instance ()->getContent ("GET_PROPERTY_ARRAY"));
		
		if (_read_only)
		{
			code = ::replaceStr (code, "%SET_PROPERTY_ARRAY%", "");
		}
		else
		{
			code = ::replaceStr (code, "%SET_PROPERTY_ARRAY%", 
		   						 CSkeleton::instance ()->getContent ("SET_PROPERTY_ARRAY"));
		}
	}
	else		   
	{ 
		code = CSkeleton::instance ()->getContent ("PROPERTY");
		code = ::replaceStr (code, "%GET_PROPERTY%", 
	   						 CSkeleton::instance ()->getContent ("GET_PROPERTY"));
		
		if (_read_only)
		{
			code = ::replaceStr (code, "%SET_PROPERTY%", "");
		}
		else
		{
			code = ::replaceStr (code, "%SET_PROPERTY%", 
		   						 CSkeleton::instance ()->getContent ("SET_PROPERTY"));
		}
	}

	if (_value_map.size () != 0)
	{
		code = ::replaceStr (code, "%VALUEMAP%", 	  getValueMapCode ());
		code = ::replaceStr (code, "%VALUEMAP_STR%",  getValueMapStrCode ());

		code = ::replaceStr (code, "%CS_VALUEMAP%",	  getValueMapCode ());
		code = ::replaceStr (code, "%CS_VALUEMAP_STR%", getValueMapStrCode ());
	}
	else
	{
		code = ::replaceStr (code, "%VALUEMAP%", 	  "");
		code = ::replaceStr (code, "%VALUEMAP_STR%",  "");
		code = ::replaceStr (code, "%CS_VALUEMAP%",   "");
		code = ::replaceStr (code, "%CS_VALUEMAP_STR%", "");
	}

	code = ::replaceStr (code, "%PROPERTY_DESC%", _desc);
	code = ::replaceStr (code, "%PROPERTY_NAME%", _name);
	code = ::replaceStr (code, "%PROPERTY_TYPE%", _data_type);
	code = ::replaceStr (code, "%PROPERTY_CS_TYPE%", ConvertToCSDataType(_data_type));
	code = ::replaceStr (code, "%PROPERTY_DLL_TYPE%", getDLLDataType(_data_type));
	code = ::replaceStr (code, "%PROPERTY_C_TO_DLL_TYPE_CONVERSION%", getCtoDLLDataTypeConversion(_data_type));
	code = ::replaceStr (code, "%PROPERTY_DLL_TO_C_TYPE_CONVERSION%", getDLLtoCDataTypeConversion(_data_type));
	
	code = ::replaceStr (code, "%PROPERTY_OAL_TYPE%", getOALType() );
	code = ::replaceStr (code, "%PROPERTY_OAL_TYPE_NEW%", getOALTypeNew());
	code = ::replaceStr (code, "%PROPERTY_OAL_TO_CS_TYPE_FREE%", getOALTypeFreeFn(true /* = oal 2 cs */));
	code = ::replaceStr (code, "%PROPERTY_CS_TO_OAL_TYPE_FREE%", getOALTypeFreeFn(false));
	code = ::replaceStr (code, "%PROPERTY_OAL_TO_CS_TYPE_CONVERSION%", getOALToCsConversion());
	code = ::replaceStr (code, "%PROPERTY_CS_TO_OAL_TYPE_CONVERSION%", getCsToOALConversion());

	return code;
}

string
CCIMProperty::getOALTypeFreeFn(bool oal_to_cs) {
	if (_data_type == "string" || _data_type == "datetime") {
		return oal_to_cs ? "Common.free(v);" : "Marshal.FreeHGlobal(t);";
	} else {
		return "";
	}
}

string
CCIMProperty::getOALType() {
	 return (_data_type == "string" || _data_type == "datetime") ? "IntPtr" : ConvertToCSDataType(_data_type);
}

string
CCIMProperty::getOALTypeNew() {
	 return (_data_type == "string" || _data_type == "datetime") ? "IntPtr.Zero" : "new " + ConvertToCSDataType(_data_type) + "()";
}

string
CCIMProperty::getOALToCsConversion() {
	return (_data_type == "string" || _data_type == "datetime") 
		? "oalConvert.ToString(v).ToString() /* this will throw an exception if the conversion fn returns null */"
		: "v";
}

string
CCIMProperty::getCsToOALConversion() {
	 return (_data_type == "string" || _data_type == "datetime") ? "oalConvert.toOALDLLPtr(a)" : "a";

}
string
CCIMProperty::minVal(string s) {
	if (g_oalcs) {
		return convIFn(s) + ".MinValue";
	} else {
		return "min_" + s;
	}
}

string
CCIMProperty::maxVal(string s) {
	if (g_oalcs) {
		return convIFn(s) + ".MaxValue";
	} else {
		return "max_" + s;
	}
}

string
CCIMProperty::convIFn(string s) {
	return g_oalcs ? ConvertToCSDataType(s) : s;
}

/*
 * getValueMapCode
 */
string 
CCIMProperty::getValueMapCode (void)
{
	string code;
	map<string, int> var_map;

	vector<pair<string, string> >::iterator i;

	if (g_oalcs) {
		code += "\t\tpublic enum %CLASSNAME%_" + _name + " {\r\n";
	}

	string prev_val = minVal(_data_type);
	for (i = _value_map.begin (); i != _value_map.end (); i++)
	{
		string var = toCVariable ((*i).second);
		/* Check if the variable is already defined */		
		map<string, int>::iterator iter = var_map.find (var);
		if (iter != var_map.end ())
		{
			int count = (*iter).second;
			var_map.erase (iter);
			var_map.insert (pair<string, int> (var, count + 1));

			char count_str [20];
			::sprintf (count_str, "__%d__", count + 1);
			var += count_str;
		}
		else
		{
			var_map.insert (pair<string, int> (var, 0));
		}

		if (isRangeValue ((*i).first))
		{
			string range      = (*i).first;
			string range_low  = (rangeLow (range) != "") ? rangeLow (range) : 
												    	   prev_val;
			string range_high;
			if (rangeHigh (range) == "")
			{
				vector<pair<string, string> >::iterator j = i;
				j++;
				
				if (j == _value_map.end ()) 
				{ 
					range_high = maxVal(_data_type);
				}
				else
				{
					range_high = rangeLow ((*j).first);
				}
			}
			else { range_high = rangeHigh (range); }
			prev_val = range_high;

			if (g_oalcs) {
                code += "\t\t\t_" + var + "_low\t= " + 
					range_low + ",\r\n";

				code += "\t\t\t_" + var + "_high\t= " + 
					range_high + ",\r\n";
			} else {
				code += "\tstatic const " + _data_type + " " + _name + "_" + 
					var + "_low\t= " + 
					range_low + ";\r\n";

				code += "\tstatic const " + _data_type + " " + _name + "_" + 
					var + "_high\t= " + 
					range_high + ";\r\n";
			}
		}
		else
		{
			if (_data_type == "string") {
				code += "/* FIXME: define this constant: ";
				code += " \t string " + _name + "_" + var + "\t = \"" + (*i).first + "\";  */\r\n";
			} else {
				if (g_oalcs) {
					code += "\t\t\t_" + var + "\t= " + (*i).first + ",\r\n";
				} else {
					code += "\tstatic const " + _data_type + " " + _name + "_" + 
						var + "\t= " + (*i).first + ";\r\n";
				}
			}
		    prev_val = (*i).first;
		}
	}

	if (g_oalcs) {
		code += "\t\t}\r\n";
	}

	return code;
}

/*
 * getValueMapStrCode
 */
string 
CCIMProperty::getValueMapStrCode (void)
{
	string code;
	string prev_val = minVal(_data_type);

	code += "\t";
	if (g_oalcs) {
		code += "\tpublic " + convIFn("string") + " " +  _name + "2Str";
	} else {
		code += "static string getValueStr_" + _name;
	}
	
	code += " (" + convIFn(_data_type) + " val) {\r\n";

	vector<pair<string, string> >::iterator i; bool is_first = true;
	for (i = _value_map.begin (); i != _value_map.end (); i++)
	{
		if (isRangeValue ((*i).first))
		{
			string range      = (*i).first;
			string range_low  = (rangeLow (range) != "") ? rangeLow (range) : 
												    	   prev_val;
			string range_high;
			if (rangeHigh (range) == "")
			{
				vector<pair<string, string> >::iterator j = i;
				j++;
				
				if (j == _value_map.end ()) 
				{ 
					range_high = maxVal(_data_type);
				}
				else
				{
					range_high = rangeLow ((*j).first);
				}
			}
			else { range_high = rangeHigh (range); }
			prev_val = range_high;

			vector<pair<string, string> >::iterator j = i;
			j++;
			code += "\t\t";
			code += g_oalcs ? "\t" : "";
			code += "if (";
			if (!is_first)				  { code += "(val >= " + range_low + ")"; }
			if ((!is_first) && 
				(j != _value_map.end ())) { code += " && ";	}
			if (j != _value_map.end ())   { code += "(val <= " + range_high + ")"; }
			code += ")\t{ return (\"" + (*i).second + "\"); }\r\n";
		}
		else
		{
			string quote = "";
			if (_data_type == "string")
			    quote = "\"";
			code += "\t\tif (val == " + quote + (*i).first + quote + ")";
			code += "\t{ return (\"" + (*i).second + "\"); }\r\n";

			prev_val = (*i).first;
		}

		is_first = false;
	}

	code += "\t\t";
	code += g_oalcs ? "\t" : "";
	code += "return \"\";\r\n";
	code += g_oalcs ? "\t" : "";
	code += "\t}\r\r\n";

	return code;
}

