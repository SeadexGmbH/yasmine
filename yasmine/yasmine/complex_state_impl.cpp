//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "complex_state_impl.h"

#include <algorithm>

#include "base.h"
#include "transition.h"


namespace sxy
{		


complex_state_impl::complex_state_impl( const std::string& _name, behavior_uptr _entry_behavior, 
	behavior_uptr _exit_behavior, const event_ids& _deferred_events )
	: state_impl( _name ),
		entry_( std::move( _entry_behavior ) ),
		exit_( std::move( _exit_behavior ) ),
		deferred_events_( _deferred_events )
{
	// Nothing to do...
}


complex_state_impl::~complex_state_impl() = default;


behavior* complex_state_impl::get_entry_behavior() const
{
	return( entry_.get() );
}


behavior* complex_state_impl::get_exit_behavior() const
{
	return( exit_.get() );
}


bool complex_state_impl::is_event_deferred( const event_id& _event_id ) const
{
	const auto found = 
		std::find( deferred_events_.begin(), deferred_events_.end(), _event_id ) != deferred_events_.end();
	return( found );
}


bool complex_state_impl::check_if_one_of_the_deferred_events_triggers_a_transition() const
{
	auto deferred_event_trigger_a_transition = false;

	for( const auto deferred_event : deferred_events_ )
	{
		for( const auto transition : get_outgoing_transitions() )
		{
			deferred_event_trigger_a_transition = transition->can_accept_event( deferred_event );
			if( deferred_event_trigger_a_transition )
			{
				break;
			}
		}

		if( deferred_event_trigger_a_transition )
		{
			break;
		}
	}

	return( deferred_event_trigger_a_transition );
}


}
