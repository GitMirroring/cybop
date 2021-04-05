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

#ifndef OPENER_SOURCE
#define OPENER_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../executor/registrar/opener/display/display_opener.c"
#include "../../executor/registrar/opener/socket/socket_opener.c"
#include "../../logger/logger.c"

/**
 * Opens up the client.
 *
 * There may be DOZENS of parametres handed over to this function.
 * This is due to the variety of communication channel settings.
 * The value of unneeded parametres may just be set to NULL.
 *
 * @param p0 the client identification (e.g. socket or window id)
 * @param p1 the socket family data (namespace)
 * @param p2 the socket family count
 * @param p3 the socket style data (communication type)
 * @param p4 the socket style count
 * @param p5 the socket protocol data
 * @param p6 the socket protocol count
 * @param p7 the socket filename data
 * @param p8 the socket filename count
 * @param p9 the socket host address data
 * @param p10 the socket host address count
 * @param p11 the socket port
 * @param p12 the socket blocking flag
 * @param p13 the internal memory data
 * @param p14 the channel
 */
void open(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open.");

    fwprintf(stdout, L"Test: Open. p14: %i\n", p14);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            open_display(p0, p13, (void*) DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p14, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            open_socket(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open. The channel is unknown.");
    }
}

/* OPENER_SOURCE */
#endif
