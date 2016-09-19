//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_execution_state_do_step.h"

#include "log.h"
#include "i_state.h"
#include "i_event_processing_callback.h"
#include "i_execution_step_visitor.h"


namespace sxy
{


t_execution_state_do_step::t_execution_state_do_step( const i_state& p_state )
	: i_execution_step(),
		m_state( p_state )
{
	// Nothing to do...
}


t_execution_state_do_step::~t_execution_state_do_step() = default;


bool t_execution_state_do_step::execute_behavior( i_event_processing_callback* const p_event_processing_callback,
	const i_event& p_event ) const
{
	Y_LOG( sxy::t_log_level::LL_INFO, "Executing 'do behavior' of state '%'.", m_state.get_name() );
	if( p_event_processing_callback )
	{
		p_event_processing_callback->before_do( m_state );
	}

	m_state.execute_do_behavior( p_event );
	if( p_event_processing_callback )
	{
		p_event_processing_callback->after_do( m_state );
	}

	Y_LOG( sxy::t_log_level::LL_INFO, "'do behavior' of state '%' executed.", m_state.get_name() );
	return( false );
}


// cppcheck-suppress unusedFunction
void t_execution_state_do_step::accept( i_execution_step_visitor& p_visitor ) const
{
	p_visitor.visit( *this );
}


// cppcheck-suppress unusedFunction
const i_state& t_execution_state_do_step::get_state() const
{
	return( m_state );
}


}
