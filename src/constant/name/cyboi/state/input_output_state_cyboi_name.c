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

/**
 * CAUTION! When editing one file, then adapt ALL FOUR files:
 * "constant/name/cyboi/state/input_output_state_cyboi_name.c"
 * "controller/globaliser/type_size/compound_type_size_globaliser.c"
 * "executor/accessor/getter/io_entry_getter.c"
 * "executor/accessor/setter/io_entry_setter.c"
 */

//
// CAUTION! If extending the number of entries here,
// the INTERNAL MEMORY base segment size MIGHT HAVE TO BE adapted as well.
//

//
// General.
//

static int* ENABLE_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* INTERRUPT_REQUEST_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* HANDLER_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* SENDER_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Serial port.
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

static int* FILE_STREAM_SERIAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* ORIGINAL_MODE_SERIAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Terminal.
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

static int* OUTPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* INPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* OUTPUT_ORIGINAL_MODE_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* INPUT_ORIGINAL_MODE_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Display.
//

static int* CONNEXION_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* SCREEN_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* GRAPHIC_CONTEXT_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* DEVICE_CONTEXT_WIN32_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* EVENT_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Socket.
//

static int* SOCKET_NUMBER_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_40_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* CLIENT_LIST_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_41_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* ACCEPTTIME_LIST_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_42_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* TIMEOUT_SOCKET_INPUT_OUTPUT_STATE_CYBOI_NAME = NUMBER_43_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* INPUT_OUTPUT_STATE_CYBOI_NAME_CONSTANT_SOURCE */
#endif
