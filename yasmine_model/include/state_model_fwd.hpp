//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef STATE_MODEL_FWD_00C93D56_497F_4C12_B9EC_F4846284C2BC
#define STATE_MODEL_FWD_00C93D56_497F_4C12_B9EC_F4846284C2BC


#include <vector>

#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


namespace model
{


class state_model;


typedef sxe::SX_UNIQUE_PTR<state_model> state_model_uptr;
typedef std::vector<state_model_uptr> state_models_uptr;
typedef std::vector<const state_model*> row_const_state_models;


}


}


#endif
