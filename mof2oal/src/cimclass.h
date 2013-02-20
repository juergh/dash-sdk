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

#ifndef __MOF2CPP_CIMCLASS_H__
#define __MOF2CPP_CIMCLASS_H__
#include <string>
#include <vector>
#include "cimproperty.h"
#include "cimreference.h"
#include "cimmethod.h"

using std::string;
using std::vector;

/**
 * @class CCIMClass
 * @brief A class holding a CIM Class information.
 */
class CCIMClass
{
public:
	/**
	 * Constructor
	 */
	CCIMClass (string _name, string _superclass_name);

public:
	/**
	 * Returns the name of this class
	 */
	string getName (void) { return _name; }

	/**
	 * Adds a description to the class.
	 */
	void addDesc (string desc);

	/**
	 * Adds a property to the class.
	 */
	void addProperty (const CCIMProperty& prop);

	/**
	 * Adds a method to the class.
	 */
	void addMethod (const CCIMMethod& method);

	/**
	 * Adds a reference to the class.
	 */
	void addReference (const CCIMReference& reference);

public:
	/**
	 * Sets this class to be an association.
	 */
	void setAssociation (void) { _association = true; }

	/**
	 * return true if this class is an association.
	 */
	bool isAssociation (void);

	/**
	 * Sets UMP Package path for this class
	 */
	void setUMLPkgPath (string path);
	
	/**
	 * Gets UMP Package path for this class
	 */
	string getUMLPkgPath (void);

	/**
 	 * Adds include references to this class
 	 */
 	void addIncludeRef (const vector<string>& ref) { _include_ref = ref; }
 
	/**
	 * Gets the key properties of this class
	 */
	vector<string> getKeyPropertyNames (void);

	/**
	 * Gets the properties of this class
	 */
	vector<string> getPropertyNames (void);

	/**
	 * Gets the super class name for this class
	 */
	string getSuperClassName (void);

	/**
	 * Gets the super class name
	 */
	CCIMClass*
	getSuperClass(void);


public:
	/**
	 * Generates the code
	 */
	virtual string generateCode (void);

	vector<string> getReferenceClasses 		(void);
	vector<string> getSuperReferenceClasses (void);
	vector<CCIMReference> getReferences		(void);
	vector<CCIMReference> getSuperReferences (void);
	string setNewReferenceKeywordIfNeeded(string refpname);
	string setNewPropertyKeywordIfNeeded(string propname);

	vector<CCIMProperty> getProperties (void) { return _props; }
	bool TemplateTypesAreEqual        (void);

private:
	string getPropertyCode 		 (void);
	string getMethodCode 		 (void);
	string getEnumeratorCode 	 (void);
	string getReferenceTemplates     (void);
	string getIncludeRefCode	 (void);
	string getAssociationTemplates	 (void);
	string getAssociationIncludes	 (void);
	string getTemplateClasses 	 (void);
	string getSuperTemplateClasses 	 (void);
	string getAddKeysCode 			(void);
	string getPropertyGetterFn (void);
	string getPropertyGetterFnHelper(string data_type, bool isArray, string switch_code);
	string getNamespace              (void);
	int analyzeProps (vector<CCIMProperty> props);
	int getPropertyGetterFnRec (string classname);

private:
	string					_name;
	string					_superclass_name;
	string					_desc;
	vector<CCIMProperty>	_props;
	vector<CCIMMethod>		_methods;
	vector<CCIMReference>	_references;
	bool					_association;
	vector<string>			_include_ref;
	string					_uml_pkg_path;
};

#endif /* __MOF2CPP_CIMCLASS_H__ */

