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

#ifndef FRAGMENT_READER_SOURCE
#define FRAGMENT_READER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../logger/logger.c"
--
#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/internal_memory_getter.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/streamer/reader/directory/directory_reader.c"
#include "../../executor/streamer/reader/file/file_reader.c"
#include "../../executor/streamer/reader/inline/inline_reader.c"
#include "../../executor/streamer/reader/serial_port/serial_port_reader.c"
#include "../../executor/streamer/reader/signal/signal_reader.c"
#include "../../executor/streamer/reader/socket/socket_reader.c"
#include "../../executor/streamer/reader/terminal/terminal_reader.c"

/**
 * Reads a message fragment via the given channel.
 *
 * @param p0 the destination item
 * @param p1 the source client identification (e.g. file descriptor for a file, serial port, terminal, socket)
 * @param p2 the message fragment data
 * @param p2 the message fragment size
 * @param p4 the destination mutex
 * @param p5 the thread exit flag
 * @param p6 the socket close flag
 * @param p13 the channel
 */
void read_fragment(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read fragment.");
    fwprintf(stdout, L"Debug: Read fragment. p13: %i\n", p13);
    fwprintf(stdout, L"Debug: Read fragment. *p12: %i\n", *((int*) p12));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) CLIENT_SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            read_socket(p0, p1, p7, p10, p11, p12, p13);
        }
    }

/*??
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) DIRECTORY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            read_directory(p0, p1, p2, p3, p4, p5, p6, p7);
        }
    }
*/

/*?? currently not needed, since the deserialiser does it all ...
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Get input/output entry.
            get_internal_memory_element((void*) &io, p7, (void*) DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, p10);

            //?? EXAMPLE-DELETE:
            //?? read_terminal(p0, io, m);
            read_display(p0, p7, (void*) DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL);
            //?? modify_item(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p2, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }
*/

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) FILE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            read_basic(destination-item, source-file-descriptor, fragment-data, fragment-size, destination-mutex, exit-flag, close-flag);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) INLINE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            read_inline(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) SERIAL_PORT_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The input/output entry.
            void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Get input/output entry.
            get_internal_memory_element((void*) &io, p7, (void*) SERIAL_PORT_INTERNAL_MEMORY_STATE_CYBOI_NAME, p10);

            read_serial_port(p0, p8, p9, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) SIGNAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            read_signal(p0, p1, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            read_terminal(p0, p1, p7, p10);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read. The channel is unknown.");
    }
}

/* FRAGMENT_READER_SOURCE */
#endif
