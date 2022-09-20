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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ASSEMBLER_NUMERAL_SELECTOR_SOURCE
#define ASSEMBLER_NUMERAL_SELECTOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Assembles the number from the given values.
 *
 * Depending on the format, the FIRST value has the MEANING:
 * - integer: value
 * - decimal fraction: value
 * - vulgar fraction: numerator
 * - complex number in cartesian form: real part
 * - complex number in polar form: absolute value
 *
 * Depending on the format, the SECOND value has the MEANING:
 * - integer: none
 * - decimal fraction: none
 * - vulgar fraction: denominator
 * - complex number in cartesian form: imaginary part
 * - complex number in polar form: argument
 *
 * @param p0 the destination number array
 * @param p1 the first algebraic sign
 * @param p2 the first number base (relevant for integer only)
 * @param p3 the first value
 * @param p4 the first decimal places (decimals)
 * @param p5 the first decimal power
 * @param p6 the second algebraic sign
 * @param p7 the second number base (relevant for integer only)
 * @param p8 the second value
 * @param p9 the second decimal places (decimals)
 * @param p10 the second decimal power
 * @param p11 the format
 */
void select_numeral_assembler(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select numeral assembler.");
    fwprintf(stdout, L"Debug: Select numeral assembler. format p11: %i\n", p11);
    fwprintf(stdout, L"Debug: Select numeral assembler. format *p11: %i\n", *((int*) p11));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) COMPLEX_CARTESIAN_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) COMPLEX_POLAR_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) FRACTION_VULGAR_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_numeral_assembler_integer(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select numeral assembler. The format is unknown.");
        fwprintf(stdout, L"Warning: Could not select numeral assembler. The format is unknown. format p11: %i\n", p11);
        fwprintf(stdout, L"Warning: Could not select numeral assembler. The format is unknown. format *p11: %i\n", *((int*) p11));
    }
}

/* ASSEMBLER_NUMERAL_SELECTOR_SOURCE */
#endif
