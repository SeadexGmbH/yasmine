//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_std_timestamp_policy.h"


//#include <chrono>
#include <sstream>
#include <iomanip>

#include<ctime>


namespace sxy
{


namespace
{


const unsigned int g_width_year( 4 );
const unsigned int g_width_clock( 2 );
const char g_fill_value( '0' );
const unsigned int g_1900( 1900 );


}


std::string
t_std_timestamp_policy::get_timestamp
(
)
{
	std::stringstream date_time_stream;
	
	time_t rawtime;
	time( &rawtime );

	tm timeinfo = *localtime( &rawtime );
	date_time_stream << std::setfill( g_fill_value ) << std::setw( g_width_year ) << ( g_1900 + timeinfo.tm_year)
		<< "/" << std::setfill( g_fill_value ) << std::setw( g_width_clock ) << ++timeinfo.tm_mon
		<< "/" << std::setfill( g_fill_value ) << std::setw( g_width_clock ) << timeinfo.tm_mday
		<< " " << std::setfill( g_fill_value ) << std::setw( g_width_clock ) << timeinfo.tm_hour
		<< ":" << std::setfill( g_fill_value ) << std::setw( g_width_clock ) << timeinfo.tm_min
		<< ":" << std::setfill( g_fill_value ) << std::setw( g_width_clock ) << timeinfo.tm_sec;

	return( date_time_stream.str() );
}


}
