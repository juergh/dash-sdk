#ifdef HAVE_CONFIG_H
#include <wsman_config.h>
#endif

#include <u/os.h>
#ifndef HAVE_SYSLOG

#ifdef WIN32
#include <windows.h>
#include <io.h>
#include <sys/locking.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#define fileno _fileno

void vsyslog(int priority, const char *fmt, va_list ap)
{
    #define WSMAND_WIN_LOGFILE "wsmand.log"
    enum { BUFSZ = 1024 };
    static FILE *df = NULL, *lock = NULL;
    char buf[BUFSZ];
    int i;

    /* first time open the log file and the lock file */
    if(df == NULL)
    {
        df = fopen(WSMAND_WIN_LOGFILE, "a+");
        lock = fopen(WSMAND_WIN_LOGFILE ".lock", "a+");
        if(df == NULL || lock == NULL)
            exit(1);
    }

    vsnprintf(buf, BUFSZ, fmt, ap);

    /* get the lock (i.e. lock the first byte of the lock file) */
    for(i = 0; 
        _locking(fileno(lock), _LK_NBLCK, 1) == EACCES && i < 10; ++i)
        Sleep(100);

    if(i < 10)
    {   /* we have the lock, write the log msg */
        fprintf(df, "%s\n", buf);
        fflush(df);
        /* unlock the file */
        _locking(fileno(lock), _LK_UNLCK, 1);
    } else {
        /* file is still locked after 10 tries, give up */
        ;
    }

    return;
}

void syslog(int priority, const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt); /* init variable list arguments */

    vsyslog(priority, fmt, ap);

    va_end(ap);
}

#endif /* ifdef WIN32 */

#else /* ifndef HAVE_SYSLOG */
#include <syslog.h>
#include <stdarg.h>
//void syslog(int priority, const char *fmt, ...);
//void vsyslog(int priority, const char *fmt, va_list args);
#endif 
