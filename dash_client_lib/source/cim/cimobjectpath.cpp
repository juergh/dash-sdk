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
 * objectpath.cpp
 * A class representing the CIM Object Path as defined by DMTF CIM 
 * infrastructure specification. (DSP004)
 */
#include <dsdk/cim/cimobjectpath.h>
#include <dsdk/cim/cimconversion.h>
#include <dsdk/cim/ciminstance.h>
#include <cmci/sfcc/sfcclient.h>

using namespace dsdk;

/*------------ CCIMObjectPath -------------------*/

/*
 * Constructors
 */
CCIMObjectPath::CCIMObjectPath (const string& ns, const string& object_name) 
														throw (ECIMError) : 
															_path (0)
{
	/* Create the underlying low level object path */
	CMPIStatus	status;
	_path = newCMPIObjectPath ((ns == "") ? NULL : ns.c_str (), 
							   (object_name == "") ? NULL : object_name.c_str (),
							   &status);
	ECIMError::checkThrowCIMStatus (status);
	_ref_count 		= new int (1);
	_auto_release	= true;
	_null_inst		= false;
}

CCIMObjectPath::CCIMObjectPath (const string& ns, const string& objectname, 
								const map<string, CCIMValue>& keys)
													throw (ECIMError) : 
														_path (0)
{
	/* Create the underlying low level object path */
	CMPIStatus	status;
	_path = newCMPIObjectPath ((ns == "") ? NULL : ns.c_str (), 
							   (objectname == "") ? NULL : objectname.c_str (),
							   &status);
	ECIMError::checkThrowCIMStatus (status);
	_ref_count 		= new int (1);
	_auto_release	= true;
	_null_inst		= false;

	/*
	 * Add the keys
	 */
	map<string, CCIMValue>::const_iterator i;
	for (i = keys.begin (); i != keys.end (); i++)
	{
		this->addKey ((*i).first, (*i).second);
	}
}

CCIMObjectPath::CCIMObjectPath (const string& hostname, 
								const string& ns, 
								const string& objectname,
								const map<string, CCIMValue>& keys)
													throw (ECIMError) : 
													_path (0)
{
	/* Create the underlying low level object path */
	CMPIStatus	status;
	_path = newCMPIObjectPath ((ns == "") ? NULL : ns.c_str (), 
							   (objectname == "") ? NULL : objectname.c_str (),
							   &status);
	ECIMError::checkThrowCIMStatus (status);
	_ref_count 		= new int (1);
	_auto_release	= true;
	_null_inst		= false;

	/*
	 * Set the host name
	 */
	this->setHostName (hostname);

	/*
	 * Add the keys
	 */
	map<string, CCIMValue>::const_iterator i;
	for (i = keys.begin (); i != keys.end (); i++)
	{
		this->addKey ((*i).first, (*i).second);
	}
}

/*
 * toCCIMObjectPath
 */
CCIMObjectPath 
CCIMObjectPath::toCCIMObjectPath (CMPIObjectPath* path, bool auto_release)
{
	CCIMObjectPath op;
	op._path 			= path;
	op._ref_count 		= new int (1);
	op._auto_release 	= auto_release;
	op._null_inst		= false;

	return op;
}


/*
 * Copy constructor 
 */
CCIMObjectPath::CCIMObjectPath (const CCIMObjectPath& op) throw (ECIMError) : 
														_path (0)
{
	if (op._null_inst) 
	{
		_null_inst		= true;
	}
	else
	{
		_path	  	  = op._path;
		_ref_count 	  = op._ref_count;
		_auto_release = op._auto_release;
		_null_inst	  = op._null_inst;
		(*_ref_count)++;
	}
}

/* 
 * Assignment operator 
 */
const CCIMObjectPath& 
CCIMObjectPath::operator = (const CCIMObjectPath& rhs) throw (ECIMError)
{
	if (rhs._null_inst)
	{
		_null_inst		= true;
	}
	else
	{
		if (!_null_inst)
		{
			(*_ref_count)--;
			if (0 == *_ref_count) 
			{ 
				if (_auto_release)
				{
					CMPIStatus status = _path->ft->release (_path); 
					ECIMError::checkThrowCIMStatus (status);
				}
				delete _ref_count;
			}
		}

		_ref_count = rhs._ref_count;
		_path	   = rhs._path;
		_null_inst = false;
		(*_ref_count)++;
	}

	return *this;
}

/* 
 * Destructor 
 */
CCIMObjectPath::~CCIMObjectPath ()
{
	if (_null_inst) { return; }

	(*_ref_count)--;
	if (0 == *_ref_count) 
	{
		if (_auto_release)
		{
			CMPIStatus status = _path->ft->release (_path);
			ECIMError::checkThrowCIMStatus (status);
		}
		delete _ref_count;
	}
}

/*
 * setNameSpace
 */
void 
CCIMObjectPath::setNameSpace (const string& ns) throw (ECIMError)
{
	CMPIStatus status;
	status = _path->ft->setNameSpace (_path, ns.c_str ());
	ECIMError::checkThrowCIMStatus (status);
}

/*
 * getNameSpace
 */
string 
CCIMObjectPath::getNameSpace (void) const throw (ECIMError)
{
	CMPIStatus 	status;
	CMPIString* cmpi_ns;
	string      ns;

	cmpi_ns = _path->ft->getNameSpace (_path, &status);
	ECIMError::checkThrowCIMStatus (status);

	if (cmpi_ns->ft->getCharPtr (cmpi_ns, &status)) 
	{
		ns = string (cmpi_ns->ft->getCharPtr (cmpi_ns, &status));
	}
	DSDK_RELEASE_ON_FAIL (status, cmpi_ns);
	ECIMError::checkThrowCIMStatus (status);

	status = cmpi_ns->ft->release (cmpi_ns);
	ECIMError::checkThrowCIMStatus (status);

	return ns;
}

/*
 * setHostName
 */
void 
CCIMObjectPath::setHostName (const string& hn) throw (ECIMError)
{
	CMPIStatus status;
	status = _path->ft->setHostname (_path, hn.c_str ());
	ECIMError::checkThrowCIMStatus (status);
}

/* 
 * getHostName
 */
string 
CCIMObjectPath::getHostName (void) const throw (ECIMError)
{
	CMPIStatus 	status;
	CMPIString* cmpi_hn;

	cmpi_hn = _path->ft->getHostname (_path, &status);
	ECIMError::checkThrowCIMStatus (status);

	string hn = string (cmpi_hn->ft->getCharPtr (cmpi_hn, &status));
	DSDK_RELEASE_ON_FAIL (status, cmpi_hn);
	ECIMError::checkThrowCIMStatus (status);

	status = cmpi_hn->ft->release (cmpi_hn);
	ECIMError::checkThrowCIMStatus (status);

	return hn;
}

/*
 * setClassName
 */
void 
CCIMObjectPath::setClassName (const string& cn) throw (ECIMError)
{
	CMPIStatus status;
	status = _path->ft->setClassName (_path, cn.c_str ());
	ECIMError::checkThrowCIMStatus (status);
}

/*
 * getClassName
 */
string 
CCIMObjectPath::getClassName (void) const throw (ECIMError)
{
	CMPIStatus 	status;
	CMPIString* cmpi_cn;

	cmpi_cn = _path->ft->getClassName (_path, &status);
	ECIMError::checkThrowCIMStatus (status);

	string cn = string (cmpi_cn->ft->getCharPtr (cmpi_cn, &status));
	DSDK_RELEASE_ON_FAIL (status, cmpi_cn);
	ECIMError::checkThrowCIMStatus (status);

	status = cmpi_cn->ft->release (cmpi_cn);
	ECIMError::checkThrowCIMStatus (status);

	return cn;
}

/*
 * addKey
 */
void 
CCIMObjectPath::addKey (const string& name, 
						const CCIMValue& value) throw (ECIMError)
{
	CMPIStatus status;

	status = _path->ft->addKey (_path, name.c_str (), 
							    (CMPIValue*) ((CCIMValue&) value).getLowLevelValue (), 
								((CCIMValue&) value).getLowLevelType ());
	ECIMError::checkThrowCIMStatus (status);
}

/*
 * getKey
 */
CCIMData 
CCIMObjectPath::getKey (const string& name) const throw (ECIMError)
{
	CMPIStatus status;
	CCIMData data (_path->ft->getKey (_path, name.c_str (), &status));
	ECIMError::checkThrowCIMStatus (status);

	return data;
}

/*
 * getKeyCount
 */
unsigned int 
CCIMObjectPath::getKeyCount (void) const throw (ECIMError)
{
	CMPIStatus 		status;
	unsigned int 	ct;

	ct = _path->ft->getKeyCount (_path, &status);
	ECIMError::checkThrowCIMStatus (status);

	return ct;
}

/*
 * getKeyAt
 */
CCIMData 
CCIMObjectPath::getKeyAt (unsigned int index, string* name) 
												const throw (ECIMError)
{
	CMPIStatus status;
	CMPIString* cmpi_ns;

	CCIMData data (_path->ft->getKeyAt (_path, index, &cmpi_ns, &status));
	ECIMError::checkThrowCIMStatus (status);

	*name = string (cmpi_ns->ft->getCharPtr (cmpi_ns, &status));
	DSDK_RELEASE_ON_FAIL (status, cmpi_ns);
	ECIMError::checkThrowCIMStatus (status);
	CMRelease (cmpi_ns);

	return data;
}

/*
 * setNameSpaceFromObjectPath
 */
void 
CCIMObjectPath::setNameSpaceFromObjectPath (const CCIMObjectPath& src)
														throw (ECIMError)
{
	CMPIStatus status = _path->ft->setNameSpaceFromObjectPath (_path, 
															   src._path);
	ECIMError::checkThrowCIMStatus (status);
}

/*
 * setHostAndNameSpaceFromObjectPath
 */
void 
CCIMObjectPath::setHostAndNameSpaceFromObjectPath (const CCIMObjectPath& src)
															throw (ECIMError)
{
	CMPIStatus status = _path->ft->setHostAndNameSpaceFromObjectPath 
																(_path, 
													     		 src._path);
	ECIMError::checkThrowCIMStatus (status);
}

/*
 * getClassQualifier
 */
CCIMData 
CCIMObjectPath::getClassQualifier (const string& qual_name) const throw (ECIMError)
{
	CMPIStatus status;
	CCIMData data (_path->ft->getClassQualifier (_path, 
												 qual_name.c_str (),
												 &status));
	ECIMError::checkThrowCIMStatus (status);

	return data;
}

/*
 * getPropertyQualifier
 */
CCIMData 
CCIMObjectPath::getPropertyQualifier (const string&  prop_name,
									  const string& qual_name) 
									  const throw (ECIMError)
{
	CMPIStatus	status;
	CCIMData data (_path->ft->getPropertyQualifier (_path,
													prop_name.c_str (),
												 	qual_name.c_str (),
												 	&status));
	ECIMError::checkThrowCIMStatus (status);

	return data;
}

/*
 * getMethodQualifier
 */
CCIMData 
CCIMObjectPath::getMethodQualifier (const string& method_name, 
									const string& qual_name) 
											const throw (ECIMError)
{
	CMPIStatus status;
	CCIMData data (_path->ft->getMethodQualifier (_path, 
												  method_name.c_str (),
												  qual_name.c_str (),
												  &status));
	ECIMError::checkThrowCIMStatus (status);

	return data;
}

/*
 * getParameterQualifier
 */
CCIMData 
CCIMObjectPath::getParameterQualifier (const string& method_name,
									   const string& param_name,
									   const string& qual_name) 
											const throw (ECIMError)
{
	CMPIStatus status;
	CCIMData data (_path->ft->getParameterQualifier (_path, 
													 method_name.c_str (),
													 param_name.c_str (),
												 	 qual_name.c_str (),
												 	 &status)); 

	return data;
}

/*
 * toString
 */
string 
CCIMObjectPath::toString (void) const throw (ECIMError)
{
	CMPIStatus status;
	CMPIString* cmpi_str = _path->ft->toString (_path, &status);
	DSDK_RELEASE_ON_FAIL (status, cmpi_str);
	ECIMError::checkThrowCIMStatus (status);

	string str = string (cmpi_str->ft->getCharPtr (cmpi_str, &status));
	status = cmpi_str->ft->release (cmpi_str);
	ECIMError::checkThrowCIMStatus (status);

	return str;
}


/*
 * clone
 */
CCIMObjectPath* 
CCIMObjectPath::clone (void) const
{
	CCIMObjectPath* op = new CCIMObjectPath ();
	op->_ref_count	   = new int (1);
	op->_auto_release  = true;
	op->_null_inst	   = false;

	CMPIStatus status;
	op->_path		   = _path->ft->clone (_path, &status);
	ECIMError::checkThrowCIMStatus (status);

	return op;
}


/*
 * instanceToObjectPath
 */
CCIMObjectPath
CCIMObjectPath::instanceToObjectPath (CMPIInstance* inst, bool auto_release)
{
	CCIMInstance ci = CCIMInstance::toCCIMInstance (inst, auto_release);
	/* 
	 * Create the object path from the instance - this contains 
	 * just the class names and no key qualifiers.
	 */
	CCIMObjectPath op = ci.getObjectPath ();

	/* 
	 * Add the key values to the object path (we assume all properties 
	 * are key properties) 
	 */
	for (unsigned int i = 0; i < ci.getPropertyCount (); i++)
	{
		string   name;
		CCIMValue val = ci.getPropertyAt (i, &name).getValue ();
		op.addKey (name, val);
	}

	return op;
}
