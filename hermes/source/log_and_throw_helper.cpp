//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifdef SX_CPP03_BOOST


#include "hermes/log_and_throw_helper.hpp"

#include "essentials/sxprintf.hpp"


namespace hermes
{


	log_and_throw_helper::log_and_throw_helper( const std::string& _file_name, const int _line )
		: file_name_( _file_name ),
		line_( _line )
	{
		// Nothing to do...
	}


	log_and_throw_helper::~log_and_throw_helper() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	void log_and_throw_helper::log( const log_level& _level, const std::string& _message ) const
	{
		hermes::log_manager_template<hermes::std_timestamp_policy>& l_log_manager = hermes::log_manager::get_instance();
		if( _level <= l_log_manager.get_log_level() )
		{
			l_log_manager.log( _level, hermes::log_manager::get_instance().get_timestamp(), file_name_, line_, _message );
		}
		throw sxe::exception( _message );
	}

}


#endif
