//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_TERMINATE_PSEUDOSTATE_FWD_C63AEEFF_DBF1_44D5_961A_A2E4D0BB745B
#define I_TERMINATE_PSEUDOSTATE_FWD_C63AEEFF_DBF1_44D5_961A_A2E4D0BB745B


#include <vector>
#include <memory>


namespace sxy
{


class i_terminate_pseudostate;
using i_terminate_pseudostate_uptr = std::unique_ptr< i_terminate_pseudostate >;
using t_terminate_pseudostates = std::vector< i_terminate_pseudostate_uptr >;
using t_raw_const_terminate_pseudostates = std::vector< const i_terminate_pseudostate* >;


}


#endif
