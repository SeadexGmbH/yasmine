//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
// This file is part of the Seadex yasmine ecosystem (http://yasmine.seadex.de).                    //
// Copyright (C) 2016-2017 Seadex GmbH                                                              //
//                                                                                                  //
// Licensing information is available in the folder "license" which is part of this distribution.   //
// The same information is available on the www @ http://yasmine.seadex.de/Licenses.html.           //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "ygen_magic_consts.hpp"

const char* const DESCRIPTION_TITLE = "Supported options";
const char* const HELP_OPTION_TEXT = "Show this help.";
const char* const DISPLAY_CFG_TEXT = "Display current configuration.";
const char* const NAMESPACES_TEXT = "Set namespace list.";
const char* const BEHAVIOR_CLASSES_TEXT = "Set classes that contain methods and functions associated to state's and transition's behaviors and transition's guards.";
const char* const TEMPLATE_DIR_TEXT = "Set template directory.";
const char* const TEMPLATE_DIR_DEFAULT = "./templates";
const char* const SOURCE_TEMPLATE_FILE_TEXT = "Set source template file (for .cpp).";
const char* const SOURCE_TEMPLATE_FILE_DEFAULT = "source.gtpl";
const char* const HEADER_TEMPLATE_FILE_TEXT = "Set header template file (for .hpp).";
const char* const HEADER_TEMPLATE_FILE_DEFAULT = "header.gtpl";
const char* const SOURCE_OUT_FILE_TEXT = "Set name of the generated cpp and hpp files. Overwrites the source and header file names given by the state machine name.";
const char* const MODEL_FILE_TEXT = "Set the state machine's model file path.";
const char* const STATE_MACHINE_NAME_TEXT = "Set the state machine name. This will also be used as the name of the generated files.";
const char* const STATE_MACHINE_TYPE_TEXT = "Set the type of the state machine. Type can be 'sync' for a sync state machine or 'async' for a async state machine.";
const char* const STATE_MACHINE_TYPE_SYNC = "sync";
const char* const STATE_MACHINE_TYPE_ASYNC = "async";

const int DESCRIPTION_COLUMN_WIDTH = 120;

