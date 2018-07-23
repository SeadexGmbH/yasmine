//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATE_MACHINE_INTROSPECTION_45E0820B_4D2F_4EF7_AF0D_EA840DA9F7C0
#define STATE_MACHINE_INTROSPECTION_45E0820B_4D2F_4EF7_AF0D_EA840DA9F7C0


#include "essentials/non_copyable.hpp"

#include "state_fwd.hpp"
#include "event_fwd.hpp"


namespace sxy
{


//!\interface state_machine_introspection
//!\brief The interface for state machine introspection. It is inherited by the state machine class state_machine.
class state_machine_introspection
{
public:
	//!\brief Constructor.
	state_machine_introspection()
	{
		// Nothing to do...
	}


	virtual ~state_machine_introspection() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	SX_NO_COPY(state_machine_introspection)

	//!\brief Get the active state configuration of the state machine.
	//!\return A list of active states of the state machine at the moment when the function is called.
	virtual raw_const_states get_active_state_configuration() const = 0;
	virtual const events& get_deferred_events() const = 0;	
};


}


#endif
