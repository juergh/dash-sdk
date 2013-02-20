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
 * raw.cpp
 */
#include "raw.h"
#include <dsdk/subject.h>
#include <dsdk/cimmap.h>
#include "help.h"
#include <dsdk/client.h>

using namespace dsdk;
namespace dashcli
{
#define MAX_ARG_NAME_VALUE_SIZE			1024

/*
 * structure to hold key value/name pair 
 */
typedef struct
{
    string	name;
    string	value;

} CIMKey_T;

/*
 * structure to hold property value/name pair 
 */
typedef struct
{
    string	name;
    string	value;

} CIMProp_T;

/*
 * structure to hold argument value/name pair 
 */
typedef struct
{
    string	name;
    string	value;
	int     type;

} CIMArg_T;

/*
 * getInstanceClassNameAndKeys.
 */
static int
getInstanceClassNameAndKeys (string uri, string* className, vector <CIMKey_T>* keys)
{
    string classNameKeys;
    string keyString;

    classNameKeys = uri;

    /* get the class Name */
    *className	  = classNameKeys.substr (0, classNameKeys.find ('?'));

    /* the keys - sub string after '.' */
    keyString	  = classNameKeys.substr (classNameKeys.find ('?') + 1, 
														classNameKeys.size());

    while (0 != keyString.size ())
    {
        CIMKey_T	key;
        string  temp;

        /* the key name and value */
        temp        = keyString.substr ( keyString.find ('=') + 1, 
                                                         keyString.size ());
        key.name    = keyString.substr (0, keyString.find ('='));
        key.value   = temp.substr (0, ((size_t)-1 != temp.find (',')) ? 
                                               temp.find (',') : temp.size ());

        /* add to the table */
        keys->push_back (key);

        /* move to next key pair (name,value) */
        if ((size_t)-1 == keyString.find (','))
        {
            break;
        }
        keyString   = keyString.substr (keyString.find (',') + 1, 
                                                            keyString.size ());
    }

    return 0;
}

/*
 * getInstancePropNameAndValues
 */
static int
getInstancePropNameAndValues (string propertyString, vector <CIMProp_T>* props)
{

	while (0 != propertyString.size ())
    {
        CIMProp_T	prop;
        string  temp;

        /* the property name and value */
        temp        = propertyString.substr ( propertyString.find ('=') + 1, 
                                                         propertyString.size ());
        prop.name    = propertyString.substr (0, propertyString.find ('='));
        prop.value   = temp.substr (0, ((size_t)-1 != temp.find (',')) ? 
                                               temp.find (',') : temp.size ());

        /* add to the table */
        props->push_back (prop);

        /* move to next property pair (name,value) */
        if ((size_t)-1 == propertyString.find (','))
        {
            break;
        }
        propertyString   = propertyString.substr (propertyString.find (',') + 1, 
                                                            propertyString.size ());
    }

    return 0;
}

/*
 * getInstancePropNameAndValues
 */
static int
getArgumentNameAndValues (string argumentString, vector <CIMArg_T>* args)
{

	/* argument can be specified in command line or in a text file, if specified it should contain '=', if not 
	   assume it as a text file */
	if ((size_t)-1 != argumentString.find ('='))
	{
		while (0 != argumentString.size ())
		{
			CIMArg_T	arg;
			string		temp;

			/* the argument name and value */
			temp        = argumentString.substr ( argumentString.find ('=') + 1, 
															 argumentString.size ());
			arg.name    = argumentString.substr (0, argumentString.find ('='));
			arg.value   = temp.substr (0, ((size_t)-1 != temp.find (',')) ? 
												   temp.find (',') : temp.size ());

			/* add to the table */
			args->push_back (arg);

			/* move to next argument pair (name,value) */
			if ((size_t)-1 == argumentString.find (','))
			{
				break;
			}
			argumentString   = argumentString.substr (argumentString.find (',') + 1, 
																argumentString.size ());
		}
	}
	else
	{
		/* assume it as text file and parse the file */

		FILE * pFile;
		pFile = fopen (argumentString.c_str (),"r");

		if (pFile != NULL)
		{
			
			while (! feof(pFile)) 
			{
				char sstr [MAX_ARG_NAME_VALUE_SIZE];
				string str;
				vector <string> classname;
				vector <string> keyprops;

				/* read a line from the argument file */
				if (fgets (sstr , MAX_ARG_NAME_VALUE_SIZE, pFile))
				{
					str = sstr;
					CIMArg_T	arg;
					string		temp;

					/* the argument name and value */
					temp        = str.substr ( str.find ('=') + 1, str.size ());
					arg.name    = str.substr (0, str.find ('='));
					if ((size_t)-1 != temp.find ("SelectorSet")) 
					{ 
						arg.value = "<wsa:EndpointReference xmlns:wsa=\"http://schemas.xmlsoap.org/ws/2004/08/addressing\" xmlns:wsman=\"http://schemas.dmtf.org/wbem/wsman/1/wsman.xsd\">";
						arg.value += temp;
						arg.value += "</wsa:EndpointReference>";
					}
					else								
					{ 
						arg.value = temp;
					}
					args->push_back (arg);
				}
			}
					
			fclose(pFile);
		}
		else
		{
			return -1;
		}
	}

    return 0;
}

/*
 * showObjectPath
 */
void
showObjectPath (CCIMObjectPath& op)
{

	fprintf (stdout, "\t%-25s = %s\n", "ResourceURI", op.getClassName ().c_str ());

	fprintf (stdout, "\tKeys :\n");
    for (unsigned int i = 0; i < op.getKeyCount (); i++)
    {
		string		name;
		CCIMData	data	= op.getKeyAt (i, &name);
		CCIMValue	value	= data.getValue ();
		if (value.getLowLevelType () == CMPI_ref)
		{
			CCIMObjectPath op = CCIMObjectPath::toCCIMObjectPath (value.getLowLevelValue ()->ref,
																  false);
			fprintf (stdout, "\n\t%s :\n", name.c_str ());
			showObjectPath (op);
		}
		else if (value.getLowLevelType () == CMPI_string)
		{
			string		str		= to<stringDSDKAdapter> (value);
			fprintf (stdout, "\t%-25s = %s\n", name.c_str (), str.c_str ());
		}
		else
		{
			fprintf (stdout, "\t%-25s = %s", name.c_str (), "N/A");
		}

	}

	return;
}


/*
 * showInstance
 */
void
showInstance (CCIMInstance& inst)
{
	fprintf (stdout, "\tProperties :\n");
    for (unsigned int i = 0; i < inst.getPropertyCount (); i++)
    {
        string		name;
        CCIMData	data	= inst.getPropertyAt (i, &name);

		CCIMValue	   value = data.getValue ();
		if (value.getLowLevelType () == CMPI_ref)
		{
			CCIMObjectPath op = CCIMObjectPath::toCCIMObjectPath (value.getLowLevelValue ()->ref,
																  false);
			fprintf (stdout, "\n\t%s :\n", name.c_str ());
			showObjectPath (op);
		}
		else if (value.getLowLevelType () == CMPI_ARRAY)
		{
			/* always to an array  */
			vector<string> str   = toArray<stringDSDKAdapter> (value);
			fprintf (stdout, "\t%-25s = ", name.c_str ());
			for (size_t j = 0; j < str.size (); j++)
			{
				fprintf (stdout, "%s ", str [j].c_str ());
			}
		}
		else if (value.getLowLevelType () == CMPI_string)
		{
			string		str		= to<stringDSDKAdapter> (value);
			fprintf (stdout, "\t%-25s = %s", name.c_str (), str.c_str ());
		}
		else
		{
			fprintf (stdout, "\t%-25s = %s", name.c_str (), "N/A");
		}
		fprintf (stdout, "\n");
    }

	return;
}

/*
 * enumerateInstanceNames
 */
int
enumerateInstanceNames (IClient* client, vector<string> commands)
{
    string ns;

    if (commands.size () <= 2) 
    {
        displayRawHelp (commands, 1);
        return -1;
    }

    /* if name space not specified use default name space */
    if (commands.size () <= 3) { ns = ""; }
    else                       { ns = commands [3]; }

    /* construct the object path with name space and class name */
    CCIMObjectPath op (ns, commands [2]);

    CCIMObjectPath::iterator iter = client->enumInstanceNames (op);

	int i = 0;
    for (; iter != iter.end (); ++iter)
    {
        CCIMObjectPath op = *iter;
		fprintf (stdout, "Instance %d :\n", i);
		showObjectPath (op);
		fprintf (stdout, "\n");
		i++;
    }

    return 0;
}

/*
 * enumerateInstances
 */
int
enumerateInstances (IClient* client, vector<string> commands)
{
    string ns;

    if (commands.size () <= 2) 
    {
        displayRawHelp (commands, 1);
        return -1;
    }


    /* if name space not specified use default name space */
    if (commands.size () <= 3) { ns = ""; }
    else                       { ns = commands [3]; }

    /* construct the object path with name space and class name */
    CCIMObjectPath op (ns, commands [2]);

    vector<string> props;
    CCIMInstance::iterator iter = client->enumInstances (op, 0, props);

	int i = 0;
    for (; iter != iter.end (); ++iter)
    {
        CCIMInstance inst = *iter;
		fprintf (stdout, "Instance %d :\n", i);
        showInstance (inst);
		fprintf (stdout, "\n");
		i++;
    }

    return 0;
}

/*
 * getInstance
 */
int
getInstance (IClient* client, vector<string> commands)
{
    string						ns;
	string						className;

    if (commands.size () <= 2) 
    {
        displayRawHelp (commands, 1);
        return -1;
    }

    /* if name space not specified use default name space */
    if (commands.size () <= 3) { ns = ""; }
    else                       { ns = commands [3]; }

    /* get class name and keys */
    vector<CIMKey_T>   keys;
    getInstanceClassNameAndKeys (commands [2], &className, &keys);

    /* construct the object path with name space and class name */
    CCIMObjectPath op (ns, className);

    /* set the keys */
    vector<CIMKey_T>::iterator iter;
    for (iter = keys.begin (); iter != keys.end (); iter++)
    {
        CIMKey_T	key;
        
        key		= *iter;
        op.addKey (key.name, toCCIMValue<stringDSDKAdapter> (key.value));
    }

    vector<string> props;
    CCIMInstance inst = client->getInstance (op, 0, props);

    fprintf (stdout, "properties :\n");
    showInstance (inst);
	fprintf (stdout, "\n");

    return 0;
}

/*
 * setInstance
 */
int
setInstance (IClient* client, vector<string> commands)
{
    string						ns;
	string						className;
	
    if (commands.size () <= 2) 
    {
        displayRawHelp (commands, 1);
        return -1;
    }

    /* if name space not specified use default name space */
    if (commands.size () <= 4) { ns = ""; }
    else                       { ns = commands [4]; }

    /* get class name and keys */
    vector<CIMKey_T>   keys;
    getInstanceClassNameAndKeys (commands [2], &className, &keys);

    /* construct the object path with name space and class name */
    CCIMObjectPath op (ns, className);

    /* set the keys */
    vector<CIMKey_T>::iterator iter;
    for (iter = keys.begin (); iter != keys.end (); iter++)
    {
        CIMKey_T	key;
        
        key		= *iter;
        op.addKey (key.name, toCCIMValue<stringDSDKAdapter> (key.value));
    }

	/* get class name and keys */
    vector<CIMProp_T>   props;
	vector<string> empty;
    getInstancePropNameAndValues (commands [3], &props);

	/* construct the instance */
    vector<string> empty_props;
    CCIMInstance instance = client->getInstance (op, 0, empty_props);

    /* set the keys */
    vector<CIMProp_T>::iterator iter1;
    for (iter1 = props.begin (); iter1 != props.end (); iter1++)
    {
        CIMProp_T	prop;
        
        prop		= *iter1;
        instance.setProperty (prop.name, toCCIMValue<stringDSDKAdapter> (prop.value));
    }

	client->setInstance (op, instance,0,empty);
	return 0;
}

/*
 * setInstance
 */
int
invokeMethod (IClient* client, vector<string> commands)
{
    string						ns;
	string						className;
	
    if (commands.size () <= 2) 
    {
        displayRawHelp (commands, 1);
        return -1;
    }

    /* if name space not specified use default name space */
    if (commands.size () <= 5) { ns = ""; }
    else                       { ns = commands [5]; }

    /* get class name and keys */
    vector<CIMKey_T>   keys;
    getInstanceClassNameAndKeys (commands [2], &className, &keys);

    /* construct the object path with name space and class name */
    CCIMObjectPath op (ns, className);

    /* set the keys */
    vector<CIMKey_T>::iterator iter;
    for (iter = keys.begin (); iter != keys.end (); iter++)
    {
        CIMKey_T	key;
        
        key		= *iter;
        op.addKey (key.name, toCCIMValue<stringDSDKAdapter> (key.value));
    }

	/* get class name and keys */
    vector<CIMArg_T>   args;
	vector<string> empty;
    if (-1 == getArgumentNameAndValues (commands [4], &args))
	{
		fprintf (stderr, "Could not parse the argument %s\n", commands [4].c_str ());
		return -1;
	}

	CCIMArgument argin ;
	CCIMArgument argout;

    /* set the keys */
    vector<CIMArg_T>::iterator iter1;
    for (iter1 = args.begin (); iter1 != args.end (); iter1++)
    {
        CIMArg_T	arg;
        
        arg		= *iter1;
		argin.addArg (arg.name, toCCIMValue<stringDSDKAdapter> (arg.value));
    }

	CCIMData d_out = client->invokeMethod (op, commands [3], argin, &argout);

	CCIMValue d_out_cv = d_out.getValue ();
	
	uint32 status = to <uint32DSDKAdapter> (d_out_cv);

	fprintf (stdout, "Invoke method return with status : %d\n", status);

	if (argout.getArgCount () > 0)
	{
		fprintf (stdout, "Output Argument : \n");
		for (size_t i = 0; i < argout.getArgCount (); i++)
		{
			string argname;
			CCIMData  d_arg = argout.getArgAt (i, &argname);
			CCIMValue v_arg = d_arg.getValue ();
			string argvalue = to<stringDSDKAdapter> (v_arg); 

			fprintf (stdout, "\t%-25s = %s\n", argname.c_str (), argvalue.c_str ());
		}
	}

	return 0;
}


/*
 * execRaw
 */
int 
doRaw (CCmdOption options, vector<string> commands)
{
	int ret = 0;
    try
    {
        CSubject subject (options._user,
                          options._password.c_str (),
                          options._authtype);
        CCIMMAP cimmap (options._host, options._port);
        IClient* client = cimmap.connect (subject);

		/* Do raw processing here */
        if (commands.size () == 1)  { displayRawHelp (commands, 1); return -1; }
        if ((commands [1] == "enumerateinstancenames") ||
			(commands [1] == "ein"))
		{ 
			try {
				ret = enumerateInstanceNames (client, commands); 
			}
			catch (exception& e)
			{
				fprintf (stderr, "Error: %s\n", e.what ());
				ret = -1;
			}
		}
		else if ((commands [1] == "enumerateinstances")     ||
			(commands [1] == "ei"))
		{ 
			try {
				ret = enumerateInstances (client, commands); 
			}
			catch (exception& e)
			{
				fprintf (stderr, "Error: %s\n", e.what ());
				ret = -1;
			}
		}
		else if ((commands [1] == "getinstance") ||
			(commands [1] == "gi"))
		{ 
			try {
				ret = getInstance (client, commands); 
			}
			catch (exception& e)
			{
				fprintf (stderr, "Error: %s\n", e.what ());
				ret = -1;
			}
		}
		else if ((commands [1] == "setinstance") ||
			(commands [1] == "si"))
		{ 
			try {
				ret = setInstance (client, commands); 
			}
			catch (exception& e)
			{
				fprintf (stderr, "Error: %s\n", e.what ());
				ret = -1;
			}
		}
		else if ((commands [1] == "invoke") ||
			(commands [1] == "im"))
		{ 
			try {
				ret = invokeMethod (client, commands); 
			}
			catch (exception& e)
			{
				fprintf (stderr, "Error: %s\n", e.what ());
				ret = -1;
			}
		}
		else
		{
			fprintf (stderr, 
					 "Error: Invalid command '%s'\n", 
					 commands [0].c_str ());
			ret = -1;
		}
		
		delete client;
    }
    catch (exception& e)
    {
        fprintf (stderr, "Error: %s\n", e.what ());
        ret = -1;
    }

    return ret;
}

};	/* namespace dashcli */





