//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef FORTY_TWO_7FADB8D9_22B1_4505_AF48_2E655055D7E3
#define FORTY_TWO_7FADB8D9_22B1_4505_AF48_2E655055D7E3


#include <memory>

#include "yasmine.hpp"


namespace examples
{


class forty_two SX_FINAL
{	
public:

	typedef sxe::SX_UNIQUE_PTR<sxy::sync_state_machine> state_machine_uptr;

		
	explicit forty_two( const sxe::uint32_t _max_iterations );
	~forty_two() SX_NOEXCEPT;
	
private:
	state_machine_uptr build_state_machine();
	bool check_state_machine() const;
	void increment_iterations();
	bool check_iterations_divided_by_2() const;
	bool check_iterations_divided_by_3() const;
	bool check_iterations_divided_by_5() const;
	bool check_iterations_exceded() const;
	void run();


	state_machine_uptr state_machine_;
	uint32_t iterations_;
	uint32_t max_iterations_;
	

};


}

#endif
