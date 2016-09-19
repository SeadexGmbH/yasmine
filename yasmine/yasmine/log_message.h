//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef LOG_MESSAGE_2F81F136_9F98_4FE3_A47A_9DEBB9538995
#define LOG_MESSAGE_2F81F136_9F98_4FE3_A47A_9DEBB9538995


#include <string>

#include "log_level.h"


namespace sxy
{


struct log_message final
{
	log_message() = default;
	log_message( const log_level _log_level,	const std::string& _log_time_stamp, const std::string&  _log_file,
		const int _log_line,	const std::string& _log_message );


	log_level log_level_message_;
	std::string log_time_stam_;
	std::string log_file_;
	int log_line_;
	std::string log_message_;
};


}


#endif
