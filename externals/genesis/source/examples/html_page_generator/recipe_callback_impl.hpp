//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex genesis library (http://genesis.seadex.de).                      //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://genesis.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef RECIPE_CALLBACK_IMPL_D1209279_561E_435D_B6DC_68F2A50937C2
#define RECIPE_CALLBACK_IMPL_D1209279_561E_435D_B6DC_68F2A50937C2


#include "recipe_callback.hpp"

#include "config.hpp"


namespace examples
{


class recipe_callback_impl SX_FINAL
	: public sx::genesis::recipe_callback
{
public:
	explicit recipe_callback_impl( const config& _config );
	virtual ~recipe_callback_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( recipe_callback_impl )
	virtual std::string get_variable_content( const std::string& _variable_name ) SX_OVERRIDE;
	virtual void before_loop( const std::string& _loop_name ) SX_OVERRIDE;
	virtual void before_loop_iteration( const std::string& _loop_name ) SX_OVERRIDE;
	virtual void after_loop_iteration( const std::string& _loop_name ) SX_OVERRIDE;
	virtual bool check_loop_condition( const std::string& _loop_name ) const SX_OVERRIDE;
	virtual void after_loop( const std::string& _loop_name ) SX_OVERRIDE;
	virtual bool check_condition( const std::string& _condition_name ) const SX_OVERRIDE;
	virtual void condition_begin( const std::string& _condition_name ) SX_OVERRIDE;
	virtual void condition_end( const std::string& _condition_name ) SX_OVERRIDE;
	virtual int get_switch_case( const std::string& _switch_name ) SX_OVERRIDE;


private:
	const config& config_;
	std::size_t country_index_;
	std::size_t city_index_;
};


}


#endif
