/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef RECEIVER_SOURCE
#define RECEIVER_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/operation/communication/receive_communication_operation_cybol_name.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/communicator/receiver/file/file_receiver.c"
// not ported to WIN32 at the moment ...
#ifdef GNU_LINUX_OPERATING_SYSTEM
    #include "../../executor/communicator/receiver/serial_port/serial_port_receiver.c"
#endif
#include "../../executor/communicator/receiver/terminal/terminal_receiver.c"
#include "../../executor/communicator/receiver/inline/inline_receiver.c"
// not ported to WIN32 at the moment ...
#ifdef GNU_LINUX_OPERATING_SYSTEM
    #include "../../executor/communicator/receiver/socket/socket_receiver.c"
    #include "../../executor/communicator/receiver/x_window_system/x_window_system_receiver.c"
#endif
#include "../../logger/logger.c"
#include "../../variable/thread_identification.c"

/**
 * Receives via the given channel into the destination.
 *
 * CAUTION! Do NOT rename this function to "receive",
 * as that name is already used by low-level socket functionality.
 *
 * CAUTION! Do NOT rename this function to "read",
 * as that name is already used for glibc library's input.
 *
 * CAUTION! Some file formats (like the German xDT format for
 * medical data exchange or HTTP requests/ responses) contain both,
 * the model AND the properties, in one file. To cover these cases,
 * the model AND properties are processed TOGETHER, in just one function.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data
 * @param p3 the source count
 * @param p4 the minimum number of bytes to be received in one call of the read function
 * @param p5 the maximum number of bytes to be received in one call of the read function
 * @param p6 the format
 * @param p7 the language
 * @param p8 the encoding
 * @param p9 the internal memory data
 * @param p10 the channel
 */
void receive_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

/*??
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p10, (void*) CYBOI_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

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
            receive_socket(p0, p1, *ps, p20, p21, p18, p19, p1, p2);
        }
    }
*/

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p10, (void*) FILE_SYSTEM_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            receive_file(p0, p1, p2, p3, p6, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p10, (void*) INLINE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            receive_inline(p0, p1, p2, p3, p6, p7);
        }
    }

// not ported to WIN32 at the moment ...
#ifdef GNU_LINUX_OPERATING_SYSTEM
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p10, (void*) SERIAL_PORT_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            receive_serial_port(p0, p1, p4, p5, p9);
        }
    }
#endif

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p10, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            receive_terminal(p0, p1, p6, p7, p9);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p10, (void*) WWW_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            receive_socket(p0, p1, (void*) WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) WWW_SERVICE_THREAD, (void*) &receive_socket_www, p1, p2, p3, p4, p5, p6, p7, p10, p11, p17, p18, p19, p20);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p10, (void*) X_WINDOW_SYSTEM_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            receive_x_window_system((void*) &p0, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive. The channel is unknown.");
    }
}

/* RECEIVER_SOURCE */
#endif
