/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef UNIX_TERMINAL_INITIALISER_SOURCE
#define UNIX_TERMINAL_INITIALISER_SOURCE

#include <termios.h> // struct termios, ISTRIP etc.

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

//
// Manipulate termios mode (attributes).
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
//       but control the behaviour of function "read" when ICANON is disabled;
//       these are VMIN and VTIME
//
// VTIME: the time to wait before function "read" will return;
//        its value is (if not 0) always interpreted as a timer in tenths of seconds
// VMIN: the number of bytes of input to be available, before function "read" will return
//

/**
 * Initialises the unix terminal mode.
 *
 * @param p0 the terminal mode
 */
void initialise_unix_terminal(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        struct termios* m = (struct termios*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Initialise unix terminal.");

        //
        // Turn off stripping of valid input bytes to seven bits,
        // so that all eight bits are available for programmes to read.
        //
        (*m).c_iflag &= ~ISTRIP;

        //
        // Set noncanonical mode.
        //
        // POSIX systems support two basic modes of input processing: canonical and noncanonical.
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
        //
        (*m).c_lflag &= ~ICANON;

        // Switch off echo.
        (*m).c_lflag &= ~ECHO;

        //
        // Set blocking mode.
        //
        // Set number of input characters to be AVAILABLE, before "read" will return.
        //
        // Some documentations recommend to set TIME = 0 and MIN = 1 in noncanonical mode.
        // This means that "read" will BLOCK until at least one byte is available
        // and maintains best compatibility with normal behaviour of terminals.
        //
        // If set to ZERO, a character gets processed right away,
        // WITHOUT waiting for yet another character input, which is
        // the equivalent of non-blocking mode and NOT wanted here.
        //
        (*m).c_cc[VMIN] = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

        // Set time to wait before "read" will return.
        (*m).c_cc[VTIME] = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not initialise unix terminal. The terminal mode is null.");
    }
}

/* UNIX_TERMINAL_INITIALISER_SOURCE */
#endif
