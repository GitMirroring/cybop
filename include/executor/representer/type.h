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

#ifndef TYPE_HEADER
#define TYPE_HEADER

//
// CAUTION! The following header files are included here so that
// it gets easier for other source files to use them by just
// including this ONE file instead of many.
//

//
// model
//

#include "constant/model/cybol/state/boolean_state_cybol_model.h"
#include "constant/model/cybol/state/empty_state_cybol_model.h"

#include "constant/model/numeral/base_numeral_model.h"

#include "constant/model/time_scale/astronomy_time_scale_model.h"
#include "constant/model/time_scale/calendar_time_scale_model.h"
#include "constant/model/time_scale/duration_time_scale_model.h"
#include "constant/model/time_scale/gregorian_calendar_time_scale_model.h"
#include "constant/model/time_scale/julian_date_time_scale_model.h"
#include "constant/model/time_scale/week_time_scale_model.h"

//
// name
//

#include "constant/name/numeral/base_numeral_name.h"
#include "constant/name/numeral/decimal_numeral_name.h"
#include "constant/name/numeral/exponent_numeral_name.h"
#include "constant/name/numeral/fraction_numeral_name.h"
#include "constant/name/numeral/power_numeral_name.h"
#include "constant/name/numeral/sign_numeral_name.h"
#include "constant/name/numeral/thousands_numeral_name.h"

//
// Loading of a shared object (dynamic library)
//
// A shared object (.so) library gets loaded when needed
// at runtime. This kind of loading happens AUTOMATICALLY.
// The necessary machine language instructions got added to the
// binary executable by the compiler and linker during translation.
//

//
// Keyword "extern"
//
// A function is declared with storage class "extern"
// by DEFAULT, even if the keyword "extern" is missing.
// The keyword "extern" has NO influence on the source code in
// terms of optimisation or the like and thus is NOT necessary.
// It is just a HINT to the reader (developer) indicating that
// the function is implemented in an EXTERNAL source file.
// A COMMENT like this one can be used as hint, instead of that keyword.
//

//
// boolean
//

void deserialise_boolean(void* p0, void* p1, void* p2);
void serialise_boolean(void* p0, void* p1);

//
// digit
//

void select_digit_decimal(void* p0, void* p1, void* p2, void* p3, void* p4);
void select_digit_hexadecimal(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// numeral
//

void deserialise_numeral(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);
void deserialise_numeral_allocation(void* p0, void* p1, void* p2, void* p3, void* p4);
void deserialise_numeral_assembler_complex_cartesian(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void deserialise_numeral_assembler_complex_polar(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void deserialise_numeral_assembler_fraction_decimal(void* p0, void* p1, void* p2, void* p3, void* p4);
void deserialise_numeral_assembler_fraction_vulgar(void* p0, void* p1, void* p2, void* p3, void* p4);
void deserialise_numeral_assembler_integer(void* p0, void* p1, void* p2);
void deserialise_numeral_decimals(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void deserialise_numeral_fraction(void* p0, void* p1, void* p2, void* p3);
void deserialise_numeral_integer(void* p0, void* p1, void* p2, void* p3);
void deserialise_numeral_null(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void deserialise_numeral_number(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);
void deserialise_numeral_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void deserialise_numeral_power(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void deserialise_numeral_value(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);
void deserialise_numeral_vector(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void deserialise_numeral_vector_list(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void deserialise_numeral_verification(void* p0, void* p1, void* p2);

void select_numeral_assembler(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void select_numeral_base(void* p0, void* p1, void* p2);
void select_numeral_sign(void* p0, void* p1, void* p2);
void select_numeral_value(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);

void serialise_numeral(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);
void serialise_numeral_complex_cartesian(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void serialise_numeral_complex_polar(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void serialise_numeral_decimals(void* p0, void* p1, void* p2, void* p3);
void serialise_numeral_fraction_decimal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void serialise_numeral_fraction_vulgar(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void serialise_numeral_integer(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void serialise_numeral_prefix(void* p0, void* p1, void* p2);
void serialise_numeral_vector(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);

//
// datetime
//

void deserialise_datetime_gregorian(void* p0, void* p1, void* p2);
void deserialise_datetime_jd(void* p0, void* p1, void* p2);
void deserialise_datetime_jd_basic(void* p0, void* p1, void* p2, void* p3);
void deserialise_datetime_julian(void* p0, void* p1, void* p2);
void deserialise_datetime_mjd(void* p0, void* p1, void* p2);
void deserialise_datetime_posix(void* p0, void* p1, void* p2);
void deserialise_datetime_tai(void* p0, void* p1, void* p2);
void deserialise_datetime_ti(void* p0, void* p1, void* p2);
void deserialise_datetime_tjd(void* p0, void* p1, void* p2);
void deserialise_datetime_utc(void* p0, void* p1, void* p2);

void serialise_datetime_gregorian(void* p0, void* p1, void* p2);
void serialise_datetime_jd(void* p0, void* p1, void* p2);
void serialise_datetime_jd_basic(void* p0, void* p1, void* p2, void* p3);
void serialise_datetime_julian(void* p0, void* p1, void* p2);
void serialise_datetime_mjd(void* p0, void* p1, void* p2);
void serialise_datetime_posix(void* p0, void* p1, void* p2);
void serialise_datetime_tai(void* p0, void* p1, void* p2);
void serialise_datetime_ti(void* p0, void* p1, void* p2);
void serialise_datetime_tjd(void* p0, void* p1, void* p2);
void serialise_datetime_utc(void* p0, void* p1, void* p2);

//
// duration
//

void deserialise_duration_iso(void* p0, void* p1, void* p2);
void deserialise_duration_jd(void* p0, void* p1, void* p2);
void deserialise_duration_julian(void* p0, void* p1, void* p2);
void deserialise_duration_si(void* p0, void* p1, void* p2);

void serialise_duration_iso(void* p0, void* p1, void* p2);
void serialise_duration_jd(void* p0, void* p1, void* p2);
void serialise_duration_julian(void* p0, void* p1, void* p2);
void serialise_duration_si(void* p0, void* p1, void* p2);

//
// time scale
//

void deserialise_time_scale_correction_leap_year(void* p0, void* p1);
void deserialise_time_scale_correction_leap_year_detection(void* p0, void* p1);
void deserialise_time_scale_correction_month(void* p0, void* p1);
void deserialise_time_scale_gregorian_calendar(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void deserialise_time_scale_gregorian_calendar_julian_day(void* p0, void* p1, void* p2, void* p3);
void deserialise_time_scale_gregorian_calendar_julian_day(void* p0, void* p1, void* p2, void* p3);
void deserialise_time_scale_gregorian_calendar_julian_day_check_reform(void* p0, void* p1, void* p2, void* p3);
void deserialise_time_scale_gregorian_calendar_julian_second(void* p0, void* p1, void* p2, void* p3);
void deserialise_time_scale_gregorian_calendar_normalise(void* p0, void* p1);
void deserialise_time_scale_julian_calendar(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void deserialise_time_scale_julian_date(void* p0, void* p1);
void deserialise_time_scale_running_day(void* p0, void* p1, void* p2, void* p3);

void serialise_time_scale_gregorian_calendar(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void serialise_time_scale_gregorian_calendar(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void serialise_time_scale_gregorian_calendar_correction(void* p0, void* p1, void* p2, void* p3);
void serialise_time_scale_gregorian_calendar_julian_day(void* p0, void* p1, void* p2, void* p3);
void serialise_time_scale_gregorian_calendar_julian_second(void* p0, void* p1, void* p2, void* p3);
void serialise_time_scale_julian_calendar(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void serialise_time_scale_julian_date(void* p0, void* p1);
void serialise_time_scale_running_day(void* p0, void* p1, void* p2);
void serialise_time_scale_running_day_day(void* p0, void* p1, void* p2);
void serialise_time_scale_running_day_month(void* p0, void* p1);
void serialise_time_scale_weekday(void* p0, void* p1);

/* TYPE_HEADER */
#endif
