//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SIMPLE_STATE_MODEL_IMPL_D70699AF_2D8D_4556_8F0B_A16E3FF78852
#define SIMPLE_STATE_MODEL_IMPL_D70699AF_2D8D_4556_8F0B_A16E3FF78852


#include "simple_state_model.hpp"
#include "state_model_impl.hpp"
#include "region_model.hpp"


namespace sxy
{


namespace model
{


//!\class simple_state_model_impl
//!\brief A simple state in the model.
class simple_state_model_impl SX_FINAL:
	public virtual simple_state_model, public state_model_impl
{
public:
	//!\brief Constructor.
	//!\param _name Name of the simple state.
	//!\param _enter_behavior Entry behavior of the simple state.
	//!\param _do_behavior Do behavior of the simple state.
	//!\param _exit_bahvior Exit behavior of the simple state.
	//!\param _deferred_events List of IDs of deferred events.
	//!\param _error_event Event that is fired in case an exception occurs.
	//!\param _is_async Specify if the simple state is sync or async.
	explicit simple_state_model_impl( const std::string& _name, const std::string& _enter_behavior = "",
		const std::string& _do_behavior = "", const std::string& _exit_behavior = "",
		const event_ids& _deferred_events = event_ids(), event_sptr _error_event = event_sptr(), bool _is_async = false );

	//!\brief Constructor.
	//!\param _name Name of the simple state.
	//!\param _is_async Specify if the simple state is sync or async.
	//!\param _enter_behavior Entry behavior of the simple state.
	//!\param _do_behavior Do behavior of the simple state.
	//!\param _exit_bahvior Exit behavior of the simple state.
	//!\param _deferred_events List of IDs of deferred events.
	//!\param _error_event Event that is fired in case an exception occurs.
	explicit simple_state_model_impl( const std::string& _name, bool _is_async, const std::string& _enter_behavior = "",
		const std::string& _do_behavior = "", const std::string& _exit_behavior = "",
		const event_ids& _deferred_events = event_ids(), event_sptr _error_event = event_sptr() );
	virtual ~simple_state_model_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( simple_state_model_impl )

	//!\brief Get the enter behavior of the simple state.
	virtual const std::string& get_enter_behavior() const SX_OVERRIDE;

	//!\brief Set the enter behavior of the simple state.
	virtual void set_enter_behavior( const std::string& _enter_behavior ) SX_OVERRIDE;

	//!\brief Get the do behavior of the simple state.
	virtual const std::string& get_do_behavior() const SX_OVERRIDE;

	//!\brief Set the do behavior of the simple state.
	virtual void set_do_behavior( const std::string& _do_behavior ) SX_OVERRIDE;

	//!\brief Get the exit behavior of the simple state.
	virtual const std::string& get_exit_behavior() const SX_OVERRIDE;

	//!\brief Set the exit behavior of the simple state.
	virtual void set_exit_behavior( const std::string& _exit_behavior ) SX_OVERRIDE;
	virtual const raw_const_region_models get_regions() const SX_OVERRIDE;
	virtual void accept( model_vertex_visitor& _constructor_visitor ) const SX_OVERRIDE;

	//!\brief Check if an error event is stored by the simple state.
	//!\return True if an event is stored by the simple state, false otherwise.
	virtual bool has_error_event() const SX_OVERRIDE;

	//!\brief Get the error event stored by the simple state.
	//!\return Event stored by the simple state.
	virtual event_sptr get_error_event() const SX_OVERRIDE;

	//!\brief Set the error event stored by the simple state.
	virtual void set_error_event( event_sptr _error_event ) SX_OVERRIDE;

	//!\brief Check if the simple state is asynchronous.
	//!\return True for async, false otherwise.
	virtual bool is_async() const SX_OVERRIDE;

	//!\brief Set the simple state to be asynchronous or synchronous.
	//!\param _is_async Switches the type of the simple state between asynchronous - on true - and synchronous - on false.
	virtual void set_is_async( bool _is_async ) SX_OVERRIDE;

	virtual void accept_delete_visitor( delete_visitor& _delete_visitor ) SX_OVERRIDE;

	//!\brief Fill the given list with the elements that defer the given event.
	//!\param _elements List of elements that defer the given event.
	//!\param _event Deferred event.
	virtual void get_event_references( std::vector<sxy::model::state_machine_element_model* >& _elements,
		const event_sptr _event ) SX_OVERRIDE;

private:
	std::string enter_behavior_;
	std::string do_behavior_;
	std::string exit_behavior_;
	event_sptr error_event_;
	bool is_async_;
};


}


}


#endif
