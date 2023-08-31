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

#ifndef INPUT_ANSI_ESCAPE_CODE_MODEL_CONSTANT_HEADER
#define INPUT_ANSI_ESCAPE_CODE_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/**
 * The down arrow input ansi escape code model.
 *
 * ESC[B
 */
static char* DOWN_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL = LATIN_CAPITAL_LETTER_B_ASCII_CHARACTER_CODE_MODEL_ARRAY;
static int* DOWN_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The left arrow input ansi escape code model.
 *
 * ESC[D
 */
static char* LEFT_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL = LATIN_CAPITAL_LETTER_D_ASCII_CHARACTER_CODE_MODEL_ARRAY;
static int* LEFT_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The right arrow input ansi escape code model.
 *
 * ESC[C
 */
static char* RIGHT_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL = LATIN_CAPITAL_LETTER_C_ASCII_CHARACTER_CODE_MODEL_ARRAY;
static int* RIGHT_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The up arrow input ansi escape code model.
 *
 * ESC[A
 */
static char* UP_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL = LATIN_CAPITAL_LETTER_A_ASCII_CHARACTER_CODE_MODEL_ARRAY;
static int* UP_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* INPUT_ANSI_ESCAPE_CODE_MODEL_CONSTANT_HEADER */
#endif
