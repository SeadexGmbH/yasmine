//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef EXIT_POINT_MODEL_DE3EF1F0_F25E_4350_A872_1D9C37669EF0
#define EXIT_POINT_MODEL_DE3EF1F0_F25E_4350_A872_1D9C37669EF0


#include "pseudostate_model.hpp"
#include "exit_point_model_fwd.hpp"


namespace sxy
{


namespace model
{


//!\interface exit_point_model
//!\brief Interface for an exit point pseudostate in the model.
class exit_point_model: public virtual pseudostate_model
{
public:
	exit_point_model()
	{
		// Nothing to do...
	}


	virtual ~exit_point_model() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY( exit_point_model )
};


}


}


#endif
