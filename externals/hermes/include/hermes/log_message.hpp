//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef LOG_MESSAGE_2F81F136_9F98_4FE3_A47A_9DEBB9538995
#define LOG_MESSAGE_2F81F136_9F98_4FE3_A47A_9DEBB9538995

#include "hermes_backward_compatibility.hpp"


#ifndef SX_NO_LOGGING


#include "log_level.hpp"
#include "essentials/compatibility/compatibility.hpp"


namespace hermes
{


class log_callback;


//!\struct log_message
//!\brief Structure of the message to be logged, containing all necessary elements: log callback (if it is used), 
//!\log level, time stamp of the log, file and line where the log is generated and the message of the log.
struct log_message SX_FINAL
{
	//!\brief Constructor
	log_message();

	//!\brief Constructor
	//!\param _log_callback Pointer to log callback.
	//!\param _log_level Log level for this log message.
	//!\param _time_stamp Time stamp of the log message.
	//!\param _file File where the log message was generated.
	//!\param _line Line of the file where the log message is generated.
	//!\param _message The message of the log.
	log_message( log_callback* _log_callback, const log_level _log_level, const std::string& _time_stamp, 
		const std::string& _file,	const int _line, const std::string& _message );

	//!\brief Function that notifies the log callback that we are done.
	void done();

	log_level log_level_;
	std::string time_stamp_;
	std::string file_;
	int line_;
	std::string message_;
	log_callback* log_callback_;
};


}


#endif

#endif
