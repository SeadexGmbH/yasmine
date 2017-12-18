////////////////////////////////////////////////////////////////////////////////////////////////////////
////                                                                                                  //
//// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
//// Copyright (C) 2016-2017 Seadex GmbH                                                              //
////                                                                                                  //
//// Licensing information is available in the folder "license" which is part of this distribution.   //
//// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
////                                                                                                  //
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "delete_visitor.hpp"

#include <algorithm>

#include "state_machine_model.hpp"
#include "simple_state_model_impl.hpp"
#include "composite_state_model_impl.hpp"
#include "final_state_model_impl.hpp"
#include "initial_pseudostate_model_impl.hpp"
#include "terminate_pseudostate_model_impl.hpp"
#include "join_model_impl.hpp"
#include "fork_model_impl.hpp"
#include "choice_model_impl.hpp"
#include "junction_model_impl.hpp"
#include "entry_point_model_impl.hpp"
#include "exit_point_model_impl.hpp"
#include "shallow_history_model_impl.hpp"
#include "deep_history_model_impl.hpp"
#include "transition_model.hpp"
#include "region_model_impl.hpp"
#include "model_exception.hpp"


namespace sxy
{


namespace model
{


delete_visitor::delete_visitor()
{
	// nothing to do...
}


delete_visitor::~delete_visitor() SX_NOEXCEPT
{
	// nothing to do...
}



void delete_visitor::visit( simple_state_model& _simple_state )
{
	delete_state( &_simple_state );
}


void delete_visitor::visit( composite_state_model& _composite_state )
{
	delete_state( &_composite_state );
}


void delete_visitor::visit( final_state_model& _final_state )
{
	delete_state( &_final_state );
}


void delete_visitor::visit( initial_pseudostate_model_impl& _initial_pseudostate )
{
	delete_pseudostate( &_initial_pseudostate );
}


void delete_visitor::visit( terminate_pseudostate_model_impl& _terminate_pseudostate )
{
	delete_pseudostate( &_terminate_pseudostate );
}


void delete_visitor::visit( join_model_impl& _join )
{
	delete_pseudostate( &_join );
}


void delete_visitor::visit( fork_model_impl& _fork )
{
	delete_pseudostate( &_fork );
}


void delete_visitor::visit( choice_model_impl& _choice )
{
	delete_pseudostate( &_choice );
}


void delete_visitor::visit( junction_model_impl& _junction )
{
	delete_pseudostate( &_junction );
}


void delete_visitor::visit( entry_point_model_impl& _entry_point )
{
	delete_state_pseudostate( &_entry_point );
}


void delete_visitor::visit( exit_point_model_impl& _exit_point )
{
	delete_state_pseudostate( &_exit_point );
}


void delete_visitor::visit( shallow_history_model_impl& _shallow_history )
{
	delete_state_pseudostate( &_shallow_history );
}


void delete_visitor::visit( deep_history_model_impl& _deep_history )
{
	delete_state_pseudostate( &_deep_history );
}


void delete_visitor::visit( transition_model& _transition )
{
	state_machine_element_model* parent_of_transition = _transition.get_parent();
	if( parent_of_transition )
	{
		sxy::model::state_machine_model* state_machine =
			dynamic_cast< sxy::model::state_machine_model* >( parent_of_transition );
		if( state_machine )
		{
			const raw_const_transition_models transitions = state_machine->get_transitions();
			const size_t idx = std::find( transitions.begin(), transitions.end(), &_transition ) - transitions.begin();
			state_machine->remove_transition( idx );
		}
	}
}


void delete_visitor::visit( region_model& _region )
{
	state_machine_element_model* parent_element = _region.get_parent();
	if( parent_element )
	{
		sxy::model::composite_state_model* parent_state = 
			dynamic_cast< sxy::model::composite_state_model* >( parent_element );
		if( parent_state )
		{
			const raw_const_region_models regions = parent_state->get_regions();
			const size_t idx = std::find( regions.begin(), regions.end(), &_region ) - regions.begin();
			parent_state->remove_region( idx );
		}
	}
}


void delete_visitor::delete_state( state_model* _state )
{
	state_machine_element_model* parent_element = _state->get_parent();
	if( parent_element )
	{
		region_model* parent_region = dynamic_cast< region_model* >( parent_element );
		if( parent_region )
		{
			const row_const_state_models states = parent_region->get_states();
			const size_t idx = std::find( states.begin(), states.end(), _state ) - states.begin();
			parent_region->remove_state( idx );
		}
	}
}


void delete_visitor::delete_pseudostate( pseudostate_model_impl* _pseudostate )
{
	state_machine_element_model* parent_element = _pseudostate->get_parent();
	if( parent_element )
	{
		sxy::model::region_model* parent_region = dynamic_cast< sxy::model::region_model* >( parent_element );
		if( parent_region )
		{
			const raw_const_pseduostate_models pseudostates = parent_region->get_pseudostates();
			const size_t idx = std::find( pseudostates.begin(), pseudostates.end(), _pseudostate ) - pseudostates.begin();
			parent_region->remove_pseudostate( idx );
		}
	}
}


void delete_visitor::delete_state_pseudostate( pseudostate_model_impl* _state_pseudostate )
{
	state_machine_element_model* parent_element = _state_pseudostate->get_parent();
	if( parent_element )
	{
		sxy::model::composite_state_model* parent_state = 
			dynamic_cast< sxy::model::composite_state_model* >( parent_element );
		if( parent_state )
		{
			const raw_const_pseduostate_models state_pseudostates = parent_state->get_state_pseudostates();
			const size_t idx = std::find( state_pseudostates.begin(), state_pseudostates.end(), _state_pseudostate ) - state_pseudostates.begin();
			parent_state->remove_state_pseudostate( idx );
		}
	}
}


}


}
