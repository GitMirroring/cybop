/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/**
 * The path for the list directory contents file logic cybol name.
 *
 * It indicates the path of a directory for listing its files and directories
 */
static wchar_t* PATH_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"path";
static int* PATH_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The all list directory contents file logic cybol name.
 *
 * It indicates that hidden files should be listed
 * as well as the current . and upper .. directory.
 */
static wchar_t* ALL_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"all";
static int* ALL_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The almost all list directory contents file logic cybol name.
 *
 * It indicates that all files are listed
 * whithout the current '.' and upper '..' directory.
 */
static wchar_t* ALMOST_ALL_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"almost_all";
static int* ALMOST_ALL_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The long list directory contents file logic cybol name.
 *
 * It indicates the usage of a long listing including file access rights etc.
 */
static wchar_t* LONG_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"long";
static int* LONG_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The one row per entry list directory contents file logic cybol name.
 *
 * It indicates the usage of a one row per entry listing for files and directories.
 */
static wchar_t* ONE_ROW_PER_ENTRY_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"one_row_per_entry";
static int* ONE_ROW_PER_ENTRY_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The recursive list directory contents file logic cybol name.
 *
 * It indicates the usage of a recursive listing of files and directories in directories.
 */
static wchar_t* RECURSIVE_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"recursive";
static int* RECURSIVE_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The short list directory contents file logic cybol name.
 *
 * It indicates the usage of a short listing of files and directories for the current directory.
 */
static wchar_t* SHORT_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"short";
static int* SHORT_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sort by file size part list directory contents file logic cybol name.
 *
 * It indicates the usage of sort by file size for the listing.
 */
static wchar_t* SORT_BY_FILE_SIZE_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"sort_by_file_size";
static int* SORT_BY_FILE_SIZE_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sort by modification date list directory contents file logic cybol name.
 *
 * It indicates the usage of sort by file modification date for the listing.
 */
static wchar_t* SORT_BY_MODIFICATION_DATE_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"sort_by_modification_date";
static int* SORT_BY_MODIFICATION_DATE_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sort by extension list directory contents file logic cybol name.
 *
 * It indicates the usage of sort by file extension for the listing.
 */
static wchar_t* SORT_BY_EXTENSION_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"sort_by_extension";
static int* SORT_BY_EXTENSION_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The export list directory contents file logic cybol name.
 *
 * Writes the command output into a file.
 */
static wchar_t* EXPORT_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"export";
static int* EXPORT_LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LIST_DIRECTORY_CONTENTS_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
