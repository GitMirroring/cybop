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

#ifndef DIRECTION_LAYOUT_CYBOL_MODEL_CONSTANT_HEADER
#define DIRECTION_LAYOUT_CYBOL_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The bottom-to-top direction layout cybol model. */
static wchar_t* BOTTOM_TO_TOP_DIRECTION_LAYOUT_CYBOL_MODEL = L"bottom-to-top";
static int* BOTTOM_TO_TOP_DIRECTION_LAYOUT_CYBOL_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The left-to-right direction layout cybol model. */
static wchar_t* LEFT_TO_RIGHT_DIRECTION_LAYOUT_CYBOL_MODEL = L"left-to-right";
static int* LEFT_TO_RIGHT_DIRECTION_LAYOUT_CYBOL_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The right-to-left direction layout cybol model. */
static wchar_t* RIGHT_TO_LEFT_DIRECTION_LAYOUT_CYBOL_MODEL = L"right-to-left";
static int* RIGHT_TO_LEFT_DIRECTION_LAYOUT_CYBOL_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The top-to-bottom direction layout cybol model. */
static wchar_t* TOP_TO_BOTTOM_DIRECTION_LAYOUT_CYBOL_MODEL = L"top-to-bottom";
static int* TOP_TO_BOTTOM_DIRECTION_LAYOUT_CYBOL_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* DIRECTION_LAYOUT_CYBOL_MODEL_CONSTANT_HEADER */
#endif
