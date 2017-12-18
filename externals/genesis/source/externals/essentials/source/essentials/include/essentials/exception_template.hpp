//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex essentials library (http://essentials.seadex.de).                //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://essentials.seadex.de/License.html.         //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EXCEPTION_TEMPLATE_6EFED438_B578_4EF6_B02A_53DC49B89A0D
#define EXCEPTION_TEMPLATE_6EFED438_B578_4EF6_B02A_53DC49B89A0D


#include <exception>

#include "essentials/compatibility/compatibility.hpp"
#include "essentials/sxprintf.hpp"


#ifndef SX_CPP03_BOOST


//!\def SX_EXCEPTION( _name )
//!\brief Create an exception class inheriting std::exception with the given name. It also supports
//! creating messages with placeholders by calling sxprintf.
//!\sa sxprintf
#define SX_EXCEPTION( _name ) \
class _name: public std::exception \
{ \
public: \
	template< typename ... args > \
	_name(const std::string & _what, args ... _args	):\
		std::exception(), \
		what_( sxe::sxprintf( _what.c_str(), _args ... ) ) \
	{ \
	} \
\
\
	virtual ~_name () SX_NOEXCEPT SX_OVERRIDE {}\
\
\
	virtual const char* what() const throw () SX_OVERRIDE \
	{ \
		return ( what_.c_str() ); \
	} \
\
\
private: \
	std::string what_; \
\
\
};


#else


#define SX_EXCEPTION( _name ) \
class _name: public std::exception \
{ \
public: \
		explicit _name(const std::string & _what ):\
			std::exception(), \
			what_( sxe::sxprintf( _what.c_str() ) ) \
	{ \
	} \
\
\
		explicit _name(const std::string & _what, const sxe::value_type& _value1 ):\
			std::exception(), \
			what_( sxe::sxprintf( _what.c_str(), _value1 ) ) \
	{ \
	} \
\
\
		explicit _name(const std::string & _what, const sxe::value_type& _value1, const sxe::value_type& _value2 ):\
			std::exception(), \
			what_( sxe::sxprintf( _what.c_str(), _value1, _value2 ) ) \
	{ \
	} \
\
\
		explicit _name(const std::string & _what, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3 ):\
			std::exception(), \
			what_( sxe::sxprintf( _what.c_str(), _value1, _value2, _value3 ) ) \
	{ \
	} \
\
\
		explicit _name(const std::string & _what, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3, const sxe::value_type& _value4 ):\
			std::exception(), \
			what_( sxe::sxprintf( _what.c_str(), _value1, _value2, _value3, _value4 ) ) \
	{ \
	} \
\
\
		explicit _name(const std::string & _what, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3, const sxe::value_type& _value4, const sxe::value_type& _value5 ):\
			std::exception(), \
			what_( sxe::sxprintf( _what.c_str(), _value1, _value2, _value3, _value4, _value5 ) ) \
	{ \
	} \
\
\
		explicit _name(const std::string & _what, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3, const sxe::value_type& _value4, const sxe::value_type& _value5, const sxe::value_type& _value6 ):\
			std::exception(), \
			what_( sxe::sxprintf( _what.c_str(), _value1, _value2, _value3, _value4, _value5, _value6 ) ) \
	{ \
	} \
\
\
\
		explicit _name(const std::string & _what, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3, const sxe::value_type& _value4, const sxe::value_type& _value5, const sxe::value_type& _value6, const sxe::value_type& _value7 ):\
			std::exception(), \
			what_( sxe::sxprintf( _what.c_str(), _value1, _value2, _value3, _value4, _value5, _value6, _value7 ) ) \
	{ \
	} \
\
\
		explicit _name(const std::string & _what, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3, const sxe::value_type& _value4, const sxe::value_type& _value5, const sxe::value_type& _value6, const sxe::value_type& _value7, const sxe::value_type& _value8 ):\
			std::exception(), \
			what_( sxe::sxprintf( _what.c_str(), _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8 ) ) \
	{ \
	} \
\
\
		explicit _name(const std::string & _what, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3, const sxe::value_type& _value4, const sxe::value_type& _value5, const sxe::value_type& _value6, const sxe::value_type& _value7, const sxe::value_type& _value8, const sxe::value_type& _value9 ):\
			std::exception(), \
			what_( sxe::sxprintf( _what.c_str(), _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8, _value9 ) ) \
	{ \
	} \
\
\
		explicit _name(const std::string & _what, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3, const sxe::value_type& _value4, const sxe::value_type& _value5, const sxe::value_type& _value6, const sxe::value_type& _value7, const sxe::value_type& _value8, const sxe::value_type& _value9, const sxe::value_type& _value10 ):\
			std::exception(), \
			what_( sxe::sxprintf( _what.c_str(), _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8, _value9, _value10 ) ) \
	{ \
	} \
\
\
	virtual ~_name () SX_NOEXCEPT SX_OVERRIDE {}\
\
\
	virtual const char* what() const throw () SX_OVERRIDE \
	{ \
		return ( what_.c_str() ); \
	} \
\
\
private: \
	std::string what_; \
\
\
};


#endif


#endif
