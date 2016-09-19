//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TIMED_EVENT_CREATOR_14DCF0FF_0E5B_41DE_B213_C7CC1610A406
#define TIMED_EVENT_CREATOR_14DCF0FF_0E5B_41DE_B213_C7CC1610A406


#include <thread>
#include <mutex>
#include <condition_variable>
#include <memory>

#include <set>

#include "event_creation_request_time_comparer.h"


namespace sxy
{


class async_state_machine;
class event_creation_request;
using event_queue = std::set< std::unique_ptr< event_creation_request >, event_creation_request_time_comparer >;

// !\class	timed_event_creator
// !\brief Provides the possibility to create timed events. It uses the state machine passed into the constructor as
// target for the events.
class timed_event_creator final
{
public:
	// !\brief Constructor of timed_event_creator.
	// !\param _state_machine - state_machine the created events are sent to.
	explicit timed_event_creator( async_state_machine& _async_state_machine );
	~timed_event_creator();
	timed_event_creator( const timed_event_creator& ) = delete;
	timed_event_creator& operator=( const timed_event_creator& ) = delete;

	// !\brief Creates an event creation request.
	// !\param _time_till_event_is_fired The time point when the event should be fired.
	// !\param _event The event that will be fired.
	// !\return Handle of the new event creation request. The handle can be used for canceling the request.
	// !\sa cancel()
	int create_event_creation_request( 
		const std::chrono::time_point< std::chrono::system_clock >& _time_till_event_is_fired,	
		const event_sptr _event );

	// !\brief Creates an event creation request.
	// !\param _time The time duration after that the event should be fired.
	// !\param _event The event that will be fired.
	// !\return Handle of the new event creation request. The handle can be used for canceling the request.
	// !\sa cancel()
	int create_event_creation_request( const std::chrono::milliseconds& _time,	const event_sptr& _event );

	// !\brief Cancels the event creation request with the given handle if the event is still in the queue of the event
	// creator.
	// !\param	_handle const int Handle of the event creation request that should be canceled.
	// !\return true if the event was canceled or false if the event could not be canceled.
	// !\sa create_event()
	bool cancel( const int _handle );

	// !\brief Starts the event creator. This has to be called before creating timed events.
	// !\return void
	// !\sa stop()
	void start();

	// !\brief Stops the event creator. The event creator needs to be stopped before it is destroyed (if it was started).
	// Else the internal thread will not be cleaned-up
	// correctly.
	// !\return void
	// !\sa start()
	void stop();


private:
	int generate_handle() const;
	bool check_if_handle_exists( const int _handle ) const;
	void generate_event();
	event_queue::const_iterator find_element_by_handle( const int _handle ) const;

	async_state_machine& state_machine_;
	event_queue event_creation_requests_;
	std::unique_ptr< std::thread > worker_;
	std::mutex mutex_;
	std::condition_variable condition_variable_;
	bool run_;
};


}


#endif
