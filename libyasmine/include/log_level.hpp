//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef Y_NO_LOGGING

#ifndef LOG_LEVEL_5059A1FA_DC2D_4C94_AA8B_49B750B30F07
#define LOG_LEVEL_5059A1FA_DC2D_4C94_AA8B_49B750B30F07


#include <string>


namespace sxy
{


#ifndef Y_CPP03_BOOST


//!\brief Enum class for log levels.
enum class log_level
{
	LL_OFF = -1, LL_ASSERT = 0, LL_FATAL = 1, LL_ERROR = 2, LL_WARN = 3, LL_INFO = 4, LL_DEBUG = 5, LL_TRACE = 6, LL_SPAM = 7
};


#else

struct log_level
{
	enum inner 
	{
		LL_OFF = -1, LL_ASSERT = 0, LL_FATAL = 1, LL_ERROR = 2, LL_WARN = 3, LL_INFO = 4, LL_DEBUG = 5, LL_TRACE = 6, LL_SPAM = 7
	};


	// cppcheck-suppress noExplicitConstructor
	log_level( inner _value ) : value_( _value )
	{
		// Nothing to do...
	}


	// cppcheck-suppress noExplicitConstructor
	log_level() : value_( LL_OFF )
	{
		// Nothing to do...
	}


	// cppcheck-suppress noExplicitConstructor
	log_level(const log_level& _log_level) : value_(_log_level.value_)
	{
		// Nothing to do...
	}


	// cppcheck-suppress functionConst
	operator inner()
	{
		return ( value_ );
	}


	inner value_;

};


#endif



//!\brief Convert the given log level to a string.
//!\param _log_level - The log level.
//!\return The log level as string.
std::string log_level_to_string( const log_level _log_level );	



#ifdef Y_CPP03_BOOST
																																							

bool operator==( const sxy::log_level& _lhs, const sxy::log_level::inner _rhs );
bool operator==( const sxy::log_level::inner _lhs, const sxy::log_level& _rhs );
bool operator<(const sxy::log_level _lhs, const sxy::log_level _rhs);
bool operator<=( const sxy::log_level _lhs, const sxy::log_level _rhs );
							


#endif


}


#endif


#endif
