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

#ifndef DATE_COMMANDER_OPTION_NAME_CONSTANT_HEADER
#define DATE_COMMANDER_OPTION_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The new date logic cybol name (parameter). */
static wchar_t* DATE_DATE_COMMANDER_LOGIC_CYBOL_NAME = L"date";
static int* DATE_DATE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The display date (Win32 only) logic cybol name. */
static wchar_t* DISPLAY_DATE_COMMANDER_LOGIC_CYBOL_NAME = L"display";
static int* DISPLAY_DATE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ISO date logic cybol name. */
static wchar_t* ISO_DATE_COMMANDER_LOGIC_CYBOL_NAME = L"iso";
static int* ISO_DATE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The RFC date logic cybol name. */
static wchar_t* RFC_DATE_COMMANDER_LOGIC_CYBOL_NAME = L"rfc";
static int* RFC_DATE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The UTC date logic cybol name. */
static wchar_t* UTC_DATE_COMMANDER_LOGIC_CYBOL_NAME = L"utc";
static int* UTC_DATE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* DATE_COMMANDER_OPTION_NAME_CONSTANT_HEADER */
#endif
