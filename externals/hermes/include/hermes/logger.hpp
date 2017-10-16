//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef LOGGER_4207DA98_D8C1_41B4_B5B1_29E8C5A22DF3
#define LOGGER_4207DA98_D8C1_41B4_B5B1_29E8C5A22DF3

#include "hermes_backward_compatibility.hpp"


#ifndef SX_NO_LOGGING


#include "logger_fwd.hpp"
#include "essentials/non_copyable.hpp"


namespace hermes
{


struct log_message;


//!\interface logger
//!\brief Interface of the general logger. The specialized loggers derive from this interface.
class logger
{
public:
	//!\brief logger constructor.
	logger()
	{
		// Nothing to do...
	}


	virtual ~logger() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	SX_NO_COPY(logger)

	//!\brief Log the message to the target medium.
	//!\param _log_message Message to be logged.
	//!\return void
	virtual void log( const log_message& _log_message ) = 0;
};


}


#endif


#endif
