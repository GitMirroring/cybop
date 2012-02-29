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

#ifndef SELECTION_COUNT_LOGIC_CYBOL_MODEL_CONSTANT_SOURCE
#define SELECTION_COUNT_LOGIC_CYBOL_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The all selection count logic cybol model. */
static wchar_t ALL_SELECTION_COUNT_LOGIC_CYBOL_MODEL_ARRAY[] = {L'a', L'l', L'l'};
static wchar_t* ALL_SELECTION_COUNT_LOGIC_CYBOL_MODEL = ALL_SELECTION_COUNT_LOGIC_CYBOL_MODEL_ARRAY;
static int* ALL_SELECTION_COUNT_LOGIC_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The prefix selection count logic cybol model. */
static wchar_t PREFIX_SELECTION_COUNT_LOGIC_CYBOL_MODEL_ARRAY[] = {L'p', L'r', L'e', L'f', L'i', L'x'};
static wchar_t* PREFIX_SELECTION_COUNT_LOGIC_CYBOL_MODEL = PREFIX_SELECTION_COUNT_LOGIC_CYBOL_MODEL_ARRAY;
static int* PREFIX_SELECTION_COUNT_LOGIC_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The suffix selection count logic cybol model. */
static wchar_t SUFFIX_SELECTION_COUNT_LOGIC_CYBOL_MODEL_ARRAY[] = {L's', L'u', L'f', L'f', L'i', L'x'};
static wchar_t* SUFFIX_SELECTION_COUNT_LOGIC_CYBOL_MODEL = SUFFIX_SELECTION_COUNT_LOGIC_CYBOL_MODEL_ARRAY;
static int* SUFFIX_SELECTION_COUNT_LOGIC_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SELECTION_COUNT_LOGIC_CYBOL_MODEL_CONSTANT_SOURCE */
#endif
