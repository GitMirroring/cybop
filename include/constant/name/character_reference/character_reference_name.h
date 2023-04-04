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

#ifndef CHARACTER_REFERENCE_NAME_CONSTANT_HEADER
#define CHARACTER_REFERENCE_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The &# decimal numeric begin character reference name. */
static wchar_t DECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME_ARRAY[] = { L'&', L'#' };
static wchar_t* DECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME = DECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME_ARRAY;
static int* DECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The & entity begin character reference name. */
static wchar_t ENTITY_BEGIN_CHARACTER_REFERENCE_NAME_ARRAY[] = { L'&' };
static wchar_t* ENTITY_BEGIN_CHARACTER_REFERENCE_NAME = ENTITY_BEGIN_CHARACTER_REFERENCE_NAME_ARRAY;
static int* ENTITY_BEGIN_CHARACTER_REFERENCE_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The &#X capital hexadecimal numeric begin character reference name. */
static wchar_t CAPITAL_HEXADECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME_ARRAY[] = { L'&', L'#', L'X' };
static wchar_t* CAPITAL_HEXADECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME = CAPITAL_HEXADECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME_ARRAY;
static int* CAPITAL_HEXADECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ; end character reference name. */
static wchar_t END_CHARACTER_REFERENCE_NAME_ARRAY[] = { L';' };
static wchar_t* END_CHARACTER_REFERENCE_NAME = END_CHARACTER_REFERENCE_NAME_ARRAY;
static int* END_CHARACTER_REFERENCE_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The &#x small hexadecimal numeric begin character reference name. */
static wchar_t SMALL_HEXADECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME_ARRAY[] = { L'&', L'#', L'x' };
static wchar_t* SMALL_HEXADECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME = SMALL_HEXADECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME_ARRAY;
static int* SMALL_HEXADECIMAL_NUMERIC_BEGIN_CHARACTER_REFERENCE_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CHARACTER_REFERENCE_NAME_CONSTANT_HEADER */
#endif
