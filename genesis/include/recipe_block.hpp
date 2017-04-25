//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef RECIPE_BLOCK_A5AF03FF_E23E_4887_A4C8_44C6E8605983
#define RECIPE_BLOCK_A5AF03FF_E23E_4887_A4C8_44C6E8605983


#include <vector>

#include "recipe_step.hpp"


namespace sx
{


namespace genesis
{

//!\class recipe_block
//!\brief Class that represents a recipe block. This block can have children.
class recipe_block : public recipe_step
{
public:
	//!\brief Constructor
	explicit recipe_block();
	virtual ~recipe_block() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( recipe_block )

	//!\brief Add a child to the list of children.
	//!\param _child New child
	virtual void add_child( sxe::SX_UNIQUE_PTR<recipe_step> _child );


protected:
	//!\brief Create the output for a step.
	//!\param _recipe_callback Generator callback
	//!\param _ostream Stream to which the generator writes.
	virtual void create_children( recipe_callback& _recipe_callback, std::stringstream& _ostream );


private:
	std::vector< sxe::SX_UNIQUE_PTR<recipe_step> > child_recipes_;
};


}


}


#endif