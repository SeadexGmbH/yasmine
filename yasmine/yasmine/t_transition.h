//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_TRANSITION_A3D38DB7_CE2B_4C4B_A8C1_A54168549941
#define T_TRANSITION_A3D38DB7_CE2B_4C4B_A8C1_A54168549941


#include "i_transition.h"
#include "t_state_machine_element.h"
#include "i_constraint.h"
#include "i_behavior.h"


namespace sxy
{


class i_composite_state;


class t_transition: public virtual i_transition, public t_state_machine_element
{
public:
	t_transition
	(
		const t_event_id p_event_id,
		i_vertex& p_source,
		i_vertex& p_target,
		const sxy::t_transition_kind p_kind = t_transition_kind::EXTERNAL,
		const std::string& p_name = "",		
		i_constraint_uptr p_guard = nullptr,
		i_behavior_uptr p_behavior = nullptr
	);


	t_transition
	(
		const t_event_ids p_event_ids,
		i_vertex& p_source,
		i_vertex& p_target,
		const sxy::t_transition_kind p_kind = t_transition_kind::EXTERNAL,
		const std::string& p_name = "",
		i_constraint_uptr p_guard = nullptr,
		i_behavior_uptr p_behavior = nullptr
	);


	virtual
	~t_transition
	(
	) override;


	t_transition
	(
		const t_transition&
	) = delete;


	t_transition&
	operator=
	(
		const t_transition&
	) = delete;


	virtual const i_vertex&
	get_source
	(
	) const override;


	virtual const i_vertex&
	get_target
	(
	) const override;


	virtual i_vertex&
	get_target
	(
	) override;


	virtual const i_constraint*
	get_guard
	(
	) const override;


	virtual const i_behavior*
	get_behavior
	(
	) const override;


	virtual t_uri
	get_uri
	(
	) const override;


	virtual sxy::t_transition_kind
	get_kind
	(
	) const override;
 

	virtual void
	add_ancestor_uri
	(
		t_uri& p_uri
	) const override;


	virtual void
	on_transition_behavior
	(
		const i_event& p_event
	) const override;


	virtual bool
	check_guard
	(
		const i_event& p_event
	) const override;


	virtual bool
	check
	(
		t_state_machine_defects& p_defects
	) const override;


	virtual bool
	can_accept_event
	(
		const t_event_id p_event
	) const override;


private:
	static bool
	check_if_source_and_target_are_in_ancestor_relationship
	(
		const i_vertex& p_source,
		const i_vertex& p_target
	);


	static bool
	check_relationship
	(
		const i_vertex& p_lhs,
		const i_composite_state* p_rhs
	);


	t_event_ids m_events;
	i_vertex& m_source;
	i_vertex& m_target;
	i_constraint_uptr m_guard;
	i_behavior_uptr m_behavior;
	t_transition_kind m_kind;


};


}


#endif
