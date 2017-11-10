//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATE_MACHINE_WITH_SUBMACHINES_2ED377F2_0917_4082_8323_1756EFEFFEE2
#define STATE_MACHINE_WITH_SUBMACHINES_2ED377F2_0917_4082_8323_1756EFEFFEE2


#include "submachine.hpp"
#include "events.hpp"


namespace examples
{


class state_machine_with_submachines SX_FINAL
{


typedef sxe::SX_UNIQUE_PTR<sxy::sync_state_machine> state_machine_uptr;
typedef sxe::SX_UNIQUE_PTR<submachine> submachine_uptr;


public:
	state_machine_with_submachines();
	~state_machine_with_submachines() SX_NOEXCEPT;
	SX_NO_COPY( state_machine_with_submachines )
	void create();
	void run();


private:
	state_machine_uptr state_machine_;
	submachine_uptr submachine1_;
	submachine_uptr submachine2_;
};


}


#endif
