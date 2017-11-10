//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATE_IMPL_3DE89F57_84D8_41A8_98D2_67E95A9D1C27
#define STATE_IMPL_3DE89F57_84D8_41A8_98D2_67E95A9D1C27


#include "state.hpp"
#include "vertex_impl.hpp"
#include "behavior_fwd.hpp"
#include "event_fwd.hpp"
#include "optimization.hpp"


namespace sxy
{


class state_impl:
	public virtual state, public vertex_impl
{
public:
	explicit state_impl( const std::string& _name );
	virtual ~state_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(state_impl)
	virtual const state_machine_element * get_parent() const SX_OVERRIDE;
	virtual void set_parent_region( region* const _parent_region ) SX_OVERRIDE;
	virtual region * get_parent_region() const SX_OVERRIDE;
	virtual size_t get_parent_region_index() const SX_OVERRIDE;
	virtual region * get_region( const std::string& _region_name ) const SX_OVERRIDE;
	virtual vertex * get_pseudostate( const std::string& _name_of_pseudostate ) const SX_OVERRIDE;
	virtual raw_composite_states get_ancestors( composite_state* const _final_ancestor,
		bool _include_final_ancestor = true ) const SX_OVERRIDE;
	virtual raw_regions get_ancestors_as_regions() const SX_OVERRIDE;
	virtual std::size_t get_nesting_level() const SX_OVERRIDE;
	virtual void set_was_active() SX_OVERRIDE;
	virtual bool was_active() const SX_OVERRIDE;
	virtual void set_active() SX_OVERRIDE;
	virtual void set_inactive() SX_OVERRIDE;
	virtual bool is_active() const SX_OVERRIDE;
	virtual bool is_complete() const SX_OVERRIDE;
	virtual void execute_do_behavior( const event& _event, async_event_handler* const _async_event_handler,
		event_collector& _event_collector ) const SX_OVERRIDE;
	virtual void execute_enter_behavior( const event& _event, event_collector& _event_collector ) const SX_OVERRIDE;
	virtual void execute_exit_behavior( const event& _event, event_collector& _event_collector ) const SX_OVERRIDE;
	virtual void enter_state( const event& _event, event_collector& _event_collector ) SX_OVERRIDE;
	virtual void exit_state( const event& _event, event_collector& _event_collector ) SX_OVERRIDE;
	virtual bool has_error_event() const SX_OVERRIDE;
	virtual event_sptr get_error_event() const SX_OVERRIDE
	// HACK clang
	// Implementation has to be here to avoid linker error under clang.
	{
		return( event_sptr() );
	}


private:
	void collect_ancestors( raw_composite_states& _ancestors, composite_state* const _final_ancestor ) const;
	void collect_ancestors_as_regions( raw_regions& _ancestors_as_regions ) const;

	bool was_active_;
	bool is_active_;
	region* parent_;

#ifdef Y_OPTIMIZE_4_SPEED
	mutable raw_composite_states ancestors_;
	mutable raw_regions ancestors_as_regions_;
#endif
};


}


#endif
