//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_CONSTRAINT_FWD_1FEE3CF1_5B7B_43EF_9E40_8CE0D3170E67
#define I_CONSTRAINT_FWD_1FEE3CF1_5B7B_43EF_9E40_8CE0D3170E67


#include <memory>
#include <functional>


namespace sxy
{


class i_constraint;
class i_event;
using i_constraint_uptr = std::unique_ptr< i_constraint >;
using t_constraint_function = std::function< bool ( const i_event& ) >;


}


#endif
