//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "config.hpp"


namespace examples
{


// DONE variable names lower case
config::config() :
	template_path_( "./templates" ),
	source_template_file_ ("countries.gtpl"),
	output_file_( "countries.html"),
	countries_()
{
	city berlin;
	berlin.name_ = "Berlin";
	berlin.population_ = 3275000;

	city hamburg;
	hamburg.name_ = "Hamburg";
	hamburg.population_ = 1686100;

	city stuttgart;
	stuttgart.name_ = "Stuttgart";
	stuttgart.population_ = 581100;

	city munich;
	munich.name_ = "Munich";
	munich.population_ = 1185400;

	city frankfurt;
	frankfurt.name_ = "Frankfurt";
	frankfurt.population_ = 648000;

	city dresden;
	dresden.name_ = "Dresden";
	dresden.population_ = 473300;
		
	country germany;
	germany.name_ = "Germany";
	germany.cities_.push_back( berlin );
	germany.cities_.push_back( hamburg );
	germany.cities_.push_back( stuttgart );
	germany.cities_.push_back( munich );
	germany.cities_.push_back( frankfurt );
	germany.cities_.push_back( dresden );
	germany.capital_index_ = 0;


	city new_york;
	new_york.name_ = "New York";
	new_york.population_ = 8550405;

	city los_angeles;
	los_angeles.name_ = "Los Angeles";
	los_angeles.population_ = 3971883;

	city chicago;
	chicago.name_ = "Chicago";
	chicago.population_ = 2720546;

	city houston;
	houston.name_ = "Houston";
	houston.population_ = 2296224;

	city phoenix;
	phoenix.name_ = "Phoenix";
	phoenix.population_ = 1563025;

	city austin;
	austin.name_ = "Austin";
	austin.population_ = 931830;

	city san_francisco;
	san_francisco.name_ = "San Francisco";
	san_francisco.population_ = 864816;

	city honolulu;
	honolulu.name_ = "Honolulu";
	honolulu.population_ = 352769;

	city washington;
	washington.name_ = "Washington";
	washington.population_ = 672228;

	country usa;
	usa.name_ = "United States of America";
	usa.cities_.push_back( new_york );
	usa.cities_.push_back( los_angeles );
	usa.cities_.push_back( chicago );
	usa.cities_.push_back( washington );
	usa.cities_.push_back( houston );
	usa.cities_.push_back( phoenix );
	usa.cities_.push_back( austin );
	usa.cities_.push_back( san_francisco );
	usa.cities_.push_back( honolulu );	
	usa.capital_index_ = 3;
	

	city tokyo;
	tokyo.name_ = "Tokyo";
	tokyo.population_ = 8637098;

	city yokohama;
	yokohama.name_ = "Yokohama";
	yokohama.population_ = 3697894;

	city osaka;
	osaka.name_ = "Osaka";
	osaka.population_ = 2668586;

	city sapporo;
	sapporo.name_ = "Sapporo";
	sapporo.population_ = 1918096;

	city hiroshima;
	hiroshima.name_ = "Hiroshima";
	hiroshima.population_ = 1163806;

	country japan;
	japan.name_ = "Japan";
	japan.cities_.push_back( hiroshima );
	japan.cities_.push_back( sapporo );
	japan.cities_.push_back( osaka );
	japan.cities_.push_back( yokohama );
	japan.cities_.push_back( tokyo );
	japan.capital_index_ = 4;


	countries_.push_back( germany );
	countries_.push_back( usa );
	countries_.push_back( japan );
}


}
