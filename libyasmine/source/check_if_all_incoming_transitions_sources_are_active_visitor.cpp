//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "check_if_all_incoming_transitions_sources_are_active_visitor.hpp"

#include "composite_state.hpp"
#include "simple_state.hpp"


namespace sxy
{


check_if_all_incoming_transitions_sources_are_active_visitor::check_if_all_incoming_transitions_sources_are_active_visitor():
	complex_state_visitor(), source_is_finished_( false )
{
	// Nothing to do...
}


check_if_all_incoming_transitions_sources_are_active_visitor::~check_if_all_incoming_transitions_sources_are_active_visitor() SX_NOEXCEPT
{
	// Nothing to do...
}


void check_if_all_incoming_transitions_sources_are_active_visitor::visit( const composite_state& _composite_state )
{
	source_is_finished_ = _composite_state.is_active();
	if( source_is_finished_ )
	{
		source_is_finished_ = _composite_state.check_if_regions_are_completed();
	}
}


void check_if_all_incoming_transitions_sources_are_active_visitor::visit( const simple_state& _simple_state )
{
	source_is_finished_ = _simple_state.is_active();
}


bool check_if_all_incoming_transitions_sources_are_active_visitor::get_result() const
{
	return( source_is_finished_ );
}


}
