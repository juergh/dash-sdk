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

#ifndef __MOF2CPP_CIMREFERENCE_H__
#define __MOF2CPP_CIMREFERENCE_H__
#include <string>
using std::string;

/**
 * @class CCIMReference
 * @brief A class representing a CIM Reference.
 */
class CCIMReference
{
public:
	/**
	 * Constructor
	 */
	CCIMReference (string reference_object, string reference_name);

public:
	/** Add description */
	void addDesc (string desc) { _desc = desc; }

	/** Get Functions. */
	string getDesc (void) { return _desc; }
	string getReferenceObject (void) { return _reference_object; }
	string getReferenceName   (void) { return _reference_name;   }

	/**
	 * Generates the code.
	 */
	virtual string generateCode (void);

private:
	string	_desc;
	string	_reference_object;
	string	_reference_name;
};

#endif /* __MOF2CPP_CIMREFERENCE_H__ */

