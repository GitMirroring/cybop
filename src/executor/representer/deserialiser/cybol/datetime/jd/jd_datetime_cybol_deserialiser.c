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

#ifndef JD_DATETIME_CYBOL_DESERIALISER_SOURCE
#define JD_DATETIME_CYBOL_DESERIALISER_SOURCE

#include <math.h>

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/datetime_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../../constant/name/cyboi/state/datetime_state_cyboi_name.c"
#include "../../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../../executor/calculator/basic/double/multiply_double_calculator.c"
#include "../../../../../../executor/calculator/basic/double/subtract_double_calculator.c"
#include "../../../../../../executor/caster/basic/integer/double_integer_caster.c"
#include "../../../../../../executor/modifier/copier/double_copier.c"
#include "../../../../../../executor/representer/deserialiser/cybol/decimal_fraction/primitive_value_decimal_fraction_cybol_deserialiser.c"
#include "../../../../../../logger/logger.c"

/**
 * Deserialises the julian date (jd) wide character data into a datetime model.
 *
 * @param p0 the destination model item
 * @param p1 the source data
 * @param p2 the source count
 */
void deserialise_cybol_datetime_jd(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol datetime jd.");

    // The destination julian day, julian second.
    void* djd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* djs = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination julian day as double.
    double djdd = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The source julian date data.
    double sd = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Get destination julian day, julian second.
    copy_array_forward((void*) &djd, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    copy_array_forward((void*) &djs, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);
    // Get source julian date data.
    deserialise_cybol_decimal_fraction_value_primitive((void*) &sd, p1, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

    // Extract integer part of source julian date data,
    // by rounding downwards to the nearest integer.
    // The result, however, is of type "double".
    //
    // Example:
    // floor (1.5) is 1.0 and floor (-1.5) is -2.0
    djdd = floor(sd);
    // Cast julian day into an integer number.
    cast_integer_double(djd, (void*) &djdd);

    // Initialise destination julian second with source julian date data.
    copy_double(djs, (void*) &sd);
    // Extract fractional part of source, by
    // subtracting the julian day integer part.
    calculate_double_subtract(djs, (void*) &djdd);
    // Normalise fractional part of source
    // to duration of day in solar seconds.
    calculate_double_multiply(djs, (void*) SOLAR_DAY_IN_SECONDS_DATETIME_STATE_CYBOI_MODEL);
}

/* JD_DATETIME_CYBOL_DESERIALISER_SOURCE */
#endif
