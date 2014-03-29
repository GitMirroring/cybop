/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SENDER_SOURCE
#define SENDER_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/communicator/sender/display/display_sender.c"
#include "../../executor/communicator/sender/file/file_sender.c"
#include "../../executor/communicator/sender/inline/inline_sender.c"
#include "../../executor/communicator/sender/serial_port/serial_port_sender.c"
#include "../../executor/communicator/sender/signal/signal_sender.c"
//?? #include "../../executor/communicator/sender/socket/socket_sender.c"
#include "../../executor/communicator/sender/terminal/terminal_sender.c"
#include "../../logger/logger.c"
#include "../../variable/thread_identification.c"

/**
 * Sends the source via the given channel.
 *
 * CAUTION! Do NOT rename this function to "send",
 * as that name is already used by low-level socket functionality.
 *
 * CAUTION! Do NOT rename this function to "write",
 * as that name is already used for glibc library's output.
 *
 * CAUTION! The properties are handed over as well,
 * since the model might also contain meta data.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the knowledge memory part
 * @param p6 the internal memory data
 * @param p7 the format
 * @param p8 the language indentation
 * @param p9 the language
 * @param p10 the encoding
 * @param p11 the source part (pointer reference)
 * @param p12 the clear flag
 * @param p13 the new line flag
 * @param p14 the null termination flag
 * @param p15 the channel
 */
void send_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p15, (void*) CYBOI_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

/*??
            // The base internal.
            int base = *CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            // The internal memory index.
            int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
            // The communication partner-connected socket of this system.
            void** ps = NULL_POINTER_STATE_CYBOI_MODEL;

            // Get communication partner-connected socket of this system.
            i = base + *COMMUNICATION_PARTNER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            get((void*) &ps, p0, (void*) &i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) POINTER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

    fwprintf(stdout, L"TEST ps: %i \n", *((int*) *ps));

            // Receive model by reading http request or response.
            //
            // CAUTION! The properties are handed over as well,
            // since they will store http headers as meta data.
            send_socket(p0, p1, *ps, p8, p20, p21, p18, p19, p1, p2);
*/
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p15, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            send_display(p1, p2, p3, p4, p5, p7, p9, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p15, (void*) FILE_SYSTEM_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            send_file(p0, p1, p2, p3, p4, p5, p7, p8, p9, p10, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p15, (void*) INLINE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            send_inline(p0, p1, p2, p3, p4, p5, p7, p8, p9, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p15, (void*) SIGNAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            send_signal(p6, p11);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p15, (void*) SERIAL_PORT_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            send_serial_port(p1, p2, p3, p4, p5, p7, p8, p9, p10, p6, p14, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p15, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            send_terminal(p1, p2, p3, p4, p5, p7, p8, p9, p10, p6, p12, p13);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p15, (void*) WWW_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            send_socket(p0, p1, (void*) WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) WWW_SERVICE_THREAD, (void*) &send_socket_www, p1, p2, p3, p4, p5, p7, p8, p11, p12, p17, p18, p19, p20);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send. The channel is unknown.");
    }
}

/* SENDER_SOURCE */
#endif
