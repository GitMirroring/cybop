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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef JULIAN_DATE_TIME_SCALE_MODEL_SOURCE
#define JULIAN_DATE_TIME_SCALE_MODEL_SOURCE

//
// Library interface
//

#include "constant.h"

/** The julian date (jd) time scale model. */
static double JULIAN_DATE_TIME_SCALE_MODEL_ARRAY[] = { 0.0 };
static double* JULIAN_DATE_TIME_SCALE_MODEL = JULIAN_DATE_TIME_SCALE_MODEL_ARRAY;

/** The modified julian date (mjd) time scale model. */
static double MODIFIED_JULIAN_DATE_TIME_SCALE_MODEL_ARRAY[] = { 2400000.5 };
static double* MODIFIED_JULIAN_DATE_TIME_SCALE_MODEL = MODIFIED_JULIAN_DATE_TIME_SCALE_MODEL_ARRAY;

/** The truncated julian date (tjd) time scale model. */
static double TRUNCATED_JULIAN_DATE_TIME_SCALE_MODEL_ARRAY[] = { 2440000.5 };
static double* TRUNCATED_JULIAN_DATE_TIME_SCALE_MODEL = TRUNCATED_JULIAN_DATE_TIME_SCALE_MODEL_ARRAY;

/** The day 0 julian date time scale model. */
static int DAY_0_JULIAN_DATE_TIME_SCALE_MODEL_ARRAY[] = { 1721426 };
static int* DAY_0_JULIAN_DATE_TIME_SCALE_MODEL = DAY_0_JULIAN_DATE_TIME_SCALE_MODEL_ARRAY;

/* JULIAN_DATE_TIME_SCALE_MODEL_SOURCE */
#endif
