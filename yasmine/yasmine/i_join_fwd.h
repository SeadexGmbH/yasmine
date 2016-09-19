//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_JOIN_FWD_62FA1B0B_2997_4645_A325_BD9ED4C1EC7D
#define I_JOIN_FWD_62FA1B0B_2997_4645_A325_BD9ED4C1EC7D


#include <vector>
#include <memory>


namespace sxy
{


class i_join;
using i_join_uptr = std::unique_ptr< i_join >;
using t_joins = std::vector< i_join_uptr >;
using t_raw_const_joins = std::vector< const i_join* >;


}


#endif
