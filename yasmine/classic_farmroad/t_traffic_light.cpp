//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_traffic_light.h"

#include <iostream>

#include "t_async_state_machine.h"
#include "t_event.h"
#include "i_composite_state.h"
#include "i_region.h"
#include "t_behavior.h"
#include "i_initial_pseudostate.h"
#include "i_simple_state.h"
#include "i_transition.h"


namespace sxy
{


namespace
{


constexpr t_event_id g_event_switch_to_red_yellow = 1;
constexpr t_event_id g_event_switch_to_green = 2;
constexpr t_event_id g_event_switch_to_yellow = 3;
constexpr t_event_id g_event_switch_to_red = 4;


}


t_traffic_light::t_traffic_light
(
	const std::string& p_name,
	const std::string& p_ascii_prefix
):	
	m_traffic_light_state_machine( p_name ),
	m_name( p_name ),
	m_ascii_prefix( p_ascii_prefix )
{			
	build_traffic_light_state_machine();
}


t_traffic_light::~t_traffic_light
(
) = default;


void
t_traffic_light::start
(
)
{		
	m_traffic_light_state_machine.run();
}


void
t_traffic_light::stop
(
)
{
	m_traffic_light_state_machine.halt();
}


void
t_traffic_light::switch_to_red_yellow
(
)
{	
	m_traffic_light_state_machine.fire_event( t_event::create_event( g_event_switch_to_red_yellow ) );
}


void
t_traffic_light::switch_to_green
(
)
{		
	m_traffic_light_state_machine.fire_event( t_event::create_event( g_event_switch_to_green ) );
}


void
t_traffic_light::switch_to_yellow
(
)
{		
	m_traffic_light_state_machine.fire_event( t_event::create_event( g_event_switch_to_yellow ) );
}


void
t_traffic_light::switch_to_red
(
)
{		
	m_traffic_light_state_machine.fire_event( t_event::create_event( g_event_switch_to_red ) );
}


void
t_traffic_light::on_traffic_light_red
(
) const
{
	std::cout << display_road_name_with_ascii_prefix() << " is now red." << std::endl;
}


void
t_traffic_light::on_traffic_light_red_yellow
(
)	const
{
	std::cout << display_road_name_with_ascii_prefix() << " is now red-yellow." << std::endl;
}


void
t_traffic_light::on_traffic_light_green
(
)	const
{
	std::cout << display_road_name_with_ascii_prefix() << " is now green." << std::endl;
}


void
t_traffic_light::on_traffic_light_yellow
(
)	const
{
	std::cout << display_road_name_with_ascii_prefix() << " is now yellow." << std::endl;
}


void
t_traffic_light::build_traffic_light_state_machine
(
)
{	
	auto& l_root = m_traffic_light_state_machine.get_root_state();
	auto& l_main_region = l_root.add_region( "main_region" );
	auto& l_initial_pseudostate = l_main_region.add_initial_pseudostate( "initial" );

	// behaviors	
	auto l_on_red_yellow = [ & ] ( const sxy::i_event& p_event ) { on_traffic_light_red_yellow(); };
	auto l_on_green = [ & ] ( const sxy::i_event& p_event ) { on_traffic_light_green(); };
	auto l_on_yellow = [ & ] ( const sxy::i_event& p_event ) { on_traffic_light_yellow(); };
	auto l_on_red =  [ & ] ( const sxy::i_event& p_event ) { on_traffic_light_red(); };

	// states
	auto& l_red_state = l_main_region.add_simple_state( "Red", l_on_red, nullptr, nullptr );
	auto& l_red_yellow_state = l_main_region.add_simple_state( "Red-Yellow", l_on_red_yellow, nullptr, nullptr );
	auto& l_green_state = l_main_region.add_simple_state( "Green",  l_on_green, nullptr, nullptr );
	auto& l_yellow_state = l_main_region.add_simple_state( "Yellow",  l_on_yellow, nullptr, nullptr );


	// transitions
	m_traffic_light_state_machine.add_transition( "initial", COMPLETION_EVENT, l_initial_pseudostate, l_red_state );
	m_traffic_light_state_machine.add_transition( "switch_to_red_yellow", g_event_switch_to_red_yellow, l_red_state, l_red_yellow_state );
	m_traffic_light_state_machine.add_transition( "switch_to_green", g_event_switch_to_green, l_red_yellow_state, l_green_state );
	m_traffic_light_state_machine.add_transition( "switch_to_yellow", g_event_switch_to_yellow, l_green_state, l_yellow_state );
	m_traffic_light_state_machine.add_transition( "switch_to_red", g_event_switch_to_red, l_yellow_state, l_red_state );
}


std::string
t_traffic_light::display_road_name_with_ascii_prefix
(			
) const
{		
	return( m_ascii_prefix + m_name );
}


}
