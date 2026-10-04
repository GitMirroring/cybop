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
// Library interface
//

#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Compares the left- with the right complex for unequality.
 *
 * CAUTION! Complex numbers can ONLY be compared for identity!
 *
 * Due to their two-dimensional field nature, they cannot
 * be represented on a number line (German: Zahlenstrahl).
 * Thus, a comparison (greater, less) is NOT possible.
 *
 * http://www.informatik.uni-leipzig.de/~meiler/Schuelerseiten.dir/DPlotzki/html/complex.htm
 * http://answers.yahoo.com/question/index?qid=20081223173853AAAbUug
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 */
void compare_complex_unequal(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare complex unequal.");

    // The destination real and imaginary.
    double dr = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    double di = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    // The source real and imaginary.
    double sr = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;
    double si = *NUMBER_0_0_DOUBLE_STATE_CYBOI_MODEL;

    // Get destination real and imaginary.
    get_complex_element((void*) &dr, (void*) p1, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    get_complex_element((void*) &di, (void*) p1, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);
    // Get source real and imaginary.
    get_complex_element((void*) &sr, (void*) p2, (void*) REAL_COMPLEX_STATE_CYBOI_NAME);
    get_complex_element((void*) &si, (void*) p2, (void*) IMAGINARY_COMPLEX_STATE_CYBOI_NAME);

    // CAUTION! Mind the NOT operator at the beginning!
    if (!((dr == sr) && (di == si))) {

        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    } else {

        // CAUTION! Leave result UNCHANGED.
    }
}
