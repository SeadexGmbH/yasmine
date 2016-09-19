//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATE_IMPL_3DE89F57_84D8_41A8_98D2_67E95A9D1C27
#define STATE_IMPL_3DE89F57_84D8_41A8_98D2_67E95A9D1C27


#include "state.hpp"
#include "vertex_impl.hpp"
#include "behavior_fwd.hpp"
#include "event_fwd.hpp"


namespace sxy
{


class state_impl:
	public virtual state, public vertex_impl
{
public:
	explicit state_impl( const std::string& _name );
	virtual ~state_impl() noexcept override = default;
	state_impl( const state_impl& ) = delete;
	state_impl& operator=( const state_impl& ) = delete;
	virtual const state_machine_element * get_parent() const override;
	virtual void set_parent_region( region* const _parent_region ) override;
	virtual region * get_parent_region() const override;
	virtual size_t get_parent_region_index() const override;
	virtual region * get_region( const std::string& _region_name ) const override;
	virtual vertex * get_pseudostate( const std::string& _name_of_pseudostate ) const override;
	virtual raw_composite_states get_ancestors( composite_state* const _final_ancestor ) const override;
	virtual raw_regions get_ancestors_as_regions() const override;
	virtual std::size_t get_nesting_level() const override;
	virtual void set_was_active() override;
	virtual bool was_active() const override;
	virtual void set_active() override;
	virtual void set_inactive() override;
	virtual bool is_active() const override;
	virtual bool is_complete() const override;
	virtual void execute_do_behavior( const event& _event, async_event_handler* const _async_event_handler ) const override;
	virtual void execute_enter_behavior( const event& _event ) const override;
	virtual void execute_exit_behavior( const event& _event ) const override;
	virtual void enter_state( const event& _event ) override;
	virtual void exit_state( const event& _event ) override;
	virtual bool has_error_event() const override;
	virtual event_sptr get_error_event() const override;


private:
	bool was_active_;
	region* parent_;
};


}


#endif
