/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef QUARTER_QYYYY_DATETIME_XDT_DESERIALISER_SOURCE
#define QUARTER_QYYYY_DATETIME_XDT_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../../../logger/logger.c"

/**
 * Deserialises the qyyyy quarter into a month.
 *
 * @param p0 the destination month
 * @param p1 the destination day
 * @param p2 the source quarter
 */
void deserialise_xdt_datetime_qyyyy_quarter(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt datetime qyyyy quarter.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_3_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_7_INTEGER_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
            copy_integer(p1, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt datetime qyyyy quarter. The quarter is unknown.");
    }
}

/* QUARTER_QYYYY_DATETIME_XDT_DESERIALISER_SOURCE */
#endif
