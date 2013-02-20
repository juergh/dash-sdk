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
 * help.h
 */
#ifndef __DCLI_HELP_H__
#define __DCLI_HELP_H__
#include <vector>
#include <string>
#include "cmdoption.h"

using std::vector;
using std::string;

namespace dashcli
{

/**
 * displays the general help
 *
 
  @section dashclihelp Dash CLI Command Format
	Usage: dashcli [options] commands\n
	@section clioptions Options allowed:
	- -h host_address\n
	- -p port\n
	- -u username\n
	- -P password\n
	- -a authtype\n
	- -t targetpath\n
	- -s start ip\n
	- -e end ip\n
	- -v verbose\n

   @section clicommands Commands allowed:
	- help				-	Display help\n
	- enumerate			-	Enumerate targets\n
	- show				-	Show information\n
	- discover			-	Perform discovery\n
	- registeredprofile	-	Checks the profile support
	- subscribe			-	Subscribe to an event\n
	- unsubscribe		-	Unsubscribe an event\n
	- renew				-	Renew an event\n
	- listenevents		-	Listen for events\n
	- raw				-	Issue raw commands\n
	- shell				-	Launch interactive DASH shell\n

	@section clitargets Targets allowed:
	- @subpage computersystemhelp\n
	- @subpage processorhelp\n
	- @subpage memoryhelp\n
	- @subpage sensorhelp\n
	- @subpage powersupplyhelp\n
	- @subpage fanhelp\n
	- @subpage softwarehelp\n
	- @subpage operatingsystemhelp\n
	- @subpage bioshelp\n
	- @subpage bootconfighelp\n
	- @subpage batteryhelp\n
	- @subpage userhelp\n
	- @subpage rolehelp\n
	- @subpage networkporthelp\n
	- @subpage dhcpclienthelp\n
	- @subpage ipinterfacehelp\n
	- @subpage dnsclienthelp\n
	- @subpage opaquemanagementdatahelp\n
	- @subpage textredirectionhelp\n
	- @subpage usbredirectionhelp\n
	- @subpage indicationfilterhelp\n
	- @subpage filtercollectionhelp\n
	- @subpage alertdestinationhelp\n
	- @subpage indicationsubscriptionhelp\n
	- @subpage ethernetporthelp\n
 */

extern void displayGeneralHelp (void);


/**
 * Displays capability help

 @page capabilityhelp capability 
Allowed commands:\n
	- profile\n
	- features\n
*/
extern void displayCapabilityHelp ();

/**
 * Displays computer system help

 @page computersystemhelp computersystem 
Allowed commands:\n
	- show\n
	- power       [status|on|off|cycle|reset]\n
	- enumerate   [processor|sensor|fan|memory|asset]\n
	- user        [list|add|modify|delete]\n
	- bootconfig  [list|add|delete|changeorder|setdefault|setnext]\n
*/
extern void displayComputerSystemHelp (const vector<string>& commands, 
									   size_t ix);

/**
 * Displays processor help
 @page processorhelp processor
 Allowed commands:\n
 - show\n
 - status\n
 - enumerate [sensor|fan|memory|asset]\n

 */
extern void displayProcessorHelp (const vector<string>& commands, size_t ix);

/**
 * Displays memory help
 @page memoryhelp memory
 Allowed commands:\n
 - show\n
 */
extern void displayMemoryHelp (const vector<string>& commands, size_t ix);

/**
 * Displays Asset help
 @page memoryhelp memory
 Allowed commands:\n
 - show\n
 */
extern void displayAssetHelp (const vector<string>& commands, size_t ix);

/**
 * Displays sensor help
 @page sensorhelp sensor
  Allowed commands:\n
 - show\n
 - reading\n
 - setthreshold [lnc|unc|lc|uc|lf|uf]\n
 */
extern void displaySensorHelp (const vector<string>& commands, size_t ix);

/**
 * Displays power supply help
 @page powersupplyhelp powersupply
 Allowed commands:\n
 - show\n
 */
extern void displayPowerSupplyHelp (const vector<string>& commands, size_t ix);

/**
 * Displays fan help
 @page fanhelp fan
 Allowed commands:\n
 - show\n
 - speed [get|set]\n
 - enumerate asset\n
 */
extern void displayFanHelp (const vector<string>& commands, size_t ix);

/**
 * Displays Boot Config help

 @page bootconfighelp bootconfig
 Allowed commands:\n
 - show\n
 - changebootorder\n
 - delete\n
 - setdefault\n
 - setnext\n
 */
extern void displayBootConfigHelp (const vector<string>& commands, size_t ix);

/**
 * Displays software help
 @page softwarehelp software
 Allowed commands:\n
 - show\n
 */
extern void displaySoftwareHelp (const vector<string>& commands, size_t ix);

/**
 * Displays user help
 @page userhelp user
 Allowed commands:\n
 - show\n
 - delete\n
 - assignroles <rolename_1> [<rolename_2> ... <rolename_n>]\n
 - removeroles <rolename_1> [<rolename_2> ... <rolename_n>]\n
 */
extern void displayUserHelp (const vector<string>& commands, size_t ix);

/**
 * Displays BIOS help
 @page Bioshelp Bios
 Allowed commands:\n
 - show\n
 - restoredefaults\n
 - setattribute <attributename> <value_1> [<value_2>... <value_n>]\n
 */
extern void displayBIOSHelp (const vector<string>& commands, size_t ix);

/**
 * Displays OpaqueManagementData help
 @page opaquemanagementdatahelp opaquemanagementdata 
 Allowed commands:\n
 - show\n
 - write <offsettowrite> <bytestowrite> <data_1> [<data_2>... <data_n>]\n
 - read <offsettoread> <bytestoread>\n
 */
extern void displayOpaqueManagementDataHelp (const vector<string>& commands, size_t ix);

/**
 * Displays UsbRedirection help
 @page usbredirectionhelp usbredirection
 Allowed commands:\n
 - show\n
 - listlocaldrives\n
 - startvmr  drive|image  <driveimagename>\n
 */
extern void displayUsbRedirectionHelp (const vector<string>& commands, size_t ix);

/**
 * Displays Operating System help
 @page operatingsystemhelp operatingsystem
 Allowed commands:\n
 - show\n
 */
extern void displayOperatingSystemHelp (const vector<string>& commands, size_t ix);

/**
 * Displays battery help
 @page batteryhelp battery
 Allowed commands:\n
 - show\n
 - enable\n
 - disable\n
 - test\n
 - recharge\n
 */
extern void displayBatteryHelp (const vector<string>& commands, size_t ix);

/**
 * Displays role help
 @page rolehelp role
 Allowed commands:\n
 - show\n
 - modify\n
 - delete\n
 - assignpermissions\n
 - getsupportedqualifiers\n
 */
extern void displayRoleHelp (const vector<string>& commands, size_t ix);

/**
 * Displays networkport help
 @page networkporthelp networkport
 Allowed commands:\n
 - show\n
 */
extern void displayNetworkPortHelp (const vector<string>& commands, size_t ix);

/**
 * Displays CDHCPClient help
 @page dhcpclienthelp dhcpclient 
 Allowed commands:\n
 - show\n
 */
extern void displayDHCPClientHelp (const vector<string>& commands, size_t ix);

/**
 * Displays IPInterface help
 @page ipinterfacehelp ipinterface 
 Allowed commands:\n
 - show\n
 */
extern void displayIPInterfaceHelp (const vector<string>& commands, size_t ix);

/**
 * Displays DNSClient help
 @page dnsclienthelp dnsclient 
 Allowed commands:\n
 - show\n
 */
extern void displayDNSClientHelp (const vector<string>& commands, size_t ix);

/**
 * Displays TextRedirection help
 @page TextRedirectionHelp textredirection
 Allowed commands:\n
 - show\n
 - activate\n
 - enable\n
 - disable\n
 - start\n
 */
extern void displayTextRedirectionHelp (const vector<string>& commands, size_t ix);

/**
 * Displays Account help
 @page AccountHelp account
 Allowed commands:\n
 - manage\n
 
 */
extern void displayAccountHelp (const vector<string>& commands, size_t ix);

/**
 * Displays Role help
 @page RoleHelp account
 Allowed commands:\n
 - manage\n
 
 */
extern void displayRolesHelp (const vector<string>& commands, size_t ix);

/**
 * Displays IndicationFilter help
 @page indicationfilterhelp indicationfilter
 Allowed commands:\n
 - show\n
 - delete\n
 */
extern void displayIndicationFilterHelp (const vector<string>& commands, size_t ix);

/**
 * Displays FilterCollection help
 @page filtercollectionhelp filtercollection
 Allowed commands:\n
 - show\n
 - delete\n
 */
extern void displayFilterCollectionHelp (const vector<string>& commands, size_t ix);

/**
 * Displays ListenerDestination help
 @page listenerdestinationhelp listenerdestination
 Allowed commands:\n
 - show\n
 - delete\n
 */
extern void displayAlertDestinationHelp (const vector<string>& commands, size_t ix);

/**
 * Displays IndicationSubscription help
 @page indicationsubscriptionhelp indicationsubscription
 Allowed commands:\n
 - show\n
 - delete\n
 */
extern void displayIndicationSubscriptionHelp (const vector<string>& commands, size_t ix);

/**
 * Displays EthernetPort help
 @page ethernetporthelp ethernetport
 Allowed commands:\n
 - show\n
 */

/*
 * displayDynamicSubscribeHelp
 */
extern void displayStaticSubscribeHelp (void);
extern void displayDynamicSubscribeHelp (void);
extern void displayEthernetPortHelp (const vector<string>& commands, size_t ix);

extern bool displayTargetHelp (string target, 
							   const vector<string>& commands, size_t ix);
extern void displayRawHelp (const vector<string>& commands, size_t ix);
extern void doHelp (const CCmdOption& options, const vector<string>& commands, size_t ix);
extern void displayIndicationHelp   (const vector<string>& commands, size_t ix);
extern void displayRawCommandHelp (void);
extern void displayRegisteredProfileHelp (const vector<string>& commands, size_t ix);




};	/* namespace dashcli */

#endif /* __DCLI_HELP_H__ */



