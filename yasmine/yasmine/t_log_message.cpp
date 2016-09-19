//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_log_message.h"


namespace sxy
{


t_log_message::t_log_message( const t_log_level p_log_level, const std::string& p_log_time_stamp, 
	const std::string&  p_log_file,	const int p_log_line,	const std::string& p_log_message )
	: m_log_level_message( p_log_level ),
		m_log_time_stamp( p_log_time_stamp ),
		m_log_file( p_log_file ),
		m_log_line( p_log_line ),
		m_log_message( p_log_message )
{
	// Nothing to do...
}


}
