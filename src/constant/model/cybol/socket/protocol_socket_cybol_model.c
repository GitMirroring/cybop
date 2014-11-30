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

#ifndef PROTOCOL_SOCKET_CYBOL_MODEL_CONSTANT_SOURCE
#define PROTOCOL_SOCKET_CYBOL_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/**
 * The icmp protocol socket cybol model.
 *
 * This is a valid protocol for a raw socket.
 */
static wchar_t* ICMP_PROTOCOL_SOCKET_CYBOL_MODEL = L"icmp";
static int* ICMP_PROTOCOL_SOCKET_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The raw protocol socket cybol model.
 *
 * This is a valid protocol for a raw socket.
 */
static wchar_t* RAW_PROTOCOL_SOCKET_CYBOL_MODEL = L"raw";
static int* RAW_PROTOCOL_SOCKET_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

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

/* PROTOCOL_SOCKET_CYBOL_MODEL_CONSTANT_SOURCE */
#endif
