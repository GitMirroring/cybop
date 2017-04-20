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

#ifndef TYPE_COMPARE_SOURCE
#define TYPE_COMPARE_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../executor/comparator/comparator.c"
#include "../../logger/logger.c"

/**
 * Compares the type of left- and right operand.
 *
 * If a wrong knowledge path is given, e.g. with non-existing node-names,
 * then a cybol operation might write data into a wrong destination,
 * e.g. source data of format "text/plain" (type wide character)
 * into a destination of format "element/part" (type pointer).
 *
 * Therefore, the types have to be IDENTICAL.
 *
 * @param p0 the result
 * @param p1 the left operand part
 * @param p2 the right operand part
 * @param p3 the operation type
 * @param p4 the left operand type
 * @param p5 the selection data
 * @param p6 the selection count
 * @param p7 the right operand type
 */
void apply_compare_type(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply compare type.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p4, p7);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The result- and operand type are identical.

        compare(p0, p1, p2, p3, p4, p5, p6);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not apply compare type. The left operand type and right operand type are different.");
        fwprintf(stdout, L"ERROR: Could not apply compare type. The left operand type and right operand type are different.\n");
        fwprintf(stdout, L"ERROR: Left operand type: %i. Right operand type: %i.\n", *((int*) p4), *((int*) p7));
    }
}

/* TYPE_COMPARE_SOURCE */
#endif
