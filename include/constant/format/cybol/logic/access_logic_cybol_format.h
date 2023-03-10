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

#ifndef ACCESS_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define ACCESS_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.h"

//
// Access
//
// IANA media type: not defined
// Self-defined media type: access
// This media type is a CYBOL extension.
//

/**
 * The access/count logic cybol format.
 *
 * Description:
 *
 * Counts the child nodes of a compound node of type "element/part" or "element/property".
 *
 * Examples:
 *
 * <node name="count_lecturers" channel="inline" format="access/count" model="">
 *     <node name="count" channel="inline" format="text/cybol-path" model=".count"/>
 *     <node name="part" channel="inline" format="text/cybol-path" model=".domain.lecturers"/>
 * </node>
 *
 * <node name="count_weekdays" channel="inline" format="access/count" model="">
 *     <node name="count" channel="inline" format="text/cybol-path" model="#column_count"/>
 *     <node name="part" channel="inline" format="text/cybol-path" model=".domain.weekdays"/>
 * </node>
 *
 * <node name="count_nodes" channel="inline" format="access/count" model="">
 *     <node name="count" channel="inline" format="text/cybol-path" model="#count"/>
 *     <node name="part" channel="inline" format="text/cybol-path" model=".db.(#list)"/>
 * </node>
 *
 * Properties:
 *
 * - count (required) [text/cybol-path]: The number of counted child nodes as result.
 * - part (required) [text/cybol-path]: The compound node of type "element/part" or "element/property" whose child nodes are to be counted.
 */
static wchar_t* COUNT_ACCESS_LOGIC_CYBOL_FORMAT = L"access/count";
static int* COUNT_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/get-format logic cybol format.
 *
 * Description:
 *
 * Retrieves a part's format.
 *
 * Examples:
 *
 * <node name="retrieve_details" channel="inline" format="access/get-format" model="">
 *     <node name="element" channel="inline" format="text/cybol-path" model="#format"/>
 *     <node name="part" channel="inline" format="text/cybol-path" model=".app.node"/>
 * </node>
 *
 * <node name="get_xdt_field_format" channel="inline" format="access/get-format" model="">
 *     <node name="element" channel="inline" format="text/cybol-path" model=".temporary.xdt.field.format"/>
 *     <node name="part" channel="inline" format="text/cybol-path" model=".temporary.xdt.field.root"/>
 * </node>
 *
 * Properties:
 *
 * - element (required) [text/cybol-path]: The part's format as return value.
 * - part (required) [text/cybol-path]: The node whose format is to be retrieved.
 */
static wchar_t* FORMAT_GET_ACCESS_LOGIC_CYBOL_FORMAT = L"access/get-format";
static int* FORMAT_GET_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/get-index logic cybol format.
 *
 * Description:
 *
 * Retrieves the index of the part with the given name within the whole.
 *
 * Examples:
 *
 * <node name="count_nodes" channel="inline" format="access/get-index" model="">
 *     <node name="index" channel="inline" format="text/cybol-path" model="#index"/>
 *     <node name="name" channel="inline" format="text/cybol-path" model="#name"/>
 *     <node name="whole" channel="inline" format="text/cybol-path" model=".domain.list"/>
 * </node>
 *
 * Properties:
 *
 * - index (required) [text/cybol-path]: The index of the found part with the given name within its compound whole parent node.
 * - name (required) [text/cybol-path | text/plain]: The name of the part node whose index is to be retrieved.
 * - whole (required) [text/cybol-path]: The compound whole node in which to search for the name.
 */
static wchar_t* GET_INDEX_ACCESS_LOGIC_CYBOL_FORMAT = L"access/get-index";
static int* GET_INDEX_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/get-name logic cybol format.
 *
 * Description:
 *
 * Retrieves a part's name.
 *
 * Examples:
 *
 * <node name="get_xdt_field_name" channel="inline" format="access/get-name" model="">
 *     <node name="element" channel="inline" format="text/cybol-path" model=".temporary.xdt.field.name"/>
 *     <node name="part" channel="inline" format="text/cybol-path" model=".temporary.xdt.field.root"/>
 * </node>
 *
 * <node name="copy_name_of_part" channel="inline" format="access/get-name" model="">
 *     <node name="element" channel="inline" format="text/cybol-path" model="#name"/>
 *     <node name="part" channel="inline" format="text/cybol-path" model=".list.[#index]"/>
 * </node>
 *
 * Properties:
 *
 * - element (required) [text/cybol-path]: The part's name as return value.
 * - part (required) [text/cybol-path]: The node whose name is to be retrieved.
 */
static wchar_t* NAME_GET_ACCESS_LOGIC_CYBOL_FORMAT = L"access/get-name";
static int* NAME_GET_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/get-type logic cybol format.
 *
 * Description:
 *
 * Retrieves a part's type.
 *
 * Examples:
 *
 * <node name="copy_type_of_part" channel="inline" format="access/get-type" model="">
 *     <node name="element" channel="inline" format="text/cybol-path" model="#type"/>
 *     <node name="part" channel="inline" format="text/cybol-path" model=".part_1"/>
 * </node>
 *
 * Properties:
 *
 * - element (required) [text/cybol-path]: The part's type as return value.
 * - part (required) [text/cybol-path]: The node whose type is to be retrieved.
 */
static wchar_t* TYPE_GET_ACCESS_LOGIC_CYBOL_FORMAT = L"access/get-type";
static int* TYPE_GET_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/indicate-empty logic cybol format.
 *
 * Description:
 *
 * Indicates if the given part is empty, that is its count is zero.
 *
 * Examples:
 *
 * <node name="test_empty" channel="inline" format="access/indicate-empty" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model="#flag"/>
 *     <node name="part" channel="inline" format="text/cybol-path" model=".patients.[#index].surname"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The flag being set to true if the part is empty, or being left untouched otherwise.
 * - part (required) [text/cybol-path]: The node which is to be checked for emptiness.
 */
static wchar_t* EMPTY_INDICATE_ACCESS_LOGIC_CYBOL_FORMAT = L"access/indicate-empty";
static int* EMPTY_INDICATE_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/indicate-exists logic cybol format.
 *
 * Description:
 *
 * Indicates if the given part is not empty, that is its count is greater than zero.
 *
 * Examples:
 *
 * <node name="test_exists" channel="inline" format="access/indicate-exists" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model="#flag"/>
 *     <node name="part" channel="inline" format="text/cybol-path" model="#number"/>
 * </node>
 *
 * <!-- Verify existence of given url path. -->
 * <node name="test_query" channel="inline" format="access/indicate-exists" model="">
 *     <node name="result" channel="inline" format="text/cybol-path" model=".var.query_exists"/>
 *     <node name="part" channel="inline" format="text/cybol-path" model=".var.request:uri:query"/>
 * </node>
 * <node name="evaluate_query" channel="inline" format="flow/branch" model="">
 *     <node name="criterion" channel="inline" format="text/cybol-path" model=".var.query_exists"/>
 *     <node name="true" channel="inline" format="text/cybol-path" model=".logic.evaluate_query"/>
 *     <!--
 *         CAUTION! Sending a response is important, even if the query was empty or not understood,
 *         since some browsers request a "/favicon.ico" or other things and if no response was sent,
 *         the browser would wait forever and block requests from other clients.
 *     -->
 *     <node name="false" channel="inline" format="text/cybol-path" model=".logic.send.empty_message"/>
 * </node>
 *
 * Properties:
 *
 * - result (required) [text/cybol-path]: The flag being set to true if the part is not null and not empty, or being left untouched otherwise.
 * - part (required) [text/cybol-path]: The node which is to be checked for existence and non-empty data.
 */
static wchar_t* EXISTS_INDICATE_ACCESS_LOGIC_CYBOL_FORMAT = L"access/indicate-exists";
static int* EXISTS_INDICATE_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ACCESS_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
