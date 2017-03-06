//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TRANSITION_IMPL_9F6CF536_11D2_4F11_B5FB_AB930B935720
#define TRANSITION_IMPL_9F6CF536_11D2_4F11_B5FB_AB930B935720


#include "transition.hpp"
#include "state_machine_element_impl.hpp"
#include "constraint.hpp"
#include "behavior.hpp"


namespace sxy
{


class composite_state;


class transition_impl Y_FINAL:
	public virtual transition, public state_machine_element_impl
{
public:
	transition_impl( const event_id _event_id, vertex& _source, vertex& _target, 
		const sxy::transition_kind _kind = transition_kind::EXTERNAL, 
		constraint_uptr _guard = constraint_uptr(), behavior_uptr _behavior = behavior_uptr());
	transition_impl( const event_ids _event_ids, vertex& _source, vertex& _target, 
		const sxy::transition_kind _kind = transition_kind::EXTERNAL,
		constraint_uptr _guard = constraint_uptr(), behavior_uptr _behavior = behavior_uptr());
	virtual ~transition_impl() Y_NOEXCEPT Y_OVERRIDE;
	Y_NO_COPY(transition_impl)
	virtual const vertex& get_source() const Y_OVERRIDE;
	virtual const vertex& get_target() const Y_OVERRIDE;
	virtual vertex& get_target() Y_OVERRIDE;
	virtual const constraint * get_guard() const Y_OVERRIDE;
	virtual const behavior * get_behavior() const Y_OVERRIDE;
	virtual uri get_uri() const Y_OVERRIDE;
	virtual const state_machine_element * get_parent() const Y_OVERRIDE;
	virtual sxy::transition_kind get_kind() const Y_OVERRIDE;
	virtual void add_ancestor_uri( uri& _uri ) const Y_OVERRIDE;
	virtual void on_transition_behavior( const event& _event, event_collector& _event_collector ) const Y_OVERRIDE;
	virtual bool check_guard( const event& _event, event_collector& _event_collector ) const Y_OVERRIDE;
	virtual bool check( state_machine_defects& _defects ) const Y_OVERRIDE;
	virtual bool can_accept_event( const event_id _event ) const Y_OVERRIDE;


private:
	static bool check_if_source_and_target_are_in_ancestor_relationship( const vertex& _source, 
		const vertex& _target );
	static bool check_relationship( const vertex& _lhs, const composite_state* _rhs );
	static std::string get_transition_name( vertex& _source, vertex& _target, const event_ids& _event_ids );
	bool check_for_cross_region_transition( state_machine_defects& _defects ) const;
	bool check_child_parent_relationship_of_source_target_of_transition( state_machine_defects& _defects ) const;
	bool check_initial_pseudostate( state_machine_defects& _defects ) const;
	bool check_exit_point( state_machine_defects& _defects ) const;

	event_ids event_ids_;
	vertex& source_;
	vertex& target_;
	constraint_uptr guard_;
	behavior_uptr behavior_;
	transition_kind kind_;
};


}


#endif
