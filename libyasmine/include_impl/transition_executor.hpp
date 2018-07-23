//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TRANSITION_EXECUTOR_H_2521E4B8_B89E_4CCE_9751_F5B6BD515AD5
#define TRANSITION_EXECUTOR_H_2521E4B8_B89E_4CCE_9751_F5B6BD515AD5


#include "essentials/non_copyable.hpp"

#include "choice_fwd.hpp"
#include "compound_transition_fwd.hpp"
#include "behavior_exception_fwd.hpp"
#include "event_fwd.hpp"


namespace sxy
{


namespace impl
{
																 
class transition_executor_impl;

}


class composite_state;
class event_processing_callback;
class async_event_handler;
class event_collector;
class interruptible;


class transition_executor SX_FINAL
{
public:
	transition_executor();
	~transition_executor() SX_NOEXCEPT;
	SX_NO_COPY(transition_executor)
	bool check_sort_and_execute_transitions( const compound_transitions& _compound_transitions, 
		raw_const_choices& _verices,	event_processing_callback* const _event_processing_callback,	
		const event& _event, events& _exception_events, async_event_handler* const _async_event_handler,
		event_collector& _event_collector, const interruptible& _interruptible );


private:
	impl::transition_executor_impl* transition_executor_impl_;
};


}


#endif
