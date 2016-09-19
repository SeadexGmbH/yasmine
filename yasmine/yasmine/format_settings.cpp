//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "format_settings.hpp"


namespace sxy
{


format_settings::format_settings()
	: format_string_(),
		missing_closing_bracket_( false ),
		correct_( false ),
		hex_( false ),
		pad_zeros_( false ),
		places_set_( false ),
		places_( 0 ),
		decimal_places_set_( false ),
		decimal_places_( 0 )
{
	// Nothing to do...
}


}
