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

#ifndef SERVICE_INTERRUPT_SOURCE
#define SERVICE_INTERRUPT_SOURCE

//
// The global variables.
//
// CAUTION! This is just the variable definition.
// Initialisation happens in directory "controller/globaliser/".
//

/** The display service interrupt flag. */
static int DISPLAY_SERVICE_INTERRUPT_ARRAY[1];
static int* DISPLAY_SERVICE_INTERRUPT = DISPLAY_SERVICE_INTERRUPT_ARRAY;

/** The serial service interrupt flag. */
static int SERIAL_SERVICE_INTERRUPT_ARRAY[1];
static int* SERIAL_SERVICE_INTERRUPT = SERIAL_SERVICE_INTERRUPT_ARRAY;

/** The socket service interrupt flag. */
static int SOCKET_SERVICE_INTERRUPT_ARRAY[1];
static int* SOCKET_SERVICE_INTERRUPT = SOCKET_SERVICE_INTERRUPT_ARRAY;

/** The terminal service interrupt flag. */
static int TERMINAL_SERVICE_INTERRUPT_ARRAY[1];
static int* TERMINAL_SERVICE_INTERRUPT = TERMINAL_SERVICE_INTERRUPT_ARRAY;

/* SERVICE_INTERRUPT_SOURCE */
#endif
