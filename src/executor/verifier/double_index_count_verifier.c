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
 * @version CYBOP 0.24.0 2022-12-24
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef DOUBLE_INDEX_COUNT_VERIFIER_SOURCE
#define DOUBLE_INDEX_COUNT_VERIFIER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../executor/copier/integer_copier.c"
#include "../../executor/logifier/boolean/and_boolean_logifier.c"
#include "../../executor/verifier/index_count_verifier.c"
#include "../../logger/logger.c"

/**
 * Verifies that the sum of the given index and count is within the data array.
 *
 * This is necessary to avoid segmentation fault errors caused by
 * pointers adressing memory that is outside the given data array.
 *
 * The first and second data count do NOT have to be identical,
 * as long as the sum of the given index and count is smaller than
 * or equal to both of them.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the element count
 * @param p2 the first index
 * @param p3 the second index
 * @param p4 the first count
 * @param p5 the second count
 */
void verify_double_index_count(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Verify double index count.");

    // The comparison results.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int r1 = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int r2 = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //?? TODO DELETE: r1, p1 = 1, p2 = 0, p4 = 1
    verify_index_count((void*) &r1, p1, p2, p4);
    //?? TODO DELETE: r2, p1 = 1, p3 = 5, p5 = 1
    verify_index_count((void*) &r2, p1, p3, p5);

    if (DEBUG_CYBOP == 1) {
        fwprintf(stdout, L"Debug: Verify double index count. r1: %i\n", r1);
        fwprintf(stdout, L"Debug: Verify double index count. r2: %i\n", r2);
    }

    copy_integer((void*) &r, (void*) &r1);
    logify_boolean_and((void*) &r, (void*) &r2);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    } else {

        //
        // The sum of one of the indices and element count
        // is greater than the first or second data count.
        //
        // This is most often caused by a knowledge path
        // pointing to a non-existing node, which may be
        // regular behaviour in a cybol application.
        //
        // REMARK: In order to keep the log file size low,
        // the following log messages are commented out.
        //
        // REMARK: This empty block containing a comment only
        // does no harm, since the compiler will remove it anyway.
        //

        // log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not verify double index count. The sum of one of the indices and element count is greater than the first or second data count.");
        // fwprintf(stdout, L"Warning: Could not verify double index count. The sum of one of the indices and element count is greater than the first or second data count.\n");
    }
}

/* DOUBLE_INDEX_COUNT_VERIFIER_SOURCE */
#endif
