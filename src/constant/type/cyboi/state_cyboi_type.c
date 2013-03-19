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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STATE_CYBOI_TYPE_CONSTANT_SOURCE
#define STATE_CYBOI_TYPE_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// CAUTION! These constants represent fundamental types close to the machine,
// e.g. numbers, which are used for fast processing of data internally to cyboi.
//

//
// datetime
//

/** The datetime state cyboi type. */
static int* DATETIME_STATE_CYBOI_TYPE = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// element
//

/**
 * The part element state cyboi type.
 *
 * CAUTION! The part constant has to be defined as primitive type here,
 * in order to be able to distinguish cyboi runtime parts from other pointers.
 */
static int* PART_ELEMENT_STATE_CYBOI_TYPE = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// logicvalue
//

/** The boolean logicvalue state cyboi type. */
static int* BOOLEAN_LOGICVALUE_STATE_CYBOI_TYPE = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// number
//

/**
 * The byte number state cyboi type.
 *
 * CAUTION! The byte number type internally uses
 * the same size as "unsigned char".
 * However, it IS NECESSARY to distinguish
 * between the two, in order to interpret
 * characters as numbers and NOT ascii codes.
 */
static int* BYTE_NUMBER_STATE_CYBOI_TYPE = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The complex number state cyboi type. */
static int* COMPLEX_NUMBER_STATE_CYBOI_TYPE = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The double number state cyboi type. */
static int* DOUBLE_NUMBER_STATE_CYBOI_TYPE = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fraction number state cyboi type. */
static int* FRACTION_NUMBER_STATE_CYBOI_TYPE = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The integer number state cyboi type. */
static int* INTEGER_NUMBER_STATE_CYBOI_TYPE = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unsigned long number state cyboi type. */
static int* UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE = NUMBER_35_INTEGER_STATE_CYBOI_MODEL_ARRAY;

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
