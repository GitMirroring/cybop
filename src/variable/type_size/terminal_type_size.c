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

#ifndef TERMINAL_TYPE_SIZE_SOURCE
#define TERMINAL_TYPE_SIZE_SOURCE

//
// The global variables.
//
// CAUTION! This is just the variable definition.
// Initialisation happens in directory "controller/globaliser/".
//

//
// Terminal mode.
//

/** The unix terminal mode type size. */
static int UNIX_TERMINAL_MODE_TYPE_SIZE_ARRAY[1];
static int* UNIX_TERMINAL_MODE_TYPE_SIZE = UNIX_TERMINAL_MODE_TYPE_SIZE_ARRAY;

/** The win32 console mode type size. */
static int WIN32_CONSOLE_MODE_TYPE_SIZE_ARRAY[1];
static int* WIN32_CONSOLE_MODE_TYPE_SIZE = WIN32_CONSOLE_MODE_TYPE_SIZE_ARRAY;

/* TERMINAL_TYPE_SIZE_SOURCE */
#endif
