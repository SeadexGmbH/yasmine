//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ASYNC_STATE_MACHINE_5D531F9B_A0F2_47FF_BCFC_3264896355C5
#define ASYNC_STATE_MACHINE_5D531F9B_A0F2_47FF_BCFC_3264896355C5


#include <list>

#include "essentials/compatibility/thread.hpp"
#include "essentials/compatibility/chrono.hpp"

#include "state_machine_base.hpp"
#include "async_event_handler.hpp"
#include "state_machine_status.hpp"


namespace sxy
{


//!\class async_state_machine
//!\brief Class for the "multi-threaded version" of the state machine. Provides methods to start and halt the state
//! machine and to fire events.
class async_state_machine SX_FINAL:
	public state_machine_base, private async_event_handler
{
public:
	//!\brief Constructor of async_state_machine.
	//!\param _name Name of the state machine.
	//!\param _event_processing_callback Event processing callback interface pointer. It can be a nullptr if no callback
	//!interface should be used.
	explicit async_state_machine(	const std::string& _name, 
		event_processing_callback* const _event_processing_callback = SX_NULLPTR );
	virtual ~async_state_machine() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(async_state_machine)

	//!\brief Enqueue the given event for firing.
	//!\param _event Event to be fired.
	//!\return true if event was successfully enqueued for firing, else false. It returns false if the enqueue for firing
	//!of the event is not possible because the state machine was stopped in the meantime (or was never started).
	//!Firing the event enqueues the event for being processed.
	virtual bool fire_event( const event_sptr& _event ) SX_OVERRIDE;

	//!\brief Starts the state machine.	When starting the state machine, the initial transitions are searched and
	//!executed. Without running the state machine, it is not possible to fire events.
	//!\return If the state machine reaches a terminate pseudostate after starting (on calling run), returns false. Else
	//!if the state machine is started and running, returns true.
	//!\sa halt_and_join, halt, join
	virtual bool run() SX_OVERRIDE;

	//!\brief Stops and joins the state machine. When stopping the state machine, all the events remaining in the queue
	//!of events will be processed and the event processing thread will be then stopped and joined. The state machine
	//!will also check for active asynchronous simple states and will stop the do behavior for all of them.
	//!\return void	
	//!\sa halt, join, run
	void halt_and_join();

	//!\brief Stops the state machine. When stopping the state machine, all the events remaining in the queue
	//!of events will be processed and the event processing thread will be then stopped and joined. The state machine
	//!will also check for active asynchronous simple states and will stop the do behavior for all of them.
	//!\return void
	//!\sa halt_and_join, join, run
	virtual void halt() SX_OVERRIDE;

	//!\brief Joins the thread of the state machine.
	//!\return void
	//!\sa halt_and_join, halt, run
	void join();


	//!\brief Waiting given amount of time for the state machine to terminate (or to stop).
	//!\param _timeoutInMs Time in milliseconds to wait for the state machine to terminate.
	//!\return bool true if the state machine is terminated or stopped, false otherwise.
	//!\sa halt_and_join, halt, run, wait	
	bool wait( const sxe::milliseconds _timeoutInMs ) const;

	//!\brief Wait for the machine to terminate (or to stop).	
	//!\return void
	//!\sa halt_and_join, halt, run, wait
	void wait() const;

	//!\brief Check if the state machine is terminated or stopped.
	//!\return bool	true if the state machine is terminated or stopped, false otherwise.
	//!\sa halt_and_join, halt, run, wait
	bool terminated() const;

	
	//!\brief Enqueue the given event for firing.
	//!\param _event Event to be fired.
	//!\return true if event was successfully enqueued for firing, else false. It returns false if the enqueue for firing
	//!of the event is not possible because the state machine was stopped in the meantime (or was never started).
	//!Firing the event enqueues the event for being processed.
	virtual bool push( const event_sptr& _event ) SX_OVERRIDE;


protected:
	void start_state_machine();


private:	
	bool insert( const event_sptr& _event );	
	void insert_impl( const event_sptr& _event );
	bool wait_predicate() const;
	bool wait_stop_condition() const;
	void work();	
	
	//!\brief Sends a priority (internal) event and add it in the front of the event list, so it will be processed before other events.
	//!\return void
	virtual void on_event( const event_sptr& _event ) SX_OVERRIDE;

	virtual void interrupt_impl() SX_OVERRIDE;


	state_machine_status status_;
	mutable sxe::mutex run_and_event_mutex_;
	sxe::condition_variable run_and_event_condition_;
	mutable sxe::condition_variable terminated_condition_;
	sxe::SX_UNIQUE_PTR< sxe::thread > worker_thread_;
	std::list<event_sptr> event_list_;
};


}


#endif
