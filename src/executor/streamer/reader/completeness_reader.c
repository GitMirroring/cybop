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

#ifndef COMPLETENESS_READER_SOURCE
#define COMPLETENESS_READER_SOURCE

#include "../../../constant/channel/cyboi/cyboi_channel.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/copier/integer/integer_copier.c"
#include "../../../executor/streamer/reader/length_reader.c"
#include "../../../logger/logger.c"

/**
 * Checks if the message is complete, with prefix or suffix
 * depending upon the given channel.
 *
 * @param p0 the complete flag
 * @param p1 the message length (possibly detected previously; should be initialised with a value < 0, e.g. with -1)
 * @param p2 the message item
 * @param p3 the language (protocol)
 * @param p4 the channel
 */
void read_completeness(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read completeness.");
    fwprintf(stdout, L"Debug: Read completeness. channel p4: %i\n", p4);
    fwprintf(stdout, L"Debug: Read completeness. channel *p4: %i\n", *((int*) p4));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Set complete flag.
            //
            // CAUTION! Whenever the blocking sensing function is left,
            // this means that at least one data element has been received.
            //
            // The buffer as defined in file "sensor.c" has a size of 1024,
            // so that many xcb events match in there. However, each event
            // is complete in itself and just a pointer.
            //
            // Therefore, a detection of a length prefix or end suffix
            // is NOT necessary here and the complete flag can be set right away.
            //
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    //
    // FILE_CYBOI_CHANNEL
    //
    // The eof-or-close flag is set inside the fragment reader
    // and filtered out in message reader,
    // so that checking for it here is not necessary.
    //

    //
    // INLINE_CYBOI_CHANNEL
    //
    // The eof-or-close flag is set inside the fragment reader
    // and filtered out in message reader,
    // so that checking for it here is not necessary.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            read_length(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            read_length(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Set complete flag.
            //
            // CAUTION! Whenever the blocking sensing function is left,
            // this means that at least one data element has been received.
            //
            // The buffer as defined in file "sensor.c" has a size of 1024,
            // so that all possible ansi escape sequences match in there.
            //
            // Therefore, a detection of a length prefix or end suffix
            // is NOT necessary here and the complete flag can be set right away.
            //
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read completeness. The channel is unknown.");
        fwprintf(stdout, L"Warning: Could not read completeness. The channel is unknown. p4: %i\n", p4);
        fwprintf(stdout, L"Warning: Could not read completeness. The channel is unknown. *p4: %i\n", *((int*) p4));
    }
}

/* COMPLETENESS_READER_SOURCE */
#endif
