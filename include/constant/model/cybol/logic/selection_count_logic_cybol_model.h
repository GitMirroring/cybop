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

#ifndef SELECTION_COUNT_LOGIC_CYBOL_MODEL_CONSTANT_HEADER
#define SELECTION_COUNT_LOGIC_CYBOL_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The all selection count logic cybol model. */
static wchar_t* ALL_SELECTION_COUNT_LOGIC_CYBOL_MODEL = L"all";
static int* ALL_SELECTION_COUNT_LOGIC_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The prefix selection count logic cybol model. */
static wchar_t* PREFIX_SELECTION_COUNT_LOGIC_CYBOL_MODEL = L"prefix";
static int* PREFIX_SELECTION_COUNT_LOGIC_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The suffix selection count logic cybol model. */
static wchar_t* SUFFIX_SELECTION_COUNT_LOGIC_CYBOL_MODEL = L"suffix";
static int* SUFFIX_SELECTION_COUNT_LOGIC_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SELECTION_COUNT_LOGIC_CYBOL_MODEL_CONSTANT_HEADER */
#endif
