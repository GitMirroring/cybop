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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef COLLECT_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define COLLECT_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Collect
//
// IANA media type: not defined
// Self-defined media type: collect
// This media type is a CYBOL extension.
//

/**
 * The collect/reduce logic cybol format.
 *
 * Description:
 *
 * Applies the given function to the items of the input operand node
 * and always uses the output node as second operand.
 *
 * If an initial value is necessary, then that may be provided in the output node.
 *
 * This is similar to functional programming, like for example in clojure:
 * (reduce + [1 2 3 4 5]) ;; => 15
 * (reduce conj #{} [:a :b :c]) ;; => #{:a :c :b}
 *
 * However, other than functional languages cyboi does not use recursion inside,
 * but iteration instead, which is far more efficient and consumes less stack memory.
 *
 * This reduce operation may be used together with some, but not all cyboi functions.
 * It may for instance apply arithmetic functions usefully, but not those for communication.
 *
 * Examples:
 *
 * <node name="apply_arbitrary_function" channel="inline" format="collect/reduce" model="">
 *     <node name="function" channel="inline" format="text/cybol-path" model=".function"/>
 *     <node name="output" channel="inline" format="text/cybol-path" model=".output"/>
 *     <node name="input" channel="inline" format="text/cybol-path" model=".input"/>
 * </node>
 *
 * <node name="add_operands_given_as_external_file" channel="inline" format="collect/reduce" model="">
 *     <node name="function" channel="inline" format="element/operation" model="calculate/add"/>
 *     <node name="output" channel="inline" format="text/cybol-path" model=".sum"/>
 *     <node name="input" channel="file" format="element/part" model="collect/reduce/summands.cybol"/>
 * </node>
 *
 * <node name="add_operands_given_as_children_of_tree_node" channel="inline" format="collect/reduce" model="">
 *     <node name="function" channel="inline" format="element/operation" model="calculate/add"/>
 *     <node name="output" channel="inline" format="text/cybol-path" model=".sum"/>
 *     <node name="input" channel="inline" format="text/cybol-path" model=".list-of-numbers"/>
 * </node>
 *
 * The list of numbers could be defined as follows, whereby the names can be chosen freely.
 *
 * <node>
 *     <node name="number_1" channel="inline" format="number/integer" model="4"/>
 *     <node name="number_2" channel="inline" format="number/integer" model="3"/>
 *     <node name="number_3" channel="inline" format="number/integer" model="2"/>
 * </node>
 *
 * Properties:
 *
 * - function (required) [text/cybol-path | element/operation]: The function to be executed and applied to each element of the input collection.
 * - output (required) [text/cybol-path]: The result node. It initially represents the first operand. This could be a single integer as calculation result or a part or another type.
 * - input (required) [text/cybol-path | element/part]: The collection given as separate node containing the actual elements.
 */
static wchar_t* REDUCE_COLLECT_LOGIC_CYBOL_FORMAT = L"collect/reduce";
static int* REDUCE_COLLECT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COLLECT_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
