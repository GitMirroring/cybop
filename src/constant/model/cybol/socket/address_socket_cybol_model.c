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

#ifndef ADDRESS_SOCKET_CYBOL_MODEL_CONSTANT_SOURCE
#define ADDRESS_SOCKET_CYBOL_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The any address socket cybol model. */
static wchar_t ANY_ADDRESS_SOCKET_CYBOL_MODEL_ARRAY[] = {L'a', L'n', L'y'};
static wchar_t* ANY_ADDRESS_SOCKET_CYBOL_MODEL = ANY_ADDRESS_SOCKET_CYBOL_MODEL_ARRAY;
static int* ANY_ADDRESS_SOCKET_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The loopback address socket cybol model. */
static wchar_t LOOPBACK_ADDRESS_SOCKET_CYBOL_MODEL_ARRAY[] = {L'l', L'o', L'o', L'p', L'b', L'a', L'c', L'k'};
static wchar_t* LOOPBACK_ADDRESS_SOCKET_CYBOL_MODEL = LOOPBACK_ADDRESS_SOCKET_CYBOL_MODEL_ARRAY;
static int* LOOPBACK_ADDRESS_SOCKET_CYBOL_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ADDRESS_SOCKET_CYBOL_MODEL_CONSTANT_SOURCE */
#endif
