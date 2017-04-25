//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef STATE_MODEL_IMPL_469ADCF1_AE5F_478C_A906_218099D99C09
#define STATE_MODEL_IMPL_469ADCF1_AE5F_478C_A906_218099D99C09


#include "state_model.hpp"
#include "state_machine_element_model_impl.hpp"
#include "transition_model_fwd.hpp"


namespace sxy
{


namespace model
{


//!\class state_model_impl
//!\brief A state in the model.
class state_model_impl:
	public virtual state_model, public state_machine_element_model_impl
{
public:
	//!\brief Constructor.
	//!\param _name  Name of the state.
	//!\param _type Type of the state model.
	//!\param _deferred_events List of IDs of deferred events.
	state_model_impl( const std::string& _name, const model_element_type& _type,
		const event_ids& _deferred_events = event_ids() );
	virtual ~state_model_impl() SX_NOEXCEPT;
	SX_NO_COPY( state_model_impl )
	//!\brief Get the list of transitions of the state.
	virtual raw_const_transition_models get_transitions() const SX_OVERRIDE;
	//!\brief Get the list of IDs of deferred events.
	virtual const event_ids& get_deferred_events() const SX_OVERRIDE;


private:
	transition_models transitions_;
	event_ids deferred_events_;
};


}


}


#endif
