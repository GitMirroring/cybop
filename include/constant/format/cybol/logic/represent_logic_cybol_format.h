/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef REPRESENT_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define REPRESENT_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

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
 * Caution! The deserialised data are appended to the destination. Already existing content is not overwritten.
 * Therefore, the destination possibly has to get emptied before since otherwise, the new data will get appended to the already existing old data.
 *
 * This operation may be used to split a source string into parts which are stored as child nodes of the destination part.
 *
 * Examples:
 *
 * <node name="deserialise_operand" channel="inline" format="represent/deserialise" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".summand"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".text"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/cybol"/>
 *     <node name="format" channel="inline" format="meta/format" model="number/integer"/>
 * </node>
 *
 * <node name="deserialise_number" channel="inline" format="represent/deserialise" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="text/plain" model="2.4e-2"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/cybol"/>
 *     <node name="format" channel="inline" format="meta/format" model="number/float"/>
 * </node>
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
 * - destination (required) [text/cybol-path]: The node into which the deserialised data are written. Its format (type) depends on the given source data.
 * - source (required) [text/cybol-path | text/plain]: The data to be deserialised.
 * - language (required) [meta/language]: The language used for deserialisation.
 * - format (optional) [meta/format]: The format (type) of the source node.
 *
 * Constraints for Property Language:
 *
 * - decimal_separator (optional) [text/plain]: The symbol (or character sequence) used to separate the integer part from the fractional part of a floating point (decimal) number.
 * - thousands_separator (optional) [text/plain]: The symbol (or character sequence) used for digit grouping.
 * - delimiter (optional) [text/plain]: The separator between the single fields (values). It may consist of many characters, but also be a simple comma, for example. Used with joined strings or character (comma) separated values (csv).
 * - quotation (optional) [text/plain]: The marker sequence used at the beginning and end of string fields (values). It may consist of many characters. Quotation is necessary if the delimiter character is part of the value. If the quotation is to be part of the value, then it has to be escaped by writing it twice (doubled). Used with joined strings or character (comma) separated values (csv).
 * - header (optional) [logicvalue/boolean]: The flag indicating whether or not the source data contain a header, so that the deserialiser can treat the first line differently. Used with character (comma) separated values (csv). Caution! It should not be mixed up with the headermodel property in represent/serialise.
 * - normalisation (optional) [logicvalue/boolean]: The flag indicating whether or not whitespaces and line breaks are merged into just one space. Used with xml or html, for example. If null, then the default is true (normalisation enabled).
 * - maximum (optional) [number/integer]: The maximum number of bytes to be transmitted. Used with serial (port) interface.
 * - minimum (optional) [number/integer]: The minimum number of bytes to be transmitted. Used with serial (port) interface.
 * - medium (optional) [text/cybol-path]: The window to which the mouse button or keyboard key refers. It is needed to search through the hierarchy of gui elements via mouse coordinates, for a suitable action. Used with graphical user interface (gui).
 *
 * CAUTION! When changing these constraints, then copy them 1:1 to file "communicate_logic_cybol_format.h".
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
 * Caution! The serialised data are appended to the destination. Already existing content is not overwritten.
 * Therefore, the destination possibly has to get emptied before since otherwise, the new data will get appended to the already existing old data.
 *
 * This operation may be used to concatenate the strings given as child nodes of the source part into the destination part and provide an optional cybol property "separator" to be used as such between the concatenated strings.
 *
 * Examples:
 *
 * <node name="serialise_number" channel="inline" format="represent/serialise" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="number/integer" model="24"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/cybol"/>
 *     <node name="format" channel="inline" format="meta/format" model="number/integer"/>
 * </node>
 *
 * <node name="serialise_week_given_as_path" channel="inline" format="represent/serialise" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".week_as_string"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".week"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/cybol"/>
 *     <node name="format" channel="inline" format="meta/format" model="number/integer"/>
 * </node>
 *
 * <node name="serialise_webpage" channel="inline" format="represent/serialise" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".webpage"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".wui.index"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/html">
 *         <node name="indentation" channel="inline" format="logicvalue/boolean" model="true"/>
 *     </node>
 *     <node name="format" channel="inline" format="meta/format" model="element/part"/>
 * </node>
 *
 * <node name="serialise_comma_separated_data" channel="inline" format="represent/serialise" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".string_node_list"/>
 *     <node name="language" channel="inline" format="meta/language" model="text/joined-string">
 *         <node name="delimiter" channel="inline" format="text/plain" model=","/>
 *         <node name="quotation" channel="inline" format="text/plain" model="&#x22;"/>
 *     </node>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The node into which the serialised data are written. Its format (type) depends on the given source data.
 * - source (required) [text/cybol-path | text/plain | number/any]: The data to be serialised.
 * - language (required) [meta/language]: The language used for serialisation.
 * - format (optional) [meta/format]: The format (type) of the source node.
 *
 * Constraints for Property Language:
 *
 * - sign (optional) [logicvalue/boolean]: The flag indicating whether or not a plus sign is to be displayed for positive numbers. Negative numbers have a minus sign in any case. If null, the default is false (no plus sign for positive numbers).
 * - base (optional) [number/integer]: The number base for example 2 for binary (dual), 8 for octal, 10 for decimal, 16 for hexadecimal. If null, the default is 10 (decimal number base).
 * - classicoctal (optional) [logicvalue/boolean]: The flag indicating whether or not the octal number base prefix is to be displayed as 0 as in classic c/c++ or using modern style 0o as in perl and python. If null, the default is false (modern style with prefix 0o).
 * - grouping (optional) [text/plain]: The symbol or character sequence used for digit grouping in thousands. If null, the default is not to use any thousands separator at all.
 * - separator (optional) [text/plain]: The symbol or character sequence used to separate the integer part from the fractional part of a floating point decimal number. If null, the default is to use the full stop (dot).
 * - decimals (optional) [number/integer]: The number of post-point decimal places (decimals). If null, the default is 4.
 * - scientific (optional) [logicvalue/boolean]: The flag indicating whether or not the decimal fraction gets displayed with mantissa and exponent. If null, the default is false (standard representation without exponent).
 * - polar (optional) [logicvalue/boolean]: The flag indicating whether or not to write the complex number using polar coordinates. If null, the default is false (using the cartesian form).
 * - newline (optional) [logicvalue/boolean]: The flag indicating whether or not a line break is added at the end of the printed characters. If null, the default is true (line gets broken). Used with text (pseudo) terminal.
 * - clear (optional) [logicvalue/boolean]: The flag indicating whether or not the terminal screen is cleared before printing characters on it. If null, the default is false (no clearing). Used with text (pseudo) terminal.
 * - positioning (optional) [logicvalue/boolean]: The flag indicating whether or not the cursor position may get changed. If null, the default is false (no repositioning). Used with text (pseudo) terminal.
 * - indentation (optional) [logicvalue/boolean]: The flag indicating whether or not the serialised data get beautified (pretty-formatted) by indenting the single lines depending on the hierarchy level. Used with xml or html, for example.
 * - delimiter (optional) [text/plain]: The separator between the single fields (values). It may consist of many characters, but also be a simple comma, for example. Used with joined strings or character (comma) separated values (csv).
 * - quotation (optional) [text/plain]: The marker sequence used at the beginning and end of string fields (values). It may consist of many characters. Quotation is necessary if the delimiter character is part of the value. If the quotation is to be part of the value, then it has to be escaped by writing it twice (doubled). Used with joined strings or character (comma) separated values (csv).
 * - normalisation (optional) [logicvalue/boolean]: The flag indicating whether or not whitespaces and line breaks are merged into just one space. Used with xml or html, for example. If null, then the default is true (normalisation enabled).
 * - width (optional) [number/integer]: The number of characters (or digits) belonging to a value. Free places get filled up with the character given in the fill property. This was defined in the original specification of character (comma) separated values (csv), in order to have fields (values) with equal width. Used with joined strings or csv.
 * - fill (optional) [text/plain]: The characters (or digit) to be used to fill free places in a value whose width is greater.
 * - headermodel (optional) [text/cybol-path]: The header data to be written as first line, yet before the actual content. Used with character (comma) separated values (csv). Caution! It should not be mixed up with the header property flag in represent/deserialise or communicate/receive.
 *
 * CAUTION! When changing these constraints, then copy them 1:1 to file "communicate_logic_cybol_format.h".
 */
static wchar_t* SERIALISE_REPRESENT_LOGIC_CYBOL_FORMAT = L"represent/serialise";
static int* SERIALISE_REPRESENT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* REPRESENT_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
