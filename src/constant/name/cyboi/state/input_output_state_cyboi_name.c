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

#ifndef INPUT_OUTPUT_STATE_CYBOI_NAME_CONSTANT_SOURCE
#define INPUT_OUTPUT_STATE_CYBOI_NAME_CONSTANT_SOURCE

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// CAUTION! If extending the number of entries here,
// then adapt the INTERNAL_MEMORY_STATE_CYBOI_MODEL_COUNT
// as well. See file "state_cyboi_model.c"!
//

//
//?? THINK: Move to read/write client entry ??
//
static int* BUFFER_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* MUTEX_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* INTERRUPT_PIPE_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* INTERRUPT_MUTEX_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// General
//

//?? Possibly delete, if base + port + client number are handed over separately to irq pipe ??
static int* IDENTIFICATION_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* HANDLER_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;
//?? Possibly delete, if replaced by client list ??
static int* SENDER_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Client
//

static int* CLIENT_LIST_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_51_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* ACCEPTTIME_LIST_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_52_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* TIMEOUT_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_53_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Thread
//

//
// The thread is relevant to the socket channel only.
// It runs the function "accept" in order to detect
// new client requests on the socket.
//
static int* IDENTIFICATION_THREAD_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* FUNCTION_THREAD_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* ARGUMENT_THREAD_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* EXIT_THREAD_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Display
//

static int* CONNEXION_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* SCREEN_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* GRAPHIC_CONTEXT_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* DEVICE_CONTEXT_WIN32_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* EVENT_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Serial port
//
// CAUTION! Store file STREAM instead of file descriptor, since:
// - stream is a more complex structure containing the descriptor
// - the c standard defines only file streams of type FILE*
//
// Special types used by various platforms are NOT stored here,
// since they may be retrieved from the FILE structure, e.g.:
// - POSIX: "file descriptor" (int) used in direct file access functions, retrieved via "int fileno(FILE* stream)"
// - Win32: "file handle" (DWORD) used in alternative input/output functions, retrieved via "int _fileno(FILE* stream)"
//          the returned int may be casted to file handle: (HANDLE) _fileno(_file)
//

static int* FILE_STREAM_SERIAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_40_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* ORIGINAL_MODE_SERIAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_41_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Socket
//

static int* SOCKET_NUMBER_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Terminal
//
// CAUTION! Store file STREAM instead of file descriptor, since:
// - stream is a more complex structure containing the descriptor
// - the c standard defines only file streams of type FILE*
//
// Special types used by various platforms are NOT stored here,
// since they may be retrieved from the FILE structure, e.g.:
// - POSIX: "file descriptor" (int) used in direct file access functions, retrieved via "int fileno(FILE* stream)"
// - Win32: "file handle" (DWORD) used in alternative input/output functions, retrieved via "int _fileno(FILE* stream)"
//          the returned int may be casted to file handle: (HANDLE) _fileno(_file)
//

static int* OUTPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_60_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* INPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_61_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* OUTPUT_ORIGINAL_MODE_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_62_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* INPUT_ORIGINAL_MODE_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_63_INTEGER_STATE_CYBOI_MODEL_ARRAY;

static int* BLOCKING_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_65_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* CANONICAL_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_66_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* ECHO_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_67_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* INPUT_OUTPUT_STATE_CYBOI_NAME_CONSTANT_SOURCE */
#endif
