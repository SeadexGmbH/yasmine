//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "recipe.hpp"

#include "file_writer.hpp"
#include "genesis_exception.hpp"


namespace sx
{


namespace genesis
{


recipe::recipe( const std::string& _template_name, recipe_callback& _recipe_callback, 
	const std::string& _templates_path ) :
		template_block( _template_name, _templates_path ),
		recipe_callback_( _recipe_callback ),
		stream_()
{
	// Nothing to do...
}


recipe::~recipe() SX_NOEXCEPT
{
	// Nothing to do...
}


void recipe::generate()
{
	create_impl( recipe_callback_ );
}


void recipe::write_to_file( const std::string& _file_path ) const
{
	write( _file_path, stream_ );
}


void recipe::create_impl( recipe_callback& _recipe_callback )
{
	template_block::create( _recipe_callback, stream_ );
}


}


}
