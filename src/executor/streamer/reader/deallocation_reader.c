/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Deallocates any resources that had been allocated by the system, e.g. an event.
 *
 * This is currently ONLY relevant for channel DISPLAY where
 * the x window system (accessed via xcb api) allocates events
 * that have to get deallocated by CYBOI after having been processed.
 *
 * CAUTION! Do NOT deallocate the event within function "read_data",
 * since it has to get PROCESSED yet afterwards, e.g. deserialised.
 *
 * The function "read_data" is called at THREE places in cyboi, from:
 * 1 executor/feeler/sensor/loop_sensor.c
 * 2 executor/communicator/receiver/read_receiver.c
 * 3 applicator/stream/read.c
 *
 * 1 executor/feeler/sensor/loop_sensor.c
 *
 * The event does NOT have to get deallocated, since it gets copied
 * and stored in the input BUFFER of the client entry by the
 * sense thread, in order to be processed LATER by the main thread.
 *
 * 2 executor/communicator/receiver/read_receiver.c
 *
 * This is the STANDARD way of processing x window system events.
 * The event DOES have to get destroyed in any case, since it was read
 * via asynchronous read from buffer and processed (e.g. deserialised) ALREADY.
 * The synchronous call of function "read_data" does NOT have to be
 * considered here, since it returns just NOTHING for channel "display",
 * because the events get caught and distributed in "activator/enabler/".
 * Therefore, this function "read_deallocation" can be called always,
 * for asynchronous and synchronous read without problem.
 *
 * 3 applicator/stream/read.c
 *
 * The event DOES have to get deallocated in any case, since it was
 * read from buffer and would otherwise be forgotten.
 * However, it can not be processed anymore after having been deallocated.
 * Therefore, it is NOT useful to call "stream/read" directly in a cybol application
 * that uses the x window system display. The event yet has to be processed
 * so that the cybol operation "communicate/receive" should be used INSTEAD.
 *
 * Additionally, the event gets deallocated in file "xcb_enabler.c",
 * if an error occurs or the handler is null etc.
 *
 * @param p0 the data
 * @param p1 the count
 * @param p2 the type
 * @param p3 the channel
 */
void read_deallocation(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read deallocation.");
    //?? fwprintf(stdout, L"Debug: Read deallocation. channel p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Read deallocation. channel *p3: %i\n", *((int*) p3));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The event.
            void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Get event.
            copy_array_forward((void*) &e, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

            //
            // Deallocate event.
            //
            // CAUTION! Free memory only if event is NOT null.
            //
            // CAUTION! It HAS TO BE destroyed manually here, since for:
            // - linux: it gets created automatically inside the xcb library
            // - win32: it gets created manually as message using the type MSG
            //
            // However, in BOTH CASES they are just pointers and hence
            // NOT platform-specific and therefore may get freed here.
            //
            deallocate_array((void*) &e, p1, p1, p2);
        }
    }

    //
    // Do NOT log anything here for reasons of efficiency.
    // Only the channel "display" needs to deallocate resources.
    // Showing a warning message for the other channels is not necessary.
    //
    // if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
    //
    //     log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read deallocation. The channel is unknown.");
    //     fwprintf(stdout, L"Warning: Could not read deallocation. The channel is unknown. p3: %i\n", p3);
    //     fwprintf(stdout, L"Warning: Could not read deallocation. The channel is unknown. *p3: %i\n", *((int*) p3));
    // }
    //
}
