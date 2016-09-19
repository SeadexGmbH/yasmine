//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "std_timestamp_policy.h"

#include <sstream>
#include <iomanip>

#include <ctime>


namespace sxy
{


namespace
{


const unsigned int WIDTH_YEAR( 4 );
const unsigned int WIDTH_CLOCK( 2 );
const char FILL_VALUE( '0' );
const unsigned int YEAR_1900( 1900 );


}


std::string std_timestamp_policy::get_timestamp()
{
	std::stringstream date_time_stream;
	time_t rawtime;
	time( &rawtime );
	tm timeinfo = *localtime( &rawtime );
	date_time_stream << std::setfill( FILL_VALUE ) << std::setw( WIDTH_YEAR ) << ( YEAR_1900 + timeinfo.tm_year ) <<
		"/" << std::setfill( FILL_VALUE ) << std::setw( WIDTH_CLOCK ) << ++timeinfo.tm_mon << "/" << std::setfill(
		FILL_VALUE ) << std::setw( WIDTH_CLOCK ) << timeinfo.tm_mday << " " << std::setfill( FILL_VALUE ) <<
		std::setw( WIDTH_CLOCK ) << timeinfo.tm_hour << ":" << std::setfill( FILL_VALUE ) <<
		std::setw( WIDTH_CLOCK ) << timeinfo.tm_min << ":" << std::setfill( FILL_VALUE ) <<
		std::setw( WIDTH_CLOCK ) << timeinfo.tm_sec;
	return( date_time_stream.str() );
}


}
