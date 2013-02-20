


#ifndef WIN32PORT_H
#define WIN32PORT_H

#include <string.h>
#include <malloc.h>
#include <ctype.h>
#ifndef strcasecmp
#define strcasecmp _stricmp
#endif
#ifndef strncasecmp
#define strncasecmp _strnicmp
#endif
#define strdup _strdup
#define snprintf _snprintf

#define tzset _tzset

#endif
