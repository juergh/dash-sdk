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
 * subscribe.h
 */
#include "indication.h"
#include "help.h"
#include <ctype.h>
#include <stdlib.h>
#include <istream>
#include <ios>
#include <dsdk/cimmap.h>
#include <dsdk/indications.h>
#include <dsdk/eventsubscribe.h>
#include "dashcli.h"
#include <dsdk/oal/CIM_FilterCollection.h>
#include <dsdk/oal/CIM_IndicationFilter.h>
bool isVerbose	= false;
using namespace dsdk;

namespace dashcli
{
using namespace std;

/**
 * Returns the items corresponding to the instance number 
 */
template<class T_Item>
vector<T_Item>
getInstance (typename T_Item::iterator iter)
{
	
	vector<T_Item>  ret;
	int ix = 0;     
	for (; iter != T_Item::iterator::end (); ++iter)
	{
		try {
			ret.push_back (*iter);
		}
		catch (ECIMError& e)
		{
			fprintf (stderr, "Error getting instance %d", ix); 
			if (isVerbose) { fprintf (stderr, "\nError: %s", e.what ()); }
		}
		ix++;
	}
	return ret;
}


void showFiltercollectionInstances(IClient* client)	{

	CFilterCollection::iterator iter = CFilterCollection::enumFilterCollection (client);
	vector<CFilterCollection>  vt = getInstance<CFilterCollection>(iter);

	for (size_t i = 0; i < vt.size (); i++)                         
	{                                                               
		fprintf (stdout, "\n Filter Collection Instance %d\n",i);                      

		try         { fprintf (stdout, "\tInstanceID         : %s\n", vt[i].getInstanceID ().c_str ());}
		catch (...) { fprintf (stdout, "\tInstanceID         : %s\n", "N/A");}
		try         { fprintf (stdout, "\tCollectionName     : %s\n", vt[i].getCollectionName ().c_str ());}
		catch (...) { fprintf (stdout, "\tCollectionName     : %s\n", "N/A");}
	}                                                               
}

int showIndicationSubscriptionInstances(IClient* client)	{

	CAbstractIndicationSubscription::iterator iter = CAbstractIndicationSubscription::enumIndicationSubscription (client);
	vector<CAbstractIndicationSubscription>  _is = getInstance<CAbstractIndicationSubscription>(iter);
	size_t i;
	for ( i = 0; i < _is.size (); i++)                         
	{                                                               
		fprintf (stdout, "\n Filter Collection Instance %d\n",i);                      

		try         { fprintf (stdout, "Filter Name                : %s\n", _is[i].getFilternName(client).c_str());}
		catch (...) { fprintf (stdout, "Filter Name                : %s\n", "N/A");}
		try         { fprintf (stdout, "Destination                : %s\n", _is[i].getAlertDestination(client).c_str());}
		catch (...) { fprintf (stdout, "Destination                : %s\n", "N/A");}
		try         { fprintf (stdout, "OnFatalErrorPolicy         : %d\n", _is[i].getOnFatalErrorPolicy());}
		catch (...) { fprintf (stdout, "OnFatalErrorPolicy         : %s\n", "N/A");}
		try         { fprintf (stdout, "OtherOnFatalErrorPolicy    : %s\n", _is[i].getOtherOnFatalErrorPolicy().c_str());}
		catch (...) { fprintf (stdout, "OtherOnFatalErrorPolicy    : %s\n", "N/A");}
		try         { fprintf (stdout, "FailureTriggerTimeInterval : %llu\n", _is[i].getFailureTriggerTimeInterval());}
		catch (...) { fprintf (stdout, "FailureTriggerTimeInterval : %s\n", "N/A");}
		try         { fprintf (stdout, "SubscriptionState          : %d\n", _is[i].getSubscriptionState());}
		catch (...) { fprintf (stdout, "SubscriptionState          : %s\n", "N/A");}
		try         { fprintf (stdout, "OtherSubscriptionState     : %s\n", _is[i].getOtherSubscriptionState().c_str());}
		catch (...) { fprintf (stdout, "OtherSubscriptionState     : %s\n", "N/A");}
		try         { fprintf (stdout, "RepeatNotificationPolicy   : %d\n", _is[i].getRepeatNotificationPolicy());}
		catch (...) { fprintf (stdout, "RepeatNotificationPolicy   : %s\n", "N/A");}
		try         { fprintf (stdout, "RepeatNotificationInterval : %llu\n", _is[i].getRepeatNotificationInterval());}
		catch (...) { fprintf (stdout, "RepeatNotificationInterval : %s\n", "N/A");}
		try         { fprintf (stdout, "RepeatNotificationGap      : %llu\n", _is[i].getRepeatNotificationGap());}
		catch (...) { fprintf (stdout, "RepeatNotificationGap      : %s\n", "N/A");}
		try         { fprintf (stdout, "RepeatNotificationCount    : %d", _is[i].getRepeatNotificationCount());}
		catch (...) { fprintf (stdout, "RepeatNotificationCount    : %s", "N/A");}
	}                                                               

	return i;
}


void showIndicationFilterInstances(IClient* client)	{

	CIndicationFilter::iterator iter = CIndicationFilter::enumIndicationFilter (client);
	
	vector<CIndicationFilter>  vt = getInstance<CIndicationFilter>(iter);

	

	for (size_t i = 0; i < vt.size (); i++)                         
	{                                                               
		fprintf (stdout, "\n\n Indication Filter Instance %d\n",i);                      

		try         { fprintf (stdout, "\tSystemCreationClassName         : %s\n", vt[i].getSystemCreationClassName ().c_str ());}
		catch (...) { fprintf (stdout, "\tSystemCreationClassName         : %s\n", "N/A");}
		try         { fprintf (stdout, "\tSystemName                      : %s\n", vt[i].getName ().c_str ());}
		catch (...) { fprintf (stdout, "\tSystemName                      : %s\n", "N/A");}
		try         { fprintf (stdout, "\tCreationClassName               : %s\n", vt[i].getCreationClassName().c_str());}
		catch (...) { fprintf (stdout, "\tCreationClassName               : %s\n", "N/A");}
		try         { fprintf (stdout, "\tName                            : %s\n", vt[i].getName().c_str());}
		catch (...) { fprintf (stdout, "\tName                            : %s\n", "N/A");}
		try         { fprintf (stdout, "\tQuery                           : %s\n", vt[i].getQuery().c_str());}
		catch (...) { fprintf (stdout, "\tQuery                           : %s\n", "N/A");}
		try         { fprintf (stdout, "\tQueryLanguage                   : %s\n", vt[i].getQueryLanguage().c_str());}
		catch (...) { fprintf (stdout, "\tQueryLanguage                   : %s\n", "N/A");}
		try         { fprintf (stdout, "\tSourceNamespace                 : %s\n", vt[i].getSourceNamespace().c_str());}
		catch (...) { fprintf (stdout, "\tSourceNamespace                 : %s\n", "N/A");}
		try         { fprintf (stdout, "\tElement Name                    : %s\n", vt[i].getElementName().c_str());}
		catch (...) { fprintf (stdout, "\tElement Name                    : %s\n", "N/A");}
		try         { fprintf (stdout, "\tIndividualSubscriptionSupported : %s", vt[i].getIndividualSubscriptionSupported()? "True":"False");}
		catch (...) { fprintf (stdout, "\tIndividualSubscriptionSupported : %s", "N/A");}
	}                                                               
}

int getSubscriptionCommands(IClient* client,vector<string> &commands) {

		int choice=1;
		string tempStr;

		tempStr = commands[0];
		commands.clear();

		commands.push_back(tempStr);
		char notifyURI[100]="";
		fprintf(stdout,"\n\n Notification URI [Mandatory]:");
		rewind(stdin);
		scanf("%[a-zA-Z0-9+*-/\\-:.]",notifyURI);
		rewind(stdin);
		#ifndef _WIN32
			getchar();
		#endif
		tempStr = notifyURI;
		
		if(tempStr.empty()) {
			fprintf(stdout,"\n\n [ERROR] : Cannot proceed as the Notification URI is empty or invalid.");
			return -1;
		} 
		commands.push_back("");	// Push empty element so that filter type can be set later.
		commands.push_back(tempStr);

		// Accepting Delivery Mode
		fprintf(stdout,"\n DELIVERY MODES [Mandatory]:");
		fprintf(stdout,"\n\t [1]. Push");
		fprintf(stdout,"\n\t [2]. PushWithAck");
		fprintf(stdout,"\n\t [3]. Batch");
		fprintf(stdout,"\n\t [4]. Pull");
		fprintf(stdout,"\n\n\t Choose Mode [1] :");
		int c;
		scanf("%d",&c);
		rewind(stdin);
		#ifndef _WIN32
			getchar();			
		#endif
		switch(c) {
			case 1:
				commands.push_back("push");
				break;
			case 2:
				commands.push_back("pushack");
				break;
			case 3:
				commands.push_back("pushbatch");
				break;
			case 4:
				commands.push_back("pull");
				break;
			default:
				fprintf(stdout,"\n No (or) invalid option selected. Using PUSH as default mode.");
				commands.push_back("push");
				break;

		}
			
		char expiryTime[30]="";

		fprintf(stdout,"\n\n Expiration Time [Optional] :");
		scanf("%[a-zA-Z0-9+*/-:]",expiryTime);
		rewind(stdin);
		#ifndef _WIN32
			getchar();
		#endif
		tempStr = expiryTime;
		
		if( tempStr.empty())	{
			commands.push_back("NULL");
		} else {
			commands.push_back(tempStr);
		}

		while(true)	{

			fprintf(stdout,"\n\n FILTER TYPES [Mandatory]:");
			fprintf(stdout,"\n\t [1]. Dynamic Filter (Through CQL/WQL Query)");
			fprintf(stdout,"\n\t [2]. Static Filter");
			fprintf(stdout,"\n\t [3]. Filter Collection");

			fprintf(stdout,"\n\n\t Choose the type of filter subscription [1/2/3]: ");
			fscanf(stdin,"%d",&choice);
			rewind(stdin);
			#ifndef _WIN32
				getchar();
			#endif	
			if(choice == 1) {
				commands[1] = "dynamicsubscribe";
				
				char temp[100]="";
				fprintf(stdout,"\n\n Query Language Type [CQL/WQL]: ");
				scanf("%[a-zA-Z]",temp);
				rewind(stdin);
				#ifndef _WIN32
					getchar();
				#endif
				tempStr = temp;
				
				if(tempStr.empty()) {
					fprintf(stdout,"\n\n\t No (or) invalid query language opted. Using CQL as default.");
					tempStr = "CQL";
				}
				commands.push_back(tempStr);


				fprintf(stdout,"\n\n Query [Mandatory]: ");
				gets(temp);
				rewind(stdin);
				tempStr = temp;
				
				if(tempStr.empty() || tempStr.length() < 5) {
					fprintf(stdout,"\n\n\t[Error] Invalid query entered.");
					return -1;
				}
				commands.push_back(tempStr);

				fprintf(stdout,"\n\n Resource URI [Optional]: ");
				tempStr.clear();
				char temp1[100] = "";
				scanf("%[a-zA-Z0-9+*/\\-:.]",temp1);
				rewind(stdin);
				#ifndef _WIN32
					getchar();
				#endif
				tempStr = temp1;
				
				if(tempStr.empty()) {
					tempStr = "http://schemas.dmtf.org/wbem/wscim/1/*";
				}
				commands.push_back(tempStr);
				break;

			} else if(choice == 2) {
				commands[1] = "staticsubscribe";
				fprintf(stdout,"\n\n Requesting for filters. Please wait.....");

				try {
					showIndicationFilterInstances(client);
				} catch (exception& e) {
					fprintf(stdout,"\n\n ERROR: No static filters are available to subscribe.");
					if (isVerbose) { 
						fprintf (stderr, "Error: %s", e.what ()); 
					}
					continue;
				}
				//fprintf(stdout, 
					//"Static filter subscription might not be supported.	Choose other filter type...");
		
				char instNumber[4];				
				fprintf(stdout,"\n\n Choose valid instance number from the above list : ");
				scanf("%[0-9]",instNumber);
				rewind(stdin);
				#ifndef _WIN32
					getchar();
				#endif
				commands.push_back(instNumber);
				break;

			} else if(choice == 3) {
				commands[1] = "collectionsubscribe";
				fprintf(stdout,"\n\n Requesting for filter collections. Please wait.....");
				try {
					showFiltercollectionInstances(client);
				}catch (exception& e) {
					fprintf(stdout,"\n\n ERROR: No filter collections are available to subscribe.");
					if (isVerbose) { 
						fprintf (stderr, "Error: %s", e.what ()); 
					}
					continue;
				}
				fprintf(stdout,"\n\n Choose valid instance number from the above list : ");
				char instNumber[4]="";
				scanf("%[0-9]",instNumber);
				rewind(stdin);
				#ifndef _WIN32
					getchar();
				#endif
				commands.push_back(instNumber);
				break;
				
			} else {
				//commands[1] = "N-o-n-e";
				fprintf(stderr, "\n\n Invalid option selected...");
				continue;
			}
		}


		// Accept EndTo URI
		char endToURI[100]="";
		fprintf(stdout,"\n\n EndTo URI [Default - Delivered to NotifyTo URI]:");
		scanf("%[a-zA-Z0-9+*/\\-:.]",endToURI);
		rewind(stdin);
		#ifndef _WIN32
			getchar();
		#endif
		tempStr = endToURI;
		
		if(tempStr.empty()) {
			commands.push_back("NULL");
		} else {
			commands.push_back(tempStr);
		}

		// Accept encode type
		string opt="0";
		fprintf(stdout,"\n\n Encode type [Optional] :");
		fprintf(stdout,"\n\t 1. UTF-8");
		fprintf(stdout,"\n\t 2. UTF-16");
		fprintf(stdout,"\n\n\t Choose the type [1/2] :");
		scanf("%c",opt.c_str());
		rewind(stdin);
		#ifndef _WIN32
			getchar();
		#endif
		if(opt == "1") {
			commands.push_back("UTF-8");
		} else if(opt == "2") {
			commands.push_back("UTF-16");
		} else {
			commands.push_back("NULL");
		}

		// locale
		char locale[20]="";
		fprintf(stdout,"\n\n Locale (Ex: ln-en) [Optional] :");
		scanf("%[a-zA-Z0-9+-_*/\\-:.]",locale);
		rewind(stdin);
		#ifndef _WIN32
			getchar();
		#endif
		tempStr = locale;
		if(tempStr.empty()) {
			commands.push_back("NULL");
		} else {
			commands.push_back(tempStr);
		}

		// bookmarks
		string bookmark="N";
		fprintf(stdout,"\n\n Request BookMarks [Y/N] [Optional] :");
		scanf("%c",bookmark.c_str());
		rewind(stdin);
		#ifndef _WIN32
			getchar();
		#endif
		if(bookmark == "Y" || bookmark == "y") {
			commands.push_back("YES");
		} else {
			commands.push_back("NULL");
		}

		// Heartbeat Interval
		char hbeatIntrval[10]="";
		fprintf(stdout,"\n\n Heartbeat Interval in seconds [Optional] :");
		scanf("%[0-9]",hbeatIntrval);
		rewind(stdin);
		#ifndef _WIN32
			getchar();
		#endif
		tempStr = hbeatIntrval;
		if(tempStr.empty()) {
			commands.push_back("NULL");
		} else {
			tempStr.clear();
			tempStr.append("PT").append(hbeatIntrval).append("S");
			commands.push_back(tempStr);
		}

		// Connection Retry
		char retryCount[5]="0";
		fprintf(stdout,"\n\n Connection Retry Count [Optional] :");
		scanf("%[0-9]",retryCount);
		rewind(stdin);
		#ifndef _WIN32
			getchar();
		#endif
		tempStr = retryCount;
		if(tempStr.empty()) {
			commands.push_back("NULL");
		} else {
			commands.push_back(tempStr);
		}

		return 0;
}


/*
 * doCreateFilter
 */
int 
doCreateFilter (IClient* client, vector<string> commands)
{
	try
	{
		if (commands.size () < 4) 
		{
			fprintf (stderr, "Error: Invalid options for createfilter\n");
			displayIndicationHelp (commands, 1);
			return -1;
		}

		CIndicationFilter::createFilter (client, commands [2], commands [3]);
		
		fprintf (stdout, "Filter created successfully");
		return 0;
	}
	catch (exception& e)
	{
		fprintf (stderr, "Error: Creating indicaton filter\n");
		if (isVerbose) { 
			fprintf (stderr, "Error: %s", e.what ()); 
		}

		return -1;
	}
}

/*
 * doCreateFilterCollection
 */
int 
doCreateFilterCollection (IClient* client, vector<string> commands)
{
	try
	{
		if (commands.size () < 4) 
		{
			fprintf (stderr, "Error: Invalid options for createcollectionfilter\n");
			displayIndicationHelp (commands, 1);
			return -1;
		}
		//@todo: As the current target (broadcom/Intel) doesn;t allow to create filtercollection we are commenting out this 
		//CFilterCollection::createFilterCollection (client, commands [2], commands [3]);
		
		fprintf (stdout, "Filter Collection created successfully");
		return 0;
	}
	catch (exception& e)
	{
		fprintf (stderr, "Error: Creating filter Collection\n");
		if (isVerbose) { 
			fprintf (stderr, "Error: %s", e.what ()); 
		}

		return -1;
	}
}

/*
 * doCreateDestination
 */
int
doCreateDestination (IClient* client, vector<string> commands)
{
	try
	{
		if (commands.size () < 3) 
		{
			fprintf (stderr, "Error: Invalid options for createfilter\n");
			displayIndicationHelp (commands, 1);
			return -1;
		}

		CAlertDestination::createDestination (client, commands [2]);
		
		fprintf (stdout, "Destination created successfully");
		return 0;
	}
	catch (exception& e)
	{
		fprintf (stderr, "Error: Creating alert destination\n");
		if (isVerbose) { 
			fprintf (stderr, "Error: %s", e.what ()); }

		return -1;
	}
}


/*
 * doSubscribe
 */
int
doStaticSubscribe (IClient* client, vector<string> commands)
{
	try
	{
		if (commands.size () == 6)
		{
			int filter_instance;

			if (-1 == dashcli_strtol (commands [5].c_str (), (long*)&filter_instance))
			{
				fprintf (stderr, "Error : Invalid Filter instance");
				return -1;
			}

			CIndicationFilter::iterator filter = CIndicationFilter::enumIndicationFilter (client);
			for (int i = 0; filter != CIndicationFilter::iterator::end (); ++filter, i++)
			{
				if (filter_instance == i) { break; }
			}
			if (filter == CIndicationFilter::iterator::end ())
			{
				fprintf (stderr, "Error : Filter instance %d not found", filter_instance);
				return -1;
			}

			//int 	mode;
			//float	expiration_timeout;

			//if 		(commands [3] == "push") 		{ mode = 0; }
			//else if (commands [3] == "pushack")		{ mode = 1; }
			//else if (commands [3] == "pushbatch")	{ mode = 3; }
			//else if (commands [3] == "pull")		{ mode = 4; }
			//else
			//{
			//	fprintf (stderr, "Error: Invalid subscription mode\n");
			//	displayIndicationHelp (commands, 1);
			//	return -1;
			//}

			//long val;
			//if (-1 == dashcli_strtol (commands [4].c_str (), &val))
			//{
			//	fprintf (stderr, "Error : Invalid expiration timeout number");
			//	return -1;
			//}
			//expiration_timeout = (float)val;

			//this function shoulbe replaced with CIndicationSubscription::createSubscription 
			/*string uuid = CIndicationSubscription::createSubscription (client, 
												  *filter,
												  commands [2], 
												  mode,  
												  0,
												  expiration_timeout);*/

			uint16 mode=0;
			if 		(commands [3] == "push") 		{ mode = CSubscriptionParams::SUBSCRIBE_DELIVERYMODE_PUSH; }
			else if (commands [3] == "pushack")		{ mode = CSubscriptionParams::SUBSCRIBE_DELIVERYMODE_PUSHWITHACK;}
			else if (commands [3] == "pushbatch")	{ mode = CSubscriptionParams::SUBSCRIBE_DELIVERYMODE_BATCH; }
			else if (commands [3] == "pull")		{ mode = CSubscriptionParams::SUBSCRIBE_DELIVERYMODE_PULL; }

			
			CSubscriptionParams subscribeParams = CSubscriptionParams(commands[2], mode);
			
			if(commands[4] != "NULL") {
				subscribeParams.setExpirationTime(commands[4]);	
			}

			if(commands[6] != "NULL")	{
				subscribeParams.setEndToURI(commands[6]);
			}

			if(commands[7] == "UTF-16")	{
				subscribeParams.setEncodeType(CSubscriptionParams::SUBSCRIBE_ENCODETYPE_UTF16);
			} else if(commands[7] == "UTF-8") {
				subscribeParams.setEncodeType(CSubscriptionParams::SUBSCRIBE_ENCODETYPE_UTF8);
			}

			if(commands[8] != "NULL")	{
				subscribeParams.setLocale(commands[8]);
			}
			
			if(commands[9] != "NULL")	{
				subscribeParams.enableBookMarks(true);
			}

			if(commands[10] != "NULL")	{
				subscribeParams.setHeartBeatInterval(commands[10]);
			}

			if(commands[11] != "NULL")	{
				int count = atoi(commands[11].c_str());
				subscribeParams.setConnectionRetryCount(count);
			}


			string uuid = CIndicationSubscription::createSubscription(client, *filter, subscribeParams);


//			fprintf (stdout, "UUID: %s\n", uuid.c_str ());
			fprintf (stdout, "Indication subscription created successfully");
			return 0;
		}
		else
		{
				fprintf (stderr, "Error: Invalid options for subscription\n");
				displayStaticSubscribeHelp ();
				return -1;
		}
	}
	catch (exception& e)
	{
		fprintf (stderr, "Error: Subscribe Events Failed\n");
		if (isVerbose) { 
			fprintf (stderr, "Error: %s", e.what ());
		}
		return -1;
	}

}
/*
 * doDynamicSubscribe
 */
int
doDynamicSubscribe (IClient* client, vector<string> commands)
{

	/*	for(uint16 i=0;i<commands.size();i++)	{
			fprintf(stdout,"\n %d = %s",i,commands[i].c_str());
		}*/
		try
		{
			if (commands.size () < 7) 
			{
				fprintf (stderr, "Error: Invalid options for subscription\n");
				displayDynamicSubscribeHelp ();
				return -1;
			}

			/*int 	mode;
			float	expiration_timeout;

			if 		(commands [3] == "push") 		{ mode = 0; }
			else if (commands [3] == "pushack")		{ mode = 1; }
			else if (commands [3] == "pushbatch")	{ mode = 3; }
			else if (commands [3] == "pull")		{ mode = 4; }
			else
			{
				fprintf (stderr, "Error: Invalid subscription mode\n");
				displayIndicationHelp (commands, 1);
				return -1;
			}

			long val;
			if (-1 == dashcli_strtol (commands [4].c_str (), &val))
			{
				fprintf (stderr, "Error : Invalid expiration timeout number");
				return -1;
			}
			expiration_timeout = (float)val;

			string resource_uri;
			if (commands.size () > 7)
			{
				resource_uri = commands [7];
			}
			else 
			{
				resource_uri = "http://schemas.dmtf.org/wbem/wscim/1/*";
			}*/

			//this function shoulbe replaced with CIndicationSubscription::createSubscription 
			//string uuid = CIndicationSubscription::createSubscription (client, 
			//									  commands [5], commands [6], 
			//									  commands [2], mode,  
			//									  0,
			//									  expiration_timeout,
			//									  resource_uri);

			uint16 mode=0;
			if 		(commands [3] == "push") 		{ mode = CSubscriptionParams::SUBSCRIBE_DELIVERYMODE_PUSH; }
			else if (commands [3] == "pushack")		{ mode = CSubscriptionParams::SUBSCRIBE_DELIVERYMODE_PUSHWITHACK; }
			else if (commands [3] == "pushbatch")	{ mode = CSubscriptionParams::SUBSCRIBE_DELIVERYMODE_BATCH; }
			else if (commands [3] == "pull")		{ mode = CSubscriptionParams::SUBSCRIBE_DELIVERYMODE_PULL; }
			
			CSubscriptionParams subscribeParams = CSubscriptionParams(commands[2], mode);
			subscribeParams.setDynamicFilterOptions(commands[7],commands [6],commands [5]);
			
			if(commands[4] != "NULL") {
				subscribeParams.setExpirationTime(commands[4]);	
			}

			if(commands[8] != "NULL")	{
				subscribeParams.setEndToURI(commands[8]);
			}

			if(commands[9] == "UTF-16")	{
				subscribeParams.setEncodeType(CSubscriptionParams::SUBSCRIBE_ENCODETYPE_UTF16);
			} else if(commands[9] == "UTF-8") {
				subscribeParams.setEncodeType(CSubscriptionParams::SUBSCRIBE_ENCODETYPE_UTF8);
			}

			if(commands[10] != "NULL")	{
				subscribeParams.setLocale(commands[8]);
			}
			
			if(commands[11] != "NULL")	{
				subscribeParams.enableBookMarks(true);
			}

			if(commands[12] != "NULL")	{
				subscribeParams.setHeartBeatInterval(commands[12]);
			}

			if(commands[13] != "NULL")	{
				int count = atoi(commands[13].c_str());
				subscribeParams.setConnectionRetryCount(count);
			}

			
			string uuid = CIndicationSubscription::createSubscription (client, subscribeParams);

//			fprintf (stdout, "UUID: %s\n", uuid.c_str ());
			fprintf (stdout, "Event subscribed successfuly");
			return 0;
		}
	
		catch (exception& e)
		{
			fprintf (stderr, "Error: Subscribe Events Failed\n");
			if (isVerbose) { 
				fprintf (stderr, "Error: %s", e.what ());
			}
		}
		return -1;
}


/*
 * doCollectionSubscribe
 */
int
doCollectionSubscribe (IClient* client, vector<string> commands)
{

	if (commands.size () < 6)
	{
		displayIndicationHelp (commands, 1);
		return -1;
	}

	try
	{
		int filter_instance;

		if (-1 == dashcli_strtol (commands [5].c_str (), (long*)&filter_instance))
		{
			fprintf (stderr, "Error : Invalid Filter instance");
			return -1;
		}

		CFilterCollection::iterator filter = CFilterCollection::enumFilterCollection (client);
		for (int i = 0; filter != CFilterCollection::iterator::end (); ++filter, i++)
		{
			if (filter_instance == i) { break; }
		}
		if (filter == CFilterCollection::iterator::end ()) 
		{
			fprintf (stderr, "Error : Filter instance %d not found", filter_instance);
			return -1;
		}

		//int 	mode;
		//float	expiration_timeout;

		//if 		(commands [3] == "push") 		{ mode = 0; }
		//else if (commands [3] == "pushack")		{ mode = 1; }
		//else if (commands [3] == "pushbatch")	{ mode = 3; }
		//else if (commands [3] == "pull")		{ mode = 4; }
		//else
		//{
		//	fprintf (stderr, "Error: Invalid subscription mode\n");
		//	displayIndicationHelp (commands, 1);
		//	return -1;
		//}

		//long val;
		//if (-1 == dashcli_strtol (commands [4].c_str (), &val))
		//{
		//	fprintf (stderr, "Error : Invalid expiration timeout number");
		//	return -1;
		//}
		//expiration_timeout = (float)val;

		//string uuid = CFilterCollectionSubscription::createSubscription (client, 
		//									  *filter,
		//									  commands [2], 
		//									  mode,  
		//									  0,
		//									  expiration_timeout);
		
		uint16 mode=0;
		if 		(commands [3] == "push") 		{ mode = CSubscriptionParams::SUBSCRIBE_DELIVERYMODE_PUSH; }
		else if (commands [3] == "pushack")		{ mode = CSubscriptionParams::SUBSCRIBE_DELIVERYMODE_PUSHWITHACK; }
		else if (commands [3] == "pushbatch")	{ mode = CSubscriptionParams::SUBSCRIBE_DELIVERYMODE_BATCH; }
		else if (commands [3] == "pull")		{ mode = CSubscriptionParams::SUBSCRIBE_DELIVERYMODE_PULL; }
		
		CSubscriptionParams subscribeParams = CSubscriptionParams(commands[2], mode);
		
		if(commands[4] != "NULL") {
			subscribeParams.setExpirationTime(commands[4]);	
		}

		if(commands[6] != "NULL")	{
			subscribeParams.setEndToURI(commands[6]);
		}

		if(commands[7] == "UTF-16")	{
			subscribeParams.setEncodeType(CSubscriptionParams::SUBSCRIBE_ENCODETYPE_UTF16);
		} else if(commands[7] == "UTF-8") {
			subscribeParams.setEncodeType(CSubscriptionParams::SUBSCRIBE_ENCODETYPE_UTF8);
		}

		if(commands[8] != "NULL")	{
			subscribeParams.setLocale(commands[8]);
		}
		
		if(commands[9] != "NULL")	{
			subscribeParams.enableBookMarks(true);
		}

		if(commands[10] != "NULL")	{
			subscribeParams.setHeartBeatInterval(commands[10]);
		}

		if(commands[11] != "NULL")	{
			int count = atoi(commands[11].c_str());
			subscribeParams.setConnectionRetryCount(count);
		}


		
		string uuid = CFilterCollectionSubscription::createSubscription(client, *filter, subscribeParams);
//		fprintf (stdout, "UUID: %s\n", uuid.c_str ());
		fprintf (stdout, "Indication subscription created successfully");
		
		return 0;
	}
	catch (exception& e)
	{
		fprintf (stderr, "Error: Subscribe Events Failed\n");
		if (isVerbose) 
		{
			fprintf (stderr, "Error: %s", e.what ());
		}
		return -1;
	}

}



/*
 * doUnsubscribe
 */
int
doUnsubscribe (IClient* client, vector<string> commands)
{

	if (commands.size () > 2)
	{
		displayIndicationHelp (commands, 1);
		return -1;
	}

	try
	{

		if(showIndicationSubscriptionInstances(client) == 0) {
			fprintf(stdout,"\nNo valid subscriptions available at the target.");
			return 0;
		}
		char instNumber[4];				
		int subscription_instance;
		fprintf(stdout,"\n\n Choose valid instance number from the above list : ");
		rewind(stdin);
		scanf("%[0-9]",instNumber);
		if(1 == sscanf(instNumber,"%d",&subscription_instance))
			sprintf(instNumber,"%d",subscription_instance);
		/*
		if (-1 == dashcli_strtol (instNumber, (long*)&subscription_instance))
		{
			fprintf (stderr, "Error : Invalid Subscription instance");
			return -1;
		}
		*/

		CAbstractIndicationSubscription::iterator subscribeIter = 
			CAbstractIndicationSubscription::enumIndicationSubscription (client);
		int i = 0;
		for (i = 0; subscribeIter != CAbstractIndicationSubscription::iterator::end (); ++subscribeIter, i++)
		{
			if (subscription_instance == i) { 
				CAbstractIndicationSubscription inst
					= *subscribeIter;
				inst.unSubscribe();
				fprintf (stdout, "Unsubscribe operation successful.\n");
				break; 
			}
		}

		if (subscribeIter == CAbstractIndicationSubscription::iterator::end ()) 
		{
			fprintf (stderr, "Error : Subscription instance %d not found", subscription_instance);
			return -1;
		}
		
		
		return 0;
	}
	catch (exception& e)
	{
		fprintf (stderr, "Error: Unsubscribe operation Failed\n");
		if (isVerbose) 
		{
			fprintf (stderr, "Error: %s", e.what ());
		}
		return -1;
	}

}


/*
 * doRenewSubscrption
 */
int
doRenewSubscrption (IClient* client, vector<string> commands)
{

	if (commands.size () > 2)
	{
		displayIndicationHelp (commands, 1);
		return -1;
	}

	try
	{

		if(showIndicationSubscriptionInstances(client) == 0) {
			fprintf(stdout,"\nNo valid subscriptions available at the target.");
			return 0;
		}

		char instNumber[4];				
		fprintf(stdout,"\n\nChoose valid instance number from the above list : ");
		rewind(stdin);
		scanf("%[0-9]",instNumber);

		int subscription_instance;

		if (-1 == dashcli_strtol (instNumber, (long*)&subscription_instance))
		{
			fprintf (stderr, "Error : Invalid Subscription instance");
			return -1;
		}


		CAbstractIndicationSubscription::iterator subscribeIter = 
			CAbstractIndicationSubscription::enumIndicationSubscription (client);
		int i=0;
		for (i = 0; subscribeIter != CAbstractIndicationSubscription::iterator::end (); ++subscribeIter, i++)
		{
			if (subscription_instance == i) { 
				CAbstractIndicationSubscription inst
					= *subscribeIter;
				//inst.renewSubscription();
				fprintf (stdout, "Renew operation successful.\n");
				break; 
			}
		}

		if (subscribeIter == CAbstractIndicationSubscription::iterator::end ()) 
		{
			fprintf (stderr, "Error : Subscription instance %d not found", subscription_instance);
			return -1;
		}
		
		
		return 0;
	}
	catch (exception& e)
	{
		fprintf (stderr, "Error: Renew operation Failed\n");
		if (isVerbose) 
		{
			fprintf (stderr, "Error: %s", e.what ());
		}
		return -1;
	}


}


/*
 * doIndication
 */
int 
doIndication (CCmdOption options, vector<string> commands)
{
	int ret = 0;
	try
	{
		CSubject subject (options._user, options._password.c_str (), options._authtype);
		CCIMMAP cimmap (options._host, options._port);
		IClient* client = cimmap.connect (subject);

		isVerbose = options._is_verbose;

		/* Do raw processing here */
		if (commands.size () == 1)  { displayIndicationHelp (commands, 1); }
		else 
		{
			if (commands [1] == "createfilter")
			{ 
				try {
					ret = doCreateFilter (client, commands); 
				}
				catch (exception& e)
				{
					fprintf (stderr, "Error: Creating Filter\n");
					if (isVerbose)
					{
						fprintf (stderr, "Error: %s", e.what ());
					}
					ret = -1;
				}
			}
			if (commands [1] == "createcollectionfilter")
			{ 
				try {
					ret = doCreateFilterCollection (client, commands); 
				}
				catch (exception& e)
				{
					fprintf (stderr, "Error: Creating filter Collection\n");
					if (isVerbose)
					{
						fprintf (stderr, "Error: %s", e.what ());
					}
					ret = -1;
				}
			}
			else if (commands [1] == "createdestination")
			{ 
				try {
					ret = doCreateDestination (client, commands); 
				}
				catch (exception& e)
				{
					fprintf (stderr, "Error: Creating alert destination\n");
					if (isVerbose) { 
						fprintf (stderr, "Error: %s", e.what ());
					}
					ret = -1;
				}
			}
			else if (commands [1] == "dynamicsubscribe")
			{ 
				try {
					ret = doDynamicSubscribe (client, commands); 
				}
				catch (exception& e)
				{
					fprintf (stderr, "Error: Subscribe Events Failed\n");
					if (isVerbose) { 
						fprintf (stderr, "Error: %s", e.what ());
					}
					ret = -1;
				}
			}

			else if (commands [1] == "staticsubscribe")
			{ 
				try {
					ret = doStaticSubscribe (client, commands); 
				}
				catch (exception& e)
				{
					fprintf (stderr, "Error: Subscribe Events Failed\n");
					if (isVerbose) { 
						fprintf (stderr, "Error: %s", e.what ());
					}
					ret = -1;
				}
			}
			else if (commands [1] == "collectionsubscribe")
			{ 
				try {
					ret = doCollectionSubscribe (client, commands); 
				}
				catch (exception& e)
				{
					fprintf (stderr, "Error: Subscribe Events Failed\n");
					if (isVerbose) 
					{ 
						fprintf (stderr, "Error: %s", e.what ());
					}
					ret = -1;
				}
			} else if(commands[1] == "subscribe")
			{
				
				if(getSubscriptionCommands(client, commands) == -1) {
					ret = -1;
				} else {

					fprintf(stdout,"\n\nPerforming subscription. Please wait...\n\n");
					doIndication(options,commands);

				}
				
			}
			else if(commands[1] == "unsubscribe")
			{
				
				try {
					ret = doUnsubscribe (client, commands); 
				}
				catch (exception& e)
				{
					fprintf (stderr, "Error: Unsubscribing Events Failed\n");
					if (isVerbose) { 
						fprintf (stderr, "Error: %s", e.what ());
					}
					ret = -1;
				}
				
			}else if(commands[1] == "renew")
			{
				
				try {
					ret = doRenewSubscrption (client, commands); 
				}
				catch (exception& e)
				{
					fprintf (stderr, "Error: Renew Events Failed\n");
					if (isVerbose) { 
						fprintf (stderr, "Error: %s", e.what ());
					}
					ret = -1;
				}
				
			}

			else
			{
				fprintf (stderr, 
						 "Error: Invalid command '%s'", 
						 commands [1].c_str ());
				ret = -1;
			}
		}

		delete client;
	}
	catch (exception& e)
	{
		fprintf (stderr, "Error: Unkown Error\n");
		if (isVerbose)
		{
			fprintf (stderr, "Error: %s", e.what ());
		}
		ret = -1;
	}

	return ret;
}

/* Clean the Input Stream */
void cleanInputBuffer ()
{
	int c;
	while ((c = getchar()) != '\n')
	;
}

};	/* namespace dashcli */



