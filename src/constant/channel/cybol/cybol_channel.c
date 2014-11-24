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

#ifndef CYBOL_CHANNEL_CONSTANT_SOURCE
#define CYBOL_CHANNEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The display cybol channel. */
static wchar_t DISPLAY_CYBOL_CHANNEL_ARRAY[] = {L'd', L'i', L's', L'p', L'l', L'a', L'y'};
static wchar_t* DISPLAY_CYBOL_CHANNEL = DISPLAY_CYBOL_CHANNEL_ARRAY;
static int* DISPLAY_CYBOL_CHANNEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The file system cybol channel. */
static wchar_t FILE_SYSTEM_CYBOL_CHANNEL_ARRAY[] = {L'f', L'i', L'l', L'e'};
static wchar_t* FILE_SYSTEM_CYBOL_CHANNEL = FILE_SYSTEM_CYBOL_CHANNEL_ARRAY;
static int* FILE_SYSTEM_CYBOL_CHANNEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The inline cybol channel. */
static wchar_t INLINE_CYBOL_CHANNEL_ARRAY[] = {L'i', L'n', L'l', L'i', L'n', L'e'};
static wchar_t* INLINE_CYBOL_CHANNEL = INLINE_CYBOL_CHANNEL_ARRAY;
static int* INLINE_CYBOL_CHANNEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The serial-port cybol channel. */
static wchar_t SERIAL_PORT_CYBOL_CHANNEL_ARRAY[] = {L's', L'e', L'r', L'i', L'a', L'l', L'-', L'p', L'o', L'r', L't'};
static wchar_t* SERIAL_PORT_CYBOL_CHANNEL = SERIAL_PORT_CYBOL_CHANNEL_ARRAY;
static int* SERIAL_PORT_CYBOL_CHANNEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The signal cybol channel. */
static wchar_t SIGNAL_CYBOL_CHANNEL_ARRAY[] = {L's', L'i', L'g', L'n', L'a', L'l'};
static wchar_t* SIGNAL_CYBOL_CHANNEL = SIGNAL_CYBOL_CHANNEL_ARRAY;
static int* SIGNAL_CYBOL_CHANNEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The socket cybol channel. */
static wchar_t SOCKET_CYBOL_CHANNEL_ARRAY[] = {L's', L'o', L'c', L'k', L'e', L't'};
static wchar_t* SOCKET_CYBOL_CHANNEL = SOCKET_CYBOL_CHANNEL_ARRAY;
static int* SOCKET_CYBOL_CHANNEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The terminal cybol channel. */
static wchar_t TERMINAL_CYBOL_CHANNEL_ARRAY[] = {L't', L'e', L'r', L'm', L'i', L'n', L'a', L'l'};
static wchar_t* TERMINAL_CYBOL_CHANNEL = TERMINAL_CYBOL_CHANNEL_ARRAY;
static int* TERMINAL_CYBOL_CHANNEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CYBOL_CHANNEL_CONSTANT_SOURCE */
#endif
