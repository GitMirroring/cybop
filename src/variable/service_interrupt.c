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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERVICE_INTERRUPT_SOURCE
#define SERVICE_INTERRUPT_SOURCE

//
// The global variables.
//
// CAUTION! This is just the variable definition.
// Initialisation happens in directory "controller/globaliser/".
//

/** The cyboi service exit flag. */
static int CYBOI_SERVICE_EXIT_ARRAY[1];
static int* CYBOI_SERVICE_EXIT = CYBOI_SERVICE_EXIT_ARRAY;

/** The serial port exit flag. */
static int SERIAL_PORT_EXIT_ARRAY[1];
static int* SERIAL_PORT_EXIT = SERIAL_PORT_EXIT_ARRAY;

/** The terminal exit flag. */
static int TERMINAL_EXIT_ARRAY[1];
static int* TERMINAL_EXIT = TERMINAL_EXIT_ARRAY;

/** The www service exit flag. */
static int WWW_SERVICE_EXIT_ARRAY[1];
static int* WWW_SERVICE_EXIT = WWW_SERVICE_EXIT_ARRAY;

/** The x window system exit flag. */
static int X_WINDOW_SYSTEM_EXIT_ARRAY[1];
static int* X_WINDOW_SYSTEM_EXIT = X_WINDOW_SYSTEM_EXIT_ARRAY;

/* SERVICE_INTERRUPT_SOURCE */
#endif
