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

#ifndef OPEN_DISPATCHING_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define OPEN_DISPATCHING_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The channel open dispatching logic cybol name. */
static wchar_t* CHANNEL_OPEN_DISPATCHING_LOGIC_CYBOL_NAME = L"channel";
static int* CHANNEL_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The device open dispatching logic cybol name. */
static wchar_t* DEVICE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME = L"device";
static int* DEVICE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The identification open dispatching logic cybol name. */
static wchar_t* IDENTIFICATION_OPEN_DISPATCHING_LOGIC_CYBOL_NAME = L"identification";
static int* IDENTIFICATION_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mode open dispatching logic cybol name. */
static wchar_t* MODE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME = L"mode";
static int* MODE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The namespace (family) open dispatching logic cybol name. */
static wchar_t* NAMESPACE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME = L"namespace";
static int* NAMESPACE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The port open dispatching logic cybol name. */
static wchar_t* PORT_OPEN_DISPATCHING_LOGIC_CYBOL_NAME = L"port";
static int* PORT_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The protocol open dispatching logic cybol name. */
static wchar_t* PROTOCOL_OPEN_DISPATCHING_LOGIC_CYBOL_NAME = L"protocol";
static int* PROTOCOL_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The server flag open dispatching logic cybol name. */
static wchar_t* SERVER_OPEN_DISPATCHING_LOGIC_CYBOL_NAME = L"server";
static int* SERVER_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The style (communication type) open dispatching logic cybol name. */
static wchar_t* STYLE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME = L"style";
static int* STYLE_OPEN_DISPATCHING_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* OPEN_DISPATCHING_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
