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

#ifndef __MOF2CPP_SKELETON_H__
#define __MOF2CPP_SKELETON_H__
#include <stdio.h>
#include <string>
#include <map>

using std::string;
using std::map;
using std::pair;


/**
 * @class CSkeleton
 * @brief A class to hold code skeletons.
 */
class CSkeleton
{
public:
	/**
	 * A Singleton instance function
	 */
	inline static CSkeleton* instance (void)
	{
		if (0 == _instance) { _instance = new CSkeleton (); }
		return _instance;
	}

public:
	/**
	 * Load a code skeleton from a file
	 */
	inline int load (string skel_name, string content_file)
	{
		FILE* fp = fopen (content_file.c_str (), "rb");
		if (NULL == fp) { return -1; }

		fseek (fp, 0, SEEK_END);
		long len = ftell (fp);
		fseek (fp, 0, SEEK_SET);

		char* buf = new char [len];
		fread (buf, 1, len, fp);
		fclose (fp);
		buf [len - 1] = '\0';

		string skel_content = buf;
		delete [] buf;

		_skel_map.insert (pair<string, string> (skel_name, skel_content));

		return 0;
	}

public:
	/**
	 * Returns the skeleton content corresponding to the skeleton name
	 */
	string getContent (string skel_name)
	{
		if (_skel_map.end () != _skel_map.find (skel_name))
		{
			return _skel_map [skel_name];
		}
		else { return ""; }
	}

private:
	/**
	 * Default constructor.
	 */
	CSkeleton () { /* Empty */ }


private:
	map<string, string>	_skel_map;

private:
	static CSkeleton*	_instance;
};

#endif /* __MOF2CPP_SKELETON_H__ */

