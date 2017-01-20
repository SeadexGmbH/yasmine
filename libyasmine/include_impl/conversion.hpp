//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CONVERSION_99CAC61B_DD8A_43E2_8612_0F42873A5741
#define CONVERSION_99CAC61B_DD8A_43E2_8612_0F42873A5741


#include "compatibility.hpp"


namespace sxy
{


bool string_to_int(	const char* const _int_as_string, int& _result );

std::string to_string( sxy::uint32_t _value );

std::string to_string( int _value );

}


#endif
