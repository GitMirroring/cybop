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

#ifndef CHECK_EVENTS_X_WINDOW_SYSTEM_SENSOR_SOURCE
#define CHECK_EVENTS_X_WINDOW_SYSTEM_SENSOR_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <X11/Xlib.h>
//?? #include <X11/Xutil.h>
#include <pthread.h>
#include <signal.h>

#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"

/**
 * Checks for x window system events.
 *
 * As an exception to other procedures in CYBOI, parametres are NOT handed over
 * as void* to this procedure, in order to avoid type casts and to gain faster
 * processing results.
 *
 * Another exception is that this procedure is actually a function, since it
 * returns a value, as opposed to other procedures in CYBOI which return
 * nothing (void).
 *
 * @param mt the mutex
 * @param c the connection
 */
int sense_x_window_system_check_events(pthread_mutex_t* mt, xcb_connection_t* c) {

    // CAUTION! DO NOT log this function call!
    // This function is executed within a thread, but the
    // logging is not guaranteed to be thread-safe and might
    // cause unpredictable programme behaviour.
    // Also, this function runs in an endless loop and would produce huge log files.

    // The mutex and display were already checked
    // for not being null in the calling function,
    // and are therefore not tested here again.

    // The number of events.
    int n = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Lock x window system mutex.
    pthread_mutex_lock(mt);

    // Wait for event.
    //
    // There are two ways to receive events:
    // - blocking
    // - non-blocking
    //
    // Since cyboi uses an own thread to detect events,
    // the "blocking" variant may be used here without problems.
    //
    // The "xcb_wait_for_event" function blocks until
    // an event is queued in the x server,
    // then dequeues it from the queue,
    // then returns it as a newly allocated structure.
    //
    // CAUTION! It is cyboi's responsibility to FREE
    // the returned structure.
    //
    // The function MAY return null in event of an error.
    // But other parts of cyboi have to care about that.
    // Since all variables in cyboi are tested for null
    // before being used, an error should not cause problems.
    //
    xcb_generic_event_t* e = xcb_wait_for_event(c);

    // Unlock x window system mutex.
    pthread_mutex_unlock(mt);

    return n;
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* CHECK_EVENTS_X_WINDOW_SYSTEM_SENSOR_SOURCE */
#endif
