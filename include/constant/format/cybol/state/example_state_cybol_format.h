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
 * @author Franziska Wehner
 */

#ifndef EXAMPLE_STATE_CYBOL_FORMAT_CONSTANT_HEADER
#define EXAMPLE_STATE_CYBOL_FORMAT_CONSTANT_HEADER

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Example
//
// IANA media type: example
//

/**
 * The example state cybol format.
 *
 * This is just offered by IANA for testing reasons.
 */
static wchar_t* EXAMPLE_STATE_CYBOL_FORMAT = L"example";
static int* EXAMPLE_STATE_CYBOL_FORMAT_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* EXAMPLE_STATE_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
