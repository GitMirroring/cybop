
/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef FIND_FILE_COMMANDER_OPTION_NAME_CONSTANT_HEADER
#define FIND_FILE_COMMANDER_OPTION_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The path logic cybol name (parameter). */
static wchar_t* PATH_FIND_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"path";
static int* PATH_FIND_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The file name logic cybol name (parameter). */
static wchar_t* NAME_FIND_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"name";
static int* NAME_FIND_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The recursive logic cybol name. */
static wchar_t* RECURSIVE_FIND_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"/r";
static int* RECURSIVE_FIND_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The insensitive name logic cybol name. */
static wchar_t* INAME_FIND_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"-iname";
static int* INAME_FIND_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* FIND_FILE_COMMANDER_OPTION_NAME_CONSTANT_HEADER */
#endif
