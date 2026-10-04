/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef BORDER_LAYOUT_CYBOL_MODEL_CONSTANT_HEADER
#define BORDER_LAYOUT_CYBOL_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The centre border layout cybol model. */
static wchar_t* CENTRE_BORDER_LAYOUT_CYBOL_MODEL = L"centre";
static int* CENTRE_BORDER_LAYOUT_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The first-horizontal border layout cybol model. */
static wchar_t* FIRST_HORIZONTAL_BORDER_LAYOUT_CYBOL_MODEL = L"first-horizontal";
static int* FIRST_HORIZONTAL_BORDER_LAYOUT_CYBOL_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The first-vertical border layout cybol model. */
static wchar_t* FIRST_VERTICAL_BORDER_LAYOUT_CYBOL_MODEL = L"first-vertical";
static int* FIRST_VERTICAL_BORDER_LAYOUT_CYBOL_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The last-horizontal border layout cybol model. */
static wchar_t* LAST_HORIZONTAL_BORDER_LAYOUT_CYBOL_MODEL = L"last-horizontal";
static int* LAST_HORIZONTAL_BORDER_LAYOUT_CYBOL_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The last-vertical border layout cybol model. */
static wchar_t* LAST_VERTICAL_BORDER_LAYOUT_CYBOL_MODEL = L"last-vertical";
static int* LAST_VERTICAL_BORDER_LAYOUT_CYBOL_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* BORDER_LAYOUT_CYBOL_MODEL_CONSTANT_HEADER */
#endif
