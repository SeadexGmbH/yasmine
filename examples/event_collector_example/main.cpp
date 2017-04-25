//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "machine.hpp"
#include "yasmine.hpp"


int main()
{
	int error_code = 0;

	hermes::log_manager_template<hermes::std_timestamp_policy>& log_manager = hermes::log_manager::get_instance();
	log_manager.set_log_level( hermes::log_level::LL_ERROR );
	log_manager.add_logger( SX_MAKE_UNIQUE< hermes::cout_logger >() );
	log_manager.run();
	sxy::version::log_version();

	examples::machine machine_example;

	log_manager.halt_and_join();

	return( error_code );
}
