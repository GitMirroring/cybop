/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "logger.h"
#include "type.h"

/**
 * Serialises the source number into a wide character numeral sequence.
 *
 * A description of possible numeral formats can be found
 * in file "number_state_cybol_format.c".
 *
 * CAUTION! The retrieval of language properties constraints such as the
 * decimal separator should NOT happen here since then, they would have
 * to be read for each single number which is not very efficient.
 * Therefore, retrieve the constraints somewhere outside in the calling
 * function and hand them over as ready parametres to here.
 *
 * @param p0 the destination wide character item
 * @param p1 the source number
 * @param p2 the sign flag
 * @param p3 the number base
 * @param p4 the prefix flag (some conversions like html numeric references do not want a "0x" prefix and prepend "&#x" themselves instead)
 * @param p5 the classic octal prefix flag (true means 0 as in c/c++; false means modern style 0o as in perl and python)
 * @param p6 the decimal separator data
 * @param p7 the decimal separator count
 * @param p8 the decimal places
 * @param p9 the scientific notation flag
 * @param p10 the format
 */
void serialise_numeral(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise numeral.");
    //?? fwprintf(stdout, L"Debug: Serialise numeral. format p10: %i\n", p10);
    //?? fwprintf(stdout, L"Debug: Serialise numeral. format *p10: %i\n", *((int*) p10));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p10, (void*) COMPLEX_CARTESIAN_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_numeral_complex_cartesian(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p10, (void*) COMPLEX_POLAR_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_numeral_complex_polar(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p10, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_numeral_fraction_decimal(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p10, (void*) FRACTION_VULGAR_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_numeral_fraction_vulgar(p0, p1, p2, p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p10, (void*) INTEGER_NUMBER_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_numeral_integer(p0, p1, p2, p3, p4, p5);
        }
    }
}
