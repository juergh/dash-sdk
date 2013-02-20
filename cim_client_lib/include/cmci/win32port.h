


#ifndef WIN32PORT_H
#define WIN32PORT_H

//#include <dsdkcompat/compat.h>

#include <string.h>
#include <ctype.h>
#ifndef strcasecmp
# define strcasecmp _stricmp
#endif
#ifndef strncasecmp
# define strncasecmp _strnicmp
#endif
#ifndef strdup
# define strdup _strdup
#endif
#ifndef snprintf
//# define snprintf win32_snprintf
# define snprintf _snprintf
#endif
#ifndef localtime_r
# define localtime_r localtime
#endif
#ifndef tzset
# define tzset _tzset
#endif

#endif
