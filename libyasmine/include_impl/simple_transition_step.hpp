//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef SIMPLE_TRANSITION_STEP_12297D2C_C792_4163_B87A_1CB896808779
#define SIMPLE_TRANSITION_STEP_12297D2C_C792_4163_B87A_1CB896808779


#include "transition_step.hpp"


namespace sxy
{


class transition;
class state;


class simple_transition_step Y_FINAL:
	public transition_step
{
public:
	explicit simple_transition_step( transition& _transition );
	virtual ~simple_transition_step() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(simple_transition_step)
	virtual const raw_transitions& get_transitions() const Y_OVERRIDE;
	virtual const vertex& get_unique_source() const Y_OVERRIDE;
	virtual const vertex& get_unique_target() const Y_OVERRIDE;
	virtual const exit_point * get_exit_point() const Y_OVERRIDE;
	virtual const entry_point * get_entry_point() const Y_OVERRIDE;
	virtual const raw_const_vertices get_target_vertices() Y_OVERRIDE;
	void execute_transition_behaviors( const event& _event ) const Y_OVERRIDE;


private:
	transition& transition_;
	raw_transitions transition_step_;
};


}


#endif
