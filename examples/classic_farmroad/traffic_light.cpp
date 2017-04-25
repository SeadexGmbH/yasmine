//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "traffic_light.hpp"

#include <iostream>

#include "yasmine.hpp"


namespace examples
{


namespace
{


#ifdef SX_CPP03_BOOST
	Y_EVENT_WITH_ID( EVENT_SWITCH_TO_RED_YELLOW, 1 )
	Y_EVENT_WITH_ID( EVENT_SWITCH_TO_GREEN, 2 )
	Y_EVENT_WITH_ID( EVENT_SWITCH_TO_YELLOW, 3 )
	Y_EVENT_WITH_ID( EVENT_SWITCH_TO_RED, 4 )
#else
	Y_EVENT_CREATE( EVENT_SWITCH_TO_RED_YELLOW, 1 )
	Y_EVENT_CREATE( EVENT_SWITCH_TO_GREEN, 2 )
	Y_EVENT_CREATE( EVENT_SWITCH_TO_YELLOW, 3 )
	Y_EVENT_CREATE( EVENT_SWITCH_TO_RED, 4 )
#endif


}


traffic_light::traffic_light(	const std::string& _name,	const std::string& _ascii_prefix )
	: traffic_light_state_machine_( _name ),
		name_( _name ),
		ascii_prefix_( _ascii_prefix )
{
	build_traffic_light_state_machine();
}


traffic_light::~traffic_light() SX_NOEXCEPT
{
	// Nothing to do...
}


void traffic_light::start()
{
	traffic_light_state_machine_.run();
}


void traffic_light::stop()
{
	traffic_light_state_machine_.halt_and_join();
}


void traffic_light::switch_to_red_yellow()
{
	traffic_light_state_machine_.fire_event( EVENT_SWITCH_TO_RED_YELLOW::create() );
}


void traffic_light::switch_to_green()
{
	traffic_light_state_machine_.fire_event( EVENT_SWITCH_TO_GREEN::create() );
}


void traffic_light::switch_to_yellow()
{
	traffic_light_state_machine_.fire_event( EVENT_SWITCH_TO_YELLOW::create() );
}


void traffic_light::switch_to_red()
{
	traffic_light_state_machine_.fire_event( EVENT_SWITCH_TO_RED::create() );
}


void traffic_light::on_traffic_light_red() const
{
	std::cout << display_road_name_with_ascii_prefix() << " is now red." << std::endl;
}


void traffic_light::on_traffic_light_red_yellow() const
{
	std::cout << display_road_name_with_ascii_prefix() << " is now red-yellow." << std::endl;
}


void traffic_light::on_traffic_light_green() const
{
	std::cout << display_road_name_with_ascii_prefix() << " is now green." << std::endl;
}


void traffic_light::on_traffic_light_yellow() const
{
	std::cout << display_road_name_with_ascii_prefix() << " is now yellow." << std::endl;
}


void traffic_light::build_traffic_light_state_machine()
{
	sxy::composite_state& root = traffic_light_state_machine_.get_root_state();
	sxy::region& main_region = root.add_region( "main_region" );
	sxy::initial_pseudostate& initial_pseudostate = main_region.add_initial_pseudostate( "initial" );

	// states
#ifdef SX_CPP03_BOOST
	sxy::simple_state& red_state =
		main_region.add_simple_state( "Red", Y_BEHAVIOR_METHOD_NO_EVENT( traffic_light, on_traffic_light_red ) );
	sxy::simple_state& red_yellow_state =
		main_region.add_simple_state( "Red-Yellow",
			Y_BEHAVIOR_METHOD_NO_EVENT( traffic_light, on_traffic_light_red_yellow ) );
	sxy::simple_state& green_state =
		main_region.add_simple_state( "Green", Y_BEHAVIOR_METHOD_NO_EVENT( traffic_light, on_traffic_light_green ) );
	sxy::simple_state& yellow_state =
		main_region.add_simple_state( "Yellow", Y_BEHAVIOR_METHOD_NO_EVENT( traffic_light, on_traffic_light_yellow ) );
#else
	sxy::simple_state& red_state = main_region.add_simple_state( "Red", 
		Y_BEHAVIOR_METHOD2( this, &traffic_light::on_traffic_light_red ) );
	sxy::simple_state& red_yellow_state = main_region.add_simple_state( "Red-Yellow", 
		Y_BEHAVIOR_METHOD2( this, &traffic_light::on_traffic_light_red_yellow ) );
	sxy::simple_state& green_state = main_region.add_simple_state( "Green",
		Y_BEHAVIOR_METHOD2( this, &traffic_light::on_traffic_light_green ) );
	sxy::simple_state& yellow_state = main_region.add_simple_state( "Yellow", 
		Y_BEHAVIOR_METHOD2( this, &traffic_light::on_traffic_light_yellow ) );
#endif

	// transitions
	traffic_light_state_machine_.add_transition( sxy::Y_COMPLETION_EVENT_ID, initial_pseudostate, red_state );
	traffic_light_state_machine_.add_transition( EVENT_SWITCH_TO_RED_YELLOW::get_event_id(), red_state,
		red_yellow_state );
	traffic_light_state_machine_.add_transition( EVENT_SWITCH_TO_GREEN::get_event_id(), red_yellow_state, green_state );
	traffic_light_state_machine_.add_transition( EVENT_SWITCH_TO_YELLOW::get_event_id(), green_state, yellow_state );
	traffic_light_state_machine_.add_transition( EVENT_SWITCH_TO_RED::get_event_id(), yellow_state, red_state );
}


std::string traffic_light::display_road_name_with_ascii_prefix() const
{
	return( ascii_prefix_ + name_ );
}


}
