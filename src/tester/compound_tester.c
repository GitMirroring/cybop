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

#ifndef COMPOUND_TESTER
#define COMPOUND_TESTER

#include "../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../constant/type/cyboi/state_cyboi_type.c"
#include "../executor/accessor/getter/complex_getter.c"
#include "../executor/accessor/getter/datetime_getter.c"
#include "../executor/accessor/getter/duration_getter.c"
#include "../executor/accessor/getter/fraction_getter.c"
#include "../executor/accessor/setter/complex_setter.c"
#include "../executor/accessor/setter/datetime_setter.c"
#include "../executor/accessor/setter/duration_setter.c"
#include "../executor/accessor/setter/fraction_setter.c"
#include "../executor/modifier/copier/integer_copier.c"
#include "../logger/logger.c"

/**
 * Tests compound operations complex.
 */
void test_compound_complex() {

    fwprintf(stdout, L"Test compound complex.\n");
}

/**
 * Tests compound operations datetime.
 */
void test_compound_datetime() {

    fwprintf(stdout, L"Test compound datetime.\n");

    // The destination datetime.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source datetime.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination julian day, julian second.
    int dd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double ds = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The source julian day, julian second.
    int sd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    double ss = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Allocate source datetime.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &d, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) DATETIME_STATE_CYBOI_TYPE);
    allocate_array((void*) &s, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) DATETIME_STATE_CYBOI_TYPE);

    // The example julian day, julian second.
    // ---------------------------------------------------------
    // Gregorian Calendar                       | Julian Date
    // ---------------------------------------------------------
    // Tuesday, 5th November 2013, 23:28:30 UT  | 2456602.47813
    // ---------------------------------------------------------
    int ed = 2456602;
    double es = 47813;

    // Initialise source julian day, julian second.
    set_datetime_element((void*) s, (void*) &ed, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    set_datetime_element((void*) s, (void*) &es, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);

    //
    // Check pre values.
    //

    // Get destination julian day, julian second.
    get_datetime_element((void*) &dd, (void*) d, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    get_datetime_element((void*) &ds, (void*) d, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);
    // Get source julian day, julian second.
    get_datetime_element((void*) &sd, (void*) s, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    get_datetime_element((void*) &ss, (void*) s, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);

    fwprintf(stdout, L"TEST pre dd: %i\n", dd);
    fwprintf(stdout, L"TEST pre ds: %f\n", ds);
    fwprintf(stdout, L"TEST pre sd: %i\n", sd);
    fwprintf(stdout, L"TEST pre ss: %f\n", ss);

    //
    // Copy source to destination.
    //

    copy_datetime(d, s);

    //
    // Check post values.
    //

    // Reset destination julian day, julian second.
    dd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    ds = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // Reset source julian day, julian second.
    sd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    ss = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Get destination julian day, julian second.
    get_datetime_element((void*) &dd, (void*) d, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    get_datetime_element((void*) &ds, (void*) d, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);
    // Get source julian day, julian second.
    get_datetime_element((void*) &sd, (void*) s, (void*) JULIAN_DAY_DATETIME_STATE_CYBOI_NAME);
    get_datetime_element((void*) &ss, (void*) s, (void*) JULIAN_SECOND_DATETIME_STATE_CYBOI_NAME);

    fwprintf(stdout, L"TEST post dd: %i\n", dd);
    fwprintf(stdout, L"TEST post ds: %f\n", ds);
    fwprintf(stdout, L"TEST post sd: %i\n", sd);
    fwprintf(stdout, L"TEST post ss: %f\n", ss);

    // Deallocate source datetime.
    deallocate_array((void*) &d, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) DATETIME_STATE_CYBOI_TYPE);
    deallocate_array((void*) &s, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) DATETIME_STATE_CYBOI_TYPE);
}

/**
 * Tests compound operations duration.
 */
void test_compound_duration() {

    fwprintf(stdout, L"Test compound duration.\n");
}

/**
 * Tests compound operations fraction.
 */
void test_compound_fraction() {

    fwprintf(stdout, L"Test compound fraction.\n");

    // The destination fraction.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source fraction.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination numerator, denominator.
    int dn = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int dd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The source numerator, denominator.
    int sn = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int sd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Allocate source fraction.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &d, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);
    allocate_array((void*) &s, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);

    // Initialise source numerator, denominator.
    set_fraction_element((void*) s, (void*) NUMBER_8_INTEGER_STATE_CYBOI_MODEL, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    set_fraction_element((void*) s, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);

    //
    // Check pre values.
    //

    // Get destination numerator, denominator.
    get_fraction_element((void*) &dn, (void*) d, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    get_fraction_element((void*) &dd, (void*) d, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);
    // Get source numerator, denominator.
    get_fraction_element((void*) &sn, (void*) s, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    get_fraction_element((void*) &sd, (void*) s, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);

    fwprintf(stdout, L"TEST pre dn: %i\n", dn);
    fwprintf(stdout, L"TEST pre dd: %i\n", dd);
    fwprintf(stdout, L"TEST pre sn: %i\n", sn);
    fwprintf(stdout, L"TEST pre sd: %i\n", sd);

    //
    // Copy source to destination.
    //

    copy_fraction(d, s);

    //
    // Check post values.
    //

    // Reset destination numerator, denominator.
    dn = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    dd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // Reset source numerator, denominator.
    sn = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    sd = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get destination numerator, denominator.
    get_fraction_element((void*) &dn, (void*) d, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    get_fraction_element((void*) &dd, (void*) d, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);
    // Get source numerator, denominator.
    get_fraction_element((void*) &sn, (void*) s, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    get_fraction_element((void*) &sd, (void*) s, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);

    fwprintf(stdout, L"TEST post dn: %i\n", dn);
    fwprintf(stdout, L"TEST post dd: %i\n", dd);
    fwprintf(stdout, L"TEST post sn: %i\n", sn);
    fwprintf(stdout, L"TEST post sd: %i\n", sd);

    // Deallocate source fraction.
    deallocate_array((void*) &d, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);
    deallocate_array((void*) &s, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);
}

/**
 * Tests compound operations.
 */
void test_compound() {

    fwprintf(stdout, L"TEST compound.\n");

    // Uncomment below functions as needed,
    // in order for them to be executed.

//    test_compound_complex();
    test_compound_datetime();
//    test_compound_duration();
//    test_compound_fraction();
}

/* COMPOUND_TESTER */
#endif
