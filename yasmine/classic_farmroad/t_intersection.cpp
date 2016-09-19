//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_intersection.h"

#include <iostream>

#include "t_event.h"
#include "i_composite_state.h"
#include "i_region.h"
#include "i_initial_pseudostate.h"
#include "i_simple_state.h"
#include "i_final_state.h"
#include "i_junction.h"
#include "i_transition.h"


namespace sxy
{


namespace
{


constexpr t_event_id g_detector_on = 1;
constexpr t_event_id g_detector_off = 2;
constexpr t_event_id g_timer_highway_minimum_time = 3;
constexpr t_event_id g_timer_phase_1 = 4;
constexpr t_event_id g_timer_phase_2 = 5;
constexpr t_event_id g_timer_farmroad_maximum_time = 6;
constexpr t_event_id g_event_farmroad_maximum_time_elapsed = 7;
const t_event_ids g_events_exit_farmroad_open = { g_detector_off, g_event_farmroad_maximum_time_elapsed };


const std::chrono::milliseconds g_timer_highway_minimum_time_duration( 5000 );
const std::chrono::milliseconds g_timer_phase_1_duration( 1000 );
const std::chrono::milliseconds g_timer_phase_2_duration( 1000 );
const std::chrono::milliseconds g_timer_farmroad_maximum_time_duration( 3000 );


const std::string g_farmroad_ascii_art = "--- ";
const std::string g_highway_ascii_art = "==== ";

}


t_intersection::t_intersection
(
):
	i_detector_callback(),	
	m_intersection_state_machine( "intersection state machine" ),
	m_highway_traffic_light("highway traffic light", g_highway_ascii_art ),
	m_farmroad_traffic_light("farmroad traffic light", g_farmroad_ascii_art ),
	m_timed_event_creator( m_intersection_state_machine ),
	m_detector( *this )
{		
	build_intersection_state_machine();
}


t_intersection::~t_intersection
(
) = default;


bool
t_intersection::start
(
)
{
	auto l_started = false;
	t_state_machine_defects l_defects;
	m_intersection_state_machine.check( l_defects );
	if( l_defects.empty() )
	{
		m_farmroad_traffic_light.start();
		m_highway_traffic_light.start();
		m_timed_event_creator.start();
		m_intersection_state_machine.run();
		m_detector.start();

		l_started = true;
	}
	else
	{
		std::cout << "The state machine is defect." << std::endl;

		write_defects_to_log( l_defects );
	}				 

	return( l_started );
}


void
t_intersection::stop
(
)
{
	m_detector.stop();
	m_intersection_state_machine.halt();
	m_timed_event_creator.stop();
	m_highway_traffic_light.stop();
	m_farmroad_traffic_light.stop();
}


void
t_intersection::detector_on
(
)
{
	std::cout << "Detector is on." << std::endl;

	m_intersection_state_machine.fire_event( t_event::create_event( g_detector_on ) );
}


void
t_intersection::detector_off
(
)
{	
	std::cout << "Detector is off." << std::endl;
	m_intersection_state_machine.fire_event( t_event::create_event( g_detector_off ) );
}


int
t_intersection::fire_timed_event
(
	const std::chrono::milliseconds p_milliseconds,
	const t_event_id p_event_id
)
{	
	auto l_event_handle = m_timed_event_creator.create_event_creation_request( std::chrono::milliseconds( p_milliseconds ), t_event::create_event( p_event_id ) );
	return( l_event_handle );
}
		

void
t_intersection::highway_open_entry
(
)
{
	Y_LOG( t_log_level::LL_INFO, "Highway open." );

	m_highway_traffic_light.switch_to_green();

	fire_timed_event( g_timer_highway_minimum_time_duration, g_timer_highway_minimum_time );
}


void
t_intersection::highway_open_exit
(
)
{
	Y_LOG( t_log_level::LL_INFO, "Highway closed." );
}


void
t_intersection::switching_to_farmroad_phase_1
(
)
{
	Y_LOG( t_log_level::LL_INFO, "Switching highway to farmroad. Phase 1." );

	m_highway_traffic_light.switch_to_yellow();
	m_farmroad_traffic_light.switch_to_red_yellow();

	fire_timed_event( g_timer_phase_1_duration, g_timer_phase_1 );
}


void
t_intersection::switching_to_farmroad_phase_2
(
)
{
	Y_LOG( t_log_level::LL_INFO, "Switching highway to farmroad. Phase 2." );

	m_highway_traffic_light.switch_to_red();

	fire_timed_event( g_timer_phase_2_duration, g_timer_phase_2 );
}


void
t_intersection::farmroad_open_entry
(
)
{
	Y_LOG( t_log_level::LL_INFO, "Farmroad open." );

	m_farmroad_traffic_light.switch_to_green();

	m_farmroad_maximum_time_event_handle = fire_timed_event( g_timer_farmroad_maximum_time_duration, g_timer_farmroad_maximum_time );
}


void
t_intersection::farmroad_open_exit
(
)
{
	Y_LOG( t_log_level::LL_INFO, "Farmroad closed." );
}


void
t_intersection::minimum_time_not_elapsed
(
)
{
	Y_LOG( t_log_level::LL_INFO, "Minimum time not elapsed." );
}
											

void
t_intersection::minimum_time_elapsed
(
)
{
	Y_LOG( t_log_level::LL_INFO, "Minimum time elapsed." );
}


void
t_intersection::minimum_time_not_elapsed_farmroad_waiting
(
)
{
	Y_LOG( t_log_level::LL_INFO, "Minimum time not elapsed. Farmroad waiting." );
}


void
t_intersection::switching_to_highway_phase_1
(
)
{
	Y_LOG( t_log_level::LL_INFO, "Switching farmroad to highway. Phase 1." );

	m_highway_traffic_light.switch_to_red_yellow();
	m_farmroad_traffic_light.switch_to_yellow();

	fire_timed_event( g_timer_phase_1_duration, g_timer_phase_1 );
}


void
t_intersection::switching_to_highway_phase_2
(
)
{
	Y_LOG( t_log_level::LL_INFO, "Switching farmroad to highway. Phase 2." );

	m_farmroad_traffic_light.switch_to_red();

	fire_timed_event( g_timer_phase_2_duration, g_timer_phase_2 );
}


bool
t_intersection::check_detector_is_on
(
)
{																			 
	return( m_detector.is_on() );
}


bool
t_intersection::check_detector_is_off
(
)
{
	return( !m_detector.is_on() );
}


void
t_intersection::cancel_timer_event_on_detector_off
(
	const sxy::i_event& p_event
)
{
	if( p_event.get_id() == g_detector_off )
	{
		if( m_farmroad_maximum_time_event_handle > 0 )
		{
			Y_LOG( t_log_level::LL_INFO, "Try to cancel event with handle %.", m_farmroad_maximum_time_event_handle );
			if( m_timed_event_creator.cancel( m_farmroad_maximum_time_event_handle ) )
			{
				Y_LOG( t_log_level::LL_INFO, "Event with handle % was canceled.", m_farmroad_maximum_time_event_handle );
			}
			else
			{
				Y_LOG( t_log_level::LL_INFO, "Event with handle % could not be canceled.", m_farmroad_maximum_time_event_handle );
			}
			m_farmroad_maximum_time_event_handle = 0;
		}
		else
		{
			Y_LOG( t_log_level::LL_INFO, "There is no event to be cancelled on detector off." );
		}
	}
}


void
t_intersection::build_intersection_state_machine
(
)
{
	auto& l_root = m_intersection_state_machine.get_root_state();
	auto& l_main_region = l_root.add_region( "main_region" );

	auto& l_initial_pseudostate = l_main_region.add_initial_pseudostate( "initial" );

	// highway open
	auto l_highway_open_entry = [ this ] ( const sxy::i_event& p_event ) { highway_open_entry(); };
	auto l_highway_open_exit = [ this ] ( const sxy::i_event& p_event ) {	highway_open_exit(); } ;
	auto& l_highway_open = l_main_region.add_composite_state( "highway open", l_highway_open_entry, l_highway_open_exit );

	auto& highway_open_region = l_highway_open.add_region( "highway region" );
	auto& l_initial_highway = highway_open_region.add_initial_pseudostate( "initial highway" );
	auto& l_initialize_dummy = highway_open_region.add_simple_state( "initialize dummy" );
	auto& l_detector_junction = highway_open_region.add_junction( "detector junction" );

	auto l_minimum_time_not_elapsed_behavior = [ this ] ( const sxy::i_event& p_event ) {	minimum_time_not_elapsed(); } ;
	auto& l_minimum_time_not_elapsed = highway_open_region.add_simple_state( "minimum time not elapsed", l_minimum_time_not_elapsed_behavior );

	auto l_minimum_time_elapsed_behavior = [ this ] ( const sxy::i_event& p_event ) {	minimum_time_elapsed(); } ;
	auto& l_minimum_time_elapsed = highway_open_region.add_simple_state( "minimum time elapsed", l_minimum_time_elapsed_behavior );

	auto l_minimum_time_not_elapsed_farmroad_waiting_behavior = [ this ] ( const sxy::i_event& p_event ) { minimum_time_not_elapsed_farmroad_waiting(); };
	auto& l_minimum_time_not_elapsed_farmroad_waiting = highway_open_region.add_simple_state( "Minimum time not elapsed and farmroad waiting", l_minimum_time_not_elapsed_farmroad_waiting_behavior );

	auto& l_highway_finished = highway_open_region.add_final_state( "highway finished" );


	// switching highway to farmroad
	auto& l_switching_to_farmroad = l_main_region.add_composite_state( "switching highway to farmroad" );
	auto& l_switching_to_farmroad_region = l_switching_to_farmroad.add_region( "region switching to farmroad" );
	auto& l_initial_switching_to_farmroad = l_switching_to_farmroad_region.add_initial_pseudostate( "initial switching highway to farmroad" );

	auto l_switching_to_farmroad_phase_1_entry = [ this ] ( const sxy::i_event& p_event ) {	switching_to_farmroad_phase_1(); };
	auto& l_switching_to_farmroad_phase_1 = l_switching_to_farmroad_region.add_simple_state( "switching to farmroad phase 1", l_switching_to_farmroad_phase_1_entry );

	auto l_switching_to_farmroad_phase_2_entry = [ this ] ( const sxy::i_event& p_event ) {	switching_to_farmroad_phase_2(); };
	auto& l_switching_to_farmroad_phase_2 = l_switching_to_farmroad_region.add_simple_state( "switching to farmroad phase 2", nullptr, l_switching_to_farmroad_phase_2_entry );

	auto& l_switching_to_farmroad_finished = l_switching_to_farmroad_region.add_final_state( "switching to farmroad finished" );

	auto l_farmroad_open_entry = [ this ] ( const sxy::i_event& p_event ) {	farmroad_open_entry(); };
	auto l_farmroad_open_exit = [ this ] ( const sxy::i_event& p_event ) { farmroad_open_exit(); };
	auto& l_farmroad_open = l_main_region.add_simple_state( "farmroad open", nullptr, l_farmroad_open_entry, l_farmroad_open_exit );


	// switching farmroad to highway
	auto& l_switching_to_highway = l_main_region.add_composite_state( "switching farmroad to highway" );
	auto& l_switching_to_highway_region = l_switching_to_highway.add_region( "region switching to highway" );
	auto& l_initial_switching_to_highway = l_switching_to_highway_region.add_initial_pseudostate( "initial switching to highway" );

	auto l_switching_to_highway_phase_1_entry = [ this ] ( const sxy::i_event& p_event ) { switching_to_highway_phase_1(); };
	auto& l_switching_to_highway_phase_1 = l_switching_to_highway_region.add_simple_state( "switching to highway phase 1", nullptr, l_switching_to_highway_phase_1_entry );

	auto l_switching_to_highway_phase_2_entry = [ this ] ( const sxy::i_event& p_event ) { switching_to_highway_phase_2(); };
	auto& l_switching_to_highway_phase_2 = l_switching_to_highway_region.add_simple_state( "switching to highway phase 2", nullptr, l_switching_to_highway_phase_2_entry );

	auto& l_switching_to_highway_finished = l_switching_to_highway_region.add_final_state( "switching to highway finished" );


	// guards	 
	auto l_guard_detector_on = [ this ] ( const sxy::i_event& p_event ) { return( check_detector_is_on() ); };
	auto l_guard_detector_off = [ this ] ( const sxy::i_event& p_event ) { return ( check_detector_is_off() ); };


	// transitions
	// in main region
	m_intersection_state_machine.add_transition( "initial_transition", COMPLETION_EVENT, l_initial_pseudostate, l_highway_open );	
	m_intersection_state_machine.add_transition( "highway_open_to_switching_highway_to_farmroad_on_completion", COMPLETION_EVENT, l_highway_open, l_switching_to_farmroad );

	m_intersection_state_machine.add_transition( "switching_highway_to_farmrod_to_farmroad_open_on_completion", COMPLETION_EVENT, l_switching_to_farmroad, l_farmroad_open );
	
	auto l_canceling_timer_event_on_detector_off = [ this ] ( const sxy::i_event& p_event ) { cancel_timer_event_on_detector_off( p_event ); };
	m_intersection_state_machine.add_transition( "farmroad_open_to_switching_farmroad_to_highway_on_timeout_or_detector_off", g_events_exit_farmroad_open, l_farmroad_open, l_switching_to_highway, t_transition_kind::EXTERNAL, nullptr, l_canceling_timer_event_on_detector_off );

	m_intersection_state_machine.add_transition( "switching_farmroad_to_highway_to_highway_open_on_completion", COMPLETION_EVENT, l_switching_to_highway, l_highway_open );


	// inside highway open
	m_intersection_state_machine.add_transition( "initial_transition_highway_open", COMPLETION_EVENT, l_initial_highway, l_initialize_dummy );
	m_intersection_state_machine.add_transition( "initializeing_dummy_to_junction_on_completion", COMPLETION_EVENT, l_initialize_dummy, l_detector_junction );

	m_intersection_state_machine.add_transition( "junction_to_waiting_minimumtime_to_pass_on_detector_on", COMPLETION_EVENT, l_detector_junction, l_minimum_time_not_elapsed_farmroad_waiting, t_transition_kind::EXTERNAL, l_guard_detector_on );
	m_intersection_state_machine.add_transition( "junction_to_waiting_for_detector_on_on_detector_off", COMPLETION_EVENT, l_detector_junction, l_minimum_time_not_elapsed, t_transition_kind::EXTERNAL, l_guard_detector_off );

	m_intersection_state_machine.add_transition( "waiting_minimum_time_to_pass_with_detector_off_to_waiting_minimum_time_to_pass_with_detector_on_on_detector_on", g_detector_on, l_minimum_time_not_elapsed, l_minimum_time_not_elapsed_farmroad_waiting );
	m_intersection_state_machine.add_transition( "waiting_minimum_time_to_pass_with_detector_off_to_waiting_for_detector_on_on_waiting_minimum_time_elapsed", g_timer_highway_minimum_time, l_minimum_time_not_elapsed, l_minimum_time_elapsed );
	
	m_intersection_state_machine.add_transition( "waiting_minimum_time_to_pass_with_detector_on_to_finished_highway_open_on_minimum_time_elapsed", g_timer_highway_minimum_time, l_minimum_time_not_elapsed_farmroad_waiting, l_highway_finished );
	
	m_intersection_state_machine.add_transition( "minimum_time_elapsed_waithing_detector_on_to_finished_highway_open_on_detector_on", g_detector_on, l_minimum_time_elapsed, l_highway_finished );
	

	// inside switching highway to farmroad
	m_intersection_state_machine.add_transition( "initial_transition_switching_highway_to_farmroad_on_completion", COMPLETION_EVENT, l_initial_switching_to_farmroad, l_switching_to_farmroad_phase_1 );
	m_intersection_state_machine.add_transition( "switching_highway_to_yellow_farmroad_to_red_yellow_to_switching_highway_to_red_on_timeout", g_timer_phase_1, l_switching_to_farmroad_phase_1, l_switching_to_farmroad_phase_2 );
	m_intersection_state_machine.add_transition( "switching_highway_to_red_to_final_state_on_timeout", g_timer_phase_2, l_switching_to_farmroad_phase_2, l_switching_to_farmroad_finished );
																																																																			
	// inside switching farmroad to highway
	m_intersection_state_machine.add_transition( "initial_transition_switching_farmroad_to_highway_on_completion", COMPLETION_EVENT, l_initial_switching_to_highway, l_switching_to_highway_phase_1 );
	m_intersection_state_machine.add_transition( "switching_highway_to_red_yellow_farmroad_to_yellow_to_switching_farmroad_to_red_on_timeout", g_timer_phase_1, l_switching_to_highway_phase_1, l_switching_to_highway_phase_2 );
	m_intersection_state_machine.add_transition( "switching_farmroad_to_red_to_final_state_on_timeout", g_timer_phase_2, l_switching_to_highway_phase_2, l_switching_to_highway_finished );
}


}
