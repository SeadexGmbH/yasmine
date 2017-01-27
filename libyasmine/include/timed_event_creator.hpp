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


#include <set>

#include "event_creation_request_time_comparer.hpp"
#include "event_creation_request.hpp"
#include "thread.hpp"


namespace sxy
{


class async_state_machine;


typedef std::set< event_creation_request, event_creation_request_time_comparer > event_queue;

//!\class	timed_event_creator
//!\brief Provides the possibility to create timed events. It uses the state machine passed into the constructor as
//!target for the events.
class timed_event_creator Y_FINAL
{
public:
	//!\brief Constructor of timed_event_creator.
	//!\param _async_state_machine - state_machine the created events are sent to.
	explicit timed_event_creator( async_state_machine& _async_state_machine );
	~timed_event_creator() Y_NOEXCEPT;
	Y_NO_COPY(timed_event_creator)

	//!\brief Creates an event creation request.
	//!\param _time_till_event_is_fired The time point when the event should be fired.
	//!\param _event The event that will be fired.
	//!\return Handle of the new event creation request. The handle can be used for canceling the request.
	//!\sa cancel()
	handle_type create_event_creation_request( 
		const sxy::time_point< sxy::system_clock >& _time_till_event_is_fired,	
		const event_sptr _event );

	//!\brief Creates an event creation request.
	//!\param _time The time duration after that the event should be fired.
	//!\param _event The event that will be fired.
	//!\return Handle of the new event creation request. The handle can be used for canceling the request.
	//!\sa cancel()
	handle_type create_event_creation_request( const sxy::milliseconds& _time,	const event_sptr& _event );

	//!\brief Cancels the event creation request with the given handle if the event is still in the queue of the event
	//!creator.
	//!\param	_handle const handle_type Handle of the event creation request that should be canceled.
	//!\return true if the event was canceled or false if the event could not be canceled.
	//!\sa create()
	bool cancel( const handle_type _handle );

	//!\brief Starts the event creator. This has to be called before creating timed events.
	//!\return void
	//!\sa halt(), join(), halt_and_join()
	void run();

	//!\brief Stops the event creator. The event creator needs to be stopped before it is destroyed (if it was started).
	//!Else the internal thread will not be cleaned-up correctly.
	//!\return void
	//!\sa run(), join(), halt_and_join()
	void halt();

	//!\brief Joins the event creator thread.	
	//!\return void
	//!\sa run(), stop(), halt_and_join()
	void join();

	//!\brief Stops and joins the event creator thread. The event creator needs to be stopped before it is destroyed (if it was started).
	//!Else the internal thread will not be cleaned-up correctly.
	//!\return void
	//!\sa run(), join(), halt()
	void halt_and_join();


private:
	// cppcheck-suppress unusedPrivateFunction
	handle_type generate_handle();
	bool check_if_handle_exists( const handle_type _handle ) const;
	void generate_event();
	event_queue::const_iterator find_element_by_handle( const handle_type _handle ) const;
	static bool compare_handles( const handle_type _handle, const event_creation_request& _event_creation_request );
	bool check_wait_condition() const;
	
	async_state_machine& state_machine_;
	event_queue event_creation_requests_;
	Y_UNIQUE_PTR< sxy::thread > worker_;
	sxy::mutex mutex_;
	sxy::condition_variable condition_variable_;
	bool run_;

	handle_type maximum_handle_;


};


}


#endif
