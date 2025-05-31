/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CYBOL_CHANNEL_CONSTANT_HEADER
#define CYBOL_CHANNEL_CONSTANT_HEADER

//
// System interface
//


#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The clock cybol channel. */
static wchar_t* CLOCK_CYBOL_CHANNEL = L"clock";
static int* CLOCK_CYBOL_CHANNEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The display cybol channel. */
static wchar_t* DISPLAY_CYBOL_CHANNEL = L"display";
static int* DISPLAY_CYBOL_CHANNEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The fifo cybol channel.
 *
 * There are TWO kinds of a pipeline:
 * - anonymous: called "pipe" in glibc
 * - named: called "fifo" in glibc
 *
 * The abbreviation FIFO stands for first-in-first-out,
 * following the principle of a data queue.
 */
static wchar_t* FIFO_CYBOL_CHANNEL = L"fifo";
static int* FIFO_CYBOL_CHANNEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The file cybol channel. */
static wchar_t* FILE_CYBOL_CHANNEL = L"file";
static int* FILE_CYBOL_CHANNEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The inline cybol channel. */
static wchar_t* INLINE_CYBOL_CHANNEL = L"inline";
static int* INLINE_CYBOL_CHANNEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pipe cybol channel.
 *
 * There are TWO kinds of a pipeline:
 * - anonymous: called "pipe" in glibc
 * - named: called "fifo" in glibc
 */
static wchar_t* PIPE_CYBOL_CHANNEL = L"pipe";
static int* PIPE_CYBOL_CHANNEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The randomiser cybol channel. */
static wchar_t* RANDOMISER_CYBOL_CHANNEL = L"randomiser";
static int* RANDOMISER_CYBOL_CHANNEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The serial port cybol channel. */
static wchar_t* SERIAL_CYBOL_CHANNEL = L"serial";
static int* SERIAL_CYBOL_CHANNEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The signal cybol channel. */
static wchar_t* SIGNAL_CYBOL_CHANNEL = L"signal";
static int* SIGNAL_CYBOL_CHANNEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The socket cybol channel. */
static wchar_t* SOCKET_CYBOL_CHANNEL = L"socket";
static int* SOCKET_CYBOL_CHANNEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The terminal cybol channel. */
static wchar_t* TERMINAL_CYBOL_CHANNEL = L"terminal";
static int* TERMINAL_CYBOL_CHANNEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CYBOL_CHANNEL_CONSTANT_HEADER */
#endif
