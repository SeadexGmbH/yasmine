//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef Y_NO_LOGGING


#ifndef LOG_MANAGER_TEMPLATE_F6D33798_A43A_4C29_86F1_0FC821B92F9B
#define LOG_MANAGER_TEMPLATE_F6D33798_A43A_4C29_86F1_0FC821B92F9B


#include <queue>

#include "base.hpp"
#include "logger.hpp"
#include "log_message.hpp"
#include "yprintf.hpp"
#include "waiter.hpp"


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
class log_manager_template Y_FINAL
{
public:
	//!\brief Get a reference to the single instance of the log manager template.
	static log_manager_template& get_instance( void )
	{
		static log_manager_template instance;
		return( instance );
	}


	Y_NO_COPY(log_manager_template)	

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


#ifndef Y_CPP03_BOOST


	//!\brief Add a message to the queue of messages that will be processed.
	//!\param	_log_level Log level of the message.
	//!\param	_time_stamp Date and time when the log message was created.
	//!\param	_file The file from where the log was called.
	//!\param	_line The line from where the log was called.
	//!\param	_message The message text for the log.
	//!\param	_args Parameters that are inserted in the message.
	//!\return void
	//!\sa log_and_wait, Y_LOG(), yprintf
	template< typename ... args > 
	void log( const log_level _log_level, const std::string& _time_stamp,	const std::string& _file,	const int _line,
		const std::string& _message, args ... _args )
	{
		{				
			log_message message( Y_NULLPTR, _log_level, _time_stamp, _file, _line, sxy::yprintf( _message.c_str(), _args ... ) );			
			sxy::lock_guard< sxy::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
	}


	//!\brief Add a message to the queue of messages and waits the message to be processed.
	//!\param	_log_level Log level of the message.
	//!\param	_time_stamp Date and time when the log message was created.
	//!\param	_file The file from where the log was called.
	//!\param	_line The line from where the log was called.
	//!\param	_message The message text for the log.
	//!\param	_args Parameters that are inserted in the message.
	//!\return void
	//!\sa log, Y_LOG(), yprintf
	template< typename ... args >
	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, args ... _args )
	{
		waiter waiter;
		{			
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxy::yprintf( _message.c_str(), _args ... ) );
			sxy::lock_guard< sxy::mutex > lock( mutex_ );
			messages_.push( message );			
		}
		condition_.notify_one();
		waiter.wait();
	}


#else
	void log(const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message)
	{
		{
			log_message message( Y_NULLPTR, _log_level, _time_stamp, _file, _line, sxy::yprintf( _message.c_str() ) );
			sxy::lock_guard< sxy::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}


	void log(const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value)
	{
		{
			log_message message( Y_NULLPTR, _log_level, _time_stamp, _file, _line, sxy::yprintf(_message.c_str(), _value) );
			sxy::lock_guard< sxy::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}


	void log(const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value1, const log_value& _value2)
	{
		{
			log_message message( Y_NULLPTR, _log_level, _time_stamp, _file, _line, sxy::yprintf(_message.c_str(), _value1, 
				_value2) );
			sxy::lock_guard< sxy::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}


	void log(const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value1, const log_value& _value2, const log_value& _value3)
	{
		{
			log_message message( Y_NULLPTR, _log_level, _time_stamp, _file, _line, sxy::yprintf(_message.c_str(), _value1, _value2,
				_value3));
			sxy::lock_guard< sxy::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}


	void log(const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value1, const log_value& _value2, const log_value& _value3, 
		const log_value& _value4)
	{
		{
			log_message message( Y_NULLPTR, _log_level, _time_stamp, _file, _line, sxy::yprintf(_message.c_str(), _value1, _value2,
				_value3, _value4));
			sxy::lock_guard< sxy::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}


	void log(const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value1, const log_value& _value2, const log_value& _value3,
		const log_value& _value4, const log_value& _value5 )
	{
		{
			log_message message( Y_NULLPTR, _log_level, _time_stamp, _file, _line, sxy::yprintf(_message.c_str(), _value1, _value2,
				_value3, _value4, _value5));
			sxy::lock_guard< sxy::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}


	void log(const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value1, const log_value& _value2, const log_value& _value3,
		const log_value& _value4, const log_value& _value5, const log_value& _value6)
	{
		{
			log_message message( Y_NULLPTR, _log_level, _time_stamp, _file, _line, sxy::yprintf(_message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6));
			sxy::lock_guard< sxy::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}


	void log(const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value1, const log_value& _value2, const log_value& _value3,
		const log_value& _value4, const log_value& _value5, const log_value& _value6, const log_value& _value7)
	{
		{
			log_message message( Y_NULLPTR, _log_level, _time_stamp, _file, _line, sxy::yprintf(_message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6, _value7) );
			sxy::lock_guard< sxy::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}


	void log(const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value1, const log_value& _value2, const log_value& _value3,
		const log_value& _value4, const log_value& _value5, const log_value& _value6, const log_value& _value7, 
		const log_value& _value8)
	{
		{
			log_message message( Y_NULLPTR, _log_level, _time_stamp, _file, _line, sxy::yprintf(_message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6, _value7, _value8) );
			sxy::lock_guard< sxy::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}


	void log(const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value1, const log_value& _value2, const log_value& _value3,
		const log_value& _value4, const log_value& _value5, const log_value& _value6, const log_value& _value7,
		const log_value& _value8, const log_value& _value9)
	{
		{
			log_message message( Y_NULLPTR, _log_level, _time_stamp, _file, _line, sxy::yprintf(_message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6, _value7, _value8, _value9) );
			sxy::lock_guard< sxy::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}			


	void log(const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value1, const log_value& _value2, const log_value& _value3,
		const log_value& _value4, const log_value& _value5, const log_value& _value6, const log_value& _value7,
		const log_value& _value8, const log_value& _value9, const log_value&  _value10)
	{
		{
			log_message message( Y_NULLPTR, _log_level, _time_stamp, _file, _line, sxy::yprintf(_message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6, _value7, _value8, _value9, _value10) );
			sxy::lock_guard< sxy::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}


//**************************************************log_and_wait**************************************************//


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxy::yprintf( _message.c_str() ) );
			sxy::lock_guard< sxy::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxy::yprintf( _message.c_str(), _value ) );
			sxy::lock_guard< sxy::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value1, const log_value& _value2 )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxy::yprintf( _message.c_str(), _value1, _value2 ) );
			sxy::lock_guard< sxy::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value1, const log_value& _value2, const log_value& _value3 )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxy::yprintf( _message.c_str(), _value1, _value2,
				_value3 ) );
			sxy::lock_guard< sxy::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value1, const log_value& _value2, const log_value& _value3,
		const log_value& _value4 )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxy::yprintf( _message.c_str(), _value1, _value2,
				_value3, _value4 ) );
			sxy::lock_guard< sxy::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value1, const log_value& _value2, const log_value& _value3,
		const log_value& _value4, const log_value& _value5 )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxy::yprintf( _message.c_str(), _value1, _value2,
				_value3, _value4, _value5 ) );
			sxy::lock_guard< sxy::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value1, const log_value& _value2, const log_value& _value3,
		const log_value& _value4, const log_value& _value5, const log_value& _value6 )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxy::yprintf( _message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6 ) );
			sxy::lock_guard< sxy::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value1, const log_value& _value2, const log_value& _value3,
		const log_value& _value4, const log_value& _value5, const log_value& _value6, const log_value& _value7 )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxy::yprintf( _message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6, _value7 ) );
			sxy::lock_guard< sxy::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value1, const log_value& _value2, const log_value& _value3,
		const log_value& _value4, const log_value& _value5, const log_value& _value6, const log_value& _value7,
		const log_value& _value8 )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxy::yprintf( _message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6, _value7, _value8 ) );
			sxy::lock_guard< sxy::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}			


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value1, const log_value& _value2, const log_value& _value3,
		const log_value& _value4, const log_value& _value5, const log_value& _value6, const log_value& _value7,
		const log_value& _value8, const log_value& _value9 )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxy::yprintf( _message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6, _value7, _value8, _value9 ) );
			sxy::lock_guard< sxy::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}			


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const log_value& _value1, const log_value& _value2, const log_value& _value3,
		const log_value& _value4, const log_value& _value5, const log_value& _value6, const log_value& _value7,
		const log_value& _value8, const log_value& _value9, const log_value&  _value10 )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxy::yprintf( _message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6, _value7, _value8, _value9, _value10 ) );
			sxy::lock_guard< sxy::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}



#endif


	//!\brief Adds a logger to which the log will be written.
	//!\param _logger - The logger to be added.
	//!\return void
	void add_logger( logger_uptr _logger )
	{
		Y_ASSERT_NO_LOG( stop_, "Logger cannot be added while running!" );
		sxy::lock_guard< sxy::mutex > lock( mutex_ );
		loggers_.push_back( sxy::move( _logger ) );
	}


	//!\brief Starts the logging. On starting, a new thread is created which processes the enqueued log message by
	//!sending them to each logger. The thread has to be stopped and joined before the	log manager is destroyed!
	//!\return void
	//!\sa halt, join
	void run()
	{
		stop_ = false;
		thread_ = sxy::thread( sxy::bind( &log_manager_template::work, this ) );
	}


	//!\brief Stops the logging. The thread that processes the log messages is notified that it should stop. It still has
	//!to be joined later.
	//!\return void
	//!\sa run, join, halt_and_join
	void halt()
	{
		{
			sxy::lock_guard< sxy::mutex > lock( mutex_ );
			stop_ = true;
		}
		condition_.notify_one();
	}


	//!\brief Joins the thread that processed the log messages. Join has to be called after the halt function.
	//!\return void
	//!\sa halt, run, halt_and_join
	void join()
	{
		thread_.join();
	}


	//!\brief Stops the logging and joins the thread that processed the log messages.
	//!\return void
	//!\sa halt, run, join
	void halt_and_join()
	{
		halt();
		join();
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
			log_level_( log_level::LL_OFF )
	{
		Y_ASSERT_NO_LOG( !LOG_MANAGER_EXISTS, "Log manager already exists!" );
		LOG_MANAGER_EXISTS = true;
	}


	~log_manager_template()
	{			
		Y_ASSERT_NO_LOG( stop_, "Thread is still running! It was not stopped." );
	}


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
				sxy::unique_lock< sxy::mutex > lock( mutex_ );
				condition_.wait( lock, sxy::bind( &log_manager_template::should_be_running, this ) );

				if( finished() )
				{
					break;
				}

				message = messages_.front();
				messages_.pop();
			}

			Y_FOR(const logger_uptr& logger, loggers_)
			{
				logger->log( message );
				message.done();
			}
		}
	}


	sxy::thread thread_;
	sxy::mutex mutex_;
	sxy::condition_variable condition_;
	bool stop_;
	loggers loggers_;
	std::queue< log_message > messages_;
	log_level log_level_;
};


}


#endif

#endif
