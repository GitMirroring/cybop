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
 * Append data to other data.
 *
 * Description:
 *
Appends the source to the destination part.
 *
 * Examples:
 *
 * <node name="append_command" channel="inline" format="modify/append" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".app.safetmp.path"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".app.safetmp.operation_type"/>
 *     <node name="type" channel="inline" format="meta/type" model="text/plain"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
destination	the destination part	true	text/cybol-path
source	the source part	true	text/cybol-path
count	If null, the part model count will be used instead. The number of elements to be overwritten.	false	number/integer
destination_index	If null, an index of zero will be used instead. The destination index from which to start copying elements to.	false	number/integer
source_index	If null, an index of zero will be used instead. The source index from which to start copying elements from.	false	number/integer
adjust	The default is 'true'. If null, the count WILL BE adjusted. The flag indicating whether or not the destination shall be adjusted to.	false	logicvalue/boolean
destination_properties	The default is 'false'. If null, the destination model (NOT properties) container will be used. The flag indicating whether to use the destination model or properties container.	false	logicvalue/boolean
source_properties	The default is 'false'. If null, the source model (NOT properties) container will be used. The flag indicating whether to use the source model or properties container.	false	logicvalue/boolean
 *
 * Expected parametres:
 * - destination (required): the destination part
 * - source (required): the source part
 * - move (optional; the default is "false"; if null, DEEP copying will be used):
 *   the flag indicating whether or not to remove source elements after having been copied;
 *   false = DEEP copy: only copying elements, their whole deep sub tree needs to be cloned
 *   true = SHALLOW copy: moving (copying + removing) elements, a shallow copy of the pointer suffices;
 * - count (optional; if null, the source part model count will be used instead):
 *   the number of elements to be modified
 * - destination_index (optional; if null, an index of zero will be used instead):
 *   the destination index from which to start copying elements to
 * - source_index (optional; if null, an index of zero will be used instead):
 *   the source index from which to start copying elements from
 * - adjust (optional; the default is "true"; if null, the destination count WILL BE adjusted):
 *   the flag indicating whether or not the destination shall be adjusted to
 *   destination_index + count_of_elements_to_be_copied;
 *   otherwise, the destination count by default remains as is
 *   and only gets extended, if the number of elements exceeds the destination count,
 *   in order to avoid memory errors caused by crossing array boundaries;
 *   Not adjusting the destination count makes sense when overwriting only a few words
 *   in the middle of some text, in order to leave the trailing text untouched
 *   and the text length altogether as is.
 * - destination_properties (optional; the default is "false"; if null, the MODEL container is used):
 *   the flag indicating whether the model- or properties container should be used;
 *   false = destination MODEL container;
 *   true = destination PROPERTIES container
 * - source_properties (optional; the default is "false"; if null, the MODEL container is used):
 *   the flag indicating whether the model- or properties container should be used;
 *   false = source MODEL container;
 *   true = source PROPERTIES container
 */
static wchar_t* APPEND_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/append";
static int* APPEND_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/empty logic cybol format.
 *
 * Empty all data.
 *
 * Description:
 *
Empties the part, i.e. removes all of its elements.
 *
 * Examples:
 *
 * <node name="reset_buffer" channel="inline" format="modify/empty" model="">
 *     <node name="part" channel="inline" format="text/cybol-path" model=".settings.voltage_buffer"/>
 *     <node name="model" channel="inline" format="logicvalue/boolean" model="true"/>
 *     <node name="properties" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
destination	the destination part	true	text/cybol-path
count	If null, the part model count will be used instead. The number of elements to be overwritten.	false	number/integer
destination_index	If null, an index of zero will be used instead. The destination index from which to start copying elements to.	false	number/integer
adjust	The default is 'true'. If null, the count WILL BE adjusted. The flag indicating whether or not the destination shall be adjusted to.	false	logicvalue/boolean
destination_properties	The default is 'false'. If null, the destination model (NOT properties) container will be used. The flag indicating whether to use the destination model or properties container.	false	logicvalue/boolean
 */
static wchar_t* EMPTY_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/empty";
static int* EMPTY_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/fill logic cybol format.
 *
 * Fills places of a container with a given initialisation element.
 *
 * Description:
 *
Fills the part up with a given element.
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
 * - TODO (required | optional) [text/cybol-path]: TODO
destination	the destination part	true	text/cybol-path
source	the source part	true	text/cybol-path
count	If null, the part model count will be used instead. The number of elements to be overwritten.	false	number/integer
destination_index	If null, an index of zero will be used instead. The destination index from which to start copying elements to.	false	number/integer
source_index	If null, an index of zero will be used instead. The source index from which to start copying elements from.	false	number/integer
adjust	The default is 'true'. If null, the count WILL BE adjusted. The flag indicating whether or not the destination shall be adjusted to.	false	logicvalue/boolean
destination_properties	The default is 'false'. If null, the destination model (NOT properties) container will be used. The flag indicating whether to use the destination model or properties container.	false	logicvalue/boolean
source_properties	The default is 'false'. If null, the source model (NOT properties) container will be used. The flag indicating whether to use the source model or properties container.	false	logicvalue/boolean
 */
static wchar_t* FILL_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/fill";
static int* FILL_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/insert logic cybol format.
 *
 * Insert data into other data.
 *
 * Description:
 *
Inserts the source- into the destination part.
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
destination	the destination part	true	text/cybol-path
source	the source part	true	text/cybol-path
count	If null, the part model count will be used instead. The number of elements to be overwritten.	false	number/integer
destination_index	If null, an index of zero will be used instead. The destination index from which to start copying elements to.	false	number/integer
source_index	If null, an index of zero will be used instead. The source index from which to start copying elements from.	false	number/integer
adjust	The default is 'true'. If null, the count WILL BE adjusted. The flag indicating whether or not the destination shall be adjusted to.	false	logicvalue/boolean
destination_properties	The default is 'false'. If null, the destination model (NOT properties) container will be used. The flag indicating whether to use the destination model or properties container.	false	logicvalue/boolean
source_properties	The default is 'false'. If null, the source model (NOT properties) container will be used. The flag indicating whether to use the source model or properties container.	false	logicvalue/boolean
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
 * - TODO (required | optional) [text/cybol-path]: TODO
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
 * - TODO (required | optional) [text/cybol-path]: TODO
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
 * - TODO (required | optional) [text/cybol-path]: TODO
destination	the destination part	true	text/cybol-path
source	the source part	true	text/cybol-path
count	If null, the part model count will be used instead. The number of elements to be overwritten.	false	number/integer
destination_index	If null, an index of zero will be used instead. The destination index from which to start copying elements to.	false	number/integer
source_index	If null, an index of zero will be used instead. The source index from which to start copying elements from.	false	number/integer
adjust	The default is 'true'. If null, the count WILL BE adjusted. The flag indicating whether or not the destination shall be adjusted to.	false	logicvalue/boolean
destination_properties	The default is 'false'. If null, the destination model (NOT properties) container will be used. The flag indicating whether to use the destination model or properties container.	false	logicvalue/boolean
source_properties	The default is 'false'. If null, the source model (NOT properties) container will be used. The flag indicating whether to use the source model or properties container.	false	logicvalue/boolean
 *
 * - adjust (optional; the default is "true"; if null, the destination count WILL BE adjusted):
 *   the flag indicating whether or not the destination shall be adjusted to
 *   destination_index + count_of_elements_to_be_copied;
 *   otherwise, the destination count by default remains as is
 *   and only gets extended, if the number of elements exceeds the destination count,
 *   in order to avoid memory errors caused by crossing array boundaries;
 *   Not adjusting the destination count makes sense when overwriting only a few words
 *   in the middle of some text, in order to leave the trailing text untouched
 *   and the text length altogether as is.
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
 * - TODO (required | optional) [text/cybol-path]: TODO
destination	the destination part	true	text/cybol-path
count	If null, the part model count will be used instead. The number of elements to be overwritten.	false	number/integer
destination_index	If null, an index of zero will be used instead. The destination index from which to start copying elements to.	false	number/integer
adjust	The default is 'true'. If null, the count WILL BE adjusted. The flag indicating whether or not the destination shall be adjusted to.	false	logicvalue/boolean
destination_properties	The default is 'false'. If null, the destination model (NOT properties) container will be used. The flag indicating whether to use the destination model or properties container.	false	logicvalue/boolean
 */
static wchar_t* REMOVE_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/remove";
static int* REMOVE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/repeat logic cybol format.
 *
 * Produce a string whose value is the concatenation of the source string repeated count times.
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
 * Description:
 *
TODO
 *
 * Examples:
 *
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
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
 * - TODO (required | optional) [text/cybol-path]: TODO
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
 * - TODO (required | optional) [text/cybol-path]: TODO
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
 * - TODO (required | optional) [text/cybol-path]: TODO
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
 * - TODO (required | optional) [text/cybol-path]: TODO
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
 * - TODO (required | optional) [text/cybol-path]: TODO
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
 * - TODO (required | optional) [text/cybol-path]: TODO
 */
static wchar_t* UPPER_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/upper";
static int* UPPER_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MODIFY_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
