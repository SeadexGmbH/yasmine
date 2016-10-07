//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef Y_NO_LOGGING			 

#ifndef COLOR_MAPPING_A8F877D1_966B_463B_AE26_BD54CB2FEC35
#define COLOR_MAPPING_A8F877D1_966B_463B_AE26_BD54CB2FEC35


#include <map>

#include "compatibility.hpp"
#include "color.hpp"
#include "log_level.hpp"


namespace sxy
{


class color_mapping final
{
public:
	color_mapping();
	~color_mapping() noexcept = default;
	color_mapping( const color_mapping& ) = delete;
	color_mapping& operator=( const color_mapping& ) = delete;
	color get_color( const log_level _log_level );


private:
	std::map< log_level, color > color_ma_;
};


}


#endif

#endif
