/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */
#ifndef FRACTION_GETTER_TESTER
#define FRACTION_GETTER_TESTER

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
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    deallocate_array((void*) &d, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);
    deallocate_array((void*) &s, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);
}

void test_fraction_getter() {

    //@todo: Write tests.
    fwprintf(stdout, L"TODO: Write tests.\n");
}

/* FRACTION_GETTER_TESTER */
#endif
