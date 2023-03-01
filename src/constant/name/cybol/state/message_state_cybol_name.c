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

#ifndef MESSAGE_STATE_CYBOL_NAME_CONSTANT_SOURCE
#define MESSAGE_STATE_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// These name constants are to be used as constraint for the cybol
// property "message" with one of the following cybol operations:
//
// - communicate/send
// - communicate/receive
// - represent/serialise
// - represent/deserialise
//

/**
 * The header message state cybol name.
 *
 * Used with character (comma) separated values (csv).
 * Specifies a compound PART that contains the header data,
 * to be found as first line in a csv file.
 */
static wchar_t* HEADER_MESSAGE_STATE_CYBOL_NAME = L"header";
static int* HEADER_MESSAGE_STATE_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MESSAGE_STATE_CYBOL_NAME_CONSTANT_SOURCE */
#endif
