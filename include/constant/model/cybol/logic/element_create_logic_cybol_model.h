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

#ifndef ELEMENT_CREATE_LOGIC_CYBOL_MODEL_CONSTANT_HEADER
#define ELEMENT_CREATE_LOGIC_CYBOL_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The part element create logic cybol model. */
static wchar_t* PART_ELEMENT_CREATE_LOGIC_CYBOL_MODEL = L"part";
static int* PART_ELEMENT_CREATE_LOGIC_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The property element create logic cybol model. */
static wchar_t* PROPERTY_ELEMENT_CREATE_LOGIC_CYBOL_MODEL = L"property";
static int* PROPERTY_ELEMENT_CREATE_LOGIC_CYBOL_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ELEMENT_CREATE_LOGIC_CYBOL_MODEL_CONSTANT_HEADER */
#endif
