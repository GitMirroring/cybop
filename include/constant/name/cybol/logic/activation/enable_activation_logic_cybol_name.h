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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ENABLE_ACTIVATION_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define ENABLE_ACTIVATION_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The channel enable activation logic cybol name. */
static wchar_t* CHANNEL_ENABLE_ACTIVATION_LOGIC_CYBOL_NAME = L"channel";
static int* CHANNEL_ENABLE_ACTIVATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The handler enable activation logic cybol name. */
static wchar_t* HANDLER_ENABLE_ACTIVATION_LOGIC_CYBOL_NAME = L"handler";
static int* HANDLER_ENABLE_ACTIVATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The port enable activation logic cybol name. */
static wchar_t* PORT_ENABLE_ACTIVATION_LOGIC_CYBOL_NAME = L"port";
static int* PORT_ENABLE_ACTIVATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ENABLE_ACTIVATION_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
