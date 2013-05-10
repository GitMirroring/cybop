/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LIST_FILE_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define LIST_FILE_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/**
 * The path for the list directory contents file logic cybol name.
 *
 * It indicates the path of a directory for listing its files and directories
 */
static wchar_t PATH_LIST_FILE_LOGIC_CYBOL_NAME_ARRAY[] = {L'p', L'a', L't', 'h'};
static wchar_t* PATH_LIST_FILE_LOGIC_CYBOL_NAME = PATH_LIST_FILE_LOGIC_CYBOL_NAME_ARRAY;
static int* PATH_LIST_FILE_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The all list directory contents file logic cybol name.
 *
 * It indicates that hidden files should be listed
 * as well as the current . and upper .. directory.
 */
static wchar_t ALL_LIST_FILE_LOGIC_CYBOL_NAME_ARRAY[] = {L'a', L'l', L'l'};
static wchar_t* ALL_LIST_FILE_LOGIC_CYBOL_NAME = ALL_LIST_FILE_LOGIC_CYBOL_NAME_ARRAY;
static int* ALL_LIST_FILE_LOGIC_CYBOL_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The long list directory contents file logic cybol name.
 *
 * It indicates the usage of a long listing including file access rights etc.
 */
static wchar_t LONG_LIST_FILE_LOGIC_CYBOL_NAME_ARRAY[] = {L'l', L'o', L'n', L'g'};
static wchar_t* LONG_LIST_FILE_LOGIC_CYBOL_NAME = LONG_LIST_FILE_LOGIC_CYBOL_NAME_ARRAY;
static int* LONG_LIST_FILE_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The one row per entry list directory contents file logic cybol name.
 *
 * It indicates the usage of a one row per entry listing for files and directories.
 */
static wchar_t ONE_ROW_PER_ENTRY_LIST_FILE_LOGIC_CYBOL_NAME_ARRAY[] = {L'o', L'n', L'e', L'_', L'r', L'o', L'w', L'_', L'p', L'e', L'r', L'_', L'e', L'n', L't', L'r', L'y'};
static wchar_t* ONE_ROW_PER_ENTRY_LIST_FILE_LOGIC_CYBOL_NAME = ONE_ROW_PER_ENTRY_LIST_FILE_LOGIC_CYBOL_NAME_ARRAY;
static int* ONE_ROW_PER_ENTRY_LIST_FILE_LOGIC_CYBOL_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The recursive list directory contents file logic cybol name.
 *
 * It indicates the usage of a recursive listing of files and directories in directories.
 */
static wchar_t RECURSIVE_LIST_FILE_LOGIC_CYBOL_NAME_ARRAY[] = {L'r', L'e', L'c', L'u', L'r', L's', L'i', L'v', L'e'};
static wchar_t* RECURSIVE_LIST_FILE_LOGIC_CYBOL_NAME = RECURSIVE_LIST_FILE_LOGIC_CYBOL_NAME_ARRAY;
static int* RECURSIVE_LIST_FILE_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The short list directory contents file logic cybol name.
 *
 * It indicates the usage of a short listing of files and directories for the current directory.
 */
static wchar_t SHORT_LIST_FILE_LOGIC_CYBOL_NAME_ARRAY[] = {L's', L'h', L'o', L'r', L't'};
static wchar_t* SHORT_LIST_FILE_LOGIC_CYBOL_NAME = SHORT_LIST_FILE_LOGIC_CYBOL_NAME_ARRAY;
static int* SHORT_LIST_FILE_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sort by file size part list directory contents file logic cybol name.
 *
 * It indicates the usage of sort by file size for the listing.
 */
static wchar_t SORT_BY_FILE_SIZE_LIST_FILE_LOGIC_CYBOL_NAME_ARRAY[] = {L's', L'o', L'r', L't', L'_', L'b', L'y', L'_', L'f', L'i', L'l', L'e', L'_', L's', L'i', L'z', L'e'};
static wchar_t* SORT_BY_FILE_SIZE_LIST_FILE_LOGIC_CYBOL_NAME = SORT_BY_FILE_SIZE_LIST_FILE_LOGIC_CYBOL_NAME_ARRAY;
static int* SORT_BY_FILE_SIZE_LIST_FILE_LOGIC_CYBOL_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sort by modification date list directory contents file logic cybol name.
 *
 * It indicates the usage of sort by file modification date for the listing.
 */
static wchar_t SORT_BY_MODIFICATION_DATE_LIST_FILE_LOGIC_CYBOL_NAME_ARRAY[] = {L's', L'o', L'r', L't', L'_', L'b', L'y', L'_', L'm', L'o', L'd', L'i', L'f', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'_', L'd', L'a', L't', L'e'};
static wchar_t* SORT_BY_MODIFICATION_DATE_LIST_FILE_LOGIC_CYBOL_NAME = SORT_BY_MODIFICATION_DATE_LIST_FILE_LOGIC_CYBOL_NAME_ARRAY;
static int* SORT_BY_MODIFICATION_DATE_LIST_FILE_LOGIC_CYBOL_NAME_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sort by extension list directory contents file logic cybol name.
 *
 * It indicates the usage of sort by file extension for the listing.
 */
static wchar_t SORT_BY_EXTENSION_LIST_FILE_LOGIC_CYBOL_NAME_ARRAY[] = {L's', L'o', L'r', L't', L'_', L'b', L'y', L'_', L'e', L'x', L't', L'e', L'n', L's', L'i', L'o', L'n'};
static wchar_t* SORT_BY_EXTENSION_LIST_FILE_LOGIC_CYBOL_NAME = SORT_BY_EXTENSION_LIST_FILE_LOGIC_CYBOL_NAME_ARRAY;
static int* SORT_BY_EXTENSION_LIST_FILE_LOGIC_CYBOL_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LIST_FILE_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif
