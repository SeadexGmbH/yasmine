//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "detector.hpp"

#include "essentials/base.hpp"
#include "essentials/compatibility/chrono.hpp"

#include "detector_callback.hpp"
#include "random_generator.hpp"


namespace
{


	const unsigned int DETECTOR_OFF_LOWER_EXTREMITY(1);
	const unsigned int DETECTOR_OFF_UPPER_EXTREMITY(12);
	const unsigned int DETECTOR_ON_UPPER_EXTREMITY(3);
	const unsigned int DETECTOR_ON_LOWER_EXTREMITY(1);


}


namespace examples
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
		SX_MAKE_UNIQUE< sxe::thread >( sxe::bind( &detector::generate_detector_events, this ) );
}


void detector::stop()
{
	{
		sxe::unique_lock< sxe::mutex > lock( mutex_ );
		run_ = false;
	}
	condition_variable_.notify_all();
	SX_ASSERT( generate_random_detector_events_->joinable(), "Event generator thread is not joinable!" );
	generate_random_detector_events_->join();
	generate_random_detector_events_.reset();
}


bool detector::is_on()
{
	sxe::unique_lock< sxe::mutex > lock( mutex_ );
	return( is_on_ );
}


void detector::generate_detector_events()
{
	sxe::unique_lock< sxe::mutex > lock( mutex_ );
	while( run_ )
	{
		random_generator generator;
		is_on_ = false;
		{
			sxe::milliseconds time_to_wait =
				sxe::milliseconds( generator.generate( DETECTOR_OFF_LOWER_EXTREMITY, DETECTOR_OFF_UPPER_EXTREMITY ) );
			condition_variable_.wait_for( lock, time_to_wait );
			detector_callback_.detector_off();
		}
		if( run_ )
		{
			is_on_ = true;
			{
				sxe::milliseconds time_to_wait =
					sxe::milliseconds( generator.generate( DETECTOR_ON_LOWER_EXTREMITY, DETECTOR_ON_UPPER_EXTREMITY ) );
				condition_variable_.wait_for( lock, time_to_wait );

				detector_callback_.detector_on();
			}
		}
	}
}


}
