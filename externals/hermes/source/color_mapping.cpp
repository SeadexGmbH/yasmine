//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SX_NO_LOGGING


#include "hermes/color_mapping.hpp"

#include <algorithm>
#include <locale>


namespace hermes
{

#ifndef SX_CPP03_BOOST


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


color_mapping::~color_mapping() SX_NOEXCEPT
{
	// Nothing to do...
}


color color_mapping::get_color( const hermes::log_level _log_level ) const
{
	color color_to_use( color::C_WHITE );
	color_map::const_iterator search = color_map_.find( _log_level );
	if (search != color_map_.end())
	{
		color_to_use = search->second;
	}
	return( color_to_use );
}


}


#endif
