//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_FILE_LOGGER_0EE18DBE_D91D_407D_BF95_0EBC8A84EBD4
#define T_FILE_LOGGER_0EE18DBE_D91D_407D_BF95_0EBC8A84EBD4

#include <string>
#include <map>
#include <regex>

#include "i_logger.h"
#include "t_exception_template.h"


namespace sxy
{


// !\class
// !\brief Class for writing messages to a log file. It rotates the log file if a certain size limit is met. Naming and location of the log files can be customized.
// All the number of log files in rotation can be set.
class t_file_logger: public i_logger
{
public:
	// !\brief Exception class of the t_file_logger.
	Y_EXCEPTION( t_exception )


	// !\brief Constructor of t_file_logger.
	// !\param	p_max_file_size_in_bytes Maximum size of a log file in bytes.
	// !\param	p_log_files_directory Folder path where the log files are stored.
	// !\param	p_name_suffix The suffix for the log files.
	// !\param	p_name_extension The extension of the log files.
	// !\param	p_max_file_number The maximum number of log files.
	// !\param  p_throw_on_error Flag for throwing exception on error. Default is true.
	t_file_logger
	(
		const size_t p_max_file_size_in_bytes,
		const std::string& p_log_files_directory,
		const std::string& p_name_suffix,
		const std::string& p_name_extension,
		const unsigned p_max_file_number,
		const bool p_throw_on_error = true
	);


	virtual
	~t_file_logger
	(
	) = default;


	t_file_logger
	(
		const t_file_logger&
	) = delete;


	t_file_logger&
	operator=
	(
		const t_file_logger&
	) = delete;


	// !\brief Writes the message in the log file.
	// !\param p_log_message Log message that will be written.
	// !\return void
	virtual void
	log
	(
		const t_log_message& p_log_message
	) override;


private:
	std::string
	get_log_file_name_with_index
	(
		const unsigned p_index
	) const;


	std::string
	get_working_log_file_name
	(			
	) const;


	void
	log_into_file
	(			
		const std::string& p_message
	) const;


	void
	rotate_if_necessary
	(
	) const;


	void
	rename_files
	(
	) const;


	void
	rename_file_if_exists
	(
		const std::string& p_old_name,
		const std::string& p_new_name
	) const;


	void
	delete_file
	(
		const std::string& p_file_name
	) const;


	const size_t m_max_file_size_in_bytes;
	const std::string m_log_files_directory;
	const std::string m_name_sufix;
	const std::string m_name_extension;
	const unsigned m_max_file_number;
	const bool m_throw_on_error;
	std::string m_working_file;
};


}


#endif
