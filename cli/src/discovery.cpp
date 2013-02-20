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
 * discovery.cpp
 */
#include "discovery.h"
#include <dsdk/discoverer.h>

using namespace dsdk;

namespace dashcli
{

int
doDiscovery (CCmdOption options, vector<string> commands)
{

	vector < pair <string, string> > v_port_scheme;
	pair <string, string> port_scheme;


	if (options._ports.size() == 0 && options._schemes.size() == 0)	
	{
		port_scheme.first = "623";
		port_scheme.second = "http";
		v_port_scheme.push_back(port_scheme);
	}

	else if (options._ports.size() == 0 && options._schemes.size() !=0)
	{
		for (size_t j = 0; j < options._schemes.size(); j++)
		{
			port_scheme.second = options._schemes[j];
			port_scheme.first = "623";
			v_port_scheme.push_back(port_scheme);
		}
	}

	else if (options._schemes.size() == 0 && options._ports.size() !=0)
	{
		for (size_t j = 0; j < options._ports.size(); j++)
		{
			port_scheme.second = "";
			port_scheme.first = options._ports[j];
			v_port_scheme.push_back(port_scheme);
		}
	}


	else
	{
		for (size_t i = 0; i < options._schemes.size(); i++)
		{
			for (size_t j = 0; j < options._ports.size(); j++)
			{
				port_scheme.first = options._ports[j];
				port_scheme.second = options._schemes[i];
				v_port_scheme.push_back(port_scheme);
			}
		}
	}

	try
	{
		vector<CCIMMAP> cimmap;
		if (options._user_specified && options._password_specified)
		{
			if(options._host_specified)
				cimmap = CDiscoverer::discoverMAP (	options._host, 
													options._user,
													options._password,
													options._authtype,
													options._port,
													options._scheme,
													options._timeout
												  );
			else
				cimmap = CDiscoverer::discoverMAPs(	options._start_ip,
													options._end_ip,
													options._user,
													options._password,
													options._authtype,
													v_port_scheme,
													options._timeout
												  );
		}
		else 
		{
			if(options._host_specified)
				cimmap = CDiscoverer::discoverMAP (	options._host,
													options._port,
													options._scheme,
													options._timeout
												  );
			else
				cimmap = CDiscoverer::discoverMAPs(	options._start_ip,
													options._end_ip,
													v_port_scheme,
													options._timeout
												  );
		}			
		if(cimmap.size ()== 0)
		{
			fprintf (stdout, "\nDash target not Discovered");
		}
		else
		{
			for (size_t i = 0; i < cimmap.size (); i++)
			{
				fprintf (stdout, "\nDiscovered:\n");
				fprintf (stdout, "\t%s:%s", cimmap [i].getHostName ().c_str (),
				cimmap [i].getPort ().c_str ());
				if ((commands.size () == 2) && (commands [1] == "info"))
				{
					fprintf (stdout, "\n\t\tDASHVersion        : %s",cimmap[i].getDASHVersion().c_str());
					fprintf (stdout, "\n\t\tProductVendor      : %s",cimmap[i].getProductVendor().c_str());
					fprintf (stdout, "\n\t\tProductVersion     : %s",cimmap[i].getProductVersion().c_str());
					fprintf (stdout, "\n\t\tProtocolVersion    : %s",cimmap[i].getProtocolVersion().c_str());
					fprintf (stdout, "\n\t\tSecurityProfile(s) : \n");
					for (size_t j = 0; j < cimmap[i].getSecurityProfileName ().size (); j++)
					{
						fprintf (stdout, "\t\t                     %s\n", cimmap[i].getSecurityProfileName () [j].c_str ());
					}
				}
			}
		}
	}
	
	catch (exception& e)
	{
		fprintf (stderr, "Error: %s", e.what ());
	}

	return 0;
}

};	/* namespace dashcli */







