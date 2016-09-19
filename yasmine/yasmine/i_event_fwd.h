//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_EVENT_FWD_622C6A23_5E15_4A6B_8278_460C74941A10
#define I_EVENT_FWD_622C6A23_5E15_4A6B_8278_460C74941A10


#include <vector>
#include <memory>


namespace sxy
{


class i_event;


using t_event_sptr = std::shared_ptr< i_event >;
using t_events = std::vector< std::shared_ptr< i_event > >;


}


#endif
