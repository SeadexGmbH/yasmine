//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SX_NO_LOGGING


#include "hermes/std_timestamp_policy.hpp"

#include <sstream>
#include <iomanip>

#include <ctime>


namespace hermes
{


namespace
{


const unsigned int WIDTH_YEAR( 4 );
const unsigned int WIDTH_CLOCK( 2 );
const char FILL_VALUE( '0' );
const unsigned int YEAR_1900( 1900 );
const char DATE_DELIMITER( '/' );
const char TIME_DELIMITER( ':' );
const char SPACE_SEPARATOR( ' ' );


}


std::string std_timestamp_policy::get_timestamp()
{
	std::stringstream date_time_stream;
	time_t rawtime;
	time( &rawtime );
	tm timeinfo = *localtime( &rawtime );
	date_time_stream << std::setfill( FILL_VALUE ) << std::setw( WIDTH_YEAR ) << ( YEAR_1900 + timeinfo.tm_year ) <<
		DATE_DELIMITER << std::setfill( FILL_VALUE ) << std::setw( WIDTH_CLOCK ) << ++timeinfo.tm_mon << DATE_DELIMITER <<
		std::setfill( FILL_VALUE ) << std::setw( WIDTH_CLOCK ) << timeinfo.tm_mday << SPACE_SEPARATOR << std::setfill( FILL_VALUE ) <<
		std::setw( WIDTH_CLOCK ) << timeinfo.tm_hour << TIME_DELIMITER << std::setfill( FILL_VALUE ) <<
		std::setw( WIDTH_CLOCK ) << timeinfo.tm_min << TIME_DELIMITER << std::setfill( FILL_VALUE ) <<
		std::setw( WIDTH_CLOCK ) << timeinfo.tm_sec;
	return( date_time_stream.str() );
}


}


#endif
