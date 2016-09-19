//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_complex_state.h"

#include <algorithm>

#include "base.h"
#include "i_behavior.h"
#include "i_transition.h"


namespace sxy
{		


t_complex_state::t_complex_state( const std::string& p_name, i_behavior_uptr p_entry_behavior, 
	i_behavior_uptr p_exit_behavior, const t_event_ids& p_deferred_events )
	: t_state( p_name ),
		m_entry( std::move( p_entry_behavior ) ),
		m_exit( std::move( p_exit_behavior ) ),
		m_deferred_events( p_deferred_events )
{
	// Nothing to do...
}


t_complex_state::~t_complex_state() = default;


i_behavior* t_complex_state::get_entry_behavior() const
{
	return( m_entry.get() );
}


i_behavior* t_complex_state::get_exit_behavior() const
{
	return( m_exit.get() );
}


bool t_complex_state::is_event_deferred( const t_event_id& p_event_id ) const
{
	const auto l_found = 
		std::find( m_deferred_events.begin(), m_deferred_events.end(), p_event_id ) != m_deferred_events.end();
	return( l_found );
}


bool t_complex_state::check_if_one_of_the_deferred_events_triggers_a_transition() const
{
	auto l_deferred_event_trigger_a_transition = false;

	for( const auto l_deferred_event : m_deferred_events )
	{
		for( const auto l_transition : get_outgoing_transitions() )
		{
			l_deferred_event_trigger_a_transition = l_transition->can_accept_event( l_deferred_event );
			if( l_deferred_event_trigger_a_transition )
			{
				break;
			}
		}

		if( l_deferred_event_trigger_a_transition )
		{
			break;
		}
	}

	return( l_deferred_event_trigger_a_transition );
}


}
