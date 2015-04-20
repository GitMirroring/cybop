/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// General
//

/** The channel shutdown maintenance logic cybol name. */
static wchar_t* CHANNEL_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME = L"channel";
static int* CHANNEL_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The identification (id) shutdown maintenance logic cybol name.
 *
 * For a socket this is the port.
 */
static wchar_t* IDENTIFICATION_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME = L"id";
static int* IDENTIFICATION_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Socket
//

/** The mode socket shutdown maintenance logic cybol name. */
static wchar_t* MODE_SOCKET_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME = L"mode";
static int* MODE_SOCKET_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The (network) service socket shutdown maintenance logic cybol name. */
static wchar_t* SERVICE_SOCKET_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME = L"service";
static int* SERVICE_SOCKET_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The (client) socket socket shutdown maintenance logic cybol name. */
static wchar_t* SOCKET_SOCKET_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME = L"socket";
static int* SOCKET_SOCKET_SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SHUTDOWN_MAINTENANCE_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif
