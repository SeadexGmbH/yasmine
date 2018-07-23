//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef SYNC_STATE_MACHINE_5352FE73_987B_4ECB_9320_685740A30EAA
#define SYNC_STATE_MACHINE_5352FE73_987B_4ECB_9320_685740A30EAA


#include <list>
#include "state_machine_base.hpp"


namespace sxy
{


//!\class sync_state_machine
//!\brief Class for the "single-threaded version" of the state machine. It provides the methods to start the state
//!machine, to fire events, to check the state machine for possible defects and to get the root state reference.
class sync_state_machine:
	public state_machine_base
{
public:
	//!\brief Constructor.
	//!\param _name Name of the state machine.
	//!\param _event_processing_callback Event processing callback interface pointer. It can be a nullptr if no callback
	//!interface should be used.
	explicit sync_state_machine( const std::string& _name,
		event_processing_callback* const _event_processing_callback = SX_NULLPTR );
	virtual ~sync_state_machine() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( sync_state_machine )

	virtual bool push( const event_sptr& _event ) SX_OVERRIDE;

	//!\brief Fire the given event.
	//!\param _event Event to be fired.	
	//!\return true if event was successfully fired, else false what means that a terminate pseudostate has been reached,
	//!the state machine was stopped and no further events can be fired.
	virtual bool fire_event( const event_sptr& _event ) SX_OVERRIDE;

	//!\brief Starts the state machine.	
	//!\return bool true if state machine can be started, else false what means that a terminate pseudostate has been
	//!reached and the state machine is stopped.
	virtual bool run() SX_OVERRIDE;
	

private:
	bool process_events_from_queue();

	std::list<event_sptr> event_list_;
};


//!\deprecated use sync_state_machine instead
typedef	sync_state_machine state_machine;


}


#endif
