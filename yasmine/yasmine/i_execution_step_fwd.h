//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_EXECUTION_STEP_FWD_86F078EE_87D2_4AEA_9D9A_D6AACB48CD42
#define I_EXECUTION_STEP_FWD_86F078EE_87D2_4AEA_9D9A_D6AACB48CD42


#include <vector>
#include <memory>


namespace sxy
{


class i_execution_step;

using i_execution_step_uptr = std::unique_ptr< i_execution_step >;

using t_execution_steps = std::vector< i_execution_step_uptr >;


}


#endif
