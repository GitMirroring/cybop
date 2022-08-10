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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef REPRESENT_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define REPRESENT_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Represent
//
// IANA media type: not defined
// Self-defined media type: represent
// This media type is a CYBOL extension.
//

/**
 * The represent/deserialise logic cybol format.
 *
 * Description:
 *
 * Deserialises the source into the destination, according to the given format.
 *
 * CAUTION! The deserialised data are APPENDED to the destination.
 * Already existing content is NOT overwritten.
 * Therefore, the destination possibly has to get EMPTIED before since otherwise,
 * the new data will get appended to the already existing old data.
 *
 * Examples:
 *
 * <node name="deserialise_comma_separated_data" channel="inline" format="represent/deserialise" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".string"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/joined-string">
 *         <node name="delimiter" channel="inline" format="text/plain" model=","/>
 *     </node>
 * </node>
 *
 * <node name="deserialise_string_taken_from_file" channel="inline" format="represent/deserialise" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="file" format="text/plain" model="path/string.txt"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/joined-string">
 *         <node name="delimiter" channel="inline" format="text/plain" model=","/>
 *     </node>
 * </node>
 *
 * <node name="deserialise_inline_data" channel="inline" format="represent/deserialise" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="text/plain" model="1;2;3;word;01/07/2022;text"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/joined-string">
 *         <node name="delimiter" channel="inline" format="text/plain" model=";"/>
 *     </node>
 * </node>
 *
 * <node name="deserialise_quoted_data_doubled_as_escape" channel="inline" format="represent/deserialise" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="text/plain" model="&#x22;begin&#x22;,01/07/2022,&#x22;some &#x22;&#x22;quoted&#x22;&#x22; text&#x22;"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/joined-string">
 *         <node name="delimiter" channel="inline" format="text/plain" model=","/>
 *         <node name="quotation" channel="inline" format="text/plain" model="&#x22;"/>
 *     </node>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The part of type "element/part" into which the deserialised data are written.
 * - source (required) [text/cybol-path | text/plain]: The data to be deserialised.
 * - language (required) [meta/language]: The language used for translation.
 * - format (optional) [meta/format]: The format (type) of the source node.
 *
 * Constraints for Property "Language":
 *
 * - delimiter (optional) [text/plain]: The separator between the single fields (values). It may consist of many characters, but also be a simple comma, for example. Used with joined strings or character (comma) separated values (csv).
 * - quotation (optional) [text/plain]: The marker sequence used at the beginning and end of string fields (values). It may consist of many characters. Quotation is necessary if the delimiter character is part of the value. If the quotation is to be part of the value, then it has to be escaped by writing it TWICE (doubled). Used with joined strings or character (comma) separated values (csv).
 * - header (optional) [logicvalue/boolean]: The flag indicating whether or not the source data contain a header, so that the deserialiser can treat the first line differently. Used with character (comma) separated values (csv). CAUTION! It should NOT be mixed up with the headermodel property in represent/serialise.
 * - normalisation (optional) [logicvalue/boolean]: The flag indicating whether or not whitespaces and line breaks are merged into just ONE space. Used with xml or html, for example. The default is TRUE (normalisation enabled), if NULL.
 * - maximum (optional) [number/integer]: The maximum number of bytes to be transmitted. Used with serial (port) interface.
 * - minimum (optional) [number/integer]: The minimum number of bytes to be transmitted. Used with serial (port) interface.
 * - medium (optional) [text/cybol-path]: The window to which the mouse button or keyboard key refers. It is needed to search through the hierarchy of gui elements via mouse coordinates, for a suitable action. Used with graphical user interface (gui).
 */
static wchar_t* DESERIALISE_REPRESENT_LOGIC_CYBOL_FORMAT = L"represent/deserialise";
static int* DESERIALISE_REPRESENT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The represent/serialise logic cybol format.
 *
 * Description:
 *
 * Serialises the source into the destination, according to the given format.
 *
 * CAUTION! The serialised data are APPENDED to the destination.
 * Already existing content is NOT overwritten.
 * Therefore, the destination possibly has to get EMPTIED before since otherwise,
 * the new data will get appended to the already existing old data.
 *
 * Examples:
 *
 * <node name="serialise_webpage" channel="inline" format="represent/serialise" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".webpage"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".wui"/>
 *     <node name="format" channel="inline" format="meta/format" model="element/part"/>
 *     <!-- A beautification with indentation and newline is actually NOT useful for pure data transfer. -->
 *     <node name="language" channel="inline" format="meta/language" model="text/html"/>
 *     <node name="indentation" channel="inline" format="logicvalue/boolean" model="true"/>
 * </node>
 *
 * <node name="serialise_week" channel="inline" format="represent/serialise" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".week_as_string"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".week"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/cybol"/>
 *     <node name="format" channel="inline" format="meta/format" model="number/integer"/>
 * </node>
 *
 * <node name="deserialise_comma_separated_data" channel="inline" format="represent/serialise" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".string"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/joined-string">
 *         <node name="delimiter" channel="inline" format="text/plain" model=","/>
 *     </node>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The part of type "element/part" into which the deserialised data are written.
 * - source (required) [text/cybol-path | text/plain]: The data to be deserialised.
 * - language (required) [meta/language]: The language used for translation.
 * - format (optional) [meta/format]: The format (type) of the source node.
 *
 * Constraints for Property "Language":
 *
 * - newline (optional) [logicvalue/boolean]: The flag indicating whether or not a line break is added at the end of the printed characters. Used with text (pseudo) terminal.
 * - clear (optional) [logicvalue/boolean]: The flag indicating whether or not the terminal screen is cleared before printing characters on it. Used with text (pseudo) terminal.
 * - indentation (optional) [logicvalue/boolean]: The flag indicating whether or not the serialised data get beautified by indenting the single lines depending on the hierarchy level. Used with xml or html, for example.
 * - delimiter (optional) [text/plain]: The separator between the single fields (values). It may consist of many characters, but also be a simple comma, for example. Used with joined strings or character (comma) separated values (csv).
 * - quotation (optional) [text/plain]: The marker sequence used at the beginning and end of string fields (values). It may consist of many characters. Quotation is necessary if the delimiter character is part of the value. If the quotation is to be part of the value, then it has to be escaped by writing it TWICE (doubled). Used with joined strings or character (comma) separated values (csv).
 * - normalisation (optional) [logicvalue/boolean]: The flag indicating whether or not whitespaces and line breaks are merged into just ONE space. Used with xml or html, for example. The default is TRUE (normalisation enabled), if NULL.
 * - width (optional) [number/integer]: The number of characters (or digits) belonging to a value. Free places get filled up with the character given in the fill property. This was defined in the original specification of character (comma) separated values (csv), in order to have fields (values) with equal width. Used with joined strings or csv.
 * - fill (optional) [text/plain]: The characters (or digit) to be used to fill free places in a value whose width is greater.
 * - headermodel (optional) [text/cybol-path]: The header data to be written as first line, yet before the actual content. Used with character (comma) separated values (csv). CAUTION! It should NOT be mixed up with the header property flag in represent/deserialise.
 */
static wchar_t* SERIALISE_REPRESENT_LOGIC_CYBOL_FORMAT = L"represent/serialise";
static int* SERIALISE_REPRESENT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* REPRESENT_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
