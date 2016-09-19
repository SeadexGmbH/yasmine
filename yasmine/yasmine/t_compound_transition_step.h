//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_COMPOUND_TRANSITION_STEP_5FE5C12E_E6AE_4F16_AD93_764327C2E299
#define T_COMPOUND_TRANSITION_STEP_5FE5C12E_E6AE_4F16_AD93_764327C2E299


#include "i_transition_step.h"


namespace sxy
{


class t_compound_transition_step final: public i_transition_step
{
public:
	explicit t_compound_transition_step
	(
		const t_raw_transitions& p_transition_step
	);


	virtual
	~t_compound_transition_step
	(
	) override;


	t_compound_transition_step
	(
		const t_compound_transition_step&
	) = delete;


	t_compound_transition_step&
	operator=
	(
		const t_compound_transition_step&
	) = delete;


	virtual const t_raw_transitions&
	get_transitions
	(
	) const override;


	virtual const i_vertex&
	get_unique_source
	(
	) const override;


	virtual const i_vertex&
	get_unique_target
	(
	) const override;


	virtual  const i_exit_point*
	get_exit_point
	(
	) const override;


	virtual const i_entry_point*
	get_entry_point
	(
	) const override;
	 

	virtual const t_raw_const_vertices
	get_target_vertices
	(
	) override;


	void
	execute_transition_behaviors
	(
		const i_event& p_event
	) const override;


private:
	const t_raw_transitions m_transitions;	


};





}


#endif
