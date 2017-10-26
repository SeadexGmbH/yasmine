//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef SPECIALIZED_EVENT_CA823D7C_65A6_4094_8641_FA9496F11C1F
#define SPECIALIZED_EVENT_CA823D7C_65A6_4094_8641_FA9496F11C1F


#include "event_impl.hpp"


namespace sxy
{

//!\class specialized_event
//!\brief Class that inherits event_impl and provides a fixed event ID and priority as well as create methods
//!for creating instances of the event.
template<class _concrete_event, sxy::event_id _event_id, sxy::event_priority _event_priority = DEFAULT_EVENT_PRIORITY>
class specialized_event: public event_impl
{
public:
	//!\brief Constructor.
	explicit specialized_event(const std::string _name = std::string())
		: event_impl( _event_id, _event_priority ),
		  name_( _name )
	{
		// Nothing to do.
	}


	virtual ~specialized_event() SX_NOEXCEPT SX_OVERRIDE
	{
		// Nothing to do.
	}


	SX_NO_COPY(specialized_event)

	//!\brief Getter for event's name.
	//!\return Name of the event.
	virtual std::string get_name() const SX_OVERRIDE
	{
		const std::string name = name_.empty() ? event_impl::get_name() : name_;
		return(name);
	}


	//!\brief Getter for event's ID.
	//!\return ID of the event.
	virtual sxy::event_id get_id() const SX_OVERRIDE
	{
		return( _event_id );
	}

	
	//!\brief Static getter for event's ID.
	//!\return ID of the event.Static method for creating an event
	static SX_CONSTEXPR sxy::event_id get_event_id()
	{
		return( _event_id );
	}


#ifdef SX_CPP03_BOOST
	

	//!\brief Method for creating an event with no parameters.
	//!\return The created event.
	static sxe::shared_ptr< _concrete_event > create()
	{
		return( SX_MAKE_SHARED< _concrete_event >() );
	}


	//!\brief Method for creating an event with 1 parameter.
	//!\return The created event.
	template<typename _param_type1>
	static sxe::shared_ptr< _concrete_event > create( const _param_type1& _p1 )
	{
		return( SX_MAKE_SHARED< _concrete_event >( _p1 ) );
	}


	//!\brief Method for creating an event with 2 parameters.
	//!\return The created event.
	template<typename _param_type1, typename _param_type2>
	static sxe::shared_ptr< _concrete_event > create( const _param_type1& _p1, const _param_type2& _p2 )
	{
		return( SX_MAKE_SHARED< _concrete_event >( _p1, _p2 ) );
	}


	//!\brief Method for creating an event with 3 parameters.
	//!\return The created event.
	template<typename _param_type1, typename _param_type2, typename _param_type3>
	static sxe::shared_ptr< _concrete_event > create( const _param_type1& _p1, const _param_type2& _p2, const _param_type3& _p3 )
	{
		return( SX_MAKE_SHARED< _concrete_event >( _p1, _p2, _p3 ) );
	}


	//!\brief Method for creating an event with 4 parameters.
	//!\return The created event.
	template<typename _param_type1, typename _param_type2, typename _param_type3, typename _param_type4>
	static sxe::shared_ptr< _concrete_event > create( const _param_type1& _p1, const _param_type2& _p2, const _param_type3& _p3,
		const _param_type4& _p4 )
	{
		return( SX_MAKE_SHARED< _concrete_event >( _p1, _p2, _p3, _p4 ) );
	}


	//!\brief Method for creating an event with 5 parameters.
	//!\return The created event.
	template<typename _param_type1, typename _param_type2, typename _param_type3, typename _param_type4, 
		typename _param_type5>
	static sxe::shared_ptr< _concrete_event > create( const _param_type1& _p1, const _param_type2& _p2, const _param_type3& _p3,
		const _param_type4& _p4, const _param_type5& _p5 )
	{
		return( SX_MAKE_SHARED< _concrete_event >( _p1, _p2, _p3, _p4, _p5 ) );
	}


	//!\brief Method for creating an event with 6 parameters.
	//!\return The created event.
	template<typename _param_type1, typename _param_type2, typename _param_type3, typename _param_type4,
		typename _param_type5, typename _param_type6>
		static sxe::shared_ptr< _concrete_event > create( const _param_type1& _p1, const _param_type2& _p2, const _param_type3& _p3,
			const _param_type4& _p4, const _param_type5& _p5, const _param_type6& _p6 )
	{
		return( SX_MAKE_SHARED< _concrete_event >( _p1, _p2, _p3, _p4, _p5, _p6 ) );
	}


	//!\brief Method for creating an event with 7 parameters.
	//!\return The created event.
	template<typename _param_type1, typename _param_type2, typename _param_type3, typename _param_type4,
		typename _param_type5, typename _param_type6, typename _param_type7>
		static sxe::shared_ptr< _concrete_event > create( const _param_type1& _p1, const _param_type2& _p2, const _param_type3& _p3,
			const _param_type4& _p4, const _param_type5& _p5, const _param_type6& _p6, const _param_type7& _p7 )
	{
		return( SX_MAKE_SHARED< _concrete_event >( _p1, _p2, _p3, _p4, _p5, _p6, _p7 ) );
	}


	//!\brief Method for creating an event with 8 parameters.
	//!\return The created event.
	template<typename _param_type1, typename _param_type2, typename _param_type3, typename _param_type4,
		typename _param_type5, typename _param_type6, typename _param_type7, typename _param_type8>
		static sxe::shared_ptr< _concrete_event > create( const _param_type1& _p1, const _param_type2& _p2, const _param_type3& _p3,
			const _param_type4& _p4, const _param_type5& _p5, const _param_type6& _p6, const _param_type7& _p7, 
			const _param_type8& _p8 )
	{
		return( SX_MAKE_SHARED< _concrete_event >( _p1, _p2, _p3, _p4, _p5, _p6, _p7, _p8 ) );
	}


	//!\brief Method for creating an event with 9 parameters.
	//!\return The created event.
	template<typename _param_type1, typename _param_type2, typename _param_type3, typename _param_type4,
		typename _param_type5, typename _param_type6, typename _param_type7, typename _param_type8, typename _param_type9>
		static sxe::shared_ptr< _concrete_event > create( const _param_type1& _p1, const _param_type2& _p2, const _param_type3& _p3,
			const _param_type4& _p4, const _param_type5& _p5, const _param_type6& _p6, const _param_type7& _p7,
			const _param_type8& _p8, const _param_type9& _p9 )
	{
		return( SX_MAKE_SHARED< _concrete_event >( _p1, _p2, _p3, _p4, _p5, _p6, _p7, _p8, _p9 ) );
	}


	//!\brief Method for creating an event with 10 parameters.
	//!\return The created event.
	template<typename _param_type1, typename _param_type2, typename _param_type3, typename _param_type4,
		typename _param_type5, typename _param_type6, typename _param_type7, typename _param_type8, typename _param_type9, 
		typename _param_type10>
		static sxe::shared_ptr< _concrete_event > create( const _param_type1& _p1, const _param_type2& _p2, const _param_type3& _p3,
			const _param_type4& _p4, const _param_type5& _p5, const _param_type6& _p6, const _param_type7& _p7,
			const _param_type8& _p8, const _param_type9& _p9, const _param_type10& _p10 )
	{
		return( SX_MAKE_SHARED< _concrete_event >( _p1, _p2, _p3, _p4, _p5, _p6, _p7, _p8, _p9, _p10 ) );
	}


#else
	//!\brief Method for creating an event with its parameters.
	//!\return The created event.
	template<typename ... _param_types>
	static sxe::shared_ptr< _concrete_event > create( _param_types... args )
	{
		return( SX_MAKE_SHARED< _concrete_event >( args... ) );
	}


#endif



private:
	std::string name_;
};


}


#endif
