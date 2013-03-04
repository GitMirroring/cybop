/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GET_STATUS_SERIAL_PORT_STARTER_SOURCE
#define GET_STATUS_SERIAL_PORT_STARTER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/maintainer/starter/serial_port/set_status_serial_port_starter.c"
#include "../../../logger/logger.c"

/**
 * Starts up the serial port status getter.
 *
 * @param p0 the internal memory data
 * @param p1 the serial port file descriptor
 */
void startup_serial_port_attributes(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* sp = (int*) p1;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup serial port attributes.");

        //
        // The structure of type "struct termios" stores the
        // entire collection of attributes of a serial port.
        // It is used with the functions "tcgetattr" and
        // "tcsetattr" to get and set the attributes.
        //

        // The original attributes.
        void* o = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The new attributes.
        struct termios n;

        // Allocate original attributes.
        o = malloc(sizeof(struct termios));

//?? fwprintf(stdout, L"TEST startup serial port attributes o: %i\n", o);

        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the function that might cause an error.
        copy_integer((void*) &errno, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        // Get original attributes.
        int e = tcgetattr(*sp, (struct termios*) o);

        if (e >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Set serial port original attributes.
            copy_array_forward(p0, (void*) &o, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ORIGINAL_ATTRIBUTES_SERIAL_PORT_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // Initialise new attributes.
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
            n = *((struct termios*) to);

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
            n.c_iflag = IGNPAR;
            n.c_oflag = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            n.c_cflag = baudr | CS8 | CLOCAL | CREAD;
            n.c_lflag = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Set number of input characters to be available, before read() will return.
            // If set to zero, one character gets processed right away,
            // without waiting for yet another character input.
            n.c_cc[VMIN] = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Set time to wait before read() will return.
            n.c_cc[VTIME] = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

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
            int e = tcsetattr(*sp, TCSANOW, &tn);

            if (e >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                // The serial port status.
                int status = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                // Get the status of bits.
                int e = ioctl(*sp, TIOCMGET, &status);

                if (e >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    // Turn on DTR.
                    status |= TIOCM_DTR;
                    // Turn on RTS.
                    status |= TIOCM_RTS;

                    // Set the status of bits.
                    int e = ioctl(*sp, TIOCMSET, &status);

                    if (e < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. Could not set the status of bits.");
                    }

                } else {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. Could not get the status of bits.");
                }

            } else {

                // Close serial port specified by file descriptor.
                close(*sp);

                if (errno == EBADF) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. The filedes argument is not a valid file descriptor.");

                } else if (errno == ENOTTY) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. The filedes is not associated with a serial port.");

                } else if (errno == EINVAL) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. Either the value of the second argument is not valid, or there is something wrong with the data in the third argument.");

                } else {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. An unknown error occured.");
                }
            }

        } else {

            // Close serial port specified by file descriptor.
            close(*sp);

            if (errno == EBADF) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. The filedes argument is not a valid file descriptor.");

            } else if (errno == ENOTTY) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. The filedes is not associated with a serial port.");

            } else {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port. An unknown error occured.");
            }
        }

        //
        // Although tcgetattr and tcsetattr specify the serial port device with a file descriptor,
        // the attributes are those of the serial port device itself and not of the file descriptor.
        // This means that the effects of changing serial port attributes are persistent;
        // if another process opens the serial port file later on, it will see the changed attributes
        // even though it doesn't have anything to do with the open file descriptor you originally
        // specified in changing the attributes.
        //
        // Similarly, if a single process has multiple or duplicated file descriptors
        // for the same serial port device, changing the serial port attributes affects
        // input and output to all of these file descriptors.
        // This means, for example, that you can't open one file descriptor or stream
        // to read from a serial port in the normal line-buffered, echoed mode;
        // and simultaneously have another file descriptor for the same serial port
        // that you use to read from it in single-character, non-echoed mode.
        // Instead, you have to explicitly switch the serial port back and forth between the two modes.
        //

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup serial port attributes. The serial port file descriptor is null.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* GET_STATUS_SERIAL_PORT_STARTER_SOURCE */
#endif
