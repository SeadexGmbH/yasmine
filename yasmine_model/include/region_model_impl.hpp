//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef REGION_MODEL_IMPL_2907B5BB_8F99_4B72_94E1_AFA0D1F8106E
#define REGION_MODEL_IMPL_2907B5BB_8F99_4B72_94E1_AFA0D1F8106E


#include "region_model.hpp"
#include "state_machine_element_model_impl.hpp"


namespace sxy
{


namespace model
{


//!\class region_model_impl
//!\brief A region in the model.
class region_model_impl SX_FINAL:
	public virtual region_model, public state_machine_element_model_impl
{
public:
	//!\brief Constructor.
	//!\param _name Name of the region.
	explicit region_model_impl( const std::string& _name );
	virtual ~region_model_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( region_model_impl )

	//!\brief Get the list of the states of the region.
	row_const_state_models get_states() const SX_OVERRIDE;

	//!\brief Get the number of states in the region.
	virtual const size_t get_states_count() const SX_OVERRIDE;

	//!\brief Get the state with the given index.
	virtual state_model& get_state( const size_t _index ) SX_OVERRIDE;

	//!\brief Add a state to the region.
	virtual void add_state( state_model_uptr _state ) SX_OVERRIDE;

	//!\brief Remove the state with the given index from the region.
	virtual void remove_state( const size_t _index ) SX_OVERRIDE;

	//!\brief Get the list of pseudostates in the region.
	virtual raw_const_pseduostate_models get_pseudostates() const SX_OVERRIDE;

	//!\brief Get the number of pseudostates in the region.
	virtual const size_t get_pseudostates_count() const SX_OVERRIDE;

	//!\brief Get the pseudostate in the region with the given index.
	virtual pseudostate_model& get_pseudostate( const size_t _index ) SX_OVERRIDE;

	//!\brief Add a pseudostate to the region.
	void add_pseudostate( pseudostate_model_uptr _region_pseudostate ) SX_OVERRIDE;

	//!\brief Remove the pseudostate with the given index from the region.
	virtual void remove_pseudostate( const size_t _index ) SX_OVERRIDE;

	//!\brief Get the child element with the given uri.
	//!\param _uri Uri of the searched element.
	//!\return Pointer to the searched element.
	//!\exception Throws sxy::model::exception if the element does not exists.
	virtual state_machine_element_model* get_child( const sxe::uri& _uri ) SX_OVERRIDE;

	virtual void accept_delete_visitor( delete_visitor& _delete_visitor ) SX_OVERRIDE;


private:
	state_models_uptr states_;
	pseudostate_models_uptr pseudostates_;
};


}


}


#endif
