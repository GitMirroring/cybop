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

#ifndef FOREGROUND_ANSI_ESCAPE_CODE_MODEL_CONSTANT_SOURCE
#define FOREGROUND_ANSI_ESCAPE_CODE_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The black foreground ansi escape code model. */
static wchar_t BLACK_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0033, 0x0030};
static wchar_t* BLACK_FOREGROUND_ANSI_ESCAPE_CODE_MODEL = BLACK_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* BLACK_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The blue foreground ansi escape code model. */
static wchar_t BLUE_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0033, 0x0034};
static wchar_t* BLUE_FOREGROUND_ANSI_ESCAPE_CODE_MODEL = BLUE_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* BLUE_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The cyan blue (china blue) foreground ansi escape code model. */
static wchar_t CYAN_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0033, 0x0036};
static wchar_t* CYAN_FOREGROUND_ANSI_ESCAPE_CODE_MODEL = CYAN_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* CYAN_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The green foreground ansi escape code model. */
static wchar_t GREEN_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0033, 0x0032};
static wchar_t* GREEN_FOREGROUND_ANSI_ESCAPE_CODE_MODEL = GREEN_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* GREEN_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The magenta (violet, purple, mauve) foreground ansi escape code model. */
static wchar_t MAGENTA_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0033, 0x0035};
static wchar_t* MAGENTA_FOREGROUND_ANSI_ESCAPE_CODE_MODEL = MAGENTA_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* MAGENTA_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The red foreground ansi escape code model. */
static wchar_t RED_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0033, 0x0031};
static wchar_t* RED_FOREGROUND_ANSI_ESCAPE_CODE_MODEL = RED_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* RED_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The white foreground ansi escape code model. */
static wchar_t WHITE_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0033, 0x0037};
static wchar_t* WHITE_FOREGROUND_ANSI_ESCAPE_CODE_MODEL = WHITE_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* WHITE_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The yellow foreground ansi escape code model. */
static wchar_t YELLOW_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0033, 0x0033};
static wchar_t* YELLOW_FOREGROUND_ANSI_ESCAPE_CODE_MODEL = YELLOW_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* YELLOW_FOREGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* FOREGROUND_ANSI_ESCAPE_CODE_MODEL_CONSTANT_SOURCE */
#endif
