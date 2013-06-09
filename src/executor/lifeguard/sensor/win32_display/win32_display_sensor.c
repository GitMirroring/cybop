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

#ifndef WIN32_DISPLAY_SENSOR_SOURCE
#define WIN32_DISPLAY_SENSOR_SOURCE

#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/lifeguard/sensor/win32_display/message_win32_display_sensor.c"

/**
 * Senses win32 display messages.
 *
 * @param p0 the internal memory data
 */
void sense_win32_display(void* p0) {

    // CAUTION! DO NOT log this function call!
    // This function is executed within a thread, but the
    // logging is not guaranteed to be thread-safe and might
    // cause unpredictable programme behaviour.

    // The interrupt.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mutex.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sleep time.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get interrupt.
    copy_array_forward((void*) &i, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get mutex.
    copy_array_forward((void*) &m, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get sleep time.
    copy_array_forward((void*) &t, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SLEEP_TIME_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        // A break condition does not exist here because the loop
        // is running neverendingly while sensing messages.
        //
        // The loop and this thread can only be exited by an external signal
        // which is sent in the corresponding interrupt service function
        // (situated in the applicator/interrupt/ directory)
        // and processed in the system signal handler procedure
        // (situated in the controller/checker.c module).

        sense_win32_display_message(i, m, t);
    }

    // An implicit call to pthread_exit() is made when this thread
    // (other than the thread in which main() was first invoked)
    // returns from the function that was used to create it (this function).
    // The pthread_exit() function does therefore not have to be called here.
    // However, since this function runs an endless loop waiting for input, it may
    // only be left using an external signal (see comment at "break" condition above).
}

/* WIN32_DISPLAY_SENSOR_SOURCE */
#endif
