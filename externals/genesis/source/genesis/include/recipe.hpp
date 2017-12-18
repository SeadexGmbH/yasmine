//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef RECIPE_20F2FCF1_99D0_4CC6_9E59_3E9BE7C1A2A6
#define RECIPE_20F2FCF1_99D0_4CC6_9E59_3E9BE7C1A2A6


#include "template_block.hpp"


namespace sx
{


namespace genesis
{


class recipe_step;

//!\class recipe
//!\brief Class for generating code from the given template and using the given callback. It can write the generated code 
//!\to the given file.
class recipe : public template_block
{
public:
	//!\brief Constructor
	//!\param _template_name Name of the file containing the used template.
	//!\param _recipe_callback Generator callback
	//!\param _templates_path Path to the templates folder.
	explicit recipe( const std::string& _template_name, recipe_callback& _recipe_callback, 
		const std::string& _templates_path );
	virtual ~recipe() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( recipe )

	//!\brief Generates the code in a internal stream.
	void generate();

	//!\brief Write the generated code to the file with the given name.
	//!\param _file_path Path of the while to which the generated code will be written.
	void write_to_file( const std::string& _file_path ) const;


private:
	void create_impl( recipe_callback& _recipe_callback );

	recipe_callback& recipe_callback_;
	std::stringstream stream_;
};


}


}


#endif
