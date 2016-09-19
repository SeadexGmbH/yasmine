//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "make_unique.hpp"
#include "constraint_impl.hpp"


namespace sxy
{


constraint_impl::constraint_impl( const constraint_function& _function )
	: constraint(),
		function_( _function )
{
	// Nothing to do...
}


bool constraint_impl::operator()( const event& _event ) const
{
	return( function_( _event ) );
}


constraint_uptr constraint_impl::create( const constraint_function& _function )
{		
	return( sxy::make_unique< sxy::constraint_impl >( _function ) );
}


}
