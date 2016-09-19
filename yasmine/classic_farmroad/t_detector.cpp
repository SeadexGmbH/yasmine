//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_detector.h"

#include <thread>
#include <random>

#include "base.h"
#include "i_detector_callback.h"


namespace
{


constexpr unsigned int g_detector_off_lower_extremity( 1500 );
constexpr unsigned int g_detector_off_upper_extremity( 12000 );
constexpr unsigned int g_detector_on_lower_extremity( 1500 );
constexpr unsigned int g_detector_on_upper_extremity( 3000 );


}


namespace sxy
{


t_detector::t_detector( i_detector_callback& p_detector_callback )
	: m_detector_callback( p_detector_callback ),
		m_is_on( false ),
		m_generate_random_detector_events(),
		m_run( false ),
		m_mutex(),
		m_condition_variable()
{
	// Nothing to do...
}


t_detector::~t_detector() = default;


void t_detector::start()
{
	m_run = true;
	m_generate_random_detector_events =
		std::make_unique< std::thread >( [ this ] () { this->generate_detector_events(); } );
}


void t_detector::stop()
{
	{
		std::unique_lock< std::mutex > l_lock( m_mutex );
		m_run = false;
	}
	m_condition_variable.notify_all();
	Y_ASSERT( m_generate_random_detector_events->joinable(), "Event generator thread is not joinable!" );
	m_generate_random_detector_events->join();
	m_generate_random_detector_events.reset();
}


bool t_detector::is_on()
{
	std::unique_lock< std::mutex > l_lock( m_mutex );
	return( m_is_on );
}


void t_detector::generate_detector_events()
{
	std::unique_lock< std::mutex > l_lock( m_mutex );
	while( m_run )
	{
		std::random_device r;
		std::default_random_engine e( r() );
		m_is_on = false;
		{
			std::uniform_int_distribution< int > uniform_dist( g_detector_off_lower_extremity, 
				g_detector_off_upper_extremity );
			auto time_to_wait = std::chrono::milliseconds( uniform_dist( e ) );
			m_condition_variable.wait_for( l_lock, time_to_wait );
			m_detector_callback.detector_off();
		}
		if( m_run )
		{
			m_is_on = true;
			{
				std::uniform_int_distribution< int > uniform_dist( g_detector_on_lower_extremity,
					g_detector_on_upper_extremity );
				auto time_to_wait = std::chrono::milliseconds( uniform_dist( e ) );
				m_condition_variable.wait_for( l_lock, time_to_wait );
				m_detector_callback.detector_on();
			}
		}
	}
}


}
