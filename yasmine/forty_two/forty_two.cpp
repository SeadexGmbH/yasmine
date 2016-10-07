//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "forty_two.hpp"

#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <thread>


Y_EVENT_WITH_ID( event_A, 1 );
Y_EVENT_WITH_ID( event_B, 2 );
Y_EVENT_WITH_ID( event_C, 3 );
Y_EVENT_WITH_ID( event_D, 4 );
Y_EVENT_WITH_ID( event_E, 5 );
Y_EVENT_WITH_ID( event_F, 6 );
Y_EVENT_WITH_ID( event_G, 7 );
Y_EVENT_WITH_ID( event_H, 8 );
Y_EVENT_WITH_ID( event_I, 9 );
Y_EVENT_WITH_ID( event_J, 10 );
Y_EVENT_WITH_ID( event_K, 11 );
Y_EVENT_WITH_ID( event_L, 12 );
Y_EVENT_WITH_ID( event_M, 13 );
Y_EVENT_WITH_ID( event_N, 14 );
Y_EVENT_WITH_ID( event_O, 15 );
Y_EVENT_WITH_ID( event_P, 16 );
Y_EVENT_WITH_ID( event_Q, 17 );
Y_EVENT_WITH_ID( event_R, 18 );
Y_EVENT_WITH_ID( event_S, 19 );
Y_EVENT_WITH_ID( event_T, 20 );
					

namespace sxy
{


forty_two::forty_two( const uint32_t _max_iterations )
	: state_machine_( std::move( build_state_machine() ) ),
		iterations_(0),
		max_iterations_( _max_iterations )
{
	Y_ASSERT( check_state_machine(), "State machine has defects!" );
	run();
}
										 

forty_two::state_machine_uptr forty_two::build_state_machine()
{
	auto l_state_machine = std::make_unique<state_machine>( "forty two state machine" );
	auto& root_state = l_state_machine->get_root_state();
	auto& main_region = root_state.add_region( "main region" );
	auto& i1 = main_region.add_initial_pseudostate( "initial pseudostate 1" );

	auto& s1 = main_region.add_simple_state( "s1", Y_BEHAVIOR_METHOD_NO_EVENT( increment_iterations ) );
	auto& s2 = main_region.add_simple_state( "s2" );
	auto& s3 = main_region.add_composite_state( "s3" );
	auto& r3_1 = s3.add_region( "s3_r1" );
	auto& r3_2 = s3.add_region( "s3_r2" );
	auto& r3_3 = s3.add_region( "s3_r3" );
		
	auto& i2 = r3_1.add_initial_pseudostate( "initial pseudostate 2" );
	auto& s3_1_1 = r3_1.add_simple_state( "s3_r1_s1" );
	auto& final1 = r3_1.add_final_state( "final state 1" );

	auto& i3 = r3_2.add_initial_pseudostate( "initial pseudostate 3" );
	auto& s3_2_1 = r3_2.add_composite_state( "s3_r2_s1" );
	auto& r3_2_1_1 = s3_2_1.add_region( "s3_r2_s1_r1" );
	auto& i4 = r3_2_1_1.add_initial_pseudostate( "initial pseudostate 4" );
	auto& s3_2_1_1_1 = r3_2_1_1.add_composite_state( "s3_r2_s1_r1_s1" );
	auto& r3_2_1_1_1_1 = s3_2_1_1_1.add_region( "s3_r2_s1_r1_s1_r1" );
	auto& i5 = r3_2_1_1_1_1.add_initial_pseudostate( "initial pseudostate 5" );
	auto& s3_2_1_1_1_1_1 = r3_2_1_1_1_1.add_simple_state( "s3_r2_s1_r1_s1_r1_s1" );	
	auto& final2 = r3_2.add_final_state( "final state 2" );	
	
	auto& i6 = r3_3.add_initial_pseudostate( "initial pseudostate 6" );
	auto& s3_3_1 = r3_3.add_simple_state( "s3_r3_s1" );
	auto& final3 = r3_3.add_final_state( "final state 3" );

	auto& s4 = main_region.add_simple_state( "s4" );

	auto& s5 = main_region.add_composite_state( "s5" );	
	auto& r5_1 = s5.add_region( "s5_r1" );
	auto& s5_1_1 = r5_1.add_composite_state( "s5_r1_s1" );
	auto& r5_1_1_1 = s5_1_1.add_region( "s5_r1_s1_r1" );
	auto& s5_1_1_1_1 = r5_1_1_1.add_composite_state( "s5_r1_s1_r1_s1" );
	auto& r5_1_1_1_1_1 = s5_1_1_1_1.add_region( "s5_r1_s1_r1_s1_r1" );
	auto& s5_1_1_1_1_1_1 = r5_1_1_1_1_1.add_simple_state( "s5_r1_s1_r1_s1_r1_s1" );
	auto& s5_1_1_1_1_1_2 = r5_1_1_1_1_1.add_simple_state( "s5_r1_s1_r1_s1_r1_s2" );
	
	auto& exit1 = s5_1_1_1_1.add_exit_point( "exit1" );
	auto& exit2 = s5.add_exit_point( "exit2" );
	
	auto& s6 = main_region.add_simple_state( "s6" );

	auto& s7 = main_region.add_composite_state( "s7" );
	auto& r7_1 = s7.add_region( "s7_r1" );
	auto& s7_1_1 = r7_1.add_composite_state( "s7_r1_s1" );
	auto& r7_1_1_1 = s7_1_1.add_region( "s7_r1_s1_r1" );
	auto& s7_1_1_1_1 = r7_1_1_1.add_composite_state( "s7_r1_s1_r1_s1" );
	auto& r7_1_1_1_1_1 = s7_1_1_1_1.add_region( "s7_r1_s1_r1_s1_r1" );
	auto& s7_1_1_1_1_1_1 = r7_1_1_1_1_1.add_composite_state( "s7_r1_s1_r1_s1_r1_s1" );
	auto& r7_1_1_1_1_1_1_1 = s7_1_1_1_1_1_1.add_region( "s7_r1_s1_r1_s1_r1_s1_r1" );
	auto& s7_1_1_1_1_1_1_1_1 = r7_1_1_1_1_1_1_1.add_simple_state( "s7_r1_s1_r1_s1_r1_s1_r1_s1" );

	auto& entry1 = s7_1_1_1_1.add_entry_point( "entry1" );
	auto& entry2 = s7.add_entry_point( "entry2" );
	
	auto& s8 = main_region.add_simple_state( "s8" );
	auto& s9 = main_region.add_simple_state( "s9" );

	auto& s10 = main_region.add_composite_state( "s10" );
	auto& r10_1 = s10.add_region( "s10_r1" );
	auto& i7 = r10_1.add_initial_pseudostate( "initial pseudostate 7" );
	auto& s10_1_1 = r10_1.add_composite_state( "s10_r1_s1" );
	auto& r10_1_1_1 = s10_1_1.add_region( "s10_r1_s1_r1" );
	auto& i8 = r10_1_1_1.add_initial_pseudostate( "initial pseudostate 8" );
	auto& s10_1_1_1_1 = r10_1_1_1.add_simple_state( "s10_r1_s1_r1_s1" );
	auto& s10_1_1_1_2 = r10_1_1_1.add_composite_state( "s10_r1_s1_r1_s2" );
	auto& r10_1_1_1_2_1 = s10_1_1_1_2.add_region( "s10_r1_s1_r1_s2_r1" );
	auto& i9 = r10_1_1_1_2_1.add_initial_pseudostate( "initial pseudostate 9" );
	auto& s10_1_1_1_2_1_1 = r10_1_1_1_2_1.add_simple_state( "r10_r1_s1_r1_s2_r1_s1" );	
	auto& s10_1_2 = r10_1.add_simple_state( "s10_r1_s2" );
	auto& s10_1_3 = r10_1.add_simple_state( "s10_r1_s3" );
	auto& shallow_history1 = s10.add_shallow_history( "shallow history 1" );

	auto& s11 = main_region.add_simple_state( "s11" );
	auto& s12 = main_region.add_simple_state( "s12" );

	auto& s13 = main_region.add_composite_state( "s13" );
	auto& r13_1 = s13.add_region( "s13_r1" );
	auto& i10 = r13_1.add_initial_pseudostate( "initial pseudostate 10" );
	auto& s13_1_1 = r13_1.add_composite_state( "s13_r1_s1" );
	auto& r13_1_1_1 = s13_1_1.add_region( "s13_r1_s1_r1" );
	auto& i11 = r13_1_1_1.add_initial_pseudostate( "initial pseudostate 11" );
	auto& s13_1_1_1_1 = r13_1_1_1.add_simple_state( "s13_r1_s1_r1_s1" );
	auto& s13_1_1_1_2 = r13_1_1_1.add_composite_state( "s13_r1_s1_r1_s2" );
	auto& r13_1_1_1_2_1 = s13_1_1_1_2.add_region( "s13_r1_s1_r1_s2_r1" );
	auto& i12 = r13_1_1_1_2_1.add_initial_pseudostate( "initial pseudostate 12" );
	auto& s13_1_1_1_2_1_1 = r13_1_1_1_2_1.add_simple_state( "r13_r1_s1_r1_s2_r1_s1" );
	auto& s13_1_2 = r13_1.add_simple_state( "s13_r1_s2" );
	auto& s13_1_3 = r13_1.add_simple_state( "s13_r1_s3" );
	auto& deep_history1 = s13.add_shallow_history( "deep history 1" );

	auto& s14 = main_region.add_simple_state( "s14" );
	auto& s15 = main_region.add_simple_state( "s15" );

	auto& fork1 = main_region.add_fork( "fork 1" );

	auto& s16 = main_region.add_composite_state( "s16" );
	auto& r16_1 = s16.add_region( "s16_r1" );
	auto& r16_2 = s16.add_region( "s16_r2" );
	auto& r16_3 = s16.add_region( "s16_r3" );
	auto& r16_4 = s16.add_region( "s16_r4" );
	auto& i13 = r16_1.add_initial_pseudostate( "initial pseudostate 13" );
	auto& s16_1_1 = r16_1.add_simple_state( "s16_r1_s1" );
	auto& s16_1_2 = r16_1.add_simple_state( "s16_r1_s2" );
	auto& s16_1_3 = r16_1.add_simple_state( "s16_r1_s3" );
	auto& s16_2_1 = r16_2.add_simple_state( "s16_r2_s1" );
	auto& s16_2_2 = r16_2.add_simple_state( "s16_r2_s2" );
	auto& s16_2_3 = r16_2.add_simple_state( "s16_r2_s3" );
	auto& s16_3_1 = r16_3.add_simple_state( "s16_r3_s1" );
	auto& s16_3_2 = r16_3.add_simple_state( "s16_r3_s2" );
	auto& s16_4_1 = r16_4.add_simple_state( "s16_r4_s1" );
	auto& s16_4_2 = r16_4.add_simple_state( "s16_r4_s2" );
	auto& s16_4_3 = r16_4.add_simple_state( "s16_r4_s3" );

	auto& s17 = main_region.add_simple_state( "s17" );

	auto& join1 = main_region.add_join( "join 1" );

	auto& s18 = main_region.add_simple_state( "s18" );

	auto& choice1 = main_region.add_choice( "choice 1" );

	auto& s19 = main_region.add_simple_state( "s19" );

	auto& junction1 = main_region.add_junction( "junction 1" );

	auto& s20 = main_region.add_simple_state( "s20" );
	auto& s21 = main_region.add_simple_state( "s21" );
	auto& s22 = main_region.add_simple_state( "s22" );
		
	sxy::event_ids deferred_events_ids = { event_S::get_event_id() };
	auto& s23 = main_region.add_simple_state( "s23", deferred_events_ids );

	auto& s24 = main_region.add_simple_state( "s24" );

	auto& junction2 = main_region.add_junction( "junction 2" );
	auto& terminate_pseudostate_1 = main_region.add_terminate_pseudostate( "terminate pseudostate 1" );

	l_state_machine->add_transition( COMPLETION_EVENT, i1, s1 );
	l_state_machine->add_transition( event_B::get_event_id(), s1, s2 );
	l_state_machine->add_transition( event_A::get_event_id(), s1, s3 );
	
	l_state_machine->add_transition( event_C::get_event_id(), s3, s2 );
	l_state_machine->add_transition( COMPLETION_EVENT, i2, s3_1_1 );
	l_state_machine->add_transition( COMPLETION_EVENT, s3_1_1, final1 );
	l_state_machine->add_transition( COMPLETION_EVENT, i3, s3_2_1 );
	l_state_machine->add_transition( COMPLETION_EVENT, i4, s3_2_1_1_1 );
	l_state_machine->add_transition( COMPLETION_EVENT, i5, s3_2_1_1_1_1_1 );
	l_state_machine->add_transition( event_D::get_event_id(), s3_2_1_1_1_1_1, final2 );
	l_state_machine->add_transition( COMPLETION_EVENT, i6, s3_3_1 );
	l_state_machine->add_transition( event_C::get_event_id(), s3_3_1, final3 );

	l_state_machine->add_transition( event_A::get_event_id(), s3, s4 );

	l_state_machine->add_transition( COMPLETION_EVENT, s3, s5_1_1_1_1_1_1 );
	l_state_machine->add_transition( event_A::get_event_id(), s5_1_1_1_1_1_1, s5_1_1_1_1_1_2 );
	l_state_machine->add_transition( event_E::get_event_id(), s5_1_1_1_1_1_1, exit1 );
	l_state_machine->add_transition( COMPLETION_EVENT, exit1, exit2 );
	l_state_machine->add_transition( event_E::get_event_id(), s5, s6 );
	l_state_machine->add_transition( COMPLETION_EVENT, exit2, entry2 );
	l_state_machine->add_transition( COMPLETION_EVENT, entry2, entry1 );
	l_state_machine->add_transition( COMPLETION_EVENT, entry1, s7_1_1_1_1_1_1_1_1 );

	l_state_machine->add_transition( event_F::get_event_id(), s7, s8 );
	l_state_machine->add_transition( event_A::get_event_id(), s7, s9 );

	l_state_machine->add_transition( event_F::get_event_id(), s7_1_1_1_1_1_1_1_1, s10 );

	l_state_machine->add_transition( COMPLETION_EVENT, i7, s10_1_2 );
	l_state_machine->add_transition( event_A::get_event_id(), s10_1_2, s10_1_3 );
	l_state_machine->add_transition( event_G::get_event_id(), s10_1_2, s10_1_1 );
	l_state_machine->add_transition( event_A::get_event_id(), s10_1_1, s10_1_3 );

	l_state_machine->add_transition( COMPLETION_EVENT, i8, s10_1_1_1_1 );
	l_state_machine->add_transition( event_H::get_event_id(), s10_1_1_1_1, s10_1_1_1_2 );
	l_state_machine->add_transition( COMPLETION_EVENT, i9, s10_1_1_1_2_1_1 );

	l_state_machine->add_transition( event_I::get_event_id(), s10_1_1, s11 );
	l_state_machine->add_transition( event_A::get_event_id(), s11, s12 );
	l_state_machine->add_transition( COMPLETION_EVENT, s11, shallow_history1 );

	l_state_machine->add_transition( event_K::get_event_id(), s10, s13 );

	l_state_machine->add_transition( COMPLETION_EVENT, i10, s13_1_2 );
	l_state_machine->add_transition( event_A::get_event_id(), s13_1_2, s13_1_3 );
	l_state_machine->add_transition( COMPLETION_EVENT, s13_1_2, s13_1_1 );
	l_state_machine->add_transition( event_A::get_event_id(), s13_1_1, s13_1_3 );

	l_state_machine->add_transition( COMPLETION_EVENT, i11, s13_1_1_1_1 );
	l_state_machine->add_transition( event_L::get_event_id(), s13_1_1_1_1, s13_1_1_1_2 );
	l_state_machine->add_transition( COMPLETION_EVENT, i12, s13_1_1_1_2_1_1 );

	l_state_machine->add_transition( event_M::get_event_id(), s13_1_1, s14 );
	l_state_machine->add_transition( event_A::get_event_id(), s14, s15 );
	l_state_machine->add_transition( event_N::get_event_id(), s14, deep_history1 );

	l_state_machine->add_transition( event_O::get_event_id(), s13, fork1 );

	l_state_machine->add_transition( COMPLETION_EVENT, fork1, s16_2_1 );
	l_state_machine->add_transition( COMPLETION_EVENT, fork1, s16_3_1 );
	l_state_machine->add_transition( COMPLETION_EVENT, fork1, s16_4_1 );

	l_state_machine->add_transition( COMPLETION_EVENT, i13, s16_1_1 );
	l_state_machine->add_transition( event_A::get_event_id(), s16_1_1, s16_1_2 );
	l_state_machine->add_transition( event_Q::get_event_id(), s16_1_1, s16_1_3 );

	l_state_machine->add_transition( event_A::get_event_id(), s16_2_1, s16_2_2 );
	l_state_machine->add_transition( event_Q::get_event_id(), s16_2_1, s16_2_3 );

	l_state_machine->add_transition( event_Q::get_event_id(), s16_3_1, s16_3_2 );

	l_state_machine->add_transition( event_A::get_event_id(), s16_4_1, s16_4_2 );
	l_state_machine->add_transition( event_Q::get_event_id(), s16_4_1, s16_4_3 );

	l_state_machine->add_transition( COMPLETION_EVENT, s16_1_3, join1 );
	l_state_machine->add_transition( COMPLETION_EVENT, s16_2_3, join1 );
	l_state_machine->add_transition( COMPLETION_EVENT, s16_3_2, join1 );
	l_state_machine->add_transition( COMPLETION_EVENT, s16_4_3, join1 );

	l_state_machine->add_transition( event_B::get_event_id(), s16, s17 );

	l_state_machine->add_transition( COMPLETION_EVENT, join1, s18 );

	l_state_machine->add_transition( event_R::get_event_id(), s18, choice1 );

	l_state_machine->add_transition( COMPLETION_EVENT, choice1, s19, Y_GUARD_METHOD_NO_EVENT( check_iterations_divided_by_2 ) );
	l_state_machine->add_transition( COMPLETION_EVENT, choice1, junction1 );

	l_state_machine->add_transition( COMPLETION_EVENT, junction1, s20, Y_GUARD_METHOD_NO_EVENT( check_iterations_divided_by_3 ) );
	l_state_machine->add_transition( COMPLETION_EVENT, junction1, s21, Y_GUARD_METHOD_NO_EVENT( check_iterations_divided_by_5 ) );
	l_state_machine->add_transition( COMPLETION_EVENT, junction1, s22 );

	l_state_machine->add_transition( COMPLETION_EVENT, s19, s23 );
	l_state_machine->add_transition( COMPLETION_EVENT, s20, s23 );
	l_state_machine->add_transition( COMPLETION_EVENT, s21, s23 );
	l_state_machine->add_transition( COMPLETION_EVENT, s22, s23 );

	l_state_machine->add_transition( event_T::get_event_id(), s23, s24 );
	l_state_machine->add_transition( event_S::get_event_id(), s24, junction2 );

	l_state_machine->add_transition( COMPLETION_EVENT, junction2, terminate_pseudostate_1, Y_GUARD_METHOD_NO_EVENT( check_iterations_exceded ) );
	l_state_machine->add_transition( COMPLETION_EVENT, junction2, s1 );

	return( std::move( l_state_machine ) );
}


bool forty_two::check_state_machine() const
{
	auto state_machine_is_ok = true;
	sxy::state_machine_defects defects;
	state_machine_->check( defects );
	if( !defects.empty() )
	{
		state_machine_is_ok = false;
	}

	return( state_machine_is_ok );
}


void forty_two::increment_iterations()
{
	++iterations_;
	Y_LOG( log_level::LL_DEBUG, "iterator incremented to %", iterations_ );
}


bool forty_two::check_iterations_divided_by_2() const
{
	return ( iterations_ % 2 == 0 );
}


bool forty_two::check_iterations_divided_by_3()	const
{
	return ( iterations_ % 3 == 0);
}


bool forty_two::check_iterations_divided_by_5()	const
{
	return ( iterations_ % 5 == 0);
}


bool forty_two::check_iterations_exceded() const
{
	return ( iterations_ > max_iterations_ );
}


void forty_two::run()
{		
#ifndef Y_NO_LOGGING
	auto& log_manager = sxy::log_manager::get_instance();
	log_manager.set_log_level( sxy::log_level::LL_DEBUG );
	log_manager.add_logger( std::make_unique< sxy::cout_logger >() );	
	log_manager.start();
#endif

	const auto start = std::chrono::steady_clock::now();	

	auto starting_success = state_machine_->start_state_machine();	
	Y_ASSERT( starting_success, "State machine was not started!" );

	for( uint32_t iteration = 0; iteration < max_iterations_; ++iteration )
	{	 
		state_machine_->fire_event( event_A::create() );
		state_machine_->fire_event( event_B::create() );
		state_machine_->fire_event( event_C::create() );
		state_machine_->fire_event( event_D::create() );
		state_machine_->fire_event( event_E::create() );
		state_machine_->fire_event( event_F::create() );
		state_machine_->fire_event( event_G::create() );
		state_machine_->fire_event( event_H::create() );
		state_machine_->fire_event( event_I::create() );
		state_machine_->fire_event( event_J::create() );
		state_machine_->fire_event( event_K::create() );
		state_machine_->fire_event( event_L::create() );
		state_machine_->fire_event( event_M::create() );
		state_machine_->fire_event( event_N::create() );
		state_machine_->fire_event( event_O::create() );
		state_machine_->fire_event( event_P::create() );
		state_machine_->fire_event( event_Q::create() );
		state_machine_->fire_event( event_R::create() );
		state_machine_->fire_event( event_S::create() );
		state_machine_->fire_event( event_T::create() );
	}

	const auto stop = std::chrono::steady_clock::now();

	std::cout << "Run time(sec): " << std::chrono::duration_cast< std::chrono::seconds >( stop - start ).count();

#ifdef Y_PROFILER		
	Y_LOG( log_level::LL_INFO, "% events were fired.", std::to_string( state_machine_->get_number_of_processed_events() ) );
#endif
	
	state_machine_->stop_state_machine();

	Y_LOG( log_level::LL_INFO, "Run time: % seconds", std::chrono::duration_cast< std::chrono::seconds >( stop - start ).count() );

#ifndef Y_NO_LOGGING
	log_manager.stop();
	log_manager.join();
#endif
	
	std::cin.get();
}	 


}
