//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TERMINATE_PSEUDOSTATE_MODEL_97493430_4F5E_4EA7_B152_E1E38C11C470
#define TERMINATE_PSEUDOSTATE_MODEL_97493430_4F5E_4EA7_B152_E1E38C11C470


#include "pseudostate_model.hpp"
#include "terminate_pseudostate_model_fwd.hpp"


namespace sxy
{


namespace model
{


//!\interface terminate_pseudostate_model
//!\brief Interface for a terminate pseudostate in the model.
class terminate_pseudostate_model: public virtual pseudostate_model
{
public:
	terminate_pseudostate_model()
	{
		// Nothing to do...
	}


	virtual ~terminate_pseudostate_model() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY( terminate_pseudostate_model )


private:
};


}


}


#endif
