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

#ifndef SET_ATTRIBUTES_TERMINAL_STARTER_SOURCE
#define SET_ATTRIBUTES_TERMINAL_STARTER_SOURCE

#include <stdio.h>
#ifdef GNU_LINUX_OPERATING_SYSTEM
    #include <termios.h>
#endif


#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Sets the terminal attributes.
 *
 * @param p0 the file descriptor data
 * @param p1 the original attributes
 */
void startup_terminal_attributes_set(void* p0, void* p1) {

// not ported to WIN32 at the moment ...
#ifdef GNU_LINUX_OPERATING_SYSTEM
    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* d = (int*) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup terminal attributes set.");

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

        // Turn off stripping of valid input bytes to seven bits,
        // so that all eight bits are available for programmes to read.
        a.c_iflag &= ~ISTRIP;
        // Turn off canonical input processing mode.
        //
        // POSIX systems support two basic modes of input: canonical and noncanonical.
        //
        // canonical:
        // - terminal input is processed in lines terminated by newline ('\n'), EOF, or EOL characters
        // - no input can be read until an entire line has been typed by the user
        // - read function returns at most a single line of input, no matter how many bytes are requested
        // - operating system provides input editing facilities: some characters are interpreted specially
        //   to perform editing operations within the current line of text, such as ERASE and KILL
        // - constants _POSIX_MAX_CANON and MAX_CANON parameterize the maximum number of bytes
        //   which may appear in a single line of canonical input;
        //   guaranteed is a maximum line length of at least MAX_CANON bytes,
        //   but the maximum might be larger, and might even dynamically change size
        //
        // noncanonical:
        // - characters are not grouped into lines
        // - ERASE and KILL processing is not performed
        // - granularity with which bytes are read is controlled by the MIN and TIME settings
        //
        // Most programs use canonical input mode, because this gives the user
        // a way to edit input line by line.
        // The usual reason to use noncanonical mode is when the program accepts
        // single-character commands or provides its own editing facilities.
        a.c_lflag &= ~ICANON;
        // Turn off echo.
        a.c_lflag &= ~ECHO;
        // Set number of input characters to be available, before read() will return.
        //
        // CAUTION! This value HAS TO BE set to zero,
        // so that one key press such as ESCAPE gets processed
        // right away (e.g. to exit an application),
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

        // Set new termios attributes.
        //
        // The second argument specifies how to deal with
        // input and output already queued.
        // It can be one of the following values:
        // TCSANOW - Make the change immediately.
        // TCSADRAIN - Make the change after waiting until all queued output has been written. You should usually use this option when changing parameters that affect output.
        // TCSAFLUSH - This is like TCSADRAIN, but also discards any queued input.
        // TCSASOFT - This is a flag bit that you can add to any of the above alternatives.
        //            Its meaning is to inhibit alteration of the state of the terminal hardware.
        //            It is a BSD extension; it is only supported on BSD systems and the GNU system.
        //            Using TCSASOFT is exactly the same as setting the CIGNORE bit in the c_cflag member of the structure termios-p points to.
        int e = tcsetattr(*d, TCSANOW, &a);

        if (e < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Close terminal on error.
            close(*d);

            if (errno == EBADF) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal attributes set. The filedes argument is not a valid file descriptor.");

            } else if (errno == ENOTTY) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal attributes set. The filedes is not associated with a terminal.");

            } else if (errno == EINVAL) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal attributes set. Either the value of the second argument is not valid, or there is something wrong with the data in the third argument.");

            } else {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal attributes set. An unknown error occured.");
            }
        }

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal attributes set. The file descriptor data is null.");
    }
#endif
}

/* SET_ATTRIBUTES_TERMINAL_STARTER_SOURCE */
#endif
