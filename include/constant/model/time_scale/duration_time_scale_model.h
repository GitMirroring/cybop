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

#ifndef DURATION_TIME_SCALE_MODEL_SOURCE
#define DURATION_TIME_SCALE_MODEL_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Solar units.
//

/**
 * The solar day in seconds duration time scale model.
 *
 * 1 solar day = 24 h * 60 min * 60 s = 86400 s
 */
static double DAY_SOLAR_DURATION_TIME_SCALE_MODEL_ARRAY[] = { 86400.0 };
static double* DAY_SOLAR_DURATION_TIME_SCALE_MODEL = DAY_SOLAR_DURATION_TIME_SCALE_MODEL_ARRAY;

/**
 * The solar hour in seconds duration time scale model.
 *
 * 1 solar hour = 60 min * 60 s = 3600 s
 */
static double HOUR_SOLAR_DURATION_TIME_SCALE_MODEL_ARRAY[] = { 3600.0 };
static double* HOUR_SOLAR_DURATION_TIME_SCALE_MODEL = HOUR_SOLAR_DURATION_TIME_SCALE_MODEL_ARRAY;

/**
 * The solar minute in seconds duration time scale model.
 *
 * 1 solar minute = 60 s
 */
static double MINUTE_SOLAR_DURATION_TIME_SCALE_MODEL_ARRAY[] = { 60.0 };
static double* MINUTE_SOLAR_DURATION_TIME_SCALE_MODEL = MINUTE_SOLAR_DURATION_TIME_SCALE_MODEL_ARRAY;

/**
 * The solar second in seconds duration time scale model.
 *
 * 1 solar second = 1 s
 */
static double SECOND_SOLAR_DURATION_TIME_SCALE_MODEL_ARRAY[] = { 1.0 };
static double* SECOND_SOLAR_DURATION_TIME_SCALE_MODEL = SECOND_SOLAR_DURATION_TIME_SCALE_MODEL_ARRAY;

//
// Gregorian units.
//

/** The gregorian year in days duration time scale model. */
static double YEAR_GREGORIAN_DURATION_TIME_SCALE_MODEL_ARRAY[] = { 365.25 };
static double* YEAR_GREGORIAN_DURATION_TIME_SCALE_MODEL = YEAR_GREGORIAN_DURATION_TIME_SCALE_MODEL_ARRAY;

/** The gregorian century in days duration time scale model. */
static double CENTURY_GREGORIAN_DURATION_TIME_SCALE_MODEL_ARRAY[] = { 36524.25 };
static double* CENTURY_GREGORIAN_DURATION_TIME_SCALE_MODEL = CENTURY_GREGORIAN_DURATION_TIME_SCALE_MODEL_ARRAY;

//
// Julian units.
//

/** The julian year in days duration time scale model. */
static double YEAR_JULIAN_DURATION_TIME_SCALE_MODEL_ARRAY[] = { 365.25 };
static double* YEAR_JULIAN_DURATION_TIME_SCALE_MODEL = YEAR_JULIAN_DURATION_TIME_SCALE_MODEL_ARRAY;

/** The julian century in days duration time scale model. */
static double CENTURY_JULIAN_DURATION_TIME_SCALE_MODEL_ARRAY[] = { 36525.0 };
static double* CENTURY_JULIAN_DURATION_TIME_SCALE_MODEL = CENTURY_JULIAN_DURATION_TIME_SCALE_MODEL_ARRAY;

/* DURATION_TIME_SCALE_MODEL_SOURCE */
#endif
