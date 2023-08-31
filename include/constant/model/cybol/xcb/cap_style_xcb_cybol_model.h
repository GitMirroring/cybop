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

#ifndef CAP_STYLE_XCB_CYBOL_MODEL_CONSTANT_HEADER
#define CAP_STYLE_XCB_CYBOL_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// The cap style defines how the endpoints of a path are drawn.
// Possible values:
//
// XCB_CAP_STYLE_BUTT: result is SQUARE at the endpoint
//     (perpendicular to the slope of the line)
//     with no projection beyond
// XCB_CAP_STYLE_NOT_LAST: result is EQUIVALENT TO Butt,
//     except that for a line-width of zero
//     the final endpoint is not drawn
// XCB_CAP_STYLE_PROJECTING: result is SQUARE at the end,
//     but the path continues BEYOND the endpoint
//     for a distance equal to half the line-width;
//     equivalent to Butt for line-width zero
// XCB_CAP_STYLE_ROUND: result is a CIRCULAR ARC with its
//     diameter equal to the line-width,
//     centered on the endpoint;
//     equivalent to Butt for line-width zero
//

/** The butt cap style xcb cybol model. */
static wchar_t* BUTT_CAP_STYLE_XCB_CYBOL_MODEL = L"butt";
static int* BUTT_CAP_STYLE_XCB_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The not-last cap style xcb cybol model. */
static wchar_t* NOT_LAST_CAP_STYLE_XCB_CYBOL_MODEL = L"not-last";
static int* NOT_LAST_CAP_STYLE_XCB_CYBOL_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The projecting cap style xcb cybol model. */
static wchar_t* PROJECTING_CAP_STYLE_XCB_CYBOL_MODEL = L"projecting";
static int* PROJECTING_CAP_STYLE_XCB_CYBOL_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The round cap style xcb cybol model. */
static wchar_t* ROUND_CAP_STYLE_XCB_CYBOL_MODEL = L"round";
static int* ROUND_CAP_STYLE_XCB_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CAP_STYLE_XCB_CYBOL_MODEL_CONSTANT_HEADER */
#endif
