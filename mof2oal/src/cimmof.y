//%2006////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2000, 2001, 2002 BMC Software; Hewlett-Packard Development
// Company, L.P.; IBM Corp.; The Open Group; Tivoli Systems.
// Copyright (c) 2003 BMC Software; Hewlett-Packard Development Company, L.P.;
// IBM Corp.; EMC Corporation, The Open Group.
// Copyright (c) 2004 BMC Software; Hewlett-Packard Development Company, L.P.;
// IBM Corp.; EMC Corporation; VERITAS Software Corporation; The Open Group.
// Copyright (c) 2005 Hewlett-Packard Development Company, L.P.; IBM Corp.;
// EMC Corporation; VERITAS Software Corporation; The Open Group.
// Copyright (c) 2006 Hewlett-Packard Development Company, L.P.; IBM Corp.;
// EMC Corporation; Symantec Corporation; The Open Group.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// THE ABOVE COPYRIGHT NOTICE AND THIS PERMISSION NOTICE SHALL BE INCLUDED IN
// ALL COPIES OR SUBSTANTIAL PORTIONS OF THE SOFTWARE. THE SOFTWARE IS PROVIDED
// "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
// LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//==============================================================================
//
// cimmof.y
// MOF2CPP parser.
//

%{
  /* Flex grammar created from CIM Specification Version 2.2 Appendix A */

  /*
     Note the following implementation details:

       1. The MOF specification has a production of type assocDeclaration,
       but an association is just a type of classDeclaration with a few
       special rules.  At least for the first pass, I'm treating an
       associationDeclaration as a classDeclaration and applying its
       syntactical rules outside of the grammar definition.

       2. Same with the indicationDeclaration.  It appears to be a normal
       classDeclaration with the INDICATION qualifier and no special
       syntactical rules.

       3. The Parser uses String objects throughout to represent
       character data.  However, the tokenizer underneath is probably
       working with 8-bit chars.  If we later use an extended character
       compatible tokenizer, I anticipate NO CHANGE to this parser.

       4. Besides the tokenizer, this parser uses 2 sets of outside
       services:
          1)Class valueFactory.  This has a couple of static methods
      that assist in creating CIMValue objects from Strings.
      2)Class cimmofParser.  This has a wide variety of methods
      that fall into these catagories:
            a) Interfaces to the Repository.  You call cimmofParser::
            methods to query and store compiled CIM elements.
        b) Error handling.
            c) Data format conversions.
            d) Tokenizer manipulation
            e) Pragma handling
            f) Alias Handling
  */


#define YYSTACKSIZE 2000

#include <cstdlib>
#include <malloc.h>
#include <map>
#include <string>
#include <vector>
#include "cimmethod.h"
#include "cimproperty.h"
#include "cimparameter.h"
#include "cimclass.h"
#include "cimqualifier.h"

#ifndef _WIN32
#define _stricmp strcasecmp
#endif

using std::map;
using std::string;
using std::vector;


/* Enable this define to compie Bison/Yacc tracing */
//#define YYDEBUG
#ifdef YYDEBUG
#define YACCTRACE(X) printf (X)
#else
#define YACCTRACE(X)
#endif

/*--------- Extern Definitions -----------*/
extern int   	yylex (void);
extern int   	yyerror (...);
extern char*	yytext;
extern void  	yyless (int n);
extern int   	yyleng;
extern int 	 	g_curline;
extern string	g_filename;

/*--------- Local Functions ----------------*/
static bool 		  isQualifierPresent (string name);
static string 		  getQualifierValueString (string name);
static vector<string> getQualifierValueArray  (string name);
static bool			  isInputParam (void);
static bool			  isOutputParam (void);

/* ------------------------------------------------------------------- */
/* These globals provide continuity between various pieces of a        */
/* declaration.  They are usually interpreted as "these modifiers were */
/* encountered and need to be applied to the finished object".  For    */
/* example, qualifiers are accumulated in g_qualifier_list[] as they   */
/* encountered, then applied to the production they qualify when it    */
/* is completed.                                                       */
/* ------------------------------------------------------------------- */
	CCIMQualifierValue					g_qualifier_value;
	vector<string>						g_array_value;
	map<string, CCIMQualifierValue>		g_qualifier_list;
	vector<CCIMParameter>				g_parameter_list;
	vector<string>						g_flavor;
	CCIMClass*							g_cur_class  = 0;
	CCIMMethod*							g_cur_method = 0;
	vector<CCIMClass>					g_classes;
	vector<string>						g_include_ref;
	bool								g_is_param_ref = false;


/* ---------------------------------------------------------------- */
/* Use our general wrap manager to handle end-of-file               */
/* ---------------------------------------------------------------- */
extern "C" {
int
yywrap () 
{
  return 1;
}
}

/* ---------------------------------------------------------------- */
/* Pass errors to our general log manager.                          */
/* ---------------------------------------------------------------- */
void
yyerror (const char *msg) 
{
	fprintf (stderr, "%s(%d): error: %s\n", g_filename.c_str (),
											g_curline, 
											msg);
}

%}

%union {
	CCIMClass*				cimclass;
	CCIMMethod*				cimmethod;
	CCIMProperty*			cimproperty;
	CCIMParameter*			cimparameter;
	CCIMReference*			cimreference;
	string*					strval;
	int						val;
}

%token TOK_ALIAS_IDENTIFIER
%token TOK_ANY
%token TOK_AS
%token TOK_ASSOCIATION
%token TOK_BINARY_VALUE
%token TOK_CHAR_VALUE
%token TOK_CLASS
%token TOK_COLON
%token TOK_COMMA
%token TOK_DISABLEOVERRIDE
%token TOK_DQUOTE
%token TOK_DT_BOOL
%token TOK_DT_CHAR16
%token TOK_DT_CHAR8
%token TOK_DT_DATETIME
%token TOK_DT_REAL32
%token TOK_DT_REAL64
%token TOK_DT_SINT16
%token TOK_DT_SINT32
%token TOK_DT_SINT64
%token TOK_DT_SINT8
%token TOK_DT_STR
%token TOK_DT_UINT16
%token TOK_DT_UINT32
%token TOK_DT_UINT64
%token TOK_DT_UINT8
%token TOK_ENABLEOVERRIDE
%token TOK_END_OF_FILE
%token TOK_EQUAL
%token TOK_FALSE
%token TOK_FLAVOR
%token TOK_HEX_VALUE
%token TOK_INCLUDE
%token TOK_INDICATION
%token TOK_INSTANCE
%token TOK_LEFTCURLYBRACE
%token TOK_LEFTPAREN
%token TOK_LEFTSQUAREBRACKET
%token TOK_METHOD
%token TOK_NULL_VALUE
%token TOK_OCTAL_VALUE
%token TOK_OF
%token TOK_PARAMETER
%token TOK_PERIOD
%token TOK_POSITIVE_DECIMAL_VALUE
%token TOK_PRAGMA
%token TOK_PROPERTY
%token TOK_QUALIFIER
%token TOK_REAL_VALUE
%token TOK_REF
%token TOK_REFERENCE
%token TOK_RESTRICTED
%token TOK_RIGHTCURLYBRACE
%token TOK_RIGHTPAREN
%token TOK_RIGHTSQUAREBRACKET
%token TOK_SCHEMA
%token TOK_SCOPE
%token TOK_SEMICOLON
%token TOK_SIGNED_DECIMAL_VALUE
%token TOK_SIMPLE_IDENTIFIER
%token TOK_STRING_VALUE
%token TOK_TOSUBCLASS
%token TOK_TRANSLATABLE
%token TOK_TRUE
%token TOK_UNEXPECTED_CHAR


%type <cimclass>	  	classHead  classDeclaration
%type <cimmethod>	  	methodHead  methodDeclaration
%type <cimproperty>	  	propertyBody propertyDeclaration
%type <cimreference>  	referenceDeclaration 
%type <strval>		  	propertyName parameterName methodName className
%type <strval>		  	superClass dataType intDataType realDataType 
%type <strval>		  	parameterType metaElement fileName 
%type <strval>		  	referencedObject referenceName 
%type <strval>		  	integerValue TOK_REAL_VALUE TOK_CHAR_VALUE
%type <strval>         	TOK_POSITIVE_DECIMAL_VALUE TOK_OCTAL_VALUE TOK_HEX_VALUE
%type <strval>         	TOK_BINARY_VALUE TOK_SIGNED_DECIMAL_VALUE
%type <strval>         	TOK_SIMPLE_IDENTIFIER TOK_STRING_VALUE
%type <strval>         	TOK_UNEXPECTED_CHAR
%type <strval>         	pragmaName pragmaVal qualifierName 
%type <strval>         	aliasIdentifier TOK_ALIAS_IDENTIFIER  alias
%type <strval>         	stringValue stringValues typedQualifierParameter
%type <strval>         	nonNullConstantValue objectRef
%type <val>			  array

%%

/*
**------------------------------------------------------------------------------
**
**   Production rules section
**
**------------------------------------------------------------------------------
*/
mofSpec: mofProductions ;


mofProductions: mofProduction mofProductions
			  | error 
			  	{ 
			  		yyerror ("Unrecognized mof production. Aborting ...\n");
					return -1;
				}
              | /* empty */ ;


// ATTN: P1 KS Apr 2002 Limit in (none) Directive handling. See FIXME below.
mofProduction : compilerDirective    { }
    		  | qualifierDeclaration { }
    		  | classDeclaration 
    		  	{ 
					$1->addIncludeRef (g_include_ref);
					g_classes.push_back (*$1);
					delete $1;
					g_cur_class = 0;
        		}
    		  | instanceDeclaration { }
			  ;

/*
**------------------------------------------------------------------------------
**
**   class Declaration productions and processing
**
**------------------------------------------------------------------------------
*/
classDeclaration : classHead  classBody { $$ = $1; }
				 ;

classHead: qualifierList TOK_CLASS className alias superClass
{
	$$ = new CCIMClass (*$3, *$5);

	if (isQualifierPresent ("association")) { $$->setAssociation (); }
	$$->addDesc (getQualifierValueString ("description"));
	$$->setUMLPkgPath (getQualifierValueString ("UMLPackagePath"));	

	if (0 != g_cur_class) { delete g_cur_class; }
	g_cur_class = $$;	
	g_include_ref.clear ();

    delete $3;
    delete $4;
    delete $5;
} ;


className: TOK_SIMPLE_IDENTIFIER {};


superClass: TOK_COLON className { $$ = $2; }
    		| /* empty */ 		{ $$ = new string (""); } ;


classBody : TOK_LEFTCURLYBRACE classFeatures TOK_RIGHTCURLYBRACE TOK_SEMICOLON
          | TOK_LEFTCURLYBRACE TOK_RIGHTCURLYBRACE TOK_SEMICOLON 
          ;


classFeatures : classFeature
    		  | classFeatures classFeature 
    		  ;


classFeature : propertyDeclaration  
    		   {
        			YACCTRACE("classFeature:applyProperty");
					g_cur_class->addProperty (*$1);
					delete $1;
    		   }
    		 | methodDeclaration 
    		   {
        			YACCTRACE("classFeature:applyMethod");
					g_cur_class->addMethod (*$1);
					delete $1;
					g_cur_method = 0;
    		   }
    		 | referenceDeclaration 
    		   {
        			YACCTRACE("classFeature:applyProperty");
			   		g_cur_class->addReference (*$1);
					delete $1;
    		   }
    		 ;

/*
**------------------------------------------------------------------------------
**
** method Declaration productions and processing.
**
**------------------------------------------------------------------------------
*/

methodDeclaration : qualifierList methodHead methodBody methodEnd
					{
    					YACCTRACE("methodDeclaration");
    					$$ = $2;

						for (unsigned int i = 0; i < g_parameter_list.size (); i++)
						{
							$$->addParameter (g_parameter_list [i]);
						}

					} 
				  ;

methodHead : dataType methodName
		     {
    			YACCTRACE("methodHead");
				if (0 != g_cur_method) { delete g_cur_method; }
				g_cur_method = new CCIMMethod (*$1, *$2);

				$$ = g_cur_method;

				$$->addDesc (getQualifierValueString ("description"));
				
				if (isQualifierPresent ("ValueMap") && 
				    isQualifierPresent ("Values"))
				{
					vector<string> value = getQualifierValueArray ("ValueMap");
					vector<string> desc  = getQualifierValueArray ("Values");

					if (value.size () == desc.size ()) 
					{
						for (int i = 0; i != value.size (); i++)
						{
							$$->addReturnCodeValueMap (value [i], desc [i]);
						}
					}
				}


				delete $1;
				delete $2;

				g_parameter_list.clear ();
		     }
		  ;

methodBody : TOK_LEFTPAREN parameters TOK_RIGHTPAREN;

methodEnd : TOK_SEMICOLON;

methodName : TOK_SIMPLE_IDENTIFIER { };

//
//  Productions for method parameters
//
parameters : parameter	{ }
    | parameters TOK_COMMA parameter { } 
    | /* empty */ ;


parameter : qualifierList parameterType parameterName array
			{
				CCIMParameter param ("", "", false);
				if ($4 == -1) { param = CCIMParameter (*$2, *$3, false); }
				else		  { param = CCIMParameter (*$2, *$3, true);  }

				if (isInputParam ())  { param.setInput ();  }
				if (isOutputParam ()) { param.setOutput (); }
				
				if (g_is_param_ref) { param.setRef (); }

				if (isQualifierPresent ("ValueMap") && 
				    isQualifierPresent ("Values"))
				{
					vector<string> value = getQualifierValueArray ("ValueMap");
					vector<string> desc  = getQualifierValueArray ("Values");

					if (value.size () == desc.size ()) 
					{
						for (int i = 0; i != value.size (); i++)
						{
							param.addValueMap (value [i], desc [i]);
						}
					}
				}

				delete $2;
				delete $3;

				g_parameter_list.push_back (param);
			}
		  ;

parameterType : dataType  
				{ 
					$$ = $1; 
					g_is_param_ref = false; 
				}
              | objectRef 
				{
			  		g_include_ref.push_back (*$1);
              		$$ = $1; 
              		g_is_param_ref = true;
				} 
              ;

/*
**------------------------------------------------------------------------------
**
**   property Declaration productions and processing
**
**------------------------------------------------------------------------------
*/
propertyDeclaration : qualifierList propertyBody propertyEnd { $$ = $2; } 
					;

propertyBody : dataType propertyName array typedDefaultValue
			   {
			   		if ($3 == -1) { $$ = new CCIMProperty (*$1, *$2, false); }
					else		  { $$ = new CCIMProperty (*$1, *$2, true);  }

					$$->addDesc (getQualifierValueString ("description"));
					if (isQualifierPresent ("ValueMap") && 
					    isQualifierPresent ("Values"))
					{
						vector<string> value = getQualifierValueArray ("ValueMap");
						vector<string> desc  = getQualifierValueArray ("Values");

						if (value.size () == desc.size ()) 
						{
							for (int i = 0; i != value.size (); i++)
							{
								$$->addValueMap (value [i], desc [i]);
							}
						}
					}

					if (isQualifierPresent ("write")) { $$->setWriteable (); }
					if (isQualifierPresent ("key"))   { $$->setAsKey (); 	 }
		
					delete $1;
					delete $2;
			   }
			 ;

propertyEnd : TOK_SEMICOLON;


/*
**------------------------------------------------------------------------------
**
**    reference Declaration productions and processing
**
**------------------------------------------------------------------------------
*/

referenceDeclaration : qualifierList referencedObject TOK_REF referenceName
                       referencePath TOK_SEMICOLON
					   {
					   	$$ = new CCIMReference (*$2, *$4);

						$$->addDesc (getQualifierValueString ("description"));
						
						delete $2;
						delete $4;
					   }
					 ;

referencedObject : TOK_SIMPLE_IDENTIFIER {};

referenceName 	 : TOK_SIMPLE_IDENTIFIER {};

referencePath	 : TOK_EQUAL stringValue { delete $2; }
    			 | /* empty */ { } 
    			 ;

objectRef : className TOK_REF { $$ = $1; } 
		  ;

parameterName : TOK_SIMPLE_IDENTIFIER {};

propertyName  : TOK_SIMPLE_IDENTIFIER {};

array : TOK_LEFTSQUAREBRACKET TOK_POSITIVE_DECIMAL_VALUE 
		TOK_RIGHTSQUAREBRACKET { $$ = 1; }
      | TOK_LEFTSQUAREBRACKET TOK_RIGHTSQUAREBRACKET { $$ = 0; }
      | /* empty */ { $$ = -1; } 
      ;


typedDefaultValue : TOK_EQUAL typedInitializer { }
				  | /* empty */ {}
				  ;


initializer : constantValue { }
    		| arrayInitializer {}
    		| referenceInitializer {}
			;


// The typedInitializer element is syntactially identical to
// the initializer element. However, the typedInitializer element
// returns, in addition to the value, the type of the value.
typedInitializer : nonNullConstantValue { delete $1; }
    			 | TOK_NULL_VALUE {}
    			 | arrayInitializer {}
    			 | referenceInitializer {}
				 ;

constantValues : constantValue {}
    		   | constantValues TOK_COMMA constantValue {}
        	   ;


// The nonNullConstantValue has been added to allow NULL
// to be distinguished from the EMPTY STRING.

constantValue : nonNullConstantValue 
				{	
					g_array_value.push_back (*$1); 
				  	delete $1; 
				}
    		  | TOK_NULL_VALUE { }
			  ;

nonNullConstantValue : integerValue   { }
    				 | TOK_REAL_VALUE { }
    				 | TOK_CHAR_VALUE { }
    				 | stringValues   { }
    				 | booleanValue   { }
					 ;

integerValue : TOK_POSITIVE_DECIMAL_VALUE
    		 | TOK_OCTAL_VALUE
    		 | TOK_HEX_VALUE
    		 | TOK_BINARY_VALUE
    		 | TOK_SIGNED_DECIMAL_VALUE
    		 ;


booleanValue : TOK_FALSE {}
    		 | TOK_TRUE {}
			 ;

stringValues : stringValue { }
    		 | stringValues stringValue
   			   {
			   	$$ = new string (*$1 + *$2);
			   	delete $1;
			   	delete $2;
			   }
			 ;

stringValue : TOK_STRING_VALUE {}
			;

arrayInitializer : TOK_LEFTCURLYBRACE constantValues TOK_RIGHTCURLYBRACE {}
    			 | TOK_LEFTCURLYBRACE  TOK_RIGHTCURLYBRACE {}
       			 ;

referenceInitializer : objectHandle {}
    				 | aliasInitializer {} 
    				 ;

objectHandle : TOK_DQUOTE namespaceHandleRef modelPath TOK_DQUOTE {} 
			 ;

aliasInitializer : aliasIdentifier { delete $1; }
				 ;

namespaceHandleRef : namespaceHandle TOK_COLON {}
    			   | /* empty */ {};


namespaceHandle : stringValue { delete $1; }
				;

modelPath		: className TOK_PERIOD keyValuePairList 
				  {	delete $1; }
				;

keyValuePairList : keyValuePair {}
				 ;
    			 | keyValuePairList TOK_COMMA keyValuePair {}
				 ;

keyValuePair : keyValuePairName TOK_EQUAL initializer {}
			 ;

keyValuePairName : TOK_SIMPLE_IDENTIFIER  
				   { delete $1; }
				 ;

alias : TOK_AS aliasIdentifier { $$ = $2; }
      | /* empty */ { $$ = new string (""); }
	  ;

aliasIdentifier : TOK_ALIAS_IDENTIFIER;


/*
**------------------------------------------------------------------------------
**
**   Instance Declaration productions and processing
**
**-----------------------------------------------------------------------------
*/

instanceDeclaration : instanceHead instanceBody {}
					;


instanceHead : qualifierList TOK_INSTANCE TOK_OF className alias
			   {
			   	delete $4;
				delete $5;
			   }
			 ;

instanceBody : TOK_LEFTCURLYBRACE valueInitializers TOK_RIGHTCURLYBRACE
    		   TOK_SEMICOLON 
    		 ;

valueInitializers : valueInitializer
    			  | valueInitializers valueInitializer 
    			  ;


valueInitializer : qualifierList TOK_SIMPLE_IDENTIFIER TOK_EQUAL
                   typedInitializer TOK_SEMICOLON
				   {
				   	delete $2;
				   }
				 ;

/*
**------------------------------------------------------------------------------
**
** Compiler directive productions and processing
**
**------------------------------------------------------------------------------
*/

compilerDirective : compilerDirectiveInclude {}
    			  | compilerDirectivePragma {}
				  ;

compilerDirectiveInclude : TOK_PRAGMA TOK_INCLUDE TOK_LEFTPAREN fileName
                           TOK_RIGHTPAREN
    					   {
						   	delete $4;
    					   }
    					 ;		  

fileName : stringValue {} 
		 ;


compilerDirectivePragma : TOK_PRAGMA pragmaName
       					  TOK_LEFTPAREN pragmaVal TOK_RIGHTPAREN
						  {
						  	delete $2;
							delete $4;
						  }
						;

/*
**------------------------------------------------------------------------------
**
**  qualifier Declaration productions and processing
**
**------------------------------------------------------------------------------
*/

qualifierDeclaration : TOK_QUALIFIER qualifierName qualifierValue scope
                       defaultFlavor TOK_SEMICOLON
					   { delete $2; } 
					 ;

qualifierValue : TOK_COLON dataType array typedDefaultValue
			     { delete $2; } 
			   ;

scope : scope_begin metaElements TOK_RIGHTPAREN {};

scope_begin : TOK_COMMA TOK_SCOPE TOK_LEFTPAREN {};

metaElements : metaElement { delete $1; }
    		 | metaElements TOK_COMMA metaElement { delete $3; } 
    		 ;

metaElement: TOK_CLASS       { $$ = new string ("class");        }
           | TOK_SCHEMA      { $$ = new string ("schema"); 		 }
           | TOK_ASSOCIATION { $$ = new string ("association");  }
           | TOK_INDICATION  { $$ = new string ("indication");   }
           | TOK_PROPERTY    { $$ = new string ("property");     }
           | TOK_REFERENCE   { $$ = new string ("reference");    }
           | TOK_METHOD      { $$ = new string ("method");       }
           | TOK_PARAMETER   { $$ = new string ("parameter");    }
           | TOK_ANY         { $$ = new string ("any");          } 
           ;

defaultFlavor : TOK_COMMA flavorHead explicitFlavors TOK_RIGHTPAREN
    			{ }
			  | /* empty */ { } 
			  ;


flavorHead : TOK_FLAVOR TOK_LEFTPAREN  { g_flavor.clear (); }
		   ;

explicitFlavors : explicitFlavor
    			| explicitFlavors TOK_COMMA explicitFlavor 
    			;


explicitFlavor : TOK_ENABLEOVERRIDE { g_flavor.push_back ("enableoverride"); }
    		   | TOK_DISABLEOVERRIDE{ g_flavor.push_back ("disableoverride");}
    		   | TOK_RESTRICTED     { g_flavor.push_back ("restricted");     }
    		   | TOK_TOSUBCLASS     { g_flavor.push_back ("tosubclass");	 }
    		   | TOK_TRANSLATABLE   { g_flavor.push_back ("translatable");	 }
			   ;

flavor : overrideFlavors { }
       | /* empty */  {}
	   ;

overrideFlavors : explicitFlavor
    			| overrideFlavors explicitFlavor 
    			;

dataType : intDataType     { $$ = $1; }
    	 | realDataType    { $$ = $1; }
    	 | TOK_DT_STR      { $$ = new string ("string");   }
    	 | TOK_DT_BOOL     { $$ = new string ("boolean");  }
    	 | TOK_DT_DATETIME { $$ = new string ("datetime"); } 
    	 ;


intDataType : TOK_DT_UINT8  { $$ = new string ("uint8");  }
    		| TOK_DT_SINT8  { $$ = new string ("sint8");  }
    		| TOK_DT_UINT16 { $$ = new string ("uint16"); }
    		| TOK_DT_SINT16 { $$ = new string ("sint16"); }
    		| TOK_DT_UINT32 { $$ = new string ("uint32"); }
    		| TOK_DT_SINT32 { $$ = new string ("sint32"); }
    		| TOK_DT_UINT64 { $$ = new string ("uint64"); }
    		| TOK_DT_SINT64 { $$ = new string ("sint64"); }
    		| TOK_DT_CHAR16 { $$ = new string ("char16"); } 
    		;


realDataType : TOK_DT_REAL32 { $$ = new string ("real32"); }
    		 | TOK_DT_REAL64 { $$ = new string ("real64"); }
			 ;
/*
**------------------------------------------------------------------------------
**
**   Qualifier list and qualifier processing
**
**------------------------------------------------------------------------------
*/
qualifierList	: qualifierListBegin qualifiers TOK_RIGHTSQUAREBRACKET {}
    			| /* empty */ 
        		{
					g_qualifier_list.clear ();
        		};

qualifierListBegin: TOK_LEFTSQUAREBRACKET 
				    {
    			  		YACCTRACE ("qualifierListbegin");
				  		g_qualifier_list.clear (); 
			      	}
			      	;

qualifiers	: qualifier { }
    		| qualifiers TOK_COMMA qualifier { } 
    		;

qualifier : qualifierName typedQualifierParameter flavor
		  	{
				g_qualifier_list.insert (std::pair<string, CCIMQualifierValue> (*$1, g_qualifier_value));
				delete $1;
		  	}
		  ;

qualifierName : TOK_SIMPLE_IDENTIFIER 
				{ 
					g_flavor.clear (); 
					g_qualifier_value = CCIMQualifierValue ();
					g_array_value.clear ();
					$$ = $1;
				}
			  | metaElement 		  
			  	{ 
			  		g_flavor.clear ();  
					g_qualifier_value = CCIMQualifierValue ();
					g_array_value.clear ();
					$$ = $1;
			  	}
			  ;


typedQualifierParameter : TOK_LEFTPAREN nonNullConstantValue TOK_RIGHTPAREN
        				  {
						  	g_qualifier_value.setValue (*$2);
							delete $2;
						  }
					    | TOK_LEFTPAREN TOK_NULL_VALUE TOK_RIGHTPAREN
        				  {
						  	g_qualifier_value.setValue ("");
						  }
    					| arrayInitializer 
    					{ 
							g_qualifier_value.setValue (g_array_value);
    					}
    					| /* empty */      
    					{ 
							g_qualifier_value.setValue ("");
    					}
						;

pragmaName: TOK_SIMPLE_IDENTIFIER {};


pragmaVal:  TOK_STRING_VALUE {};

%%

/**
 * Checks if a qualifier is present
 */
static bool
isQualifierPresent (string name)
{
	std::map<string, CCIMQualifierValue>::iterator i;
	for (i = g_qualifier_list.begin (); 
 		   	 				i != g_qualifier_list.end (); 
 		   	 				i++)
	{
		if (0 == _stricmp ((*i).first.c_str (), name.c_str ()))
		{
			return true;
		}
	}

	return false;
}

/**
 * Gets the string value corresponding to a qualifier
 */
static string 
getQualifierValueString (string name)
{
	std::map<string, CCIMQualifierValue>::iterator i;
	for (i = g_qualifier_list.begin (); 
 		   	 				i != g_qualifier_list.end (); 
 		   	 				i++)
	{
		if (0 == _stricmp ((*i).first.c_str (), name.c_str ()))
		{
			if ((*i).second.getType () == DCOM_QUALIFIER_TYPE_STRING)
			{
				return (*i).second.getValueString ();
			}
			else { return ""; }
		}
	}

	return "";
}

/**
 * Gets the array value corresponding to a qualifier
 */
static vector<string> 
getQualifierValueArray (string name)
{
	std::map<string, CCIMQualifierValue>::iterator i;
	for (i = g_qualifier_list.begin (); 
 		   	 				i != g_qualifier_list.end (); 
 		   	 				i++)
	{
		if (0 == _stricmp ((*i).first.c_str (), name.c_str ()))
		{
			if ((*i).second.getType () == DCOM_QUALIFIER_TYPE_ARRAY)
			{
				return (*i).second.getValueArray ();
			}
			else 
			{ 
				vector<string> empty_array;
				return empty_array; 
			}
		}
	}

	vector<string> empty_array;
	return empty_array; 
}

/**
 * Checks if a parameter is input parameter
 */
static bool
isInputParam (void)
{
	std::map<string, CCIMQualifierValue>::iterator i;
	for (i = g_qualifier_list.begin (); 
 		   	 				i != g_qualifier_list.end (); 
 		   	 				i++)
	{
		if (0 == _stricmp ((*i).first.c_str (), "in"))
		{
			if (0 != _stricmp ((*i).second.getValueString ().c_str (), "false"))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	return false;
}

/**
 * Checks if a parameter is output parameter
 */
static bool
isOutputParam (void)
{
	std::map<string, CCIMQualifierValue>::iterator i;
	for (i = g_qualifier_list.begin (); 
 		   	 				i != g_qualifier_list.end (); 
 		   	 				i++)
	{
		if (0 == _stricmp ((*i).first.c_str (), "out"))
		{
			if (0 != _stricmp ((*i).second.getValueString ().c_str (), "false"))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	return false;
}
