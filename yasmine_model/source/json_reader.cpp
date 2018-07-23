//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "json_reader.hpp"

#include <fstream>
#include <sstream>

#include "essentials/base.hpp"
#include "essentials/exception.hpp"
#include "essentials/uri.hpp"

#include "consts.hpp"
#include "model_element_type.hpp"
#include "json_parser_helper.hpp"
#include "composite_state_model_impl.hpp"
#include "simple_state_model_impl.hpp"
#include "final_state_model_impl.hpp"
#include "state_machine_model.hpp"
#include "region_model_impl.hpp"
#include "pseudostate_model_impl.hpp"
#include "initial_pseudostate_model_impl.hpp"
#include "terminate_pseudostate_model_impl.hpp"
#include "join_model_impl.hpp"
#include "fork_model_impl.hpp"
#include "choice_model_impl.hpp"
#include "junction_model_impl.hpp"
#include "entry_point_model_impl.hpp"
#include "exit_point_model_impl.hpp"
#include "deep_history_model_impl.hpp"
#include "shallow_history_model_impl.hpp"
#include "transition_model_impl.hpp"
#include "model_exception.hpp"


namespace sxy
{


json_reader::json_reader( const std::string& _file )
	: document_(),
	model_()
{
	read_json_file( _file );
	check_document();
	model_ = read_into_model();
	read_externals();
}


json_reader::~json_reader() SX_NOEXCEPT
{
	// Nothing to do...
}


model::state_machine_model_ptr json_reader::get_model_ptr()
{
	return( sxe::move( model_ ) );
}


const model::external_vertices& json_reader::get_external_vertices()
{
	return( model_->get_externals() );
}


void json_reader::read_externals()
{
	try{
		std::vector<const rapidjson::Value*> externals_list =
			extract_members_from_array( get_object_member_array( document_, model::JSON_EXTERNALS ) );

		SX_FOR( const rapidjson::Value* json_external, externals_list )
		{
			sxy::model::model_element_type vertex_type = 
				model::model_element_type_from_string( get_object_member_string( sxe::ref( *json_external ), model::JSON_TYPE_NODE ) );
			const std::string name = get_object_member_string( sxe::ref( *json_external ), model::JSON_NAME_NODE );
			model_->add_external_vertex( SX_MAKE_UNIQUE<sxy::model::state_machine_external_element>( name, vertex_type ) );
		}
	}
	catch( const sxy::model::exception& _e )
	{
		if( std::strcmp( _e.what(), "Member externals was not found!" ) != 0 )
		{
			throw;
		}
	}
}


void json_reader::read_json_file( const std::string& _file )
{
#ifndef SX_CPP03_BOOST
	std::ifstream infile( _file, std::ios::in );
#else
	std::ifstream infile( _file.c_str(), std::ios::in );
#endif

	if( infile.is_open() )
	{
		std::stringstream strStream;
		strStream << infile.rdbuf();
		infile.close();
		string_to_json( strStream.str().c_str(), document_ );
	}
	else
	{
		throw sxe::exception( "File % can't be opened!", _file );
	}
}


model::state_machine_model_ptr json_reader::read_into_model()
{
	model::state_machine_model_ptr sm_model = SX_MAKE_UNIQUE< model::state_machine_model >();
	const rapidjson::Value& object_member = find_object_member( document_, model::JSON_STATE_MACHINE_NODE );
	const rapidjson::Value& root = find_object_member( object_member, model::JSON_ROOT_NODE );
	sm_model->add_root_state( read_composite_state( root ) );
	std::vector<const rapidjson::Value*> transitions_list = 
		extract_members_from_array( get_object_member_array( object_member, model::JSON_TRANSITIONS_NODE ) );

	SX_FOR( const rapidjson::Value* json_transition , transitions_list )
	{
		model::transition_model_uptr transition = read_transition( *json_transition );
		sm_model->add_transition( sxe::move( transition ) );
	}

	get_event_list( sm_model );

	return( sm_model );
}


sxy::model::event_ids json_reader::read_deferred_events( const rapidjson::Value& _state ) const
{
	std::vector<const rapidjson::Value*> deferred_event_list =
		extract_members_from_array( get_object_member_array( _state, model::JSON_DEFERRED_EVENTS ) );

	sxy::model::event_ids deferred_events;
	SX_FOR( const rapidjson::Value* const an_event, deferred_event_list )
	{
		const std::string event_name = get_object_member_string( sxe::ref( *an_event ), model::JSON_EVENT_NAME );
		sxy::model::event_id event_id = get_event_id_by_name( event_name );
		deferred_events.push_back( event_id );
	}
	return( deferred_events );
}


sxy::model::event_ids json_reader::read_error_events( const rapidjson::Value& _state ) const
{
	std::vector<const rapidjson::Value*> error_event_list =
		extract_members_from_array( get_object_member_array( _state, model::JSON_ERROR_EVENT ) );

	sxy::model::event_ids error_events;
	SX_FOR( const rapidjson::Value* const an_event, error_event_list )
	{
		const std::string event_name = get_object_member_string( sxe::ref( *an_event ), model::JSON_EVENT_NAME );
		sxy::model::event_id event_id = get_event_id_by_name( event_name );
		error_events.push_back( event_id );
	}
	return( error_events );
}


model::composite_state_model_uptr json_reader::read_composite_state( const rapidjson::Value& _root )
{
	std::string name = get_object_member_string( sxe::ref(_root), model::JSON_NAME_NODE );
	std::string enter_behavior_string = get_object_member_string( sxe::ref( _root), model::JSON_ENTER_BEHAVIOR_NODE );
	std::string exit_behavior_string = get_object_member_string( sxe::ref( _root), model::JSON_EXIT_BEHAVIOR_NODE );
	sxe::SX_UNIQUE_PTR< model::composite_state_model_impl > one_composite_state =
		SX_MAKE_UNIQUE< model::composite_state_model_impl >( name, enter_behavior_string,
		exit_behavior_string, read_deferred_events( _root ) );
	std::vector<const rapidjson::Value*> json_regions = 
		extract_members_from_array( get_object_member_array( _root, model::JSON_REGIONS_NODE ) );

	SX_FOR( const rapidjson::Value* one_region , json_regions )
	{
		model::region_model_impl_uptr region = read_region( *one_region );
		one_composite_state->add_region( sxe::move( region ) );
	}

	std::vector<const rapidjson::Value*> json_state_pseudostates =
		extract_members_from_array( get_object_member_array( _root, model::JSON_STATE_PSEUDOSTATES_NODE ) );

	SX_FOR( const rapidjson::Value* one_state_pseudostate, json_state_pseudostates )
	{
		model::pseudostate_model_uptr state_pseudostate = read_state_pseudostate( *one_state_pseudostate );
		one_composite_state->add_state_pseudostate( sxe::move( state_pseudostate ) );
	}

	return( one_composite_state );
}


model::simple_state_model_uptr json_reader::read_simple_state( const rapidjson::Value& _state, bool _is_async )
{
	std::string name = get_object_member_string( sxe::ref( _state), model::JSON_NAME_NODE );
	std::string enter_behavior = get_object_member_string( sxe::ref( _state), model::JSON_ENTER_BEHAVIOR_NODE );
	std::string do_behavior = get_object_member_string( sxe::ref( _state), model::JSON_DO_BEHAVIOR_NODE );
	std::string exit_behavior = get_object_member_string( sxe::ref( _state), model::JSON_EXIT_BEHAVIOR_NODE );
	sxy::model::event_sptr error_event = sxy::model::event_sptr();
	try
	{
		const std::string behavior_exception_event = get_object_member_string( _state, model::JSON_ERROR_EVENT );
		if( !behavior_exception_event.empty() )
		{
			const sxy::model::event_id behavior_exception_event_id = get_event_id_by_name( behavior_exception_event );
			const sxy::model::event_priority behavior_exception_event_priority = 
				get_event_priority_by_name( behavior_exception_event );
			error_event = SX_MAKE_SHARED<sxy::model::event_model>( behavior_exception_event, behavior_exception_event_id, 
				behavior_exception_event_priority );
		}
	}
	catch ( ... )
	{
		// try to read error event as a list of error event objects
		try
		{
			sxy::model::event_ids error_events = read_error_events( _state );
			if( !error_events.empty() )
			{
				const std::string event_name = get_event_name( error_events.at( 0 ) );
				error_event = SX_MAKE_SHARED<sxy::model::event_model>( event_name, error_events.at( 0 ),
					get_event_priority_by_name( event_name ) );
			}
		}
		catch( ... )
		{
			// Nothing to do...
		}
	}
	sxe::SX_UNIQUE_PTR< model::simple_state_model_impl > simple_state =
		SX_MAKE_UNIQUE< model::simple_state_model_impl >( name, enter_behavior,
		do_behavior, exit_behavior, read_deferred_events( _state ), error_event, _is_async );
	return( simple_state );
}


model::final_state_model_uptr json_reader::read_final_state( const rapidjson::Value& _state )
{
	std::string name = get_object_member_string( sxe::ref( _state), model::JSON_NAME_NODE );
	sxe::SX_UNIQUE_PTR< model::final_state_model_impl > final_state =
		SX_MAKE_UNIQUE< model::final_state_model_impl >( name );
	return( final_state );
}


model::region_model_impl_uptr json_reader::read_region( const rapidjson::Value& _region )
{
	const std::string name = get_object_member_string( sxe::ref( _region ), model::JSON_NAME_NODE );
	sxe::SX_UNIQUE_PTR< model::region_model_impl > region =
		SX_MAKE_UNIQUE< model::region_model_impl >( name );
	std::vector<const rapidjson::Value*> vertices =
		extract_members_from_array( get_object_member_array( _region, model::JSON_VERTICES_NODE ) );

	SX_FOR( const rapidjson::Value* vertice, vertices )
	{
		sxy::model::model_element_type vertex_type = model::model_element_type_from_string( get_object_member_string( sxe::ref( *vertice ),
			model::JSON_TYPE_NODE ) );

		if( vertex_type == sxy::model::model_element_type::TYE_SIMPLE_STATE ||
			vertex_type == sxy::model::model_element_type::TYE_ASYNC_SIMPLE_STATE ||
			vertex_type == sxy::model::model_element_type::TYE_COMPOSITE_STATE ||
			vertex_type == sxy::model::model_element_type::TYE_FINAL_STATE )
		{
			sxy::model::state_model_uptr state = read_state( *vertice );
			region->add_state( sxe::move( state ) );
		}
		else
		{
			sxy::model::pseudostate_model_uptr pseudostate = read_pseudostate( *vertice );
			region->add_pseudostate( sxe::move( pseudostate ) );
		}
	}

	// backward compatibility -> in the region there is one list : 'vertices'. Before there were two: 'states' and 'pseudostates'.
	try{
		std::vector<const rapidjson::Value*> pseudostates_vertices =
			extract_members_from_array( get_object_member_array( _region, model::JSON_PSEUDOSTATES_NODE ) );
		SX_FOR( const rapidjson::Value* pseudostate_vertex, pseudostates_vertices )
		{
			sxy::model::model_element_type vertex_type = model::model_element_type_from_string( get_object_member_string( sxe::ref( *pseudostate_vertex ),
				model::JSON_TYPE_NODE ) );

			if( vertex_type == sxy::model::model_element_type::TYE_SIMPLE_STATE ||
				vertex_type == sxy::model::model_element_type::TYE_ASYNC_SIMPLE_STATE ||
				vertex_type == sxy::model::model_element_type::TYE_COMPOSITE_STATE ||
				vertex_type == sxy::model::model_element_type::TYE_FINAL_STATE )
			{
				// Nothing to do...
			}
			else
			{
				sxy::model::pseudostate_model_uptr pseudostate = read_pseudostate( *pseudostate_vertex );
				region->add_pseudostate( sxe::move( pseudostate ) );
			}
		}
	}
	catch( const model::exception& _e )
	{
		if( ::std::strcmp( _e.what(), "Member pseudostates was not found!" ) != 0 )
		{
			throw sxe::exception( "Unexpected error occurred: %" , _e.what() );
		}
	}

	return( region );
}


model::state_model_uptr json_reader::read_state( const rapidjson::Value& _state )
{
	model::state_model_uptr state;

	const model::model_element_type state_type = model::model_element_type_from_string( get_object_member_string( sxe::ref( _state ), 
		model::JSON_TYPE_NODE ) );
#ifndef SX_CPP03_BOOST
	switch( state_type )
#else
	switch( state_type.value_ )
#endif
	{
	case model::model_element_type::TYE_SIMPLE_STATE:
	{
		state = read_simple_state( _state );
		break;
	}

	case model::model_element_type::TYE_ASYNC_SIMPLE_STATE:
	{
		state = read_simple_state( _state, true );
		break;
	}

	case model::model_element_type::TYE_COMPOSITE_STATE:
	{
		state = read_composite_state( _state );
		break;
	}

	case model::model_element_type::TYE_FINAL_STATE:
	{
		state = read_final_state( _state );
		break;
	}

	default:
	{
		throw sxe::exception( "The element % in the array of states, is not a state!",
			get_object_member_string( sxe::ref(_state), model::JSON_NAME_NODE ) );
	}
	}

	return( state );
}


model::pseudostate_model_uptr json_reader::read_state_pseudostate( const rapidjson::Value& _state_pseudostate )
{
	model::pseudostate_model_uptr pseudostate;

	switch( model::model_element_type_from_string( get_object_member_string( sxe::ref( _state_pseudostate), model::JSON_TYPE_NODE ) ) )
	{
	case model::model_element_type::TYE_ENTRY_POINT:
	{
		pseudostate = read_entry_point( _state_pseudostate );
		break;
	}

	case model::model_element_type::TYE_EXIT_POINT:
	{
		pseudostate = read_exit_point( _state_pseudostate );
		break;
	}

	case model::model_element_type::TYE_DEEP_HISTORY:
	{
		pseudostate = read_deep_history( _state_pseudostate );
		break;
	}

	case model::model_element_type::TYE_SHALLOW_HISTORY:
	{
		pseudostate = read_shallow_history( _state_pseudostate );
		break;
	}

	default:
	{
		throw sxe::exception( "The element % in the array of state-pseudostates, is not a state pseudostate!",
			get_object_member_string( sxe::ref( _state_pseudostate), model::JSON_NAME_NODE ) );
	}
	}

	return( pseudostate );
}


model::pseudostate_model_uptr json_reader::read_pseudostate( const rapidjson::Value& _pseudostate )
{
	model::pseudostate_model_uptr pseudostate;

	switch( model::model_element_type_from_string( get_object_member_string( sxe::ref( _pseudostate), model::JSON_TYPE_NODE ) ) )
	{
	case model::model_element_type::TYE_JOIN:
	{
		pseudostate = read_join( _pseudostate );
		break;
	}

	case model::model_element_type::TYE_JUNCTION:
	{
		pseudostate = read_junction( _pseudostate );
		break;
	}

	case model::model_element_type::TYE_INITIAL_PSEUDOSTATE:
	{
		pseudostate = read_initial_pseudostate( _pseudostate );
		break;
	}

	case model::model_element_type::TYE_TERMINATE_PSEUDOSTATE:
	{
		pseudostate = read_terminate_pseudostate( _pseudostate );
		break;
	}

	case model::model_element_type::TYE_CHOICE:
	{
		pseudostate = read_choice( _pseudostate );
		break;
	}

	case model::model_element_type::TYE_FORK:
	{
		pseudostate = read_fork( _pseudostate );
		break;
	}

	default:
	{
		throw sxe::exception( "The element % in the array of states, is not a state!",
			get_object_member_string( sxe::ref( _pseudostate), model::JSON_NAME_NODE ) );
	}
	}

	return( pseudostate );
}


model::initial_pseudostate_model_uptr json_reader::read_initial_pseudostate( const rapidjson::Value& _pseudostate )
{
	return( function_read_pseudostate< model::initial_pseudostate_model_impl >( _pseudostate ) );
}


model::join_model_uptr json_reader::read_join( const rapidjson::Value& _pseudostate )
{
	return( function_read_pseudostate< model::join_model_impl >( _pseudostate ) );
}


model::fork_model_uptr json_reader::read_fork( const rapidjson::Value& _pseudostate )
{
	return( function_read_pseudostate< model::fork_model_impl >( _pseudostate ) );
}


model::choice_model_uptr json_reader::read_choice( const rapidjson::Value& _pseudostate )
{
	return( function_read_pseudostate< model::choice_model_impl >( _pseudostate ) );
}


model::junction_model_uptr json_reader::read_junction( const rapidjson::Value& _pseudostate )
{
	return( function_read_pseudostate< model::junction_model_impl >( _pseudostate ) );
}


model::terminate_pseudostate_model_uptr json_reader::read_terminate_pseudostate(
	const rapidjson::Value& _pseudostate )
{
	return( function_read_pseudostate< model::terminate_pseudostate_model_impl >( _pseudostate ) );
}


model::deep_history_model_uptr json_reader::read_deep_history( const rapidjson::Value& _pseudostate )
{
	return( function_read_pseudostate< model::deep_history_model_impl >( _pseudostate ) );
}


model::shallow_history_model_uptr json_reader::read_shallow_history( const rapidjson::Value& _pseudostate )
{
	return( function_read_pseudostate< model::shallow_history_model_impl >( _pseudostate ) );
}


model::entry_point_model_uptr json_reader::read_entry_point( const rapidjson::Value& _pseudostate )
{
	return( function_read_pseudostate< model::entry_point_model_impl >( _pseudostate ) );
}


model::exit_point_model_uptr json_reader::read_exit_point( const rapidjson::Value& _pseudostate )
{
	return( function_read_pseudostate< model::exit_point_model_impl >( _pseudostate ) );
}


model::transition_model_uptr json_reader::read_transition( const rapidjson::Value& _transition )
{
	const std::string name = get_object_member_string( sxe::ref( _transition), model::JSON_NAME_NODE );
	sxe::int64_t json_transition_kind = get_object_member_int( sxe::ref( _transition ), model::JSON_TRANSITION_KIND_NODE );
	const std::string source_vertex = 
		get_object_member_string( sxe::ref( _transition ), model::JSON_TRANSITION_SOURCE_NODE );
	const std::string target_vertex = 
		get_object_member_string( sxe::ref( _transition ), model::JSON_TRANSITION_TARGET_NODE );
	const std::string transition_guard = 
		get_object_member_string( sxe::ref( _transition ), model::JSON_TRANSITION_GUARD_NODE );
	const std::string transition_behavior = 
		get_object_member_string( sxe::ref( _transition ), model::JSON_TRANSITION_BEHAVIOR_NODE );
	std::vector<const rapidjson::Value*> events_list =
		extract_members_from_array( get_object_member_array( _transition, model::JSON_TRANSITION_EVENTS_NODE ) );
	sxy::model::event_ids events;

	SX_FOR( const rapidjson::Value* one_event, events_list )
	{
		if( one_event->IsObject() )
		{
			const std::string event_name = get_object_member_string( sxe::ref( *one_event ), model::JSON_EVENT_NAME );
			sxe::int32_t event_id = get_event_id_by_name( event_name );
			events.push_back( event_id );
		}
		else
		{
			throw sxe::exception( "Event is not an JSON object! Structure is broken." );
		}
	}

	sxy::model::transition_model_kind kind = get_transition_kind( json_transition_kind );
	sxe::SX_UNIQUE_PTR< model::transition_model_impl > transition = 
		SX_MAKE_UNIQUE< model::transition_model_impl >( name, sxe::uri( source_vertex ), sxe::uri( target_vertex ),
			kind, transition_behavior, transition_guard, events );
	return( transition );
}


sxy::model::transition_model_kind json_reader::get_transition_kind( sxe::int64_t _kind )
{
	sxy::model::transition_model_kind kind( sxy::model::transition_model_kind::EXTERNAL );
	switch( _kind )
	{
	case 0:
		kind = sxy::model::transition_model_kind::EXTERNAL;
		break;

	case 1:
		kind = sxy::model::transition_model_kind::INTERNAL;
		break;

	case 2:
		kind = sxy::model::transition_model_kind::LOCAL;
		break;

	default:
		throw sxe::exception( "Transition has no legal kind (LOCAL, EXTERNAL, INTERNAL)." );
		break;
	}

	return( kind );
}


sxe::int32_t json_reader::get_event_id_by_name( const std::string& _name ) const
{
	sxe::int32_t event_id = sxy::model::Y_MODEL_COMPLETION_EVENT_ID;
	std::vector<const rapidjson::Value*> event_list =
		extract_members_from_array( get_object_member_array( document_, model::JSON_EVENT_LIST_NODE ) );

	SX_FOR( const rapidjson::Value* const an_event, event_list )
	{
		const std::string event_name = get_object_member_string( sxe::ref( *an_event ), model::JSON_EVENT_NAME );
		if( event_name == _name )
		{
			// FixME: safe cast
			event_id = static_cast< sxe::int32_t >( get_object_member_int( sxe::ref( *an_event ), model::JSON_EVENT_ID ) );
			break;
		}
	}

	return( event_id );
}


std::string json_reader::get_event_name( const sxe::int32_t _event_id ) const
{
	std::string event_name = "";
	std::vector<const rapidjson::Value*> event_list =
		extract_members_from_array( get_object_member_array( document_, model::JSON_EVENT_LIST_NODE ) );

	SX_FOR( const rapidjson::Value* const an_event, event_list )
	{
		// FixME: safe cast
		sxe::int32_t event_id = static_cast< sxe::int32_t >( get_object_member_int( sxe::ref( *an_event ), model::JSON_EVENT_ID ) );
		if( event_id == _event_id )
		{
			event_name = get_object_member_string( sxe::ref( *an_event ), model::JSON_EVENT_NAME );
			break;
		}
	}
	return( event_name );
}


sxe::int8_t json_reader::get_event_priority_by_name( const std::string& _name ) const
{
#ifdef SX_CPP03_BOOST
	sxe::int8_t priority ( DEFAULT_EVENT_PRIORITY);
#else
	sxe::int8_t priority( sxy::model::DEFAULT_EVENT_PRIORITY );
#endif
	std::vector<const rapidjson::Value*> event_list =
		extract_members_from_array( get_object_member_array( document_, model::JSON_EVENT_LIST_NODE ) );

	SX_FOR( const rapidjson::Value* const an_event, event_list )
	{
		const std::string event_name = get_object_member_string( sxe::ref( *an_event ), model::JSON_EVENT_NAME );
		if( event_name == _name )
		{
			try
			{
				// FixME: safe cast
				priority = static_cast< sxe::int8_t > ( get_object_member_int( sxe::ref( *an_event ), model::JSON_EVENT_PRIORITY ) );
			}
			catch( ... )
			{
#ifdef SX_CPP03_BOOST
				priority = DEFAULT_EVENT_PRIORITY;
#else
				priority = sxy::model::DEFAULT_EVENT_PRIORITY;
#endif
			}
			break;
		}
	}

	return( priority );
}



void json_reader::get_event_list( model::state_machine_model_ptr& _model )
{
	std::vector<const rapidjson::Value*> event_list =
		extract_members_from_array( get_object_member_array( document_, model::JSON_EVENT_LIST_NODE ) );

	SX_FOR( const rapidjson::Value* const an_event, event_list )
	{
		const std::string event_name = get_object_member_string( sxe::ref( *an_event ), model::JSON_EVENT_NAME );
		// FixME: safe cast
		sxy::model::event_id event_id = static_cast< sxy::model::event_id >( get_object_member_int( sxe::ref( *an_event ), 
			model::JSON_EVENT_ID ) );
#ifdef SX_CPP03_BOOST
		sxy::model::event_priority priority = DEFAULT_EVENT_PRIORITY;
#else
		sxy::model::event_priority priority = sxy::model::DEFAULT_EVENT_PRIORITY;
#endif
		if( document_.HasMember( model::JSON_VERSION ) )
		{
			const std::string json_version = get_object_member_string( document_, model::JSON_VERSION );
			if( json_version != model::JSON_VERSION_1 )
			{
				// FixME: safe cast
				priority = static_cast<sxy::model::event_priority >( get_object_member_int( sxe::ref( *an_event ), 
					model::JSON_EVENT_PRIORITY ) );
			}
		}
		_model->add_event( event_name, event_id, priority );
	}
}


void json_reader::check_document() const
{
	if( !document_.IsObject() )
	{
		throw model::exception( "Model file is corrupted!" );
	}

	if( document_.ObjectEmpty() )
	{
		throw model::exception( "Model file is corrupted!" );
	}
}


}
