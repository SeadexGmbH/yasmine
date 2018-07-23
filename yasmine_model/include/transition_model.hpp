//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
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
	virtual void set_kind( transition_model_kind _kind ) = 0;
	virtual const std::string& get_behavior() const = 0;
	virtual void set_behavior( const std::string& _behavior ) = 0;
	virtual const std::string& get_guard() const = 0;
	virtual void set_guard( const std::string& _guard ) = 0;
	virtual const sxe::uri& get_source() const = 0;
	virtual void set_source( const std::string& _source ) = 0;
	virtual const sxe::uri& get_target() const = 0;
	virtual void set_target( const std::string& _target ) = 0;
	virtual const event_ids& get_event_ids() const = 0;
	virtual void set_event_ids( event_ids& _event_ids ) = 0;
	virtual void add_event( const event_id _id ) = 0;
	virtual void remove_event( const event_id _id ) = 0;
	virtual bool has_trigger( const event_id _id ) const = 0;
};


}


}


#endif
