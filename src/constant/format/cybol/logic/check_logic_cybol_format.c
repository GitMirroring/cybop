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

#ifndef CHECK_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define CHECK_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Check
//
// IANA media type: not defined
// Self-defined media type: check
// This media type is a CYBOL extension.
//

/**
 * The check/equal logic cybol format.
 *
 * Check lexicographically for equality: ==
 *
 * Left and right operand may be a vector, but there is ALWAYS
 * just ONE boolean result value ALTOGETHER.
 *
 * Usually, lexicographical comparison applies for text,
 * i.e. strings of type "wide_character" or "character".
 *
 * But also compound parts of type "element/part" do set
 * the lexicographical flag to TRUE, so that only one
 * return value gets returned, also for deep comparison.
 *
 * Example with text:
 *
 * operation: equal
 * left operand: "Hello"
 * right operand: "World"
 * result value: 0 (which corresponds to "false")
 *
 * Expected parametres:
 * - result (required): the knowledge model, in which the result is stored (of type boolean)
 * - left (required): the left operand
 * - right (required): the right operand
 * - count (optional): the number of elements to be compared (NOT relevant for lexicographical comparison, where left and right count are used and are allowed to differ)
 * - left index (optional): the left index from where to start the comparison from (NOT relevant for lexicographical comparison)
 * - right index (optional): the right index from where to start the comparison from (NOT relevant for lexicographical comparison)
 */
static wchar_t* EQUAL_CHECK_LOGIC_CYBOL_FORMAT = L"check/equal";
static int* EQUAL_CHECK_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The check/greater logic cybol format.
 *
 * Check lexicographically for greaterness: >
 */
static wchar_t* GREATER_CHECK_LOGIC_CYBOL_FORMAT = L"check/greater";
static int* GREATER_CHECK_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The check/greater-or-equal logic cybol format.
 *
 * Check lexicographically for greaterness or equality: >=
 */
static wchar_t* GREATER_OR_EQUAL_CHECK_LOGIC_CYBOL_FORMAT = L"check/greater-or-equal";
static int* GREATER_OR_EQUAL_CHECK_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The check/less logic cybol format.
 *
 * Check lexicographically for lessness: <
 */
static wchar_t* LESS_CHECK_LOGIC_CYBOL_FORMAT = L"check/less";
static int* LESS_CHECK_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The check/less-or-equal logic cybol format.
 *
 * Check lexicographically for lessness or equality: <=
 */
static wchar_t* LESS_OR_EQUAL_CHECK_LOGIC_CYBOL_FORMAT = L"check/less-or-equal";
static int* LESS_OR_EQUAL_CHECK_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The check/unequal logic cybol format.
 *
 * Check lexicographically for unequality: !=
 */
static wchar_t* UNEQUAL_CHECK_LOGIC_CYBOL_FORMAT = L"check/unequal";
static int* UNEQUAL_CHECK_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CHECK_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
