//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "intersection.hpp"

#include <iostream>

#include "yasmine.hpp"


namespace sxy
{


namespace
{


const event_id DETECTOR_ON = 1;
constexpr event_id DETECTOR_OFF = 2;
constexpr event_id TIMER_HIGHWAY_MINIMUM_TIME = 3;
constexpr event_id TIMER_PHASE_1 = 4;
constexpr event_id TIMER_PHASE_2 = 5;
constexpr event_id TIMER_FARMROAD_MAXIMUM_TIME = 6;
constexpr event_id EVENT_FARMROAD_MAXIMUM_TIME_ELAPSED = 7;
const event_ids EVENTS_EXIT_FARMROAD_OPEN = { DETECTOR_OFF, EVENT_FARMROAD_MAXIMUM_TIME_ELAPSED };


const std::chrono::milliseconds TIMER_HIGHWAY_MINIMUM_TIME_DURATION( 5000 );
const std::chrono::milliseconds TIMER_PHASE_1_DURATION( 1000 );
const std::chrono::milliseconds TIMER_PHASE_2_DURATION( 1000 );
const std::chrono::milliseconds TIMER_FARMROAD_MAXIMUM_TIME_DURATION( 3000 );


const std::string FARMROAD_ASCII_ART = "--- ";
const std::string HIGHWAY_ASCII_ART = "==== ";

}


intersection::intersection()
	:	detector_callback(),	
		intersection_state_machine_( "intersection state machine" ),
		highway_traffic_light_("highway traffic light", HIGHWAY_ASCII_ART ),
		farmroad_traffic_light_("farmroad traffic light", FARMROAD_ASCII_ART ),
		timed_event_creator_( intersection_state_machine_ ),
		detector_( *this ),
		farmroad_maximum_time_event_handle_()
{		
	build_intersection_state_machine();
}


intersection::~intersection() = default;


bool intersection::start()
{
	auto started = false;
	state_machine_defects defects;
	intersection_state_machine_.check( defects );
	if( defects.empty() )
	{
		farmroad_traffic_light_.start();
		highway_traffic_light_.start();
		timed_event_creator_.start();
		intersection_state_machine_.start_state_machine();
		detector_.start();

		started = true;
	}
	else
	{
		std::cout << "The state machine is defect." << std::endl;

		write_defects_to_log( defects );
	}				 

	return( started );
}


void intersection::stop()
{
	detector_.stop();
	intersection_state_machine_.stop_state_machine();
	timed_event_creator_.stop();
	highway_traffic_light_.stop();
	farmroad_traffic_light_.stop();
}


void intersection::detector_on()
{
	std::cout << "Detector is on." << std::endl;		
	intersection_state_machine_.fire_event( event_impl::create( DETECTOR_ON ) );
}


void intersection::detector_off()
{	
	std::cout << "Detector is off." << std::endl;
	intersection_state_machine_.fire_event( event_impl::create( DETECTOR_OFF ) );
}


int intersection::fire_timed_event(	const std::chrono::milliseconds _milliseconds,	const event_id _event_id )
{	
	auto event_handle = timed_event_creator_.create_event_creation_request( 
		std::chrono::milliseconds( _milliseconds ), event_impl::create( _event_id ) );
	return( event_handle );
}
		

void intersection::highway_open_entry()
{
	Y_LOG( log_level::LL_INFO, "Highway open." );

	highway_traffic_light_.switch_to_green();

	fire_timed_event( TIMER_HIGHWAY_MINIMUM_TIME_DURATION, TIMER_HIGHWAY_MINIMUM_TIME );
}


void intersection::highway_open_exit()
{
	Y_LOG( log_level::LL_INFO, "Highway closed." );
}


void intersection::switching_to_farmroad_phase_1()
{
	Y_LOG( log_level::LL_INFO, "Switching highway to farmroad. Phase 1." );

	highway_traffic_light_.switch_to_yellow();
	farmroad_traffic_light_.switch_to_red_yellow();

	fire_timed_event( TIMER_PHASE_1_DURATION, TIMER_PHASE_1 );
}


void intersection::switching_to_farmroad_phase_2()
{
	Y_LOG( log_level::LL_INFO, "Switching highway to farmroad. Phase 2." );

	highway_traffic_light_.switch_to_red();

	fire_timed_event( TIMER_PHASE_2_DURATION, TIMER_PHASE_2 );
}


void intersection::farmroad_open_entry()
{
	Y_LOG( log_level::LL_INFO, "Farmroad open." );

	farmroad_traffic_light_.switch_to_green();

	farmroad_maximum_time_event_handle_ = fire_timed_event( TIMER_FARMROAD_MAXIMUM_TIME_DURATION, 
		TIMER_FARMROAD_MAXIMUM_TIME );
}


void intersection::farmroad_open_exit()
{
	Y_LOG( log_level::LL_INFO, "Farmroad closed." );
}


void intersection::minimum_time_not_elapsed()
{
	Y_LOG( log_level::LL_INFO, "Minimum time not elapsed." );
}
											

void intersection::minimum_time_elapsed()
{
	Y_LOG( log_level::LL_INFO, "Minimum time elapsed." );
}


void intersection::minimum_time_not_elapsed_farmroad_waiting()
{
	Y_LOG( log_level::LL_INFO, "Minimum time not elapsed. Farmroad waiting." );
}


void intersection::switching_to_highway_phase_1()
{
	Y_LOG( log_level::LL_INFO, "Switching farmroad to highway. Phase 1." );

	highway_traffic_light_.switch_to_red_yellow();
	farmroad_traffic_light_.switch_to_yellow();

	fire_timed_event( TIMER_PHASE_1_DURATION, TIMER_PHASE_1 );
}


void intersection::switching_to_highway_phase_2()
{
	Y_LOG( log_level::LL_INFO, "Switching farmroad to highway. Phase 2." );

	farmroad_traffic_light_.switch_to_red();

	fire_timed_event( TIMER_PHASE_2_DURATION, TIMER_PHASE_2 );
}


bool intersection::check_detector_is_on()
{																			 
	return( detector_.is_on() );
}


bool intersection::check_detector_is_off()
{
	return( !detector_.is_on() );
}


void intersection::cancel_timer_event_on_detector_off( const sxy::event& _event )
{
	if( _event.get_id() == DETECTOR_OFF )
	{
		if( farmroad_maximum_time_event_handle_ > 0 )
		{
			Y_LOG( log_level::LL_INFO, "Try to cancel event with handle %.", farmroad_maximum_time_event_handle_ );
			if( timed_event_creator_.cancel( farmroad_maximum_time_event_handle_ ) )
			{
				Y_LOG( log_level::LL_INFO, "Event with handle % was cancelled.", farmroad_maximum_time_event_handle_ );
			}
			else
			{
				Y_LOG( log_level::LL_INFO, "Event with handle % could not be canceled.", 
							 farmroad_maximum_time_event_handle_ );
			}
			farmroad_maximum_time_event_handle_ = 0;
		}
		else
		{
			Y_LOG( log_level::LL_INFO, "There is no event to be cancelled on detector off." );
		}
	}
}


void intersection::build_intersection_state_machine()
{
	auto& root = intersection_state_machine_.get_root_state();
	auto& main_region = root.add_region( "main_region" );

	auto& initial_pseudostate = main_region.add_initial_pseudostate( "initial" );

	// highway open
	auto& l_highway_open = main_region.add_composite_state( "highway open", 
		Y_BEHAVIOR_METHOD_NO_EVENT( highway_open_entry ), Y_BEHAVIOR_METHOD_NO_EVENT( highway_open_exit ) );

	auto& highway_open_region = l_highway_open.add_region( "highway region" );
	auto& initial_highway = highway_open_region.add_initial_pseudostate( "initial highway" );
	auto& initialize_dummy = highway_open_region.add_simple_state( "initialize dummy" );
	auto& detector_junction = highway_open_region.add_junction( "detector junction" );

	auto& l_minimum_time_not_elapsed = highway_open_region.add_simple_state( "minimum time not elapsed",
		Y_BEHAVIOR_METHOD_NO_EVENT( minimum_time_not_elapsed ) );

	auto& l_minimum_time_elapsed = highway_open_region.add_simple_state( "minimum time elapsed",
		Y_BEHAVIOR_METHOD_NO_EVENT( minimum_time_elapsed ) );

	auto& l_minimum_time_not_elapsed_farmroad_waiting = highway_open_region.add_simple_state(
		"Minimum time not elapsed and farmroad waiting",
		Y_BEHAVIOR_METHOD_NO_EVENT( minimum_time_not_elapsed_farmroad_waiting ) );

	auto& highway_finished = highway_open_region.add_final_state( "highway finished" );


	// switching highway to farmroad
	auto& switching_to_farmroad = main_region.add_composite_state( "switching highway to farmroad" );
	auto& switching_to_farmroad_region = switching_to_farmroad.add_region( "region switching to farmroad" );
	auto& initial_switching_to_farmroad = switching_to_farmroad_region.add_initial_pseudostate( 
		"initial switching highway to farmroad" );

	auto& l_switching_to_farmroad_phase_1 = switching_to_farmroad_region.add_simple_state(
		"switching to farmroad phase 1", Y_BEHAVIOR_METHOD_NO_EVENT( switching_to_farmroad_phase_1 ) );
																				 
	auto& switching_to_farmroad_phase_2 = switching_to_farmroad_region.add_simple_state(
		"switching to farmroad phase 2", nullptr, Y_BEHAVIOR_METHOD_NO_EVENT( switching_to_farmroad_phase_2 ) );

	auto& switching_to_farmroad_finished = switching_to_farmroad_region.add_final_state( 
		"switching to farmroad finished" );

	auto& farmroad_open = main_region.add_simple_state( "farmroad open", nullptr,
		Y_BEHAVIOR_METHOD_NO_EVENT( farmroad_open_entry ), Y_BEHAVIOR_METHOD_NO_EVENT( farmroad_open_exit ) );

	// switching farmroad to highway
	auto& switching_to_highway = main_region.add_composite_state( "switching farmroad to highway" );
	auto& switching_to_highway_region = switching_to_highway.add_region( "region switching to highway" );
	auto& initial_switching_to_highway = switching_to_highway_region.add_initial_pseudostate( 
		"initial switching to highway" );

	auto& l_switching_to_highway_phase_1 = switching_to_highway_region.add_simple_state(
		"switching to highway phase 1", nullptr, Y_BEHAVIOR_METHOD_NO_EVENT( switching_to_highway_phase_1 ) );
																							
	auto& l_switching_to_highway_phase_2 = switching_to_highway_region.add_simple_state(
		"switching to highway phase 2", nullptr, Y_BEHAVIOR_METHOD_NO_EVENT( switching_to_highway_phase_2 ) );

	auto& switching_to_highway_finished = switching_to_highway_region.add_final_state( 
		"switching to highway finished" );

	// transitions
	// in main region
	intersection_state_machine_.add_transition( COMPLETION_EVENT, initial_pseudostate, l_highway_open );	
	intersection_state_machine_.add_transition( COMPLETION_EVENT, l_highway_open, switching_to_farmroad );
	intersection_state_machine_.add_transition( COMPLETION_EVENT, switching_to_farmroad, farmroad_open );
	intersection_state_machine_.add_transition( EVENTS_EXIT_FARMROAD_OPEN, farmroad_open, switching_to_highway, 
		transition_kind::EXTERNAL, nullptr, Y_BEHAVIOR_METHOD( cancel_timer_event_on_detector_off ) );
	intersection_state_machine_.add_transition( COMPLETION_EVENT, switching_to_highway, l_highway_open );
																							
	// inside highway open
	intersection_state_machine_.add_transition( COMPLETION_EVENT, initial_highway, initialize_dummy );
	intersection_state_machine_.add_transition( COMPLETION_EVENT, initialize_dummy, detector_junction );
	intersection_state_machine_.add_transition( COMPLETION_EVENT, detector_junction, 
		l_minimum_time_not_elapsed_farmroad_waiting, transition_kind::EXTERNAL,	
		Y_GUARD_METHOD_NO_EVENT( check_detector_is_on ) );
	intersection_state_machine_.add_transition( COMPLETION_EVENT,	detector_junction, l_minimum_time_not_elapsed,
		transition_kind::EXTERNAL, Y_GUARD_METHOD_NO_EVENT( check_detector_is_off ) );
	intersection_state_machine_.add_transition( DETECTOR_ON, l_minimum_time_not_elapsed, 
		l_minimum_time_not_elapsed_farmroad_waiting );
	intersection_state_machine_.add_transition(	TIMER_HIGHWAY_MINIMUM_TIME, l_minimum_time_not_elapsed, 
		l_minimum_time_elapsed );	
	intersection_state_machine_.add_transition( TIMER_HIGHWAY_MINIMUM_TIME, l_minimum_time_not_elapsed_farmroad_waiting, 
		highway_finished );	
	intersection_state_machine_.add_transition( DETECTOR_ON, l_minimum_time_elapsed, highway_finished );	

	// inside switching highway to farmroad
	intersection_state_machine_.add_transition( COMPLETION_EVENT, initial_switching_to_farmroad, 
		l_switching_to_farmroad_phase_1 );
	intersection_state_machine_.add_transition( TIMER_PHASE_1, l_switching_to_farmroad_phase_1, 
		switching_to_farmroad_phase_2 );
	intersection_state_machine_.add_transition( TIMER_PHASE_2, switching_to_farmroad_phase_2, 
		switching_to_farmroad_finished );

	// inside switching farmroad to highway
	intersection_state_machine_.add_transition( COMPLETION_EVENT, initial_switching_to_highway, 
		l_switching_to_highway_phase_1 );
	intersection_state_machine_.add_transition( TIMER_PHASE_1, l_switching_to_highway_phase_1, 
		l_switching_to_highway_phase_2 );
	intersection_state_machine_.add_transition( TIMER_PHASE_2, l_switching_to_highway_phase_2, 
		switching_to_highway_finished );
}


}
