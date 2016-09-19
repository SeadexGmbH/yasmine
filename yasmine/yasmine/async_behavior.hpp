//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ASYNC_BEHAVIOR_IMPL_2B8FEEBB_B698_4333_A90E_5686B143B1C1
#define ASYNC_BEHAVIOR_IMPL_2B8FEEBB_B698_4333_A90E_5686B143B1C1


#include <mutex>
#include <thread>
#include <memory>

#include "async_behavior_fwd.hpp"


namespace sxy
{


class event;
class simple_state_base;
class async_event_handler;


class async_behavior	
{


public:
	async_behavior();
	virtual ~async_behavior() noexcept;
	async_behavior( const async_behavior& ) = delete;
	async_behavior& operator=( const async_behavior& ) = delete;

	void start( const event& _event, const simple_state_base& _simple_state, async_event_handler& _async_event_handler );
	void stop();		

protected:
	bool should_stop() const;
											

private:	
	void run( const event& _event, const simple_state_base& _simple_state, async_event_handler& _async_event_handler );
	virtual void run_impl( const event& _event, async_event_handler& _async_event_handler ) = 0;
	virtual void notify_should_stop();
	void join();		

	std::unique_ptr<std::thread> worker_;
	mutable std::mutex mutex_;
	bool run_;


};


}


#endif
