//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CHOICE_MODEL_D643AB58_F738_4961_8DD3_A6A6D2CD55BB
#define CHOICE_MODEL_D643AB58_F738_4961_8DD3_A6A6D2CD55BB


#include "pseudostate_model.hpp"
#include "choice_model_fwd.hpp"


namespace sxy
{


namespace model
{


//!\interface chice_model
//!\brief Interface for a choice pseudostate in the model.
class choice_model: public virtual pseudostate_model
{
public:
	choice_model()
	{
		// Nothing to do...
	}


	virtual ~choice_model() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	SX_NO_COPY( choice_model )
};


}


}


#endif
