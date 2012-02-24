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

#ifndef ARITHMETIC_OPERATION_CYBOL_NAME_CONSTANT_SOURCE
#define ARITHMETIC_OPERATION_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The result arithmetic operation cybol name. */
static wchar_t RESULT_ARITHMETIC_OPERATION_CYBOL_NAME_ARRAY[] = {L'r', L'e', L's', L'u', L'l', L't'};
static wchar_t* RESULT_ARITHMETIC_OPERATION_CYBOL_NAME = RESULT_ARITHMETIC_OPERATION_CYBOL_NAME_ARRAY;
static int* RESULT_ARITHMETIC_OPERATION_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The operand 1 arithmetic operation cybol name. */
static wchar_t OPERAND_1_ARITHMETIC_OPERATION_CYBOL_NAME_ARRAY[] = {L'o', L'p', L'e', L'r', L'a', L'n', L'd', L'_', L'1'};
static wchar_t* OPERAND_1_ARITHMETIC_OPERATION_CYBOL_NAME = OPERAND_1_ARITHMETIC_OPERATION_CYBOL_NAME_ARRAY;
static int* OPERAND_1_ARITHMETIC_OPERATION_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The operand 2 arithmetic operation cybol name. */
static wchar_t OPERAND_2_ARITHMETIC_OPERATION_CYBOL_NAME_ARRAY[] = {L'o', L'p', L'e', L'r', L'a', L'n', L'd', L'_', L'2'};
static wchar_t* OPERAND_2_ARITHMETIC_OPERATION_CYBOL_NAME = OPERAND_2_ARITHMETIC_OPERATION_CYBOL_NAME_ARRAY;
static int* OPERAND_2_ARITHMETIC_OPERATION_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The type arithmetic operation cybol name. */
static wchar_t TYPE_ARITHMETIC_OPERATION_CYBOL_NAME_ARRAY[] = {L't', L'y', L'p', L'e'};
static wchar_t* TYPE_ARITHMETIC_OPERATION_CYBOL_NAME = TYPE_ARITHMETIC_OPERATION_CYBOL_NAME_ARRAY;
static int* TYPE_ARITHMETIC_OPERATION_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ARITHMETIC_OPERATION_CYBOL_NAME_CONSTANT_SOURCE */
#endif
