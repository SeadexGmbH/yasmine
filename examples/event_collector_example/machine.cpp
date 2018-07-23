//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "machine.hpp"
#include "events.hpp"


namespace examples
{

	machine::machine()
		: state_machine_(),
		  action_()
	{
		state_machine_ = setup_state_machine( "event collector state machine" );
		run_machine();
	}
	
	
	machine::~machine() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	int machine::run_machine()
	{
		int error_code = 0;
		if( check_state_machine_for_defects( *state_machine_ ) )
		{
			state_machine_->run();
			try
			{
				state_machine_->fire_event( examples::E1::create() );
				state_machine_->halt();
			}
			catch( const std::exception& exception )
			{
				SX_LOG( hermes::log_level::LL_FATAL, "Unhandled exception: '%'.", exception.what() );
				error_code = 1;
			}
			catch( ... )
			{
				SX_LOG( hermes::log_level::LL_FATAL, "Unknown exception!" );
				error_code = 2;
			}
		}
		else
		{
			error_code = 3;
		}

		return( error_code );
	}


	state_machine_uptr machine::setup_state_machine( const std::string& _name )
	{
		state_machine_uptr state_machine = SX_MAKE_UNIQUE< sxy::sync_state_machine >( _name );
		sxy::composite_state& root_state = state_machine->get_root_state();
		sxy::region& main_region = root_state.add_region( "main region" );
		sxy::initial_pseudostate& initial = main_region.add_initial_pseudostate( "initial" );
		sxy::simple_state& s1 = main_region.add_simple_state( "S1" );
		action* action_ptr = &action_;
		sxy::simple_state& s2 = main_region.add_simple_state( "S2",
			Y_BEHAVIOR_METHOD2( action_ptr, &action::fire_event_E3 ), Y_EMPTY_BEHAVIOR, Y_EMPTY_BEHAVIOR );
		sxy::simple_state& s3 = main_region.add_simple_state( "S3" );
		sxy::simple_state& s4 = main_region.add_simple_state( "S4" );
		sxy::final_state& final = main_region.add_final_state( "final" );
		state_machine->add_transition( sxy::Y_COMPLETION_EVENT_ID, initial, s1 );
		state_machine->add_transition( examples::E1::get_event_id(), s1, s2 );
		state_machine->add_transition( examples::E2::get_event_id(), s2, s3 );
		state_machine->add_transition( examples::E3::get_event_id(), s2, s4 );
		state_machine->add_transition( sxy::Y_COMPLETION_EVENT_ID, s4, s3, 
			Y_BEHAVIOR_METHOD2( action_ptr, &examples::action::fire_event_E4 ) );
		state_machine->add_transition( examples::E4::get_event_id(), s3, final,
			Y_BEHAVIOR_METHOD2( action_ptr, &examples::action::print_message_from_event ) );
		state_machine->add_transition( examples::E1::get_event_id(), s3, s2 );

		return( state_machine );
	}


	bool machine::check_state_machine_for_defects( const sxy::sync_state_machine& _state_machine )
	{
		sxy::state_machine_defects defects;
		const bool state_machine_has_no_defects = _state_machine.check( defects );
		if( !state_machine_has_no_defects )
		{
			sxy::write_defects_to_log( defects );
		}

		return( state_machine_has_no_defects );
	}

}
