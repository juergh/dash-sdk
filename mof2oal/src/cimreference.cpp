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

#include "cimreference.h"
#include "util.h"

/*
 * Constructor
 */
CCIMReference::CCIMReference (string reference_object, 
					 		  string reference_name) : 
							  _reference_object (reference_object),
							  _reference_name (reference_name)
{
}

/*
 * generateCode
 */
string
CCIMReference::generateCode (void)
{
	string code;
	if (!g_oalcs && !g_oaldll) {
	    code  = "\t/**\r\n\t * ";
	    code += _desc;
	    code += "\r\n\t */\r\n";

	    /* Write the get function header */
	    code += "\tCCIMObjectPath get" + _reference_name + "(void)\r\n";

	    /* Write the get function body. */
	    code += "\t{\r\n\t\tCOALObject::checkUpdateCache (\"" + _reference_name + "\");\r\n";
	    code += "\r\n\t\tCCIMValue	 value = this->_ins.getProperty (\"" + 
						_reference_name + "\").getValue ();\r\n";
	    code += " \r\n\t\tCCIMObjectPath " + _reference_name + 
						 " = to<CCIMObjectPath> (value);\r\n";
	    code += "\r\t\treturn " + _reference_name + ";\r\n";
	    code += "\t}\r\n";						 
	} else {
	    code = CSkeleton::instance ()->getContent ("REFERENCE");
	    code = ::replaceStr (code, "%REFERENCE_OBJ%", _reference_object);
	    code = ::replaceStr (code, "%REFERENCE_DESC%", _desc);
	    code = ::replaceStr (code, "%REFERENCE_NAME%", _reference_name);
	}

	return code;
#if 0
	/* Write the description */
	::writeString (fp, "/*\r\n");
	::writeString (fp, _desc);
	::writeString (fp, "*/\r\n");

	/* Write the get function header */
	::writeString (fp, "CCIMObjectPath get" + _reference_name + "(void) const\r\n");

	/* Write the get function body. */
	::writeString (fp, "{\r\n\tcheckUpdateCache (\"" + _reference_name + "\");\r\n");
	::writeString (fp, "{\r\n\tCCIMObjectPath " + _reference_name + 
						 " = toCCIMObjectPath (_ins.getProperty (" + 
						_reference_name + ").getValue ());\r\n");
	::writeString (fp, "return " + _reference_name + "\r\n");
	::writeString (fp, "}\r\n");						 
#endif
	return "";
}


