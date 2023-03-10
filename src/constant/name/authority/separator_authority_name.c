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

#ifndef SEPARATOR_AUTHORITY_NAME_CONSTANT_HEADER
#define SEPARATOR_AUTHORITY_NAME_CONSTANT_HEADER

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The password begin (solidus, solidus) separator authority name. */
static wchar_t* PASSWORD_BEGIN_SEPARATOR_AUTHORITY_NAME = COLON_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* PASSWORD_BEGIN_SEPARATOR_AUTHORITY_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The userinfo end (commercial at) separator authority name. */
static wchar_t* USERINFO_END_SEPARATOR_AUTHORITY_NAME = COMMERCIAL_AT_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* USERINFO_END_SEPARATOR_AUTHORITY_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The port begin (colon) separator authority name. */
static wchar_t* PORT_BEGIN_SEPARATOR_AUTHORITY_NAME = COLON_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* PORT_BEGIN_SEPARATOR_AUTHORITY_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SEPARATOR_AUTHORITY_NAME_CONSTANT_HEADER */
#endif
