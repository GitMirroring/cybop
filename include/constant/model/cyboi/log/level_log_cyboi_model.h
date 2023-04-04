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

#ifndef LEVEL_LOG_CYBOI_MODEL_CONSTANT_HEADER
#define LEVEL_LOG_CYBOI_MODEL_CONSTANT_HEADER

//
// Library interface
//

#include "constant.h"

/** The off level log cyboi model. */
static int* OFF_LEVEL_LOG_CYBOI_MODEL = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The error level log cyboi model. */
static int* ERROR_LEVEL_LOG_CYBOI_MODEL = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The warning level log cyboi model. */
static int* WARNING_LEVEL_LOG_CYBOI_MODEL = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The info level log cyboi model. */
static int* INFORMATION_LEVEL_LOG_CYBOI_MODEL = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The debug level log cyboi model. */
static int* DEBUG_LEVEL_LOG_CYBOI_MODEL = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LEVEL_LOG_CYBOI_MODEL_CONSTANT_HEADER */
#endif
