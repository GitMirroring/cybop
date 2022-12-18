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
 * @version CYBOP 0.24.0 2022-12-24
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SORT_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define SORT_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Sort
//
// IANA media type: not defined
// Self-defined media type: sort
// This media type is a CYBOL extension.
//

/**
 * The sort/bubble logic cybol format.
 *
 * Description:
 *
 * Sorts numbers via bubblesort algorithm.
 *
 * Examples:
 *
 * <node name="sort_by_title" channel="inline" format="sort/bubble" model="">
 *     <node name="part" channel="inline" format="text/cybol-path" model=".db.(#list)"/>
 *     <!-- The stack variable #list contains one of ".artist" or ".title" as child nodes of a song. -->
 *     <node name="criterion" channel="inline" format="text/plain" model=".(#list)"/>
 * </node>
 *
 * Properties:
 *
 * - part (required) [text/cybol-path]: The part whose child nodes are to be sorted.
 * - criterion (required) [text/plain]: The element (usually a string) to be used for comparison. It is given as plain text path to a sub element of each of the child parts that are to be sorted. Caution! Do NOT use format text/cybol-path, but text/plain instead.
 * - descending (optional) [text/cybol-path | logicvalue/boolean]: The descending sort direction flag. If null, the default is false (ascending).
 */
static wchar_t* BUBBLE_SORT_LOGIC_CYBOL_FORMAT = L"sort/bubble";
static int* BUBBLE_SORT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sort/insertion logic cybol format.
 *
 * Sort numbers via insertionsort-algorithm.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - part (required): the knowledge model to be sorted
 * - criterion (optional): the comparison criterion used for sorting parts
 * - descending (optional; the default is "false"): the sort direction flag;
 *   false = ascending sort order;
 *   true = descending sort order
 */
static wchar_t* INSERTION_SORT_LOGIC_CYBOL_FORMAT = L"sort/insertion";
static int* INSERTION_SORT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sort/quick logic cybol format.
 *
 * Sort numbers via quicksort-algorithm.
 *
 * Description:
 *
Sort numbers via quicksort-algorithm.
 *
 * Examples:
 *
 * <node name="sort" channel="inline" format="sort/quick" model="">
 *     <node name="output" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="input" channel="inline" format="text/cybol-path" model=".unsorted"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
output    The path where the sort numbers will be written to.    true    path/* | meta/channel
input    The path where the numbers for the are taken from.    true    path/* | meta/channel
 *
 * Expected parametres:
 * - part (required): the knowledge model to be sorted
 * - criterion (optional): the comparison criterion used for sorting parts
 * - descending (optional; the default is "false"): the sort direction flag;
 *   false = ascending sort order;
 *   true = descending sort order
 */
static wchar_t* QUICK_SORT_LOGIC_CYBOL_FORMAT = L"sort/quick";
static int* QUICK_SORT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sort/selection logic cybol format.
 *
 * Sort numbers via selectionsort-algorithm.
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 *
 * Expected parametres:
 * - part (required): the knowledge model to be sorted
 * - criterion (optional): the comparison criterion used for sorting parts
 * - descending (optional; the default is "false"): the sort direction flag;
 *   false = ascending sort order;
 *   true = descending sort order
 */
static wchar_t* SELECTION_SORT_LOGIC_CYBOL_FORMAT = L"sort/selection";
static int* SELECTION_SORT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SORT_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
