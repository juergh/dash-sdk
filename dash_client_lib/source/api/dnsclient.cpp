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
 * dnsclient.cpp
 * A class representing a DNS Client.
 */
#include <dsdk/oal/CIM_DNSProtocolEndpoint.h>
#include <dsdk/dnsclient.h>
#include <dsdk/dsdkexception.h>
#include "apiimp.h"

using namespace dsdk;

/*
 * Constructor
 */
CDNSClient::CDNSClient (const CIM_DNSProtocolEndpoint& dns)
{ 
	_dns = new CIM_DNSProtocolEndpoint (dns); 
}

/*
 * Constructor
 */
CDNSClient::CDNSClient (const CDNSClient& dns)
{
	this->_dns = new CIM_DNSProtocolEndpoint (*(dns._dns));
}

/*
 * Destruction 
 */
CDNSClient::~CDNSClient ()
{
	if (this->_dns) { delete this->_dns; }
}

/*
 * Assignment operator
 */
const CDNSClient& 
CDNSClient::operator = (const CDNSClient& rhs)
{
	if (this->_dns) { delete this->_dns; }
	this->_dns  = new CIM_DNSProtocolEndpoint (*rhs._dns);
	return *this;
}

/*
 * enumerateDNSProtocolEndpoint
 */
CDNSClient::iterator 
CDNSClient::enumDNSClients (IClient* client, bool cached)
{
	vector<string> props = getCachedProps ();

	CIM_DNSProtocolEndpoint::iterator iter = 
		CIM_DNSProtocolEndpoint::enumInstances (client, 0, props);

	if (cached) { return createIterator (iter, props);  	  }
	else 		{ return createIterator (iter); }
}

/*
 * getSystemCreationClassName
 */
string 
CDNSClient::getSystemCreationClassName (void) const
{
	return _dns->getSystemCreationClassName ();
}

/*
 * getCreationClassName
 */
string 
CDNSClient::getCreationClassName (void) const
{
	return _dns->getCreationClassName ();
}

/*
 * getSystemName
 */
string 
CDNSClient::getSystemName (void) const
{
	return _dns->getSystemName ();
}

/*
 * getName
 */
string
CDNSClient::getName (void) const
{
	return _dns->getName ();
}

/*
 * getNameFormat
 */
string
CDNSClient::getNameFormat (void) const
{
	return _dns->getNameFormat ();
}

/*
 * Gets Hostname
 */
string 
CDNSClient::getHostname (void) const
{
	return _dns->getHostname();
}

/*
 * getProtocolIFType
 */
uint16 
CDNSClient::getProtocolIFType (void) const
{
	return _dns->getProtocolIFType ();
}

/*
 * getProtocolIFTypeStr
 */
string
CDNSClient::getProtocolIFTypeStr (void) const
{
	return CIM_DNSProtocolEndpoint::getValueStr_ProtocolIFType (_dns->getProtocolIFType ());
}

/*
 * getRequestedState
 */
uint16
CDNSClient::getRequestedState (void) const
{
	return _dns->getRequestedState ();
}

/*
 * getRequestedStateStr
 */
string
CDNSClient::getRequestedStateStr (void) const
{
	return CIM_DNSProtocolEndpoint::getValueStr_RequestedState (_dns->getRequestedState ());
}

/*
 * getEnabledState
 */
uint16 
CDNSClient::getEnabledState (void) const
{
	return _dns->getEnabledState ();
}

/*
 * getEnabledStateStr
 */
string
CDNSClient::getEnabledStateStr (void) const
{
	return CIM_DNSProtocolEndpoint::getValueStr_EnabledState (_dns->getEnabledState ());
}

/*
 * getElementName
 */
string 
CDNSClient::getElementName (void) const
{
	return _dns->getElementName ();
}

/*
 * Gets AppendPrimarySuffixes
 */
boolean 
CDNSClient::appendPrimarySuffixes (void) const
{
	return _dns->getAppendPrimarySuffixes();
}

/*
 * Gets AppendParentSuffixes
 */
boolean 
CDNSClient::appendParentSuffixes (void) const
{
	return _dns->getAppendParentSuffixes();
}

/*
 * Gets DNSSuffixesToAppend
 */
vector<string> 
CDNSClient::getDNSSuffixesToAppend (void) const
{
	return _dns->getDNSSuffixesToAppend();
}

/*
 * Gets DomainName
 */
string
CDNSClient::getDomainName (void) const
{
	return _dns->getDomainName();
}

/*
 * Gets UseSuffixWhenRegistering
 */
boolean 
CDNSClient::useSuffixWhenRegistering (void) const
{
	return _dns->getUseSuffixWhenRegistering();
}

/*
 * Gets RegisterThisConnectionsAddress
 */
boolean 
CDNSClient::registerThisConnectionsAddress (void) const
{
	return _dns->getRegisterThisConnectionsAddress();
}

/*
 * Gets DHCPOptionsToUse
 */
vector<uint16> 
CDNSClient::getDHCPOptionsToUse (void) const
{
	vector<uint16> dhcpoptionstouse = _dns->getDHCPOptionsToUse() ;
	return dhcpoptionstouse;
}
/*
 * getCachedProps
 */
vector<string> 
CDNSClient::getCachedProps (void) 
{
	vector<string> props;

	props.push_back ("SystemCreationClassName");
	props.push_back ("CreationClassName");
	props.push_back ("SystemName");
	props.push_back ("Name");
	props.push_back ("NameFormat");
	props.push_back ("Hostname");
	props.push_back ("ProtocolIFType");
	props.push_back ("RequestedState");
	props.push_back ("EnabledState");
	props.push_back ("ElementName");
	props.push_back ("AppendPrimarySuffixes");
	props.push_back ("AppendParentSuffixes");
	props.push_back ("DNSSuffixesToAppend");
	props.push_back ("DomainName");
	props.push_back ("UseSuffixWhenRegistering");
	props.push_back ("RegisterThisConnectionsAddress");
	props.push_back ("DHCPOptionsToUse");
	return props;
}

/*
 * DNSClient::Iterator
 */
DEFINE_API_ITERATOR (CDNSClient);
 
/*
 * createIterator 
 */
DEFINE_CREATE_API_ITERATOR (CDNSClient, CIM_DNSProtocolEndpoint);





