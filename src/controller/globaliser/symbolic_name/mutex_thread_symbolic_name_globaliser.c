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

#ifndef MUTEX_THREAD_SYMBOLIC_NAME_GLOBALISER_SOURCE
#define MUTEX_THREAD_SYMBOLIC_NAME_GLOBALISER_SOURCE

//
// System interface
//

#include <threads.h> // mtx_*

//
// Library interface
//

#include "variable.h"

//
// The symbolic constants below were taken from file "threads.h".
//

/**
 * Initialises mutex thread symbolic name
 * (enumeration element) global variables.
 */
void globalise_symbolic_name_thread_mutex() {

    *PLAIN_MUTEX_TYPE_THREAD_SYMBOLIC_NAME = mtx_plain;
    *RECURSIVE_MUTEX_TYPE_THREAD_SYMBOLIC_NAME = mtx_recursive;
    *TIMED_MUTEX_TYPE_THREAD_SYMBOLIC_NAME = mtx_timed;
}

/* MUTEX_THREAD_SYMBOLIC_NAME_GLOBALISER_SOURCE */
#endif
