//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "log_message.h"


namespace sxy
{


log_message::log_message( const log_level _log_level, const std::string& _log_time_stamp, 
	const std::string&  _log_file,	const int _log_line,	const std::string& _log_message )
	: log_level_message_( _log_level ),
		log_time_stam_( _log_time_stamp ),
		log_file_( _log_file ),
		log_line_( _log_line ),
		log_message_( _log_message )
{
	// Nothing to do...
}


}
