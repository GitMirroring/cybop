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

#ifndef LOGIFY_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define LOGIFY_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Logify
//
// IANA media type: not defined
// Self-defined media type: logify
// This media type is a CYBOL extension.
//

/**
 * The logify/and logic cybol format.
 *
 * Description:
 *
 * Applies the boolean logic operation AND.
 *
 * Examples:
 *
 * <node name="operation" channel="inline" format="logify/and" model="">
 *     <node name="output" channel="inline" format="text/cybol-path" model=".app.result"/>
 *     <node name="input" channel="inline" format="text/cybol-path" model=".app.operand"/>
 * </node>
 *
 * Properties:
 *
 * - output (required) [text/cybol-path]: The output resulting from the boolean logic operation. It initially represents the first input operand.
 * - input (required) [text/cybol-path | logicvalue/boolean]: The second input operand.
 */
static wchar_t* AND_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/and";
static int* AND_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/nand logic cybol format.
 *
 * Apply a boolean NAND operation.
 *
 * result = x NAND y
 *
 * Description:
 *
Applies the boolean logic operation NAND.
 *
 * Examples:
 *
 * <node name="result" channel="inline" format="logicvalue/boolean" model="false"/>
<node name="operand" channel="inline" format="logicvalue/boolean" model="false"/>
<node name="operation" channel="inline" format="logify/nand" model="">
 *     <node name="output" channel="inline" format="text/cybol-path" model=".app.result"/>
 *     <node name="input" channel="inline" format="text/cybol-path" model=".app.operand"/>
 *     <node name="type" channel="inline" format="meta/type" model="logicvalue/boolean"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
output    the knowledge model in which the output is stored; used as first input operand    true    text/cybol-path
input    the second input operand    true    text/cybol-path
type    the type of both operands    true    meta/type
 *
 * Properties:
 * - output (required): the knowledge model in which the output is stored; used as first input operand
 * - input (required): the second input operand
 */
static wchar_t* NAND_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/nand";
static int* NAND_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/neg logic cybol format.
 *
 * Apply a boolean NEG operation.
 * When used with Bit operands, then this is the TWO'S COMPLEMENT (all bits negated and added one).
 *
 * result = x NEG y
 *
 * Description:
 *
Applies the boolean logic operation NEG.
 *
 * Examples:
 *
 * <node name="result" channel="inline" format="number/byte" model="25"/>
<node name="operation" channel="inline" format="logify/neg" model="">
 *     <node name="output" channel="inline" format="text/cybol-path" model=".app.result"/>
 *     <node name="input" channel="inline" format="text/cybol-path" model=".app.result"/>
 *     <node name="type" channel="inline" format="meta/type" model="number/byte"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
output    the knowledge model in which the output is stored; used as first input operand    true    text/cybol-path
input    the second input operand    true    text/cybol-path
type    the type of both operands    true    meta/type
 *
 * Properties:
 * - output (required): the knowledge model in which the output is stored; used as first input operand
 * - input (required): the second input operand
 */
static wchar_t* NEG_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/neg";
static int* NEG_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/nor logic cybol format.
 *
 * Apply a boolean NOR operation.
 *
 * result = x NOR y
 *
 * Description:
 *
Applies the boolean logic operation NOR.
 *
 * Examples:
 *
 * <node name="result" channel="inline" format="logicvalue/boolean" model="false"/>
<node name="operand" channel="inline" format="logicvalue/boolean" model="false"/>
<node name="operation" channel="inline" format="logify/nor" model="">
 *     <node name="output" channel="inline" format="text/cybol-path" model=".app.result"/>
 *     <node name="input" channel="inline" format="text/cybol-path" model=".app.operand"/>
 *     <node name="type" channel="inline" format="meta/type" model="logicvalue/boolean"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
output    the knowledge model in which the output is stored; used as first input operand    true    text/cybol-path
input    the second input operand    true    text/cybol-path
type    the type of both operands    true    meta/type
 *
 * Properties:
 * - output (required): the knowledge model in which the output is stored; used as first input operand
 * - input (required): the second input operand
 */
static wchar_t* NOR_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/nor";
static int* NOR_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/not logic cybol format.
 *
 * Apply a boolean NOT operation.
 * When used with Bit operands, then this is the ONE'S COMPLEMENT (all bits negated).
 *
 * result = x NOT y
 *
 * Description:
 *
Applies the boolean logic operation NOT.
 *
 * Examples:
 *
 * <node name="result" channel="inline" format="logicvalue/boolean" model="true"/>
<node name="operation" channel="inline" format="logify/not" model="">
 *     <node name="output" channel="inline" format="text/cybol-path" model=".app.result"/>
 *     <node name="input" channel="inline" format="text/cybol-path" model=".app.result"/>
 *     <node name="type" channel="inline" format="meta/type" model="logicvalue/boolean"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
output    the knowledge model in which the output is stored; used as first input operand    true    text/cybol-path
input    the second input operand    true    text/cybol-path
type    the type of both operands    true    meta/type
 *
 * Properties:
 * - output (required): the knowledge model in which the output is stored; used as first input operand
 * - input (required): the second input operand
 */
static wchar_t* NOT_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/not";
static int* NOT_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/or logic cybol format.
 *
 * Apply a boolean OR operation.
 *
 * result = x OR y
 *
 * Description:
 *
Applies the boolean logic operation OR.
 *
 * Examples:
 *
 * <node name="result" channel="inline" format="logicvalue/boolean" model="false"/>
<node name="operand" channel="inline" format="logicvalue/boolean" model="false"/>
<node name="operation" channel="inline" format="logify/or" model="">
 *     <node name="output" channel="inline" format="text/cybol-path" model=".app.result"/>
 *     <node name="input" channel="inline" format="text/cybol-path" model=".app.operand"/>
 *     <node name="type" channel="inline" format="meta/type" model="logicvalue/boolean"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
output    the knowledge model in which the output is stored; used as first input operand    true    text/cybol-path
input    the second input operand    true    text/cybol-path
type    the type of both operands    true    meta/type
 *
 * Properties:
 * - output (required): the knowledge model in which the output is stored; used as first input operand
 * - input (required): the second input operand
 */
static wchar_t* OR_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/or";
static int* OR_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/xnor logic cybol format.
 *
 * Apply a boolean XNOR operation.
 *
 * result = x XNOR y
 *
 * Description:
 *
Applies the boolean logic operation XNOR.
 *
 * Examples:
 *
 * <node name="result" channel="inline" format="logicvalue/boolean" model="false"/>
<node name="operand" channel="inline" format="logicvalue/boolean" model="false"/>
<node name="operation" channel="inline" format="logify/xnor" model="">
 *     <node name="output" channel="inline" format="text/cybol-path" model=".app.result"/>
 *     <node name="input" channel="inline" format="text/cybol-path" model=".app.operand"/>
 *     <node name="type" channel="inline" format="meta/type" model="logicvalue/boolean"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
output    the knowledge model in which the output is stored; used as first input operand    true    text/cybol-path
input    the second input operand    true    text/cybol-path
type    the type of both operands    true    meta/type
 *
 * Properties:
 * - output (required): the knowledge model in which the output is stored; used as first input operand
 * - input (required): the second input operand
 */
static wchar_t* XNOR_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/xnor";
static int* XNOR_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/xor logic cybol format.
 *
 * Apply a boolean XOR operation.
 *
 * result = x XOR y
 *
 * Description:
 *
Applies the boolean logic operation XOR.
 *
 * Examples:
 *
 * <node name="result" channel="inline" format="logicvalue/boolean" model="false"/>
<node name="operand" channel="inline" format="logicvalue/boolean" model="false"/>
<node name="operation" channel="inline" format="logify/xor" model="">
 *     <node name="output" channel="inline" format="text/cybol-path" model=".app.result"/>
 *     <node name="input" channel="inline" format="text/cybol-path" model=".app.operand"/>
 *     <node name="type" channel="inline" format="meta/type" model="logicvalue/boolean"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
output    the knowledge model in which the output is stored; used as first input operand    true    text/cybol-path
input    the second input operand    true    text/cybol-path
type    the type of both operands    true    meta/type
 *
 * Properties:
 * - output (required): the knowledge model in which the output is stored; used as first input operand
 * - input (required): the second input operand
 */
static wchar_t* XOR_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/xor";
static int* XOR_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LOGIFY_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
