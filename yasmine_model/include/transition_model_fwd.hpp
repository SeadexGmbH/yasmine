//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TRANSITION_MODEL_FWD_4026F90C_A4BE_4D2E_86C9_61B0A3CB98D3
#define TRANSITION_MODEL_FWD_4026F90C_A4BE_4D2E_86C9_61B0A3CB98D3


#include <vector>

#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


namespace model
{


class transition_model;


typedef sxe::SX_UNIQUE_PTR<transition_model> transition_model_uptr;
typedef std::vector<transition_model_uptr> transition_models;
typedef std::vector<const transition_model*> raw_const_transition_models;


}


}


#endif
