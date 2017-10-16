//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef LOG_CALLBACK_B451A9E6_FCDE_44DB_B821_5F838D942994
#define LOG_CALLBACK_B451A9E6_FCDE_44DB_B821_5F838D942994

#include "hermes_backward_compatibility.hpp"


#ifndef SX_NO_LOGGING

#include "essentials/compatibility/compatibility.hpp"

namespace hermes
{


//!\interface log_callback
//!\brief Interface that adds wait functionality to the class that implements it.
class log_callback
{
public:
	log_callback()
	{
		// Nothing to do...
	}


	virtual ~log_callback() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	//!\brief Wait for a condition.
	virtual void wait() = 0;
	
	//!\brief The thing we are waiting for is done.
	virtual void done() = 0;

	//!\brief Checks the thing we are waiting for is done.
	virtual bool is_done() = 0;
};


}


#endif


#endif
