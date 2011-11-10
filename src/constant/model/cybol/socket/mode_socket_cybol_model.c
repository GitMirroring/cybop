/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MODE_SOCKET_CYBOL_MODEL_CONSTANT_SOURCE
#define MODE_SOCKET_CYBOL_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The client mode socket cybol model. */
static wchar_t CLIENT_MODE_SOCKET_CYBOL_MODEL_ARRAY[] = {L'c', L'l', L'i', L'e', L'n', L't'};
static wchar_t* CLIENT_MODE_SOCKET_CYBOL_MODEL = CLIENT_MODE_SOCKET_CYBOL_MODEL_ARRAY;
static int* CLIENT_MODE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The server mode socket cybol model. */
static wchar_t SERVER_MODE_SOCKET_CYBOL_MODEL_ARRAY[] = {L's', L'e', L'r', L'v', L'e', L'r'};
static wchar_t* SERVER_MODE_SOCKET_CYBOL_MODEL = SERVER_MODE_SOCKET_CYBOL_MODEL_ARRAY;
static int* SERVER_MODE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MODE_SOCKET_CYBOL_MODEL_CONSTANT_SOURCE */
#endif
