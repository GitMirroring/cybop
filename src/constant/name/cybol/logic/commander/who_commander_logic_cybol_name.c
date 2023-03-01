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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef WHO_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define WHO_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** All User. */
static wchar_t* ALL_WHO_COMMANDER_LOGIC_CYBOL_NAME = L"all";
static int* ALL_WHO_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**time of last system boot*/
static wchar_t* BOOT_WHO_COMMANDER_LOGIC_CYBOL_NAME = L"boot";
static int* BOOT_WHO_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** print dead processes*/
static wchar_t* DEAD_WHO_COMMANDER_LOGIC_CYBOL_NAME = L"dead";
static int* DEAD_WHO_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**print system login processes*/
static wchar_t* LOGIN_WHO_COMMANDER_LOGIC_CYBOL_NAME = L"login";
static int* LOGIN_WHO_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**print only name, line, and time*/
static wchar_t* SHORT_WHO_COMMANDER_LOGIC_CYBOL_NAME = L"short";
static int* SHORT_WHO_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* WHO_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif
