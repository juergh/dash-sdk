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

#include "cimmethod.h"
#include "skeleton.h"
#include "util.h"
#include <time.h>

/*
 * generateCode
 */
string
CCIMMethod::generateCode (void)
{
	string code = CSkeleton::instance ()->getContent ("METHOD");

	code = ::replaceStr (code, "%VALUEMAP%", 	  getValueMapCode ());
	code = ::replaceStr (code, "%VALUEMAP_STR%",  getValueMapStrCode ());
	code = ::replaceStr (code, "%FUNCTION_DESC%", _desc);
	code = ::replaceStr (code, "%RETURN_TYPE%",   convIFn(_return_type));
	code = ::replaceStr (code, "%FUNCTION_NAME%", _name);
	code = ::replaceStr (code, "%FUNCTION_PARAMETERS%", getParameters ());
	code = ::replaceStr (code, "%FUNCTION_BODY%", getFunctionBody ());
	code = ::replaceStr (code, "%DLL_WRAPPER_FUNCTION_PARAMETERS%", getDllWrapperParameters ());
	code = ::replaceStr (code, "%DLL_WRAPPER_FUNCTION_BODY%", getDllWrapperFunctionBody ());
	code = ::replaceStr (code, "%CS_WRAPPER_FUNCTION_PARAMETERS%", getCSWrapperParameters ());
	code = ::replaceStr (code, "%CS_WRAPPER_FUNCTION_PARAMETERS_NO_RETVAL%", getCSWrapperParametersNoRetval ());
	code = ::replaceStr (code, "%CS_WRAPPER_PARAMETER_CONVERSION%", getCSWrapperParameterConversion ());
	code = ::replaceStr (code, "%CS_WRAPPER_DLL_CALL_PARAMETERS%", getCSWrapperDllCallParameters ());
	code = ::replaceStr (code, "%CS_WRAPPER_DLL_CALL_FUNCTION_PARAMETERS%", getCSWrapperDllCallFunctionParameters ());
	code = ::replaceStr (code, "%CS_WRAPPER_OUTPUT_PARAMETER_CONVERSION%", getCSWrapperOutputParameterConversion ());

	return code;
}


/*
 * getParameters
 */
string
CCIMMethod::getParameters (void)
{
	int inputCount = 0;
	string param;
	for (unsigned int i = 0; i < _parameters.size (); i++)
	{
		param += _parameters [i].getTypeString ();
		if (_parameters [i].isOutput ()) { 
			param += "*"; 
		} else {
			inputCount++;
		}
		param += " " + _parameters [i].getName ();
		param += ", ";
	}

	if (inputCount) {
	    param += "vector<string> IgnoreParam = vector <string>(), ";
	} else {
	    param += "vector<string> /* IgnoreParam */ = vector <string>(), ";
	}

	param += "vector<_name_value_pair> CustomParam = vector<_name_value_pair>()";

	return param;
}

/*
 * getParameters
 */
string
CCIMMethod::getCSWrapperDllCallParameters (void) {
	string param;

	param += "OalObj, ref retval";

	for (unsigned int i = 0; i < _parameters.size (); i++)
	{
		param += ", "; 

		if (_parameters[i].isArray()) {
			param += "ref _" + _parameters [i].getName();;
		} else {
			if (_parameters [i].isOutput()) {
				param += "/* isOutput */ ref ";
				if (_parameters [i].isRef() || _parameters[i].getTypeString() == "string" || _parameters[i].getTypeString() == "datetime")
					param += "_";
				param += _parameters [i].getName();
			} else if (_parameters[i].getTypeString() == "string" || _parameters[i].getTypeString() == "datetime") { 
				param += " _" + _parameters [i].getName();
			} else {
				param += " " + _parameters [i].getName();
			}
		}
	}

	return param;
}

/*
 * getParameters
 */
string
CCIMMethod::getCSWrapperDllCallFunctionParameters (void) {
	string param;

	param += "IntPtr iter";
	param += ", ref " + ConvertToCSDataType(_return_type) + " retval";

	for (unsigned int i = 0; i < _parameters.size (); i++)
	{
		param += ", "; 

		if (_parameters[i].isArray()) {
			param += "ref OalDllArg " + _parameters [i].getName();;
		} else {
			if (_parameters [i].isOutput()) 
				param += "ref ";
			if (_parameters [i].isRef()) {
				param += "IntPtr";
			} else if (_parameters [i].getTypeString() == "string" || _parameters [i].getTypeString() == "datetime") {
				param += "IntPtr";
			} else {
				param += ConvertToCSDataType(_parameters [i].getTypeString());
			}
			param += " " + _parameters [i].getName();
		}
	}

	return param;
}

/*
 * getParameters
 */
string
CCIMMethod::getCSWrapperParametersNoRetval (bool applyComma) {
	string param;

	for (unsigned int i = 0; i < _parameters.size (); i++)
	{
		if (i || applyComma) param += ", "; 

		if (_parameters[i].isArray()) {
			if (_parameters [i].isOutput ()) 
				param += "ref ";
			param += ConvertToCSDataType(_parameters [i].getTypeString());
		} else {
			if (_parameters [i].isOutput ()) 
				param += "ref ";

			if (_parameters [i].isRef ()) {
				/* classes like CIM_System... */
				param += _parameters [i].getTypeString();
			} else {
				param += ConvertToCSDataType(_parameters [i].getTypeString());
			}
		}

		param += " " + _parameters [i].getName ();
	}
	
	return param;
}

string
CCIMMethod::getCSWrapperParameters (void) {
	return "ref " + ConvertToCSDataType(_return_type) + " retval" +
		getCSWrapperParametersNoRetval(true);
}

/*
 * getFunctionBody
 */
string
CCIMMethod::getCSWrapperParameterConversion (void)
{
	string code;
	int arg_cnt = 0;

	code += "\r\n";

	for (unsigned int i = 0; i < _parameters.size (); i++)
	{
		if (!_parameters [i].isOutput() || _parameters [i].isArray ()) { 
			if (_parameters [i].isArray ()) { 
				code += "\t\t\tOalDllArg _" + _parameters [i].getName() + " = oalConvert.toOALDLLArg(" + _parameters [i].getName() + ");\r\n";
			} else if (_parameters [i].getTypeString() == "string" || _parameters [i].getTypeString() == "datetime") {
				code += "\t\t\tIntPtr _" + _parameters [i].getName() + " = oalConvert.toOALDLLPtr(" + _parameters [i].getName() + ");\r\n";
			}
		} else if (_parameters [i].isRef()) {
			code += "\t\t\tIntPtr _" + _parameters [i].getName() + " = IntPtr.Zero;\r\n";
		} else if (_parameters [i].getTypeString() == "string" || _parameters [i].getTypeString() == "datetime") {
			if (_parameters [i].isInput()) {
				code += "\t\t\tIntPtr _" + _parameters [i].getName() + " = oalConvert.toOALDLLPtr(" + _parameters [i].getName() + ");\r\n";
			} else {
				code += "\t\t\tIntPtr _" + _parameters [i].getName() + " = IntPtr.Zero;\r\n";
			}
		}
	}
	
	return code;
}

string
CCIMMethod::getCSWrapperOutputParameterConversion(void) {
	string code;
	int arg_cnt = 0;

	code += "\r\n";

	for (unsigned int i = 0; i < _parameters.size (); i++)
	{
		if (!_parameters [i].isOutput()) { 
			if (_parameters [i].isArray ()) { 
				code += "\t\t\tMarshal.FreeHGlobal(_" + _parameters [i].getName() + ".buf);\n";
			}
		} else {
			if (_parameters [i].isArray ()) { 
				if (isCimOrDriClass(_parameters [i].getTypeString())) {
					code += "\t\t" + _parameters [i].getName() + " = (" + getDataTypeFromArray(_parameters [i].getTypeString()) + "Iter.createArray(oalConvert.ToIntPtrArray(_" + _parameters [i].getName() + ")));\n";
				} else {
					code += "\t\t\t" + _parameters [i].getName() + " = oalConvert.To" + ConvertToCSDataType(getDataTypeFromArray(_parameters [i].getTypeString())) + "Array(_" + _parameters [i].getName() + ");\r\n";
				}
			} else {
				if (_parameters [i].isRef()) {
					code += "\t\t\t" + _parameters [i].getName() + " = new " + _parameters [i].getTypeString() + "(_" + _parameters [i].getName() + ");\r\n"; 
				} else if (_parameters [i].getTypeString() == "string" || _parameters [i].getTypeString() == "datetime") {
					code += "\t\t\tif (_" + _parameters [i].getName() + " != IntPtr.Zero) {\r\n";
					code += "\t\t\t\t" + _parameters [i].getName() + " = oalConvert.ToString(_" + _parameters [i].getName() + ").ToString();\r\n";
					code += "\t\t\t\tCommon.free(_" + _parameters [i].getName() + ");\n";
					code += "\t\t\t} else {\r\n";
					code += "\t\t\t\t" + _parameters [i].getName() + " = \"\";\r\n";
					code += "\t\t\t}\r\n";
				}
			}
		}
	}
	
	return code;
}

/*
 * getParameters
 */
string
CCIMMethod::getDllWrapperParameters (void) {
	string param;

	param += "COALObject *_d";
	param += ", " + getDLLDataType(_return_type) + "* retval";

	for (unsigned int i = 0; i < _parameters.size (); i++)
	{
		param += ", "; 

		if (_parameters[i].isArray()) {
			if (_parameters [i].isOutput ()) {
				param += "/* is Output */";
			}
			param += "oaldllarg *";
		} else {
			param += getDLLDataType(_parameters [i].getTypeString());
			if (_parameters [i].isRef ()) {
				param += "*";
			} 
			if (_parameters [i].isOutput ()) {
				param += "*";
			}
		}

		param += " " + _parameters [i].getName ();
	}

	return param;
}

/*
 * getFunctionBody
 */
string
CCIMMethod::getDllWrapperFunctionBody (void)
{
	string check = "\r\n";
	string code;
	string call;
	string output = "\t\t/* Output Conversion */\r\n";
	int arg_cnt = 0;

	check += "\t\t if (_d == NULL)\r\n";
	check += "\t\t\t return PP_ERR;\r\n";
	check += "\r\n";
	code += "\t\t%CLASSNAME%%TEMPLATES%* _c = dynamic_cast<%CLASSNAME%%TEMPLATES%*>(_d);\r\n";
	code += "\t\tif (_c == NULL)\r\n";
	code += "\t\t\treturn PP_ERR;\r\n";
	code += "\r\n";
	code += "\t\t%CLASSNAME% c = *_c;\r\n";
	code += "\r\n";
	call += "\r\n";
	call += "\t\ttry {\r\n";
	call += "\t\t\t*retval = c." + _name + "(";

	for (unsigned int i = 0; i < _parameters.size (); i++)
	{
		if (_parameters [i].isArray ()) 
		{ 
			code += "\t\tvector<" + _parameters [i].getType () + "> _" + _parameters [i].getName() + ";\r\n";
			if (_parameters [i].isOutput()) 
        		{
        			call += string(arg_cnt++ ? "," : "") + "&_" + _parameters [i].getName();
				if (isCimOrDriClass(_parameters [i].getTypeString())) {
 				    output += "\t\tvector<void*> __" + _parameters [i].getName() + ";\r\n";
				    output += "\t\tfor (int q=0; q < (int)_" + _parameters [i].getName() + ".size(); q++) {\r\n";
				    output += "\t\t\t__" + _parameters [i].getName() + ".push_back((void*)&_" + _parameters [i].getName() + "[q]);\r\n";
				    output += "\t\t}\r\n";
				    output += "\t\tif (vec2ser(__" + _parameters [i].getName() + ", " + _parameters [i].getName() + ") != PP_OK)\r\n";
				    output += "\t\t\treturn PP_ERR;\r\n";
				} else {
				    output += "\t\tif (vec2ser(_" + _parameters [i].getName() + ", " + _parameters [i].getName() + ") != PP_OK)\r\n";
				    output += "\t\t\treturn PP_ERR;\r\n";
				}
			}
			else
			{
                            if (_parameters[i].isRef()) {
				code += "\t\tvector<void*> classes" + _parameters [i].getName() + ";\r\n";
                                code += "\r\n";
                                code += "\t\tif (ser2vec(" + _parameters [i].getName() + ", &classes" + _parameters [i].getName() + ") != PP_OK)\r\n";
                                code += "\t\t\treturn PP_ERR;\r\n";
                                code += "\r\n";
				code += "\t\tfor (unsigned int i=0; i<classes" + _parameters [i].getName() + ".size(); i++) {;\r\n";
                                code += "\t\t    " + _parameters [i].getType() + "* d = (" + _parameters [i].getType() + "*)classes" + _parameters [i].getName() + "[i];\r\n";
                                code += "\t\t    _" + _parameters [i].getName() + ".push_back(*d);\r\n";
				code += "\t\t}\r\n";
                                code += "\r\n";
                            } else {
                                code += "\t\tif (ser2vec(" + _parameters [i].getName() + ", &_" + _parameters [i].getName() + ") != PP_OK)\r\n";
                                code += "\t\t\treturn PP_ERR;\r\n";
                                code += "\r\n";
		            }
                                call += string(arg_cnt++ ? "," : "") + "_" + _parameters [i].getName();
			}
		}
		else
		{
			if (_parameters [i].isRef ()) {
				if (!_parameters [i].isOutput ())
					check += "\t\t // TODO: Implement handling of optional parameters like TargetBios at SetBIOSAttribute! \r\n";
				check += "\t\t if (" + _parameters [i].getName() + " == NULL)\r\n";
				check += "\t\t\t return PP_ERR;\r\n";
				check += "\r\n";

				if (_parameters [i].isOutput ()) {
					code += "\t\t" + _parameters [i].getType () + " _" + _parameters [i].getName() + "(CCIMInstance::nullInstance());";
					call += string(arg_cnt++ ? "," : "") + "&_" + _parameters [i].getName();
					output += "\t\t*" + _parameters [i].getName() + " = new " + _parameters [i].getType() + "(_" + _parameters [i].getName() + ");\r\n";
				} else {
					code += "\t\t" + _parameters [i].getType () + " _" + _parameters [i].getName() + " = *" + _parameters [i].getName() + ";";
					call += string(arg_cnt++ ? "," : "") + "_" + _parameters [i].getName();
				}
				code += "\r\n";
			} else {
				if (_parameters [i].isOutput ()) {
					code += "\t\t" + _parameters [i].getTypeString() + " _" + _parameters [i].getName() + ";\r\n\r\n";
					if (_parameters [i].getTypeString() == "string" || _parameters [i].getTypeString() == "datetime") {
						code += "\t\tif (" + _parameters [i].getName() + " != NULL && *" + _parameters [i].getName() + " != NULL)\r\n";
					} else {
						code += "\t\tif (" + _parameters [i].getName() + " != NULL)\r\n";
					}
					code += "\t\t\t_" + _parameters [i].getName() + " = *" + _parameters [i].getName() + ";\r\n\r\n";
					call += (arg_cnt++ ? ", " : "") + ("&_" + _parameters [i].getName());
					output += "\t\t*" + _parameters [i].getName() + " = " + getDLLtoCDataTypeConversion(getDLLDataType(_parameters [i].getTypeString()), " _" + _parameters [i].getName()) + ";\r\n";
				} else {
					if (_parameters[i].getTypeString() == "datetime") {
						code += "\t\tdatetime _" + _parameters [i].getName() + " = datetime(" + _parameters [i].getName() + ");\n";
						call += (arg_cnt++ ? ", " : "") + ("_" + _parameters [i].getName());
					} else {
						call += (arg_cnt++ ? ", " : "") + _parameters [i].getName();
					}
				}
			}
		}
	}
	
	/* add IgnoreParam... */
	code = check + code;
	call += string(arg_cnt ? ", " : "") + "vector <string>()";	
	call += ");\r\n";
	call +=	"\t\t} catch (dsdk::EDSDKError& e) {\r\n";
	call +=	"\t\t\tunsigned int f = e.getErrorCode();\r\n";
	call +=	"#ifdef _DEBUG\r\n";
	call +=	"\t\t\tassert(f != PP_OK && f != PP_ERR);\r\n";
	call +=	"#endif\r\n";
	call +=	"\t\t\treturn f;\r\n";
	call +=	"\t\t}\r\n";
	code += call + "\r\n";
	code += "\t\tif (*retval != PP_OK)\r\n";
	code += "\t\t\treturn PP_ERR;\r\n\r\n";
	code += output + "\r\n";
	code += "\t\treturn PP_OK;";

	return code;
}


/*
 * getFunctionBody
 */
string
CCIMMethod::getFunctionBody (void)
{
	string code;

	code += "CCIMArgument\t\t\t\tin;\r\n\t\tCCIMArgument\t\t\t\tout;\r\n";
	code += "\t\tvector<string>::iterator\titer;\r\n\r\n";

	for (unsigned int i = 0; i < _parameters.size (); i++)
	{
		if (!_parameters [i].isInput ()) { continue; }

		code += "\t\tif (IgnoreParam.end () == (iter = find (IgnoreParam.begin (), IgnoreParam.end (), \"";
		code += _parameters [i].getName ();
		code += "\")))\r\n\t\t{\r\n";

		if (_parameters [i].isArray ()) 
		{ 
			if (_parameters [i].isRef ())
			{
				code += "\t\t\tvector <CCIMObjectPath> " + _parameters [i].getName () + "OP;\r\n";
				if (_parameters [i].isOutput()) {
					code += "\t\t\tfor (size_t i = 0; i < " + _parameters [i].getName () + "->size (); i++)\r\n";
					code += "\t\t\t{\r\n\t\t\t" + _parameters [i].getName () + "OP.push_back ((*" 
							+ _parameters [i].getName () + ") [i].getObjectPath());\r\n\t\t}\r\n";
				} else {
					code += "\t\t\tfor (size_t i = 0; i < " + _parameters [i].getName () + ".size (); i++)\r\n";
					code += "\t\t\t{\r\n\t\t\t" + _parameters [i].getName () + "OP.push_back (" 
							+ _parameters [i].getName () + " [i].getObjectPath());\r\n\t\t}\r\n";
				}

				code += "\t\t\tin.addArg (";
				code += "\"" + _parameters [i].getName () + 
									"\", toCCIMValueArray<CCIMObjectPath>  (" + 
									_parameters [i].getName () + "OP));\r\n";
			}
			else
			{
				code += "\t\t\tin.addArg (";
				code += "\"" + _parameters [i].getName () + 
									"\", toCCIMValueArray";
				code += "<" + _parameters [i].getType () + "DSDKAdapter> ";
				if (_parameters [i].isOutput ()) {
				    code += " (*";
				} else {
				    code += " (";
				}
				code += _parameters [i].getName () + "));\r\n";
			}
		}
		else
		{
			code += "\t\t\tin.addArg (";
			code += "\"" + _parameters [i].getName () + 
								"\", toCCIMValue";
			
			if (_parameters [i].isRef ())
			{
				code += "<CCIMObjectPath> ";
				code += " (" + _parameters [i].getName ();
				if (_parameters [i].isOutput ()) {
				    code += "->getObjectPath ()));\r\n";
				} else {
				    code += ".getObjectPath ()));\r\n";
				}
			}
			else
			{
				code += "<" + _parameters [i].getType () + "DSDKAdapter> ";
				if (_parameters [i].isOutput ()) {
				    code += " (*";
				} else {
				    code += " (";
				}
				code += _parameters [i].getName () + "));\r\n";
			}
		}

		code += "\t\t}\r\n";

	}

	code += "\r\n\t\tfor (size_t i = 0; i < CustomParam.size (); i++)\r\n";
	code += "\t\t{\r\n\t\t\tin.addArg (CustomParam [i].first, CustomParam [i].second);\r\n\t\t}\r\n\r\n";

	code += "\r\n\t\tCCIMData d_out = _client->invokeMethod (_ins.getObjectPath (), \"" + 
			_name + "\" , in, &out);\r\n\r\n";
	if (_return_type != "")
	{
			
		code += "\t\tCCIMValue d_out_cv = d_out.getValue ();\r\n";
		code += "\t\t" + _return_type +" return_value = to <" + _return_type + "DSDKAdapter> (d_out_cv, true);";
	}
	//code += "\t\t\t\t\tif( return_value == 4096) {\r\n";

	for (unsigned int i = 0; i < _parameters.size (); i++)
	{
		if (!_parameters [i].isOutput ()) { continue; }

		code += "\t\ttry {\r\n";

		code += "\t\t\tCCIMData d_" + _parameters [i].getName () + 
				" = out.getArg (\"" + 
				_parameters [i].getName () + "\");\r\n";

		code += "\t\t\tCCIMValue " + _parameters [i].getName () + "_cv = " + 
				"d_" + _parameters [i].getName () + ".getValue ();\r\n";

		code += "\t\t\t*" + _parameters [i].getName (); 
		
		if	(_parameters [i].isArray ()) { code += " = toArray<";	}
		else							 { code += " = to<";		}
		code +=	_parameters [i].getType () + 
				"DSDKAdapter> (" + _parameters [i].getName () + 
			 	"_cv, false);\r\n";
		if (isCimOrDriClass(_parameters [i].getTypeString())) {
		    if (_parameters[i].isArray()) {
			code += "\t\t\tif (" + _parameters [i].getName() + ") {\r\n";
			code += "\t\t\t\tfor (unsigned int u=0; u<" + _parameters [i].getName() + "->size(); u++) {\r\n";
			code += "\t\t\t\t\t(*" + _parameters [i].getName() + ")[u].initialize(_client);\r\n";
			code += "\t\t\t\t}\r\n";
			code += "\t\t\t}\r\n";
		    } else {
				code += "\t\t\tif (" + _parameters [i].getName() + ") {\r\n";
				code += "\t\t\t\t" + _parameters [i].getName() + "->initialize(_client);\r\n";
		    
				if (_parameters [i].getName() == "Job")
				{
					code += "\t\t\t\tint currJobState = 0;\r\n";
					code += "\t\t\t\tfor (int i=0;i<5;i++ )	{\r\n";
					code += "\t\t\t\t\tJob->disableCache();\r\n";
					code += "\t\t\t\t\tcurrJobState = Job->getJobState();\r\n";
					code += "\t\t\t\t\tif ( currJobState != 4 )	break;\r\n";
					code += "\t\t\t\t\tclock_t endwait;\r\n";
					code += "\t\t\t\t\tendwait = clock () + 20 * CLOCKS_PER_SEC ;\r\n";
					code += "\t\t\t\t\twhile (clock() < endwait) {}\r\n";
					code += "\t\t\t\t}\r\n";
				}
				code += "\t\t\t\t}\r\n";
			}
		}
		code += "\t\t}\r\n\t\tcatch (...) {}\r\n";
	}
	//code += "\t\t\t\t}\r\n";
	code += "\t\treturn return_value;";

	return code;
}

/*
 * getValueMapCode
 */
string
CCIMMethod::getValueMapCode (void)
{
	string code;

	/* get the value map code for the return code */
	code += getReturnCodeValueMapCode () + "\r\n\r\n";

	/* get the value map code for the parameters */
	for (unsigned int i = 0; i != _parameters.size (); i++)
	{
		code += _parameters [i].getValueMapCode ();		
	}
	return code;
}

/*
 * getValueMapStrCode
 */
string
CCIMMethod::getValueMapStrCode (void)
{
	string code;

	/* get the value map string  for the return code */
	code += getReturnCodeValueMapStrCode () + "\r\n\r\n";

	/* get the value map string for the parameters */
	for (unsigned int i = 0; i != _parameters.size (); i++)
	{
		code += _parameters [i].getValueMapStrCode ();		
	}
	return code;
}


string
CCIMMethod::minVal(string s) {
	if (g_oalcs) {
		return convIFn(s) + ".MinValue";
	} else {
		return "min_" + s;
	}
}

string
CCIMMethod::maxVal(string s) {
	if (g_oalcs) {
		return convIFn(s) + ".MaxValue";
	} else {
		return "max_" + s;
	}
}

string
CCIMMethod::convIFn(string s) {
	return g_oalcs ? ConvertToCSDataType(s) : s;
}

/*
 * getReturnCodeValueMapCode
 */
string 
CCIMMethod::getReturnCodeValueMapCode (void)
{
	string code;

	map<string, int> var_map;
	vector<pair<string, string> >::iterator i;
	string prev_val = minVal(_return_type);

	if (g_oalcs && _return_code_value_map.size()) {
		code += "\t\tpublic enum %CLASSNAME%_%FUNCTION_NAME%_ReturnCode : " + ConvertToCSDataEnumType(_return_type) + " {\r\n";
	}

	for (i = _return_code_value_map.begin (); i != _return_code_value_map.end (); i++)
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
				
				if (j == _return_code_value_map.end ()) 
				{ 
					range_high = maxVal(_return_type);
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
				code += "\tstatic const " + _return_type + " %FUNCTION_NAME%_" + 
						"ReturnCode" + "_" + var + "_low\t= " + 
						range_low + ";\r\n";

				code += "\tstatic const " + _return_type + " %FUNCTION_NAME%_" + 
						"ReturnCode" + "_" + var + "_high\t= " + 
						range_high + ";\r\n";
			}
		}
		else
		{
			string quote = "";
			if (_return_type == "string")
				quote = "\"";

			if (g_oalcs) {
				code += "\t\t\t_" + var + "\t= " + (*i).first + ",\r\n";
			} else {
				code += "\tstatic const " + _return_type + " %FUNCTION_NAME%_" + 
						"ReturnCode" + "_" + var + "\t= " + 
						quote + (*i).first + quote + ";\r\n";
			}

			prev_val = (*i).first;
		}
	}

	if (g_oalcs && _return_code_value_map.size()) {
		code += "\t\t}\r\n";
	}

	return code;
}

/*
 * getReturnCodeValueMapStrCode
 */
string 
CCIMMethod::getReturnCodeValueMapStrCode (void)
{
	if (_return_code_value_map.size () == 0) { return ""; }

	string code;
	string prev_val = minVal(_return_type);

	code += "\t";
	if (g_oalcs) {
		code += "\tpublic " + convIFn("string") + " %FUNCTION_NAME%_ReturnCode_2Str";
	} else {
		code += "\tstatic string getValueStr_%FUNCTION_NAME%_ReturnCode";
	}

	code += " (" + convIFn(_return_type) + " val) {\r\n";

	vector<pair<string, string> >::iterator i; bool is_first = true;
	for (i = _return_code_value_map.begin (); i != _return_code_value_map.end (); i++)
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
				
				if (j == _return_code_value_map.end ()) 
				{ 
					range_high = maxVal(_return_type);
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
			if (!is_first)							  { code += "(val >= " + range_low + "+1)"; }
			if ((!is_first) && 
				(j != _return_code_value_map.end ())) { code += " && ";	}
			if (j != _return_code_value_map.end ())   { code += "(val <= " + range_high + "-1)"; }
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


