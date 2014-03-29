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

#ifndef SOCKET_TYPE_SIZE_SOURCE
#define SOCKET_TYPE_SIZE_SOURCE

//
// The global variables.
//
// CAUTION! This is just the variable definition.
// Initialisation happens in directory "controller/globaliser/".
//

/** The in_addr socket type size. */
static int INTERNET_PROTOCOL_4_HOST_ADDRESS_SOCKET_TYPE_SIZE_ARRAY[1];
static int* INTERNET_PROTOCOL_4_HOST_ADDRESS_SOCKET_TYPE_SIZE = INTERNET_PROTOCOL_4_HOST_ADDRESS_SOCKET_TYPE_SIZE_ARRAY;

/** The sockaddr_in socket type size. */
static int INTERNET_PROTOCOL_4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY[1];
static int* INTERNET_PROTOCOL_4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = INTERNET_PROTOCOL_4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY;

/** The in6_addr socket type size. */
static int INTERNET_PROTOCOL_6_HOST_ADDRESS_SOCKET_TYPE_SIZE_ARRAY[1];
static int* INTERNET_PROTOCOL_6_HOST_ADDRESS_SOCKET_TYPE_SIZE = INTERNET_PROTOCOL_6_HOST_ADDRESS_SOCKET_TYPE_SIZE_ARRAY;

/** The sockaddr_in6 socket type size. */
static int INTERNET_PROTOCOL_6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY[1];
static int* INTERNET_PROTOCOL_6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = INTERNET_PROTOCOL_6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY;

/** The sockaddr_un socket type size. */
static int LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY[1];
static int* LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY;

/** The sockaddr socket type size. */
static int SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY[1];
static int* SOCKET_ADDRESS_SOCKET_TYPE_SIZE = SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY;

/* SOCKET_TYPE_SIZE_SOURCE */
#endif
