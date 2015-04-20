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
static wchar_t ARCHIVE_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd', L'/', L'a', L'r', L'c', L'h', L'i', L'v', L'e'};
static wchar_t* ARCHIVE_COMMAND_LOGIC_CYBOL_FORMAT = ARCHIVE_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY;
static int* ARCHIVE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/copy logic cybol format.
 *
 * Copy the given file into another.
 *
 * This is a CYBOL extension.
 */
static wchar_t COPY_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd', L'/', L'c', L'o', L'p', L'y'};
static wchar_t* COPY_COMMAND_LOGIC_CYBOL_FORMAT = COPY_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY;
static int* COPY_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/echo logic cybol format.
 *
 * Echo a given message to the standard output.
 *
 * This is a CYBOL extension.
 */
static wchar_t ECHO_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd', L'/', L'e', L'c', L'h', L'o'};
static wchar_t* ECHO_COMMAND_LOGIC_CYBOL_FORMAT = ECHO_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY;
static int* ECHO_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;


/**
 * The command/list-directory-contents logic cybol format.
 *
 * List contents of the given directory.
 *
 * This is a CYBOL extension.
 */
static wchar_t LIST_DIRECTORY_CONTENTS_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd', L'/', L'l', L'i', L's', L't', L'-', L'd', L'i', L'r', L'e', L'c', L't', L'o', L'r', L'y', L'-', L'c', L'o', L'n', L't', L'e', L'n', L't', L's'};
static wchar_t* LIST_DIRECTORY_CONTENTS_COMMAND_LOGIC_CYBOL_FORMAT = LIST_DIRECTORY_CONTENTS_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY;
static int* LIST_DIRECTORY_CONTENTS_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/move logic cybol format.
 *
 * Moves a file or directory to a destination path.
 *
 * This is a CYBOL extension.
 */
static wchar_t MOVE_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd', L'/', L'm', L'o', L'v', L'e'};
static wchar_t* MOVE_COMMAND_LOGIC_CYBOL_FORMAT = MOVE_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY;
static int* MOVE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/remove logic cybol format.
 *
 * Removes a file or directory.
 *
 * This is a CYBOL extension.
 */
static wchar_t REMOVE_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd', L'/', L'r', L'e', L'm', L'o', L'v', L'e'};
static wchar_t* REMOVE_COMMAND_LOGIC_CYBOL_FORMAT = REMOVE_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY;
static int* REMOVE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/remove logic cybol format.
 *
 * Removes a file or directory.
 *
 * This is a CYBOL extension.
 */
static wchar_t TAPE_ARCHIVER_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd', L'/', L't', L'a', L'p', L'e', L'-', L'a', L'r', L'c', L'h', L'i', L'v', L'e', L'r'};
static wchar_t* TAPE_ARCHIVER_COMMAND_LOGIC_CYBOL_FORMAT = TAPE_ARCHIVER_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY;
static int* TAPE_ARCHIVER_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/change-permission logic cybol format.
 *
 * Changes the permission of a file or directory.
 *
 * This is a CYBOL extension.
 */
static wchar_t CHANGE_PERMISSION_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd', L'/', L'c', L'h', L'a', L'n', L'g', L'e', L'-', L'p', L'e', L'r', L'm', L'i', L's', L's', L'i', L'o', L'n'};
static wchar_t* CHANGE_PERMISSION_COMMAND_LOGIC_CYBOL_FORMAT = CHANGE_PERMISSION_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY;
static int* CHANGE_PERMISSION_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/word count logic cybol format.
 *
 * Outputs the Number of rows, words and bytes for every file
 *
 * This is a CYBOL extension.
 */
static wchar_t WORD_COUNT_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd', L'/', L'w', L'o', L'r', L'd', L'-', L'c', L'o', L'u', L'n', L't'};
static wchar_t* WORD_COUNT_COMMAND_LOGIC_CYBOL_FORMAT = WORD_COUNT_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY;
static int* WORD_COUNT_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command/create-folder logic cybol format.
 *
 * Creates a folder
 *
 * This is a CYBOL extension.
 */
static wchar_t CREATE_FOLDER_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd', L'/', L'c', L'r', L'e', L'a', L't', L'e', L'-', L'f', L'o', L'l', L'd', L'e', L'r'};
static wchar_t* CREATE_FOLDER_COMMAND_LOGIC_CYBOL_FORMAT = CREATE_FOLDER_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY;
static int* CREATE_FOLDER_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The command/ping logic cybol format.
*
* Pings a given host
*
* This is a CYBOL extension.
*/
static wchar_t PING_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd', L'/', L'p', L'i', L'n', L'g'};
static wchar_t* PING_COMMAND_LOGIC_CYBOL_FORMAT = PING_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY;
static int* PING_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The command/grep logic cybol format.
*
* prints lines matching a pattern
*
* This is a CYBOL extension.
*/
static wchar_t GREP_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd', L'/', L'g', L'r', L'e', L'p'};
static wchar_t* GREP_COMMAND_LOGIC_CYBOL_FORMAT = GREP_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY;
static int* GREP_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The command/traceroute logic cybol format.
*
* displays packet routes to any reachable host
*
* This is a CYBOL extension.
*/
static wchar_t TRACEROUTE_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd', L'/', L't', L'r', L'a', L'c', L'e', L'r', L'o', L'u', L't', L'e'};
static wchar_t* TRACEROUTE_COMMAND_LOGIC_CYBOL_FORMAT = TRACEROUTE_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY;
static int* TRACEROUTE_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The command/diff logic cybol format.
*
* displays differences between two files
*
* This is a CYBOL extension.
*/
static wchar_t DIFF_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd', L'/', L'd', L'i', L'f', L'f'};
static wchar_t* DIFF_COMMAND_LOGIC_CYBOL_FORMAT = DIFF_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY;
static int* DIFF_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The command/sort logic cybol format.
*
* sorts a file
*
* This is a CYBOL extension.
*/
static wchar_t SORT_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd', L'/', L's', L'o', L'r', L't'};
static wchar_t* SORT_COMMAND_LOGIC_CYBOL_FORMAT = SORT_COMMAND_LOGIC_CYBOL_FORMAT_ARRAY;
static int* SORT_COMMAND_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COMMAND_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
