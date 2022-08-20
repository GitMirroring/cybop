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
 * TODO
 *
 * Examples:
 *
 * <node name="TODO" channel="file" format="TODO/TODO" model="path/to/file.TODO"/>
 *
 * ----------
 *
 * This is a CYBOL extension.
 */
static wchar_t* NAME_META_STATE_CYBOL_FORMAT = L"meta/name";
static int* NAME_META_STATE_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The meta/channel state cybol format.
 *
 * Description:
 *
 * TODO
 *
 * Examples:
 *
 * <node name="TODO" channel="file" format="TODO/TODO" model="path/to/file.TODO"/>
 *
 * ----------
 *
 * This is a CYBOL extension.
 */
static wchar_t* CHANNEL_META_STATE_CYBOL_FORMAT = L"meta/channel";
static int* CHANNEL_META_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The meta/encoding state cybol format.
 *
 * Description:
 *
 * TODO
 *
 * Examples:
 *
 * <node name="TODO" channel="file" format="TODO/TODO" model="path/to/file.TODO"/>
 *
 * ----------
 *
 * This is a CYBOL extension.
 */
static wchar_t* ENCODING_META_STATE_CYBOL_FORMAT = L"meta/encoding";
static int* ENCODING_META_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The meta/language state cybol format.
 *
 * Description:
 *
 * TODO
 *
 * Examples:
 *
 * <node name="TODO" channel="file" format="TODO/TODO" model="path/to/file.TODO"/>
 *
 * ----------
 *
 * This is a CYBOL extension.
 */
static wchar_t* LANGUAGE_META_STATE_CYBOL_FORMAT = L"meta/language";
static int* LANGUAGE_META_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The meta/format state cybol format.
 *
 * Description:
 *
 * TODO
 *
 * Examples:
 *
 * <node name="TODO" channel="file" format="TODO/TODO" model="path/to/file.TODO"/>
 *
 * ----------
 *
 * This is a CYBOL extension.
 */
static wchar_t* FORMAT_META_STATE_CYBOL_FORMAT = L"meta/format";
static int* FORMAT_META_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The meta/type state cybol format.
 *
 * Description:
 *
 * TODO
 *
 * Examples:
 *
 * <node name="TODO" channel="file" format="TODO/TODO" model="path/to/file.TODO"/>
 *
 * ----------
 *
 * This is a CYBOL extension.
 */
static wchar_t* TYPE_META_STATE_CYBOL_FORMAT = L"meta/type";
static int* TYPE_META_STATE_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The meta/model state cybol format.
 *
 * Description:
 *
 * TODO
 *
 * Examples:
 *
 * <node name="TODO" channel="file" format="TODO/TODO" model="path/to/file.TODO"/>
 *
 * ----------
 *
 * This is a CYBOL extension.
 */
static wchar_t* MODEL_META_STATE_CYBOL_FORMAT = L"meta/model";
static int* MODEL_META_STATE_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* META_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
