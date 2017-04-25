//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "random_generator.hpp"


#ifdef SX_CPP03_BOOST
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#endif


namespace examples
{


random_generator::random_generator()
	: random_device_()
{
	// Nothing to do...
}
	
	
random_generator::~random_generator()
{
	// Nothing to do...
}


const unsigned int random_generator::generate( const unsigned int _lower_extremity, const unsigned int _upper_extremity )
{
	unsigned int number = 0;

#ifndef SX_CPP03_BOOST
	std::default_random_engine engine( random_device_() );
	std::uniform_int_distribution< int > uniform_distribution( _lower_extremity, _upper_extremity );
	number = uniform_distribution( engine );
#else
	boost::random::mt19937 engine( random_device_() );
	boost::random::uniform_int_distribution<> uniform_distribution( _lower_extremity, _upper_extremity );
	number = uniform_distribution( engine );
#endif

	return( number );
}


}
