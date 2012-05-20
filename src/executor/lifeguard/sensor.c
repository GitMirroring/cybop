/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * @version CYBOP 0.11.0 2012-01-01
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
void sense_terminal(void* p0);
void sense_www_socket(void* p0);
void sense_x_window_system(void* p0);

/**
 * Senses a message on the given channel.
 *
 * @param p0 the internal memory data
 * @param p1 the channel
 * @param p2 the handler part
 */
void sense(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The internal memory index.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) CYBOI_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

    fwprintf(stdout, L"TEST sense cyboi service hac: %i\n", *hac);
    fwprintf(stdout, L"TEST sense cyboi service ha: %i\n", *ha);

            // Set handler type, model, properties.
            i = *CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME + *SOCKET_HANDLER_TYPE_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) ha, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            i = *CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME + *SOCKET_HANDLER_TYPE_COUNT_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) hac, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            i = *CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME + *SOCKET_HANDLER_MODEL_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) hm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            i = *CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME + *SOCKET_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) hmc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            i = *CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME + *SOCKET_HANDLER_PROPERTIES_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) hd, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            i = *CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME + *SOCKET_HANDLER_PROPERTIES_COUNT_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) hdc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // Sense incoming message (http request or response).
            sense_message(p0, (void*) CYBOI_SERVICE_THREAD, (void*) &sense_cyboi_socket);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) TERMINAL_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set handler type, model, properties.
            copy_array_forward(p0, (void*) ha, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TERMINAL_HANDLER_TYPE_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            copy_array_forward(p0, (void*) hac, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TERMINAL_HANDLER_TYPE_COUNT_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            copy_array_forward(p0, (void*) hm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TERMINAL_HANDLER_MODEL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            copy_array_forward(p0, (void*) hmc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TERMINAL_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            copy_array_forward(p0, (void*) hd, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TERMINAL_HANDLER_PROPERTIES_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            copy_array_forward(p0, (void*) hdc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TERMINAL_HANDLER_PROPERTIES_COUNT_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // Sense incoming message.
            sense_message(p0, (void*) TERMINAL_THREAD, (void*) &sense_terminal);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) WWW_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set handler type, model, properties.
            i = *WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME + *SOCKET_HANDLER_TYPE_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) ha, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            i = *WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME + *SOCKET_HANDLER_TYPE_COUNT_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) hac, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            i = *WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME + *SOCKET_HANDLER_MODEL_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) hm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            i = *WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME + *SOCKET_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) hmc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            i = *WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME + *SOCKET_HANDLER_PROPERTIES_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) hd, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            i = *WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME + *SOCKET_HANDLER_PROPERTIES_COUNT_INTERNAL_MEMORY_STATE_CYBOI_NAME;
            copy_array_forward(p0, (void*) hdc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // Sense incoming message (http request or response).
            sense_message(p0, (void*) WWW_SERVICE_THREAD, (void*) &sense_www_socket);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set handler type, model, properties.
            copy_array_forward(p0, (void*) ha, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_HANDLER_TYPE_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            copy_array_forward(p0, (void*) hac, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_HANDLER_TYPE_COUNT_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            copy_array_forward(p0, (void*) hm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_HANDLER_MODEL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            copy_array_forward(p0, (void*) hmc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_HANDLER_MODEL_COUNT_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            copy_array_forward(p0, (void*) hd, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_HANDLER_PROPERTIES_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            copy_array_forward(p0, (void*) hdc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) X_WINDOW_SYSTEM_HANDLER_PROPERTIES_COUNT_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // Sense incoming message.
            sense_message(p0, (void*) X_WINDOW_SYSTEM_THREAD, (void*) &sense_x-window-system);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense. The channel is unknown.");
    }
}

/* SENSOR_SOURCE */
#endif
