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
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/accessor/getter/channel_internal_memory_getter.c"
#include "../../../executor/feeler/sensor/entry_sensor.c"
#include "../../../executor/feeler/sensor/thread_sensor.c"
#include "../../../executor/finder/server_entry_finder.c"
#include "../../../logger/logger.c"

/**
 * Senses data on the given channel.
 *
 * @param p0 the client entry
 * @param p1 the channel (pointer reference)
 * @param p2 the port (pointer reference)
 * @param p3 the language (pointer reference)
 * @param p4 the sender client identification (pointer reference)
 * @param p5 the handler (pointer reference)
 * @param p6 the internal memory
 */
void sense(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense.");
    fwprintf(stdout, L"Debug: Sense. p0: %i\n", p0);

    // The server entry.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get server entry from internal memory.
    get_internal_memory_channel((void*) &se, p6, p1, p2);

    // Get client entry from server entry client list by given device identification or -name.
    find_server_entry((void*) &ce, se, p4, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    // Assign parametres to client entry.
    sense_entry(ce, p1, p2, p3, p4, p5);

    // Invoke sense function within a new thread.
    sense_thread(e);
}

/* SENSOR_SOURCE */
#endif
