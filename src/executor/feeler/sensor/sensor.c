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

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/server_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/accessor/getter/internal_memory_getter.c"
#include "../../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/feeler/sensor/entry_sensor.c"
#include "../../../executor/feeler/sensor/thread_sensor.c"
#include "../../../executor/maintainer/client_list/get_client_list_maintainer.c"
#include "../../../logger/logger.c"
#include "../../../mapper/channel_to_internal_memory_mapper.c"

/**
 * Senses data on the given channel.
 *
 * @param p0 the internal memory data
 * @param p1 the service port
 * @param p2 the client identification
 * @param p3 the client mode (pointer reference)
 * @param p4 the handler part (pointer reference)
 * @param p5 the sender client (pointer reference)
 * @param p6 the language (pointer reference)
 * @param p7 the channel (pointer reference)
 * @param p8 the channel
 */
void sense(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense.");
    fwprintf(stdout, L"Debug: Sense. p0: %i\n", p0);

    // The server base.
    int b = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The server entry.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client entry list item.
    int ce = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The client identification list item.
    int ci = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The client entry.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get server base by channel.
    map_channel_to_internal_memory((void*) &b, p8);

    compare_integer_greater_or_equal((void*) &r, (void*) &b, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The internal memory name (server base) is VALID.
        //
        // CAUTION! This check is important since otherwise,
        // the internal memory is accessed with a wrong index,
        // which may lead to memory errors.
        //

        // Get server entry.
        get_internal_memory_element((void*) &se, p0, b, p1);

        if (se != *NULL_POINTER_STATE_CYBOI_MODEL) {

            //
            // A server entry exists.
            //

            // Get client entry list item from server entry.
            copy_array_forward((void*) &ce, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENTRY_CLIENT_SERVER_STATE_CYBOI_NAME);
            // Get client identification list item from server entry.
            copy_array_forward((void*) &ci, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_CLIENT_SERVER_STATE_CYBOI_NAME);

            // Get client entry from client list item by client identification.
            maintain_client_list_get((void*) &e, ce, ci, p2);

            // Assign parametres to client entry.
            sense_entry(e, p3, p4, p5, p6, p7);

            // Invoke sense function WITHIN a new thread.
            sense_thread(e);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense. There exists no server entry at the given server base.");
            fwprintf(stdout, L"Error: Could not sense. There exists no server entry at the given server base. se: %i\n", se);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense. The server base is invalid.");
        fwprintf(stdout, L"Error: Could not sense. The server base is invalid. base: %i\n", b);
    }
}

/* SENSOR_SOURCE */
#endif
