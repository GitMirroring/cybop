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

#ifndef COMPARE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define COMPARE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Compare
//
// IANA media type: not defined
// Self-defined media type: compare
// This media type is a CYBOL extension.
//

/**
 * The compare/equal logic cybol format.
 *
 * Compare for equality: ==
 *
 * This is a CYBOL extension.
 */
static wchar_t* EQUAL_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/equal";
static int* EQUAL_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/greater logic cybol format.
 *
 * Compare for greaterness: >
 *
 * This is a CYBOL extension.
 */
static wchar_t* GREATER_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/greater";
static int* GREATER_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/greater-or-equal logic cybol format.
 *
 * Compare for greaterness or equality: >=
 *
 * This is a CYBOL extension.
 */
static wchar_t* GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/greater-or-equal";
static int* GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/less logic cybol format.
 *
 * Compare for lessness: <
 *
 * This is a CYBOL extension.
 */
static wchar_t* LESS_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/less";
static int* LESS_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/less-or-equal logic cybol format.
 *
 * Compare for lessness or equality: <=
 *
 * This is a CYBOL extension.
 */
static wchar_t* LESS_OR_EQUAL_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/less-or-equal";
static int* LESS_OR_EQUAL_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/unequal logic cybol format.
 *
 * Compare for unequality: !=
 *
 * This is a CYBOL extension.
 */
static wchar_t* UNEQUAL_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/unequal";
static int* UNEQUAL_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COMPARE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
