//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef FORK_MODEL_A7E3D550_1A3B_4DA6_B381_9988647E9915
#define FORK_MODEL_A7E3D550_1A3B_4DA6_B381_9988647E9915


#include "pseudostate_model.hpp"
#include "fork_model_fwd.hpp"


namespace sxy
{


namespace model
{


//!\interface fork_model
//!\brief Interface for a fork pseudostate in the model.
class fork_model: public virtual pseudostate_model
{
public:
	fork_model()
	{
		// Nothing to do...
	}


	virtual ~fork_model() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY( fork_model )
};


}


}


#endif
