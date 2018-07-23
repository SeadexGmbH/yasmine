//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PSEUDOSTATE_MODEL_D08608A5_1FE4_41BC_9E9F_AE335AE13969
#define PSEUDOSTATE_MODEL_D08608A5_1FE4_41BC_9E9F_AE335AE13969


#include "state_machine_element_model.hpp"
#include "pseudostate_model_fwd.hpp"
#include "transition_model_fwd.hpp"


namespace sxy
{


namespace model
{


class model_vertex_visitor;


//!\interface pseudostate_model
//!\brief Interface for a pseudostate in the model.
class pseudostate_model: public virtual state_machine_element_model
{
public:
	pseudostate_model()
	{
		// Nothing to do...
	}


	virtual ~pseudostate_model() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do...
	}


	virtual raw_const_transition_models get_incoming_transitions() const = 0;
	virtual void add_incoming_transition( transition_models _incoming_transition ) = 0;
	virtual raw_const_transition_models get_outgoing_transitions() const = 0;
	virtual void add_outgoing_transition( transition_models _outgoing_transition ) = 0;
	virtual void accept( model_vertex_visitor& _constructor_visitor ) const = 0;
};


}
}


#endif
