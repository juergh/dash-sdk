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

#include "cimparameter.h"
#include "util.h"


string
CCIMParameter::minVal(string s) {
	if (g_oalcs) {
		return convIFn(s) + ".MinValue";
	} else {
		return "min_" + s;
	}
}

string
CCIMParameter::maxVal(string s) {
	if (g_oalcs) {
		return convIFn(s) + ".MaxValue";
	} else {
		return "max_" + s;
	}
}

string
CCIMParameter::convIFn(string s) {
	return g_oalcs ? ConvertToCSDataType(s) : s;
}

/*
 * getValueMapCode
 */
string 
CCIMParameter::getValueMapCode (void)
{
	string code;

	map<string, int> var_map;
	vector<pair<string, string> >::iterator i;
	string prev_val = minVal(_type);

	if (g_oalcs && _value_map.size()) {
		code += "\t\tpublic enum %CLASSNAME%_%FUNCTION_NAME%_" + _name + " : " + ConvertToCSDataEnumType(_type) + " {\r\n";
	}
	
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
					range_high = maxVal(_type);
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
				code += "\tstatic const " + _type + " %FUNCTION_NAME%_" + 
						_name + "_" + var + "_low\t= " + 
						range_low + ";\r\n";

				code += "\tstatic const " + _type + " %FUNCTION_NAME%_" + 
						_name + "_" + var + "_high\t= " + 
						range_high + ";\r\n";
			}
		}
		else
		{
			if (g_oalcs) {
				code += "\t\t\t_" + var + "\t= " + (*i).first + ",\r\n";
			} else {
				code += "\tstatic const " + _type + " %FUNCTION_NAME%_" + 
						_name + "_" + var + "\t= " + 
						(*i).first + ";\r\n";
			}
			
			prev_val = (*i).first;
		}
	}

	if (g_oalcs && _value_map.size()) {
		code += "\t\t}\r\n";
	}

	return code;
}

/*
 * getValueMapStrCode
 */
string 
CCIMParameter::getValueMapStrCode (void)
{
	if (_value_map.size () == 0) { return ""; }

	string code;
	string prev_val = minVal(_type);

	code += "\t";
	if (g_oalcs) {
		code += "\tpublic " + convIFn("string") + " %FUNCTION_NAME%_" + _name + "_2Str";
	} else {
		code += "\tstatic string getValueStr_%FUNCTION_NAME%_" + _name;
	}

	code += " (" + convIFn(_type) + " val) {\r\n";

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
					range_high = maxVal(_type);
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
			code += "\t\t";
			code += g_oalcs ? "\t" : "";
			code += "if (val == " + (*i).first + ")";
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


