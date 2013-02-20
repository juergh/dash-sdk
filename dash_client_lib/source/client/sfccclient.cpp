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
 * sfccclient.cpp
 * An SFCC Client class.
 */
#include <cstdlib>
#include <dsdk/dsdkexception.h>
#include "sfccclient.h"

using namespace dsdk;

bool   g_enum_names_use_keyprops  = false;
int    g_dsdk_verbose_level = 0;
string g_dsdk_verbose_file  = "";

/*
 * Constructor
 */
CSFCCClient::CSFCCClient (CMCIClient* cc) : _cc (cc)
{
	_ref_count = new int (1);
}

/*
 * Destructor 
 */
CSFCCClient::~CSFCCClient ()
{
	(*_ref_count)--;
	if (0 == *_ref_count)
	{
		CMPIStatus	status;
		status = _cc->ft->release (_cc);
		ECIMError::checkThrowCIMStatus (status);
		delete _ref_count;
	}
}

/*
 * Copy constructor.
 */
CSFCCClient::CSFCCClient (const CSFCCClient& sc)
{
	_cc			= sc._cc;
	_ref_count	= sc._ref_count;
	*(_ref_count)++;
}

/*
 * Assignment operator
 */
const CSFCCClient& 
CSFCCClient::operator = (const CSFCCClient& rhs)
{
	(*_ref_count)--;
	if (*_ref_count) 
	{
		delete _ref_count;
		CMPIStatus	status;
		status = _cc->ft->release (_cc);
		ECIMError::checkThrowCIMStatus (status);
	}

	_cc			= rhs._cc;
	_ref_count	= rhs._ref_count;
	*(_ref_count)++;

	return *this;
}


/*
 * enumInstanceNames
 */
CCIMObjectPath::iterator 
CSFCCClient::enumInstanceNames (const CCIMObjectPath& op)
{
	CMPIStatus status;
	CMPIEnumeration* en = _cc->ft->enumInstanceNames (_cc, 
						    (CMPIObjectPath*) op.getLowLevelObject (),
											  &status);
	EConnectionFailed::checkThrowConnectionFailed (status);
	ECIMError::checkThrowCIMStatus (status);
	if (en == NULL) { throw ECIMError (status); }

	/*
	 * @bugfix SFCC does not hold namespace on enumerations it returns 
	 * Just store the namespace components.
	 */
	CCIMEnumeration ce = CCIMEnumeration::toCCIMEnumeration (en);
	ce.setNameSpace (((CCIMObjectPath&) op).getNameSpace ());

	CKeyClass<CCIMObjectPath>* key = CKeyClass<CCIMObjectPath>::create (ce);
	
	return CCIMObjectPath::iterator (key);
}


/*
 * enumInstanceNames
 */
CCIMObjectPath::iterator 
CSFCCClient::enumInstanceNames (const CCIMObjectPath& op, 
								const vector<string>& key_props)
{
	/* If we do not use the key properties - just call the plain one */
	if (!g_enum_names_use_keyprops) 
	{
		try 
		{
			return enumInstanceNames (op); 
		}
		catch (ECIMError &e)
		{
			/* check if enumerate instances are not supported */
			if (e.getCIMErrorMsg () != "wsman:UnsupportedFeature")
			{
				throw; //rethrow
			}
			else
			{
				/* enumerate instance names are not supported by the target, use enumInstances */
				g_enum_names_use_keyprops = true;
			}
		}
	}

	/* Fill in the key properties */
	char** cp = new char* [key_props.size () + 1];
	for (unsigned int i = 0; i < key_props.size (); i++)
	{
		cp [i] = (char*) key_props [i].c_str ();
	}
	cp [key_props.size ()] = '\0';

	CMPIStatus status;
	CMPIEnumeration* en = _cc->ft->enumInstances (_cc, 
						    (CMPIObjectPath*) op.getLowLevelObject (),
											  0,
											  cp,
											  &status);
	delete [] cp;
	EConnectionFailed::checkThrowConnectionFailed (status);
	ECIMError::checkThrowCIMStatus (status);
	if (en == NULL) { throw ECIMError (status); }

	/* 
	 * Create from the instance enumerator itself - the 'to' conversion 
	 * function will convert to object path based on the value type.
	 */
	CKeyClass<CCIMObjectPath>* key = CKeyClass<CCIMObjectPath>::create (
									CCIMEnumeration::toCCIMEnumeration (en));
	return CCIMObjectPath::iterator (key);
}


/*
 * enumInstances
 */
CCIMInstance::iterator 
CSFCCClient::enumInstances (const CCIMObjectPath& op, 
							CMPIFlags	flags,
							const vector<string>& props)
{
	/* Fill in the properties */
	char** cp = new char* [props.size () + 1];
	for (unsigned int i = 0; i < props.size (); i++)
	{
		cp [i] = (char*) props [i].c_str ();
	}
	cp [props.size ()] = '\0';

	CMPIStatus status;
	CMPIEnumeration* en = _cc->ft->enumInstances (_cc, 
						    (CMPIObjectPath*) op.getLowLevelObject (),
											  flags,
											  cp,
											  &status);
	delete [] cp;
	EConnectionFailed::checkThrowConnectionFailed (status);
	ECIMError::checkThrowCIMStatus (status);
	if (en == NULL) { throw ECIMError (status); }

	CCIMEnumeration cen = CCIMEnumeration::toCCIMEnumeration (en);
	cen.setClassName (op.getClassName ());
	CKeyClass<CCIMInstance>* key = CKeyClass<CCIMInstance>::create (cen);
	return CCIMInstance::iterator (key);
}

/*
 * getInstance
 */
CCIMInstance 
CSFCCClient::getInstance (const CCIMObjectPath& op, 
						  CMPIFlags flags,
						  const vector<string>& props)
{
	/* Fill in the properties */
	char** cp;
	if (0 == props.size ())
	{
		cp = NULL;
	}
	else
	{
		cp = new char* [props.size () + 1];
		for (unsigned int i = 0; i < props.size (); i++)
		{
			cp [i] = (char*) props [i].c_str ();
		}
		cp [props.size ()] = '\0';
	}

	CMPIStatus	status;
	CMPIInstance* ins = _cc->ft->getInstance (_cc, 
							(CMPIObjectPath*) op.getLowLevelObject (), 
											  flags, 
											  cp, 
											  &status);
	delete [] cp;
	EConnectionFailed::checkThrowConnectionFailed (status);
	ECIMError::checkThrowCIMStatus (status);
	if (ins == NULL) { throw ECIMError (status); }

	CCIMInstance ci = CCIMInstance::toCCIMInstance (ins);

	/**
	 * @bugfix SFCC returned object paths does not contain the namespace 
	 * component. Store the object path we get from the input on the 
	 * instance itself.
	 */
	ci.setObjectPath (op);

	return ci;
}

/*
 * createInstance
 */
CCIMObjectPath 
CSFCCClient::createInstance (const CCIMObjectPath& op, const CCIMInstance& inst)
{
	CMPIStatus status;
	CMPIObjectPath* cp = _cc->ft->createInstance (_cc, 
								(CMPIObjectPath*) op.getLowLevelObject (),
								  (CMPIInstance*) inst.getLowLevelObject (),
												  &status);
	EConnectionFailed::checkThrowConnectionFailed (status);
	ECIMError::checkThrowCIMStatus (status);
	if (cp == NULL) { throw ECIMError (status); }

	return CCIMObjectPath::toCCIMObjectPath (cp);
}

/*
 * setInstance
 */
void 
CSFCCClient::setInstance (const CCIMObjectPath& op, 
						  const CCIMInstance& inst,
						  CMPIFlags flags, 
						  const vector<string>& props)
{
	/* Fill in the properties */
	char** cp = new char* [props.size () + 1];
	for (unsigned int i = 0; i < props.size (); i++)
	{
		cp [i] = (char*) props [i].c_str ();
	}
	cp [props.size ()] = '\0';

	CMPIStatus	status;
	status = _cc->ft->setInstance (_cc, 
				 (CMPIObjectPath*) op.getLowLevelObject (), 
				   (CMPIInstance*) inst.getLowLevelObject (),
								   flags, 
								   cp);
	delete [] cp;
	EConnectionFailed::checkThrowConnectionFailed (status);
	ECIMError::checkThrowCIMStatus (status);
}

/*
 * deleteInstance
 */
void 
CSFCCClient::deleteInstance (const CCIMObjectPath& op)
{
	CMPIStatus status;
	status = _cc->ft->deleteInstance (_cc, 
				    (CMPIObjectPath*) op.getLowLevelObject ());
	EConnectionFailed::checkThrowConnectionFailed (status);
	ECIMError::checkThrowCIMStatus (status);
}



/*
 * associators
 */
CCIMInstance::iterator 
CSFCCClient::associators (const CCIMObjectPath& op, 
						  const string& assoc_class,
						  const string& result_class, 
						  const string& role, 
						  const string& result_role,
						  CMPIFlags	flags,
						  const vector<string>& props)
{
	/* Fill in the properties */
	char** cp = new char* [props.size () + 1];
	for (unsigned int i = 0; i < props.size (); i++)
	{
		cp [i] = (char*) props [i].c_str ();
	}
	cp [props.size ()] = '\0';

	CMPIStatus status;
	CMPIEnumeration* en = _cc->ft->associators (_cc, 
											   (CMPIObjectPath*) op.getLowLevelObject (),
											   (assoc_class == "") ? NULL : assoc_class.c_str (),
											   (result_class == "") ? NULL : result_class.c_str (),
											   (role == "") ? NULL : role.c_str (),
											   (result_role == "") ? NULL : result_role.c_str (),
											   flags,
											   cp,
											   &status);
	delete [] cp;
	EConnectionFailed::checkThrowConnectionFailed (status);
	ECIMError::checkThrowCIMStatus (status);
	if (en == NULL) { throw ECIMError (status); }

	CCIMEnumeration cen = CCIMEnumeration::toCCIMEnumeration (en);
	if (result_class != "") cen.setClassName (result_class);
	CKeyClass<CCIMInstance>* key = CKeyClass<CCIMInstance>::create (cen);
	return CCIMInstance::iterator (key);
}

/*
 * associatorNames
 */
CCIMObjectPath::iterator 
CSFCCClient::associatorNames (const CCIMObjectPath& op, 
							  const string& assoc_class,
							  const string& result_class, 
							  const string& role,
							  const string& result_role)
{
	CMPIStatus status;
	CMPIEnumeration* en = _cc->ft->associatorNames (_cc, 
												   (CMPIObjectPath*) op.getLowLevelObject (),
												   (assoc_class == "") ? NULL : assoc_class.c_str (),
												   (result_class == "") ? NULL : result_class.c_str (),
												   (role == "") ? NULL : role.c_str (),
												   (result_role == "") ? NULL : result_role.c_str (),
												    &status);
	EConnectionFailed::checkThrowConnectionFailed (status);
	ECIMError::checkThrowCIMStatus (status);
	if (en == NULL) { throw ECIMError (status); }

	CKeyClass<CCIMObjectPath>* key = CKeyClass<CCIMObjectPath>::create (
										CCIMEnumeration::toCCIMEnumeration (en));
	return CCIMObjectPath::iterator (key);
}


/*
 * references
 */
CCIMInstance::iterator 
CSFCCClient::references (const CCIMObjectPath& op, 
						 const string& result_class,
						 const string& role, 
						 CMPIFlags	flags,
						 const vector<string>& props)
{
	/* Fill in the properties */
	char** cp = new char* [props.size () + 1];
	for (unsigned int i = 0; i < props.size (); i++)
	{
		cp [i] = (char*) props [i].c_str ();
	}
	cp [props.size ()] = '\0';

	CMPIStatus status;
	CMPIEnumeration* en = _cc->ft->references (_cc, 
											   (CMPIObjectPath*) op.getLowLevelObject (),
											   (result_class == "") ? NULL : result_class.c_str (),
											   (role == "") ? NULL : role.c_str (),
											   flags,
											   cp,
											   &status);
	delete [] cp;
	EConnectionFailed::checkThrowConnectionFailed (status);
	ECIMError::checkThrowCIMStatus (status);
	if (en == NULL) { throw ECIMError (status); }

	CCIMEnumeration cen = CCIMEnumeration::toCCIMEnumeration (en);
	if (result_class != "") cen.setClassName (result_class);
	CKeyClass<CCIMInstance>* key = CKeyClass<CCIMInstance>::create (cen);
	return CCIMInstance::iterator (key);
}

/*
 * referenceNames
 */
CCIMObjectPath::iterator 
CSFCCClient::referenceNames (const CCIMObjectPath& op, 
							 const string& result_class,
							 const string& role)
{
	CMPIStatus status;
	CMPIEnumeration* en = _cc->ft->referenceNames (_cc, 
											   (CMPIObjectPath*) op.getLowLevelObject (),
											   (result_class == "") ? NULL : result_class.c_str (),
											   (role == "") ? NULL : role.c_str (),
											    &status);
	EConnectionFailed::checkThrowConnectionFailed (status);
	ECIMError::checkThrowCIMStatus (status);
	if (en == NULL) { throw ECIMError (status); }

	CKeyClass<CCIMObjectPath>* key = CKeyClass<CCIMObjectPath>::create (
										CCIMEnumeration::toCCIMEnumeration (en));
	return CCIMObjectPath::iterator (key);
}

/*
 * invokeMethod
 */
CCIMData 
CSFCCClient::invokeMethod (const CCIMObjectPath& op, 
						   const string&		method,
						   const CCIMArgument&	in,
						   CCIMArgument*		out)
{
	CMPIStatus status;
	CMPIData data = _cc->ft->invokeMethod (_cc, 
								op.getLowLevelObject (),
								method.c_str (),
						        ((CCIMArgument&) in).getLowLevelObject (),
						        out->getLowLevelObject (),
								&status);
	EConnectionFailed::checkThrowConnectionFailed (status);
	ECIMError::checkThrowCIMStatus (status);

	return CCIMData::toCCIMData (data);
}

/*
 * setProperty
 */
void 
CSFCCClient::setProperty (const CCIMObjectPath& op, 
						  const string& name,
						  const CCIMValue& value)
{
	CMPIStatus status;
	CMPIValue* pv	= value.getLowLevelValue ();
	CMPIType   type = value.getLowLevelType ();
	status = _cc->ft->setProperty (_cc, 
			     (CMPIObjectPath*) op.getLowLevelObject (),
								   name.c_str (), 
								   pv,
								   type);
	EConnectionFailed::checkThrowConnectionFailed (status);
	ECIMError::checkThrowCIMStatus (status);
}

/*
 * getProperty
 */
CCIMValue
CSFCCClient::getProperty (const CCIMObjectPath& op, const string& name)
{
	CMPIStatus status;
	CMPIData data = _cc->ft->getProperty (_cc,
						(CMPIObjectPath*) op.getLowLevelObject (),
										  name.c_str (),
										  &status);
	EConnectionFailed::checkThrowConnectionFailed (status);
	ECIMError::checkThrowCIMStatus (status);

	return CCIMValue::toCCIMValue (data.value, data.type);
}

/*
 * subscribeEvent
 */
string 
CSFCCClient::subscribeEvent (const CCIMObjectPath& op,
							 const string&	delivery_uri, 
						     int 			mode, 
							 float			heartbeat_interval,
							 float			expiration_timeout,
							 const string&	dialect,
							 const string&	filter)
{
	CMPIStatus status;
	char* uuid = 0;
	uuid = _cc->ft->subscribeEvent (_cc, 
										(CMPIObjectPath*) op.getLowLevelObject (),
										  delivery_uri.c_str (),
										  mode, 
										  heartbeat_interval,
										  expiration_timeout,
										  (dialect == "") ? NULL : dialect.c_str (),
										  (filter  == "") ? NULL : filter.c_str (),
										  &status);
	EConnectionFailed::checkThrowConnectionFailed (status);
	ECIMError::checkThrowCIMStatus (status);

	string ret = "N/A";
	if (uuid != NULL) 
	{ 
		ret = uuid;
		free (uuid);
	}

	return ret;
}


/*
 * subscribeEvent
 */
string 
CSFCCClient::subscribeToEvent (const CCIMObjectPath &cop, const vector<string>& params)
{

	CMPIStatus status;
	char* uuid = 0;
	char** cp = new char* [params.size () + 1];

	for (unsigned int i = 0; i < params.size (); i++)
	{
		if(strcmp(params[i].c_str(), "NULL") != 0 )
			cp [i] = (char*) params [i].c_str ();
		else
			cp [i] = NULL;
		//fprintf(stdout, "\n sfccclient.cpp --- Params conversion .....%d. %s",i,cp[i]);
	}
	cp [params.size ()] = '\0';

	uuid = _cc->ft->subscribeToEvent(_cc,
										(CMPIObjectPath*) cop.getLowLevelObject (),
										cp, &status);

	EConnectionFailed::checkThrowConnectionFailed (status);
	ECIMError::checkThrowCIMStatus (status);

	string ret = "N/A";
	if (uuid != NULL) 
	{ 
		ret = uuid;
		free (uuid);
	}

	return ret;
}


/*
 * unsubscribeEvent
 */
void 
CSFCCClient::unsubscribeEvent (const CCIMObjectPath& op)
{
	CMPIStatus status = _cc->ft->unsubscribeEvent (_cc,(CMPIObjectPath*) op.getLowLevelObject ());
	EConnectionFailed::checkThrowConnectionFailed (status);
	ECIMError::checkThrowCIMStatus (status);
}

/*
 * renewSubscription
 */
void 
CSFCCClient::renewSubscription (const CCIMObjectPath& op,const string&	renewtime)
{
	CMPIStatus status = _cc->ft->renewSubscription (_cc, (CMPIObjectPath*) op.getLowLevelObject (),renewtime.c_str());
	EConnectionFailed::checkThrowConnectionFailed (status);
	ECIMError::checkThrowCIMStatus (status);
}

/*
 * getHostName
 */
string
CSFCCClient::getHostName (void)
{
	return _cc->ft->getHostName (_cc);
}

/*
 * getPort
 */
int
CSFCCClient::getPort (void)
{
	return _cc->ft->getPort (_cc);
}

/*
 * getUser
 */
string
CSFCCClient::getUser (void)
{
	return _cc->ft->getUser (_cc);
}

/*
 * getPassword
 */
string
CSFCCClient::getPassword (void)
{
	return _cc->ft->getPassword (_cc);
}

/*
 * getImplementationNS
 */
string
CSFCCClient::getImplementationNS (void)
{
	char* ns = _cc->ft->getImplementationNS (_cc);
	return  (ns == NULL) ? "" : ns;
}

/*
 * getInteropNS
 */
string
CSFCCClient::getInteropNS  (void)
{
	char* ns = _cc->ft->getInteropNS (_cc);
	return (ns == NULL) ? "" : ns;
}

/* 
 * setTimeout
 */
void
CSFCCClient::setTimeout (unsigned long timeout)
{
	_cc->ft->setTimeout (_cc,timeout);
	return;
}

/*
 * getTimeout
 */
unsigned long
CSFCCClient::getTimeout (void)
{
	return _cc->ft->getTimeout (_cc);
}




