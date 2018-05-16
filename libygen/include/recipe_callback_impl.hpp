//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef RECIPE_CALLBACK_IMPL_A5F81CB3_58BB_4506_908B_49FCBF0C519C
#define RECIPE_CALLBACK_IMPL_A5F81CB3_58BB_4506_908B_49FCBF0C519C


#include <map>
#include <stack>
#include <vector>

#include "recipe_callback.hpp"
#include "behavior_struct.hpp"


namespace sxy
{


namespace model
{


	class state_machine_model;
	class composite_state_model;
	class region_model;
	class state_model;


}


class recipe_callback_impl SX_FINAL:
	public sx::genesis::recipe_callback
{
public:
	explicit recipe_callback_impl( const sxy::model::state_machine_model& _state_machine_model,
		std::vector<std::string> _namespaces, std::vector<std::string> _behavior_classes,
		std::string _state_machine_name, std::string _state_machine_type );
	virtual ~recipe_callback_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( recipe_callback_impl )
	virtual std::string get_variable_content( const std::string& _variable_name ) SX_OVERRIDE;
	virtual void before_loop( const std::string& _loop_name ) SX_OVERRIDE;
	virtual void before_loop_iteration( const std::string& _loop_name ) SX_OVERRIDE;
	virtual void after_loop_iteration( const std::string& _loop_name ) SX_OVERRIDE;
	virtual bool check_loop_condition( const std::string& _loop_name ) const SX_OVERRIDE;
	virtual void after_loop( const std::string& _loop_name ) SX_OVERRIDE;
	virtual bool check_condition( const std::string& _condition_name ) const SX_OVERRIDE;
	virtual void condition_begin( const std::string& _condition_name ) SX_OVERRIDE;
	virtual void condition_end( const std::string& _condition_name ) SX_OVERRIDE;
	virtual int get_switch_case( const std::string& _switch_name ) SX_OVERRIDE;


private:
	std::string get_state_property( const std::string& _property ) const;
	std::string get_pseudostate_property( const std::string& _property ) const;
	std::string get_state_pseudostate_property( const std::string& _property ) const;
	std::string get_event_property( const std::string& _property ) const;
	std::string get_date_time_string() const;
	std::string get_transition_events() const;
	void fill_struct( const std::string& _loop_name );
	void fill_one_behavior_struct( behavior_struct& _behavior, const std::string& _behavior_string );
	static int get_index( const behavior_struct& _behavior_struct );


	const sxy::model::state_machine_model& state_machine_model_;
	std::map<const std::string, const std::string> map_of_values_;
	std::vector<std::string> namespaces_;
	std::vector<std::string> behavior_classes_;
	std::size_t namespace_index_;
	std::size_t behavior_classes_index_;
	std::size_t transition_index_;
	std::size_t pseudostate_index_;
	std::size_t state_pseudostate_index_;
	std::stack<const sxy::model::state_model*> composite_states_stack_;
	std::stack<const sxy::model::region_model*> regions_stack_;
	std::stack<std::size_t> composite_states_index_stack_;
	std::stack<std::size_t> regions_index_stack_;	
	std::size_t event_index_;
	behavior_struct entry_behavior_;
	behavior_struct do_behavior_;
	behavior_struct exit_behavior_;
	behavior_struct transition_guard_;
	std::string active_switch_;
};


}


#endif
