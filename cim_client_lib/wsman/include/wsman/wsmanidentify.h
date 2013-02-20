/**
 * wsmanidentify.h
 */

#ifndef __WSMAN_IDENTIFY_H__
#define __WSMAN_IDENTIFY_H__

#define WSMAN_IDENTIFY_MAX_SECURITY_PROFILES		10

typedef struct
{
	char* protocolVersion;
	char* productVendor;
	char* productVersion;
	char* dashVersion;
	char* securityProfileName[WSMAN_IDENTIFY_MAX_SECURITY_PROFILES];

} WSMANIdentifyInfo_T;

int wsmanIdentify ( const char*				hostname,
				    const char*				username,
				    const char*				password,
					const char*			    auth,
					const char*				scheme, 
					int						port,
					unsigned long			timeout,
					WSMANIdentifyInfo_T*	info);

#endif /* __WSMAN_IDENTIFY_H__ */







