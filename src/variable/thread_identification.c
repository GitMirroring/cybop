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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef THREAD_IDENTIFICATION_SOURCE
#define THREAD_IDENTIFICATION_SOURCE

#include <threads.h> // thrd_t

//
// The global variables.
//

/**
 * The empty default thread identification.
 *
 * CAUTION! The default thread does NOT get initialised.
 * It is left EMPTY on purpose. It is used for COMPARISON only,
 * in order to find out whether or not a thread was created already.
 *
 * CAUTION! Do NOT assign an integer value here.
 * The threads (pthread) implementation under mingw win32
 * uses a struct and NOT a scalar value.
 *
 * Otherwise, the compiler reports the error:
 * incompatible types when assigning to type ‘pthread_t’ from type ‘int’
 *
 * And when trying to cast, the compiler reports the error:
 * conversion to non-scalar type requested
 *
 * Originally, pthread_t was defined as a pointer
 * (to the opaque pthread_t_struct) and later it was
 * changed to a struct containing the original pointer
 * plus a sequence counter. This is allowed under both
 * the original POSIX Threads Standard and the current
 * Single Unix Specification.
 *
 * Other threads (pthreads) implementations, such as Sun's,
 * use an int as the handle but do guarantee uniqueness
 * within the process scope. Win32 scalar typed thread
 * handles also guarantee uniqueness in system scope.
 *
 * http://sourceware.org/pthreads-win32/faq.html
 *
 */
static thrd_t DEFAULT_THREAD_IDENTIFICATION;

/* THREAD_IDENTIFICATION_SOURCE */
#endif
