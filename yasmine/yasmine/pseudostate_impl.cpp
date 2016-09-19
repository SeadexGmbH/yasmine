//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "pseudostate_impl.hpp"

#include "base.hpp"
#include "region.hpp"
#include "transition.hpp"
#include "state_machine_defect.hpp"


namespace sxy
{


pseudostate_impl::pseudostate_impl( const std::string& _name )
	: vertex_impl( _name )
{
	// Nothing to do...
}

																							
bool pseudostate_impl::check( state_machine_defects& _defects ) const
{
	auto check_ok = true;

	for( const auto outgoing_transition : get_outgoing_transitions() )
	{
		if( !outgoing_transition->can_accept_event( COMPLETION_EVENT ) )
		{
			_defects.push_back( state_machine_defect( *this,
				"'%' has outgoing transition with trigger!", get_name() ) );
			check_ok = false;
		}
	}

	return( check_ok );
}


}
