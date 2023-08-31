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

#ifndef SERVER_STATE_CYBOI_NAME_CONSTANT_HEADER
#define SERVER_STATE_CYBOI_NAME_CONSTANT_HEADER

//
// Library interface
//

#include "constant.h"

//
// CAUTION! The server entry size is set in file "state_cyboi_model.h"!
//

//
// General
//

// The server service identification (e.g. port 80 for web services).
static int* IDENTIFICATION_GENERAL_SERVER_STATE_CYBOI_NAME = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Client list
//

static int* ITEM_CLIENTS_SERVER_STATE_CYBOI_NAME = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;
//?? DELETE: A mutex is not needed since only the main thread writes to it.
//?? static int* MUTEX_CLIENTS_SERVER_STATE_CYBOI_NAME = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;
//?? static int* ACCEPTTIME_CLIENTS_SERVER_STATE_CYBOI_NAME = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Communication
//

static int* CHANNEL_COMMUNICATION_SERVER_STATE_CYBOI_NAME = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* HANDLER_COMMUNICATION_SERVER_STATE_CYBOI_NAME = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Request input
//
// CAUTION! The buffer is used only for ASYNCHRONOUS opening.
// Synchronous opening, on the other hand, accesses the blocking device
// directly and waits until a client request as input is available.
//
// CAUTION! The buffer serves as temporary INPUT STORE between enabler and opener.
// The enabler receives client requests first and stores them in this buffer item.
// A handler given in cybol then calls the opener which uses the data from this buffer.
//
// CAUTION! The buffer thus stores INTEGER numbers, NOT pointers.
//
// CAUTION! The thread is used by ASYNCHRONOUS input only.
// Since it runs an endless loop, an EXIT flag is necessary
// in order to be able to leave the loop and corresponding thread.
//

static int* ITEM_BUFFER_INPUT_SERVER_STATE_CYBOI_NAME = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* MUTEX_BUFFER_INPUT_SERVER_STATE_CYBOI_NAME = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* IDENTIFICATION_THREAD_INPUT_SERVER_STATE_CYBOI_NAME = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* EXIT_THREAD_INPUT_SERVER_STATE_CYBOI_NAME = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Display
//

static int* CONNEXION_XCB_DISPLAY_SERVER_STATE_CYBOI_NAME = NUMBER_40_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* SCREEN_XCB_DISPLAY_SERVER_STATE_CYBOI_NAME = NUMBER_41_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* GRAPHIC_CONTEXT_XCB_DISPLAY_SERVER_STATE_CYBOI_NAME = NUMBER_42_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* DEVICE_CONTEXT_WIN32_DISPLAY_SERVER_STATE_CYBOI_NAME = NUMBER_43_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Socket
//

static int* IDENTIFICATION_SOCKET_SERVER_STATE_CYBOI_NAME = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;
//?? static int* TIMEOUT_SOCKET_SERVER_STATE_CYBOI_NAME = NUMBER_51_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Backlink
//

static int* INTERNAL_MEMORY_BACKLINK_SERVER_STATE_CYBOI_NAME = NUMBER_90_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* INPUT_OUTPUT_BACKLINK_SERVER_STATE_CYBOI_NAME = NUMBER_91_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SERVER_STATE_CYBOI_NAME_CONSTANT_HEADER */
#endif
