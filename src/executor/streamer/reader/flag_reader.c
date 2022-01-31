/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef FLAG_READER_SOURCE
#define FLAG_READER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../logger/logger.c"
--
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/finder/identification_client_list_finder.c"
#include "../../../executor/finder/name_client_list_finder.c"
#include "../../../logger/logger.c"

/**
 * Reads data via the given channel into the destination.
 *
 * CAUTION! Do NOT rename this function to "read",
 * since that name is already used by low-level glibc
 * functionality in header file unistd.h.
 * Function: ssize_t read (int filedes, void *buffer, size_t size)
 *
 * @param p9 the asynchronous mode
 */
void read_flag(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read flag.");
    fwprintf(stdout, L"Debug: Read flag. p0: %i\n", p0);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, px-asynchronous-mode, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is SYNCHRONOUS mode.
        //

        // Read directly from device.
        read_device(px);

    } else {

        //
        // This is ASYNCHRONOUS mode.
        //

        //
        // Read indirectly from buffer.
        //
        // The data have been read and stored in the buffer
        // in a separate sensing thread before.
        //
        read_buffer(destination-item, client-entry, language, channel);
    }
}

/* FLAG_READER_SOURCE */
#endif
