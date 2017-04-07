//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef REGION_IMPL_DDA92905_6CBE_4061_8DA1_4E6C1E98E11A
#define REGION_IMPL_DDA92905_6CBE_4061_8DA1_4E6C1E98E11A


#include "region.hpp"
#include "state_machine_element_impl.hpp"


namespace sxy
{


class region_impl SX_FINAL: 
	public virtual region, public state_machine_element_impl
{
public:
	explicit region_impl( const std::string& _name ); 
	virtual ~region_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY(region_impl)
	void set_parent_state( composite_state* const _composite_state ) SX_OVERRIDE;
	virtual raw_const_states get_states() const SX_OVERRIDE;
	virtual const composite_state& get_parent_state() const SX_OVERRIDE;
	virtual composite_state& get_parent_state() SX_OVERRIDE;	
	virtual vertex* get_vertex( const std::string& _vertex_name ) const SX_OVERRIDE;
	virtual size_t get_pseudostate_count() const SX_OVERRIDE;
	virtual vertex* get_pseudostate( const std::string& _name ) const SX_OVERRIDE;
	virtual raw_const_pseudostates get_pseudostates() const SX_OVERRIDE;
	virtual initial_pseudostate* get_initial_pseudostate() const SX_OVERRIDE;
	virtual size_t get_state_count() const SX_OVERRIDE;
	virtual state* get_state( const std::string& _name ) const SX_OVERRIDE; 
	virtual const state* get_active_state() const SX_OVERRIDE;
	virtual state* get_active_state() SX_OVERRIDE;
	virtual void set_active_state( state* const _active_state ) SX_OVERRIDE;
	virtual void set_state_was_active( state* const _active_state ) SX_OVERRIDE;
	virtual const state* get_last_active_state() const SX_OVERRIDE;
	virtual state* get_last_active_state() SX_OVERRIDE;
	virtual initial_pseudostate& add_initial_pseudostate( initial_pseudostate_uptr _initial_state ) SX_OVERRIDE;

	//!\brief Creates an initial pseudostate with the given name and adds it to the parent region.
	//!\param _initial_state_name Name of the initial pseudostate. 
	//!\return A reference to the newly created initial pseudostate.
	virtual initial_pseudostate& add_initial_pseudostate( const std::string& _initial_state_name ) SX_OVERRIDE;
	virtual state& add_state( state_uptr _state ) SX_OVERRIDE;
	virtual simple_state& add_simple_state( const std::string& _simple_state_name, 
		const behavior_function& _behavior = behavior_function(), 
		const behavior_function& _entry_behavior = behavior_function(),
		const behavior_function& _exit_behavior = behavior_function() ) SX_OVERRIDE;
	virtual simple_state& add_simple_state( const std::string& _simple_state_name, const event_ids& _deferred_events,
		const behavior_function& _behavior = behavior_function(), 
		const behavior_function& _entry_behavior = behavior_function(), 
		const behavior_function& _exit_behavior = behavior_function(),
		event_sptr _error_event = event_sptr() ) SX_OVERRIDE;
	virtual simple_state& add_async_simple_state( const std::string& _async_simple_state_name, 
		const event_ids& _deferred_events, async_behavior_uptr _do_action = async_behavior_uptr(), 
		const behavior_function& _entry_behavior = behavior_function(),
		const behavior_function& _exit_behavior = behavior_function(), 
		event_sptr _error_event = event_sptr() ) SX_OVERRIDE;
	virtual composite_state& add_composite_state( const std::string& _composite_state_name,
		const behavior_function& _entry_action = behavior_function(), 
		const behavior_function& _exit_action = behavior_function() ) SX_OVERRIDE;
	virtual composite_state& add_composite_state( const std::string& _composite_state_name, 
		const event_ids& _deferred_events, const behavior_function& _entry_action = behavior_function(), 
		const behavior_function& _exit_action = behavior_function() ) SX_OVERRIDE;
	virtual final_state& add_final_state( const std::string& _name ) SX_OVERRIDE;
	virtual choice& add_choice( choice_uptr _choice ) SX_OVERRIDE;

	//!\brief Creates a choice with the given name and adds it to the parent region.
	//!\param _choice_name Name of the choice. 
	//!\return A reference to the newly created choice.
	virtual choice& add_choice( const std::string& _choice_name ) SX_OVERRIDE;
	virtual fork& add_fork( fork_uptr _fork ) SX_OVERRIDE;

 //!\brief Creates a fork with the given name and adds it to the parent region.
 //!\param _fork_name Name of the fork. 
 //!\return A reference to the newly created fork.
 virtual fork& add_fork( const std::string& _fork_name ) SX_OVERRIDE;
 virtual join& add_join( join_uptr _join ) SX_OVERRIDE;

 //!\brief Creates a join with the given name and adds it to the parent region.
 //!\param _join_name Name of the join.
 //!\return A reference to the newly created join.
 virtual join& add_join( const std::string& _join_name ) SX_OVERRIDE;
 virtual junction& add_junction( junction_uptr _junction ) SX_OVERRIDE;

 //!\brief Creates a junction with the given name and adds it to the parent region.
 //!\param _junction_name Name of the junction. 
 //!\return A reference to the newly created junction.
	virtual junction& add_junction( const std::string& _junction_name ) SX_OVERRIDE;
	virtual terminate_pseudostate& add_terminate_pseudostate( 
	 terminate_pseudostate_uptr _terminate_pseudostate ) SX_OVERRIDE;

 //!\brief Creates a terminate pseudostate with the given name and adds it to the parent region.
 //!\param _terminate_pseudostate_name Name of the terminate pseudostate. 
 //!\return A reference to the newly created terminate pseudostate.
	virtual terminate_pseudostate& add_terminate_pseudostate( 
		const std::string& _terminate_pseudostate_name ) SX_OVERRIDE;
	uri get_uri() const SX_OVERRIDE;
	void add_ancestor_uri ( uri& _uri ) const SX_OVERRIDE;
	virtual bool is_active_state_final () const SX_OVERRIDE;
	virtual bool check( state_machine_defects& _defects ) const SX_OVERRIDE;
	virtual const state_machine_element * get_parent() const SX_OVERRIDE;


private: 
	composite_state* parent_state_;
	states states_;
	pseudostates pseudostates_;
	initial_pseudostate* initial_pseudostate_;
	state* active_state_;
	state* last_active_state_;
};


}


#endif
