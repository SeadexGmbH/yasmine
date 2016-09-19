//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef REGION_IMPL_DDA92905_6CBE_4061_8DA1_4E6C1E98E11A
#define REGION_IMPL_DDA92905_6CBE_4061_8DA1_4E6C1E98E11A


#include "region.h"
#include "state_machine_element_impl.h"


namespace sxy
{


class region_impl final: 
	public virtual region, public state_machine_element_impl
{
public:
	explicit region_impl( const std::string& _name ); 
	virtual ~region_impl() override; 
	region_impl( const region_impl& ) = delete; 
	region_impl& operator=( const region_impl& ) = delete;
	void set_parent_state( composite_state* const _composite_state ) override;
	virtual raw_const_states get_states() const override;
	virtual const composite_state& get_parent_state() const override;
	virtual composite_state& get_parent_state() override;
	virtual vertex* get_vertex( const std::string& _vertex_name ) const override;
	virtual size_t get_pseudostate_count() const override;
	virtual vertex* get_pseudostate( const std::string& _name ) const override;
	virtual raw_const_pseudostates get_pseudostates() const override;
	virtual initial_pseudostate* get_initial_pseudostate() const override;
	virtual size_t get_state_count() const override;
	virtual state* get_state( const std::string& _name ) const override; 
	virtual const state* get_active_state() const override;
	virtual state* get_active_state() override;
	virtual void set_active_state( state* const _active_state ) override;
	virtual void set_state_was_active( state* const _active_state ) override;
	virtual const state* get_last_active_state() const override;
	virtual state* get_last_active_state() override;
	virtual initial_pseudostate& add_initial_pseudostate( initial_pseudostate_uptr _initial_state ) override;

	//!\brief Creates an initial pseudostate with the given name and adds it to the parent region.
	//!\param _initial_state_name Name of the initial pseudostate. 
	//!\return A reference to the newly created initial pseudostate.
	virtual initial_pseudostate& add_initial_pseudostate( const std::string& _initial_state_name ) override;
	virtual state& add_state( state_uptr _state ) override;
	virtual simple_state& add_simple_state( const std::string& _name, 
		const behavior_function& _behavior = behavior_function(), 
		const behavior_function& _entry_behavior = behavior_function(),
		const behavior_function& _exit_behavior = behavior_function() ) override;
	virtual simple_state& add_simple_state( const std::string& _name, const event_ids& _deferred_events,
		const behavior_function& _behavior = behavior_function(), 
		const behavior_function& _entry_behavior = behavior_function(), 
		const behavior_function& _exit_behavior = behavior_function(),
		behavior_exception_uptr _error_event = nullptr ) override;
	virtual simple_state& add_async_simple_state( const std::string& _name, const event_ids& _deferred_events,
		async_behavior_uptr _do_action = nullptr, const behavior_function& _entry_behavior = behavior_function(),
		const behavior_function& _exit_behavior = behavior_function(), 
		behavior_exception_uptr _error_event = nullptr ) override;
	virtual composite_state& add_composite_state( const std::string& _name, 
		const behavior_function& _entry_action = behavior_function(), 
		const behavior_function& _exit_action = behavior_function() ) override;
	virtual composite_state& add_composite_state( const std::string& _name, const event_ids& _deferred_events, 
		const behavior_function& _entry_action = behavior_function(), 
		const behavior_function& _exit_action = behavior_function() ) override;
	virtual final_state& add_final_state( const std::string& _name ) override;
	virtual choice& add_choice( choice_uptr _choice ) override;

	//!\brief Creates a choice with the given name and adds it to the parent region.
	//!\param _choice_name Name of the choice. 
	//!\return A reference to the newly created choice.
	virtual choice& add_choice( const std::string& _choice_name ) override;
	virtual fork& add_fork( fork_uptr _fork ) override;

 //!\brief Creates a fork with the given name and adds it to the parent region.
 //!\param _fork_name Name of the fork. 
 //!\return A reference to the newly created fork.
 virtual fork& add_fork( const std::string& _fork_name ) override;
 virtual join& add_join( join_uptr _join ) override;

 //!\brief Creates a join with the given name and adds it to the parent region.
 //!\param _join_name Name of the join.
 //!\return A reference to the newly created join.
 virtual join& add_join( const std::string& _join_name ) override;
 virtual junction& add_junction( junction_uptr _junction ) override;

 //!\brief Creates a junction with the given name and adds it to the parent region.
 //!\param _junction_name Name of the junction. 
 //!\return A reference to the newly created junction.
	virtual junction& add_junction( const std::string& _junction_name ) override;
	virtual terminate_pseudostate& add_terminate_pseudostate( 
	 const terminate_pseudostate_uptr _terminate_pseudostate ) override;

 //!\brief Creates a terminate pseudostate with the given name and adds it to the parent region.
 //!\param _terminate_pseudostate_name Name of the terminate pseudostate. 
 //!\return A reference to the newly created terminate pseudostate.
	virtual terminate_pseudostate& add_terminate_pseudostate( 
		const std::string& _terminate_pseudostate_name ) override;
	uri get_uri() const override;
	void add_ancestor_uri ( uri& _uri ) const override;
	virtual bool is_active_state_final () const override;
	virtual bool check( state_machine_defects& _defects ) const override;


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
