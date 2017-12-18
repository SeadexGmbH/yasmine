//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex essentials library (http://essentials.seadex.de).                //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://essentials.seadex.de/License.html.         //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "essentials/uri.hpp"

#include <vector>
#include <sstream>

#include "essentials/base.hpp"


namespace sxe
{


uri::uri( const std::string& _uri )
	: uri_()
{
	split_string_to_uri_segments( _uri );
}


uri::~uri() SX_NOEXCEPT
{
	// Nothing to do...
}


bool uri::is_empty() const
{
	return( uri_.empty() );
}


const std::string uri::to_string() const
{
	return( build_uri() );
}


const std::string& uri::get_front() const
{
	SX_ASSERT( !uri_.empty(), "Uri is empty!" );
	return( uri_.front() );
}


const std::string& uri::get_back()
{
	SX_ASSERT( !uri_.empty(), "Uri is empty!" );
	return( uri_.back() );
}


void uri::push_front( const std::string& _segment )
{
	uri_.push_front( _segment );
}


void uri::push_back( const std::string& _segment )
{
	uri_.push_back( _segment );
}


void uri::pop_front()
{
	SX_ASSERT( !uri_.empty(), "Uri is empty!" );
	uri_.pop_front();
}


void uri::pop_back()
{
	SX_ASSERT( !uri_.empty(), "Uri is empty!" );
	uri_.pop_back();
}


size_t uri::size() const
{
	return( uri_.size() );
}


const std::string uri::build_uri() const
{
	std::stringstream uri;

	SX_FOR( const std::string& uri_element, uri_ )
	{
		uri << URI_DELIMITER << uri_element;
	}

	return( uri.str() );
}


void uri::split_string_to_uri_segments( const std::string& _uri )
{
	std::string uri = _uri;
	if( !_uri.empty() )
	{
		if( URI_DELIMITER == _uri[ 0 ] )
		{
			uri = _uri.substr( 1 );
		}

		std::string::size_type start = 0;
		std::string::size_type end = uri.find( URI_DELIMITER );
		while( end != std::string::npos )
		{
			const std::string& segment = uri.substr( start, end - start );
			uri_.push_back( segment );
			start = ++end;
			end = uri.find( URI_DELIMITER, end );
		}

		const std::string& last_segment = uri.substr( start );
		if( last_segment[ 0 ] != URI_DELIMITER )
		{
			uri_.push_back( last_segment );
		}
	}
}


}
