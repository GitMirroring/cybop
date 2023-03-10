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

#ifndef URI_CYBOI_NAME_CONSTANT_HEADER
#define URI_CYBOI_NAME_CONSTANT_HEADER

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// The constants defined here are copies of the standard constants
// that may be found in files of this same directory.
//
// The difference is that these constants are of type "wchar_t"
// and are prefixed with "CYBOI_".
//
// This duplication of constants is necessary, because names or models
// of standard formats like HTTP or xDT are not always intuitive,
// so that CYBOI uses its own speaking names internally.
//
// Examples:
// - HTTP header names start with a capital letter, but CYBOI uses lower-case names only
// - URI parts do not have a name at all, so that CYBOI has to invent some
// - xDT fields are represented by numbers, but CYBOI uses speaking names (text) only
//

/** The scheme uri cyboi name. */
static wchar_t* SCHEME_URI_CYBOI_NAME = L"scheme";
static int* SCHEME_URI_CYBOI_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The authority uri cyboi name. */
static wchar_t* AUTHORITY_URI_CYBOI_NAME = L"authority";
static int* AUTHORITY_URI_CYBOI_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The authority-text uri cyboi name. */
static wchar_t* AUTHORITY_TEXT_URI_CYBOI_NAME = L"authority-text";
static int* AUTHORITY_TEXT_URI_CYBOI_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The path uri cyboi name. */
static wchar_t* PATH_URI_CYBOI_NAME = L"path";
static int* PATH_URI_CYBOI_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The query uri cyboi name. */
static wchar_t* QUERY_URI_CYBOI_NAME = L"query";
static int* QUERY_URI_CYBOI_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fragment uri cyboi name. */
static wchar_t* FRAGMENT_URI_CYBOI_NAME = L"fragment";
static int* FRAGMENT_URI_CYBOI_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* URI_CYBOI_NAME_CONSTANT_HEADER */
#endif
