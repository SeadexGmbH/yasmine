//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "state_machine_with_submachines.hpp"


namespace sxy
{


state_machine_with_submachines::state_machine_with_submachines()
	: state_machine_( Y_MAKE_UNIQUE<sxy::state_machine>( "sub state machines and variables" ) ),
		submachine1_(),
		submachine2_()
{
	// Nothing to do...
}


state_machine_with_submachines::~state_machine_with_submachines() Y_NOEXCEPT
{
	// Nothing to do...
}


	
void state_machine_with_submachines::create()
{	
	sxy::composite_state& root_state = state_machine_->get_root_state();
	sxy::region& main_region = root_state.add_region( "main region" );
	sxy::initial_pseudostate& initial_pseudostate = main_region.add_initial_pseudostate( "initial pseudostate" );
	sxy::simple_state& simple_state_1 = main_region.add_simple_state( "simple_state_1" );

	submachine1_ = Y_MAKE_UNIQUE<submachine>( sxy::ref( *state_machine_ ), sxy::ref( main_region ) );
	submachine2_ = Y_MAKE_UNIQUE<submachine>( sxy::ref( *state_machine_ ), sxy::ref( main_region ) );

	sxy::final_state& final_state = main_region.add_final_state( "final state" );

	state_machine_->add_transition( COMPLETION_EVENT_ID, initial_pseudostate, simple_state_1 );
	state_machine_->add_transition( EVENT_1, simple_state_1, submachine1_->get_submachine_root_state() );
	state_machine_->add_transition( EVENT_2, submachine1_->get_submachine_root_state(), simple_state_1 );
	state_machine_->add_transition( EVENT_3, simple_state_1, submachine2_->get_submachine_root_state() );
	state_machine_->add_transition( EVENT_4, submachine2_->get_submachine_root_state(), final_state );
}


void state_machine_with_submachines::run()
{
	state_machine_->start_state_machine();
	state_machine_->fire_event( event_1::create() );
	state_machine_->fire_event( event_5::create( "Hello!" ) );
	state_machine_->fire_event( event_5::create( "yasmine" ) );
	state_machine_->fire_event( event_2::create() );
	state_machine_->fire_event( event_3::create() );
	state_machine_->fire_event( event_5::create( "abc" ) );
	state_machine_->fire_event( event_5::create( "xyz" ) );
	state_machine_->fire_event( event_5::create( "123" ) );
	state_machine_->fire_event( event_4::create() );
	state_machine_->stop_state_machine();
}


}
