//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "state_machine_element_impl.hpp"


namespace sxy
{


state_machine_element_impl::state_machine_element_impl( const std::string& _name )
	: name_( _name )
{
	// Nothing to do...
}


const std::string& state_machine_element_impl::get_name() const
{
	return( name_ );
}


}
