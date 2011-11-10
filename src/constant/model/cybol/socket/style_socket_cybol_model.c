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

#ifndef STYLE_SOCKET_CYBOL_MODEL_CONSTANT_SOURCE
#define STYLE_SOCKET_CYBOL_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/memory/integer_memory_model.c"

/** The stream style socket cybol model. */
static wchar_t STREAM_STYLE_SOCKET_CYBOL_MODEL_ARRAY[] = {L's', L't', L'r', L'e', L'a', L'm'};
static wchar_t* STREAM_STYLE_SOCKET_CYBOL_MODEL = STREAM_STYLE_SOCKET_CYBOL_MODEL_ARRAY;
static int* STREAM_STYLE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The datagram style socket cybol model. */
static wchar_t DATAGRAM_STYLE_SOCKET_CYBOL_MODEL_ARRAY[] = {L'd', L'a', L't', L'a', L'g', L'r', L'a', L'm'};
static wchar_t* DATAGRAM_STYLE_SOCKET_CYBOL_MODEL = DATAGRAM_STYLE_SOCKET_CYBOL_MODEL_ARRAY;
static int* DATAGRAM_STYLE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The raw style socket cybol model. */
static wchar_t RAW_STYLE_SOCKET_CYBOL_MODEL_ARRAY[] = {L'r', L'a', L'w'};
static wchar_t* RAW_STYLE_SOCKET_CYBOL_MODEL = RAW_STYLE_SOCKET_CYBOL_MODEL_ARRAY;
static int* RAW_STYLE_SOCKET_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/* STYLE_SOCKET_CYBOL_MODEL_CONSTANT_SOURCE */
#endif
