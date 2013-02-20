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
 * virtualmedia.h
 * A class representing virtual media.
 */
#include <dsdk/dsdk_api.h>
#include <dsdk/dsdktypes.h>
#include <dsdk/client.h>
#define TCHAR char //@todo remove this.
#include <dsdk/virtualmedia.h>
#include <vmedia/RedirectableObject.h>
#include <vmedia/vmedia.h>

using namespace dsdk;

CVirtualMedia::CVirtualMedia (const string&		host,
							  int				port,
							  const string&		auth,
							  const string&		user,
							  const string&		password,
							  const string&		name,
							  RedirectionType_E	type,
							  bool				secure,
							  bool				write_support)
{
	_host			  = host;
	_port			  = port;
	_auth			  = auth;
	_user			  = user;
	_password		  = password;
	_name			  = name;
	_is_secure		  = secure;
	_is_write_support = write_support;
	_type			  = type;

	return;
}

int
CVirtualMedia::startRedirection (void)
{

	g_vmedia_verbose_level = g_dsdk_verbose_level;
	g_vmedia_verbose_file  = g_dsdk_verbose_file;

	switch (_type)
	{
		case  IMAGE:
			_redirectable_object = (RedirectableObject*)new RedirectableImage ((char*)_name.c_str (), CD_EXTRACTION_TYPE_UNKNOWN);
			break;

		case DRIVE:
		{
			/* enumerate all the drives */
			RedirectableObject** redirectableObject =  CDExtractionEnumerateDrives();
			if (redirectableObject == NULL) { return -1; }

			/* check for the matching drive */
			int i = 0;
			while (NULL != redirectableObject [i])
			{
				string drive = CDExtractionGetRedirectableObjectNameA (redirectableObject [i]);
				if (strcasecmp(drive.c_str(),_name.c_str()) == 0)
				{
					_redirectable_object = (void*)redirectableObject [i];
					break;
				}
				i++;
			}

			if (NULL == redirectableObject [i]) 
			{
				throw EFunctionReturnedWithFailure ("StartMediaRedirection",
						GetMediaRedirectionErrorStr (E_INVALID_DRIVE), E_INVALID_DRIVE);
			}
		}
		break;

		case FOLDER:
		default:
				throw EFunctionReturnedWithFailure ("StartMediaRedirection",
					"Medirection redirection type not supported", E_CD_UNKNOWN);
	}

	int device = 0;
	if(((RedirectableObject*)_redirectable_object)->GetType () == CD_EXTRACTION_TYPE_CDROM)
	{
		device = 0;
	}
	else
	{
		device = 1;
	}
	
	int status;
	/* start the redirection */
	_hndl = StartMediaRedirection (_host, _port, _auth, _user, _password, 
							(RedirectableObject*)_redirectable_object, 
							_is_secure, _is_write_support, device, &status);

	if ((_hndl == NULL) || (status != 0))
	{
		string retcodestr;
		if (status != 0)
		{
			retcodestr = GetMediaRedirectionErrorStr (status);
		}
		else
		{
			retcodestr = "Unknown Media redirection Error";
		}
		throw EFunctionReturnedWithFailure ("StartMediaRedirection",
											retcodestr, status);

	}
	else
	{
		return 0;
	}
}

/*
 * stops the redirection
 */
int
CVirtualMedia::stopRedirection (void)
{

	StopMediaRedirection (_hndl);

	return 0;
}

/*
 * gets the local drives
 */
vector<string>
CVirtualMedia::getLocalDrives (void)
{
	vector<string> drives;

	RedirectableObject** redirectableObject =  CDExtractionEnumerateDrives();
	if (redirectableObject == NULL)
	{
		return drives;
	}

	int i = 0;
	while (NULL != redirectableObject [i])
	{
		string drive = CDExtractionGetRedirectableObjectNameA (redirectableObject [i]);
		drives.push_back (drive);
		i++;
	}

	CDExtractionReleaseDriveEnumeration (redirectableObject);

	return drives;
}
