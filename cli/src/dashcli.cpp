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
 * dashcli.cpp
 * DASH Command line interface.
 */
#ifdef WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#endif
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include "cmdoption.h"
#include "help.h"
#include "targetpath.h"
#include "exec.h"
#include <dsdk/client.h>
#include <dsdk/dsdk.h>
#include "discovery.h"
#include "raw.h"
#include "dashcli.h"
#include <fstream>

using std::string;
using std::vector;
using std::list;
using namespace std;

using namespace dsdk;
using namespace dashcli;

/*--- global variable ---*/
namespace dashcli
{
bool isShell	= false;
bool isVerbose	= false;
bool isCmdBufNotEmpty = false;

};

/*
 * printCLIInfo
 */
void
printCLIInfo (void)
{

	fprintf (stdout, "dashcli %s\n", DASH_CLI_VERSION_FULL);
	fprintf (stdout, "\nCopyright (c) 2009  Advanced Micro Devices Inc.\n");
	fprintf (stdout, "Command Line Interface to manage DASH targets.\n");

}


/*
 * printUsage
 */
static void
printUsage (void)
{
	fprintf (stdout, "\n");
	printCLIInfo ();
	fprintf (stdout, "\n");
	displayGeneralHelp ();
}


/*
 * parseCmdOption
 */
int
parseCmdOption (vector<string> args, CCmdOption	&options, vector<string> &commands)
{

	/* Get the command line options */
	size_t i;

	for (i = 0;	i < args.size (); i += 1)
	{
		/* If command encountered - break */
		if (args [i].c_str ()[0] !=  '-') { break; }

		if (args [i] == "-h") 
		{
			/* sanity check */
			if ((i == (args.size () - 1)) || (args [i + 1].c_str ()[0] == '-'))
			{
				fprintf (stderr, "Error: Host name needs to follow -h\n");
				return -1;
			}

			options._host 			= args [i + 1]; 
			options._host_specified = true;
			i++;
		}
		else if (args [i] == "-p") 
		{
			/* sanity check */
			if ((i == (args.size () - 1)) || (args [i + 1].c_str ()[0] == '-')) 
			{
				fprintf (stderr, "Error: Port needs to follow -p\n");
				return -1;
			}

			string ports = args [i + 1];

			/* check if more than one port specified */
			if ((size_t)-1 == ports.find (','))
			{
				string port = args [i + 1];

				/* sanity check */
				for (size_t j = 0; j < port.size (); j++)
				{
					if (!isdigit (port [j])) 
					{
						fprintf (stderr, "Error: Invlaid port number %s\n", port.c_str ());
						return -1;
					}
				}

				options._port 			= port;
				options._port_specified = true;
				options._ports.push_back (port);
				i++;
			}
			else
			{
				/* if more than one ports specified */
				while (0 != ports.size ())
				{
					string port = ports.substr (0, ports.find (','));

					while ((size_t)-1 != port.find (' '))
					{
						port.erase (port.find (' '), 1);
					}

					/* sanity check */
					for (size_t j = 0; j < port.size (); j++)
					{
						if (!isdigit (port [j])) 
						{
							fprintf (stderr, "Error: Invlaid port number %s\n", port.c_str ());
							return -1;
						}
					}
					options._ports.push_back (port);

					if ((size_t)-1 == ports.find (','))
					{
						break;
					}
					ports = ports.substr (ports.find (',') + 1, ports.size ());
				}

				options._is_multiple_ports_specified = true;
				i++;
			}
		}
		else if (args [i] == "-u") 
		{
			/* sanity check */
			if ((i == (args.size () - 1)) || (args [i + 1].c_str ()[0] == '-')) 
			{
				fprintf (stderr, "Error: User name needs to follow -u\n");
				return -1;
			}

			options._user			= args [i + 1];
			options._user_specified 	= true;
			i++;
		}
		else if (args [i] == "-P") 
		{
			/* sanity check */
			if ((i == (args.size () - 1)) || (args [i + 1].c_str ()[0] == '-')) 
			{
				fprintf (stderr, "Error: Password needs to follow -P\n");
				return -1;
			}

			options._password			= args [i + 1];
			options._password_specified 	= true;
			i++;
		}
		else if (args [i] == "-a") 
		{
			/* sanity check */
			if ((i == (args.size () - 1)) || (args [i + 1].c_str ()[0] == '-')) 
			{
				fprintf (stderr, "Error: Authtype needs to follow -a\n");
				return -1;
			}

			options._authtype				= args [i + 1];
			options._authtype_specified 	= true;
			i++;
		}
		else if (args [i] == "-S") 
		{
			/* sanity check */
			if ((i == (args.size () - 1)) || (args [i + 1].c_str ()[0] == '-')) 
			{
				fprintf (stderr, "Error: HTTP scheme needs to follow -S\n");
				return -1;
			}

			string httpschemes = args [i + 1];

			/* check if more than one port specified */
			if ((size_t)-1 == httpschemes.find (','))
			{
				string httpscheme = args [i + 1];
				options._scheme 			= httpscheme;

				if((options._scheme == "http"||options._scheme == "https"))
				{
					options._scheme_specified = true;
					options._schemes.push_back(httpscheme);
					i++;
				}

				else 
				{
					fprintf(stderr,"Error: Invalid  scheme\n");
					return -1;
				}

			}

			else
			{
				
				/* if more than one httpscheme specified */
				while (0 != httpschemes.size ())
				{
					string httpscheme = httpschemes.substr (0, httpschemes.find (','));

					while ((size_t)-1 != httpscheme.find (' '))
					{
						httpscheme.erase (httpscheme.find (' '), 1);
					}
					if(httpscheme == "http" ||httpscheme == "https")
					{
						options._schemes.push_back (httpscheme);

						if ((size_t)-1 == httpschemes.find (','))
						{
							break;
						}

						httpschemes = httpschemes.substr (httpschemes.find (',') + 1, httpschemes.size ());
					}

					else 
					{
						fprintf(stderr, "Error: Invalid scheme\n");
						return -1;
					}
				}

				options._is_multiple_schemes_specified = true;
				i++;
			}
		}

		else if (args [i] == "-t") 
		{
			/* sanity check */
			if ((i == (args.size () - 1)) || (args [i + 1].c_str ()[0] == '-')) 
			{
				fprintf (stderr, "Error: target address needs to follow -t\n");
				return -1;
			}

			options._target_specified = true;
			options._target 		  = parseTargetPath (args [i + 1]);
			i++;
		}
		else if (args [i] == "-s") 
		{
			/* sanity check */
			if ((i == (args.size () - 1)) || (args [i + 1].c_str ()[0] == '-')) 
			{
				fprintf (stderr, "Error: start ip needs to follow -s\n");
				return -1;
			}

			options._start_ip_specified = true;
			options._start_ip			= args [i + 1];
			i++;
		}
		else if (args [i] == "-e") 
		{
			/* sanity check */
			if ((i == (args.size () - 1)) || (args [i + 1].c_str ()[0] == '-')) 
			{
				fprintf (stderr, "Error: end ip needs to follow -e\n");
				return -1;
			}

			options._end_ip_specified = true;
			options._end_ip			  = args [i + 1];
			i++;
		}
		else if (args [i] == "-T") 
		{
			/* sanity check */
			if ((i == (args.size () - 1)) || (args [i + 1].c_str ()[0] == '-')) 
			{
				fprintf (stderr, "Error: Timeout needs to follow -T\n");
				return -1;
			}

			if (-1 == dashcli_strtol (args [i + 1].c_str (), (long*)&options._timeout))
			{
				fprintf (stderr, "Error: Invalid timeout number %s\n", args [i + 1].c_str ());
				return -1;
			}

			options._timeout_specified	= true;
			i++;
		}
		else if (args [i] == "-c") 
		{
			/* sanity check */
			if ((i == (args.size () - 1)) || (args [i + 1].c_str ()[0] == '-')) 
			{
				fprintf (stderr, "Error: certificate file needs to follow -c\n");
				return -1;
			}

			options._certificate_file			= args [i + 1];
			options._is_certificate_specified 	= true;
			i++;
		}
		else if (args [i] == "-C") 
		{
			options._ignore_certificate	= true;
		}
		else if (args [i] == "-v")
		{
			/* sanity check */
			if ((i == (args.size () - 1)) || (args [i + 1].c_str ()[0] == '-')) 
			{
				fprintf (stderr, "Error: Verbose level needs to follow -v\n");
				return -1;
			}

			if (-1 == dashcli_strtol (args [i + 1].c_str (), (long*)&g_dsdk_verbose_level))
			{
				fprintf (stderr, "Error: Invalid verbose number %s\n", args [i + 1].c_str ());
				return -1;
			}

			options._is_verbose = true;
			isVerbose = true;
			
			i++;
		}
		else if (args [i] == "-o")
		{
			/* sanity check */
			if ((i == (args.size () - 1)) || (args [i + 1].c_str ()[0] == '-')) 
			{
				fprintf (stderr, "Error: Verbose output file name needs to follow -o\n");
				return -1;
			}

			string verbose_file = args [i + 1];
			g_dsdk_verbose_file = verbose_file.c_str ();
			if(ifstream(g_dsdk_verbose_file.c_str()))
			{
				remove(g_dsdk_verbose_file.c_str());
			}
			i++;
		}
		else 
		{
			fprintf (stderr, "Error: Invalid option %s\n", args [i].c_str ());
			return -1;
		}
	}

	/* Collect the commands */
	for (; i < args.size (); i++) 
	{ 
		commands.push_back (args [i]); 
	}

	/* Sanity check on the options and commands */
	/* ... Only discover and help does not require host address */
	if (!options._host_specified)
	{
		if ((commands.size () != 0) && 
			 (commands [0] != "help") && 
			 (commands [0] != "show") && 
			 (commands [0] != "shell") && 
			 (commands [0] != "exit") && 
			 (commands [commands.size () - 1] != "help") && 
			 (commands [0] != "discover") && 
			 (commands [0] != "listenevents"))
		{
			fprintf (stderr, "Error: Host name not specified for command %s\n", commands [0].c_str ());
			return -1;
		}
	}

	/* ... Discover requires the start and end ip */
	if ((commands.size () != 0) && commands [0] == "discover")
	{
		if( options._host_specified && (options._start_ip_specified || options._end_ip_specified ) )
		{
			fprintf(stderr, "\nError: Invalid options..\n");
			return -1;
		}
		else if(!options._host_specified)
		{
			if (!options._start_ip_specified)	
			{
				fprintf (stderr, "Error: Start IP address not specified\n");
				return -1;
			}

			if (!options._end_ip_specified)	
			{
				fprintf (stderr, "Error: End IP address not specified\n");
				return -1;
			}
		}
		else
		{
			//No Error - Success Case
		}
	}
	/* Bug : 995 Changes Start */
	/*Start IP and End Ip are persent but the discover operation is missing */
	if(options._start_ip_specified && options._end_ip_specified && !commands.size())
	{
		fprintf(stderr, "\nCommand syntax incomplete..\n");
		return -1;
	}
	/* Bug : 995 Changes End */

	if ((commands.size () !=0) && (commands [0] != "discover") && (options._is_multiple_ports_specified))
	{
		fprintf (stderr, "Error: Multiple Ports are specified, multiple ports are applicable only to discovery command\n");
		return -1;
	}

	return 0;
}


int 
doShell (CCmdOption gOptions)
{
	
	fprintf (stdout, "\nDASH Command Line Interface shell %s\n\n", DASH_CLI_VERSION_FULL);

	isShell = true;

	while (1)
	{
		vector <string> args;
		CCmdOption		options;

		/* copy the global options every time and over write it locally */
		options = gOptions;
		isCmdBufNotEmpty = false;
		fprintf (stdout, "dashcli>");

		/* get the commands from the input*/
		char	cmdBuf [512];
		cin.getline (cmdBuf, sizeof (cmdBuf));

		/* convert the arguments to vector of arguments */
		string	input (cmdBuf);
		while (input.size () != 0)
		{
			string		arg;

			arg = input.substr (0, input.find (" "));
			args.push_back (arg);
			isCmdBufNotEmpty = true;

			if ((size_t)-1 != input.find(" "))
			{
				input = input.substr (input.find(" "), input.size ());
				input = input.erase (0, input.find_first_not_of (" "));
			}
			else
			{
				break;
			}
		}

		if (isCmdBufNotEmpty == 0)
		{
			fprintf (stdout, "\n");
			return 0;
		}
		/* parse the commands */
		vector <string> commands;
		parseCmdOption (args, options, commands);

		if (commands.size () == 0) { continue; }

		int ret;
		/* exit shell interface */
		if ((commands [0] == "exit") || (commands [0] == "quit"))
		{ 
			return 0; 
		}
		else
		{
			ret = execCommand (options, commands);
		}

		fprintf (stdout, "\n");
	}

	return 0;
}


/*
 * main
 */
int
main (int argc, char* argv [])
{
	CCmdOption		options;
	vector<string>	commands;
	vector<string>	args;

	/* No arguments supplied - just print the usage */
	if (argc == 1) 
	{
		printUsage ();
		return 0;
	}

	/* convert the command line arguments to vector of arguments.*/
	for (int i = 1;	i < argc; i++)
	{
		string  arg (argv [i]);
		args.push_back (arg);
	}

	if (-1 == parseCmdOption (args, options, commands))
	{
		fprintf (stderr, "\nTry `dashcli help' for more information\n");
		return -1;
	}

	/* Insert the carriage return - so that all messages come one line after */
	fprintf (stdout, "\n");

	initDSDK();

	/* Execute the commands */
	int ret;
	if ((commands.size () != 0) && (commands [0] == "shell"))
	{ 
		ret = doShell (options); 
	}
	else
	{
		ret = execCommand (options, commands);
		#if WIN32
		{}
		#else 
		{ fprintf (stdout, "\n"); }
		#endif
	}

	fprintf (stdout, "\n");

	finiDSDK();

	return ret;
}


