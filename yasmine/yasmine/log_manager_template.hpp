//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef LOG_MANAGER_TEMPLATE_F6D33798_A43A_4C29_86F1_0FC821B92F9B
#define LOG_MANAGER_TEMPLATE_F6D33798_A43A_4C29_86F1_0FC821B92F9B


#include <string>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "base.hpp"
#include "logger.hpp"
#include "log_message.hpp"
#include "log_level.hpp"
#include "yprintf.hpp"


namespace sxy
{


namespace
{


bool LOG_MANAGER_EXISTS = false;


}

//!\class	t_log_manager_template
//!\brief The log manager (a singleton) controls the different loggers, manages the current log level, and takes care
//!of dispatching log messages.
template< typename time_stamp_policy > 
class log_manager_template final
{
public:
	//!\brief Get a reference to the single instance of the log manager template.
	static log_manager_template& get_instance( void )
	{
		static log_manager_template instance;
		return( instance );
	}


	log_manager_template( const log_manager_template& ) = delete;
	log_manager_template& operator=( const log_manager_template& ) = delete;

	//!\brief Gets the currently set log level.
	//!\return Current log level.
	log_level get_log_level() const
	{
		return( log_level_ );
	}


	//!\brief Sets a new log level.
	//!\param _log_level Log level to be set.
	//!\return void
	void set_log_level( const log_level _log_level )
	{
		log_level_ = _log_level;
	}


	//!\brief Add a message to the queue of messages that will be processed.
	//!\param	_log_level Log level of the message.
	//!\param	_time_stamp Date and time when the log message was created.
	//!\param	_file The file from where the log was called.
	//!\param	_line The line from where the log was called.
	//!\param	_message The message text for the log.
	//!\param	_args Parameters that are inserted in the message.
	//!\return void
	//!\sa Y_LOG(), yprintf
	template< typename ... args > 
	void log( const log_level _log_level, const std::string& _time_stamp,	const std::string& _file,	const int _line,
		const std::string& _message, args ... _args )
	{
		{
			log_message message( _log_level, _time_stamp, _file, _line, sxy::yprintf( _message.c_str(), _args ... ) );
			std::lock_guard< std::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
	}


	//!\brief Adds a logger to which the log will be written.
	//!\param _logger - The logger to be added.
	//!\return void
	void add_logger( logger_uptr _logger )
	{
		Y_ASSERT_NO_LOG( stop_, "Logger cannot be added while running!" );
		std::lock_guard< std::mutex > lock( mutex_ );
		loggers_.push_back( std::move( _logger ) );
	}


	//!\brief Starts the logging. On starting, a new thread is created which processes the enqueued log message by
	//!sending them to each logger. The thread has to be stopped and joined before the	log manager is destroyed!
	//!\return void
	//!\sa stop, join
	void start()
	{
		stop_ = false;
		thread_ = std::thread( [ this ] ()
			{
				this->work();
			}
			);
	}


	//!\brief Stops the logging. The thread that processes the log messages is notified that it should stop. It still has
	//!to be joined later.
	//!\return void
	//!\sa start, join
	void stop()
	{
		{
			std::lock_guard< std::mutex > lock( mutex_ );
			stop_ = true;
		}
		condition_.notify_one();
	}


	//!\brief Joins the thread that processed the log messages. Join has to be called after the stop function.
	//!\return void
	//!\sa stop, start
	void join()
	{
		thread_.join();
	}


	//!\brief Gets the current date and time as a string.
	//!\return String containing the date and time.
	static std::string get_timestamp()
	{
		return( time_stamp_policy::get_timestamp() );
	}


private:
	log_manager_template()
		: thread_(),
			mutex_(),
			condition_(),
			stop_( true ),
			loggers_(),
			messages_(),
			log_level_( log_level::LL_SPAM )
	{
		Y_ASSERT_NO_LOG( !LOG_MANAGER_EXISTS, "Log manager already exists!" );
		LOG_MANAGER_EXISTS = true;
	}


	~log_manager_template() = default;


	bool should_be_running() const
	{
		return( stop_ || !messages_.empty() );
	}


	bool finished() const
	{
		return( stop_ && messages_.empty() );
	}


	void work()
	{
		while( true )
		{
			log_message message;
			{
				std::unique_lock< std::mutex > lock( mutex_ );
				condition_.wait( lock, [ this ] ()
					{
						return( this->should_be_running() );
					}
					);
				if( finished() )
				{
					break;
				}

				message = messages_.front();
				messages_.pop();
			}

			for( auto & logger : loggers_ )
			{
				logger->log( message );
			}
		}
	}


	std::thread thread_;
	std::mutex mutex_;
	std::condition_variable condition_;
	bool stop_;
	loggers loggers_;
	std::queue< log_message > messages_;
	log_level log_level_;
};


}


#include "base_end.hpp"


#endif
