//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef REGION_06648EA9_E80A_49B8_9814_1723273908D2
#define REGION_06648EA9_E80A_49B8_9814_1723273908D2


#include "state_machine_element.h"
#include "state_fwd.h"
#include "region_fwd.h"
#include "pseudostate_fwd.h"
#include "initial_pseudostate_fwd.h"
#include "choice_fwd.h"
#include "fork_fwd.h"
#include "join_fwd.h"
#include "junction_fwd.h"
#include "terminate_pseudostate_fwd.h"
#include "behavior_fwd.h"
#include "event_id.h"
#include "behavior_exception_fwd.h"
#include "behavior_exception.h"
#include "async_behavior_fwd.h"


namespace sxy
{


class vertex;
class composite_state;
class simple_state;
class final_state;
class region:
	public virtual state_machine_element
{
public:
	region() = default;
	virtual ~region () override = default;
	region( const region& ) = delete;
	region& operator=( const region& ) = delete;
	virtual void set_parent_state( composite_state* const _composite_state ) = 0;
	virtual const composite_state& get_parent_state() const = 0;
	virtual composite_state& get_parent_state() = 0;
	virtual raw_const_states get_states() const = 0;
	virtual size_t get_pseudostate_count() const = 0;
	virtual vertex* get_pseudostate( const std::string& _name ) const = 0;
	virtual vertex* get_vertex( const std::string& _vertex_name ) const = 0;
	virtual raw_const_pseudostates get_pseudostates() const = 0;
	virtual initial_pseudostate* get_initial_pseudostate() const = 0;
	virtual initial_pseudostate& add_initial_pseudostate( initial_pseudostate_uptr _initial_state ) = 0;
	virtual initial_pseudostate& add_initial_pseudostate( const std::string& _initial_state_name ) = 0;
	virtual state& add_state( state_uptr _state ) = 0;
	virtual choice& add_choice( choice_uptr _choice ) = 0;
	virtual choice& add_choice( const std::string& _choice_name ) = 0;
	virtual fork& add_fork( fork_uptr _fork ) = 0;
	virtual fork& add_fork( const std::string& _fork_name ) = 0;
	virtual join& add_join( join_uptr _join ) = 0;
	virtual join& add_join( const std::string& _join_name ) = 0;
	virtual junction& add_junction( junction_uptr _junction ) = 0;
	virtual junction& add_junction( const std::string& _junction_name ) = 0;
	virtual terminate_pseudostate& add_terminate_pseudostate( 
		const terminate_pseudostate_uptr _terminate_pseudostate ) = 0;
	virtual terminate_pseudostate& add_terminate_pseudostate( const std::string& _terminate_pseudostate_name ) = 0;
	virtual simple_state& add_simple_state( const std::string& _name, 
		const behavior_function& _behavior = behavior_function(),
		const behavior_function& _entry_behavior = behavior_function(),
		const behavior_function& _exit_behavior = behavior_function() ) = 0;
	virtual simple_state& add_simple_state( const std::string& _name, const event_ids& _deferred_events,
		const behavior_function& _behavior = behavior_function(),
		const behavior_function& _entry_behavior = behavior_function(),
		const behavior_function& _exit_behavior = behavior_function(),
		behavior_exception_uptr _error_event = nullptr ) = 0;
	virtual simple_state& add_async_simple_state( const std::string& _name, const event_ids& _deferred_events,
		async_behavior_uptr _do_action = nullptr, const behavior_function& _entry_behavior = behavior_function(), 
		const behavior_function& _exit_behavior = behavior_function(),
		behavior_exception_uptr _error_event = nullptr ) = 0;
	virtual composite_state& add_composite_state(	const std::string& _name,
		const behavior_function& _entry_action = behavior_function(),
		const behavior_function& _exit_action = behavior_function() ) = 0;
	virtual composite_state& add_composite_state(	const std::string& _name, const event_ids& _deferred_events,
		const behavior_function& _entry_action = behavior_function(),
		const behavior_function& _exit_action = behavior_function() ) = 0;
	virtual final_state& add_final_state( const std::string& _name ) = 0;
	virtual size_t get_state_count() const = 0;
	virtual state* get_state( const std::string& _name ) const = 0;
	virtual const state* get_active_state() const = 0;
	virtual state* get_active_state() = 0;
	virtual void set_active_state( state* const _active_state ) = 0;
	virtual void set_state_was_active( state* const _active_state ) = 0;
	virtual const state* get_last_active_state() const = 0;
	virtual state* get_last_active_state() = 0;
	virtual bool is_active_state_final() const = 0;
	virtual bool check( state_machine_defects& _defects ) const override = 0;
};


}


#endif
