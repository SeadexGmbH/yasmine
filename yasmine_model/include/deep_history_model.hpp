//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef DEEP_HISTORY_MODEL_8B24A7EC_863C_4FFE_9E08_00CF3CD6E083
#define DEEP_HISTORY_MODEL_8B24A7EC_863C_4FFE_9E08_00CF3CD6E083


#include "pseudostate_model.hpp"


namespace sxy
{


namespace model
{


//!\interface deep_history_model
//!\brief Interface for a deep history pseudostate in the model.
class deep_history_model: public virtual pseudostate_model
{
public:
	deep_history_model()
	{
		// Nothing to do...
	}


	virtual ~deep_history_model() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY( deep_history_model )
};


}


}


#endif
