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
/* Line 1447 of yacc.c.  */
#line 249 "cimXmlResp.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif





