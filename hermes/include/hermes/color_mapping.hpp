//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SX_NO_LOGGING			 


#ifndef COLOR_MAPPING_A8F877D1_966B_463B_AE26_BD54CB2FEC35
#define COLOR_MAPPING_A8F877D1_966B_463B_AE26_BD54CB2FEC35


#include <map>

#include "essentials/non_copyable.hpp"
#include "color.hpp"
#include "log_level.hpp"


namespace hermes
{


//!\class color_mapping
//!\brief Class for mapping colors to log levels.
class color_mapping SX_FINAL
{
public:
	//!\typedef	color_map
	//!\brief Alias for the map of log levels to colors.
	typedef std::map< log_level, color > color_map;

	//!\brief Constructor.
	color_mapping();
	~color_mapping() SX_NOEXCEPT;
	SX_NO_COPY(color_mapping)

	//!\brief Method for getting the color associated with the given log level.
	//!\param _log_level The log level for which the color is requested.
	//!\return Color value associated with the given log level.
	color get_color( const log_level _log_level ) const;


private:
	color_map color_map_;
};


}


#endif


#endif
