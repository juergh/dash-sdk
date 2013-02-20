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
 * client.h
 * Client Interface.
 */
#ifndef __DSDK_SFCCCLIENT_H__
#define __DSDK_SFCCCLIENT_H__
#include <dsdk/client.h>

namespace dsdk
{

/**
 * @class CSFCCClient
 * @brief An SFCC Client class.
 */
class CSFCCClient : public IClient
{
public:
	/**
	 * Construct the CSFCCClient object from the low level SFCC Client.
	 */
	CSFCCClient (CMCIClient*  cc);

	/**
	 * Destructor
	 */
	virtual ~CSFCCClient ();

	/**
	 * Copy constructor.
	 */
	CSFCCClient (const CSFCCClient& sc);

	/**
	 * Assignment operator
	 */
	const CSFCCClient& operator = (const CSFCCClient& rhs);

public:
	/**
	 * Enumerate instance names of the class (and subclasses) defined by op.
	 * @p op	Object path containing the namespace and classname.
	 * @return	The iterator to the object paths.
	 * @throws	ECIMError.
	 */
	virtual CCIMObjectPath::iterator enumInstanceNames 
											(const CCIMObjectPath& op);


	/**
	 * Enumerate instance names of the class (and subclasses) defined by op.
	 * This function takes an extra list of key properties. This 
	 * function was added to support implementations which do not support
	 * EnumerateMode=EnumerateEPR. Instead this function
	 * (if global variable g_enum_names_use_keyprops is enabled) uses the
	 * enumerateInstances with the query for key properties and build the 
	 * object paths from the instances. 
	 * @p op.	Object path containing the namespace and classname.
	 * @return	The iterator to the object paths.
	 * @throws	ECIMError.
	 */
	virtual CCIMObjectPath::iterator enumInstanceNames 
										(const CCIMObjectPath& op,
										 const vector<string>& key_props);


	/**
	 * Enumerate instances of the class (and subclasses) defined by @p op
	 * @param op	Object path containing namespace and classname components.
	 * @param flags	Reserved
	 * @param props	An array of property names. The returned object must not 
	 *				include elements of any properties missing from the list.
	 * @return		The iterator to the instances.
	 * @throws		ECIMError
	 */
	virtual CCIMInstance::iterator enumInstances (const CCIMObjectPath& op,
										  CMPIFlags				flags,
										  const vector<string>& props = vector <string>()
										  );

	/**
	 * Get instance using @p op as reference. 
	 * @param op	Object Path containing namespace, classname and key 
	 *				components.
	 * @param flags	Reserved.
	 * @param props	An array of property names. The returned object must not 
	 *				include elements of any properties missing from the list.
	 * @return		The instance.
	 * @throws		ECIMError
	 */
	virtual CCIMInstance getInstance (const CCIMObjectPath&  	op, 
							 		  CMPIFlags			  		flags,
							 		  const vector<string>& 	props = vector <string>()
									  );

	/**
	 * Create instance from @p inst using @p op as reference. 
	 * @param op	Object path containing namespace, classname and key 
	 *				components.
	 * @param inst	Complete instance.
	 * @return		The assigned instance reference.
	 * @throws		ECIMError
	 */
	virtual CCIMObjectPath createInstance (const CCIMObjectPath& op,
										   const CCIMInstance&   inst);

	
	/**
	 * Replace an existing instance from @p inst using @p op as reference.
	 * @param op	ObjectPath containing the namespace, classname and key
	 *				components.
	 * @param inst	Complete instance.
	 * @param flags Reserved
	 * @param props	An array of property names. If not empty only these 
	 *				properties will be updated. Else all properties are 
	 *				updated.
	 * @return		None.
	 * @throws		ECIMError
	 */
	virtual void setInstance (const CCIMObjectPath& op, 
							  const CCIMInstance&   inst,
							  CMPIFlags			   	flags,
							  const vector<string>& props);

	/**
	 * Delete an existing instance using @p op as reference. 
	 * @param op	Object path containing namespace, classname and key 
	 *				components.
	 * @return		None.
	 * @throws		ECIMError
	 */
	virtual void deleteInstance (const CCIMObjectPath& op);


	/**
	 * Enumerate instances associated with the instance defined by the @p op.
	 * @param op	Source object path containing namespace, classname and 
	 *				key components.
	 * @param assoc_class	If not empty must be a valid association class
	 *						name.
	 *						It acts as a filter on the returned set of objects
	 *						by mandating that each returned object must be 
	 *						associated to the source object via an Instance
	 *						of this class or one of its subclasses.
	 * @param result_class	If not null, MUST be a valid class name.
	 *						It acts as filter on the returned set of objects
	 *						by mandating that each returned object must be 
	 *						either an Instance of this class (or its subclass).
	 * @param role			If not empty, MUST be a valid property name.
	 *						It acts as a filter on the the returned set of objects
	 *						by mandating that each returned object MUST be 
	 *						associated to the source object via an Association 
	 *						in which the source object plays the specified role 
	 *						(i.e. the name of the property in the association 
	 *						class that refers to the source object must match 
	 *						the value of this parameter).
	 * @param result_role 	If not empty, MUST be a valid Property name.
	 *   					It acts as a filter on the returned set of 
	 *						Objects by mandating that each returned Object 
	 *						MUST be associated to the source Object via an 
	 *						Association in which the returned Object plays 
	 *						the specified role (i.e. the name of the 
	 *						Property in the Association Class that refers 
	 *						to the returned Object MUST match the value 
	 *						of this parameter).
	 * @param flags			Reserved.
	 * @param props			If not empty, the members of the array define one or 
	 *						more Property names. Each returned Object MUST NOT 
	 *						include elements for any Properties missing from this 
	 *						list.
	 * @return				Iterator to the instances.
	 * @throws				ECIMError
	 */
	virtual CCIMInstance::iterator associators (const CCIMObjectPath& op,
												const string&	assoc_class,
												const string&	result_class,
												const string&	role,
												const string&	result_role,
												CMPIFlags		flags,
												const vector<string>& props = vector <string>()
											   );

	
	/** 
	 * Enumerate ObjectPaths associated with the Instance defined 
	 * by @p op.
	 * @param op		Source ObjectPath containing nameSpace, classname 
	 *					and key components.
	 * @param assoc_class 	If not empty, MUST be a valid Association Class 
	 *					name.
	 * 					It acts as a filter on the returned set of 
	 *					Objects by mandating that each returned Object 
	 *					MUST be associated to the source Object via an
	 *					Instance of this Class or one of its subclasses.
	 * @param result_class If not empty, MUST be a valid Class name.
	 *					It acts as a filter on the returned set of 
	 *					Objects by mandating that each returned Object 
	 *					MUST be either an Instance of this Class (or one
	 *				 	of its subclasses).
	 * @param role 		If not NULL, MUST be a valid Property name.
	 *					It acts as a filter on the returned set of 
	 *					Objects by mandating that each returned Object 
	 *					MUST be associated to the source Object
	 *					via an Association in which the source Object 
	 *					plays the specified role (i.e. the name of the 
	 *					Property in the Association Class that refers
	 *					to the source Object MUST match the value of 
	 *					this parameter).
	 * @param result_role 	If not NULL, MUST be a valid Property name.
	 *					It acts as a filter on the returned set of 
	 *					Objects by mandating that each returned Object 
	 *					MUST be associated to the source Object via an 
	 *					Association in which the returned Object plays 
	 *					the specified role (i.e. the name of the Property 
	 *					in the Association Class that refers to the 
	 *					returned Object MUST match the value of this 
	 *					parameter).
	 * @return	An iterator to the object paths
	 * @throws			ECIMError
	 */
	virtual CCIMObjectPath::iterator associatorNames (const CCIMObjectPath& op,
													  const string&		assoc_class,
													  const string&		result_class,
													  const string&		role,
													  const string&		result_role);


	/**
	 * Enumerates the association instances that refer to the instance 
	 * defined by @p op.
	 * @param op			Source ObjectPath containing nameSpace, classname and 
	 *						key components.
	 * @param result_class	If not NULL, MUST be a valid Class name.
	 *						It acts as a filter on the returned set of 
	 *						Objects by mandating that each returned Object 
	 *						MUST be either an Instance of this Class (or one
	 * 						of its subclasses).
	 * @param role 			If not NULL, MUST be a valid Property name.
	 *						It acts as a filter on the returned set of Objects 
	 *						by mandating that each returned Object MUST be 
	 *						associated to the source Object via an Association in 
	 *						which the source Object plays the specified role
	 *						(i.e. the name of the Property in the Association Class 
	 *						that refers to the source Object MUST match the value 
	 *						of this parameter).
	 * @param flags			Reserved.
	 * @param props			If not empty, the members of the array define one or 
	 *						more Property names. Each returned Object MUST 
	 *						NOT include elements for any Properties missing from 
	 *						this list
	 * @return				An iterator to the instances.
	 * @throws				ECIMError.
	 */
	virtual CCIMInstance::iterator references (const CCIMObjectPath& op,
											   const string&	result_class,
											   const string&	role,
											   CMPIFlags		flags,
											   const vector<string>& props = vector <string>()
											   );

	/**
	 * Enumerates the association object paths that refer to the instance 
	 * defined by @p op.
	 * @param op			Source ObjectPath containing nameSpace, classname and 
	 *						key components.
	 * @param result_class	If not NULL, MUST be a valid Class name.
	 *						It acts as a filter on the returned set of 
	 *						Objects by mandating that each returned Object 
	 *						MUST be either an Instance of this Class (or one
	 * 						of its subclasses).
	 * @param role 			If not NULL, MUST be a valid Property name.
	 *						It acts as a filter on the returned set of Objects 
	 *						by mandating that each returned Object MUST be 
	 *						associated to the source Object via an Association in 
	 *						which the source Object plays the specified role
	 *						(i.e. the name of the Property in the Association Class 
	 *						that refers to the source Object MUST match the value 
	 *						of this parameter).
	 * @return				An iterator to the object paths.
	 * @throws				ECIMError.
	 */
	virtual CCIMObjectPath::iterator referenceNames (
											const CCIMObjectPath& op,
											const string&	result_class,
											const string&	role);

	/**
	 * Invoke a named, extrinsic method of an Instance defined by 
	 * the @p op parameter.
	 * @param op		ObjectPath containing nameSpace, classname and 
	 *					key components.
	 * @param method	Method name
	 * @param in 		Input parameters.
	 * @param out 		Output parameters.
	 * @return 			Method return value.
	 * @throws			ECIMError.
	 */
	virtual CCIMData invokeMethod (const CCIMObjectPath& op,
						  		   const string&		method,
						  		   const CCIMArgument&	in,
								   CCIMArgument*		out);


	/**
	 * Set the named property value of an Instance defined by the 
	 * @p op parameter.
	 * @param op 	ObjectPath containing nameSpace, classname and key 
	 * 				components.
	 * @param name 	Property name
	 * @param value Value.
	 * @return		None.
	 * @throws		ECIMError
	 */
	virtual void setProperty (const CCIMObjectPath& op,
							  const string&		name,
							  const CCIMValue&	value);

	/** 
	 * Get the named property value of an Instance defined by 
	 * the @p op parameter.
	 * @param op	ObjectPath containing nameSpace, classname and 
	 *				key components.
	 * @param name 	Property name
	 * @return 		Property value.
	 * @throws		ECIMError.
	 */
	virtual CCIMValue getProperty (const CCIMObjectPath& op,
						  		   const string& name);

	/**
	 * Subscribe to an event.
 	 * @param op				 Objectpath containing namespace, classname and keys.
	 * @param delivery_uri		 The URI to which the event needs to be delivered.
	 * @param mode				 MODE_PUSH, MODE_PUSH_ACK, MODE_PULL
	 * @param heartbeat_interval The interval in which heartbeat events are sent.
	 * @param expiration_timeout The timeout by which the subscription expires.
	 * @param dialect			 
	 * @param filter			 Event filter.
	 * @param resource_uri
	 * @return					 The UUID of the subscription.
	 * @throws					 ECIMError.
	 */
	virtual string subscribeEvent (const CCIMObjectPath& op,
								   const string&	delivery_uri, 
								   int 				mode, 
								   float			heartbeat_interval,
								   float			expiration_timeout,
								   const string&	dialect,
								   const string&	filter);

	virtual string subscribeToEvent (const CCIMObjectPath &cop, const vector<string>& key_props);

	/**
	 * Un subscribe a previously subscribed event.
	 * @throws		ECIMError.
	 */
	virtual void unsubscribeEvent (const CCIMObjectPath& op);

	/**
	 * Renew an existing subscription.
	 * @param time	The renew time of the subscription.
	 * @throws		ECIMError.
	 */
	virtual void renewSubscription (const CCIMObjectPath& op,const string& renewtime); 

	/**
	 * Gets the Host name for this client
	 * @return hostname
	 */
	virtual string getHostName (void);

	/**
	 * Gets the Port Number for this client
	 * @return port
	 */
	virtual int getPort (void);

	/**
	 * Gets the User name for this client
	 * @return user
	 */
	virtual string getUser (void);

	/**
	 * Gets the Password for this client
	 * @return password
	 */
	virtual string getPassword (void);

	/**
	 * Gets the implementation namespace for this client
	 * @return namesapce
	 */
	virtual string getImplementationNS (void);

	/**
	 * Gets the interop namespace for this client
	 * @return namesapce
	 */
	virtual string getInteropNS (void);

	/**
	 * Sets the time out for this client
	 * @param timeout Timeout value to set.
	 */
	virtual void setTimeout (unsigned long timeout);

	/**
	 * Gets the time out for this client
	 * @return Timeout
	 */
	virtual unsigned long getTimeout (void);

	
private:
	CMCIClient*	_cc;
	int*		_ref_count;
};

};	/* namespace dsdk */

#endif /* __DSDK_SFCCCLIENT_H__ */

