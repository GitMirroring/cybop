/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef OPEN_REGISTRATION_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define OPEN_REGISTRATION_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// General
//

/** The channel open registration logic cybol name. */
static wchar_t* CHANNEL_OPEN_REGISTRATION_LOGIC_CYBOL_NAME = L"channel";
static int* CHANNEL_OPEN_REGISTRATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The identification (id) open registration logic cybol name. */
static wchar_t* IDENTIFICATION_OPEN_REGISTRATION_LOGIC_CYBOL_NAME = L"id";
static int* IDENTIFICATION_OPEN_REGISTRATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Socket
//

/** The address socket open registration logic cybol name. */
static wchar_t* ADDRESS_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME = L"address";
static int* ADDRESS_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The blocking socket open registration logic cybol name. */
static wchar_t* BLOCKING_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME = L"blocking";
static int* BLOCKING_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The filename socket open registration logic cybol name. */
static wchar_t* FILENAME_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME = L"filename";
static int* FILENAME_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The namespace (family) socket open registration logic cybol name. */
static wchar_t* NAMESPACE_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME = L"namespace";
static int* NAMESPACE_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The port socket open registration logic cybol name. */
static wchar_t* PORT_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME = L"port";
static int* PORT_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The protocol socket open registration logic cybol name. */
static wchar_t* PROTOCOL_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME = L"protocol";
static int* PROTOCOL_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The style (communication type) socket open registration logic cybol name. */
static wchar_t* STYLE_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME = L"style";
static int* STYLE_SOCKET_OPEN_REGISTRATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* OPEN_REGISTRATION_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif
