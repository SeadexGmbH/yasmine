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


#include "waiter.hpp"


namespace sxy
{


waiter::waiter()
	: done_mutex_(),
		done_condition_variable_(),
		done_()
{
	// Nothing to do...
}


waiter::~waiter() Y_NOEXCEPT
{
	// Nothing to do...
}


void waiter::wait()
{
	sxy::unique_lock<sxy::mutex> lock( done_mutex_ );	
	done_condition_variable_.wait( lock, sxy::bind( &waiter::is_done, this ) );
}


void waiter::done()
{
	sxy::lock_guard<sxy::mutex> lock( done_mutex_ );
	done_ = true;
}


bool waiter::is_done()
{
	// no locking necessary, only used within wait of condition variable 
	return( done_ );
}


}


#endif
