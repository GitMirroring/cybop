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

#ifndef REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The force parameter for the remove logic in cybol. */
static wchar_t* FORCE_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"force";
static int* FORCE_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The path parameter for the remove logic in cybol. */
static wchar_t* PATH_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"path";
static int* PATH_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The interactive parameter for the remove logic in cybol. */
static wchar_t* INTERACTIVE_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"interactive";
static int* INTERACTIVE_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The recursive parameter for the remove logic in cybol. */
static wchar_t* RECURSIVE_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"recursive";
static int* RECURSIVE_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The verbal parameter for the remove logic in cybol. */
static wchar_t* VERBAL_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"verbal";
static int* VERBAL_REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* REMOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
