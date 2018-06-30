/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef DEALLOCATE_RECEIVER_SOURCE
#define DEALLOCATE_RECEIVER_SOURCE

#include "../../../constant/channel/cyboi/cyboi_channel.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/copier/pointer_copier.c"
#include "../../../logger/logger.c"

/**
 * Deallocates the given buffer.
 *
 * This is needed for display events that have been allocated
 * inside a framework like xcb and have to get deallocated MANUALLY here.
 *
 * @param p0 the buffer
 * @param p1 the channel
 */
void receive_deallocate(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive deallocate.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                // Free buffer.
                //
                // CAUTION! Whenever an event that was queued
                // in the x server gets dequeued from the queue,
                // it is returned as a newly allocated structure.
                // It is cyboi's responsibility to FREE the
                // returned event structure.
                free(p0);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive deallocate. The buffer is null.");
            }
        }
    }
}

/* DEALLOCATE_RECEIVER_SOURCE */
#endif
