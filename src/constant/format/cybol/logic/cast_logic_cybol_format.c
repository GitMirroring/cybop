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

#ifndef CAST_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define CAST_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Cast
//
// IANA media type: not defined
// Self-defined media type: cast
// This media type is a CYBOL extension.
//

/**
 * The cast/byte logic cybol format.
 *
 * Cast value to type byte.
 *
 * Description:
 *
Casts a value from one type to another.
 *
 * Examples:
 *
 * <node name="cast_byte" channel="inline" format="cast/byte" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".part_2"/>
 *     <node name="source" channel="inline" format="number/byte" model="123"/>
 *     <node name="type" channel="inline" format="meta/type" model="number/integer"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
 * - destination	The knowledge model to cast to.	true	path/*
 * - source	The knowledge model to cast from.	true	path/* | number/*
 * - type	The source type.	true	path/* | meta/type
 *
 * Expected parametres:
 * - destination (required): the knowledge model to cast to
 * - source (required): the knowledge model to cast from
 * - count (optional; if null, the source part model count will be used instead):
 *   the number of elements to be casted
 * - destination_index (optional; if null, an index of zero will be used instead):
 *   the destination index from which to start casting
 * - source_index (optional; if null, an index of zero will be used instead):
 *   the source index from which to start casting
 */
static wchar_t* BYTE_CAST_LOGIC_CYBOL_FORMAT = L"cast/byte";
static int* BYTE_CAST_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cast/character logic cybol format.
 *
 * Cast value to type character.
 *
 * Description:
 *
Casts a value from one type to another.
 *
 * Examples:
 *
 * <node name="cast_character" channel="inline" format="cast/character" model="">
 *     <node name="destination" channel="inline" format="text/cybol-path" model=".part_2"/>
 *     <node name="source" channel="inline" format="text/cybol-path" model=".part_1"/>
 *     <node name="type" channel="inline" format="meta/type" model="text/plain"/>
 * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
destination	The knowledge model to cast to.	true	path/*
source	The knowledge model to cast from.	true	path/* | number/*
type	The source type.	true	path/* | meta/type
 *
 * Expected parametres:
 * - destination (required): the knowledge model to cast to
 * - source (required): the knowledge model to cast from
 * - count (optional; if null, the source part model count will be used instead):
 *   the number of elements to be casted
 * - destination_index (optional; if null, an index of zero will be used instead):
 *   the destination index from which to start casting
 * - source_index (optional; if null, an index of zero will be used instead):
 *   the source index from which to start casting
 */
static wchar_t* CHARACTER_CAST_LOGIC_CYBOL_FORMAT = L"cast/character";
static int* CHARACTER_CAST_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cast/double logic cybol format.
 *
 * Cast value to type double.
 *
 * Description:
 *
Casts a value from one type to another.
 *
 * Examples:
 *
 *     <node name="cast_double" channel="inline" format="cast/double" model="">
     *     <node name="destination" channel="inline" format="text/cybol-path" model=".part_2"/>
     *     <node name="source" channel="inline" format="text/cybol-path" model=".part_1"/>
     *     <node name="type" channel="inline" format="meta/type" model="number/integer"/>
     * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
destination	The knowledge model to cast to.	true	path/*
source	The knowledge model to cast from.	true	path/* | number/*
type	The source type.	true	path/* | meta/type
 *
 * Expected parametres:
 * - destination (required): the knowledge model to cast to
 * - source (required): the knowledge model to cast from
 * - count (optional; if null, the source part model count will be used instead):
 *   the number of elements to be casted
 * - destination_index (optional; if null, an index of zero will be used instead):
 *   the destination index from which to start casting
 * - source_index (optional; if null, an index of zero will be used instead):
 *   the source index from which to start casting
 */
static wchar_t* DOUBLE_CAST_LOGIC_CYBOL_FORMAT = L"cast/double";
static int* DOUBLE_CAST_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cast/integer logic cybol format.
 *
 * Cast value to type integer.
 *
 * Description:
 *
Casts a value from one type to another.
 *
 * Examples:
 *
 *     <node name="cast_double" channel="inline" format="cast/integer" model="">
     *     <node name="destination" channel="inline" format="text/cybol-path" model=".part_2"/>
     *     <node name="source" channel="inline" format="number/byte" model="12"/>
     *     <node name="type" channel="inline" format="meta/type" model="number/byte"/>
     * </node>
 *
 * Properties:
 *
 * - TODO (required | optional) [text/cybol-path]: TODO
destination	The knowledge model to cast to.	true	path/*
source	The knowledge model to cast from.	true	path/* | number/*
type	The source type.	true	path/* | meta/type
 *
 * Expected parametres:
 * - destination (required): the knowledge model to cast to
 * - source (required): the knowledge model to cast from
 * - count (optional; if null, the source part model count will be used instead):
 *   the number of elements to be casted
 * - destination_index (optional; if null, an index of zero will be used instead):
 *   the destination index from which to start casting
 * - source_index (optional; if null, an index of zero will be used instead):
 *   the source index from which to start casting
 */
static wchar_t* INTEGER_CAST_LOGIC_CYBOL_FORMAT = L"cast/integer";
static int* INTEGER_CAST_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CAST_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
