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

#ifndef CHANNEL_TO_TYPE_MAPPER_SOURCE
#define CHANNEL_TO_TYPE_MAPPER_SOURCE

#include "../constant/channel/cyboi/cyboi_channel.c"
#include "../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../constant/type/cyboi/state_cyboi_type.c"
#include "../executor/comparator/integer/equal_integer_comparator.c"
#include "../executor/copier/integer_copier.c"
#include "../logger/logger.c"

/**
 * Maps the channel to a data type.
 *
 * It is used for the data that are read from or written to
 * a device on this channel.
 *
 * @param p0 the destination data type
 * @param p1 the source channel
 */
void map_channel_to_type(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Map channel to type.");

    //
    // CAUTION! This mapper is used ONLY by clients
    // communicating in asynchronous mode with BUFFER.
    //
    // The destination data type is needed for buffer allocation.
    //
    // The channels NOT listed here are not using
    // asynchronous communication.
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) POINTER_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) PIPELINE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not map channel to type. The channel is unknown. This is unproblematic, since it is only needed for channels with asynchronous communication via buffer.");
        // fwprintf(stdout, L"Warning: Could not map channel to type. The channel is unknown. This is unproblematic, since it is only needed for channels with asynchronous communication via buffer. channel p1: %i\n", *((int*) p1));
    }
}

/* CHANNEL_TO_TYPE_MAPPER_SOURCE */
#endif
