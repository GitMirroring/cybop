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

#ifndef SEARCH_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define SEARCH_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/**
 * The search/binary logic cybol format.
 *
 * Description:
 *
 * Finds the first occurrence of the specified element within the sorted list
 * using binary (half-interval, logarithmic, binary chop) search.
 *
 * Returns the index of the element as result or minus one (-1) if the
 * element could not be found.
 *
 * Caution! The list must be sorted first to be able to apply binary search.
 *
 * TODO: NOT IMPLEMENTED YET!
 *
 * Examples:
 *
 * <node name="search_string" channel="inline" format="search/binary" model="">
 *     <node name="index" channel="inline" format="text/cybol-path" model="#index"/>
 *     <node name="list" channel="inline" format="text/plain" model="abcdefghijklmnopqrstuvwxyz"/>
 *     <node name="element" channel="inline" format="text/plain" model="q"/>
 * </node>
 *
 * <node name="search_number" channel="inline" format="search/binary" model="">
 *     <node name="index" channel="inline" format="text/cybol-path" model="#index"/>
 *     <node name="list" channel="inline" format="number/integer" model="0,1,2,3,4,5,6,7,8,9"/>
 *     <node name="element" channel="inline" format="number/integer" model="1,2,3"/>
 *     <node name="backward" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * <node name="search_part" channel="inline" format="search/binary" model="">
 *     <node name="index" channel="inline" format="text/cybol-path" model="#index"/>
 *     <node name="list" channel="inline" format="text/cybol-path" model=".db.songs"/>
 *     <node name="element" channel="inline" format="text/cybol-path" model="#title"/>
 *     <node name="model" channel="inline" format="logicvalue/boolean" model="false"/>
 * </node>
 *
 * Properties:
 *
 * - index (required) [text/cybol-path]: The index of the found element or minus one (-1) if it could not be found within the list.
 * - list (required) [text/cybol-path | text/plain | number/integer | number/double | logicvalue/boolean | element/part]: The list to be searched through.
 * - element (required) [text/cybol-path | text/plain | number/integer | number/double | logicvalue/boolean | element/part]: The element to be searched for.
 * - model (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to search through the parts' name or model value. It makes sense only if the list is of format (type) element/part which means pointers to parts. If null, the default is false (name is used).
 * - backward (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to search forward or backward. If null, the default is false (forward search is used).
 */
static wchar_t* BINARY_SEARCH_LOGIC_CYBOL_FORMAT = L"search/binary";
static int* BINARY_SEARCH_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The search/interpolation logic cybol format.
 *
 * Description:
 *
 * Finds the first occurrence of the specified element within the sorted list
 * using interpolation binary search.
 *
 * Returns the index of the element as result or minus one (-1) if the
 * element could not be found.
 *
 * Caution! The list must be sorted first to be able to apply interpolation binary search.
 *
 * TODO: NOT IMPLEMENTED YET!
 *
 * Examples:
 *
 * <node name="search_string" channel="inline" format="search/interpolation" model="">
 *     <node name="index" channel="inline" format="text/cybol-path" model="#index"/>
 *     <node name="list" channel="inline" format="text/plain" model="abcdefghijklmnopqrstuvwxyz"/>
 *     <node name="element" channel="inline" format="text/plain" model="q"/>
 * </node>
 *
 * <node name="search_number" channel="inline" format="search/interpolation" model="">
 *     <node name="index" channel="inline" format="text/cybol-path" model="#index"/>
 *     <node name="list" channel="inline" format="number/integer" model="0,1,2,3,4,5,6,7,8,9"/>
 *     <node name="element" channel="inline" format="number/integer" model="1,2,3"/>
 *     <node name="backward" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * <node name="search_part" channel="inline" format="search/interpolation" model="">
 *     <node name="index" channel="inline" format="text/cybol-path" model="#index"/>
 *     <node name="list" channel="inline" format="text/cybol-path" model=".db.songs"/>
 *     <node name="element" channel="inline" format="text/cybol-path" model="#title"/>
 *     <node name="model" channel="inline" format="logicvalue/boolean" model="false"/>
 * </node>
 *
 * Properties:
 *
 * - index (required) [text/cybol-path]: The index of the found element or minus one (-1) if it could not be found within the list.
 * - list (required) [text/cybol-path | text/plain | number/integer | number/double | logicvalue/boolean | element/part]: The list to be searched through.
 * - element (required) [text/cybol-path | text/plain | number/integer | number/double | logicvalue/boolean | element/part]: The element to be searched for.
 * - model (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to search through the parts' name or model value. It makes sense only if the list is of format (type) element/part which means pointers to parts. If null, the default is false (name is used).
 * - backward (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to search forward or backward. If null, the default is false (forward search is used).
 */
static wchar_t* INTERPOLATION_SEARCH_LOGIC_CYBOL_FORMAT = L"search/interpolation";
static int* INTERPOLATION_SEARCH_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The search/linear logic cybol format.
 *
 * Description:
 *
 * Finds the first occurrence of the specified element within the list
 * using linear (sequential) search.
 *
 * Returns the index of the element as result or minus one (-1) if the
 * element could not be found.
 *
 * Examples:
 *
 * <node name="search_string" channel="inline" format="search/linear" model="">
 *     <node name="index" channel="inline" format="text/cybol-path" model="#index"/>
 *     <node name="list" channel="inline" format="text/plain" model="Hello cybop world!"/>
 *     <node name="element" channel="inline" format="text/plain" model="cybop"/>
 * </node>
 *
 * <node name="search_number" channel="inline" format="search/linear" model="">
 *     <node name="index" channel="inline" format="text/cybol-path" model="#index"/>
 *     <node name="list" channel="inline" format="number/integer" model="5,7,1,2,3,4,6,1,2,3,0,2"/>
 *     <node name="element" channel="inline" format="number/integer" model="1,2,3"/>
 *     <node name="backward" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * <node name="search_part" channel="inline" format="search/linear" model="">
 *     <node name="index" channel="inline" format="text/cybol-path" model="#index"/>
 *     <node name="list" channel="inline" format="text/cybol-path" model=".db.songs"/>
 *     <node name="element" channel="inline" format="text/cybol-path" model="#title"/>
 *     <node name="model" channel="inline" format="logicvalue/boolean" model="false"/>
 * </node>
 *
 * Properties:
 *
 * - index (required) [text/cybol-path]: The index of the found element or minus one (-1) if it could not be found within the list.
 * - list (required) [text/cybol-path | text/plain | number/integer | number/double | logicvalue/boolean | element/part]: The list to be searched through.
 * - element (required) [text/cybol-path | text/plain | number/integer | number/double | logicvalue/boolean | element/part]: The element to be searched for.
 * - model (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to search through the parts' name or model value. It makes sense only if the list is of format (type) element/part which means pointers to parts. If null, the default is false (name is used).
 * - backward (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to search forward or backward. If null, the default is false (forward search is used).
 */
static wchar_t* LINEAR_SEARCH_LOGIC_CYBOL_FORMAT = L"search/linear";
static int* LINEAR_SEARCH_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SEARCH_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
