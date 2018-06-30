/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CHARACTER_REFERENCE_NAME_CONSTANT_SOURCE
#define CHARACTER_REFERENCE_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The &#x begin hexadecimal numeric character reference name. */
static wchar_t BEGIN_HEXADECIMAL_NUMERIC_CHARACTER_REFERENCE_NAME_ARRAY[] = {L'&', L'#', L'x'};
static wchar_t* BEGIN_HEXADECIMAL_NUMERIC_CHARACTER_REFERENCE_NAME = BEGIN_HEXADECIMAL_NUMERIC_CHARACTER_REFERENCE_NAME_ARRAY;
static int* BEGIN_HEXADECIMAL_NUMERIC_CHARACTER_REFERENCE_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The &# begin decimal numeric character reference name. */
static wchar_t BEGIN_DECIMAL_NUMERIC_CHARACTER_REFERENCE_NAME_ARRAY[] = {L'&', L'#'};
static wchar_t* BEGIN_DECIMAL_NUMERIC_CHARACTER_REFERENCE_NAME = BEGIN_DECIMAL_NUMERIC_CHARACTER_REFERENCE_NAME_ARRAY;
static int* BEGIN_DECIMAL_NUMERIC_CHARACTER_REFERENCE_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The & begin entity character reference name. */
static wchar_t BEGIN_ENTITY_CHARACTER_REFERENCE_NAME_ARRAY[] = {L'&'};
static wchar_t* BEGIN_ENTITY_CHARACTER_REFERENCE_NAME = BEGIN_ENTITY_CHARACTER_REFERENCE_NAME_ARRAY;
static int* BEGIN_ENTITY_CHARACTER_REFERENCE_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ; end character reference name. */
static wchar_t END_CHARACTER_REFERENCE_NAME_ARRAY[] = {L';'};
static wchar_t* END_CHARACTER_REFERENCE_NAME = END_CHARACTER_REFERENCE_NAME_ARRAY;
static int* END_CHARACTER_REFERENCE_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CHARACTER_REFERENCE_NAME_CONSTANT_SOURCE */
#endif
