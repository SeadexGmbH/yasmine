//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef COMPOSITE_STATE_MODEL_IMPL_EAF5C6B0_9341_4872_B701_0283A0FE433E
#define COMPOSITE_STATE_MODEL_IMPL_EAF5C6B0_9341_4872_B701_0283A0FE433E


#include "composite_state_model.hpp"
#include "state_model_impl.hpp"


namespace sxy
{


namespace model
{


//!\class composite_state_model_impl
//!\brief A composite state in the model.
class composite_state_model_impl SX_FINAL: 
	public composite_state_model, public state_model_impl
{


public:
	//!\brief Constructor.
	//!\param _name  Name of the composite state.
	//!\param _enter_behavior Entry behavior of the composite state.
	//!\param _exit_bahvior Exit behavior of the composite state.
	//!\param _deferred_events List of IDs of deferred event.
	explicit  composite_state_model_impl( const std::string& _name, const std::string& _enter_behavior = "",
		const std::string& _exit_behavior = "", const event_ids& _deferred_events = event_ids() );
	virtual ~composite_state_model_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( composite_state_model_impl )
	virtual const std::string& get_do_behavior() const SX_OVERRIDE;
	virtual void set_do_behavior( const std::string& _do_behavior ) SX_OVERRIDE;

	//!\brief Get the entry behavior of the composite state.
	virtual const std::string& get_enter_behavior() const SX_OVERRIDE;

	//!\brief Set the entry behavior of the composite state.
	void set_enter_behavior( const std::string& _enter_behavior ) SX_OVERRIDE;

	//!\brief Get the exit behavior of the composite state.
	virtual const std::string& get_exit_behavior() const SX_OVERRIDE;

	//!\brief Set the exit behavior of the composite state.
	void set_exit_behavior( const std::string& _exit_behavior ) SX_OVERRIDE;

	//!\brief Get the regions of the composite state.
	virtual const raw_const_region_models get_regions() const SX_OVERRIDE;

	//!\brief Get the number of regions in the composite state.
	virtual const size_t get_regions_count() const SX_OVERRIDE;

	//!\brief Get the region of the composite state with the given index.
	virtual region_model& get_region( const size_t _index ) SX_OVERRIDE;

	//!\brief Add a region to the list of regions of the composite state.
	virtual void add_region( region_model_uptr _region ) SX_OVERRIDE;

	//!\brief Remove the region with the given index.
	virtual void remove_region( const size_t _index ) SX_OVERRIDE;

	//!\brief Get the state pseudostates of the composite state.
	virtual raw_const_pseduostate_models get_state_pseudostates() const SX_OVERRIDE;

	//!\brief Get the number of state pseudostates of the composite state.
	virtual const size_t get_state_pseudostates_count() const SX_OVERRIDE;
	
	//!\brief Get the state pseudostate with the given index.
	virtual pseudostate_model& get_state_pseudostate( const size_t _index ) SX_OVERRIDE;

	//!\brief Add a state pseudostate to the list of the state pseudostates of the composite state.
	virtual void add_state_pseudostate( pseudostate_model_uptr _pseudostate ) SX_OVERRIDE;

	//!\brief Remove the state pseudostate with the given index.
	virtual void remove_state_pseudostate( const size_t _index ) SX_OVERRIDE;

	//!\brief Get the child element with the given uri.
	//!\param _uri Uri of the requested element.
	//!\return Pointer to the requested element.
	//!\exception Throws sxy::model::exception if the element does not exists.
	virtual state_machine_element_model* get_child( const sxe::uri& _uri ) SX_OVERRIDE;

	//!\brief Get list of that defer the given event.
	//!\param _elements List of elements to be filled.
	//!\param _event Deferred event.
	virtual void get_event_references( std::vector<sxy::model::state_machine_element_model* >& _elements,
		const event_sptr _event ) SX_OVERRIDE;

	virtual void accept( model_vertex_visitor& _constructor_visitor ) const SX_OVERRIDE;
	virtual void accept_delete_visitor( delete_visitor& _delete_visitor ) SX_OVERRIDE;


private:
	std::string enter_behavior_;
	const std::string do_behavior_;
	std::string exit_behavior_;
	region_models_uptr regions_;
	pseudostate_models_uptr state_pseudostates_;
};


}

}


#endif
