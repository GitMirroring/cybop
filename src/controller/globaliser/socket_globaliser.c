/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SOCKET_GLOBALISER_SOURCE
#define SOCKET_GLOBALISER_SOURCE

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <sys/un.h>

#include "../../variable/type_size/integral_type_size.c"
#include "../../variable/type_size/socket_type_size.c"

/**
 * Initialises socket global variables.
 */
void globalise_socket() {

    *INTERNET_PROTOCOL_4_HOST_ADDRESS_SOCKET_TYPE_SIZE = sizeof(struct in_addr);
    *INTERNET_PROTOCOL_4_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = sizeof(struct sockaddr_in);
    *INTERNET_PROTOCOL_6_HOST_ADDRESS_SOCKET_TYPE_SIZE = sizeof(struct in6_addr);
    *INTERNET_PROTOCOL_6_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = sizeof(struct sockaddr_in6);
    *LOCAL_SOCKET_ADDRESS_SOCKET_TYPE_SIZE = sizeof(struct sockaddr_un);
    *SOCKET_ADDRESS_SOCKET_TYPE_SIZE = sizeof(struct sockaddr);
}

/* SOCKET_GLOBALISER_SOURCE */
#endif
