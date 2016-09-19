//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_EVENT_PROCESSOR_H
#define T_EVENT_PROCESSOR_H


#include <memory>
#include <deque>

#include <mutex>
#include <condition_variable>
#include <thread>


#include "t_state_machine.h"


namespace sxy
{


// !\class t_async_state_machine
// !\brief Class for the "multi-threaded version" of the state machine. Provides methods to start and halt the state
// machine and to fire events.
class t_async_state_machine final:
	public t_state_machine
{
public:
	// !\brief Constructor of t_async_state_machine.
	// !\param p_name Name of the state machine.
	// !\param p_event_processing_callback Event processing callback interface pointer. It can be a nullptr if no callback
	// interface should be used.
	explicit t_async_state_machine(	const std::string& p_name, 
		i_event_processing_callback* const p_event_processing_callback = nullptr );
	virtual ~t_async_state_machine() override;
	t_async_state_machine( const t_async_state_machine& ) = delete;
	t_async_state_machine& operator=( const t_async_state_machine& ) = delete;

	// !\brief Enqueue the given event for firing.
	// !\param p_event Event to be fired.
	// !\return true if event was successfully enqueued for firing, else false. It returns false if the enqueue for firing
	// of the event is not possible because
	// the state machine was stopped in the meantime (or was never started).
	// Firing the event enqueues the event for being processed.
	virtual bool fire_event( const t_event_sptr& p_event ) override;

	// !\brief Starts the state machine.	When starting the state machine, the initial transitions are searched and
	// executed. Without running the state machine,
	// it is not possible to fire events.
	// !\return If the state machine reaches a terminate pseudostate after starting (on calling run), returns true. Else
	// if the state machine is started and running, returns false.
	bool run();

	// !\brief Stops the state machine. When stopping the state machine, all the events remaining in the queue of events
	// will be fired and the event processing thread
	// will be then stopped and joined.
	// !\return void
	void halt();


protected:
	void start();
	void stop();
	void join();


private:
	using t_thread_uptr = std::unique_ptr< std::thread >;
	enum class t_status
	{
		NEW, STARTED, STOP_REQUESTED, STOPPED
	};

	bool enqueue( const t_event_sptr p_event );
	bool wait_predicate() const;
	void work();


	t_status m_status;
	std::mutex m_run_and_event_mutex;
	std::condition_variable m_run_and_event_condition;
	t_thread_uptr m_worker_thread;
	bool m_run;
	std::deque< t_event_sptr > m_event_queue;
};


}


#endif
