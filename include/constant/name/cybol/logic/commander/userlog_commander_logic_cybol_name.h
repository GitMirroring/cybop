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

#ifndef USERLOG_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define USERLOG_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/**
* The noheader Userlog logic cybol name.
*
*/
static wchar_t* NOHEADER_USERLOG_COMMANDER_LOGIC_CYBOL_NAME = L"nohead";
static int* NOHEADER_USERLOG_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The nocurrent Userlog logic cybol name.
*
*/
static wchar_t* NOCURRENT_USERLOG_COMMANDER_LOGIC_CYBOL_NAME = L"nocurrent";
static int* NOCURRENT_USERLOG_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The short USERLOG logic cybol name.
*
*/
static wchar_t* SHORT_USERLOG_COMMANDER_LOGIC_CYBOL_NAME = L"short";
static int* SHORT_USERLOG_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
* The oldstyle Userlog logic cybol name.
*
*/
static wchar_t* OLD_USERLOG_COMMANDER_LOGIC_CYBOL_NAME = L"old";
static int* OLD_USERLOG_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* USERLOG_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
