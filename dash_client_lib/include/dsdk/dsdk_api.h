/*
 * License Agreement 
 *
 * Copyright (c) 2007, 2008, 2009 Advanced Micro Devices Inc.
 *
 * All rights reserved.
 *
 * Redistribution and use in any form of this material and any product thereof including
 * software in source or binary forms, along with any related documentation, with or 
 * without modification ("this material"), is permitted provided that the following 
 * conditions are met:
 *
 *    + Redistributions of source code of any software must retain the above copyright 
 *      notice and all terms of this license as part of the code.
 *
 *    + Redistributions in binary form of any software must reproduce the above copyright 
 *      notice and all terms of this license in any related documentation and/or other 
 *      materials.
 *
 *    + Neither the names nor trademarks of Advanced Micro Devices, Inc. or any copyright 
 *      holders or contributors may be used to endorse or promote products derived from 
 *      this material without specific prior written permission.
 *
 *    + Notice about U.S. Government restricted rights: This material is provided with ?
 *      RESTRICTED RIGHTS.? Use, duplication or disclosure by the U.S. Government is subject 
 *      to the full extent of restrictions set forth in FAR52.227 and DFARS252.227 et seq., 
 *      or any successor or applicable regulations. Use of this material by the U.S. 
 *      Government constitutes acknowledgment  of  the  proprietary rights of 
 *      Advanced Micro Devices, Inc. and any copyright holders and contributors. 
 *
 *    + In no event shall anyone redistributing or accessing or using this material 
 *      commence or participate in any arbitration or legal action relating to this 
 *      material against Advanced Micro Devices, Inc. or any copyright holders or contributors. 
 *      The foregoing shall survive any expiration or termination of this license or any 
 *      agreement or access or use related to this material.  
 *
 *    + ANY BREACH OF ANY TERM OF THIS LICENSE SHALL RESULT IN THE IMMEDIATE REVOCATION 
 *      OF ALL RIGHTS TO REDISTRIBUTE, ACCESS OR USE THIS MATERIAL. 
 *
 * THIS MATERIAL IS PROVIDED BY ADVANCED MICRO DEVICES, INC. AND ANY COPYRIGHT HOLDERS AND 
 * CONTRIBUTORS "AS IS" IN ITS CURRENT CONDITION AND WITHOUT ANY REPRESENTATIONS, GUARANTEE, 
 * OR WARRANTY OF ANY KIND OR IN ANY WAY RELATED TO SUPPORT, INDEMNITY, ERROR FREE OR 
 * UNINTERRUPTED OPERATION, OR THAT IT IS FREE FROM DEFECTS OR VIRUSES.  ALL OBLIGATIONS 
 * ARE HEREBY DISCLAIMED - WHETHER EXPRESS, IMPLIED, OR STATUTORY - INCLUDING, BUT NOT 
 * LIMITED TO, ANY IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY, FITNESS FOR A PARTICULAR 
 * PURPOSE, ACCURACY, COMPLETENESS, OPERABILITY, QUALITY OF SERVICE, OR NON-INFRINGEMENT. 
 * IN NO EVENT SHALL ADVANCED MICRO DEVICES, INC. OR ANY COPYRIGHT HOLDERS OR CONTRIBUTORS 
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, PUNITIVE, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, REVENUE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED 
 * OR BASED ON ANY THEORY OF LIABILITY ARISING IN ANY WAY RELATED TO THIS MATERIAL, EVEN IF 
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. THE ENTIRE AND AGGREGATE LIABILITY OF ADVANCED 
 * MICRO DEVICES, INC. AND ANY COPYRIGHT HOLDERS AND CONTRIBUTORS SHALL NOT EXCEED TEN DOLLARS 
 * (US $10.00). ANYONE REDISTRIBUTING OR ACCESSING OR USING THIS MATERIAL ACCEPTS THIS 
 * ALLOCATION OF RISK AND AGREES TO RELEASE ADVANCED MICRO DEVICES, INC. AND ANY COPYRIGHT 
 * HOLDERS AND CONTRIBUTORS FROM ANY AND ALL LIABILITIES, OBLIGATIONS, CLAIMS, OR DEMANDS IN 
 * EXCESS OF TEN DOLLARS (US $10.00). THE FOREGOING ARE ESSENTIAL TERMS OF THIS LICENSE AND, 
 * IF ANY OF THESE TERMS ARE CONSTRUED AS UNENFORCEABLE, FAIL IN ESSENTIAL PURPOSE, OR BECOME 
 * VOID OR DETRIMENTAL TO ADVANCED MICRO DEVICES, INC. OR ANY COPYRIGHT HOLDERS OR CONTRIBUTORS 
 * FOR ANY REASON, THEN ALL RIGHTS TO REDISTRIBUTE, ACCESS OR USE THIS MATERIAL SHALL TERMINATE 
 * IMMEDIATELY. MOREOVER, THE FOREGOING SHALL SURVIVE ANY EXPIRATION OR TERMINATION OF THIS 
 * LICENSE OR ANY AGREEMENT OR ACCESS OR USE RELATED TO THIS MATERIAL. 
 *
 * NOTICE IS HEREBY PROVIDED, AND BY REDISTRIBUTING OR ACCESSING OR USING THIS MATERIAL SUCH NOTICE 
 * IS ACKNOWLEDGED, THAT THIS MATERIAL MAY BE SUBJECT TO RESTRICTIONS UNDER THE LAWS AND REGULATIONS 
 * OF THE UNITED STATES OR OTHER COUNTRIES, WHICH INCLUDE BUT ARE NOT LIMITED TO, U.S. EXPORT 
 * CONTROL LAWS SUCH AS THE EXPORT ADMINISTRATION REGULATIONS AND NATIONAL SECURITY CONTROLS AS 
 * DEFINED THEREUNDER, AS WELL AS STATE DEPARTMENT CONTROLS UNDER THE U.S. MUNITIONS LIST. THIS 
 * MATERIAL MAY NOT BE USED, RELEASED, TRANSFERRED, IMPORTED, EXPORTED AND/OR RE-EXPORTED IN ANY 
 * MANNER PROHIBITED UNDER ANY APPLICABLE LAWS, INCLUDING U.S. EXPORT CONTROL LAWS REGARDING 
 * SPECIFICALLY DESIGNATED PERSONS, COUNTRIES AND NATIONALS OF COUNTRIES SUBJECT TO NATIONAL SECURITY 
 * CONTROLS. MOREOVER, THE FOREGOING SHALL SURVIVE ANY EXPIRATION OR TERMINATION OF ANY LICENSE 
 * OR AGREEMENT OR ACCESS OR USE RELATED TO THIS MATERIAL. 
 *
 * This license forms the entire agreement regarding the subject matter hereof and supersedes all 
 * proposals and prior discussions and writings between the parties with respect thereto. This 
 * license does not affect any ownership, rights, title, or interest in, or relating to, this 
 * material. No terms of this license can be modified or waived, and no breach of this license 
 * can be excused, unless done so in a writing signed by all affected parties. Each term of this 
 * license is separately enforceable. If any term of this license is determined to be or becomes 
 * unenforceable or illegal, such term shall be reformed to the minimum extent necessary in order 
 * for this license to remain in effect in accordance with its terms as modified by such reformation. 
 * This license shall be governed by and construed in accordance with the laws of the State of 
 * Texas without regard to rules on conflicts of law of any state or jurisdiction or the United 
 * Nations Convention on the International Sale of Goods. All disputes arising out of this license 
 * shall be subject to the jurisdiction of the federal and state courts in Austin, Texas, and all 
 * defenses are hereby waived concerning personal jurisdiction and venue of these courts.
 */
/**
 * dsdk_api.h
 * Common DASH SDK API functions.
 */
#ifndef __DSDK_API_H__
#define __DSDK_API_H__
#include <string>
#include <vector>
using std::string;
using std::vector;


/**
 * @class CAPIIterator
 * @brief An iterator template for API Layer objects that have a 
 * correspoding OAL layer objects.
 **/
template <class APIClass, class OALClass>
class CAPIIterator : public std::iterator <std::input_iterator_tag, OALClass>
{
public:
	/**
	 * Build an non-cached iterator based on the CCIMInstance iterator.
	 * @param iter The CCIMInstance iterator
	 **/
	inline CAPIIterator (typename OALClass::iterator iter) : _iter (iter), 
													_cached (false) 
													{ /* Empty */ }

	/**
	 * Build a cached iterator based on the CCIMInstance iterator.
	 * @param iter The CCIMInstance iterator
	 * @param cached_props Properties to cache
	 **/
	inline CAPIIterator (typename OALClass::iterator iter, 
						 vector<string> cached_props) : _iter (iter), 
														_cached (true),
														_cached_props (cached_props)
														{ /* Empty */ }

	/**
	 * Compare if two iterators are equal
	 * @param rhs	Right hand side to compare to.
	 * @return		True if equal.
	 * 				False if not.
	 **/
	inline bool operator == (const CAPIIterator& rhs) const
	{
		return _iter == rhs._iter;
	}

	/**
	 * Compare if two iterators are not equal
	 * @param rhs	Right hand side to compare to.
	 * @return	True if not equal.
	 * 			False if equal.
	 **/
	inline bool operator != (const CAPIIterator& rhs)
	{
		return !(*this == rhs); 
	}
	
	/**
	 * Pre increment operator (no post increment operator allowed)
	 * @return This iterator
	 **/
	inline CAPIIterator& operator ++ () 
	{ 
		++_iter;  
		return *this; 
	}
	
	/**
	 * De reference operator 
	 * @return	The item behind this iterator.
	 **/
	inline APIClass operator * ()
	{
		OALClass oal_class = *_iter;
		if (_cached) { oal_class.enableCache (_cached_props, false); }
		return APIClass (oal_class);
	}
	
	/**
	 * Pointer dereference operator 
	 * @return	The item behind this iterator.
	 **/
	inline APIClass operator ->()
	{
		OALClass oal_class = *_iter;
		if (_cached) { oal_class.enableCache (_cached_props, false); }
		return APIClass (oal_class);
	}

	/** 
	 * End of the iterator 
	 * @return The end of the iterator.
	 **/	
	inline static CAPIIterator end ()
	{
		return CAPIIterator (OALClass::iterator::end ());
	}

private:	
	typename OALClass::iterator	_iter;
	bool						_cached;
	vector<string>				_cached_props;
};


/**
 * API Iteration declaration
 */
#define DECLARE_API_ITERATOR(CLASSNAME)									\
class DSDK_Export iterator												\
{																		\
	public:																\
	iterator (_##CLASSNAME##Iterator* imp) : _imp (imp) { /* Empty */ }	\
		iterator (const iterator& iter);								\
		const iterator& operator = (const iterator& rhs);				\
		~iterator ();													\
																		\
		bool operator == (const iterator& rhs) const;					\
		bool operator != (const iterator& rhs);							\
		iterator& operator ++ ();										\
		CLASSNAME operator * ();										\
		CLASSNAME operator ->();										\
		static iterator end ();											\
																		\
	private:															\
		_##CLASSNAME##Iterator* _imp;									\
};																		\

/**
 * API Iteration definetion
 */
#define DEFINE_API_ITERATOR(CLASSNAME)																\
																									\
CLASSNAME::iterator::iterator (const iterator& iter)												\
{																									\
	_imp = new _##CLASSNAME##Iterator (*(iter._imp));												\
}																									\
																									\
const CLASSNAME::iterator&																			\
CLASSNAME::iterator::operator = (const iterator& rhs)												\
{																									\
	if (0 != _imp) { delete _imp; }																	\
	_imp = new _##CLASSNAME##Iterator (*(rhs._imp));												\
	return *this;																					\
}																									\
																									\
CLASSNAME::iterator::~iterator () { delete _imp; }													\
																									\
bool																								\
CLASSNAME::iterator::operator == (const CLASSNAME::iterator& rhs) const								\
{																									\
	return *_imp == *(rhs._imp);																	\
}																									\
																									\
bool																								\
CLASSNAME::iterator::operator != (const CLASSNAME::iterator& rhs)									\
{																									\
	return *_imp != *(rhs._imp);																	\
}																									\
																									\
CLASSNAME::iterator&																				\
CLASSNAME::iterator::operator ++ ()																	\
{																									\
	++(*_imp);																						\
	return *this;																					\
}																									\
																									\
CLASSNAME																							\
CLASSNAME::iterator::operator * ()																	\
{																									\
	return *(*_imp);																				\
}																									\
																									\
																									\
CLASSNAME																							\
CLASSNAME::iterator::operator ->()																	\
{																									\
	return *(*_imp);																				\
}																									\
																									\
CLASSNAME::iterator																					\
CLASSNAME::iterator::end ()																			\
{																									\
	_##CLASSNAME##Iterator* imp = new _##CLASSNAME##Iterator (_##CLASSNAME##Iterator::end ());		\
	return CLASSNAME::iterator (imp);																\
}

/**
 * Create API Iterator Definetion 
 */

#define DEFINE_CREATE_API_ITERATOR(APICLASS, OALCLASS)											\
																								\
APICLASS::iterator createIterator (OALCLASS::iterator iter)										\
{																								\
	_##APICLASS##Iterator* i = new _##APICLASS##Iterator (iter);								\
	return APICLASS::iterator (i);																\
}																								\
																								\
APICLASS::iterator createIterator (OALCLASS::iterator iter,										\
															  vector<string> cached_props)		\
{																								\
	_##APICLASS##Iterator* i = new _##APICLASS##Iterator (iter, cached_props);					\
																								\
	return APICLASS::iterator (i);																\
}


#endif /* __DSDK_API_H__ */

