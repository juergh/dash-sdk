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
 * cimconstclass.cpp
 * A class CIM Constant Class.
 */
#include <dsdk/cim/cimconstclass.h>
#include <dsdk/cim/cimconversion.h>


using namespace dsdk;

/* 
 * toCCIMConstClass
 */
CCIMConstClass 
CCIMConstClass::toCCIMConstClass (CMPIConstClass* cls, bool auto_release)
{
	CCIMConstClass cc (cls);
	cc._ref_count 	 = new int (1);
	cc._auto_release = auto_release;

	return cc;
}

/*
 * Copy constructor
 */
CCIMConstClass::CCIMConstClass (const CCIMConstClass& cc) 
{
	_cls 		= cc._cls;
	_ref_count	= cc._ref_count;
	(*_ref_count)++;
}

/*
 * Assignment operator.
 */
const CCIMConstClass& 
CCIMConstClass::operator = (const CCIMConstClass& rhs) throw (ECIMError)
{
	(*_ref_count)--;
	if (0 == *_ref_count)
	{
		delete _ref_count;
		if (_auto_release)
		{
			CMPIStatus status = _cls->ft->release (_cls);
			ECIMError::checkThrowCIMStatus (status);
		}
	}

	_cls 		= rhs._cls;
	_ref_count	= rhs._ref_count;
	(*_ref_count)++;

	return *this;
}

/*
 * Destructor
 */
CCIMConstClass::~CCIMConstClass ()
{
	(*_ref_count)--;
	if (0 == *_ref_count) 
	{
		if (_auto_release) { _cls->ft->release (_cls); }
		delete _ref_count;
	}
}

/*
 * clone
 */
CCIMConstClass* 
CCIMConstClass::clone (void) const
{
	CMPIStatus	   status;
	CCIMConstClass* cc = new CCIMConstClass (_cls->ft->clone (_cls, &status));
	ECIMError::checkThrowCIMStatus (status);
	cc->_ref_count 		= new int (1);
	cc->_auto_release	= true;	/* Cloned objects are not exact replica always.
								   This needs to be done here, because there 
								   will be no other way to release the CMPI 
								   object otherwise. */

	return cc;
}

/*
 * getClassName
 */
string 
CCIMConstClass::getClassName (void) const throw (ECIMError)
{
	CMPIStatus 	status;
	CMPIString*	cmpi_cn;

	cmpi_cn = _cls->ft->getClassName (_cls, &status);
	ECIMError::checkThrowCIMStatus (status);

	string cn = cmpi_cn->ft->getCharPtr (cmpi_cn, &status);
	if (status.rc != CMPI_RC_OK) { cmpi_cn->ft->release (cmpi_cn); }
	ECIMError::checkThrowCIMStatus (status);

	status = cmpi_cn->ft->release (cmpi_cn);
	ECIMError::checkThrowCIMStatus (status);

	return cn;
}

/*
 * getProperty
 */
CCIMData 
CCIMConstClass::getProperty (const string& name) const throw (ECIMError)
{
	CMPIStatus status;
	CMPIData cmpi_prop = _cls->ft->getProperty (_cls, name.c_str (), &status);
	ECIMError::checkThrowCIMStatus (status);

	return CCIMData (cmpi_prop);	
}

/*
 * getPropertyCount
 */
unsigned int 
CCIMConstClass::getPropertyCount (void) const throw (ECIMError)
{
	CMPIStatus 		status;
	unsigned int 	count;

	count = _cls->ft->getPropertyCount (_cls, &status);
	ECIMError::checkThrowCIMStatus (status);

	return count;
}

/*
 * getPropertyAt
 */
CCIMData 
CCIMConstClass::getPropertyAt (unsigned int index, string* name) 
													const throw (ECIMError)
{
	CMPIStatus 	status;
	CMPIString*	cmpi_name;

	CMPIData cmpi_prop = _cls->ft->getPropertyAt (_cls, index, &cmpi_name, 
																	&status);
	ECIMError::checkThrowCIMStatus (status);

	*name = cmpi_name->ft->getCharPtr (cmpi_name, &status);
	if (status.rc != CMPI_RC_OK) { cmpi_name->ft->release (cmpi_name); }
	ECIMError::checkThrowCIMStatus (status);

	status = cmpi_name->ft->release (cmpi_name);
	ECIMError::checkThrowCIMStatus (status);

	return CCIMData (cmpi_prop);	
}

/*
 * getQualifier
 */
CCIMData 
CCIMConstClass::getQualifier (const string& name) const throw (ECIMError)
{
	CMPIStatus status;
	CMPIData cmpi_qual = _cls->ft->getQualifier (_cls, name.c_str (), &status);
	ECIMError::checkThrowCIMStatus (status);

	return CCIMData (cmpi_qual);	
}

/*
 * getQualifierCount
 */
unsigned int 
CCIMConstClass::getQualifierCount (void) const throw (ECIMError)
{
	CMPIStatus 		status;
	unsigned int 	count;

	count = _cls->ft->getQualifierCount (_cls, &status);
	ECIMError::checkThrowCIMStatus (status);

	return count;
}

/*
 * getQualifierAt
 */
CCIMData 
CCIMConstClass::getQualifierAt (unsigned int index, string* name) 
													const throw (ECIMError)
{
	CMPIStatus 	status;
	CMPIString*	cmpi_name;

	CMPIData cmpi_qual = _cls->ft->getQualifierAt (_cls, index, &cmpi_name, 
																	&status);
	ECIMError::checkThrowCIMStatus (status);

	*name = cmpi_name->ft->getCharPtr (cmpi_name, &status);
	if (status.rc != CMPI_RC_OK) { cmpi_name->ft->release (cmpi_name); }
	ECIMError::checkThrowCIMStatus (status);

	status = cmpi_name->ft->release (cmpi_name);
	ECIMError::checkThrowCIMStatus (status);

	return CCIMData (cmpi_qual);	
}

/* 
 * getPropertyQualifier
 */
CCIMData 
CCIMConstClass::getPropertyQualifier (const string& pname, const string& qname) const throw (ECIMError)
{
	CMPIStatus status;
	CMPIData cmpi_qual = _cls->ft->getPropertyQualifier (_cls, 
														 pname.c_str (), 
														 qname.c_str (),
														 &status);
	ECIMError::checkThrowCIMStatus (status);

	return CCIMData (cmpi_qual);	
}

/*
 * getPropertyQualifierCount
 */
unsigned int 
CCIMConstClass::getPropertyQualifierCount (const string& pname) const throw (ECIMError)
{
	CMPIStatus 		status;
	unsigned int 	count;

	count = _cls->ft->getPropertyQualifierCount (_cls, 
												 pname.c_str (), 
												 &status);
	ECIMError::checkThrowCIMStatus (status);

	return count;
}

/*
 * getPropertyQualifierAt
 */
CCIMData 
CCIMConstClass::getPropertyQualifierAt (const string& pname, unsigned int index, 
											string* qname) const throw (ECIMError)
{
	CMPIStatus 	status;
	CMPIString*	cmpi_qname;

	CMPIData cmpi_qual = _cls->ft->getPropertyQualifierAt (_cls, 
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

	return CCIMData (cmpi_qual);	
}

//DSDK_DEFINE_KEY_CLASS  (CCIMConstClass);

