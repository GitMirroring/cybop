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

#ifndef MANIPULATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define MANIPULATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Manipulate bits
//
// IANA media type: not defined
// Self-defined media type: manipulate
// This media type is a CYBOL extension.
//

/**
 * The manipulate/check logic cybol format.
 *
 * Description:
 *
 * Gets the bit at the given position.
 *
 * This bit manipulation operation corresponds to the "BT" (bit) or "BTST" (bit test) assembler command.
 *
 * TODO: NOT IMPLEMENTED YET!
 *
 * Examples:
 *
 * <node name="get_bit" channel="inline" format="manipulate/check" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model="#bit"/>
 *     <node name="value" channel="inline" format="number/integer" model="71"/>
 *     <node name="position" channel="inline" format="number/integer" model="4"/>
 * </node>
 *
 * <node name="use_stack_variable" channel="inline" format="manipulate/check" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model="#bit"/>
 *     <node name="value" channel="inline" format="text/cybol-path" model=".number"/>
 *     <node name="position" channel="inline" format="text/cybol-path" model="#pos"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The bit at the given position of the value.
 * - value (required) [text/cybol-path]: The value which is to be manipulated.
 * - position (required) [text/cybol-path | number/integer]: The bit position within the value.
 * - count (optional) [text/cybol-path | number/integer]: The number of values to be manipulated. If null, the default is the value count.
 * - index (optional) [text/cybol-path | number/integer]: The index from which to start manipulating values. If null, the default is zero.
 */
static wchar_t* CHECK_MANIPULATE_LOGIC_CYBOL_FORMAT = L"manipulate/check";
static int* CHECK_MANIPULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The manipulate/clear logic cybol format.
 *
 * Description:
 *
 * Resets the bit at the given position.
 *
 * This bit manipulation operation corresponds to the "BTR" (bit reset) assembler command.
 *
 * TODO: NOT IMPLEMENTED YET!
 *
 * Examples:
 *
 * <node name="manipulate_bit" channel="inline" format="manipulate/clear" model="">
 *     <node name="value" channel="inline" format="text/cybol-path" model=".number"/>
 *     <node name="position" channel="inline" format="number/integer" model="4"/>
 * </node>
 *
 * <node name="use_stack_variable" channel="inline" format="manipulate/clear" model="">
 *     <node name="value" channel="inline" format="text/cybol-path" model=".number"/>
 *     <node name="position" channel="inline" format="text/cybol-path" model="#pos"/>
 * </node>
 *
 * Properties:
 *
 * - value (required) [text/cybol-path]: The value which is to be manipulated.
 * - position (required) [text/cybol-path | number/integer]: The bit position within the value.
 * - count (optional) [text/cybol-path | number/integer]: The number of values to be manipulated. If null, the default is the value count.
 * - index (optional) [text/cybol-path | number/integer]: The index from which to start manipulating values. If null, the default is zero.
 */
static wchar_t* CLEAR_MANIPULATE_LOGIC_CYBOL_FORMAT = L"manipulate/clear";
static int* CLEAR_MANIPULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The manipulate/rotate-left logic cybol format.
 *
 * Description:
 *
 * Rotates all bits of the value to the left by the given position.
 *
 * This bit manipulation operation corresponds to the "ROL" (rotate left) assembler command.
 *
 * TODO: NOT IMPLEMENTED YET!
 *
 * Examples:
 *
 * <node name="manipulate_bit" channel="inline" format="manipulate/rotate-left" model="">
 *     <node name="value" channel="inline" format="text/cybol-path" model=".number"/>
 *     <node name="position" channel="inline" format="number/integer" model="4"/>
 * </node>
 *
 * <node name="use_stack_variable" channel="inline" format="manipulate/rotate-left" model="">
 *     <node name="value" channel="inline" format="text/cybol-path" model=".number"/>
 *     <node name="position" channel="inline" format="text/cybol-path" model="#pos"/>
 * </node>
 *
 * Properties:
 *
 * - value (required) [text/cybol-path]: The value which is to be manipulated.
 * - position (required) [text/cybol-path | number/integer]: The bit position within the value.
 * - count (optional) [text/cybol-path | number/integer]: The number of values to be manipulated. If null, the default is the value count.
 * - index (optional) [text/cybol-path | number/integer]: The index from which to start manipulating values. If null, the default is zero.
 */
static wchar_t* ROTATE_LEFT_MANIPULATE_LOGIC_CYBOL_FORMAT = L"manipulate/rotate-left";
static int* ROTATE_LEFT_MANIPULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The manipulate/rotate-right logic cybol format.
 *
 * Description:
 *
 * Rotates all bits of the value to the right by the given position.
 *
 * This bit manipulation operation corresponds to the "ROR" (rotate right) assembler command.
 *
 * TODO: NOT IMPLEMENTED YET!
 *
 * Examples:
 *
 * <node name="manipulate_bit" channel="inline" format="manipulate/rotate-right" model="">
 *     <node name="value" channel="inline" format="text/cybol-path" model=".number"/>
 *     <node name="position" channel="inline" format="number/integer" model="4"/>
 * </node>
 *
 * <node name="use_stack_variable" channel="inline" format="manipulate/rotate-right" model="">
 *     <node name="value" channel="inline" format="text/cybol-path" model=".number"/>
 *     <node name="position" channel="inline" format="text/cybol-path" model="#pos"/>
 * </node>
 *
 * Properties:
 *
 * - value (required) [text/cybol-path]: The value which is to be manipulated.
 * - position (required) [text/cybol-path | number/integer]: The bit position within the value.
 * - count (optional) [text/cybol-path | number/integer]: The number of values to be manipulated. If null, the default is the value count.
 * - index (optional) [text/cybol-path | number/integer]: The index from which to start manipulating values. If null, the default is zero.
 */
static wchar_t* ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOL_FORMAT = L"manipulate/rotate-right";
static int* ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The manipulate/set logic cybol format.
 *
 * Description:
 *
 * Sets the bit at the given position.
 *
 * This bit manipulation operation corresponds to the "BTS" (bit set) assembler command.
 *
 * TODO: NOT IMPLEMENTED YET!
 *
 * Examples:
 *
 * <node name="manipulate_bit" channel="inline" format="manipulate/set" model="">
 *     <node name="value" channel="inline" format="text/cybol-path" model=".number"/>
 *     <node name="position" channel="inline" format="number/integer" model="4"/>
 * </node>
 *
 * <node name="use_stack_variable" channel="inline" format="manipulate/set" model="">
 *     <node name="value" channel="inline" format="text/cybol-path" model=".number"/>
 *     <node name="position" channel="inline" format="text/cybol-path" model="#pos"/>
 * </node>
 *
 * Properties:
 *
 * - value (required) [text/cybol-path]: The value which is to be manipulated.
 * - position (required) [text/cybol-path | number/integer]: The bit position within the value.
 * - count (optional) [text/cybol-path | number/integer]: The number of values to be manipulated. If null, the default is the value count.
 * - index (optional) [text/cybol-path | number/integer]: The index from which to start manipulating values. If null, the default is zero.
 */
static wchar_t* SET_MANIPULATE_LOGIC_CYBOL_FORMAT = L"manipulate/set";
static int* SET_MANIPULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The manipulate/shift-left logic cybol format.
 *
 * Description:
 *
 * Shifts all bits of the value to the left by the given position.
 *
 * This bit manipulation operation corresponds to the "SHL" (shift left) assembler command.
 *
 * TODO: NOT IMPLEMENTED YET!
 *
 * Examples:
 *
 * <node name="manipulate_bit" channel="inline" format="manipulate/shift-left" model="">
 *     <node name="value" channel="inline" format="text/cybol-path" model=".number"/>
 *     <node name="position" channel="inline" format="number/integer" model="4"/>
 * </node>
 *
 * <node name="use_stack_variable" channel="inline" format="manipulate/shift-left" model="">
 *     <node name="value" channel="inline" format="text/cybol-path" model=".number"/>
 *     <node name="position" channel="inline" format="text/cybol-path" model="#pos"/>
 * </node>
 *
 * Properties:
 *
 * - value (required) [text/cybol-path]: The value which is to be manipulated.
 * - position (required) [text/cybol-path | number/integer]: The bit position within the value.
 * - count (optional) [text/cybol-path | number/integer]: The number of values to be manipulated. If null, the default is the value count.
 * - index (optional) [text/cybol-path | number/integer]: The index from which to start manipulating values. If null, the default is zero.
 */
static wchar_t* SHIFT_LEFT_MANIPULATE_LOGIC_CYBOL_FORMAT = L"manipulate/shift-left";
static int* SHIFT_LEFT_MANIPULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The manipulate/shift-right logic cybol format.
 *
 * Description:
 *
 * Shifts all bits of the value to the right by the given position.
 *
 * This bit manipulation operation corresponds to the "SHR" (shift right) assembler command.
 *
 * TODO: NOT IMPLEMENTED YET!
 *
 * Examples:
 *
 * <node name="manipulate_bit" channel="inline" format="manipulate/shift-right" model="">
 *     <node name="value" channel="inline" format="text/cybol-path" model=".number"/>
 *     <node name="position" channel="inline" format="number/integer" model="4"/>
 * </node>
 *
 * <node name="use_stack_variable" channel="inline" format="manipulate/shift-right" model="">
 *     <node name="value" channel="inline" format="text/cybol-path" model=".number"/>
 *     <node name="position" channel="inline" format="text/cybol-path" model="#pos"/>
 * </node>
 *
 * Properties:
 *
 * - value (required) [text/cybol-path]: The value which is to be manipulated.
 * - position (required) [text/cybol-path | number/integer]: The bit position within the value.
 * - count (optional) [text/cybol-path | number/integer]: The number of values to be manipulated. If null, the default is the value count.
 * - index (optional) [text/cybol-path | number/integer]: The index from which to start manipulating values. If null, the default is zero.
 */
static wchar_t* SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOL_FORMAT = L"manipulate/shift-right";
static int* SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The manipulate/toggle logic cybol format.
 *
 * Description:
 *
 * Toggles the bit at the given position.
 *
 * This bit manipulation operation corresponds to the "CHG" (change) assembler command.
 *
 * TODO: NOT IMPLEMENTED YET!
 *
 * Examples:
 *
 * <node name="manipulate_bit" channel="inline" format="manipulate/toggle" model="">
 *     <node name="value" channel="inline" format="text/cybol-path" model=".number"/>
 *     <node name="position" channel="inline" format="number/integer" model="4"/>
 * </node>
 *
 * <node name="use_stack_variable" channel="inline" format="manipulate/toggle" model="">
 *     <node name="value" channel="inline" format="text/cybol-path" model=".number"/>
 *     <node name="position" channel="inline" format="text/cybol-path" model="#pos"/>
 * </node>
 *
 * Properties:
 *
 * - value (required) [text/cybol-path]: The value which is to be manipulated.
 * - position (required) [text/cybol-path | number/integer]: The bit position within the value.
 * - count (optional) [text/cybol-path | number/integer]: The number of values to be manipulated. If null, the default is the value count.
 * - index (optional) [text/cybol-path | number/integer]: The index from which to start manipulating values. If null, the default is zero.
 */
static wchar_t* TOGGLE_MANIPULATE_LOGIC_CYBOL_FORMAT = L"manipulate/toggle";
static int* TOGGLE_MANIPULATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MANIPULATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
