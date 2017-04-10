/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SENSOR_SOURCE
#define SENSOR_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../executor/lifeguard/sensor/serial_port/serial_port_sensor.c"
#include "../../executor/lifeguard/sensor/unix_terminal/unix_terminal_sensor.c"
#include "../../executor/lifeguard/channel_sensor.c"
#include "../../executor/lifeguard/message_sensor.c"
#include "../../executor/representer/deserialiser/network_service/network_service_deserialiser.c"
#include "../../logger/logger.c"
#include "../../variable/thread_identification.c"

//
// Forward declarations.
//
// The following functions HAVE TO BE declared here since
// otherwise, the compiler will report errors like:
//
// error: 'sense_terminal' undeclared
//
// The reason is (probably) that the functions are forwarded
// as reference (function pointer), for example:
//
// &sense_terminal
//
// The compiler does not seem to be able to recognise them
// as functions that way. Therefore, the following explicit
// declarations of the functions are necessary.
//

void sense_serial_port(void* p0);
void sense_unix_terminal(void* p0);

/**
 * Senses a message on the given channel.
 *
 * @param p0 the internal memory data
 * @param p1 the service id (e.g. socket port)
 * @param p2 the handler part (pointer reference)
 * @param p3 the sender data (pointer reference)
 * @param p4 the network service data
 * @param p5 the network service count
 * @param p6 the channel
 */
void sense(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense.");

//?? fwprintf(stdout, L"TEST sense, channel p6: %i\n", *((int*) p6));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The internal memory index.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The enable flag.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! The order of function calls is IMPORTANT!

            // Set handler.
            copy_array_forward(p0, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) HANDLER_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // CAUTION! A sensing thread is NOT necessary,
            // since input gets sensed in the main thread.

            // Set enable flag.
            copy_array_forward((void*) &e, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENABLE_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_integer(e, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! The order of function calls is IMPORTANT!

            // Set handler.
            copy_array_forward(p0, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) HANDLER_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // Run sensing thread.
            sense_message(p0, (void*) SERIAL_THREAD, &sense_serial_port);

            // Set enable flag.
            copy_array_forward((void*) &e, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENABLE_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_integer(e, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The port.
            int p = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            // Copy port (which is the service id).
            // CAUTION! It will NOT be copied, if its value is a NULL pointer.
            copy_integer((void*) &p, p1);

            if (p == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                // A direct port was NOT given as parametre.
                // Therefore, determine port from service name.

                // Deserialise port from network service name.
                deserialise_network_service((void*) &p, p4, p5);
            }

//?? fwprintf(stdout, L"TEST sense, socket port: %i\n", p);

            sense_channel(p0, (void*) SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) &p, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p6, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! The order of function calls is IMPORTANT!

            // Set handler.
            copy_array_forward(p0, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) HANDLER_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // Run sensing thread ONLY for unix terminal.
            // CAUTION! A sensing thread for win32 console is NOT necessary,
            // since its input gets sensed in the main thread.
            // Therefore, the function "sense_unix_terminal" and NOT
            // "sense_terminal" is called here.

#if defined(__linux__) || defined(__unix__)
            sense_message(p0, (void*) TERMINAL_THREAD, (void*) &sense_unix_terminal);
#elif defined(__APPLE__) && defined(__MACH__)
            sense_message(p0, (void*) TERMINAL_THREAD, (void*) &sense_unix_terminal);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
            // Not needed.
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

            // Set enable flag.
            copy_array_forward((void*) &e, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENABLE_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_integer(e, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense. The channel is unknown.");
    }
}

/* SENSOR_SOURCE */
#endif
