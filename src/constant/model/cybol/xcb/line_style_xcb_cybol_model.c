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

#ifndef LINE_STYLE_XCB_CYBOL_MODEL_CONSTANT_HEADER
#define LINE_STYLE_XCB_CYBOL_MODEL_CONSTANT_HEADER

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// The line style defines which sections of a line are drawn.
// Possible values:
//
// XCB_LINE_STYLE_DOUBLE_DASH: full path of the line is drawn,
//     but EVEN DASHES are filled DIFFERENTLY
//     than odd dashes (see fill-style), with
//     Butt cap-style used where even and odd dashes meet
// XCB_LINE_STYLE_ON_OFF_DASH: ONLY EVEN DASHES are drawn, and
//     cap-style applies to all internal ends of
//     individual dashes (except NotLast is treated as Butt)
// XCB_LINE_STYLE_SOLID: FULL PATH of the line is drawn
//

/** The double-dash line style xcb cybol model. */
static wchar_t* DOUBLE_DASH_LINE_STYLE_XCB_CYBOL_MODEL = L"double-dash";
static int* DOUBLE_DASH_LINE_STYLE_XCB_CYBOL_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The on-off-dash line style xcb cybol model. */
static wchar_t* ON_OFF_DASH_LINE_STYLE_XCB_CYBOL_MODEL = L"on-off-dash";
static int* ON_OFF_DASH_LINE_STYLE_XCB_CYBOL_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The solid line style xcb cybol model. */
static wchar_t* SOLID_LINE_STYLE_XCB_CYBOL_MODEL = L"solid";
static int* SOLID_LINE_STYLE_XCB_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LINE_STYLE_XCB_CYBOL_MODEL_CONSTANT_HEADER */
#endif
