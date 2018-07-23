//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "generator.hpp"

#include <iostream>

#include "state_machine_model.hpp"

#include "config.hpp"
#include "json_reader.hpp"
#include "recipe_callback_impl.hpp"
#include "recipe.hpp"


namespace sxy
{


void generate( const sxy::config& _config )
{
	sxy::json_reader json_reader_( _config.model_file );
	sxy::model::state_machine_model_ptr mymodel = json_reader_.get_model_ptr();
	const std::string template_path = _config.template_path;

	sxy::recipe_callback_impl cb( *mymodel, _config.namespaces, _config.behavior_classes,
		_config.state_machine_name, sxy::get_state_machine_class_as_string( _config.sm_type ) );

	std::cout << "generating header file from the template '" << _config.header_template_file << "'..." << std::endl;
	sx::genesis::recipe header_recipe( _config.header_template_file, cb, template_path );
	header_recipe.generate();
	header_recipe.write_to_file( _config.header_output_file );
	std::cout << "Header file generated into file '" << _config.header_output_file << "'." << std::endl;

	std::cout << "generating source file from the template '" << _config.source_template_file << "'..." << std::endl;
	sx::genesis::recipe source_recipe( _config.source_template_file, cb, template_path );
	source_recipe.generate();
	source_recipe.write_to_file( _config.source_output_file );
	std::cout << "Source file generated into file '" << _config.source_output_file << "'." << std::endl;
}


}
