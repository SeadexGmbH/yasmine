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
#include "chrono.hpp"


namespace
{


	const unsigned int DETECTOR_OFF_LOWER_EXTREMITY(1);
	const unsigned int DETECTOR_OFF_UPPER_EXTREMITY(12);
	const unsigned int DETECTOR_ON_UPPER_EXTREMITY(3);
	const unsigned int DETECTOR_ON_LOWER_RXTREMITY(1);


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


detector::~detector()
{
	// Nothing to do...
}


void detector::start()
{
	run_ = true;
	generate_random_detector_events_ =
		Y_MAKE_UNIQUE< sxy::thread >( sxy::bind( &detector::generate_detector_events, this ) );
}


void detector::stop()
{
	{
		sxy::unique_lock< sxy::mutex > lock( mutex_ );
		run_ = false;
	}
	condition_variable_.notify_all();
	Y_ASSERT( generate_random_detector_events_->joinable(), "Event generator thread is not joinable!" );
	generate_random_detector_events_->join();
	generate_random_detector_events_.reset();
}


bool detector::is_on()
{
	sxy::unique_lock< sxy::mutex > lock( mutex_ );
	return( is_on_ );
}


void detector::generate_detector_events()
{
	sxy::unique_lock< sxy::mutex > lock( mutex_ );
	while( run_ )
	{
		std::random_device r;
		std::default_random_engine e( r() );
		is_on_ = false;
		{
			std::uniform_int_distribution< int > uniform_dist( DETECTOR_OFF_LOWER_EXTREMITY, 
				DETECTOR_OFF_UPPER_EXTREMITY );
			sxy::milliseconds time_to_wait = sxy::milliseconds( uniform_dist( e ) );
			condition_variable_.wait_for( lock, time_to_wait );
			detector_callback_.detector_off();
		}
		if( run_ )
		{
			is_on_ = true;
			{
				std::uniform_int_distribution< int > uniform_dist( DETECTOR_ON_UPPER_EXTREMITY,
					DETECTOR_ON_UPPER_EXTREMITY );
				sxy::milliseconds time_to_wait = sxy::milliseconds( uniform_dist( e ) );
				condition_variable_.wait_for( lock, time_to_wait );

				detector_callback_.detector_on();
			}
		}
	}
}


}
