//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CONSTRAINT_FWD_1FEE3CF1_5B7B_43EF_9E40_8CE0D3170E67
#define CONSTRAINT_FWD_1FEE3CF1_5B7B_43EF_9E40_8CE0D3170E67


#include <memory>
#include <functional>


namespace sxy
{


class constraint;
class event;
using constraint_uptr = std::unique_ptr< constraint >;
using constraint_function = std::function< bool ( const event& ) >;


}


#endif
