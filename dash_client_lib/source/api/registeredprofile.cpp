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
 * registeredprofile.cpp
 * A class representing a registeredprofile.
 */
#include <string.h>
#include <dsdk/oal/CIM_RegisteredProfile.h>
#include <dsdk/oal/CIM_ReferencedProfile.h>
#include <dsdk/oal/CIM_ElementConformsToProfile.h>
#include <dsdk/registeredprofile.h>
#include "apiimp.h"

using namespace dsdk;

/*
 * Constructor
 */
CRegisteredProfile::CRegisteredProfile (const CIM_RegisteredProfile& rp)
{ 
	_rp = new CIM_RegisteredProfile (rp); 
}

/*
 * Constructor
 */
CRegisteredProfile::CRegisteredProfile (const CRegisteredProfile& rp)
{
	this->_rp = new CIM_RegisteredProfile (*(rp._rp));
}

/*
 * Destruction 
 */
CRegisteredProfile::~CRegisteredProfile ()
{
	if (this->_rp) { delete this->_rp; }
}

/*
 * Assignment operator
 */
const CRegisteredProfile& 
CRegisteredProfile::operator = (const CRegisteredProfile& rhs)
{
	if (this->_rp) { delete this->_rp; }
	this->_rp  = new CIM_RegisteredProfile (*rhs._rp);
	return *this;
}


/*
 * enumRegisteredProfile
 */
CRegisteredProfile::iterator 
CRegisteredProfile::enumRegisteredProfile (IClient* client, bool cached)
{

	vector<string> props = getCachedProps ();
	CIM_RegisteredProfile::iterator iter 
				= CIM_RegisteredProfile::enumInstances (client, 0, props);

	if (cached) { return createIterator (iter, props);}
	else 		{ return createIterator (iter);		  }
}

/*
 * getInstanceID
 */
string 
CRegisteredProfile::getInstanceID (void)
{
	return _rp->getInstanceID ();
}

/*
 * getRegisteredName
 */
string 
CRegisteredProfile::getRegisteredName (void)
{
	return _rp->getRegisteredName ();
}

/*
 * getRegisteredOrganization
 */
uint16 
CRegisteredProfile::getRegisteredOrganization (void)
{
	return _rp->getRegisteredOrganization ();
}

/*
 * getValueRegisteredOrganizationStr
 */
string
CRegisteredProfile::getValueRegisteredOrganizationStr()
{
	return _rp->getValueStr_RegisteredOrganization (getRegisteredOrganization ());
}

/*
 * getRegisteredVersion
 */
string 
CRegisteredProfile::getRegisteredVersion (void)
{
	return _rp->getRegisteredVersion ();
}

/*
 * getAdvertiseTypes
 */
vector<uint16>
CRegisteredProfile::getAdvertiseTypes (void)
{
	return  _rp->getAdvertiseTypes ();
}

/*
 * getValueAdvertiseTypesStr
 */
vector<string>
CRegisteredProfile::getValueAdvertiseTypesStr (void)
{
	vector<uint16> values;
	vector <string> valuestr;

	values = _rp->getAdvertiseTypes ();
	for (size_t i = 0; i < values.size (); i++)
	{
		valuestr.push_back (_rp->getValueStr_AdvertiseTypes (values [i]));
	}
	return valuestr;
}

/*
 * getOtherRegisteredOrganization
 */
string 
CRegisteredProfile::getOtherRegisteredOrganization (void)
{
	return _rp->getOtherRegisteredOrganization ();
}

/*
 * getAdvertiseTypeDescriptions
 */
vector<string>
CRegisteredProfile::getAdvertiseTypeDescriptions (void)
{
	return _rp->getAdvertiseTypeDescriptions ();
}

/*
 * isAdvertised
 */
bool
CRegisteredProfile::isAdvertised (IClient* client, string profilename, string versionno)
{

			
		/* Enumerating registered profile */
	CRegisteredProfile::iterator iter = CRegisteredProfile::enumRegisteredProfile (client);
	
	for (; iter != CRegisteredProfile::iterator::end (); ++iter)
	 {
		CRegisteredProfile _rp = *iter;

		string _profilename = _rp.getRegisteredName ().c_str ();

		/* Convert the profile name string to lower case*/
		for (size_t i = 0; i < _profilename.size(); i++)
		{
			if (_profilename[i] >= 0x41 && _profilename[i] <= 0x5A)
			{
				_profilename[i] = _profilename[i] + 0x20;
			}
		}

		/* Elimating the spaces from the RegisteredName string*/
		while ((size_t)-1 != _profilename.find (' '))
		{
			_profilename.erase (_profilename.find (' '), 1);
		}
		
		/* Elimating the "profile" from the RegisteredName string*/
		while ((size_t)-1 != _profilename.find ("profile"))
		{
			_profilename.erase (_profilename.find ("profile"), strlen("profile"));
		}


		/* Compare the user input with the RegisteredName string*/
		/* If yes,return success else failure*/
		int matchstr = strcasecmp (_profilename.c_str (),profilename.c_str ());
		
		if (matchstr == 0 && versionno == "")
		{
			return true;
		}
		else if ((matchstr == 0) && (_rp.getRegisteredVersion () == versionno))
		{
			return true;
		}
	}

	return false;
}
		
/*
 * getCachedProps
 */
vector<string> 
CRegisteredProfile::getCachedProps (void) 
{
	vector<string> props;

	props.push_back ("AdvertiseTypes");
	props.push_back ("InstanceID");
	props.push_back ("RegisteredName");
	props.push_back ("RegisteredOrganization");
	props.push_back ("RegisteredVersion");
	props.push_back ("OtherRegisteredOrganization");
	props.push_back ("AdvertiseTypeDescriptions");
	return props;
}

/*
 * CRegisteredProfile::Iterator
 */
DEFINE_API_ITERATOR (CRegisteredProfile);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CRegisteredProfile, CIM_RegisteredProfile);
