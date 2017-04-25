//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TRANSITION_MODEL_6ACABA37_E084_4091_8DAE_51878E9A3D54
#define TRANSITION_MODEL_6ACABA37_E084_4091_8DAE_51878E9A3D54


#include "state_machine_element_model.hpp"
#include "transition_model_fwd.hpp"
#include "transition_model_kind.hpp"
#include "event_model.hpp"


namespace sxy
{


namespace model
{


//!\interface transition_model
//!\brief Interface for a transition in the model.
class transition_model: public virtual state_machine_element_model
{
public:
	transition_model()
	{
		// Nothing to do...
	}


	virtual ~transition_model() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	SX_NO_COPY( transition_model )
	virtual transition_model_kind get_kind() const = 0;
	virtual const std::string& get_behavior() const = 0;
	virtual const std::string& get_guard() const = 0;
	virtual const sxe::uri& get_source() const = 0;
	virtual const sxe::uri& get_target() const = 0;
	virtual const event_ids& get_event_ids() const = 0;
};


}


}


#endif
