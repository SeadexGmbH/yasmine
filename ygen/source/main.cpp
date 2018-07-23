//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "boost/program_options.hpp"

#include "ygen_magic_consts.hpp"
#include "generator.hpp"
#include "genesis_exception.hpp"


bool parse_program_options( int argc, char** argv, boost::program_options::variables_map& _variables, sxy::config& _config )
{
	bool printHelp = false;
	using namespace boost::program_options;
	options_description description( DESCRIPTION_TITLE, DESCRIPTION_COLUMN_WIDTH );

	description.add_options()
		( "help,h" , HELP_OPTION_TEXT )
		( "template_dir,t", value<std::string>( &_config.template_path )->default_value( TEMPLATE_DIR_DEFAULT ), TEMPLATE_DIR_TEXT )
		( "source_template,s", value<std::string>( &_config.source_template_file )->default_value( SOURCE_TEMPLATE_FILE_DEFAULT ), SOURCE_TEMPLATE_FILE_TEXT )
		( "header_template,e", value<std::string>( &_config.header_template_file )->default_value( HEADER_TEMPLATE_FILE_DEFAULT ), HEADER_TEMPLATE_FILE_TEXT )
		( "out_file,o", value<std::string>( &_config.source_output_file ), SOURCE_OUT_FILE_TEXT )
		( "namespace,n", value< std::vector<std::string> >( &_config.namespaces ), NAMESPACES_TEXT )
		( "behavior_class,b", value< std::vector<std::string> >( &_config.behavior_classes ), BEHAVIOR_CLASSES_TEXT )
		( "model,m", value<std::string>( &_config.model_file ), MODEL_FILE_TEXT )
		( "state_machine_name,i", value<std::string>( &_config.state_machine_name ), STATE_MACHINE_NAME_TEXT )
		( "state_machine_type,y", value<sxy::state_machine_type>( &_config.sm_type )->default_value(sxy::state_machine_type::SMT_SYNC, STATE_MACHINE_TYPE_SYNC ), STATE_MACHINE_TYPE_TEXT)
		( "display_cfg,d", DISPLAY_CFG_TEXT );


	try
	{
		store( parse_command_line( argc, argv, description ), _variables );
		notify( _variables );

		if( _variables.count( "state_machine_name" ) )
		{
			std::string out_file = boost::any_cast< std::string >( _variables["state_machine_name"].value() );
			if( _variables.count( "out_file" ) )
			{
				out_file = boost::any_cast< std::string >( _variables["out_file"].value() );
			}
			_config.source_output_file = out_file + ".cpp";
			_config.header_output_file = out_file + ".hpp";
		}

		if( _variables.count( "help" ) )
		{
			printHelp = true;
		}

		if( _variables.count( "display_cfg" ) )
		{
			_config.print();
		}
	}
	catch( const std::exception& ex )
	{
		std::cout << "Error parsing command line: " << ex.what() << std::endl;
		printHelp = true;
	}
	catch( ... )
	{
		std::cout << "Unknown exception!" << std::endl;
		printHelp = true;
	}

	if( printHelp )
	{
		std::stringstream helpStream;
		helpStream << description;
		std::cout << helpStream.str() << std::endl;
	}

	return( !printHelp );
}


int main( int argc, char** argv )
{
	int error = 0;

	try
	{
		boost::program_options::variables_map variables;
		sxy::config generator_config;

		if( parse_program_options( argc, argv, variables, generator_config ) )
		{
			sxy::generate( generator_config );
		}
	}
	catch( const sx::genesis::genesis_exception& ex )
	{
		error = 1;
		std::cout << ex.what() << std::endl;
	}
	catch( const std::exception& std_ex )
	{
		error = 2;
		std::cout << std_ex.what() << std::endl;
	}
	catch( ... )
	{
		error = 3;
		std::cout << "Unknown error!" << std::endl;
	}

	if( error == 0 )
	{
		std::cout << std::endl << "Files successfully generated!" << std::endl;
	}
	else
	{
		std::cout << std::endl << "Files were not generated! See error(s) above." << std::endl;
	}

	return( error );
}
