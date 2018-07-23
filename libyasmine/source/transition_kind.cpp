//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2018 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "transition_kind.hpp"


namespace sxy
{


std::string to_string( const transition_kind _kind )
{
	std::string kind = "";

#ifndef SX_CPP03_BOOST
	switch( _kind )
#else
	switch (_kind.value_)
#endif
	{
	case sxy::transition_kind::EXTERNAL:
		kind = "EXTERNAL";
		break;

	case sxy::transition_kind::INTERNAL:
		kind = "INTERNAL";
		break;

	case sxy::transition_kind::LOCAL:
		kind = "LOCAL";
		break;

	default:
		break;
	}

	return( kind );
}



#ifdef SX_CPP03_BOOST


bool operator==(const sxy::transition_kind& _lhs, const sxy::transition_kind::inner _rhs)
{
	return( _lhs.value_ == _rhs );
}


bool operator==(const sxy::transition_kind::inner _lhs, const sxy::transition_kind& _rhs)
{
	return( _lhs == _rhs.value_ );
}


// cppcheck-suppress unusedFunction
bool operator<(const sxy::transition_kind _lhs, const sxy::transition_kind _rhs)
{
	return ( _lhs.value_ < _rhs.value_ );
}


#endif


}
