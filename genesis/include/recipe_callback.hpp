//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef RECIPE_CALLBACK_94CA6C50_A463_41C9_B424_D595F361B6C2
#define RECIPE_CALLBACK_94CA6C50_A463_41C9_B424_D595F361B6C2


#include "essentials/compatibility/compatibility.hpp"
#include "essentials/non_copyable.hpp"

#include "condition_modifier.hpp"


namespace sx
{


namespace genesis
{


//!\interface
//!\brief Callback Interface that needs to be implemented by a generator.
class recipe_callback
{
public:
	//!\brief Constructor
	explicit recipe_callback()
	{
		// Nothing to do...
	}


	virtual ~recipe_callback() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	SX_NO_COPY( recipe_callback )

	//!\brief Get the content of a variable.
	//!\param _variable_name Name of the variable for which the value is requested.
	//!\return String Value of the given variable.
	virtual std::string get_variable_content( const std::string& _variable_name ) = 0;

	//!\brief Check the condition of a loop_block.
	//!\param _loop_name Name of the loop block that is executed.
	virtual bool check_loop_condition( const std::string& _loop_name ) const = 0;

	//!\brief Execute actions before a loop_block.
	//!\param _loop_name Name of the loop block that is executed.
	virtual void before_loop( const std::string& _loop_name ) = 0;

	//!\brief Execute actions before an iteration of a loop_block.
	//!\param _loop_name Name of the loop block that is executed.
	virtual void before_loop_iteration( const std::string& _loop_name ) = 0;

	//!\brief Execute actions after an iteration of a loop_block.
	//!\param _loop_name Name of the loop block that is executed.
	virtual void after_loop_iteration( const std::string& _loop_name ) = 0;

	//!\brief Execute actions after a loop_block.
	//!\param _loop_name Name of the loop block that is executed.
	virtual void after_loop( const std::string& _loop_name ) = 0;

	//!\brief Check the condition of a condition_block.
	//!\param _loop_name Name of the condition block that is executed.
	virtual bool check_condition( const std::string& _condition_name ) const = 0;

	//!\brief Execute actions before a condition_block.
	//!\param _loop_name Name of the condition block that is executed.
	virtual void condition_begin( const std::string& _condition_name ) = 0;

	//!\brief Execute actions after a condition_block.
	//!\param _loop_name Name of the condition block that is executed.
	virtual void condition_end( const std::string& _condition_name ) = 0;

	//!\brief Returns the index of the case of the switch with the given name which shall be executed.
	//!\param _switch_name Name of the switch block for which the case index is requested.
	//!\return The index of the case that shall be executed.
	virtual int get_switch_case( const std::string& _switch_name ) = 0;
};


}


}


#endif
