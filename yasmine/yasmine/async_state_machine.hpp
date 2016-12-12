//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ASYNC_STATE_MACHINE_5D531F9B_A0F2_47FF_BCFC_3264896355C5
#define ASYNC_STATE_MACHINE_5D531F9B_A0F2_47FF_BCFC_3264896355C5


#include <list>

#include "thread.hpp"
#include "state_machine.hpp"
#include "async_event_handler.hpp"


namespace sxy
{


//!\class async_state_machine
//!\brief Class for the "multi-threaded version" of the state machine. Provides methods to start and halt the state
// machine and to fire events.
class async_state_machine Y_FINAL:
	public state_machine, private async_event_handler
{
public:
	//!\brief Constructor of async_state_machine.
	//!\param _name Name of the state machine.
	//!\param _event_processing_callback Event processing callback interface pointer. It can be a nullptr if no callback
	//!interface should be used.
	explicit async_state_machine(	const std::string& _name, 
		event_processing_callback* const _event_processing_callback = Y_NULLPTR );
	virtual ~async_state_machine() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(async_state_machine)

	//!\brief Enqueue the given event for firing.
	//!\param _event Event to be fired.
	//!\return true if event was successfully enqueued for firing, else false. It returns false if the enqueue for firing
	//!of the event is not possible because the state machine was stopped in the meantime (or was never started).
	//!Firing the event enqueues the event for being processed.
	virtual bool fire_event( const event_sptr& _event ) Y_OVERRIDE;

	//!\brief Starts the state machine.	When starting the state machine, the initial transitions are searched and
	//!executed. Without running the state machine, it is not possible to fire events.
	//!\return If the state machine reaches a terminate pseudostate after starting (on calling run), returns false. Else
	//!if the state machine is started and running, returns true.
	virtual bool start_state_machine() Y_OVERRIDE;

	//!\brief Stops the state machine. When stopping the state machine, all the events remaining in the queue of events
	//!will be processed and the event processing thread will be then stopped and joined. The state machine will also 
	//!check for active asynchronous simple states and will stop the do behavior for all of them.
	//!\return void
	virtual void stop_state_machine() Y_OVERRIDE;


protected:
	void start();
	void stop();
	void join();


private:
	typedef Y_UNIQUE_PTR< sxy::thread > thread_uptr;
	typedef sxy::function<void( const event_sptr _event )> queue_inserter;
#ifndef Y_CPP03_BOOST	
	enum class status
	{
		NEW, STARTED, STOP_REQUESTED, STOPPED
	};
#else
	struct status
	{
		enum inner
		{
			NEW, STARTED, STOP_REQUESTED, STOPPED
		};


		// cppcheck-suppress noExplicitConstructor
		status( const inner _value ) : value_( _value )
		{
			// Nothing to do...
		}


		// cppcheck-suppress functionConst
		operator inner()
		{
			return ( value_ );
		}


		inner value_;

	};
#endif

	bool insert( const event_sptr& _event );	
	void insert_impl( const event_sptr& _event );
	bool wait_predicate() const;
	void work();	
	
	//!\brief Sends a priority (internal) event and add it in the front of the event list, so it will be processed before other events.
	//!\return void
	virtual void on_event( const event_sptr& _event ) Y_OVERRIDE;


	status status_;
	sxy::mutex run_and_event_mutex_;
	sxy::condition_variable run_and_event_condition_;
	thread_uptr worker_thread_;
	bool run_;
	std::list<event_sptr> event_list_;
};


}


#endif
