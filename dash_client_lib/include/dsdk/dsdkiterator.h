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
 * dsdkiterator.h
 * A Generic iterator.
 */
#ifndef __DSDK_ITERATOR_H__
#define __DSDK_ITERATOR_H__
#include /**/ <iterator>

namespace dsdk
{

/**
 * @class CIterator
 * @brief A generic input iterator used to iterate objects in the DASH SDK
 **/
template <class Key>
class CIterator : public std::iterator <std::input_iterator_tag, typename Key::ItemType>
{
public:
	/**
	 * Build an iterator based on the key class 
	 * @param key	The key class for this iterator
	 **/
	inline CIterator (Key* key) : _is_last (false), _key (key)
	{
		if (!_key->hasNext ())  { _is_last = true; }
		else 					{ _key->next ();   }

		_key->incReferenceCount ();
	}

	/**
	 * Copy constructor
	 */
	inline CIterator (const CIterator& iter)
	{
		this->_is_last 	= iter._is_last;
		this->_key 		= iter._key;
		if (0 != this->_key) { this->_key->incReferenceCount (); }
	}

	/**
	 * Assignment Operator
	 */
	inline const CIterator& operator = (const CIterator& iter)
	{
		if (0 != this->_key) { this->_key->decReferenceCount (); }

		this->_is_last 	= iter._is_last;
		this->_key 		= iter._key;
		if (0 != this->_key) { this->_key->incReferenceCount (); }

		return *this;
	}
	
	/**
	 * Destructor
	 */
	inline ~CIterator ()	{ if (0 != _key) { _key->decReferenceCount (); }}


	/**
	 * Compare if two iterators are equal
	 * @param rhs	Right hand side to compare to.
	 * @return		True if equal.
	 * 				False if not.
	 **/
	inline bool operator == (const CIterator& rhs) const
	{
		if (this->_is_last && rhs._is_last) { return true; }
		else if (this->_key == 0)			{ return (rhs._key == 0); }
		else								{ return ((rhs._key != 0) && this->_key->isEqual (rhs._key)); }
	}

	/**
	 * Compare if two iterators are not equal
	 * @param rhs	Right hand side to compare to.
	 * @return		True if not equal.
	 * 				False if equal.
	 **/
	inline bool operator != (const CIterator& rhs)
	{
		return !(*this == rhs); 
	}
	
	/**
	 * Pre increment operator (no post increment operator allowed)
	 * @return 		This iterator
	 **/
	inline CIterator& operator ++ ()
	{
		this->advance ();
		return *this;
	}
	
	
	/**
	 * De reference operator 
	 * @return		The item behind this iterator.
	 **/
	inline typename Key::ItemType operator * ()
	{
		return _key->getItem ();
	}
	
	/**
	 * Pointer dereference operator 
	 * @return		The item behind this iterator.
	 **/
	inline typename Key::ItemType operator ->()
	{
		return _key->getItem ();
	}


	/** 
	 * End of the iterator 
	 * @return 		The end of the iterator.
	 **/	
	inline static CIterator end ()
	{
		return CIterator <Key> ();
	}


public:
	/* Default constructor - same as the end of the iterator */
	inline CIterator () : _is_last (true), _key (0) { };

	
private:
	/**
	 * Advance to the next 
	 **/
	inline void advance (void)
	{
		if (!_key->hasNext ()) { this->_is_last = true; }
		else 				   { _key->next (); }
	}


private:	
	bool	_is_last;		/**< True if this is the last entry 	*/
	Key*	_key;			/**< The key class behind this iterator */
};


/**
 * @class IGenericKey
 * @brief A Generic Key interface that could be used with the iterators. 
 * The purpose for this interface could have been implemented more elegantly
 * using a handle body pattern, but has been avoided to keep the class 
 * structure simple.
 */
template <class Item>
class IGenericKey 
{
public:
	/**
	 * Factory method. This is the method that needs to be used to create
	 * objects of this type. This enforces that the objects are always 
	 * created in the heap (This is required by the Iterator). This function
	 * stub is here just to remind that the Classes implementing this
	 * interface implement this static function. When implementing this 
	 * interface you can add any parameters you require to the create 
	 * function based on the class.
	 */
	inline static IGenericKey* create (void) { return 0; }

public:
	/**
	 * Returns the current Item this key is pointing to 
	 */
	virtual const Item& getItem (void) = 0;

	/**
	 * Moves the Key to the next item.
	 */
	virtual void next (void) = 0;

	/**
	 * Checks if there is next item.
	 * @return true if there is a next item.
	 * 		   false otherwise.
	 */
	virtual bool hasNext (void) = 0;

	/**
	 * Checks if two keys are equal.
	 * @return true if equal.
	 *		   false otherwise.
	 */
	virtual bool isEqual (const IGenericKey* k) = 0;

public:
	typedef Item ItemType;

public:
	/**
	 * Increments the reference count on this object. Even though this 
	 * is an interface this function is provided as a convenience.
	 */
	virtual void incReferenceCount (void) { _reference_count++; }

	/**
	 * Decrements the reference count on this object. If the reference
	 * count becomes 0 this object is deleted.
	 */
	virtual void decReferenceCount (void) 
	{
		_reference_count--;
		if (0 == _reference_count) { delete this; }
	}

protected:
	/**
	 * This constructor is present here to prevent any creation on the 
	 * stack. Any classes implementing this interface should put their 
	 * constructors as protected (or private) to prevent explicit 
	 * instantiation on the stack. 
	 */
	inline IGenericKey  () : _reference_count (0) { /* Empty */ };

	/**
	 * Destructor
	 */
	virtual ~IGenericKey () { /* Empty */ }

private : 
	int		_reference_count;
};

}	/* dsdk */

#endif	/* __DSDK_ITERATOR_H__ */

