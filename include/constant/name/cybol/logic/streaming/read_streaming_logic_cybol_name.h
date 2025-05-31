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

#ifndef READ_STREAMING_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define READ_STREAMING_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The asynchronicity read streaming logic cybol name. */
static wchar_t* ASYNCHRONICITY_READ_STREAMING_LOGIC_CYBOL_NAME = L"asynchronicity";
static int* ASYNCHRONICITY_READ_STREAMING_LOGIC_CYBOL_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The channel read streaming logic cybol name. */
static wchar_t* CHANNEL_READ_STREAMING_LOGIC_CYBOL_NAME = L"channel";
static int* CHANNEL_READ_STREAMING_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The language read streaming logic cybol name. */
static wchar_t* LANGUAGE_READ_STREAMING_LOGIC_CYBOL_NAME = L"language";
static int* LANGUAGE_READ_STREAMING_LOGIC_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The message read streaming logic cybol name. */
static wchar_t* MESSAGE_READ_STREAMING_LOGIC_CYBOL_NAME = L"message";
static int* MESSAGE_READ_STREAMING_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The port read streaming logic cybol name. */
static wchar_t* PORT_READ_STREAMING_LOGIC_CYBOL_NAME = L"port";
static int* PORT_READ_STREAMING_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sender read streaming logic cybol name. */
static wchar_t* SENDER_READ_STREAMING_LOGIC_CYBOL_NAME = L"sender";
static int* SENDER_READ_STREAMING_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The server read streaming logic cybol name. */
static wchar_t* SERVER_READ_STREAMING_LOGIC_CYBOL_NAME = L"server";
static int* SERVER_READ_STREAMING_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* READ_STREAMING_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
