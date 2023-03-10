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

#ifndef JOIN_STYLE_XCB_CYBOL_MODEL_CONSTANT_HEADER
#define JOIN_STYLE_XCB_CYBOL_MODEL_CONSTANT_HEADER

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.h"

//
// The join style defines how corners are drawn for wide lines.
// Possible values:
//
// XCB_JOIN_STYLE_BEVEL: result is Butt endpoint styles,
//     and then the TRIANGULAR NOTCH IS FILLED
// XCB_JOIN_STYLE_MITER: OUTER EDGES of the two lines extend to MEET at an angle;
//     however, if the angle is less than 11 degrees,
//     a Bevel join-style is used instead
// XCB_JOIN_STYLE_ROUND: result is a CIRCULAR ARC with a diameter
//     equal to the line-width, centered on the joinpoint
//

/** The bevel join style xcb cybol model. */
static wchar_t* BEVEL_JOIN_STYLE_XCB_CYBOL_MODEL = L"bevel";
static int* BEVEL_JOIN_STYLE_XCB_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The miter join style xcb cybol model. */
static wchar_t* MITER_JOIN_STYLE_XCB_CYBOL_MODEL = L"miter";
static int* MITER_JOIN_STYLE_XCB_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The round join style xcb cybol model. */
static wchar_t* ROUND_JOIN_STYLE_XCB_CYBOL_MODEL = L"round";
static int* ROUND_JOIN_STYLE_XCB_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* JOIN_STYLE_XCB_CYBOL_MODEL_CONSTANT_HEADER */
#endif
