/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CONVERTER_DECODER_TESTER
#define CONVERTER_DECODER_TESTER

#include <stdio.h>

#include "../../../../executor/converter/decoder/utf/utf_8_decoder.c"

#ifdef WIN32
#define swprintf _snwprintf
#endif

/**
 * Tests the utf-8 decoding.
 */
void test_converter_decode_utf_8() {

    log_write((void*) stdout, L"Test converter decode utf-8:\n");
    fwprintf(stdout, L"TEST converter decode utf-8");
    fwprintf(stdout, L"TEST sd: %i\n", PERCENT_SIGN_ASCII_CHARACTER_CODE_MODEL);
    fwprintf(stdout, L"TEST sd: %s\n", PERCENT_SIGN_ASCII_CHARACTER_CODE_MODEL);
    fwprintf(stdout, L"TEST sc: %i\n", *PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

    // The destination item.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination item data, count, size.
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ds = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate destination item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &d, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Get destination item data, count, size.
    copy_array_forward((void*) &dd, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dc, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ds, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIZE_ITEM_STATE_CYBOI_NAME);

    fwprintf(stdout, L"TEST pre dd: %i\n", dd);
    fwprintf(stdout, L"TEST pre dd: %ls\n", (wchar_t*) dd);
    fwprintf(stdout, L"TEST pre dc: %i\n", *((int*) dc));
    fwprintf(stdout, L"TEST pre ds: %i\n", *((int*) ds));

    //??    decode_utf_8(d, (void*) PERCENT_SIGN_ASCII_CHARACTER_CODE_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    decode_utf_8(d, "blubla", (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL);

    // Get destination item data.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &dd, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    fwprintf(stdout, L"TEST post dd: %i\n", dd);
    fwprintf(stdout, L"TEST post dd: %ls\n", (wchar_t*) dd);
    fwprintf(stdout, L"TEST post dc: %i\n", *((int*) dc));
    fwprintf(stdout, L"TEST post ds: %i\n", *((int*) ds));

    // Deallocate destination item.
    deallocate_item((void*) &d, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}
/**
 * Tests the decode integer vector function.
 */
void test_converter_deserialise_cybol_integer_vector() {

    log_write((void*) stdout, L"Test decode integer vector:\n");
    fwprintf(stdout, L"TEST decode integer vector:");

    // The source character array.
    wchar_t sa[] = {L'1', L',', L'2', L',', L'3', L',', L'4', L',', L'5'};
    void* s = sa;
    int sc = *NUMBER_5_INTEGER_STATE_CYBOI_MODEL;

    // The destination integer vector.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    int dc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int ds = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

    // Allocate integer vector.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &d, (void*) &ds, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    // Decode character array into integer vector.
    //    deserialise_cybol_integer_vector((void*) &d, (void*) &dc, (void*) &ds, s, (void*) &sc);

    // The integer values.
    int* i0 = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
    int* i1 = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
    int* i2 = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;

    /*??
        // Get integer at index 0 from integer vector.
        get((void*) &i0, d, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        // Get integer at index 1 from integer vector.
        get((void*) &i1, d, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        // Get integer at index 2 from integer vector.
        get((void*) &i2, d, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    */

    fwprintf(stdout, L"Integer 0: %i\n", *i0);
    fwprintf(stdout, L"Integer 1: %i\n", *i1);
    fwprintf(stdout, L"Integer 2: %i\n", *i2);

    // Deallocate integer vector.
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    deallocate_array((void*) &d, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &ds, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
}

/*
 * Start the test
 */
void test_converter_decoder() {

    test_converter_decode_utf_8();
    test_converter_deserialise_cybol_integer_vector();
}

/* CONVERTER_DECODER_TESTER */
#endif
