//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////
				 

#ifndef Y_NO_LOGGING

#include "color_mapping.hpp"

#include <algorithm>
#include <locale>


namespace sxy
{

#ifndef Y_CPP03_BOOST


color_mapping::color_mapping()
	: color_map_(
	{
		{ log_level::LL_FATAL, color::C_RED }, { log_level::LL_ERROR, color::C_DARK_RED },
		{ log_level::LL_ASSERT, color::C_DARK_RED }, { log_level::LL_WARN, color::C_YELLOW },
		{ log_level::LL_INFO,	color::C_DARK_YELLOW }, { log_level::LL_DEBUG, color::C_DARK_GREEN }, 
		{ log_level::LL_TRACE,color::C_DARK_GREEN }, { log_level::LL_SPAM, color::C_GREEN }
	} )
{
	// Nothing to do...
}


#else


	color_mapping::color_mapping()		
	{
		color_map_[ log_level::LL_FATAL ] = color::C_RED; 
		color_map_[ log_level::LL_ERROR ] = color::C_DARK_RED;
		color_map_[ log_level::LL_ASSERT ] = color::C_DARK_RED;
		color_map_[ log_level::LL_WARN ] = color::C_YELLOW;
		color_map_[ log_level::LL_INFO ] = color::C_DARK_YELLOW;
		color_map_[ log_level::LL_DEBUG ] = color::C_DARK_GREEN;
		color_map_[ log_level::LL_TRACE ] = color::C_DARK_GREEN;
		color_map_[ log_level::LL_SPAM ] = color::C_GREEN;
	}	


#endif


color_mapping::~color_mapping() Y_NOEXCEPT
{
	// Nothing to do...
}


color color_mapping::get_color( const sxy::log_level _log_level ) const
{
	color color_to_use = color::C_WHITE;	
	color_map::const_iterator search = color_map_.find( _log_level );
	if (search != color_map_.end())
	{
		color_to_use = search->second;
	}		
	return( color_to_use );
}	 


}


#endif
