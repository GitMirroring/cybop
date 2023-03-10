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

#ifndef LOGIFY_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define LOGIFY_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

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
 * y = x1 AND x2
 *
 * Examples:
 *
 * <node name="operation" channel="inline" format="logify/and" model="">
 *     <node name="output" channel="inline" format="text/cybol-path" model="#y"/>
 *     <node name="input" channel="inline" format="text/cybol-path" model="#x2"/>
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
 * Description:
 *
 * Applies the boolean logic operation NAND.
 *
 * y = x1 NAND x2
 *
 * Examples:
 *
 * <node name="operation" channel="inline" format="logify/nand" model="">
 *     <node name="output" channel="inline" format="text/cybol-path" model="#y"/>
 *     <node name="input" channel="inline" format="text/cybol-path" model="#x2"/>
 * </node>
 *
 * Properties:
 *
 * - output (required) [text/cybol-path]: The output resulting from the boolean logic operation. It initially represents the first input operand.
 * - input (required) [text/cybol-path | logicvalue/boolean]: The second input operand.
 */
static wchar_t* NAND_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/nand";
static int* NAND_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/neg logic cybol format.
 *
 * Description:
 *
 * Applies the boolean logic operation NEG.
 *
 * y = x1 NEG x2
 *
 * When used with Bit operands, then this is the two's complement (all bits negated and added one).
 *
 * Examples:
 *
 * <node name="operation" channel="inline" format="logify/neg" model="">
 *     <node name="output" channel="inline" format="text/cybol-path" model="#y"/>
 *     <node name="input" channel="inline" format="text/cybol-path" model="#x2"/>
 * </node>
 *
 * Properties:
 *
 * - output (required) [text/cybol-path]: The output resulting from the boolean logic operation. It initially represents the first input operand.
 * - input (required) [text/cybol-path | logicvalue/boolean]: The second input operand.
 */
static wchar_t* NEG_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/neg";
static int* NEG_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/nor logic cybol format.
 *
 * Description:
 *
 * Applies the boolean logic operation NOR.
 *
 * y = x1 NOR x2
 *
 * Examples:
 *
 * <node name="operation" channel="inline" format="logify/nor" model="">
 *     <node name="output" channel="inline" format="text/cybol-path" model="#y"/>
 *     <node name="input" channel="inline" format="text/cybol-path" model="#x2"/>
 * </node>
 *
 * Properties:
 *
 * - output (required) [text/cybol-path]: The output resulting from the boolean logic operation. It initially represents the first input operand.
 * - input (required) [text/cybol-path | logicvalue/boolean]: The second input operand.
 */
static wchar_t* NOR_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/nor";
static int* NOR_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/not logic cybol format.
 *
 * Description:
 *
 * Applies the boolean logic operation NOT.
 *
 * y = x1 NOT x2
 *
 * When used with Bit operands, then this is the one's complement (all bits negated).
 *
 * Examples:
 *
 * <node name="operation" channel="inline" format="logify/not" model="">
 *     <node name="output" channel="inline" format="text/cybol-path" model="#y"/>
 *     <node name="input" channel="inline" format="text/cybol-path" model="#x2"/>
 * </node>
 *
 * Properties:
 *
 * - output (required) [text/cybol-path]: The output resulting from the boolean logic operation. It initially represents the first input operand.
 * - input (required) [text/cybol-path | logicvalue/boolean]: The second input operand.
 */
static wchar_t* NOT_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/not";
static int* NOT_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/or logic cybol format.
 *
 * Description:
 *
 * Applies the boolean logic operation OR.
 *
 * y = x1 OR x2
 *
 * Examples:
 *
 * <node name="operation" channel="inline" format="logify/or" model="">
 *     <node name="output" channel="inline" format="text/cybol-path" model="#y"/>
 *     <node name="input" channel="inline" format="text/cybol-path" model="#x2"/>
 * </node>
 *
 * Properties:
 *
 * - output (required) [text/cybol-path]: The output resulting from the boolean logic operation. It initially represents the first input operand.
 * - input (required) [text/cybol-path | logicvalue/boolean]: The second input operand.
 */
static wchar_t* OR_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/or";
static int* OR_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/xnor logic cybol format.
 *
 * Description:
 *
 * Applies the boolean logic operation XNOR.
 *
 * y = x1 XNOR x2
 *
 * Examples:
 *
 * <node name="operation" channel="inline" format="logify/xnor" model="">
 *     <node name="output" channel="inline" format="text/cybol-path" model="#y"/>
 *     <node name="input" channel="inline" format="text/cybol-path" model="#x2"/>
 * </node>
 *
 * Properties:
 *
 * - output (required) [text/cybol-path]: The output resulting from the boolean logic operation. It initially represents the first input operand.
 * - input (required) [text/cybol-path | logicvalue/boolean]: The second input operand.
 */
static wchar_t* XNOR_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/xnor";
static int* XNOR_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/xor logic cybol format.
 *
 * Description:
 *
 * Applies the boolean logic operation XOR.
 *
 * y = x1 XOR x2
 *
 * Examples:
 *
 * <node name="operation" channel="inline" format="logify/xor" model="">
 *     <node name="output" channel="inline" format="text/cybol-path" model="#y"/>
 *     <node name="input" channel="inline" format="text/cybol-path" model="#x2"/>
 * </node>
 *
 * Properties:
 *
 * - output (required) [text/cybol-path]: The output resulting from the boolean logic operation. It initially represents the first input operand.
 * - input (required) [text/cybol-path | logicvalue/boolean]: The second input operand.
 */
static wchar_t* XOR_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/xor";
static int* XOR_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LOGIFY_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
