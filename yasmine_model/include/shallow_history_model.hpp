//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SHALLOW_HISTORY_MODEL_A6D474FF_C5C7_4608_8645_099C8B3521EE
#define SHALLOW_HISTORY_MODEL_A6D474FF_C5C7_4608_8645_099C8B3521EE


#include "pseudostate_model.hpp"
#include "shallow_history_model_fwd.hpp"


namespace sxy
{


namespace model
{


//!\interface shallow_history_model
//!\brief Interface for a shallow history pseudostate in the model.
class shallow_history_model: public virtual pseudostate_model
{
public:
	shallow_history_model()
	{
		// Nothing to do...
	}


	virtual ~shallow_history_model() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY( shallow_history_model )
};


}


}


#endif
