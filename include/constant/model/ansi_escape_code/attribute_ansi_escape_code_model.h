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

#ifndef ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_CONSTANT_HEADER
#define ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_CONSTANT_HEADER

#include <stddef.h> // char

#include "../../../constant/model/character_code/ascii/ascii_character_code_model.h"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.h"

/**
 * The blink attribute ansi escape code model.
 *
 * 5
 */
static char* BLINK_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL = DIGIT_FIVE_ASCII_CHARACTER_CODE_MODEL_ARRAY;
static int* BLINK_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bold attribute ansi escape code model.
 *
 * 1
 */
static char* BOLD_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL = DIGIT_ONE_ASCII_CHARACTER_CODE_MODEL_ARRAY;
static int* BOLD_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hidden attribute ansi escape code model.
 *
 * 8
 */
static char* HIDDEN_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL = DIGIT_EIGHT_ASCII_CHARACTER_CODE_MODEL_ARRAY;
static int* HIDDEN_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The inverse attribute ansi escape code model.
 *
 * 7
 */
static char* INVERSE_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL = DIGIT_SEVEN_ASCII_CHARACTER_CODE_MODEL_ARRAY;
static int* INVERSE_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The off attribute ansi escape code model.
 *
 * 0
 */
static char* OFF_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL = DIGIT_ZERO_ASCII_CHARACTER_CODE_MODEL_ARRAY;
static int* OFF_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The underline attribute ansi escape code model.
 *
 * 4
 */
static char* UNDERLINE_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL = DIGIT_FOUR_ASCII_CHARACTER_CODE_MODEL_ARRAY;
static int* UNDERLINE_ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ATTRIBUTE_ANSI_ESCAPE_CODE_MODEL_CONSTANT_HEADER */
#endif
