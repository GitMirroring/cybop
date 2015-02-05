/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONVERTER_ENCODER_TESTER
#define CONVERTER_ENCODER_TESTER

#include <stdio.h>

#include "../../../../executor/converter/encoder/utf/utf_8_encoder.c"

#ifdef WIN32
    #define swprintf _snwprintf
#endif

/**
 * Tests the encode integer vector function.
 */
void test_converter_serialise_integer_vector() {

    log_write((void*) stdout, L"Test encode integer vector:\n");
    fwprintf(stdout, L"TEST encode integer vector:");

    // The source integer array.
    //?? TODO: Shouldn't this be WITHOUT apostrophes, i.e.:
    //?? int sa[] = {1, 2, 3};
    int sa[] = {'1', '2', '3'};
    void* s = sa;
    int sc = *NUMBER_3_INTEGER_STATE_CYBOI_MODEL;

    // The destination character array.
    wchar_t* d = (wchar_t*) *NULL_POINTER_STATE_CYBOI_MODEL;
    int dc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int ds = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

    // Allocate destination character vector.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &d, (void*) &ds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Use compound count as index to create the element name suffix,
    // because the element is added at the end of the compound container.
//    serialise_integer_vector((void*) &d, (void*) &dc, (void*) &ds, s, (void*) &sc);

    fwprintf(stdout, L"Encoded character array: %ls\n", d);
    fwprintf(stdout, L"Encoded character array count: %i\n", dc);
    fwprintf(stdout, L"Encoded character array size: %i\n", ds);

    // Deallocate destination character vector.
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    deallocate_array((void*) &d, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &ds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}
/**
 * Tests the encode integer function.
 */
void test_converter_serialise_integer() {

    log_write((void*) stdout, L"Test encode integer:\n");
    fwprintf(stdout, L"TEST encode integer:");

    // The destination character array.
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int dc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int ds = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

    // An arbitrary source integer value.
    int s = *NUMBER_18_INTEGER_STATE_CYBOI_MODEL;

    // Allocate destination character array.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &dd, (void*) &ds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Use compound count as index to create the element name suffix,
    // because the element is added at the end of the compound container.
//    serialise_cybol_integer((void*) &dd, (void*) &dc, (void*) &ds, (void*) &s, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

    fwprintf(stdout, L"Test: Destination character array: %ls\n", (wchar_t*) dd);
    fwprintf(stdout, L"Test: Destination character array count: %i\n", dc);
    fwprintf(stdout, L"Test: Destination character array size: %i\n", ds);

    // Deallocate destination character array.
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    deallocate_array((void*) &dd, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &ds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}


/*
 * Start the test.
 */
void test_converter_encoder() {

    test_converter_serialise_integer_vector();
    test_converter_serialise_integer();

}

/* CONVERTER_ENCODER_TESTER */
#endif
