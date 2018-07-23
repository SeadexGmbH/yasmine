//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BEHAVIOR_STRUCT_12B226AB_A03E_4F10_AD6D_52E3F253A776
#define BEHAVIOR_STRUCT_12B226AB_A03E_4F10_AD6D_52E3F253A776


#include "essentials/non_copyable.hpp"

#include "state_machine_type.hpp"
#include "access_operator.hpp"


namespace sxy
{


struct behavior_struct
{
public:
	behavior_struct();
	~behavior_struct() SX_NOEXCEPT;
	SX_NO_COPY( behavior_struct )


	std::string behavior_class_name;
	std::string behavior_method_name;
	access_operator call_operator;
};


}


#endif
