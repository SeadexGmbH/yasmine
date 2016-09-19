//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_LOG_MESSAGE_H
#define T_LOG_MESSAGE_H


#include <string>

#include "t_log_level.h"


namespace sxy
{


struct t_log_message final
{
	t_log_message() = default;
	t_log_message( const t_log_level p_log_level,	const std::string& p_log_time_stamp, const std::string&  p_log_file,
		const int p_log_line,	const std::string& p_log_message );


	t_log_level m_log_level_message;
	std::string m_log_time_stamp;
	std::string m_log_file;
	int m_log_line;
	std::string m_log_message;
};


}


#endif
