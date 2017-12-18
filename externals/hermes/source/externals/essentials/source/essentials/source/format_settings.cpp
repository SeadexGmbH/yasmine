//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex essentials library (http://essentials.seadex.de).                //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://essentials.seadex.de/License.html.         //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "essentials/format_settings.hpp"


namespace sxe
{


format_settings::format_settings():
	format_string_(),
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
