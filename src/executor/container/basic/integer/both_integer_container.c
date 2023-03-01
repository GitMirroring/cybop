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

#ifndef BOTH_INTEGER_CONTAINER_SOURCE
#define BOTH_INTEGER_CONTAINER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../executor/comparator/integer/greater_integer_comparator.c"
#include "../../../../executor/comparator/integer/less_integer_comparator.c"
#include "../../../../executor/logifier/boolean/and_boolean_logifier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Compares if the bounded area contains the value.
 *
 * CAUTION! BOTH bounds are INCLUDED.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 value
 * @param p2 left bound
 * @param p3 right bound
 */
void contain_integer_both(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Contain integer both.");

    // The left bound comparison result.
    int rl = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The right bound comparison result.
    int rr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_greater_or_equal((void*) &rl, p1, p2);
    compare_integer_less_or_equal((void*) &rr, p1, p3);

    // Initialise result which serves as first operand.
    copy_integer((void*) &r, (void*) &rl);

    // Compare if BOTH results are TRUE.
    logify_boolean_and((void*) &r, (void*) &rr);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* BOTH_INTEGER_CONTAINER_SOURCE */
#endif
