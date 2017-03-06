//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef Y_NO_LOGGING

#ifndef LOGGER_4207DA98_D8C1_41B4_B5B1_29E8C5A22DF3
#define LOGGER_4207DA98_D8C1_41B4_B5B1_29E8C5A22DF3


#include "logger_fwd.hpp"
#include "non_copyable.hpp"


namespace sxy
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


	virtual ~logger() Y_NOEXCEPT
	{
		// Nothing to do...
	}


	Y_NO_COPY(logger)	

	//!\brief Log the message to the target medium.
	//!\param _log_message Message to be logged.
	//!\return void
	virtual void log( const log_message& _log_message ) = 0;
};


}


#endif

#endif
