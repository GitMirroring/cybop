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

#ifndef MESSAGE_X_WINDOW_SYSTEM_SENSOR_SOURCE
#define MESSAGE_X_WINDOW_SYSTEM_SENSOR_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <xcb/xcb.h>
#include <pthread.h>

#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
//?? #include "../../../../executor/lifeguard/sensor/x_window_system/check_events_x_window_system_sensor.c"
#include "../../../../executor/runner/sleeper.c"

/**
 * TEMPORARY implementation of a function.
 *
 * See feature request to xcb library project:
 * http://stackoverflow.com/questions/15775281/need-for-xeventsqueueddisplay-queuedafterreading-in-xcb
 *
 * from: Christian Heller <christian.heller@tuxtax.de>
 * to: Julien Danjou <julien@danjou.info>
 * date: 2013-04-05
 * now possibly filed by Julien Danjou in:
 * http://bugs.freedesktop.org/
 */
int xcb_test_for_event(xcb_connection_t* c) {

    int r = 0;

    if (((void*) c) != NULL_POINTER_STATE_CYBOI_MODEL) {

/*??
        struct _xcb_in in = c->in;
        struct event_list* l = in.events;

        if (((void*) l) != NULL_POINTER_STATE_CYBOI_MODEL) {

            xcb_generic_event_t* e = l->event;

            if (((void*) e) != NULL_POINTER_STATE_CYBOI_MODEL) {

                r = 1;
            }
        }
*/
    }

    return r;
}

/**
 * Senses x window system message.
 *
 * @param p0 the interrupt
 * @param p1 the mutex
 * @param p2 the sleep time
 * @param p3 the connection
 */
void sense_x_window_system_message(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        xcb_connection_t* c = (xcb_connection_t*) p3;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            pthread_mutex_t* mt = (pthread_mutex_t*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* irq = (int*) p0;

                // CAUTION! DO NOT log this function call!
                // This function is executed within a thread, but the
                // logging is not guaranteed to be thread-safe and might
                // cause unpredictable programme behaviour.
                // Also, this function runs in an endless loop and would produce huge log files.

                //
                // Test for event.
                //
                while (!xcb_test_for_event(c)) {

                    sleep_nano(p2);
                }

                // CAUTION! Do NOT use the following statement directly here:
                // while (XEventsQueued(*d, QueuedAfterReading) == 0) { ... }
                //
                // The direct call to XEventsQueued causes the following error:
                // Xlib: sequence lost (0x10025 > 0x36) in reply type 0x7!
                //
                // This is because the x window system may process events in the
                // main thread of CYBOI while XEventsQueued tries to read events.
                // As workaround to this problem, an EXTRA FUNCTION has been defined
                // that locks the x window system mutex before calling XEventsQueued.
                //
                // There is NO alternative to using busy waiting (while + sleep) here.
                // If XNextEvent was used already here (to block/ save processing time),
                // no x windows could ever be painted by send_x_window_system meanwhile,
                // since the x mutex is set before XNextEvent and denies access to X
                // (which is necessary to avoid "Xlib: unexpected async reply" errors).
                // Note that send_x_window_system runs in CYBOI's main thread,
                // while sense_x_window_system runs in its own thread!
                //
                // CAUTION! A global variable MAY be used to set the sleep time,
                // because it is only read but not written, and thus thread-safe.
                // The global variable should only be manipulated in cyboi's main thread.
/*??
                while (!sense_x_window_system_check_events(p1, p3)) {

                    sleep_nano(p2);
                }
*/

                // Lock x window system mutex.
                pthread_mutex_lock(mt);

                // Set x window system interrupt request to indicate
                // that a message has been received via x window system,
                // which may now be processed in the main thread of this system.
                copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                // Unlock x window system mutex.
                pthread_mutex_unlock(mt);

                // Access irq as atomic variable.
                // CAUTION! Therefore better don't use the following line:
                // while (*irq != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
                while (*irq) {

                    // Sleep as long as the x window system interrupt is not handled and reset yet.
                    //
                    // This is to give the central processing unit (cpu) some
                    // time to breathe, that is to be idle or to process other signals.
                    //
                    // Also, many window inputs are processed at once in the main thread
                    // and only if there are no further inputs to be read, the irq flag is reset,
                    // so that this endless loop can be left and new inputs detected.
                    sleep_nano(p2);
                }

            } else {

                // CAUTION! DO NOT log this function call!
                // This function is executed within a thread, but the
                // logging is not guaranteed to be thread-safe and might
                // cause unpredictable programme behaviour.
                // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense x window system message. The interrupt is null.");
            }

        } else {

            // CAUTION! DO NOT log this function call!
            // This function is executed within a thread, but the
            // logging is not guaranteed to be thread-safe and might
            // cause unpredictable programme behaviour.
            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense x window system message. The mutex is null.");
        }

    } else {

        // CAUTION! DO NOT log this function call!
        // This function is executed within a thread, but the
        // logging is not guaranteed to be thread-safe and might
        // cause unpredictable programme behaviour.
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense x window system message. The connection is null.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* MESSAGE_X_WINDOW_SYSTEM_SENSOR_SOURCE */
#endif
