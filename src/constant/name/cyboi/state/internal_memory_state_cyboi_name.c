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

#ifndef INTERNAL_MEMORY_STATE_CYBOI_NAME_CONSTANT_SOURCE
#define INTERNAL_MEMORY_STATE_CYBOI_NAME_CONSTANT_SOURCE

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// CAUTION! The internal memory size is set in file "state_cyboi_model.c"!
//

//
// CAUTION! There is NOT just one global server list, but SEPARATE ones
// for each channel. Only display and socket do have servers anyway.
// Likewise, there is one SEPARATE client list per channel.
//
// The reason is that identification numbers (id) are different
// only WITHIN, but NOT across the channels.
//

//
// Memory
//

static int* KNOWLEDGE_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* STACK_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Interrupt pipe
//

static int* PIPE_INTERRUPT_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* MUTEX_INTERRUPT_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// File
//

static int* CLIENTS_FILE_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Serial port
//

static int* CLIENTS_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Terminal
//

static int* CLIENTS_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Named pipeline
//

static int* CLIENTS_PIPELINE_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Socket
//

static int* CLIENTS_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* SERVERS_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Display
//

static int* CLIENTS_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* SERVERS_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* INTERNAL_MEMORY_STATE_CYBOI_NAME_CONSTANT_SOURCE */
#endif
