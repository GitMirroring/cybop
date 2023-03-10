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

#ifndef LOG_LEVEL_OPTION_CYBOI_MODEL_CONSTANT_HEADER
#define LOG_LEVEL_OPTION_CYBOI_MODEL_CONSTANT_HEADER

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.h"

/** The "off" log level option cyboi model. */
static wchar_t* OFF_LOG_LEVEL_OPTION_CYBOI_MODEL = L"off";
static int* OFF_LOG_LEVEL_OPTION_CYBOI_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "error" log level option cyboi model. */
static wchar_t* ERROR_LOG_LEVEL_OPTION_CYBOI_MODEL = L"error";
static int* ERROR_LOG_LEVEL_OPTION_CYBOI_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "warning" log level option cyboi model. */
static wchar_t* WARNING_LOG_LEVEL_OPTION_CYBOI_MODEL = L"warning";
static int* WARNING_LOG_LEVEL_OPTION_CYBOI_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "information" log level option cyboi model. */
static wchar_t* INFORMATION_LOG_LEVEL_OPTION_CYBOI_MODEL = L"information";
static int* INFORMATION_LOG_LEVEL_OPTION_CYBOI_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The "debug" log level option cyboi model. */
static wchar_t* DEBUG_LOG_LEVEL_OPTION_CYBOI_MODEL = L"debug";
static int* DEBUG_LOG_LEVEL_OPTION_CYBOI_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LOG_LEVEL_OPTION_CYBOI_MODEL_CONSTANT_HEADER */
#endif
