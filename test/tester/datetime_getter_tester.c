/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
#ifndef DATETIME_GETTER_TESTER
#define DATETIME_GETTER_TESTER
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
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    deallocate_array((void*) &d, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) DATETIME_STATE_CYBOI_TYPE);
    deallocate_array((void*) &s, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) DATETIME_STATE_CYBOI_TYPE);
}

void test_datetime_getter() {

    test_compound_datetime();
}
/** DATETIME_GETTER_TESTER*/
#endif
