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

#ifndef JD_DATETIME_CYBOL_SERIALISER_SOURCE
#define JD_DATETIME_CYBOL_SERIALISER_SOURCE

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/datetime_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/name/cyboi/state/datetime_state_cyboi_name.c"
#include "../../../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../../executor/accessor/getter/datetime_getter.c"
#include "../../../../../../executor/calculator/basic/double/add_double_calculator.c"
#include "../../../../../../executor/calculator/basic/double/divide_double_calculator.c"
#include "../../../../../../executor/caster/basic/double/integer_double_caster.c"
#include "../../../../../../executor/modifier/copier/double_copier.c"
#include "../../../../../../executor/representer/serialiser/cybol/decimal_fraction/value_decimal_fraction_cybol_serialiser.c"
#include "../../../../../../logger/logger.c"

/**
 * Serialises the source datetime model into the destination julian date (jd).
 *
 * @param p0 the destination model item
 * @param p1 the source data
 * @param p2 the source count
 */
void serialise_cybol_datetime_jd(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cybol datetime jd.");

    // The destination julian date.
    double djd = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The source julian day, julian second.
    void* sjd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sjs = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source julian day as double.
    double sjdd = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Get source julian day, julian second.
    get_datetime_element((void*) &sjd, (void*) &p1, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    get_datetime_element((void*) &sjs, (void*) &p1, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);

    // Initialise destination julian date with source julian second.
    copy_double((void*) &djd, sjs);
fwprintf(stdout, L"TEST serialise cybol datetime jd djd init: %f\n", djd);
    // Denormalise fractional part
    // from duration of day in solar seconds.
    calculate_double_divide((void*) &djd, (void*) SOLAR_DAY_IN_SECONDS_DATETIME_STATE_CYBOI_MODEL);
fwprintf(stdout, L"TEST serialise cybol datetime jd djd divide: %f\n", djd);
    // Cast julian day into a double number.
    cast_double_integer((void*) &sjdd, sjd);
fwprintf(stdout, L"TEST serialise cybol datetime jd sjdd cast: %f\n", sjdd);
    // Add source julian day integer part.
    calculate_double_add((void*) &djd, (void*) &sjdd);
fwprintf(stdout, L"TEST serialise cybol datetime jd djd add: %f\n", djd);

    // Assign resulting julian date to destination.
    serialise_cybol_fraction_decimal_value(p0, (void*) &djd, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
fwprintf(stdout, L"TEST serialise cybol datetime jd djd serialise to wchar_t: %ls\n", (wchar_t*) *((void**) p0));
}

/* JD_DATETIME_CYBOL_SERIALISER_SOURCE */
#endif
