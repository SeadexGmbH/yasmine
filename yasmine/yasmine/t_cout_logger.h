//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016 Seadex GmbH                                                                   //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/License.html.            //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef T_COUT_LOGGER_93274E54_295D_46BC_80E6_EDBA67B41E18
#define T_COUT_LOGGER_93274E54_295D_46BC_80E6_EDBA67B41E18


#include "i_logger.h"


namespace sxy
{


//!\class t_cout_logger
//!\brief Class for printing messages in the console.
class t_cout_logger: public i_logger
{
public:
	//!\brief Constructor of t_cout_logger.
	t_cout_logger
	(
	);


	virtual 
	~t_cout_logger
	(
	) override = default;


	t_cout_logger
	(
		const t_cout_logger&
	) = delete;


	t_cout_logger&
	operator=
	(
		const t_cout_logger&
	) = delete;


	//!\brief Prints the message in the console.
	//!\param p_log_message Log message that will be printed.
	//!\return void.
	virtual void
	log
	(
		const t_log_message& p_log_message
	) override;


private:
	static
	void
	log_level_as_message
	(
		const sxy::t_log_level p_log_level
	);


};


}


#endif
