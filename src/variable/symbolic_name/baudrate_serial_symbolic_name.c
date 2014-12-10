/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BAUDRATE_SERIAL_SYMBOLIC_NAME_SOURCE
#define BAUDRATE_SERIAL_SYMBOLIC_NAME_SOURCE

//
// The global variables.
//
// CAUTION! This is just the variable definition.
// Initialisation happens in directory "controller/globaliser/".
//

//
// A symbolic name is a pre-processor define, e.g.:
//
// #define PF_INET     2   /* IP protocol family.  */
// #define AF_INET     PF_INET
//

/** The xyz protocol family socket symbolic name. */
static int XYZ_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY[1];
static int* XYZ_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME = XYZ_PROTOCOL_FAMILY_SOCKET_SYMBOLIC_NAME_ARRAY;

/* BAUDRATE_SERIAL_SYMBOLIC_NAME_SOURCE */
#endif
