/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 * @author Falk Müller <falk89@web.de>
 */

#ifndef VALUE_NUMBER_DESERIALISER_SOURCE
#define VALUE_NUMBER_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the number value.
 *
 * @param p0 the destination format
 * @param p1 the destination type
 * @param p2 the destination integer value one
 * @param p3 the destination integer value two
 * @param p4 the destination double value one
 * @param p5 the destination double value two
 * @param p6 the source data position (pointer reference)
 * @param p7 the source count remaining
 */
void deserialise_number_value(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise number value.");
    fwprintf(stdout, L"Debug: Deserialise number value. count remaining p8: %i\n", p8);
    fwprintf(stdout, L"Debug: Deserialise number value. count remaining *p8: %i\n", *((int*) p8));

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The value data, count.
    void* vd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int vc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise value data.
    copy_pointer((void*) &vd, p6);

    if (p7 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        //
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less_or_equal((void*) &b, p7, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Either an end character was found in the selector
            // OR the source count remaining is zero.
            //
            // In BOTH cases, the value can now be deserialised.
            //

            fwprintf(stdout, L"Debug: Deserialise number value. vc: %i\n", vc);
            fwprintf(stdout, L"Debug: Deserialise number value. vd: %ls\n", (wchar_t*) vd);

            // Deserialise integer value.
            deserialise_number_integer(p2, vd, (void*) &vc);

            break;
        }

        // Select number value.
        select_number_value(p0, p1, p2, p3, p4, p5, p6, p7, (void*) &vc, (void*) &b);
    }

    // Find out if format or type were set already.
    compare_integer_equal((void*) &r, p1, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);

    if (r == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // A format and type was NOT set before.
        //
        // CAUTION! This check is important, since for fraction
        // or complex number, the format and type have been set BEFORE
        // and MUST NOT be overwritten here.
        //
        // This is because the decimal places or imaginary part,
        // respectively, get processed FIRST and the decimal point
        // or sign are used to detect a fraction or complex number.
        //
        // However, if format and type were not set before,
        // then this is clearly an INTEGER number.
        //

        // Assign format and type.
        copy_integer(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);
        copy_integer(p1, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
    }
}

/* VALUE_NUMBER_DESERIALISER_SOURCE */
#endif
