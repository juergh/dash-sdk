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

#include "cimclass.h"
#include "skeleton.h"
#include "util.h"
#include <algorithm>

using std::find;

extern vector<CCIMClass> g_classes;

/*
 * Constructor
 */
CCIMClass::CCIMClass (string name, string superclass_name) : 
							_name (name), _superclass_name (superclass_name),
							_association (false)
{
}

/*
 * addDesc
 */
void 
CCIMClass::addDesc (string desc)
{
	_desc = desc;
}

/*
 * addProperty
 */
void 
CCIMClass::addProperty (const CCIMProperty& prop)
{
	_props.push_back (prop);
}

/*
 * addMethod
 */
void 
CCIMClass::addMethod (const CCIMMethod& method)
{
	_methods.push_back (method);
}

/*
 * addReference
 */
void 
CCIMClass::addReference (const CCIMReference& reference)
{
	_references.push_back (reference);
}

/*
 * setUMLPkgPath
 */
void 
CCIMClass::setUMLPkgPath (string path)
{
	_uml_pkg_path = path;
}

/*
 * getUMLPkgPath
 */
string 
CCIMClass::getUMLPkgPath (void)
{
	return _uml_pkg_path;
}

/*
 * getKeyProperties
 */
vector<string>
CCIMClass::getKeyPropertyNames (void)
{
	vector<string> key_props;
	for (size_t i = 0; i < _props.size (); i++)
	{
		if (_props [i].isKey ())
		{
			key_props.push_back (_props [i].getName ());
		}
	}

	return key_props;
}

/*
 * get property names
 */
vector<string>
CCIMClass::getPropertyNames (void)
{
	vector<string> props;
	for (size_t i = 0; i < _props.size (); i++)
	{
		props.push_back (_props [i].getName ());
	}

	return props;
}

/*
 * getSuperClassName
 */
string
CCIMClass::getSuperClassName (void)
{
	return _superclass_name;
}

CCIMClass*
CCIMClass::getSuperClass(void) {
	if (_superclass_name != "")
	{
		for (unsigned int i = 0; i < g_classes.size (); i++)
		{
			if (g_classes [i]._name == _superclass_name)
			{
				return &g_classes [i];
			}
		}
	}

	return NULL;
}

/**
 * return true if this class is an association.
 */
bool 
CCIMClass::isAssociation (void) { 

    /* FIXME: ugly dri mof file hack, dri files should use the "Association" statement! 
       example: [Association] class CIM_BerndMueller 
    */

    if (_association) 
	return _association; 
    
    if (_name.find("CIM_") == 0)
	return _association; 
    
    CCIMClass* cc = getSuperClass();

    if (cc != NULL &&
    	cc->isAssociation()) {
	_association = true;
    }

    return _association; 
}

/*
 * generateCode
 */
string
CCIMClass::generateCode (void)
{
	string code;

	if (_association)
	{
		code = CSkeleton::instance ()->getContent ("ASSOCIATION");
	}
	else
	{
		code = CSkeleton::instance ()->getContent ("CLASS");
	}

	string ref_templates = getReferenceTemplates ();
	code = ::replaceStr (code, "%REFERENCE_TEMPLATES%", ref_templates);

	string template_classes = getTemplateClasses ();
	code = ::replaceStr (code, "%TEMPLATE_CLASSES%", template_classes);

	if (_association) {
		string enum_code = getEnumeratorCode ();
		code = ::replaceStr (code, "%ENUMERATORS%", enum_code);
	}

	string prop_code = getPropertyCode ();
	code = ::replaceStr (code, "%PROPERTIES%", prop_code);

	string method_code = getMethodCode ();
	code = ::replaceStr (code, "%METHODS%", method_code);

	code = ::replaceStr (code, "%INCLUDEREFS%", getIncludeRefCode ());

	code = ::replaceStr (code, "%ADDKEYS%", getAddKeysCode());

	/* Replace the variables */
	if (g_oalcs) {
		code = ::replaceStr (code, "%PROPERTY_GETTER%", getPropertyGetterFn());
		code = ::replaceStr (code, "%WRAPPER_DLL_NAME%", g_wrapper_dll_name); 
	}
	code = ::replaceStr (code, "%CLASSNAME%", _name); 
	code = ::replaceStr (code, "%NAMESPACE%", getNamespace()); 
	
	string _smallname = _name.c_str();
	std::transform(_smallname.begin(), _smallname.end(), _smallname.begin(),
::tolower );

	code = ::replaceStr (code, "%SMALLCLASSNAME%", _smallname);

	if (_superclass_name != "") 
	{ 
		if (_association)
		{
			string super_template = getSuperTemplateClasses ();
			if (super_template != "" && !g_oalcs)
			{
				code = ::replaceStr (code, "%SUPERCLASSNAME%", 
											_superclass_name + " <" + 
											getSuperTemplateClasses () + "> ");
			}
			else
			{
				code = ::replaceStr (code, "%SUPERCLASSNAME%", 
											_superclass_name);
			}
		}
		else
		{
			code = ::replaceStr (code, "%SUPERCLASSNAME%", _superclass_name); 
		}

		code = ::replaceStr (code, "%SUPERCLASS%", _superclass_name); 
	}
	else 						
	{ 
		if (g_oalcs) {
			code = ::replaceStr (code, "%SUPERCLASSNAME%", "OALBaseClass"); 
			code = ::replaceStr (code, "%SUPERCLASS%", "OALBaseClass"); 
		} else {
			code = ::replaceStr (code, "%SUPERCLASSNAME%", "COALObject"); 
			code = ::replaceStr (code, "%SUPERCLASS%", "COALObject"); 
		}
	}

	code = ::replaceStr (code, "%CLASSDESC%", _desc);
	code = ::replaceStr (code, "%ASSOCIATION_INCLUDES%", getAssociationIncludes());
	if (_association)
	{
		code = ::replaceStr (code, "%TEMPLATES%", getAssociationTemplates());
	}
	else
	{
		code = ::replaceStr (code, "%TEMPLATES%", "");
	}
	return code;
}


string
CCIMClass::getAssociationIncludes(void)
{
	string code;
	vector<CCIMReference> r = this->getReferences(); 
	vector<CCIMReference> sr = this->getSuperReferences();

	for (unsigned int i = 0; i < r.size (); i++) {
		code += "#include <dsdk/oal/" + r[i].getReferenceObject() + ".h>\r\n";
	}
	for (unsigned int i = 0; i < sr.size (); i++) {
		code += "#include <dsdk/oal/" + sr[i].getReferenceObject() + ".h>\r\n";
	}

	return code;
}	

/*
 * getAssociationTemplates
 */
string
CCIMClass::getAssociationTemplates(void)
{
	
	vector <string>_tmpl_obj;
	string args_obj;
	vector<CCIMReference> r = this->getReferences(); 
	vector<CCIMReference> sr = this->getSuperReferences();
	if (sr.size() > r.size()) r = sr;

	for (unsigned int i = 0; i < r.size (); i++) {
		string c = r[i].getReferenceObject();
		for ( unsigned int j = 0; j < g_classes.size(); j++ ) {
		    if (g_classes[j].getName() == r[i].getReferenceObject()) {
			if (g_classes[j].isAssociation()) {
			    c += g_classes[j].getAssociationTemplates();
			}
			break;
		    }
		}
		_tmpl_obj.push_back(c);
	}

	for (unsigned int i = 0; i < _tmpl_obj.size (); i++) {
		args_obj += (i == 0 ? "" : ", ") + _tmpl_obj[i];
	}

	return "<" + args_obj + ">";
}

/*
 *  do both templates have the same type
 */
bool
CCIMClass::TemplateTypesAreEqual(void)
{
	vector <string>_tmpl_obj;
	vector<CCIMReference> r = this->getReferences(); 
	vector<CCIMReference> sr = this->getSuperReferences();
	if (sr.size() > r.size()) r = sr;

	for (unsigned int i = 0; i < r.size (); i++) {
	    _tmpl_obj.push_back(r[i].getReferenceObject());

	    for ( unsigned int j = 0; j < g_classes.size(); j++ ) {
		if (g_classes[j].getName() == r[i].getReferenceObject()) {
		    if (g_classes[j].isAssociation()) {
			if (g_classes[j].TemplateTypesAreEqual())
			    return true;
		    }
		    break;
		}
	    }
	}

	if (_tmpl_obj.size () == 2) {
	    if (_tmpl_obj[0] == _tmpl_obj[1])
		return true;
	}

	CCIMClass* cc = getSuperClass();

	if (cc != NULL) {
	    return cc->TemplateTypesAreEqual();
	}

	return false;
}	

/*
 * set new keyword if parent class contains the same property
 */

string 
CCIMClass::setNewPropertyKeywordIfNeeded (string propname) {
	for (unsigned int i = 0; i < g_classes.size (); i++) {
		if (g_classes [i]._name == _superclass_name) {
			vector<CCIMProperty> props = g_classes[i].getProperties();
			for (unsigned int j = 0; j < props.size(); j++) {
				if (props[j].getName() == propname)
					return "new";
			}
			string ret = g_classes[i].setNewPropertyKeywordIfNeeded(propname);
			if (ret != "") 
				return ret;
		}
	}

	return "";
}

string 
CCIMClass::setNewReferenceKeywordIfNeeded (string refname) {
	for (unsigned int i = 0; i < g_classes.size (); i++) {
		if (g_classes [i]._name == _superclass_name) {
			vector<CCIMReference> refs = g_classes[i].getReferences();
			for (unsigned int j = 0; j < refs.size(); j++) {
				if (refs[j].getReferenceName() == refname)
					return "new";
			}
			string ret = g_classes[i].setNewReferenceKeywordIfNeeded(refname);
			if (ret != "") 
				return ret;
		}
	}

	return "";
}

/*
 * getPropertyCode
 */
string
CCIMClass::getPropertyCode (void)
{
	string props_code;
	for (unsigned int i = 0; i != _props.size (); i++)
	{
		string prop_code = _props [i].generateCode ();
		if (g_oalcs)
			prop_code = ::replaceStr (prop_code, "%NEW%", setNewPropertyKeywordIfNeeded(_props[i].getName()));
		props_code += prop_code;
	}

	for (unsigned int i = 0; i != _references.size (); i++)
	{
		string prop_code = _references [i].generateCode ();
		if (g_oalcs)
			prop_code = ::replaceStr (prop_code, "%NEW%", setNewReferenceKeywordIfNeeded(_references[i].getReferenceName()));
		props_code += prop_code;
	}

	return props_code;
}

/*
 * getAddKeysCode
 */
string
CCIMClass::getAddKeysCode (void)
{
	string code;
	for (unsigned int i = 0; i != _props.size (); i++)
	{
		if (_props [i].isKey ())
		{
			code += "\t\taddToKey (key, \"" + _props [i].getName () + "\");\n";
		}
	}

	return code;
}


/*
 * getMethodCode
 */
string
CCIMClass::getMethodCode (void)
{
	string method_code;
	for (unsigned int i = 0; i != _methods.size (); i++)
	{
		method_code += _methods [i].generateCode ();
	}

	return method_code;
}

/*
 * getReferenceTemplates
 */
string
CCIMClass::getReferenceTemplates (void)
{
	vector<string> rc = getReferenceClasses ();

	string ref_template;
	for (unsigned int i = 0; i < rc.size (); i++)
	{
		ref_template += "class T_" + rc[i];
		if (i != (rc.size () - 1)) { ref_template += ", ";  }
	}

	return ref_template;
}

/*
 * getTemplateClasses
 */
string
CCIMClass::getTemplateClasses (void)
{
	vector<string> rc = getReferenceClasses ();

	string code;
	for (unsigned int i = 0; i < rc.size (); i++)
	{
		code += "T_" + rc [i];
		if (i != (rc.size () - 1)) { code += ", ";  }
	}

	return code;
}


/*
 * getTemplateClasses
 */
string
CCIMClass::getSuperTemplateClasses (void)
{
	vector<string> rc = getSuperReferenceClasses ();

	string code;
	for (unsigned int i = 0; i < rc.size (); i++)
	{
		code += "T_" + rc [i];
		if (i != (rc.size () - 1)) { code += ", ";  }
	}

	return code;
}


/*
 * getReferenceClasses
 */
vector<string>
CCIMClass::getReferenceClasses (void)
{
	vector<string> ret = getSuperReferenceClasses ();

	for (unsigned int i = 0; i < _references.size (); i++)
	{
		unsigned int j;
		for (j = 0; j < ret.size (); j++)
		{
			if (ret [j] == _references [i].getReferenceName ())
			{
				break;
			}
		}
		if (j == ret.size ())
		{
			ret.push_back (_references [i].getReferenceName ());
		}
	}

	return ret;
}


vector<CCIMReference>
CCIMClass::getReferences(void) {

	if (_references.size() == 0) {
		/* Get the super class references */
		if (_superclass_name != "")
		{
			for (unsigned int i = 0; i < g_classes.size (); i++)
			{
				if (g_classes [i]._name == _superclass_name)
				{
					return g_classes [i].getReferences();
				}
			}
		}
	}
	return _references;
}

vector<CCIMReference>
CCIMClass::getSuperReferences(void) {

	if (_superclass_name != "")
	{
		for (unsigned int i = 0; i < g_classes.size (); i++)
		{
			if (g_classes [i]._name == _superclass_name)
			{
				return g_classes [i].getReferences();
			}
		}
	}

	return _references;
}

/*
 * getSuperReferenceClasses
 */
vector<string>
CCIMClass::getSuperReferenceClasses (void)
{
	vector<string> ret;

	/* Get the super class references */
	if (_superclass_name != "")
	{
		for (unsigned int i = 0; i < g_classes.size (); i++)
		{
			if (g_classes [i]._name == _superclass_name)
			{
				ret = g_classes [i].getReferenceClasses ();
				break;
			}
		}
	}

	return ret;
}

/*
 * getEnumeratorCode
 */
string
CCIMClass::getEnumeratorCode (void)
{
	string enum_code;
	vector<string> rc = getReferenceClasses ();
	vector<CCIMReference> r = this->getReferences(); 
	vector<CCIMReference> sr = this->getSuperReferences();
	if (r.size() < sr.size()) r = sr;

	for (unsigned int i = 0; i != rc.size (); i++)
	{
		for (unsigned int j = 0; j != rc.size (); j++)
		{
			if (j == i) { continue; }
  
  			string code = CSkeleton::instance ()->getContent ("ENUMERATOR");
			code = ::replaceStr (code, "%RESULT%", rc [i]);
			code = ::replaceStr (code, "%REFERED%", rc [j]);
			code = ::replaceStr (code, "%TEMPLATE_CLASSES%", getTemplateClasses ());

			if (r.size() > j)
				code = ::replaceStr (code, "%REFERED_OBJ%", r[j].getReferenceObject());
			if (r.size() > i)
				code = ::replaceStr (code, "%RESULT_OBJ%", r[i].getReferenceObject());

			enum_code += code;
		}
	}

	string pushBackProps = "\r\n";
	vector<string> pbp = this->getPropertyNames();

	for (unsigned int i = 0; i != pbp.size(); i++) {
	    pushBackProps += "\t\t\t\tprops.push_back (\"" + pbp[i] + "\");\r\n";
	}

	enum_code = ::replaceStr (enum_code, "%ENUM_PUSH_BACK_PROPS%", pushBackProps);
	return enum_code;
}


/* 
 * getIncludeRefCode
 */
string 
CCIMClass::getIncludeRefCode (void)
{
	string code;
	for (unsigned int i = 0; i != _include_ref.size (); i++)
	{
		code += "#include <dsdk/oal/" + _include_ref [i] + ".h>\r\n";		
	}
	return code;
}

string 
CCIMClass::getPropertyGetterFnHelper (string data_type, bool isArray, string switch_code) {
	string code;
	code += "\t\tpublic override " + ConvertToCSDataType(data_type);
	
	if (isArray) 
		code += "[]";

	code += " getProperty(String Name) {\r\n";
	code += "\r\n";
	code += "\t\t	switch(Name) {\r\n";
	code += switch_code;
	code += "\t\t		default: \r\n";
	code += "\t\t			break;\r\n";
	code += "\t\t	} \r\n";
	code += "\t\t	\r\n";
	if (isArray) {
		code += "\t\t	return new " + ConvertToCSDataType(data_type) + "[0];\r\n";
	} else {
		code += "\t\t	return Convert.To" + ConvertToCSDataType(data_type) + "(\"\");\r\n";
	}
	code += "\t\t} \r\n";
	code += "\r\n";

	return code;
}

	vector<string> prop_names;
	vector<string> prop_types;
	vector<bool> prop_is_array;
	vector<string> prop_typ_code;


int 
CCIMClass::analyzeProps (vector<CCIMProperty> props) {

		for (unsigned int i = 0; i != props.size (); i++) {
			if (true || setNewPropertyKeywordIfNeeded(props[i].getName()) == "new") {
				/* find right chain... */
				int chain = -1;
				for (unsigned int j = 0; j != prop_types.size (); j++) {
					if (prop_types[j] == props[i].getDataType() &&
						prop_is_array[j] == props[i].isArray()) {
						chain = j;
						break;
					}
				}
				
				if (chain == -1) {
					/* no chain found -> generate new one for this data type */
					chain = prop_types.size();
					prop_types.push_back(props[i].getDataType());
					prop_typ_code.push_back("");
					prop_is_array.push_back(props[i].isArray());
				} else {
					/* argh, filter duplicated entries */
					for (unsigned int j = 0; j != prop_names.size (); j++) {
						if (prop_names[j] == props[i].getName()) {
							chain = -1;
							break;
						}
					}
				}

				if (chain >= 0) {
					prop_names.push_back(props[i].getName());
					prop_typ_code[chain] += "\t\t		case \"" + props[i].getName() + "\":\r\n";
					//prop_typ_code[chain] += "\t\t			return get"+ props[i].getName() +"();\r\n";
					prop_typ_code[chain] += "\t\t			return new Object[] { get"+ props[i].getName() +"() };\r\n";
				}
			}
		}
		return 0;
}

int
CCIMClass::getPropertyGetterFnRec (string classname) {

	for (int k = 0; k < g_classes.size(); k++) {
		if (g_classes [k]._name == classname) {
			analyzeProps(g_classes[k].getProperties());
			getPropertyGetterFnRec(g_classes[k]._superclass_name);
		}
	}
	return 0;
}

string 
CCIMClass::getPropertyGetterFn (void) {
	string code;

	prop_names.clear();
	prop_types.clear();
	prop_is_array.clear();
	prop_typ_code.clear();

	getPropertyGetterFnRec(_name);

	for (unsigned int i = 0; i != prop_types.size(); i++) {
		code += prop_typ_code[i];
	}

	return getPropertyGetterFnHelper("object", true, code);
}

string 
CCIMClass::getNamespace (void) 
{
	if (getUMLPkgPath () == "CIM::Interop")
	{
		return "client->getInteropNS ()";
	}
	else
	{
		return "client->getImplementationNS ()";
	}
}
