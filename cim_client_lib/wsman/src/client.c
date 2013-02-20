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
 * @file client.c
 * @brief Low level CMPI API Interface implemented using WSMAN client. 
 * This file implements the API like.enumInstances, getInstance, deleteInstance etc.
 */
#include <stdlib.h>
#include <string.h>
#include <wsman-client.h>
#include <wsman-client-api.h>
#include <wsman-client-transport.h>
#include <wsman-soap.h>
#include <wsman-xml.h>
#include <wsman-epr.h>
#include <eventsink.h>
#include "wsman-xml-binding.h"
#include "cmci.h"
#include "native.h"

enum boolean {false,true};
int		g_lapi_verbose_level = 0;
char*	g_lapi_verbose_file  = NULL;

/* -------------- local macros ------------------ */

#define WSMAN_DUMP_NODE_TREE(doc)											\
{																			\
	if ((g_dump_wsman_data) && (g_wsman_dumpfile != NULL))					\
	{																		\
		ws_xml_dump_node_tree (g_wsman_dumpfile, ws_xml_get_doc_root(doc));	\
		fprintf (g_wsman_dumpfile, "\n\n");									\
	}																		\
}

#define HTTP_SUCCESS							200
#define WSMAN_SUCCESS(cl, doc)					((HTTP_SUCCESS == wsmc_get_response_code (cl)) && (!isWsmanError (doc)))
#define MAX_CLASS_NAME_LENGTH					100
#define MAX_OBJECT_URI_LENGTH					512
#define MAX_ELEMENT_SIZE						250

/*
 * Client connection information
 */
struct _ClientEnc {
	CMCIClient			enc;
	CMCICredentialData	certData;
	CMCIConnection*		connection;
	WsManClient	*		wsmanClient;
	char*				implementation_ns;
	char*				interop_ns;
};

/*
 * Key Name value pair
 */
typedef struct 
{
	CMPIString* name;
	CMPIData	value;
	char*		charValue;

} KeyNameValue_T;

/*
 * Property Name value pair
 */
typedef struct 
{
	CMPIString* name;
	CMPIData	value;
	char*		charValue;

} PropertyNameValue_T;

/*
 * Args Name value pair
 */
typedef struct 
{
	CMPIString* name;
	CMPIData	value;
	char*		charValue;

} ArgNameValue_T;

/*
 * WSMAN Error code
 */
typedef struct
{
	char*	errString;
	int		errCode;

} WSMANError_T;

/*
 * HTTP Error type
 */
typedef struct
{
	int		errCode;
	char*	errString;

} HTTPError_T;

/*---------------- SET CIM NAMESPACE ------------------ */
static int setCIMNameSpace (CMPIObjectPath* cop, client_opt_t* options)
{
	CMPIStatus      rc;
	CMGetKey (cop, "__cimnamespace", &rc);
	if (rc.rc == CMPI_RC_ERR_NO_SUCH_PROPERTY)
	{
		CMPIString*		ns = CMGetNameSpace (cop, NULL);
		options->cim_ns = (CMGetCharsPtr (ns, NULL) != NULL) ? strdup (CMGetCharsPtr (ns, NULL)) : NULL;
		CMRelease (ns);
	}
	return 0;
};

/*----------------  WSMAN Error codes ------------------ */
static WSMANError_T wsmanErrorTbl [] = 
{
	/* 
	WSMAN error code does not return error code(value) but return error string and
	wsman error is transulated to CMPI error code and transulated to best match and if no 
	best match can be found CMPI_RC_ERR_FAILED is returned 
	*/
	{"wsman:InvalidSelectors",		CMPI_RC_ERR_INVALID_PARAMETER},
	{"wsa:DestinationUnreachable",	CMPI_RC_ERR_NOT_FOUND},
	{"wsman:InternalError",			CMPI_RC_ERR_FAILED},
	{"wsman:AlreadyExists",			CMPI_RC_ERR_ALREADY_EXISTS},
	{"wxf:InvalidRepresentation",	CMPI_RC_ERR_INVALID_NAMESPACE},
	{"wsa:ActionNotSupported",		CMPI_RC_ERR_NOT_SUPPORTED},
	{"wsmb:DevliveryToUnusable",	CMPI_RC_ERR_FAILED}, //this is splling mistake with openwsman and added here to match it.
	{"wsmb:DeliveryToUnusable",		CMPI_RC_ERR_FAILED},
	{"wsen:FilterDialectRequestedUnavailable", CMPI_RC_ERR_FAILED},
	{"wsman:UnsupportedFeature",	CMPI_RC_ERR_UNSUPPORTED_FEATURE},
	{"wsen:", CMPI_RC_ERR_FAILED},
};

/* ----------------- HTTP Error codes ------------------ */
static HTTPError_T httpErrorTbl [] = 
{
	{400, "HTTP Error - Bad request\n"},
	{401, "HTTP Error - Unauthorized\n"},
	{404, "HTTP Error - File or Directory not found\n"},
	{407, "HTTP Error - Proxy Authentication Required\n"},
	{500, "HTTP Error - Internal Server Error\n"},
};


#define		MAX_LAST_ERROR_STR_LEN		512
int
getLastErrorStr (WS_LASTERR_Code error, char* str, int strLen)
{
#ifdef WIN32
	return  FormatMessageA (
        FORMAT_MESSAGE_FROM_HMODULE |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        GetModuleHandleA ("winhttp.dll") ,
        error,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPSTR)str,
        strLen, NULL );
#else
	char* errStr;
	memset (str, 0, MAX_LAST_ERROR_STR_LEN);
	errStr = wsman_transport_get_last_error_string (error);
	snprintf(str, MAX_LAST_ERROR_STR_LEN, "%s", errStr);
	return 0;
#endif
}

#ifdef WIN32
# define snprintf _snprintf
#endif

/*
 * constructWsmanClassUri
 */
static int
constructWsmanClassUri (CMPIObjectPath* cop, char* uri, size_t len, CMPIStatus* rc)
{
	size_t		classNameLen;
	CMPIString*	className;
	CMPIString*	classNamespace;

	const char*	cimNamespace;
	
	/* check for boundry condition */
	className    = CMGetClassName (cop, NULL);
	classNamespace = cop->ft->getNameSpace(cop, rc);

	cimNamespace = XML_NS_CIM_CLASS;
	if (CMGetCharPtr (className) != NULL && !memcmp(CMGetCharPtr (className), "DRI_", 4) ) {
		cimNamespace = XML_NS_DRI_CLASS;
	}
	if (NULL != CMGetCharPtr (className))
	{
		classNameLen = strlen ( CMGetCharPtr (className));
		if ((strlen (cimNamespace) + 1 + classNameLen + 1) > len)
		{
			CMSetStatusWithChars (rc, CMPI_RC_ERR_FAILED, "Error: Classname exceeded max length");
			CMRelease (className);
			CMRelease (classNamespace);
			return -1;
		}

		snprintf(uri, len, "%s/%s", cimNamespace, CMGetCharPtr (className));

		CMRelease (className);
		CMRelease (classNamespace);
	}
	else
	{
		snprintf(uri, len, "%s/*", cimNamespace);
	}

	return 0;
}

/*
 * getObjectUri
 */
static int
getObjectUri (CMPIObjectPath* cop, char* uri)
{
	CMPIString* className = CMGetClassName (cop, NULL);

	memset (uri, 0, MAX_OBJECT_URI_LENGTH);
	snprintf( uri, MAX_OBJECT_URI_LENGTH, "%s", CMGetCharPtr (className));
	CMRelease (className);

	return 0;
}

/*
 * removeTailoringSpaces
 */
int
removeTailoringSpaces (char* str)
{
	int i = 0;

	/* remove the tailoring */
	while (str [i] != 0)
	{
		if (str [i] == 0x20) { str [i] = 0; break; }
		i++;
	}

	return 0;
}

/*
 * createRefNode 
 */
int
createRefNode (CMPIObjectPath* cop, char** buff)
{
	int				keyCount;
	int				i;
	WsXmlNodeH		node;
	WsXmlNodeH		addressNode;
	WsXmlNodeH		refNode;
	WsXmlNodeH		selectorSetNode;
	WsXmlDocH		doc;
	CMPIString*		objectUri;
	CMPIString*		eprvalue; 
	int				size;
	KeyNameValue_T*	keys;
	CMPIStatus		rc;

	keyCount		= CMGetKeyCount (cop, &rc);
	objectUri		= CMGetClassName (cop, NULL);
	doc				= ws_xml_create_doc (XML_NS_ADDRESSING, WSA_EPR);
	node			= ws_xml_get_doc_root (doc);

	eprvalue = CMGetEprValue(cop, &rc);
	if (eprvalue != NULL)
	{
		if (CMGetCharPtr (eprvalue) != NULL)
		{
			*buff = strdup (CMGetCharPtr (eprvalue));
		}
		else 
		{
			*buff = NULL;
		}
	}
	if ((eprvalue == NULL) || (*buff == NULL))
	{
		addressNode		= ws_xml_add_child (node, XML_NS_ADDRESSING, WSA_ADDRESS, WSA_TO_ANONYMOUS);
		refNode			= ws_xml_add_child (node, XML_NS_ADDRESSING, WSA_REFERENCE_PARAMETERS, NULL);
		ws_xml_add_child (refNode, XML_NS_WS_MAN, WSM_RESOURCE_URI, CMGetCharPtr (objectUri));
		selectorSetNode = ws_xml_add_child (refNode, XML_NS_WS_MAN, WSM_SELECTOR_SET, NULL);

		/* get the keys from object path and set it to wsman option */
		keyCount = CMGetKeyCount (cop, &rc);
		keys	 = malloc (sizeof (KeyNameValue_T) * keyCount);
		if (keys == NULL) { return -1; }

		for (i = 0; i < keyCount; i++)
		{
			WsXmlNodeH	selectorNode;

			keys [i].value		= CMGetKeyAt (cop, i, &keys [i].name, NULL);
			keys [i].charValue	= value2Chars (keys [i].value.type, &keys [i].value.value);

			selectorNode = ws_xml_add_child(selectorSetNode, XML_NS_WS_MAN, WSM_SELECTOR, keys [i].charValue);
			ws_xml_add_node_attr(selectorNode, NULL, WSM_NAME, CMGetCharPtr (keys [i].name));
		}

		ws_xml_dump_memory_node_tree (node, buff, &size);

		for (i = 0; i < keyCount; i++)
		{
			CMRelease (keys [i].name);
			if (keys [i].charValue) { free (keys [i].charValue); }
		}
		if (keys) { free (keys);} 

	}
	ws_xml_destroy_doc(doc);
	CMRelease (objectUri);
	if (eprvalue != NULL) { CMRelease (eprvalue); }

	return 0;
}

/*
 * createInstNode 
 */
int
createInstNode (CMPIInstance* inst, char** buff)
{
	int					 propertyCount;
	int					 i;
	WsXmlNodeH			 node;
	WsXmlDocH			 doc;
	int					 size;
	PropertyNameValue_T* properties;
	CMPIStatus			 rc;
	CMPIObjectPath*		 op = NULL;
	CMPIString*			 objectUri = NULL;

	op				= inst->ft->getObjectPath (inst, NULL);
	if (op != NULL) { objectUri		= CMGetClassName (op, NULL); }
	doc				= ws_xml_create_doc (CMGetCharPtr (objectUri), "Instance");
	node			= ws_xml_get_doc_root (doc);

	/* get the keys from object path and set it to wsman option */
	propertyCount = CMGetPropertyCount (inst, &rc);
	properties	  = malloc (sizeof (PropertyNameValue_T) * propertyCount);
	if (properties == NULL) { return -1; }

	for (i = 0; i < propertyCount; i++)
	{
		WsXmlNodeH	propertyNode;

		properties [i].value		= CMGetPropertyAt (inst, i, &properties [i].name, NULL);
		properties [i].charValue	= value2Chars (properties [i].value.type, &properties [i].value.value);

		propertyNode = ws_xml_add_child(node, CMGetCharPtr (objectUri), CMGetCharPtr (properties [i].name), properties [i].charValue);
	}

	ws_xml_dump_memory_node_tree (node, buff, &size);

	for (i = 0; i < propertyCount; i++)
	{
		CMRelease (properties [i].name);
		if (properties [i].charValue) { free (properties [i].charValue); }
	}
	if (properties) { free (properties);} 

	ws_xml_destroy_doc(doc);
	CMRelease (objectUri);

	return 0;
}


/*
 * addArgsToOption 
 */ 
static int 
addArgsToOption (CMPIArgs* args, client_opt_t* options, ArgNameValue_T* argList, 
														CMPIStatus* rc)
{
	int argCount;
	int i;

	if (args == NULL) { return 0; }

	/* add the arguments to the wsman properties */
	argCount = args->ft->getArgCount (args, rc);
	for (i = 0; i < argCount; i++)
	{
		argList [i].value		= args->ft->getArgAt (args, i, &argList [i].name, rc);
		if (argList [i].value.type == CMPI_ref)
		{
			if (0 == createRefNode (argList [i].value.value.ref, (char**)&argList [i].charValue))
			{
				wsmc_add_property (options, CMGetCharPtr (argList [i].name), argList [i].charValue);
			}
		}
		else if (argList [i].value.type == CMPI_instance)
		{
			if (0 == createInstNode (argList [i].value.value.inst, (char**)&argList [i].charValue))
			{
				wsmc_add_property (options, CMGetCharPtr (argList [i].name), argList [i].charValue);
			}
		}
		else if (argList [i].value.type == CMPI_ARRAY)
		{
			CMPIArray*	array;
			int			numElements;
			int			j;

			array					= argList [i].value.value.array;
			numElements				= CMGetArrayCount (array, rc);
			argList [i].charValue	= malloc (numElements * sizeof (char*));
			if (NULL == argList [i].charValue) { return -1; }
			memset (argList [i].charValue, 0, numElements * sizeof (char*));

			for (j = 0; j < numElements; j++)
			{
				char* charValue;
				CMPIData value	= CMGetArrayElementAt (array, j, rc);
				if (CMPI_ref == CMGetArrayType(array, rc))
				{
					if (0 == createRefNode (value.value.ref, &charValue))
					{
						wsmc_add_property (options, CMGetCharPtr (argList [i].name), charValue);
						((void**)(argList [i].charValue)) [j] = charValue;
					}
				}
				else
				{
					charValue	= value2Chars (value.type, &value.value);
					wsmc_add_property (options, CMGetCharPtr (argList [i].name), charValue);
					((void**)(argList [i].charValue)) [j] = charValue;
				}
			}
		}
		else
		{
			argList [i].charValue	= value2Chars (argList [i].value.type, &argList [i].value.value);
			wsmc_add_property (options, CMGetCharPtr (argList [i].name), argList [i].charValue);
		}
	}

	return 0;
}

/*
 * releaseKeys
 */
static int
releaseArgs (ArgNameValue_T* args, int argCount)
{
	int i;

	for (i = 0; i < argCount; i++)
	{
		CMRelease (args [i].name);
		if (args [i].value.type == CMPI_ARRAY)
		{
			int j;
			int numElements = CMGetArrayCount (args [i].value.value.array, NULL);

			for (j = 0; j < numElements; j++)
			{
				if (((void**)(args [i].charValue)) [j])
					free (((void**)(args [i].charValue)) [j]);
			}
			if (args [i].charValue) { free (args [i].charValue); }
		}
		else
		{
			if (args [i].charValue) { free (args [i].charValue); }
		}
	}

	if (args) { free (args); }
	return 0;
}


/*
 * addKeysToOption 
 */ 
static int 
addKeysToOption (CMPIObjectPath* cop, client_opt_t* options, KeyNameValue_T* keys, 
															 CMPIStatus *rc)
{
	int keyCount;
	int	i;

	/* add the keys from objectpath to wsman selectors */
	keyCount = CMGetKeyCount (cop, rc);
	for (i = 0; i < keyCount; i++)
	{
		keys [i].value		= CMGetKeyAt (cop, i, &keys [i].name, NULL);
		if (keys [i].value.type == CMPI_ref)
		{
			if (0 == createRefNode (keys [i].value.value.ref, (char**)&keys [i].charValue))
			{
				wsmc_add_selector (options, CMGetCharPtr (keys [i].name), keys [i].charValue);
			}
		}
		else
		{
			keys [i].charValue	= value2Chars (keys [i].value.type, &keys [i].value.value);
			wsmc_add_selector (options, CMGetCharPtr (keys [i].name), keys [i].charValue);
		}
	}

	return 0;
}

/*
 * releaseKeys
 */
static int
releaseKeys (KeyNameValue_T* keys, int keyCount)
{
	int i;

	for (i = 0; i < keyCount; i++)
	{
		CMRelease (keys [i].name);
		if (keys [i].charValue)  { free (keys [i].charValue);}
	}

	if (keys) { free (keys);} 
	return 0;
}

/*
 * addPropertiesToOption 
 */ 
static int 
addPropertiesToOption (CMPIInstance* inst, client_opt_t* options, 
					   PropertyNameValue_T* properties, CMPIStatus* rc)
{
	int propertyCount;
	int i;

	/* add properties from instance to wsman property */
	propertyCount = CMGetPropertyCount (inst, rc);
	for (i = 0; i < propertyCount; i++)
	{
		properties [i].value		= CMGetPropertyAt (inst, i, &properties [i].name, NULL);
		properties [i].charValue	= value2Chars (properties [i].value.type, 
										&properties [i].value.value);
		wsmc_add_property (options, CMGetCharPtr (properties [i].name), 
												   properties [i].charValue);
	}

	return 0;
}

/*
 * releaseProperties
 */
static int
releaseProperties (PropertyNameValue_T* properties, int propertyCount)
{
	int i;

	for (i = 0; i < propertyCount; i++)
	{
		CMRelease (properties [i].name);
		if (properties [i].charValue) { free (properties [i].charValue); }
	}

	if (properties) free (properties);
	return 0;
}

/*
 * addPropertiesToNode
 */
static int 
addPropertiesToNode (CMPIObjectPath* cop, CMPIInstance* inst, WsXmlNodeH* node, 
								PropertyNameValue_T* properties, CMPIStatus* rc)
{
	int  propertyCount;
	int  i;
	char objectUri [MAX_OBJECT_URI_LENGTH + 1];

	getObjectUri (cop, objectUri);

	/* add properties from wsman to objectpath */
	propertyCount = CMGetPropertyCount (inst, rc);
	for (i = 0; i < propertyCount; i++)
	{
		properties [i].value		= CMGetPropertyAt (inst, i, &properties [i].name, NULL);
		properties [i].charValue	= value2Chars (properties [i].value.type, 
										&properties [i].value.value);
		ws_xml_add_child (*node, objectUri, CMGetCharPtr (properties [i].name), 
												  properties [i].charValue);
	}

	return 0;
}

/*
 * addKeysToObjectPath
 */
static int 
addKeysToObjectPath (CMPIObjectPath** cop, WsXmlNodeH node)
{
	int			childCount;
	int			i;
	WsXmlNodeH	uriNode;
	WsXmlNodeH	selectorSetNode;
	WsXmlNodeH	endPointRefNode;
	WsXmlNodeH	eprNode;
	char*		endPointRef = NULL;
	 WsXmlDocH eprDoc = NULL;

	int			size;
	char*		resUri;
	CMPIStatus  rc;

	endPointRefNode			= ws_xml_find_in_tree (node, XML_NS_ADDRESSING, "EndpointReference", 1);
	if (endPointRefNode != NULL) 
	{ 
		eprDoc = ws_xml_create_doc (XML_NS_ADDRESSING, "EndpointReference");
		eprNode = ws_xml_get_doc_root (eprDoc);
	
		ws_xml_duplicate_children (eprNode, endPointRefNode);
		ws_xml_dump_memory_node_tree (eprNode, &endPointRef, &size); 
	} 

	
	/* check if the node contains any object path/enpoing reference */
	if ((NULL == node) || 
		(NULL == ws_xml_find_in_tree (node, XML_NS_ADDRESSING, "ReferenceParameters", 1)))
	{
		return -1;
	}

	uriNode			= ws_xml_find_in_tree (node, XML_NS_WS_MAN, "ResourceURI", 1);
	selectorSetNode = ws_xml_find_in_tree (node, XML_NS_WS_MAN, "SelectorSet", 1);
	if ((uriNode == NULL) || (selectorSetNode == NULL))
	{
		return -1;
	}

	resUri	  = ws_xml_get_node_text (uriNode);
	removeTailoringSpaces (resUri); //some vendors return uri with spaces so remove the tailoring spaces

	*cop	  = newCMPIObjectPath (NULL, resUri, &rc);
	if (endPointRef != NULL)
	{
		(*cop)->ft->addEpr(*cop,endPointRef);
	}

	/* add keys from wsman to objectpaths */
	childCount	= ws_xml_get_child_count (selectorSetNode);
	for (i = 0; i < childCount; i++)
	{
		WsXmlNodeH	selectorNode;
		WsXmlAttrH	attr;
		CMPIValue	value;
		char*		nodeName;

		selectorNode = ws_xml_get_child (selectorSetNode, i, NULL, NULL);
		attr		 = ws_xml_get_node_attr (selectorNode, 0);
		nodeName	 = ws_xml_get_attr_value (attr);

		/* if the selector has a child and if the child has reference parametes then 
		  then its nested object path	 */
		if ((0 != ws_xml_get_child_count (selectorNode)) &&
			(ws_xml_find_in_tree (selectorNode, XML_NS_ADDRESSING, "EndpointReference", 1))
		   )
		{
			if (0 == addKeysToObjectPath (&value.ref, selectorNode))
			{
				(*cop)->ft->addKey(*cop, nodeName, &value, CMPI_ref);
				native_release_CMPIValue (CMPI_ref, &value);
			}
		}
		else
		{
			value		= str2CMPIValue (CMPI_string, ws_xml_get_node_text (selectorNode), NULL);
			(*cop)->ft->addKey(*cop, nodeName, &value, CMPI_string);
			native_release_CMPIValue (CMPI_string, &value);
		}
	}
	
	ws_xml_destroy_doc(eprDoc);
	xml_parser_free_memory(endPointRef);
	
	
	return 0;
}

/*
 * addPropertiesToInstance
 */
static int 
addPropertiesToInstance (char** properties, CMPIInstance** cci, WsXmlNodeH node, enum boolean getObjPath)
{
	char* propertyNamePtr = NULL;
	int			childCount;
	int			isPropertyArray;
	int			arrayExist;
	WsXmlNodeH	instanceNode;
	WsXmlNodeH	refParamNode = NULL,eprNode=NULL;
	char*		className;
	CMPIStatus	rc;
	int			i, j, k;

	if ((NULL == node) || (NULL == ws_xml_get_child (node, 0, NULL, NULL)))
	{ 
		return -1; 	
	}

	instanceNode = ws_xml_get_child (node, 0, NULL, NULL);
	className    = ws_xml_get_node_name_ns (instanceNode);
	removeTailoringSpaces (className); //some vendor send the class name with tailoring spaces, remove it.
	*cci		 = newCMPIInstance (NULL, &rc);
	setInstNsAndCn (*cci, NULL, className);



	/* add properties from wsman to instance */
	childCount	= ws_xml_get_child_count (instanceNode);
	for (i = 0; i < childCount; i++)
	{
		WsXmlNodeH	childNode;
		WsXmlNodeH	referenceNode;
		CMPIValue	value;
		char*		nodeName;
		int			propertyCount;
		CMPIString*	propertyName;
		CMPIData	data = {0};

		childNode	= ws_xml_get_child (instanceNode, i, NULL, NULL);
		nodeName	= ws_xml_get_node_local_name (childNode);

		/* add only the requested properties */
		if ((properties != NULL) && (properties [0] != NULL))
		{
			int l = 0;
			while (properties [l] != NULL)
			{
				if (0 == strcmp (nodeName, properties [l]))
				{
					break;
				}
				l++;
			}
			if (properties [l] == '\0') { continue; }
		}

		/* if the node is a a reference */
		referenceNode = ws_xml_find_in_tree (childNode, XML_NS_ADDRESSING, "ReferenceParameters", 1); 
		if (NULL != referenceNode)
		{
			CMPIValue		value;

			if (0 == addKeysToObjectPath (&value.ref, referenceNode))
			{
				(*cci)->ft->setProperty (*cci, nodeName, &value, CMPI_ref);
				native_release_CMPIValue (CMPI_ref, &value);
			}
		}
		else {

			/* check if the node is NIL node */
			WsXmlAttrH attr		 = ws_xml_get_node_attr (childNode, 0);
			if ((NULL != attr) &&
				((0 == strcmp (ws_xml_get_attr_name(attr), XML_NS_SCHEMA_INSTANCE_NIL)) && 
				 (0 == strcmp (ws_xml_get_attr_ns_prefix (attr), XML_NS_SCHEMA_INSTANCE_PREFIX)) &&
				 (0 == strcmp (ws_xml_get_attr_value (attr), "true"))
				 ))
			{
				continue;
			}

			value		= str2CMPIValue (CMPI_string, ws_xml_get_node_text (childNode), NULL);

			/* for array we dont have any information from the server, check to see if more than
			   one occurrence of property with same name, if so then its an array				*/
			isPropertyArray		= 0;
			arrayExist			= 0;
			for (j = i + 1; j < childCount; j++)
			{
				childNode	= ws_xml_get_child (instanceNode, j, NULL, NULL);
				if (strcmp (nodeName, ws_xml_get_node_local_name (childNode)) == 0)
				{
					isPropertyArray = 1;
					break;
				}
			}
			propertyCount = CMGetPropertyCount (*cci, NULL);
			for (k = 0; k < propertyCount; k++)
			{
				data = CMGetPropertyAt (*cci, k, &propertyName, NULL);
				propertyNamePtr = CMGetCharPtr (propertyName);
				if (strcmp (nodeName, propertyNamePtr) == 0)
				{
					isPropertyArray	= 1;
					arrayExist		= 1;
					CMRelease (propertyName);
					break;
				}
				else
				{
					CMRelease (propertyName);
				}
			}

			/* if the property is an array then add the properties to array if exiest or create one 
			   and add the property */
			if (isPropertyArray)
			{
				if (arrayExist)
				{
					simpleArrayAdd (data.value.array, &value, CMPI_string);
				}
				else
				{
					CMPIValue  arr;
					arr.array = newCMPIArray(0, CMPI_string, NULL);
					simpleArrayAdd (arr.array, &value, CMPI_string);
					(*cci)->ft->setProperty (*cci, nodeName, &arr, CMPI_ARRAY);
					native_release_CMPIValue (CMPI_ARRAY, &arr);
				}
			}
			else
			{
				(*cci)->ft->setProperty (*cci, nodeName, &value, CMPI_string);
				native_release_CMPIValue (CMPI_string, &value);
			}
		}
	}

	if(true == getObjPath)
	{
		eprNode = ws_xml_find_in_tree (node, XML_NS_ADDRESSING, "EndpointReference", 1);
		refParamNode = ws_xml_find_in_tree (eprNode, XML_NS_ADDRESSING, "ReferenceParameters", 1);
		if (NULL != refParamNode)
		{
			//CMPIValue		value;
			CMPIObjectPath*  value;
			if (0 == addKeysToObjectPath (&value,refParamNode))
			{
				CMPIStatus rc;
				int k;
				int propCount = value->ft->getKeyCount(value,&rc);
				for(k=0;k<propCount;k++)
				{
					CMPIString *str;
					CMPIData d = value->ft->getKeyAt(value,k,&str,&rc);
					(*cci)->ft->addKey((*cci),CMGetCharPtr(str),&d.value,d.type);
				}
			}
		}
	}


	return 0;
}

/*
 * addArguments
 */
static int 
addArgumentsToArgs (CMPIArgs** out, WsXmlNodeH node)
{
	int			childCount;
	int			isArgumentArray;
	int			arrayExist;
	WsXmlNodeH	instanceNode;
	int			i, j, k;

	if ((NULL == node) || (NULL == ws_xml_get_child (node, 0, NULL, NULL)))
	{ 
		return -1; 	
	}

	instanceNode = ws_xml_get_child (node, 0, NULL, NULL);

	/* add arguments from wsman */
	childCount	= ws_xml_get_child_count (instanceNode);
	for (i = 0; i < childCount; i++)
	{
		WsXmlNodeH	childNode;
		CMPIValue	value;
		char*		nodeName;
		int			argumentCount;
		CMPIString*	propertyName;
		CMPIData	data = {0};
		WsXmlAttrH  attr;
		WsXmlNodeH	referenceNode;
		
		childNode	= ws_xml_get_child (instanceNode, i, NULL, NULL);
		nodeName	= ws_xml_get_node_local_name (childNode);
		

		/* if the node is a a reference */
		referenceNode = ws_xml_find_in_tree (childNode, XML_NS_ADDRESSING, "ReferenceParameters", 1); 
		if (NULL != referenceNode)
		{
			CMPIValue		value;

			if (0 == addKeysToObjectPath (&value.ref, referenceNode))
			{
				(*out)->ft->addArg (*out, nodeName, &value, CMPI_ref);
				native_release_CMPIValue (CMPI_ref, &value);
			}
		}
		else 
		{
			/* check if the node is NIL node */
			attr = ws_xml_get_node_attr (childNode, 0);
			if ((NULL != attr) &&
					((0 == strcmp (ws_xml_get_attr_name(attr), XML_NS_SCHEMA_INSTANCE_NIL)) && 
					 (0 == strcmp (ws_xml_get_attr_ns_prefix (attr), XML_NS_SCHEMA_INSTANCE_PREFIX)) &&
					 (0 == strcmp (ws_xml_get_attr_value (attr), "true"))
					 ))
			{
				continue;
			}

			value		= str2CMPIValue (CMPI_string, ws_xml_get_node_text (childNode), NULL);

			/* for array we dont have any information from the server, check to see if more than
			   one occurrence of property with same name, if so then its an array				*/
			isArgumentArray 	= 0;
			arrayExist			= 0;
			for (j = i + 1; j < childCount; j++)
			{
				childNode	= ws_xml_get_child (instanceNode, j, NULL, NULL);
				if (strcmp (nodeName, ws_xml_get_node_local_name (childNode)) == 0)
				{
					isArgumentArray = 1;
					break;
				}
			}
			argumentCount = CMGetArgCount(*out,NULL);
			for (k = 0; k < argumentCount; k++)
			{
				data = CMGetArgAt (*out, k, &propertyName, NULL);
				if (strcmp (nodeName, CMGetCharPtr (propertyName)) == 0)
				{
					isArgumentArray	= 1;
					arrayExist		= 1;
					CMRelease (propertyName);
					break;
				}
				else
				{
					CMRelease (propertyName);
				}
			}

			/* if the property is an array then add the properties to array if exiest or create one 
			   and add the property */
			if (isArgumentArray)
			{
				if (arrayExist)
				{
					simpleArrayAdd (data.value.array, &value, CMPI_string);
				}
				else
				{
					CMPIValue  arr;
					arr.array = newCMPIArray(0, CMPI_string, NULL);
					simpleArrayAdd (arr.array, &value, CMPI_string);
					(*out)->ft->addArg (*out, nodeName, &arr, CMPI_ARRAY);
					native_release_CMPIValue (CMPI_ARRAY, &arr);
				}
			}
			else
			{
				(*out)->ft->addArg (*out, nodeName, &value, CMPI_string);
				native_release_CMPIValue (CMPI_string, &value);
			}
		}
	}	

	return 0;
}

/*
 * createEPR
 */
static epr_t*
createEPR (CMPIObjectPath *cop, char* uri, CMPIStatus *rc)
{
	epr_t*	epr = NULL;
	int		keyCount;
	int		i;
	KeyNameValue_T		keys;

	keyCount = CMGetKeyCount (cop, rc);

	/* create a new wsman epr */
	epr = epr_create (uri, NULL, NULL);
	if (epr == NULL) { return NULL; }

	/* add the keys from objectpath to wsman epr */
	keyCount = CMGetKeyCount (cop, rc);
	for (i = 0; i < keyCount; i++)
	{
		keys.value		= CMGetKeyAt (cop, i, &keys.name, NULL);
		keys.charValue	= value2Chars (keys.value.type, &keys.value.value);
		epr_add_selector_text (epr, CMGetCharPtr (keys.name), keys.charValue);

		CMRelease (keys.name);
		if (keys.charValue)  { free (keys.charValue);}
	}

	return epr;
}

/*
 * destroyEPR
 */
static void
destroyEPR (epr_t* epr)
{
	epr_destroy (epr);
}

/*
 * cmpInst
 */
int
cmpInst (CMPIInstance* inst1, CMPIInstance* inst2)
{
	int			propertyCount;
	CMPIData	property1;
	CMPIData	property2;
	CMPIString* propertyName1;
	CMPIString* propertyName2;
	int			i;

	if ((inst1 == NULL) || (inst2 == NULL))
	{
		return -1;
	}

	propertyCount = CMGetPropertyCount (inst1, NULL);
	for (i = 0; i < propertyCount; i++)
	{
		property1 = CMGetPropertyAt (inst1, i, &propertyName1, NULL);
		property2 = CMGetPropertyAt (inst2, i, &propertyName2, NULL);

		if (0 != strcmp (CMGetCharPtr (property1.value.string), CMGetCharPtr (property2.value.string)))
		{
			CMRelease (propertyName1);
			CMRelease (propertyName2);
			return -1;
		}
		CMRelease (propertyName1);
		CMRelease (propertyName2);
	}
	return 0;
}


/*
 * setHttpError
 */
static int 
setHttpError (CMPIStatus* rc, WsManClient* cl)
{
	int i;

	if (0 != cl->response_code)
	{
		for (i = 0; i < (sizeof (httpErrorTbl) / sizeof (HTTPError_T)); i++)
		{
			if (httpErrorTbl [i].errCode == cl->response_code)
			{
				CMSetStatusWithChars (rc, CMPI_RC_CONNECTION_FAILED, httpErrorTbl [i].errString);	
				break;
			}
		}
		
		if (i == (sizeof (httpErrorTbl)/sizeof (HTTPError_T)))
		{
			CMSetStatusWithChars (rc, CMPI_RC_CONNECTION_FAILED, "Unknown HTTP Error");	
		}
	}
	else if (0 != cl->last_error) 
	{
		char errorStr [MAX_LAST_ERROR_STR_LEN + 1];
		getLastErrorStr (cl->last_error, errorStr, sizeof (errorStr));
		CMSetStatusWithChars (rc, CMPI_RC_CONNECTION_FAILED, errorStr);	
	}
	else
	{
		CMSetStatusWithChars (rc, CMPI_RC_CONNECTION_FAILED, "Unknown Error");	
	}

	return 0;
}

/*
 * getWsmanFaultCode 
 */
char*
getWsmanFaultCode (WsXmlDocH doc)
{
	char*	ns;
	char*	faultXpath;
	char*	faultCode;
	size_t	len;

	ns = ws_xml_get_node_name_ns_prefix (ws_xml_get_doc_root (doc));
	if (ns == NULL)
	{
		return NULL;
	}
	
	/* allocate memory to fit this format /ns:Envelope/ns:Body/ns:Fault/ns:Code/ns:Subcode/ns:Value" */
	len = (6 * strlen (ns)) + sizeof ("/:Envelope/:Body/:Fault/:Code/:Subcode/:Value") + 2;
	faultXpath = malloc (len);
	if (NULL == faultXpath) { return NULL; }

	memset (faultXpath, 0, len);

	snprintf(faultXpath, len, "/%s:Envelope/%s:Body/%s:Fault/%s:Code/%s:Subcode/%s:Value ", ns, ns, ns,ns, ns, ns);
	faultCode = ws_xml_get_xpath_value (doc, faultXpath);

	free (faultXpath);

	return faultCode;
}

/*
 * isWsmanError
 */
int
isWsmanError (WsXmlDocH doc)
{
	char* faultCode = getWsmanFaultCode (doc);

	if (faultCode == NULL) { return 0;	 }
	else	{ free (faultCode); return 1;}
}

/*
 * setWsmanError
 */
static int 
setWsmanError (WsXmlDocH doc, CMPIStatus* rc)
{
	char*	faultValue;
	int		i;

	faultValue = getWsmanFaultCode (doc);
	if (faultValue != NULL)
	{
		for (i = 0; i < (sizeof (wsmanErrorTbl) / sizeof (WSMANError_T)); i++)
		{
			if (0 == strcmp (wsmanErrorTbl [i].errString, faultValue))
			{
				CMSetStatusWithChars (rc, wsmanErrorTbl [i].errCode, faultValue);
				break;
			}
		}

		if (i == (sizeof (wsmanErrorTbl) / sizeof (WSMANError_T)))
		{
			CMSetStatusWithChars (rc, CMPI_RC_ERR_FAILED, faultValue);
		}
		
		u_free (faultValue);
	}
	else
	{
		CMSetStatusWithChars (rc, CMPI_RC_ERR_FAILED, "Unknown Error");
	}
	return 0;
}

/**
 * enumInstanceNames
 */
static CMPIEnumeration* 
enumInstanceNames (CMCIClient* mb, CMPIObjectPath* cop, CMPIStatus* rc)
{
	WsManClient*		cl;
	client_opt_t*		options;
	CMPIEnumeration*	enumeration;
	CMPIObjectPath*		enumCop;
	WsXmlDocH			enumDoc;
	WsXmlDocH			doc;
	WsXmlNodeH			node;
	char*				enumContext;
	CMPIArray*			array;
	char				classUri [sizeof (XML_NS_CIM_CLASS) + 1 + MAX_CLASS_NAME_LENGTH + 1];

	/* construct the class uri */
	if (-1 == constructWsmanClassUri (cop, classUri, sizeof (classUri), rc))
	{
		return NULL;
	}

	cl		= ((ClientEnc*)mb)->wsmanClient;
	options = wsmc_options_init ();

	/* set the name space */
	setCIMNameSpace (cop, options);

	wsmc_set_action_option (options, FLAG_ENUMERATION_ENUM_EPR);

	/* enumerate the instance */
	enumDoc = wsmc_action_enumerate (cl, classUri, options, NULL);
	if (!enumDoc) 
	{
		setHttpError (rc, cl);
		wsmc_options_destroy (options);
		return NULL;
	}

	WSMAN_DUMP_NODE_TREE (enumDoc);

	if (!WSMAN_SUCCESS (cl, enumDoc))
	{
		setWsmanError (enumDoc, rc);
		enumeration = NULL;
	}
	else
	{
		array		= newCMPIArray (0, CMPI_ref, NULL);
		enumContext = wsmc_get_enum_context (enumDoc);

		/* start enumeration */
		while (enumContext != NULL && enumContext[0] != 0) 
		{
			doc = wsmc_action_pull (cl, classUri, options, NULL, enumContext);
			if (!doc) 
			{
				setHttpError (rc, cl);
				break;
			}

			WSMAN_DUMP_NODE_TREE (doc);

			if (!WSMAN_SUCCESS (cl, doc))	
			{
				ws_xml_destroy_doc (doc);
				u_free (enumContext); 
				break; 
			}
			node  = ws_xml_get_soap_body(doc);
			/* add the properties to the instance from the enumeration response node */
			if (0 == addKeysToObjectPath (&enumCop, node))
			{
				/* add the objectpath to the objectpath list/array */
				simpleArrayAdd (array, (CMPIValue*)&enumCop, CMPI_ref);
			}

			u_free(enumContext);

			enumContext = wsmc_get_enum_context (doc);
			
			if (doc) {	ws_xml_destroy_doc (doc); }
		}

		enumeration = newCMPIEnumeration (array, rc);
	}

	ws_xml_destroy_doc (enumDoc);
	wsmc_options_destroy (options);

	return enumeration;
}

/**
 * enumInstances 
 */
static CMPIEnumeration* 
enumInstances (CMCIClient* mb, CMPIObjectPath* cop, CMPIFlags flags, char** properties, CMPIStatus* rc)
{
	int					childCount;
	int					i=0;
	WsManClient*		cl;
	client_opt_t*		options;
	CMPIEnumeration	*	enumeration;
	CMPIInstance*		cci;
	WsXmlDocH			enumDoc;
	WsXmlDocH			doc;
	//WsXmlNodeH			node;
	WsXmlNodeH			itemsNode=NULL;
	WsXmlNodeH			endOfSeqNode =NULL;
	char*				enumContext;
	CMPIArray*			array;
	char				classUri [sizeof (XML_NS_CIM_CLASS) + 1 + MAX_CLASS_NAME_LENGTH + 1];

	/* construct the class uri */
	if (-1 == constructWsmanClassUri (cop, classUri, sizeof (classUri), rc))
	{
		return NULL;
	}

	cl				= ((ClientEnc*)mb)->wsmanClient;
	options			= wsmc_options_init ();

	/* set the name space */
	setCIMNameSpace (cop, options);
	
	wsmc_set_action_option (options, FLAG_ENUMERATION_ENUM_OBJ_AND_EPR);
	wsmc_set_action_option (options,FLAG_ENUMERATION_OPTIMIZATION);
	options->max_elements = MAX_ELEMENT_SIZE;

	/* enumerate the instance */
	enumDoc = wsmc_action_enumerate (cl, classUri, options, NULL);
	if (!enumDoc) 
	{
		setHttpError (rc, cl);
		wsmc_options_destroy (options);
		return NULL;
	}

	WSMAN_DUMP_NODE_TREE (enumDoc);

	if (!WSMAN_SUCCESS (cl, enumDoc))
	{
		setWsmanError (enumDoc, rc);
		enumeration = NULL;
	}
	else
	{
		array		= newCMPIArray (0, CMPI_instance, NULL);
		itemsNode = ws_xml_find_in_tree (ws_xml_get_soap_body(enumDoc), XML_NS_WS_MAN, "Items", 1);
		childCount	= ws_xml_get_child_count (itemsNode);
		for(i=0;i<childCount;i++)
		{
			WsXmlNodeH childNode	= ws_xml_get_child (itemsNode, i, NULL, NULL);
			/* add the properties to the instance from the enumeration response node */
			if (0 == addPropertiesToInstance (properties, &cci, childNode,true))
			{
				/* add the instance to the instance list/array */
				simpleArrayAdd (array, (CMPIValue*)&cci, CMPI_instance);
			}
		}
		
		endOfSeqNode = ws_xml_find_in_tree (ws_xml_get_soap_body(enumDoc), XML_NS_WS_MAN, "EndOfSequence", 1);


		enumContext = wsmc_get_enum_context (enumDoc);

		/* start enumeration */
		while ((endOfSeqNode == NULL) && enumContext != NULL && enumContext[0] != 0) 
		{
			doc = wsmc_action_pull (cl, classUri, options, NULL, enumContext);
			if (!doc) 
			{
				setHttpError (rc, cl);
				break;
			}

			WSMAN_DUMP_NODE_TREE (doc);

			if (!WSMAN_SUCCESS (cl, doc))	
			{
				char* faultCode = getWsmanFaultCode (enumDoc);
				if ((faultCode != NULL) && (0 == strcmp ("wsman:UnsupportedFeature", faultCode) ) )
				{
					setWsmanError (doc, rc);
				}
				if(faultCode) u_free(faultCode);
				ws_xml_destroy_doc (doc);
				u_free (enumContext); 
				break; 
			}
			itemsNode = ws_xml_find_in_tree (ws_xml_get_soap_body(doc), XML_NS_ENUMERATION, "Items", 1);
			childCount	= ws_xml_get_child_count (itemsNode);
			for(i=0;i<childCount;i++)
			{
				WsXmlNodeH childNode	= ws_xml_get_child (itemsNode, i, NULL, NULL);
				/* add the properties to the instance from the enumeration response node */
				if (0 == addPropertiesToInstance (properties, &cci, childNode,true))
				{
					/* add the instance to the instance list/array */
					simpleArrayAdd (array, (CMPIValue*)&cci, CMPI_instance);
				}
			}

//			node = ws_xml_find_in_tree (ws_xml_get_doc_root (doc), XML_NS_ENUMERATION, "Items", 1);
			/* add the properties to the instance from the enumeration response node */
//			if (0 == addPropertiesToInstance (properties, &cci, node))
//			{
				/* add the instance to the instance list/array */
//				simpleArrayAdd (array, (CMPIValue*)&cci, CMPI_instance);
//			}
			

			u_free (enumContext);
			enumContext = wsmc_get_enum_context (doc);
			
			if (doc) {	ws_xml_destroy_doc (doc); }
		}

		enumeration = newCMPIEnumeration (array, rc);
	}

	ws_xml_destroy_doc (enumDoc);
	wsmc_options_destroy (options);

	return enumeration;
}

/**
 * getInstance
 */
static CMPIInstance* 
getInstance (CMCIClient* mb, CMPIObjectPath* cop, CMPIFlags flags, char** properties, CMPIStatus * rc)
{
	WsManClient*		cl;
	CMPIInstance*		cci;
	client_opt_t*		options;
	WsXmlDocH			doc;
	WsXmlNodeH			node;
	int					keyCount;
	KeyNameValue_T*		keys;
	char				objectUri [MAX_OBJECT_URI_LENGTH + 1];

	getObjectUri (cop, objectUri);

	cl		= ((ClientEnc*)mb)->wsmanClient;;
	options = wsmc_options_init ();

	/* set the name space */
	setCIMNameSpace (cop, options);

	/* get the keys from object path and set it to wsman option */
	keyCount = CMGetKeyCount (cop, rc);
	keys	 = NULL;
	if (keyCount != 0)
	{
		if (NULL == (keys = malloc (sizeof (KeyNameValue_T) * keyCount))) 
		{
			wsmc_options_destroy (options);
			return NULL; 
		}
		addKeysToOption (cop, options, keys, rc);
	}

	/* perform the action / get the instance from wsman server */
	doc = wsmc_action_get (cl, objectUri, options);
	if (!doc) 
	{
		setHttpError (rc, cl);
		wsmc_options_destroy (options);
		releaseKeys (keys, keyCount);
		return NULL;
	}

	WSMAN_DUMP_NODE_TREE (doc);

	cci = NULL;
	if (WSMAN_SUCCESS (cl, doc))
	{

		/* add the properties to instance from the response node/doc */
		node = ws_xml_get_soap_body (doc);
		addPropertiesToInstance (properties, &cci, node,false);
	}
	else
	{
		setWsmanError (doc, rc);
	}

	if (doc) { ws_xml_destroy_doc (doc);	}
	wsmc_options_destroy (options);
	releaseKeys (keys, keyCount);

	return cci;
}

/**
 * createInstance
 */
static CMPIObjectPath* 
createInstance (CMCIClient* mb, CMPIObjectPath* cop, CMPIInstance* inst, CMPIStatus* rc)
{
	WsManClient*		 cl;
	CMPIObjectPath*		 newCop;
	client_opt_t*		 options;
	WsXmlDocH			 doc;
	WsXmlDocH			 instDoc;
	WsXmlNodeH			 node;
	int					 keyCount;
	int					 propertyCount;
	KeyNameValue_T*		 keys;
	PropertyNameValue_T* property;
	char				 objectUri [MAX_OBJECT_URI_LENGTH + 1];

	getObjectUri (cop, objectUri);

	cl		= ((ClientEnc*)mb)->wsmanClient;;
	options = wsmc_options_init ();

	/* create a xml doc for new instance */
	instDoc = ws_xml_create_doc ((const char*)objectUri, strrchr (objectUri, '/') + 1);
	node = ws_xml_get_doc_root (instDoc);

	/* get the keys & properties from object path and set it to wsman option and node */
	keyCount = CMGetKeyCount (cop, rc);
	keys	 = NULL;
	if (keyCount != 0)
	{
		if (NULL == (keys = malloc (sizeof (KeyNameValue_T) * keyCount))) 
		{
			wsmc_options_destroy (options);
			return NULL; 
		}
		addKeysToOption (cop, options, keys, rc);
	}
	propertyCount = CMGetPropertyCount (inst, rc);
	property	  = NULL;
	if (propertyCount != 0)
	{
		if (NULL == (property = malloc (sizeof (PropertyNameValue_T) * propertyCount)))
		{
			wsmc_options_destroy (options);
			return NULL; 
		}
		addPropertiesToNode (cop, inst, &node, property, rc);
	}

	/* perform the action / create new instance */
	doc = wsmc_action_create (cl, objectUri, options, instDoc);
	ws_xml_destroy_doc (instDoc);
	if (!doc) 
	{
		setHttpError (rc, cl);
		wsmc_options_destroy (options);
		releaseKeys (keys, keyCount);
		releaseProperties (property, propertyCount);
		return NULL;
	}

	WSMAN_DUMP_NODE_TREE (doc);

	newCop = NULL;
	if (WSMAN_SUCCESS (cl, doc))
	{
		/* create new object path */
		node = ws_xml_get_doc_root (doc);
		if (NULL != node) { addKeysToObjectPath (&newCop, node); }
	}
	else
	{
		setWsmanError (doc, rc);
	}

	if (doc) { ws_xml_destroy_doc(doc);	}
	wsmc_options_destroy(options);
	releaseKeys (keys, keyCount);
	releaseProperties (property, propertyCount);

	return newCop;
}

/**
 * setInstance
 */
static CMPIStatus 
setInstance (CMCIClient* mb, CMPIObjectPath* cop, CMPIInstance* inst, CMPIFlags flags, 
																	  char** properties)
{
	WsManClient*		 cl;
	client_opt_t*		 options;
	WsXmlDocH			 doc;
	CMPIStatus			 rc;
	int					 keyCount;
	int					 propertyCount;
	KeyNameValue_T*		 keys;
	PropertyNameValue_T* property;
	char				 objectUri [MAX_OBJECT_URI_LENGTH + 1];

	getObjectUri (cop, objectUri);

	cl		= ((ClientEnc*)mb)->wsmanClient;
	options = wsmc_options_init ();

	/* set the name space */
	setCIMNameSpace (cop, options);

	/* get the keys & properties from object path and set it to wsman options */
	keyCount = CMGetKeyCount (cop, &rc);
	keys	 = NULL;
	if (keyCount != 0)
	{
		if (NULL == (keys = malloc (sizeof (KeyNameValue_T) * keyCount))) 
		{
			wsmc_options_destroy (options);
			CMSetStatusWithChars (&rc, CMPI_RC_ERR_FAILED, "Error allocating memory\n");
			return rc; 
		}
		addKeysToOption (cop, options, keys, &rc);
	}
	propertyCount = CMGetPropertyCount (inst, &rc);
	property	  = NULL;
	if (propertyCount != 0)
	{
		if (NULL == (property = malloc (sizeof (PropertyNameValue_T) * propertyCount)))
		{
			wsmc_options_destroy (options);
			CMSetStatusWithChars (&rc, CMPI_RC_ERR_FAILED, "Error allocating memory\n");
			return rc; 
		}
		addPropertiesToOption (inst, options, property, &rc);
	}

	/* perform the action / set the instance */
	doc = wsmc_action_get_and_put (cl, objectUri, options);
	if (!doc) 
	{
		setHttpError (&rc, cl);
	}
	else
	{
		WSMAN_DUMP_NODE_TREE (doc);

		/* set the status */
		if (WSMAN_SUCCESS (cl, doc))
		{
			CMSetStatus(&rc, CMPI_RC_OK);
		}
		else
		{
			setWsmanError (doc, &rc);
		}

		ws_xml_destroy_doc(doc);
	}

	wsmc_options_destroy(options);
	releaseKeys (keys, keyCount);
	releaseProperties (property, propertyCount);

	return rc;
}

/**
 * deleteInstance
 */
static CMPIStatus 
deleteInstance (CMCIClient* mb,  CMPIObjectPath* (cop))
{
	WsManClient*	cl;
	client_opt_t*	options;
	WsXmlDocH		doc;
	CMPIStatus		rc;
	int				keyCount;
	KeyNameValue_T*	keys;
	char			objectUri [MAX_OBJECT_URI_LENGTH + 1];

	getObjectUri (cop, objectUri);

	cl		= ((ClientEnc*)mb)->wsmanClient;;
	options = wsmc_options_init();
	
	setCIMNameSpace (cop, options);

	/* get the keys from object path and set it to wsman option */
	keyCount = CMGetKeyCount (cop, &rc);
	keys	 = NULL;
	if (keyCount != 0)
	{
		if (NULL == (keys = malloc (sizeof (KeyNameValue_T) * keyCount))) 
		{
			wsmc_options_destroy (options);
			CMSetStatusWithChars (&rc, CMPI_RC_ERR_FAILED, "Error allocating memory\n");
			return rc; 
		}
		addKeysToOption (cop, options, keys, &rc);
	}

	/* perform the action / delete the instance */
	doc = wsmc_action_delete(cl, objectUri, options);
    if (!doc) 
	{
		setHttpError (&rc, cl);
		wsmc_options_destroy(options);
		return rc;
    }

	WSMAN_DUMP_NODE_TREE (doc);

	/* set the status */
	if (WSMAN_SUCCESS (cl, doc))
	{
		CMSetStatus(&rc, CMPI_RC_OK);
	}
	else
	{
		setWsmanError (doc, &rc);
	}

	if (doc) { ws_xml_destroy_doc(doc);	}
	wsmc_options_destroy(options);
	releaseKeys (keys, keyCount);

	return rc;
}

/**
 * execQuery
 */
static CMPIEnumeration* 
execQuery (CMCIClient* mb, CMPIObjectPath* cop, const char* query, const char* lang, CMPIStatus* rc)
{
	WsManClient*		cl;
	client_opt_t*		options;
	CMPIEnumeration	*	enumeration;
	CMPIInstance*		cci;
	WsXmlDocH			enumDoc;
	WsXmlDocH			doc;
	WsXmlNodeH			node;
	char*				enumContext;
	CMPIArray*			array;
	filter_t*			filter;
	char				classUri [sizeof (XML_NS_CIM_CLASS) + 1 + MAX_CLASS_NAME_LENGTH + 1];

	/* construct the class uri */
	if (-1 == constructWsmanClassUri (cop, classUri, sizeof (classUri), rc))
	{
		return NULL;
	}

	cl		= ((ClientEnc*)mb)->wsmanClient;;
	options = wsmc_options_init ();

	/* set the name space */
	setCIMNameSpace (cop, options);

	/* create the filter */
	filter = filter_create_simple ("http://schemas.dmtf.org/wbem/cql/1/dsp0202.pdf", query);

	/* enumerate the instance */ 
	enumDoc = wsmc_action_enumerate (cl, classUri, options, filter);
	if (!enumDoc) 
	{
		setHttpError (rc, cl);
		wsmc_options_destroy (options);
		filter_destroy (filter);
		return NULL;
	}

	WSMAN_DUMP_NODE_TREE (enumDoc);

	if (!WSMAN_SUCCESS (cl, enumDoc))
	{
		setWsmanError (enumDoc, rc);
		enumeration = NULL;
	}
	else
	{
		array		= newCMPIArray (0, CMPI_instance, NULL);
		enumContext = wsmc_get_enum_context (enumDoc);

		/* start enumeration */
		while (enumContext != NULL && enumContext[0] != 0) 
		{
			doc = wsmc_action_pull (cl, classUri, options, NULL, enumContext);
			if (!doc) 
			{
				setHttpError (rc, cl);
				break;
			}
			
			WSMAN_DUMP_NODE_TREE (doc);

			if (!WSMAN_SUCCESS (cl, doc))	
			{
				ws_xml_destroy_doc (doc);
				u_free (enumContext); 
				break; 
			}

			node		= ws_xml_find_in_tree (ws_xml_get_doc_root (doc), XML_NS_ENUMERATION, 
																		  "Items", 1);
			/* add the properties to the instance from the enumeration response node */
			if (0 == addPropertiesToInstance (NULL, &cci, node,false))
			{
				/* add the instance to the instance list/array */
				simpleArrayAdd (array, (CMPIValue*)&cci, CMPI_instance);
			}

			u_free (enumContext);
			enumContext = wsmc_get_enum_context (doc);
			
			if (doc) {	ws_xml_destroy_doc (doc); }
		}

		enumeration = newCMPIEnumeration (array, rc);
	}

	ws_xml_destroy_doc (enumDoc);
	wsmc_options_destroy (options);
	filter_destroy (filter);

	return enumeration;
}

/**
 * associators
 */
static CMPIEnumeration* 
associators (CMCIClient* mb, CMPIObjectPath* cop, const char* assocClass, const char* resultClass,
			 const char* role, const char* resultRole, CMPIFlags flags, char** properties, 
			 CMPIStatus	* rc)
{
	int					childCount;
	int					i=0;
	WsManClient*		cl;
	client_opt_t*		options;
	CMPIEnumeration	*	enumeration;
	CMPIInstance*		cci;
	WsXmlDocH			enumDoc;
	WsXmlDocH			doc;
//	WsXmlNodeH			node;
	WsXmlNodeH			itemsNode=NULL;
	WsXmlNodeH			endOfSeqNode =NULL;

	char*				enumContext;
	CMPIArray*			array;
	epr_t*				epr;
	filter_t*			filter;
	char				objectUri [MAX_OBJECT_URI_LENGTH + 1];

	enumeration = NULL;
	getObjectUri (cop, objectUri);

	cl		= ((ClientEnc*)mb)->wsmanClient;;
	options = wsmc_options_init ();

	/* set the name space */
	setCIMNameSpace (cop, options);

	/* get the keys from object path and set it to wsman epr */
	epr = createEPR (cop, objectUri, rc);

	/* create association filter */
	filter = filter_create_assoc (epr, 0, assocClass, resultClass, role, resultRole, NULL, 0);

	wsmc_set_action_option (options, FLAG_ENUMERATION_ENUM_OBJ_AND_EPR);
	wsmc_set_action_option (options,FLAG_ENUMERATION_OPTIMIZATION);
	options->max_elements = MAX_ELEMENT_SIZE;
	/* enumerate the instance */ 
	enumDoc = wsmc_action_enumerate (cl, CIM_ALL_AVAILABLE_CLASSES, options, filter);
	if (!enumDoc) 
	{
		setHttpError (rc, cl);
		wsmc_options_destroy (options);
		destroyEPR (epr);
		filter_destroy (filter);
		return NULL;
	}

	WSMAN_DUMP_NODE_TREE (enumDoc);

	if (WSMAN_SUCCESS (cl, enumDoc))
	{
		array		= newCMPIArray (0, CMPI_instance, NULL);
		itemsNode = ws_xml_find_in_tree (ws_xml_get_soap_body(enumDoc), XML_NS_WS_MAN, "Items", 1);
		childCount	= ws_xml_get_child_count (itemsNode);
		for(i=0;i<childCount;i++)
		{
			WsXmlNodeH childNode	= ws_xml_get_child (itemsNode, i, NULL, NULL);
			/* add the properties to the instance from the enumeration response node */
			if (0 == addPropertiesToInstance (properties, &cci, childNode,true))
			{
				/* add the instance to the instance list/array */
				simpleArrayAdd (array, (CMPIValue*)&cci, CMPI_instance);
			}
		}
		endOfSeqNode = ws_xml_find_in_tree (ws_xml_get_soap_body(enumDoc), XML_NS_WS_MAN, "EndOfSequence", 1);
		enumContext = wsmc_get_enum_context (enumDoc);

		/* start enumeration */
		while ((endOfSeqNode == NULL) && enumContext != NULL && enumContext[0] != 0) 
		{
			doc = wsmc_action_pull (cl, CIM_ALL_AVAILABLE_CLASSES, options, NULL, enumContext);
			if (!doc) 
			{
				setHttpError (rc, cl);
				break;
			}

			WSMAN_DUMP_NODE_TREE (doc);

			if (!WSMAN_SUCCESS (cl, doc))	
			{
				char* faultCode = getWsmanFaultCode (enumDoc);
				if ((faultCode != NULL) && (0 == strcmp ("wsman:UnsupportedFeature", faultCode) ) )
				{
					setWsmanError (doc, rc);
				}
				if(faultCode) u_free(faultCode);
				ws_xml_destroy_doc (doc);
				u_free (enumContext); 
				break; 
			}
			itemsNode = ws_xml_find_in_tree (ws_xml_get_soap_body(doc), XML_NS_ENUMERATION, "Items", 1);
			childCount	= ws_xml_get_child_count (itemsNode);
			for(i=0;i<childCount;i++)
			{
				WsXmlNodeH childNode	= ws_xml_get_child (itemsNode, i, NULL, NULL);
				/* add the properties to the instance from the enumeration response node */
				if (0 == addPropertiesToInstance (properties, &cci, childNode,true))
				{
					/* add the instance to the instance list/array */
					simpleArrayAdd (array, (CMPIValue*)&cci, CMPI_instance);
				}
			}
			//node = ws_xml_find_in_tree (ws_xml_get_doc_root (doc), XML_NS_ENUMERATION, "Items", 1);
			/* add the properties to the instance from the enumeration response node */
			//if (0 == addPropertiesToInstance (properties, &cci, node))
			//{
				/* add the instance to the instance list/array */
			//	simpleArrayAdd (array, (CMPIValue*)&cci, CMPI_instance);
			//}

			u_free (enumContext);
			enumContext = wsmc_get_enum_context (doc);
			
			if (doc) {	ws_xml_destroy_doc (doc); }
		}

		enumeration = newCMPIEnumeration (array, rc);
	}
	else
	{
		/* 
		  if association filter is not supported then try a different menthod, enumetare 
		  the associated class and then find the instances that match the request class and result class 
		 */
		char* faultCode = getWsmanFaultCode (enumDoc);
		if ((faultCode != NULL) && 
			((0 == strcmp ("wsen:FilterDialectRequestedUnavailable", faultCode))  ||
			 (0 == strcmp ("wsen:CannotProcessFilter", faultCode))  || 
			 (0 == strcmp ("wsman:UnsupportedFeature", faultCode))) &&
			(assocClass != NULL) && (resultClass != NULL) && (role != NULL) && (resultRole != NULL))
		{
			CMPIEnumeration*	assocClassEnum;
			CMPIEnumeration*	resultClassEnum;
			CMPIObjectPath*		objectPath;
			CMPIObjectPath*		resultClassOp;

			/* enumerate the associated class */
			objectPath		= newCMPIObjectPath(NULL, assocClass, NULL);
			assocClassEnum	= mb->ft->enumInstances (mb, objectPath, 0, NULL, rc);
			if (assocClassEnum != NULL)
			{
				array		= newCMPIArray (0, CMPI_ref, NULL);
				while (assocClassEnum->ft->hasNext(assocClassEnum, NULL)) 
				{
					CMPIInstance* reqInst;
					CMPIInstance* oldInst;
					int		 match = 0;
					CMPIData data  = assocClassEnum->ft->getNext(assocClassEnum, NULL);
					CMPIData data1 = data.value.inst->ft->getProperty (data.value.inst, role, rc);
					CMPIData data2 = data.value.inst->ft->getProperty (data.value.inst, resultRole, rc);
					
					CMPIString* className1 = CMGetClassName (cop, rc);
					CMPIString* className2 = CMGetClassName (data1.value.ref, rc);
					CMPIString* className3 = CMGetClassName (data2.value.ref, rc);

					/* enumerate the result class */
					resultClassOp	= newCMPIObjectPath(NULL, resultClass, NULL);
					resultClassEnum	= mb->ft->enumInstances (mb, resultClassOp, 0, NULL, rc);
					if (resultClassEnum != NULL)
					{
						while (resultClassEnum->ft->hasNext(resultClassEnum, NULL)) 
						{
							CMPIData resultClassInst  = resultClassEnum->ft->getNext(resultClassEnum, NULL);

							CMPIString* resultClassName = CMGetClassName ( 
														CMGetObjectPath (resultClassInst.value.inst, NULL), rc);
							/* check if accocatedClass is associated with the request class and result class */
							if ((NULL == strstr (CMGetCharPtr (className2), CMGetCharPtr (className1))) || 
								(NULL == resultClass) ||
								(NULL == strstr (CMGetCharPtr (className3), CMGetCharPtr (resultClassName))))
							{
								CMRelease (resultClassName);
								continue; 
							}
							CMRelease (resultClassName);
							match = 1;
						}
						CMRelease (resultClassEnum);
					}

					CMRelease (resultClassOp);
					CMRelease (className1);
					CMRelease (className2);
					CMRelease (className3);

					if (!match) { continue; }

					reqInst  = getInstance (mb, data1.value.ref, 0, NULL, rc);
					oldInst  = getInstance (mb, cop, 0, NULL, rc);
					if (0 == cmpInst (reqInst, oldInst))
					{
						/* create a instance of associated class and add 
						   the instance list/array */
						CMPIInstance* inst	= getInstance (mb, data2.value.ref, 0, NULL, rc);
						simpleArrayAdd (array, (CMPIValue*)&inst, CMPI_instance);
					}
					if (reqInst) { CMRelease (reqInst); }
					if (oldInst) { CMRelease (oldInst); }
				}
				enumeration = newCMPIEnumeration (array, rc);
				CMRelease (assocClassEnum);
			}
			CMRelease (objectPath);
		}
		else
		{
			setWsmanError (enumDoc, rc);
			enumeration = NULL;
		}
		
		if (faultCode) u_free (faultCode);
	}

	ws_xml_destroy_doc (enumDoc);
	wsmc_options_destroy (options);
	destroyEPR (epr);
	filter_destroy (filter);

	return enumeration;
}

/**
 * associatorNames
 */
static CMPIEnumeration* 
associatorNames (CMCIClient* mb, CMPIObjectPath* cop, const char* assocClass, const char* resultClass,
				 const char* role, const char* resultRole, CMPIStatus* rc)
{
	WsManClient*		cl;
	client_opt_t*		options;
	CMPIEnumeration*	enumeration;
	CMPIObjectPath*		enumCop;
	WsXmlDocH			enumDoc;
	WsXmlDocH			doc;
	WsXmlNodeH			node;
	char*				enumContext;
	CMPIArray*			array;
	epr_t*				epr;
	filter_t*			filter;
	char				objectUri [MAX_OBJECT_URI_LENGTH + 1];

	enumeration  = NULL;
	getObjectUri (cop, objectUri);

	cl		= ((ClientEnc*)mb)->wsmanClient;;
	options = wsmc_options_init ();

	/* set the name space */
	setCIMNameSpace (cop, options);

	/* set to enumerate epr/objectpath */
	wsmc_set_action_option(options, FLAG_ENUMERATION_ENUM_EPR);

	/* get the keys from object path and set it to wsman epr */
	epr = createEPR (cop, objectUri, rc);

	/* create association filter */
	filter = filter_create_assoc (epr, 0, assocClass, resultClass, role, resultRole, NULL, 0 );

	/* enumerate the instance */ 
	enumDoc = wsmc_action_enumerate (cl, CIM_ALL_AVAILABLE_CLASSES, options, filter);
	if (!enumDoc) 
	{
		setHttpError (rc, cl);
		wsmc_options_destroy (options);
		destroyEPR (epr);
		filter_destroy (filter);
		return NULL;
	}

	WSMAN_DUMP_NODE_TREE (enumDoc);

	if (WSMAN_SUCCESS (cl, enumDoc))
	{
		array		= newCMPIArray (0, CMPI_ref, NULL);
		enumContext = wsmc_get_enum_context (enumDoc);

		/* start enumeration */
		while (enumContext != NULL && enumContext[0] != 0) 
		{
			doc = wsmc_action_pull (cl, CIM_ALL_AVAILABLE_CLASSES, options, NULL, enumContext);
			if (!doc) 
			{
				setHttpError (rc, cl);
				break;
			}

			WSMAN_DUMP_NODE_TREE (doc);

			if (!WSMAN_SUCCESS (cl, doc))	
			{
				ws_xml_destroy_doc (doc);
				u_free (enumContext); 
				break; 
			}

             /*node = ws_xml_get_doc_root (doc);*/
			 /* Now ResourceURI in Body is used for successive operation*/ 
			 node = ws_xml_get_soap_body (doc);

			/* add the properties to the instance from the enumeration response node */
			if (0 == addKeysToObjectPath (&enumCop, node))
			{
				/* add the objectpath to the objectpath list/array */
				simpleArrayAdd (array, (CMPIValue*)&enumCop, CMPI_ref);
			}

			u_free (enumContext);
			enumContext = wsmc_get_enum_context (doc);
			
			if (doc) {	ws_xml_destroy_doc (doc); }
		}

		enumeration = newCMPIEnumeration (array, rc);
	}
	else
	{
		/* 
		  if association filter is not supported then try a different menthod, enumetare 
		  the associated class and then find the instances that match the request class and result class 
		 */
		char* faultCode = getWsmanFaultCode (enumDoc);
		if ((faultCode != NULL) && 
			((0 == strcmp ("wsen:FilterDialectRequestedUnavailable", faultCode))  || 
			 (0 == strcmp ("wsen:CannotProcessFilter", faultCode))  || 
			 (0 == strcmp ("wsman:UnsupportedFeature", faultCode))) &&
			 (assocClass != NULL) && (resultClass != NULL) && (role != NULL) && (resultRole != NULL))
		{
			CMPIEnumeration*	assocClassEnum;
			CMPIEnumeration*	resultClassEnum;
			CMPIObjectPath*		objectPath;
			CMPIObjectPath*		resultClassOp;

			/* enumerate the associated class */
			objectPath		= newCMPIObjectPath(NULL, assocClass, NULL);
			assocClassEnum	= mb->ft->enumInstances (mb, objectPath, 0, NULL, rc);
			if (assocClassEnum != NULL)
			{
				array		= newCMPIArray (0, CMPI_ref, NULL);
				while (assocClassEnum->ft->hasNext(assocClassEnum, NULL)) 
				{
					CMPIInstance* reqInst;
					CMPIInstance* oldInst;
					int		 match = 0;
					CMPIData	data;
					CMPIData	data1;
					CMPIData	data2;
					CMPIString*	className1;
					CMPIString*	className2;
					CMPIString*	className3;

					data  = assocClassEnum->ft->getNext(assocClassEnum, rc);
					if (rc->rc != CMPI_RC_OK) { continue; }
					data1 = data.value.inst->ft->getProperty (data.value.inst, role, rc);
					if (rc->rc != CMPI_RC_OK) { continue; }
					data2 = data.value.inst->ft->getProperty (data.value.inst, resultRole, rc);
					if (rc->rc != CMPI_RC_OK) { continue; }

					className1 = CMGetClassName (cop, rc);
					className2 = CMGetClassName (data1.value.ref, rc);
					className3 = CMGetClassName (data2.value.ref, rc);

					/* enumerate the result class */
					resultClassOp	= newCMPIObjectPath(NULL, resultClass, NULL);
					resultClassEnum	= mb->ft->enumInstances (mb, resultClassOp, 0, NULL, rc);
					if (resultClassEnum != NULL)
					{
						while (resultClassEnum->ft->hasNext(resultClassEnum, NULL)) 
						{
							CMPIData resultClassInst  = resultClassEnum->ft->getNext(resultClassEnum, NULL);
							CMPIObjectPath* Objpath =  CMGetObjectPath (resultClassInst.value.inst, NULL);
							CMPIString* resultClassName = CMGetClassName (Objpath, rc);
							/* check if accocatedClass is associated with the request class and result class */
							if ((NULL == strstr (CMGetCharPtr (className2), CMGetCharPtr (className1))) || 
								(NULL == resultClass) ||
								(NULL == strstr (CMGetCharPtr (className3), CMGetCharPtr (resultClassName))))
							{
								CMRelease (Objpath); 
								CMRelease (resultClassName);
								continue; 
							}
							CMRelease (Objpath); 
							CMRelease (resultClassName);
							match = 1;
						}
						CMRelease (resultClassEnum);
					}

					CMRelease (resultClassOp);
					CMRelease (className1);
					CMRelease (className2);
					CMRelease (className3);

					if (!match) { continue; }

					reqInst  = getInstance (mb, data1.value.ref, 0, NULL, rc);
					oldInst  = getInstance (mb, cop, 0, NULL, rc);
					if (0 == cmpInst (reqInst, oldInst))
					{
						int i = 0;
						/* add the objectpath to the objectpath list/array */
						CMPIObjectPath* newCop	= CMClone (data2.value.ref, rc);

						/* remove the tailring spaces from the object path */
						CMPIString* classNameStr = CMGetClassName (newCop, NULL);
						char* className		= CMGetCharPtr (classNameStr);
					
						while (className [i] != 0)
						{
							if (className [i] == 0x20) { className [i] = 0; break; }
							i++;
						}
						CMSetClassName (newCop, className);
						
						simpleArrayAdd (array, (CMPIValue*)&newCop, CMPI_ref);
						CMRelease (classNameStr);
						
					}
					if (reqInst) { CMRelease (reqInst); }
					if (oldInst) { CMRelease (oldInst); }
				}
				enumeration = newCMPIEnumeration (array, rc);
				CMRelease (assocClassEnum);
			}
			CMRelease (objectPath);
		}
		else
		{
			setWsmanError (enumDoc, rc);
			enumeration = NULL;
		}
		
		if (faultCode) u_free (faultCode);
	}

	ws_xml_destroy_doc (enumDoc);
	wsmc_options_destroy (options);
	destroyEPR (epr);
	filter_destroy (filter);

	return enumeration;
}

/**
 * references
 */
static CMPIEnumeration* 
references (CMCIClient* mb, CMPIObjectPath* cop, const char* resultClass, const char* role ,
			CMPIFlags flags, char ** properties, CMPIStatus * rc)
{
	int					childCount;
	int					i=0;
	WsManClient*		cl;
	client_opt_t*		options;
	CMPIEnumeration	*	enumeration;
	CMPIInstance*		cci;
	WsXmlDocH			enumDoc;
	WsXmlDocH			doc;
//	WsXmlNodeH			node;
	WsXmlNodeH			itemsNode=NULL;
	WsXmlNodeH			endOfSeqNode =NULL;
	char*				enumContext;
	CMPIArray*			array;
	epr_t*				epr;
	filter_t*			filter;
	char				objectUri [MAX_OBJECT_URI_LENGTH + 1];

	enumeration = NULL;
	getObjectUri (cop, objectUri);

	cl		= ((ClientEnc*)mb)->wsmanClient;;
	options = wsmc_options_init ();

	/* set the name space */
	setCIMNameSpace (cop, options);

	/* get the keys from object path and set it to wsman epr */
	epr = createEPR (cop, objectUri, rc);

	/* create association filter */
	filter = filter_create_assoc (epr, 1, NULL, resultClass, role, NULL, NULL, 0 );

	wsmc_set_action_option (options, FLAG_ENUMERATION_ENUM_OBJ_AND_EPR);
	wsmc_set_action_option (options,FLAG_ENUMERATION_OPTIMIZATION);
	options->max_elements = MAX_ELEMENT_SIZE;

	/* enumerate the instance */
	enumDoc = wsmc_action_enumerate (cl, CIM_ALL_AVAILABLE_CLASSES, options, filter);
	if (!enumDoc) 
	{
		setHttpError (rc, cl);
		wsmc_options_destroy (options);
		destroyEPR (epr);
		filter_destroy (filter);
		return NULL;
	}
	
	WSMAN_DUMP_NODE_TREE (enumDoc);

	if (WSMAN_SUCCESS (cl, enumDoc))
	{
		array		= newCMPIArray (0, CMPI_instance, NULL);
		itemsNode = ws_xml_find_in_tree (ws_xml_get_soap_body(enumDoc), XML_NS_WS_MAN, "Items", 1);
		childCount	= ws_xml_get_child_count (itemsNode);
		for(i=0;i<childCount;i++)
		{
			WsXmlNodeH childNode	= ws_xml_get_child (itemsNode, i, NULL, NULL);
			/* add the properties to the instance from the enumeration response node */
			if (0 == addPropertiesToInstance (properties, &cci, childNode,true))
			{
				/* add the instance to the instance list/array */
				simpleArrayAdd (array, (CMPIValue*)&cci, CMPI_instance);
			}
		}
		
		endOfSeqNode = ws_xml_find_in_tree (ws_xml_get_soap_body(enumDoc), XML_NS_WS_MAN, "EndOfSequence", 1);

		enumContext = wsmc_get_enum_context (enumDoc);

		/* start enumeration */
		while ((endOfSeqNode == NULL) && enumContext != NULL && enumContext[0] != 0) 
		{
			doc = wsmc_action_pull (cl, CIM_ALL_AVAILABLE_CLASSES, options, NULL, enumContext);
			if (!doc) 
			{
				setHttpError (rc, cl);
				break;
			}
			
			WSMAN_DUMP_NODE_TREE (doc);

			if (!WSMAN_SUCCESS (cl, doc))	
			{
				char* faultCode = getWsmanFaultCode (enumDoc);
				if ((faultCode != NULL) && (0 == strcmp ("wsman:UnsupportedFeature", faultCode) ) )
				{
					setWsmanError (doc, rc);
				}
				if(faultCode) u_free(faultCode);
				ws_xml_destroy_doc (doc);
				u_free (enumContext); 
				break; 
			}
			itemsNode = ws_xml_find_in_tree (ws_xml_get_soap_body(doc), XML_NS_ENUMERATION, "Items", 1);
			childCount	= ws_xml_get_child_count (itemsNode);
			for(i=0;i<childCount;i++)
			{
				WsXmlNodeH childNode	= ws_xml_get_child (itemsNode, i, NULL, NULL);
				/* add the properties to the instance from the enumeration response node */
				if (0 == addPropertiesToInstance (properties, &cci, childNode,true))
				{
					/* add the instance to the instance list/array */
					simpleArrayAdd (array, (CMPIValue*)&cci, CMPI_instance);
				}
			}

//			node		= ws_xml_find_in_tree (ws_xml_get_doc_root (doc), XML_NS_ENUMERATION, "Items", 1);
			/* add the properties to the instance from the enumeration response node */
//			if (0 == addPropertiesToInstance (properties, &cci, node))
//			{
				/* add the instance to the instance list/array */
//				simpleArrayAdd (array, (CMPIValue*)&cci, CMPI_instance);
//			}

			u_free (enumContext);
			enumContext = wsmc_get_enum_context (doc);
			
			if (doc) {	ws_xml_destroy_doc (doc); }
		}

		enumeration = newCMPIEnumeration (array, rc);
	}
	else
	{
		/* 
		  if association filter is not supported then try a different menthod, enumetare 
		  the associated class and then find the instances that match the request class and result class 
		 */
		char* faultCode = getWsmanFaultCode (enumDoc);
		if ((faultCode != NULL) && 
			((0 == strcmp ("wsen:FilterDialectRequestedUnavailable", faultCode))  || 
			 (0 == strcmp ("wsen:CannotProcessFilter", faultCode))  || 
			 (0 == strcmp ("wsman:UnsupportedFeature", faultCode))) &&
			(resultClass != NULL) && (role != NULL))
		{
			CMPIEnumeration*	assocClassEnum;
			CMPIObjectPath*		objectPath;

			/* enumerate the result class */
			objectPath		= newCMPIObjectPath(NULL, resultClass, NULL);
			assocClassEnum	= mb->ft->enumInstances (mb, objectPath, 0, NULL, rc);
			if (assocClassEnum != NULL)
			{
				array		= newCMPIArray (0, CMPI_ref, rc);
				while (assocClassEnum->ft->hasNext(assocClassEnum, NULL)) 
				{
					CMPIInstance*	inst;
					CMPIString*		className1;
					CMPIString*		className2;
					CMPIInstance*	reqInst;
					CMPIInstance*	oldInst;

					CMPIData data  = assocClassEnum->ft->getNext(assocClassEnum, NULL);
					CMPIData data1 = data.value.inst->ft->getProperty (data.value.inst, role, rc);

					/* check if accocatedClass is associated with the request class and result class */
					className1 = CMGetClassName (cop, rc);
					className2 = CMGetClassName (data1.value.ref, rc);
					if (0 != strcmp (CMGetCharPtr (className1), 
									 CMGetCharPtr (className2)))
					{ 
						CMRelease (className1);
						CMRelease (className2);
						continue; 
					}

					CMRelease (className1);
					CMRelease (className2);

					reqInst  = getInstance (mb, data1.value.ref, 0, NULL, rc);
					oldInst  = getInstance (mb, cop, 0, NULL, rc);
					if (0 == cmpInst (reqInst, oldInst))
					{
						/* create a instance of associated class and add 
						   the instance list/array */
						inst		  = CMClone (data.value.inst, rc);
						simpleArrayAdd (array, (CMPIValue*)&inst, CMPI_instance);
					}
					if (reqInst) { CMRelease (reqInst); }
					if (oldInst) { CMRelease (oldInst); }

				}
				enumeration = newCMPIEnumeration (array, rc);
				CMRelease (assocClassEnum);
			}
			CMRelease (objectPath);
		}
		else
		{
			setWsmanError (enumDoc, rc);
			enumeration = NULL;
		}

		if (faultCode) u_free (faultCode);
	}


	ws_xml_destroy_doc (enumDoc);
	wsmc_options_destroy (options);
	destroyEPR (epr);
	filter_destroy (filter);

	return enumeration;
}

/**
 * referenceNames
 */
static CMPIEnumeration* 
referenceNames (CMCIClient* mb, CMPIObjectPath* cop, const char* resultClass, const char * role,
																			  CMPIStatus * rc)
{
	WsManClient*		cl;
	client_opt_t*		options;
	CMPIEnumeration*	enumeration;
	CMPIObjectPath*		enumCop;
	WsXmlDocH			enumDoc;
	WsXmlDocH			doc;
	WsXmlNodeH			node;
	char*				enumContext;
	CMPIArray*			array;
	epr_t*				epr;
	filter_t*			filter;
	char				objectUri [MAX_OBJECT_URI_LENGTH + 1];

	enumeration = NULL;
	getObjectUri (cop, objectUri);

	cl		= ((ClientEnc*)mb)->wsmanClient;
	options = wsmc_options_init ();

	/* set the name space */
	setCIMNameSpace (cop, options);

	/* set to enumerate epr/objectpath */
	wsmc_set_action_option(options, FLAG_ENUMERATION_ENUM_EPR);


	/* get the keys from object path and set it to wsman epr */
	epr = createEPR (cop, objectUri, rc);

	/* create association filter */
	filter = filter_create_assoc (epr, 1, NULL, resultClass, role, NULL, NULL, 0 );

	/* enumerate the instance */
	enumDoc = wsmc_action_enumerate (cl, CIM_ALL_AVAILABLE_CLASSES, options, filter);
	if (!enumDoc) 
	{
		setHttpError (rc, cl);
		wsmc_options_destroy (options);
		destroyEPR (epr);
		filter_destroy (filter);
		return NULL;
	}

	WSMAN_DUMP_NODE_TREE (enumDoc);

	if (WSMAN_SUCCESS (cl, enumDoc))
	{
		array		= newCMPIArray (0, CMPI_ref, NULL);
		enumContext = wsmc_get_enum_context (enumDoc);

		/* start enumeration */
		while (enumContext != NULL && enumContext[0] != 0) 
		{
			doc = wsmc_action_pull (cl, CIM_ALL_AVAILABLE_CLASSES, options, NULL, enumContext);
			if (!doc) 
			{
				setHttpError (rc, cl);
				break;
			}

			WSMAN_DUMP_NODE_TREE (doc);

			if (!WSMAN_SUCCESS (cl, doc))	
			{
				ws_xml_destroy_doc (doc);
				u_free (enumContext); 
				break; 
			}

			node = ws_xml_get_doc_root (doc);
			/* add the properties to the instance from the enumeration response node */
			if (0 == addKeysToObjectPath (&enumCop, node))
			{
				/* add the objectpath to the objectpath list/array */
				simpleArrayAdd (array, (CMPIValue*)&enumCop, CMPI_ref);
			}

			u_free (enumContext);
			enumContext = wsmc_get_enum_context (doc);
			
			if (doc) {	ws_xml_destroy_doc (doc); }
		}

		enumeration = newCMPIEnumeration (array, rc);
	}
	else
	{
		/* 
		  if association filter is not supported then try a different menthod, enumetare 
		  the associated class and then find the instances that match the request class and result class 
		 */
		char* faultCode = getWsmanFaultCode (enumDoc);
		if ((faultCode != NULL) && 
			((0 == strcmp ("wsen:FilterDialectRequestedUnavailable", faultCode))  || 
			 (0 == strcmp ("wsen:CannotProcessFilter", faultCode))  || 
			 (0 == strcmp ("wsman:UnsupportedFeature", faultCode))) &&
			(resultClass != NULL) && (role != NULL))
		{
			CMPIEnumeration*	assocClassEnum;
			CMPIObjectPath*		objectPath;

			/* enumerate the result class */
			objectPath		= newCMPIObjectPath(NULL, resultClass, NULL);
			assocClassEnum	= mb->ft->enumInstances (mb, objectPath, 0, NULL, rc);
			if (assocClassEnum != NULL)
			{
				array		= newCMPIArray (0, CMPI_ref, rc);
				while (assocClassEnum->ft->hasNext(assocClassEnum, NULL)) 
				{
					CMPIObjectPath* newCop;
					int				propertyCount;
					int				i;
					CMPIString*		className1;
					CMPIString*		className2;
					CMPIInstance*	reqInst;
					CMPIInstance*	oldInst;

					CMPIData data  = assocClassEnum->ft->getNext(assocClassEnum, NULL);
					CMPIData data1 = data.value.inst->ft->getProperty (data.value.inst, role, rc);

					/* check if accocatedClass is associated with the request class and result class */
					className1 = CMGetClassName (cop, rc);
					className2 = CMGetClassName (data1.value.ref, rc);
					if (0 != strcmp (CMGetCharPtr (className1), 
									 CMGetCharPtr (className2)))
					{ 
						CMRelease (className1);
						CMRelease (className2);
						continue; 
					}

					CMRelease (className1);
					CMRelease (className2);

					reqInst  = getInstance (mb, data1.value.ref, 0, NULL, rc);
					oldInst  = getInstance (mb, cop, 0, NULL, rc);
					if (0 == cmpInst (reqInst, oldInst))
					{
						/* create a objectpath to this instance of associated class and add 
						   the objectpath list/array */
						newCop		  = CMGetObjectPath (data.value.inst, rc);
						propertyCount = CMGetPropertyCount (data.value.inst, rc);
						for (i = 0; i < propertyCount; i++)
						{
							CMPIString* name;
							CMPIData  value = CMGetPropertyAt (data.value.inst, i, &name, rc);
							if (value.type == CMPI_ref)
							{
								CMAddKey (newCop, CMGetCharPtr (name), &value.value, CMPI_ref); 
							}
							CMRelease (name);
						}
						simpleArrayAdd (array, (CMPIValue*)&newCop, CMPI_ref);
					}
					if (reqInst) { CMRelease (reqInst); }
					if (oldInst) { CMRelease (oldInst); }
				}
				enumeration = newCMPIEnumeration (array, rc);
				CMRelease (assocClassEnum);
			}
			CMRelease (objectPath);
		}
		else
		{
			setWsmanError (enumDoc, rc);
			enumeration = NULL;
		}

		if (faultCode) u_free (faultCode);
	}

	ws_xml_destroy_doc (enumDoc);
	wsmc_options_destroy (options);
	destroyEPR (epr);
	filter_destroy (filter);

	return enumeration;
}

/**
 * invokeMethod
 */
CMPIData 
invokeMethod (CMCIClient* mb, CMPIObjectPath* cop, const char* method, CMPIArgs* in, 
												   CMPIArgs* out, CMPIStatus* rc)
{
	WsManClient*	cl;
	client_opt_t*	options;
	CMPIData		data = {0};
	WsXmlDocH		doc;
	WsXmlNodeH		node;
	CMPIValue		value;
	int				keyCount;
	int				argCount;
	KeyNameValue_T*	keys;
	ArgNameValue_T*	args;
	char			objectUri [MAX_OBJECT_URI_LENGTH + 1];

	getObjectUri (cop, objectUri);

	cl		= ((ClientEnc*)mb)->wsmanClient;;
	options = wsmc_options_init ();

	/* set the name space */
	setCIMNameSpace (cop, options);

	/* get the keys and args from object path and args and set it to wsman option */
	keyCount = CMGetKeyCount (cop, rc);
	keys	 = NULL;
	if (keyCount != 0)
	{
		if (NULL == (keys = malloc (sizeof (KeyNameValue_T) * keyCount))) 
		{
			wsmc_options_destroy (options);
			CMSetStatusWithChars (rc, CMPI_RC_ERR_FAILED, "Error allocating memory\n");
			data.type	= CMPI_null;
			return data; 
		}
		addKeysToOption (cop, options, keys, rc);
	}
	argCount = CMGetArgCount (in, rc);
	args	 = NULL;
	if (argCount != 0)
	{
		if (NULL == (args = malloc (sizeof (ArgNameValue_T) * argCount)))
		{
			wsmc_options_destroy (options);
			CMSetStatusWithChars (rc, CMPI_RC_ERR_FAILED, "Error allocating memory\n");
			data.type	= CMPI_null;
			return data; 
		}
		addArgsToOption (in, options, args, rc);
	}

	/* perform the action / invoke the method */
	doc = wsmc_action_invoke (cl, objectUri, options, method, NULL);
	if (!doc) 
	{
		setHttpError (rc, cl);
		data.type	= CMPI_null;
	}
	else
	{

		WSMAN_DUMP_NODE_TREE (doc);

		if (WSMAN_SUCCESS (cl, doc))
		{
			node		= ws_xml_find_in_tree (ws_xml_get_doc_root (doc), objectUri, "ReturnValue", 1);
			if (NULL != node)
			{
				value		= str2CMPIValue (CMPI_string, ws_xml_get_node_text (node), NULL);
				data.value	= value;
				data.state	= CMPI_goodValue;
				data.type	= CMPI_string;

				/* add the properties to instance from the response node/doc */
				node = ws_xml_get_soap_body (doc);
				addArgumentsToArgs (&out, node);
			}
			else
			{
				setWsmanError (doc, rc);
				data.type	= CMPI_null;
			}
		}
		else
		{
			setWsmanError (doc, rc);
			data.type	= CMPI_null;
		}
		ws_xml_destroy_doc(doc);
	}

	wsmc_options_destroy(options);
	releaseKeys (keys, keyCount);
	releaseArgs (args, argCount);

	return data;
}

/**
 * setProperty
 */
static CMPIStatus 
setProperty (CMCIClient* mb, CMPIObjectPath* cop, const char* name, CMPIValue* value, CMPIType type)
{
	WsManClient*	cl;
	client_opt_t*	options;
	WsXmlDocH		doc;
	CMPIStatus		rc;
	int				keyCount;
	KeyNameValue_T*	keys;
	char			objectUri [MAX_OBJECT_URI_LENGTH + 1];
	char*			propertyValue = NULL;
	char**			propertyValues = NULL;
	int				jj;
	int				numElements = 0;

	getObjectUri (cop, objectUri);

	cl		= ((ClientEnc*)mb)->wsmanClient;;
	options = wsmc_options_init ();

	/* set the name space */
	setCIMNameSpace (cop, options);

	/* get the keys from object path and set it to wsman option */
	keyCount = CMGetKeyCount (cop, &rc);
	keys	 = NULL;
	if (keyCount != 0)
	{
		if (NULL == (keys = malloc (sizeof (KeyNameValue_T) * keyCount))) 
		{
			wsmc_options_destroy (options);
			CMSetStatusWithChars (&rc, CMPI_RC_ERR_FAILED, "Error allocating memory\n");
			return rc; 
		}
		addKeysToOption (cop, options, keys, &rc);
	}

	/* add the property to set */
	if (type == CMPI_ARRAY)
	{
		CMPIArray*	array;
		int			j;

		array			= value->array;
		numElements		= CMGetArrayCount (array, &rc);
		propertyValues	= malloc (numElements * sizeof (char*));
		if (NULL == propertyValues) 
		{
			CMSetStatusWithChars (&rc, CMPI_RC_ERR_FAILED, "Error allocating memory\n");
			return rc; 
		}
		memset (propertyValues, 0, numElements * sizeof (char*));
		if (numElements == 0)
		{
			wsmc_add_property (options, name, NULL);
		}
		else
		{
			for (j = 0; j < numElements; j++)
			{
				char* _charValue;
				CMPIData value	= CMGetArrayElementAt (array, j, &rc);
				_charValue	= value2Chars (value.type, &value.value);
				wsmc_add_property (options, name, _charValue);
				propertyValues [j] = _charValue;
			}
		}
	}
	else
	{
		propertyValue	= value2Chars (type, value);
		wsmc_add_property (options, name, propertyValue);
	}

	/* perform the action / set the property */
	doc = wsmc_action_get_and_put (cl, objectUri, options);
	if (propertyValue) { free (propertyValue); }
	
	/* free the memory */
	if (type == CMPI_ARRAY)
	{
		for (jj = 0; jj < numElements; jj++)
		{
			if (propertyValues[jj])
			{ 
				free (propertyValues[jj]);
			}
		}
		
		{
			if (propertyValues) { free (propertyValues); }
		}
	}
	else
	{
		if (propertyValues) { free (propertyValues); }
	}

	if (!doc) 
	{
		setHttpError (&rc, cl);
	}
	else
	{
		WSMAN_DUMP_NODE_TREE (doc);

		/* set the status */
		if (WSMAN_SUCCESS (cl, doc)) { CMSetStatus(&rc, CMPI_RC_OK);   }
		else						 { setWsmanError (doc, &rc);       }

		ws_xml_destroy_doc(doc);
	}

	wsmc_options_destroy(options);
	releaseKeys (keys, keyCount);

	return rc;
}

/**
 * getProperty
 */
static CMPIData 
getProperty (CMCIClient* mb, CMPIObjectPath* cop, const char* name, CMPIStatus* rc)
{
	WsManClient*	cl;
	client_opt_t*	options;
	WsXmlDocH		doc;
	WsXmlNodeH		node;
	CMPIValue		value;
	CMPIData		data = {0};
	int				keyCount;
	KeyNameValue_T*	keys;
	char			objectUri [MAX_OBJECT_URI_LENGTH + 1];

	getObjectUri (cop, objectUri);

	rc->rc = 0;
	rc->msg = NULL;
	
	cl		= ((ClientEnc*)mb)->wsmanClient;;
	options = wsmc_options_init ();

	/* set the name space */
	setCIMNameSpace (cop, options);

	/* get the keys from object path and set it to wsman option */
	keyCount = CMGetKeyCount (cop, rc);
	keys	 = NULL;
	if (keyCount != 0)
	{
		if (NULL == (keys = malloc (sizeof (KeyNameValue_T) * keyCount))) 
		{
			wsmc_options_destroy (options);
			CMSetStatusWithChars (rc, CMPI_RC_ERR_FAILED, "Error allocating memory\n");
			data.type	= CMPI_null;
			return data; 
		}
		addKeysToOption (cop, options, keys, rc);
	}

	/* perform the action / get the property */
	doc = wsmc_action_get (cl, objectUri, options);
	if (!doc) 
	{
		setHttpError (rc, cl);
	}
	else
	{
		WSMAN_DUMP_NODE_TREE (doc);

		if (WSMAN_SUCCESS (cl, doc))
		{
			node		= ws_xml_find_in_tree (ws_xml_get_doc_root (doc), objectUri, name, 1);
			value		= str2CMPIValue (CMPI_string, ws_xml_get_node_text (node), NULL);
			data.value	= value;
			data.type	= CMPI_string;
		}
		else
		{
			setWsmanError (doc, rc);
			data.type	= CMPI_null;
		}

		ws_xml_destroy_doc (doc);
	}

	wsmc_options_destroy (options);
	releaseKeys (keys, keyCount);

	return data;
}

/**
 * subscribeEvent
 */
static char*
subscribeEvent (CMCIClient* mb, CMPIObjectPath *cop, const char*	eventDeliveryUri, int mode, float	heartbeat, float expires,
				const char*	dialect, const char* query, CMPIStatus * rc)
{
	WsManClient*	cl;
	client_opt_t*	options;
	WsXmlDocH		doc;
	WsXmlNodeH		node;
	filter_t*		filter;
	char*			uuid = NULL;
	int				keyCount;
	KeyNameValue_T*	keys;
	char			objectUri [MAX_OBJECT_URI_LENGTH + 1];

	getObjectUri (cop, objectUri);

	rc->rc = 0;
	rc->msg = NULL;
	
	cl		= ((ClientEnc*)mb)->wsmanClient;;
	options = wsmc_options_init ();

	/* set the name space */
	setCIMNameSpace (cop, options);

	/* get the keys from object path and set it to wsman option */
	keyCount = CMGetKeyCount (cop, rc);
	keys	 = NULL;
	if (keyCount != 0)
	{
		if (NULL == (keys = malloc (sizeof (KeyNameValue_T) * keyCount))) 
		{
			wsmc_options_destroy (options);
			CMSetStatusWithChars (rc, CMPI_RC_ERR_FAILED, "Error allocating memory\n");
			return NULL; 
		}
		addKeysToOption (cop, options, keys, rc);
	}

	/* set wsman options */
	options->delivery_mode		= mode;
	options->heartbeat_interval = heartbeat;
	options->expires			= expires;
	options->delivery_uri		= eventDeliveryUri ? strdup (eventDeliveryUri) : NULL; 

	/* create the filter */
	filter = filter_create_simple (dialect, query);


	/* perform the action / subscrib */ 
	doc = wsmc_action_subscribe (cl, objectUri, options, filter);
	if (!doc) 
	{
		setHttpError (rc, cl);
	}
	else
	{
		WSMAN_DUMP_NODE_TREE (doc);
		if (WSMAN_SUCCESS (cl, doc))
		{
			node	= ws_xml_find_in_tree (ws_xml_get_doc_root (doc), XML_NS_EVENTING, "Identifier", 1);
			uuid    = strdup (ws_xml_get_node_text (node)==NULL?"":ws_xml_get_node_text (node));
		}
		else
		{
			setWsmanError (doc, rc);
		}

		ws_xml_destroy_doc(doc);
	}

	wsmc_options_destroy(options);
	releaseKeys (keys, keyCount);
	filter_destroy (filter);

	return uuid;
}


/**
 * subscribeEvent
 */
static char*
subscribeToEvent (CMCIClient* mb, CMPIObjectPath *cop, char **params, CMPIStatus * rc)
{

	WsManClient*	cl;
	client_opt_t*	options;
	WsXmlDocH		doc;
	WsXmlNodeH		node;
	filter_t*		filter;
	char*			uuid = NULL;
	int				keyCount;
	KeyNameValue_T*	keys;
	char			objectUri [MAX_OBJECT_URI_LENGTH + 1];
	char *endRef;
	int paramPosition = 0;
	char *dialect, *query;

	getObjectUri (cop, objectUri);
	rc->rc = 0;
	rc->msg = NULL;
	
	cl		= ((ClientEnc*)mb)->wsmanClient;;
	options = wsmc_options_init ();

	/* set the name space */
	setCIMNameSpace (cop, options);

	/* get the keys from object path and set it to wsman option */
	keyCount = CMGetKeyCount (cop, rc);
	keys	 = NULL;
	if (keyCount != 0)
	{
		if (NULL == (keys = malloc (sizeof (KeyNameValue_T) * keyCount))) 
		{
			wsmc_options_destroy (options);
			CMSetStatusWithChars (rc, CMPI_RC_ERR_FAILED, "Error allocating memory\n");
			return NULL; 
		}
		addKeysToOption (cop, options, keys, rc);
	}

	/* set wsman options */
	options->delivery_uri		= params[paramPosition] ? strdup (params[paramPosition]) : NULL; 
	options->delivery_mode	= strtol(params[++paramPosition],&endRef,10);
	options->endto_uri = params[++paramPosition] ? strdup (params[paramPosition]) : NULL; 
	options->expire_time = params[++paramPosition] ? strdup (params[paramPosition]) : NULL;
	options->encode_type = params[++paramPosition] ? strdup (params[paramPosition]) : NULL;

	// Locale
	options->locale = params[++paramPosition] ? strdup (params[paramPosition]) : NULL;
	
	//Bookmarks
	options->bookmarks = params[++paramPosition] ? 0 : 1;

	//Heartbeat interval
	options->hrtbt_interval = params[++paramPosition] ? strdup (params[paramPosition]) : NULL;

	//Connection retry count
	options->conn_retrycount = params[++paramPosition] ? atoi(params[paramPosition]) : 0;

	/* Dialect and Query parameters used only when CQL/WQL based query subscription performed. */
	dialect = params[++paramPosition];
	query = params[++paramPosition];
	filter = filter_create_simple (dialect, query);

	/* perform the action / subscrib */ 
	doc = wsmc_action_subscribe (cl, objectUri, options, filter);
	if (!doc) 
	{
		setHttpError (rc, cl);
	}
	else
	{
		WSMAN_DUMP_NODE_TREE (doc);
		if (WSMAN_SUCCESS (cl, doc))
		{
			node	= ws_xml_find_in_tree (ws_xml_get_doc_root (doc), XML_NS_EVENTING, "Identifier", 1);
			uuid    = strdup (ws_xml_get_node_text (node)==NULL?"":ws_xml_get_node_text (node));
		}
		else
		{
			setWsmanError (doc, rc);
		}

		ws_xml_destroy_doc(doc);
	}

	wsmc_options_destroy(options);
	releaseKeys (keys, keyCount);
	filter_destroy (filter);

	return uuid;
}


/**
 * unsubscribeEvent
 */
static CMPIStatus
unsubscribeEvent (CMCIClient* mb, CMPIObjectPath *cop)
{
	WsManClient*	cl;
	client_opt_t*	options;
	WsXmlDocH		doc;
	WsXmlNodeH		node;
	CMPIStatus		rc;
	int				keyCount;
	KeyNameValue_T*	keys;

	rc.rc = 0;
	rc.msg = NULL;
	
	cl		= ((ClientEnc*)mb)->wsmanClient;;
	options = wsmc_options_init();

	/* set the name space */
	//setCIMNameSpace (cop, options);

	/* get the keys from object path and set it to wsman option */
	keyCount = CMGetKeyCount (cop, &rc);
	keys	 = NULL;
	if (keyCount != 0)
	{
		if (NULL == (keys = malloc (sizeof (KeyNameValue_T) * keyCount))) 
		{
			wsmc_options_destroy (options);
			CMSetStatusWithChars (&rc, CMPI_RC_ERR_FAILED, "Error allocating memory\n");
			CMSetStatus(&rc, CMPI_RC_ERR_FAILED);
			return rc;
		}
		addKeysToOption (cop, options, keys, &rc);
	}
	doc = wsmc_action_unsubscribe (cl, CMGetCharsPtr(CMGetClassName(cop, &rc),&rc), options, NULL);
	if (!doc) 
	{
		setHttpError (&rc, cl);
	}
	else
	{

		WSMAN_DUMP_NODE_TREE (doc);

		if (WSMAN_SUCCESS (cl, doc))
		{
			node	= ws_xml_find_in_tree (ws_xml_get_doc_root (doc), XML_NS_WS_MAN, "Identifier", 1);
			CMSetStatus(&rc, CMPI_RC_OK);
		}
		else
		{
			setWsmanError (doc, &rc);
		}

		ws_xml_destroy_doc(doc);
	}

	wsmc_options_destroy(options);
	return rc;
}

/**
 * renewSubscription
 */
static CMPIStatus
renewSubscription (CMCIClient* mb, CMPIObjectPath *cop,const char* renewtime)
{
	WsManClient*	cl;
	client_opt_t*	options;
	WsXmlDocH		doc;
	CMPIStatus		rc;
	int				keyCount;
	KeyNameValue_T*	keys;
	
	char			objectUri [MAX_OBJECT_URI_LENGTH + 1];

	getObjectUri (cop, objectUri);

	rc.rc = 0;
	rc.msg = NULL;
	
	cl		= ((ClientEnc*)mb)->wsmanClient;;
	options = wsmc_options_init();

	options->renewtime = renewtime ? strdup (renewtime) : "0";

	/* get the keys from object path and set it to wsman option */
	keyCount = CMGetKeyCount (cop, &rc);
	keys	 = NULL;
	if (keyCount != 0)
	{
		if (NULL == (keys = malloc (sizeof (KeyNameValue_T) * keyCount))) 
		{
			wsmc_options_destroy (options);
			CMSetStatusWithChars (&rc, CMPI_RC_ERR_FAILED, "Error allocating memory\n");
			CMSetStatus(&rc, CMPI_RC_ERR_FAILED);
			return rc;
		}
		addKeysToOption (cop, options, keys, &rc);
	}

	doc = wsmc_action_renew (cl, objectUri, options, NULL);
	if (!doc) 
	{
		setHttpError (&rc, cl);
	}
	else
	{
		WSMAN_DUMP_NODE_TREE (doc);
		if (WSMAN_SUCCESS (cl, doc)) { CMSetStatus(&rc, CMPI_RC_OK); }
		else						 { setWsmanError (doc, &rc);		}

		ws_xml_destroy_doc(doc);
	}

	wsmc_options_destroy(options);

	return rc;
}

/*
 * A structure to hold event receiver call back function pointer and data
 */
typedef struct
{
	fpWsmcEventReceiver_T	fpCallBack;
	void*					data;

} EventReceiverCallbackData_T;

/**
 * eventReceiver
 */
static int
eventReceiver (WsXmlDocH indoc,void* data,char* ip_addr)
{
	WsXmlNodeH			node;
	WsXmlNodeH			classNode;
	WsXmlNodeH			actionNode;
	char*				className;
	int					childCount;
	int					i;
	EventData_T*		eventData = NULL;
	EventReceiverCallbackData_T*	pCallbackData;
	int					isHeartBeat = 0;
	int					ret = -1;

	actionNode  = ws_xml_get_soap_header(indoc);
	childCount =  ws_xml_get_child_count(actionNode);

	for (i = 0; i < childCount; i++)
	{
		WsXmlNodeH	childNode;
		char*				nodeName;
		char*				nodeValue;

		childNode			= ws_xml_get_child (actionNode, i, NULL, NULL);
		nodeName  = ws_xml_get_node_local_name (childNode);
		nodeValue = ws_xml_get_node_text (childNode);
		if (strcmp (nodeName, "Action") == 0
			&& strcmp (nodeValue, "http://schemas.dmtf.org/wbem/wsman/1/wsman/Heartbeat") == 0)	{

			eventData   = malloc (sizeof (EventData_T) * (3));
			if (eventData == NULL) { return ret; }

			eventData [0].name  = "SystemName";
			eventData [0].value = ip_addr;

			eventData [1].name  = "AlertType";
			eventData [1].value = "HeartBeat";
		
			eventData [2].name = '\0';
			isHeartBeat = 1;

			break;
		}
	}

	if(isHeartBeat == 0)	{
		node		= ws_xml_get_soap_body (indoc);
		classNode	= ws_xml_get_child (node, 0, NULL, NULL);
		className	= ws_xml_get_node_local_name (classNode);

		childCount	= ws_xml_get_child_count (classNode);
		eventData   = malloc (sizeof (EventData_T) * (childCount + 1));
		if (eventData == NULL) { return ret; }

		for (i = 0; i < childCount; i++)
		{
			WsXmlNodeH	childNode;

			childNode			= ws_xml_get_child (classNode, i, NULL, NULL);
			eventData [i].name  = ws_xml_get_node_local_name (childNode);
			eventData [i].value = ws_xml_get_node_text (childNode);
			if (strcmp (eventData [i].name, "SystemName") == 0)
			{
				if ((eventData [i].value, '\0') == 0)
				{
					eventData[i].value = ip_addr;
				}
			}
		}
		eventData [i].name = '\0';
	}

	/* call the call back function */
	pCallbackData = (EventReceiverCallbackData_T*)data;
	ret			  = pCallbackData->fpCallBack (eventData, pCallbackData->data);

	free (eventData);

	return ret;
}

/**
 * cmciStartEventReceiver
 */
void* 
cmciStartEventReceiver (int	port, const char*	servicePath, fpWsmcEventReceiver_T	callBack, void* data)
{

	EventReceiverCallbackData_T* pCallbackData = 
			(EventReceiverCallbackData_T*)malloc (sizeof (EventReceiverCallbackData_T));
	if (pCallbackData == NULL)
	{
		return NULL;
	}
	pCallbackData->fpCallBack = callBack;
	pCallbackData->data		  = data;

    /* register and start listening for events */
	wsevent_start (port, servicePath, eventReceiver, pCallbackData);

	return pCallbackData;
}

/**
 * cmcmStopEventReceiver
 */
int 
cmciStopEventReceiver (void* handle)
{

    /* stop listening for events */
	wsevent_stop ();
	if (handle) { free (handle); }

	return 0;
}

/**
 * getClass 
 */
static CMPIConstClass* 
getClass (CMCIClient* mb, CMPIObjectPath* cop, CMPIFlags flags, char** properties, CMPIStatus * rc)
{
	/** this function is not supported */
	CMSetStatus (rc, CMPI_RC_METHOD_NOT_IMPLEMENTED);
	return NULL;
}

/**
 * enumClassNames
 */
static CMPIEnumeration* 
enumClassNames (CMCIClient* mb, CMPIObjectPath* cop, CMPIFlags flags, CMPIStatus* rc)
{
	/** this function is not supported */
	CMSetStatus (rc, CMPI_RC_METHOD_NOT_IMPLEMENTED);
	return NULL;
}


/**
 * enumClasses 
 */
static CMPIEnumeration* 
enumClasses (CMCIClient* mb, CMPIObjectPath* cop, CMPIFlags flags, CMPIStatus* rc)
{
	/** this function is not supported */
	CMSetStatus (rc, CMPI_RC_METHOD_NOT_IMPLEMENTED);
	return NULL;
}

/**
 * cloneClient 
 */
static CMCIClient* cloneClient ( CMCIClient * cl, CMPIStatus * rc)
{
	/** this function is not implemented */
	CMSetStatus (rc, CMPI_RC_METHOD_NOT_IMPLEMENTED);
	return NULL;
}

/**
 * releaseClient
 */
static CMPIStatus releaseClient (CMCIClient * mb)
{
	CMPIStatus rc;
	ClientEnc* cl = (ClientEnc*)mb;

	if (cl->wsmanClient->authentication.method) u_free (cl->wsmanClient->authentication.method);
	wsmc_release (cl->wsmanClient);
	if (cl->implementation_ns)	{ free (cl->implementation_ns); }
	if (cl->interop_ns)			{ free (cl->interop_ns);		}
	if (cl->enc.ft) { free (cl->enc.ft); }
	free (cl);

	if (g_wsman_dumpfile) { fclose (g_wsman_dumpfile); g_wsman_dumpfile = NULL;}

	CMSetStatus(&rc, CMPI_RC_OK);
	return rc;
}

/*
 * getHostName
 */
static char*
getHostName (CMCIClient* mb)
{
	ClientEnc* cl = (ClientEnc*)mb;
	return cl->wsmanClient->data.hostname;
}

/*
 * getPort
 */
static int
getPort (CMCIClient* mb)
{
	ClientEnc* cl = (ClientEnc*)mb;
	return cl->wsmanClient->data.port;
}

/*
 * getUser
 */
static char*
getUser (CMCIClient* mb)
{
	ClientEnc* cl = (ClientEnc*)mb;
	return cl->wsmanClient->data.user;
}

/*
 * getPassword
 */
static char*
getPassword (CMCIClient* mb)
{
	ClientEnc* cl = (ClientEnc*)mb;
	return cl->wsmanClient->data.pwd;
}

/*
 * getImplementationNS
 */
char*
getImplementationNS (CMCIClient* mb)
{
	ClientEnc* cl = (ClientEnc*)mb;
	return cl->implementation_ns;
}

/*
 * getInteropNS
 */
char*
getInteropNS (CMCIClient* mb)
{
	ClientEnc* cl = (ClientEnc*)mb;
	return cl->interop_ns;
}


/*
 * setTimeout
 */
void 
setTimeout (CMCIClient* mb, unsigned long timeout)
{
	ClientEnc* cl = (ClientEnc*)mb;
	wsman_transport_set_timeout (cl->wsmanClient, timeout);
	return;
}

/*
 * getTimeout
 */
unsigned long
getTimeout (CMCIClient* mb)
{
	ClientEnc* cl = (ClientEnc*)mb;
	return wsman_transport_get_timeout (cl->wsmanClient);
}

/**
 * clientFt
 */
static const CMCIClientFT clientFt = {
   NATIVE_FT_VERSION,
   releaseClient,
   cloneClient,
   getClass,
   enumClassNames,
   enumClasses,
   getInstance,
   createInstance,
   setInstance,
   deleteInstance,
   execQuery,
   enumInstanceNames,
   enumInstances,
   associators,
   associatorNames,
   references,
   referenceNames,
   invokeMethod,
   setProperty,
   getProperty,
   subscribeEvent,
   subscribeToEvent,
   unsubscribeEvent,
   renewSubscription,
   getHostName,
   getPort,
   getUser,
   getPassword,
   getImplementationNS,
   getInteropNS,
   setTimeout,
   getTimeout
};


/**
 * findSetNameSpace
 */
static int
findSetNameSpace (CMCIClient* mb, CMPIStatus* rc)
{
	WsManClient*		cl;
	client_opt_t*		options;
	CMPIInstance*		cci;
	WsXmlDocH			enumDoc = NULL;
	WsXmlDocH			doc = NULL;
	WsXmlNodeH			node = NULL;
	char*				enumContext;
	char*				classUri = "http://schemas.dmtf.org/wbem/wscim/1/cim-schema/2/CIM_ElementConformsToProfile";
	CMPIStatus			status;
	int					i;
	char*				ns[] = {NULL,
								"interop", 
								"root/interop", 
								"/interop",
								"/root/interop"
								};

	cl				= ((ClientEnc*)mb)->wsmanClient;
	options			= wsmc_options_init ();

	/* This loop searches the ECTP instance in the namespaces mentioned above,if the search succeed in any one
	   of the namespace,the loop will be exited*/
	for (i = 0; i < (sizeof (ns) / sizeof (char*)); i++)
	{

		/* set the name space */
		options->cim_ns = ((ns [i] != NULL) ? strdup (ns [i]) : NULL);
		/* enumerate the instance */
		enumDoc = wsmc_action_enumerate (cl, classUri, options, NULL);
		if (!enumDoc) 
		{
			setHttpError (rc, cl);
			wsmc_options_destroy (options);
			return -1;
		}

		WSMAN_DUMP_NODE_TREE (enumDoc);

		if (!WSMAN_SUCCESS (cl, enumDoc))
		{
			ws_xml_destroy_doc (enumDoc);
			if (options->cim_ns != NULL) { 
				free (options->cim_ns); 
				options->cim_ns = NULL; 
			}
			enumDoc = NULL;
		}
		else
		{
			break;
		}
	}

	if (i < (sizeof (ns)/sizeof (char*)))
	{
		enumContext = wsmc_get_enum_context (enumDoc);

		if (enumContext != NULL)
		{
			doc = wsmc_action_pull (cl, classUri, options, NULL, enumContext);
			if (!doc) 
			{
				u_free (enumContext);
				setHttpError (rc, cl);
			}
			else
			{
				WSMAN_DUMP_NODE_TREE (doc);

				if (WSMAN_SUCCESS (cl, doc))
				{
					node = ws_xml_find_in_tree (ws_xml_get_doc_root (doc), XML_NS_ENUMERATION, "Items", 1);
					/* add the properties to the instance from the enumeration response node */
					if (0 == addPropertiesToInstance (NULL, &cci, node,false))
					{
						CMPIObjectPath* me;
						CMPIObjectPath* cs;
						CMPIData		im_ns;
						CMPIData		interop_ns;
						/* get the implementation namespace */
						me		= cci->ft->getProperty (cci, "ManagedElement", &status).value.ref;
						if (status.rc == CMPI_RC_OK)
						{
							im_ns	= CMGetKey (me, "__cimnamespace", &status);
							if (status.rc == CMPI_RC_OK)
							{
								((ClientEnc*)mb)->implementation_ns	= strdup (CMGetCharPtr (im_ns.value.string));
								if (g_dump_wsman_data >= 1) 
								{ 
									fprintf (g_wsman_dumpfile, "Implementation NS = %s\n", CMGetCharPtr (im_ns.value.string));
								}
							}
						}
						/* get the interop namespace */
						cs			= cci->ft->getProperty (cci, "ConformantStandard", &status).value.ref;
						if (status.rc == CMPI_RC_OK)
						{
							interop_ns	= CMGetKey (cs, "__cimnamespace", &status);
							if (status.rc == CMPI_RC_OK)
							{
								((ClientEnc*)mb)->interop_ns	= strdup (CMGetCharPtr (interop_ns.value.string));
								if (g_dump_wsman_data >= 1) 
								{ 
									fprintf (g_wsman_dumpfile, "Interop NS        = %s\n", CMGetCharPtr (interop_ns.value.string));
								}
							}
						}
						CMRelease (cci);
					}
				}
			}
			u_free (enumContext);
			if (doc) {	ws_xml_destroy_doc (doc); }
		}
	}
	if (enumDoc) {	ws_xml_destroy_doc (enumDoc); }
	wsmc_options_destroy (options);

	return 0;
}


/*
 * xmlConnect2
 */
static CMCIClient*
xmlConnect2(CMCIEnv* env, const char* hn, const char* scheme, const char* port, 
			const char* user, const char* pwd, const char* auth, int verifyPeer, int verifyHost, 
			const char* caInfo, const char* caPath, const char* certFile, const char* keyFile, 
			const char* proxy, const char* proxyUser, const char* proxyPwd, unsigned long timeout, 
			CMPIStatus *rc)
{
	int		   wsmanPort;
	ClientEnc  *cc;

	if (port == NULL) { wsmanPort = 623; }
	else
	{
		char*	endptr;

		errno = 0;
		wsmanPort = strtol(port, &endptr, 10);
		if ((*port == '\0') || (*endptr != '\0') || (errno != 0))
		{
			CMSetStatus (rc, CMPI_RC_ERR_INVALID_PORT);
			return NULL;
		}
	}

	
	cc			= (ClientEnc*)calloc (1, sizeof (ClientEnc));
	cc->enc.ft  = (CMCIClientFT*)calloc (1, sizeof (CMCIClientFT));
	
	memcpy (cc->enc.ft, &clientFt, sizeof (CMCIClientFT));
	
	cc->wsmanClient = wsmc_create (hn, wsmanPort, "/wsman", scheme, user, pwd);
	if (cc->wsmanClient == NULL) 
	{
		CMSetStatus (rc, CMPI_RC_ERR_FAILED);
		return NULL;
	}

	wsmc_transport_init (cc->wsmanClient, (void*)NULL);

	wsman_transport_set_auth_method (cc->wsmanClient, auth);

	if (proxy) 
	{
		wsman_transport_set_proxy (cc->wsmanClient, proxy);
		if (proxyUser && proxyPwd) 
		{
			int   userLen;
			int	  pwdLen;
			char* proxyUserPwd;

			/* conver the user & password into "user:password" format */
			userLen		= (int)(proxyUser ? strlen (proxyUser) : 0); 
			pwdLen		= (int)(proxyPwd ? strlen (proxyPwd) : 0);
			proxyUserPwd	= malloc (userLen + pwdLen + 2);

			if (proxyUserPwd == NULL)
			{
				CMSetStatus(rc, CMPI_RC_ERR_FAILED);
				return (CMCIClient*)cc;
			}
			if (proxyUser) { memcpy (&proxyUserPwd [0], proxyUser, userLen); }
			proxyUserPwd [userLen] = ':';
			if (proxyPwd)  { memcpy (&proxyUserPwd [userLen + 1], proxyPwd, pwdLen ); }
			proxyUserPwd [userLen + pwdLen + 1] = '\0';

			if (userLen && pwdLen)
			{
				wsman_transport_set_proxyauth (cc->wsmanClient, proxyUserPwd);
			}
			
			free (proxyUserPwd);
		}
	}

	if (caInfo)		{ wsman_transport_set_cainfo (cc->wsmanClient, caInfo);	}
	if (caPath)		{ wsman_transport_set_capath (cc->wsmanClient, caPath);	}
	if (certFile)	{ wsman_transport_set_cert	 (cc->wsmanClient, certFile);}
	if (keyFile)	{ wsman_transport_set_key 	 (cc->wsmanClient, keyFile);	}
	wsman_transport_set_verify_peer (cc->wsmanClient, verifyPeer);
	wsman_transport_set_verify_host (cc->wsmanClient, verifyHost);
	wsman_transport_set_timeout (cc->wsmanClient, timeout);

	if (g_lapi_verbose_level >= 2)
	{ 
		g_dump_wsman_data = 1; 
		if (g_lapi_verbose_file != NULL)
		{
			g_wsman_dumpfile = fopen (g_lapi_verbose_file, "a+");
			if (NULL == g_wsman_dumpfile) 
			{
				g_dump_wsman_data = 0;
			}
		}
		else
		{
			g_wsman_dumpfile = stdout;
		}
	}

	/* find the implementation namespace and interop namespace */
	if (-1 == findSetNameSpace ((CMCIClient*)cc, rc))
	{
		releaseClient ((CMCIClient*)cc);
		return NULL;
	}
	else
	{
		CMSetStatus(rc, CMPI_RC_OK);
		return (CMCIClient*)cc;
	}
}

/*
 * xmlConnect
 */
static CMCIClient*
xmlConnect (CMCIEnv *env, const char *hn, const char *scheme, const char *port,
			 const char *user, const char *pwd, const char *auth, CMPIStatus *rc)
{
  return xmlConnect2(env, hn, scheme, port, user, pwd, auth, CMCI_VERIFY_PEER, 1, NULL, NULL,
					 NULL, NULL, NULL, NULL, NULL, 0, rc);
}

/*
 * releaseEnv
 */
static void*
releaseEnv (CMCIEnv *env)
{
	return NULL;
}

/*
 * newInstance
 */
static CMPIInstance* 
newInstance (CMCIEnv* ce, const CMPIObjectPath* op, CMPIStatus* rc)
{
   return newCMPIInstance((CMPIObjectPath*)op,rc);
}

/*
 * newString
 */
static CMPIString* 
newString (CMCIEnv* ce, const char* ptr, CMPIStatus* rc)
{
   return newCMPIString(ptr, rc);
}

/*
 * newObjectPath
 */
static CMPIObjectPath* 
newObjectPath (CMCIEnv* ce, const char* ns, const char* cn, CMPIStatus* rc)
{
   return newCMPIObjectPath(ns,cn,rc);
}

/*
 * newArgs
 */
static CMPIArgs* 
newArgs (CMCIEnv* ce, CMPIStatus* rc)
{
   return newCMPIArgs (rc);
}

/*
 * newArray
 */
static CMPIArray* 
newArray (CMCIEnv* ce, CMPICount max, CMPIType type, CMPIStatus* rc)
{
   return newCMPIArray (max, type, rc);
}

/*
 * newDateTime
 */
static CMPIDateTime* 
newDateTime (CMCIEnv* ce, CMPIStatus* rc) 
{
   return native_new_CMPIDateTime (rc); 
}

/*
 * newDateTimeFromBinary
 */
static CMPIDateTime* 
newDateTimeFromBinary (CMCIEnv* ce, CMPIUint64 binTime, CMPIBoolean interval, CMPIStatus *rc) 
{
   return native_new_CMPIDateTime_fromBinary (binTime,interval,rc); 
}

/*
 * newDateTimeFromChars
 */
static CMPIDateTime* 
newDateTimeFromChars (CMCIEnv* ce, const char* utcTime, CMPIStatus* rc) 
{
   return native_new_CMPIDateTime_fromChars (utcTime,rc); 
}

/**
 * localFT
 */
static const CMCIEnvFT localFT = {
  "WSMAN",
  releaseEnv,
  xmlConnect,
  xmlConnect2,     
  newInstance,      
  newObjectPath,
  newArgs,
  newString,
  newArray,
  newDateTime,
  newDateTimeFromBinary,
  newDateTimeFromChars,
};

const CMCIEnv wsmanEnvFT = { NULL, &localFT};

/**
 * getWSMANEnv
 */
const CMCIEnv* 
getWSMANEnv (void)
{
	return &wsmanEnvFT;
}
 
