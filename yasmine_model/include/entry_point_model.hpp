//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ENTRY_POINT_MODEL_6D3516CB_20CF_476F_A80D_A4C97BFCD281
#define ENTRY_POINT_MODEL_6D3516CB_20CF_476F_A80D_A4C97BFCD281


#include "pseudostate_model.hpp"
#include "entry_point_model_fwd.hpp"


namespace sxy
{


namespace model
{


//!\interface entry_point_model
//!\brief Interface for an entry point pseudostate in the model.
class entry_point_model: public virtual pseudostate_model
{
public:
	entry_point_model()
	{
		// Nothing to do...
	}


	virtual ~entry_point_model() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY( entry_point_model )
};


}


}


#endif
