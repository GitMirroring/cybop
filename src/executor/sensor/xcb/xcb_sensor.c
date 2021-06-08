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

#ifndef XCB_SENSOR_SOURCE
#define XCB_SENSOR_SOURCE

#include <xcb/xcb.h>

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/accessor/getter/io_entry_getter.c"
#include "../../../executor/accessor/setter/io_entry_setter.c"
#include "../../../logger/logger.c"

/**
 * Senses xcb x window system messages.
 *
 * @param p0 the data available flag
 * @param p1 the input/output entry (containing e.g. display connexion, event)
 */
void sense_xcb(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense xcb.");

    //?? fwprintf(stdout, L"TEST: Sense xcb. p0: %i\n", p0);

    // The connexion.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieve connexion from input/output entry.
    //
    // CAUTION! Do NOT use "overwrite_array" function here,
    // since it adapts the array count and size.
    // But the array's count and size are CONSTANT.
    //
    // CAUTION! Hand over value as pointer REFERENCE.
    //
    // CAUTION! Do NOT hand over input/output entry as pointer reference.
    //
    get_io_entry_element((void*) &c, p1, (void*) CONNEXION_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);

    if (c != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // Get next event available from the x window system server.
        // If none is available, NULL gets returned.
        //
        // There are two ways to read events:
        // - blocking: xcb_wait_for_event
        // - non-blocking: xcb_poll_for_event
        //
        // The "xcb_wait_for_event" function blocks until an event
        // is queued in the x server, then dequeues it from the
        // queue, then returns it as a newly allocated structure.
        //
        // The "xcb_poll_for_event" function dequeues and returns
        // an event immediately. It returns NULL if no event is
        // available at the time of the call. If an error occurs,
        // the parameter error will be filled with the error status.
        //
        // Decision:
        //
        // Since this is the main thread, it MUST NOT block.
        // Therefore, the non-blocking "xcb_poll_for_event"
        // function is used here.
        //
        // In cyboi, sensing as well as processing of input happens
        // in the one single main thread. Formerly, special "sensing"
        // threads were used together with blocking function calls,
        // but not NOT anymore.
        //
        // CAUTION! Whenever an event is queued in the x server,
        // it gets dequeued from the queue here and is then
        // returned as a newly allocated structure.
        // It is cyboi's responsibility to FREE the
        // returned event structure.
        //
        // CAUTION! The event gets REMOVED from the queue
        // by the "xcb_poll_for_event" function.
        // The event therefore HAS TO BE STORED temporarily in the
        // input/output entry of the internal memory,
        // in order to be able to process it later on.
        //
        // Unfortunately, there is no function or option in xcb to
        // just peek ahead into the event queue for available events,
        // without removing them.
        // The xcb developers have been asked to add a function like
        // "xcb_test_for_event" that would return on availability
        // of an event WITHOUT ACTUALLY REMOVING the event from the queue.
        // However, the xcb developers did not like the idea for now.
        //
        // See mailing list discussion in xcb project:
        // http://stackoverflow.com/questions/15775281/need-for-xeventsqueueddisplay-queuedafterreading-in-xcb
        // http://lists.freedesktop.org/archives/xcb/2013-April/008219.html
        // http://lists.freedesktop.org/archives/xcb/2013-May/008245.html
        // http://lists.freedesktop.org/archives/xcb/2013-May/008249.html
        // http://xcb.freedesktop.org/
        //
        void* e = (void*) xcb_poll_for_event((xcb_connection_t*) c);

        //?? fwprintf(stdout, L"TEST: Sense xcb. Event e: %i\n", e);

        if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

            //
            // Set event into input/output entry.
            //
            // CAUTION! Do NOT use "overwrite_array" function here,
            // since it adapts the array count and size.
            // But the array's count and size are CONSTANT.
            //
            // CAUTION! Do NOT hand over input/output entry as pointer reference.
            //
            // CAUTION! Hand over value as pointer REFERENCE.
            //
            set_io_entry_element(p1, (void*) &e, (void*) EVENT_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);

            // Set data available flag.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense xcb. The connexion is null.");
    }
}

/* XCB_SENSOR_SOURCE */
#endif
