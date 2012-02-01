/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STATE_CYBOI_TYPE_CONSTANT_SOURCE
#define STATE_CYBOI_TYPE_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// CAUTION! These constants have been put into just ONE file,
// because they have to be assigned a unique identification integer,
// which is easier to verify having they here altogether.
//
// CAUTION! However, STATE and LOGIC constants have been split into TWO files.
// Mind the following ranges and DO NOT MIX them:
// - state constants: 0..499
// - logic constants: 500..999
//

//
// colour
//

/** The cmyk colour state cyboi type. */
static int* CMYK_COLOUR_STATE_CYBOI_TYPE = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rgb colour state cyboi type. */
static int* RGB_COLOUR_STATE_CYBOI_TYPE = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The terminal-background colour state cyboi type. */
static int* TERMINAL_BACKGROUND_COLOUR_STATE_CYBOI_TYPE = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The terminal-foreground colour state cyboi type. */
static int* TERMINAL_FOREGROUND_COLOUR_STATE_CYBOI_TYPE = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// datetime
//

/** The datetime state cyboi type. */
static int* DATETIME_STATE_CYBOI_TYPE = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hh-mm-ss datetime state cyboi type. */
static int* HH_MM_SS_DATETIME_STATE_CYBOI_TYPE = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// element
//

/** The part element state cyboi type. */
static int* PART_ELEMENT_STATE_CYBOI_TYPE = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// logicvalue
//

/** The boolean logicvalue state cyboi type. */
static int* BOOLEAN_LOGICVALUE_STATE_CYBOI_TYPE = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// number
//

/** The complex number state cyboi type. */
static int* COMPLEX_NUMBER_STATE_CYBOI_TYPE = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The double number state cyboi type. */
static int* DOUBLE_NUMBER_STATE_CYBOI_TYPE = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fraction number state cyboi type. */
static int* FRACTION_NUMBER_STATE_CYBOI_TYPE = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The integer number state cyboi type. */
static int* INTEGER_NUMBER_STATE_CYBOI_TYPE = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unsigned long number state cyboi type. */
static int* UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// path
//

/** The encapsulated path state cyboi type. */
static int* ENCAPSULATED_PATH_STATE_CYBOI_TYPE = NUMBER_40_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The knowledge path state cyboi type. */
static int* KNOWLEDGE_PATH_STATE_CYBOI_TYPE = NUMBER_41_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// pointer
//

/** The pointer state cyboi type. */
static int* POINTER_STATE_CYBOI_TYPE = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// text
//

/** The character text state cyboi type. */
static int* CHARACTER_TEXT_STATE_CYBOI_TYPE = NUMBER_60_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The wide character text state cyboi type. */
static int* WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE = NUMBER_61_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* STATE_CYBOI_TYPE_CONSTANT_SOURCE */
#endif
