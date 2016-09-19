//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_COMPOSITE_STATE_FWD_4E6EFA7D_4400_4B33_A330_603146E114BD
#define I_COMPOSITE_STATE_FWD_4E6EFA7D_4400_4B33_A330_603146E114BD


#include <vector>
#include <memory>


namespace sxy
{


class i_composite_state;
using i_composite_state_uptr = std::unique_ptr< i_composite_state >;
using t_raw_composite_states = std::vector< i_composite_state* >;


}


#endif
