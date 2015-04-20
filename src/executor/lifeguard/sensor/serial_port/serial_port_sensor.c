/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERIAL_PORT_SENSOR_SOURCE
#define SERIAL_PORT_SENSOR_SOURCE

#include <pthread.h>
#include <signal.h>
#include <wchar.h>

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/lifeguard/sensor/serial_port/message_serial_port_sensor.c"

/**
 * Senses serial port messages.
 *
 * @param p0 the internal memory data
 */
void sense_serial_port(void* p0) {

    // CAUTION! DO NOT log this function call!
    // This function is executed within a thread, but the
    // logging is not guaranteed to be thread-safe and might
    // cause unpredictable programme behaviour.

    // The interrupt.
    void* irq = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mutex.
    void* mt = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The sleep time.
    void* st = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The file descriptor item.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The file descriptor item data.
    void* fd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get interrupt.
    copy_array_forward((void*) &irq, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get mutex.
    copy_array_forward((void*) &mt, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get sleep time.
    copy_array_forward((void*) &st, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SLEEP_TIME_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get file descriptor item.
    copy_array_forward((void*) &f, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FILE_DESCRIPTOR_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Get file descriptor item data.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &fd, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        // A break condition does not exist here because the loop
        // is running neverendingly while sensing messages.
        //
        // The loop and this thread can only be exited by an external signal
        // which is sent in the corresponding interrupt service function
        // (situated in the applicator/interrupt/ directory)
        // and processed in the system signal handler procedure
        // (situated in the controller/checker.c module).

        sense_serial_port_message(irq, mt, st, fd);
    }

    // An implicit call to pthread_exit() is made when this thread
    // (other than the thread in which main() was first invoked)
    // returns from the function that was used to create it (this function).
    // The pthread_exit() function does therefore not have to be called here.
    // However, since this function runs an endless loop waiting for input, it may
    // only be left using an external signal (see comment at "break" condition above).
}

/* SERIAL_PORT_SENSOR_SOURCE */
#endif
