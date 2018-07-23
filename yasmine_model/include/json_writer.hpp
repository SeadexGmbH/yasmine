//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef JSON_WRITER_F29233A0_535E_4285_AE04_E0E163819CB2
#define JSON_WRITER_F29233A0_535E_4285_AE04_E0E163819CB2


#include <vector>

#include "rapidjson_document.hpp"
#include "state_machine_model.hpp"


namespace sxy
{


namespace model
{


class state_machine_element_model;
class transition_model_impl;
class simple_state_model;
class pseudostate_model_impl;
class pseudostate_model;
class region_model;
class composite_state_model;
class final_state_model;


}


//!\class json_writer
//!\brief Provides the ability to write a model to a file.
class json_writer SX_FINAL
{
public:
	//!\brief Constructor. Writes the model into a .ym file (JSON). An essentials exception (sxe::exception) is thrown if the write fails.
	//!\param _json_file_name Name of the output file.
	//!\param _state_machine_model The state machine model that shall be written.
	json_writer( const std::string & _json_file_name, const model::state_machine_model &_state_machine_model );
	~json_writer() SX_NOEXCEPT;
	SX_NO_COPY( json_writer )


private:
	void write_json_to_file( const std::string& _json_file, const model::state_machine_model& _state_machine_model );
	// cppcheck-suppress unusedPrivateFunction
	static void write_text_to_file( const char* _json_char, const std::string& _json_file );
	static void add_version( rapidjson::Value& _document, rapidjson::MemoryPoolAllocator< >& _allocator );
	static void add_events_from_model( const model::state_machine_model& _state_machine_model,
		rapidjson::Value& _events, rapidjson::MemoryPoolAllocator< >& _allocator );
	// cppcheck-suppress unusedPrivateFunction
	static void add_transitions_from_model( const model::state_machine_model& _state_machine_model,
		rapidjson::Value& _transitions, rapidjson::MemoryPoolAllocator< >& _allocator );
	static void add_regions_from_model( const model::composite_state_model& _composite_state_model,
		rapidjson::Value& _regions, rapidjson::MemoryPoolAllocator< >& _allocator,
		const model::state_machine_model& _state_machine_model );
	static void fill_region_object( const model::region_model& _region_model, rapidjson::Value& _region,
		rapidjson::MemoryPoolAllocator< >& _allocator, const model::state_machine_model& _state_machine_model );
	static void fill_pseudostate_object( const model::pseudostate_model& _pseudostate_model, rapidjson::Value& _pseudostate,
		rapidjson::MemoryPoolAllocator< >& _allocator );
	static void fill_simple_state_object( const model::simple_state_model& _simple_state_model, rapidjson::Value& _simple_state,
		rapidjson::MemoryPoolAllocator< >& _allocator, const model::state_machine_model& _state_machine_model );
	static void fill_composite_state_object( const model::composite_state_model& _composite_state_model,
		rapidjson::Value& _composite_state, rapidjson::MemoryPoolAllocator< >& _allocator,
		const model::state_machine_model& _state_machine_model );
	static void fill_final_state_object( const model::final_state_model& _final_state_model,
		rapidjson::Value& _final_state, rapidjson::MemoryPoolAllocator< >& _allocator );
	static void add_state_pseudostates_from_model( const model::composite_state_model& _composite_state_model,
		rapidjson::Value& _state_pseudostates, rapidjson::MemoryPoolAllocator< >& _allocator );
	static rapidjson::Value& create_rapidjson_string_value( const std::string& _string, 
		rapidjson::Value& _json_string_value );
	static void fill_base_info( rapidjson::Value& _json_val, const model::state_machine_element_model& _element,
		rapidjson::MemoryPoolAllocator< >& _allocator );
	static const std::string get_event_name_by_id( const sxy::model::event_id& _event_id,
		const model::state_machine_model& _state_machine_model );
	static const size_t get_event_index_by_id( const sxy::model::event_id& _event_id,
		const model::state_machine_model& _state_machine_model );
	void add_externals( const model::state_machine_model& _state_machine_model, rapidjson::Value& _document,
		rapidjson::MemoryPoolAllocator< >& _allocator );
};


}


#endif
