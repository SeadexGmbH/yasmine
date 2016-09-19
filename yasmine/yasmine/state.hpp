//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef STATE_A72D37CD_D9B1_430D_BBCA_13371745FC80
#define STATE_A72D37CD_D9B1_430D_BBCA_13371745FC80


#include "vertex.hpp"
#include "state_fwd.hpp"
#include "region_fwd.hpp"
#include "event_fwd.hpp"


namespace sxy
{


class state_visitor;
class behavior;
class event;
class async_event_handler;


class state:
	public virtual vertex
{
public:
	state() = default;
	virtual ~state() noexcept override = default;
	state( const state& ) = delete;
	state& operator=( const state& ) = delete;
	virtual void set_parent_region( region* const _parent_region ) = 0;
	virtual region * get_parent_region() const = 0;
	virtual size_t get_parent_region_index() const = 0;
	virtual region * get_region( const std::string& _region_name ) const = 0;
	virtual vertex * get_pseudostate( const std::string& _name_of_pseudostate ) const = 0;
	virtual behavior * get_entry_behavior() const = 0;
	virtual behavior * get_exit_behavior() const = 0;
	virtual std::size_t get_nesting_level() const = 0;
	virtual void set_active() = 0;
	virtual void set_inactive() = 0;
	virtual bool is_active() const = 0;
	virtual bool is_complete() const = 0;
	virtual bool is_event_deferred( const event_id& _event_id ) const = 0;
	virtual bool was_active() const = 0;
	virtual void set_was_active() = 0;
	virtual const regions& get_regions() const = 0;
	virtual regions& get_regions() = 0;
	virtual void execute_do_behavior( const event& _event, async_event_handler* const _async_event_handler ) const = 0;
	virtual void execute_enter_behavior( const event& _event ) const = 0;
	virtual void execute_exit_behavior( const event& _event ) const = 0;
	virtual void accept_state_visitor( state_visitor& _visitor ) const = 0;
	virtual void enter_state( const event& _event ) = 0;
	virtual void exit_state( const event& _event ) = 0;
	virtual bool has_error_event() const = 0;
	virtual event_sptr get_error_event() const = 0;
};


}


#endif
