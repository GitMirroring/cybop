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

#ifndef CLIENT_STATE_CYBOI_NAME_CONSTANT_HEADER
#define CLIENT_STATE_CYBOI_NAME_CONSTANT_HEADER

//
// Library interface
//

#include "constant.h"

//
// CAUTION! The client entry size is set in file "state_cyboi_model.h"!
//

//
// General
//

// The client device identification as integer number (e.g. file descriptor, client socket number, window id).
static int* IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;
// The client device identification as item.
static int* ITEM_GENERAL_CLIENT_STATE_CYBOI_NAME = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;
// The client device name item (e.g. a file system path pointing to some device).
static int* NAME_GENERAL_CLIENT_STATE_CYBOI_NAME = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Communication
//
// CAUTION! These constants are used by: sense, read, write.
//

static int* CHANNEL_COMMUNICATION_CLIENT_STATE_CYBOI_NAME = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* SERVER_COMMUNICATION_CLIENT_STATE_CYBOI_NAME = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* PORT_COMMUNICATION_CLIENT_STATE_CYBOI_NAME = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* LANGUAGE_COMMUNICATION_CLIENT_STATE_CYBOI_NAME = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;
// This is needed only for sending a signal (event).
static int* SOURCE_PART_COMMUNICATION_CLIENT_STATE_CYBOI_NAME = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Input
//
// CAUTION! The buffer is used only for ASYNCHRONOUS reading.
// Synchronous reading, on the other hand, accesses the blocking device
// directly and waits until data as input is available.
//
// CAUTION! The buffer serves as temporary INPUT STORE between sensor and reader.
// The sensor reads input data first and stores them in this buffer item.
// A handler given in cybol then calls the reader which uses the data from this buffer.
//
// CAUTION! The thread is used by ASYNCHRONOUS input only.
// Since it runs an endless loop, an EXIT flag is necessary
// in order to be able to leave the loop and corresponding thread.
//

static int* ITEM_BUFFER_INPUT_CLIENT_STATE_CYBOI_NAME = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* MUTEX_BUFFER_INPUT_CLIENT_STATE_CYBOI_NAME = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* IDENTIFICATION_THREAD_INPUT_CLIENT_STATE_CYBOI_NAME = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* EXIT_THREAD_INPUT_CLIENT_STATE_CYBOI_NAME = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* SENSOR_HANDLER_INPUT_CLIENT_STATE_CYBOI_NAME = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* CLOSER_HANDLER_INPUT_CLIENT_STATE_CYBOI_NAME = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Output
//
// CAUTION! The buffer is used for BOTH, synchronous AND asynchronous writing.
//
// CAUTION! The buffer serves as temporary OUTPUT STORE within the writer.
// The writing happens in a loop. If not all data could be written,
// then the already written data get removed from the buffer,
// so that the next loop cycle writes only the remaining data.
// For asynchronous writing, this is done in a separate thread.
//
// CAUTION! MANY threads may be used by asynchronous output internally.
// Contrarily to the input, they get exited AUTOMATICALLY if
// all data has been written. Therefore, neither the thread
// identification, nor an exit flag have to be stored here.
//

static int* ITEM_BUFFER_OUTPUT_CLIENT_STATE_CYBOI_NAME = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* MUTEX_BUFFER_OUTPUT_CLIENT_STATE_CYBOI_NAME = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* WRITER_HANDLER_OUTPUT_CLIENT_STATE_CYBOI_NAME = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Serial port
//

static int* ORIGINAL_MODE_SERIAL_CLIENT_STATE_CYBOI_NAME = NUMBER_40_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Terminal
//
// CAUTION! The TWO separate modes are needed for win32 console access.
//

static int* INPUT_ORIGINAL_MODE_TERMINAL_CLIENT_STATE_CYBOI_NAME = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* OUTPUT_ORIGINAL_MODE_TERMINAL_CLIENT_STATE_CYBOI_NAME = NUMBER_51_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Socket
//
// CAUTION! It is possible that MANY clients request data
// via the same port, which is managed by the operating system.
// Therefore, a lock or mutex is NOT needed for this in cyboi.
//

//?? static int* TIMEOUT_SOCKET_CLIENT_STATE_CYBOI_NAME = NUMBER_60_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Backlink
//

static int* INTERNAL_MEMORY_BACKLINK_CLIENT_STATE_CYBOI_NAME = NUMBER_90_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* INPUT_OUTPUT_BACKLINK_CLIENT_STATE_CYBOI_NAME = NUMBER_91_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* SERVER_ENTRY_BACKLINK_CLIENT_STATE_CYBOI_NAME = NUMBER_92_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CLIENT_STATE_CYBOI_NAME_CONSTANT_HEADER */
#endif
