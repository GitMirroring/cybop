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

// The client device identification (e.g. file descriptor, client socket number).
static int* IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;
// The client device name item (e.g. a file system path pointing to some device).
static int* NAME_GENERAL_CLIENT_STATE_CYBOI_NAME = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Request
//

static int* CHANNEL_REQUEST_CLIENT_STATE_CYBOI_NAME = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* PORT_REQUEST_CLIENT_STATE_CYBOI_NAME = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* LANGUAGE_REQUEST_CLIENT_STATE_CYBOI_NAME = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* HANDLER_REQUEST_CLIENT_STATE_CYBOI_NAME = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Buffer
//
// CAUTION! It serves as temporary INPUT STORE between sensor and reader.
// The sensor reads input data first and stores them in this buffer item.
// A handler given in cybol then calls the reader which uses the data from this buffer.
//

static int* ITEM_BUFFER_CLIENT_STATE_CYBOI_NAME = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* MUTEX_BUFFER_CLIENT_STATE_CYBOI_NAME = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Thread
//

static int* IDENTIFICATION_THREAD_CLIENT_STATE_CYBOI_NAME = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* EXIT_THREAD_CLIENT_STATE_CYBOI_NAME = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Serial port
//

static int* ORIGINAL_MODE_SERIAL_PORT_CLIENT_STATE_CYBOI_NAME = NUMBER_40_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Terminal
//

static int* INPUT_ORIGINAL_MODE_TERMINAL_CLIENT_STATE_CYBOI_NAME = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* OUTPUT_ORIGINAL_MODE_TERMINAL_CLIENT_STATE_CYBOI_NAME = NUMBER_51_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Socket
//

//?? static int* TIMEOUT_SOCKET_CLIENT_STATE_CYBOI_NAME = NUMBER_60_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Backlink
//

static int* SERVER_ENTRY_BACKLINK_CLIENT_STATE_CYBOI_NAME = NUMBER_99_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CLIENT_STATE_CYBOI_NAME_CONSTANT_SOURCE */
#endif
