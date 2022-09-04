/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef BASE_NUMBER_MODEL_CONSTANT_SOURCE
#define BASE_NUMBER_MODEL_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// CAUTION! The sort order is by number base and NOT alphabetically.
//

/** The binary base number model. */
static int* BINARY_BASE_NUMBER_MODEL = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The octal base number model. */
static int* OCTAL_BASE_NUMBER_MODEL = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The decimal base number model. */
static int* DECIMAL_BASE_NUMBER_MODEL = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hexadecimal base number model. */
static int* HEXADECIMAL_BASE_NUMBER_MODEL = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* BASE_NUMBER_MODEL_CONSTANT_SOURCE */
#endif
