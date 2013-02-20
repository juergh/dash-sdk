/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     XTOK_XML = 258,
     ZTOK_XML = 259,
     XTOK_CIM = 260,
     ZTOK_CIM = 261,
     XTOK_MESSAGE = 262,
     ZTOK_MESSAGE = 263,
     XTOK_SIMPLERSP = 264,
     ZTOK_SIMPLERSP = 265,
     XTOK_IMETHODRESP = 266,
     ZTOK_IMETHODRESP = 267,
     XTOK_METHODRESP = 268,
     ZTOK_METHODRESP = 269,
     XTOK_ERROR = 270,
     ZTOK_ERROR = 271,
     XTOK_IRETVALUE = 272,
     ZTOK_IRETVALUE = 273,
     XTOK_RETVALUE = 274,
     ZTOK_RETVALUE = 275,
     XTOK_NAMESPACEPATH = 276,
     ZTOK_NAMESPACEPATH = 277,
     XTOK_LOCALNAMESPACEPATH = 278,
     ZTOK_LOCALNAMESPACEPATH = 279,
     XTOK_NAMESPACE = 280,
     ZTOK_NAMESPACE = 281,
     ZTOK_IPARAMVALUE = 282,
     XTOK_RETURNVALUE = 283,
     ZTOK_RETURNVALUE = 284,
     XTOK_HOST = 285,
     ZTOK_HOST = 286,
     XTOK_VALUE = 287,
     ZTOK_VALUE = 288,
     XTOK_VALUEARRAY = 289,
     ZTOK_VALUEARRAY = 290,
     XTOK_VALUEREFERENCE = 291,
     ZTOK_VALUEREFERENCE = 292,
     XTOK_CLASSNAME = 293,
     ZTOK_CLASSNAME = 294,
     XTOK_INSTANCENAME = 295,
     ZTOK_INSTANCENAME = 296,
     XTOK_KEYBINDING = 297,
     ZTOK_KEYBINDING = 298,
     XTOK_KEYVALUE = 299,
     ZTOK_KEYVALUE = 300,
     XTOK_VALUENAMEDINSTANCE = 301,
     ZTOK_VALUENAMEDINSTANCE = 302,
     XTOK_QUALIFIER = 303,
     ZTOK_QUALIFIER = 304,
     XTOK_PROPERTY = 305,
     ZTOK_PROPERTY = 306,
     XTOK_PROPERTYARRAY = 307,
     ZTOK_PROPERTYARRAY = 308,
     XTOK_PROPERTYREFERENCE = 309,
     ZTOK_PROPERTYREFERENCE = 310,
     XTOK_PARAM = 311,
     ZTOK_PARAM = 312,
     XTOK_PARAMARRAY = 313,
     ZTOK_PARAMARRAY = 314,
     XTOK_PARAMREF = 315,
     ZTOK_PARAMREF = 316,
     XTOK_PARAMREFARRAY = 317,
     ZTOK_PARAMREFARRAY = 318,
     XTOK_METHOD = 319,
     ZTOK_METHOD = 320,
     XTOK_CLASS = 321,
     ZTOK_CLASS = 322,
     XTOK_INSTANCE = 323,
     ZTOK_INSTANCE = 324,
     XTOK_VALUEOBJECTWITHPATH = 325,
     ZTOK_VALUEOBJECTWITHPATH = 326,
     XTOK_PARAMVALUE = 327,
     ZTOK_PARAMVALUE = 328,
     XTOK_INSTANCEPATH = 329,
     ZTOK_INSTANCEPATH = 330,
     XTOK_OBJECTPATH = 331,
     ZTOK_OBJECTPATH = 332,
     XTOK_LOCALINSTANCEPATH = 333,
     ZTOK_LOCALINSTANCEPATH = 334,
     XTOK_LOCALCLASSPATH = 335,
     ZTOK_LOCALCLASSPATH = 336,
     XTOK_CLASSPATH = 337,
     ZTOK_CLASSPATH = 338
   };
#endif
/* Tokens.  */
#define XTOK_XML 258
#define ZTOK_XML 259
#define XTOK_CIM 260
#define ZTOK_CIM 261
#define XTOK_MESSAGE 262
#define ZTOK_MESSAGE 263
#define XTOK_SIMPLERSP 264
#define ZTOK_SIMPLERSP 265
#define XTOK_IMETHODRESP 266
#define ZTOK_IMETHODRESP 267
#define XTOK_METHODRESP 268
#define ZTOK_METHODRESP 269
#define XTOK_ERROR 270
#define ZTOK_ERROR 271
#define XTOK_IRETVALUE 272
#define ZTOK_IRETVALUE 273
#define XTOK_RETVALUE 274
#define ZTOK_RETVALUE 275
#define XTOK_NAMESPACEPATH 276
#define ZTOK_NAMESPACEPATH 277
#define XTOK_LOCALNAMESPACEPATH 278
#define ZTOK_LOCALNAMESPACEPATH 279
#define XTOK_NAMESPACE 280
#define ZTOK_NAMESPACE 281
#define ZTOK_IPARAMVALUE 282
#define XTOK_RETURNVALUE 283
#define ZTOK_RETURNVALUE 284
#define XTOK_HOST 285
#define ZTOK_HOST 286
#define XTOK_VALUE 287
#define ZTOK_VALUE 288
#define XTOK_VALUEARRAY 289
#define ZTOK_VALUEARRAY 290
#define XTOK_VALUEREFERENCE 291
#define ZTOK_VALUEREFERENCE 292
#define XTOK_CLASSNAME 293
#define ZTOK_CLASSNAME 294
#define XTOK_INSTANCENAME 295
#define ZTOK_INSTANCENAME 296
#define XTOK_KEYBINDING 297
#define ZTOK_KEYBINDING 298
#define XTOK_KEYVALUE 299
#define ZTOK_KEYVALUE 300
#define XTOK_VALUENAMEDINSTANCE 301
#define ZTOK_VALUENAMEDINSTANCE 302
#define XTOK_QUALIFIER 303
#define ZTOK_QUALIFIER 304
#define XTOK_PROPERTY 305
#define ZTOK_PROPERTY 306
#define XTOK_PROPERTYARRAY 307
#define ZTOK_PROPERTYARRAY 308
#define XTOK_PROPERTYREFERENCE 309
#define ZTOK_PROPERTYREFERENCE 310
#define XTOK_PARAM 311
#define ZTOK_PARAM 312
#define XTOK_PARAMARRAY 313
#define ZTOK_PARAMARRAY 314
#define XTOK_PARAMREF 315
#define ZTOK_PARAMREF 316
#define XTOK_PARAMREFARRAY 317
#define ZTOK_PARAMREFARRAY 318
#define XTOK_METHOD 319
#define ZTOK_METHOD 320
#define XTOK_CLASS 321
#define ZTOK_CLASS 322
#define XTOK_INSTANCE 323
#define ZTOK_INSTANCE 324
#define XTOK_VALUEOBJECTWITHPATH 325
#define ZTOK_VALUEOBJECTWITHPATH 326
#define XTOK_PARAMVALUE 327
#define ZTOK_PARAMVALUE 328
#define XTOK_INSTANCEPATH 329
#define ZTOK_INSTANCEPATH 330
#define XTOK_OBJECTPATH 331
#define ZTOK_OBJECTPATH 332
#define XTOK_LOCALINSTANCEPATH 333
#define ZTOK_LOCALINSTANCEPATH 334
#define XTOK_LOCALCLASSPATH 335
#define ZTOK_LOCALCLASSPATH 336
#define XTOK_CLASSPATH 337
#define ZTOK_CLASSPATH 338




/* Copy the first part of user declarations.  */
#line 1 "../backend/cimxml/cimXmlResp.y"


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

static int isBoolean(CMPIData data)
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
               int i;
               arr = newCMPIArray(0, type, NULL);
               type  = q->type & ~CMPI_ARRAY;
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
         //val.array = arr;
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
            int i;
            arr = newCMPIArray(0, type, NULL);

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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 449 "../backend/cimxml/cimXmlResp.y"
typedef union YYSTYPE {
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
} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 733 "cimXmlResp.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 745 "cimXmlResp.c"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   231

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  47
/* YYNRULES -- Number of rules. */
#define YYNRULES  103
/* YYNRULES -- Number of states. */
#define YYNSTATES  200

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   338

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     7,    11,    15,    19,    23,    27,    31,
      34,    38,    43,    47,    50,    54,    58,    62,    66,    70,
      74,    78,    82,    86,    90,    94,    98,   102,   106,   110,
     114,   115,   118,   122,   126,   132,   133,   136,   137,   140,
     141,   144,   145,   148,   149,   152,   157,   162,   167,   171,
     172,   175,   178,   181,   185,   186,   189,   194,   199,   204,
     205,   208,   212,   213,   216,   219,   223,   227,   231,   232,
     235,   238,   241,   246,   249,   250,   252,   254,   257,   261,
     265,   269,   270,   273,   276,   280,   286,   290,   293,   297,
     302,   305,   310,   315,   320,   324,   328,   330,   333,   336,
     340,   342,   345,   350
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
      85,     0,    -1,     3,     4,    86,    -1,     5,    87,     6,
      -1,     7,    88,     8,    -1,     9,    90,    10,    -1,     9,
      89,    10,    -1,    11,    91,    12,    -1,    11,    92,    12,
      -1,    11,    12,    -1,    13,    91,    14,    -1,    13,    93,
      94,    14,    -1,    13,    94,    14,    -1,    15,    16,    -1,
      17,    98,    18,    -1,    17,   116,    18,    -1,    17,   112,
      18,    -1,    17,   127,    18,    -1,    17,    99,    18,    -1,
      17,    96,    18,    -1,    17,    97,    18,    -1,    17,   100,
      18,    -1,    19,    98,    20,    -1,    19,   116,    20,    -1,
      19,   112,    20,    -1,    19,   127,    20,    -1,    19,    99,
      20,    -1,    19,    96,    20,    -1,    19,    97,    20,    -1,
      19,   100,    20,    -1,    -1,    95,    94,    -1,    72,   112,
      73,    -1,    72,   115,    73,    -1,    72,    34,   114,    35,
      73,    -1,    -1,    96,   103,    -1,    -1,    97,   108,    -1,
      -1,    98,   128,    -1,    -1,    99,   102,    -1,    -1,   100,
     101,    -1,    46,   128,   108,    47,    -1,    70,   123,   108,
      71,    -1,    70,   125,   103,    71,    -1,    66,   104,    67,
      -1,    -1,   104,   118,    -1,   104,   110,    -1,   104,   105,
      -1,    64,   106,    65,    -1,    -1,   106,   118,    -1,   106,
      56,   107,    57,    -1,   106,    58,   107,    59,    -1,   106,
      60,   107,    61,    -1,    -1,   107,   118,    -1,    68,   109,
      69,    -1,    -1,   109,   118,    -1,   109,   110,    -1,    50,
     111,    51,    -1,    54,   111,    55,    -1,    52,   111,    53,
      -1,    -1,   111,   118,    -1,   111,   112,    -1,   111,   115,
      -1,   111,    34,   113,    35,    -1,    32,    33,    -1,    -1,
     114,    -1,   112,    -1,   114,   112,    -1,    36,   123,    37,
      -1,    36,   128,    37,    -1,    36,   124,    37,    -1,    -1,
     116,   117,    -1,    38,    39,    -1,    48,   112,    49,    -1,
      48,    34,   113,    35,    49,    -1,    23,   120,    24,    -1,
      25,    26,    -1,   120,    25,    26,    -1,    21,   122,   119,
      22,    -1,    30,    31,    -1,    74,   121,   128,    75,    -1,
      78,   119,   128,    79,    -1,    82,   121,   117,    83,    -1,
      76,   123,    77,    -1,    76,   125,    77,    -1,   126,    -1,
     127,   126,    -1,    40,    41,    -1,    40,   129,    41,    -1,
     130,    -1,   129,   130,    -1,    42,    44,    45,    43,    -1,
      42,   115,    43,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   664,   664,   670,   676,   682,   685,   691,   694,   697,
     703,   706,   709,   715,   722,   725,   728,   763,   766,   769,
     772,   775,   781,   784,   787,   815,   818,   821,   824,   827,
     834,   836,   844,   848,   852,   863,   865,   876,   878,   890,
     892,   900,   902,   929,   931,   952,   966,   972,   987,  1002,
    1003,  1008,  1013,  1020,  1035,  1036,  1043,  1054,  1065,  1079,
    1080,  1095,  1105,  1106,  1111,  1125,  1131,  1137,  1149,  1155,
    1162,  1166,  1172,  1186,  1195,  1199,  1203,  1212,  1226,  1232,
    1238,  1256,  1258,  1266,  1277,  1282,  1299,  1306,  1310,  1322,
    1330,  1336,  1352,  1372,  1386,  1428,  1440,  1443,  1454,  1461,
    1471,  1481,  1497,  1503
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "XTOK_XML", "ZTOK_XML", "XTOK_CIM",
  "ZTOK_CIM", "XTOK_MESSAGE", "ZTOK_MESSAGE", "XTOK_SIMPLERSP",
  "ZTOK_SIMPLERSP", "XTOK_IMETHODRESP", "ZTOK_IMETHODRESP",
  "XTOK_METHODRESP", "ZTOK_METHODRESP", "XTOK_ERROR", "ZTOK_ERROR",
  "XTOK_IRETVALUE", "ZTOK_IRETVALUE", "XTOK_RETVALUE", "ZTOK_RETVALUE",
  "XTOK_NAMESPACEPATH", "ZTOK_NAMESPACEPATH", "XTOK_LOCALNAMESPACEPATH",
  "ZTOK_LOCALNAMESPACEPATH", "XTOK_NAMESPACE", "ZTOK_NAMESPACE",
  "ZTOK_IPARAMVALUE", "XTOK_RETURNVALUE", "ZTOK_RETURNVALUE", "XTOK_HOST",
  "ZTOK_HOST", "XTOK_VALUE", "ZTOK_VALUE", "XTOK_VALUEARRAY",
  "ZTOK_VALUEARRAY", "XTOK_VALUEREFERENCE", "ZTOK_VALUEREFERENCE",
  "XTOK_CLASSNAME", "ZTOK_CLASSNAME", "XTOK_INSTANCENAME",
  "ZTOK_INSTANCENAME", "XTOK_KEYBINDING", "ZTOK_KEYBINDING",
  "XTOK_KEYVALUE", "ZTOK_KEYVALUE", "XTOK_VALUENAMEDINSTANCE",
  "ZTOK_VALUENAMEDINSTANCE", "XTOK_QUALIFIER", "ZTOK_QUALIFIER",
  "XTOK_PROPERTY", "ZTOK_PROPERTY", "XTOK_PROPERTYARRAY",
  "ZTOK_PROPERTYARRAY", "XTOK_PROPERTYREFERENCE", "ZTOK_PROPERTYREFERENCE",
  "XTOK_PARAM", "ZTOK_PARAM", "XTOK_PARAMARRAY", "ZTOK_PARAMARRAY",
  "XTOK_PARAMREF", "ZTOK_PARAMREF", "XTOK_PARAMREFARRAY",
  "ZTOK_PARAMREFARRAY", "XTOK_METHOD", "ZTOK_METHOD", "XTOK_CLASS",
  "ZTOK_CLASS", "XTOK_INSTANCE", "ZTOK_INSTANCE",
  "XTOK_VALUEOBJECTWITHPATH", "ZTOK_VALUEOBJECTWITHPATH",
  "XTOK_PARAMVALUE", "ZTOK_PARAMVALUE", "XTOK_INSTANCEPATH",
  "ZTOK_INSTANCEPATH", "XTOK_OBJECTPATH", "ZTOK_OBJECTPATH",
  "XTOK_LOCALINSTANCEPATH", "ZTOK_LOCALINSTANCEPATH",
  "XTOK_LOCALCLASSPATH", "ZTOK_LOCALCLASSPATH", "XTOK_CLASSPATH",
  "ZTOK_CLASSPATH", "$accept", "start", "cimOperation", "message",
  "simpleResp", "iMethodResp", "methodResp", "errorResp", "iReturnValue",
  "ReturnValue", "paramValues", "paramValue", "classes", "instances",
  "instanceNames", "objectsWithPath", "namedInstances", "namedInstance",
  "objectWithPath", "class", "classData", "method", "methodData",
  "parameter", "instance", "instanceData", "property", "propertyData",
  "value", "optional_valueArray", "valueArray", "valueReference",
  "classNames", "className", "qualifier", "localNameSpacePath",
  "nameSpaces", "nameSpacePath", "host", "instancePath",
  "localInstancePath", "classPath", "objectPath", "objectPaths",
  "instanceName", "keyBindings", "keyBinding", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    84,    85,    86,    87,    88,    88,    89,    89,    89,
      90,    90,    90,    91,    92,    92,    92,    92,    92,    92,
      92,    92,    93,    93,    93,    93,    93,    93,    93,    93,
      94,    94,    95,    95,    95,    96,    96,    97,    97,    98,
      98,    99,    99,   100,   100,   101,   102,   102,   103,   104,
     104,   104,   104,   105,   106,   106,   106,   106,   106,   107,
     107,   108,   109,   109,   109,   110,   110,   110,   111,   111,
     111,   111,   111,   112,   113,   113,   114,   114,   115,   115,
     115,   116,   116,   117,   118,   118,   119,   120,   120,   121,
     122,   123,   124,   125,   126,   126,   127,   127,   128,   128,
     129,   129,   130,   130
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     4,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       0,     2,     3,     3,     5,     0,     2,     0,     2,     0,
       2,     0,     2,     0,     2,     4,     4,     4,     3,     0,
       2,     2,     2,     3,     0,     2,     4,     4,     4,     0,
       2,     3,     0,     2,     2,     3,     3,     3,     0,     2,
       2,     2,     4,     2,     0,     1,     1,     2,     3,     3,
       3,     0,     2,     2,     3,     5,     3,     2,     3,     4,
       2,     4,     4,     4,     3,     3,     1,     2,     2,     3,
       1,     2,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     0,     0,     0,     1,     0,     2,     0,     0,     0,
       0,     3,     0,    30,     0,     0,     4,     9,     0,    35,
       0,     0,    35,     0,     0,    30,     0,    30,     6,     5,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,     0,    12,    31,
      73,     0,     0,     0,     0,    19,    49,    36,    20,    62,
      38,    14,     0,    40,    18,     0,    42,    21,     0,    44,
      16,    15,     0,    82,    17,    97,    27,    28,    22,    26,
      29,    24,    23,    25,    76,     0,     0,     0,     0,     0,
      32,    33,    11,     0,     0,     0,    94,    95,     0,     0,
      98,     0,     0,   100,     0,     0,     0,    83,     0,    77,
       0,     0,    78,    80,    79,     0,     0,     0,     0,     0,
      68,    68,    68,    54,    48,    52,    51,    50,    61,    64,
      63,     0,     0,    99,   101,     0,     0,     0,    34,     0,
       0,     0,    90,     0,    91,    93,    74,     0,     0,     0,
       0,     0,     0,   103,    46,    47,    45,    87,    86,     0,
      92,    89,     0,    75,    84,    74,    65,    70,    71,    69,
      67,    66,    59,    59,    59,    53,    55,   102,    88,     0,
       0,     0,     0,     0,    85,    72,    56,    60,    57,    58
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     2,     6,     8,    10,    14,    15,    20,    21,    25,
      26,    27,    33,    34,    35,    36,    37,    79,    76,    67,
     108,   135,   161,   191,    70,   109,   136,   158,    94,   172,
     173,   178,    39,    83,   179,   121,   150,   104,   126,    63,
      98,    64,    40,    41,    73,   112,   113
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -102
static const short int yypact[] =
{
      25,    33,    72,    29,  -102,    86,  -102,   106,   122,    62,
     124,  -102,    97,    -6,   127,   128,  -102,  -102,   126,     1,
     131,   132,     1,    90,   133,    73,   134,    73,  -102,  -102,
    -102,   113,    34,    -8,    -7,    11,    -3,     2,   135,    14,
    -102,   -13,  -102,  -102,    -1,    -4,    15,    -2,     3,   129,
       5,   -14,   118,   -28,    78,    79,  -102,   141,  -102,  -102,
    -102,   136,   136,    81,    82,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,    56,  -102,  -102,    34,  -102,  -102,   116,  -102,
    -102,  -102,   121,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,    22,   138,   125,   130,   137,
    -102,  -102,  -102,   139,   116,   140,  -102,  -102,    53,    30,
    -102,    77,    89,  -102,    95,    99,    95,  -102,    91,  -102,
     143,   116,  -102,  -102,  -102,   142,   138,    96,    83,    54,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,
    -102,   144,   145,  -102,  -102,   101,   104,   123,  -102,   150,
      94,   100,  -102,   155,  -102,  -102,   118,   146,     8,    47,
     -10,    46,   147,  -102,  -102,  -102,  -102,  -102,  -102,   154,
    -102,  -102,   148,   118,  -102,   118,  -102,  -102,  -102,  -102,
    -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -102,   149,
     151,    39,    26,   -31,  -102,  -102,  -102,  -102,  -102,  -102
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -102,  -102,  -102,  -102,  -102,  -102,  -102,   168,  -102,  -102,
      98,  -102,   160,   162,   163,   165,   169,  -102,  -102,    84,
    -102,  -102,  -102,   -50,    13,  -102,    85,     4,   -19,    17,
     152,   -22,   171,    92,  -101,    70,  -102,   153,  -102,   -39,
    -102,   156,   -20,   178,   -51,  -102,    93
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -82
static const short int yytable[] =
{
      38,    55,    99,    49,    54,    84,    93,   137,   140,    18,
      65,    68,    72,    22,    97,    74,    87,   129,    89,    86,
      77,    85,    31,    90,   175,    92,    53,   116,     1,    71,
     199,    85,    81,    31,     5,    88,   114,     3,   129,   -81,
      31,   -39,   175,    82,    53,   181,    61,   -43,    78,    78,
      96,    72,    82,   127,    31,    72,   129,   118,    66,   176,
     186,    69,    32,    32,    69,    66,    23,    75,    75,   -37,
     151,   -41,     4,    12,   129,    13,   119,    32,   129,    31,
     130,   175,   131,    53,   132,   198,    31,   129,   156,   142,
     197,   197,   197,     7,   129,   129,   196,   110,   111,   138,
     180,   129,   182,   130,   183,   131,   184,   132,    61,    17,
     157,   185,    18,    53,    19,     9,    62,   133,   168,   169,
     134,   141,    31,    57,    52,    59,    53,   145,    11,   147,
     143,   111,    16,   192,   193,   159,   160,    28,    29,   177,
     177,   177,    30,    42,    43,    23,    60,    56,    58,    91,
      31,   100,   101,    80,   119,   102,    72,   103,   106,   107,
     117,   120,   122,    69,   148,    66,   155,   123,   149,   125,
     166,   154,   164,   152,   124,   165,   167,   171,    82,   170,
     188,    24,    44,   189,    45,    46,   195,    47,   163,   162,
     187,    48,   190,    50,   139,   174,   153,   128,   194,   146,
      51,     0,     0,     0,    95,   144,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115
};

static const short int yycheck[] =
{
      19,    23,    53,    22,    23,    18,    20,   108,   109,    15,
      18,    18,    40,    19,    53,    18,    20,    48,    20,    20,
      18,    41,    32,    20,    34,    20,    36,    78,     3,    18,
      61,    51,    18,    32,     5,    20,    75,     4,    48,    38,
      32,    40,    34,    38,    36,    55,    74,    46,    46,    46,
      78,    40,    38,   104,    32,    40,    48,    35,    66,    51,
     161,    68,    76,    76,    68,    66,    72,    70,    70,    68,
     121,    70,     0,    11,    48,    13,    95,    76,    48,    32,
      50,    34,    52,    36,    54,    59,    32,    48,    34,   111,
     191,   192,   193,     7,    48,    48,    57,    41,    42,    69,
      53,    48,    56,    50,    58,    52,    60,    54,    74,    12,
     129,    65,    15,    36,    17,     9,    82,    64,    24,    25,
      67,    44,    32,    25,    34,    27,    36,   114,     6,   116,
      41,    42,     8,   183,   184,   131,   132,    10,    10,   158,
     159,   160,    16,    12,    12,    72,    33,    14,    14,    20,
      32,    73,    73,    18,   173,    14,    40,    21,    77,    77,
      39,    23,    37,    68,    73,    66,    83,    37,    25,    30,
      47,    75,    71,    31,    37,    71,    26,    22,    38,    79,
      26,    13,    22,    35,    22,    22,    35,    22,    43,    45,
      43,    22,   175,    22,   109,    49,   126,   105,    49,   115,
      22,    -1,    -1,    -1,    52,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,    85,     4,     0,     5,    86,     7,    87,     9,
      88,     6,    11,    13,    89,    90,     8,    12,    15,    17,
      91,    92,    19,    72,    91,    93,    94,    95,    10,    10,
      16,    32,    76,    96,    97,    98,    99,   100,   112,   116,
     126,   127,    12,    12,    96,    97,    98,    99,   100,   112,
     116,   127,    34,    36,   112,   115,    14,    94,    14,    94,
      33,    74,    82,   123,   125,    18,    66,   103,    18,    68,
     108,    18,    40,   128,    18,    70,   102,    18,    46,   101,
      18,    18,    38,   117,    18,   126,    20,    20,    20,    20,
      20,    20,    20,    20,   112,   114,    78,   123,   124,   128,
      73,    73,    14,    21,   121,   121,    77,    77,   104,   109,
      41,    42,   129,   130,   123,   125,   128,    39,    35,   112,
      23,   119,    37,    37,    37,    30,   122,   128,   117,    48,
      50,    52,    54,    64,    67,   105,   110,   118,    69,   110,
     118,    44,   115,    41,   130,   108,   103,   108,    73,    25,
     120,   128,    31,   119,    75,    83,    34,   112,   111,   111,
     111,   106,    45,    43,    71,    71,    47,    26,    24,    25,
      79,    22,   113,   114,    49,    34,    51,   112,   115,   118,
      53,    55,    56,    58,    60,    65,   118,    43,    26,    35,
     113,   107,   107,   107,    49,    35,    57,   118,    59,    61
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 665 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 3:
#line 671 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 4:
#line 677 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 5:
#line 683 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 6:
#line 686 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 7:
#line 692 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 8:
#line 695 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 9:
#line 698 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 10:
#line 704 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 11:
#line 707 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 12:
#line 710 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 13:
#line 716 "../backend/cimxml/cimXmlResp.y"
    {
        setError(PARM, &(yyval.xtokErrorResp));
    }
    break;

  case 14:
#line 723 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 15:
#line 726 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 16:
#line 729 "../backend/cimxml/cimXmlResp.y"
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
	CMPIType  t   = guessType((yyvsp[-1].xtokValue).value);
	CMPIValue val = str2CMPIValue(t, (yyvsp[-1].xtokValue).value, NULL);
	simpleArrayAdd(PARM->respHdr.rvArray, (CMPIValue*)&val, t);
    }
    break;

  case 17:
#line 764 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 18:
#line 767 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 19:
#line 770 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 20:
#line 773 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 21:
#line 776 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 22:
#line 782 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 23:
#line 785 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 24:
#line 788 "../backend/cimxml/cimXmlResp.y"
    {
       /* Should have gotten type from <RETURNVALUE PARAMTYPE=??> */
       /* If not, we can use guessType to set it.                 */
       CMPIType  t   = (yyval.xtokReturnValue).type;
       CMPIValue val;
       if (t == 0)
           t = guessType((yyvsp[-1].xtokValue).value);
       val = str2CMPIValue(t, (yyvsp[-1].xtokValue).value, NULL);
       simpleArrayAdd(PARM->respHdr.rvArray, (CMPIValue*)&val, t);
    }
    break;

  case 25:
#line 816 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 26:
#line 819 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 27:
#line 822 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 28:
#line 825 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 29:
#line 828 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 30:
#line 834 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 31:
#line 837 "../backend/cimxml/cimXmlResp.y"
    {
        addParamValue(PARM, &PARM->paramValues, &((yyvsp[-1].xtokParamValue)));
    }
    break;

  case 32:
#line 845 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokParamValue).value = (yyvsp[-1].xtokValue);
    }
    break;

  case 33:
#line 849 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokParamValue).valueRef = (yyvsp[-1].xtokValueReference);
    }
    break;

  case 34:
#line 853 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokParamValue).type |= CMPI_ARRAY;
       (yyval.xtokParamValue).valueArray = PARM->curArray;

       /* clear the temp location */
       memset(&PARM->curArray,0,sizeof(PARM->curArray));
       PARM->valueSet=0;
    }
    break;

  case 36:
#line 866 "../backend/cimxml/cimXmlResp.y"
    {
       PARM->curClass = native_new_CMPIConstClass((yyvsp[0].xtokClass).className,NULL);
       setClassQualifiers(PARM->curClass, &PARM->qualifiers);
       setClassProperties(PARM->curClass, &PARM->properties);
       simpleArrayAdd(PARM->respHdr.rvArray,(CMPIValue*)&PARM->curClass,CMPI_class);
       PARM->curClass = NULL;
       PARM->Qs = PARM->Ps = 0;
    }
    break;

  case 38:
#line 879 "../backend/cimxml/cimXmlResp.y"
    {
       PARM->curInstance = native_new_CMPIInstance(NULL,NULL);
       setInstNsAndCn(PARM->curInstance,PARM->da_nameSpace,(yyvsp[0].xtokInstance).className);
       setInstQualifiers(PARM->curInstance, &PARM->qualifiers);
       setInstProperties(PARM->curInstance, &PARM->properties);
       simpleArrayAdd(PARM->respHdr.rvArray,(CMPIValue*)&PARM->curInstance,CMPI_instance);
       PARM->curInstance = NULL;
       PARM->Qs = PARM->Ps = 0;
    }
    break;

  case 40:
#line 893 "../backend/cimxml/cimXmlResp.y"
    {
//       setInstNsAndCn(PARM->curInstance,PARM->da_nameSpace,$2.className);
       simpleArrayAdd(PARM->respHdr.rvArray,(CMPIValue*)&PARM->curPath,CMPI_ref);
       PARM->curPath = NULL;
    }
    break;

  case 42:
#line 903 "../backend/cimxml/cimXmlResp.y"
    {
       if ((yyvsp[0].xtokObjectWithPath).type == 0)
       {
       if (PARM->curPath) CMRelease(PARM->curPath);
           createPath(&(PARM->curPath),&((yyvsp[0].xtokObjectWithPath).inst.path.instanceName));
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
           PARM->curClass = native_new_CMPIConstClass((yyvsp[0].xtokObjectWithPath).cls.cls.className,NULL);
           setClassProperties(PARM->curClass, &PARM->properties);
           simpleArrayAdd(PARM->respHdr.rvArray,(CMPIValue*)&PARM->curClass,CMPI_class);
           PARM->curClass = NULL;
           PARM->Qs = PARM->Ps = 0;
       }
    }
    break;

  case 44:
#line 932 "../backend/cimxml/cimXmlResp.y"
    {
       if (PARM->curPath) CMRelease(PARM->curPath);
       createPath(&(PARM->curPath),&((yyvsp[0].xtokNamedInstance).path));
       PARM->curInstance = native_new_CMPIInstance(PARM->curPath,NULL);
       setInstQualifiers(PARM->curInstance, &PARM->qualifiers);
       setInstProperties(PARM->curInstance, &PARM->properties);
       simpleArrayAdd(PARM->respHdr.rvArray,(CMPIValue*)&PARM->curInstance,CMPI_instance);
       PARM->curInstance = NULL;
       CMRelease(PARM->curPath);
       PARM->curPath = NULL;
       PARM->Qs = PARM->Ps = 0;
    }
    break;

  case 45:
#line 953 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokNamedInstance).path = (yyvsp[-2].xtokInstanceName);
       (yyval.xtokNamedInstance).instance = (yyvsp[-1].xtokInstance);
       PARM->Qs = PARM->Ps = 0;
    }
    break;

  case 46:
#line 967 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokObjectWithPath).inst.path = (yyvsp[-2].xtokInstancePath);
       (yyval.xtokObjectWithPath).inst.inst = (yyvsp[-1].xtokInstance);
       (yyval.xtokObjectWithPath).type = 0;
    }
    break;

  case 47:
#line 973 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokObjectWithPath).cls.path = (yyvsp[-2].xtokClassPath);
       (yyval.xtokObjectWithPath).cls.cls = (yyvsp[-1].xtokClass);
       (yyval.xtokObjectWithPath).type = 1;
    }
    break;

  case 48:
#line 988 "../backend/cimxml/cimXmlResp.y"
    {
       if (PARM->Qs)
          (yyval.xtokClass).qualifiers = PARM->qualifiers;
       else memset(&(yyval.xtokClass).qualifiers,0,sizeof((yyval.xtokClass).qualifiers));
       if (PARM->Ps)
          (yyval.xtokClass).properties = PARM->properties;
       else memset(&(yyval.xtokClass).properties,0,sizeof((yyval.xtokClass).properties));
       if (PARM->Ms)
          (yyval.xtokClass).methods = PARM->methods;
       else memset(&(yyval.xtokClass).methods,0,sizeof((yyval.xtokClass).methods));
    }
    break;

  case 49:
#line 1002 "../backend/cimxml/cimXmlResp.y"
    {;}
    break;

  case 50:
#line 1004 "../backend/cimxml/cimXmlResp.y"
    {
       PARM->Qs++;
       addQualifier(PARM,&(PARM->qualifiers),&(yyvsp[0].xtokQualifier));
    }
    break;

  case 51:
#line 1008 "../backend/cimxml/cimXmlResp.y"
    {
       PARM->Ps++;
       addProperty(PARM,&(PARM->properties),&(yyvsp[0].xtokProperty));
       PARM->PQs = 0;
    }
    break;

  case 52:
#line 1013 "../backend/cimxml/cimXmlResp.y"
    {
        PARM->Ms++;
        addMethod(PARM,&(PARM->methods),&(yyvsp[0].xtokMethod));
    }
    break;

  case 53:
#line 1021 "../backend/cimxml/cimXmlResp.y"
    {
       if (PARM->MQs)
          (yyval.xtokMethod).qualifiers = (yyvsp[-1].xtokMethodData).qualifiers;
       else memset(&(yyval.xtokMethod).qualifiers,0,sizeof((yyval.xtokMethod).qualifiers));
       if (PARM->MPs)
          (yyval.xtokMethod).params = (yyvsp[-1].xtokMethodData).params;
       else memset(&(yyval.xtokMethod).params,0,sizeof((yyval.xtokMethod).params));
       PARM->MQs = 0;
       PARM->MPs = 0;
       PARM->MPQs = 0;
    }
    break;

  case 54:
#line 1035 "../backend/cimxml/cimXmlResp.y"
    {;}
    break;

  case 55:
#line 1037 "../backend/cimxml/cimXmlResp.y"
    {
       if (PARM->MQs == 0)
          memset(&(yyval.xtokMethodData).qualifiers,0,sizeof((yyval.xtokMethodData).qualifiers));
       PARM->MQs++;
       addQualifier(PARM,&((yyval.xtokMethodData).qualifiers),&(yyvsp[0].xtokQualifier));
    }
    break;

  case 56:
#line 1044 "../backend/cimxml/cimXmlResp.y"
    {
       if (PARM->MPs == 0)
          memset(&(yyval.xtokMethodData).params,0,sizeof((yyval.xtokMethodData).params));
       PARM->MPs++;
       if (PARM->MPQs)
          (yyvsp[-2].xtokParam).qualifiers = (yyvsp[-1].xtokParam).qualifiers;
       else memset(&(yyvsp[-2].xtokParam).qualifiers,0,sizeof((yyvsp[-2].xtokParam).qualifiers));
       addParam(PARM,&((yyval.xtokMethodData).params),&(yyvsp[-2].xtokParam));
       PARM->MPQs = 0;
    }
    break;

  case 57:
#line 1055 "../backend/cimxml/cimXmlResp.y"
    {
       if (PARM->MPs == 0)
          memset(&(yyval.xtokMethodData).params,0,sizeof((yyval.xtokMethodData).params));
       PARM->MPs++;
       if (PARM->MPQs)
          (yyvsp[-2].xtokParam).qualifiers = (yyvsp[-1].xtokParam).qualifiers;
       else memset(&(yyvsp[-2].xtokParam).qualifiers,0,sizeof((yyvsp[-2].xtokParam).qualifiers));
       addParam(PARM,&((yyval.xtokMethodData).params),&(yyvsp[-2].xtokParam));
       PARM->MPQs = 0;
    }
    break;

  case 58:
#line 1066 "../backend/cimxml/cimXmlResp.y"
    {
       if (PARM->MPs == 0)
          memset(&(yyval.xtokMethodData).params,0,sizeof((yyval.xtokMethodData).params));
       PARM->MPs++;
       if (PARM->MPQs)
          (yyvsp[-2].xtokParam).qualifiers = (yyvsp[-1].xtokParam).qualifiers;
       else memset(&(yyvsp[-2].xtokParam).qualifiers,0,sizeof((yyvsp[-2].xtokParam).qualifiers));
       addParam(PARM,&((yyval.xtokMethodData).params),&(yyvsp[-2].xtokParam));
       PARM->MPQs = 0;
    }
    break;

  case 59:
#line 1079 "../backend/cimxml/cimXmlResp.y"
    {;}
    break;

  case 60:
#line 1081 "../backend/cimxml/cimXmlResp.y"
    {
       if (PARM->MPQs == 0)
          memset(&(yyval.xtokParam).qualifiers,0,sizeof((yyval.xtokParam).qualifiers));
       PARM->MPQs++;
       addQualifier(PARM,&((yyval.xtokParam).qualifiers),&(yyvsp[0].xtokQualifier));
    }
    break;

  case 61:
#line 1096 "../backend/cimxml/cimXmlResp.y"
    {
       if (PARM->Qs) (yyval.xtokInstance).qualifiers = PARM->qualifiers;
       else memset(&(yyval.xtokInstance).qualifiers, 0, sizeof((yyval.xtokInstance).qualifiers));
       if (PARM->Ps) (yyval.xtokInstance).properties = PARM->properties;
       else memset(&(yyval.xtokInstance).properties, 0, sizeof((yyval.xtokInstance).properties));
    }
    break;

  case 62:
#line 1105 "../backend/cimxml/cimXmlResp.y"
    {;}
    break;

  case 63:
#line 1107 "../backend/cimxml/cimXmlResp.y"
    {
       PARM->Qs++;
       addQualifier(PARM,&(PARM->qualifiers),&(yyvsp[0].xtokQualifier));
    }
    break;

  case 64:
#line 1112 "../backend/cimxml/cimXmlResp.y"
    {
       PARM->Ps++;
       addProperty(PARM,&(PARM->properties),&(yyvsp[0].xtokProperty));
       PARM->PQs = 0;
    }
    break;

  case 65:
#line 1126 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokProperty).val = (yyvsp[-1].xtokPropertyData);
       (yyval.xtokProperty).val.null= PARM->valueSet==0;
       PARM->valueSet=0;
    }
    break;

  case 66:
#line 1132 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokProperty).val = (yyvsp[-1].xtokPropertyData);
       (yyval.xtokProperty).val.null= PARM->valueSet==0;
       PARM->valueSet=0;
    }
    break;

  case 67:
#line 1138 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokProperty).val.array = PARM->curArray;
       (yyval.xtokProperty).val.null= PARM->valueSet==0;
       (yyval.xtokProperty).val.qualifiers = (yyvsp[-1].xtokPropertyData).qualifiers;
       memset(&PARM->curArray,0,sizeof(PARM->curArray));
       PARM->valueSet=0;
    }
    break;

  case 68:
#line 1149 "../backend/cimxml/cimXmlResp.y"
    {
      /*$$.null = 1;*/
       if (PARM->PQs == 0)
          memset(&(yyval.xtokPropertyData).qualifiers,0,sizeof((yyval.xtokPropertyData).qualifiers)); 
       PARM->valueSet=0;
    }
    break;

  case 69:
#line 1156 "../backend/cimxml/cimXmlResp.y"
    {
       if (PARM->PQs == 0)
          memset(&(yyval.xtokPropertyData).qualifiers,0,sizeof((yyval.xtokPropertyData).qualifiers));
       PARM->PQs++;
       addQualifier(PARM,&((yyval.xtokPropertyData).qualifiers),&(yyvsp[0].xtokQualifier));
    }
    break;

  case 70:
#line 1163 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokPropertyData).value = (yyvsp[0].xtokValue).value;
    }
    break;

  case 71:
#line 1167 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokPropertyData).ref = (yyvsp[0].xtokValueReference);
       (yyval.xtokPropertyData).ref.op=PARM->curPath;
       PARM->curPath=NULL;
    }
    break;

  case 72:
#line 1173 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokPropertyData).array = PARM->curArray;
    }
    break;

  case 73:
#line 1187 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokValue).value = (yyvsp[-1].xtokValue).value;
       PARM->valueSet=1;
    }
    break;

  case 74:
#line 1195 "../backend/cimxml/cimXmlResp.y"
    {
       memset(&PARM->curArray,0,sizeof(PARM->curArray));
       (yyval.xtokValueArray) = PARM->curArray;       
    }
    break;

  case 76:
#line 1204 "../backend/cimxml/cimXmlResp.y"
    {
       PARM->curArray.next = 1;
       PARM->curArray.max = 16;
       PARM->curArray.values = (char**)PARSER_MALLOC(sizeof(char*)*PARM->curArray.max);
       PARM->curArray.values[0] = (yyvsp[0].xtokValue).value;
       PARM->valueSet=1;
       (yyval.xtokValueArray) = PARM->curArray;
    }
    break;

  case 77:
#line 1213 "../backend/cimxml/cimXmlResp.y"
    {
       if (PARM->curArray.next >= PARM->curArray.max) {
          PARM->curArray.max *= 2;
          PARM->curArray.values = (char**)PARSER_REALLOC(PARM->curArray.values, sizeof(char*)*PARM->curArray.max);
       }
       PARM->curArray.values[PARM->curArray.next] = (yyvsp[0].xtokValue).value;
       PARM->curArray.next++;
       PARM->valueSet=1;
       (yyval.xtokValueArray) = PARM->curArray;
   }
    break;

  case 78:
#line 1227 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokValueReference).instancePath = (yyvsp[-1].xtokInstancePath);
       (yyval.xtokValueReference).type = typeValRef_InstancePath;
       PARM->valueSet=1;
    }
    break;

  case 79:
#line 1233 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokValueReference).instanceName = (yyvsp[-1].xtokInstanceName);
       (yyval.xtokValueReference).type = typeValRef_InstanceName;
       PARM->valueSet=1;
    }
    break;

  case 80:
#line 1239 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokValueReference).localInstancePath = (yyvsp[-1].xtokLocalInstancePath);
       (yyval.xtokValueReference).type = typeValRef_LocalInstancePath;
       PARM->valueSet=1;
    }
    break;

  case 82:
#line 1259 "../backend/cimxml/cimXmlResp.y"
    {
       simpleArrayAdd(PARM->respHdr.rvArray,(CMPIValue*)&PARM->curPath,CMPI_ref);
       PARM->curPath = NULL;
    }
    break;

  case 83:
#line 1267 "../backend/cimxml/cimXmlResp.y"
    {
	PARM->curPath = newCMPIObjectPath(NULL, (yyval.className), NULL);
    }
    break;

  case 84:
#line 1278 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokQualifier).value = (yyvsp[-1].xtokValue).value;
       PARM->valueSet=0;
    }
    break;

  case 85:
#line 1283 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokQualifier).type|=CMPI_ARRAY;
       (yyval.xtokQualifier).array=PARM->curArray;
       memset(&PARM->curArray,0,sizeof(PARM->curArray));
       PARM->valueSet=0;
    }
    break;

  case 86:
#line 1300 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokLocalNameSpacePath) = (yyvsp[-1].xtokNameSpace).cns;
    }
    break;

  case 87:
#line 1307 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokNameSpace).cns = PARSER_STRDUP((yyvsp[-1].xtokNameSpace).ns);
    }
    break;

  case 88:
#line 1311 "../backend/cimxml/cimXmlResp.y"
    {
       int l = strlen((yyvsp[-2].xtokNameSpace).cns)+strlen((yyvsp[-1].xtokNameSpace).ns)+2;
       (yyval.xtokNameSpace).cns = (char*)PARSER_MALLOC(l);
       strcpy((yyval.xtokNameSpace).cns,(yyvsp[-2].xtokNameSpace).cns);
       strcat((yyval.xtokNameSpace).cns,"/");
       strcat((yyval.xtokNameSpace).cns,(yyvsp[-1].xtokNameSpace).ns);
    }
    break;

  case 89:
#line 1323 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokNameSpacePath).host = (yyvsp[-2].xtokHost);
       (yyval.xtokNameSpacePath).nameSpacePath = (yyvsp[-1].xtokLocalNameSpacePath);
    }
    break;

  case 90:
#line 1331 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 91:
#line 1337 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokInstancePath).path = (yyvsp[-2].xtokNameSpacePath);
       (yyval.xtokInstancePath).instanceName = (yyvsp[-1].xtokInstanceName);
       (yyval.xtokInstancePath).type = 1;
    }
    break;

  case 92:
#line 1353 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokLocalInstancePath).path = (yyvsp[-2].xtokLocalNameSpacePath);
       (yyval.xtokLocalInstancePath).instanceName = (yyvsp[-1].xtokInstanceName);
       (yyval.xtokLocalInstancePath).type = 1;
    }
    break;

  case 93:
#line 1373 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokClassPath).name = (yyvsp[-2].xtokNameSpacePath);
       (yyval.xtokClassPath).className = (yyvsp[-1].className);
       (yyval.xtokClassPath).type = 0;
    }
    break;

  case 94:
#line 1387 "../backend/cimxml/cimXmlResp.y"
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
    	 XtokInstanceName *p = &(yyvsp[-1].xtokInstancePath).instanceName;

    	 /* A lot of this came from createPath(), has to be unique */
	 if (PARM->curPath) CMRelease(PARM->curPath);
    	 PARM->curPath = newCMPIObjectPath((yyvsp[-1].xtokInstancePath).path.nameSpacePath,
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
    break;

  case 95:
#line 1429 "../backend/cimxml/cimXmlResp.y"
    {
         if (PARM->curPath) CMRelease(PARM->curPath);
    	 PARM->curPath = newCMPIObjectPath((yyvsp[-1].xtokClassPath).name.nameSpacePath,
					   (yyvsp[-1].xtokClassPath).className, NULL);
	 simpleArrayAdd(PARM->respHdr.rvArray, (CMPIValue*)&PARM->curPath,
								CMPI_ref);
    	 PARM->curPath = NULL;
    }
    break;

  case 96:
#line 1441 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 97:
#line 1444 "../backend/cimxml/cimXmlResp.y"
    {
    }
    break;

  case 98:
#line 1455 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokInstanceName).className = (yyvsp[-1].xtokInstanceName).className;
       (yyval.xtokInstanceName).bindings.next = 0;
       (yyval.xtokInstanceName).bindings.keyBindings = NULL;
       PARM->curPath = NULL;
    }
    break;

  case 99:
#line 1462 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokInstanceName).className = (yyvsp[-2].xtokInstanceName).className;
       (yyval.xtokInstanceName).bindings = (yyvsp[-1].xtokKeyBindings);
       if (PARM->curPath) CMRelease(PARM->curPath);
       createPath(&(PARM->curPath), &(yyval.xtokInstanceName));
    }
    break;

  case 100:
#line 1472 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokKeyBindings).next = 1;
       (yyval.xtokKeyBindings).max  = 8;
       (yyval.xtokKeyBindings).keyBindings = (XtokKeyBinding*)PARSER_MALLOC(sizeof(XtokKeyBinding) * (yyval.xtokKeyBindings).max);
       (yyval.xtokKeyBindings).keyBindings[0].name = (yyvsp[0].xtokKeyBinding).name;
       (yyval.xtokKeyBindings).keyBindings[0].value = (yyvsp[0].xtokKeyBinding).value;
       (yyval.xtokKeyBindings).keyBindings[0].type = (yyvsp[0].xtokKeyBinding).type;
       (yyval.xtokKeyBindings).keyBindings[0].ref = (yyvsp[0].xtokKeyBinding).ref;
    }
    break;

  case 101:
#line 1482 "../backend/cimxml/cimXmlResp.y"
    {
       if ((yyval.xtokKeyBindings).next == (yyval.xtokKeyBindings).max) {
          (yyval.xtokKeyBindings).max *= 2;
          (yyval.xtokKeyBindings).keyBindings = (XtokKeyBinding*)PARSER_REALLOC((yyval.xtokKeyBindings).keyBindings,
				           sizeof(XtokKeyBinding) * (yyval.xtokKeyBindings).max);
       }
       (yyval.xtokKeyBindings).keyBindings[(yyval.xtokKeyBindings).next].name = (yyvsp[0].xtokKeyBinding).name;
       (yyval.xtokKeyBindings).keyBindings[(yyval.xtokKeyBindings).next].value = (yyvsp[0].xtokKeyBinding).value;
       (yyval.xtokKeyBindings).keyBindings[(yyval.xtokKeyBindings).next].type = (yyvsp[0].xtokKeyBinding).type;
       (yyval.xtokKeyBindings).keyBindings[(yyval.xtokKeyBindings).next].ref = (yyvsp[0].xtokKeyBinding).ref;
       (yyval.xtokKeyBindings).next++;
    }
    break;

  case 102:
#line 1498 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokKeyBinding).name = (yyvsp[-3].xtokKeyBinding).name;
       (yyval.xtokKeyBinding).value = (yyvsp[-2].xtokKeyValue).value;
       (yyval.xtokKeyBinding).type = (yyvsp[-2].xtokKeyValue).valueType;
    }
    break;

  case 103:
#line 1504 "../backend/cimxml/cimXmlResp.y"
    {
       (yyval.xtokKeyBinding).name = (yyvsp[-2].xtokKeyBinding).name;
       (yyval.xtokKeyBinding).value = NULL;
       (yyval.xtokKeyBinding).type = "ref";
       (yyval.xtokKeyBinding).ref = (yyvsp[-1].xtokValueReference);
    }
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 2830 "cimXmlResp.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytname[yytype];
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytname[yyx];
		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 1512 "../backend/cimxml/cimXmlResp.y"


