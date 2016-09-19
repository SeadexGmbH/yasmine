//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "traffic_light.hpp"

#include <iostream>

#include "yasmine.hpp"


namespace sxy
{


namespace
{


constexpr event_id EVENT_SWITCH_TO_RED_YELLOW = 1;
constexpr event_id EVENT_SWITCH_TO_GREEN = 2;
constexpr event_id EVENT_SWITCH_TO_YELLOW = 3;
constexpr event_id EVENT_SWITCH_TO_RED = 4;


}


traffic_light::traffic_light( const std::string& _name, const std::string& _ascii_prefix )
	: traffic_light_state_machine_( _name ),
		name_( _name ),
		ascii_prefix_( _ascii_prefix )
{
	build_traffic_light_state_machine();
}


traffic_light::~traffic_light() = default;
void traffic_light::start()
{
	traffic_light_state_machine_.start_state_machine();
}


void traffic_light::stop()
{
	traffic_light_state_machine_.stop_state_machine();
}


void traffic_light::switch_to_red_yellow()
{
	traffic_light_state_machine_.fire_event( event_impl::create( EVENT_SWITCH_TO_RED_YELLOW ) );
}


void traffic_light::switch_to_green()
{
	traffic_light_state_machine_.fire_event( event_impl::create( EVENT_SWITCH_TO_GREEN ) );
}


void traffic_light::switch_to_yellow()
{
	traffic_light_state_machine_.fire_event( event_impl::create( EVENT_SWITCH_TO_YELLOW ) );
}


void traffic_light::switch_to_red()
{
	traffic_light_state_machine_.fire_event( event_impl::create( EVENT_SWITCH_TO_RED ) );
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
	auto& root = traffic_light_state_machine_.get_root_state();
	auto& main_region = root.add_region( "main_region" );
	auto& initial_pseudostate = main_region.add_initial_pseudostate( "initial" );

	// states
	auto& red_state = main_region.add_simple_state( "Red", Y_BEHAVIOR_METHOD_NO_EVENT( on_traffic_light_red ) );
	auto& red_yellow_state = main_region.add_simple_state( "Red-Yellow", 
		Y_BEHAVIOR_METHOD_NO_EVENT( on_traffic_light_red_yellow ) );
	auto& green_state = main_region.add_simple_state( "Green", Y_BEHAVIOR_METHOD_NO_EVENT( on_traffic_light_green ) );
	auto& yellow_state = main_region.add_simple_state( "Yellow", Y_BEHAVIOR_METHOD_NO_EVENT( on_traffic_light_yellow ) );

	// transitions
	traffic_light_state_machine_.add_transition( COMPLETION_EVENT, initial_pseudostate, red_state );
	traffic_light_state_machine_.add_transition( EVENT_SWITCH_TO_RED_YELLOW, red_state, red_yellow_state );
	traffic_light_state_machine_.add_transition( EVENT_SWITCH_TO_GREEN, red_yellow_state, green_state );
	traffic_light_state_machine_.add_transition( EVENT_SWITCH_TO_YELLOW, green_state,	yellow_state );
	traffic_light_state_machine_.add_transition( EVENT_SWITCH_TO_RED, yellow_state, red_state );
}


std::string traffic_light::display_road_name_with_ascii_prefix() const
{
	return( ascii_prefix_ + name_ );
}


}
