//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "state_machine_base.hpp"

#include "essentials/base.hpp"
#include "essentials/exception.hpp"
#include "essentials/uri.hpp"
#include "hermes/log_and_throw.hpp"

#include "event_processing_callback.hpp"
#include "composite_state_impl.hpp"
#include "event_impl.hpp"
#include "transition_controller.hpp"
#include "region.hpp"
#include "behavior_impl.hpp"
#include "constraint_impl.hpp"
#include "transition_impl.hpp"
#include "async_simple_state_impl.hpp"
#include "completion_event.hpp"


namespace sxy
{


	state_machine_base::state_machine_base( const std::string& _name, event_processing_callback* const _event_processing_callback )
		: name_( _name ),
		event_processing_callback_( _event_processing_callback ),
		root_state_( SX_MAKE_UNIQUE< composite_state_impl >( _name ) ),
		transitions_(),
		deferred_events_(),
		state_machine_is_running_( false ),
		interrupt_( false )
#ifdef Y_PROFILER
		, processed_events_( 0 )
#endif
	{
		SX_LOG( hermes::log_level::LL_TRACE, "Creating state_machine '%'.", _name );
		if( event_processing_callback_ )
		{
			event_processing_callback_->add_state_machine_introspection( *this );
		}
		SX_LOG( hermes::log_level::LL_TRACE, "Created state_machine '%'.", _name );
	}


	state_machine_base::~state_machine_base() SX_NOEXCEPT
	{
#ifdef Y_PROFILER
		SX_LOG( hermes::log_level::LL_TRACE, "events fired by '%': %.", name_, processed_events_ );
#endif

		SX_LOG( hermes::log_level::LL_TRACE, "Destroying state_machine '%'.", name_ );

		SX_ASSERT( !state_machine_is_running_, "State machine is still running!" );

		SX_LOG( hermes::log_level::LL_TRACE, "Destroyed state_machine '%'.", name_ );
	}


	composite_state& state_machine_base::get_root_state() const
	{
		SX_ASSERT( root_state_, "No root state!" );
		return( *root_state_ );
	}


#ifdef Y_PROFILER	
	sxe::uint32_t state_machine_base::get_number_of_processed_events() const
	{
		return( processed_events_ );
	}
#endif


	transition& state_machine_base::add_transition( transition_uptr _transition )
	{
		transition& transition = *_transition;
		transitions_.push_back( sxe::move( _transition ) );
		return( transition );
	}


	transition& state_machine_base::add_transition( const event_id _event_id, vertex& _source, vertex& _target,
		const sxy::transition_kind _kind, const constraint_function& _guard, const behavior_function& _behavior )
	{
		sxe::SX_UNIQUE_PTR< sxy::transition_impl > l_transition =
			SX_MAKE_UNIQUE< sxy::transition_impl >( _event_id, sxe::ref( _source ), sxe::ref( _target ), _kind,
			( _guard ? ( constraint_impl::create( _guard ) ) : constraint_uptr() ),
				( _behavior ? ( behavior_impl::create_behavior( sxe::ref( _behavior ) ) ) : behavior_uptr() ) );
		transition_impl& transition = *l_transition;
		transitions_.push_back( sxe::move( l_transition ) );
		return( transition );
	}


	transition& state_machine_base::add_transition( const event_ids& _event_ids, vertex& _source, vertex& _target,
		const sxy::transition_kind _kind, const constraint_function& _guard, const behavior_function& _behavior )
	{
		sxe::SX_UNIQUE_PTR< sxy::transition_impl > l_transition =
			SX_MAKE_UNIQUE< sxy::transition_impl >( _event_ids, sxe::ref( _source ), sxe::ref( _target ), _kind,
			( _guard ? ( constraint_impl::create( _guard ) ) : constraint_uptr() ),
				( _behavior ? ( behavior_impl::create_behavior( sxe::ref( _behavior ) ) ) : behavior_uptr() ) );
		transition_impl& transition = *l_transition;
		transitions_.push_back( sxe::move( l_transition ) );
		return( transition );
	}


	transition& state_machine_base::add_transition( const event_id _event_id, vertex& _source, vertex& _target,
		const constraint_function& _guard, const sxy::transition_kind _kind )
	{
		sxe::SX_UNIQUE_PTR< sxy::transition_impl > l_transition =
			SX_MAKE_UNIQUE< sxy::transition_impl >( _event_id, sxe::ref( _source ), sxe::ref( _target ), _kind,
			( _guard ? ( constraint_impl::create( _guard ) ) : constraint_uptr() ), behavior_uptr() );
		transition_impl& transition = *l_transition;
		transitions_.push_back( sxe::move( l_transition ) );
		return( transition );
	}


	transition& state_machine_base::add_transition( const event_ids& _event_ids, vertex& _source, vertex& _target,
		const constraint_function& _guard, const sxy::transition_kind _kind )
	{
		sxe::SX_UNIQUE_PTR< sxy::transition_impl > l_transition =
			SX_MAKE_UNIQUE< sxy::transition_impl >( _event_ids, sxe::ref( _source ), sxe::ref( _target ), _kind,
			( _guard ? ( constraint_impl::create( _guard ) ) : constraint_uptr() ), behavior_uptr() );
		transition_impl& transition = *l_transition;
		transitions_.push_back( sxe::move( l_transition ) );
		return( transition );
	}


	transition& state_machine_base::add_transition( const event_id _event_id, vertex& _source, vertex& _target,
		const constraint_function& _guard, const behavior_function& _behavior, const sxy::transition_kind _kind )
	{
		sxe::SX_UNIQUE_PTR< sxy::transition_impl > l_transition =
			SX_MAKE_UNIQUE< sxy::transition_impl >( _event_id, sxe::ref( _source ), sxe::ref( _target ), _kind,
			( _guard ? ( constraint_impl::create( _guard ) ) : constraint_uptr() ),
				( _behavior ? ( behavior_impl::create_behavior( sxe::ref( _behavior ) ) ) : behavior_uptr() ) );
		transition_impl& transition = *l_transition;
		transitions_.push_back( sxe::move( l_transition ) );
		return( transition );
	}


	transition& state_machine_base::add_transition( const event_ids& _event_ids, vertex& _source, vertex& _target,
		const constraint_function& _guard, const behavior_function& _behavior, const sxy::transition_kind _kind )
	{
		sxe::SX_UNIQUE_PTR< sxy::transition_impl > l_transition =
			SX_MAKE_UNIQUE< sxy::transition_impl >( _event_ids, sxe::ref( _source ), sxe::ref( _target ), _kind,
			( _guard ? ( constraint_impl::create( _guard ) ) : constraint_uptr() ),
				( _behavior ? ( behavior_impl::create_behavior( sxe::ref( _behavior ) ) ) : behavior_uptr() ) );
		transition_impl& transition = *l_transition;
		transitions_.push_back( sxe::move( l_transition ) );
		return( transition );
	}


	transition& state_machine_base::add_transition( const event_id _event_id, vertex& _source, vertex& _target,
		const behavior_function& _behavior, const sxy::transition_kind _kind )
	{
		sxe::SX_UNIQUE_PTR< sxy::transition_impl > l_transition =
			SX_MAKE_UNIQUE< sxy::transition_impl >( _event_id, sxe::ref( _source ), sxe::ref( _target ), _kind,
				constraint_uptr(),
				( _behavior ? ( behavior_impl::create_behavior( sxe::ref( _behavior ) ) ) : behavior_uptr() ) );
		transition_impl& transition = *l_transition;
		transitions_.push_back( sxe::move( l_transition ) );
		return( transition );
	}


	transition& state_machine_base::add_transition( const event_ids& _event_ids, vertex& _source, vertex& _target,
		const behavior_function& _behavior, const sxy::transition_kind _kind )
	{
		sxe::SX_UNIQUE_PTR< sxy::transition_impl > l_transition =
			SX_MAKE_UNIQUE< sxy::transition_impl >( _event_ids, sxe::ref( _source ), sxe::ref( _target ), _kind,
				constraint_uptr(),
				( _behavior ? ( behavior_impl::create_behavior( sxe::ref( _behavior ) ) ) : behavior_uptr() ) );
		transition_impl& transition = *l_transition;
		transitions_.push_back( sxe::move( l_transition ) );
		return( transition );
	}


	bool state_machine_base::check( state_machine_defects& _defects ) const
	{

		bool check_ok = root_state_->check( _defects );
		if( check_ok )
		{
			SX_FOR( const transition_uptr& transition, transitions_ )
			{
				if( !transition->check( _defects ) )
				{
					check_ok = false;
					break;
				}
			}
		}

		return( check_ok );
	}


	void state_machine_base::halt()
	{
		SX_LOG( hermes::log_level::LL_INFO, "Stopping state machine '%'.", name_ );
		if( state_machine_is_running_ )
		{
			stop_all_async_states( *root_state_ );
			state_machine_is_running_ = false;
		}

		SX_LOG( hermes::log_level::LL_INFO, "Stopped state machine '%'.", name_ );
	}


	void state_machine_base::interrupt()
	{
		interrupt_ = true;
		interrupt_impl();
	}


	bool state_machine_base::is_interrupted() const
	{
		return( interrupt_ );
	}


	void state_machine_base::set_behavior_of_unhandled_event_handler( const behavior_function& _behavior )
	{
		event_handler_behavior_ = behavior_impl::create_behavior( _behavior );
	}


	std::string state_machine_base::get_name() const
	{
		return( name_ );
	}


	bool state_machine_base::run( async_event_handler* const _async_event_handler )
	{
		SX_ASSERT( root_state_, "No root state!" );
		bool state_machine_started = false;
		state_machine_is_running_ = true;

		interrupt_ = false;
		try
		{
			if( event_processing_callback_ )
			{
				event_processing_callback_->before_event( sxy::completion_event::get_event_id() );
			}

			transition_controller transition_controller;
			state_machine_started = transition_controller.start_state_machine( *root_state_, event_processing_callback_,
				_async_event_handler, *this, *this );
			if( event_processing_callback_ )
			{
				event_processing_callback_->after_event( sxy::completion_event::get_event_id() );
			}

			if( !state_machine_started )
			{
				SX_LOG( hermes::log_level::LL_INFO, "Terminate pseudostate reached. The state machine is stopping." );
				state_machine_is_running_ = false;
			}
		}
		catch( const std::exception& exception )
		{
			SX_LOG( hermes::log_level::LL_FATAL, "State machine cannot start: %.", exception.what() );
			state_machine_is_running_ = false;
			throw;
		}
		catch( ... )
		{
			SX_LOG( hermes::log_level::LL_FATAL, "State machine can not start: Unknown exception occurred." );
			state_machine_is_running_ = false;
			throw;
		}
		return( state_machine_started );
	}

	bool state_machine_base::process_event( const event_sptr& _event, async_event_handler* const _async_event_handler )
	{
#ifdef Y_PROFILER
		++processed_events_;
#endif
		bool terminate_pseudostate_has_been_reached = true;
		if( !interrupt_ )
		{
			SX_LOG( hermes::log_level::LL_INFO, "'%' is processing event '%' (%) with priority '%'.", get_name(), _event->get_name(),
				_event->get_id(), static_cast< sxe::int16_t >( _event->get_priority() ) );

			SX_ASSERT( state_machine_is_running_, "State machine is not running!" );
			SX_LOG( hermes::log_level::LL_TRACE, "Starting processing of event '%' (%) with priority '%'.", _event->get_name(), _event->get_id(),
				static_cast< sxe::int16_t >( _event->get_priority() ) );
			try
			{
				if( event_processing_callback_ )
				{
					event_processing_callback_->before_event( _event->get_id(), _event->get_priority() );
				}

				transition_controller transition_controller;
				bool event_is_deferred = false;
				bool event_was_unhandled = false;
				terminate_pseudostate_has_been_reached = transition_controller.process_event( *_event, *root_state_,
					event_processing_callback_, event_is_deferred, _async_event_handler, *this, *this, event_was_unhandled );
				SX_LOG( hermes::log_level::LL_TRACE, "Event '%' (%) has been processed.", _event->get_name(), _event->get_id() );
				if( event_processing_callback_ )
				{
					event_processing_callback_->after_event( _event->get_id() );
				}

				if( terminate_pseudostate_has_been_reached )
				{
					SX_LOG( hermes::log_level::LL_INFO, "Terminate pseudostate has been reached! The state machine '%' is stopping.", get_name() );
					state_machine_is_running_ = false;
				}
				else
				{
					if( event_is_deferred )
					{
						SX_ASSERT( !event_was_unhandled, "Event is deferred AND is handled!" );
						add_deferred_event( _event );
					}
					else
					{
						if( !event_was_unhandled ) //event_was_unhandled
						{
							handle_unhandled_event( _event );
						}
						terminate_pseudostate_has_been_reached = process_deferred_events( _async_event_handler );
					}
				}

				if( terminate_pseudostate_has_been_reached )
				{
					SX_LOG( hermes::log_level::LL_INFO, "Terminate pseudostate has been reached! The state machine '%' is stopping.", get_name() );
					state_machine_is_running_ = false;
				}
			}
			catch( const std::exception& exception )
			{
				SX_LOG( hermes::log_level::LL_FATAL, "std::exception occurred during event processing in state machine '%': %", get_name(), exception.what() );
				state_machine_is_running_ = false;
				stop_all_async_states( *root_state_ );
				throw;
			}
			catch( ... )
			{
				SX_LOG( hermes::log_level::LL_FATAL, "Unknown exception occurred in state machine '%'!", get_name() );
				state_machine_is_running_ = false;
				stop_all_async_states( *root_state_ );
				throw;
			}

			SX_LOG( hermes::log_level::LL_INFO, "'%' processed event '%' (%).", get_name(), _event->get_name(), _event->get_id() );

		}
		else
		{
			terminate_pseudostate_has_been_reached = true;
			halt();
		}

		if( terminate_pseudostate_has_been_reached )
		{
			stop_all_async_states( *root_state_ );
		}

		return( terminate_pseudostate_has_been_reached );
	}


	const events& state_machine_base::get_deferred_events() const
	{
		return( deferred_events_ );
	}


	raw_const_states state_machine_base::get_active_state_configuration() const
	{
		raw_const_states active_state_configuration;
		const composite_state& root = get_root_state();
		check_regions_for_active_states( active_state_configuration, root );
		return( active_state_configuration );
	}


	void state_machine_base::get_active_states_from_region( raw_const_states& _active_state_configuration,
		const region& _region ) const
	{
		const state* const active_state = _region.get_active_state();
		if( active_state )
		{
			_active_state_configuration.push_back( active_state );
			check_regions_for_active_states( _active_state_configuration, *active_state );
		}
	}


	void state_machine_base::check_regions_for_active_states( raw_const_states& _active_state_configuration,
		const state& _state ) const
	{
		SX_FOR( const region_uptr& region, _state.get_regions() )
		{
			get_active_states_from_region( _active_state_configuration, *region );
		}
	}


	void state_machine_base::add_deferred_event( const event_sptr& _event )
	{
		deferred_events_.push_back( _event );
		SX_LOG( hermes::log_level::LL_DEBUG, "Event '%' was deferred!", _event->get_name() );
	}


	bool state_machine_base::process_deferred_events( async_event_handler* const _async_event_handler )
	{
		const events deferred_events = deferred_events_;
		deferred_events_.clear();
		bool terminate_pseudostate_has_been_reached = false;
		transition_controller transition_controller;

		SX_FOR( const event_sptr deferred_event, deferred_events )
		{
			if( event_processing_callback_ )
			{
				event_processing_callback_->before_event( deferred_event->get_id(), deferred_event->get_priority() );
			}

			bool event_is_deferred = false;
			bool event_was_unhandled = false;
			terminate_pseudostate_has_been_reached = transition_controller.process_event( *deferred_event, *root_state_,
				event_processing_callback_, event_is_deferred, _async_event_handler, *this, *this, event_was_unhandled );
			if( event_processing_callback_ )
			{
				event_processing_callback_->after_event( deferred_event->get_id() );
			}

			if( terminate_pseudostate_has_been_reached )
			{
				SX_LOG( hermes::log_level::LL_INFO, "Terminate pseudostate has been reached! The state machine is stopping." );
				break;
			}
			else
			{
				if( event_is_deferred )
				{
					deferred_events_.push_back( deferred_event );
				}
				else
				{
					if( !event_was_unhandled )
					{
						handle_unhandled_event( deferred_event );
					}
				}
			}
		}

		return( terminate_pseudostate_has_been_reached );
	}


	void state_machine_base::stop_all_async_states( state& _state )
	{
		SX_FOR( region_uptr& region, _state.get_regions() )
		{
			stop_all_async_states_from_region( region );
		}
	}


	void state_machine_base::stop_all_async_states_from_region( region_uptr& _region )
	{
		state* const active_state = _region->get_active_state();
		if( active_state )
		{
			async_simple_state_impl* const async_state = dynamic_cast< async_simple_state_impl* >( active_state );
			if( async_state )
			{
				async_state->stop_do_behavior();
			}
			else
			{
				stop_all_async_states( *active_state );
			}
		}
	}


	void state_machine_base::interrupt_impl()
	{
		// Nothing to do...
	}


	void state_machine_base::handle_unhandled_event( const event_sptr& _event )
	{
		SX_LOG( hermes::log_level::LL_DEBUG, "Event '%' was not handled!", _event->get_name() );
		if( event_handler_behavior_ )
		{
			SX_LOG( hermes::log_level::LL_TRACE, "Executing unhandled event handler's behavior." );
			( *event_handler_behavior_ )( *_event, *this );
		}
	}

}
