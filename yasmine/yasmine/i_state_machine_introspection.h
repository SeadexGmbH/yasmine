//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef I_STATE_MACHINE_INTROSPECTION_45E0820B_4D2F_4EF7_AF0D_EA840DA9F7C0
#define I_STATE_MACHINE_INTROSPECTION_45E0820B_4D2F_4EF7_AF0D_EA840DA9F7C0


#include "i_state_fwd.h"
#include "i_event_fwd.h"


namespace sxy
{


//!\interface i_state_machine_introspection
//!brief The interface for state machine introspection. It is inherited by the state machine class t_state_machine.
class i_state_machine_introspection
{


public:
	//!\brief Constructor of i_state_machine_introspection.
	i_state_machine_introspection
	(
	) = default;
	
	
	virtual ~i_state_machine_introspection
	(
	) = default;
	
	
	i_state_machine_introspection
	(
		const i_state_machine_introspection&
	) = delete;


	i_state_machine_introspection&
	operator=
	(
		const i_state_machine_introspection&
	) = delete;


	//!\brief Gets the active state configuration of the state machine.
	//!\return A list of active states of the state machine at the moment when the function is called.
	virtual t_raw_const_states
	get_active_state_configuration
	(
	) const = 0;


	virtual const t_events&
	get_deferred_events
	(
	) const = 0;
	

private:


};


}


#endif
