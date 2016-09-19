//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_log_level.h"

#include "base.h"


namespace sxy
{


std::string log_level_to_string( const t_log_level p_log_level )
{
	std::string log_level_string = "???";

	switch( p_log_level )
	{
	case ( t_log_level::LL_FATAL ):
	{
		log_level_string = "FATAL";
	}
	break;

	case ( t_log_level::LL_ERROR ):
	{
		log_level_string = "ERROR";
	}
	break;

	case ( t_log_level::LL_ASSERT ):
	{
		log_level_string = "ASSERT";
	}
	break;

	case ( t_log_level::LL_WARN ):
	{
		log_level_string = "WARN";
	}
	break;

	case ( t_log_level::LL_INFO ):
	{
		log_level_string = "INFO";
	}
	break;

	case ( t_log_level::LL_DEBUG ):
	{
		log_level_string = "DEBUG";
	}
	break;

	case ( t_log_level::LL_TRACE ):
	{
		log_level_string = "TRACE";
	}
	break;

	case ( t_log_level::LL_SPAM ):
	{
		log_level_string = "SPAM";
	}
	break;

	case ( t_log_level::LL_PROTOCOL ):
	{
		log_level_string = "PROTOCOL";
	}
	break;

	default:
		Y_ASSERT_NO_LOG( false, "Unknown log level!" );
		break;
	}

	return( log_level_string );
}


}
