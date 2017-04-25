//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "generator_grammar.hpp"


namespace sxy
{


const std::string VARIABLE_STATE_MACHINE_NAME_CAPS = "state_machine_name_caps";
const std::string VARIABLE_STATE_MACHINE_NAME = "state_machine_name";
const std::string VARIABLE_STATE_MACHINE_TYPE = "state_machine_type";
const std::string VARIABLE_NAMESPACE_NAME = "namespace_name";
const std::string LOOP_NAMESPACE_OPEN = "namespace_open";
const std::string VARIABLE_NAMESPACE_CLOSE = "namespace_close";
const std::string VARIABLE_BEHAVIOR_CLASS_NAME = "behavior_class_name";
const std::string LOOP_BEHAVIOR_CLASSES = "behavior_classes";
const std::string VARIABLE_LAST_BEHAVIOR_CLASS = "last_behavior_class";
const std::string LOOP_TRANSITIONS = "transitions";
const std::string VARIABLE_EVENT_ID = "event_id";
const std::string VARIABLE_EVENT_NAME = "event_name";
const std::string VARIABLE_EVENT_PRIORITY = "priority";
const std::string TRANSITION_EVENT_ID = "transition_event_id";
const std::string VARIABLE_SOURCE_VERTEX = "source_vertex";
const std::string VARIABLE_TARGET_VERTEX = "target_vertex";
const std::string VARIABLE_TRANSITION_KIND = "transition_kind";
const std::string VARIABLE_TRANSITION_KIND_NAMESPACE = "sxy::transition_kind::";
const std::string VARIABLE_EMPTY_BEHAVIOR = "Y_EMPTY_BEHAVIOR";
const std::string VARIABLE_EMPTY_GUARD = "Y_EMPTY_GUARD";
const std::string LOOP_REGIONS = "regions";
const std::string VARIABLE_VERTICES = "vertices";
const std::string LOOP_PSEUDOSTATES = "pseudostates";
const std::string LOOP_STATE_PSEUDOSTATES = "state_pseudostates";
const std::string LOOP_STATES = "states";
const std::string VARIABLE_REGION_NAME = "region_name";
const std::string VARIABLE_ROOT_NAME = "root_name";
const std::string VARIABLE_CURRENT_STATE_NAME = "current_state_name";
const std::string VARIABLE_DATE_TIME = "datetime";
const unsigned int YEAR_1900( 1900 );
const unsigned int WIDTH_YEAR( 4 );
const unsigned int WIDTH_CLOCK( 2 );
const char FILL_VALUE( '0' );
const char SLASH_CHAR = '/';
const char COLON_CHAR = ':';
const std::string DOUBLE_COLON = "::";
const char OPEN_BRACE_CHAR = '{';
const char CLOSE_BRACE_CHAR = '}';
const char COMMA_CHAR = ',';
const char AND_CHAR = '&';
const char DOT_CHAR = '.';
const char UNDERSCORE_CHAR = '_';
const std::string VARIABLE_COMPLETION_EVENT_ID = "sxy::Y_COMPLETION_EVENT_ID";
const std::string CONDITION_IS_COMPOSITE_STATE = "is_composite_state";
const std::string CONDITION_IS_STATE = "is_state";
const std::string LOOP_EVENTS = "events";
const std::string VARIABLE_STATE_NAME = "state_name";
const std::string VARIABLE_STATE_TYPE = "state_type";
const std::string VARIABLE_PSEUDOSTATE_NAME = "pseudostate_name";
const std::string VARIABLE_PSEUDOSTATE_TYPE = "pseudostate_type";
const std::string VARIABLE_STATE_PSEUDOSTATE_NAME = "state_pseudostate_name";
const std::string VARIABLE_STATE_PSEUDOSTATE_TYPE = "state_pseudostate_type";
const std::string SWITCH_ENTER_BEHAVIOR = "enter_behavior";
const std::string SWITCH_DO_BEHAVIOR = "do_behavior";
const std::string SWITCH_EXIT_BEHAVIOR = "exit_behavior";
const std::string SWITCH_TRANSITION_GUARD = "transition_guard";
const std::string SWITCH_TRANSITION_BEHAVIOR = "transition_behavior";
const std::string THIS_ACCESS = "this->";
const std::string POINTER_ACCESS = "->";
const std::string REFERENCE_ACCESS = ".";
const std::string VARIABLE_GUARD_FUNCTION2 = "Y_GUARD_FUNCTION2";
const std::string VARIABLE_GUARD_METHOD2 = "Y_GUARD_METHOD2";
const std::string VARIABLE_BEHAVIOR_FUNCTION2 = "Y_BEHAVIOR_FUNCTION2";
const std::string VARIABLE_BEHAVIOR_METHOD2 = "Y_BEHAVIOR_METHOD2";
const std::string VARIABLE_METHOD_NAME = "behavior_method_name";
const std::string VARIABLE_CLASS_INSTANCE_NAME = "class_instance_name";
const std::string VARIABLE_SM_SYNC = "sync";
const std::string VARIABLE_SM_ASYNC = "async";
const std::string VARIABLE_SYNC_SM_CLASS = "sxy::sync_state_machine";
const std::string VARIABLE_ASYNC_SM_CLASS = "sxy::async_state_machine";
const char VARIABLE_CLOSE_PARENTHESIS = ')';
const char VARIABLE_OPEN_PARENTHESIS = '(';
const std::string CONDITION_LAST_PSEUDOSTATE = "last_pseudostate";
const int SWITCH_DEFAULT_INDEX = -1;


}
