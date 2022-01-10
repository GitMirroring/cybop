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

#ifndef SENSOR_SOURCE
#define SENSOR_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
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
#include "../../executor/sensor/display/display_sensor.c"
#include "../../executor/sensor/serial_port/serial_port_sensor.c"
#include "../../executor/sensor/socket/socket_sensor.c"
#include "../../executor/sensor/terminal/terminal_sensor.c"
#include "../../logger/logger.c"

/**
 * Senses data on the given channel.
 *
 * CAUTION! Unfortunately, not all clients are integer values.
 * The display connexion for the x window system (via xcb api)
 * for instance is a pointer- and not integer value.
 *
 * Therefore, the input/output entry gets handed over
 * as additional parametre, so that special client values
 * such as the display connexion may be retrieved from it inside.
 *
 * @param p0 the data available flag
 * @param p1 the sender client (client socket id)
 * @param p2 the input/output entry
 * @param p3 the channel
 */
void sense(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense.");

    //?? fwprintf(stdout, L"Debug: Sense. channel p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Sense. channel *p3: %i\n", *((int*) p3));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The interrupt request.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mutex.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get interrupt request from input/output entry.
    copy_array_forward((void*) &i, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get mutex from input/output entry.
    copy_array_forward((void*) &m, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? sense_display(p0, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? sense_serial_port(p0);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? sense_socket(p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? sense_terminal(p0, i, m, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense. The channel is unknown.");
        fwprintf(stdout, L"Error: Could not sense. The channel is unknown. The channel is unknown. p3: %i\n", p3);
        fwprintf(stdout, L"Error: Could not sense. The channel is unknown. The channel is unknown. *p3: %i\n", *((int*) p3));
    }
}

/* SENSOR_SOURCE */
#endif
