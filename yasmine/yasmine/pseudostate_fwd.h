//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef PSEUDOSTATE_FWD_64C5B45A_A614_4CE6_8634_E96D6DF41F04
#define PSEUDOSTATE_FWD_64C5B45A_A614_4CE6_8634_E96D6DF41F04


#include <vector>
#include <memory>


namespace sxy
{


class pseudostate;
using pseudostate_uptr = std::unique_ptr< pseudostate >;
using pseudostates = std::vector< pseudostate_uptr >;
using raw_const_pseudostates = std::vector< const pseudostate* >;


}


#endif
