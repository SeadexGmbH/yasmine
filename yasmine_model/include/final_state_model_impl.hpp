//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef FINAL_STATE_MODEL_IMPL_D3F6C9F5_29BD_4897_B744_9F1A70DA0B8D
#define FINAL_STATE_MODEL_IMPL_D3F6C9F5_29BD_4897_B744_9F1A70DA0B8D


#include "final_state_model.hpp"
#include "state_model_impl.hpp"
#include "region_model.hpp"


namespace sxy
{


namespace model
{


//!\class final_state_model_impl
//!\brief A final state in the model.
class final_state_model_impl SX_FINAL: 
	public final_state_model, public state_model_impl
{


public:
	//!\brief Constructor.
	//!\param _name  Name of the final state.
	explicit final_state_model_impl( const std::string& _name );
	virtual ~final_state_model_impl() SX_NOEXCEPT SX_OVERRIDE;
	SX_NO_COPY( final_state_model_impl )
	virtual const raw_const_region_models get_regions() const SX_OVERRIDE;
	virtual const std::string& get_enter_behavior() const SX_OVERRIDE;
	virtual void set_enter_behavior( const std::string& _enter_behavior ) SX_OVERRIDE;
	virtual const std::string& get_do_behavior() const SX_OVERRIDE;
	virtual void set_do_behavior( const std::string& _do_behavior ) SX_OVERRIDE;
	virtual const std::string& get_exit_behavior() const SX_OVERRIDE;
	virtual void set_exit_behavior( const std::string& _exit_behavior ) SX_OVERRIDE;
	virtual void accept( model_vertex_visitor& _constructor_visitor ) const SX_OVERRIDE;
	virtual void accept_delete_visitor( delete_visitor& _delete_visitor ) SX_OVERRIDE;


private:
	const std::string no_behavior_;
};


}


}


#endif
