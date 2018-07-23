//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef STATE_MODEL_AE9CA281_0B08_469D_BA4A_9608DD495579
#define STATE_MODEL_AE9CA281_0B08_469D_BA4A_9608DD495579


#include "state_machine_element_model.hpp"
#include "state_model_fwd.hpp"
#include "transition_model.hpp"
#include "region_model_fwd.hpp"


namespace sxy
{


namespace model
{


class model_vertex_visitor;


//!\interface state_model
//!\brief Interface for a state in the model.
class state_model : public virtual state_machine_element_model
{
public:
	state_model()
	{
		// Nothing to do...
	}


	virtual ~state_model() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	SX_NO_COPY( state_model )
	virtual raw_const_transition_models get_transitions() const = 0;
	virtual const event_ids& get_deferred_events() const = 0;
	virtual void add_deferred_event( const event_id _deferred_event_id ) = 0;
	virtual void remove_deferred_event( const event_id _deferred_event_id ) = 0;
	virtual bool defers_event( const event_id _id ) const = 0;
	virtual const raw_const_region_models get_regions() const = 0;
	virtual const size_t get_regions_count() const = 0;
	virtual const std::string& get_enter_behavior() const = 0;
	virtual void set_enter_behavior( const std::string& _enter_behavior ) = 0;
	virtual const std::string& get_do_behavior() const = 0;
	virtual void set_do_behavior( const std::string& _do_behavior ) = 0;
	virtual const std::string& get_exit_behavior() const = 0;
	virtual void set_exit_behavior( const std::string& _exit_behavior ) = 0;
	virtual void accept( model_vertex_visitor& _constructor_visitor ) const = 0;
	virtual void get_event_references( std::vector<sxy::model::state_machine_element_model*>& _elements,
		const event_sptr _event ) = 0;
};


}


}


#endif
