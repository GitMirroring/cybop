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

#ifndef ACCESS_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define ACCESS_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

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
 * Counts the child nodes of a compound node of type "element/part" or "element/properties".
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
 * - part (required) [text/cybol-path]: The compound node of type "element/part" or "element/properties" whose child nodes are to be counted.
 */
static wchar_t* COUNT_ACCESS_LOGIC_CYBOL_FORMAT = L"access/count";
static int* COUNT_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/get-format logic cybol format.
 *
 * Get a part's format.
 *
 *
 *
 * Expected parametres:
 * - element (required): the part's element (name, channel, encoding, language, format, type)
 * - part (required): the knowledge path to the part
--
Description

Get a part's format.
Example

<node name="get_details" channel="inline" format="access/get-format" model="">
    <node name="element" channel="inline" format="text/cybol-path" model=".app.details"/>
    <node name="part" channel="inline" format="text/cybol-path" model=".app.node"/>
</node>
Properties
Name    Description    Required    Format    Model
element    The part's element (format).    true    path/*
part    The knowledge path to the part.    true    path/* | number/*
--
 */
static wchar_t* FORMAT_GET_ACCESS_LOGIC_CYBOL_FORMAT = L"access/get-format";
static int* FORMAT_GET_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/get-index logic cybol format.
 *
 * Gets the index of the part within the whole.
 *
 *
 *
 * Expected parametres:
 * - index (required): the determined index of the part
 * - part (required): the name of the part whose index is to be determined
 * - whole (required): the compound within which the part is situated
--
Description

Get an index.
Example

Properties
Name    Description    Required    Format    Model
index    ???    true    path/*
part    The knowledge path to the part.    true    path/* | number/*
whole    ???    true    path/* | number/*
--
 */
static wchar_t* GET_INDEX_ACCESS_LOGIC_CYBOL_FORMAT = L"access/get-index";
static int* GET_INDEX_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/get-name logic cybol format.
 *
 * Get a part's name.
 *
 *
 *
 * Expected parametres:
 * - element (required): the part's element (name, channel, encoding, language, format, type)
 * - part (required): the knowledge path to the part
--
Description

Get a part's name.
Example

<node name="copy_name_of_part_1_into_model_of_part_2" channel="inline" format="access/get-name" model="">
    <node name="element" channel="inline" format="text/cybol-path" model=".part_2"/>
    <node name="part" channel="inline" format="text/cybol-path" model=".part_1"/>
</node>
Properties
Name    Description    Required    Format    Model
element    The part's element (name).    true    path/*
part    The knowledge path to the part.    true    path/* | number/*
--
 */
static wchar_t* NAME_GET_ACCESS_LOGIC_CYBOL_FORMAT = L"access/get-name";
static int* NAME_GET_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/get-type logic cybol format.
 *
 * Get a part's type.
 *
 *
 *
 * Expected parametres:
 * - element (required): the part's element (name, channel, encoding, language, format, type)
 * - part (required): the knowledge path to the part
--
Description

Get a part's type.
Example

<node name="copy_type_of_part_1_into_model_of_part_2" channel="inline" format="access/get-type" model="">
    <node name="element" channel="inline" format="text/cybol-path" model=".part_2"/>
    <node name="part" channel="inline" format="text/cybol-path" model=".part_1"/>
</node>
Properties
Name    Description    Required    Format    Model
element    The part's element (type).    true    path/*
part    The knowledge path to the part.    true    path/* | number/*
--
 */
static wchar_t* TYPE_GET_ACCESS_LOGIC_CYBOL_FORMAT = L"access/get-type";
static int* TYPE_GET_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/indicate-empty logic cybol format.
 *
 * Indicates if data are empty, i.e. the count is zero.
 *
 *
 *
 * Expected parametres:
 * - result (required): the result flag
 *   (set to true upon successful comparison; left untouched otherwise)
 * - part (required): the part
--
Description

Indicates if data are empty, i.e. the count is zero. The operation is ONLY usable with values of format
Example

<node name="test_empty_number_empty" channel="inline" format="access/indicate-empty" model="">
  <node name="result" channel="inline" format="text/cybol-path" model=".app.flag"/>
  <node name="part" channel="inline" format="text/cybol-path" model=".app.empty_number"/>
</node>
Properties
Name    Description    Required    Format    Model
result    The result flag, set to true on successful comparison, left untouched otherwise.    true    path/*
part    The part.    true    path/* | number/*
--
 */
static wchar_t* EMPTY_INDICATE_ACCESS_LOGIC_CYBOL_FORMAT = L"access/indicate-empty";
static int* EMPTY_INDICATE_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/indicate-exists logic cybol format.
 *
 * Indicates if data exist, i.e. the count is greater than zero.
 *
 *
 *
 * Expected parametres:
 * - result (required): the result flag
 *   (set to true upon successful comparison; left untouched otherwise)
 * - part (required): the part
--
access/indicate-exists
Description

Indicates if data exist, i.e. the count is greater than zero. The operation is ONLY usable with values of format
Example

<node name="test_empty_number_exists" channel="inline" format="access/indicate-exists" model="">
  <node name="result" channel="inline" format="text/cybol-path" model=".app.flag"/>
  <node name="part" channel="inline" format="text/cybol-path" model=".app.empty_number"/>
</node>
Properties
Name    Description    Required    Format    Model
result    The result flag, set to true on successful comparison, left untouched otherwise.    true    path/*
part    The part.    true    path/* | number/*
--
 */
static wchar_t* EXISTS_INDICATE_ACCESS_LOGIC_CYBOL_FORMAT = L"access/indicate-exists";
static int* EXISTS_INDICATE_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ACCESS_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
