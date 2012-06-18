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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_STARTER_SOURCE
#define TERMINAL_STARTER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <stdio.h>
#include <termios.h>

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../logger/logger.c"

/**
 * Starts up the terminal.
 *
 * @param p0 the internal memory data
 */
void startup_terminal(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup terminal.");

    // The terminal input- and output stream.
    void* ip = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* op = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get terminal input- and output stream.
    copy_array_forward((void*) &ip, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TERMINAL_INPUT_STREAM_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &op, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TERMINAL_OUTPUT_STREAM_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Only create new terminal resources if both,
    // input- AND output stream internal are null.
    if ((ip == *NULL_POINTER_STATE_CYBOI_MODEL) && (op == *NULL_POINTER_STATE_CYBOI_MODEL)) {

        //
        // The structure of type "struct termios" stores the
        // entire collection of attributes of a terminal.
        // It is used with the functions "tcgetattr" and
        // "tcsetattr" to read and set the attributes.
        //
        // Data Type: struct termios
        //
        // Structure that records all the I/O attributes of a terminal.
        // The structure includes at least the following members:
        // tcflag_t c_iflag - A bit mask specifying flags for input modes; see Input Modes.
        // tcflag_t c_oflag - A bit mask specifying flags for output modes; see Output Modes.
        // tcflag_t c_cflag - A bit mask specifying flags for control modes; see Control Modes.
        // tcflag_t c_lflag - A bit mask specifying flags for local modes; see Local Modes.
        // cc_t c_cc[NCCS] - An array specifying which characters are associated with various control functions; see Special Characters.
        //
        // The "struct termios" structure also contains members
        // which encode input and output transmission speeds,
        // but the representation is not specified.
        //
        // The details of the members of "struct termios" are described following:
        //
        // Data Type: tcflag_t - This is an unsigned integer type used to represent the various bit masks for terminal flags.
        // Data Type: cc_t - This is an unsigned integer type used to represent characters associated with various terminal control functions.
        // Macro: int NCCS - The value of this macro is the number of elements in the c_cc array.
        //

        // The original termios settings.
        struct termios* to = (struct termios*) *NULL_POINTER_STATE_CYBOI_MODEL;
        // The new termios settings.
        struct termios tn;

        // Allocate termios settings.
        to = (struct termios*) malloc(sizeof(struct termios));

        // Initialise terminal internals.
        //
        // CAUTION! The standard input- and output streams are used for now.
        ip = stdin;
        op = stdout;

        // Get file descriptor for file stream.
        // CAUTION! The stream "stdin" must be used instead of "stdout" here!
        int d = fileno((FILE*) ip);

        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the function that might cause an error.
        copy_integer((void*) &errno, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        // Store original termios settings.
        int e = tcgetattr(d, to);

        if (e >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // Initialise new termios settings.
            //
            // CAUTION! When setting terminal modes, one should call "tcgetattr" first
            // to get the current modes of the particular terminal device,
            // modify only those modes that you are really interested in,
            // and store the result with tcsetattr.
            //
            // It's a bad idea to simply initialize a "struct termios" structure
            // to a chosen set of attributes and pass it directly to "tcsetattr".
            // The programme may be run years from now, on systems that support
            // members not documented here. The way to avoid setting these members
            // to unreasonable values is to avoid changing them.
            //
            // What's more, different terminal devices may require
            // different mode settings in order to function properly.
            // So you should avoid blindly copying attributes
            // from one terminal device to another.
            //
            // When a member contains a collection of independent flags,
            // as the c_iflag, c_oflag and c_cflag members do,
            // even setting the entire member is a bad idea,
            // because particular operating systems have their own flags.
            // Instead, one should start with the current value of the member
            // and alter only the flags whose values matter in your program,
            // leaving any other flags unchanged.
            tn = *to;

            //
            // Manipulate termios attributes.
            //
            // A good documentation of possible flags may be found at:
            // http://www.unixguide.net/unix/programming/3.6.2.shtml
            //
            // c_iflag: input mode flags; always needed, only not if using software flow control (ick)
            // c_oflag: output mode flags; mostly hacks to make output to slow terminals work,
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

            //
            // Set input mode flags.
            //

            // Turn off stripping of valid input bytes to seven bits,
            // so that all eight bits are available for programmes to read.
            tn.c_iflag &= ~ISTRIP;

            //
            // Set local mode flags.
            //

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
            tn.c_lflag &= ~ICANON;
            // Turn off echo.
            tn.c_lflag &= ~ECHO;

            //
            // Set noncanonical input mode flags.
            //

            //
            // In noncanonical input mode, the special editing characters
            // such as ERASE and KILL are ignored.
            // The system facilities for the user to edit input are disabled
            // in noncanonical mode, so that all input characters
            // (unless they are special for signal or flow-control purposes)
            // are passed to the application program exactly as typed.
            // It is up to the application program to give the user
            // ways to edit the input, if appropriate.
            //
            // Noncanonical mode offers special parameters called MIN and TIME
            // for controlling whether and how long to wait for input to be available.
            // One can even use them to avoid ever waiting -- to return
            // immediately with whatever input is available, or with no input.
            //

            // Set number of input characters to be available, before read() will return.
            //
            // CAUTION! This value HAS TO BE set to zero,
            // so that one key press such as ESCAPE gets processed
            // right away (e.g. to exit an application),
            // without waiting for yet another character input.
            //
            tn.c_cc[VMIN] = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Set time to wait before read() will return.
            tn.c_cc[VTIME] = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

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
            int e = tcsetattr(d, TCSAFLUSH, &tn);

            if (e < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal. The termios settings could not be set.");

                if (errno == EBADF) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal. The filedes argument is not a valid file descriptor.");

                } else if (errno == ENOTTY) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal. The filedes is not associated with a terminal.");

                } else if (errno == EINVAL) {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal. Either the value of the second argument is not valid, or there is something wrong with the data in the third argument.");

                } else {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal. An unknown error occured.");
                }
            }

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal. The termios settings could not be stored.");

            if (errno == EBADF) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal. The filedes argument is not a valid file descriptor.");

            } else if (errno == ENOTTY) {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal. The filedes is not associated with a terminal.");

            } else {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal. An unknown error occured.");
            }
        }

/*??
        // Check for terminal.
        int l = strcmp("linux", getenv("TERM"));

        if (l == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"This is a terminal.");

        } else {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"This is a standard serial terminal.");
        }
*/

        // Set terminal internals.
        copy_array_forward(p0, (void*) &ip, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TERMINAL_INPUT_STREAM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &op, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TERMINAL_OUTPUT_STREAM_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &to, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) TERMINAL_ORIGINAL_ATTRIBUTES_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        //
        // Although tcgetattr and tcsetattr specify the terminal device with a file descriptor,
        // the attributes are those of the terminal device itself and not of the file descriptor.
        // This means that the effects of changing terminal attributes are persistent;
        // if another process opens the terminal file later on, it will see the changed attributes
        // even though it doesn't have anything to do with the open file descriptor you originally
        // specified in changing the attributes.
        //
        // Similarly, if a single process has multiple or duplicated file descriptors
        // for the same terminal device, changing the terminal attributes affects
        // input and output to all of these file descriptors.
        // This means, for example, that you can't open one file descriptor or stream
        // to read from a terminal in the normal line-buffered, echoed mode;
        // and simultaneously have another file descriptor for the same terminal
        // that you use to read from it in single-character, non-echoed mode.
        // Instead, you have to explicitly switch the terminal back and forth between the two modes.
        //

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal. The terminal input or output or both are already running.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* TERMINAL_STARTER_SOURCE */
#endif
