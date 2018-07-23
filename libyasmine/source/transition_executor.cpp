//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "transition_executor.hpp"

#include "hermes/log.hpp"

#include "transition_executor_impl.hpp"
#include "choice_fwd.hpp"
#include "execution_step.hpp"
#include "region_fwd.hpp"
#include "compound_transition_impl.hpp"
#include "event_processing_callback.hpp"
#include "event.hpp"
#include "algorithm_parameters.hpp"
#include "interruptible.hpp"


namespace sxy
{


transition_executor::transition_executor()
	: transition_executor_impl_()
{
	// Nothing to do...
}


transition_executor::~transition_executor() SX_NOEXCEPT
{	
	// Nothing to do...
}


bool transition_executor::check_sort_and_execute_transitions( const compound_transitions& _compound_transitions,
	raw_const_choices& _vertices, event_processing_callback* const _event_processing_callback, 
	const event& _event, events& _exception_events, async_event_handler* const _async_event_handler,
	event_collector& _event_collector, const interruptible& _interruptible )
{
	bool terminate_pseudostate_has_been_reached = false;
	SX_LOG( hermes::log_level::LL_TRACE, "Check for transition conflicts." );
	transition_executor_impl_->conflict_check( _compound_transitions );
	SX_LOG( hermes::log_level::LL_TRACE, "Sorting compound transitions." );
	const raw_compound_transitions& sorted_compound_transitions = 
		transition_executor_impl_->sort_compound_transitions( _compound_transitions );
	SX_LOG( hermes::log_level::LL_TRACE, "Compound transitions sorted." );
	SX_LOG( hermes::log_level::LL_TRACE, "Start calculating execution step(s) for all compound transitions." );

	SX_FOR( compound_transition* const compound_transition, sorted_compound_transitions )
	{
		if( _interruptible.is_interrupted() )
		{
			break;
		}

		if( _event_processing_callback )
		{
			_event_processing_callback->before_compound_transition();
		}

		execution_steps execution_steps;
		execution_steps.reserve( EXECUTION_STEPS_VECTOR_SIZE );
		raw_const_region_set entered_regions;
		SX_LOG( hermes::log_level::LL_TRACE, "Calculate execution step(s) for one compound transition." );
		transition_executor_impl_->find_states_to_enter_and_to_exit_and_calculate_execution_steps( *compound_transition,
			execution_steps, entered_regions, _event, true, _event_collector );
		SX_LOG( hermes::log_level::LL_TRACE, "Found % execution step(s).", execution_steps.size() );
		SX_LOG( hermes::log_level::LL_TRACE, "Start running execution step(s)." );
		terminate_pseudostate_has_been_reached = transition_executor_impl_->run_execution_steps( execution_steps,
			_event_processing_callback, _event, _exception_events, _async_event_handler, _event_collector );
		SX_LOG( hermes::log_level::LL_TRACE, "Finished running execution step(s)." );
		if( terminate_pseudostate_has_been_reached )
		{
			SX_LOG( hermes::log_level::LL_DEBUG, "Terminate pseudostate has been reached." );
			break;
		}

		if( _event_processing_callback )
		{
			_event_processing_callback->after_compound_transition();
		}
	}

	SX_LOG( hermes::log_level::LL_TRACE, "Finished calculating execution step(s) for all compound transitions." );
	SX_LOG( hermes::log_level::LL_TRACE, "Search for choices." );
	transition_executor_impl_->fill_vector_of_choices( _vertices, _compound_transitions );
	SX_LOG( hermes::log_level::LL_TRACE, "Found % choice(s).", _vertices.size() );
	return( terminate_pseudostate_has_been_reached );
}


}
