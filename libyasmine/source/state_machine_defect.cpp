//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "state_machine_defect.hpp"

#include "hermes/log.hpp"


namespace sxy
{


#ifdef SX_CPP03_BOOST


	state_machine_defect::state_machine_defect( const state_machine_element& _element, const std::string& _message )
		: element_( &_element ),
		message_( sxe::sxprintf( _message.c_str() ) )
	{
		// Nothing to do...
	}


state_machine_defect::state_machine_defect( const state_machine_element& _element, const std::string& _message,
	const sxe::value_type& _value )
	: element_( &_element ),
		message_( sxe::sxprintf( _message.c_str(), _value ) )
{
	// Nothing to do...
}


state_machine_defect::state_machine_defect( const state_machine_element& _element, const std::string& _message,
	const sxe::value_type& _value1, const sxe::value_type& _value2 )
	: element_( &_element ),
		message_( sxe::sxprintf( _message.c_str(), _value1, _value2 ) )
{
	// Nothing to do...
}


state_machine_defect::state_machine_defect(	const state_machine_element& _element, const std::string& _message,
	const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3 )
	: element_( &_element ),
		message_( sxe::sxprintf( _message.c_str(), _value1, _value2, _value3 ) )
{
	// Nothing to do...
}


state_machine_defect::state_machine_defect(	const state_machine_element& _element, const std::string& _message,
	const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3, const sxe::value_type& _value4 )
	: element_( &_element ),
		message_( sxe::sxprintf( _message.c_str(), _value1, _value2, _value3, _value4 ) )
{
	// Nothing to do...
}


state_machine_defect::state_machine_defect(	const state_machine_element& _element, const std::string& _message,
	const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3, const sxe::value_type& _value4,
	const sxe::value_type& _value5 )
	: element_( &_element ),
		message_( sxe::sxprintf( _message.c_str(), _value1, _value2, _value3, _value4, _value5 ) )
{
	// Nothing to do...
}


#endif


state_machine_defect::~state_machine_defect() SX_NOEXCEPT
{
	// Nothing to do...
}


const state_machine_element& state_machine_defect::get_element() const
{
	return( *element_ );
}


const std::string& state_machine_defect::get_message() const
{
	return( message_ );
}


// cppcheck-suppress unusedFunction
void write_defects_to_log( const state_machine_defects& _defects )
{
	SX_FOR( const state_machine_defect &defect, _defects )
	{
		SX_LOG( hermes::log_level::LL_ERROR, defect.get_message() );
	}
}


}
