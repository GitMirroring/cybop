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

#ifndef THREAD_IDENTIFICATION_SOURCE
#define THREAD_IDENTIFICATION_SOURCE

#include <pthread.h>

//
// The global variables.
//
// CAUTION! This is just the variable definition.
// Initialisation happens in directory "controller/globaliser/".
//

/**
 * The empty default thread.
 *
 * CAUTION! It is used for comparison only,
 * in order to find out whether or not
 * a thread was created already.
 */
static pthread_t DEFAULT_THREAD;

/** The display thread. */
static pthread_t DISPLAY_THREAD_ARRAY[1];
static pthread_t* DISPLAY_THREAD = DISPLAY_THREAD_ARRAY;

/** The serial thread. */
static pthread_t SERIAL_THREAD_ARRAY[1];
static pthread_t* SERIAL_THREAD = SERIAL_THREAD_ARRAY;

/** The socket service thread. */
static pthread_t SOCKET_THREAD_ARRAY[1];
static pthread_t* SOCKET_THREAD = SOCKET_THREAD_ARRAY;

/** The terminal thread. */
static pthread_t TERMINAL_THREAD_ARRAY[1];
static pthread_t* TERMINAL_THREAD = TERMINAL_THREAD_ARRAY;

/* THREAD_IDENTIFICATION_SOURCE */
#endif
