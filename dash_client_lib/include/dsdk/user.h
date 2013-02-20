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
#ifndef __DSDK_USER_H__
#define __DSDK_USER_H__
#include <dsdk/dsdkiterator.h>
#include <dsdk/dsdk_api.h>
#include <dsdk/computersystem.h>
#include <dsdk/oal/CIM_AccountManagementService.h>
#include <dsdk/oal/CIM_AccountManagementCapabilities.h>
#include <dsdk/oal/CIM_RoleBasedAuthorizationService.h>
#include <dsdk/oal/CIM_RoleBasedManagementCapabilities.h>

namespace dsdk
{

class CIM_Account;
class CIM_Role;
class CIM_Privilege;
class CUser;
class CRole;
typedef CAPIIterator<CUser, CIM_Account> _CUserIterator;
typedef CAPIIterator<CRole, CIM_Role>    _CRoleIterator;

/**
  * @class CRole
  * @brief A class representing a user role
  **/
class DSDK_Export CRole
{
public:
	DECLARE_API_ITERATOR (CRole);
	typedef CIM_Role CIMType;

	typedef enum
	{
		Other = 1,
		Create,
		Delete,
		Detect,
		Read,
		Write,
		Execute
	} Activities_E;

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
	} QualifierFormats_E;

	typedef struct 
	{
		Activities_E		activity;
		string				qualifier;
		QualifierFormats_E	format;

		string				activity_str;	/* activity as string	*/
		string				format_str;		/* format as string		*/
		string				instanceID;
		string				elementName;
	} Permission_T;

	/**
	 * Enumerates all the roles present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the role.
	 */
	static CRole::iterator enumRoles (IClient* client,
					 				  bool cached = true);

	/**
	 * Return the underlying CIM object
	 */
	CIM_Role* getCIMObject (void) const { return _role; }

public:
	/**
	 * Gets the CreationClassName of this Role
	 * @return The CreationClassName
	 */
	string getCreationClassName (void) const;

	/**
	 * Gets the name of this Role
	 * @return The name
	 */
	string getName (void) const;

	/**
	 * Gets the RoleCharacteristics of this Role
	 * @return The RoleCharacteristics
	 */
	vector<uint16> getRoleCharacteristics (void) const;

	/**
	 * Gets the CommonName of this Role
	 * @return The CommonName
	 */
	string getCommonName (void) const;

	/**
	 * Gets the ElementName of this Role
	 * @return The ElementName
	 */
	string getElementName (void) const;
	string displayPrivileges(void);

	/**
	* verifies whether the RoleBasedAuthorizationService and BootServiceCapabilities instances are exists or not.
	* @param rbas	CIM_RoleBasedAuthorizationService output parameter passed as reference, if service exists, it returns instance.
	* @param rbmc	CIM_RoleBasedManagementCapabilities output parameter passed as reference, if service exists, it returns instance.
	* @return true  - if the both the BS and BSC instances are exists.
	* @return false - if either one instance does not exists.
	**/
	bool capableOfRoleBasedAuthorizationService(CIM_RoleBasedAuthorizationService &rbas, CIM_RoleBasedManagementCapabilities &rbmc);
	/**
	* verifies whether the RoleBasedAuthorizationService and BootServiceCapabilities instances are exists or not.
	* @return true  - if the both the BS and BSC instances are exists.
	*		 false - if either one instance does not exists.
	**/
	bool capableOfRoleBasedAuthorizationService();

	/**
	* verifies whether the perticulare method is supported or not.
	* @return true  - if the both the BS and BSC instances are exists.
	*		 false - if either one instance does not exists.
	**/
	bool isMethodSupported(CIM_RoleBasedAuthorizationService &rbas, uint16 method);

	bool getSupportedMethodsStr(vector<string> &methods_str);


	/**
	 * Verifies whether Create role is supported or not 
	 * specified computersystem instance.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfCreateRole(CIM_RoleBasedAuthorizationService &rbas);

	/**
	 * Verifies whether Create role is supported or not 
	 * specified computersystem instance.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfCreateRole();

	/**
	 *  Verifies whether Delete role is supported or not
	 * specified computersystem instance.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfDeleteRole(CIM_RoleBasedAuthorizationService &rbas);
	
	/**
	 * Verifies whether Delete role is supported or not 
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfDeleteRole();

	/**
	 *  Verifies whether Delete role is supported or not
	 * specified computersystem instance.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfModifyRole(CIM_RoleBasedAuthorizationService &rbas);
	
	/**
	 * Verifies whether Delete role is supported or not 
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfModifyRole();

	/**
	 *  Verifies whether Delete role is supported or not
	 * specified computersystem instance.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfAssignRoles(CIM_RoleBasedAuthorizationService &rbas);
	
	/**
	 * Verifies whether Delete role is supported or not 
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfAssignRoles();

	/**
	 *  Verifies whether Delete role is supported or not
	 * specified computersystem instance.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfShowRoles(CIM_RoleBasedAuthorizationService &rbas);
	
	/**
	 * Verifies whether Delete role is supported or not 
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfShowRoles();

	/**
	 *  Verifies whether Delete role is supported or not
	 * specified computersystem instance.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfShowAccess(CIM_RoleBasedAuthorizationService &rbas);
	
	/**
	 * Verifies whether Delete role is supported or not 
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfShowAccess();

	
public:
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
	static CRole createRole (const CComputerSystem&				cs, 
							 const string&						rolename, 
							 const vector<CRole::Permission_T>&	permissions);

	/**
	 * Deletes this role
	 */
	void deleteRole (void);

	/**
	 * Modify this role with new privileges/permissons, this will replace the existing permission 
	 *                      with new permissions
	 * @param permissions	Privileges/permissions for this role(Permission_T (activities, qualifiers & formats))
	 *                      Permissions are created using the 
	 *                      1. activities (Activity_E) (Create|Delete|Detect|Read|Write|Execute|Other).
	 *                      2. qualifiers (valid qualifiers are obtained using getSupportedActivityQualifiers),
	 *                      3. and formats (QualifierFormats_E), this is optional(targets may or may not support this).
	 */
//	void modifyRole (const vector<CRole::Permission_T>&	permissions);

	// vector<uint16> roleSupport (void) const;
	/**
	 * Modify this role with new privileges/permissons, this will replace the existing permission 
	 *                      with new permissions
	 * @param permissions	Privileges/permissions for this role(Permission_T (activities, qualifiers & formats))
	 *                      Permissions are created using the 
	 *                      1. activities (Activity_E) (Create|Delete|Detect|Read|Write|Execute|Other).
	 *                      2. qualifiers (valid qualifiers are obtained using getSupportedActivityQualifiers),
	 *                      3. and formats (QualifierFormats_E), this is optional(targets may or may not support this).
	 */
 

	void modifyRole (IClient* client,string privilege,vector<CRole::Permission_T> permissions);

	/**
	 * Gets the permissions for this role
	 * @return The permissions for this role
	 */
	vector<CRole::Permission_T> getPermissions (void) const;
	
	/**
	 * Gets the permissions for this role
	 * @return The permissions for this role
	 */
	vector<CRole::Permission_T> displayPermissions (void) const;


	/*
	 * Gets the activity qualifiers supported by the target/MAP.
	 * @param client	Pointer to the client interface.
	 */
	static vector<string> getSupportedActivityQualifiers (IClient* client);

public:
	/**
	 * Construct this object from the corresponding CIM_Role
	 * object
	 */
	CRole (const CIM_Role& role);

	/**
	 * Copy constructor
	 */
	CRole (const CRole& role);

	/**
	 * Destructor
	 */
	~CRole ();

	/**
	 * Assignment operator
	 */
	const CRole& operator = (const CRole& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void);

private:
	CIM_Role*	_role;
};


/**
  * @class CUser
  * @brief A class representing a user management
  **/
class DSDK_Export CUser
{
public:
	DECLARE_API_ITERATOR (CUser);
	typedef CIM_Account CIMType;

public:
	/**
	 * Enumerates all the user account present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the user.
	 */
	static CUser::iterator enumUsers (IClient* client, bool cached = true);

	/**
	 * Return the underlying CIM object
	 */
	CIM_Account* getCIMObject (void) const { return _user; }
public:
	/**
	 * Gets SystemCreationClassName
	 * @return the systemcreationclassname
	 */
	string getSystemCreationClassName (void) const;

	/**
	 * Gets CreationClassName
	 * @ return the creationclassname
	 */
	string getCreationClassName (void) const;

	/**
	 * Gets SystemName
	 * @return the systemname
	 */
	string getSystemName (void) const;

	/**
	 * Gets the role name
	 * @return The role name
	 */
	string getName (void) const;

	/**
	 * getUserID
	 * @return The User ID
	 */
	string getUserID (void) const;

	/**
	 * Gets an array of UserPassword
	 * @ returns the password
	 */
	vector<string> getUserPassword (void) const;

	/**
	 * Gets an array of OrganizationName
	 * @ returns the organizatoinname
	 */
	vector<string> getOrganizationName (void) const;

	/**
	 * Gets ElementName
	 * @ returns the elementname
	 */
	string getElementName (void) const;

	/**
	 * Gets UserPasswordEncryptionAlgorithm
	 * @ return the userpasswordencryptionalogrithm
	 */
	uint16 getUserPasswordEncryptionAlgorithm (void) const;

	/**
	 * Gets OtherUserPasswordEncryptionAlgorithm
	 * @ return otheruserpasswordencryptionalgorithm
	 */
	string getOtherUserPasswordEncryptionAlgorithm (void) const;

	/**
	 * Gets PasswordHistoryDepth
	 * @ return the passwordhistorydepth
	 */
	uint16 getPasswordHistoryDepth (void) const;

	/**
	 * Gets PasswordExpiration
	 * @ return the passwordexpiration
	 */
	datetime getPasswordExpiration (void) const;

	/**
	 * Gets an array of ComplexPasswordRulesEnforced
	 * @ returns the list of complexpasswordrulesenforced
	 */
	vector<uint16> getComplexPasswordRulesEnforced (void) const;

	/**
	 * Gets InactivityTimeout
	 * @ returns the inactivity timeout
	 */
	datetime getInactivityTimeout (void) const;

	/**
	 * Gets MaximumSuccessiveLoginFailures
	 * @ return the maximumsuccessiveloginfailures
	 */
	uint16 getMaximumSuccessiveLoginFailures (void) const;

	/**
	 * Gets RequestedState
	 * return the requestedstate
	 */
	uint16 getRequestedState (void) const;

	/**
	 * Gets the last RequestedState  of the user as string
	 * @return The RequestedState 
	 */
	string getRequestedStateStr (void) const;

	/**
	 * Gets EnabledState
	 * @ return the EnabledState
	 */
	uint16 getEnabledState (void) const;

	/**
	 * Gets the EnabledState of the user as string
	 * @return The EnabledState
	 */
	string getEnabledStateStr (void) const;

	bool capableOfRequestStateChange();
	
	bool getRequestedStatesSupportedStr(vector<string> &states);

	bool capableOfAccountManagementService(CComputerSystem cs,
						   CIM_AccountManagementService &ams,
						   CIM_AccountManagementCapabilities &amc);

	bool capableOfAccountManagementService();

	bool isMethodSupported(CIM_AccountManagementCapabilities &amc, uint16 method);

	/**
	 * Verifies whether create user operation is allowed on the 
	 * specified computersystem instance.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfCreateUser(CComputerSystem cs, CIM_AccountManagementService &ams, CIM_AccountManagementCapabilities &rbc);

	/**
	 * Verifies whether create user operation is allowed on the 
	 * specified computersystem instance.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfCreateUser();

		/**
	 * Verifies whether create user operation is allowed on the 
	 * specified computersystem instance.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfDeleteUser(CComputerSystem cs, CIM_AccountManagementService &ams, CIM_AccountManagementCapabilities &rbc);

	/**
	 * Verifies whether create user operation is allowed on the 
	 * specified computersystem instance.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfDeleteUser();
		/**
	 * Verifies whether create user operation is allowed on the 
	 * specified computersystem instance.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfModifyUser(CComputerSystem cs, CIM_AccountManagementService &ams, CIM_AccountManagementCapabilities &rbc);

	/**
	 * Verifies whether create user operation is allowed on the 
	 * specified computersystem instance.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfModifyUser();


	/**
	 * Verifies whether Authorization service is enabled or not 
	 * specified computersystem instance.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfRoleBasedAuthorizationService(CIM_RoleBasedAuthorizationService &rbas);

	/**
	 * Verifies whether Authorization service is enabled or not 
	 * specified computersystem instance.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfRoleBasedAuthorizationService();

	/**
	 * Verifies whether Assign roles to a specific user is supported or not.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfAssignRoles(CIM_RoleBasedAuthorizationService &rbas);

	/**
	 * Verifies whether Assign roles to a specific user is supported or not.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfAssignRoles();

	/**
	 * Verifies whether Remove roles of a specific user is supported or not.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfRemoveRoles(CIM_RoleBasedAuthorizationService &rbas);

	/**
	 * Verifies whether Remove roles of a specific user is supported or not.
	 * @return true - if supported
	 *			false - if not supported.
	 */
	bool capableOfRemoveRoles();

public:
	/**
 	 * Creats a user 
	 * @param cs			Computer system where the user will be added.
 	 * @param user_id		User ID.
 	 * @param password		User password.
 	 * @param organizationname	optional Organization Name
 	 **/
 	static CUser createUser (const CComputerSystem& cs,
							 const string&		user_id, 
 							 const string&		password,
							 const string&		organizationname = "");

	/**
	 * Gets the associated role with this user
	 * @return The user roles
	 */
	vector<CRole> getUserRoles (void) const;

	/**
	 * Assign Role(s) to this user.
	 * @param roles		Role names to assign for this user.
	 */
	void assignRoles (const vector<string>& roles);

	/**
	 * Remove Role(s) from this user.
	 * @param roles		Role names to remove for this user.
	 */
	void removeRoles (const vector<string>& roles);

	/**
	 * Delets this user
	 */
	void deleteUser (void);

	/**
	 * EnableUser 
	 */
	uint32 enableUser (void);

	/**
	 * DisableUser 
	 */
	uint32 disableUser (void);
	
	/**
	 * user Support
	 */
//	vector<uint16> userSupport (void) const;
	
	/**
	 * user Support
	 */
	vector<uint16> createUserSupport (void) const;

	///**
	// * set Name /Modify the name 
	// */
	//void setName (string name);

	/**
	 * set password /Modify the password 
	 */
	void changePassword (string password);

public:
	/**
	 * Construct this object from the corresponding CIM_Account 
	 * object
	 */
	CUser (const CIM_Account& user);

	/**
	 * Copy constructor
	 */
	CUser (const CUser& user);

	/**
	 * Destructor
	 */
	~CUser ();

	/**
	 * Assignment operator
	 */
	const CUser& operator = (const CUser& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void);

private:
	CIM_Account*	_user;
};


};	/* namespace dsdk */

#endif /*__DSDK_USER_H__*/
