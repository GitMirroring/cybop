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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef FEEL_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define FEEL_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Feel
//
// IANA media type: not defined
// Self-defined media type: feel
// This media type is a CYBOL extension.
//

/**
 * The feel/sense logic cybol format.
 *
 * Sense input data within a thread.
 * Senses data input within a thread on the client with the given identification.
 *
 * Parametres:
 * - channel (required): the communication channel, e.g. file, serial, socket
 * - server (optional): the flag indicating server mode, e.g. for window or client socket stub; if NULL, the default is false (standalone client mode)
 * - port (optional): the service identification; only relevant in server mode
 * - sender (required): the client identification, e.g. file descriptor or client socket number or window id
 * - language (optional): the language, e.g. crlf or http_request, to detect message length prefix or end suffix
 * - handler (required): the callback cybol operation being executed when the thread finished reading data
 * - closer (optional): the close handler to be executed when the client does not respond and is to be closed
 */
static wchar_t* SENSE_FEEL_LOGIC_CYBOL_FORMAT = L"feel/sense";
static int* SENSE_FEEL_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The feel/suspend logic cybol format.
 *
 * Suspend a sensing thread.
 * Suspends data input sensing thread for the client with the given identification.
 *
 * Parametres:
 * - channel (required): the communication channel, e.g. file, serial, socket
 * - server (optional): the flag indicating server mode, e.g. for window or client socket stub; if NULL, the default is false (standalone client mode)
 * - port (optional): the service identification; only relevant in server mode
 * - sender (required): the client identification, e.g. file descriptor or client socket number or window id
 */
static wchar_t* SUSPEND_FEEL_LOGIC_CYBOL_FORMAT = L"feel/suspend";
static int* SUSPEND_FEEL_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* FEEL_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
