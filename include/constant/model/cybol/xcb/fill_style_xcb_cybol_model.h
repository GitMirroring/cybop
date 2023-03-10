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

#ifndef FILL_STYLE_XCB_CYBOL_MODEL_CONSTANT_HEADER
#define FILL_STYLE_XCB_CYBOL_MODEL_CONSTANT_HEADER

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// The fill style defines the contents of the source
// for line, text, and fill requests.
// Possible values:
//
// XCB_FILL_STYLE_OPAQUE_STIPPLED
// XCB_FILL_STYLE_SOLID
// XCB_FILL_STYLE_STIPPLED
// XCB_FILL_STYLE_TILED
//

/** The opaque-stippled fill style xcb cybol model. */
static wchar_t* OPAQUE_STIPPLED_FILL_STYLE_XCB_CYBOL_MODEL = L"opaque-stippled";
static int* OPAQUE_STIPPLED_FILL_STYLE_XCB_CYBOL_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The solid fill style xcb cybol model. */
static wchar_t* SOLID_FILL_STYLE_XCB_CYBOL_MODEL = L"solid";
static int* SOLID_FILL_STYLE_XCB_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The stippled fill style xcb cybol model. */
static wchar_t* STIPPLED_FILL_STYLE_XCB_CYBOL_MODEL = L"stippled";
static int* STIPPLED_FILL_STYLE_XCB_CYBOL_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tiled fill style xcb cybol model. */
static wchar_t* TILED_FILL_STYLE_XCB_CYBOL_MODEL = L"tiled";
static int* TILED_FILL_STYLE_XCB_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* FILL_STYLE_XCB_CYBOL_MODEL_CONSTANT_HEADER */
#endif
