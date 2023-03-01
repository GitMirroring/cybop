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

#ifndef STYLE_SOCKET_SYMBOLIC_NAME_GLOBALISER_SOURCE
#define STYLE_SOCKET_SYMBOLIC_NAME_GLOBALISER_SOURCE

#if defined(__linux__) || defined(__unix__)
    #include <sys/socket.h>
#elif defined(__APPLE__) && defined(__MACH__)
    #include <sys/socket.h>
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include <winsock.h>
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

#include "../../../variable/symbolic_name/style_socket_symbolic_name.c"

//
// The well-defined ip protocols below were mostly taken from:
//
// /usr/src/linux-headers-*-common/include/linux/net.h
// http://msdn.microsoft.com/en-us/library/windows/desktop/ms740506%28v=vs.85%29.aspx
//

/**
 * Initialises protocol socket symbolic name
 * (pre-processor-defined) global variables.
 */
void globalise_symbolic_name_socket_style() {

#if defined(__linux__) || defined(__unix__)
    *STREAM_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_STREAM; // 1 SOCK_STREAM
    *DATAGRAM_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_DGRAM; // 2 SOCK_DGRAM
    *RAW_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_RAW; // 3 SOCK_RAW
    *RDM_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_RDM; // 4 SOCK_RDM
    *SEQPACKET_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_SEQPACKET; // 5 SOCK_SEQPACKET
    *DCCP_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_DCCP; // 6 SOCK_DCCP
    *PACKET_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_PACKET; // 10 SOCK_PACKET
#elif defined(__APPLE__) && defined(__MACH__)
    *STREAM_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_STREAM; // 1 SOCK_STREAM
    *DATAGRAM_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_DGRAM; // 2 SOCK_DGRAM
    *RAW_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_RAW; // 3 SOCK_RAW
    *RDM_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_RDM; // 4 SOCK_RDM
    *SEQPACKET_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_SEQPACKET; // 5 SOCK_SEQPACKET
//??    *DCCP_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_DCCP; // 6 SOCK_DCCP
//??    *PACKET_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_PACKET; // 10 SOCK_PACKET
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    *STREAM_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_STREAM; // 1 SOCK_STREAM
    *DATAGRAM_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_DGRAM; // 2 SOCK_DGRAM
    *RAW_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_RAW; // 3 SOCK_RAW
    *RDM_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_RDM; // 4 SOCK_RDM
    *SEQPACKET_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_SEQPACKET; // 5 SOCK_SEQPACKET
//??    *DCCP_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_DCCP; // 6 SOCK_DCCP
//??    *PACKET_STYLE_SOCKET_SYMBOLIC_NAME = SOCK_PACKET; // 10 SOCK_PACKET
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* STYLE_SOCKET_SYMBOLIC_NAME_GLOBALISER_SOURCE */
#endif
