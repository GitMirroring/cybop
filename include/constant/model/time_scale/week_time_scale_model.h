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

#ifndef WEEK_TIME_SCALE_MODEL_SOURCE
#define WEEK_TIME_SCALE_MODEL_SOURCE

//
// Library interface
//

#include "constant.h"

/**
 * The day count week time scale model.
 *
 * 1 week = 7 days
 */
static int DAY_COUNT_WEEK_TIME_SCALE_MODEL_ARRAY[] = { 7 };
static int* DAY_COUNT_WEEK_TIME_SCALE_MODEL = DAY_COUNT_WEEK_TIME_SCALE_MODEL_ARRAY;

/** The day correction week time scale model. */
static double DAY_CORRECTION_WEEK_TIME_SCALE_MODEL_ARRAY[] = { 1.5 };
static double* DAY_CORRECTION_WEEK_TIME_SCALE_MODEL = DAY_CORRECTION_WEEK_TIME_SCALE_MODEL_ARRAY;

/* WEEK_TIME_SCALE_MODEL_SOURCE */
#endif
