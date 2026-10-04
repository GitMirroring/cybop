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

#ifndef LEVEL_NAME_LOG_CYBOI_MODEL_CONSTANT_HEADER
#define LEVEL_NAME_LOG_CYBOI_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The debug level name log cyboi model. */
static wchar_t* DEBUG_LEVEL_NAME_LOG_CYBOI_MODEL = L"Debug";
static int* DEBUG_LEVEL_NAME_LOG_CYBOI_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The error level name log cyboi model. */
static wchar_t* ERROR_LEVEL_NAME_LOG_CYBOI_MODEL = L"Error";
static int* ERROR_LEVEL_NAME_LOG_CYBOI_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The information level name log cyboi model. */
static wchar_t* INFORMATION_LEVEL_NAME_LOG_CYBOI_MODEL = L"Information";
static int* INFORMATION_LEVEL_NAME_LOG_CYBOI_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The undefined level name log cyboi model. */
static wchar_t* UNDEFINED_LEVEL_NAME_LOG_CYBOI_MODEL = L"Undefined";
static int* UNDEFINED_LEVEL_NAME_LOG_CYBOI_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The warning level name log cyboi model. */
static wchar_t* WARNING_LEVEL_NAME_LOG_CYBOI_MODEL = L"Warning";
static int* WARNING_LEVEL_NAME_LOG_CYBOI_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LEVEL_NAME_LOG_CYBOI_MODEL_CONSTANT_HEADER */
#endif
