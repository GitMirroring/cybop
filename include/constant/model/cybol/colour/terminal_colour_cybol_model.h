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

#ifndef TERMINAL_COLOUR_CYBOL_MODEL_CONSTANT_HEADER
#define TERMINAL_COLOUR_CYBOL_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The black terminal colour cybol model. */
static wchar_t* BLACK_TERMINAL_COLOUR_CYBOL_MODEL = L"black";
static int* BLACK_TERMINAL_COLOUR_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The blue terminal colour cybol model. */
static wchar_t* BLUE_TERMINAL_COLOUR_CYBOL_MODEL = L"blue";
static int* BLUE_TERMINAL_COLOUR_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The cyan blue (china blue) terminal colour cybol model. */
static wchar_t* CYAN_TERMINAL_COLOUR_CYBOL_MODEL = L"cyan";
static int* CYAN_TERMINAL_COLOUR_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The green terminal colour cybol model. */
static wchar_t* GREEN_TERMINAL_COLOUR_CYBOL_MODEL = L"green";
static int* GREEN_TERMINAL_COLOUR_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The magenta (violet, purple, mauve) terminal colour cybol model. */
static wchar_t* MAGENTA_TERMINAL_COLOUR_CYBOL_MODEL = L"magenta";
static int* MAGENTA_TERMINAL_COLOUR_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The red terminal colour cybol model. */
static wchar_t* RED_TERMINAL_COLOUR_CYBOL_MODEL = L"red";
static int* RED_TERMINAL_COLOUR_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The white terminal colour cybol model. */
static wchar_t* WHITE_TERMINAL_COLOUR_CYBOL_MODEL = L"white";
static int* WHITE_TERMINAL_COLOUR_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The yellow terminal colour cybol model. */
static wchar_t* YELLOW_TERMINAL_COLOUR_CYBOL_MODEL = L"yellow";
static int* YELLOW_TERMINAL_COLOUR_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TERMINAL_COLOUR_CYBOL_MODEL_CONSTANT_HEADER */
#endif
