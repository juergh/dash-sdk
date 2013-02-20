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
 * user_c.h
 * A class representing a user.
 */
#ifndef __CDSDK_USER_H__
#define __CDSDK_USER_H__
#include <dsdk/dsdktypes.h>
#include <dsdkc/capi.h>
#include <dsdkc/computersystem_c.h>

#ifdef __cplusplus
extern "C"
{
#endif

		typedef enum
	{
		Other = 1,
		Create,
		Delete,
		Detect,
		Read,
		Write,
		Execute
	} RoleActivities_E;

	typedef enum
	{
		ClassName	= 2,
		ClassProperty,
		ClassMethod,
		ObjectReference,
		Namespace,
		URL,
		DirectoryFileName,
		CLI,
		SCSICommand,
		Packets,
	} RoleQualifierFormats_E;

	#define MAX_ACTIVITY_STR_LEN			20
	#define MAX_QUALIFIER_LEN				100
	#define MAX_QUALIFIER_FORMAT_STR_LEN	100
	#define MAX_ELEMENT_NAME				100
	typedef struct 
	{
		RoleActivities_E		activity;
		char				qualifier [MAX_QUALIFIER_LEN + 1];
		RoleQualifierFormats_E	format;

		char				activity_str [MAX_ACTIVITY_STR_LEN + 1];		/* activity as string	*/
		char				format_str [MAX_QUALIFIER_FORMAT_STR_LEN + 1];	/* format as string		*/
		char				instanceID [MAX_ELEMENT_NAME + 1];
		char				elementName [MAX_ELEMENT_NAME + 1];
	} RolePermission_T;

/**
 * Role function table.
 */
struct _DSDKRole;
typedef struct _DSDKRole DSDKRole;

/**
 * User function table.
 */
struct _DSDKUser;
typedef struct _DSDKUser DSDKUser;

/**
 * @struct DSDKRoleFT
 * @brief Role function table 
 */

typedef struct _DSDKRoleFT
{
	/**
	 * Gets the role's Creation class Name 
	 * @param name	Creation Class Name of the role
	 * @param max_len	maximum buffer length
	 */
	void (*getCreationClassName) (DSDKRole* role, char* name, int max_len);

 	/**
	 * Gets the name of this Role
	 * @param name	The name string
	 * @param max_len	maximum buffer length
	 */
	void (*getName) (DSDKRole* role, char* name, int max_len);

	/**
	 * Gets the RoleCharacteristics
	 * @param role_char	RoleCharacteristics
	 * @param max_types	maximum types
	 */
	int (*getRoleCharacteristics) (DSDKRole* role, uint16* role_char, int max_types);

	/**
	 * Gets the CommonName of this Role
	 * @param name	The CommonName
	 * @param max_len	maximum buffer length
	 */
	void (*getCommonName) (DSDKRole* role, char* commonname, int max_len);

	/**
	 * Gets the ElementName of this Role
	 * @param name	The ElementName
	 * @param max_len	maximum buffer length
	 */
	void (*getElementName) (DSDKRole* role, char* ele_name, int max_len);

	/**
	 * Creats a new role with the permissions specified
	 * @param cs			Computer System where the role will be added.
	 * @param name			Name of the role
	 * @param permissions	Privileges/permissions for this role(Permission_T (activities, qualifiers & formats))
	 *                      Permissions are created using the 
	 *                      1. activities (Activity_E) (Create|Delete|Detect|Read|Write|Execute|Other).
	 *                      2. qualifiers (valid qualifiers are obtained using getSupportedActivityQualifiers),
	 *                      3. and formats (QualifierFormats_E), this is optional(targets may or may not support this).
	 */

	 DSDKRole* (*createRole) (DSDKComputerSystem*	cs, 
							 char*					rolename, 
							 RolePermission_T*		permissions,
							 int					num_permission);
 
	/**
	 * Deletes this role
	 */
	void (*deleteRole) (DSDKRole* role);

	/**
	 * Modify this role with new privileges
	 * @param permissions	Privileges/permissions for this role(Permission_T (activities, qualifiers & formats))
	 *                      Permissions are created using the 
	 *                      1. activities (Activity_E) (Create|Delete|Detect|Read|Write|Execute|Other).
	 *                      2. qualifiers (valid qualifiers are obtained using getSupportedActivityQualifiers),
	 *                      3. and formats (QualifierFormats_E), this is optional(targets may or may not support this).
	 */
/*	void (*modifyRole) (DSDKRole* role, 
						RolePermission_T*	
						permissions, 
						int num_permission); */


	/**
	 * Assigns new permissions to this role
	 * @param permissions	Privileges/permissions for this role(Permission_T (activities, qualifiers & formats))
	 *                      Permissions are created using the 
	 *                      1. activities (Activity_E) (Create|Delete|Detect|Read|Write|Execute|Other).
	 *                      2. qualifiers (valid qualifiers are obtained using getSupportedActivityQualifiers),
	 *                      3. and formats (QualifierFormats_E), this is optional(targets may or may not support this).
	 */
	void (*modifyRole) (DSDKRole* role,DSDKClient* client, char* privilege,
								RolePermission_T* permissions, 
								int num_permission);

	/**
	 * Gets the permissions for this role
	 */
	int (*getPermissions) (DSDKRole* role, RolePermission_T* permissions,int max_permission);

	/**
	 * Gets the permissions for this role 
	 */
	int (*displayPermissions) (DSDKRole* role,RolePermission_T* permissions,int max_permission);

	/*
	 * Gets the activity qualifiers supported by the target/MAP.
	 */

	int (*getSupportedActivityQualifiers) (DSDKRole* role, DSDKClient* client, 
											char** activityqualifiers, 
											int max_qualifiers, 
											int max_strlen);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKRole* role);

} DSDKRoleFT;

struct _DSDKRole
{
	void*		hdl;
	DSDKRoleFT*	ft;
};

/**
 * User iterator function table.
 */
struct _DSDKRoleIterator;
typedef struct _DSDKRoleIterator DSDKRoleIterator;

/**
 * @struct DSDKRoleIteratorFT
 * @brief Role iterator function table 
 */
typedef struct _DSDKRoleIteratorFT
{
	/**
	 * Returns the role at this iterator location.
	 */
	DSDKRole* (*getItem) (DSDKRoleIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKRoleIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKRoleIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKRoleIterator* di);

} DSDKRoleIteratorFT;

/**
 * @struct _DSDKRoleIterator 
 * @brief Iterator to iterate through the roles.
 */
struct _DSDKRoleIterator
{
	void*				hdl;
	DSDKRoleIteratorFT*	ft;
};

/**
 * Enumerate all the users in a system.
 */
DSDKC_Export DSDKRoleIterator* enumRoles (DSDKClient* client, BOOL cached);

/**
 * @struct DSDKUserFT
 * @brief User function table 
 */
typedef struct _DSDKUserFT
{
 	/**
 	 * Creats a user 
	 * @param cs			Computer system where the user will be added.
 	 * @param user_id		User ID.
 	 * @param password		User password.
 	 * @param certificate	Certificate to be used
 	 **/
 	DSDKUser* (*createUser) (DSDKComputerSystem* cs,
						 char*			user_id, 
 						 char*			password,
						 char*			certificate); 



	/**
	 * Gets the associated role with this user
	 */

	int (*getUserRoles) (DSDKUser* user, DSDKRole** role);

	
	/**
	 * Assign Role(s) to this user.
	 * @param roles		Role names to assign for this user.
	 */
	void (*assignRoles) (DSDKUser* user,char** roles,int num_values);

	/**
	 * Remove Role(s) from this user.
	 * @param roles		Role names to remove for this user.
	 */
	void (*removeRoles) (DSDKUser* user, char** roles,int num_values);

	/**
	 * Delets this user
	 */
	void (*deleteUser) (DSDKUser* user);

	/**
	 * EnableUser 
	 */
	uint32 (*enableUser) (DSDKUser* user);

	/**
	 * DisableUser 
	 */
	uint32 (*disableUser) (DSDKUser* user);

	/**
	 * set password /Modify the password 
	 */
	void (*changePassword) (DSDKUser* user, char* password);

	/**
	 * Gets SystemCreationClassName
	 * @return the systemcreationclassname
	 */
	void (*getSystemCreationClassName) (DSDKUser* user, char* str, int max_len);

	/**
	 * Gets CreationClassName
	 * @ return the creationclassname
	 */
	void (*getCreationClassName) (DSDKUser* user, char* str, int max_len);

	/**
	 * Gets SystemName
	 * @return the systemname
	 */
	void (*getSystemName) (DSDKUser* user, char* str, int max_len);

	/**
	 * Gets the user name
	 * @param str	The name string
	 * @param max_len	maximum buffer size
	 */
	void (*getName) (DSDKUser* user, char* str, int max_len);

	/**
	 * getUserID
	 */
	void (*getUserID) (DSDKUser* user, char* userid, int max_len);
	
	/**
	 * Gets an array of UserPassword
	 * @ returns the password
	 */
	int (*getUserPassword) (DSDKUser* user, char** users, int max_users, int max_strlen);

	/**
	 * Gets an array of OrganizationName
	 * @ returns the organizatoinname
	 */
	int (*getOrganizationName) (DSDKUser* user, char** orgname, int max_orgname, int max_strlen);

	/**
	 * getElementName
	 */
	void (*getElementName) (DSDKUser* user, char* name, int max_len);

	/**
	 * Gets the UserPasswordEncryptionAlgorithm
	 */
	uint16 (*getUserPasswordEncryptionAlgorithm) (DSDKUser* user);

	/**
	 * Gets OtherUserPasswordEncryptionAlgorithm
	 * @ return otheruserpasswordencryptionalgorithm
	 */
	void (*OtherUserPasswordEncryptionAlgorithm) (DSDKUser* user, char* name, int max_len);

	/**
	 * Gets PasswordHistoryDepth
	 * @ return the passwordhistorydepth
	 */
	uint16 (*getPasswordHistoryDepth) (DSDKUser* user);

	/**
	 * Gets an array of ComplexPasswordRulesEnforced
	 * @ returns the list of complexpasswordrulesenforced
	 */
	int (*getComplexPasswordRulesEnforced) (DSDKUser* user, uint16* rules, int max_rules);

	/**
	 * Gets MaximumSuccessiveLoginFailures
	 * @ return the maximumsuccessiveloginfailures
	 */
	uint16 (*getMaximumSuccessiveLoginFailures) (DSDKUser* user);

	/**
	 * Gets the EnabledState of the user
	 * @return The EnabledState
	 */
	uint16 (*getEnabledState) (DSDKUser* user);

	/**
 	 * Gets the state of the user as string
 	 * @param state		The Enabled State is filled in
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getEnabledStateStr) (DSDKUser* user, char* state, int max_len);

	/**
	 * Gets the last RequestedState of the user
	 * @return The RequestedState 
	 */
	uint16 (*getRequestedState) (DSDKUser* user);

	/**
 	 * Gets the requested status of the user as string
 	 * @param state		The requested state is filled in.
	 * @param max_len	maximum buffer length
 	 **/
 	void (*getRequestedStateStr) (DSDKUser* user, char* state, int max_len);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKUser* user);

} DSDKUserFT;

struct _DSDKUser
{
	void*		hdl;
	DSDKUserFT*	ft;
};

/**
 * User iterator function table.
 */
struct _DSDKUserIterator;
typedef struct _DSDKUserIterator DSDKUserIterator;

/**
 * @struct DSDKUserIteratorFT
 * @brief User iterator function table 
 */
typedef struct _DSDKUserIteratorFT
{
	/**
	 * Returns the user at this iterator location.
	 */
	DSDKUser* (*getItem) (DSDKUserIterator* di);

	/**
	 * Moves the iterator to the next location.
	 */
	void (*next) (DSDKUserIterator* di);

	/**
	 * Returns true if have reached the end 
	 */
	BOOL (*isEnd) (DSDKUserIterator* di);

	/**
	 * Releases this object
	 */
	void (*release) (DSDKUserIterator* di);

} DSDKUserIteratorFT;

/**
 * @struct _DSDKUserIterator 
 * @brief Iterator to iterate through the users.
 */
struct _DSDKUserIterator
{
	void*				hdl;
	DSDKUserIteratorFT*	ft;
};

/**
 * Enumerate all the users in a system.
 */
DSDKC_Export DSDKUserIterator* enumUsers (DSDKClient* client, BOOL cached);

#ifdef SWIGIZE
/* Role */
//DSDKC_Export void user_getCaptions (DSDKUser* user, char* caption, int max_len);
DSDKC_Export DSDKRole* role_createRole (DSDKComputerSystem* cs, char* rolename, RolePermission_T* permissions, int num_permission);
DSDKC_Export void role_deleteRole (DSDKRole* role);
DSDKC_Export void role_modifyRole (DSDKRole* role, RolePermission_T*	permissions, int num_permission);
DSDKC_Export void role_assignPermissions (DSDKRole* role,DSDKClient* client,string privilege,RolePermission_T* permissions,int num_permission);
DSDKC_Export int role_getPermissions (DSDKRole* role, RolePermission_T* permissions,int max_permission);
DSDKC_Export int role_displayPermissions (DSDKRole* role,RolePermission_T* permissions,int max_permission);
DSDKC_Export void role_getName (DSDKRole* role, char* name, int max_len);
DSDKC_Export int role_getSupportedActivityQualifiers (DSDKRole* role, DSDKClient* client, char** activityqualifiers, int max_qualifiers, int max_strlen);
DSDKC_Export void role_release (DSDKRole* role);
DSDKC_Export DSDKRole* rolei_getItem (DSDKRoleIterator* di);
DSDKC_Export void rolei_next (DSDKRoleIterator* di);
DSDKC_Export BOOL rolei_isEnd (DSDKRoleIterator* di);
DSDKC_Export void rolei_release (DSDKRoleIterator* di);
/* User */
DSDKC_Export DSDKUser* user_createUser (DSDKComputerSystem* cs, char*	user_id, char* password, char* certificate);
DSDKC_Export int user_getUserRoles (DSDKUser* user, DSDKRole** role);
DSDKC_Export void user_assignRoles (DSDKUser* user,char** roles,int num_values);
DSDKC_Export void user_removeRoles (DSDKUser* user, char** roles,int num_values);
DSDKC_Export void user_deleteUser (DSDKUser* user);
DSDKC_Export uint32 user_enableUser (DSDKUser* user);
DSDKC_Export uint32 user_disableUser (DSDKUser* user);
DSDKC_Export void user_getSystemCreationClassName (DSDKUser* user, char* name, int max_len);
DSDKC_Export void user_getCreationClassName(DSDKUser* user, char* name, int max_len);
DSDKC_Export void user_getSystemName (DSDKUser* user, char* name, int max_len);
DSDKC_Export void user_getName (DSDKUser* user, char* name, int max_len);
DSDKC_Export void user_getUserID (DSDKUser* user, char* userid, int max_len);
DSDKC_Export int user_getUserPassword (DSDKUser* user, char** users, int max_users, int max_strlen);
DSDKC_Export int user_getOrganizationName (DSDKUser* user, char** orgname, int max_orgname, int max_strlen);
DSDKC_Export void user_getElementName (DSDKUser* user, char* name, int max_len);
DSDKC_Export uint16 user_getUserPasswordEncryptionAlgorithm (DSDKUser* user);
DSDKC_Export void user_getOtherUserPasswordEncryptionAlgorithm (DSDKUser* user, char* name, int max_len);
DSDKC_Export uint16 user_getPasswordHistoryDepth (DSDKUser* user);
DSDKC_Export int user_getComplexPasswordRulesEnforced (DSDKUser* user, uint16* rules, int max_rules);
DSDKC_Export uint16 user_getMaximumSuccessiveLoginFailures (DSDKUser* user);
DSDKC_Export uint16 user_getRequestedState (DSDKUser* user);
DSDKC_Export uint16 user_getEnabledState(DSDKUser* user);
DSDKC_Export void user_getEnabledStateStr (DSDKUser* user, char* state, int max_len);
DSDKC_Export void user_release (DSDKUser* user);
DSDKC_Export DSDKUser* useri_getItem (DSDKUserIterator* di);
DSDKC_Export void useri_next (DSDKUserIterator* di);
DSDKC_Export BOOL useri_isEnd (DSDKUserIterator* di);
DSDKC_Export void useri_release (DSDKUserIterator* di);
#endif // #ifdef SWIGIZE

#ifdef __cplusplus
}
#endif

#endif /* __CDSDK_USER_H__*/
