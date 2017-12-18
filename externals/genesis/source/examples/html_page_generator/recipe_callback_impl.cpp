//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#include "recipe_callback_impl.hpp"

#include "essentials/base.hpp"
#include "essentials/conversion.hpp"
#include "essentials/exception.hpp"

#include "html_generator_grammar.hpp"


namespace examples
{
	recipe_callback_impl::recipe_callback_impl( const config& _config ) :
		recipe_callback(),		
		config_( _config ),
		country_index_( 0 ),
		city_index_( 0 )
	// DONE odd indent
	{
		// Nothing to do...
	}

	// DONE odd indent
	recipe_callback_impl::~recipe_callback_impl() SX_NOEXCEPT
	{
		// Nothing to do...
	}


	std::string recipe_callback_impl::get_variable_content( const std::string& _variable_name )
	{
		std::string result( "" );
		if( _variable_name == CITY_NAME )
		{
			result = config_.countries_[country_index_].cities_[city_index_].name_;
		}
		else if( _variable_name == CITY_POPULATION )
		{
			result = sxe::to_string( config_.countries_[country_index_].cities_[city_index_].population_ );
		}
		else if( _variable_name == COUNTRY_NAME )
		{
			result = config_.countries_[country_index_].name_;
		}			
		return( result );
	}


	// cppcheck-suppress unusedFunction
	void recipe_callback_impl::before_loop( const std::string& _loop_name )
	{
		if( _loop_name == LOOP_COUNTRIES )
		{
			country_index_ = 0;
		}
		else if( _loop_name == LOOP_CITIES )
		{
			city_index_ = 0;
		}
	}


	// cppcheck-suppress unusedFunction
	void recipe_callback_impl::before_loop_iteration( const std::string& _loop_name )
	{
		SX_UNUSED_PARAMETER( _loop_name );
	}


	// cppcheck-suppress unusedFunction
	void recipe_callback_impl::after_loop_iteration( const std::string& _loop_name )
	{
		if( _loop_name == LOOP_COUNTRIES )
		{
			++country_index_;
		}
		else if( _loop_name == LOOP_CITIES )
		{
			++city_index_;
		}
	}


	// cppcheck-suppress unusedFunction
	void recipe_callback_impl::after_loop( const std::string& _loop_name )
	{
		SX_UNUSED_PARAMETER( _loop_name );		
	}


	// cppcheck-suppress unusedFunction
	bool recipe_callback_impl::check_loop_condition( const std::string& _loop_name ) const
	{
		bool result = false;

		if( _loop_name == LOOP_COUNTRIES )
		{
			result = country_index_ < config_.countries_.size();
		}
		else if( _loop_name == LOOP_CITIES )
		{
			result = city_index_ < config_.countries_[country_index_].cities_.size();
		}	

		return( result );
	}


	// cppcheck-suppress unusedFunction
	bool recipe_callback_impl::check_condition( const std::string& _condition_name ) const
	{
		bool result = true;

		if( _condition_name == CONDITION_IS_CAPITAL )
		{
			result = config_.countries_[country_index_].capital_index_ == city_index_;
		}

		return( result );
	}


	// cppcheck-suppress unusedFunction
	void recipe_callback_impl::condition_begin( const std::string& _condition_name )
	{
		SX_UNUSED_PARAMETER( _condition_name );
	}


	// cppcheck-suppress unusedFunction
	void recipe_callback_impl::condition_end( const std::string& _condition_name )
	{
		SX_UNUSED_PARAMETER( _condition_name );
	}
	
	
	int recipe_callback_impl::get_switch_case( const std::string& _switch_name )
	{
		int switch_case = -1;
		if( _switch_name == "town_name" )
		{			
			const int population = config_.countries_[country_index_].cities_[city_index_].population_;
			if( population > 10000000 )
			{
				switch_case = 0;
			} 
			else if(population > 3000000 )			
			{
				switch_case = 1;
			}
			else if( population > 1000000 )			
			{
				switch_case = 2;
			}
			else if( population > 300000 )
			{
				switch_case = 3;
			}			
			else if( population > 20000 )
			{
				switch_case = 4;
			}
			else if( population > 1000 )
			{
				switch_case = 5;
			}
			else if( population > 100 )
			{
				switch_case = 6;
			}
		}

		return( switch_case );
	}
	

}
