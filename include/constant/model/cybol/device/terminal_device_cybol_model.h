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

#ifndef TERMINAL_DEVICE_CYBOL_MODEL_CONSTANT_HEADER
#define TERMINAL_DEVICE_CYBOL_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The standard_error_output terminal device cybol model. */
static wchar_t* STANDARD_ERROR_OUTPUT_TERMINAL_DEVICE_CYBOL_MODEL = L"standard-error-output";
static int* STANDARD_ERROR_OUTPUT_TERMINAL_DEVICE_CYBOL_MODEL_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The standard_input terminal device cybol model. */
static wchar_t* STANDARD_INPUT_TERMINAL_DEVICE_CYBOL_MODEL = L"standard-input";
static int* STANDARD_INPUT_TERMINAL_DEVICE_CYBOL_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The standard_output terminal device cybol model. */
static wchar_t* STANDARD_OUTPUT_TERMINAL_DEVICE_CYBOL_MODEL = L"standard-output";
static int* STANDARD_OUTPUT_TERMINAL_DEVICE_CYBOL_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TERMINAL_DEVICE_CYBOL_MODEL_CONSTANT_HEADER */
#endif
