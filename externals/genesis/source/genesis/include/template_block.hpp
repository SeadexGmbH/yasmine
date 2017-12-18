//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef TEMPLATE_BLOCK_43849414_0A6E_429C_9D51_FB0562A58B05
#define TEMPLATE_BLOCK_43849414_0A6E_429C_9D51_FB0562A58B05


#include <stack>

#include "recipe_block.hpp"


namespace sx
{


namespace genesis
{


class text_step;
class variable_step;
class loop_block;
class condition_block;


//!\class template_block
//!\brief Class representing a recipe block created from a template file.
class template_block 
	: public recipe_block
{
public:
	//!\brief Constructor. Get the template file name and the path to the template directory.
	//!\param _template_name Name of the template file.
	//!\param _template_path Path to templates directory
	explicit template_block( const std::string& _template_name, const std::string& _template_path );
	virtual ~template_block() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( template_block )

	//!\brief Create the output for a step.
	//!\param _recipe_callback Generator callback
	//!\param _ostream Stream to which the generator writes.
	virtual void create( recipe_callback& _recipe_callback, std::stringstream& _ostream ) SX_OVERRIDE;


private:
	void parse( std::string& _file_buffer );
	void get_text( std::string &_file_buffer );
	std::string get_keyword( std::string& _file_buffer );
	void get_variable( std::string &_file_buffer );
	void get_loop( std::string &_file_buffer );
	void get_if( std::string &_file_buffer );
	void get_switch( std::string& _file_buffer );
	void get_switch_case( std::string& _file_buffer );
	void get_switch_default( std::string& _file_buffer );
	void get_template( std::string &_file_buffer );
	const std::string get_last_to_be_closed() const;			
	static std::string read_template_file( const std::string& _file_buffer, const std::string& _templates_path );
	void check_new_line_after_end_command( std::string &_file_buffer );
	void close_loop( std::string& _file_buffer );
	void close_condition( std::string& _file_buffer );
	void close_switch( std::string& _file_buffer );
	void close_switch_case( std::string& _file_buffer );
	void close_switch_default( std::string& _file_buffer );
	bool is_any_recipe_open() const;
	std::vector<std::string> get_parameters( std::string& _file_buffer ) const;
	void final_check() const;

	template<typename T>
	void add_child_to_recipe( sxe::SX_UNIQUE_PTR<T> _child )
	{
		if( opened_recipes_.empty() )
		{
			add_child( sxe::move( _child ) );
		}
		else
		{
			opened_recipes_.top()->add_child( sxe::move( _child ) );
		}
	}


	std::stack<recipe_block*> opened_recipes_;
	std::vector<std::string> keywords_;
	std::string template_to_parse_;
	const std::string& template_path_;
	const std::string& template_file_;
};


}


}


#endif
