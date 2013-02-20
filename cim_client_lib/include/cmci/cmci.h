
/*
 * cmpic.h
 *
 * (C) Copyright IBM Corp. 2005
 *
 * THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE
 * ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE
 * CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 *
 * You can obtain a current copy of the Eclipse Public License from
 * http://www.opensource.org/licenses/eclipse-1.0.php
 *
 * Author:        Adrian Schuur <schuur@de.ibm.com>
 *
 * Description:
 *
 * CMPI Client function tables.
 *
*/

#ifndef _CMPIC_H_
#define _CMPIC_H_

#include <cmci/cmcidt.h>
#include <cmci/cmcift.h>
#include <cmci/cmcimacs.h>

#ifdef __cplusplus
extern "C" {
#endif



   //---------------------------------------------------
   //--
   //	_CMCIClientFt Function Table
   //--
   //---------------------------------------------------


   /** This structure is a table of pointers to client CIMOM services.
   */

struct _CMCIClient;
typedef struct _CMCIClient CMCIClient;
   
struct _CMCIConnection;
typedef struct _CMCIConnection CMCIConnection;
   
struct _ClientEnc;
typedef struct _ClientEnc ClientEnc;

typedef struct _CMCIClientFT {

       /** Function table version
       */
     int ftVersion;

      /** The Client object will not be used any further and may be freed by
           CMPI run time system.
	 @param cl Client this pointer.
	 @return Service return status.
      */
     CMPIStatus (*release)
              (CMCIClient* cl);
   
      /** The clone operation is not supported. 
           Inserted here to conform with other CMCI function table layouts.
	 @param cl Client this pointer.
	 @param rc Output: Service return status (suppressed when NULL).
	 @return Always NULL.
      */
     CMCIClient *(*clone) ( CMCIClient * cl, CMPIStatus * st );
     
     
      /** Get Class using &lt;op&gt; as reference. Class structure can be
         controled using the flags parameter.
	 @param cl Client this pointer.
	 @param op ObjectPath containing nameSpace and classname components.
	 @param flags Any combination of the following flags are supported: 
	    CMPI_FLAG_LocalOnly, CMPI_FLAG_IncludeQualifiers and CMPI_FLAG_IncludeClassOrigin.
	 @param properties If not NULL, the members of the array define one or more Property
	     names. Each returned Object MUST NOT include elements for any Properties
	     missing from this list
	 @param rc Output: Service return status (suppressed when NULL).
	 @return The Class.
     */
     CMPIConstClass* (*getClass)
                (CMCIClient* cl,
                 CMPIObjectPath* op, CMPIFlags flags, char** properties, CMPIStatus* rc);


       /** Enumerate Class Names (and subclass names) in the nameSpace defined by &lt;op&gt;. Inheritance scope can be controled using the
	        flags parameter.
	 @param cl Client this pointer.
	 @param op ObjectPath containing nameSpace component.
	 @param flags The following flag is supported: CMPI_FLAG_DeepInheritance.
	 @param rc Output: Service return status (suppressed when NULL).
	 @return Enumeration of ObjectPathes.
     */
     
     CMPIEnumeration* (*enumClassNames)
                (CMCIClient* cl,
                 CMPIObjectPath* op, CMPIFlags flags, CMPIStatus* rc);

     /** Enumerate Classes (and subclasses) in the nameSpace  defined by &lt;op&gt;.
         Class structure and inheritance scope can be controled using the &lt;flags&gt; parameter.
	 @param cl Client this pointer.
	 @param op ObjectPath containing nameSpace and classname components.
	 @param flags Any combination of the following flags are supported: CMPI_FLAG_LocalOnly, 
	     CMPI_FLAG_DeepInheritance, CMPI_FLAG_IncludeQualifiers and CMPI_FLAG_IncludeClassOrigin.
	 @param rc Output: Service return status (suppressed when NULL).
	 @return Enumeration of Instances.
     */
     
     CMPIEnumeration* (*enumClasses)
                (CMCIClient* cl,
                 CMPIObjectPath* op, CMPIFlags flags, CMPIStatus* rc);

      /** Get Instance using &lt;op&gt; as reference. Instance structure can be
         controled using the &lt;flags&gt; parameter.
	 @param cl Client this pointer.
	 @param op ObjectPath containing nameSpace, classname and key components.
	 @param flags Any combination of the following flags are supported: 
	    CMPI_FLAG_LocalOnly, CMPI_FLAG_IncludeQualifiers and CMPI_FLAG_IncludeClassOrigin.
	 @param properties If not NULL, the members of the array define one or more Property
	     names. Each returned Object MUST NOT include elements for any Properties
	     missing from this list
	 @param rc Output: Service return status (suppressed when NULL).
	 @return The Instance.
     */
     CMPIInstance* (*getInstance)
                (CMCIClient* cl,
                 CMPIObjectPath* op, CMPIFlags flags, char** properties, CMPIStatus* rc);

      /** Create Instance from &lt;inst&gt; using &lt;op&gt; as reference.
	 @param cl Client this pointer.
	 @param op ObjectPath containing nameSpace, classname and key components.
	 @param inst Complete instance.
	 @param rc Output: Service return status (suppressed when NULL).
	 @return The assigned instance reference.
     */
     CMPIObjectPath* (*createInstance)
                (CMCIClient* cl,
                 CMPIObjectPath* op, CMPIInstance* inst, CMPIStatus* rc);

      /** Replace an existing Instance from &lt;inst&gt; using &lt;op&gt; as reference.
	 @param cl Client this pointer.
	 @param op ObjectPath containing nameSpace, classname and key components.
	 @param inst Complete instance.
	 @param flags The following flag is supported: CMPI_FLAG_IncludeQualifiers.
	 @param properties If not NULL, the members of the array define one or more Property
	     names, only those properties will be updated. Else, all properties will be updated. 
	 @return Service return status.
     */
     CMPIStatus (*setInstance)
                (CMCIClient* cl,
                 CMPIObjectPath* op, CMPIInstance* inst, CMPIFlags flags, char ** properties);

      /** Delete an existing Instance using &lt;op&gt; as reference.
	 @param cl Client this pointer.
	 @param op ObjectPath containing nameSpace, classname and key components.
	 @return Service return status.
     */
     CMPIStatus (*deleteInstance)
                (CMCIClient* cl,
                 CMPIObjectPath* op);

      /** Query the enumeration of instances of the class (and subclasses) defined
         by &lt;op&gt; using &lt;query&gt; expression.
	 @param cl Client this pointer.
	 @param op ObjectPath containing nameSpace and classname components.
	 @param query Query expression
	 @param lang Query Language
	 @param rc Output: Service return status (suppressed when NULL).
	 @return Resulting eumeration of Instances.
     */
     CMPIEnumeration* (*execQuery)
                (CMCIClient* cl,
                 CMPIObjectPath* op, const char *query, const char *lang, CMPIStatus* rc);

       /** Enumerate Instance Names of the class (and subclasses) defined by &lt;op&gt;.
	 @param cl Client this pointer.
	 @param op ObjectPath containing nameSpace and classname components.
	 @param rc Output: Service return status (suppressed when NULL).
	 @return Enumeration of ObjectPathes.
     */
     CMPIEnumeration* (*enumInstanceNames)
                (CMCIClient* cl,
                 CMPIObjectPath* op, CMPIStatus* rc);

     /** Enumerate Instances of the class (and subclasses) defined by &lt;op&gt;.
         Instance structure and inheritance scope can be controled using the
	      &lt;flags&gt; parameter.
	 @param cl Client this pointer.
	 @param op ObjectPath containing nameSpace and classname components.
	 @param flags Any combination of the following flags are supported: CMPI_FLAG_LocalOnly, 
	     CMPI_FLAG_DeepInheritance, CMPI_FLAG_IncludeQualifiers and CMPI_FLAG_IncludeClassOrigin.
	 @param properties If not NULL, the members of the array define one or more Property
	     names. Each returned Object MUST NOT include elements for any Properties
	     missing from this list
	 @param rc Output: Service return status (suppressed when NULL).
	 @return Enumeration of Instances.
     */
     CMPIEnumeration* (*enumInstances)
                (CMCIClient* cl,
                 CMPIObjectPath* op, CMPIFlags flags, char** properties, CMPIStatus* rc);

      /** Enumerate instances associated with the Instance defined by the &lt;op&gt;.
	 @param cl Client this pointer.
	 @param op Source ObjectPath containing nameSpace, classname and key components.
	 @param assocClass If not NULL, MUST be a valid Association Class name.
	    It acts as a filter on the returned set of Objects by mandating that
	    each returned Object MUST be associated to the source Object via an
	    Instance of this Class or one of its subclasses.
	 @param resultClass If not NULL, MUST be a valid Class name.
	    It acts as a filter on the returned set of Objects by mandating that
	    each returned Object MUST be either an Instance of this Class (or one
	    of its subclasses).
	 @param role If not NULL, MUST be a valid Property name.
	    It acts as a filter on the returned set of Objects by mandating
	    that each returned Object MUST be associated to the source Object
	    via an Association in which the source Object plays the specified role
	    (i.e. the name of the Property in the Association Class that refers
	    to the source Object MUST match the value of this parameter).
	 @param resultRole If not NULL, MUST be a valid Property name.
	    It acts as a filter on the returned set of Objects by mandating
	    that each returned Object MUST be associated to the source Object
	    via an Association in which the returned Object plays the specified role
	    (i.e. the name of the Property in the Association Class that refers to
	    the returned Object MUST match the value of this parameter).
	 @param flags Any combination of the following flags are supported: 
	    CMPI_FLAG_IncludeQualifiers and CMPI_FLAG_IncludeClassOrigin.
	 @param properties If not NULL, the members of the array define one or more Property
	     names. Each returned Object MUST NOT include elements for any Properties
	     missing from this list
	 @param rc Output: Service return status (suppressed when NULL).
	 @return Enumeration of Instances.
     */
     CMPIEnumeration* (*associators)
                (CMCIClient* cl,
                 CMPIObjectPath* op, const char *assocClass, const char *resultClass,
		 const char *role, const char *resultRole, CMPIFlags flags, 
                 char** properties, CMPIStatus* rc);

      /** Enumerate ObjectPaths associated with the Instance defined by &lt;op&gt;.
	 @param cl Client this pointer.
	 @param op Source ObjectPath containing nameSpace, classname and key components.
	 @param assocClass If not NULL, MUST be a valid Association Class name.
	    It acts as a filter on the returned set of Objects by mandating that
	    each returned Object MUST be associated to the source Object via an
	    Instance of this Class or one of its subclasses.
	 @param resultClass If not NULL, MUST be a valid Class name.
	    It acts as a filter on the returned set of Objects by mandating that
	    each returned Object MUST be either an Instance of this Class (or one
	    of its subclasses).
	 @param role If not NULL, MUST be a valid Property name.
	    It acts as a filter on the returned set of Objects by mandating
	    that each returned Object MUST be associated to the source Object
	    via an Association in which the source Object plays the specified role
	    (i.e. the name of the Property in the Association Class that refers
	    to the source Object MUST match the value of this parameter).
	 @param resultRole If not NULL, MUST be a valid Property name.
	    It acts as a filter on the returned set of Objects by mandating
	    that each returned Object MUST be associated to the source Object
	    via an Association in which the returned Object plays the specified role
	    (i.e. the name of the Property in the Association Class that refers to
	    the returned Object MUST match the value of this parameter).
	 @param rc Output: Service return status (suppressed when NULL).
	 @return Enumeration of ObjectPaths.
     */
     CMPIEnumeration* (*associatorNames)
                (CMCIClient* cl,
                 CMPIObjectPath* op, const char *assocClass, const char *resultClass,
		 const char *role, const char *resultRole, CMPIStatus* rc);

       /** Enumerates the association instances that refer to the instance defined by
           &lt;op&gt;.
	 @param cl Client this pointer.
	 @param op Source ObjectPath containing nameSpace, classname and key components.
	 @param resultClass If not NULL, MUST be a valid Class name.
	    It acts as a filter on the returned set of Objects by mandating that
	    each returned Object MUST be either an Instance of this Class (or one
	    of its subclasses).
	 @param role If not NULL, MUST be a valid Property name.
	    It acts as a filter on the returned set of Objects by mandating
	    that each returned Object MUST be associated to the source Object
	    via an Association in which the source Object plays the specified role
	    (i.e. the name of the Property in the Association Class that refers
	    to the source Object MUST match the value of this parameter).
	 @param flags Any combination of the following flags are supported: 
	    CMPI_FLAG_IncludeQualifiers and CMPI_FLAG_IncludeClassOrigin.
	 @param properties If not NULL, the members of the array define one or more Property
	     names. Each returned Object MUST NOT include elements for any Properties
	     missing from this list
	 @param rc Output: Service return status (suppressed when NULL).
	 @return Enumeration of ObjectPaths.
     */
     CMPIEnumeration* (*references)
                (CMCIClient* cl,
                 CMPIObjectPath* op, const char *resultClass ,const char *role ,
		 CMPIFlags flags, char** properties, CMPIStatus* rc);

       /** Enumerates the association ObjectPaths that refer to the instance defined by
           &lt;op&gt;.
	 @param cl Client this pointer.
	 @param op Source ObjectPath containing nameSpace, classname and key components.
	 @param resultClass If not NULL, MUST be a valid Class name.
	    It acts as a filter on the returned set of Objects by mandating that
	    each returned Object MUST be either an Instance of this Class (or one
	    of its subclasses).
	 @param role If not NULL, MUST be a valid Property name.
	    It acts as a filter on the returned set of Objects by mandating
	    that each returned Object MUST be associated to the source Object
	    via an Association in which the source Object plays the specified role
	    (i.e. the name of the Property in the Association Class that refers
	    to the source Object MUST match the value of this parameter).
	 @param rc Output: Service return status (suppressed when NULL).
	 @return Enumeration of ObjectPaths.
       */
     CMPIEnumeration* (*referenceNames)
                (CMCIClient* cl,
                 CMPIObjectPath* op, const char *resultClass ,const char *role,
                 CMPIStatus* rc);

       /** Invoke a named, extrinsic method of an Instance
         defined by the &lt;op&gt; parameter.
	 @param cl Client this pointer.
	 @param op ObjectPath containing nameSpace, classname and key components.
	 @param method Method name
	 @param in Input parameters.
	 @param out Output parameters.
	 @param rc Output: Service return status (suppressed when NULL).
	 @return Method return value.
      */
     CMPIData (*invokeMethod)
                (CMCIClient* cl,
                 CMPIObjectPath* op,const char *method,
		 CMPIArgs* in, CMPIArgs* out, CMPIStatus* rc);

       /** Set the named property value of an Instance defined by the &lt;op&gt; parameter.
	 @param cl Client this pointer.
	 @param op ObjectPath containing nameSpace, classname and key components.
	 @param name Property name
	 @param value Value.
	 @param type Value type.
	 @return Service return status.
      */
     CMPIStatus (*setProperty)
                (CMCIClient* cl,
                 CMPIObjectPath* op, const char *name , CMPIValue* value,
                 CMPIType type);

       /** Get the named property value of an Instance defined by the &lt;op&gt; parameter.
	 @param cl Client this pointer.
	 @param op ObjectPath containing nameSpace, classname and key components.
	 @param name Property name
	 @param rc Output: Service return status (suppressed when NULL).
	 @return Property value.
      */
     CMPIData (*getProperty)
                (CMCIClient *cl, 
                 CMPIObjectPath *op, const char *name, CMPIStatus *rc);

	 /** Subscribe for an event
	 @param cl Client this pointer
	 @param uri event delivery uri
	 @param mode event type (0 - Push, 1 - PushWithAck, 2 - Events batch mode, 3 - Pull)
	 @param hearbeat heart beat interval in seconds
	 @param expires time for an event to expire
	 @param dialect optional dialect filter, if not specified implied value"http://www.w3.org/TR/1999/REC-xpath-19991116" 
			will be used.
	 @param filter event filter
	 @param resourceUri 
 	 @param rc status.
	 @return uuid the subscription id.
	 */
	 char* (*subscribeEvent) 
		(CMCIClient* cl, CMPIObjectPath *cop, const char* eventDeliveryUri, int	mode, float	heartbeat,
			float	expires, const char* dialect, const char* filter, CMPIStatus * rc);


	 /** Subscribe for an event
	 @param cl Client this pointer
	 @param uri event delivery uri
	 @param mode event type (0 - Push, 1 - PushWithAck, 2 - Events batch mode, 3 - Pull)
	 @param hearbeat heart beat interval in seconds
	 @param expires time for an event to expire
	 @param dialect optional dialect filter, if not specified implied value"http://www.w3.org/TR/1999/REC-xpath-19991116" 
			will be used.
	 @param filter event filter
	 @param resourceUri 
 	 @param rc status.
	 @return uuid the subscription id.
	 */
	 char* (*subscribeToEvent) 
		 (CMCIClient* cl, CMPIObjectPath *cop, char ** params, CMPIStatus * rc);



	 /** Unsubscribe an event
	 @param cl Client this pointer
	 @return rc status
	 */
	 CMPIStatus (*unsubscribeEvent) 
		 (CMCIClient * cl, CMPIObjectPath *cop);

	 /** Renew an event subscription
	 @param cl Client this pointer
	 @param time renew time 
	 @return rc status
	 */
	 CMPIStatus (*renewSubscription) 
		 (CMCIClient * cl,CMPIObjectPath *cop,const char* renewtime);


	 /** Gets the Host name
	 @param cl Client this pointer
	 @return hostname
	 */
	char* (*getHostName) (CMCIClient* cl);

	 /** Gets the port number
	 @param cl Client this pointer
	 @return port
	 */
	int (*getPort) (CMCIClient* cl);
	
	 /** Gets the user name
	 @param cl Client this pointer
	 @return user
	 */
	char* (*getUser) (CMCIClient* cl);

	 /** Gets the password
	 @param cl Client this pointer
	 @return password
	 */
	char* (*getPassword) (CMCIClient* cl);

	 /** Gets the implementation namespace
	 @param cl Client this pointer
	 @return implementation namespace
	 */
	char* (*getImplementationNS) (CMCIClient* cl);

	 /** Gets the interop namespace
	 @param cl Client this pointer
	 @return interop namespace
	 */
	char* (*getInteropNS) (CMCIClient* cl);

	/** Sets the Timeout
	 @param cl Client this pointer
	 */
	void (*setTimeout) (CMCIClient* cl, unsigned long timeout);

	/** Gets the Timeout
	 @param cl Client this pointer
	 @return time out
	 */
	unsigned long (*getTimeout) (CMCIClient* cl);

} CMCIClientFT;


typedef struct clientData {
   char *hostName;
   char *port;
   char *user;
   char *pwd;
   char *scheme;
   int  status;
} CMCIClientData;
  
#define CMCI_VERIFY_NONE 0
#define CMCI_VERIFY_PEER 1

typedef struct credentialData {
  int    verifyMode;
  char * trustStore;
  char * certFile;
  char * keyFile;
} CMCICredentialData;

struct _CMCIClient {
   void *hdl;
   CMCIClientFT *ft;
};   


#ifdef _WIN32
	#ifdef WSMAN_STATIC_LIB
		#define CMCI_Export
	#else
		#ifdef CMCI_DLL
			#define CMCI_Export  __declspec (dllexport)
		#else
			#define CMCI_Export  __declspec (dllimport)
		#endif
	#endif
#else
	#define CMCI_Export
#endif

/*
 * Initialize the wsman client library.
 * This initialization is required to initialize openwsman library which is needed to initialize libxml2
 */
CMCI_Export int cmci_init (void);

/*
 * Cleanup wsman client library.
 * This cleanup is required to cleanup openwsman library which is needed to cleanup libxml2
 */
CMCI_Export int cmci_cleanup (void);

CMCI_Export CMCIClient *cmciConnect(const char *hn, const char *scheme, const char *port, 
                        const char *user, const char *pwd, const char *auth, CMPIStatus *rc);

CMCI_Export CMCIClient *cmciConnect2(const char *hn, const char *scheme, const char *port, 
			const char *user, const char *pwd, const char *auth, 
			int verifyPeer, int verifyHost, const char* caInfo, const char*caPath, 
			const char* certFile, const char* keyFile, const char* proxy, const char* proxyUser,
			const char* Pwd, unsigned long timeout, CMPIStatus *rc);

int sameCMPIObjectPath ( const CMPIObjectPath *cop1, const CMPIObjectPath *cop2);


  /*
   * CMCIEnv function table definition
   */
   
  struct _CMCIEnv;
  typedef struct _CMCIEnv CMCIEnv;
  
  typedef struct _CMCIEnvFT {
    char *env;
    void* (*release)(CMCIEnv *ce);
    CMCIClient* (*connect)
      (CMCIEnv *ce, const char *hn, const char *scheme, const char *port, 
       const char *user, const char *pwd, const char* auth, CMPIStatus *rc);
    CMCIClient* (*connect2)
      (CMCIEnv *ce, const char *hn, const char *scheme, const char *port, 
       const char *user, const char *pwd, const char* auth,
       int verifyPeer, int verifyHost, const char* caInfo, const char*caPath, 
       const char* certFile, const char* keyFile, const char* proxy, const char* proxyUser,
       const char* Pwd, unsigned long timeout, CMPIStatus *rc);
    CMPIInstance* (*newInstance)
      (CMCIEnv *ce, const CMPIObjectPath* op, CMPIStatus* rc);
    CMPIObjectPath* (*newObjectPath)
      (CMCIEnv *ce, const char *ns, const char *cn, CMPIStatus* rc);
    CMPIArgs* (*newArgs)
      (CMCIEnv *ce, CMPIStatus* rc);
    CMPIString* (*newString)
      (CMCIEnv *ce, const char *data, CMPIStatus* rc);
    CMPIArray* (*newArray)
      (CMCIEnv *ce, CMPICount max, CMPIType type, CMPIStatus* rc);
    CMPIDateTime* (*newDateTime)
      (CMCIEnv *ce, CMPIStatus* rc);
    CMPIDateTime* (*newDateTimeFromBinary)
      (CMCIEnv *ce, CMPIUint64 binTime, CMPIBoolean interval, CMPIStatus* rc);
    CMPIDateTime* (*newDateTimeFromChars)
      (CMCIEnv *ce, const char *utcTime, CMPIStatus* rc);
  } CMCIEnvFT;

  struct _CMCIEnv {
    void *hdl;
    const CMCIEnvFT *ft;
  };

  /*
   * Prototype for CIMC Implementation Factory Function
   */
  typedef CMCIEnv *(*InitCMCIEnv) (const char *id, unsigned int options, int *rc, char **msg);

/* ------- event receiver functions ------------- */
typedef struct
{
	char*	name;
	char*	value;
} EventData_T;

typedef int (*fpWsmcEventReceiver_T) (EventData_T* eventData, void* data);

CMCI_Export void* cmciStartEventReceiver (int port, const char* servicePath, fpWsmcEventReceiver_T callBack,
									  void* data);
CMCI_Export int	  cmciStopEventReceiver	 (void* handle);

CMCI_Export extern int	 g_lapi_verbose_level;
CMCI_Export extern char* g_lapi_verbose_file;

#ifdef __cplusplus
 };
#endif

#endif // _CMPIC_H_
