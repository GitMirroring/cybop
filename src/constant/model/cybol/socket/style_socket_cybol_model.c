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

#ifndef STYLE_SOCKET_CYBOL_MODEL_CONSTANT_SOURCE
#define STYLE_SOCKET_CYBOL_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The datagram style socket cybol model. */
static wchar_t* DATAGRAM_STYLE_SOCKET_CYBOL_MODEL = L"datagram";
static int* DATAGRAM_STYLE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The dccp style socket cybol model. */
static wchar_t* DCCP_STYLE_SOCKET_CYBOL_MODEL = L"dccp";
static int* DCCP_STYLE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The packet style socket cybol model. */
static wchar_t* PACKET_STYLE_SOCKET_CYBOL_MODEL = L"packet";
static int* PACKET_STYLE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The raw style socket cybol model. */
static wchar_t* RAW_STYLE_SOCKET_CYBOL_MODEL = L"raw";
static int* RAW_STYLE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The reliable message datagram (rdm) style socket cybol model. */
static wchar_t* RDM_STYLE_SOCKET_CYBOL_MODEL = L"rdm";
static int* RDM_STYLE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The pseudo-stream packet based on datagrams (seqpacket) style socket cybol model. */
static wchar_t* SEQPACKET_STYLE_SOCKET_CYBOL_MODEL = L"seqpacket";
static int* SEQPACKET_STYLE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The stream style socket cybol model. */
static wchar_t* STREAM_STYLE_SOCKET_CYBOL_MODEL = L"stream";
static int* STREAM_STYLE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* STYLE_SOCKET_CYBOL_MODEL_CONSTANT_SOURCE */
#endif
