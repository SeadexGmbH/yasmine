//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_JUNCTION_FWD_7B62488D_9661_42DD_BC43_8E9737158029
#define I_JUNCTION_FWD_7B62488D_9661_42DD_BC43_8E9737158029


#include <vector>
#include <memory>


namespace sxy
{


class i_junction;

using i_junction_uptr = std::unique_ptr< i_junction >;

using t_junctions = std::vector< i_junction_uptr >;
using t_raw_const_junctions = std::vector< const i_junction* >;


}


#endif
