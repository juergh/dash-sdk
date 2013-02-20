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

#ifndef __MOF2CPP_CIMMETHOD_H__
#define __MOF2CPP_CIMMETHOD_H__
#include "cimparameter.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

/**
 * @class CCIMMethod
 * @brief A class representing a CIM Method.
 */
class CCIMMethod 
{
public:
	/**
	 * Constructor
	 */
	CCIMMethod (string type, string name) : _return_type (type), _name (name) { /* Empty */ }

public:
	void addDesc (string desc) 		{ _desc = desc; }
	void setReturnType (string return_type) { _return_type = return_type; }
	void addParameter  (const CCIMParameter& parameter)
	{
		_parameters.push_back (parameter);
	}

	/**
	 * Adds a value map entry for return type
	 */
	void addReturnCodeValueMap (string value, string desc) 
	{ 
		_return_code_value_map.push_back (pair<string, string> (value, desc)); 
	}


public:
	string generateCode (void);

private:
	string getParameters   (void);
	string getFunctionBody (void);

	string getDllWrapperParameters (void);
	string getDllWrapperFunctionBody (void);

	string getCSWrapperDllCallParameters (void);
	string getCSWrapperDllCallFunctionParameters (void);
	string getCSWrapperParameters (void);
	string getCSWrapperParametersNoRetval (bool applyComma = false);
	string getCSWrapperParameterConversion (void);
	string getCSWrapperOutputParameterConversion(void);

private:
	string convIFn (string s);
	string minVal (string s);
	string maxVal (string s);

	string getValueMapCode 	   (void);
	string getValueMapStrCode  (void);

	string getReturnCodeValueMapCode (void);
	string getReturnCodeValueMapStrCode (void);

private:
	string							_desc;
	string							_return_type;
	vector<pair<string, string> >	_return_code_value_map;
	string							_name;
	vector<CCIMParameter>			_parameters;
};

#endif /* __MOF2CPP_CIMMETHOD_H__ */

