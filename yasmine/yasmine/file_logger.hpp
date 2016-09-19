//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef FILE_LOGGER_0EE18DBE_D91D_407D_BF95_0EBC8A84EBD4
#define FILE_LOGGER_0EE18DBE_D91D_407D_BF95_0EBC8A84EBD4

#include <string>
#include <map>
#include <regex>

#include "logger.hpp"
#include "exception_template.hpp"


namespace sxy
{


//!\class	file_logger
//!\brief Class for writing messages to a log file. It rotates the log file if a certain size limit is met. Naming and
//!location of the log files can be customized. All the number of log files in rotation can be set.
class file_logger:
	public logger
{
public:
	//!\brief Exception class of the file_logger.
	Y_EXCEPTION( exception )

	//!\brief Constructor of file_logger.
	//!\param	_max_file_size_in_bytes Maximum size of a log file in bytes.
	//!\param	_log_files_directory Folder path where the log files are stored.
	//!\param	_name_suffix The suffix for the log files.
	//!\param	_name_extension The extension of the log files.
	//!\param	_max_file_number The maximum number of log files.
	//!\param _throw_on_error Flag for throwing exception on error. Default is true.
	file_logger( const size_t _max_file_size_in_bytes,	const std::string& _log_files_directory,	
		const std::string& _name_suffix,	const std::string& _name_extension, const unsigned _max_file_number,
		const bool _throw_on_error = true );
	virtual ~file_logger() noexcept override = default;
	file_logger( const file_logger& ) = delete;
	file_logger& operator=( const file_logger& ) = delete;

	//!\brief Writes the message in the log file.
	//!\param _log_message Log message that will be written.
	//!\return void
	virtual void log( const log_message& _log_message ) override;


private:
	std::string get_log_file_name_with_index( const unsigned _index ) const;
	std::string get_working_log_file_name() const;
	void log_into_file( const std::string& _message ) const;
	void rotate_if_necessary() const;
	void rename_files() const;
	void rename_file_if_exists(	const std::string& _old_name, const std::string& _new_name ) const;
	void delete_file( const std::string& _file_name ) const;


	const size_t max_file_size_in_bytes_;
	const std::string log_files_directory_;
	const std::string name_sufix_;
	const std::string name_extension_;
	const unsigned max_file_number_;
	const bool throw_on_error_;
	std::string working_file_;
};


}


#endif
