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
 * indications.h
 * A class representing a Indications.
 */
#ifndef __DSDK_INDICATIONS_H__
#define __DSDK_INDICATIONS_H__
#include <dsdk/dsdk_api.h>
#include <dsdk/dsdktypes.h>
#include <dsdk/cimmap.h>

#ifdef _WIN32
#pragma warning (push)
#pragma warning( disable: 4251 )
#endif

namespace dsdk
{

class CIM_IndicationFilter;
class CIndicationFilter;
typedef CAPIIterator<CIndicationFilter, CIM_IndicationFilter> _CIndicationFilterIterator;

class CIM_FilterCollection;
class CFilterCollection;
typedef CAPIIterator<CFilterCollection, CIM_FilterCollection> _CFilterCollectionIterator;

class CIM_ListenerDestination;
class CAlertDestination;
typedef CAPIIterator<CAlertDestination, CIM_ListenerDestination> _CAlertDestinationIterator;

class CIM_ManagedElement;
template <typename T1, typename T2> class CIM_AbstractIndicationSubscription;
class CAbstractIndicationSubscription;
typedef CAPIIterator<CAbstractIndicationSubscription, CIM_AbstractIndicationSubscription<CIM_ManagedElement, CIM_ListenerDestination> > _CAbstractIndicationSubscriptionIterator;

template <typename T1, typename T2> class CIM_IndicationSubscription;
class CIndicationSubscription;
typedef CAPIIterator<CIndicationSubscription, CIM_IndicationSubscription<CIM_IndicationFilter, CIM_ListenerDestination> > _CIndicationSubscriptionIterator;

template <typename T1, typename T2> class CIM_FilterCollectionSubscription;
class CFilterCollectionSubscription;
typedef CAPIIterator<CFilterCollectionSubscription, CIM_FilterCollectionSubscription<CIM_FilterCollection, CIM_ListenerDestination> > _CFilterCollectionSubscriptionIterator;


class DSDK_Export CSubscriptionParams {

public:
	static const uint16	SUBSCRIBE_DELIVERYMODE_PUSH = 0;
	static const uint16	SUBSCRIBE_DELIVERYMODE_PUSHWITHACK = 1;
	static const uint16	SUBSCRIBE_DELIVERYMODE_BATCH = 2;
	static const uint16	SUBSCRIBE_DELIVERYMODE_PULL = 3;

	//static const uint16	SUBSCRIBE_FILTERTYPE_COLLECTION = 4;
	//static const uint16	SUBSCRIBE_FILTERTYPE_STATICFILTER = 5;
	//static const uint16	SUBSCRIBE_FILTERTYPE_DYNAMICFILTER = 6;

	static const uint16	SUBSCRIBE_ENCODETYPE_UTF8 = 4;
	static const uint16	SUBSCRIBE_ENCODETYPE_UTF16 = 5;


public:
	CSubscriptionParams(const string notifyURI, const uint16 deliveryMode/*, const uint16 filterType*/);

	/* Mandatory parameters */

	/**
	 * Sets Delivery Mode of Notifications
	 * @param deliveryMode one of the delivery types (PUSH/PULL/PUSH WITH ACK/BATCH).
	 */
	void setDeliveryMode(const uint16 deliveryMode);


	/* Optional parameters */

	/**
	 * Sets Encode type
	 * @param encodeType UTF-8 or UTF-16
	 */
	void setEncodeType(const uint16 encodeType);

	/**
	 * Sets ExpirationTime of the subscription
	 * @param Expiry time in seconds in the format - PT50S.
	 */
	void setExpirationTime(const string expiryTime);

	/**
	 * Enable or disable Bookmarks
	 * @param bookmark		true - to enable bookmarks
	 *						false - to disable bookmarks.
	 */
	void reqestBookMarks(bool bookmark);

	/**
	 * Sets Dynamic Filter Options
	 * @param pFilterResURI		ResourceURI of the indication
	 * @param pFilterQuery		Query string based on the QueryType.
	 * @param pQueryType		Query type either of CQL or WQL type.
	 */
	void setDynamicFilterOptions(string pFilterResURI, string pFilterQuery, string pQueryType);

	/**
	 * Sets End To URI incase subscription expirty/termination.
	 * @param pEndToURI		EndToURI for the indication.
	 */
	void setEndToURI(string pEndToURI);

	/**
	 * Sets Locale of the notification.
	 * @param plocale		Specifies the locale type Ex: 'en'
	 */
	void setLocale(string plocale);

	/**
	 * Enable or disable booksmarks
	 * @param bookMarks		true - Enable the bookmark
	 *						false - Disables the bookmark
	 */
	void enableBookMarks(bool bookMarks);

	/**
	 * Sets Heartbeat interval.
	 * @param interval		Specifies the heartbeat interval Ex. 'PT10'
	 */
	void setHeartBeatInterval(string interval);

	/**
	 * Sets ConnectionRetryCount 
	 * @param retryCount 		Specifies the retry count to send a notification.
	 */
	void setConnectionRetryCount(int retryCount);

	string getResourceURI();
	vector <string> getLowerObject();

private:
	vector<string> subscribeParams;


	string notifyURI, endToURI;
	uint16 deliveryMode, /*filterType,*/ encodeType;
	string expirationTime;
	string heartbeatInterval;
	string locale;
	string bookMarks;
	string retryCount;

	/* Dynamic Filter related parameters */
	string dynFilterResourceURI;
	string dynFilterDialect;
	string dynFilterQuery;
	string dynFilterQueryType;


	bool   bookmarks;


};

class DSDK_Export CIndicationFilter
{
public:
	DECLARE_API_ITERATOR (CIndicationFilter);
	typedef CIM_IndicationFilter CIMType;

public:
	/**
	 * Enumerates all the indication filter present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the indicstion filter.
	 */
	static CIndicationFilter::iterator enumIndicationFilter (IClient* client,
										 				  bool cached = true);

public:
	/**
	 * Return the underlying CIM object
	 */
	CIM_IndicationFilter* getCIMObject (void) const { return _if; }


	/**
	 * Gets SystemCreationClassName
	 * @return the systemcreationclassname
	 */
	string getSystemCreationClassName (void) const;

	/**
	 * Gets SystemName
	 * @return the systemname
	 */
	string getSystemName (void) const;

	/**
	 * Gets CreationClassName
	 * @ return the creationclassname
	 */
	string getCreationClassName (void) const;

	/**
	 * Gets the Indication Filter name
	 * @return The Indication Filter name
	 */
	string getName (void) const;


	/**
	 * Gets the Query stirng for this filter
	 * @return The Query
	 */
	string getQuery (void) const;

	/**
	 * Gets the query language for this filter
	 * @ return the query language
	 */
	string getQueryLanguage (void) const;

	/**
	 * Gets SourceNamespace
	 * @ return the sourcenamespaces
	 */
	string getSourceNamespace (void) const;

	/**
	 * Gets ElementName
	 * @ return the element name
	 */
	string getElementName (void) const;


	/**
	 * Gets IndividualSubscriptionSupported
	 * @return	true if supported
	 *			false otherwise
	 */
	boolean getIndividualSubscriptionSupported (void) const;


	/**
	 * Gets FilterCreationEnabled
	 * @return	true if enabled
	 *			false otherwise
	 */
	static boolean getFilterCreationEnabled (void) ;

	/*
	 * deleteFilter
	*/
	void deleteFilter (void) const;

	/**
	 * Creates a new indication filter.
	 * @param client			Pointer to the client interface.
	 * @param querylanguage		Query language to be used for the filter.
	 *							Example "CQL" for CIM query language.
	 * @param query				Query string to create the filter based on the querylanguage.
	 *							Example "SELECT * FROM CIM_AlertIndication" for CQL.
	 */
	static CIndicationFilter createFilter (IClient* client, string querylanguage, string query);

public:
	/**
	 * Construct this object from the corresponding CIM_IndicationFilter
	 * object
	 */
	CIndicationFilter (const CIM_IndicationFilter& If);

	/**
	 * Copy constructor
	 */
	CIndicationFilter (const CIndicationFilter& If);

	/**
	 * Destructor
	 */
	~CIndicationFilter ();

	/**
	 * Assignment operator
	 */
	const CIndicationFilter& operator = (const CIndicationFilter& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void) ;

private:
	CIM_IndicationFilter*	_if;
};

/**
  * @class CFilterCollection
  * @brief A class representing a Filter Collection
  **/

class DSDK_Export CFilterCollection
{
public:
	DECLARE_API_ITERATOR (CFilterCollection);
	typedef CIM_FilterCollection CIMType;

public:
	/**
	 * Enumerates all the filter Collections present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the indicstion filter.
	 */
	static CFilterCollection::iterator enumFilterCollection (IClient* client,
										 				  bool cached = true);

public:
	/**
	 * Return the underlying CIM object
	 */
	CIM_FilterCollection* getCIMObject (void) const { return _fc; }

	/**
	 * Gets InstanceID
	 * @ return the Inatance ID
	 */
	string getInstanceID (void) const;

	/**
	 * Gets Collection Nme
	 * @ return the collection name
	 */
	string getCollectionName (void) const;

	/**
	 * Gets all filters
	 * @ return all the filters
	 */
	vector<CIndicationFilter> getAllFilters (void) const;

	/*
	 * deleteFilterCollection
	*/
	void deleteFilterCollection (void) const;

	/**
	 * Creates a new filter Collection.
	 * @param client			Pointer to the client interface.
	 * @param filtername		Collection filter name.
	 * @param filters			List for Indication filter to be added to this collection.
	 */
	static CFilterCollection createFilterCollection (IClient* client, string filtername, vector <CIndicationFilter> filters);

public:
	/**
	 * Construct this object from the corresponding CIM_IndicationFilter
	 * object
	 */
	CFilterCollection (const CIM_FilterCollection& Fc);

	/**
	 * Copy constructor
	 */
	CFilterCollection (const CFilterCollection& Fc);

	/**
	 * Destructor
	 */
	~CFilterCollection ();

	/**
	 * Assignment operator
	 */
	const CFilterCollection& operator = (const CFilterCollection& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void) ;

private:
	CIM_FilterCollection*	_fc;
};

/**
  * @class CAlertDestination
  * @brief A class representing a alert Destination
  **/
class DSDK_Export CAlertDestination
{
public:
	DECLARE_API_ITERATOR (CAlertDestination);
	typedef CIM_ListenerDestination CIMType;

public:
	/**
	 * Enumerates all the alert destination present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the listener destination.
	 */
	static CAlertDestination::iterator enumAlertDestination (IClient* client,
										 				  bool cached = true);

public:
	/**
	 * Return the underlying CIM object
	 */
	CIM_ListenerDestination* getCIMObject (void) const { return _ld; }


	/**
	 * Gets SystemCreationClassName
	 * @return the systemcreationclassname
	 */
	string getSystemCreationClassName (void) const;

	/**
	 * Gets SystemName
	 * @return the systemname
	 */
	string getSystemName (void) const;

	/**
	 * Gets CreationClassName
	 * @ return the creationclassname
	 */
	string getCreationClassName (void) const;

	/**
	 * Gets the listener destination name
	 * @return The listener destination name
	 */
	string getName (void) const;

	/**
	 * Gets PersistenceType
	 * @return The persistance type
	 */
	uint16 getPersistenceType (void) const;

	/**
	 * Gets ElementName
	 * @ return the element name
	 */
	string getElementName (void) const;

	/**
	 * Gets the destination of the alert
	 * @return	The destination
	 */
	string getDestination (void) const;

	/**
	 * Gets Protocol
	 * @return The listener destination protocol
	 */
	uint16 getProtocol (void) const;

	/*
	 * Deletes this alert destination
	 */
	void deleteDestination (void) const;

	/*
	 * Creats a Alert destination
	 * @param client		Pointer to the client interface.
	 * @param destination	Destination stirng in below format
	 *						http://<ipaddress>:<port>/path
	 *						Example http://192.168.0.11:8080/eventsink
	 */
	static  CAlertDestination createDestination (IClient* client, string destination);


public:
	/**
	 * Construct this object from the corresponding CIM_ListenerDestination
	 * object
	 */
	CAlertDestination (const CIM_ListenerDestination& ld);

	/**
	 * Copy constructor
	 */
	CAlertDestination (const CAlertDestination& ld);

	/**
	 * Destructor
	 */
	~CAlertDestination ();

	/**
	 * Assignment operator
	 */
	const CAlertDestination& operator = (const CAlertDestination& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void) ;

private:
	CIM_ListenerDestination*	_ld;
};

/**
  * @class CAbstractIndicationSubscription
  * @brief A class representing a Indication subscription
  **/

class DSDK_Export CAbstractIndicationSubscription
{
public:
	DECLARE_API_ITERATOR (CAbstractIndicationSubscription);
	typedef CIM_AbstractIndicationSubscription<CIM_ManagedElement, CIM_ListenerDestination> CIMType;

public:
	/**
	 * Enumerates all the indication subscription present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the indication subscription.
	 */
	static CAbstractIndicationSubscription::iterator enumIndicationSubscription (IClient* client,
										 				  bool cached = true);

public:
	/**
	 * Return the underlying CIM object
	 */
	CIM_AbstractIndicationSubscription<CIM_ManagedElement, CIM_ListenerDestination>* getCIMObject (void) const { return _ais; }

	/**
	 * Gets OnFatalErrorPolicy
	 */
	uint16 getOnFatalErrorPolicy (void) const;

	/**
	 * Gets OtherOnFatalErrorPolicy
	 */
	string getOtherOnFatalErrorPolicy (void) const;

	/**
	 * Gets FailureTriggerTimeInterval
	 */
	uint64 getFailureTriggerTimeInterval (void) const;

	/**
	 * Gets SubscriptionState
	 */
	uint16 getSubscriptionState (void) const;

	/**
	 * Gets OtherSubscriptionState
	 */
	string getOtherSubscriptionState (void)  const;

	/**
	 * Gets RepeatNotificationPolicy
	 */
	uint16 getRepeatNotificationPolicy (void) const;

	/**
	 * Gets RepeatNotificationInterval
	 */
	uint64 getRepeatNotificationInterval (void) const;

	/**
	 * Gets RepeatNotificationGap
	 */
	uint64 getRepeatNotificationGap (void)  const;

	/**
	 * Gets RepeatNotificationCount
	 */
	uint16 getRepeatNotificationCount (void) const;

	/*
	 * getFilternName
	 */
	string getFilternName (IClient* client) const;

	/*
	 * getAlertDestination
	*/
	string getAlertDestination (IClient* client) const;

	/**
	 *  The Filter that defines the criteria and data of the possible Indications of this subscription.
	 */
	CCIMObjectPath getFilter(void) const;

	/**
	 * The Handler addressing delivery of the possible Indications of this subscription.
	 */
	CCIMObjectPath getHandler(void) const;

	/*
	 * unsubcribe this Subscription
	 */
	void unSubscribe (void) const;

	/*
	 * Renew this Subscription
	 */

	void renewSubscription (string renewtime) const;


public:
	/**
	 * Construct this object from the corresponding CIM_IndicationSubscription
	 * object
	 */
	CAbstractIndicationSubscription (const CIM_AbstractIndicationSubscription<CIM_ManagedElement, CIM_ListenerDestination>& ais);

	/**
	 * Copy constructor
	 */
	CAbstractIndicationSubscription (const CAbstractIndicationSubscription& ais);

	/**
	 * Destructor
	 */
	~CAbstractIndicationSubscription ();

	/**
	 * Assignment operator
	 */
	const CAbstractIndicationSubscription& operator = (const CAbstractIndicationSubscription& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void) ;

private:
	CIM_AbstractIndicationSubscription<CIM_ManagedElement, CIM_ListenerDestination>*	_ais;
};


/**
  * @class CIndicationSubscription
  * @brief A class representing a Indication subscription
  **/

class DSDK_Export CIndicationSubscription
{
public:
	DECLARE_API_ITERATOR (CIndicationSubscription);
	typedef CIM_IndicationSubscription<CIM_IndicationFilter, CIM_ListenerDestination> CIMType;

public:
	/**
	 * Enumerates all the indication subscription present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the indication subscription.
	 */
	static CIndicationSubscription::iterator enumIndicationSubscription (IClient* client,
										 				  bool cached = true);

public:
	/**
	 * Return the underlying CIM object
	 */
	CIM_IndicationSubscription<CIM_IndicationFilter, CIM_ListenerDestination>* getCIMObject (void) const { return _is; }

	/**
	 * Gets OnFatalErrorPolicy
	 */
	uint16 getOnFatalErrorPolicy (void) const;

	/**
	 * Gets OtherOnFatalErrorPolicy
	 */
	string getOtherOnFatalErrorPolicy (void) const;

	/**
	 * Gets FailureTriggerTimeInterval
	 */
	uint64 getFailureTriggerTimeInterval (void) const;

	/**
	 * Gets SubscriptionState
	 */
	uint16 getSubscriptionState (void) const;

	/**
	 * Gets OtherSubscriptionState
	 */
	string getOtherSubscriptionState (void)  const;

	/**
	 * Gets RepeatNotificationPolicy
	 */
	uint16 getRepeatNotificationPolicy (void) const;

	/**
	 * Gets RepeatNotificationInterval
	 */
	uint64 getRepeatNotificationInterval (void) const;

	/**
	 * Gets RepeatNotificationGap
	 */
	uint64 getRepeatNotificationGap (void)  const;

	/**
	 * Gets RepeatNotificationCount
	 */
	uint16 getRepeatNotificationCount (void) const;

	/*
	 * getFilternName
	 */
	string getFilternName (IClient* client) const;

	/*
	 * getFilterQuery
	 */
	string getFilterQuery (IClient* client) const;

	/*
	 * getFilterQueryLanguage
	 */
	string getFilterQueryLanguage (IClient* client) const;

	/*
	 * getAlertDestination
	*/
	string getAlertDestination (IClient* client) const;

	/**
	 *  The Filter that defines the criteria and data of the possible Indications of this subscription.
	 */
	CCIMObjectPath getFilter(void) const;

	/**
	 * The Handler addressing delivery of the possible Indications of this subscription.
	 */
	CCIMObjectPath getHandler(void) const;

	/*
	 * Delets this Subscription
	*/
	void deleteSubscription (void) const;

	 //@todo need to revisit createSubscription, may need changes.
	/**
	 * Create a Alert/Indication subscription.
	 * @param client		Pointer to the client interface.
	 * @param filter		Filter to be used for creating subscriptoin.
	 * @param destination	Destination to be used for this subscription.
	 */
	static CIndicationSubscription createSubscription (IClient* client,
														CIndicationFilter filter,
														CAlertDestination destination);

	/**
	 * Create a Alert/Indication subscription.
	 * @param client		Pointer to the client interface.
	 * @param querylanguage		Query language to be used for the filter.
	 *							Example "CQL" for CIM query language.
	 * @param query				Query string to create the filter based on the querylanguage.
	 *							Example "SELECT * FROM CIM_AlertIndication" for CQL.
	 * @param destination	Destination stirng in below format
	 *						http://<ipaddress>:<port>/path
	 *						Example http://192.168.0.11:8080/eventsink
	 */
	 static CIndicationSubscription createSubscription (IClient* client, string querylanguage,
														string query,	 string destination);

	/**
	 * Create a Alert/Indication subscription.
	 * @param client			Pointer to the client interface.
	 * @param querylanguage		Query language to be used for the filter.
	 *							Example "CQL" for CIM query language.
	 * @param query				Query string to create the filter based on the querylanguage.
	 *							Example "SELECT * FROM CIM_AlertIndication" for CQL.
	 * @param destination		Destination stirng in below format
	 *							http://<ipaddress>:<port>/path
	 *							Example http://192.168.0.11:8080/eventsink
	 * @param mode				 MODE_PUSH, MODE_PUSH_ACK, MODE_PULL
	 * @param heartbeat_interval The interval in which heartbeat events are sent.
	 * @param expiration_timeout The timeout by which the subscription expires.
	 */
	static string createSubscription (IClient* client,
										string	querylanguage,	string query,
										string	destination,	int mode,
										float	heartbeat_interval,
										float	expiration_timeout,
										string	resource_uri = "http://schemas.dmtf.org/wbem/wscim/1/*");

	/**
	 * Create a Query based subscription.
	 * @param client			Pointer to the client interface.
	 * @param params			all the eventing related subscription parameters.
	 */
	static string createSubscription (IClient* client,	CSubscriptionParams params);

	static string createSubscription (IClient* client,
											 CIndicationFilter filter,
											 string destination,
											 int mode,
											 float	heartbeat_interval,
											 float  expiration_timeout);

	/**
	 * Create a IndicationFilter subscription.
	 * @param client			Pointer to the client interface.
	 * @param filter			Filtercollection to be used for creating subscriptoin.
	 * @param params			all the eventing related subscription parameters.
	 */
	static string createSubscription (IClient* client,
										CIndicationFilter filter,
										CSubscriptionParams params);

public:
	/**
	 * Construct this object from the corresponding CIM_IndicationSubscription
	 * object
	 */
	CIndicationSubscription (const CIM_IndicationSubscription<CIM_IndicationFilter, CIM_ListenerDestination>& is);

	/**
	 * Copy constructor
	 */
	CIndicationSubscription (const CIndicationSubscription& is);

	/**
	 * Destructor
	 */
	~CIndicationSubscription ();

	/**
	 * Assignment operator
	 */
	const CIndicationSubscription& operator = (const CIndicationSubscription& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void) ;

private:
	CIM_IndicationSubscription<CIM_IndicationFilter, CIM_ListenerDestination>*	_is;
};

/**
  * @class CFiltercollectionSubscription
  * @brief A class representing a Filter Collection subscription
  **/

class DSDK_Export CFilterCollectionSubscription
{
public:
	DECLARE_API_ITERATOR (CFilterCollectionSubscription);
	typedef CIM_FilterCollectionSubscription<CIM_FilterCollection, CIM_ListenerDestination> CIMType;

public:
	/**
	 * Enumerates all the filter collection subscription present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the indication subscription.
	 */
	static CFilterCollectionSubscription::iterator enumFilterCollectionSubscription (IClient* client,
										 				  bool cached = true);

public:
	/**
	 * Return the underlying CIM object
	 */
	CIM_FilterCollectionSubscription<CIM_FilterCollection, CIM_ListenerDestination>* getCIMObject (void) const { return _fcs; }

	/**
	 * Gets OnFatalErrorPolicy
	 */
	uint16 getOnFatalErrorPolicy (void) const;

	/**
	 * Gets OtherOnFatalErrorPolicy
	 */
	string getOtherOnFatalErrorPolicy (void) const;

	/**
	 * Gets FailureTriggerTimeInterval
	 */
	uint64 getFailureTriggerTimeInterval (void) const;

	/**
	 * Gets SubscriptionState
	 */
	uint16 getSubscriptionState (void) const;

	/**
	 * Gets OtherSubscriptionState
	 */
	string getOtherSubscriptionState (void)  const;

	/**
	 * Gets RepeatNotificationPolicy
	 */
	uint16 getRepeatNotificationPolicy (void) const;

	/**
	 * Gets RepeatNotificationInterval
	 */
	uint64 getRepeatNotificationInterval (void) const;

	/**
	 * Gets RepeatNotificationGap
	 */
	uint64 getRepeatNotificationGap (void)  const;

	/**
	 * Gets RepeatNotificationCount
	 */
	uint16 getRepeatNotificationCount (void) const;

	/*
	 * getFilternName
	 */
	string getFilternName (IClient* client) const;

	/*
	 * getFilterQuery
	 */
	string getFilterQuery (IClient* client) const;

	/*
	 * getFilterQueryLanguage
	 */
	string getFilterQueryLanguage (IClient* client) const;

	/*
	 * getAlertDestination
	*/
	string getAlertDestination (IClient* client) const;

	/*
	 * Delets this Subscription
	*/
	void deleteSubscription (void) const;

	/**
	 * Create a Alert/Indication subscription.
	 * @param client		Pointer to the client interface.
	 * @param filter		Filter to be used for creating subscriptoin.
	 * @param destination	Destination to be used for this subscription.
	 */
	static CFilterCollectionSubscription createSubscription (IClient* client,
														CFilterCollection filter,
														CAlertDestination destination);

	/**
	 * Create a Filter Collection subscription.
	 * @param client			Pointer to the client interface.
	 * @param filtercollection	Filtercollection to be used for creating subscriptoin.
	 * @param destination		Destination stirng in below format
	 *							http://<ipaddress>:<port>/path
	 *							Example http://192.168.0.11:8080/eventsink
	 * @param mode				 MODE_PUSH, MODE_PUSH_ACK, MODE_PULL
	 * @param heartbeat_interval The interval in which heartbeat events are sent.
	 * @param expiration_timeout The timeout by which the subscription expires.
	 */
	static string createSubscription (IClient* client,
											 CFilterCollection filtercollection,
											 string destination,
											 int mode,
											 float	heartbeat_interval,
											 float  expiration_timeout);

		/**
	 * Create a Filter Collection subscription.
	 * @param client			Pointer to the client interface.
	 * @param filtercollection	Filtercollection to be used for creating subscriptoin.
	 * @param destination		Destination stirng in below format
	 *							http://<ipaddress>:<port>/path
	 *							Example http://192.168.0.11:8080/eventsink
	 * @param mode				 MODE_PUSH, MODE_PUSH_ACK, MODE_PULL
	 * @param heartbeat_interval The interval in which heartbeat events are sent.
	 * @param expiration_timeout The timeout by which the subscription expires.
	 */
	static string createSubscription (IClient* client,
										CFilterCollection filter,
										CSubscriptionParams params);


public:
	/**
	 * Construct this object from the corresponding CIM_FilterCollectionSubscription
	 * object
	 */
	CFilterCollectionSubscription (const CIM_FilterCollectionSubscription<CIM_FilterCollection, CIM_ListenerDestination>& is);

	/**
	 * Copy constructor
	 */
	CFilterCollectionSubscription (const CFilterCollectionSubscription& fcs);

	/**
	 * Destructor
	 */
	~CFilterCollectionSubscription ();

	/**
	 * Assignment operator
	 */
	const CFilterCollectionSubscription& operator = (const CFilterCollectionSubscription& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void) ;

private:
	CIM_FilterCollectionSubscription<CIM_FilterCollection, CIM_ListenerDestination>*	_fcs;
};




};	/* namespace dsdk */

#ifdef _WIN32
#pragma warning (pop)
#endif

#endif /*__DSDK_INDICATIONS_H__*/
