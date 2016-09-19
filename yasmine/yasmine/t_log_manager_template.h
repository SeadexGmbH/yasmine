//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_LOG_MANAGER_TEMPLATE_F6D33798_A43A_4C29_86F1_0FC821B92F9B
#define T_LOG_MANAGER_TEMPLATE_F6D33798_A43A_4C29_86F1_0FC821B92F9B


#include <string>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

#include "base.h"
#include "i_logger.h"
#include "t_log_message.h"
#include "t_log_level.h"
#include "yprintf.h"


namespace sxy
{


namespace
{


bool g_log_manager_exists = false;


}


//!\class	t_log_manager_template
//!\brief The log manager (a singleton) controls the different loggers, manages the current log level, and takes care of dispatching log messages.
template< typename tt_time_stamp_policy >
class t_log_manager_template final
{
public:
	//!\brief Get a reference to the single instance of the log manager template.
	static t_log_manager_template&
	get_instance
	(
		void
	)
	{
		static t_log_manager_template instance;
		return( instance );
	}


	t_log_manager_template
	(
		const t_log_manager_template&
	) = delete;																			


	t_log_manager_template&
	operator=
	(
		const t_log_manager_template&
	) = delete;


	//!\brief Gets the currently set log level.
	//!\return Current log level.
	t_log_level get_log_level() const
	{
		return( m_log_level );
	}


	//!\brief Sets a new log level.
	//!\param p_log_level Log level to be set.
	//!\return void
	void set_log_level
	( 
		const t_log_level p_log_level 
	)
	{
		m_log_level = p_log_level;
	}

	//!\brief Add a message to the queue of messages that will be processed.
	//!\param	p_log_level_message Log level of the message.
	//!\param	p_log_time_stamp Date and time when the log message was created.
	//!\param	p_log_file The file from where the log was called.
	//!\param	p_log_line The line from where the log was called.
	//!\param	p_log_message The message text for the log.
	//!\param	p_args Parameters that are inserted in the message.
	//!\return void
	//!\sa Y_LOG(), yprintf
	template< typename ... tt_args >
	void
	log
	(
		const t_log_level p_log_level_message,
		const std::string& p_log_time_stamp,
		const std::string& p_log_file,
		const int p_log_line,
		const std::string& p_log_message,
		tt_args ... p_args
	)
	{
		{
			t_log_message l_message( p_log_level_message, p_log_time_stamp, p_log_file, p_log_line, sxy::yprintf( p_log_message.c_str(), p_args... ) );
			std::lock_guard< std::mutex > lock( m_mutex );
			m_messages.push( l_message );
		}
		m_condition.notify_one();
	}


	//!\brief Adds a logger to which the log will be written.
	//!\param p_logger - The logger to be added.
	//!\return void
	void
	add_logger
	(
		i_logger_uptr p_logger
	)
	{			
		Y_ASSERT_NO_LOG( m_stop, "Logger cannot be added while running!" );
		std::lock_guard< std::mutex > lock( m_mutex );
		m_loggers.push_back( std::move( p_logger ) );
	}


	//!\brief Starts the logging. On starting, a new thread is created which processes the enqueued log message by sending them to each logger.
	// The thread has to be stopped and joined before the	log manager is destroyed!
	//!\return void
	//!\sa stop, join
	void
	start
	(
	)
	{
		m_stop = false;
		m_thread = std::thread
		( 
			[ this ]()
			{
				this->work();
			}
		);
	}


	//!\brief Stops the logging. The thread that processes the log messages is notified that it should stop. It still has to be joined later.
	//!\return void
	//!\sa start, join
	void
	stop
	(
	)
	{
		{
			std::lock_guard< std::mutex > lock( m_mutex );
			m_stop = true;
		}
		
		m_condition.notify_one();
	}


	//!\brief Joins the thread that processed the log messages. Join has to be called after the stop function.
	//!\return void
	//!\sa stop, start
	void
	join
	(
	)
	{
		m_thread.join();
	}

	//!\brief Gets the current date and time as a string.
	//!\return String containing the date and time.
	static std::string
	get_timestamp
	(
	)
	{
		return( tt_time_stamp_policy::get_timestamp() );
	}


private:
	t_log_manager_template
	(
	): 
		m_thread(),
		m_mutex(),
		m_condition(),
		m_stop( true ),		
		m_loggers(),
		m_messages(),		
		m_log_level(t_log_level::LL_SPAM)
	{
		Y_ASSERT_NO_LOG( !g_log_manager_exists, "Log manager already exists!" );
		g_log_manager_exists = true;
	}


	~t_log_manager_template()
	{
		// Nothing to do...
	}


	bool
	should_be_running
	(
	) const
	{
		return( m_stop || !m_messages.empty() );
	}


	bool
	finished
	(
	) const
	{
		return( m_stop && m_messages.empty() );
	}


	void
	work
	(
	)
	{
		while( true )
		{
			t_log_message message;
			{
				std::unique_lock< std::mutex > lock( m_mutex );

				m_condition.wait
					(
					lock,
					[ this ] ()
					{
						return( this->should_be_running() );
					}
				);

				if( finished() )
				{
					break;
				}

				message = m_messages.front();
				m_messages.pop();
			}

			for( auto& logger : m_loggers )
			{
				logger->log( message );
			}
		}
	}


	std::thread m_thread;
	std::mutex m_mutex;
	std::condition_variable m_condition;
	bool m_stop;

	t_loggers m_loggers;
	std::queue< t_log_message > m_messages;	

	t_log_level m_log_level;
};


}


#include "base_end.h"


#endif
