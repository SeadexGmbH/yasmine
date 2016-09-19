//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_STATE_MACHINE_DEFECTS_FWD_075DDF50_2C94_4176_BB23_04A8D7292878
#define T_STATE_MACHINE_DEFECTS_FWD_075DDF50_2C94_4176_BB23_04A8D7292878


#include <vector>
#include <memory>
												

namespace sxy
{

class t_state_machine_defect;


using t_state_machine_defect_uptr = std::unique_ptr<t_state_machine_defect>;

using t_state_machine_defects = std::vector< t_state_machine_defect_uptr>;


}


#endif
