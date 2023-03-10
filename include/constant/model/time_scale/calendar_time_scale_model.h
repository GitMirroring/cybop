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

#ifndef CALENDAR_TIME_SCALE_MODEL_SOURCE
#define CALENDAR_TIME_SCALE_MODEL_SOURCE

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// The cycle in days.
//

/**
 * The cycle 1 in days calendar time scale model.
 *
 * The 1-year-cycle constant is calculated as:
 *
 * = 365
 */
static int CYCLE_1_DAY_CALENDAR_TIME_SCALE_MODEL_ARRAY[] = { 365 };
static int* CYCLE_1_DAY_CALENDAR_TIME_SCALE_MODEL = CYCLE_1_DAY_CALENDAR_TIME_SCALE_MODEL_ARRAY;

/**
 * The cycle 4 in days calendar time scale model.
 *
 * The 4-year-cycle constant is calculated as:
 *
 * = 3 * (*CYCLE_1_DAY_CALENDAR_TIME_SCALE_MODEL) + 366
 * = 3 * 365 + 366
 * = 1461
 */
static int CYCLE_4_DAY_CALENDAR_TIME_SCALE_MODEL_ARRAY[] = { 1461 };
static int* CYCLE_4_DAY_CALENDAR_TIME_SCALE_MODEL = CYCLE_4_DAY_CALENDAR_TIME_SCALE_MODEL_ARRAY;

/**
 * The cycle 100 in days calendar time scale model.
 *
 * The 100-year-cycle constant is calculated as:
 *
 * = 24 * (*CYCLE_4_DAY_CALENDAR_TIME_SCALE_MODEL) + 1460
 * = 24 * 1461 + 1460
 * = 36524
 */
static int CYCLE_100_DAY_CALENDAR_TIME_SCALE_MODEL_ARRAY[] = { 36524 };
static int* CYCLE_100_DAY_CALENDAR_TIME_SCALE_MODEL = CYCLE_100_DAY_CALENDAR_TIME_SCALE_MODEL_ARRAY;

/**
 * The cycle 400 in days calendar time scale model.
 *
 * The 400-year-cycle constant is calculated as:
 *
 * = 3 * (*CYCLE_100_DAY_CALENDAR_TIME_SCALE_MODEL) + 36525
 * = 3 * 36524 + 36525
 * = 146097
 */
static int CYCLE_400_DAY_CALENDAR_TIME_SCALE_MODEL_ARRAY[] = { 146097 };
static int* CYCLE_400_DAY_CALENDAR_TIME_SCALE_MODEL = CYCLE_400_DAY_CALENDAR_TIME_SCALE_MODEL_ARRAY;

//
// The cycle in years.
//

/**
 * The cycle 1 in years calendar time scale model.
 */
static int CYCLE_1_YEAR_CALENDAR_TIME_SCALE_MODEL_ARRAY[] = { 1 };
static int* CYCLE_1_YEAR_CALENDAR_TIME_SCALE_MODEL = CYCLE_1_YEAR_CALENDAR_TIME_SCALE_MODEL_ARRAY;

/**
 * The cycle 4 in years calendar time scale model.
 */
static int CYCLE_4_YEAR_CALENDAR_TIME_SCALE_MODEL_ARRAY[] = { 4 };
static int* CYCLE_4_YEAR_CALENDAR_TIME_SCALE_MODEL = CYCLE_4_YEAR_CALENDAR_TIME_SCALE_MODEL_ARRAY;

/**
 * The cycle 100 in years calendar time scale model.
 */
static int CYCLE_100_YEAR_CALENDAR_TIME_SCALE_MODEL_ARRAY[] = { 100 };
static int* CYCLE_100_YEAR_CALENDAR_TIME_SCALE_MODEL = CYCLE_100_YEAR_CALENDAR_TIME_SCALE_MODEL_ARRAY;

/**
 * The cycle 400 in years calendar time scale model.
 */
static int CYCLE_400_YEAR_CALENDAR_TIME_SCALE_MODEL_ARRAY[] = { 400 };
static int* CYCLE_400_YEAR_CALENDAR_TIME_SCALE_MODEL = CYCLE_400_YEAR_CALENDAR_TIME_SCALE_MODEL_ARRAY;

/* CALENDAR_TIME_SCALE_MODEL_SOURCE */
#endif
