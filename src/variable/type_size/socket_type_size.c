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

#ifndef SOCKET_TYPE_SIZE_SOURCE
#define SOCKET_TYPE_SIZE_SOURCE

//
// The global variables.
//
// CAUTION! This is just the variable definition.
// Initialisation happens in directory "controller/globaliser/".
//

//
// Host address.
//

/** The ipv4 host address socket type size (in_addr). */
static int IPV4_HOST_ADDRESS_SOCKET_TYPE_SIZE_ARRAY[1];
static int* IPV4_HOST_ADDRESS_SOCKET_TYPE_SIZE = IPV4_HOST_ADDRESS_SOCKET_TYPE_SIZE_ARRAY;

/** The ipv6 host address socket type size (in6_addr). */
static int IPV6_HOST_ADDRESS_SOCKET_TYPE_SIZE_ARRAY[1];
static int* IPV6_HOST_ADDRESS_SOCKET_TYPE_SIZE = IPV6_HOST_ADDRESS_SOCKET_TYPE_SIZE_ARRAY;

//
// Socket address.
//

/** The ipv4 socket address socket type size (sockaddr_in). */
static int IPV4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY[1];
static int* IPV4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = IPV4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY;

/** The ipv6 socket address socket type size (sockaddr_in6). */
static int IPV6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY[1];
static int* IPV6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = IPV6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY;

/** The local socket address socket type size (sockaddr_un). */
static int LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY[1];
static int* LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY;

/* SOCKET_TYPE_SIZE_SOURCE */
#endif
