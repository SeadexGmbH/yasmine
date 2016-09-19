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


#include "transition_step.h"


namespace sxy
{


class transition;
class state;


class simple_transition_step final:
	public transition_step
{
public:
	explicit simple_transition_step( transition& _transition );
	virtual ~simple_transition_step() override;
	simple_transition_step( const simple_transition_step& ) = delete;
	simple_transition_step& operator=( const simple_transition_step& ) = delete;
	virtual const raw_transitions& get_transitions() const override;
	virtual const vertex& get_unique_source() const override;
	virtual const vertex& get_unique_target() const override;
	virtual const exit_point * get_exit_point() const override;
	virtual const entry_point * get_entry_point() const override;
	virtual const raw_const_vertices get_target_vertices() override;
	void execute_transition_behaviors( const event& _event ) const override;


private:
	transition& transition_;
	raw_transitions transition_step_;
};


}


#endif
