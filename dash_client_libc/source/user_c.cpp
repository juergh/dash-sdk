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
 * user_c.cpp
 * C wrapper for user.
 */
#include <vector>
#include <string>
#include <cstring>
#include <dsdk/oal/COALObject.h>
#include <dsdkc/user_c.h>
#include <dsdk/user.h>
#include <dsdkc/error_c.h>
#include <dsdk/dsdkexception.h>

using namespace dsdk;

extern DSDKRoleFT _roleft;

/*
 * getCreationClassName
 */
extern "C" void 
role_getCreationClassName (DSDKRole* role, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CRole* _role = (CRole*) (role->hdl);
		string str = _role->getCreationClassName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * createRole
 */

extern "C" DSDKRole* 
role_createRole (DSDKComputerSystem*	   cs, 
				 char*					   rolename, 
				 RolePermission_T*		   permissions,
				 int					   num_permission)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		
		vector <CRole::Permission_T> _values;

		for (int i = 0; i < num_permission; i++)
		{
			CRole::Permission_T _permissions;
			_permissions.activity  = (CRole::Activities_E) permissions[i].activity;
			_permissions.qualifier = permissions[i].qualifier;
			_permissions.format    = (CRole::QualifierFormats_E)permissions[i].format;
			_values.push_back(_permissions);
		}

		CRole _role = CRole::createRole (*_cs, string (rolename),_values );
		
		DSDKRole * dsdk_role = new DSDKRole;

		dsdk_role->ft	= &_roleft;
		dsdk_role->hdl	= new CRole (_role);

		return dsdk_role;
	}
	CATCH_SET_ERROR ();
	return NULL;
}

/*
 * deleteRole
 */
extern "C" void 
role_deleteRole (DSDKRole* role)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CRole* _role = (CRole*) (role->hdl);
		_role->deleteRole ();
	}
	CATCH_SET_ERROR ();
}

/*
 * modifyRole
 */
//extern "C" void 
//role_modifyRole (DSDKRole* role, RolePermission_T*	permissions, int num_permission)
//{
//	dsdkc_setError (0, NULL);
//	try 
//	{
//		CRole* _role = (CRole*) (role->hdl);
//		
//		vector <CRole::Permission_T> _values;
//
//		for (int i = 0; i < num_permission; i++)
//		{
//			CRole::Permission_T _permissions;
//			_permissions.activity  = (CRole::Activities_E) permissions[i].activity;
//			_permissions.qualifier = permissions[i].qualifier;
//			_permissions.format    = (CRole::QualifierFormats_E)permissions[i].format;
//			_values.push_back(_permissions);
//		}
//
//		_role->modifyRole (_values);
//	}
//	CATCH_SET_ERROR ();
//}

/*
 * assignPermissions
 */
extern "C" void 
role_modifyRole (DSDKRole* role,DSDKClient* client,char * privilege,RolePermission_T* permissions,int num_permission)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CRole* _role = (CRole*) (role->hdl);
		

		vector <CRole::Permission_T> _values;

		for (int i = 0; i < num_permission; i++)
		{
			CRole::Permission_T _permissions;
			_permissions.activity  = (CRole::Activities_E) permissions[i].activity;
			_permissions.qualifier = permissions[i].qualifier;
			_permissions.format    = (CRole::QualifierFormats_E)permissions[i].format;
			_values.push_back(_permissions);
		}
		_role->modifyRole ((IClient*)client,privilege,_values);
	}
	CATCH_SET_ERROR ();
}



/*
 * getPermissions
 */
extern "C" int 
role_getPermissions (DSDKRole* role, RolePermission_T* permissions,int max_permission)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CRole* _role = (CRole*) (role->hdl);
		vector <CRole::Permission_T>	_permissions	 = _role->getPermissions ();

		for (size_t i = 0; ((i < _permissions.size ()) && (i < (size_t)max_permission)) ; i++)
		{
			permissions [i].activity = (RoleActivities_E)_permissions [i].activity;
			permissions [i].format   = (RoleQualifierFormats_E)_permissions[i].format;

			memset (permissions [i].activity_str, 0, MAX_ACTIVITY_STR_LEN + 1);
			snprintf(permissions [i].activity_str,   MAX_ACTIVITY_STR_LEN, "%s",_permissions [i].activity_str.c_str ());

			memset (permissions [i].qualifier, 0, MAX_QUALIFIER_LEN + 1);
			snprintf(permissions [i].qualifier,   MAX_QUALIFIER_LEN, "%s",_permissions [i].qualifier.c_str ());

			memset (permissions [i].format_str, 0, MAX_QUALIFIER_FORMAT_STR_LEN + 1);
			snprintf(permissions [i].format_str,   MAX_QUALIFIER_FORMAT_STR_LEN, "%s",_permissions [i].format_str.c_str ());
		
		}
		return (int)_permissions.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * displayPrivileges
 */
extern "C" int 
role_displayPermissions (DSDKRole* role,RolePermission_T* permissions,int max_permission)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CRole* _role = (CRole*) (role->hdl);
		vector <CRole::Permission_T>	_permissions	 = _role->displayPermissions ();
		for (size_t i = 0; ((i < _permissions.size ()) && (i < (size_t)max_permission)) ; i++)
		{
			memset (permissions [i].elementName, 0, MAX_ELEMENT_NAME + 1);
			snprintf(permissions [i].elementName,   MAX_ELEMENT_NAME, "%s",_permissions [i].elementName.c_str ());
		}
		return (int)_permissions.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getName
 */
extern "C" void 
role_getName (DSDKRole* role, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CRole* _role = (CRole*) (role->hdl);
		string str = _role->getName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getRoleCharacteristics
 */
extern "C" int 
role_getRoleCharacteristics (DSDKRole* role, uint16* role_char, int max_types)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CRole* _role = (CRole*) (role->hdl);
		vector<uint16>	_role_char = _role->getRoleCharacteristics ();
		for (size_t i = 0; (i < _role_char.size () && (i < (size_t)max_types)); i++)
		{
			role_char [i]  = _role_char [i];
		}
		return (int)_role_char.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getSupportedActivityQualifiers
 */
extern "C" int 
role_getSupportedActivityQualifiers (DSDKRole* role, DSDKClient* client, char** activityqualifiers, int max_qualifiers, 
													 int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		vector <string> str	= CRole::getSupportedActivityQualifiers ((IClient*)client);
		for (int i = 0; ((i < (int)str.size ()) && (i < max_qualifiers)); i++)
		{
			::snprintf(activityqualifiers [i],   max_strlen, "%s", str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getCommonName
 */
extern "C" void 
role_getCommonName (DSDKRole* role, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CRole* _role = (CRole*) (role->hdl);
		string str = _role->getCommonName ();
		::snprintf(name,   max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getElementName
 */
extern "C" void 
role_getElementName (DSDKRole* role, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CRole* _role = (CRole*) (role->hdl);
		string str = _role->getElementName ();
		::snprintf(name,   max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * release
 */
extern "C" void 
role_release (DSDKRole* role)
{
	dsdkc_setError (0, NULL);
	CRole* _role = (CRole*) (role->hdl);
	delete _role;
	delete role;
}


DSDKRoleFT _roleft = 
{
	role_getCreationClassName,
	role_getName,
	role_getRoleCharacteristics,
	role_getCommonName,
	role_getElementName,
	role_createRole,
	role_deleteRole,
	// role_modifyRole,
	//role_assignPermissions,
	role_modifyRole,
	role_getPermissions,
	role_displayPermissions,
	role_getSupportedActivityQualifiers,
	role_release,
};


/*
 * Make a C based software from the corresponding C++ object.
 */
static DSDKRole* 
makeDSDKRole (const CRole& role)
{
	DSDKRole* dsdk_role = new DSDKRole;
	if (NULL == dsdk_role) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_role->ft  = &_roleft;
		dsdk_role->hdl = new CRole (role);
		return dsdk_role;
	}
	CATCH_SET_ERROR ();

	delete dsdk_role;
	return NULL;
}


/*
 * getItem
 */
extern "C" DSDKRole* 
rolei_getItem (DSDKRoleIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CRole::iterator* _iter = (CRole::iterator*) (di->hdl);
		if (*_iter == CRole::iterator::end ()) { return NULL; }
		return makeDSDKRole (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
rolei_next (DSDKRoleIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CRole::iterator* _iter = (CRole::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
rolei_isEnd (DSDKRoleIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CRole::iterator* _iter = (CRole::iterator*) (di->hdl);
		return (*_iter == CRole::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
rolei_release (DSDKRoleIterator* di)
{
	dsdkc_setError (0, NULL);
	CRole::iterator* _iter = (CRole::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

DSDKRoleIteratorFT _roleift = 
{
	rolei_getItem,
	rolei_next,
	rolei_isEnd,
	rolei_release
};


/*
 * Make a C based software iterator from the corresponding C++ object.
 */
static DSDKRoleIterator* 
makeDSDKRoleIterator (const CRole::iterator& rolei)
{
	DSDKRoleIterator* dsdk_rolei = new DSDKRoleIterator;
	if (NULL == dsdk_rolei) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_rolei->ft  = &_roleift;
		dsdk_rolei->hdl = new CRole::iterator (rolei);
		return dsdk_rolei;
	}
	CATCH_SET_ERROR ();

	delete dsdk_rolei;
	return NULL;
}


/*

 * enumUsers
 */
extern "C" DSDKRoleIterator*
enumRoles (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CRole::iterator iter = CRole::enumRoles (
														(IClient*) client, 
														cached ? true : false);
		return makeDSDKRoleIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;
}

extern DSDKUserFT _userft;

/*
 * createUser
 */
extern "C" DSDKUser* 
user_createUser (DSDKComputerSystem* cs, char*	user_id, char* password, 
					char* certificate)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CComputerSystem* _cs = (CComputerSystem*) (cs->hdl);
		CUser _user = CUser::createUser (*_cs, string (user_id), string (password), 
										 string (certificate));
		
		DSDKUser * dsdk_user = new DSDKUser;

		dsdk_user->ft	= &_userft;
		dsdk_user->hdl	= new CUser (_user);

		return dsdk_user;
	}
	CATCH_SET_ERROR ();
	return NULL;
}

/*
 * getUserRoles
 */
extern "C" int
user_getUserRoles (DSDKUser* user, DSDKRole** role)
{
	dsdkc_setError (0, NULL);
	try
	{
		CUser* _user = (CUser*) (user->hdl);
		vector <CRole>	_roles	 = _user->getUserRoles ();

		for (size_t i = 0; i < _roles.size (); i++)
		{
			DSDKRole * dsdk_role = new DSDKRole;

			dsdk_role->ft	= &_roleft;
			dsdk_role->hdl	= new CRole (_roles [i]);

			role [i] = dsdk_role;
		}
		
		return (int)_roles.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}


/*
 * assignRoles
 */
extern "C" void
user_assignRoles (DSDKUser* user,char** roles,int num_values)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		
		vector <string> _values;
		for (int i = 0; i < num_values; i++)
		{
			_values.push_back (roles [i]);
		}
		_user->assignRoles (_values);
	}
	CATCH_SET_ERROR ();
	
}

/*
 * removeRoles
 */

extern "C" void
user_removeRoles (DSDKUser* user, char** roles,int num_values)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		
		vector <string> _values;
		for (int i = 0; i < num_values; i++)
		{
			_values.push_back (roles [i]);
		}
		_user->removeRoles (_values);
	}
	CATCH_SET_ERROR ();

}


/*
 * deleteUser
 */
extern "C" void 
user_deleteUser (DSDKUser* user)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		_user->deleteUser ();
	}
	CATCH_SET_ERROR ();
}

/*
 * enableUser  
 */
extern "C" uint32
user_enableUser (DSDKUser* user)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		_user->enableUser ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * disableUser
 */
extern "C" uint32
user_disableUser (DSDKUser* user)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		_user->disableUser ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

extern "C" void 
user_changePassword (DSDKUser* user, char* password)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		_user->changePassword(string(password));
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * Gets the getSystemCreationClassName
 */
extern "C" void 
user_getSystemCreationClassName (DSDKUser* user, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		string str = _user->getSystemCreationClassName ();
		::snprintf(name,   max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * Gets the getCreationClassName
 */
extern "C" void 
user_getCreationClassName(DSDKUser* user, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		string str = _user->getCreationClassName ();
		::snprintf(name,   max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * Gets the getSystemName
 */
extern "C" void 
user_getSystemName (DSDKUser* user, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		string str = _user->getSystemName ();
		::snprintf(name,   max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * Gets the user name
 */
extern "C" void 
user_getName (DSDKUser* user, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		string str = _user->getName ();
		::snprintf(name,   max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}
/*
 * getUserID
 */
extern "C" void 
user_getUserID (DSDKUser* user, char* userid, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		string str = _user->getUserID  ();
		::snprintf(userid,   max_len, "%s",  str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getUserPassword 
 */
extern "C" int 
user_getUserPassword (DSDKUser* user, char** users, int max_users, 
														int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		vector <string> str	= _user->getUserPassword ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_users)); i++)
		{
			::snprintf(users [i],   max_strlen, "%s",  str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getOrganizationName 
 */
extern "C" int 
user_getOrganizationName (DSDKUser* user, char** orgname, int max_orgname, 
														int max_strlen)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		vector <string> str	= _user->getOrganizationName ();
		for (int i = 0; ((i < (int)str.size ()) && (i < max_orgname)); i++)
		{
			::snprintf(orgname [i],   max_strlen, "%s",  str [i].c_str ());
		}
		return (int) str.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * Gets the ElementName
 */
extern "C" void 
user_getElementName (DSDKUser* user, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		string str = _user->getElementName ();
		::snprintf(name,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 *getUserPasswordEncryptionAlgorithm
 */
extern "C" uint16 
user_getUserPasswordEncryptionAlgorithm (DSDKUser* user)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		return _user->getUserPasswordEncryptionAlgorithm ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * Gets the OtherUserPasswordEncryptionAlgorithm
 */
extern "C" void 
user_getOtherUserPasswordEncryptionAlgorithm (DSDKUser* user, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		string str = _user->getOtherUserPasswordEncryptionAlgorithm ();
		::snprintf(name,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 *getPasswordHistoryDepth
 */
extern "C" uint16 
user_getPasswordHistoryDepth (DSDKUser* user)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		return _user->getPasswordHistoryDepth ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getComplexPasswordRulesEnforced
 */
extern "C" int 
user_getComplexPasswordRulesEnforced (DSDKUser* user, uint16* rules, int max_rules)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		vector<uint16>	_rules = _user->getComplexPasswordRulesEnforced ();
		for (size_t i = 0; (i < _rules.size () && (i < (size_t)max_rules)); i++)
		{
			rules [i]  = _rules [i];
		}
		return (int)_rules.size ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 *getMaximumSuccessiveLoginFailures
 */
extern "C" uint16 
user_getMaximumSuccessiveLoginFailures (DSDKUser* user)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		return _user->getMaximumSuccessiveLoginFailures ();
	}
	CATCH_SET_ERROR ();
	return 0;
}


/*
 * getEnabledState
 */
extern "C" uint16
user_getEnabledState (DSDKUser* user)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		return _user->getEnabledState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEnabledStateStr
 */
extern "C" void 
user_getEnabledStateStr (DSDKUser* user, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		string str = _user->getEnabledStateStr ();
		::strncpy (state, str.c_str (), max_len);
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getRequestedState
 */
extern "C" uint16
user_getRequestedState (DSDKUser* user)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		return _user->getRequestedState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getRequestedStateStr
 */
extern "C" void 
user_getRequestedStateStr (DSDKUser* user, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUser* _user = (CUser*) (user->hdl);
		string str = _user->getRequestedStateStr ();
		::snprintf(state,   max_len, "%s", str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * release
 */
extern "C" void 
user_release (DSDKUser* user)
{
	dsdkc_setError (0, NULL);
	CUser* _user = (CUser*) (user->hdl);
	delete _user;
	delete user;
}


DSDKUserFT _userft = 
{
	user_createUser,
	user_getUserRoles,
	user_assignRoles,
	user_removeRoles,
	user_deleteUser,
	user_enableUser,
	user_disableUser,
	user_changePassword,
	user_getSystemCreationClassName,
	user_getCreationClassName,
	user_getSystemName,
	user_getName,
	user_getUserID,
	user_getUserPassword,
	user_getOrganizationName,
	user_getElementName,
	user_getUserPasswordEncryptionAlgorithm,
	user_getOtherUserPasswordEncryptionAlgorithm,
	user_getPasswordHistoryDepth,
	user_getComplexPasswordRulesEnforced,
	user_getMaximumSuccessiveLoginFailures,
	user_getEnabledState,
	user_getEnabledStateStr,
	user_getRequestedState,
	user_getRequestedStateStr,
	user_release,
};


/*
 * Make a C based software from the corresponding C++ object.
 */
static DSDKUser* 
makeDSDKUser (const CUser& user)
{
	DSDKUser* dsdk_user = new DSDKUser;
	if (NULL == dsdk_user) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_user->ft  = &_userft;
		dsdk_user->hdl = new CUser (user);
		return dsdk_user;
	}
	CATCH_SET_ERROR ();

	delete dsdk_user;
	return NULL;
}


/*
 * getItem
 */
extern "C" DSDKUser* 
useri_getItem (DSDKUserIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CUser::iterator* _iter = (CUser::iterator*) (di->hdl);
		if (*_iter == CUser::iterator::end ()) { return NULL; }
		return makeDSDKUser (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}


/*
 * next
 */
extern "C" void 
useri_next (DSDKUserIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CUser::iterator* _iter = (CUser::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
useri_isEnd (DSDKUserIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CUser::iterator* _iter = (CUser::iterator*) (di->hdl);
		return (*_iter == CUser::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
useri_release (DSDKUserIterator* di)
{
	dsdkc_setError (0, NULL);
	CUser::iterator* _iter = (CUser::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

DSDKUserIteratorFT _userift = 
{
	useri_getItem,
	useri_next,
	useri_isEnd,
	useri_release
};


/*
 * Make a C based software iterator from the corresponding C++ object.
 */
static DSDKUserIterator* 
makeDSDKUserIterator (const CUser::iterator& useri)
{
	DSDKUserIterator* dsdk_useri = new DSDKUserIterator;
	if (NULL == dsdk_useri) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_useri->ft  = &_userift;
		dsdk_useri->hdl = new CUser::iterator (useri);
		return dsdk_useri;
	}
	CATCH_SET_ERROR ();

	delete dsdk_useri;
	return NULL;
}


/*

 * enumUsers
 */
extern "C" DSDKUserIterator*
enumUsers (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CUser::iterator iter = CUser::enumUsers (
														(IClient*) client, 
														cached ? true : false);
		return makeDSDKUserIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;
}


