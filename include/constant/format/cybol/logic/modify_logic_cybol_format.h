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

#ifndef MODIFY_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define MODIFY_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Modify
//
// IANA media type: not defined
// Self-defined media type: modify
// This media type is a CYBOL extension.
//

/**
 * The modify/append logic cybol format.
 *
 * Description:
 *
 * Appends the source data to the destination.
 *
 * Examples:
 *
 * <node name="append_action" channel="inline" format="modify/append" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".path"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".action"/>
 * </node>
 *
 * <node name="append_page_file_suffix" channel="inline" format="modify/append" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model="#page_file"/>
 *     <node name="source" channel="inline" format="text/plain" model=".html"/>
 * </node>
 *
 * <node name="overwrite_link_reference_with_project_name" channel="inline" format="modify/append" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".wui.(#category_name).body.toc.(#project_name):href"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model="#project_name"/>
 * </node>
 *
 * <node name="append_path" channel="inline" format="modify/append" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".var.path"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".var.request:uri:path"/>
 * </node>
 *
 * <node name="append_scheme_suffix" channel="inline" format="modify/append" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model="#href"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".domain.uri.scheme_suffix"/>
 * </node>
 *
 * <node name="assemble_next_element_name" channel="inline" format="modify/append" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".tui.main.menu:focus"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".var.navigation"/>
 * </node>
 *
 * <node name="assemble_current_element_background" channel="inline" format="modify/append" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".var.character"/>
 *     <node name="source" channel="inline" format="text/plain" model=":background"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - move (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not to remove source elements after having been copied. If null, the default is false (deep copying). When deep copying elements (false), their whole sub tree gets cloned. With shallow copying (true), the element content does not get duplicated and only the memory pointers to the elements get copied and afterwards removed from the source container.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be copied. If null, the default is the source part model count.
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from which to start copying elements from. If null, the default is zero.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (model).
 */
static wchar_t* APPEND_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/append";
static int* APPEND_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/empty logic cybol format.
 *
 * Description:
 *
 * Removes all data (elements) from the destination (container).
 *
 * Examples:
 *
 * <node name="reset_response_model" channel="inline" format="modify/empty" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".response"/>
 * </node>
 *
 * <node name="empty_dbfile_model" channel="inline" format="modify/empty" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".var.dbfile"/>
 *     <node name="destination_properties" channel="inline" format="logicvalue/boolean" model="false"/>
 * </node>
 *
 * <node name="reset_action_properties" channel="inline" format="modify/empty" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".gui.action"/>
 *     <node name="destination_properties" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (model).
 */
static wchar_t* EMPTY_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/empty";
static int* EMPTY_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/fill logic cybol format.
 *
 * Description:
 *
 * Fills the destination (container) with repeated source data (element).
 *
 * Caution! Even though the operations "modify/fill" and "modify/repeat" both
 * copy a source element multiple times, there are differences between them.
 *
 * "modify/fill":
 * - works with any element type
 * - does not change the size of the destination container
 * - overwrites existing elements until container is filled
 * - can copy only one element (source count of one)
 *
 * "modify/repeat":
 * - works only with text (character string)
 * - adjusts the size of the destination container (grows or shrinks)
 * - overwrites existing elements and may exceed the current destination container
 * - can copy an element sequence (source count greater or equal to one)
 *
 * Examples:
 *
 * <node name="reinitialise_integer_array" channel="inline" format="modify/fill" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".var.array"/>
 *     <node name="source" channel="inline" format="number/integer" model="-1"/>
 * </node>
 *
 * <node name="overwrite_string_content" channel="inline" format="modify/fill" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".some_text"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model="#init_sign"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from which to start copying elements from. If null, the default is zero.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (model).
 */
static wchar_t* FILL_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/fill";
static int* FILL_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/insert logic cybol format.
 *
 * Description:
 *
 * Inserts the source data into the destination part at the destination index.
 *
 * Existing data behind the destination index (insertion position) get moved towards the end.
 *
 * Examples:
 *
 * <node name="insert_word_into_string" channel="inline" format="modify/insert" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".some_text"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model="#current_word"/>
 *     <node name="destination_index" channel="inline" format="text/cybol-path" model=".text_position"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - move (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not to remove source elements after having been copied. If null, the default is false (deep copying). When deep copying elements (false), their whole sub tree gets cloned. With shallow copying (true), the element content does not get duplicated and only the memory pointers to the elements get copied and afterwards removed from the source container.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be copied. If null, the default is the source part model count.
 * - destination_index (optional) [text/cybol-path | number/integer]: The destination index from which to start copying elements to. If null, the default is zero.
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from which to start copying elements from. If null, the default is zero.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (model).
 */
static wchar_t* INSERT_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/insert";
static int* INSERT_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/lower logic cybol format.
 *
 * Description:
 *
 * Converts the source string into lower case letters stored in the destination.
 *
 * The source and destination are permitted to point to the same part since the source gets buffered internally during processing.
 *
 * Caution! This operation is applicable to text only (string of characters).
 *
 * Caution! The destination length may differ from the source length since not all characters can be converted 1:1.
 * The German "small letter sharp s" for example gets converted into the two capital letters "SS".
 *
 * Further reading:
 * https://www.unicode.org/reports/tr21/tr21-5.html
 *
 * Examples:
 *
 * <node name="convert_plain_text" channel="inline" format="modify/lower" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="text/plain" model="Mein kleiner grüner Kaktus"/>
 * </node>
 *
 * <node name="convert_text_variable" channel="inline" format="modify/upper" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".text"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (model).
 */
static wchar_t* LOWER_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/lower";
static int* LOWER_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/normalise logic cybol format.
 *
 * Description:
 *
 * Removes leading and trailing whitespaces and additionally replaces all internal sequences of whitespace with just one.
 *
 * This is useful when parsing xml or html of a webpage, for example.
 *
 * Other than "modify/strip" this operation does also replace internal sequences of whitespace.
 *
 * The source and destination are permitted to point to the same part since the source gets buffered internally during processing.
 *
 * Caution! This operation is applicable to text only (character string).
 *
 * The considered whitespace characters are taken from the JSON specification:
 * https://www.json.org/
 *
 * They are:
 * - empty: ""
 * - space: 0020
 * - line feed: 000A
 * - carriage return: 000D
 * - character tabulation: 0009
 *
 * The first (empty) can obviously not be considered and is just ignored.
 *
 * Examples:
 *
 * <node name="normalise_plain_text" channel="inline" format="modify/normalise" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="text/plain" model="    Some text    with leading and trailing and intermediary    spaces    "/>
 * </node>
 *
 * <node name="normalise_text_variable" channel="inline" format="modify/normalise" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".text"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (model).
 */
static wchar_t* NORMALISE_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/normalise";
static int* NORMALISE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/overwrite logic cybol format.
 *
 * Description:
 *
 * Overwrites the destination data with the source.
 *
 * Examples:
 *
 * <node name="reset_query_exists_flag" channel="inline" format="modify/overwrite" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".query_exists"/>
 *     <node name="source" channel="inline" format="logicvalue/boolean" model="false"/>
 * </node>
 *
 * <node name="overwrite_content" channel="inline" format="modify/overwrite" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".wui.index.body.content"/>
 *     <node name="source" channel="inline" format="text/plain" model="Hello, World!"/>
 * </node>
 *
 * <node name="assign_row" channel="inline" format="modify/overwrite" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model="#row"/>
 *     <node name="source" channel="inline" format="text/plain" model="#row_heading"/>
 * </node>
 *
 * <node name="initialise_count" channel="inline" format="modify/overwrite" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".counter.count"/>
 *     <node name="source" channel="file" format="number/integer" model="counter/storage/count.txt"/>
 * </node>
 *
 * <node name="overwrite_path" channel="inline" format="modify/overwrite" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".var.path"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".tui.(.tui.active):actions"/>
 * </node>
 *
 * <node name="assemble_current_element_background" channel="inline" format="modify/overwrite" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".var.character"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".tui.main.menu:focus"/>
 * </node>
 *
 * <node name="focus_background" channel="inline" format="modify/overwrite" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model="{.var.character}"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".settings.selection.background"/>
 * </node>
 *
 * <node name="overwrite_data" channel="inline" format="modify/overwrite" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".wui.index.body.choices.table.(#name).data"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".domain.choices.(#name)"/>
 * </node>
 *
 * <node name="overwrite_calendar_week" channel="inline" format="modify/overwrite" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".wui.index.body.navigation.table.row.week"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".domain.calendar.(.var.year_string).(.var.week_string)"/>
 * </node>
 *
 * <node name="overwrite_href" channel="inline" format="modify/overwrite" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".wui.index.body.lecturers.table.(#name).(#day).link:href"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model="#href"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - move (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not to remove source elements after having been copied. If null, the default is false (deep copying). When deep copying elements (false), their whole sub tree gets cloned. With shallow copying (true), the element content does not get duplicated and only the memory pointers to the elements get copied and afterwards removed from the source container.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be copied. If null, the default is the source part model count.
 * - destination_index (optional) [text/cybol-path | number/integer]: The destination index from which to start copying elements to. If null, the default is zero.
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from which to start copying elements from. If null, the default is zero.
 * - adjust (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not the destination count shall be adjusted (true) to destination_index plus count. If null, the default is true (destination count will be adjusted). If false, the destination count remains as is and only gets extended, if the number of elements exceeds the destination count, in order to avoid memory errors caused by crossing array boundaries. Not adjusting the destination count makes sense for instance when overwriting only a few words in the middle of some text, in order to leave the trailing text untouched and the text length altogether as is.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (model).
 */
static wchar_t* OVERWRITE_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/overwrite";
static int* OVERWRITE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/remove logic cybol format.
 *
 * Description:
 *
 * Removes count elements from the destination part.
 *
 * Examples:
 *
 * <node name="remove" channel="inline" format="modify/remove" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".summand"/>
 *     <node name="count" channel="inline" format="number/integer" model="1"/>
 *     <node name="destination_properties" channel="inline" format="logicvalue/boolean" model="false"/>
 * </node>
 *
 * <node name="remove_node" channel="inline" format="modify/remove" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".db.remain"/>
 *     <node name="destination_index" channel="inline" format="text/cybol-path" model="#remain_index"/>
 *     <node name="count" channel="inline" format="number/integer" model="1"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - count (required) [text/cybol-path | number/integer]: The number of elements to be removed. If null, the default is zero.
 * - destination_index (optional) [text/cybol-path | number/integer]: The destination index from which to start removing elements. If null, the default is zero.
 * - adjust (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not the destination count shall be adjusted (true) to destination_index plus count. If null, the default is true (destination count will be adjusted). If false, the destination count remains as is and only gets extended, if the number of elements exceeds the destination count, in order to avoid memory errors caused by crossing array boundaries. Not adjusting the destination count makes sense for instance when overwriting only a few words in the middle of some text, in order to leave the trailing text untouched and the text length altogether as is.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (model).
 */
static wchar_t* REMOVE_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/remove";
static int* REMOVE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/repeat logic cybol format.
 *
 * Description:
 *
 * Writes the source repeatedly into the destination.
 *
 * The "number" property determines the number of times the source gets repeated.
 *
 * Caution! The "number" property must not be named or mixed up with "count", since the latter is used as container count and gets initialised with the source count.
 *
 * Caution! This operation is applicable to text only (character string).
 *
 * Caution! Even though the operations "modify/fill" and "modify/repeat" both
 * copy a source element multiple times, there are differences between them.
 *
 * "modify/fill":
 * - works with any element type
 * - does not change the size of the destination container
 * - overwrites existing elements until container is filled
 * - can copy only one element (source count of one)
 *
 * "modify/repeat":
 * - works only with text (character string)
 * - adjusts the size of the destination container (grows or shrinks)
 * - overwrites existing elements and may exceed the current destination container
 * - can copy an element sequence (source count greater or equal to one)
 *
 * Examples:
 *
 * <node name="initialise_with_plain_text" channel="inline" format="modify/repeat" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".string"/>
 *     <node name="source" channel="inline" format="text/plain" model="-"/>
 *     <node name="repetition" channel="inline" format="number/integer" model="8"/>
 * </node>
 *
 * <node name="initialise_with_text_variable" channel="inline" format="modify/repeat" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".string"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".text"/>
 *     <node name="repetition" channel="inline" format="number/integer" model="2"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - repetition (required) [text/cybol-path | number/integer]: The number of times the source gets repeated. If null, the default is zero.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (model).
 */
static wchar_t* REPEAT_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/repeat";
static int* REPEAT_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/replace logic cybol format.
 *
 * Description:
 *
 * Replaces the searchterm character sequence within the destination by the source sequence as replacement.
 *
 * Caution! This operation is applicable to text only (character string).
 *
 * Examples:
 *
 * <node name="replace_letters" channel="inline" format="modify/replace" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".text"/>
 *     <node name="source" channel="inline" format="text/plain" model="alphabet"/>
 *     <node name="searchterm" channel="inline" format="text/plain" model="abc"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path | text/plain]: The source part. It is used as replacement sequence.
 * - searchterm (required) [text/cybol-path | text/plain]: The character sequence to be searched and replaced.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (model).
 */
static wchar_t* REPLACE_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/replace";
static int* REPLACE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/reverse logic cybol format.
 *
 * Description:
 *
 * Reverses the order of elements in the destination part.
 *
 * Caution! This operation is applicable to text only (character string).
 *
 * Examples:
 *
 * <node name="reverse_text" channel="inline" format="modify/reverse" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".text"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (model).
 */
static wchar_t* REVERSE_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/reverse";
static int* REVERSE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/strip logic cybol format.
 *
 * Description:
 *
 * Removes leading and trailing whitespaces.
 *
 * Some programming languages and frameworks use the synonym name "trim" instead of "strip".
 *
 * Other than "modify/normalise" this operation does not replace internal sequences of whitespace.
 *
 * The source and destination are permitted to point to the same part since the source gets buffered internally during processing.
 *
 * Caution! This operation is applicable to text only (character string).
 *
 * The considered whitespace characters are taken from the JSON specification:
 * https://www.json.org/
 *
 * They are:
 * - empty: ""
 * - space: 0020
 * - line feed: 000A
 * - carriage return: 000D
 * - character tabulation: 0009
 *
 * The first (empty) can obviously not be considered and is just ignored.
 *
 * Examples:
 *
 * <node name="strip_plain_text" channel="inline" format="modify/strip" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="text/plain" model="    Some text with leading and trailing spaces    "/>
 * </node>
 *
 * <node name="strip_text_variable" channel="inline" format="modify/strip" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".text"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (model).
 */
static wchar_t* STRIP_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/strip";
static int* STRIP_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/strip-leading logic cybol format.
 *
 * Description:
 *
 * Removes leading whitespaces.
 *
 * Some programming languages and frameworks use the synonym name "trim" instead of "strip".
 *
 * Other than "modify/strip" this operation does not replace trailing whitespaces.
 *
 * The source and destination are permitted to point to the same part since the source gets buffered internally during processing.
 *
 * Caution! This operation is applicable to text only (character string).
 *
 * The considered whitespace characters are taken from the JSON specification:
 * https://www.json.org/
 *
 * They are:
 * - empty: ""
 * - space: 0020
 * - line feed: 000A
 * - carriage return: 000D
 * - character tabulation: 0009
 *
 * The first (empty) can obviously not be considered and is just ignored.
 *
 * Examples:
 *
 * <node name="strip_plain_text" channel="inline" format="modify/strip-leading" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="text/plain" model="    Some text with leading spaces"/>
 * </node>
 *
 * <node name="strip_text_variable" channel="inline" format="modify/strip-leading" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".text"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (model).
 */
static wchar_t* STRIP_LEADING_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/strip-leading";
static int* STRIP_LEADING_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/strip-trailing logic cybol format.
 *
 * Description:
 *
 * Removes trailing whitespaces.
 *
 * Some programming languages and frameworks use the synonym name "trim" instead of "strip".
 *
 * Other than "modify/strip" this operation does not replace leading whitespaces.
 *
 * The source and destination are permitted to point to the same part since the source gets buffered internally during processing.
 *
 * Caution! This operation is applicable to text only (character string).
 *
 * The considered whitespace characters are taken from the JSON specification:
 * https://www.json.org/
 *
 * They are:
 * - empty: ""
 * - space: 0020
 * - line feed: 000A
 * - carriage return: 000D
 * - character tabulation: 0009
 *
 * The first (empty) can obviously not be considered and is just ignored.
 *
 * Examples:
 *
 * <node name="strip_plain_text" channel="inline" format="modify/strip-trailing" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="text/plain" model="Some text with leading and trailing spaces    "/>
 * </node>
 *
 * <node name="strip_text_variable" channel="inline" format="modify/strip-trailing" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".text"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (model).
 */
static wchar_t* STRIP_TRAILING_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/strip-trailing";
static int* STRIP_TRAILING_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/upper logic cybol format.
 *
 * Description:
 *
 * Converts the source string into upper case letters stored in the destination.
 *
 * The source and destination are permitted to point to the same part since the source gets buffered internally during processing.
 *
 * Caution! This operation is applicable to text only (string of characters).
 *
 * Caution! The destination length may differ from the source length since not all characters can be converted 1:1.
 * The German "small letter sharp s" for example gets converted into the two capital letters "SS".
 *
 * Further reading:
 * https://www.unicode.org/reports/tr21/tr21-5.html
 *
 * Examples:
 *
 * <node name="convert_plain_text" channel="inline" format="modify/upper" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="text/plain" model="Mein kleiner grüner Kaktus"/>
 * </node>
 *
 * <node name="convert_text_variable" channel="inline" format="modify/upper" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".text"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (model).
 */
static wchar_t* UPPER_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/upper";
static int* UPPER_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MODIFY_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
