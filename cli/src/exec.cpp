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
 * exec.cpp
 */
#define INIT_URI
#include "exec.h"
#include <algorithm>
#include <dsdk/computersystem.h>
#include <dsdk/processor.h>
#include <dsdk/memory.h>
#include <dsdk/sensor.h>
#include <dsdk/enumerator.h>
#include <dsdk/fan.h>
#include <dsdk/powersupply.h>
#include <dsdk/software.h>
#include <dsdk/biosmanagement.h>
#include <dsdk/opaquemanagementdata.h>
#include <dsdk/battery.h>
#include <dsdk/networkport.h>
#include <dsdk/dhcpclient.h>
#include <dsdk/ipinterface.h>
#include <dsdk/dnsclient.h>
#include <dsdk/indications.h>
#include <dsdk/bootconfig.h>
#include <dsdk/user.h>
#include <dsdk/privilege.h>
#include <dsdk/operatingsystem.h>
#include "targetpath.h"
#include <dsdk/subject.h>
#include <dsdk/cimmap.h>
#include "help.h"
#include "exec.h"
#include "discovery.h"
#include "indication.h"
#include "eventviewer.h"
#include <dsdk/eventsubscribe.h>
#include <dsdk/textredirection.h>
#include <dsdk/usbredirection.h>
#include <dsdk/registeredprofile.h>
#include <dsdk/ethernetport.h>
#include "raw.h"
#include "dashcli.h"
#include <dsdk/oal/CIM_Battery.h>
#include <dsdk/oal/CIM_ProtocolEndpoint.h>
#include <dsdk/oal/CIM_TCPProtocolEndpoint.h>
#include <dsdk/oal/CIM_TextRedirectionService.h>
#include <dsdk/oal/CIM_USBRedirectionService.h>
#include <dsdk/oal/CIM_BIOSServiceCapabilities.h>
#include <dsdk/cimcapabilities.h>

#ifdef WIN32
#include <winsock.h>
#else
#include <unistd.h>
#define SOCKET_ERROR -1
#endif
#ifdef _WIN32
#pragma warning (disable:4702)
#pragma warning (disable:4706)
#endif
using namespace dsdk;
long val;
int  error;

namespace dashcli
{
/**
 * Checks for the matching target and executes in the appropriate executer
 */
#define CHECK_EXEC_CMD(str, get_fn, get_type, exec_class)                 \
if (type == str)                                                          \
{                                                                         \
	try {                                                                 \
		vector<get_type> obj = get_fn (client, ins_num);                  \
																		  \
		if (obj.size () == 0)                                             \
		{                                                                 \
			fprintf (stderr,                                              \
					 "Error: No matching instance found in '%s'",         \
					 target.c_str ());                                    \
			return -1;                                                    \
		}                                                                 \
																		  \
		for (size_t i = 0; i < obj.size (); i++)                          \
		{                                                                 \
			exec_class ec (obj [i]);                                      \
			return ec.execute (client, options, commands, target_ix + 1); \
		}                                                                 \
	}                                                                     \
	catch (ECIMError& e)                                                  \
	{                                                                     \
		fprintf (stderr,                                                  \
					 "Error: No matching instance found in '%s'",         \
					 target.c_str ());                                    \
		if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }    \
		return -1;                                                        \
	}                                                                     \
}

/**
 * Returns the items corresponding to the instance number 
 */
template<class T_Item>
vector<T_Item>
getInstance (typename T_Item::iterator iter, int ins_num)
{
	bool get_all = false;
	if (ins_num == TARGET_ALL_INSTANCE) { get_all = true; }

	vector<T_Item>  ret;
	int ix = 0;     
	for (; iter != T_Item::iterator::end (); ++iter)
	{
		if ((ix == ins_num) || get_all)
		{
			try {
				ret.push_back (*iter);
			}
			catch (ECIMError& e)
			{
				fprintf (stderr, "Error getting instance %d", ix); 
				if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			}
			if (!get_all) { break; }
		}
		ix++;
	}

	return ret;
}


/**
 * @class IExec
 * @brief An executer interface.
 */
class IExec 
{
public:
	virtual int execute (void) = 0;

	virtual~ IExec () {}
};

#define CHECK_INVOKE_ENUM(CMD, OBJECT)                      \
if (commands [1] == CMD)                                    \
{                                                           \
	return this->enumerate##OBJECT (client, options,        \
									commands, target_ix);   \
}

/**
 * Display Vector String
 * @brief A generel function to display vector string values
 */
int
displayVectorStr (string disp_str, vector<string> str_values, int num_words_per_line)
{
	fprintf (stdout, "%s", disp_str.c_str());
	for (size_t i = 0; i < str_values.size (); i++)
	{
		fprintf (stdout, "%s", str_values [i].c_str ());

			if (i != (str_values.size () - 1)) { fprintf (stdout, ", "); }
	}
	return 0;
}

/**
 * Display Vector integer
 * @brief A generel function to display vector integer values
 */
int
displayVectorInt (string disp_str, vector<uint16> int_values, int num_values_per_line)
{
	fprintf (stdout, "%s", disp_str.c_str());
	int num_spaces = strlen (disp_str.c_str ());

	for (size_t i = 0; i < int_values.size (); i++)
	{
		fprintf (stdout, "%d", int_values [i]);

		if (i != (int_values.size () - 1)) { fprintf (stdout, ", "); }
		if (((i + 1) % num_values_per_line) == 0)
		{
			if ((i+1) != int_values.size ())
			{
				fprintf (stdout, "\n");
				fprintf (stdout, "%*s", num_spaces, " ");
			}
		}
	}
	return 0;
}

/**
 * @class CRootExec
 * @brief A executer at the root of a target path.
 */
class CRootExec 
{
public:
	/**
	 * Constructor
	 */
	CRootExec () { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
						 const CCmdOption&  options, 
						 vector<string>     commands,
						 size_t             target_ix);

private:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{
		if (commands.size () == 0)  { return this->show (client);}
		if (commands [0] == "show") { return this->show (client); }
		
		if (commands [0] == "registeredprofile") 
		{
			
			if (commands.size () < 3 || commands [1] != "isadvertised")
			{
				fprintf (stdout,"Invalid command\n");
				fprintf (stdout, "Usage : registeredprofile isadvertised <\"profilename\"> [<version>]");
				return -1;
			}

			string profileName = commands[2];
			string versionNo = "";

			if (commands.size() > 3 )
			{
				versionNo = commands[3];
			}
			
			/* Convert the user Input string to lower case*/
			for (size_t i = 0; i < profileName.size(); i++)
			{
				if (profileName[i] >= 0x41 && profileName[i] <= 0x5A)
				{
					profileName[i] = profileName[i] + 0x20;
				}
			}

			/* Find the input string has profile word if yes remove it or else leave the input string*/ 

			/* Elimating the spaces from the UserInput string*/
			while ((size_t)-1 != profileName.find (' '))
			{
				profileName.erase (profileName.find (' '), 1);
			}
			
			while ((size_t)-1 != profileName.find ("profile"))
			{
				profileName.erase (profileName.find ("profile"), strlen("profile"));
			}
						
			bool result = CRegisteredProfile::isAdvertised (client, profileName, versionNo);
			
			if (result == true)
			{
				if (versionNo == "")
				{
					fprintf(stdout, "%s profile is advertised",profileName.c_str ()); 
				}
				else
				{
					fprintf(stdout, "%s profile is advertised at %s",profileName.c_str(),versionNo.c_str ()); 
				}
			}

			else
			{
				if (versionNo == "")
				{
					fprintf (stdout, "%s profile is not advertised",profileName.c_str());
				}
				else
				{
					fprintf(stdout, "%s profile is not advertised at %s",profileName.c_str(),versionNo.c_str ()); 
				}
			}
			return 0;
		}

		if (commands [0] == "enumerate") 
		{ 
			if (commands.size () < 2)
			{
				fprintf (stderr, "Error: enumerate needs to be followed by the target\n");
				fprintf (stderr, "Example: enumerate computersystem");
				/* display root help */
				return -1;
			}
			CHECK_INVOKE_ENUM ("computersystem", ComputerSystem);
			CHECK_INVOKE_ENUM ("processor",      Processor);
			CHECK_INVOKE_ENUM ("sensor",         Sensor);
			CHECK_INVOKE_ENUM ("fan",            Fan);
			CHECK_INVOKE_ENUM ("powersupply",    PowerSupply);
			CHECK_INVOKE_ENUM ("memory",         Memory);
			CHECK_INVOKE_ENUM ("asset",          PhysicalAsset);
			CHECK_INVOKE_ENUM ("software",       Software);
			CHECK_INVOKE_ENUM ("operatingsystem",OperatingSystem);
			CHECK_INVOKE_ENUM ("bios",           BIOSElement);
			CHECK_INVOKE_ENUM ("bootconfig",     BootConfig);
			CHECK_INVOKE_ENUM ("user",           User);
			CHECK_INVOKE_ENUM ("role",           Role);
			CHECK_INVOKE_ENUM ("textredirection",TextRedirection);
			CHECK_INVOKE_ENUM ("usbredirection", USBRedirection);
			CHECK_INVOKE_ENUM ("opaquemanagementdata", OpaqueManagementData);
			CHECK_INVOKE_ENUM ("battery",        Battery);
			CHECK_INVOKE_ENUM ("networkport",    NetworkPort);
			CHECK_INVOKE_ENUM ("dhcpclient",     DHCPClient);
			CHECK_INVOKE_ENUM ("ipinterface",    IPInterface);
			CHECK_INVOKE_ENUM ("dnsclient",      DNSClient);
			CHECK_INVOKE_ENUM ("registeredprofile", RegisteredProfile);
			CHECK_INVOKE_ENUM ("ethernetport",	   EthernetPort);
			CHECK_INVOKE_ENUM ("indicationfilter",IndicationFilter);
			CHECK_INVOKE_ENUM ("filtercollection",FilterCollection);
			CHECK_INVOKE_ENUM ("alertdestination",AlertDestination);
			CHECK_INVOKE_ENUM ("indicationsubscription",AbstractIndicationSubscription);
			fprintf (stderr, 
					 "Error: Invalid request to enumerate '%s'",
					 commands [1].c_str ());
			return -1;
		}
		
		fprintf (stderr, "Error: Invalid command '%s'", commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client) const
	{
		printCLIInfo ();
		return 0;
	}

	/**
	 * Enumerates all the computer systems 
	 */
	int enumerateComputerSystem (IClient*           client,
								 const CCmdOption&  options, 
								 vector<string>     commands,
								 size_t             target_ix);

	/**
	 * Enumerates all the processor
	 */
	int enumerateProcessor (IClient*            client,
							const CCmdOption&   options, 
							vector<string>      commands,
							size_t              target_ix);

	/**
	 * Enumerates all the sensors
	 */
	int enumerateSensor (IClient*           client,
						 const CCmdOption&  options, 
						 vector<string>     commands,
						 size_t             target_ix);

	/**
	 * Enumerates all the memory
	 */
	int enumerateMemory (IClient*           client,
								 const CCmdOption&  options, 
								 vector<string>     commands,
								 size_t             target_ix);

	/**
	 * Enumerates all the power supplies
	 */
	int enumeratePowerSupply (IClient*          client,
							  const CCmdOption&     options, 
							  vector<string>        commands,
							  size_t                target_ix);

	/**
	 * Enumerates all the fans
	 */
	int enumerateFan (IClient*          client,
					  const CCmdOption&     options, 
					  vector<string>        commands,
					  size_t                target_ix);

	/**
	 * Enumerates all the assets
	 */
	int enumeratePhysicalAsset (IClient*            client,
						const CCmdOption&   options, 
						vector<string>      commands,
						size_t              target_ix);

	/**
	 * Enumerates all the softwares
	 */
	int enumerateSoftware (IClient*            client,
						const CCmdOption&   options, 
						vector<string>      commands,
						size_t              target_ix);

	/**
	 * Enumerates all the operating system
	 */
	int enumerateOperatingSystem (IClient*            client,
							 const CCmdOption&   options, 
							 vector<string>      commands,
							 size_t              target_ix);

	/**
	 * Enumerates all the BIOS element
	 */
	int enumerateBIOSElement (IClient*            client,
							 const CCmdOption&   options, 
							 vector<string>      commands,
							 size_t              target_ix);

	/**
	 * Enumerates all the boot configurations
	 */
	int enumerateBootConfig (IClient*            client,
							 const CCmdOption&   options, 
							 vector<string>      commands,
							 size_t              target_ix);

	/**
	 * Enumerates all the users
	 */
	int enumerateUser (IClient*            client,
						const CCmdOption&   options, 
						vector<string>      commands,
						size_t              target_ix);

	/**
	 * Enumerates all the roles
	 */
	int enumerateRole (IClient*            client,
						const CCmdOption&   options, 
						vector<string>      commands,
						size_t              target_ix);
	/**
	 * Enumerates all the Text redirection
	 */
	int enumerateTextRedirection (IClient*            client,
							 const CCmdOption&   options, 
							 vector<string>      commands,
							 size_t              target_ix);

	/**
	 * Enumerates all the USB redirection
	 */
	int enumerateUSBRedirection (IClient*            client,
							 const CCmdOption&   options, 
							 vector<string>      commands,
							 size_t              target_ix);

	/**
	 * Enumerates all the OpaqueManagementData
	 */
	int enumerateOpaqueManagementData (IClient*            client,
							 const CCmdOption&   options, 
							 vector<string>      commands,
							 size_t              target_ix);

	/**
	 * Enumerates all the Battery
	 */
	int enumerateBattery (IClient*            client,
							 const CCmdOption&   options, 
							 vector<string>      commands,
							 size_t              target_ix);

	/**
	 * Enumerates all the network port
	 */
	int enumerateNetworkPort (IClient*            client,
							 const CCmdOption&   options, 
							 vector<string>      commands,
							 size_t              target_ix);

	/**
	 * Enumerates all the DHCP Protocol EndPoint
	 */
	int enumerateDHCPClient (IClient*            client,
							 const CCmdOption&   options, 
							 vector<string>      commands,
							 size_t              target_ix);

	/**
	 * Enumerates all the IP Protocol EndPoint
	 */
	int enumerateIPInterface (IClient*            client,
							 const CCmdOption&   options, 
							 vector<string>      commands,
							 size_t              target_ix);
	/**
	 * Enumerates all the DNS Protocol EndPoint
	 */
	int enumerateDNSClient (IClient*            client,
						    const CCmdOption&   options, 
							vector<string>      commands,
							size_t              target_ix);

	/**
	 * Enumerates all the RegisteredProfile
	 */
	int enumerateRegisteredProfile (IClient*            client,
						    const CCmdOption&   options, 
							vector<string>      commands,
							size_t              target_ix);

	/*
	 * Enumerate all the ethernet Ports
	 */
	int enumerateEthernetPort (IClient*            client,
							   const CCmdOption&   options,
							   vector<string>	   commands,
							   size_t			   target_ix);

	/**
	 * Enumerates all the Indication Filter 
	 */
	int enumerateIndicationFilter (IClient*            client,
						    const CCmdOption&   options, 
							vector<string>      commands,
							size_t              target_ix);

	/**
	 * Enumerates all the Filter Collections
	 */
	int enumerateFilterCollection (IClient*            client,
						    const CCmdOption&   options, 
							vector<string>      commands,
							size_t              target_ix);

	/**
	 * Enumerates all the Alert Destination 
	 */
	int enumerateAlertDestination (IClient*            client,
						    const CCmdOption&   options, 
							vector<string>      commands,
							size_t              target_ix);

	/**
	 * Enumerates all the Indication Subscription Filter 
	 */
	int enumerateAbstractIndicationSubscription (IClient*            client,
						    const CCmdOption&   options, 
							vector<string>      commands,
							size_t              target_ix);

private:
	/**
	 * Returns the computer system(s) corresponding to instance number
	 */
	vector<CComputerSystem> getComputerSystemInstance (IClient* client, 
													   int  ins_num)
	{
		CComputerSystem::iterator iter = 
				CComputerSystem::enumComputerSystems (client);
		return getInstance<CComputerSystem> (iter, ins_num);
	}

	/**
	 * Returns the processor(s) corresponding to instance number
	 */
	vector<CProcessor> getProcessorInstance (IClient* client, 
											 int    ins_num)
	{
		CProcessor::iterator iter = CProcessor::enumProcessors (client);
		return getInstance<CProcessor> (iter, ins_num);
	}

	/**
	 * Returns the sensors (s) corresponding to instance number
	 */
	vector<CSensor> getSensorInstance (IClient* client, 
									   int  ins_num)
	{
		CSensor::iterator iter = CSensor::enumSensors (client);
		return getInstance<CSensor> (iter, ins_num);
   } 

	/**
	 * Returns the fans(s) corresponding to instance number
	 */
	vector<CFan> getFanInstance (IClient* client, 
								 int    ins_num)
	{
		CFan::iterator iter = CFan::enumFans (client);
		return getInstance<CFan> (iter, ins_num);
	}

	/**
	 * Returns the power supplu (s) corresponding to instance number
	 */
	vector<CPowerSupply> getPowerSupplyInstance (IClient* client, 
								 int    ins_num)
	{
		CPowerSupply::iterator iter = CPowerSupply::enumPowerSupplies (client);
		return getInstance<CPowerSupply> (iter, ins_num);
	}

	/**
	 * Returns the memory(s) corresponding to instance number
	 */
	vector<CMemory> getMemoryInstance (IClient* client, 
											   int  ins_num)
	{
		CMemory::iterator iter = 
				CMemory::enumMemory (client);
		return getInstance<CMemory> (iter, ins_num);
	}

	/**
	 * Returns the asset(s) corresponding to instance number
	 */
	vector<CPhysicalAsset> getPhysicalAssetInstance (IClient* client, 
													 int    ins_num)
	{
		CPhysicalAsset::iterator iter = 
				CPhysicalAsset::enumPhysicalAssets (client);
		return getInstance<CPhysicalAsset> (iter, ins_num);
	}

	/**
	 * Returns the softwares(s) corresponding to instance number
	 */
	vector<CSoftware> getSoftwareInstance (IClient* client, 
													 int    ins_num)
	{
		CSoftware::iterator iter = 
				CSoftware::enumSoftware (client);
		return getInstance<CSoftware> (iter, ins_num);
	}

	/**
	 * Returns the operating system(s) corresponding to instance number
	 */
	vector<COperatingSystem> getOperatingSystemInstance (IClient* client, 
											   int      ins_num)
	{
		COperatingSystem::iterator iter = 
				COperatingSystem::enumOperatingSystems (client);
		return getInstance<COperatingSystem> (iter, ins_num);
	}

	/**
	 * Returns the BIOS element(s) corresponding to instance number
	 */
	vector<CBIOSElement> getBIOSElementInstance (IClient* client, 
											   int      ins_num)
	{
		CBIOSElement::iterator iter = 
				CBIOSElement::enumBIOSElements (client);
		return getInstance<CBIOSElement> (iter, ins_num);
	}

	/**
	 * Returns the boot configuration(s) corresponding to instance number
	 */
	vector<CBootConfig> getBootConfigInstance (IClient* client, 
											   int      ins_num)
	{
		CBootConfig::iterator iter = 
				CBootConfig::enumBootConfigs (client);
		return getInstance<CBootConfig> (iter, ins_num);
	}

	/**
	 * Returns the user(s) corresponding to instance number
	 */
	vector<CUser> getUserInstance (IClient* client, 
								   int    ins_num)
	{
		CUser::iterator iter = CUser::enumUsers (client);
		return getInstance<CUser> (iter, ins_num);
	}

	/**
	 * Returns the role(s) corresponding to instance number
	 */
	vector<CRole> getRoleInstance (IClient* client, 
								   int    ins_num)
	{
		CRole::iterator iter = CRole::enumRoles (client);
		return getInstance<CRole> (iter, ins_num);
	}
	/**
	 * Returns the Text Redirection(s) corresponding to instance number
	 */
	vector<CTextRedirection> getTextRedirectionInstance (IClient* client, 
													   int      ins_num)
	{
		CTextRedirection::iterator iter = 
				CTextRedirection::enumTextRedirections (client);
		return getInstance<CTextRedirection> (iter, ins_num);
	}

	/**
	 * Returns the USB Redirection(s) corresponding to instance number
	 */
	vector<CUSBRedirection> getUSBRedirectionInstance (IClient* client, 
													   int      ins_num)
	{
		CUSBRedirection::iterator iter = 
				CUSBRedirection::enumUSBRedirections (client);
		return getInstance<CUSBRedirection> (iter, ins_num);
	}

	/**
	 * Returns the OpaqueManagementData corresponding to instance number
	 */
	vector<COpaqueManagementData> getOpaqueManagementDataInstance (IClient* client, 
													   int      ins_num)
	{
		COpaqueManagementData::iterator iter = 
				COpaqueManagementData::enumOpaqueManagementData (client);
		return getInstance<COpaqueManagementData> (iter, ins_num);
	}

	/**
	 * Returns the battery corresponding to instance number
	 */
	vector<CBattery> getBatteryInstance (IClient* client, 
													   int      ins_num)
	{
		CBattery::iterator iter = 
				CBattery::enumBattery (client);
		return getInstance<CBattery> (iter, ins_num);
	}

	/**
	 * Returns the networkport corresponding to instance number
	 */
	vector<CNetworkPort> getNetworkPortInstance (IClient* client, 
													   int      ins_num)
	{
		CNetworkPort::iterator iter = 
				CNetworkPort::enumNetworkPorts (client);
		return getInstance<CNetworkPort> (iter, ins_num);
	}

	/**
	 * Returns the DHCP Protocol EndPoint corresponding to instance number
	 */
	vector<CDHCPClient> getDHCPClientInstance (IClient* client, 
													   int      ins_num)
	{
		CDHCPClient::iterator iter = 
				CDHCPClient::enumDHCPClients (client);
		return getInstance<CDHCPClient> (iter, ins_num);
	}

	/**
	 * Returns the IP Protocol EndPoint corresponding to instance number
	 */
	vector<CIPInterface> getIPInterfaceInstance (IClient* client, 
													   int      ins_num)
	{
		CIPInterface::iterator iter = 
				CIPInterface::enumIPInterfaces (client);
		return getInstance<CIPInterface> (iter, ins_num);
	}

	/**
	 * Returns the DNS Protocol EndPoint corresponding to instance number
	 */
	vector<CDNSClient> getDNSClientInstance (IClient* client, 
												   int      ins_num)
	{
		CDNSClient::iterator iter = 
				CDNSClient::enumDNSClients (client);
		return getInstance<CDNSClient> (iter, ins_num);
	}

	/**
	 * Returns the Registered Profiles corresponding to instance number
	 */
	vector<CRegisteredProfile> getRegisteredProfileInstance (IClient* client, 
												   int      ins_num)
	{
		CRegisteredProfile::iterator iter = 
				CRegisteredProfile::enumRegisteredProfile (client);
		return getInstance<CRegisteredProfile> (iter, ins_num);
		
	}

	/*
	 * Returns the Ethernet Ports correspondong to instance number
	 */
	vector<CEthernetPort> getEthernetPortInstance (IClient* client,
														  int		ins_num)
	{
		CEthernetPort::iterator iter = 
			CEthernetPort::enumEthernetPorts (client);
		return getInstance<CEthernetPort> (iter, ins_num);
	}
	/**
	 * Returns the IndicationFilter corresponding to instance number
	 */
	vector<CIndicationFilter> getIndicationFilterInstance (IClient* client, 
												   int      ins_num)
	{
		CIndicationFilter::iterator iter = 
				CIndicationFilter::enumIndicationFilter (client);
		return getInstance<CIndicationFilter> (iter, ins_num);
	}

	/**
	 * Returns the IndicationFilter corresponding to instance number
	 */
	vector<CFilterCollection> getFilterCollectionInstance (IClient* client, 
												   int      ins_num)
	{
		CFilterCollection::iterator iter = 
				CFilterCollection::enumFilterCollection (client);
		return getInstance<CFilterCollection> (iter, ins_num);
	}

	/**
	 * Returns the Alert Destination corresponding to instance number
	 */
	vector<CAlertDestination> getAlertDestinationInstance (IClient* client, 
												   int      ins_num)
	{
		CAlertDestination::iterator iter = 
				CAlertDestination::enumAlertDestination (client);
		return getInstance<CAlertDestination> (iter, ins_num);
	}

	/**
	 * Returns the IndicationSubscription corresponding to instance number
	 */
	vector<CAbstractIndicationSubscription> getAbstractIndicationSubscriptionInstance (IClient* client, 
												   int      ins_num)
	{
		CAbstractIndicationSubscription::iterator iter = 
				CAbstractIndicationSubscription::enumIndicationSubscription (client);
		return getInstance<CAbstractIndicationSubscription> (iter, ins_num);
	}
};


/**
 * @class CComputerSystemExec
 * @brief A computer system executer.
 */
class CComputerSystemExec
{
public:
	typedef CComputerSystem APIType;

public:
	/**
	 * Constructor
	 */
	CComputerSystemExec (CComputerSystem cs) : _cs (cs) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{
		if (commands.size () == 0)  { displayComputerSystemHelp (commands,0); return -1; }
		if (commands [0] == "show") { return this->show (client); }
		if (commands [0] == "power"){ return this->power (client, options, commands, target_ix); }
		if (commands [0] == "user") { return this->user (client, options, commands, target_ix); }
		if (commands [0] == "role") { return this->role (client, options, commands, target_ix); }
		if (commands [0] == "opaquemanagementdata") { return this->opaquemanagementdata (client, options, commands, target_ix); }
		if (commands [0] == "bootconfig") 
		{ 
			return this->bootConfig (client, options, commands, target_ix); 
		}
		if (commands [0] == "enumerate") 
		{ 
			if (commands.size () < 2)
			{
				fprintf (stderr, 
						 "Error: enumerate needs to be followed by the type");
				/* display root help */
				return -1;
			}
			CHECK_INVOKE_ENUM ("processor",      Processor);
			CHECK_INVOKE_ENUM ("sensor",         Sensor);
			CHECK_INVOKE_ENUM ("fan",            Fan);
			CHECK_INVOKE_ENUM ("powersupply",    PowerSupply);
			CHECK_INVOKE_ENUM ("memory",         Memory);
			CHECK_INVOKE_ENUM ("asset",          PhysicalAsset);
			CHECK_INVOKE_ENUM ("software",       Software);
			CHECK_INVOKE_ENUM ("bootconfig",     BootConfig);
			CHECK_INVOKE_ENUM ("user",           User);
			fprintf (stderr, 
					 "Error: Invalid request to enumerate '%s'",
					 commands [1].c_str ());
			return -1;
		}
		
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Power command 
	 */
	int power (IClient*          client,
			   const CCmdOption& options, 
			   vector<string>    commands,
			   size_t            target_ix) 
	{
		try
		{
			int err;
			if( 1 == commands.size() ) {displayComputerSystemHelp (commands,0); return -1;}
			else if (commands [1] == "status")
			{
				fprintf (stdout, "Power state   : %s", _cs.getPowerStateStr ().c_str ());
				return 0;
			}
			if (commands [1] == "on")    
			{ 
				if (0 == (err = _cs.powerOn ())) { fprintf (stdout, "Power On Success"); return 0;}
				else
				{
					fprintf (stderr, "Power On Failed"); 
					if (isVerbose) 
					{ 
						fprintf (stderr, "\nError: %s", _cs.getReqPwrStateChangeErrStr (err).c_str ()); 
					}
					return -1;
				}
			}
			if (commands [1] == "off")   
			{ 
				if (0 == (err = _cs.powerOff ())) { fprintf (stdout, "Power Off Success"); return 0;	}
				else						
				{ 
					fprintf (stderr, "Power Off Failed");	
					if (isVerbose) 
					{ 
						fprintf (stderr, "\nError: %s", _cs.getReqPwrStateChangeErrStr (err).c_str ()); 
						
					}
					return -1;
				}
			}
			if (commands [1] == "cycle") 
			{ 
				if (0 == (err = _cs.powerCycle ()))	{ fprintf (stdout, "Power Cycle Success"); return 0;}
				else						
				{ 
					fprintf (stderr, "Power Cycle Failed");	
					if (isVerbose) 
					{ 
						fprintf (stderr, "\nError: %s", _cs.getReqPwrStateChangeErrStr (err).c_str ()); 
					}
					return -1;
				}
			}
			if (commands [1] == "resetgraceful") 
			{ 
				if (0 == (err = _cs.powerResetGraceful ()))	{ fprintf (stdout, "Power Reset Graceful Success"); return 0;}
				else						
				{ 
					fprintf (stderr, "Power Reset Graceful Failed");	
					if (isVerbose) 
					{ 
						fprintf (stderr, "\nError: %s", _cs.getReqPwrStateChangeErrStr (err).c_str ()); 
					}
					return -1;
				}
			}
			if (commands [1] == "reset")	
			{ 
				if (0 == (err = _cs.powerReset ()))	{ fprintf (stdout, "Power Reset Success"); return 0;}
				else						
				{ 
					fprintf (stderr, "Power Reset Failed");	
					if (isVerbose) 
					{ 
						fprintf (stderr, "\nError: %s", _cs.getReqPwrStateChangeErrStr (err).c_str ()); 
					}
					return -1;
				}
			}
			if (commands [1] == "supportedstates")	
			{ 
				try { 
						vector<string> states = _cs.getPowerStatesSupportedStr (); 
						displayVectorStr ("Supported Power States              : ", states, 4);
					}
				catch (...) { fprintf (stdout, "Supported Power States              : N/A");}
				return 0;
			}
			if (commands [1] == "offgraceful")   
			{ 
				if (0 == (err = _cs.powerOffGraceful ())) { fprintf (stdout, "Power Off Graceful Success"); return 0;	}
				else						
				{ 
					fprintf (stderr, "Power Off Graceful Failed");	
					if (isVerbose) 
					{ 
						fprintf (stderr, "\nError: %s", _cs.getReqPwrStateChangeErrStr (err).c_str ()); 
						
					}
					return -1;
				}
			}
			else
			{
				fprintf (stderr, "Error: Invalid power command '%s'",
												commands [1].c_str ());
				return -1;
			}
			
		}

		catch (exception& e)
		{
			fprintf (stderr, "Error: Power Operation failed");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}

	/**
	 * BootConfig command.
	 */
	int bootConfig (IClient*      client,
		const CCmdOption&   options,
		vector<string>      commands,
		size_t              target_ix)
	{
		if (commands.size () == 1) { displayComputerSystemHelp (commands, 0); return -1; }
		if (commands [1] == "add") { return this->addBootConfig    (client, commands);   }
		fprintf (stderr, "Error: Invalid bootconfig command '%s'",
												commands [1].c_str ());
		return -1;
	}

	/**
	 * add boot configuration
	 */
	int addBootConfig (IClient* client, vector<string> commands)
	{

		if (commands.size () < 5)
		{
			displayComputerSystemHelp (commands, 0);
			return -1;
		}
		/* sanity check for instance number */
		for (size_t i = 0; i < commands [2].size (); i++)
		{
			if (!isdigit (commands [2][i])) 
			{
				fprintf (stderr, "Invalid boot instance");
				return -1; 
			}
		}

		/* get the instance number */
		int inst_num ;
		if (-1 == dashcli_strtol (commands [2].c_str (), (long*)&inst_num))
		{
			fprintf (stderr, "Error : Invalid boot instance");
			return -1; 
		}

		try 
		{
			/* enumerate the boot configurations to find the instance specified */
			CBootConfig::iterator iter = enumBootConfigs (client, *(_cs.getCIMObject ()));
			for (int i = 0; iter != CBootConfig::iterator::end (); ++iter, i++)
			{
				if (i == inst_num)  { break; }
			}

			if (iter == CBootConfig::iterator::end ())
			{
				fprintf (stderr, "Invalid boot Instance");
				return -1;
			}

			/* crate a new instance of boot config */
			CBootConfig template_bc = *iter;
			CBootConfig bc = CBootConfig::addBootConfig (this->_cs, template_bc);

			/* set the boot configuration for new configuration */
			if (commands [3] == "true") { bc.setDefaultBoot (); }
			if (commands [4] == "true") { bc.setNextBoot ();    }

			/* get the existing boot order of newly created boot config and change the order*/
			vector <CBootDevice> oldBootOrder = bc.getBootOrder ();

			/* sanity check for the boot orders */
			for (size_t i = 5; i < commands.size (); i++)
			{
				int boot_order;
				if (-1 == dashcli_strtol (commands [i].c_str (), &val))
				{
					fprintf (stderr, "Error : Invalid boot order");
					return -1; 
				}
				boot_order = val;

				if (boot_order > (int)oldBootOrder.size ())
				{
					fprintf (stderr, "Invalid boot order, device does not exist");
				}
			}

			vector <CBootDevice> newBootOrder;

			/* order the boot order as given from input */
			for (size_t i = 2; i < commands.size (); i++)
			{
				newBootOrder.push_back (oldBootOrder [atoi (commands [i].c_str ())]);
			}
			
			/* copy the remaining boot devices that are not given from the input */
			for (size_t i = 0; i < oldBootOrder.size (); i++)
			{
				size_t j;
				for (j = 2; j < commands.size (); j++)
				{
					/* check if we already copied this boot device */
					if (i == (size_t)atoi (commands [j].c_str ())) break;
				}

				/* if we havent copied the device then copy it */
				if (j == commands.size ())
				{
					newBootOrder.push_back (oldBootOrder [i]);
				}
			}

			bc.changeBootOrder (newBootOrder);

			fprintf (stdout, "Boot Config Added Successfully"); 
			return 0;
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Adding boot config failed"); 
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1; 
		}
	}

	/**
	 * User command.
	 */
	int user (IClient*      client,
		const CCmdOption&   options,
		vector<string>      commands,
		size_t              target_ix)
	{
		if (commands.size () == 1)      { displayComputerSystemHelp (commands, 0); return -1; }
		if (commands [1] == "add")      { return this->addUser    (client, commands);   }
		fprintf (stderr, "Error: Invalid user command '%s'",
												commands [1].c_str ());
		displayComputerSystemHelp (commands, 0);
		return -1;
	}

	/**
	 * addUser
	 */
	int addUser (IClient* client, vector <string> commands)
	{
		if (commands.size () < 4)
		{
			displayComputerSystemHelp (commands, 0);
			return -1;
		}

		try
		{
			string organizationname;
			if (commands.size () == 5) {  organizationname = commands [4]; }
			CUser::createUser (this->_cs, commands [2], commands [3], organizationname);
			fprintf (stdout, "User Added Successfully");
		}
		catch (ECIMError& e)
		{
			fprintf (stderr, "\nAdding User Failed.");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;	
		}
		catch (EFunctionNotSupported& e)
		{
			fprintf (stderr, "\nAdding User function not supported.");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;	
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Adding user failed");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}

		return 0;
	}


	/**
	 * Role command.
	 */
	int role (IClient*      client,
		const CCmdOption&   options,
		vector<string>      commands,
		size_t              target_ix)
	{
		if (commands.size () == 1)      { displayComputerSystemHelp (commands, 0); return -1; }
		if (commands [1] == "add")      { return this->addRole    (client, commands);   }
	//	if (commands [1] == "getsupportedqualifiers")      { return this->getQualifiers    (client);   }
		fprintf (stderr, "Error: Invalid role command '%s'\n",
												commands [1].c_str ());
		displayComputerSystemHelp (commands, 0);
		return -1;
	}

	/**
	 * addRole
	 */
	int addRole (IClient* client, vector <string> commands)
	{

		if (commands.size () < 4)
		{
			displayComputerSystemHelp (commands, 0);
			return -1;
		}
		try
		{
			vector <CRole::Permission_T> permissions;

			for (size_t i = 3; i < commands.size (); i++)
			{
				CRole::Permission_T permission;
				string privilege = commands [i];

				/* seperate the activity */
				string activity = privilege.substr (0, privilege.find (','));

				if		(activity == "create") { permission.activity = CRole::Create; }
				else if (activity == "delete") { permission.activity = CRole::Delete; }
				else if (activity == "detect") { permission.activity = CRole::Detect; }
				else if (activity == "read")   { permission.activity = CRole::Read;   }
				else if (activity == "write")  { permission.activity = CRole::Write;  }
				else if (activity == "execute"){ permission.activity = CRole::Execute;}
				else if (activity == "other")  { permission.activity = CRole::Other;  }
				else 
				{
					fprintf (stderr, "Invalid activity \" %s \" specified\n", activity.c_str ());
					fprintf (stderr, "Should be one of these\n create|delete|detect|read|write|execute|other");
					return -1;
				}

				if ((size_t)-1 == privilege.find (','))
				{
					fprintf (stderr, "Qualifier missing, should be specified, seperated by comma in the permission");
					return -1;
				}
				permission.qualifier = privilege.substr (privilege.find (',') + 1, privilege.size ());
				permissions.push_back (permission);
			}
			CRole::createRole (this->_cs, commands [2], permissions);
			fprintf (stdout, "Role Added Successfully");
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Adding role failed");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}

		return 0;
	}

	/* int getQualifiers (IClient* client)
	 {
		 try
		 {
			 vector<string> qualifiers = CRole::getSupportedActivityQualifiers (client);

			 for (size_t i = 0; i < qualifiers.size (); i++)
			 {
				 fprintf (stdout, "%s\n", qualifiers [i].c_str ());
			 }

			 return 0;
		 }
		 catch (exception &e)
		 {
			 fprintf (stderr, "Error : Getting SupportedActivityQualifiers Failed");
			 if (isVerbose) { fprintf (stderr, "\nError : %s", e.what ()); }
			 return -1;
		 }
	 }*/

	
	/**
	 * Opaquemanagementdata command.
	 */
	int opaquemanagementdata (IClient*      client,
		const CCmdOption&   options,
		vector<string>      commands,
		size_t              target_ix)
	{
		if (commands.size () == 1)      { displayComputerSystemHelp (commands, 0); return -1; }
		if (commands [1] == "create")   { return this->create    (client, commands);   }
		fprintf (stderr, "Error: Invalid Opaquemanagementdata command '%s'",
												commands [1].c_str ());
		displayComputerSystemHelp (commands, 0);
		return -1;
	}

	/**
	 * createOpaquemanagementData
	 */
	int create (IClient* client, vector <string> commands)
	{
		string storagename = "";
		string dataFormat = "";	
		if ((commands.size() > 1) && (commands.size() < 4 ||  commands.size() > 5))
		{
			displayComputerSystemHelp (commands, 0);
			return -1;
		}	

		uint64 size = 0;
		if (-1 == dashcli_strtol (commands[3].c_str (), (long*)&size))
		{
			fprintf (stderr, "Error: Invalid size %s.\n", commands[2].c_str ());
			return -1;
		}
		if(commands.size () > 4)
			storagename = commands[4];						
		try
		{
			COpaqueManagementData::createData (this->_cs, commands[2], size, storagename,dataFormat);
			fprintf (stdout, "OpaquemanagementData Created Successfully");
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: OpaquemanagementData Creation failed");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}

		return 0;
	}
	 
	/**
	 * Shows the information
	 */
	int show (IClient* client) const
	{
		try			{ fprintf (stdout, "Name                                : %s\n", _cs.getName ().c_str ()); }
		catch (...) { fprintf (stdout, "Name                                : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Element Name                        : %s\n", _cs.getElementName ().c_str ()); }
		catch (...) { fprintf (stdout, "Element Name                        : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Primary Owner                       : %s\n", _cs.getPrimaryOwner ().c_str ()); }
		catch (...) { fprintf (stdout, "Primary Owner                       : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Primary Owner Contact               : %s\n", _cs.getPrimaryOwnerContact ().c_str ()); }
		catch (...) { fprintf (stdout, "Primary Owner Contact               : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Enabled State                       : %s\n", _cs.getEnabledStateStr ().c_str ()); }
		catch (...) { fprintf (stdout, "Enabled State                       : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Requested State                     : %s\n", _cs.getRequestedStateStr ().c_str ()); }
		catch (...) { fprintf (stdout, "Requested State                     : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Current Power State                 : %s\n", _cs.getPowerStateStr ().c_str ()); }
		catch (...) { fprintf (stdout, "Current Power State                 : %s\n", "N/A"); }
		
		try {
			vector<string> dedicated = _cs.getDedicatedStr ();
			displayVectorStr ("Dedicated To                        : ", dedicated, 4);
			fprintf (stdout, "\n");
		}
		catch (...) { fprintf (stdout, "Dedicated To                        : N/A\n");}
		try { 
			vector<string> capabilities = _cs.getPowerChangeCapabilitiesStr();
			displayVectorStr ("Supported Power Change capabilities : ", capabilities, 4);
			fprintf (stdout, "\n");
		}
		catch (...) { fprintf (stdout, "Supported Power Change capabilities : N/A\n");}
		try { 
			vector<string> states = _cs.getPowerStatesSupportedStr (); 
			displayVectorStr ("Supported Power States              : ", states, 4);
		}
		catch (...) { fprintf (stdout, "Supported Power States              : N/A");}
		return 0;
	}

private:
	/**
	 * Returns the processor(s) corresponding to instance number
	 */
	vector<CProcessor> getProcessorInstance (IClient* client, int ins_num)
	{
		CProcessor::iterator iter = enumProcessors (client, _cs);
		return getInstance<CProcessor> (iter, ins_num);
	}

	/**
	 * Returns the sensors (s) corresponding to instance number
	 */
	vector<CSensor> getSensorInstance (IClient* client, int ins_num)
	{
		CSensor::iterator iter = enumSensors (client, _cs);
		return getInstance<CSensor> (iter, ins_num);
	}

	/**
	 * Returns the fans(s) corresponding to instance number
	 */
	vector<CFan> getFanInstance (IClient* client, int ins_num)
	{
		CFan::iterator iter = enumFans (client, _cs);
		return getInstance<CFan> (iter, ins_num);
	}

	/**
	 * Returns the power supply (s) corresponding to instance number
	 */
	vector<CPowerSupply> getPowerSupplyInstance (IClient* client, 
								 int    ins_num)
	{
		CPowerSupply::iterator iter = enumPowerSupplies (client, _cs);
		return getInstance<CPowerSupply> (iter, ins_num);
	}


	/**
	 * Returns the memory(s) corresponding to instance number
	 */
	vector<CMemory> getMemoryInstance (IClient* client, int ins_num)
	{
		CMemory::iterator iter = enumMemory (client, _cs);
		return getInstance<CMemory> (iter, ins_num);
	}

	/**
	 * Returns the asset(s) corresponding to instance number
	 */
	vector<CPhysicalAsset> getPhysicalAssetInstance (IClient* client, 
													 int ins_num)
	{
		CPhysicalAsset::iterator iter = enumPhysicalAssets (client, _cs);
		return getInstance<CPhysicalAsset> (iter, ins_num);
	}

	/**
	 * Returns the software(s) corresponding to instance number
	 */
	vector<CSoftware> getSoftwareInstance (IClient* client, 
													 int ins_num)
	{
		CSoftware::iterator iter = enumSoftware (client, _cs);
		return getInstance<CSoftware> (iter, ins_num);
	}

	/**
	 * Returns the boot configuration(s) corresponding to instance number
	 */
	vector<CBootConfig> getBootConfigInstance (IClient* client, 
											 int    ins_num)
	{
		CBootConfig::iterator iter = enumBootConfigs (client, _cs);
		return getInstance<CBootConfig> (iter, ins_num);
	}

	/**
	 * Returns the users(s) corresponding to instance number
	 */
	vector<CUser> getUserInstance (IClient* client, 
								   int    ins_num)
	{
		CUser::iterator iter = enumUsers (client, _cs);
		return getInstance<CUser> (iter, ins_num);
	}

private:
	/**
	 * Enumerates all the processor
	 */
	int enumerateProcessor (IClient*            client,
							const CCmdOption&   options, 
							vector<string>      commands,
							size_t              target_ix);

	/**
	 * Enumerates all the sensors
	 */
	int enumerateSensor (IClient*           client,
						 const CCmdOption&  options, 
						 vector<string>     commands,
						 size_t             target_ix);

	/**
	 * Enumerates all the memory
	 */
	int enumerateMemory (IClient*           client,
								 const CCmdOption&  options, 
								 vector<string>     commands,
								 size_t             target_ix);

	/**
	 * Enumerates all the power supplies
	 */
	int enumeratePowerSupply (IClient*          client,
							  const CCmdOption&     options, 
							  vector<string>        commands,
							  size_t                target_ix);

	/**
	 * Enumerates all the fans
	 */
	int enumerateFan (IClient*          client,
					  const CCmdOption&     options, 
					  vector<string>        commands,
					  size_t                target_ix);

	/**
	 * Enumerates all the assets
	 */
	int enumeratePhysicalAsset (IClient*            client,
						const CCmdOption&   options, 
						vector<string>      commands,
						size_t              target_ix);

	/**
	 * Enumerates all the software
	 */
	int enumerateSoftware (IClient*            client,
						const CCmdOption&   options, 
						vector<string>      commands,
						size_t              target_ix);

	/**
	 * Enumerates all the boot configurations
	 */
	int enumerateBootConfig (IClient*            client,
							 const CCmdOption&   options, 
							 vector<string>      commands,
							 size_t              target_ix);

	/**
	 * Enumerates all the users
	 */
	int enumerateUser (IClient*            client,
						const CCmdOption&   options, 
						vector<string>      commands,
						size_t              target_ix);

private:
	CComputerSystem     _cs;
};

/**
 * @class CProcessorExec
 * @brief A processor executer.
 */
class CProcessorExec
{
public:
	/**
	 * Constructor
	 */
	CProcessorExec (CProcessor proc) : _proc (proc) { /* Empty */ }
					
	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{
		if (commands.size () == 0)    { displayProcessorHelp (commands, 0); return -1; }
		if (commands [0] == "show")   { return this->show (client); }
		if (commands [0] == "enumerate") 
		{ 
			if (commands.size () < 2)
			{
				fprintf (stderr, 
						 "Error: enumerate needs to be followed by the type");
				/* display root help */
				return -1;
			}
			CHECK_INVOKE_ENUM ("sensor",         Sensor);
			CHECK_INVOKE_ENUM ("fan",            Fan);
			CHECK_INVOKE_ENUM ("asset",          PhysicalAsset);
			CHECK_INVOKE_ENUM ("memory",         Memory);
			fprintf (stderr, 
					 "Error: Invalid request to enumerate '%s'",
					 commands [1].c_str ());
			return -1;
		}
		
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client) const
	{
		try			{ fprintf (stdout, "Element Name    : %s\n", _proc.getElementName ().c_str ()); }
		catch (...) { fprintf (stdout, "Element Name    : %s\n", "N/A"); }
		try			{ fprintf (stdout, "DeviceID        : %s\n", _proc.getDeviceID ().c_str ());}
		catch (...)	{ fprintf (stdout, "DeviceID        : %s\n", "N/A");}
		try			{ fprintf (stdout, "Family          : %s\n", _proc.getFamily ().c_str ());}
		catch (...)	{ fprintf (stdout, "Family          : %s\n", "N/A");}
		try			{ fprintf (stdout, "CPU Status      : %s\n", _proc.getCPUStatusStr ().c_str ());}
		catch (...) { fprintf (stdout, "CPU Status      : %s\n", "N/A");}
		try			{ fprintf (stdout, "Health State    : %s\n", _proc.getHealthStateStr ().c_str ());	}
		catch (...) { fprintf (stdout, "Health State    : %s\n", "N/A");	}
		try			{ fprintf (stdout, "Cur Clock Speed : %ld MHz\n", _proc.getCurrentClockSpeed ());}
		catch (...) { fprintf (stdout, "Cur Clock Speed : %s\n", "N/A");}
		try			{ fprintf (stdout, "Max Clock Speed : %ld MHz\n", _proc.getMaxClockSpeed ()); }
		catch (...) { fprintf (stdout, "Max Clock Speed : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Ext bus speed   : %ld MHz\n", _proc.getExternalBusClockSpeed ()); }
		catch (...) { fprintf (stdout, "Ext bus speed   : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Load Percent    : %ld\n", _proc.getLoadPercentage ()); }
		catch (...) { fprintf (stdout, "Load Percent    : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Enabled State   : %s\n", _proc.getEnabledStateStr ().c_str ()); }
		catch (...) { fprintf (stdout, "Enabled State   : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Requested State : %s\n", _proc.getRequestedStateStr ().c_str ()); }
		catch (...) { fprintf (stdout, "Requested State : %s\n", "N/A"); }
		try	{
			vector<string> status = _proc.getOperationalStatusStr (); 
			displayVectorStr ("OperationalState: ", status, 4);
		}
		catch (...) { fprintf (stdout, "OperationalState: %s", "N/A"); }
		return 0;
	}

private:
	/**
	 * Returns the sensors (s) corresponding to instance number
	 */
	vector<CSensor> getSensorInstance (IClient* client, int ins_num)
	{
		CSensor::iterator iter = enumSensors (client, _proc);
		return getInstance<CSensor> (iter, ins_num);
	}

	/**
	 * Returns the memory (s) corresponding to instance number
	 */
	vector<CMemory> getMemoryInstance (IClient* client, int ins_num)
	{
		CMemory::iterator iter = enumMemory (client, _proc);
		return getInstance<CMemory> (iter, ins_num);
	}

	/**
	 * Returns the fans(s) corresponding to instance number
	 */
	vector<CFan> getFanInstance (IClient* client, int ins_num)
	{
		CFan::iterator iter = enumFans (client, _proc);
		return getInstance<CFan> (iter, ins_num);
	}

	/**
	 * Returns the asset(s) corresponding to instance number
	 */
	vector<CPhysicalAsset> getPhysicalAssetInstance (IClient* client, 
													 int ins_num)
	{
		CPhysicalAsset::iterator iter = enumPhysicalAssets (client, _proc);
		return getInstance<CPhysicalAsset> (iter, ins_num);
	}

private:
	/**
	 * Enumerates all the sensors
	 */
	int enumerateSensor (IClient*           client,
						 const CCmdOption&  options, 
						 vector<string>     commands,
						 size_t             target_ix);

	/**
	 * Enumerates all the memory
	 */
	int enumerateMemory (IClient*           client,
								 const CCmdOption&  options, 
								 vector<string>     commands,
								 size_t             target_ix);

	/**
	 * Enumerates all the fans
	 */
	int enumerateFan (IClient*          client,
					  const CCmdOption&     options, 
					  vector<string>        commands,
					  size_t                target_ix);

	/**
	 * Enumerates all the assets
	 */
	int enumeratePhysicalAsset (IClient*            client,
						const CCmdOption&   options, 
						vector<string>      commands,
						size_t              target_ix);

private:
	CProcessor  _proc;
};


/**
 * @class CNumericSensorExec
 * @brief A Sensor executer.
 */
class CSensorExec
{
public:
	/**
	 * Constructor
	 */
	CSensorExec (CSensor sensor) : _sensor (sensor) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{
		if (commands.size () == 0)     { displaySensorHelp (commands,0); return -1; }
		if (commands [0] == "show")    { return this->show (client); }
		if (commands [0] == "reading") { return this->reading (client); }
		if (commands [0] == "setthreshold") { return this->set (client, options, commands, target_ix); }
		//if (commands [0] == "eventsubscribe")
		//{ 
		//	return this->subscribe (client, options, commands, target_ix); 
		//}
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client) 
	{

		try			{ fprintf (stdout, "Element Name      : %s\n", _sensor.getElementName ().c_str ());}
		catch (...) { fprintf (stdout, "Element Name      : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Device ID         : %s\n", _sensor.getDeviceID().c_str ());}
		catch (...) { fprintf (stdout, "Device ID         : %s\n", "N/A"); }
		try {
			fprintf (stdout, "Sensor Type       : %s\n", _sensor.getSensorTypeStr ().c_str ());
		}
		catch (...) { fprintf (stdout, "Sensor Type       : %s\n", "N/A"); }

		try	{
			vector<string> states = _sensor.getPossibleStates ();
			displayVectorStr ("Possible States   : ", states, 4);
			fprintf (stdout, "\n");
		}
		catch (...) { fprintf (stdout, "Possible States   : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Current State     : %s\n", _sensor.getCurrentState ().c_str ());}
		catch (...) { fprintf (stdout, "Current State     : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Health State      : %s\n", _sensor.getHealthStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "Health State      : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Enabled State     : %s\n", _sensor.getEnabledStateStr ().c_str ()); }
		catch (...) { fprintf (stdout, "Enabled State     : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Requested State   : %s\n", _sensor.getRequestedStateStr ().c_str ()); }
		catch (...) { fprintf (stdout, "Requested State   : %s\n", "N/A"); }
		try	{
			vector<string> status = _sensor.getOperationalStatusStr (); 
			displayVectorStr ("OperationalState  : ", status, 4);
			fprintf (stdout, "\n");
		}
		catch (...) { fprintf (stdout, "OperationalState  : %s\n", "N/A"); }

		/* 
		  all numeric sensor are sensor, so try converting all sensor to numeric sensor, 
		  if its numeric sensor it will have numeric sensor values like sensor reading, threshold etc, 
		  if not display as N/A
	    */
		CNumericSensor ns = CNumericSensor::toNumericSensor (_sensor);

		try			{ fprintf (stdout, "Sensor Reading    : %lu\n", ns.getCurrentReading ());}
		catch (...) { fprintf (stdout, "Sensor Reading    : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Base Unit         : %s\n", ns.getBaseUnitStr ().c_str ());}
		catch (...) { fprintf (stdout, "Base Unit         : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Unit Modifier     : %d\n", ns.getUnitModifier ());}
		catch (...) { fprintf (stdout, "Unit Modifier     : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Rate Units        : %s\n", ns.getRateUnitStr ().c_str ());}
		catch (...) { fprintf (stdout, "Rate Units        : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Threshold LNC     : %ld\n", (uint32) ns.getLowerThresholdNonCritical ()); }
		catch (...) { fprintf (stdout, "Threshold LNC     : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Threshold UNC     : %ld\n", (uint32) ns.getUpperThresholdNonCritical ()); }
		catch (...) { fprintf (stdout, "Threshold UNC     : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Threshold LC      : %ld\n", (uint32) ns.getLowerThresholdCritical ()); }
		catch (...) { fprintf (stdout, "Threshold LC      : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Threshold UC      : %ld\n", (uint32) ns.getUpperThresholdCritical ()); }
		catch (...) { fprintf (stdout, "Threshold UC      : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Threshold LF      : %ld\n", (uint32) ns.getLowerThresholdFatal ()); }
		catch (...) { fprintf (stdout, "Threshold LF      : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Threshold UF      : %ld", (uint32) ns.getUpperThresholdFatal ()); }
		catch (...) { fprintf (stdout, "Threshold UF      : %s", "N/A"); }

		return 0;
	}

	/**
	 * Shows the reading
	 */
	int reading (IClient* client)
	{
		CNumericSensor ns = CNumericSensor::toNumericSensor (_sensor);
		try			{ fprintf (stdout, "Sensor Reading    : %lu", ns.getCurrentReading ());}
		catch (...) { fprintf (stdout, "Sensor Reading    : %s", "N/A"); }
		return 0;
	}

	/**
	 * sets the threshold 
	 */
	int set (IClient*           client,
			 const CCmdOption& options, 
			 vector<string>    commands,
			 size_t            target_ix)
	{
		try
		{
			if (commands.size () != 3) 
			{
				fprintf (stderr, "Error: Invalid arguments.\n");
				displaySensorHelp (commands, 0);
				return -1;
			}
	
			CNumericSensor ns = CNumericSensor::toNumericSensor (_sensor);
			if(ns.getSettableThresholds().size() != 0 ){
				long val;
				if (-1 == dashcli_strtol (commands [2].c_str (), &val))
				{
					fprintf (stderr, "Error: Invalid threshold value.\n");
					displaySensorHelp (commands, 0);
					return -1;
				}

				if (commands [1] == "lnc")
				{
					ns.setLowerThresholdNonCritical (val);			
				}
				else if (commands [1] == "unc")
				{
					ns.setUpperThresholdNonCritical (val);			
				}
				else if (commands [1] == "lc")
				{
					ns.setLowerThresholdCritical (val);			
				}
				else if (commands [1] == "uc")
				{
					ns.setUpperThresholdCritical (val);			
				}
				else if (commands [1] == "lf")
				{
					ns.setLowerThresholdFatal (val);			
				}
				else if (commands [1] == "uf")
				{
					ns.setUpperThresholdFatal (val);			
				}
				else
				{
					fprintf (stderr, "Error: Invalid arguments");
					displaySensorHelp (commands, 0);
					return -1;
				}

				fprintf (stdout, "Threshold Set Successfully");
				return 0;
			}
			else
			{
			throw EFunctionNotSupported ("RestoreDefaultThresholds Method not Supported");
			}
		}catch (ECIMError& e)
		{
		fprintf (stderr, "Error:RestoreDefaultThresholds Method not supported");
		if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
		return -1;
		}
		catch (exception& e)
		{
			fprintf (stderr, "Setting Threshold failed");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ());}
			return -1;
		}
		return 0;
	}

	/**
	 * subscribe for any event on this sensor
	 */
	int subscribe (IClient*           client,
				   const CCmdOption& options, 
				   vector<string>    commands,
				   size_t            target_ix)
	{
		if (commands.size () < 4)
		{
			fprintf (stderr, "Error: Invalid arguments");
			displaySensorHelp (commands, 1);
			return -1;
		}

		try {

			char hostname [100];
			if (gethostname (hostname, sizeof (hostname)) == SOCKET_ERROR) 
			{
				fprintf (stderr, "Error : unable to get local host name");
				return -1;
			}

			string url = "http://" + string (hostname) + ":8080/eventsink";
			int    mode;

			/* get the mode */
			if      (commands [1] == "push")        { mode = 0; }
			else if (commands [1] == "pushack")     { mode = 1; }
			else if (commands [1] == "pushbatch")   { mode = 2; }
			else if (commands [1] == "pull")        { mode = 3; }
			else 
			{
				fprintf (stderr, "Error : Invalid event mode");
				return -1;
			}

			/* get the heart beat and expiration interval */
			float heartbeat_interval;
			if (-1 == dashcli_strtol (commands [2].c_str (), &val))
			{
				fprintf (stderr, "Error: Invalid heartbeat interval number");
				return -1;
			}
			heartbeat_interval =(float) val;

			float expiration_timeout;
			if (-1 == dashcli_strtol (commands [3].c_str (), &val))
			{
				fprintf (stderr, "Error: Invalid expiration timeout number");
				return -1;
			}
			expiration_timeout =(float) val;

			/* create the filter */
			string filter = "select * from CIM_AlertIndication where SystemCreationClassName=\"" 
				+ _sensor.getSystemCreationClassName () + "\", SystemName=\""
				+ _sensor.getSystemName ()+ "\"";
			
			string uuid;
			uuid = subscribeEvent (client, url, mode, heartbeat_interval, expiration_timeout,
									"http://schemas.microsoft.com/wbem/wsman/1/WQL", filter);

			/* if specified listen for event */
			if ((commands.size () >= 4) && commands [4] == "listenevent")
			{
				doListenEvents (options, commands);

				if ((commands.size () >= 5) && commands [5] == "unsubscribe")
				{
					unsubscribeEvent (client, uuid);
				}
			}
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Subscription failed");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ());}
			return -1;
		}

		return 0;
	}

private:
	CSensor _sensor;
};


/**
 * @class CFanExec
 * @brief A fan executer.
 */
class CFanExec
{
public:
	/**
	 * Constructor
	 */
	CFanExec (CFan fan) : _fan (fan) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{
		if (commands.size () == 0)  { displayFanHelp (commands,0); return -1; }
		if (commands [0] == "show") { return this->show (client); }
		if (commands [0] == "setspeed") { return this->setSpeed (client, commands); }
		if (commands [0] == "enumerate") 
		{ 
			if (commands.size () < 2)
			{
				fprintf (stderr, 
						 "Error: enumerate needs to be followed by the type");
				/* display root help */
				return -1;
			}
			CHECK_INVOKE_ENUM ("asset",          PhysicalAsset);
			fprintf (stderr, 
					 "Error: Invalid request to enumerate '%s'",
					 commands [1].c_str ());
			return -1;
		}
		
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client) const
	{
		try			{ fprintf (stdout, "Element Name      : %s\n", _fan.getElementName ().c_str ()); }
		catch (...) { fprintf (stdout, "Element Name      : %s\n", "N/A"); }
		try			{ fprintf (stdout, "DeviceID          : %s\n", _fan.getDeviceID ().c_str ()); }
		catch (...) { fprintf (stdout, "DeviceId          : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Health State      : %s\n", _fan.getHealthStateStr ().c_str ());	}
		catch (...) { fprintf (stdout, "Health State      : %s\n", "N/A");	}
		try {
			if (_fan.isVariableSpeed ())
			{
					  fprintf (stdout, "Is Variable Speed : Yes\n");
					  //fprintf (stdout, "Is Variable Speed : %s\n",_fan.getSpeed ().c_str ());
			}
			else 
			{
					  fprintf (stdout, "Is Variable Speed : No\n");
			}
		}
		catch (...)
		{
					  fprintf (stdout, "Is Variable Speed : N/A\n"); 
		}
		try			{ fprintf (stdout, "Desired Speed     : %llu\n", _fan.getDesiredSpeed ());}
		catch (...) { fprintf (stdout, "Desired Speed     : %s\n", "N/A"); }
		try {
			if (_fan.isVariableSpeed ()) { fprintf (stdout, "Is Active Cooling : Yes\n"); }
			else {						   fprintf (stdout, "Is Active Cooling : No\n");  }
		}
		catch (...)
		{
					  fprintf (stdout, "Is Active Cooling : N/A\n"); 
		}
		try			{ fprintf (stdout, "Enabled State     : %s\n", _fan.getEnabledStateStr ().c_str ()); }
		catch (...) { fprintf (stdout, "Enabled State     : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Requested State   : %s\n", _fan.getRequestedStateStr ().c_str ()); }
		catch (...) { fprintf (stdout, "Requested State   : %s\n", "N/A"); }
		try	{
			vector<string> status = _fan.getOperationalStatusStr (); 
			displayVectorStr ("OperationalState  : ", status, 4);
		}
		catch (...) { fprintf (stdout, "OperationalState  : %s", "N/A"); }

		return 0;
	}

	/*
	 * Set speed
	 */
	int setSpeed (IClient* client, vector<string> commands)
	{
		if (commands.size () < 2)
		{
			displayFanHelp (commands, 0);
			return -1;
		}

		uint64 speed;
		if (-1 == dashcli_strtol (commands [1].c_str (), &val))
		{
			fprintf (stderr, "Error : Invalid speed");
			return -1;
		}

		speed =(uint64) val;

		try 
		{
			uint32 ret;
			if (0 == (ret = this->_fan.setDesiredSpeed (speed)))
			{
				fprintf (stdout, "Speed set successfully");
			}
			else
			{
				fprintf (stderr, "Set Speed Failed"); 
				if (isVerbose) 
				{ 
					fprintf (stderr, "\nError: %s", _fan.getSetSpeedErrStr (ret).c_str ()); 
				}
				
			}
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Set Speed Failed");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}

		return 0;
	}

private:
	/**
	 * Returns the asset(s) corresponding to instance number
	 */
	vector<CPhysicalAsset> getPhysicalAssetInstance (IClient* client, 
													 int ins_num)
	{
		CPhysicalAsset::iterator iter = enumPhysicalAssets (client, _fan);
		return getInstance<CPhysicalAsset> (iter, ins_num);
	}

private:
	/**
	 * Enumerates all the assets
	 */
	int enumeratePhysicalAsset (IClient*            client,
						const CCmdOption&   options, 
						vector<string>      commands,
						size_t              target_ix);

private:
	CFan    _fan;
};


/**
 * @class CPowerSupplyExec
 * @brief A power supply executer.
 */
class CPowerSupplyExec
{
public:
	/**
	 * Constructor
	 */
	CPowerSupplyExec (CPowerSupply  ps) : _ps (ps) { /* empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{
		if (commands.size () == 0)  { displayPowerSupplyHelp (commands, 0); return -1; }
		if (commands [0] == "show") { return this->show (client); }
		if (commands [0] == "enumerate") 
		{ 
			if (commands.size () < 2)
			{
				fprintf (stderr, 
						 "Error: enumerate needs to be followed by the type");
				/* display root help */
				return -1;
			}
			CHECK_INVOKE_ENUM ("asset",          PhysicalAsset);
			fprintf (stderr, 
					 "Error: Invalid request to enumerate '%s'",
					 commands [1].c_str ());
			return -1;
		}
		
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client) const
	{
		try         { fprintf (stdout, "Element Name\t\t: %s\n", _ps.getElementName ().c_str ());}
		catch (...) { fprintf (stdout, "Element Name\t\t: %s\n", "N/A");}
		try         { fprintf (stdout, "DeviceID\t\t: %s\n", _ps.getDeviceID ().c_str ());}
		catch (...) { fprintf (stdout, "DeviceID\t\t: %s\n", "N/A");}
		try         { fprintf (stdout, "Total power\t\t: %ld\n", _ps.getTotalPower ());  }
		catch (...) { fprintf (stdout, "Total power\t\t: %s\n", "N/A");   }
		try			{ fprintf (stdout, "Health State\t\t: %s\n", _ps.getHealthStateStr ().c_str ());	}
		catch (...) { fprintf (stdout, "Health State\t\t: %s\n", "N/A");	}
		try			{ fprintf (stdout, "Enabled State\t\t: %s\n", _ps.getEnabledStateStr ().c_str ()); }
		catch (...) { fprintf (stdout, "Enabled State\t\t: %s\n", "N/A"); }
		try			{ fprintf (stdout, "Requested State\t\t: %s\n", _ps.getRequestedStateStr ().c_str ()); }
		catch (...) { fprintf (stdout, "Requested State\t\t: %s\n", "N/A"); }
		try	{
			vector<string> status = _ps.getOperationalStatusStr (); 
			displayVectorStr ("OperationalState\t: ", status, 4);
		}
		catch (...) { fprintf (stdout, "OperationalState : %s", "N/A"); }
		return 0;
	}

private:
	/**
	 * Returns the asset(s) corresponding to instance number
	 */
	vector<CPhysicalAsset> getPhysicalAssetInstance (IClient* client, 
													 int ins_num)
	{
		CPhysicalAsset::iterator iter = enumPhysicalAssets (client, _ps);
		return getInstance<CPhysicalAsset> (iter, ins_num);
	}


private:
	/**
	 * Enumerates all the assets
	 */
	int enumeratePhysicalAsset (IClient*            client,
						const CCmdOption&   options, 
						vector<string>      commands,
						size_t              target_ix);

private:
	CPowerSupply    _ps;
};


/**
 * @class CPhysicalAssetExec
 * @brief A physical asset executer.
 */
class CPhysicalAssetExec
{
public:
	/**
	 * Constructor
	 */
	CPhysicalAssetExec (CPhysicalAsset pa) : _pa (pa) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{
		if (commands.size () == 0)  { displayAssetHelp (commands, 0); return -1; }
		if (commands [0] == "show") { return this->show (client); }
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client) const
	{
		try         { fprintf (stdout, "Element Name      : %s\n", _pa.getElementName ().c_str ());}
		catch (...) { fprintf (stdout, "Element Name      : %s\n", "N/A");}
		try         { fprintf (stdout, "Manufacturer      : %s\n", _pa.getManufacturer ().c_str ());}
		catch (...) { fprintf (stdout, "Manufacturer      : %s\n", "N/A");}
		try         { fprintf (stdout, "Model             : %s\n", _pa.getModel ().c_str ());   }
		catch (...) { fprintf (stdout, "Model             : %s\n", "N/A");}
		try         { fprintf (stdout, "Serial Number     : %s\n", _pa.getSerialNumber ().c_str ());}
		catch (...) { fprintf (stdout, "Serial Number     : %s\n", "N/A");}
		try         { fprintf (stdout, "Part Number       : %s\n", _pa.getPartNumber ().c_str ());}
		catch (...) { fprintf (stdout, "Part Number       : %s\n", "N/A");}
		try         { fprintf (stdout, "SKU               : %s\n", _pa.getSKU ().c_str ());}
		catch (...) { fprintf (stdout, "SKU               : %s\n", "N/A");}
		try         { fprintf (stdout, "Tag               : %s\n", _pa.getTag ().c_str ());}
		catch (...) { fprintf (stdout, "Tag               : %s\n", "N/A");}

		try         { fprintf (stdout, "Memory Type       : %s\n", _pa.getMemoryTypeStr ().c_str ());}
		catch (...) {}
		try         { fprintf (stdout, "Memory Speed      : %lu MHz\n", _pa.getMemorySpeed ());}
		catch (...) {}
		try
		{ 
			uint64 size = _pa.getMemoryCapacity ();
			if ((size / (1024 * 1024)) >= 1024)
			{
				fprintf (stdout, "Memory Capacity   : %llu MB\n", (size / (1024 * 1024)));
			}
			else if ((size / 1024) >= 1024)
			{
				fprintf (stdout, "Memory Capacity   : %llu KB\n", (size / 1024));
			}
			else
			{
				fprintf (stdout, "Memory Capacity   : %llu Bytes\n", size);
			}
		}
		catch (...) {}
		try         { fprintf (stdout, "Memory Bank Label : %s\n", _pa.getMemoryBankLabel ().c_str ());}
		catch (...) {}
		try         { fprintf (stdout, "Memory FormFactor : %s\n", _pa.getFormFactorStr ().c_str ());}
		catch (...) {}
		try         { fprintf (stdout, "Slot Number       : %u\n", _pa.getSlotNumber ());}
		catch (...) {}
		try         { fprintf (stdout, "Chassis Type      : %s\n", _pa.getChassisPackageTypeStr ().c_str ());}
		catch (...) {}
		try         { fprintf (stdout, "Connector Type    : %s\n", _pa.getConnectorLayoutStr ().c_str ());}
		catch (...) {}
		try         { fprintf (stdout, "Rack Type         : %s\n", _pa.getTypeOfRackStr ().c_str ());}
		catch (...) {}
		try         { fprintf (stdout, "Version           : %s\n", _pa.getVersion ().c_str ());}
		catch (...) {}
		try         { fprintf (stdout, "Package Type      : %s\n", _pa.getPackageTypeStr ().c_str ());}
		catch (...) {}
		try         { 
			if (_pa.canBeFRUed ()) { fprintf (stdout, "Can be FRUed ?    : %s\n", "Yes");}
			else                   { fprintf (stdout, "Can be FRUed ?    : %s\n", "No");}
		}
		catch (...) {}
		try         { 
			if (_pa.isHostingBoard ()) { fprintf (stdout, "Is HostingBoard ? : %s", "Yes");}
			else                       { fprintf (stdout, "Is HostingBoard ? : %s", "No");}
		}
		catch (...) {}
		return 0;
	}

private:
	CPhysicalAsset  _pa;
};


/**
 * @class CMemoryExec

 * @brief A memory executer.
 */
class CMemoryExec
{
public:
	/**
	 * Constructor
	 */
	CMemoryExec (CMemory memory) : _memory (memory) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{
		if (commands.size () == 0)  { displayMemoryHelp (commands, 0); return -1; }
		if (commands [0] == "show") { return this->show (client); }
		if (commands [0] == "enumerate") 
		{ 
			if (commands.size () < 2)
			{
				fprintf (stderr, 
						 "Error: enumerate needs to be followed by the type");
				/* display root help */
				return -1;
			}
			CHECK_INVOKE_ENUM ("asset",          PhysicalAsset);
			fprintf (stderr, 
					 "Error: Invalid request to enumerate '%s'",
					 commands [1].c_str ());
			return -1;
		}
		
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client) const
	{
		try			{ fprintf (stdout, "Element Name        : %s\n", _memory.getElementName ().c_str ()); }
		catch (...) { fprintf (stdout, "Element Name        : %s\n", "N/A"); }
		try			{ fprintf (stdout, "DeviceID            : %s\n", _memory.getDeviceID ().c_str ());}
		catch (...)	{ fprintf (stdout, "DeviceID            : %s\n", "N/A");}
		try			{ fprintf (stdout, "Health State        : %s\n", _memory.getHealthStateStr ().c_str ());	}
		catch (...) { fprintf (stdout, "Health State        : %s\n", "N/A");	}
		try			{ fprintf (stdout, "Enabled State       : %s\n", _memory.getEnabledStateStr ().c_str ()); }
		catch (...) { fprintf (stdout, "Enabled State       : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Requested State     : %s\n", _memory.getRequestedStateStr ().c_str ()); }
		catch (...) { fprintf (stdout, "Requested State     : %s\n", "N/A"); }
		try         { fprintf (stdout, "Access Type         : %s\n", _memory.getAccessStr ().c_str ()); }
		catch (...) { fprintf (stdout, "Access Type         : %s\n", "N/A"); }
		try
		{
			uint64 size = _memory.getBlockSize () * _memory.getNumberOfBlocks ();
			if ((size / (1024 * 1024)) >= 1024)
			{
				fprintf (stdout, "Total Memory        : %llu MB\n", (size / (1024 * 1024)));
			}
			else if ((size / 1024) >= 1024)
			{
				fprintf (stdout, "Total Memory        : %llu KB\n", (size / 1024));
			}
			else
			{
				fprintf (stdout, "Total Memory        : %llu Bytes\n", size);
			}
		}
		catch (...) { fprintf (stdout, "Total Memory        : %s\n", "N/A"); }
		try
		{ 
			uint64 size = _memory.getBlockSize () * _memory.getConsumableBlocks ();
			if ((size / (1024 * 1024)) > 1024)
			{
				fprintf (stdout, "Available Memory    : %llu MB\n", (size / (1024 * 1024)));
			}
			else if ((size / 1024) > 1024)
			{
				fprintf (stdout, "Available Memory    : %llu KB\n", (size / 1024));
			}
			else
			{
				fprintf (stdout, "Available Memory    : %llu Bytes\n", size);
			}
		}
		catch (...) { fprintf (stdout, "Available Memory    : %s\n", "N/A"); }
		try { 
			if (_memory.isVolatile ()) { fprintf (stdout, "Is Volatile Memory  : %s", "Yes"); }
			else					   { fprintf (stdout, "Is Volatile Memory  : %s", "No"); }
		}
		catch (...) { fprintf (stdout, "Is Volatile Memory  : %s", "N/A"); }
		return 0;
	}
private:
	/**
	 * Returns the asset(s) corresponding to instance number
	 */
	vector<CPhysicalAsset> getPhysicalAssetInstance (IClient* client, 
													 int ins_num)
	{
		CPhysicalAsset::iterator iter = enumPhysicalAssets (client, _memory);
		return getInstance<CPhysicalAsset> (iter, ins_num);
	}

private:
	/**
	 * Enumerates all the assets
	 */
	int enumeratePhysicalAsset (IClient*            client,
						const CCmdOption&   options, 
						vector<string>      commands,
						size_t              target_ix);


private:
	CMemory _memory;
};

/**
 * @class CSoftwareExec
 * @brief A software executer.
 */
class CSoftwareExec
{
public:
	/**
	 * Constructor
	 */
	CSoftwareExec (CSoftware sw) : _sw (sw) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{
		if (commands.size () == 0)  { displaySoftwareHelp (commands, 0); return -1; }
		if (commands [0] == "show") { return this->show (client); }
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client) const
	{
		
		try         { fprintf (stdout, "Instance ID                : %s\n", _sw.getInstanceID ().c_str ());}
		catch (...) { fprintf (stdout, "Instance ID                : %s\n", "N/A");}
		try         { fprintf (stdout, "IsEntity                   : %s\n", _sw.getIsEntity ()?"True":"False");}
		catch (...) { fprintf (stdout, "IsEntity                   : %s\n", "N/A");}
		try         { fprintf (stdout, "VersionString              : %s\n", _sw.getVersionString ().c_str());}
		catch (...) { fprintf (stdout, "VersionString              : %s\n", "N/A");}
		try         { fprintf (stdout, "Major Version              : %d\n", _sw.getMajorVersion ());}
		catch (...) { fprintf (stdout, "Major Version              : %s\n", "N/A");}
		try         { fprintf (stdout, "Minor Version              : %d\n", _sw.getMinorVersion ());}
		catch (...) { fprintf (stdout, "Minor Version              : %s\n", "N/A");}
		try         { fprintf (stdout, "Revision Number            : %d\n", _sw.getRevisionNumber ());}
		catch (...) { fprintf (stdout, "Revision Number            : %s\n", "N/A");}
		try         { fprintf (stdout, "Build Number               : %d\n", _sw.getBuildNumber ());}
		catch (...) { fprintf (stdout, "Build Number               : %s\n", "N/A");}

		try {
			vector <string> targetedOS = _sw.getTargetOperatingSystems ();
			displayVectorStr ("Targeted Operating Systems : ", targetedOS, 4);
			fprintf (stdout, "\n");
		}
		catch (...)
		{
			fprintf (stdout, "Targeted Operating Systems : %s\n", "N/A");
		}

		try {
			vector<string> identityInfoType =  _sw.getIdentityInfoType ();
			displayVectorStr ("IdentityInfo Type          : ", identityInfoType, 4);
			fprintf (stdout, "\n");
		}
		catch (...)
		{
			fprintf (stdout, "IdentityInfo Type          : %s\n", "N/A");
		}

		try {
			vector<string> identityInfoValue =  _sw.getIdentityInfoValue ();
			displayVectorStr ("IdentityInfo Value         : ", identityInfoValue, 4);
			fprintf (stdout, "\n");
		}
		catch (...)
		{
			fprintf (stdout, "IdentityInfo Value         : %s\n", "N/A");
		}
		
		try {
			vector<string> classifications =  _sw.getClassificationsStr ();
			displayVectorStr ("Software Classifications   : ", classifications, 4);
		}
		catch (...)
		{
			fprintf (stdout, "Software Classifications   : %s", "N/A");
		}
	
		return 0;
	}

private:
	CSoftware  _sw;
};

/**
 * @class COperatingSystemExec
 * @brief A operating system executer.
 */
class COperatingSystemExec
{
public:
	/**
	 * Constructor
	 */
	COperatingSystemExec (COperatingSystem os) : _os (os) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{

		if (commands.size () == 0)              { displayOperatingSystemHelp (commands, 0); return -1; }
		if (commands [0] == "show")             { return this->show (client); }
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client) const
	{
		try         { fprintf (stdout, "Name                       : %s\n", _os.getName ().c_str ());}
		catch (...) { fprintf (stdout, "Name                       : %s\n", "N/A");}
		try         { fprintf (stdout, "OS Type                    : %s\n", _os.getOSType ().c_str ());}
		catch (...) { fprintf (stdout, "OS Type                    : %s\n", "N/A");}
		try         { fprintf (stdout, "Enabled State              : %s\n", _os.getEnabledStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "Enabled State              : %s\n", "N/A");}
		try         { fprintf (stdout, "Requested State            : %s\n", _os.getRequestedStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "Requested State            : %s\n", "N/A");}
		try	{
			vector<string> states = _os.getAvailableRequestedStatesStr ();
			displayVectorStr ("Available Requested States : ", states, 4);
			fprintf (stdout, "\n");
		}
		catch (...) { fprintf (stdout, "Available Requested States : %s\n", "N/A"); }
		try         { fprintf (stdout, "Transitioning To State     : %s", _os.getTransitioningToStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "Transitioning To State     : %s", "N/A");}

		return 0;
	}

private:
	COperatingSystem  _os;
};

/**
 * @class CBIOSElementExec
 * @brief A bios element executer.
 */
class CBIOSElementExec
{
public:
	/**
	 * Constructor
	 */
	CBIOSElementExec (CBIOSElement be) : _be (be) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{

		if (commands.size () == 0)              { displayBIOSHelp (commands, 0); return -1; }
		if (commands [0] == "show")             { return this->show (client); }
		if (commands [0] == "restoredefaults")  { return this->restoreDefaults(client);}
		if (commands [0] == "setattribute" )    { return this->setAttribute(client,commands);}
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client)
	{
		try         { fprintf (stdout, "BIOS Name              : %s\n", _be.getName ().c_str ());}
		catch (...) { fprintf (stdout, "BIOS Name              : %s\n", "N/A");}
		try         { fprintf (stdout, "Manufacturer           : %s\n", _be.getManufacturer ().c_str ());}
		catch (...) { fprintf (stdout, "Manufacturer           : %s\n", "N/A");}
		try         { fprintf (stdout, "Version                : %s\n", _be.getVersion ().c_str ());}
		catch (...) { fprintf (stdout, "Version                : %s\n", "N/A");}
		try         { fprintf (stdout, "Is PrimaryBIOS         : %s\n", _be.getPrimaryBIOS ()?"True":"False");}
		catch (...) { fprintf (stdout, "Is PrimaryBIOS         : %s\n", "N/A");}
		try         { fprintf (stdout, "SoftwareElementState   : %s\n", _be.getSoftwareElementStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "SoftwareElementState   : %s\n", "N/A");}
		try         { fprintf (stdout, "SoftwareElementID      : %s\n", _be.getSoftwareElementID ().c_str ());}
		catch (...) { fprintf (stdout, "SoftwareElementID      : %s\n", "N/A");}
		try         { fprintf (stdout, "Target OperatingSystem : %s\n", _be.getTargetOperatingSystemStr ().c_str ());}
		catch (...) { fprintf (stdout, "Target OperatingSystem : %s\n", "N/A");}

		vector <string>			defaultValues;
		vector <string>			currentValues;
		try
		{
			vector <CBIOSAttribute> ba				= _be.getAttributes ();

			fprintf(stdout,"\nBIOS Attribute (s)   :");
			if( ba.size() == 0)
				fprintf(stdout,"   N/A");

			for (size_t i = 0; i < ba.size(); i++) 
			{
				fprintf(stdout,"\n");

				try         { fprintf (stdout, "\tInstance ID          : %s\n", ba[i].getInstanceID ().c_str ());}
				catch (...) { fprintf (stdout, "\tInstance ID          : %s\n", "N/A");}

				try
				{
					fprintf(stdout, "\tAttribute Name       : %s" ,ba[i].getAttributeName().c_str()); 
					fprintf (stdout, "\n");
				}
				catch (...) { fprintf(stdout, "\tAttribute Name          : %s\n","N/A"); }

				try {
					currentValues = ba[i].getCurrentValue();
					fprintf(stdout, "\t");
					displayVectorStr ("Current Value(s)     : ", currentValues, 3);
					fprintf (stdout, "\n");
				}
				catch (...) { fprintf(stdout, "\tCurrent Value(s)     : %s\n","N/A"); }

				try {
					defaultValues = ba[i].getDefaultValue();
					fprintf(stdout, "\t");
					displayVectorStr ("Default Value(s)     : ", defaultValues, 3);
					fprintf (stdout, "\n");
				}
				catch (...) { fprintf(stdout, "\tDefault Value(s)     : %s\n","N/A"); }
				try {
					vector<string> pendingValues = ba[i].getPendingValue();
					fprintf(stdout, "\t");
					displayVectorStr ("Pending Value(s)     : ", pendingValues, 3);
					fprintf (stdout, "\n");
				}
				catch (...) { fprintf(stdout, "\tPending Value(s)     : %s\n","N/A"); }

				try
				{ 
					vector<string> values = ba[i].getPossibleValues ();
					fprintf(stdout, "\t");
					displayVectorStr ("Possible Value(s)    : ", values, 3);
					fprintf (stdout, "\n");
				}
				catch (...) { }
				try
				{
					fprintf (stdout, "\tPossible Value(s)    : %llu - %llu\n", ba [i].getLowerBound (), ba [i].getUpperBound ());
				}
				catch (...) { }

				try
				{
					fprintf (stdout, "\tAllowed String Length: %llu - %llu\n", ba [i].getMinLength (), ba [i].getMaxLength ());
				}
				catch (...) { }
				try
				{
					fprintf (stdout, "\tString Type          : %s\n", ba [i].getStringTypeStr ().c_str ());
				}
				catch (...) { }

				try         { fprintf (stdout, "\tIsReadOnly           : %s\n", ba[i].isReadOnly ()?"True":"False");}
				catch (...) { fprintf (stdout, "\tIsReadOnly           : %s\n", "N/A");}

				try         { fprintf (stdout, "\tIsPasswordSet        : %s\n", ba[i].isPasswordSet ()?"True":"False");}
				catch (...) { }
				try         { fprintf (stdout, "\tPassword Encoding    : %s\n", ba[i].getPasswordEncodingStr ().c_str ());}
				catch (...) { }
				try         { fprintf (stdout, "\tIsOrderedList        : %s", ba[i].isOrderedList()?"True":"False");}
				catch (...) { fprintf (stdout, "\tIsOrderedList        : %s", "N/A");}
				if( i+1 < ba.size())
				{
					fprintf(stdout,"\n");
				}

			}
		}
		catch (...)
		{
			fprintf(stdout,"\nBIOS Attribute (s) : N/A");
		}
		
		return 0;
	}

	/*
	 * restoreDefaults 
	 */
	int restoreDefaults (IClient* client)
	{
		try
		{
			_be.restoreDefaults();
			fprintf (stdout, "Restored default BIOS successfully");
		}
		catch (exception &e)
		{
			fprintf (stderr, "Error: RestoreDefaults failed");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}

		return 0;
	}

	/*
	 * setAttribute
	 */
	int 
	setAttribute (IClient* client, vector<string> commands)
	{
		size_t count;

		if (commands.size() <3)
		{
			fprintf (stderr, "Invalid: Insufficient arguments");
			displayBIOSHelp (commands, 0);
			return -1;
		}

		/* get the attribute to set */
		vector <CBIOSAttribute> ba =  _be.getAttributes ();
		for (count = 0; count < ba.size(); count++)
		{
			if(ba[count].getAttributeName()== commands[1]) { break; }
		}

		if (count == ba.size())
		{
			fprintf (stderr, "Invalid: AttributeName");
			return -1;
		}

		vector <string> values;
		for (size_t i = 2; i < commands.size(); i++)
		{
			values.push_back (commands[i]);
		}

		try
		{
			ba[count].setAttribute(values);
			fprintf (stdout, "Sucess: SetAttributes");
		}
		catch (exception &e)
		{
			fprintf (stderr, "Error: SetAttribute failed");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
			
		return 0;
	}

private:
	CBIOSElement  _be;
};


/**
 * @class CBootConfigExec
 * @brief A boot config executer.
 */
class CBootConfigExec
{
public:
	/**
	 * Constructor
	 */
	CBootConfigExec (CBootConfig bc) : _bc (bc) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{

		if (commands.size () == 0)              { displayBootConfigHelp (commands, 0); return -1; }
		if (commands [0] == "show")             { return this->show (client); }
		if (commands [0] == "changebootorder")  { return this->changeOrder (client, commands); } 
		if (commands [0] == "delete")           { return this->deleteBootConfig (client); } 
		if (commands [0] == "setdefault")       { return this->setDefault (client); } 
		if (commands [0] == "setnext")          { return this->setNext (client); } 
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client) const
	{
		try         { fprintf (stdout, "Element Name             : %s\n", _bc.getElementName ().c_str ());}
		catch (...) { fprintf (stdout, "Element Name             : %s\n", "N/A");}
		try         { fprintf (stdout, "Instance ID              : %s\n", _bc.getInstanceID ().c_str ());}
		catch (...) { fprintf (stdout, "Instance ID              : %s\n", "N/A");}
		try         { fprintf (stdout, "Is Default Configuration : %s\n", _bc.isDefaultBoot () ? "Yes" : "No");}
		catch (...) { fprintf (stdout, "Is Default Configuration : %s\n", "N/A");}
		try         { fprintf (stdout, "Is Current Configuration : %s\n", _bc.isCurrentBoot () ? "Yes" : "No");}
		catch (...) { fprintf (stdout, "Is Current Configuration : %s\n", "N/A");}
		try         { fprintf (stdout, "Is Next Configuration    : %s\n", _bc.isNextBoot () ? "Yes" : "No");}
		catch (...) { fprintf (stdout, "Is Next Configuration    : %s\n", "N/A");}
		try
		{
			vector<CBootDevice> bootOrder = ((CBootConfigExec*)this)->_bc.getBootOrder ();

			fprintf (stdout, "Boot Device(s)           :");
			for (size_t i = 0; i < bootOrder.size (); i++)
			{
				fprintf (stdout, "\n");
				fprintf (stdout, "\tDevice %d         : ",	i);
				try { fprintf (stdout, "%s", bootOrder [i].getStructuredBootString().c_str ()); } 
				catch (...){fprintf (stdout, "N/A");}
			}
		}
		catch (...)
		{
			fprintf (stdout, "Boot Device(s)      :  N/A");
		}


		return 0;
	}

	/**
	 * Change boot order
	 */
	int changeOrder (IClient* client, vector<string> commands)
	{
		if (commands.size () < 2)
		{
			fprintf (stdout, "Errot : Invalid arguments");
			displayBootConfigHelp (commands, 0);
			return -1;
		}

		/* get the existing boot order */
		vector <CBootDevice> oldBootOrder = _bc.getBootOrder ();
		if (oldBootOrder.size () == 0)
		{
			fprintf (stderr, "Error :  No Boot device exist");
			return -1;
		}

		if ((commands.size () - 1) > oldBootOrder.size ())
		{
			fprintf (stderr, "Error : A boot device number specified is greater than the number of available devices");
			return -1;
		}

		/* sanity check */
		for (size_t i = 1; i < commands.size (); i++)
		{

			int boot_order;
			if (-1 == dashcli_strtol (commands [i].c_str (), (long*)&boot_order))
			{
				fprintf (stderr, "Error : Invalid boot order");
				return -1; 
			}

			if (boot_order >= (int)oldBootOrder.size ())
			{
				fprintf (stderr, "Error : Invalid boot order, device does not exist");
				return -1;
			}
		}

		vector <CBootDevice> newBootOrder;

		/* order the boot order as given from input */
		for (size_t i = 0; i < (commands.size () - 1); i++)
		{
			int boot_order;
			if (-1 == dashcli_strtol (commands [i + 1].c_str (), (long*)&boot_order))
			{
				fprintf (stderr, "Error : Invalid boot order");
				return -1; 
			}
			
			newBootOrder.push_back (oldBootOrder [boot_order]);
		}
		
		/* copy the remaining boot devices that are not given from the input */
		for (size_t i = 0; i < oldBootOrder.size (); i++)
		{
			size_t j;
			for (j = 1; j < commands.size (); j++)
			{
				/* check if we already copied this boot device */
				int boot_order;
				if (-1 == dashcli_strtol (commands [j].c_str (), (long*)&boot_order))
				{
					fprintf (stderr, "Error : Invalid boot order");
					return -1; 
				}

				if (i == (size_t)boot_order) break;
			}

			/* if we havent copied the device then copy it */
			if (j == commands.size ())
			{
				newBootOrder.push_back (oldBootOrder [i]);
			}
		}

		try
		{
/*			bool prop = false;
			vector<uint16> states = _bc.changeBootOrderSupport();
			for (size_t i =0; i < _bc.changeBootOrderSupport().size(); i++)
			{
				if(states[i] == 6)
				{
					prop = true;
				}
				
			}
			if (prop == false)
			{*/
			int status = _bc.changeBootOrder (newBootOrder); 
			if (0 == status)
			{
				fprintf (stdout, "Boot Order Changed Successfully");
			}
		//	}
		}
	/*	catch (ECIMError& e)
		{fprintf (stderr, "Error:Change Boot Order Method not supported");
		if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
		return -1;
		} */
		catch (exception &e)
		{
		fprintf (stderr, "Error: Change Boot Order failed");
		if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
		return -1;
		}

		return 0;
	}

	/**
	 * Delete boot configuration
	 */
	int deleteBootConfig (IClient* client)
	{
		try
		{
			this->_bc.deleteBootConfig ();
			fprintf (stdout, "Boot Config deleted Successfully");
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Deleting Boot Config failed");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}

		return 0;
	}

	/**
	 * Set default boot configuration
	 */
	int setDefault (IClient* client)
	{
		try
		{
			if (0 == this->_bc.setDefaultBoot ())
			{
				fprintf (stdout, "Set Default Boot Successfully");
			}
			else
			{
				fprintf (stderr, "Set Default Boot Failed");
			}
		}
		catch (exception& e)
		{
			fprintf (stderr, "Set Default Boot Failed");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}

		return 0;
	}

	/**
	 * Delete boot configuration
	 */
	int setNext (IClient* client)
	{
		try
		{
			if (0 == this->_bc.setNextBoot ())
			{
				fprintf (stdout, "Set Next Boot Successfully");
			}
			else
			{
				fprintf (stderr, "Set Next Boot Failed");
			}
		}
		catch (exception& e)
		{
			fprintf (stderr, "Set Next Boot Failed");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}

private:
	CBootConfig  _bc;
};


/**
 * @class CUserExec
 * @brief A user executer.
 */
class CUserExec
{
public:
	/**
	 * Constructor
	 */
	CUserExec (CUser user) : _user (user) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{
		if (commands.size () == 0)      { displayUserHelp (commands, 0); return -1; }
		if (commands [0] == "show")     { return this->show (client); }
		if (commands [0] == "changepassword") { return this->changepassword (commands); }
		if (commands [0] == "enable")   { return this->enableUser (commands); }
		if (commands [0] == "disable")  { return this->disableUser (commands); }
		if (commands [0] == "delete")   { return this->deleteUser (commands);  }
		if (commands [0] == "assignroles") { return this->assignRoles (commands); }
		if (commands [0] == "removeroles") { return this->removeRoles (commands); }

		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client) 
	{
		try         { fprintf (stdout, "Name                       : %s\n", _user.getName ().c_str ());}
		catch (...) { fprintf (stdout, "Name                       : %s\n", "N/A");}
		try         { fprintf (stdout, "User id                    : %s\n", _user.getUserID ().c_str ());}
		catch (...) { fprintf (stdout, "User id                    : %s\n", "N/A");}
		try         { fprintf (stdout, "Element Name               : %s\n", _user.getElementName ().c_str ());}
		catch (...) { fprintf (stdout, "Element Name               : %s\n", "N/A");}
		try 
		{
			vector<string> organizationName = _user.getOrganizationName ();
			displayVectorStr ("OrganizationName(s)        : ", organizationName, 4);
			fprintf (stdout, "\n");
		}

		catch(...)
		{
				fprintf(stdout,"OrganizationName(s)        : %s\n","N/A");
		}
		try         { fprintf (stdout, "EnabledState               : %s\n", _user.getEnabledStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "EnabledState               : %s\n", "N/A");}
		try         { fprintf (stdout, "RequestedState             : %s\n", _user.getRequestedStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "RequestedState             : %s\n", "N/A");}

		vector<CRole> role = _user.getUserRoles ();

		if (0 == role.size ())
		{
			fprintf (stdout, "Associated Role(s): N/A");
		}
		else
		{
			fprintf (stdout, "Associated Role (s)        : ");
			for (size_t i = 0; i < role.size (); i++)
			{
				fprintf (stdout, "%s", role [i].getElementName ().c_str ());
#if 0
				fprintf (stdout, "                             Privileges : ");
				vector<CRole::Permission_T> permissions = role [i].getPermissions ();
				for (size_t i = 0; i < permissions.size (); i++)
				{
					try { fprintf (stdout, "%s", permissions [i].instanceID.c_str ()); }
					catch (...) {}
					try {
						string qualifier = permissions [i].qualifier;
						if (qualifier.size () != 0)
						{
							fprintf (stdout, "(%s", qualifier.c_str ()); 
							string activity = permissions [i].activity_str;
							if (activity.size () != 0) { fprintf (stdout, "(%s)", activity.c_str ()); }
							fprintf (stdout, ")", qualifier.c_str ()); 
						}
					}
					catch (...) {}
					if (i != (permissions.size () - 1)) { fprintf (stdout, ",  "); }
					if (((i + 1) % 2) == 0)  { fprintf (stdout, "\n                                          ");}
				}
				fprintf (stdout, "\n");
#else
				if (i != (role.size () - 1)) { fprintf (stdout, ",  "); }
				if (((i + 1) % 3) == 0)
				{
					if ((i+1) != role.size ()) { fprintf (stdout, "\n                             ");}
				}
#endif
			}
		}

		return 0;
	}
	/**
	 * set password /Modify the password 
	 */

	int changepassword (vector<string> commands)
	{
			if (commands.size() < 2)
			{
				fprintf (stdout, "Error : Invalid arguments\n");
				fprintf (stdout, "Usage : changepassword <password>");
				return -1;
			}

			try 
			{
				this->_user.changePassword (commands[1]);
				fprintf (stdout, "User password changed Successfully");
			}
		
			catch (exception& e)
			{
				fprintf (stderr, "Error: Changing user password");
				if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
				return -1;
			}
		
			return 0;
	}

	/**
	 * enableUser 
	 */
	int enableUser (vector <string> commands)
	{
		try
		{
	/*		vector<uint16> states = this->_user.userSupport();
			if (states.size() != 0){ */
			this->_user.enableUser ();
			fprintf (stdout, "User Enabled Successfully");
			//}
			
		}
		/* catch (ECIMError& e)
		{
			fprintf (stderr, "Error:Requested State Method not supported");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		} */
		catch (exception& e)
		{
			fprintf (stderr, "Error: Enabling User");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}

	/**
	 * disableUser 
	 */
	int disableUser (vector <string> commands)
	{
		try
		{
		/*	vector<uint16> states = this->_user.userSupport();
			if (states.size() != 0){ */
				this->_user.disableUser ();
				fprintf (stdout, "User Disabled Successfully");
		}
	/*	}
		catch (ECIMError& e)
		{
			fprintf (stderr, "Error:User Disable Method not supported");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		} */
		catch (exception& e)
		{
			fprintf (stderr, "Error: Disabling User");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}

	/**
	 * deleteUser 
	 */
	int deleteUser (vector <string> commands)
	{
		try
		{
			this->_user.deleteUser ();
			fprintf (stdout, "User Deleted Successfully");
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Deleting User");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}

	int assignRoles (vector<string> commands)
	{
		if (commands.size () < 2)
		{
			fprintf (stderr, "Error: Invalid arguments");
			displayUserHelp (commands, 0);
			return -1;
		}

		try
		{
			vector<string> roles;
			for (size_t i = 1; i < commands.size (); i++)
			{
				roles.push_back (commands [i]);
			}
			this->_user.assignRoles (roles);
			fprintf (stdout, "Roles assigned Successfully");
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Assigning Roles");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}

	int removeRoles (vector<string> commands)
	{
		if (commands.size () < 2)
		{
			fprintf (stderr, "Error: Invalid arguments");
			displayUserHelp (commands, 0);
			return -1;
		}

		try
		{
			vector<string> roles;
			for (size_t i = 1; i < commands.size (); i++)
			{
				roles.push_back (commands [i]);
			}
			this->_user.removeRoles (roles);
			fprintf (stdout, "Roles removed Successfully");
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Removing Roles");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}

private:
	CUser  _user;
};


/**
 * @class CRoleExec
 * @brief A role executer.
 */
class CRoleExec
{
public:
	/**
	 * Constructor
	 */
	CRoleExec (CRole role) : _role (role) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{
		if (commands.size () == 0)      { displayRoleHelp (commands, 0); return -1; }
		if (commands [0] == "show")     { return this->show (client); }
		if (commands [0] == "delete")   { return this->deleteRole (commands);  }
		//if (commands [0] == "modify")   { return this->modifyRole (client,commands);  }
		if (commands [0] == "modify")   { return this->modifyRole (client,commands);  }
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client) 
	{

		try			{ fprintf (stdout, "Role Name   : %s     ", _role.getElementName ().c_str ()); }
		catch(...)	{ fprintf (stdout, "Role Name   : %s     ", "N/A"); }
		fprintf (stdout, "\nPrivileges  : ");

		vector<CRole::Permission_T> permissions = _role.getPermissions ();
		for (size_t i = 0; i < permissions.size (); i++)
		{
			try { fprintf (stdout, "%s", permissions [i].instanceID.c_str ()); }
			catch (...) {}
			try {
				string qualifier = permissions [i].qualifier;
				if (qualifier.size () != 0)
				{
					fprintf (stdout, "(%s", qualifier.c_str ()); 
					string activity = permissions [i].activity_str;
					if (activity.size () != 0) { fprintf (stdout, "(%s)", activity.c_str ()); }
					fprintf (stdout, ")", qualifier.c_str ()); 
				}
			}
			catch (...) {}
			if (i != (permissions.size () - 1)) { fprintf (stdout, ",    "); }
		}
		return 0;
	}
	/**
	 * deleteUser 
	 */
	int deleteRole (vector <string> commands)
	{
		try
		{
	/*		bool prop = false;
			vector<uint16> states = this->_role.roleSupport();
			for (size_t i =0; i < _role.roleSupport().size(); i++)
			{
				if(states[i] == 9)
				{
					prop = true;
				}
				
			} */
			vector<uint16> role_characteristices = this->_role.getRoleCharacteristics();
			displayVectorInt ("role_characteristices\t\t\t: ", role_characteristices, 4); 
			fprintf (stdout, "\n");
		 	// if (prop == true)
			// {
				this->_role.deleteRole ();
				fprintf (stdout, "Role Deleted Successfully");
			/* }
			else
			{
				fprintf (stdout, "Delete Role Method not Supported.");
			} */
		} /* catch (ECIMError& e)
		{
			fprintf (stderr, "Error:Delete Role Method not supported");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		} */ catch (exception& e)
		{
			fprintf (stderr, "Error: Deleting Role");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}

		return 0;
	}

	/**
	 * assignPermissions 
	 */ 
	int modifyRole (IClient*client,vector <string> commands)
	{
		if (commands.size () < 2)
		{
			fprintf (stderr, "Error: Invalid arguments");
			displayRoleHelp (commands, 0);
			return -1;
		}
		this->_role.displayPrivileges();
		_role.displayPermissions();
		string privilege;
		try
		{
			vector <CRole::Permission_T> permissions;
			if(commands [1] == "Append")
			{
				permissions = _role.getPermissions();				
				commands.erase(commands.begin()+1);
			}

			for (size_t i = 1; i < commands.size (); i++)
			{
				CRole::Permission_T permission;
				privilege = commands [i];
				/* seperate the activity */
				string activity = privilege.substr (0, privilege.find (','));
				if		(activity == "create") { permission.activity = CRole::Create; }
				else if (activity == "delete") { permission.activity = CRole::Delete; }
				else if (activity == "detect") { permission.activity = CRole::Detect; }
				else if (activity == "read")   { permission.activity = CRole::Read;   }
				else if (activity == "write")  { permission.activity = CRole::Write;  }
				else if (activity == "execute"){ permission.activity = CRole::Execute;}
				else if (activity == "other")  { permission.activity = CRole::Other;  }
				else 
				{
					fprintf (stderr, "Invalid activity \" %s \" specified\n", activity.c_str ());
					fprintf (stderr, "Should be one of these\n create|delete|detect|read|write|execute|other");
					return -1;
				}

				if ((size_t)-1 == privilege.find (','))
				{
					fprintf (stderr, "Qualifier missing, should be specified, seperated by comma in the permission");
					return -1;
				}

				/*for (size_t i = 0; i < permissions.size (); i++)
				{
					fprintf(stdout, "permissions: %s",permissions[i].elementName.c_str());
					permissions.push_back (permissions [i]);
				}*/
				permission.qualifier = privilege.substr (privilege.find (',') + 1, privilege.size ());
				//permission.qualifier = privilege;
				permissions.push_back (permission);
			}

			this->_role.modifyRole (client,privilege,permissions);

			fprintf (stdout, "Assigned permission Successfully");
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Assigning permission");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}

private:
	CRole  _role;
};

/**
 * @class CTextRedirectionExec
 * @brief A text redirection executer.
 */
class CTextRedirectionExec
{
public:
	/**
	 * Constructor
	 */
	CTextRedirectionExec (CTextRedirection textr) : _textr (textr) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{

		if (commands.size () == 0)              { displayTextRedirectionHelp (commands, 0); return -1; }
		if (commands [0] == "show")             { return this->show (client); }
		if (commands [0] == "activate")         { return this->activate (client); }
		if (commands [0] == "disable")          { return this->disable (client); }
		if (commands [0] == "start")            { return this->start (client); }
		if (commands [0] == "MaxEnabledSAPs")   { return this->enabledSAPs (client); }
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client) 
	{
		try         { fprintf (stdout, "Name                    : %s\n", _textr.getName ().c_str ());}
		catch (...) { fprintf (stdout, "Name                    : %s\n", "N/A");}
		try         { fprintf (stdout, "Element Name            : %s\n", _textr.getElementName ().c_str ());}
		catch (...) { fprintf (stdout, "Element Name            : %s\n", "N/A");}
		try         { fprintf (stdout, "EnabledState            : %s\n", _textr.getEnabledStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "EnabledState            : %s\n", "N/A");}
		try         { fprintf (stdout, "RequestedState          : %s\n", _textr.getRequestedStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "RequestedState          : %s\n", "N/A");}
		try         { fprintf (stdout, "Protocol Type           : %s\n", _textr.getProtocolIFType ().c_str ());}
		catch (...) { fprintf (stdout, "Protocol Type           : %s\n", "N/A");}
		try         { fprintf (stdout, "Port Number             : %lu\n", _textr.getPortNumber ());}
		catch (...) { fprintf (stdout, "Port Number             : %s\n", "N/A");}
		try         { fprintf (stdout, "Termination Sequence    : %s\n", _textr.getTerminationSequence ().c_str ());}
		catch (...) { fprintf (stdout, "Termination Sequence    : %s\n", "N/A");}
		try         { fprintf (stdout, "Text Flow Type          : %s", _textr.getTextFlowType ().c_str ());}
		catch (...) { fprintf (stdout, "Text Flow Type          : %s", "N/A");}
		
		return 0;
	}

	/**
	 * activate
	 */
	int activate (IClient* client) const
	{
		try
		{
			_textr.activate ();
			fprintf (stdout, "Session activated successfully");
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Activating Session");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}

	/**
	 * disable
	 */
	int disable (IClient* client) const
	{
		try
		{
			_textr.disable ();
			fprintf (stdout, "Session disabled successfully");
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Disabling Session");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}

	/**
	 * start
	 */
	int start (IClient* client) 
	{
		try
		{
			if (-1 == _textr.startRedirection ())
			{
				fprintf (stderr, "Error: Starting redirection session");
				return -1;
			}
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Starting redirection session");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}
	
	/**
	 * MaxCurrentEnabledSAPs
	 */
	int enabledSAPs (IClient* client) const
	{
		try
		{
			fprintf (stdout, "Maximum Number of Sessions Supported =\t%d",_textr.getMaxCurrentEnabledSAPs());
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Maximum Number of Sessions Supported not found");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}

private:
	CTextRedirection  _textr;
};


/**
 * @class CUSBRedirectionExec
 * @brief A usb redirection executer.
 */
class CUSBRedirectionExec
{
public:
	/**
	 * Constructor
	 */
	CUSBRedirectionExec (CUSBRedirection usbr) : _usbr (usbr) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{

		if (commands.size () == 0)              { displayUsbRedirectionHelp (commands, 0); return -1; }
		if (commands [0] == "show")             { return this->show (client); }
		if (commands [0] == "activate")         { return this->activate (client); }
		if (commands [0] == "disable")          { return this->disable (client); }
		// if (commands [0] == "listlocaldrives")  { return this->getLocalDrives (client); }
		if (commands [0] == "startvmr")         { return this->startVMR (client, options, commands); }
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client) const
	{
		
		try         { fprintf (stdout, "Redirection Name          : %s\n", _usbr.getName ().c_str ());}
		catch (...) { fprintf (stdout, "Redirection Name          : %s\n", "N/A");}

		try         { fprintf (stdout, "SystemCreationClassName   : %s\n", _usbr.getSystemCreationClassName ().c_str ());}
		catch (...) { fprintf (stdout, "SystemCreationClassName   : %s\n", "N/A");}

		try         { fprintf (stdout, "SystemName                : %s\n", _usbr.getSystemName ().c_str ());}
		catch (...) { fprintf (stdout, "SystemName                : %s\n", "N/A");}

		try         { fprintf (stdout, "CreationClassName         : %s\n", _usbr.getCreationClassName ().c_str ());}
		catch (...) { fprintf (stdout, "CreationClassName         : %s\n", "N/A");}

		try         { fprintf (stdout, "Element Name              : %s\n", _usbr.getElementName ().c_str ());}
		catch (...) { fprintf (stdout, "Element Name              : %s\n", "N/A");}

		try         { fprintf (stdout, "EnabledState              : %s\n", _usbr.getEnabledStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "EnabledState              : %s\n", "N/A");}

		try         { fprintf (stdout, "RequestedState            : %s\n", _usbr.getRequestedStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "RequestedState            : %s\n", "N/A");}

		try         { fprintf (stdout, "Connection Mode           : %s", _usbr.getConnectionMode ().c_str ());}
		catch (...) { fprintf (stdout, "Connection Mode           : %s", "N/A");}

		return 0;
	}

	int disable (IClient* cleint)
	{
		try 
		{
			_usbr.disable ();
		}
		catch (exception& e) 
		{
			fprintf (stderr, "Error Enabling Media redirection");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}

		return 0;
	}

		/**
	 * activate
	 */
	int activate (IClient* client) 
	{
		try
		{
			_usbr.activate ();
			fprintf (stdout, "Session activated successfully");
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Activating Session");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}

	//int getLocalDrives (IClient* cleint)
	//{
	//	vector<string> drives = CVirtualMedia::getLocalDrives ();
	//	for (size_t i = 0; i < drives.size (); i++)
	//	{
	//		fprintf (stdout, "%s", drives [i].c_str ());
	//		if (i+1 != drives.size ()) { fprintf (stdout, "\n"); }
	//	}
	//	return 0;
	//}

	int startVMR (IClient* client, const CCmdOption& options, vector<string> commands)
	{

	//	CVirtualMedia* vm;

		/*if (commands.size () < 3)
		{
			fprintf (stderr, "Missing arguments\n");
			displayUsbRedirectionHelp (commands, 0);
			return -1;
		}*/

	//	if (commands [1] == "samba" || commands [1] == "nfs")
	//	{
			if (_usbr.getConnectionMode () != "Connect")
			{
				fprintf (stderr, "%s redirection type is not supported for this USB redirection session\n", commands [1].c_str ());
				fprintf (stderr, "%s is supported only if connection mode type is 'Connect'\n", commands [1].c_str ());
				fprintf (stderr, "%s supported redirection type for this USB Redirection session are 'image' and 'drive'", commands [1].c_str ());
				return -1;
			}

			try 
			{
				_usbr.startFolderRedirection(commands[1],commands[2]);
				 fprintf(stdout,"\nUSB Redirection Configuration has been successfully completed.\n");
			}
			catch (EFunctionNotSupported &e)
			{
				fprintf (stderr, "\nError: USB Redirection not Supported.");
				if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
				return -1;		
			
			}catch (EFunctionReturnedWithFailure &e)
			{
				fprintf (stderr, "\nError: Failure returned for USB Redirection.");
				if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
				return -1;		
			}catch (exception& e) 
			{
				fprintf (stderr, "\nError: starting Media redirection %s",e.what ());
				if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
				return -1;
			}

			/* continue redirecting media till 'Q' key is hit */
			/*int ch;
			while ((ch = getchar ()))
			{
				if ((ch == 'q') || (ch == 'Q'))
				{
					_usbr.disable ();
					return 0;
				}
			}

			return 0;
		}
		else if ((commands [1] == "image") || (commands [1] == "drive"))
		{*/

		//	if (_usbr.getConnectionMode () != "Listen")
		//	{
		//		fprintf (stderr, "%s redirection type is not supported for this USB redirection session\n", commands [1].c_str ());
		//		fprintf (stderr, "%s is supported only if connection mode type is 'Listen'\n", commands [1].c_str ());
		//		fprintf (stderr, "%s supported redirection type for this USB Redirection session are 'samba' and 'nfs'", commands [1].c_str ());
		//		return -1;
		//	}

		//	CVirtualMedia::RedirectionType_E type;
		//	if (commands [1] == "image") { type = CVirtualMedia::IMAGE; }
		//	else						 { type = CVirtualMedia::DRIVE; }

	/*		vm = new CVirtualMedia (options._host, 4443, options._authtype, options._user, options._password, 
									commands [2], type, false, false);*/

		//	fprintf (stdout, "Press 'Q' & 'Enter' at any time to stop media redirection:\nPress 'Enter' key to start the redirection....\n");
		//	getchar ();

		//	try {
		//		vm->startRedirection ();
		//	}
		//	catch (exception& e)
		//	{
		//		fprintf (stderr, "Error starting Media redirection");
		//		if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
		//		return -1;
		//	}

		//	/* continue redirecting media till 'Q' key is hit */
		//	int ch;
		//	while ((ch = getchar ()))
		//	{
		//		if ((ch == 'q') || (ch == 'Q'))
		//		{
		//			vm->stopRedirection ();
		//			return 0;
		//		}
		//	}
		//}
		//else
		//{
		//	fprintf (stderr, "Invalid redirection type\n");
		//	fprintf (stderr, "Valid types: image|drive|samba|nfs");
		//	return -1;
		//}

		return 0;
	}

private:
	CUSBRedirection  _usbr;
};

/**
 * @class COpaqueManagementDataExec
 * @brief A OpaqueManagementData executer.
 */
class COpaqueManagementDataExec
{
public:
	/**
	 * Constructor
	 */
	COpaqueManagementDataExec (COpaqueManagementData omd) : _omd (omd) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{

		if (commands.size () == 0)            { displayOpaqueManagementDataHelp (commands, 0); return -1; }
		if (commands [0] == "show")           { return this->show (client); }
		if (commands [0] == "write")          { return this->writeData(client,commands);}
		if (commands [0] == "importfromuri")  { return this->importData(client,commands);}
		if (commands [0] == "read" )          { return this->readData(client,commands);}
		if (commands [0] == "exportfromuri")  { return this->exportData(client,commands);}
		if (commands [0] == "delete" )        { return this->deleteOpaquemanagementdata();}
		if (commands [0] == "lock" )          { return this->lockOpaquemanagementdata(client,commands);}
		if (commands [0] == "reassignowner")  { return this->newOwnerOpaquemanagementdata(client,commands);}
		if (commands [0] == "assignaccess" )  { return this->assignAccessOpaquemanagementdata(client,commands);}
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client)
	{
		try         { fprintf (stdout, "ElementName             : %s\n", _omd.getElementName ().c_str ());}
		catch (...) { fprintf (stdout, "ElementName             : %s\n", "N/A");}

		try         { fprintf (stdout, "DeviceID                : %s\n", _omd.getDeviceID ().c_str ());}
		catch (...) { fprintf (stdout, "DeviceID                : %s\n", "N/A");}

		try         { fprintf (stdout, "OwnerName               : %s\n", _omd.getOwnerName ().c_str ());}
		catch (...) { fprintf (stdout, "OwnerName               : %s\n", "N/A");}

		/*try         { fprintf (stdout, "TransformedDataSize     : %llu\n", _omd.getTransformedDataSize ());}
		catch (...) { fprintf (stdout, "TransformedDataSize     : %s\n", "N/A");}*/

		try         { 
			uint64 size = _omd.getMaxSize ();
			if ((size / (1024 * 1024)) >= 1024)
			{
				fprintf (stdout, "MaxSize                 : %llu MB\n", (size / (1024 * 1024)));
			}
			else if ((size / 1024) >= 1024)
			{
				fprintf (stdout, "MaxSize                 : %llu KB\n", (size / 1024));
			}
			else
			{
				fprintf (stdout, "MaxSize                 : %llu Bytes\n", size);
			}

		}
		catch (...) { fprintf (stdout, "MaxSize                 : %s\n", "N/A");}

		//Not supported in schema v 2.22
		//try         { fprintf (stdout, "UntransformedDataFormat : %s\n", _omd.getUntransformedDataFormat ().c_str ());}
		//catch (...) { fprintf (stdout, "UntransformedDataFormat : %s\n", "N/A");}

		//try {
		//	/*vector <uint16> transformations = _omd.getTransformations ();
		//	displayVectorInt ("Transformations        : ", transformations, 4);*/
		//	fprintf (stdout, "\n");
		//}
		//catch (...)
		//{
		//	fprintf (stdout, "Transformations         : %s\n", "N/A");
		//}

		//try {
		//	/*vector <string> transformationKeyIDs = _omd.getTransformationKeyIDs ();
		//	displayVectorStr ("TransformationKeyIDs    : ", transformationKeyIDs, 4);*/
		//	fprintf (stdout, "\n");
		//}
		//catch (...)
		//{
		//	fprintf (stdout, "TransformationKeyIDs    : %s\n", "N/A");
		//}

		try         { fprintf (stdout, "WriteLimited            : %d\n", _omd.getWriteLimited ());}
		catch (...) { fprintf (stdout, "WriteLimited            : %s\n", "N/A");}

		try         { fprintf (stdout, "DataOrganization        : %d\n", _omd.getDataOrganization ());}
		catch (...) { fprintf (stdout, "DataOrganization        : %s\n", "N/A");}

		try         { fprintf (stdout, "Access                  : %d\n", _omd.getAccess ());}
		catch (...) { fprintf (stdout, "Access                  : %s\n", "N/A");}

		try         { fprintf (stdout, "NumberOfBlocks          : %llu	\n", _omd.getNumberOfBlocks());}
		catch (...) { fprintf (stdout, "NumberOfBlocks          : %s\n", "N/A");}
		
		try         { fprintf (stdout, "BlockSize               : %llu\n", _omd.getBlockSize ());}
		catch (...) { fprintf (stdout, "BlockSize               : %s\n", "N/A");}

		try         { fprintf (stdout, "ConsumableBlocks        : %llu\n", _omd.getConsumableBlocks ());}
		catch (...) { fprintf (stdout, "ConsumableBlocks        : %s\n", "N/A");}

		try         { fprintf (stdout, "SystemCreationClassName : %s\n", _omd.getSystemCreationClassName ().c_str());}
		catch (...) { fprintf (stdout, "SystemCreationClassName : %s\n", "N/A");}

		try         { fprintf (stdout, "SystemName              : %s\n", _omd.getSystemName ().c_str());}
		catch (...) { fprintf (stdout, "SystemName              : %s\n", "N/A");}

		try         { fprintf (stdout, "CreationClassName       : %s", _omd.getCreationClassName ().c_str());}
		catch (...) { fprintf (stdout, "CreationClassName       : %s", "N/A");}

		return 0;
	}

	/*
	 * readData
	 */
	int readData (IClient* client, vector<string> commands)
	{
		uint64			offset = 0;
		uint64			length = 0;		
		string data;
		vector <uint8>	lock;

		if (commands.size() == 1)
		{
			displayOpaqueManagementDataHelp (commands, 0);
			return -1;
		}
		if ((commands.size() > 1) && (commands.size() < 3 ||  commands.size() > 4))
		{
			fprintf (stderr, "Invalid: Insufficient arguments\n\n");
			fprintf (stdout, "----Check the Help Below----\n\n");
			displayOpaqueManagementDataHelp (commands, 0);
			return -1;
		}		

		if (-1 == dashcli_strtol (commands[1].c_str(), &val))
		{
			fprintf (stderr, "Invalid offset %s", commands [1].c_str ());
			return -1; 
		}
		
		offset = (uint64) val;

		if (-1 == dashcli_strtol (commands[2].c_str(), &val))
		{
			fprintf (stderr, "Invalid length %s", commands [2].c_str ());
			return -1; 
		}
		
		length = (uint64) val;
		if (commands.size() > 3)
		{
			int datatowrite;
			if (-1 == dashcli_strtol_hex (commands[3].c_str(), (long*)&datatowrite))
			{
				fprintf (stderr, "Invalid data %s", commands [3].c_str ());
				return -1; 
			}				
			lock.push_back ((uint8)datatowrite);			
		}
		try
		{
			/* read the data */
			if (0 == _omd.readData (offset,&length,&data ,&lock))
			{
				fprintf (stdout, "Data read :\n");
				fprintf (stdout, "%s",data.c_str());				
			}
			
			else
			{
				fprintf (stderr, "Error: Reading data");
			}
		}
		catch (exception &e)
		{
			fprintf (stderr, "Error: Reading data");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}

		return 0;
	}

	/* 
	 * writeData
	 */
	int writeData (IClient* client, vector<string> commands)
	{
		uint64			offset = 0;		
		vector <uint8>	lock;


		if (commands.size() == 1)
		{
			displayOpaqueManagementDataHelp (commands, 0);
			return -1;
		}
		if ((commands.size() > 1) && (commands.size() < 3))
		{
			fprintf (stderr, "Invalid: Insufficient arguments\n\n");
			fprintf (stdout, "----Check the Help Below----\n\n");
			displayOpaqueManagementDataHelp (commands, 0);
			return -1;
		}
		if (-1 == dashcli_strtol (commands[1].c_str(), &val))
		{
			fprintf (stderr, "Invalid offset %s", commands [1].c_str ());
			return -1; 
		}

		offset = (uint64) val;
		if (commands.size() > 3)
		{
			int datatowrite;
			if (-1 == dashcli_strtol_hex (commands[3].c_str(), (long*)&datatowrite))
			{
				fprintf (stderr, "Invalid data %s", commands [3].c_str ());
				return -1; 
			}				
			lock.push_back ((uint8)datatowrite);
			
		}    

		try
		{
			if (0 == _omd.writeData (offset, commands[2], &lock))
			{
				fprintf (stdout, "Data written successfully");
			}
			else
			{
				fprintf (stderr, "Error: Writing data");
			}
		}
		catch (exception &e)
		{
			fprintf (stderr, "Error: Writing data");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}

		return 0;
	}

	/**
	 * deleteOpaquemanagementdata
	 */
	int deleteOpaquemanagementdata ()
	{
		try
		{
			this->_omd.deleteData ();
			fprintf (stdout, "Opaquemanagementdata Deleted Successfully");
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Deleting Opaquemanagementdata");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}
	
	/**
	 * importData
	 */
	int importData (IClient* client, vector<string> commands)
	{
		uint64			offset = 0;
		uint64			length = 0;			

		if (commands.size() < 2)
		{
			fprintf (stderr, "Invalid: Insufficient arguments\n\n");
			displayOpaqueManagementDataHelp (commands, 0);
			return -1;
		}

		if (-1 == dashcli_strtol (commands[1].c_str(), &val))
		{
			fprintf (stderr, "Invalid offset %s", commands [1].c_str ());
			return -1; 
		}

		offset = (uint64) val;
		
		if (-1 == dashcli_strtol (commands[2].c_str(), &val))
		{
			fprintf (stderr, "Invalid length %s", commands [2].c_str ());
			return -1; 
		}

		length = (uint64) val;

		try
		{
			if (0 == _omd.importData (offset, &length, commands[3]))
			{
				fprintf (stdout, "Data written successfully from URI");
			}
			else
			{
				fprintf (stderr, "Error: Importing from URI data\n");
			}
		}
		catch (exception &e)
		{
			fprintf (stderr, "Error: Importing from URI data\n");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}

		return 0;
	}

	/**
	 * exportData
	 */
	int exportData (IClient* client, vector<string> commands)
	{
		uint64			offset = 0;
		uint64			length = 0;			

		if (commands.size() < 2)
		{
			fprintf (stderr, "Invalid: Insufficient arguments\n\n");
			displayOpaqueManagementDataHelp (commands, 0);
			return -1;
		}

		if (-1 == dashcli_strtol (commands[1].c_str(), &val))
		{
			fprintf (stderr, "\nInvalid offset %s", commands [1].c_str ());
			return -1; 
		}

		offset = (uint64) val;
		
		if (-1 == dashcli_strtol (commands[2].c_str(), &val))
		{
			fprintf (stderr, "\nInvalid length %s", commands [2].c_str ());
			return -1; 
		}

		length = (uint64) val;

		try
		{
			if (0 == _omd.exportData (offset, &length, commands[3]))
			{
				fprintf (stdout, "Data written successfully to URI");
			}
			else
			{
				fprintf (stderr, "Error: Export from URI data\n");
			}
		}
		catch (exception &e)
		{
			fprintf (stderr, "Error: Export from URI data\n\n");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}

		return 0;
	}
	

	/**
	 * lockOpaquemanagementdata
	 */
	int lockOpaquemanagementdata (IClient* client, vector<string> commands)
	{
		boolean bLock = true;
		vector<uint8> lockTocken;
		if (commands.size() < 2)
		{
			fprintf (stderr, "Invalid: Insufficient arguments\n\n");
			displayOpaqueManagementDataHelp (commands, 0);
			return -1;
		}

		if (!strcasecmp(commands[1].c_str(), "true")) { 
			bLock = true;
		}
		if (!strcasecmp(commands[1].c_str(), "false")) { 
			bLock = false;
		}
		
		try
		{
			if (0 == _omd.lockData (bLock,&lockTocken))
			{
				fprintf (stdout, "Locked Successfull");
				fprintf (stdout, "Lock Tocken:");
				for ( size_t j=0 ;j < lockTocken.size();j++)
				{
					fprintf (stdout, "%s",lockTocken[j]);
				}
			}
			else
			{
				fprintf (stderr, "Error: Locking data\n");
			}
		}
		catch (exception &e)
		{
			fprintf (stderr, "Error: Locking data\n");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}

		return 0;
	}		

	/**
	 * newOwnerOpaquemanagementdata
	 */
	int newOwnerOpaquemanagementdata (IClient* client, vector<string> commands)
	{
		if (commands.size() < 2)
		{
			fprintf (stderr, "Invalid: Insufficient arguments\n\n");
			displayOpaqueManagementDataHelp (commands, 0);
			return -1;
		}
		
		try
		{
			if (0 == _omd.changeOwner (commands[1]))
			{
				fprintf (stdout, "Reassigning Ownership Successfull\n\n");
			}
			else
			{
				fprintf (stderr, "Error: Re-assigning  Owner\n\n");
			}
			
		}
		catch (exception &e)
		{
			fprintf (stderr, "Error: Re-assigning  Owner\n\n");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}
	
	/**
	 * newOwnerOpaquemanagementdata
	 */
	int assignAccessOpaquemanagementdata (IClient* client, vector<string> commands)
	{
		vector <uint16>	activities;		
		if (commands.size() == 1)
		{
			displayOpaqueManagementDataHelp (commands, 0);
			return -1;
		}
		if ((commands.size() > 1) && (commands.size() < 3))
		{
			fprintf (stderr, "Invalid: Insufficient arguments\n\n");
			fprintf (stdout, "----Check the Help Below----\n\n");
			displayOpaqueManagementDataHelp (commands, 0);
			return -1;
		}
		for (size_t i = 2; i < commands.size(); i++)
		{
			std::transform(commands[i].begin(), commands[i].end(), commands[i].begin(), ::toupper);
			if(commands[i] == "READ") { activities.push_back(5); }
			if(commands[i] == "WRITE") { activities.push_back(6); }
		}
		
		try
		{
			if(0 == _omd.assignAccess (commands[1],activities))
			{
				fprintf (stdout, "Assigning Access Successfull");
			}
			else
			{
				fprintf (stderr, "Error: Assigning Access\n\n");
			}
			
		}
		catch (exception &e)
		{
			fprintf (stderr, "Error: Assigning Access\n\n");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}

	

private:
	COpaqueManagementData  _omd;
};

/**
 * @class CBatteryExec
 * @brief A Battery executer.
 */
class CBatteryExec
{
public:
	/**
	 * Constructor
	 */
	CBatteryExec (CBattery bat) : _bat (bat) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{

		if (commands.size () == 0)				{ displayBatteryHelp (commands, 0); return -1; }
		if (commands [0] == "show")				{ return this->show (client); }
		if (commands [0] == "enable")			{ return this->enable (client); }
		if (commands [0] == "disable")			{ return this->disable (client); }
		if (commands [0] == "test")				{ return this->test (client); }
		if (commands [0] == "recharge")         { return this->recharge (client); }
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client)
	{
		try			{ fprintf (stdout, "Element Name          : %s\n", _bat.getElementName ().c_str ()); }
		catch (...) { fprintf (stdout, "Element Name          : %s\n", "N/A"); }
		try         { fprintf (stdout, "DeviceID              : %s\n", _bat.getDeviceID ().c_str ());}
		catch (...) { fprintf (stdout, "DeviceID              : %s\n", "N/A");}
		try         { fprintf (stdout, "BatteryStatus         : %s\n", _bat.getBatteryStatusStr ().c_str ());}
		catch (...) { fprintf (stdout, "BatteryStatus         : %s\n", "N/A");}
		try	{
			vector<string> status = _bat.getOperationalStatusStr (); 
			displayVectorStr ("OperationalState      : ", status, 4);
			fprintf (stdout, "\n");
		}
		catch (...) { fprintf (stdout, "OperationalState      : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Health State          : %s\n", _bat.getHealthStateStr ().c_str ());	}
		catch (...) { fprintf (stdout, "Health State          : %s\n", "N/A");	}
		try			{ fprintf (stdout, "Enabled State         : %s\n", _bat.getEnabledStateStr ().c_str ()); }
		catch (...) { fprintf (stdout, "Enabled State         : %s\n", "N/A"); }
		try			{ fprintf (stdout, "Requested State       : %s\n", _bat.getRequestedStateStr ().c_str ()); }
		catch (...) { fprintf (stdout, "Requested State       : %s\n", "N/A"); }
		try         { fprintf (stdout, "Chemistry             : %d\n", _bat.getChemistry ());}
		catch (...) { fprintf (stdout, "Chemistry             : %s\n", "N/A");}
		try         { fprintf (stdout, "Max Recharge Count    : %ld\n", _bat.getMaxRechargeCount ());}
		catch (...) { fprintf (stdout, "Max Recharge Count    : %s\n", "N/A");}
		try         { fprintf (stdout, "Recharge Count        : %ld\n", _bat.getRechargeCount ());}
		catch (...) { fprintf (stdout, "Recharge Count        : %s\n", "N/A");}
		try         { fprintf (stdout, "Expected Life         : %ld\n", _bat.getExpectedLife ());}
		catch (...) { fprintf (stdout, "Expected Life         : %s\n", "N/A");}
		try         { fprintf (stdout, "Estimated Run Time    : %ld\n", _bat.getEstimatedRunTime ());}
		catch (...) { fprintf (stdout, "EstimatedRunTime      : %s\n", "N/A");}
		try         { fprintf (stdout, "Time To Full Recharge : %ld\n", _bat.getTimeToFullCharge ());}
		catch (...) { fprintf (stdout, "Time To Full Recharge : %s\n", "N/A");}
		try         { fprintf (stdout, "Max Recharge Time     : %ld", _bat.getMaxRechargeTime ());}
		catch (...) { fprintf (stdout, "Max Recharge Time     : %s", "N/A");}
		
		return 0;
	}

	/**
	 * enable
	 */
	int enable (IClient* client) const
	{
		try
		{	
//			vector<uint16> states = _bat.requestedStateSupport();
//			if (states.size() != 0)
//			{
				_bat.enable ();
				fprintf (stdout, "Battery Enabled successfully");	
				return 0;
//			}
			
		}
		catch (ECIMError& e) {
			
				fprintf (stderr, "\nMethod not supported.%s",e.what());
				if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
				
				
		}
	/*	catch (exception& e)
		{
			fprintf (stderr, "\nError: Enable Battery %s",e.what ());
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		} */

		return 0;
		
	}

	/**
	 * disable
	 */
	int disable (IClient* client) const
	{
		try
		{
			_bat.disable ();
			fprintf (stdout, "Battery Disabled successfully");
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Disable Battery");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}

	/**
	 * test
	 */
	int test (IClient* client) const
	{
		try
		{
			_bat.test ();
			fprintf (stdout, "Battery Test successfully");
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Test Battery");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}

	/**
	 * recharge
	 */
	int recharge (IClient* client) const
	{
		try
		{
			_bat.reset ();
			fprintf (stdout, "Battery recharge successfully");
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Recharge Battery");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}

private:
	CBattery  _bat;
};

/**
 * @class CNetworkPortExec
 * @brief A NetworkPort executer.
 */
class CNetworkPortExec
{
public:
	/**
	 * Constructor
	 */
	CNetworkPortExec (CNetworkPort np) : _np (np) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{

		if (commands.size () == 0)          { displayNetworkPortHelp (commands, 0); return -1; }
		if (commands [0] == "show")         { return this->show (client); }
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client)
	{
		try         { fprintf (stdout, "Name                       : %s\n", _np.getName ().c_str());}
		catch (...) { fprintf (stdout, "Name                       : %s\n", "N/A");}
		try         { fprintf (stdout, "Element Name               : %s\n", _np.getElementName ().c_str());}
		catch (...) { fprintf (stdout, "Element Name               : %s\n", "N/A");}
		try         { fprintf (stdout, "DeviceID                   : %s\n", _np.getDeviceID ().c_str ());}
		catch (...) { fprintf (stdout, "DeviceID                   : %s\n", "N/A");}
		try         { fprintf (stdout, "Speed                      : %llu Gbps\n", (_np.getSpeed () / (1000 * 1000 * 1000)));}
		catch (...) { fprintf (stdout, "Speed                      : %s\n", "N/A");}
		try         { fprintf (stdout, "Maximum Speed              : %llu Gbps\n", (_np.getMaxSpeed () / (1000 * 1000 * 1000)));}
		catch (...) { fprintf (stdout, "Maximum Speed              : %s\n", "N/A");}
		try         { fprintf (stdout, "Requested Speed            : %llu Gbps\n", (_np.getRequestedSpeed () / (1000 * 1000 * 1000)));}
		catch (...) { fprintf (stdout, "Requested Speed            : %s\n", "N/A");}
		try         { fprintf (stdout, "Link Technology            : %s\n", _np.getLinkTechnologyStr ().c_str ());}
		catch (...) { fprintf (stdout, "Link Technology            : %s\n", "N/A");}
		try         { fprintf (stdout, "MAC Address                : %s\n", _np.getPermanentAddress ().c_str());}
		catch (...) { fprintf (stdout, "MAC Address                : %s\n", "N/A");}
		try         { fprintf (stdout, "Enabled State              : %s\n", _np.getEnabledStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "Enabled State              : %s\n", "N/A");}
		try         { fprintf (stdout, "Requested State            : %s", _np.getRequestedStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "Requested State            : %s", "N/A");}
		
		return 0;
	}
private:
	CNetworkPort  _np;
};

/**
 * @class CDHCPClient
 * @brief A CDHCPClient executer.
 */
class CDHCPClientExec
{
public:
	/**
	 * Constructor
	 */
	CDHCPClientExec (CDHCPClient dhcp) : _dhcp (dhcp) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{

		if (commands.size () == 0)          { displayDHCPClientHelp (commands, 0); return -1; }
		if (commands [0] == "show")         { return this->show (client); }
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client)
	{
		try         { fprintf (stdout, "Name                        : %s\n", _dhcp.getName ().c_str ());}
		catch (...) { fprintf (stdout, "Name                        : %s\n", "N/A");}
		try         { fprintf (stdout, "Element Name                : %s\n", _dhcp.getElementName().c_str ());}
		catch (...) { fprintf (stdout, "Element Name                : %s\n", "N/A");}
		try         { fprintf (stdout, "Name Format                 : %s\n", _dhcp.getNameFormat().c_str ());}
		catch (...) { fprintf (stdout, "Name Format                 : %s\n", "N/A");}
		try         { fprintf (stdout, "Protocol IF Type            : %s\n", _dhcp.getProtocolIFTypeStr ().c_str ());}
		catch (...) { fprintf (stdout, "Protocol IF Type            : %s\n", "N/A");}
		try         { fprintf (stdout, "Requested State             : %s\n", _dhcp.getRequestedStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "Requested State             : %s\n", "N/A");}
		try         { fprintf (stdout, "Enabled State               : %s\n", _dhcp.getEnabledStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "Enabled State               : %s\n", "N/A");}
		try         { fprintf (stdout, "Client State                : %s", _dhcp.getClientState().c_str ());}
		catch (...) { fprintf (stdout, "Client State                : %s", "N/A");}
		
		return 0;
	}
private:
	CDHCPClient  _dhcp;
};

/**
 * @class CIPInterface
 * @brief A CIPInterface executer.
 */
class CIPInterfaceExec
{
public:
	/**
	 * Constructor
	 */
	CIPInterfaceExec (CIPInterface IP) : _IP (IP) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{

		if (commands.size () == 0)          { displayIPInterfaceHelp (commands, 0); return -1; }
		if (commands [0] == "show")         { return this->show (client); }
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client)
	{
		try         { fprintf (stdout, "Name                      : %s\n", _IP.getName ().c_str());}
		catch (...) { fprintf (stdout, "Name                      : %s\n", "N/A");}
		try         { fprintf (stdout, "Element Name              : %s\n", _IP.getElementName().c_str());}
		catch (...) { fprintf (stdout, "Element Name              : %s\n", "N/A");}
		try         { fprintf (stdout, "Name Format               : %s\n", _IP.getNameFormat().c_str ());}
		catch (...) { fprintf (stdout, "Name Format               : %s\n", "N/A");}
		try         { fprintf (stdout, "Protocol IF Type          : %s\n", _IP.getProtocolIFTypeStr ().c_str ());}
		catch (...) { fprintf (stdout, "Protocol IF Type          : %s\n", "N/A");}
		try         { fprintf (stdout, "IPv4Address               : %s\n", _IP.getIPv4Address().c_str());}
		catch (...) { fprintf (stdout, "IPv4Address               : %s\n", "N/A");}
		try         { fprintf (stdout, "Subnet Mask               : %s\n", _IP.getSubnetMask().c_str());}
		catch (...) { fprintf (stdout, "Subnet Mask               : %s\n", "N/A");}
		try         { fprintf (stdout, "Address Origin            : %s\n", _IP.getAddressOriginStr().c_str());}
		catch (...) { fprintf (stdout, "Address Origin            : %s\n", "N/A");}
		try         { fprintf (stdout, "IPv6Address               : %s\n", _IP.getIPv6Address().c_str());}
		catch (...) { fprintf (stdout, "IPv6Address               : %s\n", "N/A");}
		try         { fprintf (stdout, "IPv6Address Type          : %s\n", _IP.getIPv6AddressTypeStr().c_str ());}
		catch (...) { fprintf (stdout, "IPv6Address Type          : %s\n", "N/A");}
		try         { fprintf (stdout, "IPv6Subnet Prefix Length  : %d\n", _IP.getIPv6SubnetPrefixLength());}
		catch (...) { fprintf (stdout, "IPv6Subnet Prefix Length  : %s\n", "N/A");}
		try         { fprintf (stdout, "Enabled State             : %s\n", _IP.getEnabledStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "Enabled State             : %s\n", "N/A");}
		try         { fprintf (stdout, "Requested State           : %s", _IP.getRequestedStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "Requested State           : %s", "N/A");}
		
		return 0;
	}
private:
	CIPInterface  _IP;
};

/**
 * @class CDNSClient
 * @brief A CDNSClient executer.
 */
class CDNSClientExec
{
public:
	/**
	 * Constructor
	 */
	CDNSClientExec (CDNSClient dns) : _dns (dns) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{

		if (commands.size () == 0)          { displayDNSClientHelp (commands, 0); return -1; }
		if (commands [0] == "show")         { return this->show (client); }
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client)
	{
		try         { fprintf (stdout, "Name                           : %s\n", _dns.getName ().c_str ());}
		catch (...) { fprintf (stdout, "Name                           : %s\n", "N/A");}
		try         { fprintf (stdout, "Element Name                   : %s\n", _dns.getElementName().c_str());}
		catch (...) { fprintf (stdout, "Element Name                   : %s\n", "N/A");}
		try         { fprintf (stdout, "Name Format                    : %s\n", _dns.getNameFormat().c_str());}
		catch (...) { fprintf (stdout, "Name Format                    : %s\n", "N/A");}
		try         { fprintf (stdout, "Hostname                       : %s\n", _dns.getHostname().c_str());}
		catch (...) { fprintf (stdout, "Hostname                       : %s\n", "N/A");}
		try         { fprintf (stdout, "Protocol IF Type               : %s\n", _dns.getProtocolIFTypeStr ().c_str ());}
		catch (...) { fprintf (stdout, "Protocol IF Type               : %s\n", "N/A");}
		try         { fprintf (stdout, "Requested State                : %s\n", _dns.getRequestedStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "Requested State                : %s\n", "N/A");}
		try         { fprintf (stdout, "Enabled State                  : %s\n", _dns.getEnabledStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "Enabled State                  : %s\n", "N/A");}
		try         { fprintf (stdout, "Append Primary Suffixes        : %s\n", _dns.appendPrimarySuffixes()? "Yes":"No");}
		catch (...) { fprintf (stdout, "Append Primary Suffixes        : %s\n", "N/A");}
		try         { fprintf (stdout, "Append Parent Suffixes         : %s\n", _dns.appendParentSuffixes()? "Yes":"No");}
		catch (...) { fprintf (stdout, "Append Parent Suffixes         : %s\n", "N/A");}

		try {
			vector <string> dnsSuffixesToAppend = _dns.getDNSSuffixesToAppend();
			displayVectorStr ("DNSSuffixesToAppend            : ", dnsSuffixesToAppend, 4);
			fprintf (stdout, "\n");
		}

		catch (...)
		{
				fprintf(stdout,"DNSSuffixesToAppend            : %s\n","N/A");
		}

		try         { fprintf (stdout, "DomainName                     : %s\n", _dns.getDomainName().c_str());}
		catch (...) { fprintf (stdout, "DomainName                     : %s\n", "N/A");}

		try         { fprintf (stdout, "UseSuffixWhenRegistering       : %s\n", _dns.useSuffixWhenRegistering()?"Yes":"No");}
		catch (...) { fprintf (stdout, "UseSuffixWhenRegistering       : %s\n", "N/A");}

		try         { fprintf (stdout, "RegisterThisConnectionsAddress : %s\n", _dns.registerThisConnectionsAddress()?"Yes":"No");}
		catch (...) { fprintf (stdout, "RegisterThisConnectionsAddress : %s\n", "N/A");}
	
		try {
				vector<uint16> dhcpOptionsToUse = _dns.getDHCPOptionsToUse();
				displayVectorInt ("DHCPOptionsToUse               : ", dhcpOptionsToUse, 4); 
			}
		catch(...)
		{
			fprintf (stdout, "DHCPOptionsToUse               : %s", "N/A");
		}
		return 0;
	}
private:
	CDNSClient  _dns;
};

/**
 * @class CRegisteredProfile
 * @brief A CRegisteredProfile executer.
 */
class CRegisteredProfileExec
{
public:
	/**
	 * Constructor
	 */
	CRegisteredProfileExec (CRegisteredProfile rp) : _rp (rp) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{

		if (commands.size () == 0)          { displayRegisteredProfileHelp (commands, 0); return -1; }
		if (commands [0] == "show")         { return this->show (client); }
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client)
	{
		try         { fprintf (stdout, "RegisteredName          : %s\n", _rp.getRegisteredName().c_str ());}
		catch (...) { fprintf (stdout, "RegisteredName          : %s\n", "N/A");}
		try         { fprintf (stdout, "RegisteredOrganization  : %s\n", _rp.getValueRegisteredOrganizationStr().c_str ());}
		catch (...) { fprintf (stdout, "RegisteredOrganization  : %s\n", "N/A");}
		try         { fprintf (stdout, "RegisteredVersion       : %s\n", _rp.getRegisteredVersion().c_str ());}
		catch (...) { fprintf (stdout, "RegisteredVersion       : %s\n", "N/A");}

		try	
		{
			vector <string> advertisestrings;
			advertisestrings =  _rp.getValueAdvertiseTypesStr ();
			displayVectorStr ("AdvertiseTypes          : ", advertisestrings, 4);
			fprintf (stdout, "\n");
		}
		catch (...) { fprintf (stdout, "AdvertiseTypes          : %s\n", "N/A");}
		try         { fprintf (stdout, "InstanceID              : %s", _rp.getInstanceID().c_str ());}
		catch (...) { fprintf (stdout, "InstanceID              : %s", "N/A");}
		return 0;
	}
private:
	CRegisteredProfile  _rp;
};

/*
 * @class CEthernetPort
 * @brief A EthernetPort executer.
 */
class CEthernetPortExec
{
public:
	/*
	 * Constructor
	 */
	CEthernetPortExec (CEthernetPort eth) : _eth (eth) { /* Empty */ }

	/*
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{

		if (commands.size () == 0)          { displayEthernetPortHelp (commands, 0);return -1; }
		if (commands [0] == "show")         { return this->show (client); }
		fprintf (stderr, 
				 "Error: Invalid command '%s'\n", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client)
	{
		try         { fprintf (stdout, "Name                       : %s\n", _eth.getName ().c_str());}
		catch (...) { fprintf (stdout, "Name                       : %s\n", "N/A");}
		try         { fprintf (stdout, "Element Name               : %s\n", _eth.getElementName ().c_str());}
		catch (...) { fprintf (stdout, "Element Name               : %s\n", "N/A");}
		try         { fprintf (stdout, "DeviceID                   : %s\n", _eth.getDeviceID ().c_str ());}
		catch (...) { fprintf (stdout, "DeviceID                   : %s\n", "N/A");}
		try         { fprintf (stdout, "Speed                      : %llu Gbps\n", (_eth.getSpeed () / (1000 * 1000 * 1000)));}
		catch (...) { fprintf (stdout, "Speed                      : %s\n", "N/A");}
		try         { fprintf (stdout, "Maximum Speed              : %llu Gbps\n", (_eth.getMaxSpeed () / (1000 * 1000 * 1000)));}
		catch (...) { fprintf (stdout, "Maximum Speed              : %s\n", "N/A");}
		try         { fprintf (stdout, "Requested Speed            : %llu Gbps\n", (_eth.getRequestedSpeed () / (1000 * 1000 * 1000)));}
		catch (...) { fprintf (stdout, "Requested Speed            : %s\n", "N/A");}
		try         { fprintf (stdout, "Link Technology            : %s\n", _eth.getLinkTechnologyStr ().c_str ());}
		catch (...) { fprintf (stdout, "Link Technology            : %s\n", "N/A");}
		try         { fprintf (stdout, "PortType                   : %s\n", _eth.getPortTypeStr ().c_str ());}
		catch (...) { fprintf (stdout, "PortType                   : %s\n", "N/A");}
		try         { fprintf (stdout, "MAC Address                : %s\n", _eth.getPermanentAddress ().c_str());}
		catch (...) { fprintf (stdout, "MAC Address                : %s\n", "N/A");}
		
		try
		{
			vector <string> addressstr = _eth.getNetworkAddresses ();
			displayVectorStr ("NetworkAddress             : ", addressstr, 4);
			fprintf (stdout, "\n");
		}	
		catch (...) {fprintf (stdout, "NetworkAddress             : %s\n", "N/A");}

		try
		{
			vector<string> capabilities;
			capabilities = _eth.getCapabilitiesStr ();
			displayVectorStr ("Capabilities               : ", capabilities, 4);
			fprintf (stdout, "\n");
		}	
		catch (...) {fprintf (stdout, "Capabilities               : %s\n", "N/A");}

		try
		{
			vector<string> enabledcapabilities;
			enabledcapabilities = _eth.getEnabledCapabilitiesStr ();
			displayVectorStr ("EnabledCapabilities        : ", enabledcapabilities, 4);
			fprintf (stdout, "\n");
		}	
		catch (...) {fprintf (stdout, "EnabledCapabilities        : %s\n", "N/A");}

		try         { fprintf (stdout, "Enabled State              : %s\n", _eth.getEnabledStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "Enabled State              : %s\n", "N/A");}
		try         { fprintf (stdout, "Requested State            : %s", _eth.getRequestedStateStr ().c_str ());}
		catch (...) { fprintf (stdout, "Requested State            : %s", "N/A");}

		return 0;
	
	}
private:
	CEthernetPort  _eth;
};
/**
 * @class CIndicationFilter
 * @brief A CIndicationFilter executer.
 */
class CIndicationFilterExec
{
public:
	/**
	 * Constructor
	 */
	CIndicationFilterExec (CIndicationFilter If) : _if (If) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{

		if (commands.size () == 0)          { displayIndicationFilterHelp (commands, 0); return -1; }
		if (commands [0] == "show")         { return this->show (client); }
		if (commands [0] == "delete")       { return this->deleteFilter (commands); }
		fprintf (stderr, 
				 "Error: Invalid command '%s'\n", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client)
	{
		try         { fprintf (stdout, "SystemCreationClassName         : %s\n", _if.getSystemCreationClassName ().c_str ());}
		catch (...) { fprintf (stdout, "SystemCreationClassName         : %s\n", "N/A");}
		try         { fprintf (stdout, "SystemName                      : %s\n", _if.getName ().c_str ());}
		catch (...) { fprintf (stdout, "SystemName                      : %s\n", "N/A");}
		try         { fprintf (stdout, "CreationClassName               : %s\n", _if.getCreationClassName().c_str());}
		catch (...) { fprintf (stdout, "CreationClassName               : %s\n", "N/A");}
		try         { fprintf (stdout, "Name                            : %s\n", _if.getName().c_str());}
		catch (...) { fprintf (stdout, "Name                            : %s\n", "N/A");}
		try         { fprintf (stdout, "Query                           : %s\n", _if.getQuery().c_str());}
		catch (...) { fprintf (stdout, "Query                           : %s\n", "N/A");}
		try         { fprintf (stdout, "QueryLanguage                   : %s\n", _if.getQueryLanguage().c_str());}
		catch (...) { fprintf (stdout, "QueryLanguage                   : %s\n", "N/A");}
		try         { fprintf (stdout, "SourceNamespace                 : %s\n", _if.getSourceNamespace().c_str());}
		catch (...) { fprintf (stdout, "SourceNamespace                 : %s\n", "N/A");}
		try         { fprintf (stdout, "Element Name                    : %s\n", _if.getElementName().c_str());}
		catch (...) { fprintf (stdout, "Element Name                    : %s\n", "N/A");}
		try         { fprintf (stdout, "IndividualSubscriptionSupported : %s", _if.getIndividualSubscriptionSupported()? "True":"False");}
		catch (...) { fprintf (stdout, "IndividualSubscriptionSupported : %s", "N/A");}
		return 0;
	}

	/**
	 * deleteFilter 
	 */
	int deleteFilter (vector <string> commands)
	{
		try
		{
			this->_if.deleteFilter ();
			fprintf (stdout, "Indication Filter Deleted Successfully");
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Deleting Indication Filter");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}
private:
	CIndicationFilter  _if;
};

/**
 * @class CFilterCollection
 * @brief A CFilterCollection executer.
 */
class CFilterCollectionExec
{
public:
	/**
	 * Constructor
	 */
	CFilterCollectionExec (CFilterCollection Fc) : _fc (Fc) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{

		if (commands.size () == 0)          { displayFilterCollectionHelp (commands, 0); return -1; }
		if (commands [0] == "show")         { return this->show (client); }
		if (commands [0] == "showallfilters"){ return this->showallfilters (client); }
		if (commands [0] == "delete")       { return this->deleteFilterCollection (commands); }
		fprintf (stderr, 
				 "Error: Invalid command '%s'\n", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client)
	{
		try         { fprintf (stdout, "InstanceID         : %s\n", _fc.getInstanceID ().c_str ());}
		catch (...) { fprintf (stdout, "InstanceID         : %s\n", "N/A");}
		try         { fprintf (stdout, "CollectionName     : %s\n", _fc.getCollectionName ().c_str ());}
		catch (...) { fprintf (stdout, "CollectionName     : %s\n", "N/A");}
		return 0;
	}

		/**
	 * Shows the information
	 */
	int showallfilters (IClient* client)
	{
		vector<CIndicationFilter>		filters;
		try 
		{
			filters = _fc.getAllFilters();
			for (size_t i = 0 ; i < filters.size(); i++)
			{
				fprintf(stdout,"Name		%s \n:",filters[i].getName().c_str());
				fprintf(stdout,"\nQueryString %s :",filters[i].getQuery().c_str());
			}

		}

		catch(...) { fprintf(stdout,"\nError:showallFitlers failed");}


		return 0;
	}

	/**
	 * deleteFilter Collection
	 */
	int deleteFilterCollection (vector <string> commands)
	{
		try
		{
			this->_fc.deleteFilterCollection ();
			fprintf (stdout, "Indication Filter Deleted Successfully");
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Deleting Indication Filter");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}
private:
	CFilterCollection  _fc;
};

/**
 * @class CAlertDestination
 * @brief A CAlertDestination executer.
 */
class CAlertDestinationExec
{
public:
	/**
	 * Constructor
	 */
	CAlertDestinationExec (CAlertDestination ld) : _ld (ld) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{

		if (commands.size () == 0)          { displayAlertDestinationHelp (commands, 0); return -1; }
		if (commands [0] == "show")         { return this->show (client); }
		if (commands [0] == "delete")       { return this->deleteDestination (commands); }
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client)
	{
		try         { fprintf (stdout, "SystemCreationClassName         : %s\n", _ld.getSystemCreationClassName ().c_str ());}
		catch (...) { fprintf (stdout, "SystemCreationClassName         : %s\n", "N/A");}
		try         { fprintf (stdout, "SystemName                      : %s\n", _ld.getName ().c_str ());}
		catch (...) { fprintf (stdout, "SystemName                      : %s\n", "N/A");}
		try         { fprintf (stdout, "CreationClassName               : %s\n", _ld.getCreationClassName().c_str());}
		catch (...) { fprintf (stdout, "CreationClassName               : %s\n", "N/A");}
		try         { fprintf (stdout, "Name                            : %s\n", _ld.getName().c_str());}
		catch (...) { fprintf (stdout, "Name                            : %s\n", "N/A");}
		try         { fprintf (stdout, "PersistenceType                 : %d\n", _ld.getPersistenceType());}
		catch (...) { fprintf (stdout, "PersistenceType                 : %s\n", "N/A");}
		try         { fprintf (stdout, "Element Name                    : %s\n", _ld.getElementName().c_str());}
		catch (...) { fprintf (stdout, "Element Name                    : %s\n", "N/A");}
		try         { fprintf (stdout, "Destination                     : %s\n", _ld.getDestination().c_str());}
		catch (...) { fprintf (stdout, "Destination                     : %s\n", "N/A");}
		try         { fprintf (stdout, "Protocol                        : %d", _ld.getProtocol ());}
		catch (...) { fprintf (stdout, "Protocol                        : %s", "N/A");}
		
		
		return 0;
	}

	/**
	 * deleteDestination
	 */
	int deleteDestination (vector <string> commands)
	{
		try
		{
			this->_ld.deleteDestination ();
			fprintf (stdout, "Alert Destination Deleted Successfully");
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Deleting Alert Destination");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}

private:
	CAlertDestination  _ld;
};

/**
 * @class CIndicationSubscription
 * @brief A CIndicationSubscription executer.
 */
class CAbstractIndicationSubscriptionExec
{
public:
	/**
	 * Constructor
	 */
	CAbstractIndicationSubscriptionExec (CAbstractIndicationSubscription is) : _is (is) { /* Empty */ }

	/**
	 * Execute based on the options and commands.
	 */
	int execute (IClient*           client,
				 const CCmdOption&  options, 
				 vector<string>     commands,
				 size_t             target_ix);

public:
	/**
	 * Execute the commands addressed to this object
	 */
	int executeThis (IClient*           client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
	{

		if (commands.size () == 0)          { displayIndicationSubscriptionHelp (commands, 0); return -1; }
		if (commands [0] == "show")         { return this->show (client); }
		if (commands [0] == "unsubscribe")  { return this->unSubscribe (commands); }
		if (commands [0] == "renew")        { return this->renewSubscription (commands); }
		fprintf (stderr, 
				 "Error: Invalid command '%s'", 
				 commands [0].c_str ());
		return -1;
	}

	/**
	 * Shows the information
	 */
	int show (IClient* client)
	{
		try         { fprintf (stdout, "Filter Name                : %s\n", _is.getFilternName(client).c_str());}
		catch (...) { fprintf (stdout, "Filter Name                : %s\n", "N/A");}

		try         { fprintf (stdout, "Destination                : %s\n", _is.getAlertDestination(client).c_str());}
		catch (...) { fprintf (stdout, "Destination                : %s\n", "N/A");}

		try         { fprintf (stdout, "OnFatalErrorPolicy         : %d\n", _is.getOnFatalErrorPolicy());}
		catch (...) { fprintf (stdout, "OnFatalErrorPolicy         : %s\n", "N/A");}

		try         { fprintf (stdout, "OtherOnFatalErrorPolicy    : %s\n", _is.getOtherOnFatalErrorPolicy().c_str());}
		catch (...) { fprintf (stdout, "OtherOnFatalErrorPolicy    : %s\n", "N/A");}

		try         { fprintf (stdout, "FailureTriggerTimeInterval : %llu\n", _is.getFailureTriggerTimeInterval());}
		catch (...) { fprintf (stdout, "FailureTriggerTimeInterval : %s\n", "N/A");}


		try         { fprintf (stdout, "SubscriptionState          : %d\n", _is.getSubscriptionState());}
		catch (...) { fprintf (stdout, "SubscriptionState          : %s\n", "N/A");}

		try         { fprintf (stdout, "OtherSubscriptionState     : %s\n", _is.getOtherSubscriptionState().c_str());}
		catch (...) { fprintf (stdout, "OtherSubscriptionState     : %s\n", "N/A");}

		try         { fprintf (stdout, "RepeatNotificationPolicy   : %d\n", _is.getRepeatNotificationPolicy());}
		catch (...) { fprintf (stdout, "RepeatNotificationPolicy   : %s\n", "N/A");}

		try         { fprintf (stdout, "RepeatNotificationInterval : %llu\n", _is.getRepeatNotificationInterval());}
		catch (...) { fprintf (stdout, "RepeatNotificationInterval : %s\n", "N/A");}

		try         { fprintf (stdout, "RepeatNotificationGap      : %llu\n", _is.getRepeatNotificationGap());}
		catch (...) { fprintf (stdout, "RepeatNotificationGap      : %s\n", "N/A");}

		try         { fprintf (stdout, "RepeatNotificationCount    : %d", _is.getRepeatNotificationCount());}
		catch (...) { fprintf (stdout, "RepeatNotificationCount    : %s", "N/A");}

		return 0;
	}

	/**
	 * unSubscribe
	 */
	int unSubscribe (vector <string> commands)
	{
		try
		{
			this->_is.unSubscribe ();
			fprintf (stdout, "UnSubscribed Successfully");
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: UnSubscribed failed");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}

	/**
	 * renewSubscription
	 */
	int renewSubscription (vector <string> commands)
	{
		if (commands.size() < 2)
		{
			displayIndicationSubscriptionHelp (commands, 0); 
			return -1; 
		}
		
		try
		{
			this->_is.renewSubscription (commands[1]);
			fprintf (stdout, "Indication subscription renewed Successfully");
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: Renew Indication subscription");
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
			return -1;
		}
		return 0;
	}
	
private:
	CAbstractIndicationSubscription  _is;
};

#define EXEC_PRECHECK                                                       \
	/* If there are no more targets - command directed to this object */    \
	if (options._target.size () == target_ix)                               \
	{                                                                       \
		return executeThis (client, options, commands, target_ix);          \
	}                                                                       \
																			\
	/* Redirect the command to the appropriate object */                    \
	string target  = options._target [target_ix];                           \
	string type    = getTargetType (target);                                \
	int    ins_num = getTargetInstance (target);                            \
																			\
	if (ins_num == TARGET_INVALID_INSTANCE)                                 \
	{                                                                       \
		fprintf (stderr,                                                    \
				 "Error: Invalid instance number in '%s'",                  \
				 target.c_str ());                                          \
		return -1;                                                          \
	}                                           

/**
 * execute
 */
int 
CRootExec::execute (IClient*            client,
					const CCmdOption&   options, 
					vector<string>      commands,
					size_t              target_ix)
{
	EXEC_PRECHECK
	CHECK_EXEC_CMD ("computersystem",   getComputerSystemInstance, 
					CComputerSystem,    CComputerSystemExec);
	CHECK_EXEC_CMD ("processor",        getProcessorInstance, 
					CProcessor,         CProcessorExec);
	CHECK_EXEC_CMD ("sensor",           getSensorInstance,  
					CSensor,            CSensorExec);
	CHECK_EXEC_CMD ("fan",              getFanInstance,
					CFan,               CFanExec);
	CHECK_EXEC_CMD ("asset",            getPhysicalAssetInstance,   
					CPhysicalAsset,     CPhysicalAssetExec);
	CHECK_EXEC_CMD ("memory",           getMemoryInstance,  
					CMemory,            CMemoryExec);
	CHECK_EXEC_CMD ("powersupply",      getPowerSupplyInstance,  
					CPowerSupply,       CPowerSupplyExec);
	CHECK_EXEC_CMD ("software",         getSoftwareInstance,  
					CSoftware,          CSoftwareExec);
	CHECK_EXEC_CMD ("operatingsystem",  getOperatingSystemInstance,  
					COperatingSystem,   COperatingSystemExec);
	CHECK_EXEC_CMD ("bios",             getBIOSElementInstance,  
					CBIOSElement,       CBIOSElementExec);
	CHECK_EXEC_CMD ("bootconfig",       getBootConfigInstance,  
					CBootConfig,        CBootConfigExec);
	CHECK_EXEC_CMD ("user",             getUserInstance,  
					CUser,              CUserExec);
	CHECK_EXEC_CMD ("role",             getRoleInstance,  
					CRole,              CRoleExec);
	CHECK_EXEC_CMD ("textredirection",  getTextRedirectionInstance,  
					CTextRedirection,    CTextRedirectionExec);
	CHECK_EXEC_CMD ("usbredirection",   getUSBRedirectionInstance,  
					CUSBRedirection,    CUSBRedirectionExec);
	CHECK_EXEC_CMD ("opaquemanagementdata",getOpaqueManagementDataInstance,  
					COpaqueManagementData,COpaqueManagementDataExec);
	CHECK_EXEC_CMD ("battery"			,getBatteryInstance,  
					CBattery,CBatteryExec);
	CHECK_EXEC_CMD ("networkport"		,getNetworkPortInstance,  
					CNetworkPort,CNetworkPortExec);
	CHECK_EXEC_CMD ("dhcpclient"		,getDHCPClientInstance,  
					CDHCPClient,CDHCPClientExec);
	CHECK_EXEC_CMD ("ipinterface"		,getIPInterfaceInstance,  
					CIPInterface,CIPInterfaceExec);
	CHECK_EXEC_CMD ("dnsclient"		,getDNSClientInstance,  
					CDNSClient,CDNSClientExec);
	CHECK_EXEC_CMD ("registeredprofile" ,getRegisteredProfileInstance,
					CRegisteredProfile ,CRegisteredProfileExec);
	CHECK_EXEC_CMD ("ethernetport",		 getEthernetPortInstance,
					CEthernetPort,		 CEthernetPortExec);
	CHECK_EXEC_CMD ("indicationfilter"		,getIndicationFilterInstance,  
					CIndicationFilter,CIndicationFilterExec);
	CHECK_EXEC_CMD ("filtercollection"		,getFilterCollectionInstance,  
					CFilterCollection,CFilterCollectionExec);
	CHECK_EXEC_CMD ("alertdestination"		,getAlertDestinationInstance,  
					CAlertDestination,CAlertDestinationExec);
	CHECK_EXEC_CMD ("indicationsubscription"	,getAbstractIndicationSubscriptionInstance,  
					CAbstractIndicationSubscription,CAbstractIndicationSubscriptionExec);

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/**
 * execute
 */
int 
CComputerSystemExec::execute (IClient*          client,
							  const CCmdOption& options, 
							  vector<string>    commands,
							  size_t            target_ix)
{
	EXEC_PRECHECK
	CHECK_EXEC_CMD ("processor",        getProcessorInstance, 
					CProcessor,         CProcessorExec);
	CHECK_EXEC_CMD ("sensor",           getSensorInstance,  
					CSensor,            CSensorExec);
	CHECK_EXEC_CMD ("fan",              getFanInstance,         
					CFan,               CFanExec);
	CHECK_EXEC_CMD ("asset",            getPhysicalAssetInstance,   
					CPhysicalAsset,     CPhysicalAssetExec);
	CHECK_EXEC_CMD ("memory",           getMemoryInstance,  
					CMemory,            CMemoryExec);
	CHECK_EXEC_CMD ("user",             getUserInstance,  
					CUser,              CUserExec);
	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}


/**
 * execute
 */
int 
CProcessorExec::execute (IClient*           client,
						 const CCmdOption&  options, 
						 vector<string>     commands,
						 size_t             target_ix)
{
	EXEC_PRECHECK
	CHECK_EXEC_CMD ("sensor",           getSensorInstance,  
					CSensor,            CSensorExec);
	CHECK_EXEC_CMD ("fan",              getFanInstance,         
					CFan,               CFanExec);
	CHECK_EXEC_CMD ("asset",            getPhysicalAssetInstance,   
					CPhysicalAsset,     CPhysicalAssetExec);

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}


/**
 * execute
 */
int 
CSensorExec::execute (IClient*          client,
					  const CCmdOption& options, 
					  vector<string>    commands,
					  size_t            target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}


/**
 * execute
 */
int 
CFanExec::execute (IClient*          client,
				   const CCmdOption& options, 
				   vector<string>    commands,
				   size_t            target_ix)
{
	EXEC_PRECHECK
	CHECK_EXEC_CMD ("asset",            getPhysicalAssetInstance,   
					CPhysicalAsset,     CPhysicalAssetExec);

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}


/**
 * execute
 */
int 
CPowerSupplyExec::execute (IClient*          client,
						   const CCmdOption& options, 
						   vector<string>    commands,
						   size_t            target_ix)
{
	EXEC_PRECHECK
	CHECK_EXEC_CMD ("asset",            getPhysicalAssetInstance,   
					CPhysicalAsset,     CPhysicalAssetExec);

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/**
 * execute
 */
int 
CPhysicalAssetExec::execute (IClient*           client,
							 const CCmdOption&  options, 
							 vector<string>     commands,
							 size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/**
 * execute
 */
int 
CMemoryExec::execute (IClient*          client,
							 const CCmdOption&  options, 
							 vector<string>     commands,
							 size_t             target_ix)
{
	EXEC_PRECHECK
	CHECK_EXEC_CMD ("asset",            getPhysicalAssetInstance,   
					CPhysicalAsset,     CPhysicalAssetExec);

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/**
 * execute
 */
int 
CSoftwareExec::execute (IClient*           client,
						const CCmdOption&  options, 
						vector<string>     commands,
						size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/**
 * execute
 */
int 
COperatingSystemExec::execute (IClient*           client,
						const CCmdOption&  options, 
						vector<string>     commands,
						size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/**
 * execute
 */
int 
CBIOSElementExec::execute (IClient*           client,
						const CCmdOption&  options, 
						vector<string>     commands,
						size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/**
 * execute
 */
int 
CBootConfigExec::execute (IClient*           client,
						const CCmdOption&  options, 
						vector<string>     commands,
						size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/**
 * execute
 */
int 
CUserExec::execute (IClient*           client,
					const CCmdOption&  options, 
					vector<string>     commands,
					size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/**
 * execute
 */
int 
CRoleExec::execute (IClient*           client,
					const CCmdOption&  options, 
					vector<string>     commands,
					size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/**
 * execute
 */
int 
CTextRedirectionExec::execute (IClient*           client,
						const CCmdOption&  options, 
						vector<string>     commands,
						size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}


/**
 * execute
 */
int 
CUSBRedirectionExec::execute (IClient*           client,
						const CCmdOption&  options, 
						vector<string>     commands,
						size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}


/**
 * execute
 */
int 
COpaqueManagementDataExec::execute (IClient*          client,
							 const CCmdOption&  options, 
							 vector<string>     commands,
							 size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/**
 * execute
 */
int 
CBatteryExec::execute (IClient*          client,
							 const CCmdOption&  options, 
							 vector<string>     commands,
							 size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/**
 * execute
 */
int 
CNetworkPortExec::execute (IClient*          client,
							 const CCmdOption&  options, 
							 vector<string>     commands,
							 size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/**
 * execute
 */
int 
CDHCPClientExec::execute (IClient*          client,
							 const CCmdOption&  options, 
							 vector<string>     commands,
							 size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/**
 * execute
 */
int 
CIPInterfaceExec::execute (IClient*          client,
							 const CCmdOption&  options, 
							 vector<string>     commands,
							 size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/**
 * execute
 */
int 
CDNSClientExec::execute (IClient*          client,
						   const CCmdOption&  options, 
						   vector<string>     commands,
						   size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/**
 * execute
 */
int 
CRegisteredProfileExec::execute (IClient*          client,
						   const CCmdOption&  options, 
						   vector<string>     commands,
						   size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/*
 * EthernetPort Exec
 */
int 
CEthernetPortExec::execute (IClient*          client,
						   const CCmdOption&  options, 
						   vector<string>     commands,
						   size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}
/**
 * execute
 */
int 
CIndicationFilterExec::execute (IClient*          client,
						   const CCmdOption&  options, 
						   vector<string>     commands,
						   size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/**
 * execute
 */
int 
CFilterCollectionExec::execute (IClient*          client,
						   const CCmdOption&  options, 
						   vector<string>     commands,
						   size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/**
 * execute
 */
int 
CAlertDestinationExec::execute (IClient*          client,
						   const CCmdOption&  options, 
						   vector<string>     commands,
						   size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}

/**
 * execute
 */
int 
CAbstractIndicationSubscriptionExec::execute (IClient*          client,
						   const CCmdOption&  options, 
						   vector<string>     commands,
						   size_t             target_ix)
{
	EXEC_PRECHECK

	fprintf (stderr, 
			 "Error: Invalid target path at '%s'", 
			 target.c_str ());
	return -1;
}


#define ENUM_DISPLAY_FUNCTION(PARENT, TYPE, DISP_STR, DISP_STR2)        \
int                                                                     \
PARENT::enumerate##TYPE (IClient*           client,                     \
						 const CCmdOption&  options,                    \
						 vector<string>     commands,                   \
						 size_t             target_ix)                  \
{                                                                       \
	try                                                                 \
	{                                                                   \
		vector<C##TYPE> vt = get##TYPE##Instance (client,               \
												   TARGET_ALL_INSTANCE);\
		if (0 == vt.size ())                                            \
		{                                                               \
			fprintf (stdout, DISP_STR2);                                \
			fprintf (stdout, " not found");                             \
		}                                                               \
		for (size_t i = 0; i < vt.size (); i++)                         \
		{                                                               \
			fprintf (stdout, DISP_STR);                                 \
			fprintf (stdout, " Instance %d\n", i);                      \
			C##TYPE##Exec (vt [i]).show (client);                       \
			if (i != (vt.size () -1) )	{ fprintf (stdout,"\n");}		\
		}                                                               \
	}                                                                   \
	catch (ECIMError& e)                                                \
	{                                                                   \
		fprintf (stdout, DISP_STR2);                                    \
		fprintf (stdout, " not found");                                 \
		if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }  \
		return -1;                                                      \
	}                                                                   \
																		\
	return 0;                                                           \
}

ENUM_DISPLAY_FUNCTION (CRootExec, ComputerSystem,   "\nComputer System","\nComputer System(s)")
ENUM_DISPLAY_FUNCTION (CRootExec, Processor,        "\nProcessor",		"\nProcessor(s)")
ENUM_DISPLAY_FUNCTION (CRootExec, Sensor,           "\nSensor",			"\nSensor(s)")
ENUM_DISPLAY_FUNCTION (CRootExec, Fan,              "\nFan",			"\nFan(s)")
ENUM_DISPLAY_FUNCTION (CRootExec, PowerSupply,      "\nPower supply",	"\nPower supply")
ENUM_DISPLAY_FUNCTION (CRootExec, Memory,           "\nMemory",			"\nMemory")
ENUM_DISPLAY_FUNCTION (CRootExec, PhysicalAsset,    "\nAsset",			"\nAsset(s)")
ENUM_DISPLAY_FUNCTION (CRootExec, Software,         "\nSoftware",		"\nSoftware")
ENUM_DISPLAY_FUNCTION (CRootExec, OperatingSystem,  "\nOperating System",	"\nOperating System(s)")
ENUM_DISPLAY_FUNCTION (CRootExec, BIOSElement,      "\nBIOS Element",	"\nBIOS Elements(s)")
ENUM_DISPLAY_FUNCTION (CRootExec, BootConfig,       "\nBoot Config",	"\nBoot Config(s)")
ENUM_DISPLAY_FUNCTION (CRootExec, User,             "\nUser",			"\nUser(s)")
ENUM_DISPLAY_FUNCTION (CRootExec, Role,             "\nRole",			"\nRole(s)")
ENUM_DISPLAY_FUNCTION (CRootExec, TextRedirection,   "\nText Redirection","\nText Redirection(s)")
ENUM_DISPLAY_FUNCTION (CRootExec, USBRedirection,   "\nUSB Redirection","\nUSB Redirection(s)")
ENUM_DISPLAY_FUNCTION (CRootExec, OpaqueManagementData,   "\nOpaque Management Data","\nOpaque Management Data")
ENUM_DISPLAY_FUNCTION (CRootExec, Battery,          "\nBattery","\nBattery")
ENUM_DISPLAY_FUNCTION (CRootExec, NetworkPort,      "\nNetworkPort","\nNetworkPort")
ENUM_DISPLAY_FUNCTION (CRootExec, DHCPClient,      "\nDHCPClient","\nDHCPClient")
ENUM_DISPLAY_FUNCTION (CRootExec, IPInterface,      "\nIPInterface","\nIPInterface")
ENUM_DISPLAY_FUNCTION (CRootExec, DNSClient,      "\nDNSClient","\nDNSClient")
ENUM_DISPLAY_FUNCTION (CRootExec, RegisteredProfile,	"\nRegisteredProfile","\nRegisteredProfile")
ENUM_DISPLAY_FUNCTION (CRootExec, EthernetPort,		"\nEthernetPort","\nEthernetPort")
ENUM_DISPLAY_FUNCTION (CRootExec, IndicationFilter,"\nIndicationFilter","\nIndicationFilter")
ENUM_DISPLAY_FUNCTION (CRootExec, FilterCollection,"\nFilterCollection","\nFilterCollection")
ENUM_DISPLAY_FUNCTION (CRootExec, AlertDestination,"\nAlertDestination","\nAlertDestination")
ENUM_DISPLAY_FUNCTION (CRootExec, AbstractIndicationSubscription,"\nIndicationSubscription","\nIndicationSubscription")

ENUM_DISPLAY_FUNCTION (CComputerSystemExec, Processor,		"\nProcessor",	"\nProcessor(s)")
ENUM_DISPLAY_FUNCTION (CComputerSystemExec, Sensor,			"\nSensor",		"\nSensor(s)")
ENUM_DISPLAY_FUNCTION (CComputerSystemExec, Fan,			"\nFan",		"\nFan(s)")
ENUM_DISPLAY_FUNCTION (CComputerSystemExec, PowerSupply,	"\nPower supply","\nPower supply")
ENUM_DISPLAY_FUNCTION (CComputerSystemExec, Memory, "\nMemory",		"\nMemory")
ENUM_DISPLAY_FUNCTION (CComputerSystemExec, PhysicalAsset,	"\nAsset",		"\nAsset(s)")
ENUM_DISPLAY_FUNCTION (CComputerSystemExec, Software,		"\nSoftware",	"\nSoftware")
ENUM_DISPLAY_FUNCTION (CComputerSystemExec, BootConfig,		"\nBoot Config","\nBoot Config(s)")
ENUM_DISPLAY_FUNCTION (CComputerSystemExec, User,			"\nUser",		"\nUser(s)")

ENUM_DISPLAY_FUNCTION (CProcessorExec, Sensor,			"\nSensor",	"\nSensor(s)")
ENUM_DISPLAY_FUNCTION (CProcessorExec, Fan,				"\nFan",	"\nFan(s)")
ENUM_DISPLAY_FUNCTION (CProcessorExec, Memory,	"\nMemory",	"\nMemory")
ENUM_DISPLAY_FUNCTION (CProcessorExec, PhysicalAsset,	"\nAsset",	"\nAsset(s)")

ENUM_DISPLAY_FUNCTION (CMemoryExec,      PhysicalAsset,	"\nAsset",	"\nAsset(s)")

ENUM_DISPLAY_FUNCTION (CPowerSupplyExec, PhysicalAsset,	"\nAsset",	"\nAsset(s)")
ENUM_DISPLAY_FUNCTION (CFanExec,         PhysicalAsset,	"\nAsset",	"\nAsset(s)")

void doTextRedirection(CCmdOption options, vector<string>& commands)	{

	int count = commands.size();
	if(count <= 0) return;

	if(commands[0] == "textredirection")	{
		
		if(commands.size() <= 1)	{	
			doHelp(options,commands,0);
			return;
		}

		string operation = commands[1];
		/*if(operation != "connect" || operation != "disconnect")	
		{
			doHelp(options,commands,0);
			return;
		}*/


		/*CSubject subject (options._user,
					  options._password.c_str (),
					  options._authtype,
					  options._scheme,
					  options._ignore_certificate ? 0 : 1,
					  options._ignore_certificate ? 0 : 1,
					  options._certificate_file,
					  "",
					  "",
					  "",
					  "",
					  "",
					  "",
					  options._timeout);
		CCIMMAP cimmap (options._host, options._port);
		IClient* client = cimmap.connect (subject);*/

		if(operation == "connect")	{
			commands.clear();
			commands.push_back("enumerate");
			commands.push_back("textredirection");
			if(execCommand(options,commands) == -1)	{
				return;
			}
			
			char instNumber[128];
			int instance;
			fprintf(stdout,"\n\n\nChoose valid instance number from the above list : ");
			//rewind(stdin);
			//scanf("%[0-9]",instNumber);

			fflush(stdout);
			fgets(instNumber,sizeof instNumber,stdin);
			if(1 == sscanf(instNumber,"%d",&instance))
				sprintf(instNumber,"%d",instance);				
		
			string targetPath = "";
			targetPath.append("textredirection[");
			targetPath.append(instNumber);
			targetPath.append("]");
			options._target_specified = true;
			options._target 		  = parseTargetPath (targetPath);

			commands.clear();
			commands.push_back("activate");
			if(execCommand(options,commands) == -1)	{
				return;
			}

			commands.clear();
			commands.push_back("start");
			fprintf(stdout,"\nConnecting.....");
			fprintf(stdout,"\nText Redirection will start from the next re-start.");
			if(execCommand(options,commands) == -1)	{
				return;
			}
		//	commands.clear();
		} else if(operation == "disconnect")	{
			vector<int> instPos;
			try
			{
				CSubject subject (options._user,
					  options._password.c_str (),
					  options._authtype,
					  options._scheme,
					  options._ignore_certificate ? 0 : 1,
					  options._ignore_certificate ? 0 : 1,
					  options._certificate_file,
					  "",
					  "",
					  "",
					  "",
					  "",
					  "",
					  options._timeout);
				CCIMMAP cimmap (options._host, options._port);
				IClient* client = cimmap.connect (subject);


				CTextRedirection::iterator iter = CTextRedirection::enumTextRedirections (client);

				

				for (int i = 0; iter != CTextRedirection::iterator::end (); ++iter, i++)	
				{
					CTextRedirection _text = *iter;

					if(_text.getEnabledState() == 2)	
					{
						fprintf(stdout,"Text Redirection Instance %d\n",instPos.size());
			
						try         { fprintf (stdout, "Name                    : %s\n", _text.getName ().c_str ());}
						catch (...) { fprintf (stdout, "Name                    : %s\n", "N/A");}
						try         { fprintf (stdout, "Element Name            : %s\n", _text.getElementName ().c_str ());}
						catch (...) { fprintf (stdout, "Element Name            : %s\n", "N/A");}
						try         { fprintf (stdout, "EnabledState            : %s\n", _text.getEnabledStateStr ().c_str ());}
						catch (...) { fprintf (stdout, "EnabledState            : %s\n", "N/A");}
						try         { fprintf (stdout, "RequestedState          : %s\n", _text.getRequestedStateStr ().c_str ());}
						catch (...) { fprintf (stdout, "RequestedState          : %s\n", "N/A");}
						try         { fprintf (stdout, "Protocol Type           : %s\n", _text.getProtocolIFType ().c_str ());}
						catch (...) { fprintf (stdout, "Protocol Type           : %s\n", "N/A");}
						try         { fprintf (stdout, "Port Number             : %lu\n", _text.getPortNumber ());}
						catch (...) { fprintf (stdout, "Port Number             : %s\n", "N/A");}
						try         { fprintf (stdout, "Termination Sequence    : %s\n", _text.getTerminationSequence ().c_str ());}
						catch (...) { fprintf (stdout, "Termination Sequence    : %s\n", "N/A");}
						try         { fprintf (stdout, "Text Flow Type          : %s\n", _text.getTextFlowType ().c_str ());}
						catch (...) { fprintf (stdout, "Text Flow Type          : %s\n", "N/A");}

						instPos.push_back(i);
					}

				}
			}
			catch (ECIMError& e)                                                \
			{	                                                                   \
				fprintf (stdout, "Text Redirection<s>");                                    \
				fprintf (stdout, " not found");                                 \
				if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }  \
				return;                                                      \
			}
			catch (exception& e)
			{
				fprintf(stdout,"Text Redirection Failed...");
				if (isVerbose) { fprintf (stderr, "\nError: %s\n", e.what ()); } 
				return;
			}
			int enabledInstanceCount = instPos.size();

			if(enabledInstanceCount <= 0)	{
				fprintf(stdout,"\nNo Text Redirection Service is currently enabled.");
				return;
			}

			char instNumber[4];		
			fprintf(stdout,"\n\nChoose valid instance number from the above list : ");
			rewind(stdin);
			scanf("%[0-9]",instNumber);

			int optedInstance = atoi(instNumber);

			if(optedInstance > (enabledInstanceCount-1))	{
				fprintf(stdout,"\nError: Invalid instance selected.");
				return;
			}
			
			sprintf(instNumber,"%d",instPos.at(optedInstance));
			string targetPath = "";
			targetPath.append("textredirection[");
			targetPath.append(instNumber);
			targetPath.append("]");
			options._target_specified = true;
			options._target 		  = parseTargetPath (targetPath);
			commands.clear();
			commands.push_back("disable");
			if(execCommand(options,commands) == -1)	{
				return;
			}
			}else {
			doHelp(options,commands,0);
		}
	}
	return;
}
void doUSBRedirection(CCmdOption options, vector<string>& commands)	{


	string webserver = "false";
	int cont = 'y';
	int count = commands.size();
	if(count <= 0) return;

	if(commands[0] == "usbredirection")	{
		
		if(commands.size() <= 1)	{	
			doHelp(options,commands,0);
			return;
		}

		string operation = commands[1];

		if(commands [count - 1] == "help")
		{
			doHelp(options,commands,0);
			return;
		}
		if(operation == "connect")	{
			commands.clear();
			commands.push_back("enumerate");
			commands.push_back("usbredirection");
			if(execCommand(options,commands) == -1)	{
				return;
			}
		
			char instNumber[128];
			int instance;
			fprintf(stdout,"\n\n\nChoose valid instance number from the above list : ");
			//rewind(stdin);
			//scanf("%[0-9]",instNumber);
			
			fflush(stdout);
			fgets(instNumber,sizeof instNumber,stdin);
			if(1 == sscanf(instNumber,"%d",&instance))
				sprintf(instNumber,"%d",instance);

			string targetPath = "";
			targetPath.append("usbredirection[");
			targetPath.append(instNumber);
			targetPath.append("]");
			options._target_specified = true;
			options._target 		  = parseTargetPath (targetPath);

			commands.clear();
			//added to support Integrated Webserver
			fprintf(stdout,"\n\nUsing Integrate Web Server(Y/N) : ");
			rewind(stdin);	
			/***
#ifndef _WIN32
			getchar();
#endif
			**/
			//cont = getchar();
			gets((char* )&cont);
			char ch[500] ;
			if(cont == 'y' || cont == 'Y')
			{
				
				fprintf (stdout, "\nSDK USBRedirection supports HTTP/HTTPS as transport protocol\n");
#ifndef _WIN32
				fprintf (stdout, "\nProvide the File Path in the format [{folder-path}/{image}.iso]\n");
				fprintf (stdout, " \nExample -- /home/testuser/fedora8.iso \n");
#else
				fprintf (stdout, "\nProvide the File Path in the format [{drive}:{folder-path}/{image}.iso]\n");
				fprintf (stdout, " \nExample -- C:/images/fedora8.iso \n");
#endif
				fprintf (stdout, " \nFile Path: ");
				rewind(stdin);
/**
#ifndef _WIN32
				getchar();
#endif
**/
				gets(ch);	
				webserver = "true";
			}
			else
			{
				fprintf (stdout, "\nProvide the File Path [http://{ip-address}[:{port}]/{path-to-image}/{image}.iso]  :");
				rewind(stdin);
				/***
#ifndef _WIN32
				getchar();
#endif		
				**/
				gets(ch);				
			}
			/*
#ifndef _WIN32
				getchar();
#endif
				*/
			fprintf (stdout, "\nPlease Wait....");
			commands.push_back("startvmr");
			commands.push_back(ch);
			commands.push_back(webserver);
			if(execCommand(options,commands) == -1)	{
				return;
			}
		
		}else if(operation == "disconnect")	{
			vector<int> instPos;
			try
			{
				CSubject subject (options._user,
					  options._password.c_str (),
					  options._authtype,
					  options._scheme,
					  options._ignore_certificate ? 0 : 1,
					  options._ignore_certificate ? 0 : 1,
					  options._certificate_file,
					  "",
					  "",
					  "",
					  "",
					  "",
					  "",
					  options._timeout);
				CCIMMAP cimmap (options._host, options._port);
				IClient* client = cimmap.connect (subject);

				CUSBRedirection::iterator iter = 
					CUSBRedirection::enumUSBRedirections (client);

				for (int i = 0; iter != CUSBRedirection::iterator::end (); ++iter, i++)	{
					CUSBRedirection _usbiter = *iter;

					if(_usbiter.getEnabledState() == 2)	{
						
						fprintf(stdout,"USB Redirection Instance %d\n",instPos.size());
			
						try         { fprintf (stdout, "Redirection Name          : %s\n", _usbiter.getName ().c_str ());}
						catch (...) { fprintf (stdout, "Redirection Name          : %s\n", "N/A");}

						try         { fprintf (stdout, "SystemCreationClassName   : %s\n", _usbiter.getSystemCreationClassName ().c_str ());}
						catch (...) { fprintf (stdout, "SystemCreationClassName   : %s\n", "N/A");}

						try         { fprintf (stdout, "SystemName                : %s\n", _usbiter.getSystemName ().c_str ());}
						catch (...) { fprintf (stdout, "SystemName                : %s\n", "N/A");}

						try         { fprintf (stdout, "CreationClassName         : %s\n", _usbiter.getCreationClassName ().c_str ());}
						catch (...) { fprintf (stdout, "CreationClassName         : %s\n", "N/A");}

						try         { fprintf (stdout, "Element Name              : %s\n", _usbiter.getElementName ().c_str ());}
						catch (...) { fprintf (stdout, "Element Name              : %s\n", "N/A");}

						try         { fprintf (stdout, "EnabledState              : %s\n", _usbiter.getEnabledStateStr ().c_str ());}
						catch (...) { fprintf (stdout, "EnabledState              : %s\n", "N/A");}

						try         { fprintf (stdout, "RequestedState            : %s\n", _usbiter.getRequestedStateStr ().c_str ());}
						catch (...) { fprintf (stdout, "RequestedState            : %s\n", "N/A");}

						try         { fprintf (stdout, "Connection Mode           : %s", _usbiter.getConnectionMode ().c_str ());}
						catch (...) { fprintf (stdout, "Connection Mode           : %s", "N/A");}
						instPos.push_back(i);
					}

				}
			}
			catch (ECIMError& e)                                                \
			{	                                                                   \
				fprintf (stdout, "USB Redirection<s>");                                    \
				fprintf (stdout, " not found");                                 \
				if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }  \
				return;                                                      \
			} 
			catch (exception& e)
			{
				fprintf(stdout,"USB Redirection Failed...");
				if (isVerbose) { fprintf (stderr, "\nError: %s\n", e.what ()); } 
				return;
			}
				int enabledInstanceCount = instPos.size();

				if(enabledInstanceCount <= 0)	{
					fprintf(stdout,"\nNo USB Redirection Service is currently enabled.");
					return;
				}

				char instNumber[4];		
				fprintf(stdout,"\n\nChoose valid instance number from the above list : ");
				rewind(stdin);
				scanf("%[0-9]",instNumber);

				int optedInstance = atoi(instNumber);

				if(optedInstance > (enabledInstanceCount-1))	{
					fprintf(stdout,"\nError: Invalid instance selected.");
					return;
				}
				
				sprintf(instNumber,"%d",instPos.at(optedInstance));
				string targetPath = "";
				targetPath.append("usbredirection[");
				targetPath.append(instNumber);
				targetPath.append("]");
				options._target_specified = true;
				options._target 		  = parseTargetPath (targetPath);
				commands.clear();
				commands.push_back("disable");
				fprintf(stdout,"\nUSB Redirection Service is Disabled Successfully.");
				if(execCommand(options,commands) == -1)	{
					return;
				}
		} else {
			doHelp(options,commands,0);
		}
	}
	return;
}

/*
 * doRolesManage
 */
void doRolesManage(CCmdOption options, vector<string>& commands)	{
	
	int count = commands.size();
	if(count <= 0) return;

	if(commands[0] == "roles")	{
		
		if(commands.size() <= 1 || commands[1] != "manage")	{	
			doHelp(options,commands,0);
			return;
		}	
		if(commands[1] == "manage")	{
			int cont = 'y';
			while(cont == 'y' || cont == 'Y')
			{
				char optNumber[4];	
				fprintf(stdout,"\n\n1.List all Roles\n2.Add New Role\n3.Remove Role\n4.Modify Role ");
				fprintf(stdout,"\nEnter the option number from the above list: ");
				rewind(stdin);
				scanf("%[1-4]",optNumber);
				#ifndef _WIN32
					getchar();
				#endif
				int optRole = atoi(optNumber);
				switch(optRole)
				{
					case 1:
					{
						string toExecute = "role";
						string instNumber ="enumerate";	
						enumerateForInstance(options,commands,toExecute,instNumber);
					}
					break;
					case 2:
					{
						string toExecute = "computersystem";
						string instNumber ="";	
						fprintf(stdout,"\nSelect the Computer System Instances\n  ");
						enumerateForInstance(options,commands,toExecute,instNumber);
						if(instNumber == "")
							break;
						
						string targetPath = "";
						targetPath.append("computersystem[");
						targetPath.append(instNumber);
						targetPath.append("]");
						options._target_specified = true;
						options._target 	= parseTargetPath (targetPath);

						commands.clear();
						commands.push_back("role");
						commands.push_back("add");

						char details[500] ;
						fprintf(stdout,"\n\nEnter the Role Name : ");
						rewind(stdin);
						gets(details);
						if(details[0] == 0)
							break;
						commands.push_back(details);

						char privileges[1000] ;
						fprintf(stdout,"\n\nEnter the Privileges <permission_1> [<permission_2>... <permission_n>]: ");
						rewind(stdin);
						gets(privileges);

						if(privileges[0] == 0)
							break;
						
						string rolepriv = "";
						rolepriv.append(privileges);
						while (0 != rolepriv.size ())
						{
							string priv = rolepriv.substr (0, rolepriv.find (' '));
							
							commands.push_back(priv);
							if ((size_t)-1 == rolepriv.find (' '))
							{
								break;
							}
							rolepriv = rolepriv.substr(rolepriv.find (' ')+1,rolepriv.size());
							
						}
						if(execCommand(options,commands) == -1)	{
							break;
							//return;
						}
						options._target_specified = false;
						options._target 	= parseTargetPath ("");

					}
						break;
					case 3://Delete Role
					{
						GetRoles(options);
						char instNumber[4];	
						fprintf(stdout,"\n\n\nChoose valid instance number from the above list : ");
						rewind(stdin);
						scanf("%[0-9]",instNumber);	
						#ifndef _WIN32
							getchar();
						#endif

						if(instNumber[0] < 0)
							break;

						string targetPath = "";
						targetPath.append("role[");
						targetPath.append(instNumber);
						targetPath.append("]");
						options._target_specified = true;
						options._target 	= parseTargetPath (targetPath);
						commands.clear();
						commands.push_back("delete");
						if(execCommand(options,commands) == -1)	{
							break;
							//return;
						}
						options._target_specified = false;
						options._target 	= parseTargetPath ("");
					}
					break;
					case 4://Modify Role
					{
						GetRoles(options);
						char instNumber[4];	
						fprintf(stdout,"\n\n\nChoose valid instance number from the above list : ");
						rewind(stdin);
						scanf("%[0-9]",instNumber);	
						#ifndef _WIN32
							getchar();
						#endif
						
						if(instNumber[0] < 0)
							break;

						fprintf(stdout,"\nExisting Privileges for this Instance \n");
						string targetPath = "";
						targetPath.append("role[");
						targetPath.append(instNumber);
						targetPath.append("]");
						options._target_specified = true;
						options._target 	= parseTargetPath (targetPath);

						commands.clear();
						commands.push_back("show");

						if(execCommand(options,commands) == -1)	{
							break;
							//return;
						}
						commands.clear();
						commands.push_back("modify");

						char instrole[2];
						fprintf(stdout,"\n\n1.Append Privileges\n2.Re-Assaign Privileges");
						fprintf(stdout,"\nEnter the option number from the above list: ");
						rewind(stdin);
						scanf("%[1-2]",instrole);
						#ifndef _WIN32
							getchar();
						#endif
						int optionNum = atoi(instrole);
						switch(optionNum)
						{
						case 1:
							commands.push_back("Append");							
						case 2:
							{
								char privileges[1000] ;
								fprintf(stdout,"\n\nEnter the Privileges <permission_1> [<permission_2>... <permission_n>]: ");
								rewind(stdin);
								gets(privileges);
								if(privileges[0] == 0)
									break;
								
								string rolepriv = "";
								rolepriv.append(privileges);
								while (0 != rolepriv.size ())
								{
									string priv = rolepriv.substr (0, rolepriv.find (' '));
									
									commands.push_back(priv);
									if ((size_t)-1 == rolepriv.find (' '))
									{
										break;
									}
									rolepriv = rolepriv.substr(rolepriv.find (' ')+1,rolepriv.size());								
								}						
								if(execCommand(options,commands) == -1)	{
									break;
									//return;
								}								
							}
							break;
						default:
							fprintf(stdout,"\nChoose correct option from the list above ");
							break;
						}
						options._target_specified = false;
						options._target 	= parseTargetPath ("");
					}
					break;
					default:
						fprintf(stdout,"\nChoose Correct option from the list above ");
						break;
				}
				options._target_specified = false;
				options._target 	= parseTargetPath ("");
				fprintf(stdout,"\nDo you want to continue(Y/N) :");
				rewind(stdin);				
				cont = getchar();
				#ifndef _WIN32
					getchar();
				#endif
			}
		}
	}
}
/*
 * doAccountManage
 */
void doAccountManage(CCmdOption options, vector<string>& commands)	{

	int count = commands.size();
	if(count <= 0) return;

	if(commands[0] == "account")	{
		
		if(commands.size() <= 1 || commands[1] != "manage")	{	
			doHelp(options,commands,0);
			return;
		}		

		if(commands[1] == "manage")	{
			int cont = 'y';
			while(cont == 'y' || cont == 'Y')
			{
				char optNumber[4];	
				fprintf(stdout,"\n\n1.List all Accounts\n2.Create Account\n3.Delete Account\n4.Modify Account ");
				fprintf(stdout,"\nEnter the option number from the above list: ");
				rewind(stdin);
				scanf("%[1-4]",optNumber);
				#ifndef _WIN32
					getchar();
				#endif
				int optAccount = atoi(optNumber);
				switch(optAccount)
				{
				case 1:
					{
						string toExecute = "user";
						string instNumber ="enumerate";	
						enumerateForInstance(options,commands,toExecute,instNumber);
					}
					break;
				case 2://Create Account
					{
					string toExecute = "computersystem";
					string instNumber ="";	
					fprintf(stdout,"\nSelect the Computer System Instances\n  ");
					enumerateForInstance(options,commands,toExecute,instNumber);

					string targetPath = "";
					targetPath.append("computersystem[");
					targetPath.append(instNumber);
					targetPath.append("]");
					options._target_specified = true;
					options._target 	= parseTargetPath (targetPath);

					commands.clear();
					commands.push_back("user");
					commands.push_back("add");		
				
					char details[500] ;
					fprintf(stdout,"\n\nEnter the User ID : ");
					rewind(stdin);
					gets(details);
					commands.push_back(details);
					string userstr = "";
					userstr.append(details);
					memset (details, '\0', sizeof(details));
					fprintf(stdout,"\n\nEnter the Password : ");
					rewind(stdin);
					gets(details);
					commands.push_back(details);
					memset (details, '\0', sizeof(details));
					fprintf(stdout,"\n\nEnter the organizationname : ");
					rewind(stdin);
					gets(details);
					if ( details[0] != '\0')
						commands.push_back(details);
					if(execCommand(options,commands) == -1)	{
						return;
					}	
					options._target_specified = false;
					options._target 	= parseTargetPath ("");

					int inst = getInstanceNumber(options,userstr);
					char inststr[10];
					sprintf(inststr,"%d",inst);

					int check = 'n';
					fprintf(stdout,"\nDo you want to Assign Roles to the account(Y/N) :");
					rewind(stdin);				
					check = getchar();
					#ifndef _WIN32
						getchar();
					#endif
					if(check == 'y' || check == 'Y')
						AssignRolesToAccount(options,commands,inststr);					
				}
					break;
				case 3:
					{
						//Delete Account
						string toExecute = "user";
						string instNumber ="";	
						enumerateForInstance(options,commands,toExecute,instNumber);

						string targetPath = "";
						targetPath.append("user[");
						targetPath.append(instNumber);
						targetPath.append("]");
						options._target_specified = true;
						options._target 	= parseTargetPath (targetPath);
						commands.clear();
						commands.push_back("delete");
						if(execCommand(options,commands) == -1)	{
							return;
						}
						options._target_specified = false;
						options._target 	= parseTargetPath ("");
					}
					break;						
				case 4:
					{ //Modify Account
						char instNumber[4];
						fprintf(stdout,"\n\n1.Change Password\n2.Assign Roles\n3.Remove Roles ");
						fprintf(stdout,"\nEnter the option number from the above list: ");
						rewind(stdin);
						scanf("%[1-3]",instNumber);
						#ifndef _WIN32
							getchar();
						#endif
						int optionNum = atoi(instNumber);
						if(optionNum == 1)//Change Password
						{
							string toExecute = "user";
							string instNumber ="";	
							enumerateForInstance(options,commands,toExecute,instNumber);

							string targetPath = "";
							targetPath.append("user[");
							targetPath.append(instNumber);
							targetPath.append("]");
							options._target_specified = true;
							options._target 	= parseTargetPath (targetPath);

							commands.clear();
							commands.push_back("changepassword");

							char details[500] ;
							fprintf(stdout,"\n\nEnter the New Password : ");
							rewind(stdin);
							gets(details);
							commands.push_back(details);
							if(execCommand(options,commands) == -1)	{
								return;
							}
							options._target_specified = false;
							options._target 	= parseTargetPath ("");
						}						
						else if(optionNum == 2)//Assign Roles
						{
							commands.clear();
							commands.push_back("enumerate");
							commands.push_back("user");
							if(execCommand(options,commands) == -1)	{
								return;
							}
							char instNumber[4];	
							fprintf(stdout,"\n\n\nChoose valid instance number from the above list : ");
							rewind(stdin);
							scanf("%[0-9]",instNumber);	
							#ifndef _WIN32
								getchar();
							#endif

							AssignRolesToAccount(options,commands,instNumber);							
						}
						else if(optionNum == 3)//Remove Roles
						{
							string toExecute = "user";
							string instNumber ="";	
							enumerateForInstance(options,commands,toExecute,instNumber);

							string targetPath = "";
							targetPath.append("user[");
							targetPath.append(instNumber);
							targetPath.append("]");
							options._target_specified = true;
							options._target 	= parseTargetPath (targetPath);

							commands.clear();
							commands.push_back("removeroles");

							char rolename[500];	
							fprintf(stdout,"\n\nEnter the Role Name(s) to Remove<Role_1>,<Role_2> : ");
							rewind(stdin);
							gets(rolename);
							string roles = "";
							roles.append(rolename);
							while (0 != roles.size ())
							{
								string role = roles.substr (0, roles.find (','));
								
								commands.push_back(role);
								if ((size_t)-1 == roles.find (','))
								{
									break;
								}
								roles = roles.substr(roles.find (',')+1,roles.size());
								
							}							
							if(execCommand(options,commands) == -1)	{
								return;
							}
							options._target_specified = false;
							options._target 	= parseTargetPath ("");
						}					
					}
					break;
				default:
					fprintf(stdout,"\nChoose Correct option from the list above ");
					return;
				}
				fprintf(stdout,"\nDo you want to continue(Y/N) :");
				rewind(stdin);				
				cont = getchar();
				#ifndef _WIN32
					getchar();
				#endif
			}
		}
	}
	return;
}

/*
 * doCapabilies
 */
void doCapabilities(CCmdOption options, vector<string>& commands)	{

	int count = commands.size();
	if(count <= 0) return;

	if(commands[0] == "capabilities")	
	{
		fprintf (stdout, " \nSupported Profiles\n\n");
		CSubject subject (options._user,
						options._password.c_str (),
						options._authtype,
						options._scheme,
						options._ignore_certificate ? 0 : 1,
						options._ignore_certificate ? 0 : 1,
						options._certificate_file,
						"",
						"",
						"",
						"",
						"",
						"",
						options._timeout);
		CCIMMAP cimmap (options._host, options._port);
		IClient* client = cimmap.connect (subject);	
		vector<string> vprofile;
		vprofile.clear();

		int cont = 'y';
		while(cont == 'y' || cont == 'Y')
		{
			try
			{
				/* enumerate the registered profile */
				CRegisteredProfile::iterator i = CRegisteredProfile::enumRegisteredProfile (client);
				
				int cnt=0;
				for (; i != CRegisteredProfile::iterator::end (); ++i)
				{
					/* get the instances of the registered profiles */
					CRegisteredProfile rp = *i;
					/* get the names of the registered profiles */
					try
					{
						if (cnt < 10)
							fprintf(stdout, "%d  : %s\n", cnt++,rp.getRegisteredName ().c_str());
						else
							fprintf(stdout, "%d : %s\n", cnt++,rp.getRegisteredName ().c_str());
					}
					catch ( EDSDKError &e)
					{
						fprintf (stdout, "Error getting registered name : %s\n", e.what());
					}
					
					string profileName = rp.getRegisteredName ().c_str();

					/* Convert the user Input string to lower case*/
/*
					for (size_t i = 0; i < profileName.size(); i++)
					{
						if (profileName[i] >= 0x41 && profileName[i] <= 0x5A)
						{
							profileName[i] = profileName[i] + 0x20;
						}
					}
*/
					/* Elimating the spaces from the UserInput string*/
					while ((size_t)-1 != profileName.find (' '))
					{
						profileName.erase (profileName.find (' '), 1);
					}
					vprofile.push_back(profileName);
										
				}// for
			} //try
			catch (exception &e)
			{			
				fprintf (stdout, "Error accessing registered profiles : %s\n", e.what());
			}
			
			char optNumber[4];	
			fprintf(stdout,"\nEnter the profile number to list supported features : ");
			rewind(stdin);
			scanf("%[0-9]",optNumber);
			#ifndef _WIN32
				getchar();
			#endif
			int profNumber = atoi(optNumber);
			
			if ( profNumber < (int)vprofile.size() )
			{
				string prof = vprofile[profNumber].c_str();

				/* Fan Capabilities */
				if (prof == "Fan")
				{
					try
					{
						/* enumerate the selected profile */
						CFan::iterator i = CFan::enumFans (client);

						for (; i != CFan::iterator::end (); ++i)
						{
							CFan fp = *i;
							try
							{
								fprintf(stdout, "\n%s\n", fp.getElementName().c_str());
								fprintf(stdout, "\n	Supported Extrinsic Methods at the Target :\n");
								if ( fp.capableOfSetFanSpeed())
								{
									fprintf(stdout, "	* SetFanSpeed()\n");
								}

								if ( fp.capableOfRequestStateChange())
								{								
									fprintf(stdout, "	* RequestStateChange()\n");
									fprintf(stdout, "\n		 Supported Modes :\n");

									vector<uint16> states_val = fp.getSupportedStates();
									vector<string> states_str = fp.getSupportedStatesStr();
									if ( states_val.size() !=0)
									{
										for (size_t i=0; i < states_val.size(); i++)
										{
											fprintf(stdout, "		* %d - %s\n", states_val[i], states_str[i].c_str() );
										}
									}								
								}	
							}// try
							catch ( EDSDKError &e)
							{
								fprintf (stdout, "%s\n", e.what());
							}
						}// for
					} //try
					catch (exception &e)
					{			
						fprintf (stdout, "Error accessing registered profiles : %s\n", e.what());
					}
				}//if Fan

				/*  Battery capabilities */
				else if (prof == "Battery")
				{
					try
					{
						/* enumerate the selected profile */
						CBattery::iterator i = CBattery::enumBattery (client);
						int cnt=0;
						vector<uint16> vbstates;
						vbstates.clear();
						/* get the instances of the selected profiles */
						CBattery bp = *i;
						/* get the names of the selected profiles */
						try
						{
							fprintf(stdout, "\nBattery# %d : %s\n", ++cnt, bp.getDeviceID ().c_str());
							fprintf(stdout, "\n	Supported Extrinsic Methods at the Target :\n");
							if ( bp.capableOfRequestStateChange()) 
							{
								fprintf(stdout, "	* RequestStateChange()\n");
									
								vector<string> states_str = bp.getSupportedStatesStr();
								if ( states_str.size() !=0)
								{
									for (size_t i=0; i < states_str.size(); i++)
									{
										fprintf(stdout, "	* %s\n", states_str[i].c_str() );
									}
								}
							}
							else
								fprintf(stdout, "	* No Methods Supported\n");

						}
						catch ( EDSDKError &e)
						{
							fprintf (stdout, "%s\n", e.what());
						}
					} //try
					catch (exception &e)
					{			
						fprintf (stdout, "Error accessing registered profiles : %s\n", e.what());
					}
				}//if Battery

				/*  Power State Management capabilities */
				else if (prof == "PowerStateManagement")
				{
					try
					{
						/* enumerate the selected profile */
						CComputerSystem::iterator i = CComputerSystem::enumComputerSystems (client);
//						vector<uint16> pmstates_val;
						vector<string> pmstates_str;
						for (; i != CComputerSystem::iterator::end (); ++i)
						{
							/* get the instances of the selected profiles */
							CComputerSystem cs = *i; 
							
							try
							{
								/* get the names of the selected Instance */
								fprintf(stdout, "\nComputer system : %s\n", cs.getElementName().c_str());
								fprintf(stdout, "\n	Supported Extrinsic Methods at the Target :\n");
								if ( cs.capableOfRequestPowerStateChange())
								{
									fprintf(stdout, "	* RequestPowerStateChange()\n");
									fprintf(stdout, "\n		Supported Power Modes :\n");
									pmstates_str.clear();
									pmstates_str = cs.getPowerStatesSupportedStr();
									for (int k=0; k < (int)pmstates_str.size(); k++)
									{
										fprintf(stdout, "		* %s\n",  pmstates_str[k].c_str());
									}			
									fprintf(stdout, "\n		Supported Power Change Capabilities :\n");
									pmstates_str.clear();
									pmstates_str = cs.getPowerChangeCapabilitiesStr();
									for (int k=0; k < (int)pmstates_str.size(); k++)
									{
										fprintf(stdout, "		* %s\n",  pmstates_str[k].c_str());
									}			
								}
								else
									fprintf(stdout, "	* No Methods Supported\n");

								fprintf(stdout, "\n");
							}
							catch ( EDSDKError &e)
							{
								fprintf (stdout, "%s\n", e.what());
							}
						}// for
					} //try
					catch (exception &e)
					{			
						fprintf (stdout, "Error accessing registered profiles : %s\n", e.what());
					}
				}//if Power State Management 

				/*  BIOS Management capabilities */
				else if (prof == "BIOSManagement")
				{
					try
					{
						/* enumerate the selected profile */
						CBIOSElement::iterator i = CBIOSElement::enumBIOSElements (client);		
						for (; i != CBIOSElement::iterator::end (); ++i)
						{
							/* get the instances of the selected profiles */
							CBIOSElement be = *i; 
							try
							{
								/* get the names of the selected profiles */
								fprintf(stdout, "\nBIOS : %s\n", be.getName().c_str());
								fprintf(stdout, "\n	Supported Extrinsic Methods at the Target :\n");
								if ( be.capableOfRestoreDefaults() ) 
									fprintf(stdout, "	* RestoreBIOSDefaults()\n");
								if ( be.capableOfReadRawBIOSData() ) 
									fprintf(stdout, "	* ReadRawBIOSData()\n");
								if ( be.capableOfWriteRawBIOSData() ) 
									fprintf(stdout, "	* WriteRawBIOSData()\n");

								CBIOSAttribute::iterator k = CBIOSAttribute::enumBIOSAttributes(client);
								/* Here we assume that, if there is a BIOSAttribute instance exists, then we can 
								*  verify whether a SetBIOSAttribute() methos exists or not.
								*/ 
								if ( !(k == CBIOSAttribute::iterator::end()) )
								{
									CBIOSAttribute ba = *k;
									if ( ba.capableOfSetBIOSAttribute() ) 
										fprintf(stdout, "	* SetBIOSAttribute()\n");
									if ( ba.capableOfSetBIOSAttributeEmbeddedInstance() ) 
										fprintf(stdout, "	* SetBIOSAttributeEmbeddedInstance()\n");
									if ( ba.capableOfSetBIOSAttributes() ) 
										fprintf(stdout, "	* SetBIOSAttributes()\n");
									vector<string> encod_str;
									if (ba.getSupportedEncodingsStr(encod_str) )
									{
										fprintf(stdout, "\n	SupportedEncodings :\n");
										for ( size_t i=0; i< encod_str.size(); i++)
										{
											fprintf(stdout, "	* %s\n", encod_str[i].c_str());
										}
									}
									vector<string> algo_str;
									if (ba.getSupportedPasswordAlgorithms(algo_str) )
									{
										fprintf(stdout, "\n	SupportedPasswordAlgorithms :\n");
										for ( size_t i=0; i< algo_str.size(); i++)
										{
											fprintf(stdout, "	* %s\n", algo_str[i].c_str());
										}
									}
								}
								fprintf(stdout, "\n");
							}
							catch ( EDSDKError &e)
							{
								fprintf (stdout, "%s\n", e.what());
							}
						}//for
					} //try
					catch (exception &e)
					{			
						fprintf (stdout, "Error accessing registered profiles : %s\n\n", e.what());
					}
				}//if BIOS Management 

				/*  Boot Control capabilities */
				else if (prof == "BootControl")
				{
					try
					{
						CComputerSystem::iterator i = CComputerSystem::enumComputerSystems (client);
						CComputerSystem cs = *i;
						/* enumerate the selected profile */
						CBootConfig::iterator k = CBootConfig::enumBootConfigs (client);
						/* Here if we get at least one instance of bootconig associated with computer system,
						 * then we try to find the supported metnods are available or not. 
						 */
						CBootConfig bc = *k;
						try
						{								
							/* get the names of the selected Instance */
							fprintf(stdout, "Boot Config Service:\n");
							fprintf(stdout, "\n	Supported Extrinsic Methods at the Target :\n");
							if ( bc.capableOfAddBootConfig(cs) ) 
								fprintf(stdout, "	* addBootConfig()\n");
							if ( bc.capableOfDeleteBootConfig(cs) ) 
								fprintf(stdout, "	* deleteBootConfig()\n");
							if ( bc.capableOfSetDefaultBoot() ) 
								fprintf(stdout, "	* setDefaultBoot()\n");
							if ( bc.capableOfSetNextBoot() ) 
								fprintf(stdout, "	* setNextBoot()\n");
							if ( bc.capableOfchangeBootOrder() ) 
								fprintf(stdout, "	* ChangeBootOrder()\n");

							vector<string> states_str;
							if ( bc.getBootCapabilitiesSupportedStr(cs, states_str) )
							{
								fprintf(stdout, "\n		Supported BootCapabilities :\n");
								for ( size_t i=0; i<states_str.size(); i++)
								{
									fprintf(stdout, "		* %s\n", states_str[i].c_str());
								}
							}
							states_str.clear();
							if (bc.getBootStringsSupportedStr(cs, states_str))
							{
								fprintf(stdout, "\n		Supported Boot Strings :\n");
								for ( size_t i=0; i<states_str.size(); i++)
								{
								fprintf(stdout, "		* %s\n", states_str[i].c_str());
								}
							}
							fprintf(stdout, "\n"); 
						}
						catch ( EDSDKError &e)
						{
							fprintf (stdout, "%s\n", e.what());
						}
					} //try
					catch (exception &e)
					{			
						fprintf (stdout, "Error accessing registered profiles : %s\n", e.what());
					}
				}//if Boot Config 

				/*  Role Based Authorization capabilities */
				else if (prof == "RoleBasedAuthorization")
				{
					try
					{
						CRole::iterator l = CRole::enumRoles (client);
						/* get the instances of the selected profiles */
						CRole rp = *l;
						/* get the names of the selected Instance */
						fprintf(stdout, "\n	Supported Extrinsic Methods at the Target :\n");
						
						if (rp.capableOfCreateRole())
							fprintf(stdout, "	* CreateRole()\n");

						if (rp.capableOfDeleteRole())
							fprintf(stdout, "	* DeleteRole()\n");
						
						if (rp.capableOfModifyRole())
							fprintf(stdout, "	* ModifyRole()\n");
						if (rp.capableOfAssignRoles())
							fprintf(stdout, "	* AssignRoles()\n");
						if (rp.capableOfShowRoles())
							fprintf(stdout, "	* ShowRoles()\n");
						if (rp.capableOfShowAccess())
							fprintf(stdout, "	* ShowAccess()\n");

						fprintf(stdout, "\n");
					} //try
					catch (exception &e)
					{			
						fprintf (stdout, "Error accessing registered profiles : %s\n", e.what());
					}
				}//if Role Based Authorization

				/*  Simple Identity Management capabilities */
				else if (prof == "SimpleIdentityManagement")
				{
					try
					{
						/* enumerate the selected profile */
						CUser::iterator k = CUser::enumUsers (client);
						/* get the instances of the selected profiles */
						CUser up = *k;
						/* get the names of the selected Instance */
						fprintf(stdout, "\n	Supported Extrinsic Methods at the Target :\n");

						if (up.capableOfCreateUser()) 
							fprintf(stdout, "	* CreateUser()\n");
						if (up.capableOfDeleteUser()) 
							fprintf(stdout, "	* DeleteUser()\n");
						if (up.capableOfModifyUser()) 
							fprintf(stdout, "	* ModifyUser()\n");
						if (up.capableOfAssignRoles()) 
							fprintf(stdout, "	* AssignRoles()\n");
						if (up.capableOfRemoveRoles()) 
							fprintf(stdout, "	* RemoveRoles()\n");
						if (up.capableOfRequestStateChange()) 
							fprintf(stdout, "	* RequestedStateChang()\n");
						vector<string> states;
						fprintf(stdout, "\n		Supported States :\n");
						if ( up.getRequestedStatesSupportedStr(states) == true)
						{
							for ( size_t i=0; i < states.size(); i++)
								fprintf(stdout, "		* %s\n", states[i].c_str());
						}
						else
							fprintf(stdout, "\n		* No states Supported :\n");


						fprintf(stdout, "\n");
					} //try
					catch (exception &e)
					{			
						fprintf (stdout, "Error accessing registered profiles : %s\n", e.what());
					}
				}//if Simple Identity Management

				/* Text Console Redirection Capabilities */
				else if (prof == "TextConsoleRedirection")
				{
					try
					{
						/* enumerate the selected profile */
						CTextRedirection::iterator  i = CTextRedirection::enumTextRedirections (client);
						/* get the instances of the selected profiles */
						CTextRedirection tr = *i;

						try
						{
							/* get the names of the selected profiles */
							fprintf(stdout, "\n	Supported Extrinsic Methods at the Target :\n");
							if ( tr.capableOfTRSAPRequestStatesChange() )
							{
								fprintf(stdout, "	* TRSAPRequestStateChange()\n");
								vector<string> states_str; 
								if ( tr.getSupportedStatesStr(states_str))
								{
									fprintf(stdout, "\n		Supported Modes :\n");
									for (size_t i=0; i < states_str.size(); i++)
									{
										fprintf(stdout, "		* %s\n", states_str[i].c_str());
									}
								}
							}
							
							if ( tr.capableOfTRServiceRequestStatesChange() )
							{
								fprintf(stdout, "\n	* TRServiceRequestStateChange()\n");
								vector<string> states_str; 
								if ( tr.getSupportedStatesStr(states_str))
								{
									fprintf(stdout, "\n		Supported Modes :\n");
									for (size_t i=0; i < states_str.size(); i++)
									{
										fprintf(stdout, "		* %s\n", states_str[i].c_str());
									}
								}
							}
							else
								fprintf(stdout, "\n	* No Methods Supported\n");
						
						}// try
						catch ( EDSDKError &e)
						{
							fprintf (stdout, "%s\n", e.what());
						}
						fprintf(stdout, "\n");
					} //try
					catch (exception &e)
					{			
						fprintf (stdout, "Error accessing registered profiles : %s\n", e.what());
					}
				}//if Text Redirection
				/* USB Redirection Capabilities */
				else if (prof == "USBRedirection")
				{
					try
					{
						/* enumerate the selected profile */
						CUSBRedirection::iterator  i = CUSBRedirection::enumUSBRedirections (client);

						/* get the instances of the selected profiles */
						CUSBRedirection ur = *i;
						try
						{
							/* get the names of the selected profiles */
							fprintf(stdout, "\n	Supported Extrinsic Methods at the Target :\n");
							if ( ur.capableOfUSBRSAPRequestStatesChange() )
							{
								fprintf(stdout, "	* USBRSAPRequestStateChange()\n");
								vector<string> states_str;
								if (ur.getSupportedStatesStr(states_str))
								{
									fprintf(stdout, "\n		Supported Modes :\n");
									for (size_t i=0; i < states_str.size(); i++)
									{
										fprintf(stdout, "		* %s\n", states_str[i].c_str());
									}
								}
							}

							if ( ur.capableOfUSBRServiceRequestStatesChange() )
							{
								fprintf(stdout, "\n	* USBRServiceRequestStateChange()\n");
								vector<string> states_str;
								if (ur.getSupportedStatesStr(states_str))
								{
									fprintf(stdout, "\n		Supported Modes :\n");
									for (size_t i=0; i < states_str.size(); i++)
									{
										fprintf(stdout, "		* %s\n", states_str[i].c_str());
									}
								}
							}
							fprintf(stdout, "\n");
						}// try
						catch ( EDSDKError &e)
						{
							fprintf (stdout, "%s\n", e.what());
						}
					} //try
					catch (exception &e)
					{			
						fprintf (stdout, "Error accessing registered profiles : %s\n", e.what());
					}
				}//if USB Redirection
				else
				{
					fprintf(stdout, "\n%s Profile does not expose any capabilities\n\n", vprofile[profNumber].c_str() );				
				}	
			}// profNumber
			else
				fprintf(stdout, "\nSelection is out of range\n");	

			fprintf(stdout,"\nDo you want to continue(Y/N) :");
			rewind(stdin);				
			cont = getchar();
			#ifndef _WIN32
				getchar();
			#endif
		}// while
		delete client;
	} // if capabilities

	return;
}


void enumerateForInstance(CCmdOption options,vector<string>& commands,string toExecute,string &instNum)
{
	commands.clear();
	commands.push_back("enumerate");
	commands.push_back(toExecute);
	if(execCommand(options,commands) == -1)	{
		return;
	}
	if(instNum.empty())
	{
		char instNumber[4];	
		fprintf(stdout,"\n\n\nChoose valid instance number from the above list : ");
		rewind(stdin);
		scanf("%[0-9]",instNumber);
		#ifndef _WIN32
			getchar();
		#endif
		if(instNumber[0] < 0)
			instNum = "";
		else
			instNum.append(instNumber);
	}
}
void AssignRolesToAccount(CCmdOption options,vector<string>& commands,char* instNumber)
{
	CSubject subject (options._user,
							  options._password.c_str (),
							  options._authtype,
							  options._scheme,
							  options._ignore_certificate ? 0 : 1,
							  options._ignore_certificate ? 0 : 1,
							  options._certificate_file,
							  "",
							  "",
							  "",
							  "",
							  "",
							  "",
							  options._timeout);
	CCIMMAP cimmap (options._host, options._port);
	IClient* client = cimmap.connect (subject);	
	CRole::iterator iter = CRole::enumRoles (client);
	vector<string> vecrole;

	int i = 0;     
	for (; iter != CRole::iterator::end (); ++iter)
	{
		fprintf (stdout, " \nRole Instance %d\n", i);
		fprintf (stdout, "Role Name   : %s    \n\n ", (*iter).getElementName ().c_str ()); 
		vecrole.push_back((*iter).getElementName ());
		i++;
	}
	
	string targetPath = "";
	targetPath.append("user[");
	targetPath.append(instNumber);
	targetPath.append("]");
	options._target_specified = true;
	options._target 	= parseTargetPath (targetPath);

	commands.clear();
	commands.push_back("assignroles");

	char rolename[500];	
	fprintf(stdout,"\n\n\nEnter instance number(s) from the above list to Assign Roles[<Instance_1>,<Instance_2>] : ");
	rewind(stdin);
	gets(rolename);
	string roles = "";
	roles.append(rolename);
	while (0 != roles.size ())
	{
		string role = roles.substr (0, roles.find (','));
		int instrole = atoi(role.c_str());
		int size = vecrole.size();
		
		if(instrole < size)
		{
			commands.push_back(vecrole[instrole]);		
		}			
		if ((size_t)-1 == roles.find (','))
		{
			break;
		}
		roles = roles.substr(roles.find (',')+1,roles.size());		
	}	

	
	if(commands.size() == 1)
	{
		fprintf(stdout,"\nEnter correct instance number");
		return;
	}

	if(execCommand(options,commands) == -1)	{
		return;
	}
	options._target_specified = false;
	options._target 	= parseTargetPath ("");
}
void GetRoles(CCmdOption options)
{
	CSubject subject (options._user,
							  options._password.c_str (),
							  options._authtype,
							  options._scheme,
							  options._ignore_certificate ? 0 : 1,
							  options._ignore_certificate ? 0 : 1,
							  options._certificate_file,
							  "",
							  "",
							  "",
							  "",
							  "",
							  "",
							  options._timeout);
	CCIMMAP cimmap (options._host, options._port);
	IClient* client = cimmap.connect (subject);	
	CRole::iterator iter = CRole::enumRoles (client);

	vector<CRole>  ret;
	int i = 0;     
	for (; iter != CRole::iterator::end (); ++iter)
	{
		fprintf (stdout, " \nRole Instance %d\n", i);
		fprintf (stdout, "Role Name   : %s    \n\n ", (*iter).getElementName ().c_str ()); 
		i++;
	}
}

int getInstanceNumber(CCmdOption options,string userid)
{
	CSubject subject (options._user,
							  options._password.c_str (),
							  options._authtype,
							  options._scheme,
							  options._ignore_certificate ? 0 : 1,
							  options._ignore_certificate ? 0 : 1,
							  options._certificate_file,
							  "",
							  "",
							  "",
							  "",
							  "",
							  "",
							  options._timeout);
	CCIMMAP cimmap (options._host, options._port);
	IClient* client = cimmap.connect (subject);	
	int inst = 0;
	CUser::iterator iter = CUser::enumUsers (client);
	for (;iter != CUser::iterator::end (); ++iter)
	{
		if (userid == (*iter).getUserID ())				
			break;
		inst++;
	}
	
	return inst;
}


/*
 * execCommand
 */
int 
execCommand (CCmdOption options, vector<string> commands)
{
	int ret = 0;

	if ((commands.size () != 0) && 
		(commands [0] == "discover")) 	{ ret = doDiscovery (options, commands); }
	else if ((commands.size () != 0) && 
		(commands [0] == "raw")) 	{ ret = doRaw (options, commands); }
	else if ((commands.size () != 0) && 
		(commands [0] == "indication")) 	{ ret = doIndication (options, commands); }
	else if ((commands.size () != 0) &&
			 (commands [0] == "listenevents")) 	{ doListenEvents (options, commands); }
	else if ((commands.size () != 0) &&
			 (commands [0] == "textredirection")) 	{ doTextRedirection (options, commands); }
	else if ((commands.size () != 0) &&
			 (commands [0] == "usbredirection")) 	{ doUSBRedirection (options, commands); }	
	else if ((commands.size () != 0) &&
			 (commands [0] == "account")) 	{ doAccountManage (options, commands); }
	else if ((commands.size () != 0) &&
			 (commands [0] == "roles")) 	{ doRolesManage (options, commands); }
	else if ((commands.size () != 0) &&
			 (commands [0] == "capabilities")) 	{ doCapabilities (options, commands); }
	else if ((commands.size () != 0) &&
			 (commands [0] == "help")) 	{ doHelp (options, commands, 1); }
	else if ((commands.size () != 0) &&
			 (commands [commands.size () - 1] == "help")) 
	{ 
		doHelp (options, commands, 0);
	}
	else 
	{
		try
		{
			CSubject subject (options._user,
							  options._password.c_str (),
							  options._authtype,
							  options._scheme,
							  options._ignore_certificate ? 0 : 1,
							  options._ignore_certificate ? 0 : 1,
							  options._certificate_file,
							  "",
							  "",
							  "",
							  "",
							  "",
							  "",
							  options._timeout);
			CCIMMAP cimmap (options._host, options._port);
			IClient* client = cimmap.connect (subject);

			CRootExec re;

			try 
			{
				ret = re.execute (client, options, commands, 0);
			}

			catch (exception& e)
			{
				fprintf (stderr, "Error: %s\n", e.what ());
				ret = -1;
			}

			delete client;
		}
		catch (exception& e)
		{
			fprintf (stderr, "Error: %s\n", e.what ());
			ret = -1;
		}
	}

	return ret;

}

};  /* namespace dashcli */





