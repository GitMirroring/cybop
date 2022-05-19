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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef LEADING_STRIPPER_SOURCE
#define LEADING_STRIPPER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/modifier/stripper/beginning_stripper.c"
#include "../../../logger/logger.c"

/**
 * Removes leading whitespaces from the string.
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the destination array count
 * @param p2 the destination array size
 * @param p3 the source data
 * @param p4 the source count
 * @param p5 the type
 */
void strip_leading(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Strip leading.");
    fwprintf(stdout, L"Debug: Strip leading. type p5: %i\n", p5);
    fwprintf(stdout, L"Debug: Strip leading. type *p5: %i\n", *((int*) p5));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Check type, since stripping makes sense for strings only.
    compare_integer_equal((void*) &r, p5, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Search for non-whitespace character from the BEGINNING.
        strip_beginning(p0, p1, p2, p3, p4);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not strip leading. The source type is not text.");
        fwprintf(stdout, L"Warning: Could not strip leading. The source type is not text. type p5: %i\n", p5);
        fwprintf(stdout, L"Warning: Could not strip leading. The source type is not text. type *p5: %i\n", *((int*) p5));
    }
}

/* LEADING_STRIPPER_SOURCE */
#endif
