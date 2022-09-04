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

#ifndef META_STATE_CYBOL_FORMAT_CONSTANT_SOURCE
#define META_STATE_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Meta (meta data containing additional information specifying a cybol model)
//
// IANA media type: not defined
// Self-defined media type: meta
// This media type is a CYBOL extension.
//

/**
 * The meta/name state cybol format.
 *
 * Description:
 *
 * The name of the part tree node.
 *
 * Examples:
 *
 * <node name="name" channel="inline" format="meta/name" model=""/>
 */
static wchar_t* NAME_META_STATE_CYBOL_FORMAT = L"meta/name";
static int* NAME_META_STATE_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The meta/channel state cybol format.
 *
 * Description:
 *
 * The channel over which the data is sent or received.
 * It is normally used when reading or writing a file or transfering data.
 *
 * Examples:
 *
 * <node name="channel" channel="inline" format="meta/channel" model="file"/>
 * <node name="channel" channel="inline" format="meta/channel" model="socket"/>
 * <node name="channel" channel="inline" format="meta/channel" model="inline"/>
 */
static wchar_t* CHANNEL_META_STATE_CYBOL_FORMAT = L"meta/channel";
static int* CHANNEL_META_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The meta/encoding state cybol format.
 *
 * Description:
 *
 * The text encoding.
 * It is normally used when reading or writing a file or transfering data.
 *
 * Examples:
 *
 * <node name="encoding" channel="inline" format="meta/encoding" model="utf-8"/>
 */
static wchar_t* ENCODING_META_STATE_CYBOL_FORMAT = L"meta/encoding";
static int* ENCODING_META_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The meta/language state cybol format.
 *
 * Description:
 *
 * The language also called data format in which the data are structured.
 * It is normally used when reading or writing a file or transfering data.
 *
 * Examples:
 *
 * <node name="language" channel="inline" format="meta/language" model="text/cybol"/>
 * <node name="language" channel="inline" format="meta/language" model="text/html"/>
 */
static wchar_t* LANGUAGE_META_STATE_CYBOL_FORMAT = L"meta/language";
static int* LANGUAGE_META_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The meta/format state cybol format.
 *
 * Description:
 *
 * The format in which the data is available.
 * It is normally used when reading or writing a file or transfering data.
 *
 * Examples:
 *
 * <node name="format" channel="inline" format="meta/format" model="text/plain"/>
 * <node name="format" channel="inline" format="meta/format" model="number/integer"/>
 */
static wchar_t* FORMAT_META_STATE_CYBOL_FORMAT = L"meta/format";
static int* FORMAT_META_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The meta/type state cybol format.
 *
 * Description:
 *
 * The cyboi-internal data type used to allocate memory.
 *
 * Examples:
 *
 * <node name="type" channel="inline" format="meta/type" model=""/>
 */
static wchar_t* TYPE_META_STATE_CYBOL_FORMAT = L"meta/type";
static int* TYPE_META_STATE_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The meta/model state cybol format.
 *
 * Description:
 *
 * The cyboi-internal data model holding the actual data.
 *
 * Examples:
 *
 * <node name="model" channel="inline" format="meta/model" model=""/>
 */
static wchar_t* MODEL_META_STATE_CYBOL_FORMAT = L"meta/model";
static int* MODEL_META_STATE_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* META_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
