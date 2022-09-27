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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef MODIFY_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define MODIFY_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

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
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from which to start copying elements from. If null, the default is an index of zero.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (destination model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (source model).
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
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (destination model).
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
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from which to start copying elements from. If null, the default is an index of zero.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (destination model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (source model).
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
 * - destination_index (optional) [text/cybol-path | number/integer]: The destination index from which to start copying elements to. If null, the default is an index of zero.
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from which to start copying elements from. If null, the default is an index of zero.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (destination model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (source model).
 */
static wchar_t* INSERT_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/insert";
static int* INSERT_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/lower logic cybol format.
 *
 * Convert string to lower case letters.
 *
 * Caution! This operation is applicable to text only (character string).
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - move (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not to remove source elements after having been copied. If null, the default is false (deep copying). When deep copying elements (false), their whole sub tree gets cloned. With shallow copying (true), the element content does not get duplicated and only the memory pointers to the elements get copied and afterwards removed from the source container.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be copied. If null, the default is the source part model count.
 * - destination_index (optional) [text/cybol-path | number/integer]: The destination index from which to start copying elements to. If null, the default is an index of zero.
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from which to start copying elements from. If null, the default is an index of zero.
 * - adjust (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not the destination count shall be adjusted (true) to destination_index plus count. If null, the default is true (destination count will be adjusted). If false, the destination count remains as is and only gets extended, if the number of elements exceeds the destination count, in order to avoid memory errors caused by crossing array boundaries. Not adjusting the destination count makes sense for instance when overwriting only a few words in the middle of some text, in order to leave the trailing text untouched and the text length altogether as is.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (destination model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (source model).
 */
static wchar_t* LOWER_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/lower";
static int* LOWER_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/normalise logic cybol format.
 *
 * Removes leading and trailing whitespaces and additionally replaces all internal sequences
 * of whitespace with just one (useful e.g. when parsing xml or html of a webpage).
 *
 * Caution! Other than "modify/strip" this operation does also replace internal sequences of whitespace.
 *
 * Caution! This operation is applicable to text only (character string).
 *
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - move (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not to remove source elements after having been copied. If null, the default is false (deep copying). When deep copying elements (false), their whole sub tree gets cloned. With shallow copying (true), the element content does not get duplicated and only the memory pointers to the elements get copied and afterwards removed from the source container.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be copied. If null, the default is the source part model count.
 * - destination_index (optional) [text/cybol-path | number/integer]: The destination index from which to start copying elements to. If null, the default is an index of zero.
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from which to start copying elements from. If null, the default is an index of zero.
 * - adjust (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not the destination count shall be adjusted (true) to destination_index plus count. If null, the default is true (destination count will be adjusted). If false, the destination count remains as is and only gets extended, if the number of elements exceeds the destination count, in order to avoid memory errors caused by crossing array boundaries. Not adjusting the destination count makes sense for instance when overwriting only a few words in the middle of some text, in order to leave the trailing text untouched and the text length altogether as is.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (destination model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (source model).
 */
static wchar_t* NORMALISE_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/normalise";
static int* NORMALISE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/overwrite logic cybol format.
 *
 * Overwrite data with other data.
 *
 * Description:
 *
Overwrites the destination- with the source part.
 *
 * Examples:
 *
 * <node name="reset_count" channel="inline" format="modify/overwrite" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".settings.voltage_count"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".settings.voltage_default"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - move (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not to remove source elements after having been copied. If null, the default is false (deep copying). When deep copying elements (false), their whole sub tree gets cloned. With shallow copying (true), the element content does not get duplicated and only the memory pointers to the elements get copied and afterwards removed from the source container.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be copied. If null, the default is the source part model count.
 * - destination_index (optional) [text/cybol-path | number/integer]: The destination index from which to start copying elements to. If null, the default is an index of zero.
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from which to start copying elements from. If null, the default is an index of zero.
 * - adjust (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not the destination count shall be adjusted (true) to destination_index plus count. If null, the default is true (destination count will be adjusted). If false, the destination count remains as is and only gets extended, if the number of elements exceeds the destination count, in order to avoid memory errors caused by crossing array boundaries. Not adjusting the destination count makes sense for instance when overwriting only a few words in the middle of some text, in order to leave the trailing text untouched and the text length altogether as is.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (destination model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (source model).
 */
static wchar_t* OVERWRITE_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/overwrite";
static int* OVERWRITE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/remove logic cybol format.
 *
 * Remove data from other data.
 *
 * Description:
 *
Removes count elements from the part.
 *
 * Examples:
 *
 * <node name="remove" channel="inline" format="modify/remove" model="">
 *     <node name="part" channel="inline" format="text/cybol-path" model=".summand"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be copied. If null, the default is the source part model count.
 * - destination_index (optional) [text/cybol-path | number/integer]: The destination index from which to start copying elements to. If null, the default is an index of zero.
 * - adjust (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not the destination count shall be adjusted (true) to destination_index plus count. If null, the default is true (destination count will be adjusted). If false, the destination count remains as is and only gets extended, if the number of elements exceeds the destination count, in order to avoid memory errors caused by crossing array boundaries. Not adjusting the destination count makes sense for instance when overwriting only a few words in the middle of some text, in order to leave the trailing text untouched and the text length altogether as is.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (destination model).
 */
static wchar_t* REMOVE_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/remove";
static int* REMOVE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/repeat logic cybol format.
 *
 * ??TODO: Description:
 *
 * Writes a destination string whose value is the concatenation of the source string repeated count times.
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
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - move (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not to remove source elements after having been copied. If null, the default is false (deep copying). When deep copying elements (false), their whole sub tree gets cloned. With shallow copying (true), the element content does not get duplicated and only the memory pointers to the elements get copied and afterwards removed from the source container.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be copied. If null, the default is the source part model count.
 * - destination_index (optional) [text/cybol-path | number/integer]: The destination index from which to start copying elements to. If null, the default is an index of zero.
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from which to start copying elements from. If null, the default is an index of zero.
 * - adjust (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not the destination count shall be adjusted (true) to destination_index plus count. If null, the default is true (destination count will be adjusted). If false, the destination count remains as is and only gets extended, if the number of elements exceeds the destination count, in order to avoid memory errors caused by crossing array boundaries. Not adjusting the destination count makes sense for instance when overwriting only a few words in the middle of some text, in order to leave the trailing text untouched and the text length altogether as is.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (destination model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (source model).
 */
static wchar_t* REPEAT_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/repeat";
static int* REPEAT_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/replace logic cybol format.
 *
 * Replace target character sequence with replacement sequence.
 *
 * Description:
 *
TODO
 *
 * Caution! This operation is applicable to text only (character string).
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - move (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not to remove source elements after having been copied. If null, the default is false (deep copying). When deep copying elements (false), their whole sub tree gets cloned. With shallow copying (true), the element content does not get duplicated and only the memory pointers to the elements get copied and afterwards removed from the source container.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be copied. If null, the default is the source part model count.
 * - destination_index (optional) [text/cybol-path | number/integer]: The destination index from which to start copying elements to. If null, the default is an index of zero.
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from which to start copying elements from. If null, the default is an index of zero.
 * - adjust (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not the destination count shall be adjusted (true) to destination_index plus count. If null, the default is true (destination count will be adjusted). If false, the destination count remains as is and only gets extended, if the number of elements exceeds the destination count, in order to avoid memory errors caused by crossing array boundaries. Not adjusting the destination count makes sense for instance when overwriting only a few words in the middle of some text, in order to leave the trailing text untouched and the text length altogether as is.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (destination model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (source model).
 */
static wchar_t* REPLACE_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/replace";
static int* REPLACE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/reverse logic cybol format.
 *
 * Reverse the order of child nodes of the source part storing them in the destination part.
 *
 * Description:
 *
TODO
 *
 * Caution! This operation is applicable to text only (character string).
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - move (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not to remove source elements after having been copied. If null, the default is false (deep copying). When deep copying elements (false), their whole sub tree gets cloned. With shallow copying (true), the element content does not get duplicated and only the memory pointers to the elements get copied and afterwards removed from the source container.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be copied. If null, the default is the source part model count.
 * - destination_index (optional) [text/cybol-path | number/integer]: The destination index from which to start copying elements to. If null, the default is an index of zero.
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from which to start copying elements from. If null, the default is an index of zero.
 * - adjust (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not the destination count shall be adjusted (true) to destination_index plus count. If null, the default is true (destination count will be adjusted). If false, the destination count remains as is and only gets extended, if the number of elements exceeds the destination count, in order to avoid memory errors caused by crossing array boundaries. Not adjusting the destination count makes sense for instance when overwriting only a few words in the middle of some text, in order to leave the trailing text untouched and the text length altogether as is.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (destination model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (source model).
 */
static wchar_t* REVERSE_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/reverse";
static int* REVERSE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/strip logic cybol format.
 *
 * Remove leading and trailing whitespaces.
 *
 * Some programming languages and frameworks use the synonym name "trim" instead of "strip".
 *
 * Caution! Other than "modify/normalise" this operation does not replace internal sequences of whitespace.
 *
 * Description:
 *
TODO
 *
 * Caution! This operation is applicable to text only (character string).
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - move (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not to remove source elements after having been copied. If null, the default is false (deep copying). When deep copying elements (false), their whole sub tree gets cloned. With shallow copying (true), the element content does not get duplicated and only the memory pointers to the elements get copied and afterwards removed from the source container.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be copied. If null, the default is the source part model count.
 * - destination_index (optional) [text/cybol-path | number/integer]: The destination index from which to start copying elements to. If null, the default is an index of zero.
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from which to start copying elements from. If null, the default is an index of zero.
 * - adjust (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not the destination count shall be adjusted (true) to destination_index plus count. If null, the default is true (destination count will be adjusted). If false, the destination count remains as is and only gets extended, if the number of elements exceeds the destination count, in order to avoid memory errors caused by crossing array boundaries. Not adjusting the destination count makes sense for instance when overwriting only a few words in the middle of some text, in order to leave the trailing text untouched and the text length altogether as is.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (destination model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (source model).
 */
static wchar_t* STRIP_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/strip";
static int* STRIP_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/strip-leading logic cybol format.
 *
 * Remove leading whitespaces.
 *
 * Some programming languages and frameworks use the synonym name "trim" instead of "strip".
 *
 * Description:
 *
TODO
 *
 * Caution! This operation is applicable to text only (character string).
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - move (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not to remove source elements after having been copied. If null, the default is false (deep copying). When deep copying elements (false), their whole sub tree gets cloned. With shallow copying (true), the element content does not get duplicated and only the memory pointers to the elements get copied and afterwards removed from the source container.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be copied. If null, the default is the source part model count.
 * - destination_index (optional) [text/cybol-path | number/integer]: The destination index from which to start copying elements to. If null, the default is an index of zero.
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from which to start copying elements from. If null, the default is an index of zero.
 * - adjust (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not the destination count shall be adjusted (true) to destination_index plus count. If null, the default is true (destination count will be adjusted). If false, the destination count remains as is and only gets extended, if the number of elements exceeds the destination count, in order to avoid memory errors caused by crossing array boundaries. Not adjusting the destination count makes sense for instance when overwriting only a few words in the middle of some text, in order to leave the trailing text untouched and the text length altogether as is.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (destination model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (source model).
 */
static wchar_t* STRIP_LEADING_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/strip-leading";
static int* STRIP_LEADING_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/strip-trailing logic cybol format.
 *
 * Remove trailing whitespaces.
 *
 * Some programming languages and frameworks use the synonym name "trim" instead of "strip".
 *
 * Description:
 *
TODO
 *
 * Caution! This operation is applicable to text only (character string).
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - move (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not to remove source elements after having been copied. If null, the default is false (deep copying). When deep copying elements (false), their whole sub tree gets cloned. With shallow copying (true), the element content does not get duplicated and only the memory pointers to the elements get copied and afterwards removed from the source container.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be copied. If null, the default is the source part model count.
 * - destination_index (optional) [text/cybol-path | number/integer]: The destination index from which to start copying elements to. If null, the default is an index of zero.
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from which to start copying elements from. If null, the default is an index of zero.
 * - adjust (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not the destination count shall be adjusted (true) to destination_index plus count. If null, the default is true (destination count will be adjusted). If false, the destination count remains as is and only gets extended, if the number of elements exceeds the destination count, in order to avoid memory errors caused by crossing array boundaries. Not adjusting the destination count makes sense for instance when overwriting only a few words in the middle of some text, in order to leave the trailing text untouched and the text length altogether as is.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (destination model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (source model).
 */
static wchar_t* STRIP_TRAILING_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/strip-trailing";
static int* STRIP_TRAILING_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/upper logic cybol format.
 *
 * Convert string to upper case letters.
 *
 * Description:
 *
TODO
 *
 * Caution! This operation is applicable to text only (character string).
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination part.
 * - source (required) [text/cybol-path]: The source part.
 * - move (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not to remove source elements after having been copied. If null, the default is false (deep copying). When deep copying elements (false), their whole sub tree gets cloned. With shallow copying (true), the element content does not get duplicated and only the memory pointers to the elements get copied and afterwards removed from the source container.
 * - count (optional) [text/cybol-path | number/integer]: The number of elements to be copied. If null, the default is the source part model count.
 * - destination_index (optional) [text/cybol-path | number/integer]: The destination index from which to start copying elements to. If null, the default is an index of zero.
 * - source_index (optional) [text/cybol-path | number/integer]: The source index from which to start copying elements from. If null, the default is an index of zero.
 * - adjust (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether or not the destination count shall be adjusted (true) to destination_index plus count. If null, the default is true (destination count will be adjusted). If false, the destination count remains as is and only gets extended, if the number of elements exceeds the destination count, in order to avoid memory errors caused by crossing array boundaries. Not adjusting the destination count makes sense for instance when overwriting only a few words in the middle of some text, in order to leave the trailing text untouched and the text length altogether as is.
 * - destination_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as destination. If null, the default is false (destination model).
 * - source_properties (optional) [text/cybol-path | logicvalue/boolean]: The flag indicating whether to use the model or properties container as source. If null, the default is false (source model).
 */
static wchar_t* UPPER_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/upper";
static int* UPPER_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MODIFY_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
