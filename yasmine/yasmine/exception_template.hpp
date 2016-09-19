//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EXCEPTION_TEMPLATE_6EFED438_B578_4EF6_B02A_53DC49B89A0D
#define EXCEPTION_TEMPLATE_6EFED438_B578_4EF6_B02A_53DC49B89A0D


#include <exception>
#include <string>

#include "yprintf.hpp"


//!\def Y_EXCEPTION( _name )
//!\brief The macro creates an exception class inheriting the std::exception with the given name. It also supports
// creating messages with placeholders by calling yprintf.
//!\sa yprintf
#define Y_EXCEPTION( _name ) \
class _name: public std::exception \
{ \
public: \
	template< typename ... args > \
	_name(const std::string & _what, args ... _args	)\
		: std::exception(), \
			what_( yprintf( _what.c_str(), _args ... ) ) \
	{ \
	} \
\
\
	virtual ~_name () noexcept override {}\
\
\
	virtual const char* what() const throw () override \
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
