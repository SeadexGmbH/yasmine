//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ASYNC_BEHAVIOUR_IMPL_2B8FEEBB_B698_4333_A90E_5686B143B1C1
#define ASYNC_BEHAVIOUR_IMPL_2B8FEEBB_B698_4333_A90E_5686B143B1C1


#include "non_copyable.hpp"
#include "async_behaviour_fwd.hpp"
#include "thread.hpp"


namespace sxy
{


class event;
class simple_state_base;
class async_event_handler;


class async_behaviour	
{


public:
	async_behaviour();
	virtual ~async_behaviour() Y_NOEXCEPT;
	Y_NO_COPY(async_behaviour)
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
