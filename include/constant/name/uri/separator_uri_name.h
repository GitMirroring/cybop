/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SEPARATOR_URI_NAME_CONSTANT_HEADER
#define SEPARATOR_URI_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t
//
// Library interface
//

#include "constant.h"

//
// Scheme.
//

/** The scheme end (colon) separator uri name. */
static wchar_t* SCHEME_END_SEPARATOR_URI_NAME = COLON_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* SCHEME_END_SEPARATOR_URI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The scheme with authority (colon, solidus, solidus) separator uri name. */
static wchar_t SCHEME_WITH_AUTHORITY_SEPARATOR_URI_NAME_ARRAY[] = { 0x003A, 0x002F, 0x002F };
static wchar_t* SCHEME_WITH_AUTHORITY_SEPARATOR_URI_NAME = SCHEME_WITH_AUTHORITY_SEPARATOR_URI_NAME_ARRAY;
static int* SCHEME_WITH_AUTHORITY_SEPARATOR_URI_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Authority.
//

/** The authority begin (solidus, solidus) separator uri name. */
/*??
static wchar_t AUTHORITY_BEGIN_SEPARATOR_URI_NAME_ARRAY[] = { 0x002F, 0x002F };
static wchar_t* AUTHORITY_BEGIN_SEPARATOR_URI_NAME = AUTHORITY_BEGIN_SEPARATOR_URI_NAME_ARRAY;
static int* AUTHORITY_BEGIN_SEPARATOR_URI_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;
*/

//
// Path.
//

/** The path begin (solidus) separator uri name. */
static wchar_t* PATH_BEGIN_SEPARATOR_URI_NAME = SOLIDUS_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* PATH_BEGIN_SEPARATOR_URI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Query.
//

/** The query begin (question mark) separator uri name. */
static wchar_t* QUERY_BEGIN_SEPARATOR_URI_NAME = QUESTION_MARK_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* QUERY_BEGIN_SEPARATOR_URI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The query parametre begin (ampersand) separator uri name. */
static wchar_t* QUERY_PARAMETRE_BEGIN_SEPARATOR_URI_NAME = AMPERSAND_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* QUERY_PARAMETRE_BEGIN_SEPARATOR_URI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The query parametre assignment ("equals sign") separator uri name. */
static wchar_t* QUERY_PARAMETRE_ASSIGNMENT_SEPARATOR_URI_NAME = EQUALS_SIGN_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* QUERY_PARAMETRE_ASSIGNMENT_SEPARATOR_URI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Fragment.
//

/** The fragment begin (number sign) separator uri name. */
static wchar_t* FRAGMENT_BEGIN_SEPARATOR_URI_NAME = NUMBER_SIGN_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* FRAGMENT_BEGIN_SEPARATOR_URI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SEPARATOR_URI_NAME_CONSTANT_HEADER */
#endif
