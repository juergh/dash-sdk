/* 
 * Copyright (c) 2005, 2006 by KoanLogic s.r.l. - All rights reserved.  
 */

#ifndef _U_MISC_H_
#define _U_MISC_H_


#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif

/* define U_PATH_MAX */
#ifndef PATH_MAX
#define U_PATH_MAX 4096
#else
#define U_PATH_MAX PATH_MAX
#endif

/* define U_NAME_MAX */
#ifdef NAME_MAX
#define U_NAME_MAX NAME_MAX
#else
#ifdef FILENAME_MAX
#define U_NAME_MAX FILENAME_MAX
#else
#define U_NAME_MAX 512
#endif 
#endif

/* define U_FILENAME_MAX (path + name) */
#define U_FILENAME_MAX (U_PATH_MAX + U_NAME_MAX)

#define U_ONCE if (({ static int __x = 0; int __y; __y = __x; __x = 1; !__y;}))
#define U_SSTRCPY(to, from) u_sstrncpy((to), (from), sizeof(to) - 1)
#define U_FREE(ptr) do {if (ptr) { u_free(ptr); ptr = NULL; }} while (0)
#define U_CLOSE(fd) do {if (fd != -1) { close(fd); fd = -1; }} while (0)
#define U_FCLOSE(fp) do {if (fp) { fclose(fp); fp = NULL; }} while (0)
#define U_PCLOSE(pp) do {if (pp) { pclose(pp); pp = NULL; }} while (0)
#define u_unused_args(...) u_use_unused_args(NULL, __VA_ARGS__)

int isstrdigit(char *str);
int u_isnl(int c);
void u_trim(char *s);
void u_trim_quotes(char *);
int u_isquote(int c);
int u_isblank(int c);
int u_isblank_str(const char *ln);
char *u_strndup(const char *s, size_t len);
char *u_strdup(const char *s);
int u_savepid (const char *pf);
char *u_sstrncpy (char *dst, const char *src, size_t size);
void* u_memdup(const void *src, size_t size);
int u_tokenize (char *wlist, const char *delim, char **tokv, size_t tokv_sz);
int u_snprintf(char *str, size_t size, const char *fmt, ...);
int u_path_snprintf(char *str, size_t size, char sep, const char *fmt, ...);
void u_use_unused_args(char *dummy, ...);
int u_data_is_bin (char *data, size_t sz);


/* openwsman */
size_t u_tokenize1(char **result, size_t reslen, char *str, char delim);
int u_path_is_absolute (const char *filename);

#ifdef __cplusplus
}
#endif

#endif /* !_U_MISC_H_ */
