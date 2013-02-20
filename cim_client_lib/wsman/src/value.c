/*!
  \file value.c
  \brief Native CMPIValue helper module.

  This module provides means to clone and release CMPIValues.

  (C) Copyright IBM Corp. 2003
  (C) Copyright Intel Corp. 2006
 
  THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE 
  ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
  CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 
  You can obtain a current copy of the Eclipse Public License from
  http://www.opensource.org/licenses/eclipse-1.0.php

  \author Frank Scheffler
  $Revision: 1.1 $
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cmcidt.h"
#include "cmcift.h"
#include "native.h"

#ifdef DMALLOC
#include "dmalloc.h"
#endif
 
char *keytype2Chars(CMPIType type);
CMPIType guessType(char *val);
char *value2Chars(CMPIType type, CMPIValue * value);
extern char *pathToChars(CMPIObjectPath * cop, CMPIStatus * rc, char *str,
								 int uri);


void native_release_CMPIValue ( CMPIType type, CMPIValue * val )
{
	if ( val )
		switch ( type ) {
	
		case CMPI_instance:
			if (val->inst)
			    CMRelease ( val->inst );
			break;
	
		case CMPI_class:
			if (val->inst)
			    CMRelease ( val->inst );
			break;
	
		case CMPI_ref:
			if (val->ref)
			    CMRelease ( val->ref );
			break;
	
		case CMPI_args:
			if (val->args)
			    CMRelease ( val->args );
			break;
	
		case CMPI_enumeration:
			if (val->Enum)
			    CMRelease ( val->Enum );
			break;
	
		case CMPI_string:
			if (val->string)
			    CMRelease ( val->string );
			break;
	
		case CMPI_chars:
			if (val->chars)
			    free ( val->chars );
			break;
	
		case CMPI_dateTime:
			if (val->dateTime)
			    CMRelease ( val->dateTime );
			break;
	
		default:
			if ( type & CMPI_ARRAY ) {
				if (val->array)
				    CMRelease ( val->array );
			}
		}
}


CMPIValue native_clone_CMPIValue ( CMPIType type,
				   CMPIValue * val,
				   CMPIStatus * rc )
{
	CMPIValue v;

        v.uint64 = 0LL;		/* Necessary, don't delete */
	if ( type & CMPI_ARRAY ) {
		CMPIArray *array = val->array;
                if (array)
		v.array = CMClone ( array, rc );
	} 
	else
	if ( (type & CMPI_ENC) && val->inst ) {
		switch ( type ) {

		case CMPI_instance:
                        if (val->inst)
			v.inst = CMClone ( val->inst, rc );
			break;

		case CMPI_ref:
                        if (val->ref)
			v.ref = CMClone ( val->ref, rc );
			break;

		case CMPI_args:
                        if (val->args)
			v.args = CMClone ( val->args, rc );
			break;

		case CMPI_enumeration:
                        if (val->Enum)
			v.Enum = CMClone ( val->Enum, rc );
			break;

		case CMPI_string:
                        if (val->string)
			v.string = CMClone ( val->string, rc );
			break;

		case CMPI_chars:
                        if (val->chars)
			v.chars = strdup ( val->chars );
			break;

		case CMPI_dateTime:
                        if (val->dateTime)
			v.dateTime = CMClone ( val->dateTime, rc );
			break;
		}

	} else {
                if (val)
		v = *val;
	}

	CMSetStatus ( rc, CMPI_RC_OK );
	return v;
}

static char *value2CharsUri(CMPIType type, CMPIValue * value, int uri)
{
   char str[2048], *p;
   CMPIString *cStr;

   str[0]=0;
   if (type & CMPI_ARRAY) {
   }
   else if (type & CMPI_ENC) {

      switch (type) {
      case CMPI_instance:
         break;

      case CMPI_ref:
        // return strdup(value->ref ? pathToChars(value->ref, NULL, str, uri) : "NULL");
		  	if (value->ref) {
		  cStr=value->ref->ft->toString(value->ref,NULL);
		  p = strdup((char *) cStr->hdl);
		  CMRelease(cStr);
		} else {
		  p = strdup("NULL");
		}
 
		return p;

		  break;

      case CMPI_args:
         break;

      case CMPI_filter:
         break;

      case CMPI_string:
      case CMPI_numericString:
      case CMPI_booleanString:
      case CMPI_dateTimeString:
      case CMPI_classNameString:
         return strdup(value->string ? (char*)value->string->hdl : "NULL");

      case CMPI_dateTime:
         if (value->dateTime) {
         cStr=CMGetStringFormat(value->dateTime,NULL);
         p = strdup((char *) cStr->hdl);
         CMRelease(cStr);
         } else
             p = strdup("NULL");
	 return p;
      }

   }
   else if (type & CMPI_SIMPLE) {

      switch (type) {
      case CMPI_boolean:
         return strdup(value->boolean ? "true" : "false");

      case CMPI_char16:
         break;
      }

   }
   else if (type & CMPI_INTEGER) {

      switch (type) {
      case CMPI_uint8:
         sprintf(str, "%u", value->uint8);
         return strdup(str);
      case CMPI_sint8:
         sprintf(str, "%d", value->sint8);
         return strdup(str);
      case CMPI_uint16:
         sprintf(str, "%u", value->uint16);
         return strdup(str);
      case CMPI_sint16:
         sprintf(str, "%d", value->sint16);
         return strdup(str);
      case CMPI_uint32:
         sprintf(str, "%lu", value->uint32);
         return strdup(str);
      case CMPI_sint32:
         sprintf(str, "%ld", value->sint32);
         return strdup(str);
      case CMPI_uint64:
         sprintf(str, "%llu", value->uint64);
         return strdup(str);
      case CMPI_sint64:
         sprintf(str, "%lld", value->sint64);
         return strdup(str);
      }

   }
   else if (type & CMPI_REAL) {

      switch (type) {
      case CMPI_real32:
         sprintf(str, "%g", value->real32);
         return strdup(str);
      case CMPI_real64:
         sprintf(str, "%g", value->real64);
         return strdup(str);
      }

   }
   return strdup(str);
}

char *value2Chars(CMPIType type, CMPIValue * value)
{
   return value2CharsUri(type,value,0);
}

char *keytype2Chars(CMPIType type)
{
   if (type == CMPI_boolean) return "boolean";
   if (type & (CMPI_INTEGER | CMPI_REAL)) return "numeric";
   return "string";
}

CMPIType guessType(char *val)
{
   /* TODO: Currently doesn't guess right for real values (3.175e+00) */
   if (((*val=='-' || *val=='+') && strlen(val)>1) || isdigit(*val)) {
      char *c;
      for (c=val+1; ; c++) {
         if (*c==0) {
            if (!isdigit(*val)) return CMPI_sint64;
            return CMPI_uint64;
         }
         if (!isdigit(*c)) break;
      }
   }
   else if (strcasecmp(val,"true") == 0 || strcasecmp(val,"false") == 0)
     return CMPI_boolean;
   return CMPI_string;
}

struct XtokValueReference;
CMPIValue str2CMPIValue(CMPIType type, char *val, struct XtokValueReference *ref)
{
	CMPIValue value = {0};

   if (type==0) {
      type=guessType(val);
   }

  
   switch (type) {
   case CMPI_char16:
      value.char16 = *val;
      break;
   case CMPI_chars:
      value.chars = strdup(val);
      break;
   case CMPI_string:
      value.string = native_new_CMPIString(val, NULL);
      break;
   case CMPI_sint64:
      sscanf(val, "%lld", &value.sint64);
      break;
   case CMPI_uint64:
      sscanf(val, "%llu", &value.uint64);
      break;
   case CMPI_sint32:
      sscanf(val, "%ld", &value.sint32);
      break;
   case CMPI_uint32:
      sscanf(val, "%lu", &value.uint32);
      break;
   case CMPI_sint16:
      sscanf(val, "%hd", &value.sint16);
      break;
   case CMPI_uint16:
      sscanf(val, "%hu", &value.uint16);
      break;
   case CMPI_uint8:
      sscanf(val, "%lu", &value.uint32);
      value.uint8 = (CMPIUint8)value.uint32;
      break;
   case CMPI_sint8:
      sscanf(val, "%ld", &value.sint32);
      value.sint8 = (CMPISint8)value.sint32;
      break;
   case CMPI_boolean:
      value.boolean = (CMPIBoolean)strcasecmp(val, "false");
      break;
   case CMPI_real32:
      sscanf(val, "%f", &value.real32);
      break;
   case CMPI_real64:
      sscanf(val, "%lf", &value.real64);
      break;
   case CMPI_dateTime:
      value.dateTime = native_new_CMPIDateTime_fromChars(val, NULL);
      break;
  default:
      //printf("%s(%d): invalid value %d-%s\n", __FILE__, __LINE__, (int) type, val);
      abort();
   }
   return value;
}
/****************************************************************************/

/*** Local Variables:  ***/
/*** mode: C           ***/
/*** c-basic-offset: 8 ***/
/*** End:              ***/
