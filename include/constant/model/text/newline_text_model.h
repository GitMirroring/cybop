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

#ifndef NEWLINE_TEXT_MODEL_CONSTANT_HEADER
#define NEWLINE_TEXT_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/**
 * The macintosh newline text model until version 9.
 *
 * carriage return (cr)
 */
static wchar_t* MACINTOSH_NEWLINE_TEXT_MODEL = CARRIAGE_RETURN_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* MACINTOSH_NEWLINE_TEXT_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The unix newline text model.
 *
 * line feed (lf)
 */
static wchar_t* UNIX_NEWLINE_TEXT_MODEL = LINE_FEED_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* UNIX_NEWLINE_TEXT_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The windows newline text model.
 *
 * carriage return (cr)
 * line feed (lf)
 */
static wchar_t WINDOWS_NEWLINE_TEXT_MODEL_ARRAY[] = { 0x000D, 0x000A };
static wchar_t* WINDOWS_NEWLINE_TEXT_MODEL = WINDOWS_NEWLINE_TEXT_MODEL_ARRAY;
static int* WINDOWS_NEWLINE_TEXT_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* NEWLINE_TEXT_MODEL_CONSTANT_HEADER */
#endif
