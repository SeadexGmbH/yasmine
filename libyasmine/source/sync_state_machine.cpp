//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "sync_state_machine.hpp"

#include "hermes/log.hpp"


namespace sxy
{


sync_state_machine::sync_state_machine( const std::string& _name,	event_processing_callback* const _event_processing_callback )	
	: state_machine_base(_name, _event_processing_callback)
{
	// Nothing to do...
}


sync_state_machine::~sync_state_machine() SX_NOEXCEPT
{
	// Nothing to do...
}


bool sync_state_machine::push( const event_sptr& _event )
{
	event_list_.push_back( _event );	
	return( true );
}


bool sync_state_machine::fire_event( const event_sptr& _event )
{
	SX_LOG( hermes::log_level::LL_INFO, "Firing & processing event '%' (%) with priority '%'.", _event->get_name(),
		_event->get_id(), static_cast< sxe::int16_t >( _event->get_priority() ) );
	bool terminate_pseudostate_has_been_reached = true;
	if( !is_interrupted() )
	{
		terminate_pseudostate_has_been_reached = process_event( _event, SX_NULLPTR );
		if( !terminate_pseudostate_has_been_reached )
		{
			terminate_pseudostate_has_been_reached = process_events_from_queue();
		}
		SX_LOG( hermes::log_level::LL_INFO, "Event '%' (%) has been fired & processed.", _event->get_name(), _event->get_id() );
	}
	else
	{
		SX_LOG( hermes::log_level::LL_INFO, "State machine is interrupted and no event can be fired!" );
	}
	return( !terminate_pseudostate_has_been_reached );
}


bool sync_state_machine::run()
{
	SX_LOG( hermes::log_level::LL_INFO, "Starting state machine '%'.", get_name() );

	const bool state_machine_started = state_machine_base::run( SX_NULLPTR );

	SX_LOG( hermes::log_level::LL_INFO, "Started state machine '%'.", get_name() );


	return( state_machine_started );
}


bool sync_state_machine::process_events_from_queue()
{
	bool terminate_pseudostate_has_been_reached = false;
	while( !event_list_.empty() && !terminate_pseudostate_has_been_reached )
	{
		event_sptr event_to_be_fired = event_list_.front();
		event_list_.pop_front();
		terminate_pseudostate_has_been_reached = process_event( event_to_be_fired, SX_NULLPTR );
	}
	return( terminate_pseudostate_has_been_reached );
}


}
