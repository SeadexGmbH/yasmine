//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "condition_modifier.hpp"

#include <algorithm>

#include "essentials/conversion.hpp"

#include "grammar.hpp"
#include "genesis_exception.hpp"


namespace sx
{


namespace genesis
{

		
condition_modifier get_condition_modifier_from_string( const std::string& _condition_modifier )
{			
	const std::string condition_modifier_caps = sxe::to_upper( _condition_modifier );

	condition_modifier modifier( condition_modifier::NONE );
	if( condition_modifier_caps == condition_modifier_NOT )
	{
		modifier = condition_modifier::NOT;
	}
	else if( condition_modifier_caps == condition_modifier_NONE )
	{
		modifier = condition_modifier::NONE;
	}
	else
	{
		throw sx::genesis::genesis_exception( "Invalid condition modifier!" );
	}
	return ( modifier );
}


}


}
