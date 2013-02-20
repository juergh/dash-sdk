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
 * user.h
 * A class representing a user management.
 */
#include <sstream>
#include <dsdk/oal/CIM_Account.h>
#include <dsdk/oal/CIM_Role.h>
#include <dsdk/oal/CIM_Privilege.h>
#include <dsdk/oal/CIM_AssignedIdentity.h>
#include <dsdk/oal/CIM_ComputerSystem.h>
#include <dsdk/oal/CIM_HostedService.h>
#include <dsdk/oal/CIM_AccountManagementService.h>
#include <dsdk/oal/CIM_RoleBasedAuthorizationService.h>
#include <dsdk/oal/CIM_OwningCollectionElement.h>
#include <dsdk/oal/CIM_RoleBasedManagementCapabilities.h>
#include <dsdk/oal/CIM_MemberOfCollection.h>
#include <dsdk/oal/CIM_ConcreteDependency.h>
#include <dsdk/oal/CIM_ServiceAffectsElement.h>
#include <dsdk/oal/CIM_AccountManagementCapabilities.h>
#include <dsdk/oal/CIM_ElementCapabilities.h>
#include "enumeratortemplate.h"
#include <dsdk/user.h>
#include <dsdk/dsdkexception.h>
#include "apiimp.h"
#include <dsdk/cimcapabilities.h>

#define MAX_SIZE 256


using namespace dsdk;
using std::map;

/*
 * Constructor
 */
CUser::CUser (const CIM_Account& user)
{ 
	_user = new CIM_Account (user); 
}

/*
 * Constructor
 */
CUser::CUser (const CUser& user)
{
	this->_user = new CIM_Account (*(user._user));
}

/*
 * Destruction 
 */
CUser::~CUser ()
{
	if (this->_user) { delete this->_user; }
}

/*
 * Assignment operator
 */
const CUser& 
CUser::operator = (const CUser& rhs)
{
	if (this->_user) { delete this->_user; }
	this->_user  = new CIM_Account (*rhs._user);
	return *this;
}


/*
 * enumerateUsers
 */
CUser::iterator 
CUser::enumUsers (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_Account::iterator iter = 
		CIM_Account::enumInstances (client, 0, props);

	if (cached) { return createIterator (iter, props);  	  }
	else 		{ return createIterator (iter); }
}


/*
 * getSystemCreationClassName
 */
string 
CUser::getSystemCreationClassName (void) const
{
	return ((CUser*)this)->_user->getSystemCreationClassName ();
}

/*
 * getCreationClassName
 */
string 
CUser::getCreationClassName (void) const
{
	return ((CUser*)this)->_user->getCreationClassName ();
}

/*
 * getSystemName
 */
string 
CUser::getSystemName (void) const
{
	return ((CUser*)this)->_user->getSystemName ();
}

/*
 * getName
 */
string
CUser::getName (void) const
{
	return ((CUser*)this)->_user->getName ();
}

/*
 * getUserID
 */
string 
CUser::getUserID (void) const
{
	return ((CUser*)this)->_user->getUserID ();
}

/*
 * getUserPassword
 */
vector<string> 
CUser::getUserPassword (void) const
{
	vector<string> userpassword;
	userpassword = ((CUser*)this)->_user->getUserPassword ();
	return userpassword;
}
/*
 * getOrganizationName
 */
vector<string> 
CUser:: getOrganizationName (void) const
{
	vector<string> organizationname;
	organizationname = ((CUser*)this)->_user->getOrganizationName ();
	return organizationname;
}

/*
 * getElementName
 */
string 
CUser::getElementName (void) const
{
	return ((CUser*)this)->_user->getElementName ();
}

/*
 * getUserPasswordEncryptionAlgorithm
 */
uint16 
CUser::getUserPasswordEncryptionAlgorithm (void) const
{
	return ((CUser*)this)->_user->getUserPasswordEncryptionAlgorithm ();
}

/*
 * getOtherUserPasswordEncryptionAlgorithm
 */
string 
CUser::getOtherUserPasswordEncryptionAlgorithm (void) const
{
	return ((CUser*)this)->_user->getOtherUserPasswordEncryptionAlgorithm ();
}

/*
 * getPasswordHistoryDepth
 */
uint16 
CUser::getPasswordHistoryDepth (void) const
{
	return ((CUser*)this)->_user->getPasswordHistoryDepth ();
}

/*
 * getComplexPasswordRulesEnforced
 */
vector<uint16> 
CUser::getComplexPasswordRulesEnforced (void) const
{
	return ((CUser*)this)->_user->getComplexPasswordRulesEnforced ();
}

/*
 * getPasswordExpiration
 */
datetime
CUser::getPasswordExpiration (void) const
{
	return ((CUser*)this)->_user->getPasswordExpiration ();
}

/*
 * getInactivityTimeout
 */
datetime
CUser::getInactivityTimeout (void) const
{
	return ((CUser*)this)->_user->getInactivityTimeout ();
}

/*
 * getMaximumSuccessiveLoginFailures
 */
uint16 
CUser::getMaximumSuccessiveLoginFailures (void) const
{
	return ((CUser*)this)->_user->getMaximumSuccessiveLoginFailures ();
}

/*
 * getRequestedState
 */
uint16
CUser::getRequestedState (void) const
{
	return ((CUser*)this)->_user->getRequestedState ();
}

/*
 * getRequestedStateStr
 */
string
CUser::getRequestedStateStr (void) const
{ 
	return CIM_Account::getValueStr_RequestedState (
			((CUser*) this)->_user->getRequestedState ()); 
} 	

/*
 * getEnabledState
 */
uint16 
CUser::getEnabledState (void) const
{
	return ((CUser*)this)->_user->getEnabledState ();
}

/*
 * getEnabledStateStr 
 */
string
CUser::getEnabledStateStr (void) const
{ 
	return CIM_Account::getValueStr_RequestedState (
			((CUser*) this)->_user->getRequestedState ()); 
} 	

string
strToOctet (string str)
{
	char	temp [0x20];
	string	hexstr;

	sprintf (temp, "0x%08X", str.size () + 4);
	hexstr += temp;

	for (size_t i = 0; i < str.size (); i++)
	{
		sprintf (temp, "%x", str [i]);
		hexstr += temp;
	}

	/* convert any small case hex to captial */
	for (size_t i = 0; i <hexstr.size (); i++)
	{
		if ((hexstr [i] >= 'a') && (hexstr [i] <= 'f')) { hexstr [i] -= 32; }
	}

	return hexstr;
}


/* 
 * createUser
 */
CUser
CUser::createUser(const CComputerSystem& cs,
				  const string&		user_id, 
				  const string&		password,
				  const string&		organizationname)
{
	vector<string>	props,empty_props;
	props.push_back("OperationsSupported");
	IClient* client = cs.getCIMObject ()->getClient ();
	CIM_AccountManagementService ams(CCIMInstance::nullInstance());
	CIM_AccountManagementCapabilities rbc(CCIMInstance::nullInstance());
	CUser usr (CCIMInstance::nullInstance());
	/* Enumerate the Account Management Service with this CS */
	CIM_AccountManagementService::iterator iter =CIM_HostedService <CIM_ComputerSystem, 
		CIM_AccountManagementService>::enumerateDependent (client,
												 *(cs.getCIMObject ()), empty_props);
	
	if (iter == CIM_AccountManagementService::iterator::end ())
	{
		throw EFunctionNotSupported ("createUser");
	}
	ams = *iter;
	/* To check the support for the create account */
	CIM_AccountManagementCapabilities::iterator eleciter =
			CIM_ElementCapabilities <CIM_AccountManagementService, CIM_AccountManagementCapabilities>::
			enumerateCapabilities (client, ams, props);

	if (eleciter == CIM_AccountManagementCapabilities::iterator::end ())
	{
		throw EFunctionNotSupported ("createUser");
	} 
	
	rbc = *eleciter;

	/* Create the user using account management service */
	CIM_Account				account (CCIMInstance::nullInstance ());
	vector <CIM_Identity>	identity;
	vector <string>			passwords; 
	vector <string>			organizationnames; 
	passwords.push_back (strToOctet (password));
	organizationnames.push_back (organizationname);
	/*create a new CIM_Account instance */
	CCIMObjectPath ObjectPath ("","http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Account");
	CCIMInstance inst (ObjectPath);
	
	inst.setProperty ("CreationClassName",toCCIMValue<stringDSDKAdapter> ("CIM_AccountManagementService"));
	inst.setProperty ("ElementName", toCCIMValue<stringDSDKAdapter> (user_id));
	inst.setProperty ("EnabledState", toCCIMValue<stringDSDKAdapter> ("2"));
	inst.setProperty ("Name",toCCIMValue<stringDSDKAdapter> (user_id));
	inst.setProperty ("OrganizationName", toCCIMValue<stringDSDKAdapter> (organizationname));
	inst.setProperty ("RequestedState", toCCIMValue<stringDSDKAdapter> ("2"));
	inst.setProperty ("SystemCreationClassName",toCCIMValue<stringDSDKAdapter> (cs.getCIMObject ()->getCreationClassName ()));
	inst.setProperty ("SystemName",toCCIMValue<stringDSDKAdapter> (cs.getCIMObject ()->getName ()));
	inst.setProperty ("UserID", toCCIMValue<stringDSDKAdapter> (user_id));
	inst.setProperty ("UserPassword", toCCIMValue<stringDSDKAdapter> (strToOctet (password)));

	vector<_name_value_pair> account_template;
	account_template.push_back (_name_value_pair ("AccountTemplate", toCCIMValue<CCIMInstance>  (inst)));

	vector<string> ignore;
	ignore.push_back ("AccountTemplate");
	bool prop = false;
	vector<uint16> states_support = rbc.getOperationsSupported();
	for (size_t i =0; i < rbc.getOperationsSupported().size(); i++)
	{
		if(states_support[i] == 2)
		{
			uint32 status = ams.CreateAccount (*(cs.getCIMObject ()), "", &account, &identity, ignore, account_template);

			/* if create account is success return the created user, 
				else throw EFunctionReturnedWithFailure execption */
			if (0 == status)
			{
				account.initialize (client);
				account.setUserID (user_id);
				account.setUserPassword (passwords);
				account.setElementName (user_id + " Account");
				account.setOrganizationName (organizationnames);
				CUser user = CUser(account);
				user.enableUser ();
				return user;
			}
			else 
			{
				string  retcodestr = ams.getValueStr_CreateAccount_ReturnCode (status);
				throw EFunctionReturnedWithFailure ("CIM_AccountManagementService::CreateAccount", 
													retcodestr, status);
			}

		}
	}
	if (prop == false){throw EFunctionNotSupported ("createUser");}
	throw EFunctionNotSupported ("Create Account Method not Supported");
}


/*
 * deleteUser
 */
void
CUser::deleteUser (void)
{
	_user->getClient ()->deleteInstance (_user->getObjectPath ());
}

/*
 * EnableUser
 */
uint32
CUser::enableUser (void)
{
	datetime 		immediate = CCIMDateTime (0, true);
	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

	if ( capableOfRequestStateChange() == false ){
		throw EFunctionNotSupported ("CIM_Account::RequestStateChange Method not supported");
	}

	vector<string> ignore;
	ignore.push_back ("TimeoutPeriod");
	uint32 ret = _user->RequestStateChange (CIM_EnabledLogicalElement::RequestStateChange_RequestedState_Enabled,
											&job, immediate, ignore);
	if (ret != 0) 
	{
		string retcodestr = _user->getValueStr_RequestStateChange_ReturnCode(ret);
		throw EFunctionReturnedWithFailure ("CIM_Account::RequestStateChange", retcodestr, ret);
	}

	return ret;
}


/*
 * disableUser
 */
uint32
CUser::disableUser (void)
{
	datetime 		immediate = CCIMDateTime (0, true);
	CIM_ConcreteJob	job (CCIMInstance::nullInstance ());

	if ( capableOfRequestStateChange() == false )
		throw EFunctionNotSupported ("CIM_Account::RequestStateChange Method not supported");

	vector<string> ignore;
	ignore.push_back ("TimeoutPeriod");
	uint32 ret = _user->RequestStateChange (CIM_EnabledLogicalElement::RequestStateChange_RequestedState_Disabled,
											&job, immediate, ignore);
	if (ret != 0) 
	{
		string retcodestr = _user->getValueStr_RequestStateChange_ReturnCode(ret);
		throw EFunctionReturnedWithFailure ("CIM_Account::RequestStateChange", retcodestr, ret);
	}

	return ret;
}

///*
// * set Name /Modify the name 
// */
//void 
//CUser::setName (string name)
//{
//	((CUser*)this)->_user->setName(name);
//	((CUser*)this)->_user->setUserID(name);
//}

/*
 * set password /Modify the password  
 */
void 
CUser::changePassword (string password)
{
	vector <string>		passwords;
	passwords.push_back (strToOctet (password));
	((CUser*)this)->_user->setUserPassword(passwords);
}
/*
 * getUserRoles
 */
vector <CRole> 
CUser::getUserRoles (void) const
{
	vector <string>		props = getCachedProps();
	vector <CRole>		associated_roles;

	/* get the user identity */
	CIM_Identity::iterator identities = 
		CIM_AssignedIdentity <CIM_Identity, 
		CIM_Account>::enumerateIdentityInfo (this->_user->getClient (), *(this->_user), props);
	if (identities == CIM_Identity::iterator::end ())
	{
		return associated_roles;
	}

	for (;identities != CIM_Identity::iterator::end (); ++identities)
	{
		CIM_Identity id = *identities;

		CIM_Role::iterator roles = 
			CIM_MemberOfCollection <CIM_Role, CIM_Identity>::enumerateCollection 
										(id.getClient (), id, props);
		if (roles == CIM_Role::iterator::end ())
		{
			continue;
		}

		for (;roles != CIM_Role::iterator::end (); ++roles)
		{
			CRole role (*roles);

			associated_roles.push_back (role);
		}
	}
	
	return associated_roles;
}

/*
 * assignRoles
 */
void
CUser::assignRoles (const vector<string>& roles)
{
	vector<string>		props,empty_props;
	props.push_back("ElementName");
	IClient*			client;
	vector<CIM_Role>	_roles;

	client = this->_user->getClient();

	/* find the identity for this user */
	CIM_Identity::iterator identities = 
		CIM_AssignedIdentity <CIM_Identity, CIM_Account>::enumerateIdentityInfo (client, 
																*(this->_user), empty_props);
	if (identities == CIM_Identity::iterator::end ())
	{
		return;
	}

	/* Enumerate the all available roles */
	CIM_Role::iterator iter = CIM_Role::enumInstances (client, 0, props);
	for (;iter != CIM_Role::iterator::end (); ++iter)
	{
		CIM_Role role = *iter;
		for (size_t i = 0; i < roles.size (); i++)
		{
			if (role.getElementName () == roles [i])
			{
				_roles.push_back (role);
			}
		}
	}

	if (_roles.size () == 0)
	{
		throw EDSDKError (DSDK_INVALID_ROLE);
	}

	/* get all the roles associated with this user/identity and append to new list of roles */
	CIM_Role::iterator currentroles = CIM_MemberOfCollection <CIM_Role, CIM_Identity>::enumerateCollection 
									(client, *identities, props);
	for (; currentroles != CIM_Role::iterator::end (); ++currentroles)
	{
		CIM_Role role = *currentroles;
		string name   = role.getElementName ();
		bool append   = true;

		for (size_t i = 0; i < _roles.size (); i++)
		{
			if (name == _roles [i].getElementName ())
			{
				append = false;
			}
		}

		if (append) { _roles.push_back (role); }
	}

	CIM_RoleBasedAuthorizationService rbas(CCIMInstance::nullInstance());
	if(capableOfAssignRoles(rbas) == false) {
		throw EFunctionNotSupported ("assignRoles");
	}
	uint32 status = rbas.AssignRoles (*identities, _roles);

	/* if assign role is success return, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return;
	}
	else 
	{
		string  retcodestr = rbas.getValueStr_AssignRoles_ReturnCode (status);
		throw EFunctionReturnedWithFailure ("CIM_RoleBasedAuthorizationService::AssignRoles", 
											retcodestr, status);
	}
}


/*
 * removeRoles
 */
void
CUser::removeRoles (const vector<string>& roles)
{
	vector<string>		empty_props,props;
	props.push_back("ElementName");
	IClient*			client;
	vector<CIM_Role>	_roles;
	bool				rolematch = false;

	client = this->_user->getClient();

	/* find the identity for this user */
	CIM_Identity::iterator identities = 
		CIM_AssignedIdentity <CIM_Identity, CIM_Account>::enumerateIdentityInfo (client, 
																*(this->_user), empty_props);
	if (identities == CIM_Identity::iterator::end ())
	{
		return;
	}

	CIM_Identity id = *identities;

	/* get all the roles associated with this user/identity */
	CIM_Role::iterator roleiter = CIM_MemberOfCollection <CIM_Role, CIM_Identity>::enumerateCollection 
									(client, id, props);
	for (; roleiter != CIM_Role::iterator::end (); ++roleiter)
	{
		CIM_Role role	= *roleiter;
		//string rolename = role.getName ();
		string rolename = role.getElementName ();
		bool dontdelete = true;
		
		for (size_t i = 0; i < roles.size (); i++)
		{
			if (rolename == roles [i])
			{
				dontdelete = false; 
				rolematch  = true; /* make sure atleast one role match the given role name */
			}
		}
		
		/* create a new array for */
		if (dontdelete)
		{
			_roles.push_back (role);
		}
	}

	if (!rolematch)
	{
		throw EDSDKError (DSDK_INVALID_ROLE);
	}

	CIM_RoleBasedAuthorizationService rbas(CCIMInstance::nullInstance());
	if(capableOfRemoveRoles(rbas) == false) {
		throw EFunctionNotSupported ("removeRoles");
	}

	uint32 status = rbas.AssignRoles (*identities, _roles);

	/* if assign role is success return, else throw EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return;
	}
	else 
	{
		string  retcodestr = rbas.getValueStr_AssignRoles_ReturnCode (status);
		throw EFunctionReturnedWithFailure ("CIM_RoleBasedAuthorizationService::AssignRoles", 
											retcodestr, status);
	}
}

bool CUser::capableOfRequestStateChange()
{
	vector<string>	empty_props;

	vector<uint16> caps = CCIMCapabilities::getSupportedStates(this->_user->getClient(), *(this->_user));

	/* As per spec, the CIM_EnabledLogicalElementCapabilities.RequestedStatesSupported property should contain
	at least one value */
	if ( caps.size() == 0)
		return false;

	return true;
}

bool CUser::getRequestedStatesSupportedStr(vector<string> &states)
{
	states = CCIMCapabilities::getSupportedStatesStr(this->_user->getClient(), *(this->_user));
	if ( states.size()== 0)
		return false;

	return true;
}

/**
*/
bool
CUser::capableOfAccountManagementService(CComputerSystem cs, CIM_AccountManagementService &ams,
						   CIM_AccountManagementCapabilities &amc)
{
	vector<string>	empty_props;

	/* enumereate the CComputerSystem instance associated wiht CIM_Account through CIM_AccountOnSystem */
	CIM_ComputerSystem::iterator csiter = CIM_AccountOnSystem<CIM_ComputerSystem, 
		CIM_Account>::enumerateGroupComponent(this->_user->getClient(), *(this->_user), empty_props);
	if ( csiter == CIM_ComputerSystem::iterator::end () )
		return false;

	cs = *csiter;

	/* Enumerate the Account Management Service with this CS */
	CIM_AccountManagementService::iterator iter =CIM_HostedService <CIM_ComputerSystem, 
		CIM_AccountManagementService>::enumerateDependent (this->_user->getClient(),
												 *(cs.getCIMObject ()), empty_props);
	
	if (iter == CIM_AccountManagementService::iterator::end ())
	{
		return false;
	}
	ams = *iter;
	/* To check the support for the create account */
	CIM_AccountManagementCapabilities::iterator eleciter =
			CIM_ElementCapabilities <CIM_AccountManagementService, CIM_AccountManagementCapabilities>::
			enumerateCapabilities (this->_user->getClient(), ams, empty_props);

	if (eleciter == CIM_AccountManagementCapabilities::iterator::end ())
	{
		return false;
	} 
	
	amc = *eleciter;
	return true;
}
/**
*/
bool
CUser::capableOfAccountManagementService()
{
	CComputerSystem cs (CCIMInstance::nullInstance());
	CIM_AccountManagementService ams (CCIMInstance::nullInstance());
	CIM_AccountManagementCapabilities amc (CCIMInstance::nullInstance());
	return capableOfAccountManagementService(cs, ams, amc);
}

/**
*/
bool
CUser::isMethodSupported(CIM_AccountManagementCapabilities &amc, uint16 method)
{
	// Get the OperationsSupported property values from CIM_AccountManagementCapabilities service instance.
	vector<uint16> methods_val = amc.getOperationsSupported();
	if ( methods_val.size() == 0 )
		return false;

	// verify whether the OperationsSupported propery contains value for CreateUser
	for (size_t i=0; i < methods_val.size(); i++)
	{
		if ( methods_val[i] == method)
			return true;
	}

	return false;
}
/**
*/
bool
CUser::capableOfCreateUser(CComputerSystem cs, CIM_AccountManagementService &ams,
						   CIM_AccountManagementCapabilities &amc)
{
	// Verify whether all the services instances exists or not
	if ( capableOfAccountManagementService(cs, ams, amc) == false )
		return false;

	return isMethodSupported(amc, CIM_AccountManagementCapabilities::OperationsSupported_Create);
}
/**
*/
bool
CUser::capableOfCreateUser()
{
	CComputerSystem cs (CCIMInstance::nullInstance());
	CIM_AccountManagementService ams (CCIMInstance::nullInstance());
	CIM_AccountManagementCapabilities amc (CCIMInstance::nullInstance());
	return capableOfCreateUser(cs, ams, amc);
}

/**
*/
bool
CUser::capableOfDeleteUser(CComputerSystem cs, CIM_AccountManagementService &ams,
						   CIM_AccountManagementCapabilities &amc)
{
	// Verify whether all the services instances exists or not
	if ( capableOfAccountManagementService(cs, ams, amc) == false )
		return false;

	return isMethodSupported(amc, CIM_AccountManagementCapabilities::OperationsSupported_Delete);
}

/**
*/bool
CUser::capableOfDeleteUser()
{
	CComputerSystem cs (CCIMInstance::nullInstance());
	CIM_AccountManagementService ams (CCIMInstance::nullInstance());
	CIM_AccountManagementCapabilities amc (CCIMInstance::nullInstance());
	return capableOfDeleteUser(cs, ams, amc);
}

/**
*/
bool
CUser::capableOfModifyUser(CComputerSystem cs, CIM_AccountManagementService &ams,
						   CIM_AccountManagementCapabilities &amc)
{
	// Verify whether all the services instances exists or not
	if ( capableOfAccountManagementService(cs, ams, amc) == false )
		return false;

	return isMethodSupported(amc, CIM_AccountManagementCapabilities::OperationsSupported_Modify);
}

/**
*/
bool
CUser::capableOfModifyUser()
{
	CComputerSystem cs (CCIMInstance::nullInstance());
	CIM_AccountManagementService ams (CCIMInstance::nullInstance());
	CIM_AccountManagementCapabilities amc (CCIMInstance::nullInstance());
	return capableOfModifyUser(cs, ams, amc);
}

/**
*/
bool
CUser::capableOfAssignRoles(CIM_RoleBasedAuthorizationService &rbas)
{
	return capableOfRoleBasedAuthorizationService(rbas);
}
/**
*/
bool
CUser::capableOfAssignRoles()
{
	CIM_RoleBasedAuthorizationService rbas(CCIMInstance::nullInstance());
	return capableOfRoleBasedAuthorizationService(rbas);
}
/**
*/
bool
CUser::capableOfRemoveRoles(CIM_RoleBasedAuthorizationService &rbas)
{
	return capableOfRoleBasedAuthorizationService(rbas);
}
/**
*/
bool
CUser::capableOfRemoveRoles()
{
	CIM_RoleBasedAuthorizationService rbas(CCIMInstance::nullInstance());
	return capableOfRoleBasedAuthorizationService(rbas);
}
/**
*/
bool
CUser::capableOfRoleBasedAuthorizationService(CIM_RoleBasedAuthorizationService &rbas)
{

	vector<string>	empty_props;
	/* Enumerate the Role based authorization service */
	CIM_RoleBasedAuthorizationService::iterator rbasiter =
		CIM_RoleBasedAuthorizationService::enumInstances (this->_user->getClient(),
		0,
		empty_props);
	if (rbasiter == CIM_RoleBasedAuthorizationService::iterator::end ())
	{
		return false;
	}

	/* Only one Role based authorization service will be supported so use the first instance */
	rbas = *rbasiter;
	return true;
}
/**
*/
bool
CUser::capableOfRoleBasedAuthorizationService()
{
	CIM_RoleBasedAuthorizationService rbas(CCIMInstance::nullInstance());
	return capableOfRoleBasedAuthorizationService(rbas);
}

/*
 * getCachedProps
 */
vector<string> 
CUser::getCachedProps (void)
{
	vector<string> props;
	props.push_back ("SystemCreationClassName");
	props.push_back ("CreationClassName");
	props.push_back ("SystemName");
	props.push_back ("Name");
	props.push_back ("UserID");
	props.push_back ("UserPassword");
	props.push_back ("OrganizationName");
	props.push_back ("ElementName");
	props.push_back ("UserPasswordEncryptionAlgorithm");
	props.push_back ("OtherUserPasswordEncryptionAlgorithm");
	props.push_back ("PasswordHistoryDepth");
	props.push_back ("ComplexPasswordRulesEnforced");
	props.push_back ("MaximumSuccessiveLoginFailures");
	props.push_back ("RequestedState");
	props.push_back ("EnabledState");
	props.push_back ("InstanceID");
	return props;
}


/*
 * CUser::Iterator
 */
DEFINE_API_ITERATOR (CUser);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CUser, CIM_Account);




/*
 * Constructor
 */
CRole::CRole (const CIM_Role& role)
{ 
	_role = new CIM_Role (role); 
}

/*
 * Constructor
 */
CRole::CRole (const CRole& role)
{
	this->_role = new CIM_Role (*(role._role));
}

/*
 * Destruction 
 */
CRole::~CRole ()
{
	if (this->_role) { delete this->_role; }
}

/*
 * Assignment operator
 */
const CRole& 
CRole::operator = (const CRole& rhs)
{
	if (this->_role) { delete this->_role; }
	this->_role  = new CIM_Role (*rhs._role);
	return *this;
}


/*
 * enumerateUsers
 */
CRole::iterator 
CRole::enumRoles (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_Role::iterator iter = 
		CIM_Role::enumInstances (client, 0, props);

	if (cached) { return createIterator (iter, props);  	  }
	else 		{ return createIterator (iter); }
}

/*
 * getCreationClassName
 */
string 
CRole::getCreationClassName (void) const
{
	return this->_role->getCreationClassName ();
}

/*
 * getName
 */
string 
CRole::getName (void) const
{
	return this->_role->getName ();
}

/*
 * getRoleCharacteristics
 */
vector<uint16>
CRole::getRoleCharacteristics (void) const
{
	return this->_role->getRoleCharacteristics ();
}

/*
 * getCommonName
 */
string 
CRole::getCommonName (void) const
{
	return this->_role->getCommonName ();
}

/*
 * getElementName
 */
string 
CRole::getElementName (void) const
{
	return this->_role->getElementName ();
}

string
CRole::displayPrivileges(void){

return this->_role->getElementName ();
}
/*
 * createRole 
 */
CRole 
CRole::createRole (const CComputerSystem& cs, 
				   const string& rolename, 
				   const vector<CRole::Permission_T>& permissions)
{
	vector<string>	empty_props;
	IClient* client = cs.getCIMObject ()->getClient ();

	/* Enumerate the Role based authorization service with this CS */
	//CIM_RoleBasedAuthorizationService::iterator iter =
	//	CIM_HostedService <CIM_ComputerSystem, 
	//	CIM_RoleBasedAuthorizationService>::enumerateDependent (client,
	//															*(cs.getCIMObject ()),
	//															empty_props);

	//if (iter == CIM_RoleBasedAuthorizationService::iterator::end ())
	//{
	//	throw EFunctionNotSupported ("createRole");
	//}

	/* Only one Role based authorization service will be supported so use the first instance */
	// CIM_RoleBasedAuthorizationService rbas = *iter;
	CIM_RoleBasedAuthorizationService rbas(CCIMInstance::nullInstance());

	CRole Cr(CCIMInstance::nullInstance ());

	if( Cr.capableOfCreateRole(rbas) == false) {
		throw EFunctionNotSupported ("createRole");
	}

	/* create the privilege template */
	vector <string>		priv_templates;	
	string				activity_template;
	string				qualifier_template;	
	vector<_name_value_pair> role_template123;
	boolean privilege_granted;
	string privilege_elementname;
	string privilege_InstanceID;
	string qualifier_format;
	boolean RepresentsAuthorizationRights;
	string qualifier1;

	/*create a new CIM_Role instance */
	CCIMObjectPath ObjectPath ("","http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Role");
	CCIMInstance inst (ObjectPath);
	inst.setProperty ("CommonName",toCCIMValue<stringDSDKAdapter>  (rolename));
	inst.setProperty ("CreationClassName",toCCIMValue<stringDSDKAdapter> ("DRI_Role"));
	inst.setProperty ("ElementName", toCCIMValue<stringDSDKAdapter> (rolename));
	inst.setProperty ("Name", toCCIMValue<stringDSDKAdapter> (rolename));

	
	role_template123.push_back (_name_value_pair ("RoleTemplate", toCCIMValue<CCIMInstance>  (inst)));

	CCIMObjectPath ObjectPathPriv ("","http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Privilege");	

	for(size_t iPer = 0;iPer < permissions.size(); iPer++)
	 {
		 qualifier1 = permissions[iPer].qualifier;
		 uint16 actc = (uint16)permissions[iPer].activity;
		 string activity = CIM_Privilege::getValueStr_Activities(actc);
		 
		 std::transform(qualifier1.begin(), qualifier1.end(), qualifier1.begin(), ::toupper);		 
		 CPrivilege::iterator privIter = CPrivilege::enumPrivileges(client,false);
		 bool prop = false;
		 for (; privIter != CPrivilege::iterator::end (); ++privIter)
		 {
			CPrivilege privInst = *privIter;
			string d_act1 = activity;
			std::transform(d_act1.begin(), d_act1.end(), d_act1.begin(), ::toupper);
			string ElementName = privInst.getElementName();
			std::transform(ElementName.begin(), ElementName.end(), ElementName.begin(), ::toupper);
			if(ElementName.find(qualifier1,0) == 0 || privInst.getInstanceID().find(qualifier1,0) == 0 || ElementName == qualifier1) 
			{
				if (activity == "other"){
					prop = true;
					
				}
				else {
					if(ElementName.find(d_act1,0) != -1)
					{
						prop = true;
					}
				}
				if (prop == true) {
					/*create a new CIM_Privilege instance */
					
					CCIMInstance inst1 (ObjectPathPriv);
					privilege_granted = privInst.getPrivilegeGranted();
					privilege_elementname = privInst.getElementName();
					privilege_InstanceID = privInst.getInstanceID();
					RepresentsAuthorizationRights = privInst.getRepresentsAuthorizationRights();
					vector <uint16> priv_activities = privInst.getActivities();
					for (size_t i = 0; i < priv_activities.size(); i++)
					{
						char privactivities[MAX_SIZE];
						string activitiesstr;
						sprintf(privactivities,"%d",priv_activities[i]);
						activitiesstr += privactivities;
						activity_template = activitiesstr;	
						inst1.setProperty ("Activities",toCCIMValue<stringDSDKAdapter> (activity_template));
					
					}
					vector <uint16> qualifierformats = privInst.getQualifierFormats();
					for (size_t i = 0; i < qualifierformats.size(); i++)
					{
						char qualifierformat[MAX_SIZE];
						string qualifierstr;
						sprintf(qualifierformat,"%d",qualifierformats[i]);
						qualifierstr += qualifierformat;
						qualifier_format = qualifierstr;
						inst1.setProperty ("QualifierFormats",toCCIMValue<stringDSDKAdapter>(qualifier_format));
					}
					vector <string> priv_qualifier = privInst.getActivityQualifiers();
					for (size_t i = 0; i < priv_qualifier.size(); i++)
					{
						qualifier_template = priv_qualifier[i];		
						inst1.setProperty ("ActivityQualifiers",toCCIMValue<stringDSDKAdapter> (qualifier_template));
					}
				   inst1.setProperty ("ElementName", toCCIMValue<stringDSDKAdapter> (privilege_elementname));
				   inst1.setProperty ("InstanceID", toCCIMValue<stringDSDKAdapter> (privilege_InstanceID));
				   inst1.setProperty ("PrivilegeGranted",toCCIMValue<booleanDSDKAdapter> (privilege_granted));
				   inst1.setProperty ("QualifierFormats",toCCIMValue<stringDSDKAdapter>(qualifier_format));
				   inst1.setProperty ("RepresentsAuthorizationRights", toCCIMValue<booleanDSDKAdapter> (RepresentsAuthorizationRights));
				   role_template123.push_back (_name_value_pair ("Privileges", toCCIMValue<CCIMInstance>  (inst1)));
						   
				  break;
				}
			}
		}
	 }
	string role_templates;	

	vector<string> ignore;
	ignore.push_back ("RoleTemplate");
	ignore.push_back ("Privileges");	

	/* Create the role using role based authorization  service */
	CIM_Role				role (CCIMInstance::nullInstance ());
	vector <CIM_ManagedElement>		role_limited_to;
	role_limited_to.push_back (*(cs.getCIMObject ()));

	uint32 status = rbas.CreateRole (role_templates, *(cs.getCIMObject ()), priv_templates,
							  role_limited_to, &role, ignore , role_template123);


	/* if create role is success return the created role, else throw 
											EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return CRole (role);
	}
	else 
	{
		string  retcodestr = rbas.getValueStr_CreateRole_ReturnCode (status);
		throw EFunctionReturnedWithFailure ("CIM_RoleBasedAuthorizationService::CreateRole", 
											retcodestr, status);
	}
}

bool
CRole::capableOfRoleBasedAuthorizationService(CIM_RoleBasedAuthorizationService &rbas, CIM_RoleBasedManagementCapabilities &rbmc) 
{

	vector<string>	empty_props;
	/* Enumerate the Role based authorization service */
	CIM_RoleBasedAuthorizationService::iterator rbasiter =
		CIM_ServiceAffectsElement <CIM_Role, CIM_RoleBasedAuthorizationService>::
				enumerateAffectingElement (_role->getClient (), *_role,	empty_props);

	if (rbasiter == CIM_RoleBasedAuthorizationService::iterator::end ())
	{
		return false;
	}

	/* Only one Role based authorization service will be supported so use the first instance */
	rbas = *rbasiter;

	CIM_RoleBasedManagementCapabilities::iterator rbmciter = CIM_ElementCapabilities<CIM_RoleBasedAuthorizationService,
		CIM_RoleBasedManagementCapabilities>::enumerateCapabilities(_role->getClient(), rbas, empty_props);


	if (rbmciter == CIM_RoleBasedManagementCapabilities::iterator::end ())
	{
		return false;
	}
	rbmc = * rbmciter;

	return true;
}

bool
CRole::capableOfRoleBasedAuthorizationService()
{
	CIM_RoleBasedAuthorizationService rbas(CCIMInstance::nullInstance());
	CIM_RoleBasedManagementCapabilities rbmc (CCIMInstance::nullInstance());
	return capableOfRoleBasedAuthorizationService(rbas, rbmc);
}

bool
CRole::isMethodSupported(CIM_RoleBasedAuthorizationService &rbas, uint16 method)
{
	CIM_RoleBasedManagementCapabilities rbmc (CCIMInstance::nullInstance());

	if( capableOfRoleBasedAuthorizationService(rbas, rbmc) == false )
		return false;

	vector<uint16> method_val = rbmc.getSupportedMethods();
	if ( method_val.size() == 0)
		return false;
	for ( size_t i=0; i < method_val.size(); i++)
	{
		if ( method_val[i] == method)
			return true;
	}
	return false;
}


bool CRole::getSupportedMethodsStr(vector<string> &methods_str)
{
	CIM_RoleBasedAuthorizationService rbas (CCIMInstance::nullInstance());
	CIM_RoleBasedManagementCapabilities rbmc (CCIMInstance::nullInstance());
	if( capableOfRoleBasedAuthorizationService(rbas, rbmc) == false )
		return false;

	vector <uint16> methods_val = rbmc.getSupportedMethods();
	if ( methods_val.size()== 0)
		return false;
	for ( size_t i=0; i < methods_val.size(); i++)
	{
		methods_str.push_back(rbmc.getValueStr_SupportedMethods(methods_val[i]) );
	}
	return true;
}


/**
* capableOfCreateRole
*/
bool
CRole::capableOfCreateRole(CIM_RoleBasedAuthorizationService &rbas)
{
	return isMethodSupported(rbas, CIM_RoleBasedManagementCapabilities::SupportedMethods_CreateRole);
}

/**
* capableOfCreateRole
*/
bool 
CRole::capableOfCreateRole()
{
	CIM_RoleBasedAuthorizationService rbas(CCIMInstance::nullInstance());
	return capableOfCreateRole(rbas);
}

bool
CRole::capableOfModifyRole(CIM_RoleBasedAuthorizationService &rbas)
{
	return isMethodSupported(rbas, CIM_RoleBasedManagementCapabilities::SupportedMethods_ModifyRole);
}


bool 
CRole::capableOfModifyRole()
{
	CIM_RoleBasedAuthorizationService rbas(CCIMInstance::nullInstance());
	return capableOfModifyRole(rbas);
}

bool
CRole::capableOfAssignRoles(CIM_RoleBasedAuthorizationService &rbas)
{
	return isMethodSupported(rbas, CIM_RoleBasedManagementCapabilities::SupportedMethods_AssignRoles);
}


bool 
CRole::capableOfAssignRoles()
{
	CIM_RoleBasedAuthorizationService rbas(CCIMInstance::nullInstance());
	return capableOfAssignRoles(rbas);
}

bool
CRole::capableOfShowRoles(CIM_RoleBasedAuthorizationService &rbas)
{
	return isMethodSupported(rbas, CIM_RoleBasedManagementCapabilities::SupportedMethods_ShowRoles);
}


bool 
CRole::capableOfShowRoles()
{
	CIM_RoleBasedAuthorizationService rbas(CCIMInstance::nullInstance());
	return capableOfShowRoles(rbas);
}

bool
CRole::capableOfShowAccess(CIM_RoleBasedAuthorizationService &rbas)
{
	return isMethodSupported(rbas, CIM_RoleBasedManagementCapabilities::SupportedMethods_ShowAccess);
}


bool 
CRole::capableOfShowAccess()
{
	CIM_RoleBasedAuthorizationService rbas(CCIMInstance::nullInstance());
	return capableOfShowAccess(rbas);
}


/*
 * deleteRole 
 */
void
CRole::deleteRole (void)
{


	///* Enumerate the Role based authorization service with this CS */
	//CIM_RoleBasedAuthorizationService::iterator iter =
	//	CIM_ServiceAffectsElement <CIM_Role, 
	//	CIM_RoleBasedAuthorizationService>::enumerateAffectingElement (_role->getClient (),
	//															*_role,
	//															empty_props);

	//if (iter == CIM_RoleBasedAuthorizationService::iterator::end ())
	//{
	//	throw EFunctionNotSupported ("deleteRole");
	//}

	//CIM_RoleBasedAuthorizationService rbas = *iter;
	/* Delete the role using role based authorization  service */
	CIM_RoleBasedAuthorizationService rbas(CCIMInstance::nullInstance());
	if(capableOfDeleteRole(rbas) == false) {
		throw EFunctionNotSupported ("deleteRole");
	}

	uint32 status = rbas.DeleteRole (*_role);
	/* if delete role is success return, else throw 
											EFunctionReturnedWithFailure execption */
	if (0 == status)
	{
		return;
	}
	else 	{
		string  retcodestr = rbas.getValueStr_DeleteRole_ReturnCode (status);
		throw EFunctionReturnedWithFailure ("CIM_RoleBasedAuthorizationService::DeleteRole", 
											retcodestr, status);
	}
}

bool
CRole::capableOfDeleteRole(CIM_RoleBasedAuthorizationService &rbas)
{
//	vector<string>	empty_props;

	/* Enumerate the Role based authorization service with this CS */
/*
	CIM_RoleBasedAuthorizationService::iterator iter =
		CIM_ServiceAffectsElement <CIM_Role, 
		CIM_RoleBasedAuthorizationService>::enumerateAffectingElement (_role->getClient (),
																*_role,
																empty_props);

	if (iter == CIM_RoleBasedAuthorizationService::iterator::end ())
	{
		return false;
	}

	rbas = *iter;
	return true;
*/

	return isMethodSupported(rbas, CIM_RoleBasedManagementCapabilities::SupportedMethods_DeleteRole);

}

bool
CRole::capableOfDeleteRole()
{
	CIM_RoleBasedAuthorizationService rbas(CCIMInstance::nullInstance());
	return capableOfDeleteRole(rbas);
}
/*
 * Role Support for Modify roles and delete roles.
 */

/* vector<uint16> 
CRole::roleSupport(void)const
{

vector<string>	empty_props;
	/* Enumerate the Role based authorization service with this CS */
/*	CIM_RoleBasedAuthorizationService::iterator iter =
		CIM_ServiceAffectsElement <CIM_Role, 
		CIM_RoleBasedAuthorizationService>::enumerateAffectingElement (_role->getClient (),
																*_role,
																empty_props);

	if (iter == CIM_RoleBasedAuthorizationService::iterator::end ())
	{
		throw EFunctionNotSupported ("CIM_RoleBasedAuthorizationService Instances are not found.");
	}

	/* Only one Role based authorization service will be supported so use the first instance */ 
/*	CIM_RoleBasedAuthorizationService rbas = *iter;

	CIM_RoleBasedManagementCapabilities::iterator eleciter =
			CIM_ElementCapabilities <CIM_RoleBasedAuthorizationService, CIM_RoleBasedManagementCapabilities>::
			enumerateCapabilities (_role->getClient (), rbas ,empty_props);

	if (eleciter == CIM_RoleBasedManagementCapabilities::iterator::end ())
	{
		// error no association instance found
		fprintf (stdout, "CIM_RoleBasedManagementCapabilities is not Found:");
		throw EFunctionNotSupported ("User:RequestedState supported not available");
		//return -1;
	} 

	CIM_RoleBasedManagementCapabilities rms = *eleciter;
	return rms.getSupportedMethods();
} */

/*
 * modifyRole 
 */
//void
//CRole::modifyRole (const vector<CRole::Permission_T>& permissions)
//{
//	vector<string>	empty_props;
//
//	/* Enumerate the Role based authorization service with this CS */
//	CIM_RoleBasedAuthorizationService::iterator iter =
//		CIM_ServiceAffectsElement <CIM_Role, 
//		CIM_RoleBasedAuthorizationService>::enumerateAffectingElement (_role->getClient (),
//																*_role,
//																empty_props);
//
//	if (iter == CIM_RoleBasedAuthorizationService::iterator::end ())
//	{
//		throw EFunctionNotSupported ("deleteRole");
//	}
//
//	/* Only one Role based authorization service will be supported so use the first instance */
//	CIM_RoleBasedAuthorizationService rbas = *iter;
//	
//	/* modify the role using role based authorization  service */
//	vector <CIM_ManagedElement>		role_limited_to;
//	
//	/* create the privilege template */
//	vector <string>		priv_templates;
//	string				priv_template;
//	string				activity_template;
//	string				qualifier_template;
//	string				format_template;
//
//	activity_template  = "Activities={";
//	qualifier_template = "ActivityQualifiers={";
//
//	for (size_t i = 0; i < permissions.size (); i++)
//	{
//			
//			char str[MAX_SIZE]; 
//			string sstr;
//
//			sprintf(str,"%d",permissions [i].activity);
//			sstr += str;
//
//			activity_template += "\"" + sstr + "\"";
//			if (i < (permissions.size () - 1)) { activity_template += ","; }
//
//			qualifier_template += "\"" + permissions [i].qualifier + "\"";
//			if (i < (permissions.size () - 1) ) { qualifier_template += ",";}
//	}
//
//	activity_template  += "};";
//	qualifier_template  += "};";
//
//	priv_template = "Instance of CIM_Privilege { InstanceID=\"" + getName () + "priv\";	\
//                        RepresentsAuthorizationRights=\"true\";					\
//                        PrivilegeGranted=\"true\";" + 
//                        activity_template + 
//                        qualifier_template + 
//                        format_template + "};";
//
//	priv_templates.push_back (priv_template);
//
//	uint32 status = rbas.ModifyRole (priv_templates, role_limited_to, *_role);
//	/* if modify role is success return, else throw EFunctionReturnedWithFailure execption */
//	if (0 == status)
//	{
//		return;
//	}
//	else 
//	{
//		string  retcodestr = rbas.getValueStr_ModifyRole_ReturnCode (status);
//		throw EFunctionReturnedWithFailure ("CIM_RoleBasedAuthorizationService::ModifyRole", 
//											retcodestr, status);
//	}
//
//	return;
//}


/*
 * getPrivileges
 */
vector<CRole::Permission_T> 
CRole::getPermissions (void) const
{
	vector<string>		props;
	vector<CIM_Privilege>		privileges;

	props.push_back ("InstanceID");
	props.push_back ("ElementName");
	props.push_back ("Activities");
	props.push_back ("ActivityQualifiers");
	props.push_back ("QualifierFormats");

	CIM_Privilege::iterator iter =
		CIM_MemberOfCollection <CIM_Role, CIM_Privilege>::enumerateMember
									(_role->getClient (), *_role, props);
	for (; iter != CIM_Privilege::iterator::end (); ++iter)
	{
		CIM_Privilege privilege = *iter;
		privileges.push_back (privilege);
	}

	vector<Permission_T>	permissions;
	vector <uint16>			activities;
	vector <string>			qualifiers;
	vector <uint16>			formats;
	string					instanceID;
	string					name;

	for (size_t i = 0; i < privileges.size (); i++)
	{
		Permission_T			permission;

		try	{ permission.instanceID  = privileges [i].getInstanceID();
		
		}
		catch (...) {}
		try	{ permission.elementName = privileges [i].getElementName();}
		catch (...) {}
		try	{ activities	= privileges [i].getActivities (); }
		catch (...) {}
		try { qualifiers	= privileges [i].getActivityQualifiers (); }
		catch (...) {}
		try { formats		= privileges [i].getQualifierFormats (); }
		catch (...) {}
		for (size_t i = 0; i < activities.size (); i++)
		{
			permission.activity		= (CRole::Activities_E)activities [i];
			permission.activity_str	= CIM_Privilege::getValueStr_Activities (activities [i]);

			if (i < qualifiers.size ()) { permission.qualifier = qualifiers [i]; }
			if (i < formats.size ())
			{ 
				permission.format_str    = CIM_Privilege::getValueStr_QualifierFormats (formats [i]); 
			}
		}

		permissions.push_back (permission);
	}

	return permissions;
}
/*
 * displayPrivileges
 */

vector<CRole::Permission_T> 
CRole::displayPermissions (void) const
{
	vector<string>		props;
	vector<CIM_Privilege>		privileges;
	props.push_back ("ElementName");
	CIM_Privilege::iterator iter =
		CIM_MemberOfCollection <CIM_Role, CIM_Privilege>::enumerateMember
									(_role->getClient (), *_role, props);


	for (; iter != CIM_Privilege::iterator::end (); ++iter)
	{
		CIM_Privilege privilege = *iter;
		privileges.push_back (privilege);
	}
	vector<Permission_T>	permissions;
	for (size_t i = 0; i < privileges.size (); i++)
	{
		Permission_T			permission;
		try	{ permission.elementName = privileges [i].getElementName();	}
		catch (...) {}
		permissions.push_back (permission);
		}
	

	return permissions;

}

/*
 * getSupportedActivityQualifiers
 */
vector<string> 
CRole::getSupportedActivityQualifiers (IClient* client)
 {
	vector<string> props;
	vector<string> qualifiers;

	CIM_RoleBasedManagementCapabilities::iterator iter = 
		CIM_RoleBasedManagementCapabilities::enumInstances (client, 0, props);
	if (iter != CIM_RoleBasedManagementCapabilities::iterator::end ())
	{
		qualifiers = (*iter).getActivityQualifiersSupported ();
	}

	return qualifiers;
 }


/*
 * getCachedProps
 */
vector<string> 
CRole::getCachedProps (void)
{
	vector<string> props;
	props.push_back ("CreationClassName");
	props.push_back ("Name");
	props.push_back ("RoleCharacteristics");
	props.push_back ("CommonName");
	props.push_back ("ElementName");

	return props;
}

void
CRole::modifyRole (IClient*client,string privilege,vector<CRole::Permission_T> permissions)
{
	/*enumerating all the privileges instances*/
	vector<string>		props;
	vector<string>	empty_props;

	/* Enumerate the Role based authorization service with this CS */
	CIM_RoleBasedAuthorizationService::iterator iter =
		CIM_ServiceAffectsElement <CIM_Role, 
		CIM_RoleBasedAuthorizationService>::enumerateAffectingElement (_role->getClient (),
																*_role,
																empty_props);

	if (iter == CIM_RoleBasedAuthorizationService::iterator::end ())
	{
		throw EFunctionNotSupported ("assignRole");
	}

	/* Only one Role based authorization service will be supported so use the first instance */
	CIM_RoleBasedAuthorizationService rbas = *iter;
	/* modify the role using role based authorization  service */
	vector <CIM_ManagedElement>		role_limited_to;
	
	/* create the privilege template */
	vector <string>		priv_templates;
	
	string qualifier1;
	boolean privilege_granted;
	string privilege_elementname;
	string privilege_InstanceID;
	string activity_template;
	string qualifier_template;
	string qualifier_format;
	vector<_name_value_pair> privilege_template;
	CCIMObjectPath ObjectPath ("","http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Privilege");
	
	 boolean RepresentsAuthorizationRights;
	 vector<CRole::Permission_T> permission = getPermissions ();
	 for(size_t iPer = 0;iPer < permissions.size(); iPer++)
	 {
		 //privilege = permissions[iPer].qualifier;
		 //qualifier1 = privilege.substr (privilege.find (',') + 1, privilege.size ());
		 qualifier1 = permissions[iPer].qualifier;
		 std::transform(qualifier1.begin(), qualifier1.end(), qualifier1.begin(), ::toupper);
		 //string activity = privilege.substr (0, privilege.find (','));

		 uint16 actc = (uint16)permissions[iPer].activity;
		 string activity = CIM_Privilege::getValueStr_Activities(actc);

		 CPrivilege::iterator privIter = CPrivilege::enumPrivileges(client,true);
		 bool prop = false;
		 for (; privIter != CPrivilege::iterator::end (); ++privIter)
		 {
			CPrivilege privInst = *privIter;
			string d_act1 = activity;
			std::transform(d_act1.begin(), d_act1.end(), d_act1.begin(), ::toupper);
			string ElementName = privInst.getElementName();
			std::transform(ElementName.begin(), ElementName.end(), ElementName.begin(), ::toupper);
			if(ElementName.find(qualifier1,0) == 0 || privInst.getInstanceID().find(qualifier1,0) == 0 || ElementName == qualifier1) 
			{
				if (activity == "other"){
					prop = true;
					
				}
				else {
					if(ElementName.find(d_act1,0) != -1)
					{
						prop = true;
					}
				}
				if (prop == true) {
					/*create a new CIM_Account instance */
					
					CCIMInstance inst (ObjectPath);
					privilege_granted = privInst.getPrivilegeGranted();
					privilege_elementname = privInst.getElementName();
					privilege_InstanceID = privInst.getInstanceID();
					RepresentsAuthorizationRights = privInst.getRepresentsAuthorizationRights();
					vector <uint16> priv_activities = privInst.getActivities();
					for (size_t i = 0; i < priv_activities.size(); i++)
					{
						char privactivities[MAX_SIZE];
						string activitiesstr;
						sprintf(privactivities,"%d",priv_activities[i]);
						activitiesstr += privactivities;
						activity_template = activitiesstr;	
						inst.setProperty ("Activities",toCCIMValue<stringDSDKAdapter> (activity_template));
					
					}
					vector <uint16> qualifierformats = privInst.getQualifierFormats();
					for (size_t i = 0; i < qualifierformats.size(); i++)
					{
						char qualifierformat[MAX_SIZE];
						string qualifierstr;
						sprintf(qualifierformat,"%d",qualifierformats[i]);
						qualifierstr += qualifierformat;
						qualifier_format = qualifierstr;
						inst.setProperty ("QualifierFormats",toCCIMValue<stringDSDKAdapter>(qualifier_format));
					}
					vector <string> priv_qualifier = privInst.getActivityQualifiers();
					for (size_t i = 0; i < priv_qualifier.size(); i++)
					{
						qualifier_template = priv_qualifier[i];		
						inst.setProperty ("ActivityQualifiers",toCCIMValue<stringDSDKAdapter> (qualifier_template));
					}
				   inst.setProperty ("ElementName", toCCIMValue<stringDSDKAdapter> (privilege_elementname));
				   inst.setProperty ("InstanceID", toCCIMValue<stringDSDKAdapter> (privilege_InstanceID));
				   inst.setProperty ("PrivilegeGranted",toCCIMValue<booleanDSDKAdapter> (privilege_granted));
				   inst.setProperty ("QualifierFormats",toCCIMValue<stringDSDKAdapter>(qualifier_format));
				   inst.setProperty ("RepresentsAuthorizationRights", toCCIMValue<booleanDSDKAdapter> (RepresentsAuthorizationRights));
				   privilege_template.push_back (_name_value_pair ("Privileges", toCCIMValue<CCIMInstance>  (inst)));
						   
				  break;
				}
			}
		}
	 }
		
		vector<string> ignore;
		ignore.push_back ("Privileges");
		uint32 status = rbas.ModifyRole (priv_templates, role_limited_to, *_role, ignore, privilege_template);
		/* if modify role is success return the created role, else throw 
							EFunctionReturnedWithFailure execption */
		if (0 == status)
		{
		return;
		}
		else 
		{
		string  retcodestr = rbas.getValueStr_ModifyRole_ReturnCode (status);
			throw EFunctionReturnedWithFailure ("CIM_RoleBasedAuthorizationService::ModifyRole", 
							retcodestr, status);
		}
}


/*
 * CRole::Iterator
 */
DEFINE_API_ITERATOR (CRole);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CRole, CIM_Role);



