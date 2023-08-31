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

#ifndef REPRESENTATION_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define REPRESENTATION_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The destination representation logic cybol name. */
static wchar_t* DESTINATION_REPRESENTATION_LOGIC_CYBOL_NAME = L"destination";
static int* DESTINATION_REPRESENTATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The format representation logic cybol name. */
static wchar_t* FORMAT_REPRESENTATION_LOGIC_CYBOL_NAME = L"format";
static int* FORMAT_REPRESENTATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The language representation logic cybol name. */
static wchar_t* LANGUAGE_REPRESENTATION_LOGIC_CYBOL_NAME = L"language";
static int* LANGUAGE_REPRESENTATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The source representation logic cybol name. */
static wchar_t* SOURCE_REPRESENTATION_LOGIC_CYBOL_NAME = L"source";
static int* SOURCE_REPRESENTATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* REPRESENTATION_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
