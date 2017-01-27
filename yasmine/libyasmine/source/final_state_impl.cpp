//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "final_state_impl.hpp"

#include "const_vertex_visitor.hpp"
#include "vertex_visitor.hpp"
#include "state_visitor.hpp"
#include "region.hpp"
#include "state_machine_defect.hpp"
#include "base.hpp"


namespace sxy
{


final_state_impl::final_state_impl( const std::string& _name )
	: state_impl( _name )
{
	// Nothing to do...
}


final_state_impl::~final_state_impl() Y_NOEXCEPT
{
	// Nothing to do...
}
																				 

behavior* final_state_impl::get_entry_behavior() const
{
	return( Y_NULLPTR );
}


behavior* final_state_impl::get_exit_behavior() const
{
	return( Y_NULLPTR );
}


const regions& final_state_impl::get_regions() const
{
	static const regions regions;
	return( regions );
}


regions& final_state_impl::get_regions()
{
	static regions regions;
	return( regions );
}


bool final_state_impl::check( state_machine_defects& _defects ) const
{
	bool check_ok = true;

	// 15.3.2 Final State -> Constraint [1]: A final state cannot have any outgoing transitions.
	if( !get_outgoing_transitions().empty() )
	{
		_defects.push_back( state_machine_defect( *this,
				"Final state '%' has '%' outgoing transitions!", get_name(), get_outgoing_transitions().size() ) );
		check_ok = false;
	}

	// 15.3.2 Final State -> Constraint [2]: A final state cannot have regions.
	if( !get_regions().empty() )
	{
		_defects.push_back( state_machine_defect( *this, "Final state '%' has '%' region(s)!",
				get_name(), get_regions().size() ) );
		check_ok = false;
	}

	// 15.3.2 Final State -> Constraint [3]: A final state cannot reference a submachine.
	// Does not apply.
	// 15.3.2 Final State -> Constraint [4]: A final state has no entry behavior.
	if( get_entry_behavior() )
	{
		_defects.push_back( state_machine_defect( *this, "Final state '%' has entry behavior!",
				get_name() ) );
		check_ok = false;
	}

	// 15.3.2 Final State -> Constraint [5]: A final state has no exit behavior.
	if( get_exit_behavior() )
	{
		_defects.push_back( state_machine_defect( *this, "Final state '%' has exit behavior!",
				get_name() ) );
		check_ok = false;
	}

	// 15.3.2 Final State -> Constraint [6]: A final state has no state (doActivity) behavior.
	// Enforced by design.
	return( check_ok );
}


void final_state_impl::accept_vertex_visitor( const_vertex_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


void final_state_impl::accept_vertex_visitor( vertex_visitor& _visitor )
{
	_visitor.visit( *this );
}


void final_state_impl::accept_state_visitor( state_visitor& _visitor ) const
{
	_visitor.visit( *this );
}


bool final_state_impl::is_event_deferred( const event_id& _event_id ) const
{
	Y_UNUSED_PARAMETER( _event_id );
	return( false );
}


}
