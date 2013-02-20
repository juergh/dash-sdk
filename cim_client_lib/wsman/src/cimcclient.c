/**
 * @file cimcclient.c
 * @brief Low level connection API's
 */


#include <wsman-client.h>
#include "cimc.h"
#include "cmci.h"

extern const CMCIEnv* getWSMANEnv(void);

/**
 * cmci_init
 */
int
cmci_init (void)
{
	/* initialize openwsman library which is needed to initialize libxml2 */
	wsmc_init ();

	return 0;
}

/**
 * cmci_cleanup
 */
int
cmci_cleanup (void)
{
	/* Cleanup openwsman library which is needed to cleanup libxml2 */
	wsmc_cleanup ();
	return 0;
}


/**
 * cmciRelease
**/
CMPIStatus 
cmciRelease(CMCIClient* cmciClient)
{
	CMPIStatus rc;

	cmciClient->ft->release (cmciClient);

	CMSetStatus(&rc, CMPI_RC_OK);
	return rc;
}

/**
 * cmciConnect2
**/
CMCIClient *cmciConnect2 (const char *hn, const char *scheme, const char *port,
                        const char *user, const char *pwd, const char* auth,
                        int verifyPeer, int verifyHost, const char* caInfo, const char* caPath,
                        const char* certFile, const char* keyFile, const char* proxy, 
                        const char* proxyUser, const char* proxyPwd, unsigned long timeout, 
                        CMPIStatus *rc)
{

	CMCIClient*		cmciClient;

	CMCIEnv* ccEnv = (CMCIEnv*)getWSMANEnv ();
	if (ccEnv == NULL)
	{
		if(rc) 
		{
			rc->rc	= CMPI_RC_ERR_FAILED;
			rc->msg	= NULL;
		}
		cmciClient = NULL;
	}
	else
	{
		cmciClient = (CMCIClient*)ccEnv->ft->connect2 (ccEnv, 
												hn, scheme, port, user, pwd, auth, verifyPeer, 
												verifyHost, caInfo, caPath, certFile, keyFile, proxy,
												proxyUser, proxyPwd, timeout, rc);	
	}

	return cmciClient;
}


/**
 * cmciConnect
**/
CMCIClient *cmciConnect(const char *hn, const char *scheme, const char *port,
                        const char *user, const char *pwd, const char *auth, CMPIStatus *rc)
{
	return cmciConnect2 (hn, scheme, port, user, pwd, auth, 1, 1, NULL, NULL, NULL, NULL,
						NULL, NULL, NULL, 0, rc);
}

