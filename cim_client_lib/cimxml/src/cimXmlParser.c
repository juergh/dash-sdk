
/*
 * cimXmlParser.c
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
 * Author:       Adrian Schuur <schuur@de.ibm.com>
 *
 * Description:
 *
 * CIM XML lexer for sfcc to be used in connection with cimXmlResp.y.
 *
*/


#include <stdio.h>
#include <stdlib.h>
#include <cmci/cmcidt.h>

#include "cimXmlParser.h"
#include "cimXmlResp.h"

#ifdef DMALLOC
#include "dmalloc.h"
#endif


int yylex(YYSTYPE * lvalp, ParserControl * parm);
int yyerror(char *s);

static int attrsOk(XmlBuffer * xb, const XmlElement * e, XmlAttr * r,
                   const char *tag, int etag);
static char *getValue(XmlBuffer * xb, const char *v);
extern int yyparse(void *);

typedef struct tags {
   const char *tag;
   const int tagLen;
   int (*process) (YYSTYPE *, ParserControl * parm);
   int etag;
} Tags;

#define TAG(t) t,(sizeof(t)-1)


static void Throw(XmlBuffer * xb, char *msg)
{
   printf("*** Error: %s\n", msg);
   exit(1);
}

static XmlBuffer *newXmlBuffer(const char *s)
{
   XmlBuffer *xb = (XmlBuffer *) malloc(sizeof(XmlBuffer));
   xb->base = xb->cur = (char *) strdup(s);
   xb->last = xb->cur + strlen(xb->cur);
   xb->nulledChar = 0;
   xb->eTagFound = 0;
   xb->etag = 0;
   return xb;
}

static void releaseXmlBuffer(XmlBuffer *xb)
{
    free (xb->base);
    free (xb);
}

void skipWS(XmlBuffer * xb)
{
   static int c = 0;
   c++;
   while (*xb->cur <= ' ' && xb->last > xb->cur)
      xb->cur++;
}

static int getChars(XmlBuffer * xb, const char *s)
{
   int l = strlen(s);
   if (strncmp(xb->cur, s, l) == 0) {
      xb->cur += l;
      return 1;
   }
   return 0;
}

static int getChar(XmlBuffer * xb, const char c)
{
   if (*xb->cur++ == c)
      return *(xb->cur - 1);
   xb->cur--;
   return 0;
}

char *nextTag(XmlBuffer * xb)
{
   if (xb->nulledChar) {
      xb->nulledChar = 0;
      return xb->cur + 1;
   }
   skipWS(xb);
   if (*xb->cur == '<')
      return xb->cur + 1;
   return NULL;
}

int nextEquals(const char *n, const char *t, const int l)
{
   if (strncmp(n, t, l) == 0) {
      if (!isalnum(*(n + l))) {
         return 1;
      }
   }
   return 0;
}

static char skipTag(XmlBuffer * xb)
{
   while (*xb->cur != '>' && xb->last > xb->cur)
      xb->cur++;
   xb->cur++;
   return *xb->cur;
}

static int getWord(XmlBuffer * xb, const char *w, int xCase)
{
   int l = strlen(w);
   if ((xCase && strncmp(xb->cur, w, l) == 0)
       || (xCase == 0 && strncasecmp(xb->cur, w, l) == 0)) {
      if (!isalnum(*(xb->cur + l))) {
         xb->cur += l;
         return 1;
      }
   }
   return 0;
}

static int tagEquals(XmlBuffer * xb, const char *t)
{
   char *start = NULL;
   int sz = 0;
   if (*xb->cur == 0) {
      xb->cur++;
      sz = 1;
   }                            // why is this needed ?
   else
      start = xb->cur;
   skipWS(xb);
   if (sz || getChar(xb, '<')) {
      skipWS(xb);
      if (getWord(xb, t, 1))
         return 1;
   }
   else {
      printf("OOOPS\n");
   }
   xb->cur = start;
   return 0;
}

static int attrsOk(XmlBuffer * xb, const XmlElement * e, XmlAttr * r,
                   const char *tag, int etag)
{
   unsigned int n;
   char *ptr, wa[32];
   char msg1[] = { "Unknown attribute in list for " };
   char msg2[] = { "Bad attribute list for " };
   char word[32];

   for (n = 0; (e + n)->attr; n++)
      wa[n] = 0;

   xb->eTagFound = 0;
   for (skipWS(xb); isalpha(*xb->cur); skipWS(xb)) {
//      for (n=0; n < a.size(); n++) {
      for (n = 0; (e + n)->attr; n++) {
         if (wa[n] == 1)
            continue;
         if (getWord(xb, (e + n)->attr, 0)) {
            if (!isalnum(*xb->cur)) {
               skipWS(xb);
               if (getChar(xb, '=')) {
                  (r + n)->attr = getValue(xb, (e + n)->attr);
                  wa[n] = 1;
                  goto ok;
               }
               else
                  Throw(xb, "'=' expected in attribute list");
            }
         }
      }
      strncpy(word, xb->cur, 10);
      word[10] = 0;
      ptr = (char *) alloca(strlen(tag) + strlen(msg1) + 8 + 20);
      strcpy(ptr, msg1);
      strcat(ptr, tag);
      strcat(ptr, " (");
      strcat(ptr, word);
      strcat(ptr, ")");
      Throw(xb, ptr);
    ok:;
   }

   if (getChars(xb, "/>")) {
      xb->eTagFound = 1;
      xb->etag = etag;
      return 1;
   }

   else if (getChar(xb, '>'))
      return 1;

   else if (getChars(xb, "?>") && strcmp(tag, "?xml") == 0) {
      xb->eTagFound = 1;
      xb->etag = etag;
      return 1;
   }

   ptr = (char *) alloca(strlen(tag) + strlen(msg2) + 96);
   strcpy(ptr, msg2);
   strcat(ptr, tag);
   strcat(ptr, ": ");
   strncpy(word, xb->cur, 30);
   word[30]=0;
   strcat(ptr, word);
   strcat(ptr," ");
   strcat(ptr, tag);
   Throw(xb, ptr);
   return -1;
}

/* Is this Broken?  I guess we don't allow escaping the quotes */

static char *getValue(XmlBuffer * xb, const char *v)
{
   char dlm = 0;
   char *start = NULL;

   skipWS(xb);
   if ((dlm = getChar(xb, '"')) || (dlm = getChar(xb, '\''))) {
      start = xb->cur;
      while (*xb->cur != dlm) {
         xb->cur++;
      }
      *xb->cur = 0;
      xb->cur++;
      return start;
   }
   return NULL;
}



static char *getContent(XmlBuffer * xb)
{
   char *start = xb->cur,*end;
   if (xb->eTagFound)
      return NULL;
   for (; *xb->cur != '<' && xb->cur < xb->last; xb->cur++);
   if (start == xb->cur) return "";

   while (*start && *start<=' ') start++;
   xb->nulledChar = *(xb->cur);
   *(xb->cur) = 0;
   end=xb->cur;
   if (*(end-1)<=' ') {
      end--;
      while (*end && *end<=' ') *end--=0;
   }
   return start;
}



typedef struct xmlCmpiType {
   char *str;
   CMPIType type;
} xmlCmpiType;

static xmlCmpiType xmlCmpiTypes[] = {
   {"boolean", CMPI_boolean},
   {"char16", CMPI_char16},
   {"real32",  CMPI_real32},
   {"real64",  CMPI_real64},
   {"uint8", CMPI_uint8},
   {"uint16", CMPI_uint16},
   {"uint32", CMPI_uint32},
   {"uint64", CMPI_uint64},
   {"sint8",   CMPI_sint8},
   {"sint16",  CMPI_sint16},
   {"sint32",  CMPI_sint32},
   {"sint64", CMPI_sint64},
   {"string",  CMPI_string},
   {"string",  CMPI_chars},
   {"datetime", CMPI_dateTime},
   {"reference", CMPI_ref},
   {"instance", CMPI_instance}
};

CMPIType xmlToCmpiType(char *xmlTypeStr)
{
    int i;
    if (xmlTypeStr != NULL)
        for (i = 0; i < (sizeof(xmlCmpiTypes) / sizeof(xmlCmpiType)); i++)
            if (strcasecmp(xmlTypeStr, xmlCmpiTypes[i].str) == 0)
                return xmlCmpiTypes[i].type;
    return CMPI_null;
}

char * cmpiToXmlType(CMPIType cmpiType)
{
    int i;
    for (i = 0; i < (sizeof(xmlCmpiTypes) / sizeof(xmlCmpiType)); i++)
        if (cmpiType == xmlCmpiTypes[i].type)
            return xmlCmpiTypes[i].str;
    return NULL;
}

//static XmlBuffer* xmb;

static int procXml(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = { {"version"},
   {"encoding"},
   {NULL}
   };
   XmlAttr attr[2];

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "?xml")) {
      if (attrsOk(parm->xmb, elm, attr, "?xml", ZTOK_XML)) {
         return XTOK_XML;
      }
   }
   return 0;
}

static int procCim(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {"CIMVERSION"},
      {"DTDVERSION"},
      {NULL}
   };
   XmlAttr attr[2];

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "CIM")) {
      if (attrsOk(parm->xmb, elm, attr, "CIM", ZTOK_CIM))
         return XTOK_CIM;
   }
   return 0;
}

static int procMessage(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {"ID"},
      {"PROTOCOLVERSION"},
      {NULL}
   };
   XmlAttr attr[2];

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "MESSAGE")) {
      if (attrsOk(parm->xmb, elm, attr, "MESSAGE", ZTOK_MESSAGE)) {
         lvalp->xtokMessage.id = attr[0].attr;
         parm->respHdr.id = attr[0].attr;
         return XTOK_MESSAGE;
      }
   }
   return 0;
}

static int procSimpleResp(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {NULL}
   };
   XmlAttr attr[1];
   if (tagEquals(parm->xmb, "SIMPLERSP")) {
      if (attrsOk(parm->xmb, elm, attr, "SIMPLERSP", ZTOK_SIMPLERSP))
         return XTOK_SIMPLERSP;
   }
   return 0;
}

static int procIMethodResp(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {"NAME"},
      {NULL}
   };
   XmlAttr attr[1];

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "IMETHODRESPONSE")) {
      if (attrsOk(parm->xmb, elm, attr, "IMETHODRESPONSE", ZTOK_IMETHODRESP)) {
         lvalp->xtokMessage.id = attr[0].attr;
         parm->respHdr.id = attr[0].attr;
         return XTOK_IMETHODRESP;
      }
   }
   return 0;
}

static int procMethodResp(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {"NAME"},
      {NULL}
   };
   XmlAttr attr[1];

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "METHODRESPONSE")) {
      if (attrsOk(parm->xmb, elm, attr, "METHODRESPONSE", ZTOK_METHODRESP)) {
         lvalp->xtokMessage.id = attr[0].attr;
         parm->respHdr.id = attr[0].attr;
         return XTOK_METHODRESP;
      }
   }

   return 0;
}

static int procErrorResp(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {"CODE"},
      {"DESCRIPTION"},
      {NULL}
   };
   XmlAttr attr[2];

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "ERROR")) {
      if (attrsOk(parm->xmb, elm, attr, "ERROR", ZTOK_ERROR)) {
         lvalp->xtokErrorResp.code = attr[0].attr;
         lvalp->xtokErrorResp.description = attr[1].attr;
         return XTOK_ERROR;
      }
   }
   return 0;
}

static int procIRetValue(YYSTYPE * lvalp, ParserControl * parm)
{
   XmlAttr attr[1];

   if (tagEquals(parm->xmb, "IRETURNVALUE")) {
      static XmlElement elm[] = {
         {NULL}
      };

      memset(attr, 0, sizeof(attr));
      if (attrsOk(parm->xmb, elm, attr, "IRETURNVALUE", ZTOK_IRETVALUE)) {
         return XTOK_IRETVALUE;
      }
   }
   return 0;
}

static int procRetValue(YYSTYPE * lvalp, ParserControl * parm)
{
   if (tagEquals(parm->xmb, "RETURNVALUE")) {
      static XmlElement elm[] = {
         {"PARAMTYPE"},
         {NULL}
      };
      XmlAttr attr[2];
      //int i;
      memset(attr, 0, sizeof(attr));
      if (attrsOk(parm->xmb, elm, attr, "RETURNVALUE", ZTOK_RETVALUE)) {
         lvalp->xtokReturnValue.type = CMPI_null;
         if (attr[0].attr) {
            lvalp->xtokReturnValue.type = xmlToCmpiType(attr[0].attr);
         }
         return XTOK_RETVALUE;
      }
   }
   return 0;
}

static int procLocalNameSpacePath(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {NULL}
   };
   XmlAttr attr[1];
   if (tagEquals(parm->xmb, "LOCALNAMESPACEPATH")) {
      if (attrsOk
          (parm->xmb, elm, attr, "LOCALNAMESPACEPATH",
           ZTOK_LOCALNAMESPACEPATH)) {
         return XTOK_LOCALNAMESPACEPATH;
      }
   }
   return 0;
}

static int procClassPath(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {NULL}
   };
   XmlAttr	 attr[1];

   if (tagEquals(parm->xmb, "CLASSPATH")) {
      if (attrsOk(parm->xmb, elm, attr, "CLASSPATH", ZTOK_CLASSPATH))
      {
         return XTOK_CLASSPATH;
      }
   }
   return 0;
}

static int procLocalClassPath(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {NULL}
   };
   XmlAttr	 attr[1];

   if (tagEquals(parm->xmb, "LOCALCLASSPATH")) {
      if (attrsOk(parm->xmb, elm, attr, "LOCALCLASSPATH", ZTOK_LOCALCLASSPATH))
      {
         return XTOK_LOCALCLASSPATH;
      }
   }
   return 0;
}

static int procLocalInstancePath(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {NULL}
   };
   XmlAttr attr[1];
   if (tagEquals(parm->xmb, "LOCALINSTANCEPATH")) {
      if (attrsOk
          (parm->xmb, elm, attr, "LOCALINSTANCEPATH",
           ZTOK_LOCALINSTANCEPATH)) {
         return XTOK_LOCALINSTANCEPATH;
      }
   }
   return 0;
}

static int procObjectPath(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {NULL}
   };
   XmlAttr attr[1];
   if (tagEquals(parm->xmb, "OBJECTPATH")) {
      if (attrsOk(parm->xmb, elm, attr, "OBJECTPATH",
           ZTOK_OBJECTPATH)) {
         lvalp->xtokValue.value = getContent(parm->xmb);
         return XTOK_OBJECTPATH;
      }
   }
   return 0;
}

static int procNameSpace(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {"NAME"},
      {NULL}
   };
   XmlAttr attr[1];

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "NAMESPACE")) {
      if (attrsOk(parm->xmb, elm, attr, "NAMESPACE", ZTOK_NAMESPACE)) {
         lvalp->xtokNameSpace.ns = attr[0].attr;
         return XTOK_NAMESPACE;
      }
   }
   return 0;
}

static int procParamValue(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {"NAME"},
      {"PARAMTYPE"},
      {NULL}
   };
   XmlAttr attr[2];
   //int i, m;

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "PARAMVALUE")) {
      if (attrsOk(parm->xmb, elm, attr, "PARAMVALUE", ZTOK_PARAMVALUE)) {
         lvalp->xtokParamValue.name = attr[0].attr;
         lvalp->xtokParamValue.type = CMPI_null;
         if (attr[1].attr) {
            lvalp->xtokParamValue.type = xmlToCmpiType(attr[1].attr);
         }
         return XTOK_PARAMVALUE;
      }
   }
   return 0;
}

static int procClassName(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {"NAME"},
      {NULL}
   };
   XmlAttr attr[1];

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "CLASSNAME")) {
      if (attrsOk(parm->xmb, elm, attr, "CLASSNAME", ZTOK_CLASSNAME)) {
         lvalp->className = attr[0].attr;
         return XTOK_CLASSNAME;
      }
   }
   return 0;
}

static int procInstanceName(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {"CLASSNAME"},
      {NULL}
   };
   XmlAttr attr[1];

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "INSTANCENAME")) {
      if (attrsOk(parm->xmb, elm, attr, "INSTANCENAME", ZTOK_INSTANCENAME)) {
         lvalp->xtokInstanceName.className = attr[0].attr;
         return XTOK_INSTANCENAME;
      }
   }
   return 0;
}

static int procKeyBinding(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {"NAME"},
      {NULL}
   };
   XmlAttr attr[1];

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "KEYBINDING")) {
      if (attrsOk(parm->xmb, elm, attr, "KEYBINDING", ZTOK_KEYBINDING)) {
         lvalp->xtokInstanceName.className = attr[0].attr;
         return XTOK_KEYBINDING;
      }
   }
   return 0;
}

static int procInstance(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {"CLASSNAME"},
      {NULL}
   };
   XmlAttr attr[1];

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "INSTANCE")) {
      if (attrsOk(parm->xmb, elm, attr, "INSTANCE", ZTOK_INSTANCE)) {
         lvalp->xtokInstance.className = attr[0].attr;
         return XTOK_INSTANCE;
      }
   }
   return 0;
}

static int procClass(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {"NAME"},
      {"SUPERCLASS"},
      {NULL}
   };
   XmlAttr attr[2];

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "CLASS")) {
      if (attrsOk(parm->xmb, elm, attr, "CLASS", ZTOK_CLASS)) {
         lvalp->xtokClass.className = attr[0].attr;
         lvalp->xtokClass.superClass = attr[1].attr;
         return XTOK_CLASS;
      }
   }
   return 0;
}

static int procKeyValue(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {"VALUETYPE"},
      {NULL}
   };
   XmlAttr attr[1] = {
      {NULL}
   };
   char *val;

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "KEYVALUE")) {
      if (attrsOk(parm->xmb, elm, attr, "KEYVALUE", ZTOK_KEYVALUE)) {
         val = getContent(parm->xmb);
         lvalp->xtokKeyValue.valueType = attr[0].attr;
         lvalp->xtokKeyValue.value = val;
         return XTOK_KEYVALUE;
      }
   }
   return 0;
}

static int procHost(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {NULL}
   };
   XmlAttr attr[1];
   if (tagEquals(parm->xmb, "HOST")) {
      if (attrsOk(parm->xmb, elm, attr, "HOST", ZTOK_HOST)) {
         lvalp->xtokHost.host = getContent(parm->xmb);
         return XTOK_HOST;
      }
   }
   return 0;
}

static int procValue(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {NULL}
   };
   XmlAttr attr[1];
   if (tagEquals(parm->xmb, "VALUE")) {
      char *v;
      if (attrsOk(parm->xmb, elm, attr, "VALUE", ZTOK_VALUE)) {
         v=getContent(parm->xmb);
         lvalp->xtokValue.value = v;
         return XTOK_VALUE;
      }
   }
   return 0;
}

static int procValueArray(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {NULL}
   };
   XmlAttr attr[1];
   if (tagEquals(parm->xmb, "VALUE.ARRAY")) {
      if (attrsOk(parm->xmb, elm, attr, "VALUE.ARRAY",
           ZTOK_VALUEARRAY)) {
         return XTOK_VALUEARRAY;
      }
   }
   return 0;
}

static int procValueNamedInstance(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {NULL}
   };
   XmlAttr attr[1];
   if (tagEquals(parm->xmb, "VALUE.NAMEDINSTANCE")) {
      if (attrsOk(parm->xmb, elm, attr, "VALUE.NAMEDINSTANCE",
           ZTOK_VALUENAMEDINSTANCE)) {
         lvalp->xtokValue.value = getContent(parm->xmb);
         return XTOK_VALUENAMEDINSTANCE;
      }
   }
   return 0;
}

static int procInstancePath(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {NULL}
   };
   XmlAttr attr[1];
   if (tagEquals(parm->xmb, "INSTANCEPATH")) {
      if (attrsOk(parm->xmb, elm, attr, "INSTANCEPATH",
           ZTOK_INSTANCEPATH)) {
         lvalp->xtokValue.value = getContent(parm->xmb);
         return XTOK_INSTANCEPATH;
      }
   }
   return 0;
}

static int procNameSpacePath(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {NULL}
   };
   XmlAttr attr[1];
   if (tagEquals(parm->xmb, "NAMESPACEPATH")) {
      if (attrsOk(parm->xmb, elm, attr, "NAMESPACEPATH",
           ZTOK_NAMESPACEPATH)) {
         lvalp->xtokValue.value = getContent(parm->xmb);
         return XTOK_NAMESPACEPATH;
      }
   }
   return 0;
}

static int procValueReference(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {NULL}
   };
   XmlAttr attr[1];
   if (tagEquals(parm->xmb, "VALUE.REFERENCE")) {
      if (attrsOk(parm->xmb, elm, attr, "VALUE.REFERENCE",
           ZTOK_VALUEREFERENCE)) {
         lvalp->xtokValue.value = getContent(parm->xmb);
         return XTOK_VALUEREFERENCE;
      }
   }
   return 0;
}

static int procValueObjectWithPath(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = {
      {NULL}
   };
   XmlAttr attr[1];
   if (tagEquals(parm->xmb, "VALUE.OBJECTWITHPATH")) {
      if (attrsOk(parm->xmb, elm, attr, "VALUE.OBJECTWITHPATH",
           XTOK_VALUEOBJECTWITHPATH)) {
         return XTOK_VALUEOBJECTWITHPATH;
      }
   }
   return 0;
}

static int procQualifier(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = { {"NAME"},
   {"TYPE"},
   {"PROPAGATED"},
   {"OVERRIDABLE"},
   {"TOSUBCLASS"},
   {"TOINSTANCE"},
   {"TRANSLATABLE"},
   {NULL}
   };
   XmlAttr attr[8];
   //int i, m;

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "QUALIFIER")) {
      if (attrsOk(parm->xmb, elm, attr, "QUALIFIER", ZTOK_QUALIFIER)) {
         memset(&lvalp->xtokQualifier, 0, sizeof(XtokQualifier));
         lvalp->xtokQualifier.name = attr[0].attr;
         lvalp->xtokQualifier.type = xmlToCmpiType(attr[1].attr);
         if (attr[2].attr)
            lvalp->xtokQualifier.propagated = !strcasecmp(attr[2].attr, "true");
         if (attr[3].attr)
            lvalp->xtokQualifier.overridable =
                !strcasecmp(attr[3].attr, "true");
         if (attr[4].attr)
            lvalp->xtokQualifier.tosubclass = !strcasecmp(attr[4].attr, "true");
         if (attr[5].attr)
            lvalp->xtokQualifier.toinstance = !strcasecmp(attr[5].attr, "true");
         if (attr[6].attr)
            lvalp->xtokQualifier.translatable =
                !strcasecmp(attr[6].attr, "true");
         return XTOK_QUALIFIER;
      }
   }
   return 0;
}


static int procProperty(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = { {"NAME"},
   {"TYPE"},
   {"CLASSORIGIN"},
   {"PROPAGATED"},
   {NULL}
   };
   XmlAttr attr[4];
   //int i, m;

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "PROPERTY")) {
      attr[1].attr = NULL;
      lvalp->xtokProperty.valueType = (CMPIType) 1;
      if (attrsOk(parm->xmb, elm, attr, "PROPERTY", ZTOK_PROPERTY)) {
         memset(&lvalp->xtokProperty, 0, sizeof(XtokProperty));
         lvalp->xtokProperty.name = attr[0].attr;
         lvalp->xtokProperty.valueType = CMPI_null;
         if (attr[1].attr)
            lvalp->xtokProperty.valueType = xmlToCmpiType(attr[1].attr);
         lvalp->xtokProperty.classOrigin = attr[2].attr;
         if (attr[3].attr)
            lvalp->xtokProperty.propagated = !strcasecmp(attr[3].attr, "true");
         lvalp->xtokProperty.propType = typeProperty_Value;
         return XTOK_PROPERTY;
      }
   }
   return 0;
}

static int procPropertyArray(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elmPA[] = { {"NAME"},
   {"TYPE"},
   {"CLASSORIGIN"},
   {"PROPAGATED"},
   {"ARRAYSIZE"},
   {NULL}
   };
   XmlAttr attr[5];
   //int i, m;

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "PROPERTY.ARRAY")) {
      if (attrsOk(parm->xmb, elmPA, attr, "PROPERTY.ARRAY", ZTOK_PROPERTYARRAY)) {
         lvalp->xtokProperty.name = attr[0].attr;
         lvalp->xtokProperty.valueType = CMPI_null;
         if (attr[1].attr)
            lvalp->xtokProperty.valueType = xmlToCmpiType(attr[1].attr);
         lvalp->xtokProperty.classOrigin = attr[2].attr;
         if (attr[3].attr)
            lvalp->xtokProperty.propagated = !strcasecmp(attr[3].attr, "true");
         lvalp->xtokParam.arraySize = attr[4].attr;
         lvalp->xtokProperty.propType = typeProperty_Array;
         lvalp->xtokProperty.val.array.next = lvalp->xtokProperty.val.array.max = 0;
         return XTOK_PROPERTYARRAY;
      }
   }
   return 0;
}

static int procPropertyReference(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = { {"NAME"},
   {"REFERENCECLASS"},
   {"CLASSORIGIN"},
   {"PROPAGATED"},
   {NULL}
   };
   XmlAttr attr[4];

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "PROPERTY.REFERENCE")) {
      attr[1].attr = NULL;
      if (attrsOk(parm->xmb, elm, attr, "PROPERTY.REFERENCE", ZTOK_PROPERTYREFERENCE)) {
         memset(&lvalp->xtokProperty, 0, sizeof(XtokProperty));
         lvalp->xtokProperty.valueType = CMPI_ref;
         lvalp->xtokProperty.name = attr[0].attr;
         lvalp->xtokProperty.referenceClass = attr[1].attr;
         lvalp->xtokProperty.classOrigin = attr[2].attr;
         if (attr[3].attr)
            lvalp->xtokProperty.propagated = !strcasecmp(attr[3].attr, "true");
         lvalp->xtokProperty.propType = typeProperty_Reference;
         return XTOK_PROPERTYREFERENCE;
      }
   }
   return 0;
}

static int procMethod(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] = { {"NAME"},
   {"TYPE"},
   {"CLASSORIGIN"},
   {"PROPAGATED"},
   {NULL}
   };
   XmlAttr attr[4];
   //int i, m;

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "METHOD")) {
      attr[1].attr = NULL;
      if (attrsOk(parm->xmb, elm, attr, "METHOD", ZTOK_METHOD)) {
         memset(&lvalp->xtokMethod, 0, sizeof(XtokMethod));
         lvalp->xtokMethod.name = attr[0].attr;
         lvalp->xtokMethod.type = CMPI_null;
         if (attr[1].attr)
            lvalp->xtokMethod.type = xmlToCmpiType(attr[1].attr);
         lvalp->xtokMethod.classOrigin = attr[2].attr;
         if (attr[3].attr)
            lvalp->xtokMethod.propagated = !strcasecmp(attr[3].attr, "true");
         return XTOK_METHOD;
      }
   }
   return 0;
}

static int procParam(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] =
   { {"NAME"},
     {"TYPE"},
     {NULL}
   };
   XmlAttr attr[2];
   //int i,m;

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "PARAMETER")) {
      attr[1].attr = NULL;
      if (attrsOk(parm->xmb, elm, attr, "PARAMETER", ZTOK_PARAM)) {
         memset(&lvalp->xtokParam, 0, sizeof(XtokParam));
         lvalp->xtokParam.pType = ZTOK_PARAM;
         lvalp->xtokParam.name = attr[0].attr;
         lvalp->xtokParam.type = CMPI_null;
         if (attr[1].attr)
            lvalp->xtokParam.type = xmlToCmpiType(attr[1].attr);
         return XTOK_PARAM;
      }
   }
   return 0;
}

static int procParamArray(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] =
   { {"NAME"},
     {"TYPE"},
     {"ARRAYSIZE"},
     {NULL}
   };
   XmlAttr attr[3];
   //int i,m;

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "PARAMETER.ARRAY")) {
      attr[1].attr = NULL;
      if (attrsOk(parm->xmb, elm, attr, "PARAMETER.ARRAY", ZTOK_PARAMARRAY)) {
         memset(&lvalp->xtokParam, 0, sizeof(XtokParam));
         lvalp->xtokParam.pType = ZTOK_PARAMARRAY;
         lvalp->xtokParam.name = attr[0].attr;
         lvalp->xtokParam.type = CMPI_null;
         if (attr[1].attr)
            lvalp->xtokParam.type = xmlToCmpiType(attr[1].attr) | CMPI_ARRAY;
         lvalp->xtokParam.arraySize = attr[2].attr;
         return XTOK_PARAMARRAY;
      }
   }
   return 0;
}

static int procParamRef(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] =
   { {"NAME"},
     {"REFERENCECLASS"},
     {NULL}
   };
   XmlAttr attr[2];

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "PARAMETER.REFERENCE")) {
      attr[1].attr = NULL;
      if (attrsOk(parm->xmb, elm, attr, "PARAMETER.REFERENCE", ZTOK_PARAMREF)) {
         memset(&lvalp->xtokParam, 0, sizeof(XtokParam));
         lvalp->xtokParam.pType = ZTOK_PARAMREF;
         lvalp->xtokParam.name = attr[0].attr;
         lvalp->xtokParam.refClass = attr[1].attr;
         lvalp->xtokParam.type = CMPI_ref;
         return XTOK_PARAMREF;
      }
   }
   return 0;
}

static int procParamRefArray(YYSTYPE * lvalp, ParserControl * parm)
{
   static XmlElement elm[] =
   { {"NAME"},
     {"REFERENCECLASS"},
     {"ARRAYSIZE"},
     {NULL}
   };
   XmlAttr attr[3];

   memset(attr, 0, sizeof(attr));
   if (tagEquals(parm->xmb, "PARAMETER.REFARRAY")) {
      attr[1].attr = NULL;
      if (attrsOk(parm->xmb, elm, attr, "PARAMETER.REFARRAY", ZTOK_PARAM)) {
         memset(&lvalp->xtokParam, 0, sizeof(XtokParam));
         lvalp->xtokParam.pType = ZTOK_PARAMREFARRAY;
         lvalp->xtokParam.name = attr[0].attr;
         lvalp->xtokParam.refClass = attr[1].attr;
         lvalp->xtokParam.arraySize = attr[2].attr;
         lvalp->xtokParam.type = CMPI_refA;
         return XTOK_PARAM;
      }
   }
   return 0;
}


static Tags tags[] = {
   {TAG("?xml"), procXml, ZTOK_XML},
   {TAG("CIM"), procCim, ZTOK_CIM},
   {TAG("MESSAGE"), procMessage, ZTOK_MESSAGE},
   {TAG("SIMPLERSP"), procSimpleResp, ZTOK_SIMPLERSP},
   {TAG("ERROR"), procErrorResp, ZTOK_ERROR},
   {TAG("IMETHODRESPONSE"), procIMethodResp, ZTOK_IMETHODRESP},
   {TAG("IRETURNVALUE"), procIRetValue, ZTOK_IRETVALUE},
   {TAG("LOCALNAMESPACEPATH"), procLocalNameSpacePath, ZTOK_LOCALNAMESPACEPATH},
   {TAG("LOCALINSTANCEPATH"), procLocalInstancePath, ZTOK_LOCALINSTANCEPATH},
   {TAG("LOCALCLASSPATH"), procLocalClassPath, ZTOK_LOCALCLASSPATH},
   {TAG("NAMESPACEPATH"), procNameSpacePath, ZTOK_NAMESPACEPATH},
   {TAG("NAMESPACE"), procNameSpace, ZTOK_NAMESPACE},
   {TAG("PARAMVALUE"), procParamValue, ZTOK_PARAMVALUE},
   {TAG("CLASSNAME"), procClassName, ZTOK_CLASSNAME},
   {TAG("VALUE.ARRAY"), procValueArray, ZTOK_VALUEARRAY},
   {TAG("VALUE.NAMEDINSTANCE"), procValueNamedInstance, ZTOK_VALUENAMEDINSTANCE},
   {TAG("VALUE.REFERENCE"), procValueReference, ZTOK_VALUEREFERENCE},
   {TAG("VALUE.OBJECTWITHPATH"), procValueObjectWithPath, ZTOK_VALUEOBJECTWITHPATH},
   {TAG("VALUE"), procValue, ZTOK_VALUE},
   {TAG("HOST"), procHost, ZTOK_HOST},
   {TAG("KEYVALUE"), procKeyValue, ZTOK_KEYVALUE},
   {TAG("KEYBINDING"), procKeyBinding, ZTOK_KEYBINDING},
   {TAG("INSTANCEPATH"), procInstancePath, ZTOK_INSTANCEPATH},
   {TAG("INSTANCENAME"), procInstanceName, ZTOK_INSTANCENAME},
   {TAG("INSTANCE"), procInstance, ZTOK_INSTANCE},
   {TAG("PROPERTY.REFERENCE"), procPropertyReference, ZTOK_PROPERTYREFERENCE},
   {TAG("PROPERTY.ARRAY"), procPropertyArray, ZTOK_PROPERTYARRAY},
   {TAG("PROPERTY"), procProperty, ZTOK_PROPERTY},
   {TAG("QUALIFIER"), procQualifier, ZTOK_QUALIFIER},
   {TAG("PARAMETER.ARRAY"), procParamArray, ZTOK_PARAMARRAY},
   {TAG("PARAMETER.REFERENCE"), procParamRef, ZTOK_PARAMREF},
   {TAG("PARAMETER.REFARRAY"), procParamRefArray, ZTOK_PARAMREFARRAY},
   {TAG("PARAMETER"), procParam, ZTOK_PARAM},
   {TAG("METHOD"), procMethod, ZTOK_METHOD},
   {TAG("CLASS"), procClass, ZTOK_CLASS},
   {TAG("OBJECTPATH"), procObjectPath, ZTOK_OBJECTPATH},
   {TAG("METHODRESPONSE"), procMethodResp, ZTOK_METHODRESP},
   {TAG("RETURNVALUE"), procRetValue, ZTOK_RETVALUE},
   {TAG("CLASSPATH"), procClassPath, ZTOK_CLASSPATH}
};
#define TAGS_NITEMS	(int)(sizeof(tags)/sizeof(Tags))

int yylex(YYSTYPE * lvalp, ParserControl * parm)
{
   int i, rc;
   char *next;

   for (;;) {
      next = nextTag(parm->xmb);
      if (next == NULL) {
         return 0;
      }
//      fprintf(stderr,"--- token: %.32s\n",next); //usefull for debugging
      if (parm->xmb->eTagFound) {
         parm->xmb->eTagFound = 0;
         return parm->xmb->etag;
      }

      if (*next == '/') {
         for (i = 0; i < TAGS_NITEMS; i++) {
            if (nextEquals(next + 1, tags[i].tag, tags[i].tagLen) == 1) {
               skipTag(parm->xmb);
               return tags[i].etag;
            }
         }
      }

      else {
         if (strncmp(parm->xmb->cur, "<!--", 4) == 0) {
            parm->xmb->cur = strstr(parm->xmb->cur, "-->") + 3;
            continue;
         }
         for (i = 0; i < TAGS_NITEMS; i++) {
            if (nextEquals(next, tags[i].tag, tags[i].tagLen) == 1) {
//	       printf("+++ %d\n",i);
               rc=tags[i].process(lvalp, parm);
               return rc;
            }
         }
      }
      break;
   }
   return 0;
}

int yyerror(char *s)
{
   printf("*-* yyerror: %s\n", s);
   exit(5);
}

ResponseHdr scanCimXmlResponse(const char *xmlData, CMPIObjectPath *cop)
{
   ParserControl control;
   XtokParamValue *outParam=NULL;
   CMPIArgs *args = NULL;
   CMPIValue value;
   XmlBuffer *xmb;

#if DEBUG
   extern int do_debug;

   if (do_debug)
       fprintf(stderr,"*** CIMOM response: %s\n", xmlData);
#endif

   memset(&control,0,sizeof(control));

   xmb = newXmlBuffer(xmlData);
   control.xmb = xmb;
   control.respHdr.xmlBuffer = xmb;

   control.respHdr.rvArray=newCMPIArray(0,0,NULL);
   control.da_nameSpace=(char*)getNameSpaceChars(cop);

   control.heap = parser_heap_init();

   control.respHdr.rc = yyparse(&control);

   /* Process OUT parameters */
   outParam = control.paramValues.first;

   if (outParam) { 

       args = newCMPIArgs(NULL);

       while (outParam) {

           /*value = (outParam->type == CMPI_ref) 
               ? str2CMPIValue(outParam->type, NULL, &outParam->valueRef)
               : str2CMPIValue(outParam->type, outParam->value.value, NULL);*/
           value = str2CMPIValue(outParam->type, outParam->value.value, &outParam->valueRef);

           /* Add it to the args list */
           args->ft->addArg ( args, outParam->name, &value, outParam->type);
	   native_release_CMPIValue(outParam->type,&value);
           outParam = outParam->next;
       }
       control.respHdr.outArgs = args;
       /* Note : Freeing of list will be done by
        * parser_heap_term() routine.
        */
   }

   parser_heap_term(control.heap);

   releaseXmlBuffer(xmb);

   return control.respHdr;
}

#define PARSER_HEAP_INCREMENT 100

ParserHeap* parser_heap_init()
{
  return calloc(1,sizeof(ParserHeap));
}

void parser_heap_term(ParserHeap* ph)
{
  int i;
  if (ph) {
    for (i=ph->numBlocks - 1; i >= 0; i--) {
      void * blk = ph->blocks[i];
      if (blk != NULL)
	  free(ph->blocks[i]);
    }
    free(ph->blocks);
    free(ph);
  }
}

static int parser_heap_grow(ParserHeap *ph)
{
  if (ph) {
    if (ph->numBlocks >= ph->capacity) {
      ph->blocks = realloc(ph->blocks,
			   sizeof(void*)*(ph->capacity+PARSER_HEAP_INCREMENT));
      if (ph->blocks) {
	ph->capacity += PARSER_HEAP_INCREMENT;
      } else {
	return -1;
      }
    }
    ph->numBlocks += 1; 
    return ph->numBlocks - 1;
  } else {
    return -1;
  }
}

void* parser_malloc(ParserHeap *ph, size_t sz)
{
  int idx = parser_heap_grow(ph);
  if (idx >= 0) {
    return (ph->blocks[idx]=malloc(sz));
  } else {
    return NULL;
  }
}

void* parser_calloc(ParserHeap *ph, size_t num, size_t sz)
{
  int idx = parser_heap_grow(ph);
  if (idx >= 0) {
    return (ph->blocks[idx]=calloc(num,sz));
  } else {
    return NULL;
  }
}

void* parser_realloc(ParserHeap *ph, void *p, size_t sz)
{
   int i;
   int idx;

   for (i=ph->numBlocks - 1; i >= 0; i--) 
      if(ph->blocks[i]==p) ph->blocks[i]=NULL;

  idx = parser_heap_grow(ph);
  if (idx >= 0) {
    return (ph->blocks[idx]=realloc(p,sz));
  } else {
    return NULL;
  }
}

void* parser_strdup(ParserHeap *ph, const char *s)
{
  int idx = parser_heap_grow(ph);
  if (idx >= 0) {
    return (ph->blocks[idx]=strdup(s));
  } else {
    return NULL;
  }
}

