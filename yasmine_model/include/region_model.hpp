//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef REGION_MODEL_54D9A6B5_527D_4ECE_959C_2DD711919B25
#define REGION_MODEL_54D9A6B5_527D_4ECE_959C_2DD711919B25


#include "state_machine_element_model.hpp"
#include "region_model_fwd.hpp"
#include "state_model_fwd.hpp"
#include "pseudostate_model_fwd.hpp"


namespace sxy
{


namespace model
{


//!\interface region_model
//!\brief Interface for a region in the model.
class region_model: 
	public virtual state_machine_element_model
{
public:
	region_model()
	{
		// Nothing to do...
	}


	virtual ~region_model() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY( region_model )
	virtual row_const_state_models get_states() const = 0;
	virtual void add_state( state_model_uptr _state ) = 0;
	virtual raw_const_pseduostate_models get_pseudostates() const = 0;
	virtual void add_pseudostate( pseudostate_model_uptr _region_pseudostate ) = 0;
};


}


}


#endif
