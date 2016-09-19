//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_EXCEPTION_TEMPLATE_6EFED438_B578_4EF6_B02A_53DC49B89A0D
#define T_EXCEPTION_TEMPLATE_6EFED438_B578_4EF6_B02A_53DC49B89A0D


#include <exception>
#include <string>

#include "yprintf.h"


//!\def Y_EXCEPTION( p_name )
//!\brief The macro creates an exception class inheriting the std::exception with the given name. It also supports creating messages with placeholders by calling yprintf.
//!\sa yprintf
#define Y_EXCEPTION( p_name ) \
class p_name: public std::exception \
{ \
public: \
		template<typename ... tt_args> \
		p_name \
		( \
			const std::string& p_what, \
			tt_args ... p_args \
		): \
			std::exception(), \
			m_what( yprintf( p_what.c_str(), p_args... ) ) \
{ \
} \
\
\
		virtual \
		~p_name \
		( \
		) override \
		{ \
		} \
\
\
		virtual const char* what() const throw() override \
		{ \
			return ( m_what.c_str() ); \
		} \
\
\
private: \
		std::string m_what; \
\
\
};


#endif
