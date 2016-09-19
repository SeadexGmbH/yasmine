//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef EVENT_WITH_PARAMETERS_B699EFDE_DB4D_461B_A0DD_632CCFE9B5D5
#define EVENT_WITH_PARAMETERS_B699EFDE_DB4D_461B_A0DD_632CCFE9B5D5


#include <utility>

#include "event_impl.hpp"


namespace sxy
{


template< typename ... args > 
class event_with_parameters:
	public event_impl
{
public:
	using parameters = std::tuple< args ... >;


	event_with_parameters( const event_id _event_id, args ... _args )
		: event_impl( _event_id, DEFAULT_EVENT_PRIORITY ),
		parameters_( std::forward< args >( _args ) ... )
	{
		// Nothing to do...
	}


	event_with_parameters( const event_id _event_id, const event_priority _event_priority, args ... _args )
		: event_impl( _event_id, _event_priority ),
			parameters_( std::forward< args >( _args ) ... )
	{
		// Nothing to do...
	}
																															 

	virtual ~event_with_parameters() noexcept override = default;	


	event_with_parameters( const event_with_parameters& ) = delete;
	event_with_parameters& operator=( const event_with_parameters& ) = delete;
	const parameters& get_parameters() const
	{
		return( parameters_ );
	}


	static event_sptr create( const event_id _event_id, args ... _args )
	{
		auto event = std::make_shared< sxy::event_with_parameters< args ... > >( _event_id, _args ... );
		return( event );
	}


	static event_sptr create(	const event_id _event_id, const event_priority _event_priority, args ... _args )
	{
		auto event = std::make_shared< sxy::event_with_parameters< args ... > >( _event_id, _event_priority, _args ... );
		return( event );
	}		


private:
	parameters parameters_;
};


}


#endif
