//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>

#include "recipe.hpp"
#include "genesis_exception.hpp"
#include "recipe_callback_impl.hpp"


int main()
{
	int error = 0;

	try
	{	
		examples::config configuration;
		examples::recipe_callback_impl recipe_callback( configuration );
		std::cout << "Generating source file from the template '" << configuration.source_template_file_ << "'..." << std::endl;
		sx::genesis::recipe source_recipe( configuration.source_template_file_, recipe_callback, configuration.template_path_ );
		source_recipe.generate();
		source_recipe.write_to_file( configuration.output_file_ );
		std::cout << "Finished. Output file '" << configuration.output_file_ << "'." << std::endl;
	}
	catch( const sx::genesis::genesis_exception& exception )
	{
		error = 1;
		// DONE add "Unhandled std::exception: "
		std::cout << "Unhandled std::exception: " << exception.what() << std::endl;
	}
	catch( const std::exception& exception )
	{
		error = 2;
		// DONE add "Unhandled unknown exception: "
		std::cout << "Unhandled unknown exception: " << exception.what() << std::endl;
	}
	catch( ... )
	{
		error = 3;
		std::cout << "Unknown error!" << std::endl;
	}

	return ( error );
}
