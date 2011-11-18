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

#ifndef CONVERTER_TESTER
#define CONVERTER_TESTER

#include <stdio.h>

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/converter/decoder/utf/utf_8_unicode_character_decoder.c"
#include "../../executor/converter/encoder/model_diagram/model_diagram_encoder.c"
#include "../../executor/converter/encoder/utf/utf_8_unicode_character_encoder.c"
#include "../../logger/logger.c"

/**
 * Tests the integer-to-wide character conversion.
 */
void test_converter_integer_to_wide_character_conversion() {

    log_write((void*) stdout, L"Test integer-to-wide character conversion:\n");

    // The test wide character array.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    int tc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // One byte for the wide character and another for the trailing null.
    size_t ts = *NUMBER_2_INTEGER_STATE_CYBOI_MODEL;

    // Allocate test wide character array.
    allocate_array((void*) &t, (void*) &ts, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);

    // Transform source integer to destination string.
    // A null wide character is written to mark the end of the string.
    // The return value is the number of characters generated
    // for the given input, excluding the trailing null.
    // If not all output fits into the provided buffer,
    // a negative value is returned.
#ifdef CYGWIN_ENVIRONMENT
    tc = wsprintfW((wchar_t*) t, L"%i", *NUMBER_5_INTEGER_STATE_CYBOI_MODEL);
/* CYGWIN_ENVIRONMENT */
#else
    tc = swprintf((wchar_t*) t, ts, L"%i", *NUMBER_5_INTEGER_STATE_CYBOI_MODEL);
/* CYGWIN_ENVIRONMENT */
#endif

    fwprintf(stdout, L"TEST ts: %i\n", ts);
    fwprintf(stdout, L"TEST tc: %i\n", tc);
    fwprintf(stdout, L"TEST t: %ls\n", (wchar_t*) t);

    // Deallocate test wide character array.
    deallocate_array((void*) &t, (void*) &ts, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
}

/**
 * Tests the encode integer function.
 */
void test_converter_encode_integer() {

    log_write((void*) stdout, L"Test encode integer:\n");

    // The destination character array.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ds = *NULL_POINTER_STATE_CYBOI_MODEL;

    // An arbitrary source integer value.
    int s = *NUMBER_18_INTEGER_STATE_CYBOI_MODEL;

    // Allocate destination character array.
    allocate_model((void*) &d, (void*) &dc, (void*) &ds, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);

    // Use compound count as index to create the element name suffix,
    // because the element is added at the end of the compound container.
    encode_integer((void*) &d, dc, ds, (void*) &s, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

    fwprintf(stdout, L"Test: Destination character array: %ls\n", (wchar_t*) d);
    fwprintf(stdout, L"Test: Destination character array count: %i\n", *((int*) dc));
    fwprintf(stdout, L"Test: Destination character array size: %i\n", *((int*) ds));

    // Deallocate destination character array.
    deallocate_model((void*) &d, (void*) &dc, (void*) &ds, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
}

/**
 * Tests the decode integer vector function.
 */
void test_converter_decode_integer_vector() {

    log_write((void*) stdout, L"Test decode integer vector:\n");

    // The source character array.
    wchar_t sa[] = {L'1', L',', L'2', L',', L'3', L',', L'4', L',', L'5'};
    void* s = sa;
    int sc = *NUMBER_5_INTEGER_STATE_CYBOI_MODEL;

    // The destination integer vector.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    int dc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int ds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Allocate integer vector.
    allocate_array((void*) &d, (void*) &ds, (void*) INTEGER_STATE_CYBOI_TYPE);

    // Decode character array into integer vector.
    decode_integer_vector((void*) &d, (void*) &dc, (void*) &ds, s, (void*) &sc);

    // The integer values.
    int* i0 = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
    int* i1 = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
    int* i2 = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;

/*??
    // Get integer at index 0 from integer vector.
    get((void*) &i0, d, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_STATE_CYBOI_TYPE);
    // Get integer at index 1 from integer vector.
    get((void*) &i1, d, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_STATE_CYBOI_TYPE);
    // Get integer at index 2 from integer vector.
    get((void*) &i2, d, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_STATE_CYBOI_TYPE);
*/

    fwprintf(stdout, L"Integer 0: %i\n", *i0);
    fwprintf(stdout, L"Integer 1: %i\n", *i1);
    fwprintf(stdout, L"Integer 2: %i\n", *i2);

    // Deallocate integer vector.
    deallocate_array((void*) &d, (void*) &ds, (void*) INTEGER_STATE_CYBOI_TYPE);
}

/**
 * Tests the encode integer vector function.
 */
void test_converter_encode_integer_vector() {

    log_write((void*) stdout, L"Test encode integer vector:\n");

    // The source integer array.
    //?? TODO: Shouldn't this be WITHOUT apostrophes, i.e.:
    //?? int sa[] = {1, 2, 3};
    int sa[] = {'1', '2', '3'};
    void* s = sa;
    int sc = *NUMBER_3_INTEGER_STATE_CYBOI_MODEL;

    // The destination character array.
    wchar_t* d = (wchar_t*) *NULL_POINTER_STATE_CYBOI_MODEL;
    int dc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int ds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Allocate destination character vector.
    allocate_array((void*) &d, (void*) &ds, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);

    // Use compound count as index to create the element name suffix,
    // because the element is added at the end of the compound container.
    encode_integer_vector((void*) &d, (void*) &dc, (void*) &ds, s, (void*) &sc);

    fwprintf(stdout, L"Encoded character array: %ls\n", d);
    fwprintf(stdout, L"Encoded character array count: %i\n", dc);
    fwprintf(stdout, L"Encoded character array size: %i\n", ds);

    // Deallocate destination character vector.
    deallocate_array((void*) &d, (void*) &ds, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
}

/**
 * Tests the utf-8 decoding.
 */
void test_converter_decode_utf8() {

    log_write((void*) stdout, L"Test utf-8 decoding:\n");

    wchar_t* f = L"exit/run.cybol";
    int fc = 14;

    // The read model.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    int rmc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int rms = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Allocate read model.
    allocate_array((void*) &rm, (void*) &rms, (void*) CHARACTER_STATE_CYBOI_TYPE);

    // Read persistent byte stream over channel.
//    receive_data((void*) &rm, (void*) &rmc, (void*) &rms, (void*) f, (void*) &fc, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) FILE_SYSTEM_CYBOI_CHANNEL);

    fwprintf(stdout, L"TEST rms: %i\n", rms);
    fwprintf(stdout, L"TEST rmc: %i\n", rmc);
    fwprintf(stdout, L"TEST rm: %s\n", (wchar_t*) rm);

    // The wide character model.
    void* wm = *NULL_POINTER_STATE_CYBOI_MODEL;
    int wmc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int wms = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Allocate wide character model.
    allocate_array((void*) &wm, (void*) &wms, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);

    decode_utf_8_unicode_character_vector((void*) &wm, (void*) &wmc, (void*) &wms, rm, (void*) &rmc);
    //?? TEST only! DELETE LATER!
//??    decode_utf_8_unicode_character_vector((void*) &wm, (void*) &wmc, (void*) &wms, (void*) ASCII_CYBOL_TEXT_CYBOL_TYPE, (void*) CYBOL_TEXT_CYBOL_TYPE_COUNT);

    fwprintf(stdout, L"TEST wm: %ls\n", (wchar_t*) wm);
    fwprintf(stdout, L"TEST wmc: %i\n", wmc);

    // Deallocate read model.
    deallocate_array((void*) &rm, (void*) &rms, (void*) CHARACTER_STATE_CYBOI_TYPE);

    // Deallocate wide character model.
    deallocate_array((void*) &wm, (void*) &wms, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
}

/**
 * Tests the converter.
 *
 * Sub test procedure call can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_converter() {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Test converter.");

//    test_converter_integer_to_wide_character_conversion();

//    test_converter_encode_integer();

//    test_converter_decode_integer_vector();
//    test_converter_encode_integer_vector();

//    test_converter_decode_utf8();
}

/* CONVERTER_TESTER */
#endif
