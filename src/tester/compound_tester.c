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
#include "../executor/accessor/getter/datetime_getter.c"
#include "../logger/logger.c"

/**
 * Tests compound operations complex.
 */
void test_compound_complex() {

    fwprintf(stdout, L"Test compound complex.");
}

/**
 * Tests compound operations datetime.
 */
void test_compound_datetime() {

    fwprintf(stdout, L"Test compound datetime.");

    // The datetime.
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int dc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int ds = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

    // Allocate datetime.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &dd, (void*) &ds, (void*) DATETIME_STATE_CYBOI_TYPE);

    fwprintf(stdout, L"TEST dd: %i\n", dd);

    // Deallocate datetime.
    deallocate_array((void*) &dd, (void*) &dc, (void*) &ds, (void*) DATETIME_STATE_CYBOI_TYPE);
}

/**
 * Tests compound operations duration.
 */
void test_compound_duration() {

    fwprintf(stdout, L"Test compound duration.");
}

/**
 * Tests compound operations fraction.
 */
void test_compound_fraction() {

    fwprintf(stdout, L"Test compound fraction.");

    // The fraction.
    void* fd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int fc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int fs = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

    // Allocate fraction.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &fd, (void*) &fs, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);

    fwprintf(stdout, L"TEST fd: %i\n", fd);

    // Deallocate fraction.
    deallocate_array((void*) &fd, (void*) &fc, (void*) &fs, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);
}

/**
 * Tests compound operations.
 */
void test_compound() {

    fwprintf(stdout, L"TEST compound.\n");

    // Uncomment below functions as needed,
    // in order for them to be executed.

//    test_compound_complex();
//    test_compound_datetime();
//    test_compound_duration();
    test_compound_fraction();
}

/* COMPOUND_TESTER */
#endif
