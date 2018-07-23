//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef JOIN_MODEL_925E12E6_260B_4B8C_99D1_454D32458D0C
#define JOIN_MODEL_925E12E6_260B_4B8C_99D1_454D32458D0C


#include "pseudostate_model.hpp"
#include "join_model_fwd.hpp"


namespace sxy
{


namespace model
{


//!\interface join_model
//!\brief Interface for a join pseudostate in the model.
class join_model: public virtual pseudostate_model
{
public:
	join_model()
	{
		// Nothing to do...
	}


	virtual ~join_model() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY( join_model )
};


}


}


#endif
