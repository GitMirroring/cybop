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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef INTERNAL_MEMORY_STATE_CYBOI_NAME_CONSTANT_HEADER
#define INTERNAL_MEMORY_STATE_CYBOI_NAME_CONSTANT_HEADER

//
// Library interface
//

#include "constant.h"

//
// CAUTION! The internal memory size is set in file "state_cyboi_model.h"!
//

//
// Memory
//

// This is a part.
static int* KNOWLEDGE_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;
// This is a part.
static int* STACK_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;
// This is a part.
static int* SIGNAL_MEMORY_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Interrupt pipe
//

// This is an integer array of size two.
static int* PIPE_INTERRUPT_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;
// This is an integer array of size one.
static int* MUTEX_INTERRUPT_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;
// This is an integer array of size one.
static int* IDENTIFICATION_INTERRUPT_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Input output
//

static int* DISPLAY_INPUT_OUTPUT_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* FIFO_INPUT_OUTPUT_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* FILE_INPUT_OUTPUT_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* SERIAL_INPUT_OUTPUT_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* SOCKET_INPUT_OUTPUT_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;
static int* TERMINAL_INPUT_OUTPUT_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Selflink
//

static int* INTERNAL_MEMORY_SELFLINK_INTERNAL_MEMORY_STATE_CYBOI_NAME = NUMBER_29_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* INTERNAL_MEMORY_STATE_CYBOI_NAME_CONSTANT_HEADER */
#endif
