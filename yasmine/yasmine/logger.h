//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef LOGGER_4207DA98_D8C1_41B4_B5B1_29E8C5A22DF3
#define LOGGER_4207DA98_D8C1_41B4_B5B1_29E8C5A22DF3


#include "logger_fwd.h"
#include "log_message.h"


namespace sxy
{


// !\interface logger
// !\brief Interface of the general logger. The specialized loggers derive from this interface.
class logger
{
public:
	// !\brief logger constructor.
	logger() = default;
	virtual ~logger() = default;
	logger( const logger& ) = delete;
	logger& operator=( const logger& ) = delete;

	// !\brief Log the message to the target medium.
	// !\param _log_message Message to be logged.
	// !\return void
	virtual void log( const log_message& _log_message ) = 0;
};


}


#endif
