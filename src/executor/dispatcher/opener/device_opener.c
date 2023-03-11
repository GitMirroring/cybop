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

#ifndef DEVICE_OPENER_SOURCE
#define DEVICE_OPENER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/dispatcher/opener/display/display_opener.c"
#include "../../../executor/dispatcher/opener/fifo/fifo_opener.c"
#include "../../../executor/dispatcher/opener/file/file_opener.c"
#include "../../../executor/dispatcher/opener/serial_port/serial_port_opener.c"
#include "../../../executor/dispatcher/opener/socket/socket_opener.c"
#include "../../../executor/dispatcher/opener/terminal/terminal_opener.c"
#include "logger.h"

/**
 * Opens the device belonging to the given channel.
 *
 * @param p0 the client identification (e.g. file descriptor, socket number, window id)
 * @param p1 the port
 * @param p2 the host address data (network communication) OR filename data (device, file, local unix domain socket)
 * @param p3 the host address count (network communication) OR filename count (device, file, local unix domain socket)
 * @param p4 the file open mode data
 * @param p5 the file open mode count
 * @param p6 the family data (namespace)
 * @param p7 the family count
 * @param p8 the style data (communication type)
 * @param p9 the style count
 * @param p10 the protocol data
 * @param p11 the protocol count
 * @param p12 the client entry
 * @param p13 the channel
 */
void open_device(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open device.");
    //?? fwprintf(stdout, L"Debug: Open device. p13: %i\n", p13);
    //?? fwprintf(stdout, L"Debug: Open device. *p13: %i\n", *((int*) p13));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            open_display(p0, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) FIFO_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! This is a NAMED PIPELINE, also called FIFO.
            // It is NOT an anonymous pipeline (pipe).
            //

            open_fifo(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) FILE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            open_file(p0, p2, p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            open_serial_port(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            open_socket(p0, p1, p2, p3, p6, p7, p8, p9, p10, p11);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            open_terminal(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open device. The channel is unknown.");
        fwprintf(stdout, L"Warning: Could not open device. The channel is unknown. channel p13: %i\n", p13);
        fwprintf(stdout, L"Warning: Could not open device. The channel is unknown. channel *p13: %i\n", *((int*) p13));
    }
}

/* DEVICE_OPENER_SOURCE */
#endif
