/*
 * License Agreement 
 *
 * Copyright (c) 2007, 2008, 2009 Advanced Micro Devices Inc.
 *
 * All rights reserved.
 *
 * Redistribution and use in any form of this material and any product thereof including
 * software in source or binary forms, along with any related documentation, with or 
 * without modification ("this material"), is permitted provided that the following 
 * conditions are met:
 *
 *    + Redistributions of source code of any software must retain the above copyright 
 *      notice and all terms of this license as part of the code.
 *
 *    + Redistributions in binary form of any software must reproduce the above copyright 
 *      notice and all terms of this license in any related documentation and/or other 
 *      materials.
 *
 *    + Neither the names nor trademarks of Advanced Micro Devices, Inc. or any copyright 
 *      holders or contributors may be used to endorse or promote products derived from 
 *      this material without specific prior written permission.
 *
 *    + Notice about U.S. Government restricted rights: This material is provided with ?
 *      RESTRICTED RIGHTS.? Use, duplication or disclosure by the U.S. Government is subject 
 *      to the full extent of restrictions set forth in FAR52.227 and DFARS252.227 et seq., 
 *      or any successor or applicable regulations. Use of this material by the U.S. 
 *      Government constitutes acknowledgment  of  the  proprietary rights of 
 *      Advanced Micro Devices, Inc. and any copyright holders and contributors. 
 *
 *    + In no event shall anyone redistributing or accessing or using this material 
 *      commence or participate in any arbitration or legal action relating to this 
 *      material against Advanced Micro Devices, Inc. or any copyright holders or contributors. 
 *      The foregoing shall survive any expiration or termination of this license or any 
 *      agreement or access or use related to this material.  
 *
 *    + ANY BREACH OF ANY TERM OF THIS LICENSE SHALL RESULT IN THE IMMEDIATE REVOCATION 
 *      OF ALL RIGHTS TO REDISTRIBUTE, ACCESS OR USE THIS MATERIAL. 
 *
 * THIS MATERIAL IS PROVIDED BY ADVANCED MICRO DEVICES, INC. AND ANY COPYRIGHT HOLDERS AND 
 * CONTRIBUTORS "AS IS" IN ITS CURRENT CONDITION AND WITHOUT ANY REPRESENTATIONS, GUARANTEE, 
 * OR WARRANTY OF ANY KIND OR IN ANY WAY RELATED TO SUPPORT, INDEMNITY, ERROR FREE OR 
 * UNINTERRUPTED OPERATION, OR THAT IT IS FREE FROM DEFECTS OR VIRUSES.  ALL OBLIGATIONS 
 * ARE HEREBY DISCLAIMED - WHETHER EXPRESS, IMPLIED, OR STATUTORY - INCLUDING, BUT NOT 
 * LIMITED TO, ANY IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY, FITNESS FOR A PARTICULAR 
 * PURPOSE, ACCURACY, COMPLETENESS, OPERABILITY, QUALITY OF SERVICE, OR NON-INFRINGEMENT. 
 * IN NO EVENT SHALL ADVANCED MICRO DEVICES, INC. OR ANY COPYRIGHT HOLDERS OR CONTRIBUTORS 
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, PUNITIVE, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, REVENUE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED 
 * OR BASED ON ANY THEORY OF LIABILITY ARISING IN ANY WAY RELATED TO THIS MATERIAL, EVEN IF 
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. THE ENTIRE AND AGGREGATE LIABILITY OF ADVANCED 
 * MICRO DEVICES, INC. AND ANY COPYRIGHT HOLDERS AND CONTRIBUTORS SHALL NOT EXCEED TEN DOLLARS 
 * (US $10.00). ANYONE REDISTRIBUTING OR ACCESSING OR USING THIS MATERIAL ACCEPTS THIS 
 * ALLOCATION OF RISK AND AGREES TO RELEASE ADVANCED MICRO DEVICES, INC. AND ANY COPYRIGHT 
 * HOLDERS AND CONTRIBUTORS FROM ANY AND ALL LIABILITIES, OBLIGATIONS, CLAIMS, OR DEMANDS IN 
 * EXCESS OF TEN DOLLARS (US $10.00). THE FOREGOING ARE ESSENTIAL TERMS OF THIS LICENSE AND, 
 * IF ANY OF THESE TERMS ARE CONSTRUED AS UNENFORCEABLE, FAIL IN ESSENTIAL PURPOSE, OR BECOME 
 * VOID OR DETRIMENTAL TO ADVANCED MICRO DEVICES, INC. OR ANY COPYRIGHT HOLDERS OR CONTRIBUTORS 
 * FOR ANY REASON, THEN ALL RIGHTS TO REDISTRIBUTE, ACCESS OR USE THIS MATERIAL SHALL TERMINATE 
 * IMMEDIATELY. MOREOVER, THE FOREGOING SHALL SURVIVE ANY EXPIRATION OR TERMINATION OF THIS 
 * LICENSE OR ANY AGREEMENT OR ACCESS OR USE RELATED TO THIS MATERIAL. 
 *
 * NOTICE IS HEREBY PROVIDED, AND BY REDISTRIBUTING OR ACCESSING OR USING THIS MATERIAL SUCH NOTICE 
 * IS ACKNOWLEDGED, THAT THIS MATERIAL MAY BE SUBJECT TO RESTRICTIONS UNDER THE LAWS AND REGULATIONS 
 * OF THE UNITED STATES OR OTHER COUNTRIES, WHICH INCLUDE BUT ARE NOT LIMITED TO, U.S. EXPORT 
 * CONTROL LAWS SUCH AS THE EXPORT ADMINISTRATION REGULATIONS AND NATIONAL SECURITY CONTROLS AS 
 * DEFINED THEREUNDER, AS WELL AS STATE DEPARTMENT CONTROLS UNDER THE U.S. MUNITIONS LIST. THIS 
 * MATERIAL MAY NOT BE USED, RELEASED, TRANSFERRED, IMPORTED, EXPORTED AND/OR RE-EXPORTED IN ANY 
 * MANNER PROHIBITED UNDER ANY APPLICABLE LAWS, INCLUDING U.S. EXPORT CONTROL LAWS REGARDING 
 * SPECIFICALLY DESIGNATED PERSONS, COUNTRIES AND NATIONALS OF COUNTRIES SUBJECT TO NATIONAL SECURITY 
 * CONTROLS. MOREOVER, THE FOREGOING SHALL SURVIVE ANY EXPIRATION OR TERMINATION OF ANY LICENSE 
 * OR AGREEMENT OR ACCESS OR USE RELATED TO THIS MATERIAL. 
 *
 * This license forms the entire agreement regarding the subject matter hereof and supersedes all 
 * proposals and prior discussions and writings between the parties with respect thereto. This 
 * license does not affect any ownership, rights, title, or interest in, or relating to, this 
 * material. No terms of this license can be modified or waived, and no breach of this license 
 * can be excused, unless done so in a writing signed by all affected parties. Each term of this 
 * license is separately enforceable. If any term of this license is determined to be or becomes 
 * unenforceable or illegal, such term shall be reformed to the minimum extent necessary in order 
 * for this license to remain in effect in accordance with its terms as modified by such reformation. 
 * This license shall be governed by and construed in accordance with the laws of the State of 
 * Texas without regard to rules on conflicts of law of any state or jurisdiction or the United 
 * Nations Convention on the International Sale of Goods. All disputes arising out of this license 
 * shall be subject to the jurisdiction of the federal and state courts in Austin, Texas, and all 
 * defenses are hereby waived concerning personal jurisdiction and venue of these courts.
 */
/**
 * ciminstance.h
 * A Class representing a CIM Instance.
 */
#include <dsdk/cim/ciminstance.h>
#include <cmci/sfcc/sfcclient.h>
#include <dsdk/cim/cimconversion.h>
#include <dsdk/cim/cimclasskeys.h>

using namespace dsdk;

/* 
 * Constructor
 */
CCIMInstance::CCIMInstance (const CCIMObjectPath& op) : _inst (0), 
													    _ref_count (0)
{
	/* Create a new low level instance based on the object path */
	CMPIStatus status;
	_inst = native_new_CMPIInstance 
					((CMPIObjectPath*) op.getLowLevelObject (),
					 &status);
	ECIMError::checkThrowCIMStatus (status);

	_op				= op.clone ();
	_op_set			= true;
	_ref_count 		= new int (1);
	_auto_release	= true;
	_null_inst		= false;
}

/* 
 * toCCIMInstance
 */
CCIMInstance
CCIMInstance::toCCIMInstance (CMPIInstance* inst, bool auto_release)
{
	CCIMInstance ci;
	ci._op_set		 = false;
	ci._op		     = 0;
	ci._inst 	  	 = inst;
	ci._ref_count 	 = new int (1);
	ci._auto_release = auto_release;
	ci._null_inst	 = false;

	return ci;
}

/*
 * Copy constructor
 */
CCIMInstance::CCIMInstance (const CCIMInstance& ci) throw (ECIMError)
{
	if (ci._null_inst) 
	{ 
		_null_inst = true;
		_op_set    = false;
	}
	else
	{
		_op_set		  = ci._op_set;
		if (_op_set)  { _op = ci._op; /* new CCIMObjectPath (*(ci._op)); */ }
		else		  { _op = 0; }

		_inst		  = ci._inst;
		_ref_count	  = ci._ref_count;
		_auto_release = ci._auto_release;
		_null_inst	  = ci._null_inst;
		(*_ref_count)++;
	}
}

/*
 * Assignment operator.
 */
const CCIMInstance& 
CCIMInstance::operator = (const CCIMInstance& rhs) throw (ECIMError)
{
	if (rhs._null_inst)
	{
		_null_inst = true;
		_op_set    = false;	
	}
	else
	{
		if (!_null_inst)
		{
			(*_ref_count)--;
			if (0 == *_ref_count)
			{
				delete _ref_count;
				if (_op_set) { delete _op; }

				if (_auto_release)
				{
					CMPIStatus status = _inst->ft->release (_inst);
					ECIMError::checkThrowCIMStatus (status);
				}
			}
		}

		_op_set		  = rhs._op_set;
		if (_op_set)  { _op = rhs._op; /* new CCIMObjectPath (*(rhs._op)); */ }
		else		  { _op = 0; }

		_inst 		  = rhs._inst;
		_ref_count	  = rhs._ref_count;
		_auto_release = rhs._auto_release;
		_null_inst	  = rhs._null_inst;
		(*_ref_count)++;
	}
	return *this;
}

/*
 * Destructor
 */
CCIMInstance::~CCIMInstance ()
{
	if (_null_inst) { return; }

	(*_ref_count)--;
	if (0 == *_ref_count) 
	{
		if (_auto_release) { _inst->ft->release (_inst); }
		if (_op_set) 	   { delete _op; }
		delete _ref_count;
	}
}

/*
 * clone
 */
CCIMInstance* 
CCIMInstance::clone (void) throw (ECIMError)
{
	CCIMInstance* ci = new CCIMInstance ();
	CMPIStatus	   status;

	ci->_inst = _inst->ft->clone (_inst, &status);
	ECIMError::checkThrowCIMStatus (status);

	ci->_op_set		  	= _op_set;
	if (ci->_op_set) { _op = new CCIMObjectPath (*_op); }
	else			 { _op = 0; }

	ci->_ref_count 		= new int (1);
	ci->_auto_release	= true;	/* Cloned objects are not exact replica always.
								   This needs to be done here, because there 
								   will be no other way to release the CMPI 
								   object otherwise. */
	ci->_null_inst		= false;

	return ci;
}

/*
 * getProperty
 */
CCIMData 
CCIMInstance::getProperty (const string& name) const throw (ECIMError)
{
	CMPIStatus status;
	CMPIData cmpi_prop = _inst->ft->getProperty (_inst, name.c_str (), 
												 &status);
	ECIMError::checkThrowCIMStatus (status);

	return CCIMData::toCCIMData (cmpi_prop, false);	
}

/*
 * getPropertyCount
 */
unsigned int 
CCIMInstance::getPropertyCount (void) const throw (ECIMError)
{
	CMPIStatus 		status;
	unsigned int 	count;

	count = _inst->ft->getPropertyCount (_inst, &status);
	ECIMError::checkThrowCIMStatus (status);

	return count;
}

/*
 * getPropertyAt
 */
CCIMData 
CCIMInstance::getPropertyAt (unsigned int index, string* name) 
													const throw (ECIMError)
{
	CMPIStatus 	status;
	CMPIString*	cmpi_name;

	CMPIData cmpi_prop = _inst->ft->getPropertyAt (_inst, index, &cmpi_name, 
																	&status);
	ECIMError::checkThrowCIMStatus (status);

	*name = cmpi_name->ft->getCharPtr (cmpi_name, &status);
	if (status.rc != CMPI_RC_OK) { cmpi_name->ft->release (cmpi_name); }
	ECIMError::checkThrowCIMStatus (status);

	status = cmpi_name->ft->release (cmpi_name);
	ECIMError::checkThrowCIMStatus (status);

	return CCIMData::toCCIMData (cmpi_prop, false);	
}

/**
 * setProperty 
 */
void
CCIMInstance::setProperty (const string& name, const CCIMValue& value) throw (ECIMError)
{
	CMPIStatus status = _inst->ft->setProperty (
									_inst, 
									name.c_str (),
									(CMPIValue*) value.getLowLevelValue (),
									value.getLowLevelType ());
	ECIMError::checkThrowCIMStatus (status);
}


/*
 * getQualifier
 */
CCIMData 
CCIMInstance::getQualifier (const string& name) const throw (ECIMError)
{
	CMPIStatus status;
	CMPIData cmpi_qual = _inst->ft->getQualifier (_inst, 
												  name.c_str (), 
												  &status);
	ECIMError::checkThrowCIMStatus (status);

	return CCIMData::toCCIMData (cmpi_qual, false);	
}

/**
 * setPropertyFilter
 */
void 
CCIMInstance::setPropertyFilter (const vector<string>& props, 
								 const vector<string>& keys) throw (ECIMError)
{
	char** prop_list;
	char** key_list;

	/** Fill in the property list */
	if (props.size () != 0)
	{
		prop_list = new char* [props.size () + 1];
		for (size_t i = 0; i != props.size (); i++)
		{
			prop_list [i] = (char*) props [i].c_str ();
		}
		prop_list [props.size ()] = NULL;
	}
	else
	{
		prop_list = NULL;
	}

	/** Fill in the key list */
	if (keys.size () != 0)
	{
		key_list = new char* [keys.size () + 1];
		for (size_t i = 0; i != keys.size (); i++)
		{
			key_list [i] = (char*) keys [i].c_str ();
		}
		key_list [keys.size ()] = NULL;
	}
	else
	{
		key_list = NULL;
	}

	CMPIStatus status = _inst->ft->setPropertyFilter (_inst, 
													  prop_list,
													  key_list);
	if (NULL != prop_list) { delete [] prop_list; }
	if (NULL != key_list)  { delete [] key_list;  }
	ECIMError::checkThrowCIMStatus (status);
}

/*
 * getQualifierCount
 */
unsigned int 
CCIMInstance::getQualifierCount (void) const throw (ECIMError)
{
	CMPIStatus 		status;
	unsigned int 	count;

	count = _inst->ft->getQualifierCount (_inst, &status);
	ECIMError::checkThrowCIMStatus (status);

	return count;
}

/*
 * getQualifierAt
 */
CCIMData 
CCIMInstance::getQualifierAt (unsigned int index, string* name) 
														const throw (ECIMError)
{
	CMPIStatus 	status;
	CMPIString*	cmpi_name;

	CMPIData cmpi_qual = _inst->ft->getQualifierAt (_inst, index, &cmpi_name, 
																	&status);
	ECIMError::checkThrowCIMStatus (status);

	*name = cmpi_name->ft->getCharPtr (cmpi_name, &status);
	if (status.rc != CMPI_RC_OK) { cmpi_name->ft->release (cmpi_name); }
	ECIMError::checkThrowCIMStatus (status);

	status = cmpi_name->ft->release (cmpi_name);
	ECIMError::checkThrowCIMStatus (status);

	return CCIMData::toCCIMData (cmpi_qual, false);	
}

/* 
 * getPropertyQualifier
 */
CCIMData 
CCIMInstance::getPropertyQualifier (const string& pname, const string& qname)
{
	CMPIStatus status;
	CMPIData cmpi_qual = _inst->ft->getPropertyQualifier (_inst, 
														  pname.c_str (), 
														  qname.c_str (),
														  &status);
	ECIMError::checkThrowCIMStatus (status);

	return CCIMData::toCCIMData (cmpi_qual, false);	
}

/*
 * getPropertyQualifierCount
 */
unsigned int 
CCIMInstance::getPropertyQualifierCount (const string& pname) const throw (ECIMError)
{
	CMPIStatus 		status;
	unsigned int 	count;

	count = _inst->ft->getPropertyQualifierCount (_inst, 
												  pname.c_str (), 
												  &status);
	ECIMError::checkThrowCIMStatus (status);

	return count;
}

/*
 * getPropertyQualifierAt
 */
CCIMData 
CCIMInstance::getPropertyQualifierAt (const string& pname, unsigned int index, 
											string* qname) const throw (ECIMError)
{
	CMPIStatus 	status;
	CMPIString*	cmpi_qname;

	CMPIData cmpi_qual = _inst->ft->getPropertyQualifierAt (_inst,
															pname.c_str (),
														    index, 
														    &cmpi_qname, 
														    &status);
	ECIMError::checkThrowCIMStatus (status);

	*qname = cmpi_qname->ft->getCharPtr (cmpi_qname, &status);
	if (status.rc != CMPI_RC_OK) { cmpi_qname->ft->release (cmpi_qname); }
	ECIMError::checkThrowCIMStatus (status);

	status = cmpi_qname->ft->release (cmpi_qname);
	ECIMError::checkThrowCIMStatus (status);

	return CCIMData::toCCIMData (cmpi_qual, false);	
}

/*
 * getObjectPath
 */
CCIMObjectPath 
CCIMInstance::getObjectPath (void) const throw (ECIMError)
{
	if (_op_set) { return *_op; }
	else		 
	{ 
		CMPIStatus status;
		CMPIObjectPath* cmpi_path = _inst->ft->getObjectPath (_inst, &status);
		ECIMError::checkThrowCIMStatus (status);
	
		return CCIMObjectPath::toCCIMObjectPath (cmpi_path);
	}
}

/*
 * setObjectPath
 */
void 
CCIMInstance::setObjectPath (const CCIMObjectPath& op)
{
	if (_op_set) { delete _op; }

	_op 	= op.clone ();
	_op_set	= true;
}

/*
 * makeInstanceObjectPath
 */
void
dsdk::makeInstanceObjectPath (CCIMInstance* inst, const string& classname)
{
	CMPIStatus status;

	if (inst->_op_set) { return; } 

	/* get the class keys */
	vector <string> keys;
	keys = getCIMClassKeys (classname);
	if (keys.size () == 0) 
	{ 
		return; 
	}

	CMPIObjectPath* op = inst->_inst->ft->getObjectPath (inst->_inst, &status);
	ECIMError::checkThrowCIMStatus (status);

	inst->_op = new CCIMObjectPath (CCIMObjectPath::toCCIMObjectPath (op));

	/* get the keys values and add it to object path */
	for (size_t i = 0; i < keys.size(); i++)
	{
		try {
			CCIMData data = inst->getProperty (keys [i]);
			inst->_op->addKey (keys [i], data.getValue());
		}
		catch (...) 
		{
			delete inst->_op;
			return; 
		}
	}

	/* set it to true only after we are able to get all property 
	   value and add it to object path */
	inst->_op_set = true;

	return;
}

//DSDK_DEFINE_KEY_CLASS (CCIMInstance);

