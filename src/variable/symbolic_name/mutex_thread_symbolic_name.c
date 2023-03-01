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

#ifndef MUTEX_THREAD_SYMBOLIC_NAME_SOURCE
#define MUTEX_THREAD_SYMBOLIC_NAME_SOURCE

//
// The global variables.
//
// CAUTION! This is just the variable definition.
// Initialisation happens in directory "controller/globaliser/".
//

//
// A symbolic constant is an enumeration entry,
// e.g. taken from file "threads.h":
//
// /* Mutex types.  */
// enum
// {
//   mtx_plain     = 0,
//   mtx_recursive = 1,
//   mtx_timed     = 2
// };
//
// CAUTION! They CANNOT be handed over as reference to a function
// since otherwise, the compiler will show an error like:
// error: lvalue required as unary ‘&’ operand
//
// Therefore, these global variables are defined to hold the
// original value of the symbolic name and be used instead.
//
// CAUTION! The definition of pure integer constants is NOT possible,
// since the values of symbolic names DIFFER between operating systems.
// Therefore, global variables are used and the values of
// symbolic names assigned at runtime, when cyboi starts up.
//

/** The plain mutex type thread symbolic name. */
static int PLAIN_MUTEX_TYPE_THREAD_SYMBOLIC_NAME_ARRAY[1];
static int* PLAIN_MUTEX_TYPE_THREAD_SYMBOLIC_NAME = PLAIN_MUTEX_TYPE_THREAD_SYMBOLIC_NAME_ARRAY;

/** The recursive mutex type thread symbolic name. */
static int RECURSIVE_MUTEX_TYPE_THREAD_SYMBOLIC_NAME_ARRAY[1];
static int* RECURSIVE_MUTEX_TYPE_THREAD_SYMBOLIC_NAME = RECURSIVE_MUTEX_TYPE_THREAD_SYMBOLIC_NAME_ARRAY;

/** The timed mutex type thread symbolic name. */
static int TIMED_MUTEX_TYPE_THREAD_SYMBOLIC_NAME_ARRAY[1];
static int* TIMED_MUTEX_TYPE_THREAD_SYMBOLIC_NAME = TIMED_MUTEX_TYPE_THREAD_SYMBOLIC_NAME_ARRAY;

/* MUTEX_THREAD_SYMBOLIC_NAME_SOURCE */
#endif
