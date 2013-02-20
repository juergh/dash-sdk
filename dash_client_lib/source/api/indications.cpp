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
 * indications.cpp
 * A class representing a indications.
 */
#include <dsdk/oal/CIM_IndicationFilter.h>
#include <dsdk/oal/CIM_IndicationService.h>
#include <dsdk/oal/CIM_AbstractIndicationSubscription.h>
#include <dsdk/oal/CIM_IndicationSubscription.h>
#include <dsdk/oal/CIM_ListenerDestination.h>
#include <dsdk/oal/CIM_ServiceAffectsElement.h>
#include <dsdk/oal/CIM_ConcreteComponent.h>
#include <dsdk/oal/CIM_FilterCollection.h>
#include <dsdk/oal/CIM_FilterCollectionSubscription.h>
#include <dsdk/oal/CIM_MemberOfCollection.h>
#include <dsdk/indications.h>
#include <dsdk/dsdkexception.h>
#include "apiimp.h"
#include <dsdk/enumerator.h>
#include <dsdk/eventsubscribe.h>

#define MAX_SIZE 256

typedef CIM_AbstractIndicationSubscription<CIM_ManagedElement, CIM_ListenerDestination> CIMAbstractIndicationSubscription;

typedef CIM_IndicationSubscription<CIM_IndicationFilter, CIM_ListenerDestination> CIMIndicationSubscription;

typedef CIM_FilterCollectionSubscription<CIM_FilterCollection, CIM_ListenerDestination> CIMFilterCollectionSubscription;


using namespace dsdk;

/*
 * Constructor
 */
CIndicationFilter::CIndicationFilter (const CIM_IndicationFilter& If)
{ 
	_if = new CIM_IndicationFilter (If); 
}

/*
 * Constructor
 */
CIndicationFilter::CIndicationFilter (const CIndicationFilter& If)
{
	this->_if = new CIM_IndicationFilter (*(If._if));
}

/*
 * Destruction 
 */
CIndicationFilter::~CIndicationFilter ()
{
	if (this->_if) { delete this->_if; }
}

/*
 * Assignment operator
 */
const CIndicationFilter& 
CIndicationFilter::operator = (const CIndicationFilter& rhs)
{
	if (this->_if) { delete this->_if; }
	this->_if  = new CIM_IndicationFilter (*rhs._if);
	return *this;
}

/*
 * enumerate IndicationFilter
 */
CIndicationFilter::iterator 
CIndicationFilter::enumIndicationFilter (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();
	CIM_IndicationFilter::iterator iter = 
		CIM_IndicationFilter::enumInstances (client, 0, props,
											CCIMObjectPath(client->getInteropNS (), "CIM_IndicationFilter"));

	if (cached) { return createIterator (iter, props); }
	else 		{ return createIterator (iter); }
}

/*
 * deleteFilter
 */
void
CIndicationFilter::deleteFilter (void) const
{
	_if->getClient ()->deleteInstance (_if->getObjectPath ());
}

/*
 * Create Filter
 */ 
CIndicationFilter
CIndicationFilter::createFilter(IClient* client,string querylanguage, string query)
{
	char str[MAX_SIZE]; 
	string name;

	/* create a random name */
	sprintf(str,"%d", rand());
	name += str;

	/* create the object path */
	CCIMObjectPath op (client->getInteropNS (), 
						"http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_IndicationFilter");
	op.addKey ("CreationClassName",toCCIMValue<stringDSDKAdapter> ("CIM_IndicationFilter"));
	op.addKey ("Name",toCCIMValue<stringDSDKAdapter> (name));
	op.addKey ("SystemCreationClassName",toCCIMValue<stringDSDKAdapter> ("CIM_ComputerSystem"));
	op.addKey ("SystemName",toCCIMValue<stringDSDKAdapter> ("localhost.localdomain"));
	op.addKey ("__cimnamespace",toCCIMValue<stringDSDKAdapter> ("root/interop"));

	/* create the new instance locally */
	CCIMInstance inst (op);

	//inst.setProperty("IndividualSubscriptionSupported",to<booleanAdapter> (true));
	inst.setProperty("Query", toCCIMValue<stringDSDKAdapter> (query));
	inst.setProperty("QueryLanguage", toCCIMValue<stringDSDKAdapter> (querylanguage));
	inst.setProperty("SourceNamespace ", toCCIMValue<stringDSDKAdapter> ("root/interop"));

	/* create a new filter in the target */
	CCIMObjectPath filter_op = client->createInstance(op, inst);

	vector<string> empty;
	CIM_IndicationFilter  filter_inst = client->getInstance (filter_op, 0, empty);
	filter_inst.initialize (client);

	return CIndicationFilter (filter_inst);
}

/*
 * getSystemCreationClassName
 */
string 
CIndicationFilter::getSystemCreationClassName (void) const
{
	return _if->getSystemCreationClassName ();
}

/*
 * getSystemName
 */
string 
CIndicationFilter::getSystemName (void) const
{
	return _if->getSystemName ();
}

/*
 * getCreationClassName
 */
string 
CIndicationFilter::getCreationClassName (void) const
{
	return _if->getCreationClassName ();
}

/*
 * getName
 */
string
CIndicationFilter::getName (void) const
{
	return _if->getName ();
}

/*
 * Gets Query
 */
string
CIndicationFilter::getQuery (void) const
{
	return _if->getQuery ();
}

/*
 * Gets QueryLanguage
 */
string
CIndicationFilter::getQueryLanguage (void) const
{
	return _if->getQueryLanguage ();
}

/*
 * getSourceNamespace
 */
string 
CIndicationFilter::getSourceNamespace (void) const
{
	return _if->getSourceNamespace ();
}

/*
 * getElementName
 */
string 
CIndicationFilter::getElementName (void) const
{
	return _if->getElementName ();
}

/*
 * Gets IndividualSubscriptionSupported
 */
boolean
CIndicationFilter::getIndividualSubscriptionSupported (void) const
{
	return _if->getIndividualSubscriptionSupported ();
}


/*
 * getCachedProps
 */
vector<string>
CIndicationFilter::getCachedProps (void) 
{
	vector<string> props;
	props.push_back ("SystemCreationClassName");
	props.push_back ("SystemName");
	props.push_back ("CreationClassName");
	props.push_back ("Name");
	props.push_back ("Query");
	props.push_back ("QueryLanguage");
	props.push_back ("SourceNamespace");
	props.push_back ("ElementName");
	props.push_back ("IndividualSubscriptionSupported");
	return props;
}

/*
 * IndicationFilter::Iterator
 */
DEFINE_API_ITERATOR (CIndicationFilter);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CIndicationFilter, CIM_IndicationFilter);

/**
 * CFilterCollection
 */

/*
 * Constructor
 */
CFilterCollection::CFilterCollection (const CIM_FilterCollection& Fc)
{ 
	_fc = new CIM_FilterCollection (Fc); 
}

/*
 * Constructor
 */
CFilterCollection::CFilterCollection (const CFilterCollection& Fc)
{
	this->_fc = new CIM_FilterCollection (*(Fc._fc));
}

/*
 * Destruction 
 */
CFilterCollection::~CFilterCollection ()
{
	if (this->_fc) { delete this->_fc; }
}

/*
 * Assignment operator
 */
const CFilterCollection& 
CFilterCollection::operator = (const CFilterCollection& rhs)
{
	if (this->_fc) { delete this->_fc; }
	this->_fc  = new CIM_FilterCollection (*rhs._fc);
	return *this;
}

/*
 * enumerate IndicationFilterCollection
 */
CFilterCollection::iterator 
CFilterCollection::enumFilterCollection (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();
	CIM_FilterCollection::iterator iter = 
		CIM_FilterCollection::enumInstances (client, 0, props,
											CCIMObjectPath(client->getInteropNS (), "CIM_FilterCollection"));

	if (cached) { return createIterator (iter, props); }
	else 		{ return createIterator (iter); }
}

/*
 * deleteFilter
 */
void
CFilterCollection::deleteFilterCollection (void) const
{
	_fc->getClient ()->deleteInstance (_fc->getObjectPath ());
}

/*
 * getInstanceID
 */
string 
CFilterCollection::getInstanceID (void) const
{
	return _fc->getInstanceID ();
}

/*
 * getElementName
 */
string 
CFilterCollection::getCollectionName (void) const
{
	return _fc->getCollectionName ();
}


vector<CIndicationFilter> 
CFilterCollection::getAllFilters (void) const
{
	vector<CIndicationFilter>		filters;
	vector<string> props;

	CIM_IndicationFilter::iterator iter =
		CIM_MemberOfCollection <CIM_FilterCollection, CIM_IndicationFilter>::enumerateMember
									(_fc->getClient (), *_fc, props);
	for (; iter != CIM_IndicationFilter::iterator::end (); ++iter)
	{
		CIM_IndicationFilter filter = *iter;
		filters.push_back (filter);
	}

	return filters;
}

/*
 * Create Filter
 */ 
CFilterCollection
CFilterCollection::createFilterCollection(IClient* client, string filtername, vector<CIndicationFilter> filters)
{
	char str[MAX_SIZE]; 
	string name;

	/* create a random name */
	sprintf(str,"%d", rand());
	name += str;

	/* create the object path */
	CCIMObjectPath op (client->getInteropNS (), 
						"http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_IndicationFilter");
	op.addKey ("CreationClassName",toCCIMValue<stringDSDKAdapter> ("CIM_IndicationFilter"));
	op.addKey ("Name",toCCIMValue<stringDSDKAdapter> (name));
	op.addKey ("SystemCreationClassName",toCCIMValue<stringDSDKAdapter> ("CIM_ComputerSystem"));
	op.addKey ("SystemName",toCCIMValue<stringDSDKAdapter> ("localhost.localdomain"));
	op.addKey ("__cimnamespace",toCCIMValue<stringDSDKAdapter> ("root/interop"));

	/* create the new instance locally */
	CCIMInstance inst (op);

	//inst.setProperty("IndividualSubscriptionSupported",to<booleanAdapter> (true));
//	inst.setProperty("Query", toCCIMValue<stringDSDKAdapter> (query));
//	inst.setProperty("QueryLanguage", toCCIMValue<stringDSDKAdapter> (querylanguage));
	inst.setProperty("SourceNamespace ", toCCIMValue<stringDSDKAdapter> ("root/interop"));

	/* create a new filter in the target */
	CCIMObjectPath filter_op = client->createInstance(op, inst);

	vector<string> empty;
	CIM_FilterCollection  filter_inst = client->getInstance (filter_op, 0, empty);
	filter_inst.initialize (client);

	return CFilterCollection (filter_inst);
}

/*
 * getCachedProps
 */
vector<string>
CFilterCollection::getCachedProps (void) 
{
	vector<string> props;
	props.push_back ("InstanceID");
	props.push_back ("CollectionName");
	return props;
}

/*
 * FilterCollection::Iterator
 */
DEFINE_API_ITERATOR (CFilterCollection);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CFilterCollection, CIM_FilterCollection);

/*
 *CAlertDestination
 */ 

/*
 * Constructor
 */
CAlertDestination::CAlertDestination (const CIM_ListenerDestination& ld)
{ 
	_ld = new CIM_ListenerDestination (ld); 
}

/*
 * Constructor
 */
CAlertDestination::CAlertDestination (const CAlertDestination& ld)
{
	this->_ld= new CIM_ListenerDestination (*(ld._ld));
}

/*
 * Destruction 
 */
CAlertDestination::~CAlertDestination ()
{
	if (this->_ld) { delete this->_ld; }
}

/*
 * Assignment operator
 */
const CAlertDestination& 
CAlertDestination::operator = (const CAlertDestination& rhs)
{
	if (this->_ld) { delete this->_ld; }
	this->_ld  = new CIM_ListenerDestination (*rhs._ld);
	return *this;
}

/*
 * enumerate alert Destination
 */
CAlertDestination::iterator 
CAlertDestination::enumAlertDestination (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_ListenerDestination::iterator iter = 
		CIM_ListenerDestination::enumInstances (client, 0, props, 
											CCIMObjectPath(client->getInteropNS (), "CIM_ListenerDestination"));

	if (cached) { return createIterator (iter, props); }
	else 		{ return createIterator (iter); }
}


/*
 * Create Alert Destination
 */ 
CAlertDestination
CAlertDestination::createDestination(IClient* client,string destination)
{

	char str[MAX_SIZE]; 
	string name;

	/* create a random name */
	sprintf(str,"%d", rand ());
	name += str;

	/* create the object path */
	CCIMObjectPath op (client->getInteropNS (), 
						"http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ListenerDestination");
	op.addKey ("CreationClassName", toCCIMValue<stringDSDKAdapter> ("DRI_ListenerDestination"));
	op.addKey ("Name", toCCIMValue<stringDSDKAdapter> (name));
	op.addKey ("SystemCreationClassName", toCCIMValue<stringDSDKAdapter> ("CIM_ComputerSystem"));
	op.addKey ("SystemName", toCCIMValue<stringDSDKAdapter> ("localhost.localdomain"));
	op.addKey ("__cimnamespace", toCCIMValue<stringDSDKAdapter> ("root/interop"));

	/* create the new instance locally */
	CCIMInstance inst (op);
	//instance.setProperty("IndividualSubscriptionSupported",to<booleanAdapter> (true));
	inst.setProperty("Destination", toCCIMValue<stringDSDKAdapter> (destination));
	inst.setProperty("SourceNamespace ", toCCIMValue<stringDSDKAdapter> ("root/interop"));

	/* create the filter instance in the target */
	CCIMObjectPath dest_op = client->createInstance(op, inst);
	
	vector<string> empty;
	CIM_ListenerDestination  dest_inst = client->getInstance (dest_op, 0, empty);
	dest_inst.initialize (client);

	return CAlertDestination (dest_inst);
}

/*
 * deleteDestination
 */
void
CAlertDestination::deleteDestination (void) const
{
	_ld->getClient ()->deleteInstance (_ld->getObjectPath ());
}


/*
 * getSystemCreationClassName
 */
string 
CAlertDestination::getSystemCreationClassName (void) const
{
	return _ld->getSystemCreationClassName ();
}

/*
 * getSystemName
 */
string 
CAlertDestination::getSystemName (void) const
{
	return _ld->getSystemName ();
}

/*
 * getCreationClassName
 */
string 
CAlertDestination::getCreationClassName (void) const
{
	return _ld->getCreationClassName ();
}

/*
 * getName
 */
string
CAlertDestination::getName (void) const
{
	return _ld->getName ();
}

/*
 * Gets PersistenceType
 */
uint16
CAlertDestination::getPersistenceType (void) const
{
	return _ld->getPersistenceType ();
}

/*
 * getElementName
 */
string 
CAlertDestination::getElementName (void) const
{
	return _ld->getElementName ();
}

/*
 * Gets Destination
 */
string 
CAlertDestination::getDestination (void) const
{
	return _ld->getDestination ();
}

/*
 * Gets Protocol
 */
uint16 
CAlertDestination::getProtocol (void) const
{
	return _ld->getProtocol();
}

/*
 * getCachedProps
 */
vector<string> 
CAlertDestination::getCachedProps (void) 
{
	vector<string> props;

	props.push_back ("SystemCreationClassName");
	props.push_back ("SystemName");
	props.push_back ("CreationClassName");
	props.push_back ("Name");
	props.push_back ("PersistenceType");
	props.push_back ("ElementName");
	props.push_back ("Destination");
	props.push_back ("Protocol");
	return props;
}

/*
 * Constructor
 */
CAbstractIndicationSubscription::CAbstractIndicationSubscription (const CIM_AbstractIndicationSubscription<CIM_ManagedElement, 
													CIM_ListenerDestination>& ais)
{ 
	_ais = new CIM_AbstractIndicationSubscription<CIM_ManagedElement, CIM_ListenerDestination> (ais); 
}

/*
 * Constructor
 */
CAbstractIndicationSubscription::CAbstractIndicationSubscription (const CAbstractIndicationSubscription& ais)
{
	this->_ais = new CIM_AbstractIndicationSubscription<CIM_ManagedElement, CIM_ListenerDestination> (*(ais._ais));
}

/*
 * Destruction 
 */
CAbstractIndicationSubscription::~CAbstractIndicationSubscription ()
{
	if (this->_ais) { delete this->_ais; }
}

/*
 * Assignment operator
 */
const CAbstractIndicationSubscription& 
CAbstractIndicationSubscription::operator = (const CAbstractIndicationSubscription& rhs)
{
	if (this->_ais) { delete this->_ais; }
	this->_ais  = new CIM_AbstractIndicationSubscription<CIM_ManagedElement, CIM_ListenerDestination> (*rhs._ais);
	return *this;
}

/*
 * enumerate IndicationSubscription
 */
CAbstractIndicationSubscription::iterator 
CAbstractIndicationSubscription::enumIndicationSubscription (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_AbstractIndicationSubscription<CIM_ManagedElement, CIM_ListenerDestination>::iterator iter = 
			CIM_AbstractIndicationSubscription<CIM_ManagedElement, CIM_ListenerDestination>::enumInstances (client, 0, props,
													CCIMObjectPath(client->getInteropNS (), "CIM_AbstractIndicationSubscription"));

	if (cached) { return createIterator (iter, props); }
	else 		{ return createIterator (iter); }
}

/*
 * deleteSubscription
 */
void
CAbstractIndicationSubscription::unSubscribe (void) const
{
	_ais->getClient ()->unsubscribeEvent(_ais->getObjectPath ());
}

/*
 * renewSubscription
 */
void
CAbstractIndicationSubscription::renewSubscription (string renewtime) const
{
	 _ais->getClient ()->renewSubscription(_ais->getObjectPath (),renewtime);
}

/*
 *  getOnFatalErrorPolicy
 */
uint16 
CAbstractIndicationSubscription::getOnFatalErrorPolicy (void) const
{
	return _ais->getOnFatalErrorPolicy();
}

/*
 * Gets OtherOnFatalErrorPolicy
 */
string 
CAbstractIndicationSubscription::getOtherOnFatalErrorPolicy (void) const
{
	return _ais->getOtherOnFatalErrorPolicy();
}

/*
 * Gets FailureTriggerTimeInterval
 */
uint64
CAbstractIndicationSubscription::getFailureTriggerTimeInterval (void) const
{
	return _ais->getFailureTriggerTimeInterval();
}
/*
 * Gets SubscriptionState
 */
uint16 
CAbstractIndicationSubscription::getSubscriptionState (void) const
{
	return _ais->getSubscriptionState();
}

/*
 * Gets OtherSubscriptionState
 */
string 
CAbstractIndicationSubscription::getOtherSubscriptionState (void)  const
{
	return _ais->getOtherSubscriptionState();
}

/*
 * Gets RepeatNotificationPolicy
 */
uint16 
CAbstractIndicationSubscription::getRepeatNotificationPolicy (void) const
{
	return _ais->getRepeatNotificationPolicy();
}

/*
 * Gets RepeatNotificationInterval
 */
uint64 
CAbstractIndicationSubscription::getRepeatNotificationInterval (void) const
{
	return _ais->getRepeatNotificationInterval();
}

/*
 * Gets RepeatNotificationGap
 */
uint64 
CAbstractIndicationSubscription::getRepeatNotificationGap (void)  const
{
	return _ais->getRepeatNotificationGap();
}

/*
 * Gets RepeatNotificationCount
 */
uint16 
CAbstractIndicationSubscription::getRepeatNotificationCount (void) const
{
	return _ais->getRepeatNotificationCount();
}

/*
 * getFilternName
 */
string  
CAbstractIndicationSubscription::getFilternName(IClient* client) const
{
	vector<string> props;
	props.push_back("CollectionName");
	props.push_back("Name");

	try {
		CIM_IndicationSubscription<CIM_IndicationFilter, CIM_ListenerDestination>* is
			= (CIM_IndicationSubscription<CIM_IndicationFilter, CIM_ListenerDestination>*)_ais;
		CCIMObjectPath ObjPath = is->getFilter();

		// there is a bug in RI, which does not return correct resourse URI, once its fixed remove this line.
		//ObjPath.setClassName ("http://schemas.dri.org/wbem/wscim/1/cim-schema/2/CIM_IndicationFilter");

		CIM_IndicationFilter  ins = client->getInstance (ObjPath,0,props);
		ins.enableCache(props,false);
		ins.initialize (client);
		return ins.getName();
	}
	catch (...)
	{
		CIM_FilterCollectionSubscription<CIM_FilterCollection, CIM_ListenerDestination>* fcs
			= (CIM_FilterCollectionSubscription<CIM_FilterCollection, CIM_ListenerDestination>*)_ais;
		CCIMObjectPath ObjPath = fcs->getFilter();

		// there is a bug in RI, which does not return correct resourse URI, once its fixed remove this line.
		//ObjPath.setClassName ("http://schemas.dri.org/wbem/wscim/1/cim-schema/2/CIM_FilterCollection");

		CIM_FilterCollection ins = client->getInstance (ObjPath,0,props);
		ins.enableCache(props,false);
		ins.initialize (client);
		return ins.getCollectionName();	
	}
}

/*
 * getAlertDestination
 */
string 
CAbstractIndicationSubscription::getAlertDestination(IClient* client) const
{
	vector<string> props;
	props.push_back("Destination");
	CCIMObjectPath ObjPath = _ais->getHandler();

	// there is a bug in RI, which does not return correct resourse URI, once its fixed remove this line.
	//ObjPath.setClassName ("http://schemas.dri.org/wbem/wscim/1/cim-schema/2/DRI_ListenerDestinationWsMa");

	CIM_ListenerDestination  ins = client->getInstance(ObjPath, 0, props);
	ins.enableCache(props,false);
	ins.initialize (client);
	return ins.getDestination();
}

/*
 * getCachedProps
 */
vector<string> 
CAbstractIndicationSubscription::getCachedProps (void) 
{
	vector<string> props;
	props.push_back ("OnFatalErrorPolicy");
	props.push_back ("OtherOnFatalErrorPolicy");
	props.push_back ("FailureTriggerTimeInterval");
	props.push_back ("OnFatalErrorPolicy");
	props.push_back ("SubscriptionState");
	props.push_back ("OtherSubscriptionState");
	props.push_back ("RepeatNotificationPolicy");
	props.push_back ("RepeatNotificationInterval");
	props.push_back ("RepeatNotificationGap");
	props.push_back ("RepeatNotificationCount");
	props.push_back ("Filter");
	props.push_back ("Handler");
	return props;
}

/*
 * IndicationSubscription::Iterator
 */
DEFINE_API_ITERATOR (CAbstractIndicationSubscription);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CAbstractIndicationSubscription, CIMAbstractIndicationSubscription);

/*
 * ListenerDestination::Iterator
 */
DEFINE_API_ITERATOR (CAlertDestination);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CAlertDestination, CIM_ListenerDestination);

/*
 * Constructor
 */
CIndicationSubscription::CIndicationSubscription (const CIM_IndicationSubscription<CIM_IndicationFilter, 
													CIM_ListenerDestination>& is)
{ 
	_is = new CIM_IndicationSubscription<CIM_IndicationFilter, CIM_ListenerDestination> (is); 
}

/*
 * Constructor
 */
CIndicationSubscription::CIndicationSubscription (const CIndicationSubscription& is)
{
	this->_is = new CIM_IndicationSubscription<CIM_IndicationFilter, CIM_ListenerDestination> (*(is._is));
}

/*
 * Destruction 
 */
CIndicationSubscription::~CIndicationSubscription ()
{
	if (this->_is) { delete this->_is; }
}

/*
 * Assignment operator
 */
const CIndicationSubscription& 
CIndicationSubscription::operator = (const CIndicationSubscription& rhs)
{
	if (this->_is) { delete this->_is; }
	this->_is  = new CIM_IndicationSubscription<CIM_IndicationFilter, CIM_ListenerDestination> (*rhs._is);
	return *this;
}

/*
 * enumerate IndicationSubscription
 */
CIndicationSubscription::iterator 
CIndicationSubscription::enumIndicationSubscription (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_IndicationSubscription<CIM_IndicationFilter, CIM_ListenerDestination>::iterator iter = 
			CIMIndicationSubscription::enumInstances (client, 0, props);

	if (cached) { return createIterator (iter, props); }
	else 		{ return createIterator (iter); }
}

/*
 * Create CIndicationSubscription
 */ 
CIndicationSubscription
CIndicationSubscription::createSubscription(IClient* client, CIndicationFilter filter, CAlertDestination destination)
{
/*
	CCIMObjectPath ObjectPathFilter ("root/interop","http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_IndicationFilter");

	ObjectPathFilter.addKey ("CreationClassName",toCCIMValue<stringDSDKAdapter> ("CIM_IndicationFilter"));
	ObjectPathFilter.addKey ("Name",toCCIMValue<stringDSDKAdapter> (If.getName()));
	ObjectPathFilter.addKey ("SystemCreationClassName",toCCIMValue<stringDSDKAdapter> ("CIM_ComputerSystem"));
	ObjectPathFilter.addKey ("SystemName",toCCIMValue<stringDSDKAdapter> ("localhost.localdomain"));
	ObjectPathFilter.addKey ("__cimnamespace",toCCIMValue<stringDSDKAdapter> ("root/interop"));

	CCIMInstance instanceFilter (ObjectPathFilter);

	CCIMObjectPath ObjectPathListener ("root/interop","http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ListenerDestination");

	ObjectPathListener.addKey ("CreationClassName",toCCIMValue<stringDSDKAdapter> ("DRI_ListenerDestinationWsMan"));
	ObjectPathListener.addKey ("Name",toCCIMValue<stringDSDKAdapter> (ld.getName()));
	ObjectPathListener.addKey ("SystemCreationClassName",toCCIMValue<stringDSDKAdapter> ("CIM_ComputerSystem"));
	ObjectPathListener.addKey ("SystemName",toCCIMValue<stringDSDKAdapter> ("localhost.localdomain"));
	ObjectPathListener.addKey ("__cimnamespace",toCCIMValue<stringDSDKAdapter> ("root/interop"));

	CCIMInstance instanceListener (ObjectPathListener);
*/

	/* create the instance and object path */
	CCIMObjectPath op (client->getInteropNS (),"http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_IndicationSubscription");
	op.addKey ("Filter", toCCIMValue<CCIMObjectPath>(filter.getCIMObject ()->getObjectPath ()));
	op.addKey ("Handler",toCCIMValue<CCIMObjectPath>(destination.getCIMObject ()->getObjectPath ()));
	
	CCIMInstance inst (op);

	CCIMObjectPath subscription_op = client->createInstance(op, inst);
	
	/* create the subscription */
	vector<string> empty;
	CIM_IndicationSubscription<CIM_IndicationFilter, CIM_ListenerDestination>  subscription_inst 
													= client->getInstance (subscription_op, 0, empty);
	subscription_inst.initialize (client);

	return CIndicationSubscription (subscription_inst);
}

/*
 * Create CIndicationSubscription
 */ 
CIndicationSubscription 
CIndicationSubscription::createSubscription (IClient* client,	string querylanguage, 
											 string query,		string destination)
{

	return	createSubscription (client, CIndicationFilter::createFilter (client, querylanguage, query), 
								CAlertDestination::createDestination (client, destination));

}

/*
 * Create CIndicationSubscription
 */ 
string
CIndicationSubscription::createSubscription (IClient* client,	string querylanguage,
											 string query,		string destination,
											 int mode,
											 float	heartbeat_interval,
											 float  expiration_timeout,
											 string	resource_uri)
{

	string  dialect;
	if (querylanguage == "CQL")
	{
		dialect = "http://schemas.dmtf.org/wbem/cql/1/dsp0202.pdf";
	}
	else if (querylanguage == "WQL")
	{
		dialect = "http://schemas.microsoft.com/wbem/wsman/1/WQL";
	}
	else
	{
		dialect = querylanguage;
	}

	CCIMObjectPath op = CCIMObjectPath ("", resource_uri);
	//string uuid = subscribeEvent (client, destination, 
	//										  mode, 
	//										  heartbeat_interval,
	//										  expiration_timeout,
	//										  dialect,
	//										  query,
	//										  resource_uri);
	string uuid = client->subscribeEvent (op, destination, mode, heartbeat_interval, 
								   expiration_timeout, dialect, query);

	return uuid;
}

/*
 * Create CIndicationSubscription
 */ 
string
CIndicationSubscription::createSubscription (IClient* client,	CSubscriptionParams params)
{
	CCIMObjectPath op = CCIMObjectPath ("",params.getResourceURI());
	return client->subscribeToEvent (op, params.getLowerObject());
}





/*
 * Create CIndicationSubscription using CIndication Filter
 */ 
string
CIndicationSubscription::createSubscription (IClient* client,	
											 CIndicationFilter filter,
											 string destination,
											 int mode,
											 float	heartbeat_interval,
											 float  expiration_timeout)
{

	string uuid = client->subscribeEvent (filter.getCIMObject ()->getObjectPath (), destination, 
											  mode, 
											  heartbeat_interval,
											  expiration_timeout,
											  "",
											  "");
	return uuid;
}


/*
 * Create CIndicationSubscription using CIndication Filter
 */ 
string
CIndicationSubscription::createSubscription (IClient* client,	
											 CIndicationFilter filter,
											 CSubscriptionParams params)
{
	return client->subscribeToEvent (filter.getCIMObject ()->getObjectPath (), params.getLowerObject());
}

/*
 * deleteSubscription
 */
void
CIndicationSubscription::deleteSubscription (void) const
{
	_is->getClient ()->deleteInstance (_is->getObjectPath ());
}

/*
 *  getOnFatalErrorPolicy
 */
uint16 
CIndicationSubscription::getOnFatalErrorPolicy (void) const
{
	return _is->getOnFatalErrorPolicy();
}

/*
 * Gets OtherOnFatalErrorPolicy
 */
string 
CIndicationSubscription::getOtherOnFatalErrorPolicy (void) const
{
	return _is->getOtherOnFatalErrorPolicy();
}

/*
 * Gets FailureTriggerTimeInterval
 */
uint64
CIndicationSubscription::getFailureTriggerTimeInterval (void) const
{
	return _is->getFailureTriggerTimeInterval();
}
/*
 * Gets SubscriptionState
 */
uint16 
CIndicationSubscription::getSubscriptionState (void) const
{
	return _is->getSubscriptionState();
}

/*
 * Gets OtherSubscriptionState
 */
string 
CIndicationSubscription::getOtherSubscriptionState (void)  const
{
	return _is->getOtherSubscriptionState();
}

/*
 * Gets RepeatNotificationPolicy
 */
uint16 
CIndicationSubscription::getRepeatNotificationPolicy (void) const
{
	return _is->getRepeatNotificationPolicy();
}

/*
 * Gets RepeatNotificationInterval
 */
uint64 
CIndicationSubscription::getRepeatNotificationInterval (void) const
{
	return _is->getRepeatNotificationInterval();
}

/*
 * Gets RepeatNotificationGap
 */
uint64 
CIndicationSubscription::getRepeatNotificationGap (void)  const
{
	return _is->getRepeatNotificationGap();
}

/*
 * Gets RepeatNotificationCount
 */
uint16 
CIndicationSubscription::getRepeatNotificationCount (void) const
{
	return _is->getRepeatNotificationCount();
}

/*
 * getFilternName
 */
string  
CIndicationSubscription::getFilternName(IClient* client) const
{
	vector<string> empty;
	CCIMObjectPath ObjPath = _is->getFilter();

	// there is a bug in RI, which does not return correct resourse URI, once its fixed remove this line.
	ObjPath.setClassName ("http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_IndicationFilter");
	
	CIM_IndicationFilter  ins = client->getInstance (ObjPath,0,empty);
	ins.initialize (client);
	return ins.getName();
}

/*
 * getFilterQueryLanguage
 */
string  
CIndicationSubscription::getFilterQueryLanguage (IClient* client) const
{
	vector<string> empty;
	CCIMObjectPath ObjPath = _is->getFilter();

	// there is a bug in RI, which does not return correct resourse URI, once its fixed remove this line.
	ObjPath.setClassName ("http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_IndicationFilter");

	CIM_IndicationFilter  ins = client->getInstance(ObjPath, 0, empty);
	ins.initialize (client);
	return ins.getQueryLanguage ();
}


/*
 * getFilterQuery
 */
string  
CIndicationSubscription::getFilterQuery(IClient* client) const
{
	vector<string> empty;
	CCIMObjectPath ObjPath = _is->getFilter();

	// there is a bug in RI, which does not return correct resourse URI, once its fixed remove this line.
	ObjPath.setClassName ("http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_IndicationFilter");

	CIM_IndicationFilter  ins = client->getInstance(ObjPath, 0, empty);
	ins.initialize (client);
	return ins.getQuery();
}

/*
 * getAlertDestination
 */
string 
CIndicationSubscription::getAlertDestination(IClient* client) const
{
	vector<string> empty;
	CCIMObjectPath ObjPath = _is->getHandler();

	// there is a bug in RI, which does not return correct resourse URI, once its fixed remove this line.
	ObjPath.setClassName ("http://schemas.dri.org/wbem/wscim/1/cim-schema/2/DRI_ListenerDestinationWsMan");

	CIM_ListenerDestination  ins = client->getInstance(ObjPath, 0, empty);
	ins.initialize (client);
	return ins.getDestination();
}

/*
 * getCachedProps
 */
vector<string> 
CIndicationSubscription::getCachedProps (void) 
{
	vector<string> props;
	props.push_back ("OnFatalErrorPolicy");
	props.push_back ("OtherOnFatalErrorPolicy");
	props.push_back ("FailureTriggerTimeInterval");
	props.push_back ("OnFatalErrorPolicy");
	props.push_back ("SubscriptionState ");
	props.push_back ("OtherSubscriptionState");
	props.push_back ("RepeatNotificationPolicy");
	props.push_back ("RepeatNotificationInterval");
	props.push_back ("RepeatNotificationGap");
	props.push_back ("RepeatNotificationCount");
	props.push_back ("Filter");
	props.push_back ("Handler");
	return props;
}

/*
 * IndicationSubscription::Iterator
 */
DEFINE_API_ITERATOR (CIndicationSubscription);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CIndicationSubscription, CIMIndicationSubscription);

/**
 * CFilterCollectionSubscription
 **/

/*
 * Constructor
 */
CFilterCollectionSubscription::CFilterCollectionSubscription (const CIM_FilterCollectionSubscription<CIM_FilterCollection, 
													CIM_ListenerDestination>& fcs)
{ 
	_fcs = new CIM_FilterCollectionSubscription<CIM_FilterCollection, CIM_ListenerDestination> (fcs); 
}

/*
 * Constructor
 */
CFilterCollectionSubscription::CFilterCollectionSubscription (const CFilterCollectionSubscription& fcs)
{
	this->_fcs = new CIM_FilterCollectionSubscription<CIM_FilterCollection, CIM_ListenerDestination> (*(fcs._fcs));
}

/*
 * Destruction 
 */
CFilterCollectionSubscription::~CFilterCollectionSubscription ()
{
	if (this->_fcs) { delete this->_fcs; }
}

/*
 * Assignment operator
 */
const CFilterCollectionSubscription& 
CFilterCollectionSubscription::operator = (const CFilterCollectionSubscription& rhs)
{
	if (this->_fcs) { delete this->_fcs; }
	this->_fcs  = new CIM_FilterCollectionSubscription<CIM_FilterCollection, CIM_ListenerDestination> (*rhs._fcs);
	return *this;
}

/*
 * enumerate FilterCollectionSubscription
 */
CFilterCollectionSubscription::iterator 
CFilterCollectionSubscription::enumFilterCollectionSubscription (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_FilterCollectionSubscription<CIM_FilterCollection, CIM_ListenerDestination>::iterator iter = 
			CIMFilterCollectionSubscription::enumInstances (client, 0, props,
															CCIMObjectPath(client->getInteropNS (), "CIM_FilterCollectionSubscription"));

	if (cached) { return createIterator (iter, props); }
	else 		{ return createIterator (iter); }
}

/*
 * Create CIndicationSubscription
 */ 
CFilterCollectionSubscription
CFilterCollectionSubscription::createSubscription(IClient* client, CFilterCollection filter, CAlertDestination destination)
{

	/* create the instance and object path */
	CCIMObjectPath op (client->getInteropNS (),"http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_FilterCollectionSubscription");
	op.addKey ("Filter", toCCIMValue<CCIMObjectPath>(filter.getCIMObject ()->getObjectPath ()));
	op.addKey ("Handler",toCCIMValue<CCIMObjectPath>(destination.getCIMObject ()->getObjectPath ()));
	
	CCIMInstance inst (op);

	CCIMObjectPath subscription_op = client->createInstance(op, inst);
	
	/* create the subscription */
	vector<string> empty;
	CIM_FilterCollectionSubscription<CIM_FilterCollection, CIM_ListenerDestination>  subscription_inst 
													= client->getInstance (subscription_op, 0, empty);
	subscription_inst.initialize (client);

	return CFilterCollectionSubscription (subscription_inst);
}

/*
 * Create CFilterCollectionSubscription using CFilter Collection
 */ 
string
CFilterCollectionSubscription::createSubscription (IClient* client,	CFilterCollection filter,
											 string destination,
											 int	mode,
											 float	heartbeat_interval,
											 float  expiration_timeout)
{

	string uuid = subscribeEvent (client, filter.getCIMObject ()->getObjectPath (), destination, 
											  mode, 
											  heartbeat_interval,
											  expiration_timeout,
											  "",
											  "");
	return uuid;
}


/*
 * Create CFilterCollectionSubscription using CFilter Collection
 */ 
string
CFilterCollectionSubscription::createSubscription (IClient* client,	
												   CFilterCollection filter, 
												   CSubscriptionParams params)
{
	string uuid = client->subscribeToEvent(filter.getCIMObject()->getObjectPath(), params.getLowerObject());
	return uuid;
}



/*
 * deleteSubscription
 */
void
CFilterCollectionSubscription::deleteSubscription (void) const
{
	_fcs->getClient ()->deleteInstance (_fcs->getObjectPath ());
}

/*
 *  getOnFatalErrorPolicy
 */
uint16 
CFilterCollectionSubscription::getOnFatalErrorPolicy (void) const
{
	return _fcs->getOnFatalErrorPolicy();
}

/*
 * Gets OtherOnFatalErrorPolicy
 */
string 
CFilterCollectionSubscription::getOtherOnFatalErrorPolicy (void) const
{
	return _fcs->getOtherOnFatalErrorPolicy();
}

/*
 * Gets FailureTriggerTimeInterval
 */
uint64
CFilterCollectionSubscription::getFailureTriggerTimeInterval (void) const
{
	return _fcs->getFailureTriggerTimeInterval();
}
/*
 * Gets SubscriptionState
 */
uint16 
CFilterCollectionSubscription::getSubscriptionState (void) const
{
	return _fcs->getSubscriptionState();
}

/*
 * Gets OtherSubscriptionState
 */
string 
CFilterCollectionSubscription::getOtherSubscriptionState (void)  const
{
	return _fcs->getOtherSubscriptionState();
}

/*
 * Gets RepeatNotificationPolicy
 */
uint16 
CFilterCollectionSubscription::getRepeatNotificationPolicy (void) const
{
	return _fcs->getRepeatNotificationPolicy();
}

/*
 * Gets RepeatNotificationInterval
 */
uint64 
CFilterCollectionSubscription::getRepeatNotificationInterval (void) const
{
	return _fcs->getRepeatNotificationInterval();
}

/*
 * Gets RepeatNotificationGap
 */
uint64 
CFilterCollectionSubscription::getRepeatNotificationGap (void)  const
{
	return _fcs->getRepeatNotificationGap();
}

/*
 * Gets RepeatNotificationCount
 */
uint16 
CFilterCollectionSubscription::getRepeatNotificationCount (void) const
{
	return _fcs->getRepeatNotificationCount();
}

/*
 * getFilternName
 */
string  
CFilterCollectionSubscription::getFilternName(IClient* client) const
{
	vector<string> empty;
	CCIMObjectPath ObjPath = _fcs->getFilter();

	// there is a bug in RI, which does not return correct resourse URI, once its fixed remove this line.
	//ObjPath.setClassName ("http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_FilterCollection");
	
	CIM_FilterCollection  ins = client->getInstance (ObjPath,0,empty);
	ins.initialize (client);
	return ins.getCollectionName();
}

/*
 * getAlertDestination
 */
string 
CFilterCollectionSubscription::getAlertDestination(IClient* client) const
{
	vector<string> empty;
	CCIMObjectPath ObjPath = _fcs->getHandler();

	// there is a bug in RI, which does not return correct resourse URI, once its fixed remove this line.
	//ObjPath.setClassName ("http://schemas.dri.org/wbem/wscim/1/cim-schema/2/DRI_ListenerDestinationWsMan");

	CIM_ListenerDestination  ins = client->getInstance(ObjPath, 0, empty);
	ins.initialize (client);
	return ins.getDestination();
}

/*
 * getCachedProps
 */
vector<string> 
CFilterCollectionSubscription::getCachedProps (void) 
{
	vector<string> props;
	props.push_back ("OnFatalErrorPolicy");
	props.push_back ("OtherOnFatalErrorPolicy");
	props.push_back ("FailureTriggerTimeInterval");
	props.push_back ("OnFatalErrorPolicy");
	props.push_back ("SubscriptionState");
	props.push_back ("OtherSubscriptionState");
	props.push_back ("RepeatNotificationPolicy");
	props.push_back ("RepeatNotificationInterval");
	props.push_back ("RepeatNotificationGap");
	props.push_back ("RepeatNotificationCount");
	props.push_back ("Filter");
	props.push_back ("Handler");
	return props;
}

/*
 * IndicationSubscription::Iterator
 */
DEFINE_API_ITERATOR (CFilterCollectionSubscription);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CFilterCollectionSubscription, CIMFilterCollectionSubscription);

CSubscriptionParams::CSubscriptionParams(string pNotifyURI, uint16 pDeliveryMode) 
{
	notifyURI = pNotifyURI;
	deliveryMode = pDeliveryMode;

	/* Initialize other optional values */
	encodeType = 0;
}

/**
 * Sets Encode type
 * @param encodeType UTF-8 or UTF-16
 */
void CSubscriptionParams::setEncodeType(uint16 pEncodeType)
{
	encodeType = pEncodeType;
}

/**
 * Sets ExpirationTime of the subscription
 * @param Expiry time in seconds in the format - PT50S.
 */
void CSubscriptionParams::setExpirationTime(string pExpiryTime) {
	expirationTime = pExpiryTime;
}

void CSubscriptionParams::setEndToURI(string pEndToURI) {
	endToURI = pEndToURI;
}

void CSubscriptionParams::setLocale(string pLocale) {
	locale = pLocale;
}


string CSubscriptionParams::getResourceURI() {
	return dynFilterResourceURI;
}

void CSubscriptionParams::enableBookMarks(bool pBookMarks) {
	if(pBookMarks)	{
		bookMarks = "TRUE";
	} else {
		bookMarks.clear();
	}
}

/**
 * Sets Locale of the notification.
 * @param plocale		Specifies the locale type Ex: 'en'
 */
void CSubscriptionParams::setHeartBeatInterval(string interval){
	heartbeatInterval = interval;
}

/**
 * Sets ConnectionRetryCount 
 * @param retryCount 		Specifies the retry count to send a notification.
 */
void CSubscriptionParams::setConnectionRetryCount(int count){
	if(count > 0)	{
		char val[5]="";
		sprintf(val,"%d",count);
		retryCount = val;
	} 
}

/**
 * Sets Dynamic Filter Options
 * @param pFilterResURI		ResourceURI of the indication
 * @param pFilterQuery		Query string based on the QueryType.
 * @param pQueryType		Query type either of CQL or WQL type.
 */
void CSubscriptionParams::setDynamicFilterOptions(string pFilterResURI, 
												  string pFilterQuery, 
												  string pQueryType) {
	dynFilterQueryType = pQueryType;
	dynFilterQuery = pFilterQuery;
	dynFilterResourceURI = pFilterResURI;
}

vector <string> CSubscriptionParams::getLowerObject() 
{

	char val[2];

	subscribeParams.push_back(notifyURI);

	sprintf(val,"%d",deliveryMode);
	subscribeParams.push_back(val);

	if(endToURI.empty())	{
		subscribeParams.push_back("NULL");
	} else {
		subscribeParams.push_back(endToURI);
	}

	if(expirationTime.empty()) {
		subscribeParams.push_back("NULL");
	} else {
		subscribeParams.push_back(expirationTime);
	}

	switch(encodeType) {
		case SUBSCRIBE_ENCODETYPE_UTF8:
			subscribeParams.push_back("UTF-8");
			break;
		case SUBSCRIBE_ENCODETYPE_UTF16:
			subscribeParams.push_back("UTF-16");
			break;
		default:
			subscribeParams.push_back("NULL");
			break;
	}

	if(locale.empty())	{
		subscribeParams.push_back("NULL");
	} else {
		subscribeParams.push_back(locale);
	}

	if(bookMarks.empty())	{
		subscribeParams.push_back("NULL");
	} else {
		subscribeParams.push_back("TRUE");
	}

	if(heartbeatInterval.empty())	{
		subscribeParams.push_back("NULL");
	}	else	{
		subscribeParams.push_back(heartbeatInterval);
	}


	if(retryCount.empty())	{
		subscribeParams.push_back("NULL");
	}	else	{
		subscribeParams.push_back(retryCount);
	}

		
	//sprintf(val,"%d",filterType);
	//subscribeParams.push_back(val);

	if(dynFilterQueryType.empty()) {
		subscribeParams.push_back("NULL");
	} else if (dynFilterQueryType == "CQL")	{
		subscribeParams.push_back("http://schemas.dmtf.org/wbem/cql/1/dsp0202.pdf");
	} else if (dynFilterQueryType == "WQL")	{
		subscribeParams.push_back("http://schemas.microsoft.com/wbem/wsman/1/WQL");
	} else	{
		subscribeParams.push_back(dynFilterQueryType);
	}

	if(dynFilterQuery.empty())	{
		subscribeParams.push_back("NULL");
	} else {
		subscribeParams.push_back(dynFilterQuery);
	}

	if(dynFilterResourceURI.empty()) {
			subscribeParams.push_back("NULL");
	} else {
			subscribeParams.push_back(dynFilterResourceURI);
	}
	
	return subscribeParams;

}