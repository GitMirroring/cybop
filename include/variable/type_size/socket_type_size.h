/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SOCKET_TYPE_SIZE_VARIABLE_HEADER
#define SOCKET_TYPE_SIZE_VARIABLE_HEADER

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
int IPV4_HOST_ADDRESS_SOCKET_TYPE_SIZE_ARRAY[1];
int* IPV4_HOST_ADDRESS_SOCKET_TYPE_SIZE = IPV4_HOST_ADDRESS_SOCKET_TYPE_SIZE_ARRAY;

/** The ipv6 host address socket type size (in6_addr). */
int IPV6_HOST_ADDRESS_SOCKET_TYPE_SIZE_ARRAY[1];
int* IPV6_HOST_ADDRESS_SOCKET_TYPE_SIZE = IPV6_HOST_ADDRESS_SOCKET_TYPE_SIZE_ARRAY;

//
// Socket address.
//

/** The ipv4 socket address socket type size (sockaddr_in). */
int IPV4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY[1];
int* IPV4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = IPV4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY;

/** The ipv6 socket address socket type size (sockaddr_in6). */
int IPV6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY[1];
int* IPV6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = IPV6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY;

/** The local socket address socket type size (sockaddr_un). */
int LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY[1];
int* LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE_ARRAY;

/* SOCKET_TYPE_SIZE_VARIABLE_HEADER */
#endif
