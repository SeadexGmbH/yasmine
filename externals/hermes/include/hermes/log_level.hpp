//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef LOG_LEVEL_5059A1FA_DC2D_4C94_AA8B_49B750B30F07
#define LOG_LEVEL_5059A1FA_DC2D_4C94_AA8B_49B750B30F07

#include "hermes_backward_compatibility.hpp"


#ifndef SX_NO_LOGGING


#include <string>


namespace hermes
{


#ifndef SX_CPP03_BOOST


//!\enum log_level
//!\brief The log levels.
enum class log_level
{
	LL_OFF = -1, LL_ASSERT = 0, LL_FATAL = 1, LL_ERROR = 2, LL_WARN = 3, LL_INFO = 4, LL_DEBUG = 5, LL_TRACE = 6, LL_SPAM = 7
};


#else


//!\struct log_level
//!\brief Structure representing a log level (enum wrapper for C++11 enum class like behavior).
struct log_level
{
	//!\enum log_level
	//!\brief The log levels.
	enum inner 
	{
		LL_OFF = -1, LL_ASSERT = 0, LL_FATAL = 1, LL_ERROR = 2, LL_WARN = 3, LL_INFO = 4, LL_DEBUG = 5, LL_TRACE = 6, LL_SPAM = 7
	};


	//!\brief Constructor
	//!\param _value Given log level value that is represented by the structure.
	log_level( inner _value ) : value_( _value )
	{
		// Nothing to do...
	}


	//!\brief Constructor. Default value is LL_OFF.
	log_level() : value_( LL_OFF )
	{
		// Nothing to do...
	}


	//!\brief Constructor
	//!\param _color Given log level structure containing the log level value that is represented by the structure.
	log_level(const log_level& _log_level) : value_(_log_level.value_)
	{
		// Nothing to do...
	}


	//!\brief Function returning the log level value represented by the structure.
	operator inner() const
	{
		return ( value_ );
	}


	//!\brief Log level value represented by the structure.
	inner value_;

};


#endif



//!\brief Convert the given log level to a string.
//!\param _log_level The log level.
//!\return The log level as string.
std::string log_level_to_string( const log_level _log_level );



#ifdef SX_CPP03_BOOST


bool operator==( const hermes::log_level& _lhs, const hermes::log_level::inner _rhs );
bool operator==( const hermes::log_level::inner _lhs, const hermes::log_level& _rhs );
bool operator<(const hermes::log_level _lhs, const hermes::log_level _rhs);
bool operator<=( const hermes::log_level _lhs, const hermes::log_level _rhs );


#endif


}


#endif


#endif
