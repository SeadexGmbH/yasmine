//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SX_NO_LOGGING


#include "hermes/log_level.hpp"

#include "essentials/base.hpp"


namespace hermes
{


std::string log_level_to_string( const log_level _log_level )
{
	std::string log_level_string = "???";

#ifndef SX_CPP03_BOOST
	switch( _log_level )
#else
	switch (_log_level.value_)
#endif
	{
	case ( log_level::LL_FATAL ):
	{
		log_level_string = "FATAL";
	}
	break;

	case ( log_level::LL_ERROR ):
	{
		log_level_string = "ERROR";
	}
	break;

	case ( log_level::LL_ASSERT ):
	{
		log_level_string = "ASSERT";
	}
	break;

	case ( log_level::LL_WARN ):
	{
		log_level_string = "WARN";
	}
	break;

	case ( log_level::LL_INFO ):
	{
		log_level_string = "INFO";
	}
	break;

	case ( log_level::LL_DEBUG ):
	{
		log_level_string = "DEBUG";
	}
	break;

	case ( log_level::LL_TRACE ):
	{
		log_level_string = "TRACE";
	}
	break;

	case ( log_level::LL_SPAM ):
	{
		log_level_string = "SPAM";
	}
	break;

	default:
		SX_ASSERT( false, "Unknown log level!" );
		break;
	}
	 

	return( log_level_string );
}


#ifdef SX_CPP03_BOOST


// cppcheck-suppress unusedFunction
bool operator==(const hermes::log_level& _lhs, const hermes::log_level::inner _rhs)
{
	return( _lhs.value_ == _rhs );
}


bool operator==(const hermes::log_level::inner _lhs, const hermes::log_level& _rhs)
{
	return( _lhs == _rhs.value_ );
}


// cppcheck-suppress unusedFunction
bool operator<(const hermes::log_level _lhs, const hermes::log_level _rhs)
{
	return ( _lhs.value_ < _rhs.value_ );
}


// cppcheck-suppress unusedFunction
bool operator<=( const hermes::log_level _lhs, const hermes::log_level _rhs )
{
	return ( _lhs.value_ <= _rhs.value_ );
}


#endif


}


#endif
