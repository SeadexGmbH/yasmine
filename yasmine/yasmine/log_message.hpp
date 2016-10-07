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


#ifndef LOG_MESSAGE_2F81F136_9F98_4FE3_A47A_9DEBB9538995
#define LOG_MESSAGE_2F81F136_9F98_4FE3_A47A_9DEBB9538995


#include <string>

#include "log_level.hpp"


namespace sxy
{


struct log_message final
{
	log_message() = default;
	log_message( const log_level _log_level, const std::string& _time_stamp, const std::string& _file,
		const int _line, const std::string& _message );


	log_level log_level_;
	std::string time_stamp_;
	std::string file_;
	int line_;
	std::string message_;
};


}


#endif

#endif
