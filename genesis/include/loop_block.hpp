//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef LOOP_BLOCK_08F296C5_8660_453B_9AE3_903E1AEE52D9
#define LOOP_BLOCK_08F296C5_8660_453B_9AE3_903E1AEE52D9


#include "recipe_block.hpp"


namespace sx
{


namespace genesis
{


//!\class loop_block
//!\brief Class representing a loop. This block can have children.
class loop_block SX_FINAL
	: public recipe_block
{
public:
	//!\brief Constructor
	//!\param _loop_name Name of the loop block.
	explicit loop_block( const std::string& _loop_name);
	virtual ~loop_block() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( loop_block )

	//!\brief Create the output for a step.
	//!\param _recipe_callback Generator callback
	//!\param _ostream Stream to which the generator writes.
	virtual void create( recipe_callback& _recipe_callback, std::stringstream& _ostream ) SX_OVERRIDE;


private:
	const std::string loop_name_;
};


}


}


#endif
