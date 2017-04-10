/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERIAL_PORT_SHUTTER_SOURCE
#define SERIAL_PORT_SHUTTER_SOURCE

#include <stdio.h>

/*??
#if defined(__linux__) || defined(__unix__)
    #include <termios.h>
#elif defined(__APPLE__) && defined(__MACH__)
    #include <termios.h>
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    // Not needed
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
*/

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/lifeguard/interrupter/thread_interrupter.c"
#include "../../../../executor/maintainer/shutter/serial_port/attributes_serial_port_shutter.c"
#include "../../../../executor/maintainer/shutter/serial_port/close_serial_port_shutter.c"
#include "../../../../logger/logger.c"

/**
 * Shuts down the serial port.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the internal memory data
 * @param p1 the service thread
 * @param p2 the service thread interrupt
 */
void shutdown_serial_port(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown serial port.");

    // The serial port file descriptor item.
    void* sp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The serial port file descriptor item data.
    void* spd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get serial port file descriptor item.
    copy_array_forward((void*) &sp, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FILE_DESCRIPTOR_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Only deallocate serial port resources if existent.
    if (sp != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Interrupt serial port service thread.
        interrupt_thread(p1, p2);

        // Get serial port file descriptor item data.
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        copy_array_forward((void*) &spd, sp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

        // The serial port file descriptor item data as integer.
        int* spdi = (int*) spd;

        if (*spdi >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            //
            // Reset attributes of serial port.
            //
            // Although tcgetattr and tcsetattr specify the serial port device with a file descriptor,
            // the attributes are those of the serial port device itself and not of the file descriptor.
            // This means that the effects of changing serial port attributes are persistent;
            // if another process opens the serial port file later on, it will see the changed attributes
            // even though it doesn't have anything to do with the open file descriptor originally
            // specified in changing the attributes.
            //
            // Similarly, if a single process has multiple or duplicated file descriptors
            // for the same serial port device, changing the serial port attributes affects
            // input and output to all of these file descriptors.
            // This means, for example, that one can't open one file descriptor or stream
            // to read from a serial port in the normal line-buffered, echoed mode;
            // and simultaneously have another file descriptor for the same serial port
            // that one uses to read from it in single-character, non-echoed mode.
            // Instead, one has to explicitly switch the serial port back and forth between the two modes.
            //
            // Therefore, it does not matter whether the input- OR
            // output file descriptor is specified here. EITHER may be used.
            // The attribute changes affect the whole serial port,
            // that is input AND output.
            //
            shutdown_serial_port_attributes(spd, p0);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port. The serial port file descriptor is zero or negative.");
        }

        shutdown_serial_port_close(spd);

        // Deallocate serial port file descriptor item.
        deallocate_item((void*) &sp, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        // Reset serial port file descriptor.
        // CAUTION! Assign NULL to the internal memory.
        // It is ESSENTIAL, since cyboi tests for null pointers.
        // Otherwise, wild pointers would lead to memory corruption.
        copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FILE_DESCRIPTOR_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown serial port. There is no serial port running.");
    }
}

/* SERIAL_PORT_SHUTTER_SOURCE */
#endif
