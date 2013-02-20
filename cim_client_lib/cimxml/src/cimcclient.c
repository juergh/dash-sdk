
/*
 * $Id: cimcclient.c,v 1.2 2007/02/07 18:09:58 mihajlov Exp $
 *
 * © Copyright IBM Corp. 2007
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Eclipse Public License from
 * http://www.opensource.org/licenses/eclipse-1.0.php
 *
 * Author:        Viktor Mihajlovski <mihajlov@de.ibm.com>
 *
 * Description:
 *
 * CIM C Client Loader Implementation
 *
 */

#include <cimc/cimc.h>

#include <stdio.h>
#include <stdlib.h>
#include <cmci/win32port.h>
#include <windows.h>
#ifndef WIN32_PORT
#include <dlfcn.h>
#endif


/*
 * Canonical CIM C API entry points
 */

#define LIBLEN 512
#define ENTLEN 256
#define ERRLEN 1024

typedef CIMCEnv* (*fpCIMEnv_T)(const char *id);
extern CIMCEnv* _Create_XML_Env(const char *id);

CIMCEnv* NewCIMCEnv(const char *id, unsigned int options, int *rc, char **msg, char* backend)
{
   InitCimcEnv  init=NULL;
   CIMCEnv     *rv=NULL;
   fpCIMEnv_T  fpCIMEnv;
   //HINSTANCE hinstLib;


   fpCIMEnv = &_Create_XML_Env;

   rv = fpCIMEnv (id);


#if 0
    hinstLib = LoadLibraryA (backend);

    if (hinstLib == NULL) 
	{
		int i = 0;
		i = GetLastError();
		printf("ERROR: unable to load DLL %d\n", i);
        return i;
    }

    // Get function pointer
    fpCIMEnv = (fpCIMEnv_T)GetProcAddress(hinstLib, "_Create_XML_Env");
    if (fpCIMEnv == NULL) {
		printf("ERROR: unable to find DLL function\n");
        FreeLibrary(hinstLib);
        return 1;
    }

	rv = fpCIMEnv (id);
	rv->hdl = hinstLib;
   
#ifndef WIN32_PORT
   library = dlopen(libName, RTLD_NOW);
   if (library==NULL) {
     *msg=calloc(1,ERRLEN+1);
     *rc=1;
     snprintf(*msg,ERRLEN,"Unable to load %s library %s",libName,dlerror());
   } else {
     snprintf(entry, ENTLEN,"_Create_%s_Env", id);
     init = (InitCimcEnv)dlsym(library, entry);
     if (init==NULL) {
       *msg=calloc(1,ERRLEN+1);
       *rc=2;
       snprintf(*msg,ERRLEN,"Unable to locate entry %s in %s",entry,libName);
     } else {
       *rc=0;
       *msg=NULL;
       rv = init(id,options,rc,msg); 
       rv->hdl=library;
     }
   }
#endif
#endif

   return rv;
}

void ReleaseCIMCEnv(CIMCEnv *env)
{
   void *lib=NULL;
   if (env) {
     lib = env->hdl;
     env->ft->release(env);
     if (lib) {
#ifndef WIN32_PORT
       dlclose(lib);
#else
     FreeLibrary(lib);
#endif
     }
   }
}
