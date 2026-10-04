/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The channel startup maintenance logic cybol name. */
static wchar_t* CHANNEL_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"channel";
static int* CHANNEL_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The connexions startup maintenance logic cybol name. */
static wchar_t* CONNEXIONS_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"connexions";
static int* CONNEXIONS_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The device startup maintenance logic cybol name. */
static wchar_t* DEVICE_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"device";
static int* DEVICE_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The namespace (family) startup maintenance logic cybol name. */
static wchar_t* NAMESPACE_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"namespace";
static int* NAMESPACE_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The port startup maintenance logic cybol name. */
static wchar_t* PORT_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"port";
static int* PORT_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The protocol startup maintenance logic cybol name. */
static wchar_t* PROTOCOL_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"protocol";
static int* PROTOCOL_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The style (communication type) startup maintenance logic cybol name. */
static wchar_t* STYLE_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"style";
static int* STYLE_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The timeout startup maintenance logic cybol name. */
static wchar_t* TIMEOUT_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME = L"timeout";
static int* TIMEOUT_STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* STARTUP_MAINTENANCE_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
