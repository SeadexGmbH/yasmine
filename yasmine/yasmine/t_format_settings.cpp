//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "t_format_settings.h"


namespace sxy
{


t_format_settings::t_format_settings()
	: m_format_string(),
		m_missing_closing_bracket( false ),
		m_correct( false ),
		m_hex( false ),
		m_pad_zeros( false ),
		m_places_set( false ),
		m_places( 0 ),
		m_decimal_places_set( false ),
		m_decimal_places( 0 )
{
	// Nothing to do...
}


}
