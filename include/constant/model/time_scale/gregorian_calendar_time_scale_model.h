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

#ifndef GREGORIAN_CALENDAR_TIME_SCALE_MODEL_SOURCE
#define GREGORIAN_CALENDAR_TIME_SCALE_MODEL_SOURCE

//
// Library interface
//

#include "constant.h"

/** The year gregorian calendar time scale model. */
static int YEAR_GREGORIAN_CALENDAR_TIME_SCALE_MODEL_ARRAY[] = { 1582 };
static int* YEAR_GREGORIAN_CALENDAR_TIME_SCALE_MODEL = YEAR_GREGORIAN_CALENDAR_TIME_SCALE_MODEL_ARRAY;

/** The month gregorian calendar time scale model. */
static int MONTH_GREGORIAN_CALENDAR_TIME_SCALE_MODEL_ARRAY[] = { 10 };
static int* MONTH_GREGORIAN_CALENDAR_TIME_SCALE_MODEL = MONTH_GREGORIAN_CALENDAR_TIME_SCALE_MODEL_ARRAY;

/** The day gregorian calendar time scale model. */
static int DAY_GREGORIAN_CALENDAR_TIME_SCALE_MODEL_ARRAY[] = { 15 };
static int* DAY_GREGORIAN_CALENDAR_TIME_SCALE_MODEL = DAY_GREGORIAN_CALENDAR_TIME_SCALE_MODEL_ARRAY;

/* GREGORIAN_CALENDAR_TIME_SCALE_MODEL_SOURCE */
#endif
