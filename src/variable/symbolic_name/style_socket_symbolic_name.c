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

#ifndef STYLE_SOCKET_SYMBOLIC_NAME_SOURCE
#define STYLE_SOCKET_SYMBOLIC_NAME_SOURCE

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
// CAUTION! They CANNOT be handed over as reference to a function
// since otherwise, the compiler will show an error like:
// error: lvalue required as unary ‘&’ operand
//
// Therefore, these global variables are defined to hold the
// original value of the symbolic name and be used instead.
//
// CAUTION! The definition of pure integer constants is NOT possible,
// since the values of symbolic names DIFFER between operating systems.
// Therefore, global variables are used and the values of
// symbolic names assigned at runtime, when cyboi starts up.
//

//
// The socket styles below were mostly taken from:
//
// /usr/src/linux-headers-*-common/include/linux/net.h
// http://msdn.microsoft.com/en-us/library/windows/desktop/ms740506%28v=vs.85%29.aspx
//

/** The 1 stream style socket symbolic name. */
int STREAM_STYLE_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* STREAM_STYLE_SOCKET_SYMBOLIC_NAME = STREAM_STYLE_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 2 datagram style socket symbolic name. */
int DATAGRAM_STYLE_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* DATAGRAM_STYLE_SOCKET_SYMBOLIC_NAME = DATAGRAM_STYLE_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 3 raw style socket symbolic name. */
int RAW_STYLE_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* RAW_STYLE_SOCKET_SYMBOLIC_NAME = RAW_STYLE_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 4 rdm style socket symbolic name. */
int RDM_STYLE_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* RDM_STYLE_SOCKET_SYMBOLIC_NAME = RDM_STYLE_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 5 seqpacket style socket symbolic name. */
int SEQPACKET_STYLE_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* SEQPACKET_STYLE_SOCKET_SYMBOLIC_NAME = SEQPACKET_STYLE_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 6 dccp style socket symbolic name. */
int DCCP_STYLE_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* DCCP_STYLE_SOCKET_SYMBOLIC_NAME = DCCP_STYLE_SOCKET_SYMBOLIC_NAME_ARRAY;

/** The 10 packet style socket symbolic name. */
int PACKET_STYLE_SOCKET_SYMBOLIC_NAME_ARRAY[1];
int* PACKET_STYLE_SOCKET_SYMBOLIC_NAME = PACKET_STYLE_SOCKET_SYMBOLIC_NAME_ARRAY;

/* STYLE_SOCKET_SYMBOLIC_NAME_SOURCE */
#endif
