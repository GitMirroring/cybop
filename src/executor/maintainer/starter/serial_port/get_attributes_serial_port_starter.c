/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GET_ATTRIBUTES_SERIAL_PORT_STARTER_SOURCE
#define GET_ATTRIBUTES_SERIAL_PORT_STARTER_SOURCE


#include <stdio.h>

#ifdef __APPLE__
    #include <sys/ioctl.h>
    #include <termios.h>
#elif WIN32
// source: sys/termios.h
    #define NCCS        20

    typedef unsigned int    tcflag_t;
    typedef unsigned char   cc_t;
    typedef unsigned int    speed_t;

    struct termios {
        tcflag_t c_iflag;
        tcflag_t c_oflag;
        tcflag_t c_cflag;
        tcflag_t c_lflag;
        cc_t c_cc[NCCS];
        speed_t c_ispeed;
        speed_t c_ospeed;
    };

    #define TCGETA          0x5405
#elif GNU_LINUX_OPERATING_SYSTEM
    #include <sys/ioctl.h>
    #include <termios.h>
#else
    #include <sys/ioctl.h>
    #include <termios.h>
#endif

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/maintainer/starter/serial_port/set_attributes_serial_port_starter.c"
#include "../../../../logger/logger.c"

/**
 * Gets the serial port attributes.
 *
 * @param p0 the file descriptor data
 * @param p1 the baudrate
 * @param p2 the internal memory data
 */
void startup_serial_port_attributes_get(void* p0, void* p1, void* p2) {
#ifdef WIN32
    //?? Port to WIN32
#else
    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* d = (int*) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup serial port attributes get.");

        // Allocate original attributes.
        //
        // The structure of type "struct termios" stores the
        // entire collection of attributes of a serial port.
        // It is used with the functions "tcgetattr" and
        // "tcsetattr" to get and set the attributes.
        void* a = malloc(sizeof(struct termios));

        if (a != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Initialise error number.
            // It is a global variable/ function and other operations
            // may have set some value that is not wanted here.
            //
            // CAUTION! Initialise the error number BEFORE calling
            // the function that might cause an error.
            copy_integer((void*) &errno, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

            // Get original attributes.
            int e = tcgetattr(*d, (struct termios*) a);

            if (e >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                // Set original attributes internals.
                copy_array_forward(p2, (void*) &a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ORIGINAL_ATTRIBUTES_SERIAL_PORT_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

                startup_serial_port_attributes_set(p0, a, p1);

            } else {

                // Close serial port on error.
                close(*d);

                if (errno == EBADF) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port attributes get. The filedes argument is not a valid file descriptor.");

                } else if (errno == ENOTTY) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port attributes get. The filedes is not associated with a serial port.");

                } else {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port attributes get. An unknown error occured.");
                }
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port attributes get. The original attributes is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port attributes get. The serial port file descriptor data is null.");
    }
#endif
}

/* GET_ATTRIBUTES_SERIAL_PORT_STARTER_SOURCE */
#endif
