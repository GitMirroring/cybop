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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef PROTOCOL_SOCKET_CYBOL_MODEL_CONSTANT_HEADER
#define PROTOCOL_SOCKET_CYBOL_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/**
 * The bluetooth radio frequency communications (bluetooth_rfcomm) protocol socket cybol model.
 *
 * This is a valid protocol for a stream socket.
 */
static wchar_t* BTHPROTO_RFCOMM_PROTOCOL_SOCKET_CYBOL_MODEL = L"bluetooth_rfcomm";
static int* BTHPROTO_RFCOMM_PROTOCOL_SOCKET_CYBOL_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The internet control message protocol (icmp) protocol socket cybol model.
 *
 * This is a valid protocol for a raw socket.
 */
static wchar_t* ICMP_PROTOCOL_SOCKET_CYBOL_MODEL = L"icmp";
static int* ICMP_PROTOCOL_SOCKET_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The internet control message protocol version 6 (icmpv6) protocol socket cybol model.
 *
 * This is a valid protocol for a raw socket.
 */
static wchar_t* ICMPV6_PROTOCOL_SOCKET_CYBOL_MODEL = L"icmpv6";
static int* ICMPV6_PROTOCOL_SOCKET_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The internet group management protocol (igmp) protocol socket cybol model.
 *
 * This is a valid protocol for a raw socket.
 */
static wchar_t* IGMP_PROTOCOL_SOCKET_CYBOL_MODEL = L"igmp";
static int* IGMP_PROTOCOL_SOCKET_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The raw protocol socket cybol model.
 *
 * This is a valid protocol for a raw socket.
 */
static wchar_t* RAW_PROTOCOL_SOCKET_CYBOL_MODEL = L"raw";
static int* RAW_PROTOCOL_SOCKET_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pgm protocol formerly called reliable multicast (rm) protocol socket cybol model.
 *
 * This is a valid protocol for a rdm socket.
 */
static wchar_t* RM_PROTOCOL_SOCKET_CYBOL_MODEL = L"rm";
static int* RM_PROTOCOL_SOCKET_CYBOL_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The tcp protocol socket cybol model.
 *
 * This is the default protocol for stream sockets.
 */
static wchar_t* TCP_PROTOCOL_SOCKET_CYBOL_MODEL = L"tcp";
static int* TCP_PROTOCOL_SOCKET_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The udp protocol socket cybol model.
 *
 * This is the default protocol for datagram sockets.
 */
static wchar_t* UDP_PROTOCOL_SOCKET_CYBOL_MODEL = L"udp";
static int* UDP_PROTOCOL_SOCKET_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* PROTOCOL_SOCKET_CYBOL_MODEL_CONSTANT_HEADER */
#endif
