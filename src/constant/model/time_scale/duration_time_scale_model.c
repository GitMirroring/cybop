/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DURATION_TIME_SCALE_MODEL_SOURCE
#define DURATION_TIME_SCALE_MODEL_SOURCE

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Solar seconds.
//

/**
 * The solar day in seconds datetime state cyboi model.
 *
 * 1 solar day = 24 h * 60 min * 60 s = 86400 s
 */
static int DAY_SOLAR_DURATION_TIME_SCALE_MODEL_ARRAY[] = {86400};
static int* DAY_SOLAR_DURATION_TIME_SCALE_MODEL = DAY_SOLAR_DURATION_TIME_SCALE_MODEL_ARRAY;

/**
 * The solar hour in seconds datetime state cyboi model.
 *
 * 1 solar hour = 60 min * 60 s = 3600 s
 */
static int HOUR_SOLAR_DURATION_TIME_SCALE_MODEL_ARRAY[] = {3600};
static int* HOUR_SOLAR_DURATION_TIME_SCALE_MODEL = HOUR_SOLAR_DURATION_TIME_SCALE_MODEL_ARRAY;

/**
 * The solar minute in seconds datetime state cyboi model.
 *
 * 1 solar minute = 60 s
 */
static int MINUTE_SOLAR_DURATION_TIME_SCALE_MODEL_ARRAY[] = {60};
static int* MINUTE_SOLAR_DURATION_TIME_SCALE_MODEL = MINUTE_SOLAR_DURATION_TIME_SCALE_MODEL_ARRAY;

/**
 * The solar second in seconds datetime state cyboi model.
 *
 * 1 solar second = 1 s
 */
static int SECOND_SOLAR_DURATION_TIME_SCALE_MODEL_ARRAY[] = {1};
static int* SECOND_SOLAR_DURATION_TIME_SCALE_MODEL = SECOND_SOLAR_DURATION_TIME_SCALE_MODEL_ARRAY;

/* DURATION_TIME_SCALE_MODEL_SOURCE */
#endif
