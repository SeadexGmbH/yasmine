//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ASYNC_BEHAVIOR_A799E0CD_DD3E_45EA_BF47_586C94FC32CB
#define ASYNC_BEHAVIOR_A799E0CD_DD3E_45EA_BF47_586C94FC32CB


#include "essentials/non_copyable.hpp"
#include "essentials/compatibility/thread.hpp"

#include "async_behavior_fwd.hpp"


namespace sxy
{


class event;
class simple_state_base;
class async_event_handler;
class event_collector;


class async_behavior	
{


public:
	async_behavior();
	virtual ~async_behavior() SX_NOEXCEPT;
	SX_NO_COPY(async_behavior)
	void run( const event& _event, event_collector& _event_collector, const simple_state_base& _simple_state, async_event_handler& _async_event_handler );
	void halt_and_join();
											 
protected:
	bool should_stop() const;
											

private:		
	void work( const event& _event, event_collector& _event_collector, const simple_state_base& _simple_state, 
		async_event_handler& _async_event_handler );
	virtual void run_impl( const event& _event, event_collector& _event_collector, 
		async_event_handler& _async_event_handler ) = 0;
	virtual void notify_should_stop();
	void join();		

	sxe::SX_UNIQUE_PTR<sxe::thread> worker_;
	mutable sxe::mutex mutex_;
	bool run_;


};


}


#endif
