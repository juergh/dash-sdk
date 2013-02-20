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

#ifndef __MOF2CPP_CIMQUALIFIER_H__
#define __MOF2CPP_CIMQUALIFIER_H__

#define DCOM_QUALIFIER_TYPE_STRING	0x01
#define DCOM_QUALIFIER_TYPE_ARRAY	0x02

/**
 * @class CCIMQualifier
 * A class representing CIM Qualifier. This class is implemented with a 
 * very simple case of string and arrays as possible types. If it gets 
 * more complex than this, the class needs to be implemented as handle 
 * body.
 */
class CCIMQualifierValue 
{
public:
	CCIMQualifierValue () { /* Empty */ }

	/* Sets the value of the qualifier */
	void setValue (string value) 
	{
		_type  = DCOM_QUALIFIER_TYPE_STRING;
		_value = value;
	}
	
	/* Sets the value of the qualifier */
	void setValue (const vector<string>& value)
	{
		_type  		 = DCOM_QUALIFIER_TYPE_ARRAY;
		_array_value = value;
	}

public:
	/**
	 * Returns the type 
	 */
	int getType (void) const { return _type; }

	/**
	 * Returns the string value
	 */
	string getValueString (void) const { return _value; }	

	/**
	 * Returns the array value
	 */
	const vector<string>& getValueArray (void) const { return _array_value; }	

private:
	int				_type;
	string			_value;
	vector<string>	_array_value;
};

#endif /* __MOF2CPP_CIMQUALIFIER_H__ */

