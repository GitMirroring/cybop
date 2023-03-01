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
 * The contain/any logic cybol format.
 *
 * Description:
 *
 * Checks if the given part contains the value at all, no matter at which position.
 *
 * TODO: NOT IMPLEMENTED YET!
 *
 * Examples:
 *
 * <node name="check_for_string" channel="inline" format="contain/any" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model="#flag"/>
 *     <node name="part" channel="inline" format="text/cybol-path" model=".gedichte.[#index]"/>
 *     <node name="value" channel="inline" format="text/plain" model="Stelldichein"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The boolean result flag indicating whether or not the part contains the value at all.
 * - part (required) [text/cybol-path]: The part in which to search.
 * - value (required) [text/cybol-path | text/plain | number/integer]: The value to search for.
 */
static wchar_t* ANY_CONTAIN_LOGIC_CYBOL_FORMAT = L"contain/any";
static int* ANY_CONTAIN_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The contain/left logic cybol format.
 *
 * Description:
 *
 * Checks if the part starts with the given value, at the beginning.
 *
 * TODO: NOT IMPLEMENTED YET!
 *
 * Examples:
 *
 * <node name="check_for_string" channel="inline" format="contain/left" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model="#flag"/>
 *     <node name="part" channel="inline" format="text/cybol-path" model=".gedichte.[#index]"/>
 *     <node name="value" channel="inline" format="text/plain" model="Vom Eise befreit"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The boolean result flag indicating whether or not the part starts with the value.
 * - part (required) [text/cybol-path]: The part in which to search.
 * - value (required) [text/cybol-path | text/plain | number/integer]: The value to search for.
 */
static wchar_t* LEFT_CONTAIN_LOGIC_CYBOL_FORMAT = L"contain/left";
static int* LEFT_CONTAIN_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The contain/right logic cybol format.
 *
 * Description:
 *
 * Checks if the part ends with the given value, at the end.
 *
 * TODO: NOT IMPLEMENTED YET!
 *
 * Examples:
 *
 * <node name="check_for_string" channel="inline" format="contain/right" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model="#flag"/>
 *     <node name="part" channel="inline" format="text/cybol-path" model=".gedichte.[#index]"/>
 *     <node name="value" channel="inline" format="text/plain" model="Laß du den Himmel, Freund, sorgen wie gestern so heut."/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The boolean result flag indicating whether or not the part ends with the value.
 * - part (required) [text/cybol-path]: The part in which to search.
 * - value (required) [text/cybol-path | text/plain | number/integer]: The value to search for.
 */
static wchar_t* RIGHT_CONTAIN_LOGIC_CYBOL_FORMAT = L"contain/right";
static int* RIGHT_CONTAIN_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CONTAIN_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
