//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "transition_priority.h"
#include "compound_transition.h"
#include "composite_state_impl.h"
#include "transition.h"
#include "region.h"
#include "deep_history.h"
#include "shallow_history.h"
#include "behavior.h"


namespace sxy
{


transition_priority::transition_priority( compound_transition& _compound_transition )
	: compound_transition_( &_compound_transition ),
		priority_( _compound_transition.get_LCA_region()->get_parent_state().get_nesting_level() )
{
	// Nothing to do...
}


transition_priority::~transition_priority() = default;


std::size_t transition_priority::get_priority() const
{
	return( priority_ );
}


compound_transition& transition_priority::get_compound_transition() const
{
	return( *compound_transition_ );
}


bool transition_priority::operator<( const transition_priority& _compare_member )  const
{
	return( priority_ > _compare_member.get_priority() );
}


}