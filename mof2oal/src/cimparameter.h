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

#ifndef __MOF2CPP_CIMPARAMETER_H__
#define __MOF2CPP_CIMPARAMETER_H__
#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::pair;
using std::map;

/**
 * @class CCIMParameter
 * @brief A class representing a CIM Parameter.
 */
class CCIMParameter
{
public:
	CCIMParameter (string type, string name, bool array) : _type  (type),
														   _name  (name),
														   _array (array),
														   _input (false),
														   _output(false),
														   _ref   (false)
														   { /* Empty */ }

public:
	void setInput  (void) { _input  = true; }
	void setOutput (void) { _output = true; }
	bool isInput   (void) { return _input;  }
	bool isOutput  (void) { return _output; }

	void setRef (void) { _ref = true; }
	bool isRef (void)  { return _ref; }

	bool   isArray (void) { return _array; }
	string getName (void) { return _name;  }
	string getType (void) { return _type;  }
	string getTypeString (void) 
	{
		string ts;

		if (_array) { ts = "vector<" + _type + ">"; }
		else 		{ ts = _type; }

		return ts;
	}

	/**
	 * Adds a value map entry
	 */
	void addValueMap (string value, string desc) 
	{ 
		_value_map.push_back (pair<string, string> (value, desc)); 
	}

public:
	string getValueMapCode (void);
	string getValueMapStrCode  (void);

private:
	string	_type;
	string	_name;
	bool	_array;
	bool	_input;
	bool	_output;
	bool	_ref;
	vector<pair<string, string> >	_value_map;

	string convIFn (string s);
	string minVal (string s);
	string maxVal (string s);
};

#endif /* __MOF2CPP_CIMPARAMETER_H__ */

