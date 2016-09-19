//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_TIMED_EVENT_CREATOR_14DCF0FF_0E5B_41DE_B213_C7CC1610A406
#define T_TIMED_EVENT_CREATOR_14DCF0FF_0E5B_41DE_B213_C7CC1610A406


#include <thread>
#include <mutex>
#include <condition_variable>
#include <memory>

#include <set>

#include "t_event_creation_request_time_comparer.h"


namespace sxy
{


class t_state_machine;
class t_event_creation_request;


using t_event_queue = std::set< std::unique_ptr<t_event_creation_request>, t_event_creation_request_time_comparer >;


//!\class	t_timed_event_creator t_timed_event_creator.h "t_timed_event_creator.h"
//!\brief Provides the possibility to create timed events. It uses the state machine passed into the constructor as target for the events.
class t_timed_event_creator final
{
public:
	//!\brief Constructor of t_timed_event_creator.
	//!\param p_state_machine -  t_state_machine the created events are sent to.
	explicit t_timed_event_creator
	(
		t_state_machine& p_state_machine
	);


	~t_timed_event_creator
	(
	);


	t_timed_event_creator
	(
		const t_timed_event_creator&
	) = delete;


	t_timed_event_creator&
	operator=
	(
		const t_timed_event_creator&
	) = delete;


	//!\brief Creates an event creation request.
	//!\param p_time_till_event_is_fired The time point when the event should be fired.
	//!\param p_event The event that will be fired.	
	//!\return Handle of the new event creation request. The handle can be used for canceling the request.
	//!\sa cancel()
	int
	create_event_creation_request
	(
		const std::chrono::time_point< std::chrono::system_clock >& p_time_till_event_is_fired,
		const t_event_sptr p_event
	);
	
	
	//!\brief Creates an event creation request.
	//!\param p_time The time duration after that the event should be fired.
	//!\param p_event The event that will be fired.	
	//!\return Handle of the new event creation request. The handle can be used for canceling the request.
	//!\sa cancel()
	int
	create_event_creation_request
	(
		const std::chrono::milliseconds& p_time,
		const t_event_sptr& p_event
	);
	
	
	//!\brief Cancels the event creation request with the given handle if the event is still in the queue of the event creator.
	//!\param	p_handle const int Handle of the event creation request that should be canceled.
	//!\return true if the event was canceled or false if the event could not be canceled.
	//!\sa create_event()
	bool
	cancel
	(
		const int p_handle
	);
	
	
	//!\brief Starts the event creator. This has to be called before creating timed events.
	//!\return void
	//!\sa stop()	
	void
	start
	(
	);
	
	
	//!\brief Stops the event creator. The event creator needs to be stopped before it is destroyed (if it was started). Else the internal thread will not be cleaned-up
	// correctly.
	//!\return void
	//!\sa start()
	void
	stop
	(
	);


private:
	int
	generate_handle
	(
	) const;


	bool
	check_if_handle_exists
	(
		const int p_handle
	) const;


	void
	generate_event
	(
	);


	t_event_queue::const_iterator
	find_element_by_handle
	(
		const int p_handle
	) const;


	t_state_machine& m_state_machine;	
	t_event_queue m_event_creation_requests;
	std::unique_ptr<std::thread> m_worker;

	std::mutex m_mutex;
	std::condition_variable m_condition_variable;		
	bool m_run;

};


}


#endif
