//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "complex_state_impl.hpp"

#include <algorithm>

#include "base.hpp"
#include "transition.hpp"


namespace sxy
{		


complex_state_impl::complex_state_impl( const std::string& _name, behaviour_uptr _entry_behaviour, 
	behaviour_uptr _exit_behaviour, const event_ids& _deferred_events )
	: state_impl( _name ),
		entry_( sxy::move( _entry_behaviour ) ),
		exit_( sxy::move( _exit_behaviour ) ),
		deferred_events_( _deferred_events )
{
	// Nothing to do...
}


complex_state_impl::~complex_state_impl() Y_NOEXCEPT
{
	// Nothing to do...
}


behaviour* complex_state_impl::get_entry_behaviour() const
{
	return( entry_.get() );
}


behaviour* complex_state_impl::get_exit_behaviour() const
{
	return( exit_.get() );
}


bool complex_state_impl::is_event_deferred( const event_id& _event_id ) const
{
	const bool found =
		std::find( deferred_events_.begin(), deferred_events_.end(), _event_id ) != deferred_events_.end();
	return( found );
}


bool complex_state_impl::check_if_one_of_the_deferred_events_triggers_a_transition() const
{
	bool deferred_event_trigger_a_transition = false;

	Y_FOR( const event_id deferred_event, deferred_events_ )
	{
		Y_FOR( const transition* const transition, get_outgoing_transitions() )
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
