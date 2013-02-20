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
 * discoverer_c.cpp
 * CIMMAP discoverer.
 */
#include <dsdkc/discoverer_c.h>
#include <dsdk/discoverer.h>
#include <dsdk/cimmap.h>
#include <dsdkc/error_c.h>

using namespace dsdk;

/*
 * discoverMAPs
 */
void discoverMAPs (char* start_ip, char* end_ip,
				   char*   username,
				   char*   password,
				   char*   auth,
				   PortScheme_T* port_schemes, 
				   int			 num_port_schemes, 
				   u32			 timeout, 
				   int			 max_maps,
				   DSDKCIMMAP*	 cimmap[], 
				   int*			 num_maps)
{

	dsdkc_setError (0, NULL);
	try
	{
		vector < pair <string, string> > v_port_scheme;

		if (NULL != port_schemes)
		{
			for (int i = 0; i < num_port_schemes;i++)
			{
				pair <string, string> port_scheme;
				port_scheme.first  = (NULL == port_schemes->port) ? "" : port_schemes->port;
				port_scheme.second = (NULL == port_schemes->http_scheme) ? "" : port_schemes->http_scheme;
				v_port_scheme.push_back(port_scheme);
				port_schemes++;
			}
		}

		vector<CCIMMAP>	_cimmap;
		if((username == NULL) && (password  == NULL))
		{
			_cimmap = CDiscoverer::discoverMAPs (start_ip,
												(NULL == end_ip) ? "" : end_ip,
												 v_port_scheme,
											     timeout);
		}
		else
		{
			_cimmap = CDiscoverer::discoverMAPs (start_ip,
												(NULL == end_ip) ? "" : end_ip,
												(username == NULL) ? "" : username,
												(password  == NULL) ? "" : password,
												(auth  == NULL) ? "digest" : auth,
												 v_port_scheme,
												 timeout);
		}
		for (size_t i = 0; ((i < _cimmap.size ()) && (i < (size_t)max_maps)); i++)
		{
			cimmap [i] = makeCIMMAP (_cimmap [i].getHostName ().c_str (), 
									 _cimmap [i].getPort ().c_str ());
		}

		*num_maps = (int)_cimmap.size ();
	}
	CATCH_SET_ERROR ();

	return;
}

/*
 * discoverMap
 */
void 
discoverMAP (char* host_name, char* username,
			 char* password, char* auth,char* port,
			 char* http_scheme, uint32 timeout,
			 int max_maps,		DSDKCIMMAP* cimmap [], 
			 int* num_maps)
{

	dsdkc_setError (0, NULL);
	try
	{
		vector<CCIMMAP>	_cimmap;
		if((username == NULL) && (password  == NULL))
		{
			_cimmap = CDiscoverer::discoverMAP (host_name, 
											   (NULL == port) ? "" : port, 
											   (NULL == http_scheme) ? "" : http_scheme, 
												timeout);
		}else
		{
			_cimmap = CDiscoverer::discoverMAP (host_name, 
											   (username == NULL) ? "" : username,
											   (password  == NULL) ? "" : password,
											   (auth  == NULL) ? "digest" : auth,
											   (NULL == port) ? "" : port, 
											   (NULL == http_scheme) ? "" : http_scheme, 
												timeout);
		}

		
		for (size_t i = 0; ((i < _cimmap.size ()) && (i < (size_t)max_maps)); i++)
		{
			cimmap [i] = makeCIMMAP (_cimmap [i].getHostName ().c_str (), 
									 _cimmap [i].getPort ().c_str ());
		}
	}
	CATCH_SET_ERROR ();

}
