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
 * dsdkexception.h
 * DASH SDK Exceptions.
 */
#ifndef __DSDK_EXCEPTION_H__
#define __DSDK_EXCEPTION_H__
#include <exception>
#include <string>
#include <dsdk/errorcode.h>
#include <dsdk/dsdktypes.h>
#include <cmci/cmci.h>


using std::exception;
using std::string;

namespace dsdk
{

/**
 * @class EDSDKError
 * A generic DASH SDK Error Exception. All the exceptions thrown by the DASH
 * SDK are derived from this exception. 
 */
class EDSDKError : public exception
{
public:
	/**
	 * Construct this object from the error code.
	 */
	EDSDKError (int error_code) : _error_code (error_code), 
								  _msg (g_dsdk_error_code [error_code]) { /* Empty */ }

	/**
	 * Construct this object from the error code and message string.
	 */
	EDSDKError (int error_code, string msg) :	_error_code (error_code) 
	{
		_msg = g_dsdk_error_code [error_code];
		_msg += " : " + msg;
	}

public:
	/**
	 * Describes this exception
	 */
	virtual const char* what (void) const throw () { return _msg.c_str (); }

	/**
	 * Get the return code.
	 */
	virtual unsigned int getErrorCode (void) const throw () 
											{ return _error_code; }

	/**
	 * Default Destructor.
	 */
	~EDSDKError () throw () {};

protected:
	int  	_error_code;
	string	_msg;
};


/**
 * @class ECIMError
 * @brief	A CIM error exception. This execption is thrown when there is a CIM error
 *			Ex. wsa:DestinationUnreachable, wsman:InvalidSelectors, wsa:ActionNotSupported etc.
 *			Call getCIMErrorMsg to get the CIM error.
 */
class ECIMError : public EDSDKError
{
public:
	/**
	 * Static inline function that checks if the status has error and 
	 * throws the exception.
	 */
	static inline void checkThrowCIMStatus (const CMPIStatus& status) 
	{
		if (status.rc != CMPI_RC_OK) { throw ECIMError (status); }
	}

public:
	/**
	 * Build this class from the low level status code 
	 */
	ECIMError (const CMPIStatus& status) : EDSDKError (DSDK_CIM_ERROR)
	{
		if (0 != status.msg)
		{
			_cim_error_msg	= status.msg->ft->getCharPtr (status.msg, NULL);
			status.msg->ft->release (status.msg);
		}
		else
		{
			switch (status.rc)
			{
			case	CMPI_RC_OK:							_cim_error_msg = "Success";		break;
			case	CMPI_RC_ERR_FAILED:					_cim_error_msg = "Unknown Error";		break;
			case	CMPI_RC_ERR_ACCESS_DENIED:			_cim_error_msg = "Access Denied"; break;
			case	CMPI_RC_ERR_INVALID_NAMESPACE:		_cim_error_msg = "Invalid Namesapce"; break;
			case	CMPI_RC_ERR_INVALID_PARAMETER:		_cim_error_msg = "Invalid parameter"; break;
			case	CMPI_RC_ERR_INVALID_CLASS:			_cim_error_msg = "Invalid class"; break;
			case	CMPI_RC_ERR_NOT_FOUND:				_cim_error_msg = "Not found"; break;
			case	CMPI_RC_ERR_NOT_SUPPORTED:			_cim_error_msg = "Not supported"; break;
			case	CMPI_RC_ERR_INVALID_SUPERCLASS:		_cim_error_msg = "Invalid superclass"; break;
			case	CMPI_RC_ERR_ALREADY_EXISTS:			_cim_error_msg = "Already Exists"; break;
			case	CMPI_RC_ERR_NO_SUCH_PROPERTY:		_cim_error_msg = "No such Property"; break;
			case	CMPI_RC_ERR_TYPE_MISMATCH:			_cim_error_msg = "Type mismatch"; break;
			case	CMPI_RC_ERR_QUERY_LANGUAGE_NOT_SUPPORTED:_cim_error_msg = "Query Language not supported"; break;
			case	CMPI_RC_ERR_INVALID_QUERY:			_cim_error_msg = "Invalid Query"; break;
			case	CMPI_RC_ERR_METHOD_NOT_AVAILABLE:	_cim_error_msg = "Method not available"; break;
			case	CMPI_RC_ERR_METHOD_NOT_FOUND:		_cim_error_msg = "Method not found"; break;
			case	CMPI_RC_CONNECTION_FAILED:			_cim_error_msg = "Connection failed"; break;
			case	CMPI_RC_METHOD_NOT_IMPLEMENTED:		_cim_error_msg = "Method not implemented"; break;
			case	CMPI_RC_ERR_INVALID_PORT:			_cim_error_msg = "Invalid port number"; break;
			case	CMPI_RC_ERR_UNSUPPORTED_FEATURE:	_cim_error_msg = "Unsupported Feature";break;
			default:	_cim_error_msg = "Unknown Error";
			}
		}
		_msg	= _msg + " : " + _cim_error_msg;
		_rc = status.rc;
	};

public:
	/**
	 * Descibes this exception
	 */
	virtual const char* what (void) const throw () 
	{ 
		return _msg.c_str (); 
	}

	/**
	 * Get the return code.
	 */
	virtual unsigned int getRetCode (void) const throw () 
											{ return (unsigned int) _rc; }

	/**
	 * Get CIM Error message 
	 */
	virtual string getCIMErrorMsg (void) { return _cim_error_msg; }
		

	/**
	 * Default Destructor.
	 */
	~ECIMError () throw () {};

private:
	CMPIrc	_rc;
	string  _cim_error_msg;
};

/**
 * @class ECIMMethodNotImplemented
 * @brief Method not implemented macro. This execption is thrown when unsupported 
 *		  CIM method is called. Call getMethod function to get the method name.
 */
class ECIMMethodNotImplemented : public EDSDKError
{
public:
	/**
	 * Static inline function that checks if the status has method not implemented and 
	 * throws the exception.
	 */
	static inline void checkThrowCIMMethodNotImplemented (const CMPIStatus& status, string name) 
	{
		if (status.rc == CMPI_RC_METHOD_NOT_IMPLEMENTED) { throw ECIMMethodNotImplemented (name); }
	}


public:
	ECIMMethodNotImplemented (string name) : EDSDKError (DSDK_CIMMETHOD_NOTIMPLEMENTED), 
											_name (name) 
	{ 
		_msg = _name + " : " + _msg;
	}

public:
	/**
	 * Descibes this exception
	 */
	virtual const char* what (void) const throw () 
	{ 
		return _msg.c_str (); 
	}

	/**
	 * Get the return code.
	 */
	virtual string getMethod (void) const throw () { return _name; }

	/**
	 * Default Destructor.
	 */
	~ECIMMethodNotImplemented () throw () {};

private:
	string	_name;
};



/**
 * @class EConnectionFailed
 * @brief A connection failed exception. This execption is thrown when a connection error like
 *		  when not able to connect to server or not able to authenticate. Call getConnectionFailedMsg
 *		  to get the error message.
 */
class EConnectionFailed : public EDSDKError
{
public:
	/**
	 * Constructor
	 */
	EConnectionFailed () : EDSDKError (DSDK_CONNECTION_FAILED) {}

	/**
	 * Static inline function that checks if the status has connection error and 
	 * throws the exception.
	 */
	static inline void checkThrowConnectionFailed (const CMPIStatus& status) 
	{
		if (status.rc == CMPI_RC_CONNECTION_FAILED) { throw EConnectionFailed (status); }
	}

public:
	/**
	 * Build this class from the low level status code 
	 */
	EConnectionFailed (const CMPIStatus& status) : EDSDKError (DSDK_CONNECTION_FAILED)
	{
		if (0 != status.msg)
		{
			_connection_error_msg = status.msg->ft->getCharPtr (status.msg, NULL);
			_msg = _msg + " : " + _connection_error_msg;
			status.msg->ft->release (status.msg);
		}
	};

	/**
	 * Describes this exception
	 */
	virtual const char* what (void) const throw () 
	{ 
		return _msg.c_str ();
	}

	/**
	 * Gets the connection failed error message 
	 */
	virtual string getConnectionFailedMsg (void)
	{
		return _connection_error_msg;
	}

	/**
	 * Default Destructor.
	 */
	~EConnectionFailed () throw () {};

private:
	string _connection_error_msg;
	string _what;
};

/**
 * @class ENotEnoughMemory
 * @brief Not enough memory exception.
 */
class ENotEnoughMemory : public EDSDKError
{
public:
	/**
	 * Constructor
	 */
	ENotEnoughMemory () : EDSDKError (DSDK_NOT_ENOUGH_MEMORY) {}
};

/**
 * @class EFunctionNotSupported
 * @brief Function is not supported by the remote.
 */
class EFunctionNotSupported : public EDSDKError
{
public:
	/**
	 * Constructor
	 */
	EFunctionNotSupported (string function) : EDSDKError (DSDK_FUNCTION_NOT_SUPPORTED)
	{
		_function = function;
		_msg	  = _msg + " : " + _function;
	}

	/**
	 * Describes this exception
	 */
	virtual const char* what (void) const throw () 
	{ 
		return _msg.c_str (); 
	}

	/**
	 * Gets the name of function not supported
	 */
	virtual string getFunction (void)
	{
		return _function;
	}


	/**
	 * Default Destructor.
	 */
	~EFunctionNotSupported () throw () {};

private:
	string _function;
};

/**
 * @class EFunctionReturnedWithFailure
 * @brief Function is returned with failure. This execption is thrown when a 
 *		  CIM Extrinsic method is returned with failure. Call getFunction to get the
 *		  function name and call getErrorMsg to get the failure message.
 */
class EFunctionReturnedWithFailure : public EDSDKError
{
public:
	/**
	 * Constructor
	 */
	EFunctionReturnedWithFailure (string fnname, string retcodestr, uint32 status) 
								: EDSDKError (DSDK_FUNCTION_RETURNED_WITH_FAILURE)
	{
		_function   = fnname + " : " + retcodestr;
		_funname    = fnname;
		_retcodestr = retcodestr;
		_statusvalue= status; 
		_msg	    = _msg + " : " + _function;
		
	}

	/**
	 * Describes this exception
	 */
	virtual const char* what (void) const throw () 
	{ 
		return _msg.c_str (); 
	}

	/**
	 * Gets the name of function returned with failure
	 */
	virtual string getFunction (void)
	{
		return _funname;
	}

	/**
	 * Gets the retcode string of function 
	 */
	virtual string getErrorMsg (void)
	{
		return _retcodestr;
	}

	/**
	 * Get the return code.
	 */
	virtual unsigned int getRetCode (void)  
											{ return _statusvalue; }


	/**
	 * Default Destructor.
	 */
	~EFunctionReturnedWithFailure () throw () {};

private:
	string _function;
	string _funname;
	string _retcodestr;
	uint32  _statusvalue;
};

};	/* namespace dsdk */





#endif /* __DSDK_EXCEPTION_H__ */


