//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CONFIG_F0DF6484_1AB7_48AC_9471_42C853B24430
#define CONFIG_F0DF6484_1AB7_48AC_9471_42C853B24430


#include "country.hpp"


namespace examples
{


struct config
{
	config();

	std::string template_path_;
	std::string source_template_file_;	
	std::string output_file_;	
	std::vector<country> countries_;	
};


}


#endif
