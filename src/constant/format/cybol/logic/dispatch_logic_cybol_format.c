/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef DISPATCH_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define DISPATCH_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Dispatch
//
// IANA media type: not defined
// Self-defined media type: dispatch
// This media type is a CYBOL extension.
//

/**
 * The dispatch/close logic cybol format.
 *
 * Close down a client that has been used for connecting to a service.
 * Closes down the client on the given channel.
 *
 * Parametres:
 * - channel (required): the communication channel, e.g. file, serial, socket
 * - server (optional): the flag indicating server mode, e.g. for window or client socket stub; if NULL, the default is false (standalone client mode)
 * - port (optional): the service identification; only relevant in server mode
 * - identification (required): the file descriptor or client socket number or window id returned from cyboi (except for channel "server_socket", where accept returns a ready client socket id)
 */
static wchar_t* CLOSE_DISPATCH_LOGIC_CYBOL_FORMAT = L"dispatch/close";
static int* CLOSE_DISPATCH_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The dispatch/open logic cybol format.
 *
 * Open up a client for connecting to a service.
 * Opens up a client on the given channel.
 *
 * Parametres:
 * - channel (required): the communication channel, e.g. file, serial, socket
 * - server (optional): the flag indicating server mode, e.g. for window or client socket stub; if NULL, the default is false (standalone client mode)
 * - port (optional): the service identification; only relevant in server mode
 * - namespace (optional): the address family, e.g. ipv4 or ipv6
 * - style (optional): the communication style, e.g. stream or datagram
 * - protocol (optional): the protocol, e.g. tcp or udp
 * - file open mode (optional): either read or write; if NULL, the default is read
 * - device (optional):
 *      = filename for channel "file" or "serialport" or "terminal" or "fifo", e.g. /path/to/file.txt or /dev/ttyS0
 *      = filename for channel "socket" with namespace "local" (unix domain socket), e.g. localbuffer.socket
 *      = host address for channel "socket" with namespace "ipv4" or "ipv6", e.g. localhost or 127.0.0.1
 *      = null for channel "display", since a client window does not need it (therefore it is OPTIONAL)
 * - identification (required): the file descriptor or client socket number or window id returned from cyboi (except for channel "server_socket", where accept returns a ready client socket id)
 */
static wchar_t* OPEN_DISPATCH_LOGIC_CYBOL_FORMAT = L"dispatch/open";
static int* OPEN_DISPATCH_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* DISPATCH_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
