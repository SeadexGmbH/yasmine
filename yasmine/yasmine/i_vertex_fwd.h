//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_VERTEX_FWD_9F913860_C5C3_4773_BB31_D98183BE0565
#define I_VERTEX_FWD_9F913860_C5C3_4773_BB31_D98183BE0565


#include <vector>
#include <memory>


namespace sxy
{


class i_vertex;

using t_vertex_uptr = std::unique_ptr< i_vertex >;

using t_raw_const_vertices = std::vector< const i_vertex* >;
using t_vertices = std::vector< t_vertex_uptr >;


}


#endif
