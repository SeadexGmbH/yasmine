//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef INITIAL_PSEUDOSTATE_MODEL_32EC2305_FEBD_4F09_A6DB_4E9C79B7172B
#define INITIAL_PSEUDOSTATE_MODEL_32EC2305_FEBD_4F09_A6DB_4E9C79B7172B


#include "pseudostate_model.hpp"
#include "initial_pseudostate_model_fwd.hpp"


namespace sxy
{


namespace model
{


//!\interface initial_pseudostate_model
//!\brief Interface for an initial pseudostate int the model.
class initial_pseudostate_model: public virtual pseudostate_model
{
public:
	initial_pseudostate_model()
	{
		// Nothing to do...
	}


	virtual ~initial_pseudostate_model() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY( initial_pseudostate_model )
};


}


}


#endif
