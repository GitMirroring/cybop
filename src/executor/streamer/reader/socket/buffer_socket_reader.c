/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BUFFER_SOCKET_READER_SOURCE
#define BUFFER_SOCKET_READER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/streamer/reader/bsd_socket/bsd_socket_reader.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../../executor/streamer/reader/bsd_socket/bsd_socket_reader.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../../executor/streamer/reader/winsock/winsock_reader.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

//
// Unified socket send/receive.
//
// The communication functions for udp sockets are: sendto/recvfrom.
// When using them, address data have to be handed over as argument.
//
// However, if calling the "connect" function on datagram socket
// startup, the address data may be specified as argument there.
//
// Then, the send/recv (instead of sendto/recvfrom) functions
// may be used for stream AS WELL AS datagram sockets,
// since necessary address data are added internally.
//
// http://openbook.galileo-press.de/c_von_a_bis_z/025_c_netzwerkprogrammierung_004.htm#mj50a66f07dc78c522bbc8a31b18c366a8
//

/**
 * Reads socket data until the given buffer is filled.
 *
 * @param p0 the destination buffer data
 * @param p1 the destination buffer count
 * @param p2 the destination buffer size
 * @param p3 the source socket
 * @param p4 the socket options
 */
void read_socket_buffer(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read socket buffer.");

#if defined(__linux__) || defined(__unix__)
    read_bsd_socket(p0, p1, p2, p3, p4);
#elif defined(__APPLE__) && defined(__MACH__)
    read_bsd_socket(p0, p1, p2, p3, p4);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    read_winsock(p0, p1, p2, p3, p4);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* BUFFER_SOCKET_READER_SOURCE */
#endif
