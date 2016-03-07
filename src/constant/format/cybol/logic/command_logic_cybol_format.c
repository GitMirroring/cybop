/*
 * Copyright (C) 1999-2015. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI. If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org/>
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMMAND_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define COMMAND_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// The CYBOL type constants' names and values have been adapted to follow
// the style of the Internet media type / content type that is also
// known under the name Multipurpose Internet Mail Extensions (MIME).
// These types are managed by the Internet Assigned Numbers Authority (IANA).
// See document "Multipurpose Internet Mail Extensions (MIME) Part Two: Media Types":
// http://tools.ietf.org/html/rfc2046
//
// Since the MIME standard does not offer media types for certain data,
// CYBOL had to invent new languages (media types), e.g. for dates, numbers etc.
// This is not meant to pollute the MIME standard, just to fill a gap!
// In case IANA adopts these extensions one day -- fine.
// If, however, other media type values replacing ours are proposed,
// we are open to adapt the CYBOL language specification accordingly.
//

//
// Command (some operation to be processed over time).
//
// IANA media type: not defined
// Self-defined media type: command
// This media type is a CYBOL extension.
//

/**
 * The command/archive logic cybol format.
 *
 * Archive the given files into a packed format.
 *
 * This is a CYBOL extension.
 */
static wchar_t* ARCHIVE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/archive";
static int* ARCHIVE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/change-directory logic cybol format.
 *
 * Change the directory.
 *
 * This is a CYBOL extension.
 */
static wchar_t* CHANGE_DIRECTORY_COMMAND_LOGIC_CYBOL_FORMAT = L"command/change-directory";
static int* CHANGE_DIRECTORY_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/change-permission logic cybol format.
 *
 * Changes the permission of a file or directory.
 *
 * This is a CYBOL extension.
 */
static wchar_t* CHANGE_PERMISSION_COMMAND_LOGIC_CYBOL_FORMAT = L"command/change-permission";
static int* CHANGE_PERMISSION_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/clear logic cybol format.
 *
 * Clear the console screen.
 *
 * This is a CYBOL extension.
 */
static wchar_t* CLEAR_COMMAND_LOGIC_CYBOL_FORMAT = L"command/clear";
static int* CLEAR_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/compare-files logic cybol format.
 *
 * Compare two files.
 *
 * This is a CYBOL extension.
 */
static wchar_t* COMPARE_FILES_COMMAND_LOGIC_CYBOL_FORMAT = L"command/compare-files";
static int* COMPARE_FILES_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/config-network logic cybol format.
 *
 * Get network information.
 *
 * This is a CYBOL extension.
 */
static wchar_t* CONFIG_NETWORK_COMMAND_LOGIC_CYBOL_FORMAT = L"command/config-network";
static int* CONFIG_NETWORK_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/copy logic cybol format.
 *
 * Copy the given file into another.
 *
 * This is a CYBOL extension.
 */
static wchar_t* COPY_COMMAND_LOGIC_CYBOL_FORMAT = L"command/copy";
static int* COPY_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/create-folder logic cybol format.
 *
 * Creates a folder
 *
 * This is a CYBOL extension.
 */
static wchar_t* CREATE_FOLDER_COMMAND_LOGIC_CYBOL_FORMAT = L"command/create-folder";
static int* CREATE_FOLDER_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/date logic cybol format.
 *
 * Print out the date.
 *
 * This is a CYBOL extension.
 */
static wchar_t* DATE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/date";
static int* DATE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/delay logic cybol format.
 *
 * Delay for a few seconds.
 *
 * This is a CYBOL extension.
 */
static wchar_t* DELAY_COMMAND_LOGIC_CYBOL_FORMAT = L"command/delay";
static int* DELAY_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/diff logic cybol format.
 *
 * displays differences between two files
 *
 * This is a CYBOL extension.
 */
static wchar_t* DIFF_COMMAND_LOGIC_CYBOL_FORMAT = L"command/diff";
static int* DIFF_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/disk-free logic cybol format.
 *
 * Display free disk space.
 *
 * This is a CYBOL extension.
 */
static wchar_t* DISK_FREE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/disk-free";
static int* DISK_FREE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/display-content logic cybol format.
 *
 * Display the content of one or more text files
 *
 * This is a CYBOL extension.
 */
static wchar_t* DISPLAY_CONTENT_COMMAND_LOGIC_CYBOL_FORMAT = L"command/display-content";
static int* DISPLAY_CONTENT_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/echo logic cybol format.
 *
 * Echo a given message to the standard output.
 *
 * This is a CYBOL extension.
 */
static wchar_t* ECHO_COMMAND_LOGIC_CYBOL_FORMAT = L"command/echo";
static int* ECHO_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/find-command logic cybol format.
 *
 * Locates the binary, source, and manual page files for a command.
 *
 * This is a CYBOL extension.
 */
static wchar_t* FIND_COMMAND_COMMAND_LOGIC_CYBOL_FORMAT = L"command/find-command";
static int* FIND_COMMAND_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/find-file logic cybol format.
 *
 * Find a file.
 *
 * This is a CYBOL extension.
 */
static wchar_t* FIND_FILE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/find-file";
static int* FIND_FILE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/grep logic cybol format.
 *
 * prints lines matching a pattern
 *
 * This is a CYBOL extension.
 */
static wchar_t* GREP_COMMAND_LOGIC_CYBOL_FORMAT = L"command/grep";
static int* GREP_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/help logic cybol format.
 *
 * Provides information about one or all system commands.
 *
 * This is a CYBOL extension.
 */
static wchar_t* HELP_COMMAND_LOGIC_CYBOL_FORMAT  = L"command/help";
static int* HELP_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/kill logic cybol format.
 *
 * Kill a process.
 *
 * This is a CYBOL extension.
 */
static wchar_t* KILL_COMMAND_LOGIC_CYBOL_FORMAT = L"command/kill";
static int* KILL_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;


/**
 * The command/list-directory-contents logic cybol format.
 *
 * List contents of the given directory.
 *
 * This is a CYBOL extension.
 */
static wchar_t* LIST_DIRECTORY_CONTENTS_COMMAND_LOGIC_CYBOL_FORMAT = L"command/list-directory-contents";
static int* LIST_DIRECTORY_CONTENTS_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/list-tasks logic cybol format.
 *
 * List all the processes running on the computer.
 *
 * This is a CYBOL extension.
 */
static wchar_t* LIST_TASKS_COMMAND_LOGIC_CYBOL_FORMAT = L"command/list-tasks";
static int* LIST_TASKS_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/move logic cybol format.
 *
 * Moves a file or directory to a destination path.
 *
 * This is a CYBOL extension.
 */
static wchar_t* MOVE_COMMAND_LOGIC_CYBOL_FORMAT  = L"command/move";
static int* MOVE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/ping logic cybol format.
 *
 * Pings a given host
 *
 * This is a CYBOL extension.
 */
static wchar_t* PING_COMMAND_LOGIC_CYBOL_FORMAT = L"command/ping";
static int* PING_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/remove logic cybol format.
 *
 * Removes a file or directory.
 *
 * This is a CYBOL extension.
 */
static wchar_t* REMOVE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/remove";
static int* REMOVE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/sort logic cybol format.
 *
 * sorts a file
 *
 * This is a CYBOL extension.
 */
static wchar_t* SORT_COMMAND_LOGIC_CYBOL_FORMAT = L"command/sort";
static int* SORT_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/spellcheck logic cybol format.
 *
 * Spellcheck a file.
 *
 * This is a CYBOL extension.
 */
static wchar_t* SPELLCHECK_COMMAND_LOGIC_CYBOL_FORMAT = L"command/spellcheck";
static int* SPELLCHECK_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/remove logic cybol format.
 *
 * Removes a file or directory.
 *
 * This is a CYBOL extension.
 */
static wchar_t* TAPE_ARCHIVER_COMMAND_LOGIC_CYBOL_FORMAT = L"command/tape-archiver";
static int* TAPE_ARCHIVER_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/traceroute logic cybol format.
 *
 * displays packet routes to any reachable host
 *
 * This is a CYBOL extension.
 */
static wchar_t* TRACEROUTE_COMMAND_LOGIC_CYBOL_FORMAT = L"command/traceroute";
static int* TRACEROUTE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/word count logic cybol format.
 *
 * Outputs the Number of rows, words and bytes for every file
 *
 * This is a CYBOL extension.
 */
static wchar_t* WORD_COUNT_COMMAND_LOGIC_CYBOL_FORMAT = L"command/word-count";
static int* WORD_COUNT_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COMMAND_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
