/* 
 * Copyright (c) 2005, 2006 by KoanLogic s.r.l. - All rights reserved.  
 */

#ifndef _U_CARPAL_H_
#define _U_CARPAL_H_

#include <sys/types.h>
#ifdef TIME_WITH_SYS_TIME
#include <sys/time.h>
#endif
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdarg.h>


#include <u/log.h>

#ifdef __cplusplus
extern "C" {
#endif

#define msg(label, ...) label( __VA_ARGS__)
#define msg_noargs(label, literal) label("%s", literal)

/** \brief log a message and goto "err" label
 *
 *   log a message of type \e label if \e expr not zero.
 *
 */
#define msg_err(label, ...) do { msg(label, __VA_ARGS__); goto err; } while(0)

/** \brief log a message if \e expr not zero.
 *
 *   log a message of type \e label if \e expr is not zero 
 *
 *   \e expr text statement will be written to the log file.
 *
 *   For ex.:
 *       warn_if(check(abc) < 0);
 */
#define msg_if(label, expr) do { if( expr ) msg_noargs(label, #expr); } while(0)

/** \brief log a message if \e expr not zero and enter the if-block
 *
 *   log a message of type \e label if \e expr is not zero and enter the
 *   following if-block.
 *
 *   \e expr text statement will be written to the log file.
 *
 *   A C-style dbg_ code block should follow. For ex.:
 *       dbg_ifb(i == 0)
 *       {
 *           do_something();
 *           do_something();
 *       }
 */
#define msg_ifb(label, expr) if( (expr) && (msg_noargs(label, #expr) ? 1 : 1) ) 

/** \brief log a message if \e expr not zero and return \e err.
 *
 *   log a message of type \e label if \e expr is not zero and return
 *   \e err to the caller.
 *
 *   \e expr text statement will be written to the log file.
 *
 *   Example:
 *      dbg_return_if(param == NULL, FUNC_ERROR);
 */
#define msg_return_if(label, expr, err) msg_ifb(label, expr) return err

/** \brief log a message if \e expr not zero and return \e err. (Log the strerror also)
 *
 *   log a message of type \e label if \e expr is not zero and return
 *   \e err to the caller. Log also the strerror(errno).
 *
 *   \e expr text statement will be written to the log file.
 */
#define msg_return_sif(label, expr, err) \
    do { msg_ifb(label, expr) { msg_strerror(label, errno); return err; } } while(0)

/** \brief log a message if \e expr not zero and goto \e gt.
 *
 *   log a message of type \e label if \e expr is not zero and goto
 *   to the label \e gt (that must be in-scope).
 *
 *   \e expr text statement will be written to the log file.
 */
#define msg_goto_if(label, expr, gt) msg_ifb(label, expr) goto gt

/** \brief log a message if \e expr not zero and goto to the label "err"
 *
 *   log a message of type \e label if \e expr is not zero and goto
 *   to the label "err" (that must be defined).
 *
 *   \e expr text statement will be written to the log file.
 */
#define msg_err_if(label, expr) do { msg_ifb(label, expr) { goto err;} } while(0)

/** \brief log a message if \e expr not zero and goto to the label "err". 
 *
 *   log a message of type \e label if \e expr is not zero and goto
 *   to the label "err" (that must be defined). also logs arguments provided
 *   by the caller.
 */
#define msg_err_ifm(label, expr, ...) \
    do { if( (expr) ) { msg(label, __VA_ARGS__); goto err; } } while(0)

/** \brief log a message if \e expr not zero and goto to the label "err". 
 *
 *   log a message of type \e label if \e expr is not zero and goto
 *   to the label "err" (that must be defined). also logs strerror(errno).
 */
#define msg_err_sif(label, expr) \
    do { msg_ifb(label, expr) { msg_strerror(label, errno); goto err; } } while(0)

/** \brief write a debug message containing the message returned by strerror(errno) */
#ifdef WIN32
#define msg_strerror(label, en)                                     \
    do {                                                            \
        LPVOID lpMsgBuf = NULL;  DWORD dw = GetLastError();         \
        if(FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER |          \
            FORMAT_MESSAGE_FROM_SYSTEM, NULL, dw,                   \
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),              \
            (LPTSTR) &lpMsgBuf, 0, NULL ) && lpMsgBuf)              \
        {                                                           \
            msg(label, "%s", lpMsgBuf);                             \
            LocalFree(lpMsgBuf);                                    \
        }                                                           \
    } while(0)
#else
#ifdef HAVE_STRERROR_R
    #ifdef STRERROR_R_CHAR_P
        #define msg_strerror(label, en)                             \
            do {                                                    \
            enum { _DBG_BUFSZ = 256 };                              \
            char *p, _eb[_DBG_BUFSZ] = { 0 };                       \
            p = strerror_r(en, _eb, _DBG_BUFSZ);                    \
            if(p) {                                                 \
                msg(label, "%s", p);                                \
            } else {                                                \
                msg(label, "strerror_r(%d, ...) failed", en);       \
            }                                                       \
        } while(0)                                        
    #else                                                     
        #define msg_strerror(label, en)                             \
        do {                                                        \
            enum { _DBG_BUFSZ = 256 };                              \
            char _eb[_DBG_BUFSZ] = { 0 };                           \
            if(strerror_r(en, _eb, _DBG_BUFSZ) == 0) {              \
                msg(label, "%s", _eb);                              \
            } else {                                                \
                msg(label, "strerror_r(%d, ...) failed", en);       \
            }                                                       \
        } while(0)                                        
    #endif                                                    
#else                                                         
    #define msg_strerror(label, en)                                 \
        do {                                                        \
            char *p;                                                \
            if((p = strerror(en)) != NULL) {                        \
                msg(label, "%s", p);                                \
            } else {                                                \
                msg(label, "strerror(%d) failed", en);              \
            }                                                       \
        } while(0)                  
#endif  
#endif /* ! def WIN32 */

/* nop_ macros */
#define nop_return_if(expr, err)       do { if(expr) return err; } while(0)
#define nop_err_if(expr)               do { if(expr) goto err;   } while(0)
#define nop_goto_if(expr, gt)          do { if(expr) goto gt;    } while(0)

/* con_ macros */
#define con(...)                       msg(console, __VA_ARGS__)
#define con_err(...)                   msg_err(console, __VA_ARGS__)
#define con_ifb(expr)                  msg_ifb(console, expr)
#define con_if(expr)                   msg_if(console, expr) 
#define con_return_if(expr, err)       msg_return_if(console, expr, err)
#define con_err_if(expr)               msg_err_if(console, expr)
#define con_err_ifm(expr, ...)         \
    msg_err_ifm(console, expr, __VA_ARGS__)
#define con_goto_if(expr, gt)          msg_goto_if(console, expr, gt)
#define con_strerror(errno)            msg_strerror(console, errno)

/* info_ macros */
/* #define info(...)                    msg(info, __VA_ARGS__) */
#define info_err(...)                   msg_err(info, __VA_ARGS__)
#define info_ifb(expr)                  msg_ifb(info, expr)
#define info_if(expr)                   msg_if(info, expr) 
#define info_return_if(expr, err)       msg_return_if(info, expr, err)
#define info_err_if(expr)               msg_err_if(info, expr)
#define info_err_sif(expr)              msg_err_sif(info, expr)
#define info_err_ifm(expr, ...)         \
    msg_err_ifm(info, expr, __VA_ARGS__)
#define info_goto_if(expr, gt)          msg_goto_if(info, expr, gt)
#define info_strerror(errno)            msg_strerror(info, errno)

/* warn_ macros */
#define warn(...)                       msg(warning, __VA_ARGS__)
#define warn_err(...)                   msg_err(warning, __VA_ARGS__)
#define warn_ifb(expr)                  msg_ifb(warning, expr)
#define warn_if(expr)                   msg_if(warning, expr) 
#define warn_return_if(expr, err)       msg_return_if(warning, expr, err)
#define warn_err_if(expr)               msg_err_if(warning, expr)
#define warn_err_sif(expr)              msg_err_sif(warning, expr)
#define warn_err_ifm(expr, ...)         \
    msg_err_ifm(warning, expr, __VA_ARGS__)
#define warn_goto_if(expr, gt)          msg_goto_if(warning, expr, gt)
#define warn_strerror(errno)            msg_strerror(warning, errno)

/* dbg_ macros */
#ifdef DEBUG
    #define dbg(...)                    msg(debug, __VA_ARGS__)
    #define dbg_err(...)                msg_err(debug, __VA_ARGS__)
    #define dbg_ifb(expr)               msg_ifb(debug, expr)
    #define dbg_if(expr)                msg_if(debug, expr) 
    #define dbg_return_if(expr, err)    msg_return_if(debug, expr, err)
    #define dbg_return_sif(expr, err)   msg_return_sif(debug, expr, err)
    #define dbg_err_if(expr)            msg_err_if(debug, expr)
    #define dbg_err_sif(expr)           msg_err_sif(debug, expr)
    #define dbg_err_ifm(expr, ...)      \
        msg_err_ifm(debug, expr, __VA_ARGS__)
    #define dbg_goto_if(expr, gt)       msg_goto_if(debug, expr, gt)
    #define dbg_strerror(errno)         msg_strerror(debug, errno)
    /* simple debugging timing macros */
    #define TIMER_ON \
        time_t _t_beg = time(0), _t_prev = _t_beg, _t_now; int _t_step = 0
    #define TIMER_STEP                                                      \
        do {                                                                \
        _t_now = time(0);                                                   \
        dbg("  step %u: %u s (delta: %u s)",                                \
            _t_step++, _t_now - _t_beg, _t_now - _t_prev);                  \
            _t_prev = _t_now;                                               \
       } while(0)
    #define TIMER_OFF  dbg("elapsed: %u s", (time(0) - _t_beg))
#else /* disable debugging */
    #include <ctype.h>
    /* this will be used just to avoid empty-if (and similar) warnings */
    #define dbg_nop()
    #define dbg(...)                    dbg_nop()
    #define dbg_err(...)                do { goto err; } while(0)
    #define dbg_ifb(expr)               if( (expr) )
    #define dbg_if(expr)                expr
    #define dbg_return_if(expr, err)    do { if( (expr) ) return err; } while(0)
    #define dbg_err_if(expr)            do { if( (expr)) goto err; } while(0)
    #define dbg_err_sif(expr)           do { if( (expr)) goto err; } while(0)
    #define dbg_err_ifm(expr, ...)      do { if( (expr)) goto err; } while(0)
    #define dbg_goto_if(expr, gt)       do { if((expr)) goto gt; } while(0)
    #define dbg_strerror(errno)         dbg_nop()
    #define TIMER_ON
    #define TIMER_STEP
    #define TIMER_OFF
#endif /* ifdef DEBUG */

#ifdef __cplusplus
}
#endif

#endif /* _U_CARPAL_H_ */

