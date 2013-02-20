
/*
 * cimXmlParser.h
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
 * CIM XML lexer for sfcb to be used in connection with cimXmlOps.y.
 *
*/

#ifndef XMLSCAN_H
#define XMLSCAN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <cmci/cmcidt.h>
#include <cmci/cmcift.h>
#include <cmci/cmcimacs.h>
#include <cmci/native.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum typeValRef {
   typeValRef_InstanceName,
   typeValRef_InstancePath,
   typeValRef_LocalInstancePath
} TypeValRef;

typedef enum typeProperty {
   typeProperty_Value,
   typeProperty_Reference,
   typeProperty_Array
} TypeProperty;

typedef struct xmlBuffer {
   char *base;
   char *last;
   char *cur;
   char eTagFound;
   int etag;
   char nulledChar;
} XmlBuffer;

typedef struct xmlElement {
   char *attr;
} XmlElement;

typedef struct xmlAttr {
   char *attr;
} XmlAttr;




typedef struct xtokNameSpace {
   char *ns;
   char *cns;                   // must be free'd
} XtokNameSpace;

typedef struct xtokMessage {
   char *id;
} XtokMessage;

typedef struct xtokValue {
   char *value;
} XtokValue;

typedef struct xtokValueArray {
   int max,next;
   char **values;
} XtokValueArray;

typedef struct xtokHost {
   char *host;
} XtokHost;

typedef struct xtokNameSpacePath {
    XtokHost host;
    char *nameSpacePath;
} XtokNameSpacePath;



struct xtokKeyBinding;
struct xtokValueReference;

typedef struct xtokKeyValue {
   char *valueType, *value;
} XtokKeyValue;

typedef struct xtokKeyBindings {
   int max, next;
   struct xtokKeyBinding *keyBindings; // must be free'd
} XtokKeyBindings;

typedef struct xtokInstanceName {
   char *className;
   XtokKeyBindings bindings;
} XtokInstanceName;

typedef struct xtokInstancePath {
   XtokNameSpacePath path;
   XtokInstanceName instanceName;
   int type;
} XtokInstancePath;

typedef struct xtokLocalInstancePath {
   char *path;
   XtokInstanceName instanceName;
   int type;
} XtokLocalInstancePath;

typedef struct xtokLocalClassPath {
   char *path;
   char *className;
   int type;
} XtokLocalClassPath;

typedef struct xtokClassPath {
   XtokNameSpacePath name;
   char *className;
   int  type;
} XtokClassPath;

typedef struct xtokValueReference {
   union {
      XtokInstancePath instancePath;
      XtokLocalInstancePath localInstancePath;
      XtokInstanceName instanceName;
   };
   TypeValRef type;
   CMPIObjectPath *op;
} XtokValueReference;

typedef struct xtokValueRefArray {
   int max,next;
   XtokValueReference *values;
} XtokValueRefArray;

typedef struct xtokKeyBinding {
   char *name, *value, *type;
   XtokValueReference ref;
} XtokKeyBinding;


typedef struct xtokQualifier {
   struct xtokQualifier *next;
   char *name;
   CMPIType type;
   char *value;
   XtokValueArray array;
   char propagated, overridable, tosubclass, toinstance, translatable;
} XtokQualifier;

typedef struct xtokQualifiers {
   XtokQualifier *last, *first; // must be free'd
} XtokQualifiers;



typedef struct xtokPropertyData {
//   union {
      char *value;
      XtokValueReference ref;
      XtokValueArray array;
//   };
   XtokQualifiers qualifiers;
   int null;
} XtokPropertyData;

typedef struct xtokProperty {
   struct xtokProperty *next;
   char *name;
   char *classOrigin;
   char propagated;
   char *referenceClass;
   CMPIType valueType;
   XtokPropertyData val;
   TypeProperty propType;
} XtokProperty;

typedef struct xtokProperties {
   XtokProperty *last, *first;  // must be free'd
} XtokProperties;

typedef struct xtokReturnValue {
   CMPIType type;
} XtokReturnValue;

typedef struct xtokInstance {
   char *className;
   XtokProperties properties;
   XtokQualifiers qualifiers;
} XtokInstance;

typedef struct xtokInstanceWithPath {
   XtokInstancePath path;
   XtokInstance inst;
} XtokInstanceWithPath;

typedef struct xtokInstanceData {
   XtokProperties properties;
   XtokQualifiers qualifiers;
} XtokInstanceData;

typedef struct xtokNamedInstance {
   XtokInstanceName path;
   XtokInstance instance;
} XtokNamedInstance;

typedef struct xtokObjectPath {
   XtokInstancePath path;
} XtokObjectPath;

typedef struct xtokPropertyList {
   XtokValueArray list;
} XtokPropertyList;


typedef struct xtokParamValue {
  struct xtokParamValue *next;
  char *name;
  CMPIType type;
  union {
     XtokValue value;
     XtokValueReference valueRef;
     XtokValueArray valueArray;
  };
} XtokParamValue;

typedef struct xtokParamValues {
   XtokParamValue *last, *first;  // must be free'd
} XtokParamValues;


typedef struct xtokParam {
   struct xtokParam *next;
   XtokQualifiers qualifiers;
   XtokQualifier qualifier;
   int qPart;
   int pType;
   char *name;
   char *refClass;
   char *arraySize;
   CMPIType type;
} XtokParam;

typedef struct xtokParams {
   XtokParam *last, *first;  // must be free'd
} XtokParams;


typedef struct xtokMethod {
   struct xtokMethod *next;
   XtokQualifiers qualifiers;
   XtokParams params;
   char *name;
   char *classOrigin;
   int propagated;
   CMPIType type;
} XtokMethod;

typedef struct xtokMethodData {
   XtokQualifiers qualifiers;
   XtokParams params;
} XtokMethodData;

typedef struct xtokMethods {
   XtokMethod *last, *first;  // must be free'd
} XtokMethods;


typedef struct xtokClass {
   char *className;
   char *superClass;
   XtokProperties properties;
   XtokQualifiers qualifiers;
   XtokMethods    methods;
} XtokClass;

typedef struct xtokClassWithPath {
   XtokClassPath path;
   XtokClass cls;
} XtokClassWithPath;

typedef struct xtokObjectWithPath {
   union {
       XtokInstanceWithPath inst;
       XtokClassWithPath cls;
   };
   int type;
} XtokObjectWithPath;

typedef struct xtokErrorResp {
   char *code;
   char *description;
} XtokErrorResp;



#include <setjmp.h>

typedef struct responseHdr {
   XmlBuffer *xmlBuffer;
   int rc;
   int opType;
   int simple;
   char *id;
   char *iMethod;
   int methodCall;
   void *cimRequest;
   unsigned long cimRequestLength;
   int errCode;
   char *description;
   CMPIArray *rvArray;
   CMPIArgs *outArgs;
} ResponseHdr;


typedef struct parser_heap {
  size_t  capacity;
  size_t  numBlocks;
  void  **blocks;
} ParserHeap;
 
typedef struct parser_control {
   XmlBuffer *xmb;
   ResponseHdr respHdr;
   char *da_nameSpace;
   CMPIInstance *curInstance;
   CMPIObjectPath *curPath;
   CMPIConstClass *curClass;
   XtokProperties properties;
   XtokQualifiers qualifiers;
   XtokMethods     methods;
   XtokParamValues paramValues;
   XtokValueArray curArray;
   int valueSet;
   int Qs,Ps,Ms,MPs,MQs,MPQs,PQs;
   ParserHeap *heap;
} ParserControl;

ParserHeap* parser_heap_init();
void parser_heap_term(ParserHeap* ph);
void* parser_malloc(ParserHeap *ph, size_t sz);
void* parser_calloc(ParserHeap *ph, size_t num, size_t sz);
void* parser_realloc(ParserHeap *ph, void *p, size_t sz);
void* parser_strdup(ParserHeap *ph, const char *s);

extern ResponseHdr scanCimXmlResponse(const char *xmlData, CMPIObjectPath *cop);
extern void freeCimXmlResponse(ResponseHdr * hdr);

#ifdef __cplusplus
 }
#endif

#endif
