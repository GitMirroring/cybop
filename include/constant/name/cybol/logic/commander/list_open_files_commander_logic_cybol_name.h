/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The list uid option for the list open files logic in cybol. */
static wchar_t* LIST_UID_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME = L"listuid";
static int* LIST_UID_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list file size option for the list open files logic in cybol. */
static wchar_t* LIST_FILE_SIZE_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME = L"listfilesize";
static int* LIST_FILE_SIZE_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list tasks for the list open files logic in cybol. */
static wchar_t* LIST_TASKS_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME = L"listtasks";
static int* LIST_TASKS_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The disable tcp option for the list open files logic in cybol. */
static wchar_t* DISABLE_TCP_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME = L"disabletcp";
static int* DISABLE_TCP_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The terse listing option for the list open files logic in cybol. */
static wchar_t* TERSE_LISTING_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME = L"terselisting";
static int* TERSE_LISTING_LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LIST_OPEN_FILES_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
