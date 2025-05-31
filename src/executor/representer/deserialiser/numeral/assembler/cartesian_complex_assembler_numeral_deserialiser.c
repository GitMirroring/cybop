/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
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
 * Assembles the cartesian complex from the given values.
 *
 * @param p0 the destination cartesian complex number
 * @param p1 the real part algebraic sign
 * @param p2 the real part pre point value
 * @param p3 the real part post point value
 * @param p4 the real part power factor
 * @param p5 the imaginary part algebraic sign
 * @param p6 the imaginary part pre point value
 * @param p7 the imaginary part post point value
 * @param p8 the imaginary part power factor
 */
void deserialise_numeral_assembler_complex_cartesian(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral assembler complex cartesian.");
    //?? fwprintf(stdout, L"Debug: Deserialise numeral assembler complex cartesian. real part pre point value p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral assembler complex cartesian. real part pre point value *p2: %i\n", *((int*) p2));
    //?? fwprintf(stdout, L"Debug: Deserialise numeral assembler complex cartesian. imaginary part pre point value p6: %i\n", p6);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral assembler complex cartesian. imaginary part pre point value *p6: %i\n", *((int*) p6));

    // The real part.
    double r = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The imaginary part.
    double i = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Deserialise real part.
    deserialise_numeral_assembler_fraction_decimal((void*) &r, p1, p2, p3, p4);
    // Deserialise imaginary part.
    deserialise_numeral_assembler_fraction_decimal((void*) &i, p5, p6, p7, p8);

    // Assign real part.
    set_complex_element(p0, (void*) &r, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    // Assign imaginary part.
    set_complex_element(p0, (void*) &i, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);
}
