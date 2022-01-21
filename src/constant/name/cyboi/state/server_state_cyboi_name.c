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

#ifndef SERVER_STATE_CYBOI_NAME_CONSTANT_SOURCE
#define SERVER_STATE_CYBOI_NAME_CONSTANT_SOURCE

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// CAUTION! The server entry size is set in file "state_cyboi_model.c"!
//

//
// General
//

static int* IDENTIFICATION_GENERAL_SERVER_STATE_CYBOI_NAME = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* CLIENT_MODE_GENERAL_SERVER_STATE_CYBOI_NAME = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* HANDLER_GENERAL_SERVER_STATE_CYBOI_NAME = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* SENDER_GENERAL_SERVER_STATE_CYBOI_NAME = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* LANGUAGE_GENERAL_SERVER_STATE_CYBOI_NAME = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* CHANNEL_GENERAL_SERVER_STATE_CYBOI_NAME = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Client
//
// CAUTION! The client identification is NOT used as client list index
// due to security reasons. Otherwise, a cybol developer might assign
// an astronomic number leading to severe system errors.
//
// Therefore, two lists exist IN PARALLEL:
// - one keeping the client identifications
// - another one referencing the client entries (resources)
//
// The first may be used to find the desired client identification
// whose index (position) is the same as in the second list,
// so that the corresponding client entry may be retrieved.
//

static int* IDENTIFICATION_CLIENT_SERVER_STATE_CYBOI_NAME = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* ENTRY_CLIENT_SERVER_STATE_CYBOI_NAME = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* ACCEPTTIME_CLIENT_SERVER_STATE_CYBOI_NAME = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* MUTEX_CLIENT_SERVER_STATE_CYBOI_NAME = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Thread
//

static int* IDENTIFICATION_THREAD_SERVER_STATE_CYBOI_NAME = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* EXIT_THREAD_SERVER_STATE_CYBOI_NAME = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Interrupt.
//

static int* PIPE_INTERRUPT_SERVER_STATE_CYBOI_NAME = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* MUTEX_INTERRUPT_SERVER_STATE_CYBOI_NAME = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Display
//

static int* CONNEXION_XCB_DISPLAY_SERVER_STATE_CYBOI_NAME = NUMBER_40_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* SCREEN_XCB_DISPLAY_SERVER_STATE_CYBOI_NAME = NUMBER_41_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Socket
//

static int* NUMBER_SOCKET_SERVER_STATE_CYBOI_NAME = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* TIMEOUT_SOCKET_SERVER_STATE_CYBOI_NAME = NUMBER_51_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SERVER_STATE_CYBOI_NAME_CONSTANT_SOURCE */
#endif
