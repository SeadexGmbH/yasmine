//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PSEUDOSTATE_MODEL_IMPL_5B405971_4677_4872_9BD7_1AC88418E022
#define PSEUDOSTATE_MODEL_IMPL_5B405971_4677_4872_9BD7_1AC88418E022


#include "pseudostate_model.hpp"
#include "state_machine_element_model_impl.hpp"


namespace sxy
{


namespace model
{


//!\class pseudostate_model_impl
//!\brief A pseudostate in the model.
class pseudostate_model_impl:
	public virtual pseudostate_model, public state_machine_element_model_impl
{


public:
	//!\brief Constructor.
	//!\param _name Name of the pseudostate.
	//!\param _type Type of the pseudostate.
	pseudostate_model_impl( const std::string& _name, const model_element_type& _type );
	virtual ~pseudostate_model_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( pseudostate_model_impl )

	//!\brief Get the list of the incoming transitions of the pseudostate.
	virtual raw_const_transition_models get_incoming_transitions() const SX_OVERRIDE;

	//!\brief Add an incoming transition to the list of the incoming transitions of the pseudostate.
	virtual void add_incoming_transition( transition_models _incoming_transition ) SX_OVERRIDE;

	//!\brief Get the list of the outgoing transitions of the pseudostate.
	virtual raw_const_transition_models get_outgoing_transitions() const SX_OVERRIDE;

	//!\brief Add a outgoing transition to the list of the outgoing transitions of the pseudostate.
	virtual void add_outgoing_transition( transition_models _outgoing_transition ) SX_OVERRIDE;

	virtual state_machine_element_model* get_child( const sxe::uri& _uri ) SX_OVERRIDE;

private:
	transition_models incoming_transitions_;
	transition_models outgoing_transitions_;


};


}


}


#endif
