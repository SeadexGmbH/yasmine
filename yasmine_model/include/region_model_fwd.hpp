//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef REGION_MODEL_FWD_77B8548B_6558_41A0_8514_0EDE8724D8BE
#define REGION_MODEL_FWD_77B8548B_6558_41A0_8514_0EDE8724D8BE


#include <vector>

#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


namespace model
{


class region_model;
class region_model_impl;


typedef sxe::SX_UNIQUE_PTR<region_model> region_model_uptr;
typedef sxe::SX_UNIQUE_PTR<region_model_impl> region_model_impl_uptr;
typedef std::vector<region_model_uptr> region_models_uptr;
typedef std::vector<const region_model*> raw_const_region_models;


}


}


#endif
