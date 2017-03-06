//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef Y_NO_LOGGING			 

#ifndef COLOR_MAPPING_A8F877D1_966B_463B_AE26_BD54CB2FEC35
#define COLOR_MAPPING_A8F877D1_966B_463B_AE26_BD54CB2FEC35


#include <map>

#include "non_copyable.hpp"
#include "color.hpp"
#include "log_level.hpp"


namespace sxy
{


class color_mapping Y_FINAL
{
public:
	typedef std::map< log_level, color > color_map;

	color_mapping();
	~color_mapping() Y_NOEXCEPT;
	Y_NO_COPY(color_mapping)
	color get_color( const log_level _log_level ) const;


private:
	color_map color_map_;
};


}


#endif

#endif
