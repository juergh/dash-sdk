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
 * subject_c.cpp
 * A class representing a subject.
 */
#include <cstring>
#include <dsdkc/subject_c.h>
#include <dsdk/subject.h>
#include <dsdkc/error_c.h>
#include <dsdk/dsdkexception.h>

using namespace dsdk;

/*
 * getUser
 */
extern "C" void 
sb_getUser (DSDKSubject* sub, char* user, int max_len)
{

	CSubject* _sub = (CSubject*) (sub->hdl);
	try 
	{
		string str = _sub->getUser ();
		::snprintf(user,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
}


/*
 * getPassword
 */
extern "C" void 
sb_getPassword (DSDKSubject* sub, char* password, int max_len)
{
	CSubject* _sub = (CSubject*) (sub->hdl);
	try 
	{
		_sub->getPassword (max_len, password);
	} 
	CATCH_SET_ERROR ();
}


/*
 * getAuth
 */
extern "C" void 
sb_getAuth (DSDKSubject* sub, char* auth, int max_len)
{
	CSubject* _sub = (CSubject*) (sub->hdl);
	try 
	{
		string str = _sub->getAuth ();
		::snprintf(auth,   max_len, "%s",str.c_str ());
	} 
	CATCH_SET_ERROR ();
}


/*
 * getVerifyPeer
 */
extern "C" int  
sb_getVerifyPeer (DSDKSubject* sub)
{
	CSubject* _sub = (CSubject*) (sub->hdl);
	try 
	{
		return _sub->getVerifyPeer (); 
	} 
	CATCH_SET_ERROR ();
	return -1;
}


/*
 * getVerifyHost
 */
extern "C" int  
sb_getVerifyHost (DSDKSubject* sub)
{
	CSubject* _sub = (CSubject*) (sub->hdl);
	try 
	{
		return _sub->getVerifyHost (); 
	} 
	CATCH_SET_ERROR ();
	return -1;
}


/*
 * getCaInfo
 */
extern "C" void 
sb_getCaInfo (DSDKSubject* sub, char* ca_info, int max_len)
{
	CSubject* _sub = (CSubject*) (sub->hdl);
	try 
	{
		string str = _sub->getCaInfo (); 
		::snprintf(ca_info,   max_len, "%s",str.c_str ());
		return;
	} 
	CATCH_SET_ERROR ();
}


/*
 * getCaPath
 */
extern "C" void 
sb_getCaPath (DSDKSubject* sub, char* ca_path, int max_len)
{
	CSubject* _sub = (CSubject*) (sub->hdl);
	try 
	{
		string str = _sub->getCaPath (); 
		::snprintf(ca_path,   max_len, "%s",str.c_str ());
		return;
	} 
	CATCH_SET_ERROR ();
}


/*
 * getCertFile
 */
extern "C" void 
sb_getCertFile (DSDKSubject* sub, char* cert_file, int max_len)
{
	CSubject* _sub = (CSubject*) (sub->hdl);
	try 
	{
		string str = _sub->getCertFile (); 
		::snprintf(cert_file,   max_len, "%s",str.c_str ());
		return;
	} 
	CATCH_SET_ERROR ();
}


/*
 * getKeyFile
 */
extern "C" void 
sb_getKeyFile (DSDKSubject* sub, char* key_file, int max_len)
{
	CSubject* _sub = (CSubject*) (sub->hdl);
	try 
	{
		string str = _sub->getKeyFile (); 
		::snprintf(key_file,   max_len, "%s",str.c_str ());
		return;
	} 
	CATCH_SET_ERROR ();
}


/*
 * getProxy
 */
extern "C" void 
sb_getProxy (DSDKSubject* sub, char* proxy, int max_len)
{
	CSubject* _sub = (CSubject*) (sub->hdl);
	try 
	{
		string str = _sub->getProxy (); 
		::snprintf(proxy,   max_len, "%s",str.c_str ());
		return;
	} 
	CATCH_SET_ERROR ();
}


/*
 * getProxyUser
 */
extern "C" void 
sb_getProxyUser (DSDKSubject* sub, char* proxy_user, int max_len)
{
	CSubject* _sub = (CSubject*) (sub->hdl);
	try 
	{
		string str = _sub->getCaPath (); 
		::snprintf(proxy_user,   max_len, "%s",str.c_str ());
		return;
	} 
	CATCH_SET_ERROR ();
}


/*
 * getProxyPassword
 */
extern "C" void 
sb_getProxyPassword (DSDKSubject* sub, char* password, int max_len)
{
	CSubject* _sub = (CSubject*) (sub->hdl);
	try 
	{
		_sub->getProxyPassword (max_len, password); 
		return;
	} 
	CATCH_SET_ERROR ();
}


/*
 * getTimeout
 */
extern "C" int  
sb_getTimeout (DSDKSubject* sub)
{
	CSubject* _sub = (CSubject*) (sub->hdl);
	try 
	{	
		return _sub->getTimeout (); 
	} 
	CATCH_SET_ERROR ();
	return -1;
}


/*
 * release
 */
extern "C" void 
sb_release (DSDKSubject* sub)
{
	dsdkc_setError (0, NULL);
	CSubject* _sub = (CSubject*) (sub->hdl);
	delete _sub;
	delete sub;
}


static _DSDKSubjectFT ft = 
{
	sb_getUser,
	sb_getPassword,
	sb_getAuth,
	sb_getVerifyPeer,
	sb_getVerifyHost,
	sb_getCaInfo,
	sb_getCaPath,
	sb_getCertFile,
	sb_getKeyFile,
	sb_getProxy,
	sb_getProxyUser,
	sb_getProxyPassword,
	sb_getTimeout,
	sb_release,
};


/*
 * makeSubject
 */
extern "C" DSDKSubject* 
makeSubject (const char*	user, 
			const char*		password,  
			const char*		auth,
			const char*		http_scheme,
			int 			verify_peer, 
			int				verify_host,
			const char*		ca_info,
			const char*		ca_path,
			const char*		cert_file,
			const char*		key_file,
			const char*		proxy,
			const char*		proxy_user,
			const char*		proxy_password,
			unsigned long	timeout)
{
	DSDKSubject* sub = 0;
	try
	{
		sub 	 = new DSDKSubject;
		sub->hdl = new CSubject ((0 == user) ? "" : user, 
								 (0 == password) ? "" : password, 
								 (0 == auth) ? "" : auth, 
								 (0 == http_scheme) ? "" : http_scheme,
								 verify_peer, 
								 verify_host,
								 (0 == ca_info) ? "" : ca_info,
								 (0 == ca_path) ? "" : ca_path,
								 (0 == cert_file) ? "" : cert_file,
								 (0 == key_file) ? "" : key_file,
								 (0 == proxy) ? "" : proxy,
								 (0 == proxy_user) ? "" : proxy_user,
								 (0 == proxy_password) ? "" : proxy_password,
								 timeout);
		sub->ft    = &ft;
	}
	catch (...)
	{
		if (0 != sub) { delete sub; }
		return 0;
	}

	return sub;
}


