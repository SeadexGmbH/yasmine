//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_FORK_FWD_9E024994_76D1_4B32_AAA5_30630EC8F828
#define I_FORK_FWD_9E024994_76D1_4B32_AAA5_30630EC8F828


#include <vector>
#include <memory>


namespace sxy
{


class i_fork;

using i_fork_uptr = std::unique_ptr< i_fork >;

using t_forks = std::vector< i_fork_uptr >;
using t_raw_const_forks = std::vector< const i_fork* >;


}


#endif

