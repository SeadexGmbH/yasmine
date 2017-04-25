//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef SWITCH_BLOCK_DBBA48C9_294D_4F33_8424_CCD31767B4BC
#define SWITCH_BLOCK_DBBA48C9_294D_4F33_8424_CCD31767B4BC


#include "recipe_block.hpp"

#include <map>


namespace sx
{


namespace genesis
{


//!\class switch_block
//!\brief class representing an 'switch'. This block can have children.
class switch_block SX_FINAL
	: public recipe_block
{
public:
	//!\brief constructor
	//!\param _switch_name Name of the switch block.
	explicit switch_block( const std::string& _switch_name );
	virtual ~switch_block() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( switch_block )

	//!\brief Create the output for a step.
	//!\param _recipe_callback Generator callback
	//!\param _ostream stream to which the generator writes.
	virtual void create( recipe_callback& _recipe_callback, std::stringstream& _ostream ) SX_OVERRIDE;

	//!\brief Create the output for a step.
	//!\param _recipe_callback Generator callback
	//!\param _ostream Stream to which the generator writes.
	virtual void create_children( recipe_callback& _recipe_callback, std::stringstream& _ostream ) SX_OVERRIDE;

	//!\brief Add a child to the list of children.
	//!\param _child New child
	virtual void add_child( sxe::SX_UNIQUE_PTR<recipe_step> _child ) SX_OVERRIDE;


	//!\brief Set the internal index for the current case. This is only used during parsing of a template.
	//!\param _index Index value. Index value must be greater than or equal to zero.
	void set_case_index( const int _index );


private:
	const std::string switch_name_;
	int current_case_index_;
	std::map< int, std::vector< sxe::SX_UNIQUE_PTR<recipe_step> > > switch_cases_;
	std::vector< sxe::SX_UNIQUE_PTR<recipe_step> > default_;


};


}


}


#endif
