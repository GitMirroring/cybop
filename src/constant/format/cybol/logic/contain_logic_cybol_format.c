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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CONTAIN_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define CONTAIN_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Contain
//
// IANA media type: not defined
// Self-defined media type: contain
// This media type is a CYBOL extension.
//

/**
 * The contain/both logic cybol format.
 *
 * Compare if bounded area contains value.
 *
 * This is a CYBOL extension.
 */
static wchar_t* BOTH_CONTAIN_LOGIC_CYBOL_FORMAT = L"contain/both";
static int* BOTH_CONTAIN_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The contain/left logic cybol format.
 *
 * Compare if bounded area contains value.
 *
 * This is a CYBOL extension.
 */
static wchar_t* LEFT_CONTAIN_LOGIC_CYBOL_FORMAT = L"contain/left";
static int* LEFT_CONTAIN_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The contain/none logic cybol format.
 *
 * Compare if bounded area contains value.
 *
 * This is a CYBOL extension.
 */
static wchar_t* NONE_CONTAIN_LOGIC_CYBOL_FORMAT = L"contain/none";
static int* NONE_CONTAIN_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The contain/right logic cybol format.
 *
 * Compare if bounded area contains value.
 *
 * This is a CYBOL extension.
 */
static wchar_t* RIGHT_CONTAIN_LOGIC_CYBOL_FORMAT = L"contain/right";
static int* RIGHT_CONTAIN_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CONTAIN_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
