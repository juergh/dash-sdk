/**
 * dashping.h
 */
#ifndef __DASHPING_H__
#define __DASHPING_H__
#include <cmci/cmci.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "wsmanidentify.h"

CMCI_Export int dashPing   (const char*				hostname,
							const char*				username,
							const char*				password,
							const char*			    auth,
							const char*				scheme,
							int 					port,
							unsigned long			timeout,
							WSMANIdentifyInfo_T*	wsmaninfo);

CMCI_Export int inet_pton (int af, const char* src, void* dest);

#ifdef __cplusplus
}
#endif

// Error codes 
#define DLAPI_E_INVALID_ARG					(-2)
#define DLAPI_E_SOCKET_FAILED				(-3)
#define DLAPI_E_INVALID_HOSTNAME			(-4)
#define DLAPI_E_UNABLE_TO_OPEN_RMCP_PORT	(-5)
#define DLAPI_E_CONNECTION_FAILED			(-6)
#define DLAPI_E_NO_RMCP_RESPONSE			(-7)
#define DLAPI_E_NO_WSMAN_RESPONSE			(-8)
#define DLAPI_E_CONNECT_FAILED				(-9)
#define DLAPI_E_NOT_DASH_MACHINE			(-10)
#endif /* __DASHPING_H__ */





