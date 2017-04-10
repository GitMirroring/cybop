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

#ifndef CONVERTER_TESTER
#define CONVERTER_TESTER

#include "decoder/decoder_tester.c"
#include "encoder/encoder_tester.c"

/**
 * Tests the integer-to-wide character conversion.
 */
void test_converter_integer_to_wide_character_conversion() {

    log_write((void*) stdout, L"Test integer-to-wide character conversion:\n");

    // The test wide character data.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // One byte for the wide character and another for the trailing null.
    int s = *NUMBER_2_INTEGER_STATE_CYBOI_MODEL;

    // Allocate test wide character data.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &d, (void*) &s, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // The temporary size_t variable.
    //
    // CAUTION! It IS NECESSARY because on 64 Bit machines,
    // the "size_t" type has a size of 8 Byte,
    // whereas the "int" type has the usual size of 4 Byte.
    // When trying to cast between the two, memory errors
    // will occur and the valgrind memcheck tool report:
    // "Invalid read of size 8".
    //
    // CAUTION! Initialise temporary size_t variable with final int value
    // JUST BEFORE handing that over to the glibc function requiring it.
    //
    // CAUTION! Do NOT use cyboi-internal copy functions to achieve that,
    // because values are casted to int* internally again.
    size_t ts = s;

    // Transform source integer to destination string.
    // A null wide character is written to mark the end of the string.
    // The return value is the number of characters generated
    // for the given input, excluding the trailing null.
    // If not all output fits into the provided buffer,
    // a negative value is returned.

    c = swprintf((wchar_t*) d, ts, L"%i", *NUMBER_5_INTEGER_STATE_CYBOI_MODEL);

    fwprintf(stdout, L"TEST ts: %i\n", s);
    fwprintf(stdout, L"TEST tc: %i\n", c);
    fwprintf(stdout, L"TEST t: %ls\n", (wchar_t*) d);

    // Deallocate test wide character data.
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    deallocate_array((void*) &d, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &s, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/*
 * Start converter tests
 */
void test_converter() {

    fwprintf(stdout, L"TEST executor/converter/decoder.\n");
    test_converter_decoder();
    fwprintf(stdout, L"TEST executor/converter/encoder.\n");
    test_converter_encoder();
    fwprintf(stdout, L"TEST executor/converter generell test.\n");
    test_converter_integer_to_wide_character_conversion();
}

/* CONVERTER_TESTER */
#endif
