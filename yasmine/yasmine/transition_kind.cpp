//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "transition_kind.h"


namespace sxy
{


std::string to_string( const transition_kind _kind )
{
	std::string kind = "";

	switch( _kind )
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


}
