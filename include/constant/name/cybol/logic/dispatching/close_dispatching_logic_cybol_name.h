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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CLOSE_DISPATCHING_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define CLOSE_DISPATCHING_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The channel close dispatching logic cybol name. */
static wchar_t* CHANNEL_CLOSE_DISPATCHING_LOGIC_CYBOL_NAME = L"channel";
static int* CHANNEL_CLOSE_DISPATCHING_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The identification close dispatching logic cybol name. */
static wchar_t* IDENTIFICATION_CLOSE_DISPATCHING_LOGIC_CYBOL_NAME = L"identification";
static int* IDENTIFICATION_CLOSE_DISPATCHING_LOGIC_CYBOL_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The port close dispatching logic cybol name. */
static wchar_t* PORT_CLOSE_DISPATCHING_LOGIC_CYBOL_NAME = L"port";
static int* PORT_CLOSE_DISPATCHING_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The server flag close dispatching logic cybol name. */
static wchar_t* SERVER_CLOSE_DISPATCHING_LOGIC_CYBOL_NAME = L"server";
static int* SERVER_CLOSE_DISPATCHING_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CLOSE_DISPATCHING_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
