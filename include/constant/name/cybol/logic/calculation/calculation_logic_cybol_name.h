/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CALCULATION_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define CALCULATION_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The result calculation logic cybol name. */
static wchar_t* RESULT_CALCULATION_LOGIC_CYBOL_NAME = L"result";
static int* RESULT_CALCULATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The operand calculation logic cybol name. */
static wchar_t* OPERAND_CALCULATION_LOGIC_CYBOL_NAME = L"operand";
static int* OPERAND_CALCULATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The count calculation logic cybol name. */
static wchar_t* COUNT_CALCULATION_LOGIC_CYBOL_NAME = L"count";
static int* COUNT_CALCULATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The result index calculation logic cybol name. */
static wchar_t* RESULT_INDEX_CALCULATION_LOGIC_CYBOL_NAME = L"result_index";
static int* RESULT_INDEX_CALCULATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The operand index calculation logic cybol name. */
static wchar_t* OPERAND_INDEX_CALCULATION_LOGIC_CYBOL_NAME = L"operand_index";
static int* OPERAND_INDEX_CALCULATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CALCULATION_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
