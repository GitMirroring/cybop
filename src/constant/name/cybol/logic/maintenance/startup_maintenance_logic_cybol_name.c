/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// General
//

/** The channel startup maintenance logic cybol name. */
static wchar_t* CHANNEL_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"channel";
static int* CHANNEL_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The identification (id) startup maintenance logic cybol name.
 *
 * For a socket this is the port.
 */
static wchar_t* IDENTIFICATION_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"id";
static int* IDENTIFICATION_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Serial interface
//

/** The baudrate serial interface startup maintenance logic cybol name. */
static wchar_t* BAUDRATE_SERIAL_INTERFACE_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"baudrate";
static int* BAUDRATE_SERIAL_INTERFACE_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The filename serial interface startup maintenance logic cybol name. */
static wchar_t* FILENAME_SERIAL_INTERFACE_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"filename";
static int* FILENAME_SERIAL_INTERFACE_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Socket
//

/** The address socket startup maintenance logic cybol name. */
static wchar_t* ADDRESS_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"address";
static int* ADDRESS_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The connexions socket startup maintenance logic cybol name. */
static wchar_t* CONNEXIONS_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"connexions";
static int* CONNEXIONS_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The filename socket startup maintenance logic cybol name. */
static wchar_t* FILENAME_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"filename";
static int* FILENAME_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mode socket startup maintenance logic cybol name. */
static wchar_t* MODE_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"mode";
static int* MODE_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The namespace (family) socket startup maintenance logic cybol name. */
static wchar_t* NAMESPACE_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"namespace";
static int* NAMESPACE_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The protocol socket startup maintenance logic cybol name. */
static wchar_t* PROTOCOL_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"protocol";
static int* PROTOCOL_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The (network) service socket startup maintenance logic cybol name. */
static wchar_t* SERVICE_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"service";
static int* SERVICE_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The (client) socket socket startup maintenance logic cybol name. */
static wchar_t* SOCKET_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"socket";
static int* SOCKET_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The style (communication type) socket startup maintenance logic cybol name. */
static wchar_t* STYLE_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"style";
static int* STYLE_SOCKET_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif
