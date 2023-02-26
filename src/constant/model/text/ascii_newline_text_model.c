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
 * @version CYBOP 0.24.0 2022-12-24
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ASCII_NEWLINE_TEXT_MODEL_CONSTANT_SOURCE
#define ASCII_NEWLINE_TEXT_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/**
 * The macintosh ascii newline text model until version 9.
 *
 * carriage return (cr)
 */
static unsigned char* MACINTOSH_ASCII_NEWLINE_TEXT_MODEL = CARRIAGE_RETURN_ASCII_CHARACTER_CODE_MODEL_ARRAY;
static int* MACINTOSH_ASCII_NEWLINE_TEXT_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The unix ascii newline text model.
 *
 * line feed (lf)
 */
static unsigned char* UNIX_ASCII_NEWLINE_TEXT_MODEL = LINE_FEED_ASCII_CHARACTER_CODE_MODEL_ARRAY;
static int* UNIX_ASCII_NEWLINE_TEXT_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The windows ascii newline text model.
 *
 * carriage return (cr)
 * line feed (lf)
 */
static unsigned char WINDOWS_ASCII_NEWLINE_TEXT_MODEL_ARRAY[] = { 0x0D, 0x0A };
static unsigned char* WINDOWS_ASCII_NEWLINE_TEXT_MODEL = WINDOWS_ASCII_NEWLINE_TEXT_MODEL_ARRAY;
static int* WINDOWS_ASCII_NEWLINE_TEXT_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ASCII_NEWLINE_TEXT_MODEL_CONSTANT_SOURCE */
#endif
