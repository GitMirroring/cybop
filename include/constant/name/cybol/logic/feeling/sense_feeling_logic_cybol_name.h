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

#ifndef SENSE_FEELING_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define SENSE_FEELING_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The channel sense feeling logic cybol name. */
static wchar_t* CHANNEL_SENSE_FEELING_LOGIC_CYBOL_NAME = L"channel";
static int* CHANNEL_SENSE_FEELING_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The closer sense feeling logic cybol name. */
static wchar_t* CLOSER_SENSE_FEELING_LOGIC_CYBOL_NAME = L"closer";
static int* CLOSER_SENSE_FEELING_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The handler sense feeling logic cybol name. */
static wchar_t* HANDLER_SENSE_FEELING_LOGIC_CYBOL_NAME = L"handler";
static int* HANDLER_SENSE_FEELING_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The language sense feeling logic cybol name. */
static wchar_t* LANGUAGE_SENSE_FEELING_LOGIC_CYBOL_NAME = L"language";
static int* LANGUAGE_SENSE_FEELING_LOGIC_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The port sense feeling logic cybol name. */
static wchar_t* PORT_SENSE_FEELING_LOGIC_CYBOL_NAME = L"port";
static int* PORT_SENSE_FEELING_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sender sense feeling logic cybol name. */
static wchar_t* SENDER_SENSE_FEELING_LOGIC_CYBOL_NAME = L"sender";
static int* SENDER_SENSE_FEELING_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The server sense feeling logic cybol name. */
static wchar_t* SERVER_SENSE_FEELING_LOGIC_CYBOL_NAME = L"server";
static int* SERVER_SENSE_FEELING_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SENSE_FEELING_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
