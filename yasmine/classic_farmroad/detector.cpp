//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "detector.hpp"

#include <thread>
#include <random>

#include "base.hpp"
#include "detector_callback.hpp"


namespace
{


constexpr unsigned int DETECTOR_OFF_LOWER_EXTREMITY( 1500 );
constexpr unsigned int DETECTOR_OFF_UPPER_EXTREMITY( 12000 );
constexpr unsigned int DETECTOR_ON_UPPER_EXTREMITY( 3000 );
constexpr unsigned int DETECTOR_ON_LOWER_RXTREMITY( 1500 );


}


namespace sxy
{


detector::detector( detector_callback& _detector_callback )
	: detector_callback_( _detector_callback ),
		is_on_( false ),
		generate_random_detector_events_(),
		run_( false ),
		mutex_(),
		condition_variable_()
{
	// Nothing to do...
}


detector::~detector() = default;


void detector::start()
{
	run_ = true;
	generate_random_detector_events_ =
		std::make_unique< std::thread >( [ this ] () { this->generate_detector_events(); } );
}


void detector::stop()
{
	{
		std::unique_lock< std::mutex > lock( mutex_ );
		run_ = false;
	}
	condition_variable_.notify_all();
	Y_ASSERT( generate_random_detector_events_->joinable(), "Event generator thread is not joinable!" );
	generate_random_detector_events_->join();
	generate_random_detector_events_.reset();
}


bool detector::is_on()
{
	std::unique_lock< std::mutex > lock( mutex_ );
	return( is_on_ );
}


void detector::generate_detector_events()
{
	std::unique_lock< std::mutex > lock( mutex_ );
	while( run_ )
	{
		std::random_device r;
		std::default_random_engine e( r() );
		is_on_ = false;
		{
			std::uniform_int_distribution< int > unifordist_( DETECTOR_OFF_LOWER_EXTREMITY, 
				DETECTOR_OFF_UPPER_EXTREMITY );
			auto time_to_wait = std::chrono::milliseconds( unifordist_( e ) );
			condition_variable_.wait_for( lock, time_to_wait );
			detector_callback_.detector_off();
		}
		if( run_ )
		{
			is_on_ = true;
			{
				std::uniform_int_distribution< int > unifordist_( DETECTOR_ON_UPPER_EXTREMITY,
					DETECTOR_ON_UPPER_EXTREMITY );
				auto time_to_wait = std::chrono::milliseconds( unifordist_( e ) );
				condition_variable_.wait_for( lock, time_to_wait );
				detector_callback_.detector_on();
			}
		}
	}
}


}
