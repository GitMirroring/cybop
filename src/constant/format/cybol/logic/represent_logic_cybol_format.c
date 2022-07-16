/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef REPRESENT_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define REPRESENT_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Represent
//
// IANA media type: not defined
// Self-defined media type: represent
// This media type is a CYBOL extension.
//

/**
 * The represent/deserialise logic cybol format.
 *
 * Append data to other data.
 *
 * This is a CYBOL extension.
 */
static wchar_t* DESERIALISE_REPRESENT_LOGIC_CYBOL_FORMAT = L"represent/deserialise";
static int* DESERIALISE_REPRESENT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The represent/serialise logic cybol format.
 *
 * Append data to other data.
 *
 * This is a CYBOL extension.
 */
static wchar_t* SERIALISE_REPRESENT_LOGIC_CYBOL_FORMAT = L"represent/serialise";
static int* SERIALISE_REPRESENT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* REPRESENT_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
