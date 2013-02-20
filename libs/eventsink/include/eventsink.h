/*
 * eventsink.h
 */
#ifndef EVENTSINK_HEADER_INCLUDED
#define	EVENTSINK_HEADER_INCLUDED

#include "wsman-types.h"
#include "wsman-client.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* default port & path */
#define EVENT_SINK_PORT 8080
#define EVENT_SINK_PATH "/eventsink"

#ifdef _WIN32
	#ifdef EVENTSINK_STATIC_LIB
		#define EVENTSINK_Export
	#else
		#ifdef EVENTSINK_DLL
			#define EVENTSINK_Export  __declspec (dllexport)
		#else
			#define EVENTSINK_Export  __declspec (dllimport)
		#endif
	#endif
#else
	#define EVENTSINK_Export
#endif



typedef int (*fp_evt_callback) (WsXmlDocH doc, void* data, char* ip_addr);
EVENTSINK_Export int wsevent_start (int port, const char* service_path, 
									fp_evt_callback fp_callback, void* data);
EVENTSINK_Export int wsevent_stop  (void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* EVENTSINK_HEADER_INCLUDED */
