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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef RETRIEVE_RANDOMISATION_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define RETRIEVE_RANDOMISATION_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Properties.
//

/** The result retrieve randomisation logic cybol name. */
static wchar_t* RESULT_RETRIEVE_RANDOMISATION_LOGIC_CYBOL_NAME = L"result";
static int* RESULT_RETRIEVE_RANDOMISATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The minimum retrieve randomisation logic cybol name. */
static wchar_t* MINIMUM_RETRIEVE_RANDOMISATION_LOGIC_CYBOL_NAME = L"minimum";
static int* MINIMUM_RETRIEVE_RANDOMISATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The maximum retrieve randomisation logic cybol name. */
static wchar_t* MAXIMUM_RETRIEVE_RANDOMISATION_LOGIC_CYBOL_NAME = L"maximum";
static int* MAXIMUM_RETRIEVE_RANDOMISATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* RETRIEVE_RANDOMISATION_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
