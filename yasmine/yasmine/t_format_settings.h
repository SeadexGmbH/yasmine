//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_FORMAT_SETTINGS_H
#define T_FORMAT_SETTINGS_H


#include <string>


namespace	sxy
{


struct t_format_settings final
{
	t_format_settings
	(
	);


	std::string m_format_string;
	bool m_missing_closing_bracket;
	bool m_correct;
	bool m_hex;
	bool m_pad_zeros;
	bool m_places_set;
	int m_places;
	bool m_decimal_places_set;
	int m_decimal_places;

};


}


#endif
