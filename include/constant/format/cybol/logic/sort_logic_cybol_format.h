/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SORT_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define SORT_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

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
 * Sorts numbers via bubble sort algorithm.
 *
 * Examples:
 *
 * <node name="sort_visitors" channel="inline" format="sort/bubble" model="">
 *     <node name="part" channel="inline" format="text/cybol-path" model=".domain.visitors"/>
 *     <node name="criterion" channel="inline" format="text/plain" model=".surname"/>
 *     <node name="descending" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * <node name="sort_songs_by_title" channel="inline" format="sort/bubble" model="">
 *     <node name="part" channel="inline" format="text/cybol-path" model=".db.(#list)"/>
 *     <!-- The stack variable #list contains one of ".artist" or ".title" as child nodes of a song. -->
 *     <node name="criterion" channel="inline" format="text/plain" model=".(#list)"/>
 * </node>
 *
 * Properties:
 *
 * - part (required) [text/cybol-path]: The part whose child nodes are to be sorted.
 * - criterion (required) [text/cybol-path | text/plain]: The element (usually a string) to be used for comparison. It is given as plain text path to a sub element of each of the child parts that are to be sorted. Caution! One may use a path of format text/cybol-path to point to a part, but that one finally has to contain a path of format text/plain.
 * - descending (optional) [text/cybol-path | logicvalue/boolean]: The descending sort direction flag. If null, the default is false (ascending).
 */
static wchar_t* BUBBLE_SORT_LOGIC_CYBOL_FORMAT = L"sort/bubble";
static int* BUBBLE_SORT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sort/insertion logic cybol format.
 *
 * Description:
 *
 * Sorts numbers via insertion sort algorithm.
 *
 * TODO: NOT IMPLEMENTED YET!
 *
 * Examples:
 *
 * <node name="sort_visitors" channel="inline" format="sort/insertion" model="">
 *     <node name="part" channel="inline" format="text/cybol-path" model=".domain.visitors"/>
 *     <node name="criterion" channel="inline" format="text/plain" model=".surname"/>
 *     <node name="descending" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * Properties:
 *
 * - part (required) [text/cybol-path]: The part whose child nodes are to be sorted.
 * - criterion (required) [text/cybol-path | text/plain]: The element (usually a string) to be used for comparison. It is given as plain text path to a sub element of each of the child parts that are to be sorted. Caution! One may use a path of format text/cybol-path to point to a part, but that one finally has to contain a path of format text/plain.
 * - descending (optional) [text/cybol-path | logicvalue/boolean]: The descending sort direction flag. If null, the default is false (ascending).
 */
static wchar_t* INSERTION_SORT_LOGIC_CYBOL_FORMAT = L"sort/insertion";
static int* INSERTION_SORT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sort/quick logic cybol format.
 *
 * Description:
 *
 * Sorts numbers via quick sort algorithm.
 *
 * TODO: NOT IMPLEMENTED YET!
 *
 * Examples:
 *
 * <node name="sort_visitors" channel="inline" format="sort/quick" model="">
 *     <node name="part" channel="inline" format="text/cybol-path" model=".domain.visitors"/>
 *     <node name="criterion" channel="inline" format="text/plain" model=".surname"/>
 *     <node name="descending" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * Properties:
 *
 * - part (required) [text/cybol-path]: The part whose child nodes are to be sorted.
 * - criterion (required) [text/cybol-path | text/plain]: The element (usually a string) to be used for comparison. It is given as plain text path to a sub element of each of the child parts that are to be sorted. Caution! One may use a path of format text/cybol-path to point to a part, but that one finally has to contain a path of format text/plain.
 * - descending (optional) [text/cybol-path | logicvalue/boolean]: The descending sort direction flag. If null, the default is false (ascending).
 */
static wchar_t* QUICK_SORT_LOGIC_CYBOL_FORMAT = L"sort/quick";
static int* QUICK_SORT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The sort/selection logic cybol format.
 *
 * Description:
 *
 * Sorts numbers via selection sort algorithm.
 *
 * TODO: NOT IMPLEMENTED YET!
 *
 * Examples:
 *
 * <node name="sort_visitors" channel="inline" format="sort/selection" model="">
 *     <node name="part" channel="inline" format="text/cybol-path" model=".domain.visitors"/>
 *     <node name="criterion" channel="inline" format="text/plain" model=".surname"/>
 *     <node name="descending" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * Properties:
 *
 * - part (required) [text/cybol-path]: The part whose child nodes are to be sorted.
 * - criterion (required) [text/cybol-path | text/plain]: The element (usually a string) to be used for comparison. It is given as plain text path to a sub element of each of the child parts that are to be sorted. Caution! One may use a path of format text/cybol-path to point to a part, but that one finally has to contain a path of format text/plain.
 * - descending (optional) [text/cybol-path | logicvalue/boolean]: The descending sort direction flag. If null, the default is false (ascending).
 */
static wchar_t* SELECTION_SORT_LOGIC_CYBOL_FORMAT = L"sort/selection";
static int* SELECTION_SORT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SORT_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
