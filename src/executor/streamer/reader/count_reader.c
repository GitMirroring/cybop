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

#ifndef COUNT_READER_SOURCE
#define COUNT_READER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Checks if the buffer count is greater or equal to the expected message length.
 *
 * @param p0 the complete flag
 * @param p1 the message length
 * @param p2 the buffer count
 */
void read_count(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read count.");
    //?? fwprintf(stdout, L"Debug: Read count. buffer count p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Read count. buffer count *p2: %i\n", *((int*) p2));
    //?? fwprintf(stdout, L"Debug: Read count. message length p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Read count. message length *p1: %i\n", *((int*) p1));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_greater_or_equal((void*) &r, p2, p1);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The expected number (message length) of characters
        // has been received and is available in the buffer.
        //

        // Set complete flag.
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* COUNT_READER_SOURCE */
#endif
