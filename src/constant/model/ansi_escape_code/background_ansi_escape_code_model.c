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

#ifndef BACKGROUND_ANSI_ESCAPE_CODE_MODEL_CONSTANT_SOURCE
#define BACKGROUND_ANSI_ESCAPE_CODE_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The black background ansi escape code model. */
static wchar_t BLACK_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0034, 0x0030};
static wchar_t* BLACK_BACKGROUND_ANSI_ESCAPE_CODE_MODEL = BLACK_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* BLACK_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The blue background ansi escape code model. */
static wchar_t BLUE_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0034, 0x0034};
static wchar_t* BLUE_BACKGROUND_ANSI_ESCAPE_CODE_MODEL = BLUE_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* BLUE_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The cyan blue (china blue) background ansi escape code model. */
static wchar_t CYAN_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0034, 0x0036};
static wchar_t* CYAN_BACKGROUND_ANSI_ESCAPE_CODE_MODEL = CYAN_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* CYAN_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The green background ansi escape code model. */
static wchar_t GREEN_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0034, 0x0032};
static wchar_t* GREEN_BACKGROUND_ANSI_ESCAPE_CODE_MODEL = GREEN_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* GREEN_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The magenta (violet, purple, mauve) background ansi escape code model. */
static wchar_t MAGENTA_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0034, 0x0035};
static wchar_t* MAGENTA_BACKGROUND_ANSI_ESCAPE_CODE_MODEL = MAGENTA_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* MAGENTA_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The red background ansi escape code model. */
static wchar_t RED_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0034, 0x0031};
static wchar_t* RED_BACKGROUND_ANSI_ESCAPE_CODE_MODEL = RED_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* RED_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The white background ansi escape code model. */
static wchar_t WHITE_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0034, 0x0037};
static wchar_t* WHITE_BACKGROUND_ANSI_ESCAPE_CODE_MODEL = WHITE_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* WHITE_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The yellow background ansi escape code model. */
static wchar_t YELLOW_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0034, 0x0033};
static wchar_t* YELLOW_BACKGROUND_ANSI_ESCAPE_CODE_MODEL = YELLOW_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* YELLOW_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* BACKGROUND_ANSI_ESCAPE_CODE_MODEL_CONSTANT_SOURCE */
#endif
