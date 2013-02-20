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
 * software.cpp
 * Class representing Software
 */
#include <dsdk/oal/CIM_SoftwareIdentity.h>
#include <dsdk/software.h>
#include "apiimp.h"

using namespace dsdk;

/*
 * Constructor
 */
CSoftware::CSoftware (const CIM_SoftwareIdentity& sw)
{ 
	_sw = new CIM_SoftwareIdentity (sw); 
}

/*
 * Constructor
 */
CSoftware::CSoftware (const CSoftware& sw)
{
	this->_sw = new CIM_SoftwareIdentity (*(sw._sw));
}

/*
 * Destruction 
 */
CSoftware::~CSoftware ()
{
	if (this->_sw) { delete this->_sw; }
}

/*
 * Assignment operator
 */
const CSoftware& 
CSoftware::operator = (const CSoftware& rhs)
{
	if (this->_sw) { delete this->_sw; }
	this->_sw  = new CIM_SoftwareIdentity (*rhs._sw);
	return *this;
}


/*
 * enumSoftware
 */
CSoftware::iterator 
CSoftware::enumSoftware (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_SoftwareIdentity::iterator iter = 
			CIM_SoftwareIdentity::enumInstances (client, 
												 0, 
												 props);
	if (cached) { return createIterator (iter, props);  }
	else 		{ return createIterator (iter); 		}
}


/*
 * getInstanceID
 */
string 
CSoftware::getInstanceID (void) const
{
	return ((CSoftware*) this)->_sw->getInstanceID ();
}

/*
 * Gets IsEntity
 */
boolean
CSoftware::getIsEntity (void) const
{
	return ((CSoftware*) this)->_sw->getIsEntity ();
}

/*
 * getVersionString
 */
string 
CSoftware::getVersionString (void) const
{
	return ((CSoftware*) this)->_sw->getVersionString ();
}


/*
 * getMajorVersion
 */
uint16 
CSoftware::getMajorVersion (void) const
{
	return ((CSoftware*) this)->_sw->getMajorVersion ();
}

/*
 * getMinorVersion
 */
uint16 
CSoftware::getMinorVersion (void) const
{
	return ((CSoftware*) this)->_sw->getMinorVersion ();
}


/*
 * getRevisionNumber
 */
uint16 
CSoftware::getRevisionNumber (void) const
{
	return ((CSoftware*) this)->_sw->getRevisionNumber ();
}


/*
 * getBuildNumber
 */
uint16 
CSoftware::getBuildNumber (void) const
{
	return ((CSoftware*) this)->_sw->getBuildNumber ();
}

/*
 * getTargetOSTypes
 */

vector<uint16>
CSoftware::getTargetOSTypes (void) const
{
	return ((CSoftware*) this)->_sw->getTargetOSTypes ();
}

/*
 * getTargetOperatingSystems
 */
vector<string> 
CSoftware::getTargetOperatingSystems (void) const
{
	return ((CSoftware*) this)->_sw->getTargetOperatingSystems ();
}

/*
 * getIdentityInfoType
 */
vector<string> 
CSoftware::getIdentityInfoType (void) const
{
	return ((CSoftware*) this)->_sw->getIdentityInfoType ();
}

/*
 * getIdentityInfoValue
 */
vector<string> 
CSoftware::getIdentityInfoValue (void) const
{
	return ((CSoftware*) this)->_sw->getIdentityInfoValue ();
}
/*
 * getClassifications
 */
vector<uint16> 
CSoftware::getClassifications (void) const
{
	vector<uint16> ret;

	vector<uint16> cl = 
				((CSoftware*) this)->_sw->getClassifications ();
	for (size_t i = 0; i < cl.size (); i++)
	{
		uint16 val;
		if ((cl [i] > CIM_SoftwareIdentity::Classifications_DMTF_Reserved_low) && 
			(cl [i] < CIM_SoftwareIdentity::Classifications_DMTF_Reserved_high))
		{
			val = dmtf_reserved;
		}
		else if ((cl [i] > CIM_SoftwareIdentity::Classifications_Vendor_Reserved_low) && 
				 (cl [i] < CIM_SoftwareIdentity::Classifications_Vendor_Reserved_high))
		{
			val = vendor_reserved;
		}
		else
		{
			val = cl [i];
		}

		ret.push_back (val);
	}

	return ret;
}

/*
 * getClassification as string
 */
vector<string>
CSoftware::getClassificationsStr (void) const
{
	vector<uint16> classifications = ((CSoftware*) this)->_sw->getClassifications ();
		vector <string> classificationstr;
		for(size_t value = 0; value < classifications.size(); value++ )
		{
			classificationstr.push_back(((CSoftware*) this)->_sw->getValueStr_Classifications(classifications[value]));
		}
		return classificationstr;
}


/*
 * Software classifications.
 */
const uint16 CSoftware::unknown                = CIM_SoftwareIdentity::Classifications_Unknown;
const uint16 CSoftware::other                  = CIM_SoftwareIdentity::Classifications_Other;               
const uint16 CSoftware::driver                 = CIM_SoftwareIdentity::Classifications_Driver;                 
const uint16 CSoftware::configuration_software = CIM_SoftwareIdentity::Classifications_Configuration_Software;
const uint16 CSoftware::application_software   = CIM_SoftwareIdentity::Classifications_Application_Software;
const uint16 CSoftware::instrumentation        = CIM_SoftwareIdentity::Classifications_Instrumentation;  
const uint16 CSoftware::firmware_bios          = CIM_SoftwareIdentity::Classifications_Firmware_BIOS;       
const uint16 CSoftware::diagnostic_software    = CIM_SoftwareIdentity::Classifications_Diagnostic_Software;
const uint16 CSoftware::operating_system       = CIM_SoftwareIdentity::Classifications_Operating_System;   
const uint16 CSoftware::middleware             = CIM_SoftwareIdentity::Classifications_Middleware;      
const uint16 CSoftware::firmware               = CIM_SoftwareIdentity::Classifications_Firmware;            
const uint16 CSoftware::bios_fcode             = CIM_SoftwareIdentity::Classifications_BIOS_FCode;
const uint16 CSoftware::support_service_pack   = CIM_SoftwareIdentity::Classifications_Support_Service_Pack;
const uint16 CSoftware::software_bundle        = CIM_SoftwareIdentity::Classifications_Software_Bundle;        
const uint16 CSoftware::dmtf_reserved          = CIM_SoftwareIdentity::Classifications_DMTF_Reserved_low;
const uint16 CSoftware::vendor_reserved        = CIM_SoftwareIdentity::Classifications_Vendor_Reserved_low;


/*
 * getCachedProps
 */
vector<string> 
CSoftware::getCachedProps (void)
{
	vector<string> props;
	props.push_back ("InstanceID");
	props.push_back ("IsEntity");
	props.push_back ("VersionString");
	props.push_back ("MajorVersion");
	props.push_back ("MinorVersion");
	props.push_back ("RevisionNumber");
	props.push_back ("BuildNumber");
	props.push_back ("TargetOSTypes");
	props.push_back ("TargetOperatingSystems");
	props.push_back ("IdentityInfoType");
	props.push_back ("IdentityInfoValue");
	props.push_back ("Classifications");
	return props;
}

/*
 * CSoftware::Iterator
 */
DEFINE_API_ITERATOR (CSoftware);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CSoftware, CIM_SoftwareIdentity);
