//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef COMPOSITE_STATE_MODEL_3486C4FF_7607_4948_B81E_542780DEAAA6
#define COMPOSITE_STATE_MODEL_3486C4FF_7607_4948_B81E_542780DEAAA6


#include "state_model.hpp"
#include "composite_state_model_fwd.hpp"
#include "pseudostate_model_fwd.hpp"
#include "region_model_fwd.hpp"


namespace sxy
{


namespace model
{


//!\interface composite_state_model
//!\brief Interface for a composite state in the model.
class composite_state_model: 
	public virtual state_model
{


public:
	composite_state_model()
	{
		// Nothing to do...
	}


	virtual ~composite_state_model() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY( composite_state_model )
	virtual const std::string& get_enter_behavior() const = 0;
	virtual void set_enter_behavior( const std::string& _enter_behavior ) = 0;
	virtual const std::string& get_exit_behavior() const = 0;
	virtual void set_exit_behavior( const std::string& _exit_behavior ) = 0;
	virtual void add_region( region_model_uptr _region ) = 0;
	virtual raw_const_pseduostate_models get_state_pseudostates() const = 0;
	virtual void add_state_pseudostate( pseudostate_model_uptr _pseudostate ) = 0;
};


}


}


#endif
