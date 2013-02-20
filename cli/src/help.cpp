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
 * help.cpp
 * Displays context based help.
 */
#include "help.h"
#include "targetpath.h"
#include "dashcli.h"
#include "stdio.h"
using namespace std;

namespace dashcli
{

/*
 * displayGeneralHelp
 */
void
displayGeneralHelp (void)
{
	if (!isShell)
	{
		fprintf (stdout, "Usage: dashcli [options] commands\n");
	}
	else
	{
		fprintf (stdout, "Usage: [options] commands\n");
	}
	fprintf (stdout, "\nOptions allowed:\n");
	fprintf (stdout, "\t-h <host>               Host Name\n");
	fprintf (stdout, "\t-p <port(s)>            Server Port(s)(For discovery more than one ports can be specified seperated by commas)\n");
	fprintf (stdout, "\t-u <username>           User Name\n");
	fprintf (stdout, "\t-P <password>           Password\n");
	fprintf (stdout, "\t-a <digest|basic|gss>   Authentication Type [default=digest]\n");
	fprintf (stdout, "\t-S <http|https>         HTTP Scheme [default=http]\n");
#ifdef WIN32
	fprintf (stdout, "\t-C                      Ignore certificate/do not verify certificate (To verify, certificate should be stored in certificate store)\n");
#else
	fprintf (stdout, "\t-c <certificate>        Certificate file (Alternatively certificate can be stored in certificate store)\n");
	fprintf (stdout, "\t-C                      Ignore certificate/do not verify certificate\n");
#endif
	fprintf (stdout, "\t-t <targetpath>         Target Path\n");
	fprintf (stdout, "\t-s <startip>            Start IP address for discovery (only for discovery)\n");
	fprintf (stdout, "\t-e <endip>              End IP address for discovery (only for discovery)\n");
	fprintf (stdout, "\t-T <timeout>            Timeout in seconds\n");
	fprintf (stdout, "\t-v <1|2>                Verbose Level [ 1 - More explanation on error or 2-Dump WSMAN data]\n");
	fprintf (stdout, "\t-o <verboseoutput>      Verbose output file to dump wsman data [default is sdtout]. \n");

	fprintf (stdout, "\nCommands allowed:\n");
	fprintf (stdout, "\thelp                    Display help\n");
	fprintf (stdout, "\tenumerate               Enumerate targets\n");
	fprintf (stdout, "\tshow                    Show dashcli information\n");
	fprintf (stdout, "\tdiscover                Perform discovery\n");
	fprintf (stdout, "\tregisteredprofile       Checks the profile support\n");
	fprintf (stdout, "\tindication              Indication commands(subscribe for indication, create filters/destinations\n");
	fprintf (stdout, "\tlistenevents            Listen for events/alerts\n");
	fprintf (stdout, "\ttextredirection         Configure Text Redirection services\n");
	fprintf (stdout, "\tusbredirection          Configure USB Redirection services\n");
	fprintf (stdout, "\traw                     Issue raw commands\n");
	fprintf (stdout, "\taccount			Creates,Deletes and Manages the Account\n");
	fprintf (stdout, "\troles			Creates,Deletes and Manages the Roles\n");
	if (!isShell)
	{
		fprintf (stdout, "\tshell                   Launch interactive DASH shell\n");
	}
	else
	{
		fprintf (stdout, "\texit                   Exit shell\n");
	}
	fprintf (stdout, "\tcapabilities		Display Capabilities of a target\n");
	fprintf (stdout, "\nFor commands specific to targets\n");
	fprintf (stdout, "\tdashcli help target\n");
	fprintf (stdout, "\nWhere allowed targets are\n");
	fprintf (stdout, "\tregisteredprofile\n");
	fprintf (stdout, "\tcomputersystem\n");
	fprintf (stdout, "\tprocessor\n");
	fprintf (stdout, "\tmemory\n");
	fprintf (stdout, "\tasset\n");
	fprintf (stdout, "\tbootconfig\n");
	fprintf (stdout, "\tbios\n");
	fprintf (stdout, "\tpowersupply\n");
	fprintf (stdout, "\tfan\n");
	fprintf (stdout, "\tsoftware\n");
	fprintf (stdout, "\toperatingsystem\n");
	fprintf (stdout, "\tbattery\n");
	//fprintf (stdout, "\tuser\n");
	fprintf (stdout, "\trole\n");
	fprintf (stdout, "\tnetworkport\n");
	fprintf (stdout, "\tdhcpclient\n");
	fprintf (stdout, "\tipinterface\n");
	fprintf (stdout, "\tdnsclient\n");
	fprintf (stdout, "\topaquemanagementdata\n");
	//fprintf (stdout, "\ttextredirection\n");
	//fprintf (stdout, "\tusbredirection\n");
	//fprintf (stdout, "\tindicationfilter\n");
	//fprintf (stdout, "\tfiltercollection\n");
	//fprintf (stdout, "\talertdestination\n");
	fprintf (stdout, "\tindicationsubscription\n");
	fprintf (stdout, "\tethernetport\n");

	fprintf (stdout, "\nExample usage:\n");
	fprintf (stdout, "Discovery example:\n");
	if (!isShell)
	{
		fprintf (stdout, "dashcli -s 192.168.0.4 -e 192.168.0.15 -u admin -P admin -p 623 discover\n");
		fprintf (stdout, "dashcli -s 192.168.0.4 -e 192.168.0.15 -p 623 discover\n");
		fprintf (stdout, "dashcli -s 192.168.0.4 -e 192.168.0.15 -p 623,664,8889 discover\n");
		fprintf (stdout, "dashcli -s 192.168.0.4 -e 192.168.0.15 -S http  -p 623 discover\n");
		fprintf (stdout, "dashcli -s 192.168.0.4 -e 192.168.0.15 -S https -p 664 discover\n");
		fprintf (stdout, "dashcli -s 192.168.0.4 -e 192.168.0.15 discover info\n");
		fprintf (stdout, "dachcli -h hounds-demo -S http -p 623 discover\n");
		fprintf (stdout, "dachcli -h 192.168.0.8 -S http -p 623 discover\n");
		fprintf (stdout, "dachcli -h hounds-demo -S http -p 623 discover info\n");
		fprintf (stdout, "dachcli -h 192.168.0.8 -S http -p 623 discover info\n");
	}
	else
	{
		fprintf (stdout, "dashcli -s 192.168.0.4 -e 192.168.0.15 -u admin -P admin -p 623 discover\n");
		fprintf (stdout, "-s 192.168.0.4 -e 192.168.0.15 -p 623,664,8889 discover\n");
		fprintf (stdout, "dachcli -h hounds-demo -S http -p 623 discover\n");
		fprintf (stdout, "dachcli -h 192.168.0.8 -S http -p 623 discover\n");
		fprintf (stdout, "dachcli -h hounds-demo -S http -p 623 discover info\n");
		fprintf (stdout, "dachcli -h 192.168.0.8 -S http -p 623 discover info\n");
	}

	fprintf (stdout, "\nEnumerate target example:\n");
	if (!isShell)
	{
		fprintf (stdout, "dashcli -h 192.168.0.4 -p 623 -u admin -P admin enumerate computersystem\n");
		fprintf (stdout, "dashcli -h 192.168.0.4 -p 623 -u admin -P admin enumerate processor\n");
		fprintf (stdout, "dashcli -h 192.168.0.4 -p 623 -u admin -P admin enumerate bootconfig\n");

		fprintf (stdout, "\nExecuting commands on a target example:\n");
		fprintf (stdout, "dashcli -h 192.168.0.4 -p 623 -u admin -P admin -t computersystem[0] power on\n");
		fprintf (stdout, "dashcli -h 192.168.0.4 -p 623 -u admin -P admin -t processor[0] enumerate memory\n");
		fprintf (stdout, "dashcli -h 192.168.0.4 -p 623 -u admin -P admin -t bootconfig[0] changebootorder 1 0\n");
	}
	else
	{
		fprintf (stdout, "enumerate computersystem\n");
		fprintf (stdout, "-h 192.168.0.4 -p 623 -u admin -P admin enumerate computersystem\n");
	}
}

/*
 * Displays computer system help
 */
void 
displayCapabilitiesHelp (const vector<string>& commands, size_t ix)
{


	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tlist		List Profiles supported on a target\n");
		fprintf (stdout, "\tmethods		Display methos supported in a profile\n");
		fprintf (stdout, "\tmodes		List modes supported for a operations\n");
		return;
	}

	/* Get the command */

	string cmd = commands [ix];
	if (cmd == "list")
	{
		fprintf (stdout, "List Profiles supported on a target\n");
		return;
	}
	else if (cmd == "methods")
	{
		fprintf (stdout, "<profile> method \n");
		return;
	}
	else if (cmd == "modes")
	{
		fprintf (stdout, "<profile> modes \n");
		return;
	}

	return;
}


/*
 * Displays computer system help
 */
void 
displayComputerSystemHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tpower       [status|on|offcycle|reset|resetgraceful|offgraceful|supportedstates]\n");
		fprintf (stdout, "\tenumerate   processor|sensor|fan|memory|asset\n");
		fprintf (stdout, "\tuser        add\n");
		fprintf (stdout, "\trole        add|getsupportedqualifiers\n");
		fprintf (stdout, "\tbootconfig  add\n");
		fprintf (stdout, "\topaquemanagementdata  create\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this computer system\n");
		return;
	}
	else if (cmd == "power")
	{
		fprintf (stdout, "power [status|on|off|cycle|reset|resetgraceful|offgraceful|supportedstates]\n");
		fprintf (stdout, "\tstatus           :Display the current power status\n");
		fprintf (stdout, "\ton               :Power on\n");
		fprintf (stdout, "\toff              :Power off\n");
		fprintf (stdout, "\tcycle            :Power cycle\n");
		fprintf (stdout, "\treset            :Power reset\n");
		fprintf (stdout, "\tresetgraceful    :Power reset gracefully\n");
		fprintf (stdout, "\toffgraceful      :Power off gracefully\n");
		fprintf (stdout, "\tsupportedstates  :Power supported states\n");
		return;
	}
	else if (cmd == "enumerate")
	{
		fprintf (stdout, "enumerate processor|sensor|fan|memory|asset]\n");
		fprintf (stdout, "\tprocessor Enumerate the processors in this system\n");
		fprintf (stdout, "\tsensor    Enumerate the sensors in this system\n");
		fprintf (stdout, "\tfan       Enumerate the fans in this system\n");
		fprintf (stdout, "\tmemory    Enumerate the memory in this system\n");
		fprintf (stdout, "\tasset     Enumerate the asset in this system\n");
		return;
	}
	else if (cmd == "user")
	{
		if ((ix + 1) == commands.size ())
		{
			fprintf (stdout, "Allowed commands:\n");
			fprintf (stdout, "\tadd <username> <password> [<organizationname>]\n");
			return;
		}

		cmd = commands [ix + 1];
		if (cmd == "add")
		{
			fprintf (stdout, "Adds a user to this computer system\n");
			fprintf (stdout, "Usage : add <user_id> <password> [<organizationname>]\n");
			fprintf (stdout, "Example: user add testuser testpassword\n");
		}
		else
		{
			fprintf (stdout, "Allowed commands:\n");
			fprintf (stdout, "add <user_id> <password> [<organizationname>]\n");
		}
		return;
	}
	else if (cmd == "role")
	{
		if ((ix + 1) == commands.size ())
		{
			fprintf (stdout, "Allowed commands:\n");
			fprintf (stdout, "\tadd <rolename> <permission_1> [<permission_2>... <permission_n>]\n");
			fprintf (stdout, "\tgetsupportedqualifiers\n");
			return;
		}

		cmd = commands [ix + 1];
		if (cmd == "add")
		{
			fprintf (stdout, "Usage : add <rolename> <permission_1> [<permission_2>... <permission_n>]\n");
			fprintf (stdout, "Where permission are constructed using supported activites and qualifiers seperated by commans as below\n");
			fprintf (stdout, "\"activities, qualifiers\"\n\n");
			fprintf (stdout, "Where activities are one of these  \"create|delete|detect|read|write|execute|other\" \n");
			fprintf (stdout, "List of supported qualifiers can be obtained using \"role getsupportedqualifiers\" command\n\n");
			fprintf (stdout, "Example : role add adminrole \"execute,SP Login\" \"write, Clear Log\" \"execute, KVM redirection\"\n");

		}
		/*else if (cmd == "getsupportedqualifiers")
		{
			fprintf (stdout, "List the supported privilege qualifiers by the target\n");
			fprintf (stdout, "Usage: getsupportedqualifiers\n"); */
		// }
		else {
			fprintf (stdout, "\nAllowed commands:\n");
			fprintf (stdout, "\tadd <rolename> <permission_1> [<permission_2>... <permission_n>]\n");
		//	fprintf (stdout, "\tgetsupportedqualifiers\n");
		}
		return;
	}
	else if (cmd == "bootconfig")
	{
		 if ((ix + 1) == commands.size ())
		 {
			fprintf (stdout, "Allowed commands:\n");
			fprintf (stdout, "\tadd <existbootconfiginstancenum> <defaultboot>, <nextboot> <bootorderlistfromtemplateinstance>\n");
			return;
		 }

		 cmd = commands [ix + 1];
		 if (cmd == "add")
		 {
			fprintf (stdout, "Adds a boot configuration to this computer system\n");
			fprintf (stdout, "Usage: add <existbootconfiginstancenum> <defaultboot>, <nextboot> <bootorderlistfromtemplateinstance>\n");
			fprintf (stdout, "where :\nexistbootconfiginstancenum        - Instance number of existing boot configuration to be used for as template for new instance\n");
			fprintf (stdout, "defaultboot                       - true|false\n");
			fprintf (stdout, "nextboot                          - true|false\n");
			fprintf (stdout, "bootorderlistfromtemplateinstance - bootorder from the config instance specified in existbootconfiginstancenum. Ex 2 0 1.\n");
		 }
		 else 
		 {
			fprintf (stdout, "Allowed commands:\n");
			fprintf (stdout, "\tadd <existbootconfiginstancenum> <defaultboot>, <nextboot> <bootorderlistfromtemplateinstance>\n");
		 }
		 return;
	}

	else if (cmd == "opaquemanagementdata")
	{
		if ((ix + 1) == commands.size ())
		{
			fprintf (stdout, "Allowed commands:\n");
			fprintf (stdout, "\tcreate <name> <size> <[<storagelocation>]\n");
			fprintf (stdout, "Creates a opaquemanagementdata to this computer system\n");
			return;
		}

		cmd = commands [ix + 1];
		if (cmd == "create")
		{
			fprintf (stdout, "Creates a opaquemanagementdata to this computer system\n");
			fprintf (stdout, "Usage : create <name> <size> <[<storagelocation>]\n");
			fprintf (stdout, "Example: opaquemanagementdata create name 100\n");
			fprintf (stdout, "name             - Name for the new Opaque Management Data\n");
			fprintf (stdout, "size             - Size of Opaque Management Data in bytes\n");
			fprintf (stdout, "storagelocation  - Optional, if not specified, locaton depends on implementation\n");										
		}
		else
		{
			fprintf (stdout, "Allowed commands:\n");
			fprintf (stdout, "create <name> <size> [<storagelocation>]\n");
		}
		return;
	}

	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tpower       [status|on|off|resetgraceful|cycle|reset|supportedstates]\n");
		fprintf (stdout, "\tenumerate   processor|sensor|fan|memory|asset\n");
		fprintf (stdout, "\tuser        add\n");
		fprintf (stdout, "\trole        add\n");
		fprintf (stdout, "\tbootconfig  add\n");
		fprintf (stdout, "\topaquemanagementdata  create\n");
		return;
	}
}


/*
 * Displays processor help
 */
void 
displayProcessorHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tstatus\n");
		fprintf (stdout, "\tenumerate  sensor|fan|memory|asset\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this processor\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}
	else if (cmd == "status")
	{
		fprintf (stdout, "Shows the current status of this processor\n");
		fprintf (stdout, "Usage : status\n");
		return;
	}
	else if (cmd == "enable")
	{
		fprintf (stdout, "Enable this processor\n");
		fprintf (stdout, "Usage : enable\n");
		return;
	}
	else if (cmd == "disable")
	{
		fprintf (stdout, "Disable this processor\n");
		fprintf (stdout, "Usage : disable\n");
		return;
	}
	else if (cmd == "enumerate")
	{
		fprintf (stdout, "enumerate  sensor|fan|memory|asset\n");
		fprintf (stdout, "\tsensor    Enumerate the sensors in this system\n");
		fprintf (stdout, "\tfan       Enumerate the fans in this system\n");
		fprintf (stdout, "\tmemory    Enumerate the memory in this system\n");
		fprintf (stdout, "\tasset     Enumerate the asset in this system\n");
		return;
	}
	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tstatus\n");
		fprintf (stdout, "\tenumerate  sensor|fan|memory|asset\n");
		return;
	}
}


/*
 * Displays memory help
 */
void 
displayMemoryHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this memory\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}
	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}
}


/*
 * Displays Asset help
 */
void 
displayAssetHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this asset\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}
	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}
}

/*
 * Displays sensor help
 */
void 
displaySensorHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\treading\n");
		fprintf (stdout, "\tsetthreshold lnc|unc|lc|uc|lf|uf <thresholdvalue>\n");
		//fprintf (stdout, "\teventsubscribe [push|pushack|pushbatch|pull] heartbeat expiration [listenevent [unsubscribe]]\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this sensor\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}
	else if (cmd == "reading")
	{
		fprintf (stdout, "Shows the current reading of this sensor\n");
		fprintf (stdout, "Usage : reading\n");
		return;
	}
	else if (cmd == "setthreshold")
	{
		fprintf (stdout, "setthreshold lnc|unc|lc|uc|lf|uf <thresholdvalue>\n");
		fprintf (stdout, "\tlnc   Set the lower non critical threshold\n");
		fprintf (stdout, "\tunc   Set the upper non critical threshold\n");
		fprintf (stdout, "\tlc    Set the lower critical threshold\n");
		fprintf (stdout, "\tuc    Set the upper critical threshold\n");
		fprintf (stdout, "\tlf    Set the lower fatal threshold\n");
		fprintf (stdout, "\tuf    Set the lower fatal threshold\n");
		return;
	}
#if 0
	else if (cmd == "subscribe")
	{
		fprintf (stdout, "subscribe for event on this sensor\n");
		fprintf (stdout, "eventsubscribe [push|pushack|pushbatch|pull] heartbeat expiration [listenevent [unsubscribe]]\n");
		fprintf (stdout, "\tpush        Push event mode\n");
		fprintf (stdout, "\tpushack     Push mode with acknowledge\n");
		fprintf (stdout, "\tpushbatch   Push batch mode\n");
		fprintf (stdout, "\tpull        Pull mode\n");
		fprintf (stdout, "\theartbeat   Heart beat interval\n");
		fprintf (stdout, "\texpiration  Expiration time interval\n");
		fprintf (stdout, "\tlistenevent Listen for event after subscription(optional)\n");
		fprintf (stdout, "\tunsubscribe Unsubscribe this subscription after listening (optional)\n");
		return;
	}
#endif
	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\treading\n");
		fprintf (stdout, "\tsetthreshold lnc|unc|lc|uc|lf|uf <thresholdvalue>\n");
		return;
	}
}


/*
 * Displays power supply help
 */
void 
displayPowerSupplyHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this power supply\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}
	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}
}

/*
 * Displays fan help
 */
void 
displayFanHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tsetspeed <speed>\n");
		fprintf (stdout, "\tenumerate asset\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this fan\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}
	if (cmd == "enumerate")
	{
		fprintf (stdout, "enumerate asset\n");
		return;
	}
	if (cmd == "setspeed")
	{
		fprintf (stdout, "Set the desired speed of this fan\n");
		fprintf (stdout, "Usage: setspeed <speed>\n");
		return;
	}
	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tsetspeed <speed>\n");
		fprintf (stdout, "\tenumerate asset\n");
		return;
	}
}


/*
 * Displays Boot Config help
 */
void 
displayBootConfigHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tchangebootorder <newbootorderlist...>\n");
		fprintf (stdout, "\tdelete\n");
		fprintf (stdout, "\tsetdefault\n");
		fprintf (stdout, "\tsetnext\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this boot config\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}
	else if (cmd == "changebootorder")
	{
		fprintf (stdout, "Changes the bootorder for this boot configuration\n");
		fprintf (stdout, "Usage : changebootorder <newbootorderlist...>\n");
		fprintf (stdout, "Example : chagebootorder 2 1 3 (where 2 1 3 are current boot order)\n");
		return;
	}
	else if (cmd == "delete")
	{
		fprintf (stdout, "Delete this boot configuration\n");
		fprintf (stdout, "Usage : delete\n");
		return;
	}
	else if (cmd == "setdefault")
	{
		fprintf (stdout, "Set this boot config as default configuration\n");
		fprintf (stdout, "Usage : setdefault\n");
		return;
	}
	else if (cmd == "setnext")
	{
		fprintf (stdout, "Set this configuration for next boot\n");
		fprintf (stdout, "Usage : setnext\n");
		return;
	}
	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tchangebootorder <newbootorderlist...>\n");
		fprintf (stdout, "\tdelete\n");
		fprintf (stdout, "\tsetdefault\n");
		fprintf (stdout, "\tsetnext\n");
		return;
	}
}


/*
 * Displays user help
 */
void 
displayUserHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tenable\n");
		fprintf (stdout, "\tdisable\n");
		fprintf (stdout, "\tdelete\n");
		fprintf (stdout, "\tchangepassword <password>\n");
		fprintf (stdout, "\tassignroles <rolename_1> [<rolename_2> ... <rolename_n>]\n");
		fprintf (stdout, "\tremoveroles <rolename_1> [<rolename_2> ... <rolename_n>]\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this user\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}
	else if (cmd == "enable")
	{
		fprintf (stdout, "Enable this user\n");
		fprintf (stdout, "Usage : enable\n");
		return;
	}
	else if (cmd == "disable")
	{
		fprintf (stdout, "Disable this user\n");
		fprintf (stdout, "Usage : disable\n");
		return;
	}
	else if (cmd == "delete")
	{
		fprintf (stdout, "Delete this user\n");
		fprintf (stdout, "Usage : delete\n");
		return;
	}

	else if (cmd == "changepassword")
	{
		fprintf (stdout, "change the password for this user\n");
		fprintf (stdout, "Usage : changepassword <password>\n");
		return;
	}

	else if (cmd == "assignroles")
	{
		fprintf (stdout, "Assign roles to this user\n");
		fprintf (stdout, "Usage : assignroles <rolename_1> [<rolename_2> ... <rolename_n>]\n");
		return;
	}
	else if (cmd == "removeroles")
	{
		fprintf (stdout, "Remove roles from this user\n");
		fprintf (stdout, "Usage : removeroles <rolename_1> [<rolename_2> ... <rolename_n>]\n");
		return;
	}
	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tdelete\n");
		fprintf (stdout, "\tchangepassword <password>\n");
		fprintf (stdout, "\tassignroles <rolename_1> [<rolename_2> ... <rolename_n>]\n");
		fprintf (stdout, "\tremoveroles <rolename_1> [<rolename_2> ... <rolename_n>]\n");
		return;
	}
}


/*
 * Displays role help
 */
void 
displayRoleHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tdelete\n");
		fprintf (stdout, "\tmodify <permission_1> [<permission_2>... <permission_n>]\n");
		fprintf (stdout, "\tassignpermissions <permission_1> [<permission_2>... <permission_n>]\n");
		fprintf (stdout, "\tgetsupportedqualifiers\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this role\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}
	else if (cmd == "modify")
	{
		fprintf (stdout, "Modifies this role\n");
		fprintf (stdout, "Usage : modify <permission_1> [<permission_2>... <permission_n>]\n");
		fprintf (stdout, "Where permission are constructed using supported activites and qualifiers seperated by commans as below\n");
		fprintf (stdout, "\"activities, qualifiers\"\n\n");
		fprintf (stdout, "Where activities are one of these  \"create|delete|detect|read|write|execute|other\" \n");
		fprintf (stdout, "List of supported qualifiers can be obtained using \"getsupportedqualifiers\" command\n\n");
		fprintf (stdout, "Example : modify \"execute,SP Login\" \"write, Clear Log\" \"execute, KVM redirection\"\n");
		return;
	}
	else if (cmd == "assignpermissions")
	{
		fprintf (stdout, "Assigns new permissions to this role\n");
		fprintf (stdout, "Usage : assignpermissions <permission_1> [<permission_2>... <permission_n>]\n");
		fprintf (stdout, "Where permission are constructed using supported activites and qualifiers seperated by commans as below\n");
		fprintf (stdout, "\"activities, qualifiers\"\n\n");
		fprintf (stdout, "Where activities are one of these  \"create|delete|detect|read|write|execute|other\" \n");
		fprintf (stdout, "List of supported qualifiers can be obtained using \"getsupportedqualifiers\" command\n\n");
		fprintf (stdout, "Example : assignpermissions \"execute,SP Login\" \"write, Clear Log\" \"execute, KVM redirection\"\n");
		return;
	}
	else if (cmd == "delete")
	{
		fprintf (stdout, "Deletes this role\n");
		fprintf (stdout, "Usage : delete\n");
		return;
	}
	else if (cmd == "getsupportedqualifiers")
	{
			fprintf (stdout, "List the supported privilege qualifiers, by the target\n");
			fprintf (stdout, "Usage: getsupportedqualifiers\n");
	}
	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tdelete\n");
		fprintf (stdout, "\tmodify <permission_1> [<permission_2>... <permission_n>]\n");
		fprintf (stdout, "\tassignpermissions <permission_1> [<permission_2>... <permission_n>]\n");
		fprintf (stdout, "\tgetsupportedqualifiers\n");
		return;
	}
}

/*
 * Displays software help
 */
void 
displaySoftwareHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this software\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}
	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}
}

/*
 * Displays Operating System help
 */
void 
displayOperatingSystemHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this operating system\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}
	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}
}

/*
 * Displays BIOS help
 */
void 
displayBIOSHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\trestoredefaults\n");
		fprintf (stdout, "\tsetattribute <attributename> <value_1> [<value_2>... <value_n>]\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this bios\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}

	if (cmd == "restoredefaults")
	{
		fprintf (stdout, "Restores this bios with default values\n");
		fprintf (stdout, "Usage: restoredefaults\n");
		return;
	}

	if (cmd == "setattribute")
	{
		fprintf (stdout, "Set the bios attribute values\n");
		fprintf (stdout, "Usage: setattribute <attributename> <value_1> [<value_2> <value_n>]\n\n");
		fprintf (stdout, "attributename     - name of the attribute to set(should be same as listed in show command)\n");
		fprintf (stdout, "value_1.. value_n - value of the attribute to set. It should be a valid value for the attriute name\n");
		fprintf (stdout, "Example : \nsetattribute \"DMTF:Network Boot ROM\" Enable\n");
		fprintf (stdout, "setattribute \"Boot Order\" Hard-Disk1 CD/DVD RemovableDisk\n");
		return;
	}
	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\trestoredefaults\n");
		fprintf (stdout, "\tsetattribute <attributename> <value_1> [<value_2>... <value_n>]\n");
		return;
	}
}

/*
 * Displays OpaqueManagementData help
 */
void 
displayOpaqueManagementDataHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\twrite <offsettowrite> <datatowrite>\n");
		fprintf (stdout, "\timportfromuri <offsettowrite> <bytestowrite> <URI>\n");		
		fprintf (stdout, "\tread <offsettoread> <bytestoread>\n");
		fprintf (stdout, "\texportfromuri <offsettowrite> <bytestowrite> <URI>\n");
		fprintf (stdout, "\tlock <true/false>\n");
		fprintf (stdout, "\treassignowner <username>\n");
		fprintf (stdout, "\tassignaccess <username> <activities>\n");
		fprintf (stdout, "\tdelete\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this opaquemanagementdata\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}

	if (cmd == "write")
	{
		fprintf (stdout, "Writes the given datavalue at the given offset\n");
		fprintf (stdout, "Usage: write <offsettowrite> <datatowrite> <[<locktoken>]\n\n");
		fprintf (stdout, "Example : write 0 \"opaquedata\"\n");
		fprintf (stdout, "offsettowrite : offset ranges from 0 to maxsize-1 of the opaque\n");
		fprintf (stdout, "datatowrite : data to write in opaque in form of string\n");
		fprintf (stdout, "locktoken[Optional] : Token to lock\n");

		return;
	}

	if (cmd == "importfromuri")
	{
		fprintf (stdout, "Writes the data from the URI specified at the given offset\n");
		fprintf (stdout, "Usage: importfromuri <offsettowrite> <bytestowrite> <URI>\n\n\n");
		fprintf (stdout, "Example : importfromuri 0 \"length of the data to read\" \"Read the data from the given URI\"\n");
		fprintf (stdout, "offsettowrite : offset ranges from 0 to maxsize of the opaque\n");
		fprintf (stdout, "bytestowrite : number of bytes to import\n");
		fprintf (stdout, "URI : Import data from the given URI\n");

		return;
	}	

	if (cmd == "read")
	{
		fprintf (stdout, "Reads the data from the given offset\n");
		fprintf (stdout, "Usage: read <offsettoread> <bytestoread>  <[<locktoken>]\n\n\n");
		fprintf (stdout, "Example : read 0 5 \n");
		fprintf (stdout, "offsettowrite : offset ranges from 0 to maxsize of the opaque\n");
		fprintf (stdout, "bytestoread : number of bytes to read\n");	
		fprintf (stdout, "locktoken[Optional] : Token to lock\n");
		return;
	}

	if (cmd == "exportfromuri")
	{
		fprintf (stdout, "Writes the data to the specified URI at the given offset\n");
		fprintf (stdout, "Usage: exportfromuri <offsettowrite> <bytestowrite> <URI>\n\n\n");
		fprintf (stdout, "Example : exportfromuri 0 \"length of the data to read\" \"Export data from the given URI\"\n");
		fprintf (stdout, "offsettowrite : offset ranges from 0 to maxsize of the opaque\n");
		fprintf (stdout, "bytestowrite : number of bytes to import\n");
		fprintf (stdout, "URI : Export data from the given URI\n");
		return;
	}

	if (cmd == "reassignowner")
	{
		fprintf (stdout, "Assigns new owner to this Opaquemanagementdata\n");
		fprintf (stdout, "Usage: reassignowner <username>\n\n\n");
		fprintf (stdout, "Example: reassignowner user1\n");
		fprintf (stdout, "username : User Accounts\n");
		return;
	}

	if (cmd == "assignaccess")
	{
		fprintf (stdout, "Assign Access to the users\n");
		fprintf (stdout, "Usage: assignaccess <username> <activities>\n\n");
		fprintf (stdout, "Example: assignaccess Administrator Read/Write\n");
		fprintf (stdout, "username : User Accounts\n");
		fprintf (stdout, "activities : Read and/or Write\n");
		return;
		;
	}

	if (cmd == "lock")
	{
		fprintf (stdout, "Lock this Opaquemanagementdata\n");
		fprintf (stdout, "Usage: lock <true/false>\n");
		return;
		;
	}
	
	else if (cmd == "delete")
	{
		fprintf (stdout, "Delete this Opaquemanagementdata\n");
		fprintf (stdout, "Usage : delete\n");
		return;
	}

	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\twrite <offsettowrite> <datatowrite> \n");
		fprintf (stdout, "\timportfromuri <offsettowrite> <bytestowrite> <URI>\n");		
		fprintf (stdout, "\tread <offsettoread> <bytestoread>\n");
		fprintf (stdout, "\texportfromuri <offsettowrite> <bytestowrite> <URI>\n");		
		fprintf (stdout, "\tlock <true/false>\n");
		fprintf (stdout, "\treassignowner <username>\n");
		fprintf (stdout, "\tassignaccess <username> <activities>\n");
		fprintf (stdout, "\tdelete\n");
		return;
	}
}

/*
 * Displays TextRedirection help
 */
void 
displayTextRedirectionHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tactivate\n");
		fprintf (stdout, "\tenable\n");
		fprintf (stdout, "\tdisable\n");
		fprintf (stdout, "\tstart\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this text redirection\n");
		return;
	}

	if (cmd == "activate")
	{
		fprintf (stdout, "Activates this redirection\n");
		fprintf (stdout, "Usage : activate\n");
		return;
	}

	if (cmd == "enable")
	{
		fprintf (stdout, "Enables this redirection but not activate\n");
		fprintf (stdout, "Usage : enable\n");
		return;
	}

	if (cmd == "disable")
	{
		fprintf (stdout, "Disables this redirection\n");
		fprintf (stdout, "Usage : disable\n");
		return;
	}

	if (cmd == "start")
	{
		fprintf (stdout, "Starts this text redirection\n");
		fprintf (stdout, "Usage : start\n");
		return;
	}
	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tactivate\n");
		fprintf (stdout, "\tenable\n");
		fprintf (stdout, "\tdisable\n");
		fprintf (stdout, "\tstart\n");
		return;
	}
}

/*
 * Displays UsbRedirection help
 */
void 
displayUsbRedirectionHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "\tusbredirection [connect|disconnect]\n");
		fprintf (stdout, "\nUsage: dashcli -h <host> -u <user> -P <pass> [-a <digest|basic>] usbredirection [ connect | disconnect ] \n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this usbredirection\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}

	if (cmd == "listlocaldrives")
	{
		fprintf (stdout, "Shows the available drives in the local machine\n");
		fprintf (stdout, "Usage: listlocaldrives\n");
		return;
	}
	if (cmd == "connect")
	{
		fprintf (stdout, "Connects to the USB Redirection\n");
		fprintf (stdout, "Usage : usbredirection connect\n\n");
		fprintf (stdout, "Integrated WebServer - y  (For using default SDK Webserver)\n");
		fprintf (stdout, "pathtoimage  - Path to the folder where the image file located \n");
#ifndef _WIN32
		fprintf (stdout, "Example:   /home/testuser/fedora8.iso\n\n");
#else
		fprintf (stdout, "Example:   C:/images/fedora8.iso\n\n");
#endif
		fprintf (stdout, "Integrated WebServer - n   (For using external Webserver)\n");
		fprintf (stdout, "File Path - Path to the server where the image is located\n");
		fprintf (stdout, "Example:  http://165.200.24.156:8080/images/fedora8.iso\n");
		return;
	}
	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "\tusbredirection [connect|disconnect]\n");
		fprintf (stdout, "\nUsage: dashcli -h <host> -u <user> -P <pass> [-a <digest|basic>] usbredirection [ connect | disconnect ] \n");
		return;
	}
}

/*
 * Displays battery help
 */
void 
displayBatteryHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tenable\n");
		fprintf (stdout, "\tdisable\n");
		fprintf (stdout, "\ttest\n");
		fprintf (stdout, "\trecharge\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this battery\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}
	if (cmd == "enable")
	{
		fprintf (stdout, "Turn on Battery\n");
		fprintf (stdout, "Usage : enable\n");
		return;
	}

	if (cmd == "disable")
	{
		fprintf (stdout, "Turn off Battery\n");
		fprintf (stdout, "Usage : disable\n");
		return;
	}

	if (cmd == "test")
	{
		fprintf (stdout, "Perform a recalculation of charge thresholds\n");
		fprintf (stdout, "Usage : test\n");
		return;
	}

	if (cmd == "recharge")
	{
		fprintf (stdout, "Perform Recharge Operation \n");
		fprintf (stdout, "Usage : recharge\n");
		return;
	}
	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tenable\n");
		fprintf (stdout, "\tdisable\n");
		fprintf (stdout, "\ttest\n");
		fprintf (stdout, "\trecharge\n");
		return;
	}
}

/*
 * Displays networkport help
 */
void 
displayNetworkPortHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this networkport\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}

	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}
}

/*
 * Displays CDHCPClient help
 */
void 
displayDHCPClientHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this DHCPClient\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}

	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}
}

/*
 * Displays IPInterface help
 */
void 
displayIPInterfaceHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this IPInterface\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}

	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}
}

/*
 * Displays DNSClient help
 */
void 
displayDNSClientHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this DNSClient\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}

	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}
}

/*
 * Displays RegisteredProfiles help
 */
void 
displayRegisteredProfileHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Displays the supported profiles\n"); 
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tisadvertised\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of the Registered Profile\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}

	else if (cmd == "isadvertised")
	{
		fprintf (stdout, "Shows the given profile is advertised at given version\n");
		fprintf (stdout, "Usage : registeredprofile isadvertised <\"profilename\"> [<version>]\n\n");
		fprintf (stdout, "profilename : DASH profile name as per specification \n");
		fprintf (stdout, "Example     :Base Desktop And Mobile Profile or a short name like basedesktopandmobile \n\n");
		fprintf (stdout, "version     : DASH version\n");
		fprintf (stdout, "Example     :1.0.0\n\n");
		fprintf (stdout, "Example :dashcli -h 192.168.4.2 -u admin -p 623 -P admin registeredprofile isadvertised \"Base Desktop And Mobile Profile\" 1.0.0 \n\n");
		fprintf (stdout, "Example :dashcli -h 192.168.4.2 -u admin -p 623 -P admin registeredprofile isadvertised \"Base Desktop And Mobile Profile\" \n\n");
		fprintf (stdout, "Example :dashcli -h 192.168.4.2 -u admin -p 623 -P admin registeredprofile isadvertised \"fanProfile\" 1.0.0 \n\n");
		fprintf (stdout, "Example :dashcli -h 192.168.4.2 -u admin -p 623 -P admin registeredprofile isadvertised \"fanProfile\" \n\n");
		fprintf (stdout, "Example :dashcli -h 192.168.4.2 -u admin -p 623 -P admin registeredprofile isadvertised \"fan\" 1.0.0 \n\n");
		fprintf (stdout, "Example :dashcli -h 192.168.4.2 -u admin -p 623 -P admin registeredprofile isadvertised \"fan\" \n\n");
	}
	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tisadvertised\n");
		return;
	}
}

/*
 * Displays EthernetPort help
 */
void 
displayEthernetPortHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this EthernetPort\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}

	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		return;
	}
}
/*
 * Displays IndicationFilter help
 */
void 
displayIndicationFilterHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tdelete\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this Indication Filter\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}

	else if (cmd == "delete")
	{
		fprintf (stdout, "Delete this Indication Filter\n");
		fprintf (stdout, "Usage : delete\n");
		return;
	}

	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tdelete\n");
		return;
	}
}

/*
 * Displays filtercollection help
 */
void 
displayFilterCollectionHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tdelete\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this Filter Collection\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}

	else if (cmd == "delete")
	{
		fprintf (stdout, "Delete this Filter Collection\n");
		fprintf (stdout, "Usage : delete\n");
		return;
	}

	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tdelete\n");
		return;
	}
}

/*
 * Displays AlertDestination help
 */
void 
displayAlertDestinationHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tdelete\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this Alert Destination\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}

	else if (cmd == "delete")
	{
		fprintf (stdout, "Delete this Alert Destination\n");
		fprintf (stdout, "Usage : delete\n");
		return;
	}

	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tdelete\n");
		return;
	}
}

/*
 * Displays IndicationSubscription help
 */
void 
displayIndicationSubscriptionHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tunsubscribe\n");
		fprintf (stdout, "\trenew\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "show")
	{
		fprintf (stdout, "Shows the properties of this Indication Subscription\n");
		fprintf (stdout, "Usage : show\n");
		return;
	}

	else if (cmd == "unsubscribe")
	{
		fprintf (stdout, "Delete this Indication Subscription\n");
		fprintf (stdout, "Usage : unsubscribe\n");
		return;
	}

	else if (cmd == "renew")
	{
		fprintf (stdout, "Renews this Indication Subscription\n");
		fprintf (stdout, "Usage : renew <renewtime>\n");
		fprintf (stdout, "Renew time format\n");
		fprintf (stdout, "\tYYYY-MM-DDThh:mm:ss.sTZD (eg 2009-01-07T03:17:31-06:00)\nwhere\n");
		fprintf (stdout, "\tYYYY = four-digit year\n");
		fprintf (stdout, "\tMM = two-digit month (01=January, etc.)\n");
		fprintf (stdout, "\tDD = two-digit day of month (01 through 31)\n");
		fprintf (stdout, "\thh = two digits of hour (00 through 23) (am/pm NOT allowed)\n");
		fprintf (stdout, "\tmm = two digits of minute (00 through 59)\n");
		fprintf (stdout, "\tss = two digits of second (00 through 59)\n");
		fprintf (stdout, "\ts = one or more digits representing a decimal fraction of a second\n");
		fprintf (stdout, "\tTZD = time zone designator (Z or +hh:mm or -hh:mm)");
		return;
	}

	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tshow\n");
		fprintf (stdout, "\tunsubscribe\n");
		fprintf (stdout, "\trenew\n");
		return;
	}
}

/*
 * Displays help based on the target type 
 */
bool
displayTargetHelp (string target, const vector<string>& commands, size_t ix)
{
	if (target == "computersystem")      { displayComputerSystemHelp (commands, ix); }
	else if (target == "processor")      { displayProcessorHelp      (commands, ix); }
	else if (target == "memory")         { displayMemoryHelp         (commands, ix); }
	else if (target == "sensor")         { displaySensorHelp         (commands, ix); }
	else if (target == "powersupply")    { displayPowerSupplyHelp    (commands, ix); }
	else if (target == "fan")            { displayFanHelp            (commands, ix); }
	else if (target == "bootconfig")     { displayBootConfigHelp     (commands, ix); }
	else if (target == "user")           { displayUserHelp           (commands, ix); }
	else if (target == "role")           { displayRoleHelp           (commands, ix); }
	else if (target == "software")       { displaySoftwareHelp       (commands, ix); }
	else if (target == "operatingsystem"){ displayOperatingSystemHelp(commands, ix); }
	else if (target == "asset")          { displayAssetHelp          (commands, ix); }
	else if (target == "bios")			 { displayBIOSHelp           (commands, ix); }
	else if (target == "textredirection"){displayTextRedirectionHelp (commands, ix); }
	else if (target == "usbredirection") {displayUsbRedirectionHelp  (commands, ix); }
	else if (target == "opaquemanagementdata") {displayOpaqueManagementDataHelp (commands,ix);}
	else if (target == "battery")		 {displayBatteryHelp (commands,ix);}
	else if (target == "networkport")	 {displayNetworkPortHelp (commands,ix);}
	else if (target == "dhcpclient")	 {displayDHCPClientHelp (commands,ix);}
	else if (target == "ipinterface")	 {displayIPInterfaceHelp (commands,ix);}
	else if (target == "dnsclient")      {displayDNSClientHelp (commands,ix);}
	else if (target == "registeredprofile") {displayRegisteredProfileHelp (commands,ix);}
	else if (target == "ethernetport")	 {displayEthernetPortHelp (commands,ix); }
	else if (target == "indicationfilter")    {displayIndicationFilterHelp (commands,ix);}
	else if (target == "filtercollection")	  {displayFilterCollectionHelp (commands,ix);}
	else if (target == "alertdestination") {displayAlertDestinationHelp (commands,ix);}
	else if (target == "indicationsubscription") {displayIndicationSubscriptionHelp (commands,ix);}
	else { return false; }

	return true;
}

/*
 * displayEnumerateHelp
 */
void
displayEnumerateHelp (void)
{
	fprintf (stdout, "Usage: enumerate target\n");
	return;
}

/*
 * displayShellHelp
 */
void
displayShellHelp (void)
{
	fprintf (stdout, "Launchs interactive DASH shell\n");
	fprintf (stdout, "Usage : [options] shell\n");
	fprintf (stdout, "See dashcli help for allowed options\n");
	fprintf (stdout, "Options specified here can be over written with in the shell\n");

	fprintf (stdout, "\nExample : dashcli shell\n");
	fprintf (stdout, "Example : dashcli -h 192.168.0.1 -u admin -P admin shell\n");

}

/*
 * displayDiscoverHelp
 */
void 
displayDiscoverHelp (void)
{
	fprintf (stdout, 
		"Discovers the DASH target specified by the ip address range. \n");
	fprintf (stdout, 
		"Usage: dashcli -s <start_ip> -e <end_ip> [ -u <username> -P <password> -p <port_1, [port_2, port_n]]> discover [info]\n");
	fprintf (stdout, "Where info - Displays the DASH  information\n");
	fprintf (stdout, "Example: dashcli -s 192.168.0.10 -e 192.168.0.20 -u admin -P admin discover\n");
	fprintf (stdout, "Example: dashcli -s 192.168.0.10 -e 192.168.0.20 discover\n");
	fprintf (stdout, "Example: dashcli -s 192.168.0.10 -e 192.168.0.20 -p 623 discover\n");
	fprintf (stdout, "Example: dashcli -s 192.168.0.10 -e 192.168.0.20 -p \"623,8080\"  discover\n");
	fprintf (stdout, "Example: dashcli -s 192.168.0.4 -e 192.168.0.15 -u admin -P admin -p 623 discover info\n");
	fprintf (stdout, "Example: dashcli -s 192.168.0.10 -e 192.168.0.20 discover info\n");
	fprintf (stdout, "Example: dachcli -h hounds-demo -S http -p 623 discover\n");
	fprintf (stdout, "Example: dachcli -h 192.168.0.8 -S http -p 623 discover\n");
	fprintf (stdout, "Example: dachcli -h hounds-demo -S http -p 623 discover info\n");
	fprintf (stdout, "Example: dachcli -h 192.168.0.8 -S http -p 623 discover info\n");

	return;
}

/*
 * displaySubscribeHelp
 */
void 
displayStaticSubscribeHelp (void)
{
	fprintf (stdout, "Subscribes for events using static filter\n");
	fprintf (stdout, 
			"Usage: dashcli -h <host> -u <user> -P <pass> [-a <digest|basic>] indication \
 staticsubscribe <destination_uri> <subscribetype> <expirationtimeout> <filter_instance>\n");

	fprintf (stdout, "where  \ndestination_uri           - IP address and path where the events should be sent. Its constructed as http://<ipaddress>:<port>/<path>\n");
	fprintf (stdout, "\t\t\tEx : http://192.168.0.101:8080/eventsink\n");
	fprintf (stdout, "subscribetype             - Is one of push|pushack|pushbatch|pull\n\t\t\tpush      - send event, acknowledgement not needed\n\
			pushack   - send event, acknowledgement needed\n\t\t\tpushbatch - send event in a batch\n\t\t\tpull      - do not send event, evets will be pulled\n");
	fprintf (stdout, "expirationtimeout - Event subscription expiration timeout in seconds, 0 not to set exiration timeout\n");
	fprintf (stdout, "filter_instance - Instance number of filter to use for this subscription, use enumerate indicationfilter to get list of instances\n");
	
	fprintf (stdout, "Example :\ndashcli -h 192.168.0.20 -p 623 -u admin -P admin indication staticsubscribe http://192.168.0.101:8080/eventsink push 0 1\n");

	return;
}

/*
 * displayDynamicSubscribeHelp
 */
void 
displayDynamicSubscribeHelp (void)
{
	fprintf (stdout, "Subscribes for events using dynamic filter \n");
	fprintf (stdout, 
			"Usage: dashcli -h <host> -u <user> -P <pass> [-a <digest|basic>] indication \
 dynamicsubscribe <destination_uri> <subscribetype> <expirationtimeout> <querylanguage> <queryfilter> [<resource_uri>]\n");

	fprintf (stdout, "where  \ndestination_uri   - IP address and path where the events should be sent. Its constructed as http://<ipaddress>:<port>/<path>\n");
	fprintf (stdout, "\t\t\tEx : http://192.168.0.101:8080/eventsink\n");
	fprintf (stdout, "subscribetype     - Is one of push|pushack|pushbatch|pull\n\t\t\tpush      - send event, acknowledgement not needed\n\
			pushack   - send event, acknowledgement needed\n\t\t\tpushbatch - send event in a batch\n\t\t\tpull      - do not send event, evets will be pulled\n");
	fprintf (stdout, "expirationtimeout - Event subscription expiration timeout in seconds, 0 not to set exiration timeout\n");
	fprintf (stdout, "querylanguage     - Query language to be used for the filter. <CQL|CQL>\n");
	fprintf (stdout, "query             - Query Filter Ex. \"select * from CIM_AlertIndication\"\n");
	fprintf (stdout, "resource_uri      - Resource URI Ex. http://schemas.dmtf.org/wbem/wscim/1/*\n");
	fprintf (stdout, "                                 Ex. http://schemas.dmtf.org/wbem/wscim/1/cim_schema/2/CIM_SNMPTrapIndication\n");

	fprintf (stdout, "Example :\ndashcli -h 192.168.0.20 -p 623 -u admin -P admin indication dynamicsubscribe http://192.168.0.101:8080/eventsink push 0 CQL \"SELECT * FROM CIM_AlertIndication\"\n");
	fprintf (stdout, "Example :\ndashcli -h 192.168.0.20 -p 623 -u admin -P admin indication dynamicsubscribe http://192.168.0.101:8080/eventsink push 0 CQL \"SELECT * FROM CIM_AlertIndication\" http://schemas.dmtf.org/wbem/wscim/1/cim_schema/2/CIM_AlertIndication\n");

	return;
}

/*
 * displayCollectionSubscribeHelp
 */
void 
displayCollectionSubscribeHelp (void)
{
	fprintf (stdout, "Subscribes for events using filter collection\n");
	fprintf (stdout, 
			"Usage: dashcli -h <host> -u <user> -P <pass> [-a <digest|basic>] indication \
 collectionsubscribe <destination_uri> <subscribetype> <expirationtimeout> <filtercollection_instance>\n");

	fprintf (stdout, "where  \ndestination_uri           - IP address and path where the events should be sent. Its constructed as http://<ipaddress>:<port>/<path>\n");
	fprintf (stdout, "\t\t\tEx : http://192.168.0.101:8080/eventsink\n");
	fprintf (stdout, "subscribetype             - Is one of push|pushack|pushbatch|pull\n\t\t\tpush      - send event, acknowledgement not needed\n\
			pushack   - send event, acknowledgement needed\n\t\t\tpushbatch - send event in a batch\n\t\t\tpull      - do not send event, evets will be pulled\n");
	fprintf (stdout, "expirationtimeout - Event subscription expiration timeout in seconds, 0 not to set exiration timeout\n");
	fprintf (stdout, "filtercollection_instance - Instance number of filter collection to use for this subscription, use enumerate filtercollection to get list of instances\n");
	
	fprintf (stdout, "Example :\ndashcli -h 192.168.0.20 -p 623 -u admin -P admin indication collectionsubscribe http://192.168.0.101:8080/eventsink push 0 1\n");

	return;
}

/*
 * displayIndicationHelp
 */
void
displayIndicationHelp (const vector<string>& commands, size_t ix)
{

	/* if there are no other commands - just display general help */
	if (ix == commands.size ())
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tcreatefilter            Creats new indication filter\n");
		fprintf (stdout, "\tcreatedestination       Creats new alert destination\n");
//		fprintf (stdout, "\tstaticsubscribe         Subscribe done by static filter\n");
//		fprintf (stdout, "\tdynamicsubscribe        Subscribe done by dynamic filter\n");
//		fprintf (stdout, "\tcollectionsubscribe     Subscribs indication/alert using Filter Collection\n");
		fprintf (stdout, "\tsubscribe		Subscribes indication/alert using static or dynamic or filter collection types.\n");
		fprintf (stdout, "\tunsubscribe             Unsubscribe a indication/alert subscription\n");
		fprintf (stdout, "\trenew                   Renews a indication/alert subscription\n");

		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if (cmd == "createfilter")
	{
		fprintf (stdout, "Creates a indication filter.\n");
		fprintf (stdout, 
			"Usage: dashcli -h <host> -u <user> -P <pass> [-a <digest|basic>] indication createfilter <querylanguage> <querystring>\n");
		fprintf (stdout, "where \nquerylanguage         - Query language to be used for the filter. \n\t\t\tEx: Example \"CQL\" for CIM query language\n");
		fprintf (stdout, "querystring           - Query string to create the filter based on the querylanguage\n");
		fprintf (stdout, "\t\t\tEx : \"SELECT * FROM CIM_AlertIndication\" for CQL.\n");
		return;
	}
	else if (cmd == "createdestination")
	{
		fprintf (stdout, "Creats Alert destination\n");
		fprintf (stdout, 
			"Usage: dashcli -h <host> -u <user> -P <pass> [-a <digest|basic>] indication createdestination <destination_uri>\n");
		fprintf (stdout, "where  \ndestination_uri       - IP address and path where the events should be sent. Its constructed as http://<ipaddress>:<port>/<path>\n");
		fprintf (stdout, "\t\t\tEx : http://192.168.0.101:8080/eventsink\n");
		return;
	}
	//else if (cmd == "staticsubscribe")
	//{
	//	displayStaticSubscribeHelp ();
	//	return;
	//}
	//else if (cmd == "dynamicsubscribe")
	//{
	//	displayDynamicSubscribeHelp ();
	//	return;
	//}
	//else if (cmd == "collectionsubscribe")
	//{
	//	displayCollectionSubscribeHelp ();
	//	return;
	//}
	
	else
	{
		if (cmd != "help") 
		{ 
			fprintf (stderr, "Error: Invalid help command\n");
		}
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tcreatefilter            Creats new indication filter\n");
		fprintf (stdout, "\tcreatedestination       Creats new alert destination\n");
		fprintf (stdout, "\tsubscribe               Subscribes indication/alert\n");
//		fprintf (stdout, "\tcollectionsubscribe     Subscribs indication/alert using Filter Collection\n");
		fprintf (stdout, "\tunsubscribe             Unsubscribe a indication/alert subscription\n");
		fprintf (stdout, "\trenew                   Renews a indication/alert subscription\n");
		return;
	}


}
/*
 * displayTextRedirectionHelp
 */
void
displayTextRedirectionHelp(void)
{
	fprintf (stdout, "Allowed commands:\n");
	fprintf (stdout, "\tconnect			Enables and starts the text redirection.\n");
	fprintf (stdout, "\tdisconnect		Disables and stops the text redirection.\n");
	fprintf (stdout, "\nUsage: dashcli -h <host> -u <user> -P <pass> [-a <digest|basic>] textredirection [ connect | disconnect ] \n");
}
/*
 * displayAccountHelp
 */
void
displayAccountHelp(void)
{
	fprintf (stdout, "Allowed commands:\n");
	fprintf (stdout, "\tmanage	 Manages the Account for creating,Deleteing and assign Roles.\n");
	fprintf (stdout, "\nUsage: dashcli -h <host> -u <user> -P <pass> [-a <digest|basic>] account [ manage ] \n");
}

/*
 * displayRolesHelp
 */
void
displayRolesHelp(void)
{
	fprintf (stdout, "Allowed commands:\n");
	fprintf (stdout, "\tmanage	 Manages the Roles for creating,Deleteing and Modify the Roles.\n");
	fprintf (stdout, "\nUsage: dashcli -h <host> -u <user> -P <pass> [-a <digest|basic>] roles manage \n");
}

/*
 * displayListenEventsHelp
 */
void
displayListenEventsHelp (void)
{
	fprintf (stdout, "Listen for dash events\n");
	fprintf (stdout, "Usage: dashcli [-p <port>] listenevents\n");
	return;
}
	
/*
 * displayShowHelp
 */
void
displayShowHelp (void)
{
	fprintf (stdout,"Shows the informations about the dashcli\n");
	fprintf (stdout, 
			"Usage: dashcli show\n");
	return;
}

/*
 * displayHelpHelp
 */
void
displayHelpHelp (void)
{
	fprintf (stdout,"Display the target help page\n");
	fprintf (stdout, 
			"Usage: dashcli help <target>\n");
	return;
}

/*
 * doHelp
 */
void
doHelp (const CCmdOption& options, const vector<string>& commands, size_t ix)
{
	/* If target not provided - give generic help */
	if (commands.size () == 1) 
	{ 
		displayGeneralHelp (); 
		return;
	}

	/* If command is discover - display discover help */
	if (commands [ix] == "discover") 
	{
		displayDiscoverHelp ();
		return;
	}
	/* If the command is enumerate display denumerate help */
	if (commands [ix] == "enumerate")
	{
		displayEnumerateHelp ();
		return;
	}
	if (commands [ix] == "shell")
	{
		displayShellHelp ();
		return;
	}
	/* If command is raw - display raw help */
	else if (commands [ix] == "raw") 
	{
		displayRawHelp (commands, 2);
		return;
	}
	else if (commands [ix] == "indication") 
	{
		displayIndicationHelp (commands, 2);
		return;
	}
	else if (commands [ix] == "textredirection") 
	{
		displayTextRedirectionHelp ();
		return;
	}
	else if (commands [ix] == "listenevents")
	{
		displayListenEventsHelp ();
		return;
	}
	else if (commands [ix] == "account") 
	{
		displayAccountHelp ();
		return;
	}
	else if (commands [ix] == "roles") 
	{
		displayRolesHelp ();
		return;
	}
	else if (commands [ix] == "show")
	{
		displayShowHelp ();
		return;
	}
	else if (commands [ix] == "capabilities")
	{
		displayCapabilitiesHelp (commands, 2);
		return;
	}
	else if (commands [ix] == "help")
	{
		displayHelpHelp ();
		return;
	}

	/* Get the target name */
	string target = commands [ix];
	if (!displayTargetHelp (target, commands, ix + 1))
	{ 
		/* 
		 * User could have requested help based on the target - get the 
		 * target type and provide help based on it.
		 */
		if (options._target_specified)
		{
			target = getTargetType (options._target [options._target.size () - 1]);
			if (!displayTargetHelp (target, commands, ix))
			{
				fprintf (stderr, "Error: Invalid target type\n");
				displayGeneralHelp ();
			}
		}
		else { displayGeneralHelp (); }
	}

	return;
}

/*
 * displayRawHelp
 */
void
displayRawHelp (const vector<string>& commands, size_t ix)
{
	/* if there are no other commands - just display general help */
	if (commands.size () <= ix)
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tenumerateinstancenames|ein <classname> [<namespace>]\n");
		fprintf (stdout, "\tenumerateinstances|ei <classname> [<namespace>]\n");
		fprintf (stdout, "\tgetinstance|gi <classuri> [<namespace>]\n");
		fprintf (stdout, "\tsetinstance|si <classuri> <property_name_value_pairs> [<namespace>]\n");
		fprintf (stdout, "\tinvoke|im <classuri> <method_name> <argument_name_value_pairs> [<namespace>]\n");
		return;
	}

	/* Get the command */
	string cmd = commands [ix];
	if ((cmd == "enumerateinstancenames") || (cmd == "ein"))
	{
		fprintf (stdout, "Enumerates and display the object paths of instances of the class\n");
		fprintf (stdout, "Usage : raw enumerateinstancenames|ein <classname> [<namespace>]\n");
		fprintf (stdout, 
		"\nExample: dashcli -h 192.168.0.1 -u admin -P password -a digest raw enumerateinstancenames CIM_ComputerSystem\n");
		fprintf (stdout, 
		"Example: dashcli -h 192.168.0.1 -u admin -P password -a digest raw ein CIM_RegisteredProfile root/interop\n");
		return;
	}
	if ((cmd == "enumerateinstances") || (cmd == "ei"))
	{
		fprintf (stdout, "Enumerates and display the instances of the class\n");
		fprintf (stdout, "Usage : enumerateinstances|ei <classname> [<namespace>]\n");
		fprintf (stdout, 
		"\nExample: dashcli -h 192.168.0.1 -u admin -P password -a digest raw ei CIM_ComputerSystem\n");
		fprintf (stdout, 
		"Example: dashcli -h 192.168.0.1 -u admin -P password -a digest raw enumerateinstances CIM_RegisteredProfile root/interop\n");
		return;
	}
	if ((cmd == "getinstance") || (cmd == "gi"))
	{
		fprintf (stdout, "Displays a instance of the class specified by classuri\n");
		fprintf (stdout, "Usage : getinstance|gi <classuri> [<namespace>]\n");
		fprintf (stdout, "\nWhere\nclassuri is constructed using the class URI and class key properties as below\n");
		fprintf (stdout, "ClassURI?key_1=\"keyvalue_1\",...key_n=\"keyvalue_n\"\n");
		fprintf (stdout, "Key property values keyvalue_1... keyvalue_n can be obtained using enumerateinstances or enumerateinstancenames raw commands\n");
		fprintf (stdout, 
			"\nExample: dashcli -h 192.168.0.1 -u admin -P admin -a digest raw getinstance http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ComputerSystem?CreationClassName=\"DRI_ComputerSystem\",Name=\"mkl-desktop\"\n");
		fprintf (stdout, 
			"Example: dashcli -h 192.168.0.1 -u admin -P admin -a digest raw gi http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_RegisteredProfile?InstanceID=\"desktop\" root/interop\n");
		return;
	}

	if ((cmd == "setinstance") || (cmd == "si"))
	{
		fprintf (stdout, "Sets the properties of a instance of the class specified by classuri\n");
		fprintf (stdout, "Usage : setinstance|si <classuri> <properties_name_value_pairs> [<namespace>]\n");
		fprintf (stdout, "\nWhere \nclassuri is constructed using the class URI and class key properties as below\n");
		fprintf (stdout, "\t\tClassURI?key_1=\"keyvalue_1\",...key_n=\"keyvalue_n\"\n");
		fprintf (stdout, "\t\tEx : http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/DRI_Account?CreationClassName=\"DRI_Account\",Name=\"account_0\"\n");
		fprintf (stdout, "\t\tKey property values keyvalue_1... keyvalue_n can be obtained using enumerateinstances or enumerateinstancenames raw commands\n");
		fprintf (stdout, "properties_name_value_pairs is constructed using the property name and property value and seperated by ',' as below\n");
		fprintf (stdout, "\t\tpropertyname_1=propertyvalue_1,...propertyname_n=propertyvalue_n\n");
		fprintf (stdout, "\t\tEx : \"OrganizationName=DMTF,UserPassword=password\"\n");
		fprintf (stdout, 
			"\nExample: dashcli -h 192.168.0.1 -u admin -P admin -a digest raw setinstance http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Account?CreationClassName=\"CIM_Account\",Name=\"account_0\",SystemName=\"remote\",SystemCreationClassName=\"CIM_ComputerSystem\"\" \"OrganizationName=AMD\"\n");
		fprintf (stdout, 
			"\nExample: dashcli -h 192.168.0.1 -u admin -P admin -a digest raw setinstance http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_Account?CreationClassName=\"CIM_Account\",Name=\"account_0\",SystemName=\"remote\",SystemCreationClassName=\"CIM_ComputerSystem\"\" \"OrganizationName=AMD\" root/interop\n");
		return;
	}
	if ((cmd == "invoke") || (cmd == "im"))
	{
		fprintf (stdout, "Invokes a extrinsic method specified by method_name of instance of the class specified by classuri\n");
		fprintf (stdout, "Usage : invoke|in <classuri> <method_name> <argument_name_value|argument_file> [<namespace>]\n");
		fprintf (stdout, "\nWhere\nclassuri is constructed using the class URI and class key properties as below\n");
		fprintf (stdout, "\t\tClassURI?key_1=\"keyvalue_1\",...key_n=\"keyvalue_n\"\n");
		fprintf (stdout, "\t\tKey property values keyvalue_1... keyvalue_n can be obtained using enumerateinstances or enumerateinstancenames raw commands\n");
		fprintf (stdout, "method_name Name of the method to invoke\n");
		fprintf (stdout, "argument_name_value is constructed using the argument name and argument value and seperated by ',' as below\n");
		fprintf (stdout, "\t\targname_1=\"argvalue_1\",...argname_n=\"argvalue_n\"\n");
		fprintf (stdout, "\t\tEx : PowerState=2\n");
		fprintf (stdout, "argument_file  An argument file with one argument name, value per line in a text file as below\n");
		fprintf (stdout, "\t\targname_1=\"argvalue_1\"\n\t\targname_2=\"argvalue_2\"\n\t\t.\n\t\t.\n\t\t.\n\t\targname_n=\"argvalue_n\"\n");
		fprintf (stdout, "\t\tEx : PowerState=2\n\t\tManagedElement=<wsa:Address>http://schemas.xmlsoap.org/ws/2004/08/addressing/role/anonymous</wsa:Address>.  <wsa:ReferenceParameters>.    <wsman:ResourceURI>http://schemas.dri.org/wbem/wscim/1/cim-schema/2/DRI_ComputerSystem</wsman:ResourceURI>.    <wsman:SelectorSet>.      <wsman:Selector Name=\"CreationClassName\">DRI_ComputerSystem</wsman:Selector>.      <wsman:Selector Name=\"Name\">host</wsman:Selector>.    </wsman:SelectorSet>.  </wsa:ReferenceParameters>\n");
		fprintf (stdout, 
			"\nExample: dashcli -h 192.168.0.1 -u admin -P admin -a digest raw invoke http://schemas.dri.org/wbem/wscim/1/cim-schema/2/DRI_PowerManagementService?Name=pwrmgrservice1,CreationClassName=DRI_PowerManagementService,SystemName=host,SystemCreationClassName=DRI_ComputerSystem RequestPowerStateChange \"PowerState=2\"\n");
		fprintf (stdout, 
			"\nExample: dashcli -h 192.168.0.1 -u admin -P admin -a digest raw invoke http://schemas.dri.org/wbem/wscim/1/cim-schema/2/DRI_PowerManagementService?Name=pwrmgrservice1,CreationClassName=DRI_PowerManagementService,SystemName=host,SystemCreationClassName=DRI_ComputerSystem RequestPowerStateChange \"PowerState=2\" root/interop\n");
		return;
	}

	else
	{
		fprintf (stdout, "Allowed commands:\n");
		fprintf (stdout, "\tenumerateinstancenames|ein <classname> [<namespace>]\n");
		fprintf (stdout, "\tenumerateinstances|ei <classname> [<namespace>]\n");
		fprintf (stdout, "\tgetinstance|gi <classuri> [<namespace>]\n");
		fprintf (stdout, "\tsetinstance|si <classuri> <property_name_value_pairs> [<namespace>]\n");
		fprintf (stdout, "\tinvoke|im <classuri> <method_name> <argument_name_value_pairs> [<namespace>]\n");
		return;
	}
	return;
}

};  /* namespace dashcli */
