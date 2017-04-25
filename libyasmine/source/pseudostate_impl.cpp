//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "pseudostate_impl.hpp"

#include "essentials/base.hpp"

#include "region.hpp"
#include "transition.hpp"
#include "state_machine_defect.hpp"
#include "completion_event.hpp"


namespace sxy
{


pseudostate_impl::pseudostate_impl( const std::string& _name )
	: vertex_impl( _name )
{
	// Nothing to do...
}


pseudostate_impl::~pseudostate_impl() SX_NOEXCEPT
{
	// Nothing to do...
}

																							
bool pseudostate_impl::check( state_machine_defects& _defects ) const
{
	bool check_ok = true;

	SX_FOR( const transition* const outgoing_transition, get_outgoing_transitions() )
	{
		if( !outgoing_transition->can_accept_event( sxy::completion_event::get_event_id() ) )
		{
			_defects.push_back( state_machine_defect( *this,
				"'%' has outgoing transition with trigger!", get_name() ) );
			check_ok = false;
		}
	}

	return( check_ok );
}


}
