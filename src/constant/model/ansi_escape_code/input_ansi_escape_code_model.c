/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INPUT_ANSI_ESCAPE_CODE_MODEL_CONSTANT_SOURCE
#define INPUT_ANSI_ESCAPE_CODE_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Terminal input.
//
// Example: The "arrow up" key delivers: ESC[A
//

/** The down arrow input ansi escape code model. */
static wchar_t DOWN_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0042};
static wchar_t* DOWN_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL = DOWN_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* DOWN_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The left arrow input ansi escape code model. */
static wchar_t LEFT_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0044};
static wchar_t* LEFT_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL = LEFT_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* LEFT_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The right arrow input ansi escape code model. */
static wchar_t RIGHT_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0043};
static wchar_t* RIGHT_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL = RIGHT_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* RIGHT_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The up arrow input ansi escape code model. */
static wchar_t UP_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0041};
static wchar_t* UP_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL = UP_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* UP_ARROW_INPUT_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* INPUT_ANSI_ESCAPE_CODE_MODEL_CONSTANT_SOURCE */
#endif
