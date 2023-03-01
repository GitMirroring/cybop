/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SENSOR_SOURCE
#define SENSOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../executor/feeler/sensor/entry_sensor.c"
#include "../../../executor/feeler/sensor/thread_sensor.c"
#include "../../../executor/finder/entry_finder.c"
#include "../../../logger/logger.c"
#include "../../../mapper/channel_to_type_mapper.c"

/**
 * Senses data on the given channel.
 *
 * @param p0 the internal memory
 * @param p1 the channel
 * @param p2 the server flag
 * @param p3 the port
 * @param p4 the sender device identification (e.g. file descriptor of a file, serial port, client socket, window id)
 * @param p5 the language
 * @param p6 the handler (pointer reference)
 * @param p7 the closer (pointer reference)
 */
void sense(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense.");
    //?? fwprintf(stdout, L"Information: Sense. channel p1: %i\n", p1);
    //?? fwprintf(stdout, L"Information: Sense. channel *p1: %i\n", *((int*) p1));

    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get client entry belonging to given source device.
    find_entry((void*) &ce, p0, p1, p2, p3, p4);

    //
    // CAUTION! Do NOT check client entry for NULL here,
    // since the INLINE_CYBOI_CHANNEL does NOT have one.
    // Otherwise, it would not be processed.
    //

    // Store data in client entry.
    sense_entry(ce, p5, p6, p7);

    compare_integer_unequal((void*) &r, p1, (void*) DISPLAY_CYBOI_CHANNEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is NOT the display channel.
        //
        // CAUTION! The DISPLAY events are catched in operation
        // "activate/enable" and distributed to the single window
        // input buffers. Therefore, another thread is NOT necessary
        // here for channel display.
        //
        // However, this operation "feel/sense" is important for
        // assigning a HANDLER to a window of the display channel.
        //

        // Invoke sense function within a new thread.
        sense_thread(ce);
    }
}

/* SENSOR_SOURCE */
#endif
