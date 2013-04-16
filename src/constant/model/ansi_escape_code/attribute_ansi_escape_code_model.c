/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_CONSTANT_SOURCE
#define ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The blink attribute ansi escape code model. */
static wchar_t* BLINK_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL = DIGIT_FIVE_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* BLINK_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The bold attribute ansi escape code model. */
static wchar_t* BOLD_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL = DIGIT_ONE_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* BOLD_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hidden attribute ansi escape code model. */
static wchar_t* HIDDEN_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL = DIGIT_EIGHT_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* HIDDEN_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The inverse attribute ansi escape code model. */
static wchar_t* INVERSE_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL = DIGIT_SEVEN_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* INVERSE_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The off attribute ansi escape code model. */
static wchar_t* OFF_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL = DIGIT_ZERO_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* OFF_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The underline attribute ansi escape code model. */
static wchar_t* UNDERLINE_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL = DIGIT_FOUR_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* UNDERLINE_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_CONSTANT_SOURCE */
#endif
