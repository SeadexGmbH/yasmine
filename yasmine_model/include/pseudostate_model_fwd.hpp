//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PSEUDOSTATE_MODEL_FWD_B51FBD5C_C127_419E_8E47_4FACE291D1AE
#define PSEUDOSTATE_MODEL_FWD_B51FBD5C_C127_419E_8E47_4FACE291D1AE


#include <vector>

#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


namespace model
{


class pseudostate_model_impl;
class pseudostate_model;


typedef sxe::SX_UNIQUE_PTR<pseudostate_model_impl> pseudostate_model_uptr;
typedef std::vector<pseudostate_model_uptr> pseudostate_models_uptr;
typedef std::vector< const pseudostate_model_impl*> raw_const_pseduostate_models;


}


}


#endif
