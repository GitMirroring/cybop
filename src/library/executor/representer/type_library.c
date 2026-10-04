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

//
// boolean
//

#include "../../../executor/representer/deserialiser/boolean/boolean_deserialiser.c"
#include "../../../executor/representer/serialiser/boolean/boolean_serialiser.c"

//
// datetime
//

#include "../../../executor/representer/deserialiser/datetime/gregorian/gregorian_datetime_deserialiser.c"
#include "../../../executor/representer/deserialiser/datetime/jd/basic_jd_datetime_deserialiser.c"
#include "../../../executor/representer/deserialiser/datetime/jd/jd_datetime_deserialiser.c"
#include "../../../executor/representer/deserialiser/datetime/jd/mjd_datetime_deserialiser.c"
#include "../../../executor/representer/deserialiser/datetime/jd/tjd_datetime_deserialiser.c"
#include "../../../executor/representer/deserialiser/datetime/julian/julian_datetime_deserialiser.c"
#include "../../../executor/representer/deserialiser/datetime/posix/posix_datetime_deserialiser.c"
#include "../../../executor/representer/deserialiser/datetime/tai/tai_datetime_deserialiser.c"
#include "../../../executor/representer/deserialiser/datetime/ti/ti_datetime_deserialiser.c"
#include "../../../executor/representer/deserialiser/datetime/utc/utc_datetime_deserialiser.c"

#include "../../../executor/representer/serialiser/datetime/gregorian/gregorian_datetime_serialiser.c"
#include "../../../executor/representer/serialiser/datetime/jd/basic_jd_datetime_serialiser.c"
#include "../../../executor/representer/serialiser/datetime/jd/jd_datetime_serialiser.c"
#include "../../../executor/representer/serialiser/datetime/jd/mjd_datetime_serialiser.c"
#include "../../../executor/representer/serialiser/datetime/jd/tjd_datetime_serialiser.c"
#include "../../../executor/representer/serialiser/datetime/julian/julian_datetime_serialiser.c"
#include "../../../executor/representer/serialiser/datetime/posix/posix_datetime_serialiser.c"
#include "../../../executor/representer/serialiser/datetime/tai/tai_datetime_serialiser.c"
#include "../../../executor/representer/serialiser/datetime/ti/ti_datetime_serialiser.c"
#include "../../../executor/representer/serialiser/datetime/utc/utc_datetime_serialiser.c"

//
// duration
//

#include "../../../executor/representer/deserialiser/duration/iso/iso_duration_deserialiser.c"
#include "../../../executor/representer/deserialiser/duration/jd/jd_duration_deserialiser.c"
#include "../../../executor/representer/deserialiser/duration/julian/julian_duration_deserialiser.c"
#include "../../../executor/representer/deserialiser/duration/si/si_duration_deserialiser.c"

#include "../../../executor/representer/serialiser/duration/iso/iso_duration_serialiser.c"
#include "../../../executor/representer/serialiser/duration/jd/jd_duration_serialiser.c"
#include "../../../executor/representer/serialiser/duration/julian/julian_duration_serialiser.c"
#include "../../../executor/representer/serialiser/duration/si/si_duration_serialiser.c"

//
// numeral
//

#include "../../../executor/representer/deserialiser/numeral/allocation_numeral_deserialiser.c"
#include "../../../executor/representer/deserialiser/numeral/assembler/cartesian_complex_assembler_numeral_deserialiser.c"
#include "../../../executor/representer/deserialiser/numeral/assembler/decimal_fraction_assembler_numeral_deserialiser.c"
#include "../../../executor/representer/deserialiser/numeral/assembler/integer_assembler_numeral_deserialiser.c"
#include "../../../executor/representer/deserialiser/numeral/assembler/polar_complex_assembler_numeral_deserialiser.c"
#include "../../../executor/representer/deserialiser/numeral/assembler/vulgar_fraction_assembler_numeral_deserialiser.c"
#include "../../../executor/representer/deserialiser/numeral/decimals_numeral_deserialiser.c"
#include "../../../executor/representer/deserialiser/numeral/fraction_numeral_deserialiser.c"
#include "../../../executor/representer/deserialiser/numeral/integer_numeral_deserialiser.c"
#include "../../../executor/representer/deserialiser/numeral/null_numeral_deserialiser.c"
#include "../../../executor/representer/deserialiser/numeral/number_numeral_deserialiser.c"
#include "../../../executor/representer/deserialiser/numeral/numeral_deserialiser.c"
#include "../../../executor/representer/deserialiser/numeral/part_numeral_deserialiser.c"
#include "../../../executor/representer/deserialiser/numeral/power_numeral_deserialiser.c"
#include "../../../executor/representer/deserialiser/numeral/value_numeral_deserialiser.c"
#include "../../../executor/representer/deserialiser/numeral/verification_numeral_deserialiser.c"
#include "../../../executor/representer/deserialiser/numeral_vector/list_numeral_vector_deserialiser.c"
#include "../../../executor/representer/deserialiser/numeral_vector/numeral_vector_deserialiser.c"

#include "../../../executor/representer/serialiser/numeral/cartesian_complex_numeral_serialiser.c"
#include "../../../executor/representer/serialiser/numeral/decimal_fraction_numeral_serialiser.c"
#include "../../../executor/representer/serialiser/numeral/decimals_numeral_serialiser.c"
#include "../../../executor/representer/serialiser/numeral/integer_numeral_serialiser.c"
#include "../../../executor/representer/serialiser/numeral/numeral_serialiser.c"
#include "../../../executor/representer/serialiser/numeral/polar_complex_numeral_serialiser.c"
#include "../../../executor/representer/serialiser/numeral/prefix_numeral_serialiser.c"
#include "../../../executor/representer/serialiser/numeral/vulgar_fraction_numeral_serialiser.c"
#include "../../../executor/representer/serialiser/numeral_vector/list_numeral_vector_serialiser.c"
#include "../../../executor/representer/serialiser/numeral_vector/numeral_vector_serialiser.c"

#include "../../../executor/selector/numeral/assembler_numeral_selector.c"
#include "../../../executor/selector/numeral/base_numeral_selector.c"
#include "../../../executor/selector/numeral/sign_numeral_selector.c"
#include "../../../executor/selector/numeral/value_numeral_selector.c"

//
// time scale
//

#include "../../../executor/representer/deserialiser/time_scale/correction/detection_leap_year_correction_time_scale_deserialiser.c"
#include "../../../executor/representer/deserialiser/time_scale/correction/leap_year_correction_time_scale_deserialiser.c"
#include "../../../executor/representer/deserialiser/time_scale/correction/month_correction_time_scale_deserialiser.c"
//?? #include "../../../executor/representer/deserialiser/time_scale/gregorian_calendar/ALTERNATIVE_julian_day_gregorian_calendar_time_scale_deserialiser.c"
#include "../../../executor/representer/deserialiser/time_scale/gregorian_calendar/check_reform_julian_day_gregorian_calendar_time_scale_deserialiser.c"
#include "../../../executor/representer/deserialiser/time_scale/gregorian_calendar/gregorian_calendar_time_scale_deserialiser.c"
#include "../../../executor/representer/deserialiser/time_scale/gregorian_calendar/julian_day_gregorian_calendar_time_scale_deserialiser.c"
#include "../../../executor/representer/deserialiser/time_scale/gregorian_calendar/julian_second_gregorian_calendar_time_scale_deserialiser.c"
#include "../../../executor/representer/deserialiser/time_scale/gregorian_calendar/normalise_gregorian_calendar_time_scale_deserialiser.c"
#include "../../../executor/representer/deserialiser/time_scale/julian_calendar/julian_calendar_time_scale_deserialiser.c"
#include "../../../executor/representer/deserialiser/time_scale/julian_date/julian_date_time_scale_deserialiser.c"
#include "../../../executor/representer/deserialiser/time_scale/running_day/running_day_time_scale_deserialiser.c"

//?? #include "../../../executor/representer/serialiser/time_scale/gregorian_calendar/ALTERNATIVE_gregorian_calendar_time_scale_serialiser.c"
#include "../../../executor/representer/serialiser/time_scale/gregorian_calendar/correction_gregorian_calendar_time_scale_serialiser.c"
#include "../../../executor/representer/serialiser/time_scale/gregorian_calendar/gregorian_calendar_time_scale_serialiser.c"
#include "../../../executor/representer/serialiser/time_scale/gregorian_calendar/julian_day_gregorian_calendar_time_scale_serialiser.c"
#include "../../../executor/representer/serialiser/time_scale/gregorian_calendar/julian_second_gregorian_calendar_time_scale_serialiser.c"
#include "../../../executor/representer/serialiser/time_scale/julian_calendar/julian_calendar_time_scale_serialiser.c"
#include "../../../executor/representer/serialiser/time_scale/julian_date/julian_date_time_scale_serialiser.c"
#include "../../../executor/representer/serialiser/time_scale/running_day/day_running_day_time_scale_serialiser.c"
#include "../../../executor/representer/serialiser/time_scale/running_day/month_running_day_time_scale_serialiser.c"
#include "../../../executor/representer/serialiser/time_scale/running_day/running_day_time_scale_serialiser.c"
#include "../../../executor/representer/serialiser/time_scale/weekday/weekday_time_scale_serialiser.c"
