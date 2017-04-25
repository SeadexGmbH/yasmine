//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "json_writer.hpp"

#include <fstream>

#include "rapidjson/prettywriter.h"

#include "essentials/exception.hpp"
#include "essentials/base.hpp"

#include "consts.hpp"
#include "transition_model.hpp"
#include "state_machine_model.hpp"
#include "model_element_type.hpp"
#include "composite_state_model_impl.hpp"
#include "region_model_impl.hpp"
#include "simple_state_model_impl.hpp"
#include "final_state_model_impl.hpp"
#include "pseudostate_model_impl.hpp"
#include "event_model.hpp"


namespace sxy
{


json_writer::json_writer( const std::string& _json_file_name, const model::state_machine_model& _state_machine_model )
{
	write_json_to_file( _json_file_name, _state_machine_model );
}


json_writer::~json_writer()SX_NOEXCEPT
{
	// Nothing to do...
}


void json_writer::write_json_to_file( const std::string& _json_file, const model::state_machine_model& _state_machine_model )
{
	rapidjson::Document doc;
	doc.SetObject();
	add_version( doc, doc.GetAllocator() );
	rapidjson::Value json_state_machine( rapidjson::kObjectType );	
	
	rapidjson::Value json_events( rapidjson::kArrayType );
	add_events_from_model( _state_machine_model, json_events, doc.GetAllocator() );
	doc.AddMember( rapidjson::StringRef( model::JSON_EVENT_LIST_NODE ), json_events, doc.GetAllocator() );

	rapidjson::Value json_transitions( rapidjson::kArrayType );
	add_transitions_from_model( _state_machine_model, json_transitions, doc.GetAllocator() );
	json_state_machine.AddMember( rapidjson::StringRef( model::JSON_TRANSITIONS_NODE ), json_transitions, doc.GetAllocator() );
	
	rapidjson::Value root( rapidjson::kObjectType );
	sxy::model::composite_state_model_impl& root_state = _state_machine_model.get_root_state();
	fill_composite_state_object( root_state, root, doc.GetAllocator() );	
	json_state_machine.AddMember( rapidjson::StringRef( model::JSON_ROOT_NODE ), root, doc.GetAllocator() );

	doc.AddMember( rapidjson::StringRef( model::JSON_STATE_MACHINE_NODE ), json_state_machine, doc.GetAllocator() );
	rapidjson::StringBuffer string_buffer;
	rapidjson::PrettyWriter< rapidjson::StringBuffer > writer( string_buffer );
	doc.Accept( writer );
	const char* const json_char = string_buffer.GetString();
	write_text_to_file( json_char, _json_file );
}


void json_writer::write_text_to_file( const char* _json_char, const std::string& _json_file )
{
#ifndef SX_CPP03_BOOST
	std::ofstream json_file( _json_file, std::ios_base::out );
#else
	std::ofstream json_file( _json_file.c_str(), std::ios_base::out );
#endif

	if( json_file.is_open() )
	{
		json_file << _json_char << std::endl;
		json_file.close();
	}
	else
	{
		throw sxe::exception( "File % cannot be opened for writing!", _json_file );
	}
}


void json_writer::add_version( rapidjson::Value& _document, rapidjson::MemoryPoolAllocator< >& _allocator )
{
	_document.AddMember( rapidjson::StringRef( model::JSON_VERSION ),
		rapidjson::StringRef( model::JSON_CURRENT_VERSION_VALUE ), _allocator );
}


void json_writer::add_events_from_model( const model::state_machine_model& _state_machine_model,
	rapidjson::Value& _events, rapidjson::MemoryPoolAllocator< >& _allocator )
{
	SX_FOR( const sxy::model::event_model& an_event, _state_machine_model.get_events() )
	{
		const std::string name = an_event.name;
		sxy::model::event_id id = an_event.id;
		sxy::model::event_priority priority = an_event.priority;

		rapidjson::Value json_event( rapidjson::kObjectType );
		rapidjson::Value name_val;
		name_val.SetString( name.c_str(), name.length(), _allocator );
		json_event.AddMember( rapidjson::StringRef( model::JSON_NAME_NODE ), name_val, _allocator );
		json_event.AddMember( rapidjson::StringRef( model::JSON_EVENT_ID ), id, _allocator );
		json_event.AddMember( rapidjson::StringRef( model::JSON_EVENT_PRIORITY ), priority, _allocator );

		_events.PushBack( json_event.Move(), _allocator );
	}
}


void json_writer::add_transitions_from_model( const model::state_machine_model& _state_machine_model,
	rapidjson::Value& _transitions, rapidjson::MemoryPoolAllocator< >& _allocator )
{
	SX_FOR( const model::transition_model* transition, _state_machine_model.get_transitions() )
	{
		rapidjson::Value json_transition( rapidjson::kObjectType );
		rapidjson::Value name_node;

		json_transition.AddMember( rapidjson::StringRef( model::JSON_NAME_NODE ),
			create_rapidjson_string_value( transition->get_name(), name_node ).Move(), _allocator );
		int kind = transition->get_kind() == sxy::model::transition_model_kind::EXTERNAL ? 
			0 : ( transition->get_kind() == sxy::model::transition_model_kind::INTERNAL ? 1 : 2 );
		json_transition.AddMember( rapidjson::StringRef( model::JSON_TRANSITION_KIND_NODE ), kind, _allocator );
		const std::string source = transition->get_source().to_string();
		rapidjson::Value source_val;
		source_val.SetString( source.c_str(), source.length(), _allocator );
		json_transition.AddMember( rapidjson::StringRef( model::JSON_TRANSITION_SOURCE_NODE ), source_val, _allocator );
		const std::string target = transition->get_target().to_string();
		rapidjson::Value target_val;
		target_val.SetString( target.c_str(), target.length(), _allocator );
		json_transition.AddMember( rapidjson::StringRef( model::JSON_TRANSITION_TARGET_NODE ), target_val, _allocator );
		rapidjson::Value json_events( rapidjson::kArrayType );

		SX_FOR( sxy::model::event_id transition_event_id, transition->get_event_ids() )
		{
			rapidjson::Value json_event( rapidjson::kObjectType );
			rapidjson::Value name_val;
			const std::string name = get_event_name_by_id( transition_event_id, _state_machine_model );
			name_val.SetString( name.c_str(), name.length(), _allocator );
			json_event.AddMember( rapidjson::StringRef( model::JSON_NAME_NODE ), name_val, _allocator );
			json_events.PushBack( json_event.Move(), _allocator );
		}

		json_transition.AddMember( rapidjson::StringRef( model::JSON_TRANSITION_EVENTS_NODE ), json_events, _allocator );
		rapidjson::Value transition_guard;
		json_transition.AddMember( rapidjson::StringRef( model::JSON_TRANSITION_GUARD_NODE ),
			create_rapidjson_string_value( transition->get_guard(), transition_guard ).Move(), _allocator );
		rapidjson::Value transition_behavior;
		json_transition.AddMember( rapidjson::StringRef( model::JSON_TRANSITION_BEHAVIOR_NODE ),
			create_rapidjson_string_value( transition->get_behavior(), transition_behavior ).Move(), _allocator );
		_transitions.PushBack( json_transition.Move(), _allocator );
	}
}


void json_writer::add_regions_from_model( const model::composite_state_model& _composite_state_model,
	rapidjson::Value& _regions, rapidjson::MemoryPoolAllocator< >& _allocator )
{
	SX_FOR( const sxy::model::region_model* const region, _composite_state_model.get_regions() )
	{
		rapidjson::Value json_region( rapidjson::kObjectType );
		fill_region_object( *region, json_region, _allocator );
		if( json_region.IsObject() )
		{
			_regions.PushBack( json_region.Move(), _allocator );
		}
	}
}


void json_writer::fill_region_object( const model::region_model& _region_model, rapidjson::Value& _region,
	rapidjson::MemoryPoolAllocator< >& _allocator )
{
	rapidjson::Value name_node;
	_region.AddMember( rapidjson::StringRef( model::JSON_NAME_NODE ),
		create_rapidjson_string_value( _region_model.get_name(), name_node ).Move(), _allocator );
	rapidjson::Value json_states( rapidjson::kArrayType );

	SX_FOR( const sxy::model::state_model* const one_state_model, _region_model.get_states() )
	{
		const model::model_element_type type_of_state = one_state_model->get_type();

#ifndef SX_CPP03_BOOST
		switch( type_of_state )
#else
		switch( type_of_state.value_ )
#endif
		{
		case model::model_element_type::TYE_SIMPLE_STATE:
		{
			const model::simple_state_model_impl* simple_state_model = 
				dynamic_cast< const model::simple_state_model_impl* >( one_state_model );
			SX_ASSERT( simple_state_model, "Simple state cannot be written to json file!" );
			rapidjson::Value json_state( rapidjson::kObjectType );
			fill_simple_state_object( *simple_state_model, json_state, _allocator );
			json_states.PushBack( json_state, _allocator );
			break;
		}

		case model::model_element_type::TYE_COMPOSITE_STATE:
		{
			const model::composite_state_model_impl* composite_state_state_model =
				dynamic_cast< const model::composite_state_model_impl* >( one_state_model );
			SX_ASSERT( composite_state_state_model, "Composite state cannot be written to json file!" );
			rapidjson::Value json_state( rapidjson::kObjectType );
			fill_composite_state_object( *composite_state_state_model, json_state, _allocator );
			json_states.PushBack( json_state, _allocator );
			break;
		}

		case model::model_element_type::TYE_FINAL_STATE:
		{
			const model::final_state_model_impl* final_state_model = 
				dynamic_cast< const model::final_state_model_impl* >( one_state_model );
			SX_ASSERT( final_state_model, "Final state cannot be written to json file!" );
			rapidjson::Value json_state( rapidjson::kObjectType );
			fill_final_state_object( *final_state_model, json_state, _allocator );
			json_states.PushBack( json_state, _allocator );
			break;
		}

		default:
			SX_ASSERT( false, "Type is not correct!" );
		}
	}

	_region.AddMember( rapidjson::StringRef( model::JSON_VERTICES_NODE ), json_states, _allocator );
	rapidjson::Value json_pseudostates( rapidjson::kArrayType );

	SX_FOR( const sxy::model::pseudostate_model* const pseudostate, _region_model.get_pseudostates() )
	{
		rapidjson::Value json_pseudostate( rapidjson::kObjectType );
		fill_pseudostate_object( *pseudostate, json_pseudostate, _allocator );
		json_pseudostates.PushBack( json_pseudostate, _allocator );
	}

	_region.AddMember( rapidjson::StringRef( model::JSON_PSEUDOSTATES_NODE ), json_pseudostates, _allocator );
}


void json_writer::fill_pseudostate_object( const model::pseudostate_model& _pseudostate_model,
	rapidjson::Value& _pseudostate, rapidjson::MemoryPoolAllocator< >& _allocator )
{
	fill_base_info( _pseudostate, _pseudostate_model, _allocator );
}


void json_writer::fill_simple_state_object( const model::simple_state_model& _simple_state_model,
	rapidjson::Value& _simple_state, rapidjson::MemoryPoolAllocator< >& _allocator )
{
	if( _simple_state_model.is_async() )
	{
		rapidjson::Value name_node;
		_simple_state.AddMember( rapidjson::StringRef( model::JSON_NAME_NODE ),
			create_rapidjson_string_value( _simple_state_model.get_name(), name_node ).Move(), _allocator );
		rapidjson::Value type_node;
		_simple_state.AddMember( rapidjson::StringRef( model::JSON_TYPE_NODE ),
			create_rapidjson_string_value( model::TYPE_ASYNC_SIMPLE_STATE, type_node ).Move(), _allocator );
	}
	else
	{
		fill_base_info( _simple_state, _simple_state_model, _allocator );
	}

	rapidjson::Value transition_enter_behavior;
	_simple_state.AddMember( rapidjson::StringRef( model::JSON_ENTER_BEHAVIOR_NODE ),
		create_rapidjson_string_value( _simple_state_model.get_enter_behavior(), transition_enter_behavior ).Move(), _allocator );
	rapidjson::Value transition_do_behavior;
	_simple_state.AddMember( rapidjson::StringRef( model::JSON_DO_BEHAVIOR_NODE ),
		create_rapidjson_string_value( _simple_state_model.get_do_behavior(), transition_do_behavior ).Move(), _allocator );
	rapidjson::Value transition_exit_behavior;
	_simple_state.AddMember( rapidjson::StringRef( model::JSON_EXIT_BEHAVIOR_NODE ),
		create_rapidjson_string_value( _simple_state_model.get_exit_behavior(), transition_exit_behavior ).Move(), _allocator );
	rapidjson::Value deferred_events( rapidjson::kArrayType );
	_simple_state.AddMember( rapidjson::StringRef( model::JSON_DEFERRED_EVENTS ), deferred_events, _allocator );
}


void json_writer::fill_composite_state_object( const model::composite_state_model& _composite_state_model,
	rapidjson::Value& _composite_state, rapidjson::MemoryPoolAllocator< >& _allocator )
{
	fill_base_info( _composite_state, _composite_state_model, _allocator );

	// regions
	rapidjson::Value json_regions( rapidjson::kArrayType );
	add_regions_from_model( _composite_state_model, json_regions, _allocator );
	_composite_state.AddMember( rapidjson::StringRef( model::JSON_REGIONS_NODE ), json_regions, _allocator );

	// state_pseudostates
	rapidjson::Value json_state_pseudostates( rapidjson::kArrayType );
	add_state_pseudostates_from_model( _composite_state_model, json_state_pseudostates, _allocator );
	_composite_state.AddMember( rapidjson::StringRef( model::JSON_STATE_PSEUDOSTATES_NODE ), json_state_pseudostates, _allocator );

	// behaviors
	rapidjson::Value transition_enter_behavior;
	_composite_state.AddMember( rapidjson::StringRef( model::JSON_ENTER_BEHAVIOR_NODE ),
		create_rapidjson_string_value( _composite_state_model.get_enter_behavior(), transition_enter_behavior ).Move(), _allocator );
	rapidjson::Value transition_exit_behavior;
	_composite_state.AddMember( rapidjson::StringRef( model::JSON_EXIT_BEHAVIOR_NODE ),
		create_rapidjson_string_value( _composite_state_model.get_exit_behavior(), transition_exit_behavior ).Move(), _allocator );
}


void json_writer::fill_final_state_object( const model::final_state_model& _final_state_model, rapidjson::Value& _final_state,
	rapidjson::MemoryPoolAllocator< >& _allocator )
{
	fill_base_info( _final_state, _final_state_model, _allocator );
}


void json_writer::add_state_pseudostates_from_model( const model::composite_state_model& _composite_state_model,
	rapidjson::Value& _state_pseudostates, rapidjson::MemoryPoolAllocator< >& _allocator )
{
	SX_FOR( const sxy::model::pseudostate_model* const state_pseudostate, _composite_state_model.get_state_pseudostates() )
	{
		rapidjson::Value json_state_pseudostate( rapidjson::kObjectType );
		fill_pseudostate_object( *state_pseudostate, json_state_pseudostate, _allocator );
		_state_pseudostates.PushBack( json_state_pseudostate.Move(), _allocator );
	}
}


rapidjson::Value& json_writer::create_rapidjson_string_value( const std::string& _string, 
	rapidjson::Value& _json_string_value )
{
	_json_string_value.SetString( _string.c_str(), _string.length() );
	return( _json_string_value );
}


void json_writer::fill_base_info( rapidjson::Value& _json_val, const model::state_machine_element_model& _element,
	rapidjson::MemoryPoolAllocator< >& _allocator )
{
	rapidjson::Value name_node;
	_json_val.AddMember( rapidjson::StringRef( model::JSON_NAME_NODE ),
		create_rapidjson_string_value( _element.get_name(), name_node ).Move(), _allocator );
	rapidjson::Value type_node;
	const std::string node_type = model_element_type_to_string( _element.get_type() );
	type_node.SetString( node_type.c_str(), node_type.length(), _allocator );
	_json_val.AddMember( rapidjson::StringRef( model::JSON_TYPE_NODE ), type_node.Move(), _allocator );
}


const std::string json_writer::get_event_name_by_id( const sxy::model::event_id& _event_id,
	const model::state_machine_model& _state_machine_model )
{
	std::string event_name = "";
	SX_FOR( const sxy::model::event_model& an_event , _state_machine_model.get_events() )
	{
		if( _event_id == an_event.id )
		{
			event_name = an_event.name;
			break;
		}
	}

	return( event_name );
}


}
