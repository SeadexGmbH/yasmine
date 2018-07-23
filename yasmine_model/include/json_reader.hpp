//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef JSON_READER_B84EDCFB_85B6_4060_971F_96D6FB6D87B7
#define JSON_READER_B84EDCFB_85B6_4060_971F_96D6FB6D87B7

#include <cstdlib>

#include "essentials/non_copyable.hpp"
#include "essentials/uri.hpp"

#include "rapidjson_document.hpp"

#include "consts.hpp"
#include "transition_model_kind.hpp"
#include "region_model_fwd.hpp"
#include "pseudostate_model_fwd.hpp"
#include "state_machine_model_fwd.hpp"
#include "state_model_fwd.hpp"
#include "composite_state_model_fwd.hpp"
#include "simple_state_model_fwd.hpp"
#include "final_state_model_fwd.hpp"
#include "initial_pseudostate_model_fwd.hpp"
#include "terminate_pseudostate_model_fwd.hpp"
#include "join_model_fwd.hpp"
#include "fork_model_fwd.hpp"
#include "choice_model_fwd.hpp"
#include "junction_model_fwd.hpp"
#include "entry_point_model_fwd.hpp"
#include "exit_point_model_fwd.hpp"
#include "deep_history_model_fwd.hpp"
#include "shallow_history_model_fwd.hpp"
#include "transition_model_fwd.hpp"
#include "json_parser_helper.hpp"
#include "event_model.hpp"
#include "externals_fwd.hpp"


namespace sxy
{


namespace model
{
	class state_machine_element_model_impl;
}


//!\class json_reader
//!\brief Provides the ability to read an yasmine model from a JSON file (.ym).
class json_reader SX_FINAL
{
public:
	//!\brief Constructor. An essentials exception (sxe::exception) is thrown if reading of the json fails.
	//!\param _file JSON file containing the model description.
	explicit json_reader( const std::string& _file );
	~json_reader() SX_NOEXCEPT;
	SX_NO_COPY(json_reader)
	//!\brief Retrieve the read model.
	//!\return Pointer to the model.
	model::state_machine_model_ptr get_model_ptr();
	const model::external_vertices& get_external_vertices();


private:
	void read_externals();
	void read_json_file( const std::string& _file );
	model::state_machine_model_ptr read_into_model();
	sxy::model::event_ids read_deferred_events( const rapidjson::Value& _state ) const;
	sxy::model::event_ids read_error_events( const rapidjson::Value& _state ) const;
	model::composite_state_model_uptr read_composite_state( const rapidjson::Value& _root );
	model::simple_state_model_uptr read_simple_state( const rapidjson::Value& _state, bool _is_async = false );
	model::final_state_model_uptr read_final_state( const rapidjson::Value& _state );
	model::region_model_impl_uptr read_region( const rapidjson::Value& _region );
	model::state_model_uptr read_state( const rapidjson::Value& _state );
	model::pseudostate_model_uptr read_state_pseudostate( const rapidjson::Value& _state_pseudostate );
	model::pseudostate_model_uptr read_pseudostate( const rapidjson::Value& _pseudostate );
	model::initial_pseudostate_model_uptr read_initial_pseudostate( const rapidjson::Value& _pseudostate );
	model::join_model_uptr read_join( const rapidjson::Value& _pseudostate );
	model::fork_model_uptr read_fork( const rapidjson::Value& _pseudostate );
	model::choice_model_uptr read_choice( const rapidjson::Value& _pseudostate );
	model::junction_model_uptr read_junction( const rapidjson::Value& _pseudostate );
	model::terminate_pseudostate_model_uptr read_terminate_pseudostate( const rapidjson::Value& _pseudostate );
	model::deep_history_model_uptr read_deep_history( const rapidjson::Value& _pseudostate );
	model::shallow_history_model_uptr read_shallow_history( const rapidjson::Value& _pseudostate );
	model::entry_point_model_uptr read_entry_point( const rapidjson::Value& _pseudostate );
	model::exit_point_model_uptr read_exit_point( const rapidjson::Value& _pseudostate );
	model::transition_model_uptr read_transition( const rapidjson::Value& _transition );
	static sxy::model::transition_model_kind get_transition_kind( sxe::int64_t _kind );
	sxe::int32_t get_event_id_by_name( const std::string& _name ) const;
	std::string get_event_name( const sxe::int32_t _event_id ) const;
	sxe::int8_t get_event_priority_by_name( const std::string& _name ) const;
	void get_event_list( model::state_machine_model_ptr& _model );
	void check_document() const;
	
	template< typename pseudostate_impl >
	sxe::SX_UNIQUE_PTR< pseudostate_impl > function_read_pseudostate( const rapidjson::Value& _pseudostate )
	{
		const std::string pseudostate_name = get_object_member_string( sxe::ref( _pseudostate ), model::JSON_NAME_NODE );
		sxe::SX_UNIQUE_PTR< pseudostate_impl > new_pseudostate =
			SX_MAKE_UNIQUE< pseudostate_impl >( pseudostate_name );
		return( new_pseudostate );
	}


	rapidjson::Document document_;
	model::state_machine_model_ptr model_;
};


}


#endif
