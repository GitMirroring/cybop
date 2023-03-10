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

#ifndef AWAKENER_SOURCE
#define AWAKENER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/awakener/display_awakener.c"
#include "../../executor/awakener/serial_port_awakener.c"
#include "../../executor/awakener/socket_awakener.c"
#include "../../executor/awakener/terminal_awakener.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../logger/logger.c"

/**
 * Let the system send an input to itself over the channel
 * with the given input/output base.
 *
 * This is necessary to wake up blocking sensing threads,
 * so that they can exit themselves.
 *
 * @param p0 the input/output entry
 * @param p1 the channel
 */
void awaken(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Awaken.");
    fwprintf(stdout, L"Debug: Awaken. channel p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Awaken. channel *p1: %i\n", *((int*) p1));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            awaken_display(p0);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            awaken_serial_port(p0);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            awaken_socket(p0);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            awaken_terminal(p0);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not awaken. The channel is unknown.");
        fwprintf(stdout, L"Warning: Could not awaken. The channel is unknown. p1: %i\n", *((int*) p1));
    }
}

/* AWAKENER_SOURCE */
#endif
