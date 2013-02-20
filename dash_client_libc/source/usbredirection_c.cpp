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
 * usbredirection_c.cpp
 * C wrapper for usbredirection.
 */
#include <vector>
#include <string>
#include <cstring>
#include <dsdk/oal/COALObject.h>
#include <dsdkc/usbredirection_c.h>
#include <dsdk/usbredirection.h>
#include <dsdkc/error_c.h>


using namespace dsdk;

/*
 * Gets the getSystemCreationClassName
 */
extern "C" void 
usbr_getSystemCreationClassName (DSDKUSBRedirection* usbr, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUSBRedirection* _usbr = (CUSBRedirection*) (usbr->hdl);
		string str = _usbr->getSystemCreationClassName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * Gets the getSystemName
 */
extern "C" void 
usbr_getSystemName (DSDKUSBRedirection* usbr, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUSBRedirection* _usbr = (CUSBRedirection*) (usbr->hdl);
		string str = _usbr->getSystemName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * Gets the usb redirection name
 */
extern "C" void 
usbr_getName (DSDKUSBRedirection* usbr, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUSBRedirection* _usbr = (CUSBRedirection*) (usbr->hdl);
		string str = _usbr->getName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * Gets the getCreationClassName
 */
extern "C" void 
usbr_getCreationClassName(DSDKUSBRedirection* usbr, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUSBRedirection* _usbr = (CUSBRedirection*) (usbr->hdl);
		string str = _usbr->getCreationClassName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}
/*
 * Gets the getElementName
 */
extern "C" void 
usbr_getElementName (DSDKUSBRedirection* usbr, char* name, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUSBRedirection* _usbr = (CUSBRedirection*) (usbr->hdl);
		string str = _usbr->getElementName ();
		::snprintf(name,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * startFolderRedirection
 */
extern "C" int 
usbr_startFolderRedirection (DSDKUSBRedirection* usbr, char* path)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUSBRedirection* _usbr = (CUSBRedirection*) (usbr->hdl);
		return (int)_usbr->startFolderRedirection (string(path));
	}
	CATCH_SET_ERROR ();

	return 0;

}

/*
 * getEnabledState
 */
extern "C" uint16 
usbr_getEnabledState (DSDKUSBRedirection* tr)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUSBRedirection* _usbrr = (CUSBRedirection*) (tr->hdl);
		return _usbrr->getEnabledState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getEnabledStateStr
 */
extern "C" void 
usbr_getEnabledStateStr (DSDKUSBRedirection* tr, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUSBRedirection* _usbrr = (CUSBRedirection*) (tr->hdl);
		string str = _usbrr->getEnabledStateStr ();
		::snprintf(state,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * getRequestedState
 */
extern "C" uint16 
usbr_getRequestedState (DSDKUSBRedirection* tr)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUSBRedirection* _usbrr = (CUSBRedirection*) (tr->hdl);
		return _usbrr->getRequestedState ();
	}
	CATCH_SET_ERROR ();
	return 0;
}

/*
 * getRequestedStateStr
 */
extern "C" void 
usbr_getRequestedStateStr (DSDKUSBRedirection* tr, char* state, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUSBRedirection* _usbrr = (CUSBRedirection*) (tr->hdl);
		string str = _usbrr->getRequestedStateStr ();
		::snprintf(state,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * Gets the Usb redirection ConnectionMode
 */
extern "C" void 
usbr_getConnectionMode (DSDKUSBRedirection* usbr, char* cmode, int max_len)
{
	dsdkc_setError (0, NULL);
	try 
	{
		CUSBRedirection* _usbr = (CUSBRedirection*) (usbr->hdl);
		string str = _usbr->getConnectionMode ();
		::snprintf(cmode,   max_len, "%s",str.c_str ());
	}
	CATCH_SET_ERROR ();

	return;
}


/*
 * Enable/Activate this redirection session
 */
extern "C" void 
usbr_activate (DSDKUSBRedirection* usbr)
{
	dsdkc_setError (0, NULL);
	try
	{
		CUSBRedirection* _usbr = (CUSBRedirection*) (usbr->hdl);
		_usbr->activate ();
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * Enable this redirection session.
 */
/*extern "C" void 
usbr_enable (DSDKUSBRedirection* usbr)
{
	dsdkc_setError (0, NULL);
	try
	{
		CUSBRedirection* _usbr = (CUSBRedirection*) (usbr->hdl);
		_usbr->enable ();
	}
	CATCH_SET_ERROR ();
	return;
}*/

/* 
 * Disable this redirection session
 */
extern "C" void 
usbr_disable (DSDKUSBRedirection* usbr)
{
	dsdkc_setError (0, NULL);
	try
	{
		CUSBRedirection* _usbr = (CUSBRedirection*) (usbr->hdl);
		_usbr->disable ();
	}
	CATCH_SET_ERROR ();
	return;
}

/*
 * release
 */
extern "C" void 
usbr_release (DSDKUSBRedirection* usbr)
{
	dsdkc_setError (0, NULL);
	CUSBRedirection* _usbr = (CUSBRedirection*) (usbr->hdl);
	delete _usbr;
	delete usbr;
}

static DSDKUSBRedirectionFT _usbrft = 
{
	usbr_getSystemCreationClassName,
	usbr_getSystemName,
	usbr_getName,
	usbr_getCreationClassName,
	usbr_getElementName,
	usbr_getEnabledState,
	usbr_getEnabledStateStr,
	usbr_getRequestedState,
	usbr_getRequestedStateStr,
	usbr_getConnectionMode,
	usbr_activate,
	usbr_disable,
	usbr_release,
	usbr_startFolderRedirection,
};


/*
 * Make a C based Usb Redirection from the corresponding C++ object.
 */
static DSDKUSBRedirection* 
makeDSDKUSBRedirection (const CUSBRedirection& usbr)
{
	DSDKUSBRedirection* dsdk_usbr = new DSDKUSBRedirection;
	if (NULL == dsdk_usbr) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_usbr->ft		= &_usbrft;
		dsdk_usbr->hdl	= new CUSBRedirection (usbr);
		return dsdk_usbr;
	}
	CATCH_SET_ERROR ();

	delete dsdk_usbr;
	return NULL;

}

/*
 * getItem
 */
extern "C" DSDKUSBRedirection* 
usbri_getItem (DSDKUSBRedirectionIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CUSBRedirection::iterator* _iter = (CUSBRedirection::iterator*) (di->hdl);
		if (*_iter == CUSBRedirection::iterator::end ()) { return NULL; }
		return makeDSDKUSBRedirection (*(*_iter));
	}
	CATCH_SET_ERROR ();
	return NULL;
}



/*
 * next
 */
extern "C" void 
usbri_next (DSDKUSBRedirectionIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CUSBRedirection::iterator* _iter = (CUSBRedirection::iterator*) (di->hdl);
		++(*_iter);
	}
	CATCH_SET_ERROR ();
}


/*
 * isEnd
 */
extern "C" BOOL 
usbri_isEnd (DSDKUSBRedirectionIterator* di)
{
	dsdkc_setError (0, NULL);
	try
	{
		CUSBRedirection::iterator* _iter = (CUSBRedirection::iterator*) (di->hdl);
		return (*_iter == CUSBRedirection::iterator::end ());
	}
	CATCH_SET_ERROR ();
	return 1;
}


/*
 * release
 */
extern "C" void 
usbri_release (DSDKUSBRedirectionIterator* di)
{
	dsdkc_setError (0, NULL);
	CUSBRedirection::iterator* _iter = (CUSBRedirection::iterator*) (di->hdl);
	delete _iter;
	delete di;
}

static DSDKUSBRedirectionIteratorFT _usbrift = 
{
	usbri_getItem,
	usbri_next,
	usbri_isEnd,
	usbri_release
};

/*
 * Make a C based Usb Redirection iterator from the corresponding C++ object.
 */
static DSDKUSBRedirectionIterator* 
makeDSDKUSBRedirectionIterator (const CUSBRedirection::iterator& usbri)
{

	DSDKUSBRedirectionIterator* dsdk_usbri = new DSDKUSBRedirectionIterator;
	if (NULL == dsdk_usbri) { return NULL; }

	dsdkc_setError (0, NULL);
	try
	{
		dsdk_usbri->ft  = &_usbrift;
		dsdk_usbri->hdl = new CUSBRedirection::iterator (usbri);
		return dsdk_usbri;
	}
	CATCH_SET_ERROR ();

	delete dsdk_usbri;
	return NULL;
}

/*
 * enumUsbredirection
 */
extern "C" DSDKUSBRedirectionIterator*
enumUSBRedirection (DSDKClient* client, BOOL cached)
{
	dsdkc_setError (0, NULL);
	try
	{
		CUSBRedirection::iterator iter = CUSBRedirection::enumUSBRedirections (
													(IClient*) client, 
													(cached ? true : false));

		return makeDSDKUSBRedirectionIterator (iter);
	}
	CATCH_SET_ERROR ();
	return NULL;
}




