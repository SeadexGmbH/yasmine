//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "config.hpp"

#include <iostream>


namespace sxy
{


config::config():
	template_path(),
	source_template_file(),
	header_template_file(),
	source_output_file(),
	header_output_file(),
	model_file(),
	state_machine_name(),
	sm_type(),
	namespaces(),
	behavior_classes()
{
	// Nothing to do...
}


config::~config() SX_NOEXCEPT
{
	// Nothing to do...
}


void config::print() const
{
	std::cout << "Template directory: " << template_path << std::endl;
	std::cout << "Source file template: " << source_template_file << std::endl;
	std::cout << "Source file output: " << source_output_file << std::endl;
	std::cout << "Header file template: " << header_template_file << std::endl;
	std::cout << "Header file output: " << header_output_file << std::endl;
	std::cout << "Model file: " << model_file << std::endl;
	std::cout << "State machine name: " << state_machine_name << std::endl;
	std::cout << "State machine type: " << sm_type_to_string( sm_type ) << std::endl;
	if( namespaces.empty() )
	{
		std::cout << "No namespace(s)." << std::endl;
	}
	else
	{
		std::cout << "Namespace(s):" << std::endl;
		SX_FOR( const std::string& one_namespace , namespaces )
		{
			std::cout << " " << one_namespace << std::endl;
		}
	}

	if( behavior_classes.empty() )
	{
		std::cout << "No behavior class(es)." << std::endl;
	}
	else
	{
		std::cout << "Behavior class(es):" << std::endl;
		SX_FOR( const std::string& behavior_class, behavior_classes )
		{
			std::cout << " " << behavior_class << std::endl;
		}
	}
}


}
