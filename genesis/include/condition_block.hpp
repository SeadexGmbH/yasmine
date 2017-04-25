//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CONDITION_BLOCK_3922737B_1A00_451A_AFCB_B29D0123210C
#define CONDITION_BLOCK_3922737B_1A00_451A_AFCB_B29D0123210C


#include "recipe_block.hpp"
#include "condition_modifier.hpp"


namespace sx
{


namespace genesis
{


//!\class confition_block
//!\brief class representing an 'if'. This block can have children.
class condition_block SX_FINAL
	: public recipe_block
{
public:
	//!\brief constructor
	//!\param _condition_name name of the condition block.
	//!\param _modifier condition modifier. default value is none.
	//!\sa condition_modifier
	explicit condition_block( const std::string& _condition_name, const condition_modifier& _modifier = condition_modifier::NONE );
	virtual ~condition_block() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( condition_block )

	//!\brief create the output for a step.
	//!\param _recipe_callback generator callback
	//!\param _ostream stream to which the generator writes.
	virtual void create( recipe_callback& _recipe_callback, std::stringstream& _ostream ) SX_OVERRIDE;


private:
	void apply_modifier( bool& _result ) const;

	const std::string condition_name_;
	const condition_modifier modifier_;
			

};


}


}


#endif
