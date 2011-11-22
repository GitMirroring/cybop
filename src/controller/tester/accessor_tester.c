/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ACCESSOR_TESTER
#define ACCESSOR_TESTER

#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../executor/memoriser/size_determiner.c"
#include "../../logger/logger.c"

/**
 * Tests the accessor size determiner.
 */
void test_accessor_size_determiner() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test accessor size determiner.");

    // The character type (type) size.
    int cs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The double type (type) size.
    int ds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The integer type (type) size.
    int is = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The pointer type (type) size.
    int ps = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The unsigned long type (type) size.
    int uls = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The wide character type (type) size.
    int wcs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Determine size.
    determine_size((void*) &cs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    determine_size((void*) &ds, (void*) DOUBLE_NUMBER_STATE_CYBOI_TYPE);
    determine_size((void*) &is, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    determine_size((void*) &ps, (void*) POINTER_STATE_CYBOI_TYPE);
    determine_size((void*) &uls, (void*) UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE);
    determine_size((void*) &wcs, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    fwprintf(stdout, L"Type size character: %i\n", cs);
    fwprintf(stdout, L"Type size double: %i\n", ds);
    fwprintf(stdout, L"Type size integer: %i\n", is);
    fwprintf(stdout, L"Type size pointer: %i\n", ps);
    fwprintf(stdout, L"Type size unsigned long: %i\n", uls);
    fwprintf(stdout, L"Type size wide character: %i\n", wcs);
}

/**
 * Tests the accessor assigner.
 */
void test_accessor_assigner() {

    // The double number.
    double d = 2.0;
    // The value to be assigned.
    double v = 3.5;

    fwprintf(stdout, L"Double before assigner: %f\n", d);
//??    assign((void*) &d, (void*) &v, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) DOUBLE_NUMBER_STATE_CYBOI_TYPE);
    fwprintf(stdout, L"Double after assigner: %f\n", d);
}

/**
 * Tests the accessor array setter.
 */
void test_accessor_array_setter() {

    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    int ds = *NUMBER_100_INTEGER_STATE_CYBOI_MODEL;
    wchar_t* s1 = L"Huhu scheene Welt, lass' mal sehen!";
    int s1c = *NUMBER_35_INTEGER_STATE_CYBOI_MODEL;
    int i1 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    wchar_t* s2 = L"Erde";
    int s2c = *NUMBER_4_INTEGER_STATE_CYBOI_MODEL;
    int i2 = *NUMBER_13_INTEGER_STATE_CYBOI_MODEL;

    // Allocate destination array.
    allocate_array((void*) &d, (void*) &ds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    fwprintf(stdout, L"d string: %ls\n", (wchar_t*) d);
    fwprintf(stdout, L"s1: %ls\n", s1);
    fwprintf(stdout, L"s1c: %i\n", s1c);
    fwprintf(stdout, L"i1: %i\n", i1);

//??    overwrite_array(d, (void*) s1, (void*) &s1c, (void*) &i1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    fwprintf(stdout, L"d string 2: %ls\n", (wchar_t*) d);
    fwprintf(stdout, L"s2: %ls\n", s2);
    fwprintf(stdout, L"s2c: %i\n", s2c);
    fwprintf(stdout, L"i2: %i\n", i2);

//??    overwrite_array(d, (void*) s2, (void*) &s2c, (void*) &i2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    fwprintf(stdout, L"d string 3: %ls\n", (wchar_t*) d);

    // Deallocate destination array.
    deallocate_array((void*) &d, (void*) &ds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/**
 * Tests the accessor.
 */
void test_accessor() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test accessor.");

//    test_accessor_size_determiner();
//    test_accessor_assigner();
//    test_accessor_array_setter();
}

/* ACCESSOR_TESTER */
#endif
