//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "recipe_callback_impl.hpp"

#include <sstream>
#include <iomanip>
#include <ctime>

#include "essentials/base.hpp"
#include "generator_grammar.hpp"
#include "essentials/exception.hpp"
#include "event_model_id.hpp"
#include "essentials/conversion.hpp"
#include "state_machine_model.hpp"
#include "composite_state_model_impl.hpp"
#include "region_model.hpp"
#include "state_model_impl.hpp"
#include "pseudostate_model.hpp"


namespace sxy
{


recipe_callback_impl::recipe_callback_impl( const sxy::model::state_machine_model& _state_machine_model,
	std::vector<std::string> _namespaces, std::vector<std::string> _behavior_classes,
	std::string _state_machine_name, std::string _state_machine_type )
	: recipe_callback(),
		state_machine_model_( _state_machine_model ),
		map_of_values_(),
		namespaces_( _namespaces ),
		behavior_classes_( _behavior_classes ),
		namespace_index_( 0 ),
		base_class_index_( 0 ),
		behavior_classes_index_( 0 ),
		transition_index_( 0 ),
		pseudostate_index_( 0 ),
		state_pseudostate_index_( 0 ),
		composite_states_stack_(),
		regions_stack_(),
		composite_states_index_stack_(),
		regions_index_stack_(),
		event_index_( 0 ),
		entry_behavior_(),
		do_behavior_(),
		exit_behavior_(),
		transition_guard_(),
		active_switch_()
{
	const std::string state_machine_name_caps = sxe::to_upper( _state_machine_name );
	map_of_values_.insert( std::make_pair( VARIABLE_STATE_MACHINE_NAME_CAPS, state_machine_name_caps ) );
	map_of_values_.insert( std::make_pair( VARIABLE_STATE_MACHINE_NAME, _state_machine_name ) );
	map_of_values_.insert( std::make_pair( VARIABLE_STATE_MACHINE_TYPE, _state_machine_type ) );
}


recipe_callback_impl::~recipe_callback_impl() SX_NOEXCEPT
{
	// Nothing to do...
}


std::string recipe_callback_impl::get_variable_content( const std::string& _variable_name )
{
	std::string result( "" );
	if( _variable_name == VARIABLE_NAMESPACE_NAME )
	{
		result = namespaces_[namespace_index_];
	}
	else if( _variable_name == VARIABLE_BEHAVIOR_CLASS_NAME )
	{
		result = behavior_classes_[behavior_classes_index_];
	}
	else if( _variable_name == VARIABLE_STATE_MACHINE_NAME_CAPS 
		|| _variable_name == VARIABLE_STATE_MACHINE_NAME  || _variable_name == VARIABLE_STATE_MACHINE_TYPE )
	{
		result = map_of_values_[_variable_name];
	}
	else if( _variable_name == VARIABLE_DATE_TIME )
	{
		result = get_date_time_string();
	}
	else if( _variable_name == TRANSITION_EVENT_ID )
	{
		result = get_transition_events();
	}
	else if( _variable_name == VARIABLE_EVENT_ID || _variable_name == VARIABLE_EVENT_NAME )
	{
		result = get_event_property( _variable_name );
	}
	else if( _variable_name == VARIABLE_SOURCE_VERTEX )
	{
		const sxy::model::transition_model* trans = state_machine_model_.get_transitions().at( transition_index_ );
		sxe::uri uri_of_source = trans->get_source();
		result = uri_of_source.get_back();
	}
	else if( _variable_name == VARIABLE_TARGET_VERTEX )
	{
		const sxy::model::transition_model* trans = state_machine_model_.get_transitions().at( transition_index_ );
		sxe::uri uri_of_target = trans->get_target();
		result = uri_of_target.get_back();
	}
	else if( _variable_name == VARIABLE_TRANSITION_KIND )
	{
		const sxy::model::transition_model* trans = state_machine_model_.get_transitions().at( transition_index_ );
		result = VARIABLE_TRANSITION_KIND_NAMESPACE + to_string( trans->get_kind() );
	}
	else if( _variable_name == VARIABLE_REGION_NAME )
	{
		SX_ASSERT( regions_stack_.top(), "There is no region to get the name!" );
		result = regions_stack_.top()->get_name();
	}
	else if( _variable_name == VARIABLE_ROOT_NAME )
	{
		result = state_machine_model_.get_root_state().get_name();
	}
	else if( _variable_name == VARIABLE_CURRENT_STATE_NAME )
	{
		SX_ASSERT( composite_states_stack_.top(), "There is no composite state to get the name!" );
		result = composite_states_stack_.top()->get_name();
	}
	else if( _variable_name == VARIABLE_STATE_TYPE || _variable_name == VARIABLE_STATE_NAME )
	{
		result = get_state_property( _variable_name );
	}
	else if( _variable_name == VARIABLE_PSEUDOSTATE_TYPE || _variable_name == VARIABLE_PSEUDOSTATE_NAME )
	{
		result = get_pseudostate_property( _variable_name );
	}
	else if( _variable_name == VARIABLE_STATE_PSEUDOSTATE_NAME || _variable_name == VARIABLE_STATE_PSEUDOSTATE_TYPE )
	{
		result = get_state_pseudostate_property( _variable_name );
	}
	else if( _variable_name == VARIABLE_METHOD_NAME )
	{
		if( active_switch_ == SWITCH_TRANSITION_BEHAVIOR )
		{
			result = do_behavior_.behavior_method_name;
		}
		else if( active_switch_ == SWITCH_TRANSITION_GUARD )
		{
			result = transition_guard_.behavior_method_name;
		}
		else if( active_switch_ == SWITCH_DO_BEHAVIOR )
		{
			result = do_behavior_.behavior_method_name;
		}
		else if( active_switch_ == SWITCH_ENTER_BEHAVIOR )
		{
			result = entry_behavior_.behavior_method_name;
		}
		else if( active_switch_ == SWITCH_EXIT_BEHAVIOR )
		{
			result = exit_behavior_.behavior_method_name;
		}
	}
	else if(_variable_name == VARIABLE_CLASS_INSTANCE_NAME )
	{
		if( active_switch_ == SWITCH_TRANSITION_BEHAVIOR )
		{
			result = do_behavior_.behavior_class_name;
		}
		else if( active_switch_ == SWITCH_TRANSITION_GUARD )
		{
			result = transition_guard_.behavior_class_name;
		}
		else if( active_switch_ == SWITCH_DO_BEHAVIOR )
		{
			result = do_behavior_.behavior_class_name;
		}
		else if( active_switch_ == SWITCH_ENTER_BEHAVIOR )
		{
			result = entry_behavior_.behavior_class_name;
		}
		else if( active_switch_ == SWITCH_EXIT_BEHAVIOR )
		{
			result = exit_behavior_.behavior_class_name;
		}
	}
	else
	{
		throw sxe::exception( "No variable name: '%'!", _variable_name );
	}
	return( result );
}


void recipe_callback_impl::before_loop( const std::string& _loop_name )
{
	if( _loop_name == LOOP_NAMESPACE_OPEN )
	{
		namespace_index_ = 0;
	}
	else if( _loop_name == LOOP_BEHAVIOR_CLASSES )
	{
		behavior_classes_index_ = 0;
	}
	else if( _loop_name == LOOP_TRANSITIONS )
	{
		transition_index_ = 0;
	}
	else if( _loop_name == LOOP_REGIONS )
	{				
		if( composite_states_stack_.empty() )
		{
			composite_states_stack_.push( &state_machine_model_.get_root_state() );
		}
		regions_index_stack_.push( 0 );
	}
	else if( _loop_name == LOOP_STATES )
	{
		composite_states_index_stack_.push( 0 );
	}
	else if( _loop_name == LOOP_PSEUDOSTATES )
	{
		pseudostate_index_ = 0;
	}
	else if( _loop_name == LOOP_STATE_PSEUDOSTATES )
	{
		state_pseudostate_index_ = 0;
	}
	else if( _loop_name == LOOP_EVENTS )
	{
		event_index_ = 0;
	}
}


void recipe_callback_impl::before_loop_iteration( const std::string& _loop_name )
{
	if( _loop_name == LOOP_REGIONS )
	{
		regions_stack_.push( composite_states_stack_.top()->get_regions()[regions_index_stack_.top()] );
	}
	else if( _loop_name == LOOP_STATES )
	{
		composite_states_stack_.push( regions_stack_.top()->get_states()[composite_states_index_stack_.top()] );
		fill_struct( _loop_name );
	}
	else if( _loop_name == LOOP_STATE_PSEUDOSTATES )
	{
		// Nothing to do...
	}
	else if( _loop_name == LOOP_PSEUDOSTATES )
	{
		// Nothing to do...
	}
	else if( _loop_name == LOOP_TRANSITIONS )
	{
		fill_struct( _loop_name );
	}
}


void recipe_callback_impl::after_loop_iteration( const std::string& _loop_name )
{
	if( _loop_name == LOOP_NAMESPACE_OPEN )
	{
		++namespace_index_;
	}
	else if( _loop_name == VARIABLE_NAMESPACE_CLOSE )
	{
		--namespace_index_;
	}
	else if( _loop_name == LOOP_BEHAVIOR_CLASSES )
	{
		++behavior_classes_index_;
	}
	else if( _loop_name == LOOP_TRANSITIONS )
	{
		++transition_index_;
	}
	else if( _loop_name == LOOP_REGIONS )
	{
		++regions_index_stack_.top();
		regions_stack_.pop();
	}
	else if( _loop_name == LOOP_STATES )
	{
		++composite_states_index_stack_.top();
		composite_states_stack_.pop();
	}
	else if( _loop_name == LOOP_PSEUDOSTATES )
	{
		++pseudostate_index_;
	}
	else if( _loop_name == LOOP_STATE_PSEUDOSTATES )
	{
		++state_pseudostate_index_;
	}
	else if( _loop_name == LOOP_EVENTS )
	{
		++event_index_;
	}
}


void recipe_callback_impl::after_loop( const std::string& _loop_name )
{
	if( _loop_name == LOOP_REGIONS )
	{
		if( composite_states_stack_.size() == 1 ) 
		{
			composite_states_stack_.pop();
		}
		regions_index_stack_.pop();
	}
	else if( _loop_name == LOOP_STATES )
	{
		composite_states_index_stack_.pop();
	}
	else if( _loop_name == LOOP_PSEUDOSTATES )
	{
		// Nothing to do...
	}
	else if( _loop_name == LOOP_STATE_PSEUDOSTATES )
	{
		// Nothing to do...
	}
	else if( _loop_name == LOOP_BEHAVIOR_CLASSES )
	{
		// Nothing to do...
	}
}


bool recipe_callback_impl::check_loop_condition( const std::string& _loop_name ) const
{
	bool result = false;
	if( _loop_name == LOOP_NAMESPACE_OPEN )
	{
		result = namespace_index_ < namespaces_.size();
	}
	else if( _loop_name == VARIABLE_NAMESPACE_CLOSE )
	{
		result = namespace_index_ > 0;
	}
	else if( _loop_name == LOOP_BEHAVIOR_CLASSES )
	{
		result = behavior_classes_index_ < behavior_classes_.size();
	}
	else if( _loop_name == LOOP_TRANSITIONS )
	{
		result = transition_index_ < state_machine_model_.get_transitions().size();
	}
	else if( _loop_name == LOOP_REGIONS )
	{
		const sxy::model::state_model* state_to_check = composite_states_stack_.top();
		SX_ASSERT( state_to_check, "There is no state in the stack!" );
		result = regions_index_stack_.top() < state_to_check->get_regions().size();
	}
	else if( _loop_name == LOOP_STATES )
	{
		if( !composite_states_stack_.empty() )
		{
			if( !composite_states_stack_.top()->get_regions().empty() )
			{
				if( !regions_index_stack_.empty() )
				{
					const sxy::model::region_model* region_to_check = composite_states_stack_.top()->get_regions()[regions_index_stack_.top()];
					result = composite_states_index_stack_.top() < region_to_check->get_states().size();
				}
			}
		}
	}
	else if( _loop_name == LOOP_PSEUDOSTATES )
	{
		const sxy::model::region_model* region_to_check = regions_stack_.top();
		result = pseudostate_index_ < region_to_check->get_pseudostates().size();
	}
	else if( _loop_name == LOOP_STATE_PSEUDOSTATES )
	{
		if( !composite_states_stack_.empty() )
		{
			const sxy::model::composite_state_model* state_to_check =
				dynamic_cast< const sxy::model::composite_state_model* >( composite_states_stack_.top() );
			if( state_to_check )
			{
				result = state_pseudostate_index_ < state_to_check->get_state_pseudostates().size();
			}
		}
	}
	else if( _loop_name == LOOP_EVENTS )
	{
		result = event_index_ < state_machine_model_.get_events().size();
	}
			
	return( result );
}


bool recipe_callback_impl::check_condition( const std::string& _condition_name ) const
{
	bool result = true;

	if( _condition_name == VARIABLE_LAST_BEHAVIOR_CLASS )
	{
		result = behavior_classes_index_ == behavior_classes_.size() - 1;
	}
	else if( _condition_name == CONDITION_IS_STATE )
	{	
		if( !composite_states_stack_.empty() )
		{
			const sxy::model::state_model* state = composite_states_stack_.top();
			result = state != SX_NULLPTR;
		}
		else
		{
			throw sxe::exception( "There is no vertex to check if it is a composite state!" );
		}
	}
	else if( _condition_name == CONDITION_IS_COMPOSITE_STATE )
	{
		if( !composite_states_stack_.empty() )
		{
			const sxy::model::composite_state_model* state = 
				dynamic_cast< const sxy::model::composite_state_model* > ( composite_states_stack_.top() );
			result = state != SX_NULLPTR;
		}
		else
		{
			throw sxe::exception( "There is no state to check if it is a composite state!" );
		}
	}
	else if( _condition_name == CONDITION_LAST_PSEUDOSTATE )
	{
		result = pseudostate_index_ == regions_stack_.top()->get_pseudostates().size() - 1;
	}

	return( result );
}


void recipe_callback_impl::condition_begin( const std::string& _condition_name )
{	
	if( _condition_name == CONDITION_IS_STATE )
	{
		if( composite_states_stack_.empty() )
		{
			composite_states_stack_.push( &state_machine_model_.get_root_state() );
		}
	}
	else if( _condition_name == CONDITION_IS_COMPOSITE_STATE )
	{
		// Nothing to do...
	}
}


void recipe_callback_impl::condition_end( const std::string& _condition_name )
{
	if( _condition_name == CONDITION_IS_STATE )
	{
		if( composite_states_stack_.size() == 1 )
		{
			composite_states_stack_.pop();
		}
	}
	else if( _condition_name == CONDITION_IS_COMPOSITE_STATE )
	{
		// Nothing to do...
	}
}


int recipe_callback_impl::get_switch_case( const std::string& _switch_name )
{
	behavior_classes_index_ = 0;
	active_switch_ = _switch_name;
	int index = SWITCH_DEFAULT_INDEX;
	if( _switch_name == SWITCH_TRANSITION_BEHAVIOR )
	{
		index = get_index( do_behavior_ );
	}	
	else if( _switch_name == SWITCH_TRANSITION_GUARD )
	{
		index = get_index( transition_guard_ );
	}
	else if( _switch_name == SWITCH_ENTER_BEHAVIOR )
	{
		index = get_index( entry_behavior_ );
	}
	else if( _switch_name == SWITCH_DO_BEHAVIOR )
	{
		index = get_index( do_behavior_ );
	}
	else if( _switch_name == SWITCH_EXIT_BEHAVIOR )
	{
		index = get_index( exit_behavior_ );
	}
	return( index );
}


std::string recipe_callback_impl::get_state_property( const std::string& _property ) const
{
	std::string result( "" );
	const sxy::model::region_model* region_to_check = regions_stack_.top();
	const sxy::model::state_model* state = region_to_check->get_states()[composite_states_index_stack_.top()];
	if( composite_states_index_stack_.top() < region_to_check->get_states().size() )
	{
		if( _property == VARIABLE_STATE_NAME )
		{
			result = state->get_name();
		}
		else if( _property == VARIABLE_STATE_TYPE )
		{
			result = model_element_type_to_string( state->get_type() );
		}
		else
		{
			throw sxe::exception( "Wrong command!" );
		}
	}
	else
	{
		throw sxe::exception( "No state to get name/type!" );
	}

	return( result );
}


std::string recipe_callback_impl::get_pseudostate_property( const std::string& _property ) const
{
	std::string result( "" );
	const sxy::model::region_model* region_to_check = regions_stack_.top();
	const sxy::model::pseudostate_model* pseudostate = region_to_check->get_pseudostates()[pseudostate_index_];
	if( pseudostate_index_ < region_to_check->get_pseudostates().size() )
	{
		if( _property == VARIABLE_PSEUDOSTATE_NAME )
		{
			result = pseudostate->get_name();
		}
		else if( _property == VARIABLE_PSEUDOSTATE_TYPE )
		{
			result = model_element_type_to_string( pseudostate->get_type() );
		}
		else
		{
			throw sxe::exception( "Wrong command!" );
		}
	}
	else
	{
		throw sxe::exception( "No pseudostate to get name/type!" );
	}

	return( result );
}


std::string recipe_callback_impl::get_state_pseudostate_property( const std::string& _property ) const
{
	std::string result( "" );
	const sxy::model::composite_state_model* state = dynamic_cast< const sxy::model::composite_state_model* >( composite_states_stack_.top() );
	if( state )
	{
		const sxy::model::pseudostate_model* state_pseudostate = state->get_state_pseudostates()[state_pseudostate_index_];
		if( _property == VARIABLE_STATE_PSEUDOSTATE_NAME )
		{
			result = state_pseudostate->get_name();
		}
		else if( _property == VARIABLE_STATE_PSEUDOSTATE_TYPE )
		{
			result = model_element_type_to_string( state_pseudostate->get_type() );
		}
		else
		{
			throw sxe::exception( "Wrong command!" );
		}
	}

	return( result );
}


std::string recipe_callback_impl::get_event_property( const std::string& _property ) const
{
	std::string result( "" );
	if( event_index_ < state_machine_model_.get_events().size() )
	{
		sxy::model::event_model& event = state_machine_model_.get_events()[event_index_];
		if( _property == VARIABLE_EVENT_ID )
		{
			result = sxe::to_string( event.id );
		}
		else if( _property == VARIABLE_EVENT_NAME )
		{
			result = event.name;
		}
		else if( _property == VARIABLE_EVENT_PRIORITY )
		{
			result = sxe::to_string( event.priority );
		}
		else
		{
			throw sxe::exception( "Wrong command!" );
		}
	}
	else
	{
		throw sxe::exception( "Event index out of range!" );
	}

	return( result );
}


std::string recipe_callback_impl::get_date_time_string() const
{
	std::stringstream date_time_stream;
	time_t rawtime;
	time( &rawtime );
	tm timeinfo = *localtime( &rawtime );
	date_time_stream << std::setfill( FILL_VALUE ) << std::setw( WIDTH_YEAR ) << ( YEAR_1900 + timeinfo.tm_year ) <<
		SLASH_CHAR << std::setfill( FILL_VALUE ) << std::setw( WIDTH_CLOCK ) << ++timeinfo.tm_mon << SLASH_CHAR << std::setfill(
			FILL_VALUE ) << std::setw( WIDTH_CLOCK ) << timeinfo.tm_mday << " " << std::setfill( FILL_VALUE ) <<
		std::setw( WIDTH_CLOCK ) << timeinfo.tm_hour << COLON_CHAR << std::setfill( FILL_VALUE ) <<
		std::setw( WIDTH_CLOCK ) << timeinfo.tm_min << COLON_CHAR << std::setfill( FILL_VALUE ) <<
		std::setw( WIDTH_CLOCK ) << timeinfo.tm_sec;
	return( date_time_stream.str() );
}


std::string recipe_callback_impl::get_transition_events() const
{
	std::string result( "" );
	if( state_machine_model_.get_transitions().size() > 0 )
	{
		const sxy::model::transition_model* trans = state_machine_model_.get_transitions().at( transition_index_ );
		sxy::model::event_id id = 0;
		if( !trans->get_event_ids().empty() )
		{
			result = OPEN_BRACE_CHAR;
			for( std::size_t i = 0; i < trans->get_event_ids().size(); ++i )
			{
				id = trans->get_event_ids()[i];
				if( id == sxy::model::Y_MODEL_COMPLETION_EVENT_ID )
				{
					result += VARIABLE_COMPLETION_EVENT_ID;
				}
				else
				{
					result += sxe::to_string( id );
				}
				result += COMMA_CHAR;
				result += " ";
			}
			result.erase( result.length() - 2, 2 );
			result += CLOSE_BRACE_CHAR;
		}
		else
		{
			result = VARIABLE_COMPLETION_EVENT_ID;
		}
	}

	return( result );
}


void recipe_callback_impl::fill_struct( const std::string& _loop_name )
{
	if( _loop_name == LOOP_TRANSITIONS )
	{
		const sxy::model::transition_model* trans = state_machine_model_.get_transitions().at( transition_index_ );
		fill_one_behavior_struct( do_behavior_, trans->get_behavior() );
		fill_one_behavior_struct( transition_guard_, trans->get_guard() );
	}
	else if( _loop_name == LOOP_STATES )
	{
		const model::state_model* state = composite_states_stack_.top();
		fill_one_behavior_struct( entry_behavior_, state->get_enter_behavior() );
		fill_one_behavior_struct( do_behavior_, state->get_do_behavior() );
		fill_one_behavior_struct( exit_behavior_, state->get_exit_behavior() );
	}
}


void recipe_callback_impl::fill_one_behavior_struct( behavior_struct& _behavior, const std::string& _behavior_string )
{
	if( _behavior_string.empty() )
	{
		// Nothing to do...
		_behavior.call_operator = access_operator::AO_NO_ACCESS_OPERATOR;
		_behavior.behavior_class_name = "";
		_behavior.behavior_method_name = "";
	}
	else if( _behavior_string.find( THIS_ACCESS ) != std::string::npos )
	{
		// this->foo
		_behavior.call_operator = access_operator::AO_THIS_ACCESS;
		_behavior.behavior_class_name = behavior_classes_[0];
		_behavior.behavior_method_name = _behavior_string.substr( _behavior_string.find( THIS_ACCESS ) + THIS_ACCESS.length(), _behavior_string.length() - _behavior_string.find( THIS_ACCESS ) - THIS_ACCESS.length() );
	}
	else if( _behavior_string.find( POINTER_ACCESS ) != std::string::npos )
	{
		// bar->foo
		_behavior.call_operator = access_operator::AO_POINTER_ACCESS;
		_behavior.behavior_class_name = _behavior_string.substr( 0, _behavior_string.find( POINTER_ACCESS ) );
		_behavior.behavior_method_name = _behavior_string.substr( _behavior_string.find( POINTER_ACCESS ) + 2, _behavior_string.length() - _behavior_string.find( POINTER_ACCESS ) - 2 );
	}
	else if( _behavior_string.find( REFERENCE_ACCESS ) != std::string::npos )
	{
		// bar.foo
		_behavior.call_operator = access_operator::AO_REFERENCE_ACCESS;
		_behavior.behavior_class_name = _behavior_string.substr( 0, _behavior_string.find( DOT_CHAR ) );
		_behavior.behavior_method_name = _behavior_string.substr( _behavior_string.find( DOT_CHAR ) + 1, _behavior_string.length() - _behavior_string.find( DOT_CHAR ) - 1 );
	}
	else
	{
		// bar::foo
		_behavior.call_operator = access_operator::AO_FUNCTION_ACCESS;
		_behavior.behavior_class_name = "";
		_behavior.behavior_method_name = _behavior_string;
	}
}


int recipe_callback_impl::get_index( const behavior_struct& _behavior_struct )
{
	int index = SWITCH_DEFAULT_INDEX;

	switch( _behavior_struct.call_operator )
	{
	case access_operator::AO_THIS_ACCESS:
	{
		index = 0;
		break;
	}
	case access_operator::AO_POINTER_ACCESS:
	{
		index = 1;
		break;
	}
	case access_operator::AO_REFERENCE_ACCESS:
	{
		index = 2;
		break;
	}
	case access_operator::AO_FUNCTION_ACCESS:
	{
		index = 3;
		break;
	}
	default:
		break;
	}

	return( index );
}


}
