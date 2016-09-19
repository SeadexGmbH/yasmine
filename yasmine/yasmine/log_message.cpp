//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "log_message.hpp"


namespace sxy
{


log_message::log_message( const log_level _log_level, const std::string& _time_stamp, 
	const std::string&  _file, const int _line,	const std::string& _message )
	: log_level_( _log_level ),
		time_stamp_( _time_stamp ),
		file_( _file ),
		line_( _line ),
		message_( _message )
{
	// Nothing to do...
}


}
