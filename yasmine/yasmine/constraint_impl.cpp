//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "constraint_impl.h"


namespace sxy
{


constraint_impl::constraint_impl( const constraint_function& _function )
	: constraint(),
		function_( _function )
{
	// Nothing to do...
}


constraint_impl::~constraint_impl() = default;


bool constraint_impl::operator()( const event& _event ) const
{
	return( function_( _event ) );
}


constraint_uptr constraint_impl::create_constraint( const constraint_function& _function )
{
	auto constraint = std::make_unique< sxy::constraint_impl >( _function );
	return( std::move( constraint ) );
}


}
