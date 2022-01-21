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

static int* IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;
//?? static int* CLIENT_MODE_GENERAL_CLIENT_STATE_CYBOI_NAME = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* HANDLER_GENERAL_CLIENT_STATE_CYBOI_NAME = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* SENDER_GENERAL_CLIENT_STATE_CYBOI_NAME = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* LANGUAGE_GENERAL_CLIENT_STATE_CYBOI_NAME = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* CHANNEL_GENERAL_CLIENT_STATE_CYBOI_NAME = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Buffer
//

static int* ITEM_BUFFER_CLIENT_STATE_CYBOI_NAME = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* MUTEX_BUFFER_CLIENT_STATE_CYBOI_NAME = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Thread
//

static int* IDENTIFICATION_THREAD_CLIENT_STATE_CYBOI_NAME = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* EXIT_THREAD_CLIENT_STATE_CYBOI_NAME = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Interrupt
//

static int* PIPE_INTERRUPT_CLIENT_STATE_CYBOI_NAME = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* MUTEX_INTERRUPT_CLIENT_STATE_CYBOI_NAME = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Server
//

static int* IDENTIFICATION_SERVER_CLIENT_STATE_CYBOI_NAME = NUMBER_40_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Channel
//

//?? static int* SERIAL_PORT_CLIENT_STATE_CYBOI_NAME = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;
//?? static int* TERMINAL_CLIENT_STATE_CYBOI_NAME = NUMBER_51_INTEGER_STATE_CYBOI_MODEL_ARRAY;
//?? static int* XCB_CONNEXION_CLIENT_STATE_CYBOI_NAME = NUMBER_52_INTEGER_STATE_CYBOI_MODEL_ARRAY;

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

//?? static int* FILE_STREAM_SERIAL_CLIENT_STATE_CYBOI_NAME = NUMBER_60_INTEGER_STATE_CYBOI_MODEL_ARRAY;
//?? static int* ORIGINAL_MODE_SERIAL_CLIENT_STATE_CYBOI_NAME = NUMBER_61_INTEGER_STATE_CYBOI_MODEL_ARRAY;

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

//?? static int* OUTPUT_FILE_STREAM_TERMINAL_CLIENT_STATE_CYBOI_NAME = NUMBER_70_INTEGER_STATE_CYBOI_MODEL_ARRAY;
//?? static int* INPUT_FILE_STREAM_TERMINAL_CLIENT_STATE_CYBOI_NAME = NUMBER_71_INTEGER_STATE_CYBOI_MODEL_ARRAY;
//?? static int* OUTPUT_ORIGINAL_MODE_TERMINAL_CLIENT_STATE_CYBOI_NAME = NUMBER_72_INTEGER_STATE_CYBOI_MODEL_ARRAY;
//?? static int* INPUT_ORIGINAL_MODE_TERMINAL_CLIENT_STATE_CYBOI_NAME = NUMBER_73_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//?? static int* BLOCKING_TERMINAL_CLIENT_STATE_CYBOI_NAME = NUMBER_75_INTEGER_STATE_CYBOI_MODEL_ARRAY;
//?? static int* CANONICAL_TERMINAL_CLIENT_STATE_CYBOI_NAME = NUMBER_76_INTEGER_STATE_CYBOI_MODEL_ARRAY;
//?? static int* ECHO_TERMINAL_CLIENT_STATE_CYBOI_NAME = NUMBER_77_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Display
//

//?? static int* CONNEXION_XCB_DISPLAY_CLIENT_STATE_CYBOI_NAME = NUMBER_80_INTEGER_STATE_CYBOI_MODEL_ARRAY;
//?? static int* SCREEN_XCB_DISPLAY_CLIENT_STATE_CYBOI_NAME = NUMBER_81_INTEGER_STATE_CYBOI_MODEL_ARRAY;
//?? static int* GRAPHIC_CONTEXT_XCB_DISPLAY_CLIENT_STATE_CYBOI_NAME = NUMBER_82_INTEGER_STATE_CYBOI_MODEL_ARRAY;
//?? static int* DEVICE_CONTEXT_WIN32_DISPLAY_CLIENT_STATE_CYBOI_NAME = NUMBER_83_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CLIENT_STATE_CYBOI_NAME_CONSTANT_SOURCE */
#endif
