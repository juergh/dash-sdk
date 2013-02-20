/* 
 * Copyright (c) 2005, 2006 by KoanLogic s.r.l. - All rights reserved.  
 */

#ifndef _U_LOGPRV_H_
#define _U_LOGPRV_H_


#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined (__SUNPRO_C) || defined(__SUNPRO_CC)
#define u_log_write(fac, lev, ctx, ...) \
    u_log_write_ex(fac, lev, ctx, __FILE__, __LINE__,__func__, __VA_ARGS__)
#else /* __SUNPRO_C || __SUNPRO_CC */
#define u_log_write(fac, lev, ctx, ...) \
    u_log_write_ex(fac, lev, ctx, __FILE__, __LINE__,__FUNCTION__, __VA_ARGS__)
#endif /* __SUNPRO_C || __SUNPRO_CC */

/** pack context information (if [ctx] is > 0) and the priority label and 
    send both to the log system followed by the user message string 

  fac:  facility (label)
  lev:  priority level
  ctx:  prints context information if [ctx] > 0
  file: filename
  line: line number
  func: function name
  fmt:  printf-style format string
  ...:  optional parameters

  */
int u_log_write_ex(int fac, int lev, int ctx, const char* file, int line, 
    const char *func, const char* fmt, ...);

#ifdef __cplusplus
}
#endif

#endif /* !_U_LOGPRV_H_ */
