//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_transition_kind.h"


namespace sxy
{


std::string
to_string
(
	const t_transition_kind p_kind
)
{
	std::string l_kind = "";

	switch( p_kind )
	{
	case sxy::t_transition_kind::EXTERNAL:
		l_kind = "EXTERNAL";
		break;

	case sxy::t_transition_kind::INTERNAL:
		l_kind = "INTERNAL";
		break;

	case sxy::t_transition_kind::LOCAL:
		l_kind = "LOCAL";
		break;

	default:
		break;
	}

	return( l_kind );
}


}
