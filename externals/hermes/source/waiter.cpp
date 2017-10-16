//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SX_NO_LOGGING


#include "hermes/waiter.hpp"


namespace hermes
{


waiter::waiter()
	: done_mutex_(),
		done_condition_variable_(),
		done_()
{
	// Nothing to do...
}


waiter::~waiter() SX_NOEXCEPT
{
	// Nothing to do...
}


void waiter::wait()
{
	sxe::unique_lock<sxe::mutex> lock( done_mutex_ );
	done_condition_variable_.wait( lock, sxe::bind( &waiter::is_done, this ) );
}


void waiter::done()
{
	sxe::lock_guard<sxe::mutex> lock( done_mutex_ );
	done_ = true;
}


bool waiter::is_done()
{
	// no locking necessary, only used within wait of condition variable 
	return( done_ );
}


}


#endif
