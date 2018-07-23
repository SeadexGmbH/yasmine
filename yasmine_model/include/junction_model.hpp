//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef JUNCTION_MODEL_F486D1A4_FE05_4FBF_9E00_F69FBFCC70B2
#define JUNCTION_MODEL_F486D1A4_FE05_4FBF_9E00_F69FBFCC70B2


#include "pseudostate_model.hpp"
#include "junction_model_fwd.hpp"


namespace sxy
{


namespace model
{


//!\interface junction_model
//!\brief Interface for a junction pseudostate in the model.
class junction_model: public virtual pseudostate_model
{
public:
	junction_model()
	{
		// Nothing to do...
	}


	virtual ~junction_model() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY( junction_model )
};


}


}


#endif
