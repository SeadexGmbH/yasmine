//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex hermes library (http://hermes.seadex.de).                        //
// Copyright( C ) 2017 Seadex GmbH                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://hermes.seadex.de/License.html.             //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef LOG_MANAGER_TEMPLATE_F6D33798_A43A_4C29_86F1_0FC821B92F9B
#define LOG_MANAGER_TEMPLATE_F6D33798_A43A_4C29_86F1_0FC821B92F9B

#include "hermes_backward_compatibility.hpp"


#ifndef SX_NO_LOGGING


#include <queue>

#include "essentials/base.hpp"
#include "logger.hpp"
#include "log_message.hpp"
#include "essentials/sxprintf.hpp"
#include "waiter.hpp"


namespace hermes
{


namespace
{


bool LOG_MANAGER_EXISTS = false;


}

//!\class t_log_manager_template
//!\brief The log manager (a singleton) controls the different loggers, manages the current log level, and takes care
//!of dispatching log messages.
template< typename time_stamp_policy > 
class log_manager_template SX_FINAL
{
public:
	//!\brief Get a reference to the single instance of the log manager template.
	static log_manager_template& get_instance( void )
	{
		static log_manager_template instance;
		return( instance );
	}


	SX_NO_COPY(log_manager_template)

	//!\brief Get the currently set log level.
	//!\return Current log level.
	log_level get_log_level() const
	{
		return( log_level_ );
	}


	//!\brief Set a new log level.
	//!\param _log_level Log level to be set.
	//!\return void
	void set_log_level( const log_level _log_level )
	{
		log_level_ = _log_level;
	}


#ifndef SX_CPP03_BOOST


	//!\brief Add a message to the queue of messages that will be processed.
	//!\param _log_level Log level of the message.
	//!\param _time_stamp Date and time when the log message was created.
	//!\param _file The file from where the log was called.
	//!\param _line The line from where the log was called.
	//!\param _message The message text for the log.
	//!\param _args Parameters that are inserted in the message.
	//!\return void
	//!\sa log_and_wait, SX_LOG(), sxprintf
	template< typename ... args > 
	void log( const log_level _log_level, const std::string& _time_stamp,	const std::string& _file,	const int _line,
		const std::string& _message, args ... _args )
	{
		{
			log_message message( SX_NULLPTR, _log_level, _time_stamp, _file, _line, sxe::sxprintf( _message.c_str(), _args ... ) );
			sxe::lock_guard< sxe::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
	}


	//!\brief Add a message to the queue of messages and waits the message to be processed.
	//!\param _log_level Log level of the message.
	//!\param _time_stamp Date and time when the log message was created.
	//!\param _file The file from where the log was called.
	//!\param _line The line from where the log was called.
	//!\param _message The message text for the log.
	//!\param _args Parameters that are inserted in the message.
	//!\return void
	//!\sa log, SX_LOG(), sxprintf
	template< typename ... args >
	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, args ... _args )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxe::sxprintf( _message.c_str(), _args ... ) );
			sxe::lock_guard< sxe::mutex > lock( mutex_ );
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
			log_message message( SX_NULLPTR, _log_level, _time_stamp, _file, _line, sxe::sxprintf( _message.c_str() ) );
			sxe::lock_guard< sxe::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}


	void log(const hermes::log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value)
	{
		{
			log_message message( SX_NULLPTR, _log_level, _time_stamp, _file, _line, sxe::sxprintf(_message.c_str(), _value) );
			sxe::lock_guard< sxe::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}


	void log(const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value1, const sxe::value_type& _value2)
	{
		{
			log_message message( SX_NULLPTR, _log_level, _time_stamp, _file, _line, sxe::sxprintf(_message.c_str(), _value1, 
				_value2) );
			sxe::lock_guard< sxe::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}


	void log(const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3)
	{
		{
			log_message message( SX_NULLPTR, _log_level, _time_stamp, _file, _line, sxe::sxprintf(_message.c_str(), _value1, _value2,
				_value3));
			sxe::lock_guard< sxe::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}


	void log(const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3,
		const sxe::value_type& _value4)
	{
		{
			log_message message( SX_NULLPTR, _log_level, _time_stamp, _file, _line, sxe::sxprintf(_message.c_str(), _value1, _value2,
				_value3, _value4));
			sxe::lock_guard< sxe::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}


	void log(const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3,
		const sxe::value_type& _value4, const sxe::value_type& _value5 )
	{
		{
			log_message message( SX_NULLPTR, _log_level, _time_stamp, _file, _line, sxe::sxprintf(_message.c_str(), _value1, _value2,
				_value3, _value4, _value5));
			sxe::lock_guard< sxe::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}


	void log(const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3,
		const sxe::value_type& _value4, const sxe::value_type& _value5, const sxe::value_type& _value6)
	{
		{
			log_message message( SX_NULLPTR, _log_level, _time_stamp, _file, _line, sxe::sxprintf(_message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6));
			sxe::lock_guard< sxe::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}


	void log(const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3,
		const sxe::value_type& _value4, const sxe::value_type& _value5, const sxe::value_type& _value6, const sxe::value_type& _value7)
	{
		{
			log_message message( SX_NULLPTR, _log_level, _time_stamp, _file, _line, sxe::sxprintf(_message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6, _value7) );
			sxe::lock_guard< sxe::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}


	void log(const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3,
		const sxe::value_type& _value4, const sxe::value_type& _value5, const sxe::value_type& _value6, const sxe::value_type& _value7,
		const sxe::value_type& _value8)
	{
		{
			log_message message( SX_NULLPTR, _log_level, _time_stamp, _file, _line, sxe::sxprintf(_message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6, _value7, _value8) );
			sxe::lock_guard< sxe::mutex > lock(mutex_);
			messages_.push(message);
		}
		condition_.notify_one();
	}


	void log( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3,
		const sxe::value_type& _value4, const sxe::value_type& _value5, const sxe::value_type& _value6, const sxe::value_type& _value7,
		const sxe::value_type& _value8, const sxe::value_type& _value9 )
	{
		{
			log_message message( SX_NULLPTR, _log_level, _time_stamp, _file, _line, sxe::sxprintf( _message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6, _value7, _value8, _value9 ) );
			sxe::lock_guard< sxe::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
	}


	void log( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3,
		const sxe::value_type& _value4, const sxe::value_type& _value5, const sxe::value_type& _value6, const sxe::value_type& _value7,
		const sxe::value_type& _value8, const sxe::value_type& _value9, const sxe::value_type&  _value10 )
	{
		{
			log_message message( SX_NULLPTR, _log_level, _time_stamp, _file, _line, sxe::sxprintf( _message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6, _value7, _value8, _value9, _value10 ) );
			sxe::lock_guard< sxe::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
	}


//**************************************************log_and_wait**************************************************//


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxe::sxprintf( _message.c_str() ) );
			sxe::lock_guard< sxe::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxe::sxprintf( _message.c_str(), _value ) );
			sxe::lock_guard< sxe::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value1, const sxe::value_type& _value2 )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxe::sxprintf( _message.c_str(), _value1, _value2 ) );
			sxe::lock_guard< sxe::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3 )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxe::sxprintf( _message.c_str(), _value1, _value2,
				_value3 ) );
			sxe::lock_guard< sxe::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3,
		const sxe::value_type& _value4 )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxe::sxprintf( _message.c_str(), _value1, _value2,
				_value3, _value4 ) );
			sxe::lock_guard< sxe::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3,
		const sxe::value_type& _value4, const sxe::value_type& _value5 )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxe::sxprintf( _message.c_str(), _value1, _value2,
				_value3, _value4, _value5 ) );
			sxe::lock_guard< sxe::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3,
		const sxe::value_type& _value4, const sxe::value_type& _value5, const sxe::value_type& _value6 )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxe::sxprintf( _message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6 ) );
			sxe::lock_guard< sxe::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3,
		const sxe::value_type& _value4, const sxe::value_type& _value5, const sxe::value_type& _value6, const sxe::value_type& _value7 )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxe::sxprintf( _message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6, _value7 ) );
			sxe::lock_guard< sxe::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3,
		const sxe::value_type& _value4, const sxe::value_type& _value5, const sxe::value_type& _value6, const sxe::value_type& _value7,
		const sxe::value_type& _value8 )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxe::sxprintf( _message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6, _value7, _value8 ) );
			sxe::lock_guard< sxe::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}			


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3,
		const sxe::value_type& _value4, const sxe::value_type& _value5, const sxe::value_type& _value6, const sxe::value_type& _value7,
		const sxe::value_type& _value8, const sxe::value_type& _value9 )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxe::sxprintf( _message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6, _value7, _value8, _value9 ) );
			sxe::lock_guard< sxe::mutex > lock( mutex_ );
			messages_.push( message );
		}
		condition_.notify_one();
		waiter.wait();
	}


	void log_and_wait( const log_level _log_level, const std::string& _time_stamp, const std::string& _file, const int _line,
		const std::string& _message, const sxe::value_type& _value1, const sxe::value_type& _value2, const sxe::value_type& _value3,
		const sxe::value_type& _value4, const sxe::value_type& _value5, const sxe::value_type& _value6, const sxe::value_type& _value7,
		const sxe::value_type& _value8, const sxe::value_type& _value9, const sxe::value_type&  _value10 )
	{
		waiter waiter;
		{
			log_message message( &waiter, _log_level, _time_stamp, _file, _line, sxe::sxprintf( _message.c_str(), _value1, _value2,
				_value3, _value4, _value5, _value6, _value7, _value8, _value9, _value10 ) );
			sxe::lock_guard< sxe::mutex > lock( mutex_ );
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
		SX_ASSERT( stop_, "Logger cannot be added while running!" );
		sxe::lock_guard< sxe::mutex > lock( mutex_ );
		loggers_.push_back( sxe::move( _logger ) );
	}


	//!\brief Starts the logging. On starting, a new thread is created which processes the enqueued log message by
	//!sending them to each logger. The thread has to be stopped and joined before the log manager is destroyed!
	//!\return void
	//!\sa halt, join
	void run()
	{
		stop_ = false;
		thread_ = sxe::thread( sxe::bind( &log_manager_template::work, this ) );
	}


	//!\brief Stops the logging. The thread that processes the log messages is notified that it should stop. It still has
	//!to be joined later.
	//!\return void
	//!\sa run, join, halt_and_join
	void halt()
	{
		{
			sxe::lock_guard< sxe::mutex > lock( mutex_ );
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


	//!\brief Get the current date and time as a string.
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
		SX_ASSERT( !LOG_MANAGER_EXISTS, "Log manager already exists!" );
		LOG_MANAGER_EXISTS = true;
	}


	~log_manager_template()
	{			
		SX_ASSERT( stop_, "Thread is still running! It was not stopped." );
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
				sxe::unique_lock< sxe::mutex > lock( mutex_ );
				condition_.wait( lock, sxe::bind( &log_manager_template::should_be_running, this ) );

				if( finished() )
				{
					break;
				}

				message = messages_.front();
				messages_.pop();
			}

			SX_FOR(const logger_uptr& logger, loggers_)
			{
				logger->log( message );
				message.done();
			}
		}
	}


	sxe::thread thread_;
	sxe::mutex mutex_;
	sxe::condition_variable condition_;
	bool stop_;
	loggers loggers_;
	std::queue< log_message > messages_;
	log_level log_level_;
};


}


#endif

#endif
