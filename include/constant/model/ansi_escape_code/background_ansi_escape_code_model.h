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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef BACKGROUND_ANSI_ESCAPE_CODE_MODEL_CONSTANT_HEADER
#define BACKGROUND_ANSI_ESCAPE_CODE_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The black background ansi escape code model. */
static char BLACK_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = { 0x34, 0x30 };
static char* BLACK_BACKGROUND_ANSI_ESCAPE_CODE_MODEL = BLACK_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* BLACK_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The blue background ansi escape code model. */
static char BLUE_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = { 0x34, 0x34 };
static char* BLUE_BACKGROUND_ANSI_ESCAPE_CODE_MODEL = BLUE_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* BLUE_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The cyan blue (china blue) background ansi escape code model. */
static char CYAN_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = { 0x34, 0x36 };
static char* CYAN_BACKGROUND_ANSI_ESCAPE_CODE_MODEL = CYAN_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* CYAN_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The green background ansi escape code model. */
static char GREEN_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = { 0x34, 0x32 };
static char* GREEN_BACKGROUND_ANSI_ESCAPE_CODE_MODEL = GREEN_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* GREEN_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The magenta (violet, purple, mauve) background ansi escape code model. */
static char MAGENTA_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = { 0x34, 0x35 };
static char* MAGENTA_BACKGROUND_ANSI_ESCAPE_CODE_MODEL = MAGENTA_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* MAGENTA_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The red background ansi escape code model. */
static char RED_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = { 0x34, 0x31 };
static char* RED_BACKGROUND_ANSI_ESCAPE_CODE_MODEL = RED_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* RED_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The white background ansi escape code model. */
static char WHITE_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = { 0x34, 0x37 };
static char* WHITE_BACKGROUND_ANSI_ESCAPE_CODE_MODEL = WHITE_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* WHITE_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The yellow background ansi escape code model. */
static char YELLOW_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = { 0x34, 0x33 };
static char* YELLOW_BACKGROUND_ANSI_ESCAPE_CODE_MODEL = YELLOW_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* YELLOW_BACKGROUND_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* BACKGROUND_ANSI_ESCAPE_CODE_MODEL_CONSTANT_HEADER */
#endif
