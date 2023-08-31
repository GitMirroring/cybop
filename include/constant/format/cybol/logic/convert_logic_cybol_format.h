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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CONVERT_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER
#define CONVERT_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Convert
//
// IANA media type: not defined
// Self-defined media type: convert
// This media type is a CYBOL extension.
//

/**
 * The convert/decode logic cybol format.
 *
 * Description:
 *
 * Decodes the source into the destination, according to the encoding.
 *
 * Caution! The decoded data are appended to the destination. Already existing content is not overwritten.
 * Therefore, the destination possibly has to get emptied before since otherwise, the new data will get appended to the already existing old data.
 *
 * Examples:
 *
 * <node name="decode_request" channel="inline" format="convert/decode" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".action"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".request"/>
 *     <node name="encoding" channel="inline" format="meta/encoding" model="utf-8"/>
 * </node>
 *
 * <node name="decode" channel="inline" format="convert/decode" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".result"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".text"/>
 *     <node name="encoding" channel="inline" format="meta/encoding" model="utf-8"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination wide character array consisting of elements of type "wchar_t".
 * - source (required) [text/cybol-path]: The source byte array consisting of elements of type "char".
 * - encoding (required) [text/cybol-path | meta/encoding]: The message encoding.
 */
static wchar_t* DECODE_CONVERT_LOGIC_CYBOL_FORMAT = L"convert/decode";
static int* DECODE_CONVERT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The convert/encode logic cybol format.
 *
 * Description:
 *
 * Encodes the source into the destination, according to the encoding.
 *
 * Caution! The encoded data are appended to the destination. Already existing content is not overwritten.
 * Therefore, the destination possibly has to get emptied before since otherwise, the new data will get appended to the already existing old data.
 *
 * Examples:
 *
 * <node name="decode" channel="inline" format="convert/encode" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".data"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".webpage"/>
 *     <node name="encoding" channel="inline" format="meta/encoding" model="utf-8"/>
 * </node>
 *
 * Properties:
 *
 * - destination (required) [text/cybol-path]: The destination byte array consisting of elements of type "char".
 * - source (required) [text/cybol-path]: The source wide character array consisting of elements of type "wchar_t".
 * - encoding (required) [text/cybol-path | meta/encoding]: The message encoding.
 */
static wchar_t* ENCODE_CONVERT_LOGIC_CYBOL_FORMAT = L"convert/encode";
static int* ENCODE_CONVERT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CONVERT_LOGIC_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
