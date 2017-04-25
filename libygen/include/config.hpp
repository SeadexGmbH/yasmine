//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef YGEN_CONFIG_FB3FF499_2D1D_437A_8C77_CB6E9422EE10
#define YGEN_CONFIG_FB3FF499_2D1D_437A_8C77_CB6E9422EE10


#include <vector>

#include "essentials/non_copyable.hpp"

#include "state_machine_type.hpp"


namespace sxy
{


struct config
{
public:
	config();
	~config() SX_NOEXCEPT;
	SX_NO_COPY( config )
	void print() const;

	std::string template_path;
	std::string source_template_file;
	std::string header_template_file;
	std::string source_output_file;
	std::string header_output_file;
	std::string model_file;
	std::string state_machine_name;
	state_machine_type sm_type;
	std::vector<std::string> namespaces;
	std::vector<std::string> behavior_classes;
};


}


#endif
