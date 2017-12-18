//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef LOG_AND_THROW_HELPER_048D9A04_8BD3_49F0_97EA_7DCB3D6E08FC
#define LOG_AND_THROW_HELPER_048D9A04_8BD3_49F0_97EA_7DCB3D6E08FC


#ifdef SX_CPP03_BOOST


#include <string>

#include "essentials/compatibility/compatibility.hpp"
#include "essentials/non_copyable.hpp"
#include "essentials/exception.hpp"
#include "log.hpp"


namespace hermes
{


	struct log_level;


	class log_and_throw_helper SX_FINAL
	{
	public:
		log_and_throw_helper( const std::string& _file_name, const int _line );
		~log_and_throw_helper() SX_NOEXCEPT;
		SX_NO_COPY( log_and_throw_helper )

		void log( const log_level& _level, const std::string& _message ) const;

		template< typename _parameter_type1 >
		void log( const log_level& _level, const std::string& _message, _parameter_type1 _value1 ) const
		{
			log_manager_template<std_timestamp_policy>& l_log_manager = log_manager::get_instance();
			if( _level <= l_log_manager.get_log_level() )
			{
				l_log_manager.log( _level, log_manager::get_instance().get_timestamp(), file_name_, line_, _message, _value1 );
			}
			throw sxe::exception( _message, _value1 );
		}


		template< typename _parameter_type1, typename _parameter_type2 >
		void log( const log_level& _level, const std::string& _message, _parameter_type1 _value1,
			_parameter_type2 _value2 ) const
		{
			log_manager_template<std_timestamp_policy>& l_log_manager = log_manager::get_instance();
			if( _level <= l_log_manager.get_log_level() )
			{
				l_log_manager.log( _level, log_manager::get_instance().get_timestamp(), file_name_, line_, _message, _value1,
					_value2 );
			}
			throw sxe::exception( _message, _value1, _value2 );
		}


		template< typename _parameter_type1, typename _parameter_type2, typename _parameter_type3 >
		void log( const log_level& _level, const std::string& _message, _parameter_type1 _value1,
			_parameter_type2 _value2, _parameter_type3 _value3 ) const
		{
			log_manager_template<std_timestamp_policy>& l_log_manager = log_manager::get_instance();
			if( _level <= l_log_manager.get_log_level() )
			{
				l_log_manager.log( _level, log_manager::get_instance().get_timestamp(), file_name_, line_, _message, _value1,
					_value2, _value3 );
			}
			throw sxe::exception( _message, _value1, _value2, _value3 );
		}


		template< typename _parameter_type1, typename _parameter_type2, typename _parameter_type3, 
			typename _parameter_type4 >
		void log( const log_level& _level, const std::string& _message, _parameter_type1 _value1,
			_parameter_type2 _value2, _parameter_type3 _value3, _parameter_type4 _value4 ) const
		{
			log_manager_template<std_timestamp_policy>& l_log_manager = log_manager::get_instance();
			if( _level <= l_log_manager.get_log_level() )
			{
				l_log_manager.log( _level, log_manager::get_instance().get_timestamp(), file_name_, line_, _message, _value1,
					_value2, _value3, _value4 );
			}
			throw sxe::exception( _message, _value1, _value2, _value3, _value4 );
		}


		template< typename _parameter_type1, typename _parameter_type2, typename _parameter_type3, 
			typename _parameter_type4, typename _parameter_type5 >
		void log( const log_level& _level, const std::string& _message, _parameter_type1 _value1,
			_parameter_type2 _value2, _parameter_type3 _value3, _parameter_type4 _value4, _parameter_type5 _value5 ) const
		{
			log_manager_template<std_timestamp_policy>& l_log_manager = log_manager::get_instance();
			if( _level <= l_log_manager.get_log_level() )
			{
				l_log_manager.log( _level, log_manager::get_instance().get_timestamp(), file_name_, line_, _message, 
					_value1, _value2, _value3, _value4, _value5 );
			}
			throw sxe::exception( _message, _value1, _value2, _value3, _value4, _value5 );
		}


		template< typename _parameter_type1, typename _parameter_type2, typename _parameter_type3, 
			typename _parameter_type4, typename _parameter_type5, typename _parameter_type6 >
			void log( const log_level& _level, const std::string& _message, _parameter_type1 _value1,
				_parameter_type2 _value2, _parameter_type3 _value3, _parameter_type4 _value4, _parameter_type5 _value5,
				_parameter_type6 _value6 ) const
		{
			log_manager_template<std_timestamp_policy>& l_log_manager = log_manager::get_instance();
			if( _level <= l_log_manager.get_log_level() )
			{
				l_log_manager.log( _level, log_manager::get_instance().get_timestamp(), file_name_, line_, _message, 
					_value1, _value2, _value3, _value4, _value5, _value6 );
			}
			throw sxe::exception( _message, _value1, _value2, _value3, _value4, _value5, _value6 );
		}


		template< typename _parameter_type1, typename _parameter_type2, typename _parameter_type3, 
			typename _parameter_type4, typename _parameter_type5, typename _parameter_type6, typename _parameter_type7 >
			void log( const log_level& _level, const std::string& _message, _parameter_type1 _value1,
				_parameter_type2 _value2, _parameter_type3 _value3, _parameter_type4 _value4, _parameter_type5 _value5,
				_parameter_type6 _value6, _parameter_type7 _value7 ) const
		{
			log_manager_template<std_timestamp_policy>& l_log_manager = log_manager::get_instance();
			if( _level <= l_log_manager.get_log_level() )
			{
				l_log_manager.log( _level, log_manager::get_instance().get_timestamp(), file_name_, line_, _message, 
					_value1, _value2, _value3, _value4, _value5, _value6, _value7 );
			}
			throw sxe::exception( _message, _value1, _value2, _value3, _value4, _value5, _value6, _value7 );
		}


		template< typename _parameter_type1, typename _parameter_type2, typename _parameter_type3, 
			typename _parameter_type4, typename _parameter_type5, typename _parameter_type6, typename _parameter_type7,
			typename _parameter_type8 >
			void log( const log_level& _level, const std::string& _message, _parameter_type1 _value1,
				_parameter_type2 _value2, _parameter_type3 _value3, _parameter_type4 _value4, _parameter_type5 _value5,
				_parameter_type6 _value6, _parameter_type7 _value7, _parameter_type8 _value8 ) const
		{
			log_manager_template<std_timestamp_policy>& l_log_manager = log_manager::get_instance();
			if( _level <= l_log_manager.get_log_level() )
			{
				l_log_manager.log( _level, log_manager::get_instance().get_timestamp(), file_name_, line_, _message, _value1,
					_value2, _value3, _value4, _value5, _value6, _value7, _value8 );
			}
			throw sxe::exception( _message, _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8 );
		}


		template< typename _parameter_type1, typename _parameter_type2, typename _parameter_type3, 
			typename _parameter_type4, typename _parameter_type5, typename _parameter_type6, typename _parameter_type7,
			typename _parameter_type8, typename _parameter_type9 >
			void log( const log_level& _level, const std::string& _message, _parameter_type1 _value1,
				_parameter_type2 _value2, _parameter_type3 _value3, _parameter_type4 _value4, _parameter_type5 _value5,
				_parameter_type6 _value6, _parameter_type7 _value7, _parameter_type8 _value8, _parameter_type9 _value9 ) const
		{
			log_manager_template<std_timestamp_policy>& l_log_manager = log_manager::get_instance();
			if( _level <= l_log_manager.get_log_level() )
			{
				l_log_manager.log( _level, log_manager::get_instance().get_timestamp(), file_name_, line_, _message, 
					_value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8, _value9 );
			}
			throw sxe::exception( _message, _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8, _value9 );
		}


		template< typename _parameter_type1, typename _parameter_type2, typename _parameter_type3, 
			typename _parameter_type4, typename _parameter_type5, typename _parameter_type6, typename _parameter_type7,
			typename _parameter_type8, typename _parameter_type9, typename _parameter_type10 >
			void log( const log_level& _level, const std::string& _message, _parameter_type1 _value1,
				_parameter_type2 _value2, _parameter_type3 _value3, _parameter_type4 _value4, _parameter_type5 _value5,
				_parameter_type6 _value6, _parameter_type7 _value7, _parameter_type8 _value8, _parameter_type9 _value9,
				_parameter_type10 _value10 ) const
		{
			log_manager_template<std_timestamp_policy>& l_log_manager = log_manager::get_instance();
			if( _level <= l_log_manager.get_log_level() )
			{
				l_log_manager.log( _level, log_manager::get_instance().get_timestamp(), file_name_, line_, _message, 
					_value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8, _value9, _value10 );
			}
			throw sxe::exception( _message, _value1, _value2, _value3, _value4, _value5, _value6, _value7, _value8, _value9,
				_value10 );
		}

	private:
		const std::string& file_name_;
		const int line_;


	};


}


#endif


#endif
