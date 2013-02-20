/**
 * wsmanidentify.c
 * WSMan identify
 */
#include <wsman-client.h>
#include <wsman-client-api.h>
#include <wsman-client-transport.h>
#include <stdlib.h>
#include <string.h>
#include "cmci.h"
#include <wsman/wsmanidentify.h>


/**
  * Identify the WSMan server in the Given host
  * @ret 0 WSMan Server Found
  * @ret -1 WSMan Server Not Found
  */
int wsmanIdentify (const char *hostname, const char*username,const char*password,const char*auth,const char* scheme, int port, unsigned long timeout, WSMANIdentifyInfo_T* info)
{
	
    WsManClient *	cl;
    WsXmlDocH		doc;
    client_opt_t*	options = NULL;
	int				ret = 0;
	int			    childCount;
	int				i = 0 ;
	WsXmlNodeH	    identityNode1;

    if (username == NULL && password == NULL)
	{
		cl		= wsmc_create( hostname, port, "/wsman-anon/identify", scheme, "", "");
	}
	else
	{
		cl		= wsmc_create( hostname, port, "/wsman", scheme, username, password);
		wsman_transport_set_auth_method (cl, auth);
	}

    wsmc_transport_init(cl, NULL);
	wsman_transport_set_timeout (cl, timeout);
    options = wsmc_options_init();

    doc = wsmc_action_identify(cl, options);
	

	if (doc) 
	{		
		if (g_lapi_verbose_level >= 2) { ws_xml_dump_node_tree (stdout, ws_xml_get_doc_root(doc)); }

		identityNode1 = ws_xml_find_in_tree (ws_xml_get_doc_root (doc), XML_NS_WSMAN_ID, "ProtocolVersion", 1); 
		if (identityNode1 != NULL)
		{
			if (info != NULL)
			{
				WsXmlNodeH	    node;

				/* get the wsman information */
				node				  = ws_xml_find_in_tree (ws_xml_get_doc_root (doc), XML_NS_WSMAN_ID, "ProtocolVersion", 1); 
				info->protocolVersion = strdup(ws_xml_get_node_text (node));

				node				  = ws_xml_find_in_tree (ws_xml_get_doc_root (doc), XML_NS_WSMAN_ID, "ProductVendor", 1); 
				info->productVendor   = strdup(ws_xml_get_node_text (node));

				node				  = ws_xml_find_in_tree (ws_xml_get_doc_root (doc), XML_NS_WSMAN_ID, "ProductVersion", 1); 
				info->productVersion  = strdup(ws_xml_get_node_text (node));

				node				  = ws_xml_find_in_tree (ws_xml_get_doc_root (doc), "http://schemas.dmtf.org/wbem/dash/1/dash.xsd", "DASHVersion", 1); 
				info->dashVersion	  = strdup(ws_xml_get_node_text (node));

				node       = ws_xml_find_in_tree (ws_xml_get_doc_root (doc), XML_NS_WSMAN_ID, "SecurityProfiles", 1);
				childCount = ws_xml_get_child_count (node);
				for (i = 0; ((i < childCount) && (i < WSMAN_IDENTIFY_MAX_SECURITY_PROFILES)); i++)
				{
					WsXmlNodeH profileNameNode;
					profileNameNode = ws_xml_get_child (node, i, NULL, NULL);
					info->securityProfileName [i] = strdup (ws_xml_get_node_text (profileNameNode));
				}
			 }
			ret = 0; 
		} 
		
		if (doc) { ws_xml_destroy_doc(doc); }
	}
	else
	{
		ret = -1;
	}

	u_free (cl->authentication.method);
	wsmc_options_destroy (options);
	wsmc_release (cl);

	return ret;
}
