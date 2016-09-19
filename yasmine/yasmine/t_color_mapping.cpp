//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_color_mapping.h"

#include <algorithm>
#include <locale>


namespace sxy
{


t_color_mapping::t_color_mapping()
	: m_color_map(
	{
		{ t_log_level::LL_FATAL, t_color::C_RED }, { t_log_level::LL_ERROR, t_color::C_DARK_RED  },
		{ t_log_level::LL_ASSERT, t_color::C_DARK_RED }, { t_log_level::LL_WARN, t_color::C_YELLOW },
		{ t_log_level::LL_INFO,	t_color::C_DARK_YELLOW }, { t_log_level::LL_DEBUG, t_color::C_DARK_GREEN }, 
		{ t_log_level::LL_TRACE,t_color::C_DARK_GREEN }, { t_log_level::LL_SPAM, t_color::C_GREEN }, 
		{ t_log_level::LL_PROTOCOL, t_color::C_BLUE } 
	} )
{
	// Nothing to do...
}


t_color t_color_mapping::get_color( const sxy::t_log_level p_log_level )
{
	return( m_color_map[ p_log_level ] );
}


}
