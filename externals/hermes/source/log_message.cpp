//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SX_NO_LOGGING


#include "hermes/log_message.hpp"
#include "hermes/log_callback.hpp"


namespace hermes
{


log_message::log_message()
	: log_level_(),
		time_stamp_(),
		file_(),
		line_(),
		message_(),
		log_callback_()
{
	// Nothing to do...
}


log_message::log_message( log_callback* _log_callback, const log_level _log_level, const std::string& _time_stamp,
	const std::string&  _file, const int _line, const std::string& _message )
	: log_level_( _log_level ),
		time_stamp_( _time_stamp ),
		file_( _file ),
		line_( _line ),
		message_( _message ),
		log_callback_( _log_callback )
{
	// Nothing to do...
}


void log_message::done()
{
	if( log_callback_ )
	{
		log_callback_->done();
	}
}


}


#endif
