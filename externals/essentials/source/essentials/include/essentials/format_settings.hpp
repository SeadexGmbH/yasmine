//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex essentials library (http://essentials.seadex.de).                //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://essentials.seadex.de/License.html.         //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef FORMAT_SETTINGS_1D24A599_70E3_42BB_BFE6_46BD94217FAB
#define FORMAT_SETTINGS_1D24A599_70E3_42BB_BFE6_46BD94217FAB


#include <string>

#include "compatibility/compatibility.hpp"


namespace sxe
{

//!\struct format_settings
//!\brief Structure containing information for formatting the output of sxprintf.
struct format_settings SX_FINAL
{
	//!\brief Constructor.
	format_settings();


	std::string format_string_;
	bool missing_closing_bracket_;
	bool correct_;
	bool hex_;
	bool pad_zeros_;
	bool places_set_;
	int places_;
	bool decimal_places_set_;
	int decimal_places_;
};

}


#endif
