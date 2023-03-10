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

#ifndef BORDER_CYBOL_MODEL_CONSTANT_HEADER
#define BORDER_CYBOL_MODEL_CONSTANT_HEADER

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The ascii line border cybol model. */
static wchar_t* ASCII_LINE_BORDER_CYBOL_MODEL = L"ascii";
static int* ASCII_LINE_BORDER_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The double line border cybol model. */
static wchar_t* DOUBLE_LINE_BORDER_CYBOL_MODEL = L"double";
static int* DOUBLE_LINE_BORDER_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The round line border cybol model. */
static wchar_t* ROUND_LINE_BORDER_CYBOL_MODEL = L"round";
static int* ROUND_LINE_BORDER_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The simple line border cybol model. */
static wchar_t* SIMPLE_LINE_BORDER_CYBOL_MODEL = L"simple";
static int* SIMPLE_LINE_BORDER_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* BORDER_CYBOL_MODEL_CONSTANT_HEADER */
#endif
