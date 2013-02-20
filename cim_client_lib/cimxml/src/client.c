
/*
 * client.c
 *
 * (C) Copyright IBM Corp. 2005
 * (C) Copyright Intel Corp. 2005
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


#include <cmci/cmci.h>
#include "utilft.h"
#include <cmci/native.h>

#include <cimc/cimc.h>

#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include "cimXmlParser.h"
#include <windows.h>

#define CIMSERVER_TIMEOUT	(10 * 60) /* 10 minutes max per operation */

#ifdef DEBUG
#undef DEBUG
#define DEBUG 1
#else
#define DEBUG 0
#endif

#ifdef DMALLOC
#include "dmalloc.h"
#endif

void list2StringBuffer(UtilStringBuffer *sb, UtilList *ul, char *sep);
char *getResponse(CMCIConnection *con, CMPIObjectPath *cop);
CMCIConnection *initConnection(CMCIClientData *cld);

extern UtilList *getNameSpaceComponents(CMPIObjectPath * cop);
extern void pathToXml(UtilStringBuffer *sb, CMPIObjectPath *cop);
extern char *value2Chars(CMPIType type, CMPIValue * value);
extern char *pathToChars(CMPIObjectPath * cop, CMPIStatus * rc, char *str,
								 int uri);
char * cmpiToXmlType(CMPIType cmpiType);

#if DEBUG
int do_debug = 1;	/* simple enable debug messages flag */

#define SET_DEBUG()	set_debug();

static void set_debug()
{
    static int firsttime = 1;
    char *dbg;
    if (firsttime == 1) {
	firsttime--;
        do_debug = ((dbg = getenv("CMPISFCC_DEBUG")) != NULL &&
		    strcasecmp(dbg, "true") == 0);
    }
}
#else
#define SET_DEBUG()
#endif

//#if TIMING
#if 0
#define _T_FAILED	"FAIL"
#define _T_GOOD         "GOOD"

#define _T_STAMP(tv) \
       ((unsigned long long)((tv).tv_sec*1000000ull + (tv).tv_usec))
#define START_TIMING(funcstr) \
       struct timeval _tvs, _tve; \
       const char *fstr = funcstr; \
       gettimeofday(&_tvs, NULL);
#define END_TIMING(sitestr) \
       gettimeofday(&_tve, NULL); \
       printf("!#Timing - %s ticks: %llu - %s#!\n", \
                  fstr, (unsigned long long)(_T_STAMP(_tve)-_T_STAMP(_tvs)), sitestr);
#else
#define START_TIMING(funcstr)
#define END_TIMING(sitestr)
#endif


/* static const strings for IMETHODCALL names */
static const char EnumerateInstanceNames[] = "EnumerateInstanceNames";
static const char GetInstance[] = "GetInstance";
static const char CreateInstance[] = "CreateInstance";
static const char ModifyInstance[] = "ModifyInstance";
static const char DeleteInstance[] = "DeleteInstance";
static const char ExecQuery[] = "ExecQuery";
static const char EnumerateInstances[] = "EnumerateInstances";
static const char Associators[] = "Associators";
static const char AssociatorNames[] = "AssociatorNames";
static const char References[] = "References";
static const char ReferenceNames[] = "ReferenceNames";
static const char SetProperty[] = "SetProperty";
static const char GetProperty[] = "GetProperty";
static const char GetClass[] = "GetClass";
static const char EnumerateClassNames[] = "EnumerateClassNames";
static const char EnumerateClasses[] = "EnumerateClasses";

typedef const struct _CMCIConnectionFT {
    CMPIStatus (*release) (CMCIConnection *);
    char *(*genRequest)(ClientEnc *cle, const char *op, CMPIObjectPath *cop,
						  int classWithKeys);
    char *(*addPayload)(CMCIConnection *, UtilStringBuffer *pl);
    char *(*getResponse)(CMCIConnection *con, CMPIObjectPath *cop);
    void (*initializeHeaders)(CMCIConnection *con);
    void (*reset)(CMCIConnection *);
} CMCIConnectionFT;

struct _ClientEnc {
   CMCIClient          enc;
   CMCIClientData      data;
   CMCICredentialData  certData;
   CMCIConnection     *connection;
};

#define MAX_PLAUSIBLE_PROGRESS 30
#define MAX_PROGRESS_FIXUPS    10

struct _TimeoutControl {
  time_t   mTimestampStart;
  time_t   mTimestampLast;
  unsigned mFixups;
};

struct _CMCIConnection {
    CMCIConnectionFT *ft;        
    CURL *mHandle;               // The handle to the curl object
    struct curl_slist *mHeaders; // The list of headers sent with each request
    UtilStringBuffer *mBody;     // The body of the request
    UtilStringBuffer *mUri;      // The uri of the request
    UtilStringBuffer *mUserPass; // The username/password used in authentication
    UtilStringBuffer *mResponse; // Used to store the HTTP response
    CMPIStatus        mStatus;   // returned request status (via HTTP trailers)               
    struct _TimeoutControl mTimeout; /* Used for timeout control */
};

/* --------------------------------------------------------------------------*/

static CMPIStatus cloneStatus(CMPIStatus st)
{
  CMPIStatus rc;
  rc.rc = st.rc;
  if (st.msg) {
    rc.msg = CMClone(st.msg,NULL);
  } else {
    rc.msg = NULL;
  }
  return rc;
}

static char *getErrorMessage(CURLcode err)
{
#if LIBCURL_VERSION_NUM >= 0x071200
    return curl_easy_strerror(err);
#else
    char error[64];
    sprintf(error,"CURL error: %d", err);
    return strdup(error);
#endif
}

/* --------------------------------------------------------------------------*/

void list2StringBuffer(UtilStringBuffer *sb, UtilList *ul, char *sep)
{
   void *e;
   for (e=ul->ft->getFirst(ul); e; e=ul->ft->getNext(ul)) {
      sb->ft->appendChars(sb,(char*)e);
      sb->ft->appendChars(sb,sep);
   }
}

/* --------------------------------------------------------------------------*/

static size_t writeHeaders(void *ptr, size_t size,
				  size_t nmemb, void *stream)
{
  
  CMPIStatus *status=(CMPIStatus*)stream;
  char *str=ptr;
  char *colonidx; 
  
  if (str[nmemb-1] != 0) {
    /* make sure the string is zero-terminated */
      str = malloc(nmemb + 1);
      memcpy(str,ptr,nmemb);
      str[nmemb] = 0;
  } else {
    str = strdup(ptr);
  }
  colonidx=strchr(str,':');
  if (colonidx) {
    *colonidx=0;
    if (strcasecmp(str,"cimstatuscode") == 0) {
      /* set status code */
      status->rc = atoi(colonidx+1);
      }
      else
      if (strcasecmp(str, "cimstatuscodedescription") == 0) {
      status->msg=newCMPIString(colonidx+1,NULL);
    }
  }
  free(str);
  return nmemb;
}

/* --------------------------------------------------------------------------*/

static size_t writeCb(void *ptr, size_t size,
					size_t nmemb, void *stream)
{
    UtilStringBuffer *sb=(UtilStringBuffer*)stream;
    unsigned int length = size * nmemb;
    sb->ft->appendBlock(sb, ptr, length);
    return length;
}


static int checkProgress(void *data,
			 double total,
			 double actual,
			 double ign1,
			 double ign2)
{
  struct _TimeoutControl * timeout;
  time_t timestampNow;

  timeout = (struct _TimeoutControl*)data;
  timestampNow = time(NULL);
  
  /* we received everything and don't care about timeouts */
  if (total == actual) {
    return 0;
  }
  if (timeout->mFixups > MAX_PROGRESS_FIXUPS) {
    /* to many fixups occured -> fail */
    return 1;
  }
  if (timeout->mTimestampStart == 0 || 
      timeout->mTimestampLast > timestampNow ||
      timestampNow - timeout->mTimestampLast > MAX_PLAUSIBLE_PROGRESS ) {
    /* need to fix up - either first call or system time changed */
    timeout->mFixups += 1;
    timeout->mTimestampStart = timestampNow;
    timeout->mTimestampLast = timestampNow;
    return 0;
  }
  if (timestampNow - timeout->mTimestampStart < CIMSERVER_TIMEOUT) {
    timeout->mTimestampLast = timestampNow;
    return 0; 
  } else {
    return 1;
  }
}


/* --------------------------------------------------------------------------*/

static CMPIStatus releaseConnection(CMCIConnection *con)
{
  CMPIStatus rc = {CMPI_RC_OK,NULL};
  if (con->mHeaders) {
    curl_slist_free_all(con->mHeaders);
    con->mHeaders = NULL;
  }
  curl_easy_cleanup(con->mHandle);
  if (con->mBody) CMRelease(con->mBody);
  if (con->mUri) CMRelease(con->mUri);
  if (con->mUserPass) CMRelease(con->mUserPass);
  if (con->mResponse) CMRelease(con->mResponse);
  if (con->mStatus.msg) CMRelease(con->mStatus.msg);

  free(con);
  return rc;
}

/* --------------------------------------------------------------------------*/

static char *addPayload(CMCIConnection *con, UtilStringBuffer *pl)
{
//    con->mBody = pl;
//    if (dumpXml)
//        cerr << "To server: " << pl << endl;

    CURLcode rv;

    rv = curl_easy_setopt(con->mHandle, CURLOPT_POSTFIELDS,
					pl->ft->getCharPtr(pl));
    if (rv) return getErrorMessage(rv);
    rv = curl_easy_setopt(con->mHandle, CURLOPT_POSTFIELDSIZE,
					pl->ft->getSize(pl));
    if (rv) return getErrorMessage(rv);
    return NULL;
}

/* --------------------------------------------------------------------------*/

static char* genRequest(ClientEnc *cle, const char *op,
			CMPIObjectPath *cop, int classWithKeys)
{
   CMCIConnection   *con = cle->connection;
   CMCIClientData   *cld = &cle->data;
   UtilList 	    *nsc;
   char		    method[256]    = "CIMMethod: ";
   char		    CimObject[512] = "CIMObject: ";
   char		    *nsp;

   if (!con->mHandle) return "Unable to initialize curl interface.";

//    if (!supportsSSL() && url.scheme == "https")
//        throw HttpException("this curl library does not support https urls.");

   con->mResponse->ft->reset(con->mResponse);

   con->mUri->ft->reset(con->mUri);
   con->mUri->ft->append6Chars(con->mUri, cld->scheme, "://", cld->hostName,
						  ":", cld->port, "/cimom");

   /* Initialize curl with the url */
   curl_easy_setopt(con->mHandle, CURLOPT_URL,
				  con->mUri->ft->getCharPtr(con->mUri));

   /* Enable progress checking */
   curl_easy_setopt(con->mHandle, CURLOPT_NOPROGRESS, 0);
   
   /* Reset timeout control */
   con->mTimeout.mTimestampStart = 0;
   con->mTimeout.mTimestampLast = 0;
   con->mTimeout.mFixups = 0;

   /* This will be a HTTP post */
   curl_easy_setopt(con->mHandle, CURLOPT_POST, 1);

   /* Disable SSL Host verification */
   curl_easy_setopt(con->mHandle, CURLOPT_SSL_VERIFYHOST, 0);

   /* Setup authentication */
   curl_easy_setopt(con->mHandle, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);

   /* Set username and password */
   if (cld->user != NULL) {
      UtilStringBuffer *UserPass = con->mUserPass;

      UserPass->ft->reset(UserPass);
      UserPass->ft->appendChars(UserPass, cld->user);
      if (cld->pwd)
	 UserPass->ft->append3Chars(UserPass, ":", cld->pwd, NULL);
      /* Setup "<userid>:<password>" */
      curl_easy_setopt(con->mHandle, CURLOPT_USERPWD,
				     UserPass->ft->getCharPtr(UserPass));
   }

   /* initialize status */
   CMSetStatus(&con->mStatus,CMPI_RC_OK);

   /* Setup connect timeouts for cimserver operations */
   curl_easy_setopt(con->mHandle, CURLOPT_NOSIGNAL, 1);
   curl_easy_setopt(con->mHandle, CURLOPT_CONNECTTIMEOUT, CIMSERVER_TIMEOUT);

   /* setup callback for client timeout calculations */
   curl_easy_setopt(con->mHandle, CURLOPT_PROGRESSFUNCTION, checkProgress);
   curl_easy_setopt(con->mHandle, CURLOPT_PROGRESSDATA, &con->mTimeout);

   // Initialize default headers
   con->ft->initializeHeaders(con);

   // Add CIMMethod header
   strcat(method, op);
   con->mHeaders = curl_slist_append(con->mHeaders, method);

   // Add CIMObject header with cop's namespace, class, keys
   if (classWithKeys)
       pathToChars(cop, NULL, &CimObject[11], 1);
   else {
       nsc = getNameSpaceComponents(cop);
       nsp = nsc->ft->getFirst(nsc);
       while (nsp != NULL) {
	   strcat(CimObject, nsp);
	   free(nsp); /* VM: freeing strdup'ed memory - should be part of release */
           if ((nsp = nsc->ft->getNext(nsc)) != NULL)
	       strcat(CimObject, "%2F");
       }
       CMRelease(nsc);
   }
   con->mHeaders = curl_slist_append(con->mHeaders, CimObject);

   // Set all of the headers for the request
   curl_easy_setopt(con->mHandle, CURLOPT_HTTPHEADER, con->mHeaders);

   // Set up the callbacks to store the response
   curl_easy_setopt(con->mHandle, CURLOPT_WRITEFUNCTION, writeCb);

   // Use CURLOPT_FILE instead of CURLOPT_WRITEDATA - more portable
   curl_easy_setopt(con->mHandle, CURLOPT_FILE, con->mResponse);

   // Header processing: 
   curl_easy_setopt(con->mHandle, CURLOPT_WRITEHEADER, &con->mStatus);
   curl_easy_setopt(con->mHandle, CURLOPT_HEADERFUNCTION, writeHeaders);

   // Fail if we receive an error (HTTP response code >= 300)
   curl_easy_setopt(con->mHandle, CURLOPT_FAILONERROR, 1);

   // Turn this on to enable debugging
#if DEBUG
   curl_easy_setopt(con->mHandle, CURLOPT_VERBOSE, do_debug);
#endif

   return NULL;
}

/* --------------------------------------------------------------------------*/

char *getResponse(CMCIConnection *con, CMPIObjectPath *cop)
{
    CURLcode rv;

    rv = curl_easy_perform(con->mHandle);

    /* indicate timeout error for aborted by progess handler */
    if (rv == CURLE_ABORTED_BY_CALLBACK) {
      rv = CURLE_OPERATION_TIMEOUTED;
    }

    if (rv) {
        long responseCode = -1;
        // Use CURLINFO_HTTP_CODE instead of CURLINFO_RESPONSE_CODE
        // (more portable to older versions of curl)
        curl_easy_getinfo(con->mHandle, CURLINFO_HTTP_CODE, &responseCode);
        return (responseCode == 401) ? strdup("Invalid username/password") :
				       getErrorMessage(rv);
    }

    if (con->mResponse->ft->getSize(con->mResponse) == 0)
        return strdup("No data received from server");
    
    return NULL;
}

/* --------------------------------------------------------------------------*/

static void initializeHeaders(CMCIConnection *con)
{
    static const char *headers[] = {
	"Content-type: application/xml; charset=\"utf-8\"",
	"Accept:",
	"Expect:",
	"CIMProtocolVersion: 1.0",
	"CIMOperation: MethodCall",
#ifdef HAVE_HTTP_CHUNKING
	"TE: trailers",
#endif
	NULL
    };
    unsigned int i;

    if (con->mHeaders) {
        curl_slist_free_all(con->mHeaders);
        con->mHeaders = NULL;
    }
    for (i = 0; headers[i]!= NULL; i++)
        con->mHeaders = curl_slist_append(con->mHeaders, headers[i]);
}

static CMCIConnectionFT conFt={
  releaseConnection,
  genRequest,
  addPayload,
  getResponse,
  initializeHeaders
};

/* --------------------------------------------------------------------------*/

CMCIConnection *initConnection(CMCIClientData *cld)
{
   CMCIConnection *c=(CMCIConnection*)calloc(1,sizeof(CMCIConnection));
   c->ft=&conFt;
   c->mHandle = curl_easy_init();
   c->mHeaders = NULL;
   c->mBody = UtilFactory->newStringBuffer(256);
   c->mUri = UtilFactory->newStringBuffer(256);
   c->mUserPass = UtilFactory->newStringBuffer(64);
   c->mResponse = UtilFactory->newStringBuffer(2048);

   return c;
}

/*--------------------------------------------------------------------------*/

typedef struct XmlSpecialCharItem {
    const char XmlAscii;
    const char *XmlEscape;
    const int  XmlEscapeSize;
} XmlSpecialChar;

static const XmlSpecialChar XmlEscapes[] = {
     {0x22, "&quot;",	6},	/* '"' */
     {0x26, "&amp;",	5},	/* '&' */
     {0x27, "&apos;",	6},	/* ''' */
     {0x3c, "&lt;",	4},	/* '<' */
     {0x3e, "&gt;",	4},	/* '>' */
};

#define SizeofXmlEscapes (sizeof(XmlEscapes)/sizeof(XmlSpecialChar))

char XmlToAscii(char **XmlStr);
char * XmlToAsciiStr(char *XmlStr);
char * AsciiToXmlStr(char *Ap);

char XmlToAscii(char **XmlStr)
{
    char rval;
    int i;
    if ((rval = *XmlStr[0]) == '&')
    {
        for (i = 0; i < SizeofXmlEscapes; ++i)
        {
            if (strncmp(*XmlStr, XmlEscapes[i].XmlEscape,
                                 XmlEscapes[i].XmlEscapeSize) == 0)
            {
                *XmlStr += XmlEscapes[i].XmlEscapeSize;
                return XmlEscapes[i].XmlAscii;
            }
        }
    }
    (*XmlStr)++;
    return rval;
}

char * XmlToAsciiStr(char *XmlStr)
{
    char *AsciiStr = malloc(strlen(XmlStr) + 1); /* assume ascii <= xml len */
    char *Ap = AsciiStr;
    char *Xp = XmlStr;
    while (*Xp != '\0')
    {
        *Ap++ = XmlToAscii(&Xp);
    }
    *Ap = '\0';
    return AsciiStr;
}

char * AsciiToXmlStr(char *AsciiStr)
{
    char *Ap;
    char *XmlStr; 
    int  Xlen;
    int  i;
    size_t buflen;
    if (AsciiStr) {
      buflen = strlen(AsciiStr) + 1;
      XmlStr = malloc(buflen);
    }
    if (XmlStr) {
      Xlen = 0;
      for (Ap = AsciiStr; *Ap != '\0'; Ap++)
	{
	  for (i = 0; i < SizeofXmlEscapes; ++i)
            if (*Ap == XmlEscapes[i].XmlAscii)
	      break;
	  if (i < SizeofXmlEscapes)
	    {
	      if (buflen - Xlen <= XmlEscapes[i].XmlEscapeSize) {
		buflen = 2 * buflen;
		XmlStr = realloc(XmlStr,buflen);
		if (XmlStr == NULL) {
		  break;
		}
	      }
	      memcpy(XmlStr + Xlen, XmlEscapes[i].XmlEscape, XmlEscapes[i].XmlEscapeSize);
	      Xlen += XmlEscapes[i].XmlEscapeSize;
	    }
	  else
            XmlStr[Xlen++] = *Ap;
	}
      XmlStr[Xlen] = '\0';
    }
    return XmlStr;
}

/*--------------------------------------------------------------------------*/
static void emitlocal(UtilStringBuffer *sb, int f)
{
   sb->ft->append3Chars(sb, "<IPARAMVALUE NAME=\"LocalOnly\"><VALUE>",
			    f != 0? "TRUE" : "FALSE",
			    "</VALUE></IPARAMVALUE>\n");
}

/* --------------------------------------------------------------------------*/

static void emitqual(UtilStringBuffer *sb, int f)
{
   sb->ft->append3Chars(sb, "<IPARAMVALUE NAME=\"IncludeQualifiers\"><VALUE>",
			    f != 0 ? "TRUE" : "FALSE",
			    "</VALUE></IPARAMVALUE>\n");
}

/* --------------------------------------------------------------------------*/

static void emitorigin(UtilStringBuffer *sb, int f)
{
   sb->ft->append3Chars(sb, "<IPARAMVALUE NAME=\"IncludeClassOrigin\"><VALUE>",
			    f != 0 ? "TRUE" : "FALSE",
			    "</VALUE></IPARAMVALUE>\n");
}

/* --------------------------------------------------------------------------*/

static void emitdeep(UtilStringBuffer *sb, int f)
{
   sb->ft->append3Chars(sb, "<IPARAMVALUE NAME=\"DeepInheritance\"><VALUE>",
			    f != 0 ? "TRUE" : "FALSE",
			    "</VALUE></IPARAMVALUE>\n");
}

/* --------------------------------------------------------------------------*/

static void addXmlValue(UtilStringBuffer *sb, 
                        char *ContainerTag,
                        char *ContainerType,
                        char *ValueName, 
                        CMPIData data)
{
    int       isArray     = CMIsArray(data);
    char      *arrayStr   = isArray ? ".ARRAY" : "";
    CMPIType  valtyp      = data.type & ~CMPI_ARRAY; 
    char      *xmlTypeStr = cmpiToXmlType(valtyp);
    char      *cv;
    int       i, n;
    /* If empty data item, skip out without outputting */
    if ((data.state & CMPI_nullValue) ||
        (isArray && (n = CMGetArrayCount(data.value.array, NULL)) == 0) )
    {
        return;
    }
    
    if(strcasecmp(ContainerTag, "PARAMVALUE")) {
    	sb->ft->append3Chars(sb, "<", ContainerTag, arrayStr);
    }
    else {
    	sb->ft->appendChars(sb, "<");
    	sb->ft->appendChars(sb, ContainerTag);
    }
    sb->ft->append3Chars(sb, " NAME=\"", ValueName, "\"");
    if (xmlTypeStr)
        sb->ft->append5Chars(sb, " ", ContainerType, "=\"", xmlTypeStr, "\"");
    sb->ft->appendChars(sb, ">\n");
    if (isArray)
    {
        CMPIArray *arr   = data.value.array;
        sb->ft->appendChars(sb, "<VALUE.ARRAY>\n");
        for (i = 0; i < n; ++i)
        {
            CMPIData ele = CMGetArrayElementAt(arr, i, NULL);
            cv = value2Chars(valtyp, &ele.value);
            if (valtyp == CMPI_string || valtyp == CMPI_chars)
{
                char *xmlValStr  = AsciiToXmlStr(cv);
                if (cv) free(cv);
                cv = xmlValStr;
            }
            sb->ft->append3Chars(sb, "<VALUE>", cv, "</VALUE>\n");
            free (cv);
        }
        sb->ft->appendChars(sb, "</VALUE.ARRAY>\n");
    }
    else
    {
        cv = value2Chars(valtyp, &(data.value));
        if (valtyp == CMPI_string || valtyp == CMPI_chars)
        {
            char *xmlValStr  = AsciiToXmlStr(cv);
            if (cv) free(cv);
            cv = xmlValStr;
        }
        sb->ft->append3Chars(sb, "<VALUE>", cv, "</VALUE>\n");
        free(cv);
    }
    if(strcasecmp(ContainerTag, "PARAMVALUE")) {
    	sb->ft->append5Chars(sb, "</", ContainerTag, arrayStr, ">", "\n");
    }
    else {
    	sb->ft->append3Chars(sb, "</", ContainerTag, ">");
    	sb->ft->appendChars(sb, "\n");
    }    
}

/* --------------------------------------------------------------------------*/

static void addXmlNamespace(UtilStringBuffer *sb, CMPIObjectPath *cop)
{
   UtilList *nsc = getNameSpaceComponents(cop);
   char *nsp;

   sb->ft->appendChars(sb,"<LOCALNAMESPACEPATH>\n");
   for (nsp = nsc->ft->getFirst(nsc); nsp; nsp = nsc->ft->getNext(nsc)) {
      sb->ft->append3Chars(sb, "<NAMESPACE NAME=\"", nsp, "\"></NAMESPACE>\n");
      free(nsp);
   }
   sb->ft->appendChars(sb, "</LOCALNAMESPACEPATH>\n");
   CMRelease(nsc);
}

/* --------------------------------------------------------------------------*/

static void addXmlObjectName(UtilStringBuffer *sb, CMPIObjectPath *cop,
					      const char *ValueTagName)
{
   CMPIString *cn = cop->ft->getClassName(cop, NULL);
   sb->ft->append5Chars(sb, "<IPARAMVALUE NAME=\"",
			    ValueTagName,
			    "\">\n<INSTANCENAME CLASSNAME=\"",
			    (char *)cn->hdl, "\">\n");
   pathToXml(sb, cop);
   sb->ft->appendChars(sb,"</INSTANCENAME>\n</IPARAMVALUE>\n");
   CMRelease(cn);
}

/* --------------------------------------------------------------------------*/

static void addXmlClassnameParam(UtilStringBuffer *sb, CMPIObjectPath *cop)
{
   CMPIString *cn = cop->ft->getClassName(cop, NULL);
   if (cn->hdl && *((char*)cn->hdl)) {
      sb->ft->append3Chars(sb,
	      "<IPARAMVALUE NAME=\"ClassName\"><CLASSNAME NAME=\"",
	      (char*)cn->hdl, "\"/></IPARAMVALUE>\n");
   }
   CMRelease(cn);
}

/* --------------------------------------------------------------------------*/

static void addXmlHeader(UtilStringBuffer *sb)
{
   static const char xmlHeader[]={
      "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\n"
      "<CIM CIMVERSION=\"2.0\" DTDVERSION=\"2.0\">\n"
      "<MESSAGE ID=\"4711\" PROTOCOLVERSION=\"1.0\">\n"
      "<SIMPLEREQ>\n"
   };

   sb->ft->appendChars(sb, xmlHeader);
}

/* --------------------------------------------------------------------------*/

static void addXmlFooter(UtilStringBuffer *sb)
{
   static const char xmlFooter[]={
      "</SIMPLEREQ>\n"
      "</MESSAGE>\n"
      "</CIM>\n"
   };

   sb->ft->appendChars(sb, xmlFooter);
}

/* --------------------------------------------------------------------------*/

static void addXmlPropertyListParam(UtilStringBuffer *sb, char** properties)
{
   sb->ft->appendChars(sb, "<IPARAMVALUE NAME=\"PropertyList\"><VALUE.ARRAY>");
   while (*properties) {
       sb->ft->append3Chars(sb, "<VALUE>", *properties, "</VALUE>");
       properties++;
   }
   sb->ft->appendChars(sb, "</VALUE.ARRAY></IPARAMVALUE>\n");
}

/* --------------------------------------------------------------------------*/

static void addXmlNamedInstance(UtilStringBuffer *sb,
                                CMPIObjectPath * cop, CMPIInstance * inst)
{
   CMPIString       * cn;
   int		      i;
   int                numproperties = inst->ft->getPropertyCount(inst, NULL);
   CMPIData	      propertydata;
   CMPIString	    * propertyname;

   if (cop == NULL)
       cop = inst->ft->getObjectPath(inst, NULL);

   cn  = cop->ft->getClassName(cop, NULL);

   sb->ft->appendChars(sb, "<VALUE.NAMEDINSTANCE>\n");

   /* Add the objectpath */
   sb->ft->append3Chars(sb, "<INSTANCENAME CLASSNAME=\"",
                            (char *)cn->hdl, "\">\n");
   pathToXml(sb, cop);
   sb->ft->appendChars(sb,"</INSTANCENAME>\n");

   /* Add the instance */
   sb->ft->append3Chars(sb,"<INSTANCE CLASSNAME=\"", (char*)cn->hdl, "\">\n");
   CMRelease(cn);

   for (i = 0; i < numproperties; i++)
   {
      propertydata = inst->ft->getPropertyAt(inst, i, &propertyname, NULL);
      addXmlValue(sb, "PROPERTY", "TYPE", propertyname->hdl,
                                              propertydata);
      if(propertyname) CMRelease(propertyname);
   }
   sb->ft->appendChars(sb,"</INSTANCE>\n");

   sb->ft->appendChars(sb,"</VALUE.NAMEDINSTANCE>\n");
}

/* --------------------------------------------------------------------------*/
/* --------------------------------------------------------------------------*/

static CMCIClient * cloneClient ( CMCIClient * cl, CMPIStatus * st )
{
  CMPIStatus rc;
  CMSetStatusWithChars(&rc, CMPI_RC_ERR_NOT_SUPPORTED, "Clone function not supported");
  if (st) *st=rc;
  return NULL;
}  

static CMPIStatus releaseClient(CMCIClient * mb)
{
  CMPIStatus rc={CMPI_RC_OK,NULL};
  ClientEnc		* cl = (ClientEnc*)mb;
  
  if (cl->data.hostName) {
    free(cl->data.hostName);
  }
  if (cl->data.user) {
    free(cl->data.user);
  }
  if (cl->data.pwd) {
    free(cl->data.pwd);
  }
  if (cl->data.scheme) {
    free(cl->data.scheme);
  }
  if (cl->data.port) {
    free(cl->data.port);
  }
  if (cl->certData.trustStore) {
    free(cl->certData.trustStore);
  }
  if (cl->certData.certFile) {
    free(cl->certData.certFile);
  }
  if (cl->certData.keyFile) {
    free(cl->certData.keyFile);
  }
 
  if (cl->connection) CMRelease(cl->connection);

  free(cl);
  return rc;
}

static CMPIEnumeration * enumInstanceNames(
	CMCIClient * mb,
	CMPIObjectPath * cop,
	CMPIStatus * rc)
{
   ClientEnc		* cl = (ClientEnc*)mb;
   CMCIConnection	* con = cl->connection;
   UtilStringBuffer	* sb = UtilFactory->newStringBuffer(2048);
   char			* error;
   ResponseHdr		rh;
   CMPIEnumeration      *retval;

   START_TIMING(EnumerateInstanceNames);
   SET_DEBUG();

   con->ft->genRequest(cl, EnumerateInstanceNames, cop, 0);

   /* Construct the CIM-XML request */
   addXmlHeader(sb);
   sb->ft->append3Chars(sb, "<IMETHODCALL NAME=\"", EnumerateInstanceNames, "\">");

   addXmlNamespace(sb, cop);
   addXmlClassnameParam(sb, cop);

   sb->ft->appendChars(sb,"</IMETHODCALL>\n");
   addXmlFooter(sb);

   error = con->ft->addPayload(con, sb);

   if (error || (error = con->ft->getResponse(con, cop))) {
      CMSetStatusWithChars(rc, CMPI_RC_ERR_FAILED, error);
      free(error);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return NULL;
   }
 
   if (con->mStatus.rc != CMPI_RC_OK) {
      if (rc)
	*rc=cloneStatus(con->mStatus);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return NULL;
   }

   CMRelease(sb);

   rh = scanCimXmlResponse(CMGetCharPtr(con->mResponse), cop);

   if (rh.errCode != 0) {
      CMSetStatusWithChars(rc, rh.errCode, rh.description);
      free(rh.description);
      CMRelease(rh.rvArray);
      END_TIMING(_T_FAILED);
      return NULL;
   }

#if DEBUG
   if (do_debug)
       printf ("\treturn enumeration array type %d expected CMPI_ref %d\n",
	        rh.rvArray->ft->getSimpleType(rh.rvArray, NULL), CMPI_ref);
#endif

   CMSetStatus(rc,CMPI_RC_OK);
   retval = newCMPIEnumeration(rh.rvArray, NULL);
   END_TIMING(_T_GOOD);
   return retval;
}

/* --------------------------------------------------------------------------*/

static CMPIInstance * getInstance(
	CMCIClient * mb,
	CMPIObjectPath * cop,
	CMPIFlags flags,
	char ** properties,
	CMPIStatus * rc)
/*
<?xml version="1.0" encoding="utf-8"?>
<CIM CIMVERSION="2.0" DTDVERSION="2.0">
  <MESSAGE ID="4711" PROTOCOLVERSION="1.0">
    <SIMPLEREQ>
      <IMETHODCALL NAME="GetInstance">
        <LOCALNAMESPACEPATH>
          <NAMESPACE NAME="root"/>
          <NAMESPACE NAME="cimv2"/>
        </LOCALNAMESPACEPATH>
        <IPARAMVALUE NAME="LocalOnly">
          <VALUE>FALSE</VALUE>
        </IPARAMVALUE>
        <IPARAMVALUE NAME="IncludeClassOrigin">
          <VALUE>FALSE</VALUE>
        </IPARAMVALUE>
        <IPARAMVALUE NAME="IncludeQualifiers">
          <VALUE>FALSE</VALUE>
        </IPARAMVALUE>
        <IPARAMVALUE NAME="InstanceName">
          <INSTANCENAME CLASSNAME="Linux_ComputerSystem">
            <KEYBINDING NAME="CreationClassName">
              <KEYVALUE VALUETYPE="string">Linux_ComputerSystem</KEYVALUE>
            </KEYBINDING>
            <KEYBINDING NAME="Name">
              <KEYVALUE VALUETYPE="string">bestorga.ibm.com</KEYVALUE>
            </KEYBINDING>
          </INSTANCENAME>
        </IPARAMVALUE>
      </IMETHODCALL>
    </SIMPLEREQ>
  </MESSAGE>
</CIM>
*/
{
   CMPIInstance *cci;
   ClientEnc *cl=(ClientEnc*)mb;
   CMCIConnection *con=cl->connection;
   UtilStringBuffer *sb=UtilFactory->newStringBuffer(2048);
   char *error;
   ResponseHdr rh;

   START_TIMING(GetInstance);
   SET_DEBUG();

   con->ft->genRequest(cl, GetInstance, cop, 0);

   addXmlHeader(sb);
   sb->ft->append3Chars(sb, "<IMETHODCALL NAME=\"", GetInstance, "\">");

   addXmlNamespace(sb, cop);

   emitlocal(sb,flags & CMPI_FLAG_LocalOnly);
   emitorigin(sb,flags & CMPI_FLAG_IncludeClassOrigin);
   emitqual(sb,flags & CMPI_FLAG_IncludeQualifiers);

   if (properties != NULL)
	addXmlPropertyListParam(sb, properties);

   /* Add the instance classname */
   addXmlObjectName(sb, cop, "InstanceName");

   sb->ft->appendChars(sb,"</IMETHODCALL>\n");

   addXmlFooter(sb);

   error = con->ft->addPayload(con, sb);

   if (error || (error = con->ft->getResponse(con, cop))) {
      CMSetStatusWithChars(rc,CMPI_RC_ERR_FAILED,error);
      free(error);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return NULL;
   }

   if (con->mStatus.rc != CMPI_RC_OK) {
      if (rc)
	*rc=cloneStatus(con->mStatus);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return NULL;
   }

   CMRelease(sb);

   rh = scanCimXmlResponse(CMGetCharPtr(con->mResponse), cop);

   if (rh.errCode != 0) {
      CMSetStatusWithChars(rc, rh.errCode, rh.description);
      free(rh.description);
      CMRelease(rh.rvArray);
      END_TIMING(_T_FAILED);
      return NULL;
   }

#if DEBUG
   if (do_debug)
       printf ("\treturn type %d expected CMPI_instance %d\n",
	    rh.rvArray->ft->getSimpleType(rh.rvArray, NULL), CMPI_instance);
#endif

   CMSetStatus(rc,CMPI_RC_OK);
   cci = rh.rvArray->ft->getElementAt(rh.rvArray, 0, NULL).value.inst;
   cci = CMClone(cci,NULL);
   CMRelease(rh.rvArray);
   END_TIMING(_T_GOOD);
   return cci;
}

/* --------------------------------------------------------------------------*/

static CMPIObjectPath * createInstance(
	CMCIClient * mb,
	CMPIObjectPath * cop,
	CMPIInstance * inst,
	CMPIStatus * rc)
{
   ClientEnc        *cl  = (ClientEnc*)mb;
   CMCIConnection   *con = cl->connection;
   UtilStringBuffer *sb  = UtilFactory->newStringBuffer(2048);
   char             *error;
   ResponseHdr	    rh;
   int		    i, numproperties = inst->ft->getPropertyCount(inst, NULL);
   CMPIString	    *classname, *propertyname;
   CMPIData	    propertydata;
   CMPIObjectPath   *retval;

   START_TIMING(CreateInstance);
   SET_DEBUG();

   con->ft->genRequest(cl, CreateInstance, cop, 0);

   /* Construct the CIM-XML request */
   addXmlHeader(sb);

   sb->ft->append3Chars(sb, "<IMETHODCALL NAME=\"", CreateInstance, "\">");

   addXmlNamespace(sb, cop);

   classname = cop->ft->getClassName(cop, NULL);
   sb->ft->append3Chars(sb, "<IPARAMVALUE NAME=\"NewInstance\">\n"
			    "<INSTANCE CLASSNAME=\"",
			    (char *)classname->hdl, "\">\n");
   CMRelease(classname);

   /* Add all the instance properties */
   for (i=0; i<numproperties; i++) {
      propertydata = inst->ft->getPropertyAt(inst, i, &propertyname, NULL);
      addXmlValue(sb, "PROPERTY", "TYPE", propertyname->hdl, propertydata);
      if (propertyname) CMRelease(propertyname);
   }

   sb->ft->appendChars(sb,"</INSTANCE>\n</IPARAMVALUE>\n");
   sb->ft->appendChars(sb,"</IMETHODCALL>\n");
   addXmlFooter(sb);

   error = con->ft->addPayload(con,sb);

   if (error || (error = con->ft->getResponse(con, cop))) {
      CMSetStatusWithChars(rc,CMPI_RC_ERR_FAILED,error);
      free(error);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return NULL;
   }

   if (con->mStatus.rc != CMPI_RC_OK) {
      if (rc)
     *rc=cloneStatus(con->mStatus);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return NULL;
   }

   CMRelease(sb);

   rh = scanCimXmlResponse(CMGetCharPtr(con->mResponse), cop);
   if (rh.errCode != 0) {
      CMSetStatusWithChars(rc, rh.errCode, rh.description);
      free(rh.description);
      CMRelease(rh.rvArray);
      END_TIMING(_T_FAILED);
      return NULL;
   }

#if DEBUG
   if (do_debug)
       printf ("\treturn type %d expected CMPI_ref %d\n",
	    rh.rvArray->ft->getSimpleType(rh.rvArray, NULL), CMPI_ref);
#endif

   CMSetStatus(rc,CMPI_RC_OK);
   retval = rh.rvArray->ft->getElementAt(rh.rvArray, 0, NULL).value.ref;
   END_TIMING(_T_GOOD);
   return retval;
}

/* --------------------------------------------------------------------------*/

static CMPIStatus setInstance(
	CMCIClient * mb,
	CMPIObjectPath * cop,
	CMPIInstance * inst,
	CMPIFlags flags,
	char ** properties)
/*
<?xml version="1.0" encoding="utf-8"?>
<CIM CIMVERSION="2.0" DTDVERSION="2.0">
  <MESSAGE ID="4711" PROTOCOLVERSION="1.0">
    <SIMPLEREQ>
      <IMETHODCALL NAME="ModifyInstance">
        <LOCALNAMESPACEPATH>
          <NAMESPACE NAME="root"/>
          <NAMESPACE NAME="cimv2"/>
        </LOCALNAMESPACEPATH>
        <IPARAMVALUE NAME="ModifiedInstance">
          <VALUE.NAMEDINSTANCE>
            <INSTANCENAME CLASSNAME="CWS_Authorization">
              <KEYBINDING NAME="Username">
                <KEYVALUE VALUETYPE="string">foo</KEYVALUE>
              </KEYBINDING>
              <KEYBINDING NAME="Classname">
                <KEYVALUE VALUETYPE="string">bar</KEYVALUE>
              </KEYBINDING>
            </INSTANCENAME>
            <INSTANCE CLASSNAME="CWS_Authorization">
              <PROPERTY NAME="Username" TYPE="string">
                <VALUE>foo</VALUE>
              </PROPERTY>
              <PROPERTY NAME="Classname" TYPE="string">
                <VALUE>bar</VALUE>
              </PROPERTY>
              <PROPERTY NAME="Enumerate" TYPE="boolean">
                <VALUE>FALSE</VALUE>
              </PROPERTY>
              <PROPERTY NAME="Get" TYPE="boolean">
                <VALUE>FALSE</VALUE>
              </PROPERTY>
              <PROPERTY NAME="Set" TYPE="boolean">
                <VALUE>FALSE</VALUE>
              </PROPERTY>
              <PROPERTY NAME="Create" TYPE="boolean">
                <VALUE>FALSE</VALUE>
              </PROPERTY>
              <PROPERTY NAME="Delete" TYPE="boolean">
                <VALUE>FALSE</VALUE>
              </PROPERTY>
              <PROPERTY NAME="Query" TYPE="boolean">
                <VALUE>true</VALUE>
              </PROPERTY>
            </INSTANCE>
          </VALUE.NAMEDINSTANCE>
        </IPARAMVALUE>
      </IMETHODCALL>
    </SIMPLEREQ>
  </MESSAGE>
</CIM>
*/
{
   ClientEnc        *cl  = (ClientEnc*)mb;
   CMCIConnection   *con = cl->connection;
   UtilStringBuffer *sb  = UtilFactory->newStringBuffer(2048);
   char             *error;
   ResponseHdr      rh;
   CMPIStatus	    rc;

   START_TIMING(ModifyInstance);
   SET_DEBUG();

   con->ft->genRequest(cl, ModifyInstance, cop, 0);

   /* Construct the CIM-XML request */
   addXmlHeader(sb);
   sb->ft->append3Chars(sb, "<IMETHODCALL NAME=\"", ModifyInstance, "\">\n");

   addXmlNamespace(sb, cop);

   /* NOTE - IncludeQualifiers flag is now deprecated */
   emitqual(sb,flags & CMPI_FLAG_IncludeQualifiers);

   /* Add the property filter list */
   if (properties != NULL)
	addXmlPropertyListParam(sb, properties);

   sb->ft->appendChars(sb, "<IPARAMVALUE NAME=\"ModifiedInstance\">\n");
   addXmlNamedInstance(sb, cop, inst);
   sb->ft->appendChars(sb,"</IPARAMVALUE>\n");

   sb->ft->appendChars(sb,"</IMETHODCALL>\n");
   addXmlFooter(sb);

   error = con->ft->addPayload(con,sb);

   if (error || (error = con->ft->getResponse(con, cop))) {
      CMSetStatusWithChars(&rc,CMPI_RC_ERR_FAILED,error);
      free(error);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return rc;
   }

   if (con->mStatus.rc != CMPI_RC_OK) {
      rc=cloneStatus(con->mStatus);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return rc;
   }

   CMRelease(sb);

   rh = scanCimXmlResponse(CMGetCharPtr(con->mResponse), cop);
   if (rh.errCode != 0) {
      CMSetStatusWithChars(&rc, rh.errCode, rh.description);
      free(rh.description);
      CMRelease(rh.rvArray);
   }
   else
   CMSetStatus(&rc, CMPI_RC_OK);

   END_TIMING(_T_GOOD);
   return rc;
}

/* --------------------------------------------------------------------------*/

static CMPIStatus deleteInstance(
	CMCIClient * mb,
	CMPIObjectPath * cop)
/*
<?xml version="1.0" encoding="utf-8"?>
<CIM CIMVERSION="2.0" DTDVERSION="2.0">
  <MESSAGE ID="4711" PROTOCOLVERSION="1.0">
    <SIMPLEREQ>
      <IMETHODCALL NAME="DeleteInstance">
        <LOCALNAMESPACEPATH>
          <NAMESPACE NAME="root"/>
          <NAMESPACE NAME="cimv2"/>
        </LOCALNAMESPACEPATH>
        <IPARAMVALUE NAME="InstanceName">
          <INSTANCENAME CLASSNAME="CWS_Authorization">
            <KEYBINDING NAME="Username">
              <KEYVALUE VALUETYPE="string">bestorga</KEYVALUE>
            </KEYBINDING>
            <KEYBINDING NAME="Classname">
              <KEYVALUE VALUETYPE="string">foobar</KEYVALUE>
            </KEYBINDING>
          </INSTANCENAME>
        </IPARAMVALUE>
      </IMETHODCALL>
    </SIMPLEREQ>
  </MESSAGE>
</CIM>
*/
{
   ClientEnc		*cl = (ClientEnc*)mb;
   CMCIConnection	*con = cl->connection;
   UtilStringBuffer	*sb = UtilFactory->newStringBuffer(2048);
   char			*error;
   ResponseHdr		rh;
   CMPIString		*classname;
   CMPIStatus		rc;

   START_TIMING(DeleteInstance);
   SET_DEBUG();

   con->ft->genRequest(cl, DeleteInstance, cop, 0);

   addXmlHeader(sb);
   sb->ft->append3Chars(sb,"<IMETHODCALL NAME=\"", DeleteInstance, "\">");

   addXmlNamespace(sb, cop);

   /* Add instance stuff */
   classname = cop->ft->getClassName(cop, NULL);
   sb->ft->append3Chars(sb, "<IPARAMVALUE NAME=\"InstanceName\">\n"
			    "<INSTANCENAME CLASSNAME=\"",
			    (char*)classname->hdl,"\">\n");
   CMRelease(classname);

   pathToXml(sb, cop);

   sb->ft->appendChars(sb,"</INSTANCENAME>\n");
   sb->ft->appendChars(sb,"</IPARAMVALUE>\n");
   sb->ft->appendChars(sb,"</IMETHODCALL>\n");
   addXmlFooter(sb);

   error = con->ft->addPayload(con,sb);

   if (error || (error = con->ft->getResponse(con, cop))) {
      CMSetStatusWithChars(&rc,CMPI_RC_ERR_FAILED,error);
      free(error);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return rc;
   }

   if (con->mStatus.rc != CMPI_RC_OK) {
     rc=cloneStatus(con->mStatus);
     CMRelease(sb);
      END_TIMING(_T_FAILED);
     return rc;
   }

   CMRelease(sb);

   rh = scanCimXmlResponse(CMGetCharPtr(con->mResponse), cop);
   if (rh.errCode != 0) {
      CMSetStatusWithChars(&rc, rh.errCode, rh.description);
      free(rh.description);
      CMRelease(rh.rvArray);
   }
   else
   CMSetStatus(&rc, CMPI_RC_OK);

   END_TIMING(_T_GOOD);
   return rc;
}

/* --------------------------------------------------------------------------*/

/* finish but not working - scanCimXmlResponse fails parsing results */
static CMPIEnumeration * execQuery(
	CMCIClient * mb,
	CMPIObjectPath * cop,
	const char * query,
	const char * lang,
	CMPIStatus * rc)
/*
<?xml version="1.0" encoding="utf-8"?>
<CIM CIMVERSION="2.0" DTDVERSION="2.0">
  <MESSAGE ID="4711" PROTOCOLVERSION="1.0">
    <SIMPLEREQ>
      <IMETHODCALL NAME="ExecQuery">
        <LOCALNAMESPACEPATH>
          <NAMESPACE NAME="root"/>
          <NAMESPACE NAME="cimv2"/>
        </LOCALNAMESPACEPATH>
        <IPARAMVALUE NAME="QueryLanguage">
          <VALUE>WQL</VALUE>
        </IPARAMVALUE>
        <IPARAMVALUE NAME="Query">
          <VALUE>select * from Linux_ComputerSystem where PrimaryOwnerName="root"</VALUE>
        </IPARAMVALUE>
      </IMETHODCALL>
    </SIMPLEREQ>
  </MESSAGE>
</CIM>
*/
{
   ClientEnc        *cl  = (ClientEnc *)mb;
   CMCIConnection   *con = cl->connection;
   UtilStringBuffer *sb  = UtilFactory->newStringBuffer(2048);
   char             *error;
   ResponseHdr      rh;
   CMPIEnumeration  *retval;

   START_TIMING(ExecQuery);
   SET_DEBUG();

   con->ft->genRequest(cl, ExecQuery, cop, 0);

   addXmlHeader(sb);

   sb->ft->append3Chars(sb, "<IMETHODCALL NAME=\"", ExecQuery, "\">");

   addXmlNamespace(sb, cop);

   /* Add the query language */
   sb->ft->append3Chars(sb,
        "<IPARAMVALUE NAME=\"QueryLanguage\">\n<VALUE>",
        lang, "</VALUE>\n</IPARAMVALUE>");

   /* Add the query */
   sb->ft->append3Chars(sb,
        "<IPARAMVALUE NAME=\"Query\">\n<VALUE>",
        query, "</VALUE>\n</IPARAMVALUE>");

   sb->ft->appendChars(sb,"</IMETHODCALL>\n");
   addXmlFooter(sb);

   error = con->ft->addPayload(con,sb);

   if (error || (error = con->ft->getResponse(con, cop))) {
      CMSetStatusWithChars(rc,CMPI_RC_ERR_FAILED,error);
      free(error);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return NULL;
   }

   if (con->mStatus.rc != CMPI_RC_OK) {
      if (rc)
     *rc=cloneStatus(con->mStatus);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return NULL;
   }

   CMRelease(sb);

   rh = scanCimXmlResponse(CMGetCharPtr(con->mResponse), cop);
   if (rh.errCode != 0) {
      CMSetStatusWithChars(rc, rh.errCode, rh.description);
      free(rh.description);
      CMRelease(rh.rvArray);
      END_TIMING(_T_FAILED);
      return NULL;
   }

#if DEBUG
   if (do_debug)
       printf ("\treturn enumeration array type %d expected CMPI_instance %d\n",
	    rh.rvArray->ft->getSimpleType(rh.rvArray, NULL), CMPI_instance);
#endif

   CMSetStatus(rc, CMPI_RC_OK);
   retval = newCMPIEnumeration(rh.rvArray, NULL);
   END_TIMING(_T_GOOD);
   return retval;
}

/* --------------------------------------------------------------------------*/

static CMPIEnumeration * enumInstances(
	CMCIClient * mb,
	CMPIObjectPath * cop,
	CMPIFlags flags,
	char ** properties,
	CMPIStatus * rc)
{
    ClientEnc	     *cl  = (ClientEnc *)mb;
    CMCIConnection   *con = cl->connection;
    UtilStringBuffer *sb  = UtilFactory->newStringBuffer(2048);
    char             *error;
    ResponseHdr	     rh;
    CMPIEnumeration   *retval;

    START_TIMING(EnumerateInstances);
    SET_DEBUG();

    con->ft->genRequest(cl, EnumerateInstances, cop, 0);

    addXmlHeader(sb);

    sb->ft->append3Chars(sb, "<IMETHODCALL NAME=\"", EnumerateInstances, "\">");
    addXmlNamespace(sb, cop);

    addXmlClassnameParam(sb, cop);

    emitdeep(sb,flags & CMPI_FLAG_DeepInheritance);
    emitlocal(sb,flags & CMPI_FLAG_LocalOnly);
    emitqual(sb,flags & CMPI_FLAG_IncludeQualifiers);
    emitorigin(sb,flags & CMPI_FLAG_IncludeClassOrigin);

    if (properties != NULL)
	addXmlPropertyListParam(sb, properties);

    sb->ft->appendChars(sb,"</IMETHODCALL>\n");
    addXmlFooter(sb);

    error = con->ft->addPayload(con,sb);

    if (error || (error = con->ft->getResponse(con, cop))) {
        CMSetStatusWithChars(rc,CMPI_RC_ERR_FAILED,error);
	free(error);
        END_TIMING(_T_FAILED);
        return NULL;
    }

    if (con->mStatus.rc != CMPI_RC_OK) {
        if (rc)
      *rc=cloneStatus(con->mStatus);
      CMRelease(sb);
        END_TIMING(_T_FAILED);
      return NULL;
    }

    CMRelease(sb);

    rh = scanCimXmlResponse(CMGetCharPtr(con->mResponse), cop);

    if (rh.errCode != 0) {
        CMSetStatusWithChars(rc, rh.errCode, rh.description);
	free(rh.description);
	CMRelease(rh.rvArray);
        END_TIMING(_T_FAILED);
        return NULL;
    }

#if DEBUG
   if (do_debug)
       printf ("\treturn enumeration array type %d expected CMPI_instance %d\n",
	    rh.rvArray->ft->getSimpleType(rh.rvArray, NULL), CMPI_instance);
#endif

    CMSetStatus(rc, CMPI_RC_OK);
    retval = newCMPIEnumeration(rh.rvArray, NULL);
    END_TIMING(_T_GOOD);
    return retval;
}

/* --------------------------------------------------------------------------*/

static CMPIEnumeration * associators(
	CMCIClient	* mb,
	CMPIObjectPath	* cop,
	const char	* assocClass,
	const char	* resultClass,
	const char	* role,
	const char	* resultRole,
	CMPIFlags	flags,
	char		** properties,
	CMPIStatus	* rc)
/*
<?xml version="1.0" encoding="utf-8"?>
<CIM CIMVERSION="2.0" DTDVERSION="2.0">
  <MESSAGE ID="4711" PROTOCOLVERSION="1.0">
    <SIMPLEREQ>
      <IMETHODCALL NAME="Associators">
        <LOCALNAMESPACEPATH>
          <NAMESPACE NAME="root"/>
          <NAMESPACE NAME="cimv2"/>
        </LOCALNAMESPACEPATH>
        <IPARAMVALUE NAME="ObjectName">
          <INSTANCENAME CLASSNAME="Linux_ComputerSystem">
            <KEYBINDING NAME="CreationClassName">
              <KEYVALUE VALUETYPE="string">Linux_ComputerSystem</KEYVALUE>
            </KEYBINDING>
            <KEYBINDING NAME="Name">
              <KEYVALUE VALUETYPE="string">bestorga.ibm.com</KEYVALUE>
            </KEYBINDING>
          </INSTANCENAME>
        </IPARAMVALUE>
        <IPARAMVALUE NAME="AssocClass">
          <CLASSNAME NAME="Linux_RunningOS"/>
        </IPARAMVALUE>
        <IPARAMVALUE NAME="IncludeQualifiers">
          <VALUE>FALSE</VALUE>
        </IPARAMVALUE>
        <IPARAMVALUE NAME="IncludeClassOrigin">
          <VALUE>TRUE</VALUE>
        </IPARAMVALUE>
      </IMETHODCALL>
    </SIMPLEREQ>
  </MESSAGE>
</CIM>
*/
{
   ClientEnc		*cl = (ClientEnc*)mb;
   CMCIConnection	*con = cl->connection;
   UtilStringBuffer	*sb = UtilFactory->newStringBuffer(2048);
   char			*error;
   CMPIEnumeration      *retval;
   ResponseHdr rh;

   START_TIMING(Associators);
   SET_DEBUG();

   con->ft->genRequest(cl, Associators, cop, 0);
   addXmlHeader(sb);

   sb->ft->append3Chars(sb, "<IMETHODCALL NAME=\"", Associators, "\">");

   addXmlNamespace(sb, cop);

   /* TODO: Need to switch from ObjName to InstanceName? */
   addXmlObjectName(sb, cop, "ObjectName");

   /* Add optional parameters */
   if (assocClass!=NULL)
      sb->ft->append3Chars(sb,
                   "<IPARAMVALUE NAME=\"AssocClass\"><CLASSNAME NAME=\"",
                   assocClass,
		  "\"/></IPARAMVALUE>\n");

   if (resultClass!=NULL)
      sb->ft->append3Chars(sb,
                   "<IPARAMVALUE NAME=\"ResultClass\"><CLASSNAME NAME=\"",
                   resultClass,
		  "\"/></IPARAMVALUE>\n");

   if (role)
      sb->ft->append3Chars(sb,
                   "<IPARAMVALUE NAME=\"Role\"><VALUE>",
                   role,
		 "</VALUE></IPARAMVALUE>\n");

   if (resultRole)
      sb->ft->append3Chars(sb, "<IPARAMVALUE NAME=\"ResultRole\"><VALUE>", resultRole,
		 "</VALUE></IPARAMVALUE>\n");

   /* Add optional flags */
   emitorigin(sb,flags & CMPI_FLAG_IncludeClassOrigin);
   emitqual(sb,flags & CMPI_FLAG_IncludeQualifiers);

   /* Add property list filter */
   if (properties != NULL)
	addXmlPropertyListParam(sb, properties);

   sb->ft->appendChars(sb,"</IMETHODCALL>\n");
   addXmlFooter(sb);

   error = con->ft->addPayload(con, sb);

   if (error || (error = con->ft->getResponse(con,cop))) {
      CMSetStatusWithChars(rc, CMPI_RC_ERR_FAILED, error);
      free(error);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return NULL;
   }

   if (con->mStatus.rc != CMPI_RC_OK) {
      if (rc)
     *rc=cloneStatus(con->mStatus);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return NULL;
   }

   CMRelease(sb);

   rh=scanCimXmlResponse(CMGetCharPtr(con->mResponse),cop);

   if (rh.errCode != 0) {
      CMSetStatusWithChars(rc, rh.errCode, rh.description);
      free(rh.description);
      CMRelease(rh.rvArray);
      END_TIMING(_T_FAILED);
      return NULL;
   }

#if DEBUG
   if (do_debug)
       printf ("\treturn enumeration array type %d expected CMPI_instance %d\n",
	    rh.rvArray->ft->getSimpleType(rh.rvArray, NULL), CMPI_instance);
#endif

   CMSetStatus(rc, CMPI_RC_OK);
   retval = newCMPIEnumeration(rh.rvArray, NULL);
   END_TIMING(_T_GOOD);
   return retval;
}

/* --------------------------------------------------------------------------*/

static CMPIEnumeration * associatorNames(
	CMCIClient	* mb,
	CMPIObjectPath	* cop,
	const char	* assocClass,
	const char	* resultClass,
	const char	* role,
	const char	* resultRole,
	CMPIStatus	* rc)
/*
<?xml version="1.0" encoding="utf-8"?>
<CIM CIMVERSION="2.0" DTDVERSION="2.0">
  <MESSAGE ID="4711" PROTOCOLVERSION="1.0">
    <SIMPLEREQ>
      <IMETHODCALL NAME="AssociatorNames">
	<LOCALNAMESPACEPATH>
	  <NAMESPACE NAME="root"/>
	  <NAMESPACE NAME="cimv2"/>
	</LOCALNAMESPACEPATH>
	<IPARAMVALUE NAME="ObjectName">
	  <INSTANCENAME CLASSNAME="Linux_ComputerSystem">
	    <KEYBINDING NAME="CreationClassName">
	      <KEYVALUE VALUETYPE="string">Linux_ComputerSystem</KEYVALUE>
	    </KEYBINDING>
	    <KEYBINDING NAME="Name">
	      <KEYVALUE VALUETYPE="string">bestorga.ibm.com</KEYVALUE>
	    </KEYBINDING>
	  </INSTANCENAME>
	</IPARAMVALUE>
	<IPARAMVALUE NAME="AssocClass">
	  <CLASSNAME NAME="Linux_RunningOS"/>
	</IPARAMVALUE>
      </IMETHODCALL>
    </SIMPLEREQ>
  </MESSAGE>
</CIM>
*/
{
   ClientEnc		*cl = (ClientEnc*)mb;
   CMCIConnection	*con = cl->connection;
   UtilStringBuffer	*sb = UtilFactory->newStringBuffer(2048);
   char			*error;
   CMPIEnumeration      *retval;
   ResponseHdr rh;

   START_TIMING(AssociatorNames);
   SET_DEBUG();

   con->ft->genRequest(cl, AssociatorNames, cop, 0);
   addXmlHeader(sb);

   sb->ft->append3Chars(sb, "<IMETHODCALL NAME=\"", AssociatorNames, "\">");

   addXmlNamespace(sb, cop);

   addXmlObjectName(sb, cop, "ObjectName");

   /* Add optional parameters */
   if (assocClass!=NULL)
      sb->ft->append3Chars(sb,
                   "<IPARAMVALUE NAME=\"AssocClass\"><CLASSNAME NAME=\"",
                   assocClass,
          "\"/></IPARAMVALUE>\n");

   if (resultClass!=NULL)
      sb->ft->append3Chars(sb,
                   "<IPARAMVALUE NAME=\"ResultClass\"><CLASSNAME NAME=\"",
                   resultClass,
          "\"/></IPARAMVALUE>\n");

   if (role)
      sb->ft->append3Chars(sb, 
                   "<IPARAMVALUE NAME=\"Role\"><VALUE>", 
                   role,
         "</VALUE></IPARAMVALUE>\n");

   if (resultRole)
      sb->ft->append3Chars(sb,
                   "<IPARAMVALUE NAME=\"ResultRole\"><VALUE>", 
                   resultRole,
         "</VALUE></IPARAMVALUE>\n");

   sb->ft->appendChars(sb,"</IMETHODCALL>\n");
   addXmlFooter(sb);

   error = con->ft->addPayload(con,sb);

   if (error || (error=con->ft->getResponse(con,cop))) {
      CMSetStatusWithChars(rc,CMPI_RC_ERR_FAILED,error);
      free(error);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return NULL;
   }

   if (con->mStatus.rc != CMPI_RC_OK) {
      if (rc)
     *rc=cloneStatus(con->mStatus);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return NULL;
   }

   CMRelease(sb);

   rh=scanCimXmlResponse(CMGetCharPtr(con->mResponse),cop);

   if (rh.errCode != 0) {
      CMSetStatusWithChars(rc, rh.errCode, rh.description);
      free(rh.description);
      CMRelease(rh.rvArray);
      END_TIMING(_T_FAILED);
      return NULL;
   }

#if DEBUG
   if (do_debug)
      printf ("\treturn enumeration array type %d expected CMPI_ref %d\n",
	    rh.rvArray->ft->getSimpleType(rh.rvArray, NULL), CMPI_ref);
#endif

   CMSetStatus(rc, CMPI_RC_OK);
   retval = newCMPIEnumeration(rh.rvArray, NULL);
   END_TIMING(_T_GOOD);
   return retval;
}

/* --------------------------------------------------------------------------*/

static CMPIEnumeration * references(
	CMCIClient * mb,
	CMPIObjectPath * cop,
	const char * resultClass,
	const char * role ,
	CMPIFlags flags,
	char ** properties,
	CMPIStatus * rc)
{
   ClientEnc		*cl = (ClientEnc*)mb;
   CMCIConnection	*con = cl->connection;
   UtilStringBuffer	*sb = UtilFactory->newStringBuffer(2048);
   char			*error;
   CMPIEnumeration      *retval;
   ResponseHdr rh;

   START_TIMING(References);
   SET_DEBUG();

   con->ft->genRequest(cl, References, cop, 0);
   addXmlHeader(sb);

   sb->ft->append3Chars(sb, "<IMETHODCALL NAME=\"", References, "\">");

   addXmlNamespace(sb, cop);

   addXmlObjectName(sb, cop, "ObjectName");

   /* Add optional parameters */
   if (resultClass)
      sb->ft->append3Chars(sb, 
                     "<IPARAMVALUE NAME=\"ResultClass\"><CLASSNAME NAME=\"",
                     resultClass, 
                     "\"/></IPARAMVALUE>\n");

   if (role)
      sb->ft->append3Chars(sb,
                     "<IPARAMVALUE NAME=\"Role\"><VALUE>",
	             role,
         "</VALUE></IPARAMVALUE>\n");

   /* Add optional flags */
   emitorigin(sb,flags & CMPI_FLAG_IncludeClassOrigin);
   emitqual(sb,flags & CMPI_FLAG_IncludeQualifiers);

   /* Add property list filter */
   if (properties != NULL)
	addXmlPropertyListParam(sb, properties);

   sb->ft->appendChars(sb,"</IMETHODCALL>\n");
   addXmlFooter(sb);

   error = con->ft->addPayload(con, sb);

   if (error || (error=con->ft->getResponse(con,cop))) {
      CMSetStatusWithChars(rc,CMPI_RC_ERR_FAILED,error);
      free(error);
      END_TIMING(_T_FAILED);
      return NULL;
   }

   if (con->mStatus.rc != CMPI_RC_OK) {
      if (rc)
     *rc=cloneStatus(con->mStatus);
      CMRelease(sb);
      return NULL;
   }

   CMRelease(sb);

   rh=scanCimXmlResponse(CMGetCharPtr(con->mResponse),cop);

   if (rh.errCode!=0) {
      CMSetStatusWithChars(rc,rh.errCode,rh.description);
      free(rh.description);
      CMRelease(rh.rvArray);
      END_TIMING(_T_FAILED);
      return NULL;
   }

#if DEBUG
   if (do_debug)
       printf ("\treturn enumeration array type %d expected CMPI_instance %d\n",
	    rh.rvArray->ft->getSimpleType(rh.rvArray, NULL), CMPI_instance);
#endif

   CMSetStatus(rc,CMPI_RC_OK);
   retval = newCMPIEnumeration(rh.rvArray, NULL);
   END_TIMING(_T_GOOD);
   return retval;
}

/* --------------------------------------------------------------------------*/

static CMPIEnumeration * referenceNames(
	CMCIClient * mb,
	CMPIObjectPath * cop,
	const char * resultClass,
	const char * role,
	CMPIStatus * rc)
{
   ClientEnc		*cl = (ClientEnc*)mb;
   CMCIConnection	*con = cl->connection;
   UtilStringBuffer	*sb = UtilFactory->newStringBuffer(2048);
   char			*error;
   CMPIEnumeration      *retval;
   ResponseHdr rh;

   START_TIMING(ReferenceNames);
   SET_DEBUG();

   con->ft->genRequest(cl, ReferenceNames, cop, 0);
   addXmlHeader(sb);

   sb->ft->append3Chars(sb, "<IMETHODCALL NAME=\"", ReferenceNames, "\">");

   addXmlNamespace(sb, cop);

   addXmlObjectName(sb, cop, "ObjectName");

   if (resultClass!=NULL)
      sb->ft->append3Chars(sb,
	      "<IPARAMVALUE NAME=\"ResultClass\"><CLASSNAME NAME=\"",
	      resultClass,
              "\"/></IPARAMVALUE>\n");
   if (role)
      sb->ft->append3Chars(sb, 
              "<IPARAMVALUE NAME=\"Role\"><VALUE>",
	      role,
              "</VALUE></IPARAMVALUE>\n");

   sb->ft->appendChars(sb,"</IMETHODCALL>\n");
   addXmlFooter(sb);

   error = con->ft->addPayload(con, sb);

   if (error || (error=con->ft->getResponse(con,cop))) {
      CMSetStatusWithChars(rc,CMPI_RC_ERR_FAILED,error);
      free(error);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return NULL;
   }

   if (con->mStatus.rc != CMPI_RC_OK) {
      if (rc)
     *rc=cloneStatus(con->mStatus);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return NULL;
   }

   CMRelease(sb);

   rh=scanCimXmlResponse(CMGetCharPtr(con->mResponse),cop);

   if (rh.errCode!=0) {
      CMSetStatusWithChars(rc,rh.errCode,rh.description);
      free(rh.description);
      CMRelease(rh.rvArray);
      END_TIMING(_T_FAILED);
      return NULL;
   }

#if DEBUG
   if (do_debug)
       printf ("\treturn enumeration array type %d expected CMPI_ref %d\n",
	    rh.rvArray->ft->getSimpleType(rh.rvArray, NULL), CMPI_ref);
#endif

   CMSetStatus(rc,CMPI_RC_OK);
   retval = newCMPIEnumeration(rh.rvArray, NULL);
   END_TIMING(_T_GOOD);
   return retval;
}

/* --------------------------------------------------------------------------*/

CMPIData invokeMethod(
	CMCIClient * mb,
	CMPIObjectPath * cop,
	const char * method,
	CMPIArgs * in,
	CMPIArgs * out,
	CMPIStatus * rc)
/*
<?xml version="1.0" encoding="utf-8"?>
<CIM CIMVERSION="2.0" DTDVERSION="2.0">
  <MESSAGE ID="4711" PROTOCOLVERSION="1.0">
    <SIMPLEREQ>
      <METHODCALL NAME="IsAuthorized">
        <LOCALINSTANCEPATH>
          <LOCALNAMESPACEPATH>
            <NAMESPACE NAME="root"/>
            <NAMESPACE NAME="cimv2"/>
          </LOCALNAMESPACEPATH>
          <INSTANCENAME CLASSNAME="CWS_Authorization">
            <KEYBINDING NAME="Username">
              <KEYVALUE VALUETYPE="string">schuur</KEYVALUE>
            </KEYBINDING>
            <KEYBINDING NAME="Classname">
              <KEYVALUE VALUETYPE="string">CIM_ComputerSystem</KEYVALUE>
            </KEYBINDING>
          </INSTANCENAME>
        </LOCALINSTANCEPATH>
        <PARAMVALUE NAME="operation">
          <VALUE>Query</VALUE>
        </PARAMVALUE>
      </METHODCALL>
    </SIMPLEREQ>
  </MESSAGE>
</CIM>
*/
{
   ClientEnc		*cl = (ClientEnc*)mb;
   CMCIConnection	*con = cl->connection;
   UtilStringBuffer	*sb=UtilFactory->newStringBuffer(2048);
   char			*error;
   ResponseHdr		rh;
   CMPIString		*cn;
   CMPIData		retval;
   int			i, numinargs = 0;
   char                 *cv;

   START_TIMING(method);
   SET_DEBUG();

   if (in)
      numinargs = in->ft->getArgCount(in, NULL);

   con->ft->genRequest(cl, (const char *)method, cop, 1);

   addXmlHeader(sb);

   /* Add the extrinsic method name */
   sb->ft->append3Chars(sb,"<METHODCALL NAME=\"", method, "\">");

   sb->ft->appendChars(sb,"<LOCALINSTANCEPATH>");

   addXmlNamespace(sb, cop);

   /* Add the objectpath */
   cn = cop->ft->getClassName(cop,NULL);
   sb->ft->append3Chars(sb, "<INSTANCENAME CLASSNAME=\"",
					  (char*)cn->hdl,"\">\n");
   pathToXml(sb, cop);
   sb->ft->appendChars(sb,"</INSTANCENAME>\n");
   CMRelease(cn);

   sb->ft->appendChars(sb,"</LOCALINSTANCEPATH>\n");

   /* Add the input parameters */
   for (i = 0; i < numinargs; i++) {
      CMPIString * argname, * name;
      CMPIData argdata = in->ft->getArgAt(in, i, &argname, NULL);
      CMPIObjectPath *argcop;
      // Output XML for IN arg values, specific by type
      switch (argdata.type & ~CMPI_ARRAY) {
         case CMPI_boolean:
         case CMPI_char16:
         case CMPI_real32:
         case CMPI_real64:
         case CMPI_uint8:
         case CMPI_uint16:
         case CMPI_uint32:
         case CMPI_uint64:
         case CMPI_sint8:
         case CMPI_sint16:
         case CMPI_sint32:
         case CMPI_sint64:
         case CMPI_string:
         case CMPI_chars:
         case CMPI_dateTime:
             addXmlValue(sb, "PARAMVALUE", "PARAMTYPE",
                                          argname->hdl, argdata);
             break;
         case CMPI_instance:	/* TODO: UNTESTED */
             if (argdata.type & CMPI_ARRAY)
                 goto not_supported;
             sb->ft->append3Chars(sb, "<PARAMVALUE NAME=\"",
                                      argname->hdl,
                                      "\" PARAMTYPE=\"instance\">\n");
             addXmlNamedInstance(sb, NULL, argdata.value.inst);
      sb->ft->appendChars(sb,"</PARAMVALUE>\n");
             break;
         case CMPI_ref:
             if (argdata.type & CMPI_ARRAY)
                 goto not_supported;
             argcop = argdata.value.ref;
             sb->ft->append3Chars(sb, "<PARAMVALUE NAME=\"",
                                      argname->hdl,
                                      "\" PARAMTYPE=\"reference\">\n");
             sb->ft->appendChars(sb, "<VALUE.REFERENCE>\n");
             sb->ft->appendChars(sb, "<INSTANCEPATH>\n");
             sb->ft->appendChars(sb, "<NAMESPACEPATH>\n");
             name = argcop->ft->getHostname(argcop, NULL);
             sb->ft->append3Chars(sb, "<HOST>",
                                  name != NULL ? 
                                     (char *)name->hdl : "localhost",
                                  "</HOST>\n");
             if (name != NULL)
                 CMRelease(name);
             addXmlNamespace(sb, argcop);
             sb->ft->appendChars(sb, "</NAMESPACEPATH>\n");

             name = argcop->ft->getClassName(argcop, NULL);
             sb->ft->append3Chars(sb, "<INSTANCENAME CLASSNAME=\"",
			    (char*)name->hdl, "\">\n");
             CMRelease(name);
             pathToXml(sb, argcop);
             sb->ft->appendChars(sb,"</INSTANCENAME>\n");
             sb->ft->appendChars(sb,"</INSTANCEPATH>\n");
             sb->ft->appendChars(sb,"</VALUE.REFERENCE>\n");
             sb->ft->appendChars(sb,"</PARAMVALUE>\n");
             break;
         default:

           not_supported:

	     CMSetStatusWithChars(rc, CMPI_RC_ERR_FAILED,
                                  strdup("Unsupported IN argument type"));
             retval.state = CMPI_notFound | CMPI_nullValue;
             END_TIMING(_T_FAILED);
             return retval;
       }
       CMRelease(argname);
   }

   sb->ft->appendChars(sb,"</METHODCALL>\n");
   addXmlFooter(sb);

   error = con->ft->addPayload(con,sb);

   if (error || (error = con->ft->getResponse(con, cop))) {
      CMSetStatusWithChars(rc,CMPI_RC_ERR_FAILED,error);
      free(error);
      retval.state = CMPI_notFound | CMPI_nullValue;
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return retval;
   }

   if (con->mStatus.rc != CMPI_RC_OK) {
      if (rc)
     *rc=cloneStatus(con->mStatus);
      CMRelease(sb);
      retval.state = CMPI_notFound | CMPI_nullValue;
      END_TIMING(_T_FAILED);
      return retval;
   }

   CMRelease(sb);

   rh = scanCimXmlResponse(CMGetCharPtr(con->mResponse),cop);

   if (rh.errCode != 0) {
      CMSetStatusWithChars(rc, rh.errCode, rh.description);
      free(rh.description);
      CMRelease(rh.rvArray);
      if (rh.outArgs) CMRelease(rh.outArgs);
      retval.state = CMPI_notFound | CMPI_nullValue;
      END_TIMING(_T_FAILED);
      return retval;
   }

   /* Handle output args if parsed available and requested */
   if (rh.outArgs && out) {
       int numparsedoutargs = rh.outArgs->ft->getArgCount(rh.outArgs, NULL);
       CMPIData data;
       for (i = 0; i < numparsedoutargs; i++) {
           data = rh.outArgs->ft->getArgAt(rh.outArgs, i, &cn, NULL);
           out->ft->addArg( out, CMGetCharPtr(cn), &data.value, data.type);
           CMRelease(cn);
       }
       CMRelease(rh.outArgs);
   }

   /* Set good status and return */
#if DEBUG
   if (do_debug)
       printf ("\treturn type %d\n",
		 rh.rvArray->ft->getSimpleType(rh.rvArray, NULL));
#endif

   CMSetStatus(rc, CMPI_RC_OK);
   retval=rh.rvArray->ft->getElementAt(rh.rvArray, 0, NULL);
   retval.value=native_clone_CMPIValue(rh.rvArray->ft->getSimpleType(rh.rvArray, NULL),&retval.value,NULL);
   CMRelease(rh.rvArray);
   END_TIMING(_T_GOOD)
   return retval;
}

/* --------------------------------------------------------------------------*/

static CMPIStatus setProperty(
	CMCIClient * mb,
	CMPIObjectPath * cop,
	const char * name,
	CMPIValue * value,
	CMPIType type)
/*
<?xml version="1.0" encoding="utf-8"?>
<CIM CIMVERSION="2.0" DTDVERSION="2.0">
  <MESSAGE ID="4711" PROTOCOLVERSION="1.0">
    <SIMPLEREQ>
      <IMETHODCALL NAME="SetProperty">
        <LOCALNAMESPACEPATH>
          <NAMESPACE NAME="root"/>
          <NAMESPACE NAME="cimv2"/>
        </LOCALNAMESPACEPATH>
        <IPARAMVALUE NAME="PropertyName">
          <VALUE>CurrentTimeZone</VALUE>
        </IPARAMVALUE>
        <IPARAMVALUE NAME="NewValue">
          <VALUE>123</VALUE>
        </IPARAMVALUE>
        <IPARAMVALUE NAME="InstanceName">
          <INSTANCENAME CLASSNAME="Linux_OperatingSystem">
            <KEYBINDING NAME="CSCreationClassName">
              <KEYVALUE VALUETYPE="string">Linux_ComputerSystem</KEYVALUE>
            </KEYBINDING>
            <KEYBINDING NAME="CSName">
              <KEYVALUE VALUETYPE="string">bestorga.ibm.com</KEYVALUE>
            </KEYBINDING>
            <KEYBINDING NAME="CreationClassName">
              <KEYVALUE VALUETYPE="string">Linux_OperatingSystem</KEYVALUE>
            </KEYBINDING>
            <KEYBINDING NAME="Name">
              <KEYVALUE VALUETYPE="string">bestorga.ibm.com</KEYVALUE>
            </KEYBINDING>
          </INSTANCENAME>
        </IPARAMVALUE>
      </IMETHODCALL>
    </SIMPLEREQ>
  </MESSAGE>
</CIM>
*/
{
   ClientEnc        *cl = (ClientEnc*)mb;
   CMCIConnection   *con = cl->connection;
   UtilStringBuffer *sb=UtilFactory->newStringBuffer(2048);
   char		    *error;
   ResponseHdr      rh;
   CMPIString	    *cn;
   CMPIStatus	    rc = {CMPI_RC_OK, NULL};
   char             *cv;

   START_TIMING(SetProperty);
   SET_DEBUG();

   con->ft->genRequest(cl, SetProperty, cop, 0);

   addXmlHeader(sb);
   sb->ft->append3Chars(sb,"<IMETHODCALL NAME=\"", SetProperty, "\">");

   addXmlNamespace(sb, cop);

   /* Add the property */
   sb->ft->append3Chars(sb,
        "<IPARAMVALUE NAME=\"PropertyName\">\n<VALUE>",
        name, "</VALUE>\n</IPARAMVALUE>");

   /* Add the new value */
   sb->ft->append3Chars(sb,
        "<IPARAMVALUE NAME=\"NewValue\">\n<VALUE>",
        cv=value2Chars(type,value), "</VALUE>\n</IPARAMVALUE>");
   if(cv) free(cv);

   /* Add the objectpath */
   cn = cop->ft->getClassName(cop,NULL);
   sb->ft->append3Chars(sb,"<IPARAMVALUE NAME=\"InstanceName\">\n"
          "<INSTANCENAME CLASSNAME=\"",(char*)cn->hdl,"\">\n");
   pathToXml(sb, cop);
   sb->ft->appendChars(sb,"</INSTANCENAME>\n</IPARAMVALUE>\n");
   CMRelease(cn);

   sb->ft->appendChars(sb,"</IMETHODCALL>\n");
   addXmlFooter(sb);

   error = con->ft->addPayload(con,sb);

   if (error || (error = con->ft->getResponse(con, cop))) {
      CMSetStatusWithChars(&rc,CMPI_RC_ERR_FAILED,error);
      free(error);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return rc;
   }

   if (con->mStatus.rc != CMPI_RC_OK) {
     rc=cloneStatus(con->mStatus);
     CMRelease(sb);
      END_TIMING(_T_FAILED);
     return rc;
   }

   CMRelease(sb);

   rh = scanCimXmlResponse(CMGetCharPtr(con->mResponse),cop);

   if (rh.errCode != 0) {
      CMSetStatusWithChars(&rc, rh.errCode, rh.description);
      free(rh.description);
   }
   
   CMRelease(rh.rvArray);
   END_TIMING(_T_GOOD);
   return rc;
}

/* --------------------------------------------------------------------------*/

static CMPIData getProperty(
	CMCIClient * mb,
	CMPIObjectPath * cop,
	const char * name,
	CMPIStatus * rc)
/*
<?xml version="1.0" encoding="utf-8"?>
<CIM CIMVERSION="2.0" DTDVERSION="2.0">
  <MESSAGE ID="4711" PROTOCOLVERSION="1.0">
    <SIMPLEREQ>
      <IMETHODCALL NAME="GetProperty">
        <LOCALNAMESPACEPATH>
          <NAMESPACE NAME="root"/>
          <NAMESPACE NAME="cimv2"/>
        </LOCALNAMESPACEPATH>
        <IPARAMVALUE NAME="PropertyName">
          <VALUE>CurrentTimeZone</VALUE>
        </IPARAMVALUE>
        <IPARAMVALUE NAME="InstanceName">
          <INSTANCENAME CLASSNAME="Linux_OperatingSystem">
            <KEYBINDING NAME="CSCreationClassName">
              <KEYVALUE VALUETYPE="string">Linux_ComputerSystem</KEYVALUE>
            </KEYBINDING>
            <KEYBINDING NAME="CSName">
              <KEYVALUE VALUETYPE="string">bestorga.ibm.com</KEYVALUE>
            </KEYBINDING>
            <KEYBINDING NAME="CreationClassName">
              <KEYVALUE VALUETYPE="string">Linux_OperatingSystem</KEYVALUE>
            </KEYBINDING>
            <KEYBINDING NAME="Name">
              <KEYVALUE VALUETYPE="string">bestorga.ibm.com</KEYVALUE>
            </KEYBINDING>
          </INSTANCENAME>
        </IPARAMVALUE>
      </IMETHODCALL>
    </SIMPLEREQ>
  </MESSAGE>
</CIM>
*/
{
   ClientEnc		*cl = (ClientEnc*)mb;
   CMCIConnection	*con = cl->connection;
   UtilStringBuffer	*sb=UtilFactory->newStringBuffer(2048);
   char			*error;
   ResponseHdr		rh;
   CMPIString		*cn;
   CMPIData		retval;

   START_TIMING(GetProperty);
   SET_DEBUG();

   con->ft->genRequest(cl, GetProperty, cop, 0);

   addXmlHeader(sb);
   sb->ft->append3Chars(sb,"<IMETHODCALL NAME=\"", GetProperty, "\">");

   addXmlNamespace(sb, cop);

   /* Add the property */
   sb->ft->append3Chars(sb,
        "<IPARAMVALUE NAME=\"PropertyName\">\n<VALUE>",
        name, "</VALUE>\n</IPARAMVALUE>");

   /* Add the objectpath */
   cn = cop->ft->getClassName(cop,NULL);
   sb->ft->append3Chars(sb,"<IPARAMVALUE NAME=\"InstanceName\">\n"
          "<INSTANCENAME CLASSNAME=\"",(char*)cn->hdl,"\">\n");
   pathToXml(sb, cop);
   sb->ft->appendChars(sb,"</INSTANCENAME>\n</IPARAMVALUE>\n");
   CMRelease(cn);

   sb->ft->appendChars(sb,"</IMETHODCALL>\n");
   addXmlFooter(sb);

   error = con->ft->addPayload(con,sb);

   if (error || (error = con->ft->getResponse(con, cop))) {
      CMSetStatusWithChars(rc,CMPI_RC_ERR_FAILED,error);
      free(error);
      retval.state = CMPI_notFound | CMPI_nullValue;
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return retval;
   }

   if (con->mStatus.rc != CMPI_RC_OK) {
      if (rc)
     *rc=cloneStatus(con->mStatus);
      CMRelease(sb);
      retval.state = CMPI_notFound | CMPI_nullValue;
      END_TIMING(_T_FAILED);
      return retval;
   }

   CMRelease(sb);

   rh = scanCimXmlResponse(CMGetCharPtr(con->mResponse),cop);

   if (rh.errCode != 0) {
      CMSetStatusWithChars(rc, rh.errCode, rh.description);
      free(rh.description);
      CMRelease(rh.rvArray);
      retval.state = CMPI_notFound | CMPI_nullValue;
      END_TIMING(_T_FAILED);
      return retval;
   }

   /* Set good return status and return */
#if DEBUG
   if (do_debug)
       printf ("\treturn type %d\n",
	    rh.rvArray->ft->getSimpleType(rh.rvArray, NULL));
#endif

   CMSetStatus(rc, CMPI_RC_OK);
   retval=rh.rvArray->ft->getElementAt(rh.rvArray, 0, NULL);
   retval.value=native_clone_CMPIValue(rh.rvArray->ft->getSimpleType(rh.rvArray, NULL),&retval.value,NULL);
   CMRelease(rh.rvArray);
   END_TIMING(_T_GOOD);
   return retval;
}

/* --------------------------------------------------------------------------*/

static CMPIConstClass * getClass(
	CMCIClient * mb,
	CMPIObjectPath * cop,
	CMPIFlags flags,
	char ** properties,
	CMPIStatus * rc)
{
   CMPIConstClass *ccl, *ccc;
   ClientEnc *cl=(ClientEnc*)mb;
   CMCIConnection *con=cl->connection;
   UtilStringBuffer *sb=UtilFactory->newStringBuffer(2048);
   char *error;
   ResponseHdr rh;

   START_TIMING(GetClass);
   SET_DEBUG();

   con->ft->genRequest(cl, GetClass, cop, 0);

   addXmlHeader(sb);

   sb->ft->append3Chars(sb,"<IMETHODCALL NAME=\"", GetClass, "\">");

   addXmlNamespace(sb, cop);

   emitlocal(sb,flags & CMPI_FLAG_LocalOnly);
   emitorigin(sb,flags & CMPI_FLAG_IncludeClassOrigin);
   emitqual(sb,flags & CMPI_FLAG_IncludeQualifiers);

   if (properties != NULL)
	addXmlPropertyListParam(sb, properties);

   addXmlClassnameParam(sb, cop);

   sb->ft->appendChars(sb,"</IMETHODCALL>\n");
   addXmlFooter(sb);

   error = con->ft->addPayload(con,sb);

   if (error || (error=con->ft->getResponse(con,cop))) {
      CMSetStatusWithChars(rc,CMPI_RC_ERR_FAILED,error);
      free(error);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return NULL;
   }

   if (con->mStatus.rc != CMPI_RC_OK) {
      if (rc)
     *rc=cloneStatus(con->mStatus);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return NULL;
   }

   CMRelease(sb);

   rh=scanCimXmlResponse(CMGetCharPtr(con->mResponse),cop);

   if (rh.errCode!=0) {
      CMSetStatusWithChars(rc,rh.errCode,rh.description);
      free(rh.description);
      CMRelease(rh.rvArray);
      END_TIMING(_T_FAILED);
      return NULL;
   }

#if DEBUG
   if (do_debug)
       printf ("\treturn enumeration array type %d expected CMPI_class %d\n",
	    rh.rvArray->ft->getSimpleType(rh.rvArray, NULL), CMPI_class);
#endif

   CMSetStatus(rc, CMPI_RC_OK);
   ccl = rh.rvArray->ft->getElementAt(rh.rvArray, 0, NULL).value.cls;
   ccc = CMClone(ccl,NULL);
   CMRelease(rh.rvArray);
   END_TIMING(_T_GOOD);
   return ccc;
}

/* --------------------------------------------------------------------------*/

/* finished & working */
static CMPIEnumeration* enumClassNames(
	CMCIClient * mb,
	CMPIObjectPath * cop,
	CMPIFlags flags,
	CMPIStatus * rc)
{
   ClientEnc *cl=(ClientEnc*)mb;
   CMCIConnection *con=cl->connection;
   UtilStringBuffer *sb=UtilFactory->newStringBuffer(2048);
   char *error;
   CMPIEnumeration   *retval;
   ResponseHdr       rh;

   START_TIMING(EnumerateClassNames);
   SET_DEBUG();

   con->ft->genRequest(cl, EnumerateClassNames, cop, 0);

   /* Construct the CIM-XML request */
   addXmlHeader(sb);
   sb->ft->append3Chars(sb,"<IMETHODCALL NAME=\"", EnumerateClassNames, "\">");

   addXmlNamespace(sb, cop);
   emitdeep(sb,flags & CMPI_FLAG_DeepInheritance);
   addXmlClassnameParam(sb, cop);

   sb->ft->appendChars(sb,"</IMETHODCALL>\n");
   addXmlFooter(sb);

   error = con->ft->addPayload(con,sb);

   if (error || (error = con->ft->getResponse(con,cop))) {
      CMSetStatusWithChars(rc,CMPI_RC_ERR_FAILED,error);
      free(error);
      CMRelease(sb);\
      END_TIMING(_T_FAILED);
      return NULL;
   }

   if (con->mStatus.rc != CMPI_RC_OK) {
      if (rc)
     *rc=cloneStatus(con->mStatus);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return NULL;
   }

   CMRelease(sb);

   rh=scanCimXmlResponse(CMGetCharPtr(con->mResponse),cop);

   if (rh.errCode!=0) {
      CMSetStatusWithChars(rc,rh.errCode,rh.description);
      free(rh.description);
      CMRelease(rh.rvArray);
      END_TIMING(_T_FAILED);
      return NULL;
   }

#if DEBUG
   if (do_debug)
       printf ("\treturn enumeration array type %d expected CMPI_ref %d\n",
	    rh.rvArray->ft->getSimpleType(rh.rvArray, NULL), CMPI_ref);
#endif

   CMSetStatus(rc,CMPI_RC_OK);
   retval = newCMPIEnumeration(rh.rvArray, NULL);
   END_TIMING(_T_GOOD);
   return retval;
}

/* --------------------------------------------------------------------------*/

static CMPIEnumeration * enumClasses(
	CMCIClient * mb,
	CMPIObjectPath * cop,
	CMPIFlags flags,
	CMPIStatus * rc)
{
   ClientEnc	     *cl  = (ClientEnc *)mb;
   CMCIConnection   *con = cl->connection;
   UtilStringBuffer *sb  = UtilFactory->newStringBuffer(2048);
   char             *error;
   CMPIEnumeration  *retval;
   ResponseHdr	     rh;

   START_TIMING(EnumerateClasses);
   SET_DEBUG();

   con->ft->genRequest(cl, EnumerateClasses, cop, 0);

   /* Construct the CIM-XML request */
   addXmlHeader(sb);
   sb->ft->append3Chars(sb, "<IMETHODCALL NAME=\"", EnumerateClasses, "\">");

   addXmlNamespace(sb, cop);
   emitdeep(sb,flags & CMPI_FLAG_DeepInheritance);
   emitlocal(sb,flags & CMPI_FLAG_LocalOnly);
   emitqual(sb,flags & CMPI_FLAG_IncludeQualifiers);
   emitorigin(sb,flags & CMPI_FLAG_IncludeClassOrigin);
   addXmlClassnameParam(sb, cop);

   sb->ft->appendChars(sb,"</IMETHODCALL>\n");
   addXmlFooter(sb);

   error = con->ft->addPayload(con,sb);

   if (error || (error = con->ft->getResponse(con, cop))) {
      CMSetStatusWithChars(rc,CMPI_RC_ERR_FAILED,error);
      free(error);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return NULL;
   }

   if (con->mStatus.rc != CMPI_RC_OK) {
      if (rc)
     *rc=cloneStatus(con->mStatus);
      CMRelease(sb);
      END_TIMING(_T_FAILED);
      return NULL;
   }

   CMRelease(sb);

   rh = scanCimXmlResponse(CMGetCharPtr(con->mResponse), cop);

   if (rh.errCode != 0) {
      CMSetStatusWithChars(rc, rh.errCode, rh.description);
      free(rh.description);
      CMRelease(rh.rvArray);
      END_TIMING(_T_FAILED);
      return NULL;
   }

#if DEBUG
   if (do_debug)
       printf ("\treturn enumeration array type %d expected CMPI_class %d\n",
	    rh.rvArray->ft->getSimpleType(rh.rvArray, NULL), CMPI_class);
#endif

   CMSetStatus(rc, CMPI_RC_OK);
   retval = newCMPIEnumeration(rh.rvArray, NULL);
   END_TIMING(_T_GOOD);

   return retval;
}

/* --------------------------------------------------------------------------*/

static CMCIClientFT clientFt = {
   NATIVE_FT_VERSION,
   releaseClient,
   cloneClient,
   getClass,
   enumClassNames,
   enumClasses,
   getInstance,
   createInstance,
   setInstance,
   deleteInstance,
   execQuery,
   enumInstanceNames,
   enumInstances,
   associators,
   associatorNames,
   references,
   referenceNames,
   invokeMethod,
   setProperty,
   getProperty
};


/*
 * Environment Support
 */

/* --------------------------------------------------------------------------*/

static CMCIClient *xmlConnect2(CIMCEnv *env, const char *hn, const char *scheme, const char *port,
			 const char *user, const char *pwd, 
			 int verifyMode, const char * trustStore,
			 const char * certFile, const char * keyFile,
			 CMPIStatus *rc)
{  
   ClientEnc *cc = (ClientEnc*)calloc(1, sizeof(ClientEnc));

   cc->enc.hdl		= &cc->data;
   cc->enc.ft		= &clientFt;

   cc->data.hostName	= hn ? strdup(hn) : strdup("localhost");
   cc->data.user	= user ? strdup(user) : NULL;
   cc->data.pwd		= pwd ? strdup(pwd) : NULL;
   cc->data.scheme	= scheme ? strdup(scheme) : strdup("http");

   if (port != NULL)
      cc->data.port = strdup(port);
   else
      cc->data.port = strcmp(cc->data.scheme, "https") == 0 ? 
	strdup("5989") : strdup("5988");

   cc->certData.verifyMode = verifyMode;
   cc->certData.trustStore = trustStore ? strdup(trustStore) : NULL;
   cc->certData.certFile = certFile ? strdup(certFile) : NULL;
   cc->certData.keyFile = keyFile ? strdup(keyFile) : NULL;
   
   cc->connection=initConnection(&cc->data);

   /* set SSL options */
   if (cc->connection) {
     curl_easy_setopt(cc->connection->mHandle,CURLOPT_SSL_VERIFYPEER,
		      verifyMode == CMCI_VERIFY_PEER ? 1 : 0);
      if (trustStore)
       curl_easy_setopt(cc->connection->mHandle,CURLOPT_CAINFO,trustStore);
      if (certFile)
       curl_easy_setopt(cc->connection->mHandle,CURLOPT_SSLCERT,certFile);
      if (keyFile)
       curl_easy_setopt(cc->connection->mHandle,CURLOPT_SSLKEY,keyFile);       
     }
 
   CMSetStatus(rc, CMPI_RC_OK);
   return (CMCIClient*)cc;
}

static CMCIClient *xmlConnect(CIMCEnv *env, const char *hn, const char *scheme, const char *port,
                        const char *user, const char *pwd, CMPIStatus *rc)
{
  return xmlConnect2(env, hn, scheme, port, user, pwd, CMCI_VERIFY_PEER, NULL,
		      NULL, NULL, rc);
}

static void *releaseEnv(CIMCEnv *env)
{
  CMPIStatus rc = {CMPI_RC_OK,NULL};
  
  free(env);
  curl_global_cleanup();
  return NULL;
}

static CMPIInstance* newInstance(CIMCEnv* ce, const CMPIObjectPath* op, CMPIStatus* rc)
{
   return newCMPIInstance((CMPIObjectPath*)op,rc);
}

static CMPIString* newString(CIMCEnv* ce, const char *ptr, CMPIStatus * rc)
{
   return newCMPIString(ptr, rc);
}

static CMPIObjectPath* newObjectPath(CIMCEnv* ce, const char *ns, const char *cn, CMPIStatus* rc)
{
   return newCMPIObjectPath(ns,cn,rc);
}

static CMPIArgs* newArgs(CIMCEnv* ce, CMPIStatus* rc)
{
   return newCMPIArgs(rc);
}

static CMPIArray* newArray(CIMCEnv* ce, CMPICount max, CMPIType type, CMPIStatus* rc)
{
   return newCMPIArray(max, type, rc);
}

static CMPIDateTime *newDateTime(CIMCEnv* ce, CMPIStatus *rc) 
{
   return native_new_CMPIDateTime(rc); 
}

static CMPIDateTime *newDateTimeFromBinary(CIMCEnv* ce, CMPIUint64 binTime, CMPIBoolean interval, 
      CMPIStatus *rc) 
{
   return native_new_CMPIDateTime_fromBinary(binTime,interval,rc); 
}

static CMPIDateTime *newDateTimeFromChars(CIMCEnv* ce, const char *utcTime, CMPIStatus *rc) 
{
   return native_new_CMPIDateTime_fromChars(utcTime,rc); 
}

static CIMCEnvFT localFT = {
  "CIMXML",
  releaseEnv,
  xmlConnect,
  xmlConnect2,     
  newInstance,      
  newObjectPath,
  newArgs,
  newString,
  newArray,
  newDateTime,
  newDateTimeFromBinary,
  newDateTimeFromChars,
};

/* Factory function for CIMXML Client */
// Export this function
__declspec(dllexport) CIMCEnv* _Create_XML_Env(char *id);
CIMCEnv* _Create_XML_Env(char *id)
{
 
    CIMCEnv *env = (CIMCEnv*)malloc(sizeof(CIMCEnv));
    env->hdl=NULL;
    env->ft=&localFT;
    
    return env;
 }
 
