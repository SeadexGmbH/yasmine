//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
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


class transition_impl final:
	public virtual transition, public state_machine_element_impl
{
public:
	transition_impl(	const event_id _event_id, vertex& _source, vertex& _target, 
		const sxy::transition_kind _kind = transition_kind::EXTERNAL, 
		constraint_uptr _guard = nullptr, behavior_uptr _behavior = nullptr );
	transition_impl(	const event_ids _event_ids, vertex& _source, vertex& _target, 
		const sxy::transition_kind _kind = transition_kind::EXTERNAL,
		constraint_uptr _guard = nullptr, behavior_uptr _behavior = nullptr );
	virtual ~transition_impl() noexcept override;
	transition_impl( const transition_impl& ) = delete;
	transition_impl& operator=( const transition_impl& ) = delete;
	virtual const vertex& get_source() const override;
	virtual const vertex& get_target() const override;
	virtual vertex& get_target() override;
	virtual const constraint * get_guard() const override;
	virtual const behavior * get_behavior() const override;
	virtual uri get_uri() const override;
	virtual const state_machine_element * get_parent() const override;
	virtual sxy::transition_kind get_kind() const override;
	virtual void add_ancestor_uri( uri& _uri ) const override;
	virtual void on_transition_behavior( const event& _event ) const override;
	virtual bool check_guard( const event& _event ) const override;
	virtual bool check( state_machine_defects& _defects ) const override;
	virtual bool can_accept_event( const event_id _event ) const override;


private:
	static bool check_if_source_and_target_are_in_ancestor_relationship( const vertex& _source, 
		const vertex& _target );
	static bool check_relationship( const vertex& _lhs, const composite_state* _rhs );
	static std::string get_transition_name( vertex& _source, vertex& _target, const event_ids _event_ids );


	event_ids event_ids_;
	vertex& source_;
	vertex& target_;
	constraint_uptr guard_;
	behavior_uptr behavior_;
	transition_kind kind_;
};


}


#endif
