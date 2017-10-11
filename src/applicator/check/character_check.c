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

#ifndef CHARACTER_CHECK_SOURCE
#define CHARACTER_CHECK_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../executor/checker/part_checker.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../logger/logger.c"

/**
 * Tests if the operand type is "wide_character".
 *
 * If other types than cybol "text/plain" (which is "wide_character" in cyboi)
 * are to be sorted lexicographically, e.g. integer, double/fraction, datetime etc.,
 * then they have to be sorted first using the cyboi-internal type, e.g. "datetime",
 * and only AFTERWARDS, they may be serialised into type "wide_character".
 *
 * Therefore, lexicographical comparison in cyboi ALWAYS relies on type "wide_character",
 * which is why it is verified here.
 *
 * @param p0 the result
 * @param p1 the left operand part
 * @param p2 the right operand part
 * @param p3 the operation type
 * @param p4 the operand type
 */
void apply_check_character(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply check character.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The operand type is "wide_character".

        check_part(p0, p1, p2, p3);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not apply check character. The operand type is not wide_character.");
        fwprintf(stdout, L"ERROR: Could not apply check character. The operand type is not wide_character.\n");
        fwprintf(stdout, L"ERROR: Operand type: %i.\n", *((int*) p4));
    }
}

/* CHARACTER_CHECK_SOURCE */
#endif
