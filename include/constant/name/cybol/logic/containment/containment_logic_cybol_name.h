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

#ifndef CONTAINMENT_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define CONTAINMENT_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The result containment logic cybol name. */
static wchar_t* RESULT_CONTAINMENT_LOGIC_CYBOL_NAME = L"result";
static int* RESULT_CONTAINMENT_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The value containment logic cybol name. */
static wchar_t* VALUE_CONTAINMENT_LOGIC_CYBOL_NAME = L"value";
static int* VALUE_CONTAINMENT_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The left containment logic cybol name. */
static wchar_t* LEFT_CONTAINMENT_LOGIC_CYBOL_NAME = L"left";
static int* LEFT_CONTAINMENT_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The right containment logic cybol name. */
static wchar_t* RIGHT_CONTAINMENT_LOGIC_CYBOL_NAME = L"right";
static int* RIGHT_CONTAINMENT_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The type containment logic cybol name. */
static wchar_t* TYPE_CONTAINMENT_LOGIC_CYBOL_NAME = L"type";
static int* TYPE_CONTAINMENT_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The selection containment logic cybol name. */
static wchar_t* SELECTION_CONTAINMENT_LOGIC_CYBOL_NAME = L"selection";
static int* SELECTION_CONTAINMENT_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CONTAINMENT_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
