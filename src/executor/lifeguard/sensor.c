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
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SENSOR_SOURCE
#define SENSOR_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/lifeguard/sensor/display/display_sensor.c"
#include "../../executor/lifeguard/sensor/serial_port/serial_port_sensor.c"
//?? #include "../../executor/lifeguard/sensor/socket/socket_sensor.c"
#include "../../executor/lifeguard/sensor/terminal/terminal_sensor.c"
#include "../../executor/lifeguard/message_sensor.c"
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

void sense_cyboi_socket(void* p0);
void sense_display(void* p0);
void sense_serial_port(void* p0);
void sense_terminal(void* p0);
void sense_www_socket(void* p0);

/**
 * Senses a message on the given channel.
 *
 * @param p0 the internal memory data
 * @param p1 the handler part (pointer reference)
 * @param p2 the channel
 */
void sense(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense.");

//?? fwprintf(stdout, L"TEST sense channel p2: %i\n", *((int*) p2));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The internal memory index.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) CYBOI_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

fwprintf(stdout, L"TEST sense - cyboi r: %i\n", r);

            // Set handler.
            copy_integer((void*) &i, (void*) CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            calculate_integer_add((void*) &i, (void*) HANDLER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
            copy_array_forward(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // Sense incoming message.
//??            sense_message(p0, (void*) CYBOI_SERVICE_THREAD, (void*) &sense_cyboi_socket);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

fwprintf(stdout, L"TEST sense - display r: %i\n", r);

            // Set handler.
            copy_array_forward(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) HANDLER_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

#ifdef GNU_LINUX_OPERATING_SYSTEM
            // Sense incoming message.
            sense_message(p0, (void*) DISPLAY_THREAD, (void*) &sense_display);
#endif
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) SERIAL_PORT_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//?? fwprintf(stdout, L"TEST sense - serial port r: %i\n", r);

            // Set handler.
            copy_array_forward(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) HANDLER_SERIAL_PORT_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // Sense incoming message.
            sense_message(p0, (void*) SERIAL_PORT_THREAD, (void*) &sense_serial_port);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//?? fwprintf(stdout, L"TEST sense - terminal r: %i\n", r);

            // Set handler.
            copy_array_forward(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) HANDLER_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // Sense incoming message.
            sense_message(p0, (void*) TERMINAL_THREAD, (void*) &sense_terminal);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) WWW_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

fwprintf(stdout, L"TEST sense - www r: %i\n", r);

            // Set handler.
            i = *WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME + *HANDLER_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // Sense incoming message.
//??            sense_message(p0, (void*) WWW_SERVICE_THREAD, (void*) &sense_www_socket);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense. The channel is unknown.");
    }
}

/* SENSOR_SOURCE */
#endif
