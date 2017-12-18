#include "state_machine_external_element.hpp"


namespace sxy
{


namespace model
{


state_machine_external_element::state_machine_external_element( const std::string& _name, const model_element_type& _type ):
	name_( _name ),
	type_( _type )
{
	// Nothing to do...
}


state_machine_external_element::~state_machine_external_element() SX_NOEXCEPT
{
	// Nothing to do...
}


const std::string& state_machine_external_element::get_name() const
{
	return( name_ );
}


const std::string& state_machine_external_element::get_name()
{
	return( name_ );
}


void state_machine_external_element::set_name( const std::string& _name )
{
	name_ = _name;
}


const model_element_type state_machine_external_element::get_type() const
{
	return( type_ );
}


void state_machine_external_element::set_type( const model_element_type& _type )
{
	type_ = _type;
}


}


}


