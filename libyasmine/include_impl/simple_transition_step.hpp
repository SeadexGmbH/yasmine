//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef SIMPLE_TRANSITION_STEP_12297D2C_C792_4163_B87A_1CB896808779
#define SIMPLE_TRANSITION_STEP_12297D2C_C792_4163_B87A_1CB896808779


#include "transition_step.hpp"


namespace sxy
{


class transition;
class state;


class simple_transition_step SX_FINAL:
	public transition_step
{
public:
	explicit simple_transition_step( transition& _transition );
	virtual ~simple_transition_step() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(simple_transition_step)
	virtual const raw_transitions& get_transitions() const SX_OVERRIDE;
	virtual const vertex& get_unique_source() const SX_OVERRIDE;
	virtual const vertex& get_unique_target() const SX_OVERRIDE;
	virtual const exit_point * get_exit_point() const SX_OVERRIDE;
	virtual const entry_point * get_entry_point() const SX_OVERRIDE;
	virtual const raw_const_vertices get_target_vertices() SX_OVERRIDE;
	void execute_transition_behaviors( const event& _event, event_collector& _event_collector ) const SX_OVERRIDE;


private:
	transition& transition_;
	raw_transitions transition_step_;
};


}


#endif
