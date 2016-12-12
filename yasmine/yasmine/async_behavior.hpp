//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ASYNC_BEHAVIOR_A799E0CD_DD3E_45EA_BF47_586C94FC32CB
#define ASYNC_BEHAVIOR_A799E0CD_DD3E_45EA_BF47_586C94FC32CB


#include "non_copyable.hpp"
#include "async_behavior_fwd.hpp"
#include "thread.hpp"


namespace sxy
{


class event;
class simple_state_base;
class async_event_handler;


class async_behavior	
{


public:
	async_behavior();
	virtual ~async_behavior() Y_NOEXCEPT;
	Y_NO_COPY(async_behavior)
	void start( const event& _event, const simple_state_base& _simple_state, async_event_handler& _async_event_handler );
	void stop();		

protected:
	bool should_stop() const;
											

private:	
	void run( const event& _event, const simple_state_base& _simple_state, async_event_handler& _async_event_handler );
	virtual void run_impl( const event& _event, async_event_handler& _async_event_handler ) = 0;
	virtual void notify_should_stop();
	void join();		

	sxy::Y_UNIQUE_PTR<sxy::thread> worker_;
	mutable sxy::mutex mutex_;
	bool run_;


};


}


#endif
