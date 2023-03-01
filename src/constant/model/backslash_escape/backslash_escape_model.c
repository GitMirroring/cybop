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

#ifndef BACKSLASH_ESCAPE_MODEL_CONSTANT_SOURCE
#define BACKSLASH_ESCAPE_MODEL_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// The FIRST wide character of EACH sequence is reverse solidus (backslash)
// with the unicode code point: U+005C
//

/** The quotation mark " backslash escape model. */
static wchar_t QUOTATION_MARK_BACKSLASH_ESCAPE_MODEL_ARRAY[] = { 0x005C, 0x0022 };
static wchar_t* QUOTATION_MARK_BACKSLASH_ESCAPE_MODEL = QUOTATION_MARK_BACKSLASH_ESCAPE_MODEL_ARRAY;
static int* QUOTATION_MARK_BACKSLASH_ESCAPE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The reverse solidus (backslash) \ backslash escape model. */
static wchar_t REVERSE_SOLIDUS_BACKSLASH_ESCAPE_MODEL_ARRAY[] = { 0x005C, 0x005C };
static wchar_t* REVERSE_SOLIDUS_BACKSLASH_ESCAPE_MODEL = REVERSE_SOLIDUS_BACKSLASH_ESCAPE_MODEL_ARRAY;
static int* REVERSE_SOLIDUS_BACKSLASH_ESCAPE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The solidus (slash) / backslash escape model. */
static wchar_t SOLIDUS_BACKSLASH_ESCAPE_MODEL_ARRAY[] = { 0x005C, 0x002F };
static wchar_t* SOLIDUS_BACKSLASH_ESCAPE_MODEL = SOLIDUS_BACKSLASH_ESCAPE_MODEL_ARRAY;
static int* SOLIDUS_BACKSLASH_ESCAPE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The backspace b backslash escape model. */
static wchar_t BACKSPACE_BACKSLASH_ESCAPE_MODEL_ARRAY[] = { 0x005C, 0x0008 };
static wchar_t* BACKSPACE_BACKSLASH_ESCAPE_MODEL = BACKSPACE_BACKSLASH_ESCAPE_MODEL_ARRAY;
static int* BACKSPACE_BACKSLASH_ESCAPE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The form feed f backslash escape model. */
static wchar_t FORM_FEED_BACKSLASH_ESCAPE_MODEL_ARRAY[] = { 0x005C, 0x000C };
static wchar_t* FORM_FEED_BACKSLASH_ESCAPE_MODEL = FORM_FEED_BACKSLASH_ESCAPE_MODEL_ARRAY;
static int* FORM_FEED_BACKSLASH_ESCAPE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The line feed n backslash escape model. */
static wchar_t LINE_FEED_BACKSLASH_ESCAPE_MODEL_ARRAY[] = { 0x005C, 0x000A };
static wchar_t* LINE_FEED_BACKSLASH_ESCAPE_MODEL = LINE_FEED_BACKSLASH_ESCAPE_MODEL_ARRAY;
static int* LINE_FEED_BACKSLASH_ESCAPE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The carriage return r backslash escape model. */
static wchar_t CARRIAGE_RETURN_BACKSLASH_ESCAPE_MODEL_ARRAY[] = { 0x005C, 0x000D };
static wchar_t* CARRIAGE_RETURN_BACKSLASH_ESCAPE_MODEL = CARRIAGE_RETURN_BACKSLASH_ESCAPE_MODEL_ARRAY;
static int* CARRIAGE_RETURN_BACKSLASH_ESCAPE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The horizontal tab (character tabulation) t backslash escape model. */
static wchar_t HORIZONTAL_TAB_BACKSLASH_ESCAPE_MODEL_ARRAY[] = { 0x005C, 0x0009 };
static wchar_t* HORIZONTAL_TAB_BACKSLASH_ESCAPE_MODEL = HORIZONTAL_TAB_BACKSLASH_ESCAPE_MODEL_ARRAY;
static int* HORIZONTAL_TAB_BACKSLASH_ESCAPE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unicode u backslash escape model. */
static wchar_t UNICODE_BACKSLASH_ESCAPE_MODEL_ARRAY[] = { 0x005C, 0x0075 };
static wchar_t* UNICODE_BACKSLASH_ESCAPE_MODEL = UNICODE_BACKSLASH_ESCAPE_MODEL_ARRAY;
static int* UNICODE_BACKSLASH_ESCAPE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* BACKSLASH_ESCAPE_MODEL_CONSTANT_SOURCE */
#endif
