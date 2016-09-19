//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_uri.h"

#include <vector>
#include <sstream>

#include "base.h"
#include "globals.h"


namespace sxy
{


t_uri::t_uri
(		
	const std::string& p_uri
): 
	m_uri()
{
	split_string_to_uri_segments( p_uri );
}


t_uri::~t_uri
(
) = default;


bool
// cppcheck-suppress unusedFunction
t_uri::is_empty
(
) const
{													
	return( m_uri.empty() );
}


const std::string
t_uri::to_string
(
) const
{
	return( build_uri() );
}
		

const std::string&
// cppcheck-suppress unusedFunction
t_uri::get_front
(
) const
{
	Y_ASSERT( !m_uri.empty(), "Uri is empty!" );
	return ( m_uri.front() );
}


const std::string&
// cppcheck-suppress unusedFunction
t_uri::get_back
(
)
{
	Y_ASSERT( !m_uri.empty(), "Uri is empty!" );
	return ( m_uri.back() );
}


void
t_uri::push_front
(
	const std::string& p_segment
)
{
	m_uri.push_front( p_segment );
}
	

void
t_uri::push_back
(
	const std::string& p_segment
)
{
	m_uri.push_back( p_segment );
}


void
t_uri::pop_front
(
)
{
	Y_ASSERT( !m_uri.empty(), "Uri is empty!" );
	m_uri.pop_front();	
}


void
t_uri::pop_back
(
)
{
	Y_ASSERT( !m_uri.empty(), "Uri is empty!" );
	m_uri.pop_back();		
}


size_t
t_uri::size
(
) const
{
	return( m_uri.size() );
}


const std::string 
t_uri::build_uri
(
)	const
{										
	std::stringstream l_uri;

	for(const auto& l_uri_element : m_uri)
	{
		l_uri << g_uri_delimiter << l_uri_element;		
	}

	return( l_uri.str() );
}
	

void
t_uri::split_string_to_uri_segments
(
	const std::string& p_uri
)
{
	std::string l_uri = p_uri;
	if( !p_uri.empty() )
	{
		if( g_uri_delimiter == p_uri[0] )
		{
			l_uri = p_uri.substr( 1 );
		}

		std::string::size_type l_start = 0;
		std::string::size_type l_end = l_uri.find( g_uri_delimiter );

		while( l_end != std::string::npos )
		{
			auto segment = l_uri.substr( l_start, l_end - l_start );
			m_uri.push_back( segment );
			l_start = ++l_end;
			l_end = l_uri.find( g_uri_delimiter, l_end );
		}

		auto l_last_segment = l_uri.substr( l_start );
		if( l_last_segment[0] != g_uri_delimiter )
		{
			m_uri.push_back( l_last_segment );
		}
	}
}


}
