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
	//!\brief Add a state to the region.
	void add_state( state_model_uptr _state ) SX_OVERRIDE;
	//!\brief Get the list of pseudostates of the region.
	raw_const_pseduostate_models get_pseudostates() const SX_OVERRIDE;
	//!\brief Add a pseudostate to the region.
	void add_pseudostate( pseudostate_model_uptr _region_pseudostate ) SX_OVERRIDE;


private:
	state_models_uptr states_;
	pseudostate_models_uptr pseudostates_;
};


}


}


#endif
