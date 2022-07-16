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

#ifndef COMMUNICATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define COMMUNICATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Communicate
//
// IANA media type: not defined
// Self-defined media type: communicate
// This media type is a CYBOL extension.
//

/**
 * The communicate/identify logic cybol format.
 *
 * Identify the device or client having sent/placed a request in the interrupt pipe.
 *
 * This is a CYBOL extension.
 */
static wchar_t* IDENTIFY_COMMUNICATE_LOGIC_CYBOL_FORMAT = L"communicate/identify";
static int* IDENTIFY_COMMUNICATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The communicate/receive logic cybol format.
 *
 * Receive data via a communication channel.
 *
 * This is a CYBOL extension.
 */
static wchar_t* RECEIVE_COMMUNICATE_LOGIC_CYBOL_FORMAT = L"communicate/receive";
static int* RECEIVE_COMMUNICATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The communicate/send logic cybol format.
 *
 * Send data via a communication channel.
 *
 * This is a CYBOL extension.
 */
static wchar_t* SEND_COMMUNICATE_LOGIC_CYBOL_FORMAT = L"communicate/send";
static int* SEND_COMMUNICATE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COMMUNICATE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
