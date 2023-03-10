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

#ifndef CYBOL_NAME_CONSTANT_HEADER
#define CYBOL_NAME_CONSTANT_HEADER

#include <stddef.h> // wchar_t

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.h"

/** The name cybol name. */
static wchar_t* NAME_CYBOL_NAME = L"name";
static int* NAME_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The channel cybol name. */
static wchar_t* CHANNEL_CYBOL_NAME = L"channel";
static int* CHANNEL_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The format cybol name. */
static wchar_t* FORMAT_CYBOL_NAME = L"format";
static int* FORMAT_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The model cybol name. */
static wchar_t* MODEL_CYBOL_NAME = L"model";
static int* MODEL_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CYBOL_NAME_CONSTANT_HEADER */
#endif
