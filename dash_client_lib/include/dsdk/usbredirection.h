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
 * usbredirection.h
 * A class representing a usb redirection.
 */
#ifndef __DSDK_USBREDIRECTION_H__
#define __DSDK_USBREDIRECTION_H__
#include <dsdk/dsdk_api.h>
#include <dsdk/dsdktypes.h>
#include <dsdk/cimmap.h>
#include <dsdk/oal/CIM_RemoteServiceAccessPoint.h>

namespace dsdk
{

class CIM_USBRedirectionSAP;
class CIM_USBRedirectionService;
class CUSBRedirection;
typedef CAPIIterator<CUSBRedirection, CIM_USBRedirectionSAP> _CUSBRedirectionIterator;


/**
  * @class CUSBRedirection
  * @brief A class representing a usb redirection
  **/
class DSDK_Export CUSBRedirection
{
public:
	DECLARE_API_ITERATOR (CUSBRedirection);
	typedef CIM_USBRedirectionSAP CIMType;

public:
	/**
	 * Enumerates all the usb redirection service present under a MAP.
	 * @param client	Pointer to the client interface.
	 * @param cached	true  - Enable caching \n
	 *					false - Disable caching.
	 * @return			Iterator to the test redirection.
	 */
	static CUSBRedirection::iterator enumUSBRedirections (IClient* client,
										 				  bool cached = true);

public:
	/**
	 * Return the underlying CIM object
	 */
	CIM_USBRedirectionSAP* getCIMObject (void) const { return _usbr; }

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
	 * Gets the usb redirection name
	 * @return The usbredirection name
	 */
	string getName (void) const;

	/**
	 * Gets CreationClassName
	 * @ return the creationclassname
	 */
	string getCreationClassName (void) const;

	
	/**
	 * Gets ElementName
	 */
	string getElementName (void) const;

	/**
	 * Gets EnabledState
	 * @ return the EnabledState
	 */
	uint16 getEnabledState (void) const;

	/**
	 * Gets EnabledState as string
	 * @ return the EnabledState
	 */
	string getEnabledStateStr (void) const;

	/**
	 * Gets RequestedState
	 * return the requestedstate
	 */
	uint16 getRequestedState (void) const;

	/**
	 * Gets Requested State as string
	 * @ return the Requested State as string
	 */
	string getRequestedStateStr (void) const;

	/**
	 * Gets the connection mode
	 * @return The connection mode
	 */
	string getConnectionMode (void) const;

	/**
	 * Gets ResetTimeout
	 * @ return the resettimeout value
	 */
	datetime getResetTimeout (void) const;

	/**
	 * Gets SessionTimeout
	 * @ return the sessiontimeout value
	 */
	datetime getSessionTimeout (void) const;

	/**
	 * Enable/Activate this redirection session
	 */
	int activate (void) const;

	/** 
	 * Disable this redirection session
	 */
	void disable (void) const;

	/** 
	 * Starts the NFS/Samba share redirection. 
	 */
	int startFolderRedirection (string path, string defaultServer = "false") const;
	
	/** 
	 * Requested State Support 
	 */
	// vector<uint16> enablesupport (void) const;

	/** 
	 * Requested State Support  for CIM_USBRedirectionService
	 */
	// vector<uint16> usbenablesupport (void) const;
	
	/**
	 * Verifies whether RedirectionService is enabled or not.
	 * @param usb		If supported, usb contains the reference of the 
	 *					redirection service instance.
	 * @return	true - if supported
	 *			false - if not supported.
	 */
//	bool capableOfRedirectionService(CIM_USBRedirectionService &usb) const;
	
	/**
	 * Verifies whether RedirectionService is enabled or not.
	 * @return	true - if supported
	 *			false - if not supported.
	 */
//	bool capableOfRedirectionService() const;

	/**
	 * Verifies whether Folder Redirection is supported by the service or not.
	 * @param usb		If supported, rmsrv contains the reference of the 
	 *					service access point using which the folder redirection can be started.
	 * @return	true - if supported
	 *			false - if not supported.
	 */
	bool capableOfFolderRedirection(CIM_RemoteServiceAccessPoint &rmsrv)const;

	/**
	 * Verifies whether Folder Redirection is supported by the service or not.
	 * @return	true - if supported
	 *			false - if not supported.
	 */

	bool capableOfFolderRedirection()const;

	/**
	* Verifies whether the SAPRequestedStatesChange() method is supported or not.
	* First it verifires the existance of the USBtRedirectionService instance and the verifies that
	* the CIM_EnabledLogicalElementCapabilities.RequestedStatesSupported property contains at least one value.
	* @param  USBRS variable
	* @return  true  - if both the instance exists, also returns  TRS instance.
	*          false - if one of the instance, or both instance does not exiest.
	**/
	bool capableOfUSBRSAPRequestStatesChange(CIM_USBRedirectionService &usb)const;

	/**
	* Verifies whether the SAPRequestedStatesChange() method is supported or not.
	* First it verifires the existance of the SAPUSBRedirectionSAP instance and the verifies that
	* the CIM_EnabledLogicalElementCapabilities.RequestedStatesSupported property contains at least one value.
	* @param  USBRS variable
	* @return  true  - if both the instance exists, 
	*          false - if one of the instance, or both instance does not exiest.
	**/
	bool capableOfUSBRSAPRequestStatesChange(void)const;

	/**
	* Verifies whether the RequestedStatesChange() method is supported or not.
	* First it verifires the existance of the USBRedirectionSAP instance and the verifies that
	* the CIM_EnabledLogicalElementCapabilities.RequestedStatesSupported property contains at least one value.
	* @param  USBRS variable
	* @return  true  - if both the instance exists, also returns  TRS instance.
	*          false - if one of the instance, or both instance does not exiest.
	**/
	bool capableOfUSBRServiceRequestStatesChange(CIM_USBRedirectionService &usb)const;

	/**
	* Verifies whether the RequestedStatesChange() method is supported or not.
	* First it verifires the existance of the USBRedirectionService instance and the verifies that
	* the CIM_EnabledLogicalElementCapabilities.RequestedStatesSupported property contains at least one value.
	* @param  USBRS variable
	* @return  true  - if both the instance exists, 
	*          false - if one of the instance, or both instance does not exiest.
	**/
	bool capableOfUSBRServiceRequestStatesChange(void)const;

	/**
	* Verifies whether the perticulsr RequestedStatsChange value is supported or not.
	* @param  USBRS and RequestedState value
	* @return  true  - if RequestedState value supported.
	*          false - if RequestedState value is not supported.
	**/
	bool isSupportedRequestStates (CIM_USBRedirectionService &usb,const uint16)const;

	/**
	* Returns the CIM_EnabledLogicalElementCapabilities.RequestedStatesSupported property values
	* @param  USBRS
	* @return  vector<uint16> array
	**/
	bool getSupportedStates(vector<uint16> &states_val)const;

	/**
	* Returns the CIM_EnabledLogicalElementCapabilities.RequestedStatesSupported property string values
	* @param  USBRS
	* @return  vector<string> array
	**/
	bool getSupportedStatesStr(vector<string> &states_str)const;

public:
	/**
	 * Construct this object from the corresponding CIM_USBRedirectionSAP 
	 * object
	 */
	CUSBRedirection (const CIM_USBRedirectionSAP& usbr); 

	/**
	 * Copy constructor
	 */
	CUSBRedirection (const CUSBRedirection& usbr);

	/**
	 * Destructor
	 */
	~CUSBRedirection ();

	/**
	 * Assignment operator
	 */
	const CUSBRedirection& operator = (const CUSBRedirection& rhs);

	/**
	 * Returns the properties that are cached by this object
	 */
	static vector<string> getCachedProps (void);

private:
	CIM_USBRedirectionSAP*	_usbr;
};

};	/* namespace dsdk */

#endif /*__DSDK_USBREDIRECTION_H__*/
