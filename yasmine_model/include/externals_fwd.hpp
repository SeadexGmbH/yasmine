//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef EXTERNALS_FWD_0272FF1D_FEB5_48EB_BDD8_A094BAD8D12F
#define EXTERNALS_FWD_0272FF1D_FEB5_48EB_BDD8_A094BAD8D12F

#include <vector>

#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


namespace model
{

class state_machine_external_element;
typedef sxe::SX_UNIQUE_PTR<sxy::model::state_machine_external_element> external_uptr;
typedef std::vector< external_uptr > external_vertices;

}


}


#endif

