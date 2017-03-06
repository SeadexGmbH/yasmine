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


#ifndef LOG_CALLBACK_B451A9E6_FCDE_44DB_B821_5F838D942994
#define LOG_CALLBACK_B451A9E6_FCDE_44DB_B821_5F838D942994


#include "compatibility.hpp"


namespace sxy
{


class log_callback
{
public:
	log_callback()
	{
		// Nothing to do...
	}


	virtual ~log_callback() Y_NOEXCEPT
	{
		// Nothing to do...
	}


	virtual void wait() = 0;
	virtual void done() = 0;
	virtual bool is_done() = 0;
};
		
}


#endif


#endif
