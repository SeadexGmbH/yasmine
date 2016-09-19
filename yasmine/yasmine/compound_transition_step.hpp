//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef COMPOUND_TRANSITION_STEP_5FE5C12E_E6AE_4F16_AD93_764327C2E299
#define COMPOUND_TRANSITION_STEP_5FE5C12E_E6AE_4F16_AD93_764327C2E299


#include "transition_step.hpp"


namespace sxy
{


class compound_transition_step final:
	public transition_step
{
public:
	explicit compound_transition_step( const raw_transitions& _transition_step );
	virtual ~compound_transition_step() noexcept override = default;
	compound_transition_step( const compound_transition_step& ) = delete;
	compound_transition_step& operator=( const compound_transition_step& ) = delete;
	virtual const raw_transitions& get_transitions() const override;
	virtual const vertex& get_unique_source() const override;
	virtual const vertex& get_unique_target() const override;
	virtual const exit_point * get_exit_point() const override;
	virtual const entry_point * get_entry_point() const override;
	virtual const raw_const_vertices get_target_vertices() override;
	void execute_transition_behaviors( const event& _event ) const override;


private:
	const raw_transitions transitions_;
};


}


#endif
