%{

/*
 * cimXmlResp.y
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
 * CIM XML grammar for sfcc.
 *
*/


/*
**=============================================================================
**
** Includes
**
**=============================================================================
*/

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "cimXmlParser.h"

#ifdef DMALLOC
#include "dmalloc.h"
#endif


//
// Define the global parser state object:
//

#define YYPARSE_PARAM parm
#define YYLEX_PARAM parm
#define YYERROR_VERBOSE 1

#define PARM ((ParserControl*)parm)

#define PARSER_MALLOC(s) parser_malloc(PARM->heap,(s))
#define PARSER_CALLOC(n,s) parser_calloc(PARM->heap,(n),(n))
#define PARSER_REALLOC(p,s) parser_realloc(PARM->heap,(p),(s))
#define PARSER_STRDUP(s) parser_strdup(PARM->heap,(s))

extern int yyerror(char*);
extern int yylex (void *lvalp, ParserControl *parm);
extern CMPIConstClass * native_new_CMPIConstClass ( char  *cn, CMPIStatus * rc );
extern int addClassProperty( CMPIConstClass * ccls, char * name,
			     CMPIValue * value, CMPIType type,
			     CMPIValueState state);
extern CMPIType guessType(char *val);
extern int addInstPropertyQualifier( CMPIInstance* ci, char * pname,
				     char *qname, CMPIValue * value,
				     CMPIType type);
extern int addClassPropertyQualifier( CMPIConstClass* cc, char * pname,
				      char *qname, CMPIValue * value,
				      CMPIType type);
extern int addClassQualifier( CMPIConstClass* cc, char * name,
				      CMPIValue * value,
				      CMPIType type);
extern char *XmlToAsciiStr(char *XmlStr);

#if DEBUG
extern int do_debug;
#endif

static inline int isBoolean(CMPIData data)
{
   if (data.type == CMPI_chars) {
      if (strcasecmp(data.value.chars,"true") == 0) return 0xffff;
      if (strcasecmp(data.value.chars,"false") == 0) return 0;
   }
   return -1;
}

static void createPath(CMPIObjectPath **op, XtokInstanceName *p)
{
   int i;
   CMPIValue val,*valp;
   CMPIType type;

   *op = newCMPIObjectPath(NULL, p->className, NULL);
   for (i = 0; i < p->bindings.next; i++) {
      valp = getKeyValueTypePtr(p->bindings.keyBindings[i].type,
                                p->bindings.keyBindings[i].value,
                                &p->bindings.keyBindings[i].ref,
                                &val, &type);
      CMAddKey(*op, p->bindings.keyBindings[i].name, valp, type);
      if (type == CMPI_ref) {
	CMRelease(valp->ref);
      }
   }
}

static void setInstProperties(CMPIInstance *ci, XtokProperties *ps)
{
   XtokProperty *np = NULL,*p = ps ? ps->first : NULL;
   CMPIValue val;
   CMPIObjectPath *op;
   CMPIStatus status;
   CMPIType   type;
   XtokQualifier *nq = NULL,*q;
   XtokQualifiers *qs;
   int rc, n, setq;

   while (p) {
      setq=1;
      switch (p->propType) {
      case typeProperty_Value:
         type = p->valueType;
         if (p->val.value != NULL && p->val.null==0) {
            if (type == CMPI_string || type == CMPI_chars) {
                char *charsStr = XmlToAsciiStr(p->val.value);
                val = str2CMPIValue(type, charsStr, NULL);
                free (charsStr);
            }
            else
                val = str2CMPIValue(type, p->val.value, NULL);
            CMSetProperty(ci, p->name, &val, type);
	    native_release_CMPIValue(type, &val);
         }
         else {
            CMSetProperty(ci, p->name, NULL, type);
            setq = 0;
         }
         break;
      case typeProperty_Reference: 
         op=p->val.ref.op;
         CMSetProperty(ci, p->name, &op, CMPI_ref);
	 CMRelease(op);
         break;
      case typeProperty_Array:
         type = p->valueType;
         if (p->val.array.next > 0) {
            CMPIArray *arr = newCMPIArray(0, type, &status);
            if (p->val.array.max > 0) {
            int i;
               for (i = 0; i < p->val.array.next; ++i)
               {
                   char *valStr = p->val.array.values[i];
                   if (type == CMPI_string || type == CMPI_chars) {
                       char *charsStr = XmlToAsciiStr(valStr);
                       val = str2CMPIValue(type, charsStr, NULL);
                       free (charsStr);
                   }
                   else
                       val = str2CMPIValue(type, valStr, NULL);
                   CMSetArrayElementAt(arr, i, &val, type);
	           native_release_CMPIValue(type, &val);
               }
            }
            val.array = arr;
            CMSetProperty(ci, p->name, &val, type | CMPI_ARRAY);
            CMRelease(arr);			/* cloned in property */
         }
         else {
            CMSetProperty(ci, p->name, NULL, p->valueType | CMPI_ARRAY);
            setq = 0;
         }
         break;
      }

      if (setq) {
         qs=&p->val.qualifiers;
         q=qs ? qs->first : NULL;  
         n=0;   
         while (q) {
            if (q->type & CMPI_ARRAY) {
               CMPIArray *arr = NULL;
               arr = newCMPIArray(0, type, NULL);
               type  = q->type & ~CMPI_ARRAY;
               int i;
               if (q->array.max) {
                   for (i = 0; i < q->array.next; ++i) {
                  val = str2CMPIValue(type, q->array.values[i], NULL);
                  CMSetArrayElementAt(arr, i, &val, type);
                  native_release_CMPIValue(type,&val);
               }
               }
               rc = addInstPropertyQualifier(ci, p->name, q->name,
					     (CMPIValue *)&arr, q->type); 
               native_release_CMPIValue(q->type,(CMPIValue*)&arr);
            }
            else {
               val = str2CMPIValue(q->type, q->value, NULL);
               rc= addInstPropertyQualifier(ci, p->name, q->name, &val, q->type);
               native_release_CMPIValue(q->type,&val);
            }   
            nq = q->next; 
            q = nq;
         }
      }

      np = p->next;
      p = np;

   }

   if (ps)
      ps->first = ps->last =  NULL;
}

static void setInstQualifiers(CMPIInstance *ci, XtokQualifiers *qs)
{
   XtokQualifier *nq = NULL,*q = qs ? qs->first : NULL;
   CMPIValue val;
   int rc;
   
   while (q) {
      if (q->type & CMPI_ARRAY) {
               CMPIType type=q->type&~CMPI_ARRAY;
               CMPIArray *arr = newCMPIArray(0, type, NULL);
               int i;
          if (q->array.max) {
              for (i = 0; i < q->array.next; ++i) {
                  val = str2CMPIValue(type, q->array.values[i], NULL);
                  CMSetArrayElementAt(arr, i, &val, type);
                  native_release_CMPIValue(type,&val);
               }
               rc = addInstQualifier(ci, q->name, (CMPIValue*)&arr, q->type);
               native_release_CMPIValue(q->type,(CMPIValue*)&arr);
      }
      }
      else {
         val = str2CMPIValue(q->type, q->value, NULL);
         rc = addInstQualifier(ci, q->name, &val, q->type);
         native_release_CMPIValue( q->type,&val);
      }
      nq = q->next;
      q = nq;
   }
   if (qs) {
      qs->first = qs->last = NULL;
   }
}

static void setClassProperties(CMPIConstClass *cls, XtokProperties *ps)
{
   XtokProperty *np = NULL,*p = ps ? ps->first : NULL;
   CMPIValue val;
   CMPIArray       *arr;
   XtokQualifier   *nq,*q;
   XtokQualifiers *qs;
   int rc, n;

      val.uint64=0l;
   while (p) {
      switch (p->propType) {
      case typeProperty_Value:
         addClassProperty(cls, p->name, &val, p->valueType, CMPI_nullValue);
         break;
      case typeProperty_Reference:
         addClassProperty(cls, p->name, &val, CMPI_ref, CMPI_nullValue);
	 break;
      case typeProperty_Array:
         val.array = arr;
	 addClassProperty(cls, p->name, &val,
                               p->valueType | CMPI_ARRAY, CMPI_nullValue);
         break;
      }

      qs=&p->val.qualifiers;
      q=qs ? qs->first : NULL;  
      n=0;   
      while (q) {
         if (q->type & CMPI_ARRAY) {
            CMPIType type=q->type&~CMPI_ARRAY;
            arr = newCMPIArray(0, type, NULL);
            int i;
            if (q->array.max) {
                for (i = 0; i < q->array.next; ++i) {
               val = str2CMPIValue(type, q->array.values[i], NULL);
               CMSetArrayElementAt(arr, i, &val, type);
               native_release_CMPIValue(type,&val);
            }
            }
            val.array = arr;
            rc = addClassPropertyQualifier(cls, p->name, q->name, &val, q->type); 
            native_release_CMPIValue(q->type,(CMPIValue*)&arr);
         }
         else {
            val = str2CMPIValue(q->type, q->value, NULL);
            rc= addClassPropertyQualifier(cls, p->name, q->name, &val, q->type);
            native_release_CMPIValue(q->type,&val);
         }   
         nq = q->next; 
         q = nq;
      }

      np = p->next;
      p = np;
   }
   if (ps) ps->first = ps->last = NULL;
}

static void setClassQualifiers(CMPIConstClass *cls, XtokQualifiers *qs)
{
   XtokQualifier *nq = NULL,*q = qs ? qs->first : NULL;
   CMPIValue val;
   int rc;
   
   while (q) {
      if (q->type & CMPI_ARRAY) {
               CMPIType type=q->type&~CMPI_ARRAY;
               CMPIArray *arr = newCMPIArray(0, type, NULL);
               int i;
          if (q->array.max > 0) {
              for (i = 0; i < q->array.next; ++i) {
                   char *valStr = q->array.values[i];
                   if (type == CMPI_string || type == CMPI_chars)
                   {
                       char *charsStr = XmlToAsciiStr(valStr);
                       val = str2CMPIValue(type, charsStr, NULL);
                       free (charsStr);
                   }
                   else
                       val = str2CMPIValue(type, valStr, NULL);
                  CMSetArrayElementAt(arr, i, &val, type);
                  native_release_CMPIValue(type,&val);
               }
               rc = addClassQualifier(cls, q->name, (CMPIValue*)&arr, q->type);
               native_release_CMPIValue(q->type,(CMPIValue*)&arr);
      }
      }
      else {
          char *valStr = q->value;
          if (q->type == CMPI_string || q->type == CMPI_chars)
          {
              char *charsStr = XmlToAsciiStr(valStr);
              val = str2CMPIValue(q->type, charsStr, NULL);
              free (charsStr);
          }
          else
              val = str2CMPIValue(q->type, valStr, NULL);
         rc = addClassQualifier(cls, q->name, &val, q->type);
         native_release_CMPIValue( q->type,&val);
      }
      nq = q->next;
      q = nq;
   }
   if (qs) {
      qs->first = qs->last = NULL;
   }
}


static void addProperty(ParserControl *parm, XtokProperties *ps, XtokProperty *p)
{
   XtokProperty *np;
   np = (XtokProperty*)PARSER_MALLOC(sizeof(XtokProperty));
   memcpy(np, p, sizeof(XtokProperty));
   np->next = NULL;
   if (ps->last) ps->last->next = np;
   else ps->first = np;
   ps->last = np;
}

static void addParamValue(ParserControl *parm, XtokParamValues *vs, XtokParamValue *v)
{
   XtokParamValue *nv;
   nv = (XtokParamValue*)PARSER_MALLOC(sizeof(XtokParamValue));
   memcpy(nv, v, sizeof(XtokParamValue));
   nv->next = NULL;
   if (vs->last)
      vs->last->next = nv;
   else
      vs->first = nv;
   vs->last = nv;
}

static void addQualifier(ParserControl *parm, XtokQualifiers *qs, XtokQualifier *q)
{
   XtokQualifier *nq;
   nq = (XtokQualifier*)PARSER_MALLOC(sizeof(XtokQualifier));
   memcpy(nq, q, sizeof(XtokQualifier));
   nq->next = NULL;
   if (qs->last) qs->last->next = nq;
   else qs->first = nq;
   qs->last = nq;
}

static void addMethod(ParserControl *parm, XtokMethods *ms, XtokMethod *m)
{
#if 0	/* TODO: Reactivate when setMethod is implemented */
   XtokMethod *nm;
   nm = (XtokMethod*)PARSER_MALLOC(sizeof(XtokMethod));
   memcpy(nm, m, sizeof(XtokMethod));
   nm->next = NULL;
   if (ms->last)
      ms->last->next = nm;
   else
      ms->first = nm;
   ms->last = nm;
#endif
}

static void addParam(ParserControl *parm, XtokParams *ps, XtokParam *p)
{
#if 0	/* TODO: Reactivate when setParam is implemented */
   XtokParam *np;
   np = (XtokParam*)PARSER_MALLOC(sizeof(XtokParam));
   memcpy(np, p, sizeof(XtokParam));
   np->next = NULL;
   if (ps->last)
      ps->last->next = np;
   else
      ps->first = np;
   ps->last = np;
#endif
}

static void setError(ParserControl *parm, XtokErrorResp *e)
{
#if DEBUG
   if (do_debug)
       fprintf(stderr, "error:: code:%s description:%s\n", 
                                 e->code, e->description);
#endif
   PARM->respHdr.errCode = atoi(e->code);
   PARM->respHdr.description = XmlToAsciiStr(e->description);
}

%}

%pure_parser

/*
**=============================================================================
**
** Union used to pass tokens from Lexer to this Parser.
**
**=============================================================================
*/

%union
{
   int                           intValue;
   char                          boolValue;
   char*                         className;
   void*                         tokCim;

   XtokMessage                   xtokMessage;
   XtokErrorResp                 xtokErrorResp;

   XtokNameSpace                 xtokNameSpace;
   char*                         xtokLocalNameSpacePath;
   XtokNameSpacePath             xtokNameSpacePath;
   XtokHost                      xtokHost;
   XtokInstancePath              xtokInstancePath;
   XtokLocalInstancePath         xtokLocalInstancePath;
   XtokClassPath                 xtokClassPath;

   XtokValue                     xtokValue;
   XtokValueArray                xtokValueArray;
   XtokValueReference            xtokValueReference;
   XtokObjectWithPath            xtokObjectWithPath;
   XtokObjectPath                xtokObjectPath;
   XtokInstanceName              xtokInstanceName;
   XtokKeyBinding                xtokKeyBinding;
   XtokKeyBindings               xtokKeyBindings;
   XtokKeyValue                  xtokKeyValue;

   XtokClass                     xtokClass;
   XtokInstance                  xtokInstance;
   XtokNamedInstance             xtokNamedInstance;

   XtokProperty                  xtokProperty;
   XtokPropertyData              xtokPropertyData;

   XtokMethod                    xtokMethod;
   XtokMethodData                xtokMethodData;
   XtokQualifier                 xtokQualifier;

   XtokParamValues               xtokParamValues;
   XtokParamValue                xtokParamValue;
   XtokParam                     xtokParam;

   XtokReturnValue               xtokReturnValue;
};

%token <tokCim>                  XTOK_XML
%token <intValue>                ZTOK_XML
%type <tokCim>                   cimOperation


%token <tokCim>                  XTOK_CIM
%token <intValue>                ZTOK_CIM

%token <xtokMessage>             XTOK_MESSAGE
%token <intValue>                ZTOK_MESSAGE
%type  <xtokMessage>             message

%token <intValue>                XTOK_SIMPLERSP
%token <intValue>                ZTOK_SIMPLERSP

%token <intValue>                XTOK_IMETHODRESP
%token <intValue>                ZTOK_IMETHODRESP
%type  <xtokImethodResp>         iMethodResp

%token <intValue>                XTOK_METHODRESP
%token <intValue>                ZTOK_METHODRESP
%type  <xtokMethodResp>          methodResp

%token <intValue>                XTOK_ERROR
%token <intValue>                ZTOK_ERROR
%type  <xtokErrorResp>           errorResp

%token <intValue>                XTOK_IRETVALUE
%token <intValue>                ZTOK_IRETVALUE

%token <intValue>                XTOK_RETVALUE
%token <intValue>                ZTOK_RETVALUE
//%type  <xtokRetValue>            retValue

%token <xtokNameSpacePath>       XTOK_NAMESPACEPATH
%token <intValue>                ZTOK_NAMESPACEPATH
%type  <xtokNameSpacePath>       nameSpacePath

%token <xtokLocalNameSpacePath>  XTOK_LOCALNAMESPACEPATH
%token <intValue>                ZTOK_LOCALNAMESPACEPATH
%type  <xtokLocalNameSpacePath>  localNameSpacePath

%token <xtokNameSpace>           XTOK_NAMESPACE
%token <intValue>                ZTOK_NAMESPACE
%type  <xtokNameSpace>           nameSpaces

%token <intValue>                ZTOK_IPARAMVALUE

%token <xtokReturnValue>	 XTOK_RETURNVALUE
%token <intValue>                ZTOK_RETURNVALUE
%type  <xtokReturnValue>	 ReturnValue

%token <xtokHost>                XTOK_HOST
%type  <xtokHost>                host
%token <intValue>                ZTOK_HOST

%token <xtokValue>               XTOK_VALUE
%type  <xtokValue>               value
%token <intValue>                ZTOK_VALUE

%token <xtokValueArray>          XTOK_VALUEARRAY
%type  <xtokValueArray>          optional_valueArray
%type  <xtokValueArray>          valueArray
%token <intValue>                ZTOK_VALUEARRAY

%token <intValueReference>       XTOK_VALUEREFERENCE
%type  <xtokValueReference>      valueReference
%token <intValue>                ZTOK_VALUEREFERENCE

%token <className>               XTOK_CLASSNAME
%token <intValue>                ZTOK_CLASSNAME
%type  <className>               className

%token <xtokInstanceName>        XTOK_INSTANCENAME
%token <intValue>                ZTOK_INSTANCENAME
%type  <xtokInstanceName>        instanceName

%token <xtokKeyBinding>          XTOK_KEYBINDING
%token <intValue>                ZTOK_KEYBINDING
%type  <xtokKeyBinding>          keyBinding
%type  <xtokKeyBindings>         keyBindings

%token <xtokKeyValue>            XTOK_KEYVALUE
%token <intValue>                ZTOK_KEYVALUE

//%type  <boolValue>               boolValue

%token <xtokNamedInstance>       XTOK_VALUENAMEDINSTANCE
%token <intValue>                ZTOK_VALUENAMEDINSTANCE
%type  <xtokNamedInstance>       namedInstance

%token <xtokQualifier>           XTOK_QUALIFIER
%type  <xtokQualifier>           qualifier
%token <intValue>                ZTOK_QUALIFIER

%token <xtokProperty>            XTOK_PROPERTY
%token <intValue>                ZTOK_PROPERTY
%token <xtokPropertyArray>       XTOK_PROPERTYARRAY
%token <intValue>                ZTOK_PROPERTYARRAY
%token <xtokProperty>            XTOK_PROPERTYREFERENCE
%token <intValue>                ZTOK_PROPERTYREFERENCE

%type  <xtokPropertyData>        propertyData
%type  <xtokProperty>            property

%token <xtokParam>               XTOK_PARAM
%type  <xtokParam>               parameter
%token <intValue>                ZTOK_PARAM
%token <xtokParam>               XTOK_PARAMARRAY
%token <intValue>                ZTOK_PARAMARRAY
%token <xtokParam>               XTOK_PARAMREF
%token <intValue>                ZTOK_PARAMREF
%token <xtokParam>               XTOK_PARAMREFARRAY
%token <intValue>                ZTOK_PARAMREFARRAY

%token <xtokMethod>              XTOK_METHOD
%type  <xtokMethod>              method
%token <intValue>                ZTOK_METHOD
%type  <xtokMethodData>          methodData

%type  <xtokClass>               class
%type  <xtokClassData>           classData
%token <xtokClass>               XTOK_CLASS
%token <intValue>                ZTOK_CLASS

%type  <xtokInstance>            instance
%type  <xtokInstanceData>        instanceData
%token <xtokInstance>            XTOK_INSTANCE
%token <intValue>                ZTOK_INSTANCE

%type  <xtokObjectWithPath>      objectWithPath
%token <xtokObjectWithPath>      XTOK_VALUEOBJECTWITHPATH
%token <intValue>                ZTOK_VALUEOBJECTWITHPATH

%type  <xtokParamValues>         paramValues
%type  <xtokParamValue>          paramValue
%token <xtokParamValue>          XTOK_PARAMVALUE
%token <intValue>                ZTOK_PARAMVALUE

%type  <xtokInstancePath>        instancePath
%token <xtokInstancePath>        XTOK_INSTANCEPATH
%token <intValue>                ZTOK_INSTANCEPATH

%type  <xtokObjectPath>          objectPath
%token <xtokObjectPath>          XTOK_OBJECTPATH
%token <intValue>                ZTOK_OBJECTPATH

%type  <xtokLocalInstancePath>   localInstancePath
%token <xtokLocalInstancePath>   XTOK_LOCALINSTANCEPATH
%token <intValue>                ZTOK_LOCALINSTANCEPATH

//%type  <xtokClassPath>           localClassPath
%token <xtokLocalClassPath>      XTOK_LOCALCLASSPATH
%token <intValue>                ZTOK_LOCALCLASSPATH

%type  <xtokClassPath>           classPath
%token <xtokClassPath>           XTOK_CLASSPATH
%token <intValue>                ZTOK_CLASSPATH

%%

/*
**=============================================================================
**
** The grammar itself.
**
**=============================================================================
*/

start
    : XTOK_XML ZTOK_XML cimOperation
    {
    }
;

cimOperation
    : XTOK_CIM message ZTOK_CIM
    {
    }
;

message
    : XTOK_MESSAGE simpleResp ZTOK_MESSAGE
    {
    }
;

simpleResp
    : XTOK_SIMPLERSP methodResp ZTOK_SIMPLERSP
    {
    }
    | XTOK_SIMPLERSP iMethodResp ZTOK_SIMPLERSP
    {
    }
;

iMethodResp
    : XTOK_IMETHODRESP errorResp ZTOK_IMETHODRESP
    {
    }
    | XTOK_IMETHODRESP iReturnValue ZTOK_IMETHODRESP
    {
    }
    | XTOK_IMETHODRESP ZTOK_IMETHODRESP
    {
    }
;

methodResp
    : XTOK_METHODRESP errorResp ZTOK_METHODRESP
    {
    }
    | XTOK_METHODRESP ReturnValue paramValues ZTOK_METHODRESP
    {
    }
    | XTOK_METHODRESP paramValues ZTOK_METHODRESP
    {
    }
;

errorResp
    : XTOK_ERROR ZTOK_ERROR
    {
        setError(PARM, &$$);
    }
;

iReturnValue
    : XTOK_IRETVALUE instanceNames ZTOK_IRETVALUE
    {
    }
    |  XTOK_IRETVALUE classNames ZTOK_IRETVALUE
    {
    }
    |  XTOK_IRETVALUE value ZTOK_IRETVALUE
    {
	/*
	 * Construct from Pegasus returned from getProperty() call.
	 * Construct:
	 *      <IRETVALUE>
	 *	<VALUE>Fan device</value>
	 *      </IRETVALUE>
	 *
	 * Surprised that there was not a container/qualifier with
	 * the type of the value. Based on that can only conclude
	 * it's a string, or let guessType() try to do better. Does
	 * not handle an array of values, hopefully won't see this.
	 */
	CMPIType  t   = guessType($2.value);
	CMPIValue val = str2CMPIValue(t, $2.value, NULL);
	simpleArrayAdd(PARM->respHdr.rvArray, (CMPIValue*)&val, t);
    }
    /* | XTOK_IRETVALUE valueObjectsWithPath ZTOK_IRETVALUE
    {
    }
    | XTOK_IRETVALUE valueObjectsWithLocalPath ZTOK_IRETVALUE
    {
    }
    | XTOK_IRETVALUE valueObjects ZTOK_IRETVALUE
    {
    }
    | XTOK_IRETVALUE valueArray ZTOK_IRETVALUE
    {
        memset(&PARM->curArray,0,sizeof(PARM->curArray));
        PARM->valueSet=0;
    }
    | XTOK_IRETVALUE valueRef ZTOK_IRETVALUE
    {
    } */
    | XTOK_IRETVALUE objectPaths ZTOK_IRETVALUE
    {
    }
    | XTOK_IRETVALUE objectsWithPath ZTOK_IRETVALUE
    {
    }
    | XTOK_IRETVALUE classes ZTOK_IRETVALUE
    {
    }
    | XTOK_IRETVALUE instances ZTOK_IRETVALUE
    {
    }
    | XTOK_IRETVALUE namedInstances ZTOK_IRETVALUE
    {
    }
;

ReturnValue
    : XTOK_RETVALUE instanceNames ZTOK_RETVALUE
    {
    }
    |  XTOK_RETVALUE classNames ZTOK_RETVALUE
    {
    }
    |  XTOK_RETVALUE value ZTOK_RETVALUE
    {
       /* Should have gotten type from <RETURNVALUE PARAMTYPE=??> */
       /* If not, we can use guessType to set it.                 */
       CMPIType  t   = $$.type;
       CMPIValue val;
       if (t == 0)
           t = guessType($2.value);
       val = str2CMPIValue(t, $2.value, NULL);
       simpleArrayAdd(PARM->respHdr.rvArray, (CMPIValue*)&val, t);
    }
    /* | XTOK_RETVALUE valueObjectsWithPath ZTOK_RETVALUE
    {
    }
    | XTOK_RETVALUE valueObjectsWithLocalPath ZTOK_RETVALUE
    {
    }
    | XTOK_RETVALUE valueObjects ZTOK_RETVALUE
    {
    }
    | XTOK_RETVALUE valueArray ZTOK_RETVALUE
    {
        memset(&PARM->curArray,0,sizeof(PARM->curArray));
        PARM->valueSet=0;
    }
    | XTOK_RETVALUE valueRef ZTOK_RETVALUE
    {
    } */
    | XTOK_RETVALUE objectPaths ZTOK_RETVALUE
    {
    }
    | XTOK_RETVALUE objectsWithPath ZTOK_RETVALUE
    {
    }
    | XTOK_RETVALUE classes ZTOK_RETVALUE
    {
    }
    | XTOK_RETVALUE instances ZTOK_RETVALUE
    {
    }
    | XTOK_RETVALUE namedInstances ZTOK_RETVALUE
    {
    }
;

paramValues
    : /* empty */ 
    {
    }  
    | paramValue paramValues
    {
        addParamValue(PARM, &PARM->paramValues, &($1));
    }
;

paramValue 
    : 
    XTOK_PARAMVALUE value ZTOK_PARAMVALUE
    {
       $$.value = $2;
    }
    | XTOK_PARAMVALUE valueReference ZTOK_PARAMVALUE
    {
       $$.valueRef = $2;
    }
    | XTOK_PARAMVALUE XTOK_VALUEARRAY valueArray ZTOK_VALUEARRAY ZTOK_PARAMVALUE
    {
       $$.type |= CMPI_ARRAY;
       $$.valueArray = PARM->curArray;

       /* clear the temp location */
       memset(&PARM->curArray,0,sizeof(PARM->curArray));
       PARM->valueSet=0;
    }
;

classes
    : /* empty */
    | classes class
    {
       PARM->curClass = native_new_CMPIConstClass($2.className,NULL);
       setClassQualifiers(PARM->curClass, &PARM->qualifiers);
       setClassProperties(PARM->curClass, &PARM->properties);
       simpleArrayAdd(PARM->respHdr.rvArray,(CMPIValue*)&PARM->curClass,CMPI_class);
       PARM->curClass = NULL;
       PARM->Qs = PARM->Ps = 0;
    }
;

instances
    : /* empty */
    | instances instance
    {
       PARM->curInstance = native_new_CMPIInstance(NULL,NULL);
       setInstNsAndCn(PARM->curInstance,PARM->da_nameSpace,$2.className);
       setInstQualifiers(PARM->curInstance, &PARM->qualifiers);
       setInstProperties(PARM->curInstance, &PARM->properties);
       simpleArrayAdd(PARM->respHdr.rvArray,(CMPIValue*)&PARM->curInstance,CMPI_instance);
       PARM->curInstance = NULL;
       PARM->Qs = PARM->Ps = 0;
    }
;

instanceNames
    : /* empty */
    | instanceNames instanceName
    {
//       setInstNsAndCn(PARM->curInstance,PARM->da_nameSpace,$2.className);
       simpleArrayAdd(PARM->respHdr.rvArray,(CMPIValue*)&PARM->curPath,CMPI_ref);
       PARM->curPath = NULL;
    }
;

objectsWithPath
    : /* empty */
    | objectsWithPath objectWithPath
    {
       if ($2.type == 0)
       {
       if (PARM->curPath) CMRelease(PARM->curPath);
           createPath(&(PARM->curPath),&($2.inst.path.instanceName));
       CMSetNameSpace(PARM->curPath,PARM->da_nameSpace);
       PARM->curInstance = native_new_CMPIInstance(PARM->curPath,NULL);
       setInstProperties(PARM->curInstance, &PARM->properties);
       simpleArrayAdd(PARM->respHdr.rvArray,(CMPIValue*)&PARM->curInstance,CMPI_instance);
       PARM->curInstance = NULL;
       CMRelease(PARM->curPath);
       PARM->curPath = NULL;
       PARM->Qs = PARM->Ps = 0;
    }
       else
       {
           PARM->curClass = native_new_CMPIConstClass($2.cls.cls.className,NULL);
           setClassProperties(PARM->curClass, &PARM->properties);
           simpleArrayAdd(PARM->respHdr.rvArray,(CMPIValue*)&PARM->curClass,CMPI_class);
           PARM->curClass = NULL;
           PARM->Qs = PARM->Ps = 0;
       }
    }
;


namedInstances
    : /* empty */
    | namedInstances namedInstance
    {
       if (PARM->curPath) CMRelease(PARM->curPath);
       createPath(&(PARM->curPath),&($2.path));
       PARM->curInstance = native_new_CMPIInstance(PARM->curPath,NULL);
       setInstQualifiers(PARM->curInstance, &PARM->qualifiers);
       setInstProperties(PARM->curInstance, &PARM->properties);
       simpleArrayAdd(PARM->respHdr.rvArray,(CMPIValue*)&PARM->curInstance,CMPI_instance);
       PARM->curInstance = NULL;
       CMRelease(PARM->curPath);
       PARM->curPath = NULL;
       PARM->Qs = PARM->Ps = 0;
    }
;


/*
 *    valueNamedInstance
*/

namedInstance
    : XTOK_VALUENAMEDINSTANCE instanceName instance ZTOK_VALUENAMEDINSTANCE
    {
       $$.path = $2;
       $$.instance = $3;
       PARM->Qs = PARM->Ps = 0;
    }
;


/*
 *    objectWithPath
*/

objectWithPath
    : XTOK_VALUEOBJECTWITHPATH instancePath instance ZTOK_VALUEOBJECTWITHPATH
    {
       $$.inst.path = $2;
       $$.inst.inst = $3;
       $$.type = 0;
    }
    | XTOK_VALUEOBJECTWITHPATH classPath class ZTOK_VALUEOBJECTWITHPATH
    {
       $$.cls.path = $2;
       $$.cls.cls = $3;
       $$.type = 1;
    }
;



/*
 *    class
*/

class
    : XTOK_CLASS classData ZTOK_CLASS
    {
       if (PARM->Qs)
          $$.qualifiers = PARM->qualifiers;
       else memset(&$$.qualifiers,0,sizeof($$.qualifiers));
       if (PARM->Ps)
          $$.properties = PARM->properties;
       else memset(&$$.properties,0,sizeof($$.properties));
       if (PARM->Ms)
          $$.methods = PARM->methods;
       else memset(&$$.methods,0,sizeof($$.methods));
    }
;

classData
    : /* empty */ {;}
    | classData qualifier
    {
       PARM->Qs++;
       addQualifier(PARM,&(PARM->qualifiers),&$2);
    }
    | classData property     {
       PARM->Ps++;
       addProperty(PARM,&(PARM->properties),&$2);
       PARM->PQs = 0;
    }
    | classData method     {
        PARM->Ms++;
        addMethod(PARM,&(PARM->methods),&$2);
    }
;

method
    : XTOK_METHOD methodData ZTOK_METHOD
    {
       if (PARM->MQs)
          $$.qualifiers = $2.qualifiers;
       else memset(&$$.qualifiers,0,sizeof($$.qualifiers));
       if (PARM->MPs)
          $$.params = $2.params;
       else memset(&$$.params,0,sizeof($$.params));
       PARM->MQs = 0;
       PARM->MPs = 0;
       PARM->MPQs = 0;
    }
;

methodData
    : /* empty */ {;}
    | methodData qualifier
    {
       if (PARM->MQs == 0)
          memset(&$$.qualifiers,0,sizeof($$.qualifiers));
       PARM->MQs++;
       addQualifier(PARM,&($$.qualifiers),&$2);
    }
    | methodData XTOK_PARAM parameter ZTOK_PARAM
    {
       if (PARM->MPs == 0)
          memset(&$$.params,0,sizeof($$.params));
       PARM->MPs++;
       if (PARM->MPQs)
          $2.qualifiers = $3.qualifiers;
       else memset(&$2.qualifiers,0,sizeof($2.qualifiers));
       addParam(PARM,&($$.params),&$2);
       PARM->MPQs = 0;
    }
    | methodData XTOK_PARAMARRAY parameter ZTOK_PARAMARRAY
    {
       if (PARM->MPs == 0)
          memset(&$$.params,0,sizeof($$.params));
       PARM->MPs++;
       if (PARM->MPQs)
          $2.qualifiers = $3.qualifiers;
       else memset(&$2.qualifiers,0,sizeof($2.qualifiers));
       addParam(PARM,&($$.params),&$2);
       PARM->MPQs = 0;
    }
    | methodData XTOK_PARAMREF parameter ZTOK_PARAMREF
    {
       if (PARM->MPs == 0)
          memset(&$$.params,0,sizeof($$.params));
       PARM->MPs++;
       if (PARM->MPQs)
          $2.qualifiers = $3.qualifiers;
       else memset(&$2.qualifiers,0,sizeof($2.qualifiers));
       addParam(PARM,&($$.params),&$2);
       PARM->MPQs = 0;
    }
;

parameter
    : /* empty */ {;}
    | parameter qualifier
    {
       if (PARM->MPQs == 0)
          memset(&$$.qualifiers,0,sizeof($$.qualifiers));
       PARM->MPQs++;
       addQualifier(PARM,&($$.qualifiers),&$2);
    }
;


/*
 *    instance
*/

instance
    : XTOK_INSTANCE instanceData ZTOK_INSTANCE
    {
       if (PARM->Qs) $$.qualifiers = PARM->qualifiers;
       else memset(&$$.qualifiers, 0, sizeof($$.qualifiers));
       if (PARM->Ps) $$.properties = PARM->properties;
       else memset(&$$.properties, 0, sizeof($$.properties));
    }
;

instanceData
    : /* empty */ {;}
    | instanceData qualifier
    {
       PARM->Qs++;
       addQualifier(PARM,&(PARM->qualifiers),&$2);
    }
    | instanceData property
    {
       PARM->Ps++;
       addProperty(PARM,&(PARM->properties),&$2);
       PARM->PQs = 0;
    }
;


/*
 *    property
*/

property
    : XTOK_PROPERTY propertyData ZTOK_PROPERTY
    {
       $$.val = $2;
       $$.val.null= PARM->valueSet==0;
       PARM->valueSet=0;
    }
    | XTOK_PROPERTYREFERENCE propertyData ZTOK_PROPERTYREFERENCE
    {
       $$.val = $2;
       $$.val.null= PARM->valueSet==0;
       PARM->valueSet=0;
    }
    | XTOK_PROPERTYARRAY propertyData ZTOK_PROPERTYARRAY
    {
       $$.val.array = PARM->curArray;
       $$.val.null= PARM->valueSet==0;
       $$.val.qualifiers = $2.qualifiers;
       memset(&PARM->curArray,0,sizeof(PARM->curArray));
       PARM->valueSet=0;
    }
;

propertyData
    : /* empty */ 
    {
      /*$$.null = 1;*/
       if (PARM->PQs == 0)
          memset(&$$.qualifiers,0,sizeof($$.qualifiers)); 
       PARM->valueSet=0;
    }
    | propertyData qualifier
    {
       if (PARM->PQs == 0)
          memset(&$$.qualifiers,0,sizeof($$.qualifiers));
       PARM->PQs++;
       addQualifier(PARM,&($$.qualifiers),&$2);
    }
    | propertyData value
    {
       $$.value = $2.value;
    }
    | propertyData valueReference
    {
       $$.ref = $2;
       $$.ref.op=PARM->curPath;
       PARM->curPath=NULL;
    }
    | propertyData XTOK_VALUEARRAY optional_valueArray ZTOK_VALUEARRAY
    {
       $$.array = PARM->curArray;
    }
;



/*
 *    value
*/


value
    : XTOK_VALUE ZTOK_VALUE
    {
       $$.value = $1.value;
       PARM->valueSet=1;
    }
;

optional_valueArray
    : /* empty */
    {
       memset(&PARM->curArray,0,sizeof(PARM->curArray));
       $$ = PARM->curArray;       
    }
    | valueArray 
;

valueArray
    : value
    {
       PARM->curArray.next = 1;
       PARM->curArray.max = 16;
       PARM->curArray.values = (char**)PARSER_MALLOC(sizeof(char*)*PARM->curArray.max);
       PARM->curArray.values[0] = $1.value;
       PARM->valueSet=1;
       $$ = PARM->curArray;
    }
    | valueArray value
    {
       if (PARM->curArray.next >= PARM->curArray.max) {
          PARM->curArray.max *= 2;
          PARM->curArray.values = (char**)PARSER_REALLOC(PARM->curArray.values, sizeof(char*)*PARM->curArray.max);
       }
       PARM->curArray.values[PARM->curArray.next] = $2.value;
       PARM->curArray.next++;
       PARM->valueSet=1;
       $$ = PARM->curArray;
   }
;

valueReference
    : XTOK_VALUEREFERENCE instancePath ZTOK_VALUEREFERENCE
    {
       $$.instancePath = $2;
       $$.type = typeValRef_InstancePath;
       PARM->valueSet=1;
    }
    | XTOK_VALUEREFERENCE instanceName ZTOK_VALUEREFERENCE
    {
       $$.instanceName = $2;
       $$.type = typeValRef_InstanceName;
       PARM->valueSet=1;
    }
    | XTOK_VALUEREFERENCE localInstancePath ZTOK_VALUEREFERENCE
    {
       $$.localInstancePath = $2;
       $$.type = typeValRef_LocalInstancePath;
       PARM->valueSet=1;
    }
;

/*
boolValue
    : XTOK_VALUE ZTOK_VALUE
    {
//       int b = isBoolean($1.val);
//       if (b >= 0) $$ = (b != 0);
    }
;
*/

classNames
    : /* empty */
    | classNames className
    {
       simpleArrayAdd(PARM->respHdr.rvArray,(CMPIValue*)&PARM->curPath,CMPI_ref);
       PARM->curPath = NULL;
    }
;

className
    : XTOK_CLASSNAME ZTOK_CLASSNAME
    {
	PARM->curPath = newCMPIObjectPath(NULL, $$, NULL);
    }
;

/*
 *    qualifier
*/

qualifier
    : XTOK_QUALIFIER value ZTOK_QUALIFIER
    {
       $$.value = $2.value;
       PARM->valueSet=0;
    }
    | XTOK_QUALIFIER XTOK_VALUEARRAY optional_valueArray ZTOK_VALUEARRAY ZTOK_QUALIFIER
    {
       $$.type|=CMPI_ARRAY;
       $$.array=PARM->curArray;
       memset(&PARM->curArray,0,sizeof(PARM->curArray));
       PARM->valueSet=0;
    }
;


/*
 *    localNameSpacePath
*/



localNameSpacePath
    : XTOK_LOCALNAMESPACEPATH nameSpaces ZTOK_LOCALNAMESPACEPATH
    {
       $$ = $2.cns;
    }
;

nameSpaces
    : XTOK_NAMESPACE ZTOK_NAMESPACE
    {
       $$.cns = PARSER_STRDUP($1.ns);
    }
    | nameSpaces XTOK_NAMESPACE ZTOK_NAMESPACE
    {
       int l = strlen($1.cns)+strlen($2.ns)+2;
       $$.cns = (char*)PARSER_MALLOC(l);
       strcpy($$.cns,$1.cns);
       strcat($$.cns,"/");
       strcat($$.cns,$2.ns);
    }
;


nameSpacePath
    : XTOK_NAMESPACEPATH host localNameSpacePath ZTOK_NAMESPACEPATH
    {
       $$.host = $2;
       $$.nameSpacePath = $3;
    }
;

host
    : XTOK_HOST ZTOK_HOST
    {
    }
;

instancePath
    : XTOK_INSTANCEPATH nameSpacePath instanceName ZTOK_INSTANCEPATH
    {
       $$.path = $2;
       $$.instanceName = $3;
       $$.type = 1;
    }
 /*
    | nameSpacePath instanceName
    {
    }
    | XTOK_LOCALCLASSPATH localNameSpacePath className ZTOK_LOCALCLASSPATH
    {
    } */
;

localInstancePath
    : XTOK_LOCALINSTANCEPATH localNameSpacePath instanceName ZTOK_LOCALINSTANCEPATH
    {
       $$.path = $2;
       $$.instanceName = $3;
       $$.type = 1;
    }
;

/*
localClassPath
    : XTOK_LOCALCLASSPATH localNameSpacePath className ZTOK_LOCALCLASSPATH
    {
       $$.da_namespace = $2;
       $$.className = $3;
       $$.type = 1;
    }
;
*/

classPath
    : XTOK_CLASSPATH nameSpacePath className ZTOK_CLASSPATH
    {
       $$.name = $2;
       $$.className = $3;
       $$.type = 0;
    }
;


/*
 *    objectPath
 */

objectPath
    : XTOK_OBJECTPATH instancePath ZTOK_OBJECTPATH
    {
    	/*
    	 * Construct from Pegasus that caused a associatorNames()
    	 * return value failure.
    	 * Construct:
    	 *     <OBJECTPATH>
    	 *     <INSTANCEPATH>
    	 *         ...
    	 *     </INSTANCEPATH>
    	 *     </OBJECTPATH>
         *
    	 * Parser was not recognizing <OBJECTPATH>/</OBJECTPATH>
    	 * and was aborting, added productions to handle this.
    	 * This code basically returns the info collected for the
    	 * INSTANCEPATH container for OBJECTPATH.
    	 */
    	 int i;
    	 CMPIValue val,*valp;
    	 CMPIType type;
    	 XtokInstanceName *p = &$2.instanceName;

    	 /* A lot of this came from createPath(), has to be unique */
	 if (PARM->curPath) CMRelease(PARM->curPath);
    	 PARM->curPath = newCMPIObjectPath($2.path.nameSpacePath,
    				                           p->className, NULL);
	 if (p->bindings.next > 0)
	     for (i = 0; i < p->bindings.next; i++) {
		valp = getKeyValueTypePtr(p->bindings.keyBindings[i].type,
    					  p->bindings.keyBindings[i].value,
    					  &p->bindings.keyBindings[i].ref,
					  &val, &type);
		CMAddKey(PARM->curPath, p->bindings.keyBindings[i].name,
    							    valp, type);
		if (type == CMPI_ref) {
		  CMRelease(valp->ref);
		}
	     }
	 simpleArrayAdd(PARM->respHdr.rvArray, (CMPIValue*)&PARM->curPath,
								CMPI_ref);
    	 PARM->curPath = NULL;
    }
    | XTOK_OBJECTPATH classPath ZTOK_OBJECTPATH
    {
         if (PARM->curPath) CMRelease(PARM->curPath);
    	 PARM->curPath = newCMPIObjectPath($2.name.nameSpacePath,
					   $2.className, NULL);
	 simpleArrayAdd(PARM->respHdr.rvArray, (CMPIValue*)&PARM->curPath,
								CMPI_ref);
    	 PARM->curPath = NULL;
    }
;

objectPaths
    : objectPath
    {
    }
    | objectPaths objectPath
    {
    }
;

/*
 *    instanceName
*/


instanceName
    : XTOK_INSTANCENAME ZTOK_INSTANCENAME
    {
       $$.className = $1.className;
       $$.bindings.next = 0;
       $$.bindings.keyBindings = NULL;
       PARM->curPath = NULL;
    }
    | XTOK_INSTANCENAME keyBindings ZTOK_INSTANCENAME
    {
       $$.className = $1.className;
       $$.bindings = $2;
       if (PARM->curPath) CMRelease(PARM->curPath);
       createPath(&(PARM->curPath), &$$);
    }
;

keyBindings
    : keyBinding
    {
       $$.next = 1;
       $$.max  = 8;
       $$.keyBindings = (XtokKeyBinding*)PARSER_MALLOC(sizeof(XtokKeyBinding) * $$.max);
       $$.keyBindings[0].name = $1.name;
       $$.keyBindings[0].value = $1.value;
       $$.keyBindings[0].type = $1.type;
       $$.keyBindings[0].ref = $1.ref;
    }
    | keyBindings keyBinding
    {
       if ($$.next == $$.max) {
          $$.max *= 2;
          $$.keyBindings = (XtokKeyBinding*)PARSER_REALLOC($$.keyBindings,
				           sizeof(XtokKeyBinding) * $$.max);
       }
       $$.keyBindings[$$.next].name = $2.name;
       $$.keyBindings[$$.next].value = $2.value;
       $$.keyBindings[$$.next].type = $2.type;
       $$.keyBindings[$$.next].ref = $2.ref;
       $$.next++;
    }
;

keyBinding
    : XTOK_KEYBINDING XTOK_KEYVALUE ZTOK_KEYVALUE ZTOK_KEYBINDING
    {
       $$.name = $1.name;
       $$.value = $2.value;
       $$.type = $2.valueType;
    }
    | XTOK_KEYBINDING valueReference ZTOK_KEYBINDING
    {
       $$.name = $1.name;
       $$.value = NULL;
       $$.type = "ref";
       $$.ref = $2;
    }
;

%%
