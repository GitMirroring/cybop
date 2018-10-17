/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef INTERNAL_MEMORY_STATE_CYBOI_NAME_CONSTANT_SOURCE
#define INTERNAL_MEMORY_STATE_CYBOI_NAME_CONSTANT_SOURCE

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// These constants are NOT sorted alphabetically, but as follows:
// - knowledge memory
// - stack memory
// - signal memory
// - sleep time
// - serial port
// - terminal
// - display
// - socket
//
// CAUTION! The socket stands at last, since unpredictably
// many socket services may have to be added in the future.
//

/** The knowledge memory. */
static int* KNOWLEDGE_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The stack memory. */
static int* STACK_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The signal memory. */
static int* SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* SLEEP_TIME_SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The serial port.
 *
 * The total number of possible serial port services (ports) is: 1
 */
static int* SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_100_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The terminal.
 *
 * The total number of possible terminal services (ports) is: 1
 */
static int* TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_200_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The display.
 *
 * The total number of possible display services (ports) is: 1
 */
static int* DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_300_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The socket base.
 *
 * The PORT NUMBER is used as offset to this base number,
 * so that each network service has its own memory space.
 *
 * CAUTION! Only SERVER SOCKETS are stored here.
 * If this CYBOI interpreter acts as client asking
 * another service, then that socket number has to be
 * stored in the corresponding CYBOL application.
 *
 * The total number of possible socket services (ports) is: 65536
 */
static int* SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_400_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* INTERNAL_MEMORY_STATE_CYBOI_NAME_CONSTANT_SOURCE */
#endif
