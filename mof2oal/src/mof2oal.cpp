/*
 * <AMD 3BSD notice header>
 *
 * Copyright (c) 2006, 2007, 2008 Advanced Micro Devices, Inc.
 *
 * All rights reserved.
 *
 * This file is subject to the license found in the LICENSE.AMD file which
 * states the following in part:
 *
 * Redistribution and use in any form of this material and any product
 * thereof including software in source or binary forms, along with any
 * related documentation, with or without modification ("this material"),
 * is permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code of any software must retain the above
 *     copyright notice and all terms of this license as part of the code.
 *
 *   * Redistributions in binary form of any software must reproduce the
 *     above copyright notice and all terms of this license in any related
 *     documentation and/or other materials. 
 *
 *   * Neither the names nor trademarks of Advanced Micro Devices, Inc.
 *     or any copyright holders or contributors may be used to endorse or
 *     promote products derived from this material without specific prior
 *     written permission.
 */

#include "cimmethod.h"
#include "cimproperty.h"
#include "cimparameter.h"
#include "cimclass.h"
#include "cimmof_tab.h"
#include "skeleton.h"
#include "util.h"
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#ifdef _WIN32
#include <windows.h>
#else
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <fnmatch.h>
#endif

#ifdef _WIN32
#define FILE_MAX _MAX_PATH
#else
#define FILE_MAX PATH_MAX
#endif 

using std::vector;
using std::string;

extern int yyparse ();
extern FILE* yyin;

extern vector<CCIMClass>	g_classes;
vector<string>			g_vclassesblacklist;
string				g_filename;
vector<string>			g_vfilename;
string g_skeldir  = "./";
string g_outdir   = "./";
string g_moffile  = "";
string g_mofdir  = "";
string g_keyfile  = "";
string g_cimfactoryfile = "";
string g_blacklistfile = "";
string g_wrapper_dll_name = "PP.dll";

bool g_genurifile  = false;
bool g_oalcs = false;
bool g_oaldll = false;
bool g_debug = false;
bool g_allproperty_writeable = false;

CSkeleton* CSkeleton::_instance = 0;
int parse_mof_file(string file);
int read_blacklisted_classes();
int generate_cim_factory();

bool contains(vector<string>* haystack, const char* needle);

int main (int argc, char* argv[])
{
    if ((argc < 2))
    { 
	printf ("mof2oal\n");
	printf ("Copyright (c) 2008 Raritan Inc. \n");
	printf ("Usage: mof2oal [-oaldll  || -oalcs] -s code_skeleton_dir -m mof_dir -o output_dir [-d] [-w] [-cf cimfactory file] [-b class blacklist]\n");
	return -1; 
    }

    int ix; 
    for (ix = 1; ix < argc; ix++)
    {
	if (0 == strcmp (argv [ix], "-o"))
	{
	    ix++;
	    if (ix >= argc)
	    {
		fprintf (stderr, "ERROR: Out directory not specified\n");
		return -1;
	    }

	    g_outdir = string (argv [ix]) + "/";
	}
	else if (0 == strcmp (argv [ix], "-s"))
	{
	    ix++;
	    if (ix >= argc)
	    {
		fprintf (stderr, "ERROR: Skeleton directory not specified\n");
		return -1;
	    }

	    g_skeldir = string (argv [ix]) + "/";
	}
	else if (0 == strcmp (argv [ix], "-m"))
	{
	    ix++;
	    if (ix >= argc)
	    {
		fprintf (stderr, "ERROR: MOF file not specified\n");
		return -1;
	    }
	    string p = string (argv [ix]);
	    int pos;
	    while ((pos = p.find("\\")) != -1) {
		p.replace(pos, 1, "/");
	    }
	    int last_slash = p.rfind('/');
	    if (last_slash == -1) {
		/* no slash found... assume just the filename is given */
		g_moffile = p;
		g_mofdir = "";
	    } else {
		g_mofdir = p.substr(0, last_slash + 1);
		g_moffile = p.substr(last_slash + 1, p.length() - last_slash);
	    }
	}
	else if (0 == strcmp (argv [ix], "-d"))
	{
	    g_debug = true;
	}
	else if (0 == strcmp (argv [ix], "-oaldll"))
	{
	    g_oaldll = true;
	    if (g_skeldir == "./") {
		g_skeldir = string("../skel/mof2oaldll/");
	    }
	}
	else if (0 == strcmp (argv [ix], "-oalcs"))
	{
	    g_oalcs = true;
	    if (g_skeldir == "./") {
		g_skeldir = string("../skel/mof2oalcs/");
	    }
	}
	else if (0 == strcmp (argv [ix], "-u"))
	{
	    g_genurifile = true;
	}
	else if (0 == strcmp (argv [ix], "-w"))
	{
	    g_allproperty_writeable = true;
	}
	else if (0 == strcmp (argv [ix], "-cf")) {
	    ix++;
	    if (ix >= argc)
	    {
		fprintf (stderr, "ERROR: cimfactory file not specified\n");
		return -1;
	    }
	    g_cimfactoryfile = string(argv [ix]);
	}
	else if (0 == strcmp (argv [ix], "-b")) {
	    ix++;
	    if (ix >= argc)
	    {
		fprintf (stderr, "ERROR: blacklist file not specified\n");
		return -1;
	    }
	    g_blacklistfile = string(argv [ix]);
	}
	else { break; }
    }

    printf("Using mof file '%s%s'\n", g_mofdir.c_str(), g_moffile.c_str());

    if (g_blacklistfile != "") {
	fprintf (stdout, "Reading blacklist...");
	read_blacklisted_classes();
	fprintf (stdout, "done\n");
    }

    if (parse_mof_file(g_mofdir + g_moffile))
	return -1;

    /* There needs to be at least on file as input */
    if (g_vfilename.size () == 0) 
    {
	fprintf (stderr, "ERROR: No input mof file specified (%s%s)\n", g_mofdir.c_str(), g_moffile.c_str());
	return -1;
    }

    printf("Checking for duplicates...");

    std::sort( g_vfilename.begin(), g_vfilename.end() );
    std::vector<std::string>::iterator new_end_pos;
    new_end_pos = std::unique( g_vfilename.begin(), g_vfilename.end() );
    g_vfilename.erase( new_end_pos, g_vfilename.end() );

    printf("done\nParsing...");
    for (unsigned int i = 0; i < g_vfilename.size (); i++)
    {
	if (g_debug) {
	    fprintf (stdout, "Parsing %s ... ", g_vfilename [i].c_str ());
	} else {
	    fprintf(stdout, ".");
	    if ((i % 64) == 0) 
		fprintf(stdout, "\n");
	    fflush(stdout);
	}

	g_filename = g_vfilename [i];
	FILE* fip = fopen (g_vfilename [i].c_str (),  "r");
	if (NULL == fip) 
	{
	    fprintf (stderr, "Failed - Unable to open %s\n", g_vfilename [i].c_str ());
	    return -1;
	}

	yyin = fip;
	if (-1 == yyparse ())
	{
	    fclose (fip);
	    return -1;
	}
	fclose (fip);
	if (g_debug)
	    fprintf (stdout, "done\n");
    }
    if (!g_debug)
	fprintf (stdout, "done\n");

    if (g_cimfactoryfile != "") {
	fprintf (stdout, "Writing cim factory... (%s)", g_cimfactoryfile.c_str());
	generate_cim_factory();
	fprintf (stdout, "done\n");
    }

    if (g_oaldll) {
	FILE* gfop = fopen ((g_outdir + "OALDLL.h").c_str (), "wb");
	fclose (gfop);
    }

    ::loadSkeletonFiles ();

    printf("Writing...");
    string class_code;
    for (unsigned int i = 0; i != g_classes.size (); i++)
    {
	CCIMClass c = g_classes [i];
	class_code  = c.generateCode ();

	string code = CSkeleton::instance ()->getContent ("FILE");
	code = ::replaceStr (code, "%CLASSCODE%", class_code);
	code = ::replaceStr (code, "%FILENAME%", argv [1]);
	code = ::fixCRLF (code);

	string prefix = "";
	string fileext = ".h";
	if (g_oalcs) {
	    prefix = "OALCS_";
	    fileext = ".cs";
	} else if (g_oaldll) {
	    prefix = "OALDLL_";
	}
	string out_file = prefix + c.getName () + fileext;
	if (g_debug) {
	    fprintf (stdout, "Writing %s ... ", out_file.c_str ());
	} else {
	    fprintf(stdout, ".");
	    if ((i % 64) == 0) 
		fprintf(stdout, "\n");
	    fflush(stdout);
	}

	bool needWrite = true;

	// see whether we need to write the file (compare it to the current content)
	FILE* fop = fopen ((g_outdir + out_file).c_str (), "rb");
	if (fop != NULL) {
	    if (fseek(fop, 0, SEEK_END) == 0) {
		long size = ftell(fop);
		// only worth looking further if the size matches
		if (size == code.size()) {
		    if (fseek(fop, 0, SEEK_SET) == 0) {
			char *oldContent = new char[size];
			if (oldContent) {
			    size_t ret;
			    if ((ret = fread(oldContent, 1, size, fop)) == size) {
				if (memcmp(oldContent, code.c_str(), size) == 0) {
				    // the file to write is equal, so no need to write it again
				    needWrite = false;
				}
			    } else {
				fprintf(stderr, "Cannot read file\n");
			    }
			    delete[] oldContent;
			} else {
			    fprintf(stderr, "Cannot allcoate memory\n");
			}
		    } else {
			fprintf(stderr, "Cannot seek file!\n");
		    }
		}
	    } else {
		fprintf(stderr, "Cannot seek file!\n");
	    }
	    fclose(fop);
	}

	if (needWrite) {
	    fop = fopen ((g_outdir + out_file).c_str (), "wb");
	    if (NULL == fop)
	    {
		fprintf (stderr, "\nERROR: Unable to write to %s\n", (g_outdir + out_file).c_str ());
		continue;
	    }
	    fwrite (code.c_str (), 1, code.size (), fop);
	    fclose (fop);
	}

	if (g_oaldll) {
	    string incl_file = "#include <OALDLL_" + c.getName () + ".h>\n";
	    incl_file = ::fixCRLF (incl_file);
	    FILE* gfop = fopen ((g_outdir + "OALDLL.h").c_str (), "a+b");
	    fseek(gfop,0,SEEK_END);
	    fputs(incl_file.c_str(), gfop);
	    fclose (gfop);
	}

	if (g_debug)
	    fprintf (stdout, "done\n");
    }

    if (!g_debug)
	fprintf (stdout, "done\n");

    return 0;
}

int parse_mof_file(string file) {
    std::fstream fip(file.c_str(), std::ios::in);
    if (NULL == fip) 
    {
	fprintf (stderr, "Failed - Unable to open %s\n", file.c_str());
	return -1;
    }
    std::string line;
    while (std::getline(fip, line)) {
	if (line.find("#pragma include") != string::npos) {
	    size_t first_quote = line.find("\"");
	    size_t second_quote = line.rfind("\"");
	    if (first_quote != string::npos &&
		first_quote != second_quote) {
		    string r = line.substr(first_quote+1, second_quote - first_quote - 1);
		    string f = r;
		    size_t last_slash = r.rfind("/");
		    if (r.find("CIM_") != string::npos || r.find("DRI_") != string::npos) {
			if (last_slash != string::npos) f = r.substr(last_slash + 1, r.length() - last_slash - 5);
			if (contains(&g_vclassesblacklist, f.c_str())) continue;
			g_vfilename.push_back(g_mofdir + r);
		    } else {
			parse_mof_file(g_mofdir + r);
		    }
	    }
	}
    }
    return 0;
}

int read_blacklisted_classes() {
	char name[FILE_MAX];
	FILE* blacklist;
	blacklist = fopen (g_blacklistfile.c_str(), "rb");
	if(blacklist)
	{
	    while(!feof(blacklist))
	    {
		fscanf (blacklist, "%s\n" ,name);
		if(g_debug)
		    printf("exclude: %s\n", name);
		g_vclassesblacklist.push_back(name);
	    }
	    fclose(blacklist);
	}
	return 0;
}

int generate_cim_factory() {
    string line = "";
    string placeholder;
    placeholder.resize(50, ' ');

    FILE* fop = fopen(g_cimfactoryfile.c_str(), "wb");
    if(NULL == fop)
    {
	fprintf(stderr, "\nERROR: Unable to write to %s\n", g_cimfactoryfile.c_str());
	return -1;
    }

    line += "#include <stdio.h>\n";
    line += "#include <dsdk/dsdktypes.h>\n";
    line += "#include \"cimfactory.h\"\n";

    for(unsigned int i = 0; i != g_classes.size(); i++)
    {
	if (g_classes[i].isAssociation()) continue;
	string cn = g_classes[i].getName();
	line += "#include <dsdk/oal/" + cn + ".h>\n";
    }

    fwrite(line.c_str(), 1, line.size(), fop);

    line = "using namespace dsdk;\n\n";
    line += "namespace wrapperCpp {\n\n";
    line += "COALObject* create(CCIMInstance* ins)\n{\n";

    line += "  string cn = ins->getObjectPath().getClassName();\n";
    line += "  int last_slash = cn.rfind('/');\n";
    line += "  if (last_slash != -1)\n";
    line += "    cn = cn.substr(last_slash + 1, cn.length() - last_slash);\n\n";

    for(unsigned int i = 0; i != g_classes.size(); i++)
    {
	if (g_classes[i].isAssociation()) continue;
	string cn = g_classes[i].getName();
	line += "  if(0 == strcmp(cn.c_str(),\"" + cn + "\"))" 
	    + (placeholder.size() <= cn.size() ? " " : placeholder.substr(0, placeholder.size() - cn.size()));

	/* keep this in for the moment cause it may be need for debugging or 
	   something like that...

	if (cn.find("DRI_") == 0) {
	    CCIMClass* cc = g_classes[i].getSuperClass();
	    if (cc != NULL) {
		cn = cc->getName();
		// cn.replace(0, 3, "CIM");
	    }
	    
	}
	*/

	line += "return new " + cn + "(*ins);\n";
    }

    line += "  return NULL;\n}\n\n";
    line += "};	/* namespace dsdk */\n";
    
    fwrite(line.c_str(), 1, line.size(), fop);
    fclose(fop);

    return 0;
}

bool contains(vector<string>* haystack, const char* needle)
{
    string s = needle;
    vector<string>::iterator result = find(haystack->begin(), haystack->end(), s);
    if(result != haystack->end())
	return true;
    return false;
}
