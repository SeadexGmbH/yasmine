//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef VERTEX_FWD_9F913860_C5C3_4773_BB31_D98183BE0565
#define VERTEX_FWD_9F913860_C5C3_4773_BB31_D98183BE0565


#include <vector>
#include <memory>


namespace sxy
{


class vertex;
using vertex_uptr = std::unique_ptr< vertex >;
using raw_const_vertices = std::vector< const vertex* >;
using vertices = std::vector< vertex_uptr >;


}


#endif
