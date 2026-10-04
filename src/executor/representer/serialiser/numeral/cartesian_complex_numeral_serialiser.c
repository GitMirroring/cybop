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

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "type.h"

/**
 * Serialises the cartesian complex into a wide character sequence.
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
 */
void serialise_numeral_complex_cartesian(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise numeral complex cartesian.");
    fwprintf(stdout, L"Debug: Serialise numeral complex cartesian. source number p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Serialise numeral complex cartesian. source number *p1: %i\n", *((int*) p1));

    // The real part.
    double r = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The imaginary part.
    double i = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Get real part.
    get_complex_element((void*) &r, p1, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    // Get imaginary part.
    get_complex_element((void*) &i, p1, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);

    // Serialise real part.
    serialise_numeral_fraction_decimal(p0, (void*) &r, p2, p3, p4, p5, p6, p7, p8, p9);
    //
    // Serialise imaginary part.
    //
    // CAUTION! The sign parametre value has to be set to TRUE in any case
    // in order to SEPARATE the imaginary from the real part.
    //
    serialise_numeral_fraction_decimal(p0, (void*) &i, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, p3, p4, p5, p6, p7, p8, p9);
}
