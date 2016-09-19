//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_CHOICE_FWD_CC41E744_8F28_465B_8CD6_4F3A437D121C
#define I_CHOICE_FWD_CC41E744_8F28_465B_8CD6_4F3A437D121C


#include <vector>
#include <memory>


namespace sxy
{


class i_choice;

using i_choice_uptr = std::unique_ptr< i_choice >;

using t_choices = std::vector< i_choice_uptr >;
using t_raw_const_choices = std::vector< const i_choice* >;


}


#endif
