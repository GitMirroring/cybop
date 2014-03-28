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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CALCULATION_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define CALCULATION_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The result calculation logic cybol name. */
static wchar_t RESULT_CALCULATION_LOGIC_CYBOL_NAME_ARRAY[] = {L'r', L'e', L's', L'u', L'l', L't'};
static wchar_t* RESULT_CALCULATION_LOGIC_CYBOL_NAME = RESULT_CALCULATION_LOGIC_CYBOL_NAME_ARRAY;
static int* RESULT_CALCULATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The operand calculation logic cybol name. */
static wchar_t OPERAND_CALCULATION_LOGIC_CYBOL_NAME_ARRAY[] = {L'o', L'p', L'e', L'r', L'a', L'n', L'd'};
static wchar_t* OPERAND_CALCULATION_LOGIC_CYBOL_NAME = OPERAND_CALCULATION_LOGIC_CYBOL_NAME_ARRAY;
static int* OPERAND_CALCULATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The type calculation logic cybol name. */
static wchar_t TYPE_CALCULATION_LOGIC_CYBOL_NAME_ARRAY[] = {L't', L'y', L'p', L'e'};
static wchar_t* TYPE_CALCULATION_LOGIC_CYBOL_NAME = TYPE_CALCULATION_LOGIC_CYBOL_NAME_ARRAY;
static int* TYPE_CALCULATION_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CALCULATION_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif
