/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BUFFER_SOCKET_WRITER_SOURCE
#define BUFFER_SOCKET_WRITER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/streamer/writer/bsd_socket/bsd_socket_writer.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../../executor/streamer/writer/bsd_socket/bsd_socket_writer.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../../executor/streamer/writer/winsock/winsock_writer.c"
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
 * Writes buffer data via socket.
 *
 * @param p0 the destination socket
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the number of bytes transferred
 */
void write_socket_buffer(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write socket buffer.");

#if defined(__linux__) || defined(__unix__)
    write_bsd_socket(p0, p1, p2, p3);
#elif defined(__APPLE__) && defined(__MACH__)
    write_bsd_socket(p0, p1, p2, p3);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    write_winsock(p0, p1, p2, p3);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* BUFFER_SOCKET_WRITER_SOURCE */
#endif
