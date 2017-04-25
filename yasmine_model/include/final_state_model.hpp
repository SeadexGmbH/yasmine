//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef FINAL_STATE_MODEL_418502AE_CCF1_4713_90D0_2335AF26A3B7
#define FINAL_STATE_MODEL_418502AE_CCF1_4713_90D0_2335AF26A3B7


#include "state_model.hpp"
#include "final_state_model_fwd.hpp"


namespace sxy
{


namespace model
{



//!\interface final_state_model
//!\brief Interface for a final state in the model.
class final_state_model: 
	public virtual state_model
{


public:
	final_state_model()
	{
		// Nothing to do...
	}


	virtual ~final_state_model() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY( final_state_model )
};


}


}


#endif
