
/*  A Bison parser, made from cimmof.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TOK_ALIAS_IDENTIFIER	258
#define	TOK_ANY	259
#define	TOK_AS	260
#define	TOK_ASSOCIATION	261
#define	TOK_BINARY_VALUE	262
#define	TOK_CHAR_VALUE	263
#define	TOK_CLASS	264
#define	TOK_COLON	265
#define	TOK_COMMA	266
#define	TOK_DISABLEOVERRIDE	267
#define	TOK_DQUOTE	268
#define	TOK_DT_BOOL	269
#define	TOK_DT_CHAR16	270
#define	TOK_DT_CHAR8	271
#define	TOK_DT_DATETIME	272
#define	TOK_DT_REAL32	273
#define	TOK_DT_REAL64	274
#define	TOK_DT_SINT16	275
#define	TOK_DT_SINT32	276
#define	TOK_DT_SINT64	277
#define	TOK_DT_SINT8	278
#define	TOK_DT_STR	279
#define	TOK_DT_UINT16	280
#define	TOK_DT_UINT32	281
#define	TOK_DT_UINT64	282
#define	TOK_DT_UINT8	283
#define	TOK_ENABLEOVERRIDE	284
#define	TOK_END_OF_FILE	285
#define	TOK_EQUAL	286
#define	TOK_FALSE	287
#define	TOK_FLAVOR	288
#define	TOK_HEX_VALUE	289
#define	TOK_INCLUDE	290
#define	TOK_INDICATION	291
#define	TOK_INSTANCE	292
#define	TOK_LEFTCURLYBRACE	293
#define	TOK_LEFTPAREN	294
#define	TOK_LEFTSQUAREBRACKET	295
#define	TOK_METHOD	296
#define	TOK_NULL_VALUE	297
#define	TOK_OCTAL_VALUE	298
#define	TOK_OF	299
#define	TOK_PARAMETER	300
#define	TOK_PERIOD	301
#define	TOK_POSITIVE_DECIMAL_VALUE	302
#define	TOK_PRAGMA	303
#define	TOK_PROPERTY	304
#define	TOK_QUALIFIER	305
#define	TOK_REAL_VALUE	306
#define	TOK_REF	307
#define	TOK_REFERENCE	308
#define	TOK_RESTRICTED	309
#define	TOK_RIGHTCURLYBRACE	310
#define	TOK_RIGHTPAREN	311
#define	TOK_RIGHTSQUAREBRACKET	312
#define	TOK_SCHEMA	313
#define	TOK_SCOPE	314
#define	TOK_SEMICOLON	315
#define	TOK_SIGNED_DECIMAL_VALUE	316
#define	TOK_SIMPLE_IDENTIFIER	317
#define	TOK_STRING_VALUE	318
#define	TOK_TOSUBCLASS	319
#define	TOK_TRANSLATABLE	320
#define	TOK_TRUE	321
#define	TOK_UNEXPECTED_CHAR	322

#line 37 "cimmof.y"

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
#include <cstring>
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


#line 164 "cimmof.y"
typedef union {
	CCIMClass*				cimclass;
	CCIMMethod*				cimmethod;
	CCIMProperty*			cimproperty;
	CCIMParameter*			cimparameter;
	CCIMReference*			cimreference;
	string*					strval;
	int						val;
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		240
#define	YYFLAG		-32768
#define	YYNTBASE	68

#define YYTRANSLATE(x) ((unsigned)(x) <= 322 ? yytranslate[x] : 151)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     5,     7,     8,    10,    12,    14,    16,    19,
    25,    27,    30,    31,    36,    40,    42,    45,    47,    49,
    51,    56,    59,    63,    65,    67,    69,    73,    74,    79,
    81,    83,    87,    92,    94,   101,   103,   105,   108,   109,
   112,   114,   116,   120,   123,   124,   127,   128,   130,   132,
   134,   136,   138,   140,   142,   144,   148,   150,   152,   154,
   156,   158,   160,   162,   164,   166,   168,   170,   172,   174,
   176,   178,   181,   183,   187,   190,   192,   194,   199,   201,
   204,   205,   207,   211,   213,   217,   221,   223,   226,   227,
   229,   232,   238,   243,   245,   248,   254,   256,   258,   264,
   266,   272,   279,   284,   288,   292,   294,   298,   300,   302,
   304,   306,   308,   310,   312,   314,   316,   321,   322,   325,
   327,   331,   333,   335,   337,   339,   341,   343,   344,   346,
   349,   351,   353,   355,   357,   359,   361,   363,   365,   367,
   369,   371,   373,   375,   377,   379,   381,   385,   386,   388,
   390,   394,   398,   400,   402,   406,   410,   412,   413,   415
};

static const short yyrhs[] = {    69,
     0,    70,    69,     0,     1,     0,     0,   124,     0,   128,
     0,    71,     0,   119,     0,    72,    75,     0,   143,     9,
    73,   117,    74,     0,    62,     0,    10,    73,     0,     0,
    38,    76,    55,    60,     0,    38,    55,    60,     0,    77,
     0,    76,    77,     0,    86,     0,    78,     0,    89,     0,
   143,    79,    80,    81,     0,   140,    82,     0,    39,    83,
    56,     0,    60,     0,    62,     0,    84,     0,    83,    11,
    84,     0,     0,   143,    85,    94,    96,     0,   140,     0,
    93,     0,   143,    87,    88,     0,   140,    95,    96,    97,
     0,    60,     0,   143,    90,    52,    91,    92,    60,     0,
    62,     0,    62,     0,    31,   106,     0,     0,    73,    52,
     0,    62,     0,    62,     0,    40,    47,    57,     0,    40,
    57,     0,     0,    31,    99,     0,     0,   101,     0,   107,
     0,   108,     0,   102,     0,    42,     0,   107,     0,   108,
     0,   101,     0,   100,    11,   101,     0,   102,     0,    42,
     0,   103,     0,    51,     0,     8,     0,   105,     0,   104,
     0,    47,     0,    43,     0,    34,     0,     7,     0,    61,
     0,    32,     0,    66,     0,   106,     0,   105,   106,     0,
    63,     0,    38,   100,    55,     0,    38,    55,     0,   109,
     0,   110,     0,    13,   111,   113,    13,     0,   118,     0,
   112,    10,     0,     0,   106,     0,    73,    46,   114,     0,
   115,     0,   114,    11,   115,     0,   116,    31,    98,     0,
    62,     0,     5,   118,     0,     0,     3,     0,   120,   121,
     0,   143,    37,    44,    73,   117,     0,    38,   122,    55,
    60,     0,   123,     0,   122,   123,     0,   143,    62,    31,
    99,    60,     0,   125,     0,   127,     0,    48,    35,    39,
   126,    56,     0,   106,     0,    48,   149,    39,   150,    56,
     0,    50,   147,   129,   130,   134,    60,     0,    10,   140,
    96,    97,     0,   131,   132,    56,     0,    11,    59,    39,
     0,   133,     0,   132,    11,   133,     0,     9,     0,    58,
     0,     6,     0,    36,     0,    49,     0,    53,     0,    41,
     0,    45,     0,     4,     0,    11,   135,   136,    56,     0,
     0,    33,    39,     0,   137,     0,   136,    11,   137,     0,
    29,     0,    12,     0,    54,     0,    64,     0,    65,     0,
   139,     0,     0,   137,     0,   139,   137,     0,   141,     0,
   142,     0,    24,     0,    14,     0,    17,     0,    28,     0,
    23,     0,    25,     0,    20,     0,    26,     0,    21,     0,
    27,     0,    22,     0,    15,     0,    18,     0,    19,     0,
   144,   145,    57,     0,     0,    40,     0,   146,     0,   145,
    11,   146,     0,   147,   148,   138,     0,    62,     0,   133,
     0,    39,   102,    56,     0,    39,    42,    56,     0,   107,
     0,     0,    62,     0,    63,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   269,   272,   273,   278,   282,   283,   284,   291,   301,   304,
   322,   325,   326,   329,   330,   334,   335,   339,   345,   352,
   368,   381,   414,   416,   418,   423,   424,   425,   428,   461,
   466,   481,   484,   513,   524,   536,   538,   540,   541,   544,
   547,   549,   551,   553,   554,   558,   559,   563,   564,   565,
   572,   573,   574,   575,   578,   579,   586,   591,   594,   595,
   596,   597,   598,   601,   602,   603,   604,   605,   609,   610,
   613,   614,   622,   625,   626,   629,   630,   633,   636,   639,
   640,   643,   646,   650,   652,   655,   658,   662,   663,   666,
   677,   681,   688,   692,   693,   697,   712,   713,   716,   723,
   727,   743,   748,   752,   754,   756,   757,   760,   761,   762,
   763,   764,   765,   766,   767,   768,   771,   773,   777,   780,
   781,   785,   786,   787,   788,   789,   792,   793,   796,   797,
   800,   801,   802,   803,   804,   808,   809,   810,   811,   812,
   813,   814,   815,   816,   820,   821,   830,   831,   836,   843,
   844,   847,   854,   861,   871,   876,   880,   884,   890,   893
};

static const char * const yytname[] = {   "$","error","$undefined.","TOK_ALIAS_IDENTIFIER",
"TOK_ANY","TOK_AS","TOK_ASSOCIATION","TOK_BINARY_VALUE","TOK_CHAR_VALUE","TOK_CLASS",
"TOK_COLON","TOK_COMMA","TOK_DISABLEOVERRIDE","TOK_DQUOTE","TOK_DT_BOOL","TOK_DT_CHAR16",
"TOK_DT_CHAR8","TOK_DT_DATETIME","TOK_DT_REAL32","TOK_DT_REAL64","TOK_DT_SINT16",
"TOK_DT_SINT32","TOK_DT_SINT64","TOK_DT_SINT8","TOK_DT_STR","TOK_DT_UINT16",
"TOK_DT_UINT32","TOK_DT_UINT64","TOK_DT_UINT8","TOK_ENABLEOVERRIDE","TOK_END_OF_FILE",
"TOK_EQUAL","TOK_FALSE","TOK_FLAVOR","TOK_HEX_VALUE","TOK_INCLUDE","TOK_INDICATION",
"TOK_INSTANCE","TOK_LEFTCURLYBRACE","TOK_LEFTPAREN","TOK_LEFTSQUAREBRACKET",
"TOK_METHOD","TOK_NULL_VALUE","TOK_OCTAL_VALUE","TOK_OF","TOK_PARAMETER","TOK_PERIOD",
"TOK_POSITIVE_DECIMAL_VALUE","TOK_PRAGMA","TOK_PROPERTY","TOK_QUALIFIER","TOK_REAL_VALUE",
"TOK_REF","TOK_REFERENCE","TOK_RESTRICTED","TOK_RIGHTCURLYBRACE","TOK_RIGHTPAREN",
"TOK_RIGHTSQUAREBRACKET","TOK_SCHEMA","TOK_SCOPE","TOK_SEMICOLON","TOK_SIGNED_DECIMAL_VALUE",
"TOK_SIMPLE_IDENTIFIER","TOK_STRING_VALUE","TOK_TOSUBCLASS","TOK_TRANSLATABLE",
"TOK_TRUE","TOK_UNEXPECTED_CHAR","mofSpec","mofProductions","mofProduction",
"classDeclaration","classHead","className","superClass","classBody","classFeatures",
"classFeature","methodDeclaration","methodHead","methodBody","methodEnd","methodName",
"parameters","parameter","parameterType","propertyDeclaration","propertyBody",
"propertyEnd","referenceDeclaration","referencedObject","referenceName","referencePath",
"objectRef","parameterName","propertyName","array","typedDefaultValue","initializer",
"typedInitializer","constantValues","constantValue","nonNullConstantValue","integerValue",
"booleanValue","stringValues","stringValue","arrayInitializer","referenceInitializer",
"objectHandle","aliasInitializer","namespaceHandleRef","namespaceHandle","modelPath",
"keyValuePairList","keyValuePair","keyValuePairName","alias","aliasIdentifier",
"instanceDeclaration","instanceHead","instanceBody","valueInitializers","valueInitializer",
"compilerDirective","compilerDirectiveInclude","fileName","compilerDirectivePragma",
"qualifierDeclaration","qualifierValue","scope","scope_begin","metaElements",
"metaElement","defaultFlavor","flavorHead","explicitFlavors","explicitFlavor",
"flavor","overrideFlavors","dataType","intDataType","realDataType","qualifierList",
"qualifierListBegin","qualifiers","qualifier","qualifierName","typedQualifierParameter",
"pragmaName","pragmaVal",""
};
#endif

static const short yyr1[] = {     0,
    68,    69,    69,    69,    70,    70,    70,    70,    71,    72,
    73,    74,    74,    75,    75,    76,    76,    77,    77,    77,
    78,    79,    80,    81,    82,    83,    83,    83,    84,    85,
    85,    86,    87,    88,    89,    90,    91,    92,    92,    93,
    94,    95,    96,    96,    96,    97,    97,    98,    98,    98,
    99,    99,    99,    99,   100,   100,   101,   101,   102,   102,
   102,   102,   102,   103,   103,   103,   103,   103,   104,   104,
   105,   105,   106,   107,   107,   108,   108,   109,   110,   111,
   111,   112,   113,   114,   114,   115,   116,   117,   117,   118,
   119,   120,   121,   122,   122,   123,   124,   124,   125,   126,
   127,   128,   129,   130,   131,   132,   132,   133,   133,   133,
   133,   133,   133,   133,   133,   133,   134,   134,   135,   136,
   136,   137,   137,   137,   137,   137,   138,   138,   139,   139,
   140,   140,   140,   140,   140,   141,   141,   141,   141,   141,
   141,   141,   141,   141,   142,   142,   143,   143,   144,   145,
   145,   146,   147,   147,   148,   148,   148,   148,   149,   150
};

static const short yyr2[] = {     0,
     1,     2,     1,     0,     1,     1,     1,     1,     2,     5,
     1,     2,     0,     4,     3,     1,     2,     1,     1,     1,
     4,     2,     3,     1,     1,     1,     3,     0,     4,     1,
     1,     3,     4,     1,     6,     1,     1,     2,     0,     2,
     1,     1,     3,     2,     0,     2,     0,     1,     1,     1,
     1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     2,     1,     3,     2,     1,     1,     4,     1,     2,
     0,     1,     3,     1,     3,     3,     1,     2,     0,     1,
     2,     5,     4,     1,     2,     5,     1,     1,     5,     1,
     5,     6,     4,     3,     3,     1,     3,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     4,     0,     2,     1,
     3,     1,     1,     1,     1,     1,     1,     0,     1,     2,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     3,     0,     1,     1,
     3,     3,     1,     1,     3,     3,     1,     0,     1,     1
};

static const short yydefact[] = {     0,
     3,   149,     0,     0,     1,     0,     7,     0,     8,     0,
     5,    97,    98,     6,     0,     0,     0,   159,     0,   116,
   110,   108,   111,   114,   115,   112,   113,   109,   153,   154,
     0,     2,   148,     9,   148,    91,     0,     0,     0,   150,
   158,     0,     0,     0,     0,     0,   148,    16,    19,    18,
    20,     0,   148,    94,     0,    11,    89,     0,     0,   147,
     0,     0,   157,   128,    73,   100,     0,   160,     0,   134,
   144,   135,   145,   146,   139,   141,   143,   137,   133,   138,
   140,   142,   136,    45,   131,   132,     0,   118,     0,    15,
     0,    17,    36,     0,     0,     0,     0,     0,    95,     0,
     0,    13,    89,   151,    67,    61,    69,    66,    58,    65,
    64,    60,    75,    68,    70,     0,    55,    57,    59,    63,
    62,    71,     0,     0,   123,   122,   124,   125,   126,   129,
   152,   127,    99,   101,     0,    47,     0,     0,     0,     0,
   106,    14,   148,     0,    34,    32,     0,    42,    22,    45,
    93,     0,    90,    88,     0,    10,    92,     0,    74,    72,
   156,   155,   130,     0,    44,     0,   103,   105,     0,     0,
   102,     0,   104,     0,    26,     0,    24,    21,    37,    39,
    47,    81,    52,     0,    51,    53,    54,    76,    77,    79,
    12,    56,    43,    46,   119,     0,   120,   107,   148,    23,
     0,     0,    31,    30,     0,     0,    33,    82,     0,     0,
    96,     0,   117,    27,    40,    41,    45,    38,    35,     0,
     0,    80,   121,    29,     0,    78,    87,    83,    84,     0,
     0,     0,    85,    86,    48,    49,    50,     0,     0,     0
};

static const short yydefgoto[] = {   238,
     5,     6,     7,     8,    57,   156,    34,    47,    48,    49,
    94,   144,   178,   149,   174,   175,   202,    50,    95,   146,
    51,    96,   180,   206,   203,   217,   150,   136,   167,   234,
   184,   116,   117,   118,   119,   120,   121,   122,   186,   187,
   188,   189,   209,   210,   221,   228,   229,   230,   102,   190,
     9,    10,    36,    53,    54,    11,    12,    67,    13,    14,
    45,    88,    89,   140,    30,   139,   170,   196,   130,   131,
   132,    84,    85,    86,    15,    16,    39,    40,    41,    64,
    19,    69
};

static const short yypact[] = {    18,
-32768,-32768,   -22,   169,-32768,    18,-32768,    -9,-32768,    -2,
-32768,-32768,-32768,-32768,    11,   169,   -11,-32768,    -6,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    27,-32768,   -10,-32768,    13,-32768,   -13,    10,     0,-32768,
   -14,    -1,    22,   245,    50,    26,    -5,-32768,-32768,-32768,
-32768,   215,    44,-32768,    25,-32768,    84,   -13,   169,-32768,
    72,   105,-32768,    95,-32768,-32768,    35,-32768,    39,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,    58,-32768,-32768,    41,    91,   170,-32768,
    43,-32768,-32768,    66,    48,    64,    55,    60,-32768,    87,
   118,   115,    84,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,    12,-32768,-32768,-32768,-32768,
    -1,-32768,    70,    74,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,    95,-32768,-32768,   -15,    97,    92,    99,    76,     3,
-32768,-32768,    53,    80,-32768,-32768,    79,   104,-32768,    58,
-32768,     9,-32768,-32768,   -13,-32768,-32768,   138,-32768,-32768,
-32768,-32768,-32768,    77,-32768,     9,-32768,-32768,   111,    95,
-32768,   170,-32768,    15,-32768,   230,-32768,-32768,-32768,   113,
    97,    -1,-32768,    93,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,    20,-32768,-32768,    13,-32768,
   102,    89,-32768,-32768,    -1,    98,-32768,-32768,   -13,   147,
-32768,    95,-32768,-32768,-32768,-32768,    58,-32768,-32768,   116,
   148,-32768,-32768,-32768,   101,-32768,-32768,   153,-32768,   146,
   101,    31,-32768,-32768,-32768,-32768,-32768,   182,   183,-32768
};

static const short yypgoto[] = {-32768,
   163,-32768,-32768,-32768,   -54,-32768,-32768,-32768,   137,-32768,
-32768,-32768,-32768,-32768,-32768,   -12,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,  -140,     5,-32768,
    24,-32768,  -149,   -56,-32768,-32768,-32768,   -40,   -41,   -44,
-32768,-32768,-32768,-32768,-32768,-32768,   -39,-32768,    90,    94,
-32768,-32768,-32768,-32768,   141,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,   -82,-32768,-32768,-32768,  -124,-32768,
-32768,   -47,-32768,-32768,   -32,-32768,-32768,   139,   192,-32768,
-32768,-32768
};


#define	YYLAST		292


static const short yytable[] = {    63,
    52,    66,    55,   103,    97,   124,   141,   163,   192,   181,
    59,   153,    17,   172,    52,   105,   106,    -4,     1,    37,
    55,   182,   158,    61,    62,   199,  -148,    42,    33,     2,
   212,   164,    43,   153,     2,    35,    44,   105,   106,    18,
   107,   165,   108,   182,    46,   197,    61,    38,    56,    91,
   183,   110,     2,    58,  -148,   111,    60,     2,   173,   112,
    87,    65,   107,   -28,   108,     3,   159,     4,    61,   114,
   200,    65,   109,   110,   115,   213,   224,   111,   105,   106,
   160,   112,   235,     2,    68,    90,   100,   223,   101,   198,
   133,   114,     2,    65,   134,   185,   115,   135,    98,   137,
   191,   138,   142,   107,   143,   108,   125,   145,   -28,   185,
   176,   105,   106,   109,   110,   147,   148,   152,   111,   151,
   153,   201,   112,   126,   155,   161,   113,   166,   204,   162,
   168,   169,   114,   193,    65,   171,   107,   115,   108,   177,
   179,   208,   -25,   205,   105,   106,   123,   110,   127,   195,
   216,   111,   211,   215,   220,   112,   222,   219,   128,   129,
   226,   225,   227,   231,   218,   114,   176,    65,    32,   107,
   115,   108,    20,    20,    21,    21,   232,    22,    22,   109,
   110,   239,   240,    92,   111,   207,   214,   237,   112,   194,
   236,   233,   157,    99,   154,    31,     0,   104,   114,     0,
    65,     0,     0,   115,    23,    23,     0,     0,     0,    24,
    24,     0,     0,    25,    25,     0,     0,    26,    26,     0,
     0,    27,    27,     0,     0,     0,    28,    28,    70,    71,
    29,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,    70,    71,     0,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    70,    71,
     0,    72,    73,    74,    75,    76,    77,    78,    79,    80,
    81,    82,    83,     0,     0,     0,    93,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    56
};

static const short yycheck[] = {    41,
    33,    42,    35,    58,    52,    62,    89,   132,   158,   150,
    11,     3,    35,    11,    47,     7,     8,     0,     1,     9,
    53,    13,    11,    38,    39,    11,     9,    39,    38,    40,
    11,    47,    39,     3,    40,    38,    10,     7,     8,    62,
    32,    57,    34,    13,    55,   170,    38,    37,    62,    55,
    42,    43,    40,    44,    37,    47,    57,    40,    56,    51,
    11,    63,    32,    11,    34,    48,    55,    50,    38,    61,
    56,    63,    42,    43,    66,    56,   217,    47,     7,     8,
   121,    51,   232,    40,    63,    60,    62,   212,     5,   172,
    56,    61,    40,    63,    56,   152,    66,    40,    55,    59,
   155,    11,    60,    32,    39,    34,    12,    60,    56,   166,
   143,     7,     8,    42,    43,    52,    62,    31,    47,    60,
     3,   176,    51,    29,    10,    56,    55,    31,   176,    56,
    39,    33,    61,    57,    63,    60,    32,    66,    34,    60,
    62,   182,    39,    31,     7,     8,    42,    43,    54,    39,
    62,    47,    60,    52,   209,    51,    10,    60,    64,    65,
    13,    46,    62,    11,   205,    61,   199,    63,     6,    32,
    66,    34,     4,     4,     6,     6,    31,     9,     9,    42,
    43,     0,     0,    47,    47,   181,   199,   232,    51,   166,
   232,   231,   103,    53,   101,     4,    -1,    59,    61,    -1,
    63,    -1,    -1,    66,    36,    36,    -1,    -1,    -1,    41,
    41,    -1,    -1,    45,    45,    -1,    -1,    49,    49,    -1,
    -1,    53,    53,    -1,    -1,    -1,    58,    58,    14,    15,
    62,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    14,    15,    -1,    17,    18,    19,    20,
    21,    22,    23,    24,    25,    26,    27,    28,    14,    15,
    -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    -1,    -1,    -1,    62,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    62
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"
/* This file comes from bison-@bison_version@.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 3:
#line 274 "cimmof.y"
{ 
			  		yyerror ("Unrecognized mof production. Aborting ...\n");
					return -1;
				;
    break;}
case 5:
#line 282 "cimmof.y"
{ ;
    break;}
case 6:
#line 283 "cimmof.y"
{ ;
    break;}
case 7:
#line 285 "cimmof.y"
{ 
					yyvsp[0].cimclass->addIncludeRef (g_include_ref);
					g_classes.push_back (*yyvsp[0].cimclass);
					delete yyvsp[0].cimclass;
					g_cur_class = 0;
        		;
    break;}
case 8:
#line 291 "cimmof.y"
{ ;
    break;}
case 9:
#line 301 "cimmof.y"
{ yyval.cimclass = yyvsp[-1].cimclass; ;
    break;}
case 10:
#line 305 "cimmof.y"
{
	yyval.cimclass = new CCIMClass (*yyvsp[-2].strval, *yyvsp[0].strval);

	if (isQualifierPresent ("association")) { yyval.cimclass->setAssociation (); }
	yyval.cimclass->addDesc (getQualifierValueString ("description"));
	yyval.cimclass->setUMLPkgPath (getQualifierValueString ("UMLPackagePath"));	

	if (0 != g_cur_class) { delete g_cur_class; }
	g_cur_class = yyval.cimclass;	
	g_include_ref.clear ();

    delete yyvsp[-2].strval;
    delete yyvsp[-1].strval;
    delete yyvsp[0].strval;
;
    break;}
case 11:
#line 322 "cimmof.y"
{;
    break;}
case 12:
#line 325 "cimmof.y"
{ yyval.strval = yyvsp[0].strval; ;
    break;}
case 13:
#line 326 "cimmof.y"
{ yyval.strval = new string (""); ;
    break;}
case 18:
#line 340 "cimmof.y"
{
        			YACCTRACE("classFeature:applyProperty");
					g_cur_class->addProperty (*yyvsp[0].cimproperty);
					delete yyvsp[0].cimproperty;
    		   ;
    break;}
case 19:
#line 346 "cimmof.y"
{
        			YACCTRACE("classFeature:applyMethod");
					g_cur_class->addMethod (*yyvsp[0].cimmethod);
					delete yyvsp[0].cimmethod;
					g_cur_method = 0;
    		   ;
    break;}
case 20:
#line 353 "cimmof.y"
{
        			YACCTRACE("classFeature:applyProperty");
			   		g_cur_class->addReference (*yyvsp[0].cimreference);
					delete yyvsp[0].cimreference;
    		   ;
    break;}
case 21:
#line 369 "cimmof.y"
{
    					YACCTRACE("methodDeclaration");
    					yyval.cimmethod = yyvsp[-2].cimmethod;

						for (unsigned int i = 0; i < g_parameter_list.size (); i++)
						{
							yyval.cimmethod->addParameter (g_parameter_list [i]);
						}

					;
    break;}
case 22:
#line 382 "cimmof.y"
{
    			YACCTRACE("methodHead");
				if (0 != g_cur_method) { delete g_cur_method; }
				g_cur_method = new CCIMMethod (*yyvsp[-1].strval, *yyvsp[0].strval);

				yyval.cimmethod = g_cur_method;

				yyval.cimmethod->addDesc (getQualifierValueString ("description"));
				
				if (isQualifierPresent ("ValueMap") && 
				    isQualifierPresent ("Values"))
				{
					vector<string> value = getQualifierValueArray ("ValueMap");
					vector<string> desc  = getQualifierValueArray ("Values");

					if (value.size () == desc.size ()) 
					{
						for (int i = 0; i != value.size (); i++)
						{
							yyval.cimmethod->addReturnCodeValueMap (value [i], desc [i]);
						}
					}
				}


				delete yyvsp[-1].strval;
				delete yyvsp[0].strval;

				g_parameter_list.clear ();
		     ;
    break;}
case 25:
#line 418 "cimmof.y"
{ ;
    break;}
case 26:
#line 423 "cimmof.y"
{ ;
    break;}
case 27:
#line 424 "cimmof.y"
{ ;
    break;}
case 29:
#line 429 "cimmof.y"
{
				CCIMParameter param ("", "", false);
				if (yyvsp[0].val == -1) { param = CCIMParameter (*yyvsp[-2].strval, *yyvsp[-1].strval, false); }
				else		  { param = CCIMParameter (*yyvsp[-2].strval, *yyvsp[-1].strval, true);  }

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

				delete yyvsp[-2].strval;
				delete yyvsp[-1].strval;

				g_parameter_list.push_back (param);
			;
    break;}
case 30:
#line 462 "cimmof.y"
{ 
					yyval.strval = yyvsp[0].strval; 
					g_is_param_ref = false; 
				;
    break;}
case 31:
#line 467 "cimmof.y"
{
			  		g_include_ref.push_back (*yyvsp[0].strval);
              		yyval.strval = yyvsp[0].strval; 
              		g_is_param_ref = true;
				;
    break;}
case 32:
#line 481 "cimmof.y"
{ yyval.cimproperty = yyvsp[-1].cimproperty; ;
    break;}
case 33:
#line 485 "cimmof.y"
{
			   		if (yyvsp[-1].val == -1) { yyval.cimproperty = new CCIMProperty (*yyvsp[-3].strval, *yyvsp[-2].strval, false); }
					else		  { yyval.cimproperty = new CCIMProperty (*yyvsp[-3].strval, *yyvsp[-2].strval, true);  }

					yyval.cimproperty->addDesc (getQualifierValueString ("description"));
					if (isQualifierPresent ("ValueMap") && 
					    isQualifierPresent ("Values"))
					{
						vector<string> value = getQualifierValueArray ("ValueMap");
						vector<string> desc  = getQualifierValueArray ("Values");

						if (value.size () == desc.size ()) 
						{
							for (int i = 0; i != value.size (); i++)
							{
								yyval.cimproperty->addValueMap (value [i], desc [i]);
							}
						}
					}

					if (isQualifierPresent ("write")) { yyval.cimproperty->setWriteable (); }
					if (isQualifierPresent ("key"))   { yyval.cimproperty->setAsKey (); 	 }
		
					delete yyvsp[-3].strval;
					delete yyvsp[-2].strval;
			   ;
    break;}
case 35:
#line 526 "cimmof.y"
{
					   	yyval.cimreference = new CCIMReference (*yyvsp[-4].strval, *yyvsp[-2].strval);

						yyval.cimreference->addDesc (getQualifierValueString ("description"));
						
						delete yyvsp[-4].strval;
						delete yyvsp[-2].strval;
					   ;
    break;}
case 36:
#line 536 "cimmof.y"
{;
    break;}
case 37:
#line 538 "cimmof.y"
{;
    break;}
case 38:
#line 540 "cimmof.y"
{ delete yyvsp[0].strval; ;
    break;}
case 39:
#line 541 "cimmof.y"
{ ;
    break;}
case 40:
#line 544 "cimmof.y"
{ yyval.strval = yyvsp[-1].strval; ;
    break;}
case 41:
#line 547 "cimmof.y"
{;
    break;}
case 42:
#line 549 "cimmof.y"
{;
    break;}
case 43:
#line 552 "cimmof.y"
{ yyval.val = 1; ;
    break;}
case 44:
#line 553 "cimmof.y"
{ yyval.val = 0; ;
    break;}
case 45:
#line 554 "cimmof.y"
{ yyval.val = -1; ;
    break;}
case 46:
#line 558 "cimmof.y"
{ ;
    break;}
case 47:
#line 559 "cimmof.y"
{;
    break;}
case 48:
#line 563 "cimmof.y"
{ ;
    break;}
case 49:
#line 564 "cimmof.y"
{;
    break;}
case 50:
#line 565 "cimmof.y"
{;
    break;}
case 51:
#line 572 "cimmof.y"
{ delete yyvsp[0].strval; ;
    break;}
case 52:
#line 573 "cimmof.y"
{;
    break;}
case 53:
#line 574 "cimmof.y"
{;
    break;}
case 54:
#line 575 "cimmof.y"
{;
    break;}
case 55:
#line 578 "cimmof.y"
{;
    break;}
case 56:
#line 579 "cimmof.y"
{;
    break;}
case 57:
#line 587 "cimmof.y"
{	
					g_array_value.push_back (*yyvsp[0].strval); 
				  	delete yyvsp[0].strval; 
				;
    break;}
case 58:
#line 591 "cimmof.y"
{ ;
    break;}
case 59:
#line 594 "cimmof.y"
{ ;
    break;}
case 60:
#line 595 "cimmof.y"
{ ;
    break;}
case 61:
#line 596 "cimmof.y"
{ ;
    break;}
case 62:
#line 597 "cimmof.y"
{ ;
    break;}
case 63:
#line 598 "cimmof.y"
{ ;
    break;}
case 69:
#line 609 "cimmof.y"
{;
    break;}
case 70:
#line 610 "cimmof.y"
{;
    break;}
case 71:
#line 613 "cimmof.y"
{ ;
    break;}
case 72:
#line 615 "cimmof.y"
{
			   	yyval.strval = new string (*yyvsp[-1].strval + *yyvsp[0].strval);
			   	delete yyvsp[-1].strval;
			   	delete yyvsp[0].strval;
			   ;
    break;}
case 73:
#line 622 "cimmof.y"
{;
    break;}
case 74:
#line 625 "cimmof.y"
{;
    break;}
case 75:
#line 626 "cimmof.y"
{;
    break;}
case 76:
#line 629 "cimmof.y"
{;
    break;}
case 77:
#line 630 "cimmof.y"
{;
    break;}
case 78:
#line 633 "cimmof.y"
{;
    break;}
case 79:
#line 636 "cimmof.y"
{ delete yyvsp[0].strval; ;
    break;}
case 80:
#line 639 "cimmof.y"
{;
    break;}
case 81:
#line 640 "cimmof.y"
{;
    break;}
case 82:
#line 643 "cimmof.y"
{ delete yyvsp[0].strval; ;
    break;}
case 83:
#line 647 "cimmof.y"
{	delete yyvsp[-2].strval; ;
    break;}
case 84:
#line 650 "cimmof.y"
{;
    break;}
case 85:
#line 652 "cimmof.y"
{;
    break;}
case 86:
#line 655 "cimmof.y"
{;
    break;}
case 87:
#line 659 "cimmof.y"
{ delete yyvsp[0].strval; ;
    break;}
case 88:
#line 662 "cimmof.y"
{ yyval.strval = yyvsp[0].strval; ;
    break;}
case 89:
#line 663 "cimmof.y"
{ yyval.strval = new string (""); ;
    break;}
case 91:
#line 677 "cimmof.y"
{;
    break;}
case 92:
#line 682 "cimmof.y"
{
			   	delete yyvsp[-1].strval;
				delete yyvsp[0].strval;
			   ;
    break;}
case 96:
#line 699 "cimmof.y"
{
				   	delete yyvsp[-3].strval;
				   ;
    break;}
case 97:
#line 712 "cimmof.y"
{;
    break;}
case 98:
#line 713 "cimmof.y"
{;
    break;}
case 99:
#line 718 "cimmof.y"
{
						   	delete yyvsp[-1].strval;
    					   ;
    break;}
case 100:
#line 723 "cimmof.y"
{;
    break;}
case 101:
#line 729 "cimmof.y"
{
						  	delete yyvsp[-3].strval;
							delete yyvsp[-1].strval;
						  ;
    break;}
case 102:
#line 745 "cimmof.y"
{ delete yyvsp[-4].strval; ;
    break;}
case 103:
#line 749 "cimmof.y"
{ delete yyvsp[-2].strval; ;
    break;}
case 104:
#line 752 "cimmof.y"
{;
    break;}
case 105:
#line 754 "cimmof.y"
{;
    break;}
case 106:
#line 756 "cimmof.y"
{ delete yyvsp[0].strval; ;
    break;}
case 107:
#line 757 "cimmof.y"
{ delete yyvsp[0].strval; ;
    break;}
case 108:
#line 760 "cimmof.y"
{ yyval.strval = new string ("class");        ;
    break;}
case 109:
#line 761 "cimmof.y"
{ yyval.strval = new string ("schema"); 		 ;
    break;}
case 110:
#line 762 "cimmof.y"
{ yyval.strval = new string ("association");  ;
    break;}
case 111:
#line 763 "cimmof.y"
{ yyval.strval = new string ("indication");   ;
    break;}
case 112:
#line 764 "cimmof.y"
{ yyval.strval = new string ("property");     ;
    break;}
case 113:
#line 765 "cimmof.y"
{ yyval.strval = new string ("reference");    ;
    break;}
case 114:
#line 766 "cimmof.y"
{ yyval.strval = new string ("method");       ;
    break;}
case 115:
#line 767 "cimmof.y"
{ yyval.strval = new string ("parameter");    ;
    break;}
case 116:
#line 768 "cimmof.y"
{ yyval.strval = new string ("any");          ;
    break;}
case 117:
#line 772 "cimmof.y"
{ ;
    break;}
case 118:
#line 773 "cimmof.y"
{ ;
    break;}
case 119:
#line 777 "cimmof.y"
{ g_flavor.clear (); ;
    break;}
case 122:
#line 785 "cimmof.y"
{ g_flavor.push_back ("enableoverride"); ;
    break;}
case 123:
#line 786 "cimmof.y"
{ g_flavor.push_back ("disableoverride");;
    break;}
case 124:
#line 787 "cimmof.y"
{ g_flavor.push_back ("restricted");     ;
    break;}
case 125:
#line 788 "cimmof.y"
{ g_flavor.push_back ("tosubclass");	 ;
    break;}
case 126:
#line 789 "cimmof.y"
{ g_flavor.push_back ("translatable");	 ;
    break;}
case 127:
#line 792 "cimmof.y"
{ ;
    break;}
case 128:
#line 793 "cimmof.y"
{;
    break;}
case 131:
#line 800 "cimmof.y"
{ yyval.strval = yyvsp[0].strval; ;
    break;}
case 132:
#line 801 "cimmof.y"
{ yyval.strval = yyvsp[0].strval; ;
    break;}
case 133:
#line 802 "cimmof.y"
{ yyval.strval = new string ("string");   ;
    break;}
case 134:
#line 803 "cimmof.y"
{ yyval.strval = new string ("boolean");  ;
    break;}
case 135:
#line 804 "cimmof.y"
{ yyval.strval = new string ("datetime"); ;
    break;}
case 136:
#line 808 "cimmof.y"
{ yyval.strval = new string ("uint8");  ;
    break;}
case 137:
#line 809 "cimmof.y"
{ yyval.strval = new string ("sint8");  ;
    break;}
case 138:
#line 810 "cimmof.y"
{ yyval.strval = new string ("uint16"); ;
    break;}
case 139:
#line 811 "cimmof.y"
{ yyval.strval = new string ("sint16"); ;
    break;}
case 140:
#line 812 "cimmof.y"
{ yyval.strval = new string ("uint32"); ;
    break;}
case 141:
#line 813 "cimmof.y"
{ yyval.strval = new string ("sint32"); ;
    break;}
case 142:
#line 814 "cimmof.y"
{ yyval.strval = new string ("uint64"); ;
    break;}
case 143:
#line 815 "cimmof.y"
{ yyval.strval = new string ("sint64"); ;
    break;}
case 144:
#line 816 "cimmof.y"
{ yyval.strval = new string ("char16"); ;
    break;}
case 145:
#line 820 "cimmof.y"
{ yyval.strval = new string ("real32"); ;
    break;}
case 146:
#line 821 "cimmof.y"
{ yyval.strval = new string ("real64"); ;
    break;}
case 147:
#line 830 "cimmof.y"
{;
    break;}
case 148:
#line 832 "cimmof.y"
{
					g_qualifier_list.clear ();
        		;
    break;}
case 149:
#line 837 "cimmof.y"
{
    			  		YACCTRACE ("qualifierListbegin");
				  		g_qualifier_list.clear (); 
			      	;
    break;}
case 150:
#line 843 "cimmof.y"
{ ;
    break;}
case 151:
#line 844 "cimmof.y"
{ ;
    break;}
case 152:
#line 848 "cimmof.y"
{
				g_qualifier_list.insert (std::pair<string, CCIMQualifierValue> (*yyvsp[-2].strval, g_qualifier_value));
				delete yyvsp[-2].strval;
		  	;
    break;}
case 153:
#line 855 "cimmof.y"
{ 
					g_flavor.clear (); 
					g_qualifier_value = CCIMQualifierValue ();
					g_array_value.clear ();
					yyval.strval = yyvsp[0].strval;
				;
    break;}
case 154:
#line 862 "cimmof.y"
{ 
			  		g_flavor.clear ();  
					g_qualifier_value = CCIMQualifierValue ();
					g_array_value.clear ();
					yyval.strval = yyvsp[0].strval;
			  	;
    break;}
case 155:
#line 872 "cimmof.y"
{
						  	g_qualifier_value.setValue (*yyvsp[-1].strval);
							delete yyvsp[-1].strval;
						  ;
    break;}
case 156:
#line 877 "cimmof.y"
{
						  	g_qualifier_value.setValue ("");
						  ;
    break;}
case 157:
#line 881 "cimmof.y"
{ 
							g_qualifier_value.setValue (g_array_value);
    					;
    break;}
case 158:
#line 885 "cimmof.y"
{ 
							g_qualifier_value.setValue ("");
    					;
    break;}
case 159:
#line 890 "cimmof.y"
{;
    break;}
case 160:
#line 893 "cimmof.y"
{;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 895 "cimmof.y"


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
