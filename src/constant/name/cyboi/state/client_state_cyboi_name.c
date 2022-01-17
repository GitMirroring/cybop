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

#ifndef CLIENT_STATE_CYBOI_NAME_CONSTANT_SOURCE
#define CLIENT_STATE_CYBOI_NAME_CONSTANT_SOURCE

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// CAUTION! The client entry size is set in file "state_cyboi_model.c"!
//

//
// General
//
// This is the client socket number that was assigned
// automatically by the system when accepting the client request.
//

static int* IDENTIFICATION_CLIENT_STATE_CYBOI_NAME = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* LANGUAGE_CLIENT_STATE_CYBOI_NAME = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* CHANNEL_CLIENT_STATE_CYBOI_NAME = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Message
//
// The buffer stores input data read from the client.
//
// It can be of different types, depending on the channel:
// - display: event array of void*
// - serial port: character array of char
// - socket: character array of char
// - terminal: wide character array of wchar_t
//

static int* BUFFER_MESSAGE_CLIENT_STATE_CYBOI_NAME = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* MUTEX_MESSAGE_CLIENT_STATE_CYBOI_NAME = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Thread
//
// The thread runs the function "sense" in order
// to detect new input on the client.
//
static int* IDENTIFICATION_THREAD_CLIENT_STATE_CYBOI_NAME = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;
//?? static int* FUNCTION_THREAD_CLIENT_STATE_CYBOI_NAME = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;
//?? static int* ARGUMENT_THREAD_CLIENT_STATE_CYBOI_NAME = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* EXIT_THREAD_CLIENT_STATE_CYBOI_NAME = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Interrupt
//

static int* PIPE_INTERRUPT_CLIENT_STATE_CYBOI_NAME = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* MUTEX_INTERRUPT_CLIENT_STATE_CYBOI_NAME = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Input/Output
//

static int* INPUT_OUTPUT_IDENTIFICATION_CLIENT_STATE_CYBOI_NAME = NUMBER_40_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Channel
//

static int* SERIAL_PORT_CLIENT_STATE_CYBOI_NAME = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* TERMINAL_CLIENT_STATE_CYBOI_NAME = NUMBER_51_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* XCB_CONNEXION_CLIENT_STATE_CYBOI_NAME = NUMBER_52_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CLIENT_STATE_CYBOI_NAME_CONSTANT_SOURCE */
#endif
