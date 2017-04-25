//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TRANSITION_MODEL_IMPL_6EA9FC2E_FBED_4750_9D48_532B7A0FFAC2
#define TRANSITION_MODEL_IMPL_6EA9FC2E_FBED_4750_9D48_532B7A0FFAC2


#include "transition_model.hpp"

#include "essentials/uri.hpp"

#include "state_machine_element_model_impl.hpp"


namespace sxy
{


namespace model
{


//!\class transition_model
//!\brief A transition in the model.
class transition_model_impl:
	public virtual transition_model, public state_machine_element_model_impl
{
public:
	//!\brief Constructor.
	//!\param _name Name of the transition.
	//!\param _source_uri Uri of the source vertex.
	//!\param _target_uri Uri of the target vertex.
	//!\param _king Transition kind.
	//!\param _behavior Behavior of the transition..
	//!\param _guard Guard of the transition.
	//!\param _events List of IDs of events.
	transition_model_impl( const std::string& _name, const sxe::uri& _source_uri, const sxe::uri& _target_uri, 
		const transition_model_kind _kind, const std::string& _behavior, const std::string& _guard, 
		const event_ids& _events );
	virtual ~transition_model_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( transition_model_impl ) 
	virtual transition_model_kind get_kind() const SX_OVERRIDE;

	//!\brief Get the behavior of the transition.
	//!\return String behavior of the transition.
	virtual const std::string& get_behavior() const SX_OVERRIDE;
	//!\brief Get the guard of the transition.
	//!\return String guard of the transition.
	virtual const std::string& get_guard() const SX_OVERRIDE;
	//!\brief Get the URI of the transition's source vertex.
	virtual const sxe::uri& get_source() const SX_OVERRIDE;
	//!\brief Set the URI of the transition's source vertex.
	virtual const sxe::uri& get_target() const SX_OVERRIDE;
	//!\brief Get the List of IDs of transition's events.
	const event_ids& get_event_ids() const SX_OVERRIDE;


private:
	const sxe::uri source_;
	const sxe::uri target_;
	const transition_model_kind kind_;
	const std::string behavior_;
	const std::string guard_;
	const event_ids events_;
};


}


}


#endif
