/*!
  \file enumeration.c
  \brief Native CMPIEnumeration implementation.

  This is the native CMPIEnumeration implementation as used for remote
  providers. It reflects the well-defined interface of a regular
  CMPIEnumeration, however, it works independently from the management broker.
  
  It is part of a native broker implementation that simulates CMPI data
  types rather than interacting with the entities in a full-grown CIMOM.

  (C) Copyright IBM Corp. 2003
 
  THIS FILE IS PROVIDED UNDER THE TERMS OF THE ECLIPSE PUBLIC LICENSE 
  ("AGREEMENT"). ANY USE, REPRODUCTION OR DISTRIBUTION OF THIS FILE 
  CONSTITUTES RECIPIENTS ACCEPTANCE OF THE AGREEMENT.
 
  You can obtain a current copy of the Eclipse Public License from
  http://www.opensource.org/licenses/eclipse-1.0.php

  \author Frank Scheffler
  $Revision: 1.1 $
*/

#include <stdlib.h>
#include "cmcidt.h"
#include "cmcift.h"
#include "cmcimacs.h"
#include "native.h"

#ifdef DMALLOC
#include "dmalloc.h"
#endif

struct native_enum {
	CMPIEnumeration enumeration;

	CMPICount current;
	CMPIArray * data;
};


static struct native_enum * __new_enumeration ( CMPIArray *,
						CMPIStatus * );


/*****************************************************************************/

static CMPIStatus __eft_release ( CMPIEnumeration * enumeration )
{
	struct native_enum * e = (struct native_enum *) enumeration;
	CMPIStatus st;

	if (e) {
		st = CMRelease(e->data);
		free ( enumeration );
		return st;
	}

	CMReturn ( CMPI_RC_ERR_FAILED );
}


static CMPIEnumeration * __eft_clone ( CMPIEnumeration * enumeration,
				       CMPIStatus * rc )
{
	CMPIStatus tmp;
	struct native_enum * e = (struct native_enum *) enumeration;
	CMPIArray * data       = CMClone ( e->data, &tmp );

	if ( tmp.rc != CMPI_RC_OK ) {
		CMSetStatus ( rc, CMPI_RC_ERR_FAILED );
		return NULL;
	}

	return 
		(CMPIEnumeration *) __new_enumeration ( data, rc );
}


static CMPIData __eft_getNext ( CMPIEnumeration * enumeration,
				CMPIStatus * rc )
{
	struct native_enum * e = (struct native_enum *) enumeration;
	return CMGetArrayElementAt ( e->data, e->current++, rc );
}


static CMPIBoolean __eft_hasNext ( CMPIEnumeration * enumeration,
				   CMPIStatus * rc )
{
	struct native_enum * e = (struct native_enum *) enumeration;
	return ( e->current < CMGetArrayCount ( e->data, rc ) );
}


static CMPIArray * __eft_toArray ( CMPIEnumeration * enumeration,
				   CMPIStatus * rc )
{
	struct native_enum * e = (struct native_enum *) enumeration;
	CMSetStatus ( rc, CMPI_RC_OK );
	return e->data;
}


static struct native_enum * __new_enumeration ( CMPIArray * array,
						CMPIStatus * rc )
{
	static CMPIEnumerationFT eft = {
		NATIVE_FT_VERSION,
		__eft_release,
		__eft_clone,
		__eft_getNext,
		__eft_hasNext,
		__eft_toArray
	};
	static const CMPIEnumeration e = {
		"CMPIEnumeration",
		&eft
	};

	struct native_enum * enumeration = (struct native_enum *)
		calloc ( 1, sizeof ( struct native_enum ) );

	enumeration->enumeration = e;
	enumeration->data = array; 	/* CMClone ( array, rc ) ? */

	CMSetStatus ( rc, CMPI_RC_OK );
	return enumeration;
}


CMPIEnumeration * native_new_CMPIEnumeration ( CMPIArray * array,
					       CMPIStatus * rc )
{
	return (CMPIEnumeration *) __new_enumeration ( array, rc );
}


/****************************************************************************/

/*** Local Variables:  ***/
/*** mode: C           ***/
/*** c-basic-offset: 8 ***/
/*** End:              ***/
