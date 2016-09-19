//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_PSEUDOSTATE_FWD_64C5B45A_A614_4CE6_8634_E96D6DF41F04
#define I_PSEUDOSTATE_FWD_64C5B45A_A614_4CE6_8634_E96D6DF41F04


#include <vector>
#include <memory>


namespace sxy
{


class i_pseudostate;

using i_pseudostate_uptr = std::unique_ptr< i_pseudostate >;

using t_raw_const_pseudostates = std::vector< const i_pseudostate* >;
using t_pseudostates = std::vector< i_pseudostate_uptr >;


}


#endif
