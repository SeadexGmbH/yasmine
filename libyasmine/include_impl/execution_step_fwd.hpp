//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EXECUTION_STEP_FWD_86F078EE_87D2_4AEA_9D9A_D6AACB48CD42
#define EXECUTION_STEP_FWD_86F078EE_87D2_4AEA_9D9A_D6AACB48CD42


#include <vector>
														
#include "essentials/compatibility/compatibility.hpp"


namespace sxy
{


class execution_step;
typedef sxe::SX_UNIQUE_PTR< execution_step > execution_step_uptr;
typedef std::vector< execution_step_uptr > execution_steps;


}


#endif
