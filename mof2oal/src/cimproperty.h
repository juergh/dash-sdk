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

#ifndef __MOF2CPP_CIMPROPERTY_H__
#define __MOF2CPP_CIMPROPERTY_H__
#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;
using std::pair;

extern bool g_allproperty_writeable;

/**
 * @class CCIMProperty
 * @brief A CIM Property.
 */
class CCIMProperty 
{
public:
	/**
	 * Constructor.
	 */
	CCIMProperty (string data_type, string name, bool is_array);

public:
	/**
	 * Returns the name of this property
	 */
	string getName (void) { return _name; }

public:
	/**
	 * Adds the description for the property
	 */
	void addDesc (string desc) { _desc = desc; }

	/**
	 * Adds a value map entry
	 */
	void addValueMap (string value, string desc) 
	{ 
		_value_map.push_back (pair<string, string> (value, desc)); 
	}

	/**
	 * Sets this property to be writeable
	 */
	void setWriteable (void) { _read_only = false; }

	/**
	 * Sets this property to be key
	 */
	void setAsKey (void) { _key = true; }

	/**
	 * Returns true if this is a key property
	 */
	bool isKey (void) { return _key; }

	/**
	 * Returns the data type
	 */
	string getDataType (void) { return _data_type; }

	/**
	 * Returns whether the property is an array
	 */
	bool isArray (void) { return _is_array; }

	/**
	 * Compare operator
	 */
	bool operator == (const CCIMProperty& rhs) { return _name == rhs._name; }

public:
	/**
	 * Generate the code for the property.
	 */
	virtual string generateCode (void);

private:
	string getValueMapCode (void);
	string getValueMapStrCode  (void);
	string convIFn (string s);
	string minVal (string s);
	string maxVal (string s);
	string getOALTypeFreeFn (bool oal2cs);
	string getOALType (void);
	string getOALTypeNew (void);
	string getOALToCsConversion (void);
	string getCsToOALConversion (void);

private:
	string				_desc;
	string				_data_type;
	string				_name;
	bool				_is_array;
	bool				_read_only;
	bool				_key;
//	map<string, string>	_value_map;
	vector<pair<string, string> >	_value_map;
};

#endif /* __MOF2CPP_CIMPROPERTY_H__ */

