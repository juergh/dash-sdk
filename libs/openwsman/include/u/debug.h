/*******************************************************************************
* Copyright (C) 2004-2006 Intel Corp. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
*  - Neither the name of Intel Corp. nor the names of its
*    contributors may be used to endorse or promote products derived from this
*    software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL Intel Corp. OR THE CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

/**
 * @author Anas Nashif
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include <stdarg.h>
#include <stdio.h>
#include <u/os.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef enum {
    DEBUG_LEVEL_ALWAYS   = -1,
    DEBUG_LEVEL_NONE     = 0,
    DEBUG_LEVEL_ERROR    = 1,
    DEBUG_LEVEL_CRITICAL = 2,
    DEBUG_LEVEL_WARNING  = 3,
    DEBUG_LEVEL_MESSAGE  = 4,
    DEBUG_LEVEL_INFO     = 5,
    DEBUG_LEVEL_DEBUG    = 6,
} debug_level_e;


typedef void (*debug_fn) (const char *message,
                           debug_level_e level,
                           void* user_data);
struct _debug_handler_t {
    debug_fn   	         fn;
    debug_level_e 	level;
    void*     		user_data;
    unsigned int	id;
};
typedef struct _debug_handler_t debug_handler_t;


unsigned int
debug_add_handler (debug_fn fn,
                      debug_level_e level,
                      void* user_data);

void debug_remove_handler (unsigned int id);
void debug_destroy_handlers (void);

void debug_full(debug_level_e  level, const char *format, ...);
void debug_full_verbose(debug_level_e  level, char *file,
                 int line, const char *proc, const char *format, ...);

// #define ENABLE_TRACING
#ifdef ENABLE_TRACING
#if defined (__SUNPRO_C) || defined(__SUNPRO_CC)
#define TRACE_ENTER printf("TRACE: Entering %s %s:%d\n", __func__, __FILE__, __LINE__ );
#define TRACE_DETAILS(format...) printf("TRACE: %s :%s:%d --- %s\n", __func__, __FILE__, __LINE__ , debug_helper (format));
#define TRACE_EXIT  printf("TRACE: Leaving %s %s:%d\n", __func__, __FILE__, __LINE__ );
#else // __SUNPRO_C || __SUNPRO_CC
#define TRACE_ENTER printf("TRACE: Entering %s %s:%d\n", __FUNCTION__, __FILE__, __LINE__ );
#define TRACE_DETAILS(format...) printf("TRACE: %s :%s:%d --- %s\n", __FUNCTION__, __FILE__, __LINE__ , debug_helper (format));
#define TRACE_EXIT  printf("TRACE: Leaving %s %s:%d\n", __FUNCTION__, __FILE__, __LINE__ );
#endif // __SUNPRO_C || __SUNPRO_CC
#else
#define TRACE_ENTER
#ifdef _WIN32
static __inline void TRACE_DETAILS(char* format, ...) {
    return;
}
#else
#define TRACE_DETAILS(format...)
#endif
#define TRACE_EXIT
#endif




#ifdef WIN32

static __inline void debug(char* format, ...) {
    debug_full(DEBUG_LEVEL_WARNING, format);
}
static __inline void error(char* format, ...) {
    debug_full(DEBUG_LEVEL_WARNING, format);
}
static __inline void message(char* format, ...) {
    debug_full(DEBUG_LEVEL_WARNING, format);
}

#else // WIN32

#ifdef WSMAN_DEBUG_VERBOSE

#if defined (__SUNPRO_C) || defined(__SUNPRO_CC)
#define debug(format...) \
        debug_full_verbose(DEBUG_LEVEL_DEBUG, __FILE__, __LINE__,__func__, format)
#define error(format...) \
        debug_full_verbose(DEBUG_LEVEL_ERROR, __FILE__, __LINE__,__func__, format)
#define message(format...) \
        debug_full_verbose(DEBUG_LEVEL_MESSAGE, __FILE__, __LINE__,__func__, format)
#else // __SUNPRO_C || __SUNPRO_CC
#define debug(format...) \
        debug_full_verbose(DEBUG_LEVEL_DEBUG, __FILE__, __LINE__,__FUNCTION__, format)
#define error(format...) \
        debug_full_verbose(DEBUG_LEVEL_ERROR, __FILE__, __LINE__,__FUNCTION__, format)
#define message(format...) \
        debug_full_verbose(DEBUG_LEVEL_MESSAGE, __FILE__, __LINE__,__FUNCTION__, format)
#endif // __SUNPRO_C || __SUNPRO_CC

#else // WSMAN_DEBUG_VERBOSE

#define warnings(format...) \
        debug_full(DEBUG_LEVEL_WARNING, format)

#define debug(format...) \
        debug_full(DEBUG_LEVEL_DEBUG, format)

#define error(format...) \
        debug_full(DEBUG_LEVEL_ERROR, format)

#define message(format...) \
        debug_full(DEBUG_LEVEL_MESSAGE, format)

#endif // WSMAN_DEBUG_VERBOSE

#endif // WIN32



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /*DEBUG_H_*/

