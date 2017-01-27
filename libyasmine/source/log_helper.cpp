//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef Y_CPP03_BOOST

#include "log_helper.hpp"

#include "yprintf.hpp"


namespace sxy
{


	log_helper::log_helper( const std::string& _file_name, const int _line )
		: file_name_(_file_name),
			line_(_line)
	{
		// Nothing to do...
	}


	log_helper::~log_helper() Y_NOEXCEPT
	{
		// Nothing to do...
	}
							 

	void log_helper::log( const log_level& _level, const std::string& _message ) const
	{
		sxy::log_manager_template<sxy::std_timestamp_policy>& l_log_manager = log_manager::get_instance();
			if( _level <= l_log_manager.get_log_level() )
			{
				l_log_manager.log( _level, log_manager::get_instance().get_timestamp(), file_name_, line_, _message );
			}
	}

}
	

#endif
