//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "consts.hpp"


namespace sxy
{


namespace model
{


const char* const JSON_STATE_MACHINE_NODE = "state_machine";
const char* const JSON_ROOT_NODE = "root";
const char* const JSON_TRANSITIONS_NODE = "transitions";
const char* const JSON_NAME_NODE = "name";
const char* const JSON_TYPE_NODE = "type";
const char* const JSON_ENTER_BEHAVIOR_NODE = "enter_behavior";
const char* const JSON_DO_BEHAVIOR_NODE = "do_behavior";
const char* const JSON_EXIT_BEHAVIOR_NODE = "exit_behavior";
const char* const JSON_REGIONS_NODE = "regions";
const char* const JSON_VERTICES_NODE = "vertices";
const char* const JSON_STATE_PSEUDOSTATES_NODE = "pseudostates";
const char* const JSON_PSEUDOSTATES_NODE = "pseudostates";
const char* const JSON_TRANSITION_KIND_NODE = "kind";
const char* const JSON_TRANSITION_SOURCE_NODE = "source";
const char* const JSON_TRANSITION_TARGET_NODE = "target";
const char* const JSON_TRANSITION_GUARD_NODE = "guard";
const char* const JSON_TRANSITION_BEHAVIOR_NODE = "behavior";
const char* const JSON_TRANSITION_EVENTS_NODE = "event_name";
const char* const JSON_DEFERRED_EVENTS = "deferred_event_name";
const char* const JSON_ERROR_EVENT = "error_event";
const char* const JSON_EVENT_ID = "ID";
const char* const JSON_EVENT_NAME = "name";
const char* const JSON_EVENT_LIST_NODE = "event_list";
const char* const JSON_EVENT_PRIORITY = "priority";
const char* const JSON_VERSION = "version";
const char* const JSON_CURRENT_VERSION_VALUE = "2.0";
const char* const JSON_VERSION_1 = "1.0";


const std::string TYPE_TRANSITION = "transition";
const std::string TYPE_SIMPLE_STATE = "simple_state";
const std::string TYPE_ASYNC_SIMPLE_STATE = "async_simple_state";
const std::string TYPE_COMPOSITE_STATE = "composite_state";
const std::string TYPE_FINAL_STATE = "final_state";
const std::string TYPE_INITIAL_PSEUDOSTATE = "initial_pseudostate";
const std::string TYPE_TERMINATE_PSEUDOSTATE = "terminate_pseudostate";
const std::string TYPE_ENTRY_POINT = "entry_point";
const std::string TYPE_EXIT_POINT = "exit_point";
const std::string TYPE_DEEP_HISTORY = "deep_history";
const std::string TYPE_SHALLOW_HISTORY = "shallow_history";
const std::string TYPE_JOIN = "join";
const std::string TYPE_JUNCTION = "junction";
const std::string TYPE_FORK = "fork";
const std::string TYPE_CHOICE = "choice";
const std::string TYPE_REGION = "region";
const std::string TYPE_UNKNOWN = "unknown";


const std::string CONFIG_FILE_IS_CORRUPTED = "Config file is corrupted!";
const std::string CHOOSE_FILE_TEXT = "Select log file";
const std::string FILE_CANNOT_BE_OPENED = "File cannot be opened!";
const std::string PATH_CONFIG_JSON_FILE = "path_config.json";
const std::string CHOOSE_FILE_TYPE = "file (*.*);;";
const std::string CHOOSE_FILE_TEXT_SAVE = "Select file to save data";
const std::string CHOOSE_FILE_DEFAULT_SAVING_NAME = "state_machine.json";
const std::string CHOOSE_FILE_TYPE_SAVE = "all files (*.*);;";


const char* const TRANSITION_MUST_BE_IN_JSON_ARRAY = "Transitions from the json file are not in an array!";

}


}
