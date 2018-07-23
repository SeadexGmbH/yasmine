//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef COMPOUND_TRANSITION_STEP_5FE5C12E_E6AE_4F16_AD93_764327C2E299
#define COMPOUND_TRANSITION_STEP_5FE5C12E_E6AE_4F16_AD93_764327C2E299


#include "transition_step.hpp"


namespace sxy
{


class compound_transition_step SX_FINAL:
	public transition_step
{
public:
	explicit compound_transition_step( const raw_transitions& _transition_step );
	virtual ~compound_transition_step() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(compound_transition_step)
	virtual const raw_transitions& get_transitions() const SX_OVERRIDE;
	virtual const vertex& get_unique_source() const SX_OVERRIDE;
	virtual const vertex& get_unique_target() const SX_OVERRIDE;
	virtual const exit_point * get_exit_point() const SX_OVERRIDE;
	virtual const entry_point * get_entry_point() const SX_OVERRIDE;
	virtual const raw_const_vertices get_target_vertices() SX_OVERRIDE;
	void execute_transition_behaviors( const event& _event, event_collector& _event_collector ) const SX_OVERRIDE;


private:
	const raw_transitions transitions_;
};


}


#endif
