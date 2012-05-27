/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
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

/** The cyboi service thread. */
static pthread_t CYBOI_SERVICE_THREAD_ARRAY[1];
static pthread_t* CYBOI_SERVICE_THREAD = CYBOI_SERVICE_THREAD_ARRAY;

/** The gnu linux console thread. */
static pthread_t TERMINAL_THREAD_ARRAY[1];
static pthread_t* TERMINAL_THREAD = TERMINAL_THREAD_ARRAY;

/** The www service thread. */
static pthread_t WWW_SERVICE_THREAD_ARRAY[1];
static pthread_t* WWW_SERVICE_THREAD = WWW_SERVICE_THREAD_ARRAY;

/** The x window system thread. */
static pthread_t X_WINDOW_SYSTEM_THREAD_ARRAY[1];
static pthread_t* X_WINDOW_SYSTEM_THREAD = X_WINDOW_SYSTEM_THREAD_ARRAY;

/* THREAD_IDENTIFICATION_SOURCE */
#endif
