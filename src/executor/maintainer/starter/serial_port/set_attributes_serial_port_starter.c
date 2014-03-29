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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SET_ATTRIBUTES_SERIAL_PORT_STARTER_SOURCE
#define SET_ATTRIBUTES_SERIAL_PORT_STARTER_SOURCE

#include <stdio.h>

#ifdef __APPLE__
    #include <sys/ioctl.h>
    #include <termios.h>
#elif WIN32
    #include <windows.h>
    // source: sys/termios.h
    #define IGNPAR          0000004
    #define CS8             0000060
    #define CLOCAL          0004000
    #define CREAD           0000200
    #define VMIN            6
    #define VTIME           5
    #define TCSANOW         0
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
#include "../../../../executor/maintainer/starter/serial_port/get_status_serial_port_starter.c"
#include "../../../../logger/logger.c"

/**
 * Sets the serial port attributes.
 *
 * @param p0 the file descriptor data
 * @param p1 the original attributes
 * @param p2 the baudrate
 */
void startup_serial_port_attributes_set(void* p0, void* p1, void* p2) {

#ifdef __APPLE__
    //?? Check the status for apple - maybe some problems with some librarys

#elif WIN32
    // not ported to WIN32 at the moment ...

#elif GNU_LINUX_OPERATING_SYSTEM

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* d = (int*) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup serial port attributes set.");

        // The serialised baudrate item.
        void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The serialised baudrate item data.
        void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Allocate serialised baudrate item.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate_item((void*) &b, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        // Serialise given baudrate integer parametre into serialised baudrate item.
        serialise_terminal_mode_line_speed(b, p2);

        // Get serialised wide character item data, count.
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        copy_array_forward((void*) &bd, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

        if (bd != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // The serialised baudrate item data as integer.
            int* bdi = (int*) bd;

            // Initialise new attributes.
            //
            // The structure of type "struct termios" stores the
            // entire collection of attributes of a serial port.
            // It is used with the functions "tcgetattr" and
            // "tcsetattr" to get and set the attributes.
            //
            // CAUTION! When setting serial port modes, one should call "tcgetattr" first
            // to get the current modes of the particular serial port device,
            // modify only those modes that you are really interested in,
            // and store the result with tcsetattr.
            //
            // It's a bad idea to simply initialize a "struct termios" structure
            // to a chosen set of attributes and pass it directly to "tcsetattr".
            // The programme may be run years from now, on systems that support
            // members not documented here. The way to avoid setting these members
            // to unreasonable values is to avoid changing them.
            //
            // What's more, different serial port devices may require
            // different mode settings in order to function properly.
            // So you should avoid blindly copying attributes
            // from one serial port device to another.
            //
            // When a member contains a collection of independent flags,
            // as the c_iflag, c_oflag and c_cflag members do,
            // even setting the entire member is a bad idea,
            // because particular operating systems have their own flags.
            // Instead, one should start with the current value of the member
            // and alter only the flags whose values matter in your program,
            // leaving any other flags unchanged.
            struct termios a = *((struct termios*) p1);

            //
            // Manipulate termios attributes.
            //
            // A good documentation of possible flags may be found at:
            // http://www.unixguide.net/unix/programming/3.6.2.shtml
            //
            // c_iflag: input mode flags; always needed, only not if using software flow control (ick)
            // c_oflag: output mode flags; mostly hacks to make output to slow serial ports work,
            //          newer systems have dropped almost all of them as obsolete
            // c_cflag: control mode flags; set character size, generate even parity, enabling hardware flow control
            // c_lflag: local mode flags; most applications will probably want to turn off ICANON
            //          (canonical, i.e. line-based, input processing), ECHO and ISIG
            // c_cc: an array of characters that have special meanings on input;
            //       these characters are given names like VINTR, VSTOP etc.
            //       the names are indexes into the array
            //       two of these "characters" are not really characters at all,
            //       but control the behaviour of read() when ICANON is disabled;
            //       these are VMIN and VTIME
            //
            // VTIME: the time to wait before read() will return;
            //        its value is (if not 0) always interpreted as a timer in tenths of seconds
            // VMIN: the number of bytes of input to be available, before read() will return
            //

            // Ignore parity.
            a.c_iflag = IGNPAR;
            a.c_oflag = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            a.c_cflag = *bdi | CS8 | CLOCAL | CREAD;
            a.c_lflag = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Set number of input characters to be available, before read() will return.
            // If set to zero, one character gets processed right away,
            // without waiting for yet another character input.
            a.c_cc[VMIN] = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Set time to wait before read() will return.
            a.c_cc[VTIME] = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            // Initialise error number.
            // It is a global variable/ function and other operations
            // may have set some value that is not wanted here.
            //
            // CAUTION! Initialise the error number BEFORE calling
            // the function that might cause an error.
            copy_integer((void*) &errno, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

            // Set new attributes.
            //
            // The second argument specifies how to deal with
            // input and output already queued.
            // It can be one of the following values:
            // TCSANOW - Make the change immediately.
            // TCSADRAIN - Make the change after waiting until all queued output has been written. You should usually use this option when changing parameters that affect output.
            // TCSAFLUSH - This is like TCSADRAIN, but also discards any queued input.
            // TCSASOFT - This is a flag bit that you can add to any of the above alternatives.
            //            Its meaning is to inhibit alteration of the state of the serial port hardware.
            //            It is a BSD extension; it is only supported on BSD systems and the GNU system.
            //            Using TCSASOFT is exactly the same as setting the CIGNORE bit in the c_cflag member of the structure termios-p points to.
            int e = tcsetattr(*d, TCSANOW, &a);

            if (e >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                startup_serial_port_status_get(p0);

            } else {

                // Close serial port on error.
                close(*d);

                if (errno == EBADF) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port attributes set. The filedes argument is not a valid file descriptor.");

                } else if (errno == ENOTTY) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port attributes set. The filedes is not associated with a serial port.");

                } else if (errno == EINVAL) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port attributes set. Either the value of the second argument is not valid, or there is something wrong with the data in the third argument.");

                } else {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port attributes set. An unknown error occured.");
                }
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port attributes set. The baudrate item data is null.");
        }

        // Deallocate serialised baudrate array.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        deallocate_item((void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port attributes set. The file descriptor data is null.");
    }
#else
#endif
}

/* SET_ATTRIBUTES_SERIAL_PORT_STARTER_SOURCE */
#endif
